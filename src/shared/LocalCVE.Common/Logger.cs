using System.Reflection;
using System.Globalization;
using System.Diagnostics;
using System.Runtime.CompilerServices;

namespace LocalCVE.Common
{
    public static class Logger
    {
        private static readonly string Version = Assembly.GetExecutingAssembly().GetCustomAttribute<AssemblyFileVersionAttribute>()?.Version ?? "Unknown";

        public static string CurrentVerLogDirPath { get; private set; }
        public static string CurrentLogFile { get; private set; }
        public static string AppLogDirPath { get; private set; }

        public static void InitLogger(string appLogPath, bool console = false)
        {
            string versionedPath = Path.Join(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "WTDawson", "LocalCVE", appLogPath);
            string basePath = Path.GetDirectoryName(versionedPath);

            if(!Directory.Exists(versionedPath))
            {
                Directory.CreateDirectory(versionedPath);
            }

            AppLogDirPath = basePath;
            CurrentVerLogDirPath = versionedPath;

            var logFile = $"Log_{DateTime.Now.ToString(@"yyyy-MM-dd", CultureInfo.InvariantCulture)}.log";
            var logFilePath = Path.Join(versionedPath, logFile);
            CurrentLogFile = logFilePath;

            Trace.Listeners.Add(new TextWriterTraceListener(logFilePath));
            if(console)
            {
                Trace.Listeners.Add(new ConsoleTraceListener());
            }
            Trace.AutoFlush = true;
        }

        private static string GetCallerInfo(string memberName, string sourceFilePath, int sourceLineNumber)
        {
            string callerFileName = "Unknown";
            try
            {
                string fileName = Path.GetFileName(sourceFilePath);
                if(!string.IsNullOrEmpty(fileName))
                {
                    callerFileName = fileName;
                }
            } catch (Exception)
            {
                callerFileName = "Unknown";
                throw;
            }

            return $"{callerFileName}::{memberName}::{sourceLineNumber}";
        }

        private static void Log(string msg, string type, string memberName, string sourceFilePath, int sourceLineNumber)
        {
            Trace.WriteLine($"[{DateTime.Now.TimeOfDay} {DateTime.Now.ToString(@"yyyy-MM-dd", CultureInfo.InvariantCulture)}] [{type}] {GetCallerInfo(memberName, sourceFilePath, sourceLineNumber)}");
            if(msg != string.Empty)
            {
                Trace.Indent();
                Trace.WriteLine(msg);
                Trace.Unindent();
            }
        }

        public static void LogWarning(string msg, [CallerMemberName] string memberName = "", [CallerFilePath] string sourceFilePath = "", [CallerLineNumber] int sourceLineNumber = 0)
        {
            Log(msg, "Warning", memberName, sourceFilePath, sourceLineNumber);
        }

        public static void LogInfo(string msg, [CallerMemberName] string memberName = "", [CallerFilePath] string sourceFilePath = "", [CallerLineNumber] int sourceLineNumber = 0)
        {
            Log(msg, "Info", memberName, sourceFilePath, sourceLineNumber);
        }

        public static void LogTrace(string msg, [CallerMemberName] string memberName = "", [CallerFilePath] string sourceFilePath = "", [CallerLineNumber] int sourceLineNumber = 0)
        {
            Log(msg, "Trace", memberName, sourceFilePath, sourceLineNumber);
        }

        public static void LogDebug(string msg, [CallerMemberName] string memberName = "", [CallerFilePath] string sourceFilePath = "", [CallerLineNumber] int sourceLineNumber = 0)
        {
#if DEBUG
            Log(msg, "Debug", memberName, sourceFilePath, sourceLineNumber);
#endif
        }
    }
}
