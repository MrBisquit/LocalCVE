#if defined(WIN32) || defined(WIN64)

#include <windows.h>
#include <shlobj.h>
#include <string.h>
#include <malloc.h>
#include <localcve/platform/platform.h>

int lc_platform_get_data_dir(char** path) {
    char* out;

    if (!SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, out))) {
		strcpy(out, "C:\\Users\\Default\\AppData\\Roaming");
	}
    
    *path = malloc(strlen(out) + 1);
    strcpy(*path, out);

    return LC_PLAT_RET_NOERROR;
}

int lc_platform_dir_exist(const char* path) {
    DWORD attributes = GetFileAttributesA(path);

    if (attributes == INVALID_FILE_ATTRIBUTES) {
        return 0;
    }

    return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

int lc_platform_dir_create(const char* path) {
    SHCreateDirectoryEx(NULL, path, NULL);

    return LC_PLAT_RET_NOERROR;
}

int lc_platform_dir_delete(const char* path) {

}

#endif