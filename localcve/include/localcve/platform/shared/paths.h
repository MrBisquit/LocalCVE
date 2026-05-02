#ifndef LOCALCVE_PLATFORM_SHARED_PATHS_H
#define LOCALCVE_PLATFORM_SHARED_PATHS_H

// Shared functions (defined in each platform section)

/// @brief Fetches the path of the data directory
/// @note This is typically %APPDATA% on Windows, and %XDG_DATA_HOME (if it exists),
///     or "~/.local/share/" if it doesn't exist
/// @returns A code accourding to the platform return enum (LC_PLAT_RET)
int lc_platform_get_data_dir(char** path);

/// @brief Checks if the directory exists
/// @param path The directory path
/// @return 1 if it exists, 0 if not
int lc_platform_dir_exist(const char* path);

/// @brief Creates a directory
/// @param path The directory path
/// @return A code accourding to the platform return enum (LC_PLAT_RET)
int lc_platform_dir_create(const char* path);

/// @brief Deletes a directory
/// @param path The directory path
/// @return A code accourding to the platform return enum (LC_PLAT_RET)
int lc_platform_dir_delete(const char* path);

#endif