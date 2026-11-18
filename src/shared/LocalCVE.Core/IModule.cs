using Microsoft.Extensions.DependencyInjection;
using System;
using System.Collections.Generic;
using System.Text;

namespace LocalCVE.Core
{
    /// <summary>
    /// The interface that all modules are based off of
    /// </summary>
    public interface IModule
    {
        public void Init(IServiceCollection services);

        public void Shutdown();
    }
}
