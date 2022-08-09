#ifndef UTILS_H_
#define UTILS_H_

#include <stddef.h>
#include "inttypes.h"
uintmax_t strntoumax(const char*,char**,int,size_t);

#define atox(NAME,TYPE) TYPE NAME(const char*nptr) {                \
        return (TYPE)strntoumax(nptr, (char **)NULL, 10, ~(size_t)0);}

#define strtox(NAME,TYPE) TYPE NAME(const char *nptr, char **endptr, int base){ \
        return (TYPE)strntoumax(nptr, endptr, base, ~(size_t)0);}


atox(atoi,int);
atox(atol,long);
atox(atoll,long long);

strtox(strtoimax,intmax_t);
strtox(strtol,signed long);
strtox(strtoll,signed long long);
strtox(strtoul,unsigned long);
strtox(strotoumax,uintmax_t);
strtox(strtoull,unsigned long long);

#endif // UTILS_H_
