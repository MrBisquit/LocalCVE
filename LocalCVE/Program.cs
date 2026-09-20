using LocalCVE.Core;
using LocalCVE.Core.OSV;
using System.CommandLine;

namespace LocalCVE
{
    internal class Program
    {
        static void Main(string[] args)
        {
            LCVE lcve;

            RootCommand rootCommand = new();
            foreach(ICommand command in ICommand.Commands)
            {
                rootCommand.Subcommands.Add(command.GetCommand());
            }

            rootCommand.Parse(args).Invoke();
        }
    }
}