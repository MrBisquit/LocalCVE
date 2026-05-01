#ifndef LOCALCVE_PLATFORM_H
#define LOCALCVE_PLATFORM_H

#include "shared/defs.h"
#include "shared/paths.h"

#if defined(WIN32) || defined(WIN64)
#include "win/win.h"
#else
#include "linux/linux.h"
#endif

#endif