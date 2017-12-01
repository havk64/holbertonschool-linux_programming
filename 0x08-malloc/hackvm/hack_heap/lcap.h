#ifndef LCAP_H
#define LCAP_H
#include <sys/capability.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct flags
{
	const char *str;
	cap_flag_t flag;
} flags_t;
#endif /* LCAP_H */
