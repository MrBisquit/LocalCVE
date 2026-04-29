#ifndef LOCALCVE_UTILS_PATH_H
#define LOCALCVE_UTILS_PATH_H

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <localcve/defs.h>

char* lc_utils_path_combine(char* a, char* b);
//int lc_utils_has_lead_sep(char* str);
//int lc_utils_has_trail_sep(char* str);

int lc_utils_path_is_default(char* path);

#endif