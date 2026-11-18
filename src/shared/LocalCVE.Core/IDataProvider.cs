using System;
using System.Collections.Generic;
using System.Text;

namespace LocalCVE.Core
{
    public interface IDataProvider
    {
        public static Dictionary<string, IDataProvider> DataProviders = new();

        /// <summary>
        /// This method should do anything required for the initial setup
        /// of the data provider.
        /// Each data provider gets given a directory, all data must be put
        /// into this directory.
        /// 
        /// During this stage, the data provider should load any configuration
        /// neccecary, and report any missing configuration.
        /// 
        /// Logs, errors, and warnings should all go through the main logger.
        /// </summary>
        /// <param name="path">The data directory for the data provider</param>
        public void Setup(string path);
    }
}
