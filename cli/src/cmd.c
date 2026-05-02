#include <cli/cli.h>

const lc_cli_cmd lc_cmds[] = {
    {
        LC_CLI_CMD_HELP,

        lc_cli_cmd_help,

        "help",
        "Provides usage information",

        "--command/-c <str>,--minimal/-m",

        0x0
    },
    {
        LC_CLI_CMD_VERSION,

        lc_cli_cmd_version,

        "version",
        "Provides specific version information",

        "No args",

        0x0
    },

    {
        LC_CLI_CMD_SETUP,

        lc_cli_cmd_setup,

        "setup",
        "Sets up LocalCVE in a directory",

        "--db-only/-db,--cve-git/-cg <str>,--ghsa-git/-gg <str>",

        0x1
    },
    {
        LC_CLI_CMD_SYNC,

        NULL,

        "sync",
        "Synchronises the database",

        "No args",

        0x1
    },
    {
        LC_CLI_CMD_STATUS,

        NULL,

        "status",
        "Gets the status of the database",

        "No args",

        0x1
    },
    {
        LC_CLI_CMD_CONFIG,

        NULL,

        "config",
        "Gets/sets config values",

        "--find/-f <str>, --list/-l, --key/-k <str>, --value/-v <str>",

        0x1
    }
};

const size_t lc_cmds_size = sizeof(lc_cmds) / sizeof(*lc_cmds);