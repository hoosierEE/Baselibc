#ifndef KLIBC_H_
#define KLIBC_H_

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define __alias(x) __attribute__((weak, alias(x)))


#ifndef __extern_inline
#define __extern_inline extern inline __attribute__((gnu_inline))
#endif


#endif // KLIBC_H_
