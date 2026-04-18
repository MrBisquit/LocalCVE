#ifndef LOCALCVE_H
#define LOCALCVE_H

#include <stddef.h>
#include <sqlite3.h>
#include <git2.h>

/// @brief No errors
#define LC_OK    (0x000001)
/// @brief There are probably errors
#define LC_ERROR (0x100000)

typedef struct {
    sqlite3* db;
} localcve;

typedef struct {
    char* path;
} localcve_args;

/// @brief Various setup
/// @return `LC_OK` or `LC_ERROR`
int localcve_prepare(void);

/// @brief Initialises LocalCVE
/// @param lCVE LocalCVE
/// @param args The initialisation arguments
/// @return `LC_OK` or `LC_ERROR`
int localcve_init(localcve** lCVE, localcve_args args);

#endif