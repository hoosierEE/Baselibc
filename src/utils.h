#ifndef UTILS_H_
#define UTILS_H_

#include <stddef.h>
#include <inttypes.h>
uintmax_t strntoumax(const char*,char**,int,size_t);

#define atox(TYPE,NAME) TYPE NAME(const char*nptr) {                \
        return (TYPE)strntoumax(nptr, (char **)NULL, 10, ~(size_t)0);}

#define strtox(TYPE,NAME) TYPE NAME(const char *nptr, char **endptr, int base){ \
        return (TYPE)strntoumax(nptr, endptr, base, ~(size_t)0);}


atox(int,atoi);
atox(long,atol);
atox(long long,atoll);
#endif // UTILS_H_
