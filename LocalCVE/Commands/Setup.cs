using System;
using System.Collections.Generic;
using System.CommandLine;
using System.Text;

namespace LocalCVE.Commands
{
    public class Setup : ICommand
    {
        public Command GetCommand()
        {
            Command cmd = new(
                "setup",
                "Sets up LocalCVE."
            );

            Option<string> yeah = new("--a", "--b");
            cmd.Options.Add(yeah);

            cmd.SetAction(Run);

            return cmd;
        }

        public void Run(ParseResult? result)
        {
            
        }
    }
}
