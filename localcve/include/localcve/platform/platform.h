#ifndef LOCALCVE_PLATFORM_H
#define LOCALCVE_PLATFORM_H

#if defined(WIN32) || defined(WIN64)
#include "win/win.h"
#else
#include "linux/linux.h"
#endif

#endif