#ifndef LOCALCVE_DEFS_H
#define LOCALCVE_DEFS_H

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

/// @brief The database is ready to go
#define LC_STATUS_READY         (0x0000A0)
/// @brief The database is empty
#define LC_STATUS_EMPTY         (0x0000A1)
/// @brief The database is unreadable (corrupted)
#define LC_STATUS_CORRUPTED     (0x0000B0)
/// @brief A lockfile is present, the database is unavailable
///        for ACID reasons
#define LC_STATUS_LOCKED        (0x0000C0)

#if defined(WIN32) || defined(WIN64)
#define LC_SEP   "\\"
#else
#define LC_SEP   "/"
#endif

#endif