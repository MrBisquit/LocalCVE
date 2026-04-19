#ifndef LOCALCVE_CONFIG_IMPL_H
#define LOCALCVE_CONFIG_IMPL_H

#include <stdio.h>
#include <malloc.h>
#include <localcve/defs.h>
#include <localcve/config.h>

int lc_impl_read_cfg_stream(FILE* stream, localcve_config** config);
int lc_impl_write_cfg_stream(FILE* stream, localcve_config* config);

#endif