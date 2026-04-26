#ifndef LOCALCVE_DEFS_H
#define LOCALCVE_DEFS_H

#define LC_STR_HELPER(x) #x
#define LC_STR(x) LC_STR_HELPER(x)

#define LC_VER_MAJOR            1
#define LC_VER_MINOR            0
#define LC_VER_PATCH            0

#define LC_VER_STRING           LC_STR(LC_VER_MAJOR) "." LC_STR(LC_VER_MINOR) "." LC_STR(LC_VER_PATCH)

/// @brief No errors
#define LC_OK                   (0xA00000)
/// @brief There are probably errors
#define LC_ERROR                (0xE00000)
/// @brief Retured by `localcve_iserror` when it is unable
///        to work out if the code is an error or not
#define LC_UNKNOWN              (0xF00000)

/// @brief A NULL pointer was probably parsed as a parameter
///        when it shouldn't have been
#define LC_ERR_UNEXP_PTR_NULL   (0x010000)
/// @brief A value was not expected
#define LC_ERR_UNEXP_VALUE      (0x011000)

/// @brief The database/config is ready to go
#define LC_STATUS_READY         (0x0000A0)
/// @brief The database/config is empty
#define LC_STATUS_EMPTY         (0x0000A1)
/// @brief The database/config is unreadable (corrupted)
#define LC_STATUS_CORRUPTED     (0x0000B0)
/// @brief A lockfile is present, the database is unavailable
///        for ACID reasons
#define LC_STATUS_LOCKED        (0x0000C0)

#if defined(WIN32) || defined(WIN64)
#define LC_SEP   "\\"
#else
#define LC_SEP   "/"
#endif

// Default values
#define LC_DEFAULT_CVE_PATH     ("https://github.com/CVEProject/cvelistV5.git\0")
#define LC_DEFAULT_GHSA_PATH    ("https://github.com/github/advisories.git\0")

extern const char* localcve_default_cve_path;
extern const char* localcve_default_ghsa_path;

#endif