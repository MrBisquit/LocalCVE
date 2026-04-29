#ifndef LOCALCVE_CONFIG_H
#define LOCALCVE_CONFIG_H

#include <stdint.h>

typedef struct {
    /// @todo Move the below variables into the KVP store default values
    ///       These don't *have* to be moved for ease, just the loading
    ///       and saving need to be as kvps

    uint16_t data_path_length;
    char* data_path;

    uint16_t cve_git_length;
    /// @brief Provider (as a git repo) for CVE data
    /// @details E.g. https://github.com/CVEProject/cvelistV5.git
    char* cve_git;

    uint16_t ghsa_git_length;
    /// @brief Provider (as a git repo) for GHSA data
    /// @details E.g. https://github.com/github/advisories.git
    char* ghsa_git;

    // Since this is basically a kvp store
    uint32_t keys;
} localcve_config;

#endif