#ifndef LOCALCVE_CONFIG_H
#define LOCALCVE_CONFIG_H

#include <stdint.h>

typedef struct {
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
} localcve_config;

#endif