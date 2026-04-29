#include <cli/cli.h>

int lc_cli_arg_parse_str(LC_CLI_ARG_STR* arg, const char* next) {
    return LC_CLI_ARGS_NOERROR;
}

int lc_cli_arg_parse_int(LC_CLI_ARG_INT* arg, const char* next) {
    return LC_CLI_ARGS_NOERROR;
}

int lc_cli_arg_parse_flt(LC_CLI_ARG_FLT* arg, const char* next) {
    return LC_CLI_ARGS_NOERROR;
}

int lc_cli_arg_parse_flg(LC_CLI_ARG_FLG* arg, const char* next) {
    return LC_CLI_ARGS_NOERROR;
}

int lc_cli_arg_parse_pre(LC_CLI_ARG_PRE* arg, const char* next) {
    return LC_CLI_ARGS_NOERROR;
}

int lc_cli_arg_parse(LC_CLI_ARG* args, size_t c, int argc, const char* const* argv, int start) {
    /**
        \section args How args work
        \paragraph
            This iterates through all of the provided arguments, tries to find the
            corresponding argument, and if it cannot find it, returns an
            LC_CLI_ARGS_UK_ARG error
    */

    for(size_t i = start; i < argc; i++) {
        // Check if it starts with a dash
        if(argv[i][0] != '-')
            return LC_CLI_ARGS_UNK_ARG;
        
        // Check if it's a long string
        int lng = argv[i][1] == '-' ? 1 : 0;

        char* arg = malloc(strlen(argv[i]) - (lng ? 2 : 1) + 1);
        strcpy(arg, argv[i] + (lng ? 2 : 1));

        LC_CLI_ARG* _arg = NULL;

        // Now try to find it
        for(size_t j = 0; j < c; j++) {
            if(lng) {
                if(strcmp(args[j].name, arg) == 0) {
                    _arg = &args[j];
                    break;
                }
            }
            else {
                if(strcmp(args[j].small, arg) == 0) {
                    _arg = &args[j];
                    break;
                }
            }
        }

        free(arg);

        if(_arg == NULL) {
            LC_CLI_PRT_WRN_T("Failed to find argument, expect unexpected behaviour");
            return LC_CLI_ARGS_UNK_ERR;
        }

        // Then parse stuff
        int ret = LC_CLI_ARGS_NOERROR;
        switch(_arg->type) {
            case LC_CLI_ARG_TYPE_STR:
                if(i + 1 >= argc) return LC_CLI_ARGS_TFA_ERR;

                ret = lc_cli_arg_parse_str(&(_arg->val.STR), argv[i + 1]);
                i++;
                break;
            case LC_CLI_ARG_TYPE_INT:
                if(i + 1 >= argc) return LC_CLI_ARGS_TFA_ERR;

                ret = lc_cli_arg_parse_int(&(_arg->val.INT), argv[i + 1]);
                i++;
                break;
            case LC_CLI_ARG_TYPE_FLT:
                if(i + 1 >= argc) return LC_CLI_ARGS_TFA_ERR;

                ret = lc_cli_arg_parse_flt(&(_arg->val.FLT), argv[i + 1]);
                i++;
                break;
            case LC_CLI_ARG_TYPE_FLG:
                if(i + 1 < argc && argv[i + 1][0] != '-') {
                    lc_cli_arg_parse_flg(&(_arg->val.FLG), argv[i + 1]);
                    i++;
                } else {
                    lc_cli_arg_parse_flg(&(_arg->val.FLG), NULL);
                }
                break;
            case LC_CLI_ARG_TYPE_PRE:
                if(i + 1 >= argc) return LC_CLI_ARGS_TFA_ERR;

                ret = lc_cli_arg_parse_pre(&(_arg->val.PRE), argv[i + 1]);
                i++;
                break;
            default:
                return LC_CLI_ARGS_UNK_ERR;
        }

        if(ret != LC_CLI_ARGS_NOERROR)
            return ret;
    }
    
    return LC_CLI_ARGS_NOERROR;
}