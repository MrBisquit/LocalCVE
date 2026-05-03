#if !defined(WIN32) && !defined(WIN64)

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <malloc.h>
#include <localcve/platform/platform.h>

// Utils
static void __expand_home(const char* path, char* out, size_t out_size) {
    if(path[0] == '~') {
        const char* home = getenv("HOME");
        if(!home) {
            struct passwd* pw = getpwuid(getuid());
            home = pw ? pw->pw_dir : "";
        }
        snprintf(out, out_size, "%s%s", home, path + 1);
    } else {
        snprintf(out, out_size, "%s", path);
    }
}

int lc_platform_get_data_dir(char** path) {
    char buffer[1024];

    const char* env = getenv("XDG_DATA_HOME");
    if(env) {
        __expand_home(env, buffer, sizeof(buffer));
    } else {
        __expand_home("~/.local/share/", buffer, sizeof(buffer));
    }

    *path = strdup(buffer);
	if (!*path) return LC_PLAT_RET_NOERROR;

    return LC_PLAT_RET_NOERROR;
}

int lc_platform_dir_exist(const char* path) {
    struct stat stats;

    if(stat(path, &stats) == 0 && S_ISDIR(stats.st_mode)) {
        return 1;
    }

    return 0;
}

int lc_platform_dir_create(const char* path) {
    mkdir(path, 0755);

    return LC_PLAT_RET_NOERROR;
}

int lc_platform_dir_delete(const char* path) {

}

#endif