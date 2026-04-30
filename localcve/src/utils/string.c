#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <localcve/utils/string.h>

int lc_utils_toupper(char* str) {
    if(str == NULL) {
        return 0;
    }

    for(size_t i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }

    return 1;
}

int lc_utils_tolower(char* str) {
    if(str == NULL) {
        return 0;
    }

    for(size_t i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }

    return 1;
}