#ifndef LOCALCVE_H
#define LOCALCVE_H

#include <stddef.h>
#include <sqlite3.h>
#include <git2.h>

#include <localcve/defs.h>
#include <localcve/config.h>
#include <localcve/platform/platform.h>

#include <localcve/utils/path.h>
#include <localcve/utils/string.h>

typedef struct {
    sqlite3* db;
    localcve_config config;

    char* db_path;
    char* cve_path;
    char* ghsa_path;
} localcve;

typedef struct {
    /// @brief The base path for the repository stuff
    char* path;
} localcve_args;

/// @brief Various setup
/// @return `LC_OK` or `LC_ERROR`
int localcve_prepare(void);

/// @brief Clean things like libgit2 up
/// @return `LC_OK` or `LC_ERROR`
int localcve_clean(void);

/// @brief Initialises LocalCVE
/// @param lCVE LocalCVE
/// @param args The initialisation arguments
/// @return `LC_OK` or `LC_ERROR`
int localcve_init(localcve** lCVE, localcve_args args);

/// @brief Sets the LocalCVE configuration up
/// @note This should only be run if there is no pre-existing
///       LocalCVE setup
/// @warning This will entirely remove all configuration data,
///          this is irreversible
/// @param lCVE LocalCVE
/// @return `LC_OK` or `LC_ERROR`
/// @todo Implement `localcve_setup_config`
int localcve_setup_config(localcve* lCVE);

/// @brief Sets the LocalCVE database up
/// @note This should only be run if there is no pre-existing
///       LocalCVE setup
/// @warning This will entirely remove all database data,
///          this is irreversible
/// @param lCVE LocalCVE
/// @return `LC_OK` or `LC_ERROR`
/// @todo Implement `localcve_setup_database`
int localcve_setup_database(localcve* lCVE);

/// @brief Checks the LocalCVE database, and configuration
/// @param lCVE LocalCVE
/// @return A code (`LC_OK` or `LC_ERROR`) `|` `LC_STATUS_`...
///         Use `localcve_iserror`, or `code & LC_ERROR`
/// @todo Implement `localcve_status`
int localcve_status(localcve* lCVE);

/// @brief Checks to see if the returned code is an error code
/// @param code The code to check
/// @return `LC_OK`, `LC_ERROR` or `LC_UNKNOWN`
int localcve_is_error(int code);

#endif