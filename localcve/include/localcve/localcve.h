#ifndef LOCALCVE_H
#define LOCALCVE_H

#include <stddef.h>
#include <sqlite3.h>
#include <git2.h>

/// @brief No errors
#define LC_OK               (0xA00000)
/// @brief There are probably errors
#define LC_ERROR            (0xE00000)
/// @brief Retured by `localcve_iserror` when it is unable
///        to work out if the code is an error or not
#define LC_UNKNOWN          (0xF00000)

#define LC_STATUS_READY     (0x0000A0)
#define LC_STATUS_EMPTY     (0x0000A1)

#if defined(WIN32) || defined(WIN64)
#define LC_SEP   "\\"
#else
#define LC_SEP   "/"
#endif

typedef struct {
    sqlite3* db;
} localcve;

typedef struct {
    /// @brief The base path for the repository stuff
    char* path;

    /// @brief Provider (as a git repo) for CVE data
    /// @example https://github.com/CVEProject/cvelistV5.git
    char* CVE_git;

    /// @brief Provider (as a git repo) for GHSA data
    /// @example https://github.com/github/advisories.git
    char* GHSA_git;
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

/// @brief Sets the LocalCVE database and configuration up
/// @note This should only be run if there is no pre-existing
///       LocalCVE setup
/// @warning This will entirely remove all present database
///          data, and any configuration present, this is
///          irreversible
/// @param lCVE LocalCVE
/// @return `LC_OK` or `LC_ERROR`
/// @todo Implement `localcve_setup`
int localcve_setup(localcve* lCVE);

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