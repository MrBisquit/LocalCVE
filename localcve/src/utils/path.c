#include <localcve/utils/path.h>

char* lc_utils_path_combine(char* a, char* b) {
    int has_trailing = a[strlen(a) - 1] == LC_SEP[0]; // Check if A ends with the value of `LC_SEP`
    int has_leading = b[0] == LC_SEP[0]; // Check if B starts with the value of `LC_SEP`
    int has_both = has_trailing && has_leading;

    int needs_sep = !has_trailing && !has_leading && !has_both;

    size_t total = strlen(a) +
        strlen(b) +
        (has_trailing || has_leading && !has_both ? strlen(LC_SEP) : 0) +
        (has_both ? -strlen(LC_SEP) : 0)
        + 1; // for '\0'

    /*char* buffer = malloc(sizeof(char) * total);
    strcpy(buffer, a);*/
    char* buffer = strdup(a);

    if(needs_sep) {
        strcat(buffer, LC_SEP);
    }

    if(has_both) {
        b++; // Basically, skip the leading separater
    }

    strcat(buffer, b);

    return buffer;
}

int lc_utils_path_is_default(char* path) {
    return strlen(path) == 1 && path[0] == '-' ? 0x1 : 0x0;
}

int lc_utils_generate_default(char** path) {
    // Generate the default path

    
}