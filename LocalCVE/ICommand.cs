using System;
using System.Collections.Generic;
using System.CommandLine;
using System.Text;

namespace LocalCVE
{
    public interface ICommand
    {
        public static ICommand[] Commands =
        {
            new LocalCVE.Commands.Setup()
        };

        public Command GetCommand();
    }
}
