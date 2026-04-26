#include <cli/cli.h>

const lc_cli_cmd lc_cmds[] = {
    {
        LC_CLI_CMD_HELP,

        lc_cli_cmd_help,

        "help",
        "Provides usage information",

        "--command/-c <str>",

        0x0
    },
    {
        LC_CLI_CMD_VERSION,

        NULL,

        "version",
        "Provides specific version information",

        "No args",

        0x0
    }
};

const size_t lc_cmds_size = sizeof(lc_cmds) / sizeof(*lc_cmds);