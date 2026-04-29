#include <cli/cli.h>

int lc_cli_cmd_version(int argc, const char* const* argv) {
    #define CC(c) CONSOLE_COLOR(c)
    #define CCR CONSOLE_COLOR_RESET
    #define WHITE CONSOLE_FG_BRIGHT_WHITE

    printf("LocalCVE CLI\t\t" CC(WHITE) LC_CLI_VER_STRING CCR
        "\nLocalCVE backend\t" CC(WHITE) LC_VER_STRING CCR "\n\n");

    printf("Dependencies:\n");
    printf("\tsqlite\t\t" CC(WHITE) SQLITE_VERSION CCR " (" STR(SQLITE_VERSION_NUMBER) ")\n");
    printf("\tlibgit2\t\t" CC(WHITE) LIBGIT2_VERSION CCR "\n\n");

    printf("Built on " CC(WHITE) __DATE__ CCR " at " CC(WHITE) __TIME__ CCR "\n");

    return LC_CLI_RET_NOERROR;
}