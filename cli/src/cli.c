#include <cli/cli.h>

int lc_cli_cmd_match(const char* str, LC_CLI_CMD** cmd, int flags) {
    static const struct {
        const char* name;
        LC_CLI_CMD cmd;

        int nodb;
    } table[] = {
        { "help",       LC_CLI_CMD_HELP,    0x1 },
        { "version",    LC_CLI_CMD_VERSION, 0x1 },

        { "setup",      LC_CLI_CMD_SETUP,   0x0 },
        { "sync",       LC_CLI_CMD_SYNC,    0x0 },
        { "status",     LC_CLI_CMD_STATUS,  0x0 },
        { "config",     LC_CLI_CMD_CONFIG,  0x0 }
    };
    static const size_t table_size = sizeof(table) / sizeof(*table);

    if(str[0] == '-') {
        return LC_CLI_CMD_NOTFOUND;
    }

    for(size_t i = 0; i < table_size; i++) {
        if(strcmp(str, table[i].name) == 0)
            if(flags & LC_CLI_FLG_NODB)
                if(table[i].nodb == 0x1) {
                    *cmd = &(table[i].cmd);
                    return LC_CLI_CMD_FOUND;
                } else
                    return LC_CLI_CMD_NOTFOUND;
            else {
                *cmd = &(table[i].cmd);
                return LC_CLI_CMD_FOUND;
            }
    }

    return LC_CLI_CMD_NOTFOUND;
}

int lc_cli_cmd_find(LC_CLI_CMD* cmd, lc_cli_cmd** ptr) {
    for(size_t i = 0; i < lc_cmds_size; i++) {
        if(lc_cmds[i].cmd == *cmd) {
            *ptr = &lc_cmds[i];
            return LC_CLI_CMD_FOUND;
        }
    }

    return LC_CLI_CMD_NOTFOUND;
}

int lc_cli_exec(lc_cli_cmd* ptr, int argc, const char* const argv[]) {
    int ret = LC_CLI_RET_NOERROR;

    if(ptr == NULL) {
        LC_CLI_PRT_ERR_T("Command is NULL");

        return LC_ERROR;
    }

    if(ptr->func == NULL) {
        LC_CLI_PRT_ERR_T("Command func ptr is NULL");

        return LC_ERROR;
    }

    switch((ret = ptr->func(argc, argv))) {
        case LC_CLI_ARGS_UNK_ARG:
            printf(
                LC_CLI_ERR("Unknown argument(s). Use \"%s help -c %s\" for usage information.") "\n",
                argv[0], argv[1]
            );
            break;
        case LC_CLI_RET_NOERROR:
            break;
        default:
            LC_CLI_PRT_WRN("Unknown return code");
    }

    return ret;
}