#include <cli/cli.h>

int lc_cli_cmd_setup(int argc, const char* const* argv) {
    #define CC(c) CONSOLE_COLOR(c)
    #define CCR CONSOLE_COLOR_RESET
    #define FG_BLUE CONSOLE_FG_BRIGHT_BLUE
    #define FG_WHITE CONSOLE_FG_BRIGHT_WHITE
    #define FG_YELLOW CONSOLE_FG_BRIGHT_YELLOW

    if(argc == -1) {
        printf("The setup command is used to set up a fresh LocalCVE instance, this "
            "command should " CC(FG_WHITE) "ONLY " CCR
            "be used when you do not wish to keep any of the data, or configuration.\n"
            "If you wish instead to reset the database, without changing any configuration "
            "please use the \"--db-only\" flag.");

        return LC_CLI_RET_NOERROR;
    }

    LC_CLI_ARG args[] = {
        {
            "db-only",
            "db",

            (LC_CLI_ARG_VALUE){
                .FLG = (LC_CLI_ARG_FLG){
                    0,

                    0
                }
            },
            LC_CLI_ARG_TYPE_FLG
        },
        {
            "cve-git",
            "cg",

            (LC_CLI_ARG_VALUE){
                .STR = (LC_CLI_ARG_STR){
                    "https://github.com/CVEProject/cvelistV5.git",

                    0,
                    NULL
                }
            },
            LC_CLI_ARG_TYPE_STR
        },
        {
            "ghsa-git",
            "gg",

            (LC_CLI_ARG_VALUE){
                .STR = (LC_CLI_ARG_STR){
                    "https://github.com/github/advisory-database.git",

                    0,
                    NULL
                }
            },
            LC_CLI_ARG_TYPE_STR
        }
    };
    size_t args_count = sizeof(args) / sizeof(*args);

    int ret = lc_cli_arg_parse(args, args_count, argc, argv, 3);

    if(ret != LC_CLI_ARGS_NOERROR)
        return ret;

    LC_CLI_PRT_INF("Fetching data path");

    char* data_path = NULL;

    if(!lc_cli_get_data_dir(&data_path, argv[1])) {
        LC_CLI_PRT_ERR_T("Couldn't fetch information");
        return LC_CLI_RET_ERROR;
    } else {
        printf(LC_CLI_INF("Found data path: %s") "\n", data_path);
    }

    localcve* lCVE = NULL;
    /*localcve_args* lCVE_args = malloc(sizeof(localcve_args));
    lCVE_args->path = malloc(sizeof(data_path));
    memcpy(lCVE_args->path, data_path, sizeof(data_path));*/

    localcve_args lCVE_args = {
        .path = strdup(data_path)
    };
    localcve_init(&lCVE, lCVE_args);

    if(args[0].val.FLG.val) {
        LC_CLI_PRT_INF("Skipping checks, and configuration setup");
    } else {
        // The majority of the below is handled by the LocalCVE backend

        LC_CLI_PRT_INF("(1/4) Performing checks...");
        // Check if the directory even exists
        if(!lc_platform_dir_exist(data_path)) {
            LC_CLI_PRT_INF("\tCreating directory");
            lc_platform_dir_create(data_path);
        }
        // Clean up any existing folders within
        // Clean up any existing files within

        LC_CLI_PRT_INF("(2/4) Setting up configuration...");
        // Create configuration file
        // Set defaults
        // Set information passed in parameters

        LC_CLI_PRT_INF("(3/4) Setting up database...");
        // Create database tables
        //char* db_path = lc_utils_path_combine(data_path, "localcve.db");
        /*if(localcve_setup_database(lCVE) != LC_OK) {
            LC_CLI_PRT_ERR_UR(STR(localcve_setup_database), LC_OK, LC_ERROR);
            return 1;
        }*/

        LC_CLI_PRT_INF("(4/4) Finishing up...");
        // Remove any files, including any lock files present

        printf(LC_CLI_INF("Use \"%s sync\" to pull data from the databases") "\n", argv[0]);
    }

    return LC_CLI_RET_NOERROR;
}