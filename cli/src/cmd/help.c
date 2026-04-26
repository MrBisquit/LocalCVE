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
            }
        }
    };

    if(strcmp(argv[1], "help") == 0)
        lc_cli_arg_parse(args, argc, argv, 2);
    else
        lc_cli_arg_parse(args, argc, argv, 3);

    if(args[0].val.STR.val_len == 0) {
        printf("LocalCVE CLI version " LC_CLI_VER_STRING
            "\nLocalCVE backend version " LC_VER_STRING "\n\n");

        printf("For commands that are marked as \"NODB\", you do not need to specify "
            "a path to use.\n\n"
            "Base command usage (NODB):\n"
            "\tlocalcve [subcommand] (...args)\n"
            "Base command usage:\n"
            "\tlocalcve [path] [subcommand] (...args)\n\n"
            "For the path, either specify a valid path, or \"-\" to use the default path.\n\n"
            "Subcommands:\n");

        for(size_t i = 0; i < lc_cmds_size; i++) {
            printf("%s (0x%X)\n", lc_cmds[i].name, lc_cmds[i].cmd);
            printf("\tNODB: %s\n", lc_cmds[i].requires_db == 0 ? "Yes" : "No");
            printf("\tDescription:%s\n", lc_cmds[i].desc);
            printf("\tArgs: %s\n", lc_cmds[i].arg_string);
            printf("\tExample: %s %s (%s)\n\n", argv[0], lc_cmds[i].name, lc_cmds[i].arg_string);
        }
    } else {
        
    }

    return LC_CLI_RET_NOERROR;
}