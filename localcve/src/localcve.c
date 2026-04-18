#include <localcve/localcve.h>

int localcve_prepare() {
    

    return LC_OK;
}

int localcve_init(localcve** lCVE, localcve_args args) {
    if(sqlite3_open_v2(
        args.path,
        &((*lCVE)->db),
        SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
        NULL
    ) != SQLITE_OK) {
        return LC_ERROR;
    };

    return LC_OK;
}