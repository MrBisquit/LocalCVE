#include <localcve/localcve.h>

int localcve_prepare() {
    if(git_libgit2_init() < 0) {
        return LC_ERROR;
    }

    return LC_OK;
}

int localcve_clean() {
    if(git_libgit2_shutdown() < 0) {
        return LC_ERROR;
    }

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

int localcve_is_error(int code) {
    // Basically just checks if the code contains LC_ERROR, or LC_OK
    return code & LC_ERROR ? LC_ERROR : code & LC_OK ? LC_OK : LC_UNKNOWN;
}