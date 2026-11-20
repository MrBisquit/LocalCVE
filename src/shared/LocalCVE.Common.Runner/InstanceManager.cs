using System;
using System.Collections.Generic;
using System.IO.Pipes;
using System.Text;
using System.Text.Json;

namespace LocalCVE.Common
{
    /// <summary>
    /// Instance management
    /// </summary>
    public static class InstanceManager
    {
        /// <summary>
        /// Attempt to register a Mutex.
        /// 
        /// This helps prevent multiple instances from running simultaneously.
        /// </summary>
        /// <param name="name">The unique name of the mutex</param>
        /// <param name="mut">The output of the mutex. This will be invalid if the method returns false</param>
        /// <returns>Returns true if the mutex does not already exist, false if it does</returns>
        public static bool CreateMutex(string name, out Mutex mut)
        {
            mut = new Mutex(false, name);

            try
            {
                return mut.WaitOne(0, false);
            } finally
            {
                mut?.Close();
            }
        }

        /// <summary>
        /// Releases the mutex
        /// </summary>
        /// <param name="mut">The mutext to release, this will become invalid</param>
        public static void ReleaseMutex(Mutex mut)
        {
            Logger.LogInfo("Releasing mutex");
            mut.ReleaseMutex();
            Logger.LogDebug("Released mutex sucessfully");
        }

        /// <summary>
        /// This is the class that contains the data that can be sent from one instance
        /// to another.
        /// </summary>
        public sealed class InstanceInfo
        {
            /// <summary>
            /// The InstanceInfo message type enum
            /// </summary>
            public enum InstanceInfoType
            {
                InstanceCreatedEvent,
                GenericMessage
            };

            /// <summary>
            /// The InstanceInfo message type
            /// </summary>
            public InstanceInfoType Type { get; private set; }

            /// <summary>
            /// The InstanceInfoData union-like thing, holds the actual data
            /// </summary>
            public abstract record InstanceInfoData
            {
                public sealed record InstanceCreatedEvent : InstanceInfoData
                {
                    public required string[] Args;
                };

                public sealed record GenericMessage : InstanceInfoData
                {
                    public required string Message;
                }
            };

            /// <summary>
            /// The InstanceInfoData, holds the actual data
            /// </summary>
            public InstanceInfoData Data { get; private set; }

            /// <summary>
            /// InstanceInfo constructor with an InstanceCreatedEvent
            /// </summary>
            /// <param name="instanceCreatedEvent">The data</param>
            public InstanceInfo(InstanceInfoData.InstanceCreatedEvent instanceCreatedEvent)
            {
                Data = instanceCreatedEvent;
                Type = InstanceInfoType.InstanceCreatedEvent;
            }

            /// <summary>
            /// InstanceInfo constructor with a GenericMessage
            /// </summary>
            /// <param name="genericMessage">The data</param>
            public InstanceInfo(InstanceInfoData.GenericMessage genericMessage)
            {
                Data = genericMessage;
                Type = InstanceInfoType.GenericMessage;
            }
        }

        /// <summary>
        /// Starts the pipe server, this should be used if you wish to recieve data when another instance
        /// is opened.
        /// </summary>
        /// <param name="name">The name of the pipe</param>
        /// <param name="callback">The callback</param>
        /// <param name="ct">The cancellation token to cancel the task</param>
        /// <exception cref="InvalidDataException">If the data recieved is invalid</exception>
        public static void StartPipeServer(string name, Action<InstanceInfo> callback, CancellationToken ct)
        {
            Task.Run(() =>
            {
                while(true)
                {
                    using var server = new NamedPipeServerStream(name, PipeDirection.In);
                    server.WaitForConnection();

                    using var reader = new StreamReader(server);
                    string message = reader.ReadToEnd();

                    var data = JsonSerializer.Deserialize<InstanceInfo>(message)
                        ?? throw new InvalidDataException("Data recieved was null");

                    callback(data);
                }
            }, ct);
        }

        /// <summary>
        /// Attempt to send a message to another instance
        /// </summary>
        /// <param name="name">The name of the pipe</param>
        /// <param name="data">The data to send</param>
        /// <param name="ct">The cancellation token</param>
        /// <returns>The task</returns>
        public static async Task SendMessageAsync(string name, InstanceInfo data, CancellationToken ct)
        {
            using var client = new NamedPipeClientStream(name);
            try
            {
                await client.ConnectAsync(ct);

                using var writer = new StreamWriter(client);
                
                string message = JsonSerializer.Serialize(data);
                await writer.WriteLineAsync(new StringBuilder(message), ct);
                await writer.FlushAsync(ct);

                writer.Close();
                await writer.DisposeAsync();
                await client.DisposeAsync();
            } finally
            {
                client.Close();
                client.Dispose();
            }
        }
    }
}
