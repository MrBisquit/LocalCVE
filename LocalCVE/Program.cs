using LocalCVE.Core;
using LocalCVE.Core.OSV;
using System.CommandLine;

namespace LocalCVE
{
    internal class Program
    {
        static void Main(string[] args)
        {
            LocalCVE.Core.LocalCVE lcve = new();

            RootCommand rootCommand = new();
            foreach(ICommand command in ICommand.Commands)
            {
                rootCommand.Subcommands.Add(command.GetCommand());
            }

            rootCommand.Parse(args).Invoke();

            lcve.Dispose();
        }
    }
}