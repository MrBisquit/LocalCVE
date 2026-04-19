#ifndef LOCALCVE_CALLBACKS_H
#define LOCALCVE_CALLBACKS_H

#include <git2.h>

/// @brief Transfer progress callback for `git_clone_options` (`git_clone`)
typedef int (*localcve_git_fetch_progress)(
    const git_indexer_progress* stats,
    void* payload
);

/// @brief Checkout progress callback for `git_clone_options` (`git_clone`)
typedef void (*localcve_git_checkout_progress)(
    const char* path,
    size_t cur,
    size_t tot,
    void* payload
);

#endif