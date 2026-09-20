using System;
using System.Collections.Generic;
using System.Text;

namespace LocalCVE.Core
{
    public static class Paths
    {
        public static string GlobalDataPath
        {
            get { return Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData); }
        }
        public static string GlobalLocalPath
        {
            get { return Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData); }
        }

        /// <summary>
        /// Base LocalCVE path, defaults to application data.
        /// (%appdata%/LocalCVE)
        /// </summary>
        public static string BasePath = Path.Combine(GlobalDataPath, "LocalCVE");

        /// <summary>
        /// LocalCVE data path, can be changed. Defaults to application data.
        /// (BasePath/Data or %appdata%/LocalCVE/Data)
        /// </summary>
        public static string DataPath = Path.Combine(BasePath, "Data");

        public static string LogsPath
        {
            get { return GetLogsPath(); }
        }

        public static string GlobalLogsPath
        {
            get { return GetGlobalLogsPath(); }
        }

        internal static string GetLogsPath()
        {
            return Path.Combine(BasePath, "Logs");
        }

        internal static string GetGlobalLogsPath()
        {
            return Path.Combine(GlobalLocalPath, "Logs");
        }
    }
}
