#include <cli/cli.h>

/**
    \section lcvecli-usage Usage

    localcve [subcommand] (...args)
        help        Provides usage information
            (cmd)   Optional command parameter for command-specific information
        version     Provides version information

    ---------------------------------------------------------------------------

    localcve [path] [subcommand] (...args)
        setup       Sets up the database
        sync        Synchronises the database
        status      Gets the status of the database
        config      Gets/sets configuration

    [path] can either be a path, or "-" to use the default path
*/

int lc_cli_last = LC_OK;

int main(int argc, const char* const argv[]) {
    if(argc == 1) {
        printf(
            "LocalCVE CLI version " LC_CLI_VER_STRING
            "\nLocalCVE backend version " LC_VER_STRING
            "\n\n"
            "Run with \"help\" for usage information, or \"version\" for more "
            "in-depth version information."
            "\n"
        );

        return 0;
    }

    LC_CLI_CMD* cmd = NULL;
    lc_cli_cmd* match = NULL;

    if((lc_cli_last = lc_cli_cmd_match(argv[1], &cmd, LC_CLI_FLG_NODB)) & LC_CLI_CMD_FOUND) {
        if((lc_cli_last = lc_cli_cmd_find(cmd, &match)) & LC_CLI_CMD_FOUND) {
            if((lc_cli_last = lc_cli_exec(match, argc, argv)) == LC_CLI_RET_NOERROR) {
                return 0;
            } else {
                LC_CLI_PRT_INF_UR("lc_cli_exec", lc_cli_last, LC_CLI_RET_NOERROR);
                return 1;
            }
        } else {
            LC_CLI_PRT_WRN("Command recognised, but couldn't be found\n");
        }
    }

    if((lc_cli_last = localcve_prepare()) != LC_OK) {
        LC_CLI_PRT_CRT_UR("localcve_prepare", lc_cli_last, LC_OK);
        //printf(LC_CLI_CRT_UR("localcve_prepare") "\n" LC_CLI_TRC "\n", lc_cli_last, LC_OK);
        /*printf(LC_CLI_CRT("\"localcve_prepare\" returned 0x%X when " STR(LC_OK) " was expected\n"),
            lc_cli_last);*/
        return 1;
    }

    if((lc_cli_last = lc_cli_cmd_match(argv[1], &cmd, LC_CLI_FLG_NONE)) & LC_CLI_CMD_FOUND) {
        if((lc_cli_last = lc_cli_cmd_find(cmd, &match)) & LC_CLI_CMD_FOUND) {
            if((lc_cli_last = lc_cli_exec(match, argc, argv)) == LC_CLI_RET_NOERROR) {
                return 0;
            } else {
                LC_CLI_PRT_INF_UR("lc_cli_exec", lc_cli_last, LC_CLI_RET_NOERROR);
                return 1;
            }
        } else {
            LC_CLI_PRT_WRN("Command recognised, but couldn't be found\n");
        }
    }

    if((lc_cli_last = localcve_clean()) != LC_OK) {
        LC_CLI_PRT_ERR_UR("localcve_clean", lc_cli_last, LC_OK);
        return 1;
    }
    
    return 0;
}