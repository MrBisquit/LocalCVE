#ifndef LOCALCVE_BACKEND_H
#define LOCALCVE_BACKEND_H

#include <sqlite3.h>

/// @brief No errors
#define LC_OK    (0x000001)
/// @brief There are probably errors
#define LC_ERROR (0x100000)

/// @brief Various setup
/// @return `LC_OK` or `LC_ERROR`
int localcve_prepare(void);

#endif