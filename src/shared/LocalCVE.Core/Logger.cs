using System;
using System.Collections.Generic;
using System.Text;

namespace LocalCVE.Core
{
    /*internal static class Logger
    {
        private static FileStream GlobalLogsFile;
        private static StreamWriter GlobalLogs;
        private static bool WriteGlobal = false;
        private static FileStream LocalLogsFile;
        private static StreamWriter LocalLogs;
        private static bool WriteLocal = false;

        public static void Setup()
        {
            string now = DateTime.Now.ToString("dd'-'MM'-'yyyy");
            FileMode mode = FileMode.OpenOrCreate;
            GlobalLogsFile = File.Open(Path.Combine(Paths.GlobalLogsPath, now + ".log"), mode);
            GlobalLogsFile.Seek(0, SeekOrigin.End);
            GlobalLogs = new StreamWriter(GlobalLogsFile);
            WriteGlobal = true;
            LocalLogsFile = File.Open(Path.Combine(Paths.LogsPath, now + ".log"), mode);
            LocalLogsFile.Seek(0, SeekOrigin.End);
            LocalLogs = new StreamWriter(LocalLogsFile);
            WriteLocal = true;

            Log(null, "OK", "Logger ready.", null);
        }

        public static void Shutdown()
        {
            Log(null, null, "Loggers shutting down.", null);

            GlobalLogs.Close();
            GlobalLogsFile.Close();
            WriteGlobal = false;
            LocalLogs.Close();
            LocalLogsFile.Close();
            WriteLocal = false;

            Log(null, "WRN", "If you see this message, something went wrong.", null);
        }

        public static void ReportFault(string? src, bool? gbl, Exception? exception, string? msg)
        {
            if(src == null && gbl == null && exception == null && msg == null)
            {
                //GlobalLogs.WriteLine("An unknown fault has occured");
                //LocalLogs.WriteLine("An unknown fault has occured");

                Log(null, "FAULT", "An unknown fault has occured.", null);
            }
        }

        public static void Log(string? src, string? s, string msg, bool? gbl = false)
        {
            string now = DateTime.Now.ToString("dd'-'MM'-'yyyy'@'HH':'mm':'ss'.'fff");
            string status = s == null ? "" : $"[{s}]";
            string source = src == null ? "" : $"({src})";
            string str = $"[{now}]{status}{source} {msg}";
            if (gbl == true || gbl == null && WriteGlobal)
                GlobalLogs.WriteLine(str);
            if (gbl == false || gbl == null && WriteLocal)
                LocalLogs.WriteLine(str);

            Console.WriteLine($"[{(gbl == null ? "B" : gbl == true ? "G" : "L")}]{str}");
        }
    }

    public class LoggerSource
    {
        public string Source { get; private set; }

        public LoggerSource(string source)
        {
            Source = source;
        }
    }*/
}
