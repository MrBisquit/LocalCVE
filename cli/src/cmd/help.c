#include <cli/cli.h>

int lc_cli_cmd_help(int argc, const char* const* argv) {
    LC_CLI_ARG args[] = {
        {
            "command",
            "c",

            (LC_CLI_ARG_VALUE){
                (LC_CLI_ARG_STR){
                    "",

                    0,
                    NULL
                }
            },
            LC_CLI_ARG_TYPE_STR
        }
    };
    size_t args_count = sizeof(args) / sizeof(*args);

    int ret = LC_CLI_ARGS_NOERROR;
    if(strcmp(argv[1], "help") == 0)
        ret = lc_cli_arg_parse(args, args_count, argc, argv, 2);
    else
        ret = lc_cli_arg_parse(args, args_count, argc, argv, 3);

    if(ret != LC_CLI_ARGS_NOERROR)
        return ret;

    #define CC(c) CONSOLE_COLOR(c)
    #define CCR CONSOLE_COLOR_RESET
    #define FG_BLUE CONSOLE_FG_BRIGHT_BLUE
    #define FG_WHITE CONSOLE_FG_BRIGHT_WHITE

    if(args[0].val.STR.val_len == 0) {
        printf("LocalCVE CLI version " LC_CLI_VER_STRING
            "\nLocalCVE backend version " LC_VER_STRING "\n\n");

        printf("For commands that are marked as \"NODB\", you do not need to specify "
            "a path to use.\n\n"
            "Base command usage (NODB):\n"
            CC(FG_WHITE) "\tlocalcve [subcommand] (...args)\n" CCR
            "Base command usage:\n"
            CC(FG_WHITE) "\tlocalcve [path] [subcommand] (...args)\n\n" CCR
            "For the path, either specify a valid path, or \"-\" to use the default path.\n\n"
            "Subcommands:\n");

        for(size_t i = 0; i < lc_cmds_size; i++) {
            printf(CC(FG_WHITE) "%s" CCR " (0x%X)\n", lc_cmds[i].name, lc_cmds[i].cmd);
            printf(CC(FG_WHITE) "\tNODB:" CCR " %s\n", lc_cmds[i].requires_db == 0 ? "Yes" : "No");
            printf(CC(FG_WHITE) "\tDescription:" CCR " %s\n", lc_cmds[i].desc);
            printf(CC(FG_WHITE) "\tArgs:" CCR " %s\n", lc_cmds[i].arg_string);
            printf(CC(FG_WHITE) "\tExample:" CCR " %s %s (%s)\n", argv[0],
                lc_cmds[i].name, lc_cmds[i].arg_string);
        }
    } else {
        
    }

    return LC_CLI_RET_NOERROR;
}