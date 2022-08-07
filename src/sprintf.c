/*
 * sprintf.c
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h> /*@alex for INT_MAX */
#ifndef NO_UNISTD_H
#include <unistd.h>
#endif

int sprintf(char *buffer, const char *format, ...)
{
	va_list ap;
	int rv;

	va_start(ap, format);
	/* rv = vsnprintf(buffer, PTRDIFF_MAX, format, ap); */
	/*@alex error: specified bound 9223372036854775807 exceeds 'INT_MAX' [-Werror=format-truncation=] */
	rv = vsnprintf(buffer, INT_MAX, format, ap);
	va_end(ap);

	return rv;
}
