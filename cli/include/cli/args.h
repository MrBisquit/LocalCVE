#ifndef LOCALCVE_CLI_ARGS_H
#define LOCALCVE_CLI_ARGS_H

typedef enum {
    LC_CLI_ARG_TYPE_STR     = 0x00,     // String
    LC_CLI_ARG_TYPE_INT     = 0x01,     // Integer
    LC_CLI_ARG_TYPE_FLT     = 0x02,     // Float
    LC_CLI_ARG_TYPE_FLG     = 0x03,     // Flag
    LC_CLI_ARG_TYPE_PRE     = 0x04      // Pre-defined options  Follows on 0x00
} LC_CLI_ARG_TYPE;

typedef struct {
    const char* def;

    int val_len;
    char* val;
} LC_CLI_ARG_STR;

typedef struct {
    int def;

    int min;
    int max;

    int val;
} LC_CLI_ARG_INT;

typedef struct {
    float def;

    float min;
    float max;

    float val;
 } LC_CLI_ARG_FLT;

typedef struct {
    int def;

    int val;
} LC_CLI_ARG_FLG;

typedef struct {
    int def;

    const char** opts;

    int val;
} LC_CLI_ARG_PRE;

typedef union {
    // These are only caps because int is reserved so it had to be different and it annoyed me
    LC_CLI_ARG_STR STR;
    LC_CLI_ARG_INT INT;
    LC_CLI_ARG_FLT FLT;
    LC_CLI_ARG_FLG FLG;
    LC_CLI_ARG_PRE PRE;
} LC_CLI_ARG_VALUE;

typedef struct {
    const char* name;                   // E.g. "help"
    const char* small;                  // E.g. "h"

    LC_CLI_ARG_VALUE val;
    LC_CLI_ARG_TYPE type;
} LC_CLI_ARG;

int lc_cli_arg_parse_str(LC_CLI_ARG_STR* arg, const char* next);
int lc_cli_arg_parse_int(LC_CLI_ARG_INT* arg, const char* next);
int lc_cli_arg_parse_flt(LC_CLI_ARG_FLT* arg, const char* next);
int lc_cli_arg_parse_flg(LC_CLI_ARG_FLG* arg, const char* next);
int lc_cli_arg_parse_pre(LC_CLI_ARG_PRE* arg, const char* next);

int lc_cli_arg_parse(LC_CLI_ARG* args, size_t c, int argc, const char* const* argv, int start);

#endif