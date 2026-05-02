#include <cli/cli.h>

int lc_cli_cmd_help(int argc, const char* const* argv) {
    if(argc == -1) {
        printf("No command-specific usage information.");

        return LC_CLI_RET_NOERROR;
    }

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
        },
        {
            "minimal",
            "m",

            (LC_CLI_ARG_VALUE){
                .FLG = (LC_CLI_ARG_FLG){
                    0,

                    0
                }
            },
            LC_CLI_ARG_TYPE_FLG
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
    #define FG_YELLOW CONSOLE_FG_BRIGHT_YELLOW

    if(args[0].val.STR.val_len == 0) {
        if(args[1].val.FLG.val == 0) {
            printf("LocalCVE CLI version " LC_CLI_VER_STRING
                "\nLocalCVE backend version " LC_VER_STRING "\n\n");

            if(strcmp(argv[1], "help") != 0) {
                printf("For the command that you ran, the following path would be "
                    "provided: " CC(FG_WHITE));

                char* data_path = NULL;

                if(lc_cli_get_data_dir(&data_path, argv[1])) {
                    printf("%s\n", data_path);
                } else {
                    LC_CLI_PRT_WRN("Couldn't fetch information");
                }

                printf(CCR);
            }

            printf("For commands that are marked as \"NODB\", you do not need to specify "
                "a path to use.\n\n"
                "Base command usage (NODB):\n"
                CC(FG_WHITE) "\tlocalcve [subcommand] (...args)\n" CCR
                "Base command usage:\n"
                CC(FG_WHITE) "\tlocalcve [path] [subcommand] (...args)\n\n" CCR
                "For the path, either specify a valid path, or \"-\" to use the default path.\n\n"
                "Subcommands:\n");
        }

        for(size_t i = 0; i < lc_cmds_size; i++) {
            printf(CC(FG_WHITE) "%s" CCR " (0x%X)\n", lc_cmds[i].name, lc_cmds[i].cmd);
            printf(CC(FG_WHITE) "\tNODB:" CCR " %s\n", lc_cmds[i].requires_db == 0 ? "Yes" : "No");
            printf(CC(FG_WHITE) "\tDescription:" CCR " %s\n", lc_cmds[i].desc);
            printf(CC(FG_WHITE) "\tArgs:" CCR " %s\n", lc_cmds[i].arg_string);
            if(args[1].val.FLG.val == 0) {
                printf(CC(FG_WHITE) "\tExample:" CCR " %s%s%s (%s)\n", argv[0],
                        lc_cmds[i].requires_db ? " - " : " ", lc_cmds[i].name, lc_cmds[i].arg_string);
            }
            if(lc_cmds[i].func == NULL)
                printf(CC(FG_YELLOW) "\tNOT IMPLEMENTED" CCR "\n");
        }
    } else {
        for(size_t i = 0; i < lc_cmds_size; i++) {
            if(strcmp(lc_cmds[i].name, args[0].val.STR.val) == 0) {
                printf("Usage for " CC(FG_WHITE) "%s" CCR " command:\n", lc_cmds[i].name);

                printf(CC(FG_WHITE) "\tNODB:" CCR " %s\n", lc_cmds[i].requires_db == 0 ? "Yes" : "No");
                printf(CC(FG_WHITE) "\tDescription:" CCR " %s\n", lc_cmds[i].desc);
                printf(CC(FG_WHITE) "\tArgs:" CCR " %s\n", lc_cmds[i].arg_string);
                if(args[1].val.FLG.val == 0) {
                    printf(CC(FG_WHITE) "\tExample:" CCR " %s%s%s (%s)\n", argv[0],
                        lc_cmds[i].requires_db ? " - " : " ", lc_cmds[i].name, lc_cmds[i].arg_string);
                }
                if(lc_cmds[i].func == NULL)
                    printf(CC(FG_YELLOW) "\tNOT IMPLEMENTED" CCR "\n");
                else
                    printf("\n");

                printf(CC(FG_WHITE) "Command-specific usage:\n" CCR);
                lc_cmds[i].func(-1, NULL);
                printf("\n");

                return LC_CLI_RET_NOERROR;
            }
        }

        LC_CLI_PRT_WRN_T("Failed to find command, check that it exists");
        return LC_CLI_RET_ERROR;
    }

    return LC_CLI_RET_NOERROR;
}