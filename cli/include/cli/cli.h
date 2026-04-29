#ifndef LOCALCVE_CLI_H
#define LOCALCVE_CLI_H

#include <stdio.h>
#include <string.h>
#include <localcve/localcve.h>
#include <cli/ansi_console_small.h>
#include <cli/macros.h>
#include <cli/cmd.h>
#include <cli/args.h>

#define LC_CLI_VER_MAJOR        1
#define LC_CLI_VER_MINOR        0
#define LC_CLI_VER_PATCH        0

#define LC_CLI_VER_STRING       LC_STR(LC_CLI_VER_MAJOR) "." LC_STR(LC_CLI_VER_MINOR) \
                                "." LC_STR(LC_CLI_VER_PATCH)

extern int lc_cli_last;

typedef enum {
    LC_CLI_CMD_HELP             = 0x10,
    LC_CLI_CMD_VERSION          = 0x11,

    LC_CLI_CMD_SETUP            = 0x00,
    LC_CLI_CMD_SYNC             = 0x01,
    LC_CLI_CMD_STATUS           = 0x02,

    LC_CLI_CMD_UNKNOWN          = 0x20
} LC_CLI_CMD;

typedef struct {
    LC_CLI_CMD cmd;

    int (*func)(int, const char* const*);

    const char* name;
    const char* desc;

    const char* arg_string;

    int requires_db;
} lc_cli_cmd;

#define LC_CLI_CMD_NORM         (0x00)
#define LC_CLI_CMD_NODB         (0x10)
#define LC_CLI_CMD_ERR          (0x20)

#define LC_CLI_FLG_NONE         (0x00)
#define LC_CLI_FLG_NODB         (0x01)

#define LC_CLI_CMD_FOUND        (0x0AF000)
#define LC_CLI_CMD_NOTFOUND     (0x0AE000)

#define LC_CLI_RET_NOERROR      (0xA00000)

#define LC_CLI_ARGS_NOERROR     (0x0A0000)
#define LC_CLI_ARGS_UNK_ARG     (0xE00000)
#define LC_CLI_ARGS_UNK_ERR     (0xEEEEEE)
#define LC_CLI_ARGS_PARSE_ERR   (0xE00001)
#define LC_CLI_ARGS_TFA_ERR     (0xE00002) // Too Few Arguments

extern const lc_cli_cmd lc_cmds[];
extern const size_t lc_cmds_size;

int lc_cli_cmd_match(const char* str, LC_CLI_CMD** cmd, int flags);
int lc_cli_cmd_find(LC_CLI_CMD* cmd, lc_cli_cmd** ptr);
int lc_cli_exec(lc_cli_cmd* ptr, int argc, const char* const argv[]);

#endif