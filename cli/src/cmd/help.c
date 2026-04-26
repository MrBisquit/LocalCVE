#include <cli/cli.h>

int lc_cli_cmd_help(int argc, const char* const* argv) {
    printf("Hi\n");
    return LC_CLI_RET_NOERROR;
}