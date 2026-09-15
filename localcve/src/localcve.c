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
    if(*lCVE == NULL) {
        *lCVE = malloc(sizeof(localcve));
    }

    // Create paths based on the base path
    (*lCVE)->db_path = lc_utils_path_combine(args.path, "LocalCVE.db");

    printf("%s\n", (*lCVE)->db_path);

    if(sqlite3_open_v2(
        (*lCVE)->db_path,
        &((*lCVE)->db),
        SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
        NULL
    ) != SQLITE_OK) {
        return LC_ERROR;
    };

    return LC_OK;
}

int localcve_deinit(localcve** lCVE) {
    /*printf("1\n");
    if(*lCVE == NULL) {
        return LC_OK;
    }
    printf("2\n");
    if((*lCVE)->db_path) {
        free((*lCVE)->db_path);
    }
    printf("3\n");
    if((*lCVE)->cve_path) {
        free((*lCVE)->cve_path);
    }
    printf("4\n");
    if((*lCVE)->ghsa_path) {
        free((*lCVE)->ghsa_path);
    }
    printf("5\n");
    if((*lCVE)->db) {
        if(sqlite3_close(&((*lCVE)->db)) != SQLITE_OK) {
            return LC_ERROR;
        }
    }
    printf("6\n");
    free(*lCVE);
    printf("7\n");*/
    return LC_OK;
}

int localcve_setup(localcve* lCVE) {

    return LC_OK;
}

int localcve_status(localcve* lCVE) {

    return LC_OK;
}

int localcve_is_error(int code) {
    // Basically just checks if the code contains LC_ERROR, or LC_OK
    return code & LC_ERROR ? LC_ERROR : code & LC_OK ? LC_OK : LC_UNKNOWN;
}