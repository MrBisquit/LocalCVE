#include <localcve/utils/string.h>
#include <cli/cli.h>

int lc_cli_arg_parse_str(LC_CLI_ARG_STR* arg, const char* next) {
    if(strlen(next) > 0) {
        arg->val = malloc(sizeof(next));
        strcpy(arg->val, next);
        arg->val_len = strlen(next);
    }
    return LC_CLI_ARGS_NOERROR;
}

int lc_cli_arg_parse_int(LC_CLI_ARG_INT* arg, const char* next) {
    errno = 0;
    char* endptr;

    long val = strtol(next, &endptr, 10);
    if(endptr == next || *endptr != '\0') {
        return LC_CLI_ARGS_PARSE_ERR;
    }

    arg->val = (int)val;
    if(arg->min > arg->val || arg->max < arg->val) {
        return LC_CLI_ARGS_INT_OOB_ERR;
    }

    return LC_CLI_ARGS_NOERROR;
}

int lc_cli_arg_parse_flt(LC_CLI_ARG_FLT* arg, const char* next) {
    errno = 0;
    char* endptr;

    float val = strtof(next, &endptr);
    if(endptr == next || *endptr != '\0') {
        return LC_CLI_ARGS_PARSE_ERR;
    }

    arg->val = (int)val;
    if(arg->min > arg->val || arg->max < arg->val) {
        return LC_CLI_ARGS_INT_OOB_ERR;
    }

    return LC_CLI_ARGS_NOERROR;
}

int __lc_cli_is_true(char* str) {
    if(str == NULL || strlen(str) == 0) {
        return 0;
    }

    if(strcmp(str, "1") == 0 ||
        strcmp(str, "true") == 0 ||
        strcmp(str, "on") == 0 ||
        strcmp(str, "yes") == 0 ||
        strcmp(str, "y") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int __lc_cli_is_false(char* str) {
    if(str == NULL || strlen(str) == 0) {
        return 0;
    }

    if(strcmp(str, "0") == 0 ||
        strcmp(str, "false") == 0 ||
        strcmp(str, "off") == 0 ||
        strcmp(str, "no") == 0 ||
        strcmp(str, "n") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int lc_cli_arg_parse_flg(LC_CLI_ARG_FLG* arg, const char* next) {
    if(next == NULL) {
        arg->val = arg->def == 1 ? 0 : 1;
        return LC_CLI_ARGS_NOERROR;
    }

    if(lc_utils_tolower(next) != 1) {
        return LC_CLI_ARGS_PARSE_ERR;
    }

    int is_true = __lc_cli_is_true(next);
    int is_false = __lc_cli_is_false(next);

    if(!is_true && !is_false) {
        arg->val = arg->def == 1 ? 0 : 1;
    } else if(is_true || is_false) {
        arg->val = is_true ? 1 : is_false ? 0 : 2;
    } else {
        arg->val = 2;
        return LC_CLI_ARGS_FLG_UNK;
    }

    return LC_CLI_ARGS_NOERROR;
}

int lc_cli_arg_parse_pre(LC_CLI_ARG_PRE* arg, const char* next) {
    /// @todo lc_cli_arg_parse_pre implementation

    return LC_CLI_ARGS_NOERROR;
}

int lc_cli_arg_parse(LC_CLI_ARG* args, size_t c, int argc, const char* const* argv, int start) {
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