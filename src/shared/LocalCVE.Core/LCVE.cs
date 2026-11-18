using LocalCVE.Core.Database;
using System;
using System.Collections.Generic;
using System.Text;

namespace LocalCVE.Core
{
    public class LocalCVE : IDisposable
    {
        public DatabaseManager DBManager;

        public LocalCVE()
        {
            Directory.CreateDirectory(Paths.DataPath);
            Directory.CreateDirectory(Paths.LogsPath);
            Directory.CreateDirectory(Paths.GlobalLogsPath);

            Logger.Setup();
            Logger.Log(null, "INFO", $"Global log directory: {Paths.GlobalLogsPath}", null);
            Logger.Log(null, "INFO", $"Local log directory: {Paths.LogsPath}", null);

            //Directory.CreateDirectory(Path.Combine(Paths.DataPath, "CVEListV5"));
            //LibGit2Sharp.Repository.Clone("https://github.com/CVEProject/cvelistV5", Path.Combine(Paths.DataPath, "CVEListV5"));
        }

        public void Dispose()
        {
            Logger.Shutdown();
        }
    }
}
