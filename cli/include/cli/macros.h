#ifndef LOCALCVE_CLI_MACROS_H
#define LOCALCVE_CLI_MACROS_H

#define LC_CLI_INF(m)           CONSOLE_COLOR(CONSOLE_FG_BRIGHT_BLUE) "info" CONSOLE_COLOR_RESET ": " m
#define LC_CLI_WRN(w)           CONSOLE_COLOR(CONSOLE_FG_YELLOW) "warn" CONSOLE_COLOR_RESET ": " w
#define LC_CLI_ERR(e)           CONSOLE_COLOR(CONSOLE_FG_RED) "error" CONSOLE_COLOR_RESET ": " e
#define LC_CLI_CRT(e)           CONSOLE_COLOR(CONSOLE_BG_RED) CONSOLE_COLOR(CONSOLE_FG_BLACK)     \
                                "critical" CONSOLE_COLOR_RESET ": " CONSOLE_COLOR(CONSOLE_FG_RED) \
                                e CONSOLE_COLOR_RESET

#define LC_CLI_INF_UR(f)        LC_CLI_INF(f ": Returned 0x%X but 0x%X was expected")
#define LC_CLI_WRN_UR(f)        LC_CLI_WRN(f ": Returned 0x%X but 0x%X was expected")
#define LC_CLI_ERR_UR(f)        LC_CLI_ERR(f ": Returned 0x%X but 0x%X was expected")
#define LC_CLI_CRT_UR(f)        LC_CLI_CRT(f ": Returned 0x%X but 0x%X was expected")

#define LC_CLI_DBG              __FILE__ ":" STR(__LINE__)
#define LC_CLI_TRC              CONSOLE_COLOR(CONSOLE_FG_BRIGHT_YELLOW) "trace" CONSOLE_COLOR_RESET ": " \
                                LC_CLI_DBG

#define LC_CLI_PRT_INF(m)       printf(LC_CLI_INF(m) "\n")
#define LC_CLI_PRT_WRN(m)       printf(LC_CLI_WRN(m) "\n")
#define LC_CLI_PRT_ERR(m)       printf(LC_CLI_ERR(m) "\n")
#define LC_CLI_PRT_CRT(m)       printf(LC_CLI_CRT(m) "\n")

#define LC_CLI_PRT_INF_T(m)     printf(LC_CLI_INF(m) "\n" LC_CLI_TRC "\n")
#define LC_CLI_PRT_WRN_T(m)     printf(LC_CLI_WRN(m) "\n" LC_CLI_TRC "\n")
#define LC_CLI_PRT_ERR_T(m)     printf(LC_CLI_ERR(m) "\n" LC_CLI_TRC "\n")
#define LC_CLI_PRT_CRT_T(m)     printf(LC_CLI_CRT(m) "\n" LC_CLI_TRC "\n")

#define LC_CLI_PRT_INF_UR(f,e,r) printf(LC_CLI_INF_UR(f) "\n" LC_CLI_TRC "\n", e, r)
#define LC_CLI_PRT_WRN_UR(f,e,r) printf(LC_CLI_WRN_UR(f) "\n" LC_CLI_TRC "\n", e, r)
#define LC_CLI_PRT_ERR_UR(f,e,r) printf(LC_CLI_ERR_UR(f) "\n" LC_CLI_TRC "\n", e, r)
#define LC_CLI_PRT_CRT_UR(f,e,r) printf(LC_CLI_CRT_UR(f) "\n" LC_CLI_TRC "\n", e, r)

#endif