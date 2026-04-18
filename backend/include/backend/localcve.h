#ifndef LOCALCVE_LOCALCVE_H
#define LOCALCVE_LOCALCVE_H

#include <sqlite3.h>

typedef struct {
    sqlite3* db;
} localcve;

#endif