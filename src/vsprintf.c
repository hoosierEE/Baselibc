/*
 * vsprintf.c
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h> /*@alex for INT_MAX */
#ifndef NO_UNISTD_H
#include <unistd.h>
#endif

int vsprintf(char *buffer, const char *format, va_list ap)
{
	/* return vsnprintf(buffer, PTRDIFF_MAX, format, ap); */
	/*@alex error: specified bound 9223372036854775807 exceeds 'INT_MAX' [-Werror=format-truncation=] */
	return vsnprintf(buffer, INT_MAX, format, ap);
}
