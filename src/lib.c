#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#ifndef NO_UNISTD_H
#include <unistd.h>
#endif

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
/* * assert.h */
#ifndef _ASSERT_H
#define _ASSERT_H
#ifdef NDEBUG
/*
 * NDEBUG doesn't just suppress the faulting behavior of assert(),
 * but also all side effects of the assert() argument.  This behavior
 * is required by the C standard, and allows the argument to reference
 * variables that are not defined without NDEBUG.
 */
#define assert(x) ((void)(0))
#else
extern void __assert_fail(const char *, const char *, unsigned int);
#define assert(x) ((x) ? (void)0 : __assert_fail(#x, __FILE__, __LINE__))
#endif
#endif				/* _ASSERT_H */

/*
 * ctype.h
 *
 * This assumes ASCII.
 */
#ifndef _CTYPE_H
#define _CTYPE_H
__extern_inline int isupper(int __c) {return __c >= 'A' && __c <= 'Z';}
__extern_inline int islower(int __c) {return __c >= 'a' && __c <= 'z';}
__extern_inline int isalpha(int __c) {return islower(__c) || isupper(__c);}
__extern_inline int isdigit(int __c) {return ((unsigned)__c - '0') <= 9;}
__extern_inline int isalnum(int __c) {return isalpha(__c) || isdigit(__c);}
__extern_inline int isascii(int __c) {return !(__c & ~0x7f);}
__extern_inline int isblank(int __c) {return (__c == '\t') || (__c == ' ');}
__extern_inline int iscntrl(int __c) {return __c < 0x20;}
__extern_inline int isspace(int __c) {return __c == ' ' || __c == '\n' || __c == '\t' || __c == '\r';}
__extern_inline int isxdigit(int __c) {return isdigit(__c) || (__c >= 'a' && __c <= 'f') || (__c >= 'A' && __c <= 'F');}
__extern_inline int toupper(int __c) {return islower(__c) ? (__c & ~32) : __c;}
__extern_inline int tolower(int __c) {return isupper(__c) ? (__c | 32) : __c;}
#endif				/* _CTYPE_H */


/* * inttypes.h */
#ifndef _INTTYPES_H
#define _INTTYPES_H
/* static __inline__ intmax_t imaxabs(intmax_t __n) {return (__n < (intmax_t) 0) ? -__n : __n;} */ // unused?
__extern intmax_t strtoimax(const char *, char **, int);
__extern uintmax_t strtoumax(const char *, char **, int);
/* extensions */
__extern intmax_t strntoimax(const char *, char **, int, size_t);
__extern uintmax_t strntoumax(const char *, char **, int, size_t);
#if !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS)
#define PRId8	"d"
#define PRId16	"d"
#define PRId32	"d"
#define PRId64	__PRI64_RANK "d"
#define PRIdLEAST8	"d"
#define PRIdLEAST16	"d"
#define PRIdLEAST32	"d"
#define PRIdLEAST64	__PRI64_RANK "d"
#define PRIdFAST8	"d"
#define PRIdFAST16	__PRIFAST_RANK "d"
#define PRIdFAST32	__PRIFAST_RANK "d"
#define PRIdFAST64	__PRI64_RANK "d"
#define PRIdMAX	 __PRI64_RANK "d"
#define PRIdPTR  __PRIPTR_RANK "d"
#define PRIi8	"i"
#define PRIi16	"i"
#define PRIi32	"i"
#define PRIi64	__PRI64_RANK "i"
#define PRIiLEAST8	"i"
#define PRIiLEAST16	"i"
#define PRIiLEAST32	"i"
#define PRIiLEAST64	__PRI64_RANK "i"
#define PRIiFAST8	"i"
#define PRIiFAST16	__PRIFAST_RANK "i"
#define PRIiFAST32	__PRIFAST_RANK "i"
#define PRIiFAST64	__PRI64_RANK "i"
#define PRIiMAX	 __PRI64_RANK "i"
#define PRIiPTR  __PRIPTR_RANK "i"
#define PRIo8	"o"
#define PRIo16	"o"
#define PRIo32	"o"
#define PRIo64	__PRI64_RANK "o"
#define PRIoLEAST8	"o"
#define PRIoLEAST16	"o"
#define PRIoLEAST32	"o"
#define PRIoLEAST64	__PRI64_RANK "o"
#define PRIoFAST8	"o"
#define PRIoFAST16	__PRIFAST_RANK "o"
#define PRIoFAST32	__PRIFAST_RANK "o"
#define PRIoFAST64	__PRI64_RANK "o"
#define PRIoMAX	 __PRI64_RANK "o"
#define PRIoPTR  __PRIPTR_RANK "o"
#define PRIu8	"u"
#define PRIu16	"u"
#define PRIu32	"u"
#define PRIu64	__PRI64_RANK "u"
#define PRIuLEAST8	"u"
#define PRIuLEAST16	"u"
#define PRIuLEAST32	"u"
#define PRIuLEAST64	__PRI64_RANK "u"
#define PRIuFAST8	"u"
#define PRIuFAST16	__PRIFAST_RANK "u"
#define PRIuFAST32	__PRIFAST_RANK "u"
#define PRIuFAST64	__PRI64_RANK "u"
#define PRIuMAX	 __PRI64_RANK "u"
#define PRIuPTR  __PRIPTR_RANK "u"
#define PRIx8	"x"
#define PRIx16	"x"
#define PRIx32	"x"
#define PRIx64	__PRI64_RANK "x"
#define PRIxLEAST8	"x"
#define PRIxLEAST16	"x"
#define PRIxLEAST32	"x"
#define PRIxLEAST64	__PRI64_RANK "x"
#define PRIxFAST8	"x"
#define PRIxFAST16	__PRIFAST_RANK "x"
#define PRIxFAST32	__PRIFAST_RANK "x"
#define PRIxFAST64	__PRI64_RANK "x"
#define PRIxMAX	 __PRI64_RANK "x"
#define PRIxPTR  __PRIPTR_RANK "x"
#define PRIX8	"X"
#define PRIX16	"X"
#define PRIX32	"X"
#define PRIX64	__PRI64_RANK "X"
#define PRIXLEAST8	"X"
#define PRIXLEAST16	"X"
#define PRIXLEAST32	"X"
#define PRIXLEAST64	__PRI64_RANK "X"
#define PRIXFAST8	"X"
#define PRIXFAST16	__PRIFAST_RANK "X"
#define PRIXFAST32	__PRIFAST_RANK "X"
#define PRIXFAST64	__PRI64_RANK "X"
#define PRIXMAX	 __PRI64_RANK "X"
#define PRIXPTR  __PRIPTR_RANK "X"
#define SCNd8	"hhd"
#define SCNd16	"hd"
#define SCNd32	"d"
#define SCNd64	__PRI64_RANK "d"
#define SCNdLEAST8	"hhd"
#define SCNdLEAST16	"hd"
#define SCNdLEAST32	"d"
#define SCNdLEAST64	__PRI64_RANK "d"
#define SCNdFAST8	"hhd"
#define SCNdFAST16	__PRIFAST_RANK "d"
#define SCNdFAST32	__PRIFAST_RANK "d"
#define SCNdFAST64	__PRI64_RANK "d"
#define SCNdMAX	 __PRI64_RANK "d"
#define SCNdPTR  __PRIPTR_RANK "d"
#define SCNi8	"hhi"
#define SCNi16	"hi"
#define SCNi32	"i"
#define SCNi64	__PRI64_RANK "i"
#define SCNiLEAST8	"hhi"
#define SCNiLEAST16	"hi"
#define SCNiLEAST32	"i"
#define SCNiLEAST64	__PRI64_RANK "i"
#define SCNiFAST8	"hhi"
#define SCNiFAST16	__PRIFAST_RANK "i"
#define SCNiFAST32	__PRIFAST_RANK "i"
#define SCNiFAST64	__PRI64_RANK "i"
#define SCNiMAX	 __PRI64_RANK "i"
#define SCNiPTR  __PRIPTR_RANK "i"
#define SCNo8	"hho"
#define SCNo16	"ho"
#define SCNo32	"o"
#define SCNo64	__PRI64_RANK "o"
#define SCNoLEAST8	"hho"
#define SCNoLEAST16	"ho"
#define SCNoLEAST32	"o"
#define SCNoLEAST64	__PRI64_RANK "o"
#define SCNoFAST8	"hho"
#define SCNoFAST16	__PRIFAST_RANK "o"
#define SCNoFAST32	__PRIFAST_RANK "o"
#define SCNoFAST64	__PRI64_RANK "o"
#define SCNoMAX	 __PRI64_RANK "o"
#define SCNoPTR  __PRIPTR_RANK "o"
#define SCNu8	"hhu"
#define SCNu16	"hu"
#define SCNu32	"u"
#define SCNu64	__PRI64_RANK "u"
#define SCNuLEAST8	"hhu"
#define SCNuLEAST16	"hu"
#define SCNuLEAST32	"u"
#define SCNuLEAST64	__PRI64_RANK "u"
#define SCNuFAST8	"hhu"
#define SCNuFAST16	__PRIFAST_RANK "u"
#define SCNuFAST32	__PRIFAST_RANK "u"
#define SCNuFAST64	__PRI64_RANK "u"
#define SCNuMAX	 __PRI64_RANK "u"
#define SCNuPTR  __PRIPTR_RANK "u"
#define SCNx8	"hhx"
#define SCNx16	"hx"
#define SCNx32	"x"
#define SCNx64	__PRI64_RANK "x"
#define SCNxLEAST8	"hhx"
#define SCNxLEAST16	"hx"
#define SCNxLEAST32	"x"
#define SCNxLEAST64	__PRI64_RANK "x"
#define SCNxFAST8	"hhx"
#define SCNxFAST16	__PRIFAST_RANK "x"
#define SCNxFAST32	__PRIFAST_RANK "x"
#define SCNxFAST64	__PRI64_RANK "x"
#define SCNxMAX	 __PRI64_RANK "x"
#define SCNxPTR  __PRIPTR_RANK "x"
#endif
#endif				/* _INTTYPES_H */


/* * string.h */
#ifndef _STRING_H
#define _STRING_H
__extern void *memccpy(void *, const void *, int, size_t);
__extern void *memchr(const void *, int, size_t);
__extern void *memrchr(const void *, int, size_t);
__extern int memcmp(const void *, const void *, size_t);
__extern void *memcpy(void *, const void *, size_t);
__extern void *memmove(void *, const void *, size_t);
__extern void *memset(void *, int, size_t);
__extern void *memmem(const void *, size_t, const void *, size_t);
__extern void memswap(void *, void *, size_t);
__extern void bzero(void *, size_t);
__extern int strcasecmp(const char *, const char *);
__extern int strncasecmp(const char *, const char *, size_t);
__extern char *strcat(char *, const char *);
__extern char *strchr(const char *, int);
__extern char *index(const char *, int);
__extern char *strrchr(const char *, int);
__extern char *rindex(const char *, int);
__extern int strcmp(const char *, const char *);
__extern char *strcpy(char *, const char *);
__extern size_t strcspn(const char *, const char *);
__extern char *strdup(const char *);
__extern char *strndup(const char *, size_t);
__extern size_t strlen(const char *);
__extern size_t strnlen(const char *, size_t);
__extern char *strncat(char *, const char *, size_t);
__extern size_t strlcat(char *, const char *, size_t);
__extern int strncmp(const char *, const char *, size_t);
__extern char *strncpy(char *, const char *, size_t);
__extern size_t strlcpy(char *, const char *, size_t);
__extern char *strpbrk(const char *, const char *);
__extern char *strsep(char **, const char *);
__extern size_t strspn(const char *, const char *);
__extern char *strstr(const char *, const char *);
__extern char *strtok(char *, const char *);
__extern char *strtok_r(char *, const char *, char **);
/* Some dummy functions to avoid errors with C++ cstring */
/* inline static int strcoll(const char *s1, const char *s2) {return strcmp(s1, s2);} */
/* inline static size_t strxfrm(char *dest, const char *src, size_t n) */
/* { */
/* 	strncpy(dest, src, n); */
/* 	return strlen(src); */
/* } */
#endif				/* _STRING_H */

/* * stdlib.h */
#ifndef _STDLIB_H
#define _STDLIB_H
#include <stdbool.h>
__extern_inline int abs(int __n) {return (__n < 0) ? -__n : __n;}
__extern int atoi(const char *);
__extern long atol(const char *);
__extern long long atoll(const char *);
__extern_inline long labs(long __n) {return (__n < 0L) ? -__n : __n;}
__extern_inline long long llabs(long long __n) {return (__n < 0LL) ? -__n : __n;}
__extern void free(void *);
__extern void *malloc(size_t);
__extern void *calloc(size_t, size_t);
__extern void *realloc(void *, size_t);
/* Giving malloc some memory from which to allocate */
__extern void add_malloc_block(void *, size_t);
__extern void get_malloc_memory_status(size_t *, size_t *);
/* Malloc locking
 * Until the callbacks are set, malloc doesn't do any locking.
 * malloc_lock() *may* timeout, in which case malloc() will return NULL.
 */
typedef bool (*malloc_lock_t)(void);
typedef void (*malloc_unlock_t)(void);
__extern void set_malloc_locking(malloc_lock_t, malloc_unlock_t);
__extern long strtol(const char *, char **, int);
__extern long long strtoll(const char *, char **, int);
__extern unsigned long strtoul(const char *, char **, int);
__extern unsigned long long strtoull(const char *, char **, int);
typedef int (*__comparefunc_t) (const void *, const void *);
__extern void *bsearch(const void *, const void *, size_t, size_t, __comparefunc_t);
__extern void qsort(void *, size_t, size_t, __comparefunc_t);
__extern long jrand48(unsigned short *);
__extern long mrand48(void);
__extern long nrand48(unsigned short *);
__extern long lrand48(void);
__extern unsigned short *seed48(const unsigned short *);
__extern void srand48(long);
#define RAND_MAX 0x7fffffff
__extern_inline int rand(void) {return (int)lrand48();}
__extern_inline void srand(unsigned int __s) {srand48(__s);}
__extern_inline long random(void) {return lrand48();}
__extern_inline void srandom(unsigned int __s) {srand48(__s);}
#endif				/* _STDLIB_H */

/* * stdio.h */
#ifndef _STDIO_H
#define _STDIO_H
/* The File structure is designed to be compatible with ChibiOS/RT type
 * BaseSequentialStream.
 */
struct File;
typedef struct File FILE;
struct File_methods
{
    size_t (*write)(FILE* instance, const char *bp, size_t n);
    size_t (*read)(FILE* instance, char *bp, size_t n);
};
struct File
{
    const struct File_methods *vmt;
};
#ifndef EOF
# define EOF (-1)
#endif
/* Standard file descriptors - implement these globals yourself. */
extern FILE* const stdin;
extern FILE* const stdout;
extern FILE* const stderr;
/* Wrappers around stream write and read */
__extern_inline size_t fread(void *buf, size_t size, size_t nmemb, FILE *stream)
{
    if (stream->vmt->read == NULL) return 0;
    return stream->vmt->read(stream, buf, size*nmemb) / size;
}
__extern_inline size_t fwrite(const void *buf, size_t size, size_t nmemb, FILE *stream)
{
    if (stream->vmt->write == NULL) return 0;
    return stream->vmt->write(stream, buf, size*nmemb) / size;
}
__extern_inline int fputs(const char *s, FILE *f) {return fwrite(s, 1, strlen(s), f);}
__extern_inline int puts(const char *s) {return fwrite(s, 1, strlen(s), stdout) + fwrite("\n", 1, 1, stdout);}
__extern_inline int fputc(int c, FILE *f)
{
	unsigned char ch = c;
	return fwrite(&ch, 1, 1, f) == 1 ? ch : EOF;
}
__extern char *fgets(char *, int, FILE *);
__extern_inline int fgetc(FILE *f)
{
	unsigned char ch;
	return fread(&ch, 1, 1, f) == 1 ? ch : EOF;
}
#define putc(c,f)  fputc((c),(f))
#define putchar(c) fputc((c),stdout)
#define getc(f) fgetc(f)
#define getchar() fgetc(stdin)
__extern int printf(const char *, ...);
__extern int vprintf(const char *, va_list);
__extern int fprintf(FILE *, const char *, ...);
__extern int vfprintf(FILE *, const char *, va_list);
__extern int sprintf(char *, const char *, ...);
__extern int vsprintf(char *, const char *, va_list);
__extern int snprintf(char *, size_t n, const char *, ...);
__extern int vsnprintf(char *, size_t n, const char *, va_list);
__extern int asprintf(char **, const char *, ...);
__extern int vasprintf(char **, const char *, va_list);
__extern int sscanf(const char *, const char *, ...);
__extern int vsscanf(const char *, const char *, va_list);
/* Open a memory buffer for writing.
 Note: Does not write null terminator.*/
struct MemFile
{
    struct File file;
    char *buffer;
    size_t bytes_written;
    size_t size;
};
FILE *fmemopen_w(struct MemFile* storage, char *buffer, size_t size);
#endif				/* _STDIO_H */


//
// headers above, regular libraries below this line
//

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

/*
 * malloc.c
 *
 * Very simple linked-list based malloc()/free().
 */

/* BEGIN_malloc.h */

/*
 * malloc.h
 *
 * Internals for the memory allocator
 */


/*
 * This structure should be a power of two.  This becomes the
 * alignment unit.
 */
struct free_arena_header;

struct arena_header {
	size_t type;
	size_t size;
	struct free_arena_header *next, *prev;
};

#ifdef DEBUG_MALLOC
#define ARENA_TYPE_USED 0x64e69c70
#define ARENA_TYPE_FREE 0x012d610a
#define ARENA_TYPE_HEAD 0x971676b5
#define ARENA_TYPE_DEAD 0xeeeeeeee
#else
#define ARENA_TYPE_USED 0
#define ARENA_TYPE_FREE 1
#define ARENA_TYPE_HEAD 2
#endif

#define ARENA_SIZE_MASK (~(sizeof(struct arena_header)-1))

/*
 * This structure should be no more than twice the size of the
 * previous structure.
 */
struct free_arena_header {
	struct arena_header a;
	struct free_arena_header *next_free, *prev_free;
};

/* END_malloc.h */


/* Both the arena list and the free memory list are double linked
   list with head node.  This the head node. Note that the arena list
   is sorted in order of address. */
static struct free_arena_header __malloc_head = {
	{
		ARENA_TYPE_HEAD,
		0,
		&__malloc_head,
		&__malloc_head,
	},
	&__malloc_head,
	&__malloc_head
};

static bool malloc_lock_nop(void) {return true;}
static void malloc_unlock_nop(void) {}

static malloc_lock_t malloc_lock = &malloc_lock_nop;
static malloc_unlock_t malloc_unlock = &malloc_unlock_nop;

static inline void mark_block_dead(struct free_arena_header *ah)
{
#ifdef DEBUG_MALLOC
	ah->a.type = ARENA_TYPE_DEAD;
#endif
}

static inline void remove_from_main_chain(struct free_arena_header *ah)
{
	struct free_arena_header *ap, *an;
	mark_block_dead(ah);
	ap = ah->a.prev;
	an = ah->a.next;
	ap->a.next = an;
	an->a.prev = ap;
}

static inline void remove_from_free_chain(struct free_arena_header *ah)
{
	struct free_arena_header *ap, *an;
	ap = ah->prev_free;
	an = ah->next_free;
	ap->next_free = an;
	an->prev_free = ap;
}

static inline void remove_from_chains(struct free_arena_header *ah)
{
	remove_from_free_chain(ah);
	remove_from_main_chain(ah);
}

static void *__malloc_from_block(struct free_arena_header *fp, size_t size)
{
	size_t fsize;
	struct free_arena_header *nfp, *na, *fpn, *fpp;
	fsize = fp->a.size;
	/* We need the 2* to account for the larger requirements of a
	   free block */
	if (fsize >= size + 2 * sizeof(struct arena_header)) {
		/* Bigger block than required -- split block */
		nfp = (struct free_arena_header *)((char *)fp + size);
		na = fp->a.next;
		nfp->a.type = ARENA_TYPE_FREE;
		nfp->a.size = fsize - size;
		fp->a.type = ARENA_TYPE_USED;
		fp->a.size = size;
		/* Insert into all-block chain */
		nfp->a.prev = fp;
		nfp->a.next = na;
		na->a.prev = nfp;
		fp->a.next = nfp;
		/* Replace current block on free chain */
		nfp->next_free = fpn = fp->next_free;
		nfp->prev_free = fpp = fp->prev_free;
		fpn->prev_free = nfp;
		fpp->next_free = nfp;
	} else {
		fp->a.type = ARENA_TYPE_USED; /* Allocate the whole block */
		remove_from_free_chain(fp);
	}
	return (void *)(&fp->a + 1);
}

static struct free_arena_header *__free_block(struct free_arena_header *ah)
{
	struct free_arena_header *pah, *nah;
	pah = ah->a.prev;
	nah = ah->a.next;
	if (pah->a.type == ARENA_TYPE_FREE &&
	    (char *)pah + pah->a.size == (char *)ah) {
		/* Coalesce into the previous block */
		pah->a.size += ah->a.size;
		pah->a.next = nah;
		nah->a.prev = pah;
		mark_block_dead(ah);
		ah = pah;
		pah = ah->a.prev;
	} else {
		/* Need to add this block to the free chain */
		ah->a.type = ARENA_TYPE_FREE;
		ah->next_free = __malloc_head.next_free;
		ah->prev_free = &__malloc_head;
		__malloc_head.next_free = ah;
		ah->next_free->prev_free = ah;
	}
	/* In either of the previous cases, we might be able to merge
	   with the subsequent block... */
	if (nah->a.type == ARENA_TYPE_FREE &&
	    (char *)ah + ah->a.size == (char *)nah) {
		ah->a.size += nah->a.size;
		/* Remove the old block from the chains */
		remove_from_chains(nah);
	}
	/* Return the block that contains the called block */
	return ah;
}

void *malloc(size_t size)
{
	struct free_arena_header *fp;
	if (size == 0)
		return NULL;
	/* Add the obligatory arena header, and round up */
	size = (size + 2 * sizeof(struct arena_header) - 1) & ARENA_SIZE_MASK;
        if (!malloc_lock())
                return NULL;
        void *result = NULL;
	for (fp = __malloc_head.next_free; fp->a.type != ARENA_TYPE_HEAD;
	     fp = fp->next_free) {
		if (fp->a.size >= size) {
			/* Found fit -- allocate out of this block */
			result = __malloc_from_block(fp, size);
                        break;
		}
	}
        malloc_unlock();
	return result;
}

/* Call this to give malloc some memory to allocate from */
void add_malloc_block(void *buf, size_t size)
{
	struct free_arena_header *fp = buf;
	struct free_arena_header *pah;
	if (size < sizeof(struct free_arena_header))
		return; // Too small.
	/* Insert the block into the management chains.  We need to set
	   up the size and the main block list pointer, the rest of
	   the work is logically identical to free(). */
	fp->a.type = ARENA_TYPE_FREE;
	fp->a.size = size;
        if (!malloc_lock())
            return;
	/* We need to insert this into the main block list in the proper
	   place -- this list is required to be sorted.  Since we most likely
	   get memory assignments in ascending order, search backwards for
	   the proper place. */
	for (pah = __malloc_head.a.prev; pah->a.type != ARENA_TYPE_HEAD;
	     pah = pah->a.prev) {
		if (pah < fp)
			break;
	}
	/* Now pah points to the node that should be the predecessor of
	   the new node */
	fp->a.next = pah->a.next;
	fp->a.prev = pah;
	pah->a.next = fp;
	fp->a.next->a.prev = fp;
	/* Insert into the free chain and coalesce with adjacent blocks */
	fp = __free_block(fp);
        malloc_unlock();
}

void free(void *ptr)
{
	struct free_arena_header *ah;
	if (!ptr)
		return;
	ah = (struct free_arena_header *)
	    ((struct arena_header *)ptr - 1);
#ifdef DEBUG_MALLOC
	assert(ah->a.type == ARENA_TYPE_USED);
#endif
        if (!malloc_lock())
            return;
	/* Merge into adjacent free blocks */
	ah = __free_block(ah);
        malloc_unlock();
}

void get_malloc_memory_status(size_t *free_bytes, size_t *largest_block)
{
    struct free_arena_header *fp;
    *free_bytes = 0;
    *largest_block = 0;
    if (!malloc_lock())
            return;
    for (fp = __malloc_head.next_free; fp->a.type != ARENA_TYPE_HEAD; fp = fp->next_free) {
        *free_bytes += fp->a.size;
        if (fp->a.size >= *largest_block) {
            *largest_block = fp->a.size;
        }
    }
    malloc_unlock();
}

void set_malloc_locking(malloc_lock_t lock, malloc_unlock_t unlock)
{
    if (lock)
        malloc_lock = lock;
    else
        malloc_lock = &malloc_lock_nop;
    if (unlock)
        malloc_unlock = unlock;
    else
        malloc_unlock = &malloc_unlock_nop;
}


/* * realloc.c */
/* FIXME: This is cheesy, it should be fixed later */
void *realloc(void *ptr, size_t size)
{
	struct free_arena_header *ah;
	void *newptr;
	size_t oldsize;
	if (!ptr)
		return malloc(size);
	if (size == 0) {
		free(ptr);
		return NULL;
	}
	/* Add the obligatory arena header, and round up */
	size = (size + 2 * sizeof(struct arena_header) - 1) & ARENA_SIZE_MASK;
	ah = (struct free_arena_header *)
	    ((struct arena_header *)ptr - 1);
	if (ah->a.size >= size && size >= (ah->a.size >> 2)) {
		/* This field is a good size already. */
		return ptr;
	} else {
		/* Make me a new block.  This is kind of bogus; we should
		   be checking the following block to see if we can do an
		   in-place adjustment... fix that later. */
		oldsize = ah->a.size - sizeof(struct arena_header);
		newptr = malloc(size);
		memcpy(newptr, ptr, (size < oldsize) ? size : oldsize);
		free(ptr);
		return newptr;
	}
}

/*
 * fgets.c
 *
 * This will be very slow due to the implementation of getc(),
 * but we don't have anywhere to put characters we don't need from
 * the input.
 */
char *fgets(char *s, int n, FILE *f)
{
	int ch;
	char *p = s;
	while (n > 1) {
		ch = getc(f);
		if (ch == EOF) {
			*p = '\0';
			return NULL;
		}
		*p++ = ch;
		n--;
		if (ch == '\n')
			break;
	}
	if (n)
		*p = '\0';
	return s;
}

/* * memcpy.c */
void *memcpy(void *dst, const void *src, size_t n)
{
	const char *p = src;
	char *q = dst;
#if defined(__i386__)
	size_t nl = n >> 2;
	asm volatile ("cld ; rep ; movsl ; movl %3,%0 ; rep ; movsb":"+c" (nl),
		      "+S"(p), "+D"(q)
		      :"r"(n & 3));
#elif defined(__x86_64__)
	size_t nq = n >> 3;
	asm volatile ("cld ; rep ; movsq ; movl %3,%%ecx ; rep ; movsb":"+c"
		      (nq), "+S"(p), "+D"(q)
		      :"r"((uint32_t) (n & 7)));
#else
	while (n--) {
		*q++ = *p++;
	}
#endif
	return dst;
}

/* * memcmp.c */
int memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *c1 = s1, *c2 = s2;
	int d = 0;
	while (n--) {
		d = (int)*c1++ - (int)*c2++;
		if (d)
			break;
	}
	return d;
}

/* * memchr.c */
void *memchr(const void *s, int c, size_t n)
{
	const unsigned char *sp = s;
	while (n--) {
		if (*sp == (unsigned char)c)
			return (void *)sp;
		sp++;
	}
	return NULL;
}

/*
 * memmem.c
 *
 * Find a byte string inside a longer byte string
 *
 * This uses the "Not So Naive" algorithm, a very simple but
 * usually effective algorithm, see:
 *
 * http://www-igm.univ-mlv.fr/~lecroq/string/
 */
void *memmem(const void *haystack, size_t n, const void *needle, size_t m)
{
	const unsigned char *y = (const unsigned char *)haystack;
	const unsigned char *x = (const unsigned char *)needle;
	size_t j, k, l;
	if (m > n || !m || !n)
		return NULL;
	if (1 != m) {
		if (x[0] == x[1]) {
			k = 2;
			l = 1;
		} else {
			k = 1;
			l = 2;
		}
		j = 0;
		while (j <= n - m) {
			if (x[1] != y[j + 1]) {
				j += k;
			} else {
				if (!memcmp(x + 2, y + j + 2, m - 2)
				    && x[0] == y[j])
					return (void *)&y[j];
				j += l;
			}
		}
	} else
		do {
			if (*y == *x)
				return (void *)y;
			y++;
		} while (--n);
	return NULL;
}

/* * asprintf.c */
int asprintf(char **bufp, const char *format, ...)
{
	va_list ap, ap1;
	int rv;
	int bytes;
	char *p;
	va_start(ap, format);
	va_copy(ap1, ap);
	bytes = vsnprintf(NULL, 0, format, ap1) + 1;
	va_end(ap1);
	*bufp = p = malloc(bytes);
	if (!p)
		return -1;
	rv = vsnprintf(p, bytes, format, ap);
	va_end(ap);
	return rv;
}

/* * bsearch.c */
void *bsearch(const void *key, const void *base, size_t nmemb,
	      size_t size, int (*cmp) (const void *, const void *))
{
	while (nmemb) {
		size_t mididx = nmemb / 2;
		const void *midobj = (const char*)base + mididx * size;
		int diff = cmp(key, midobj);
		if (diff == 0)
			return (void *)midobj;
		if (diff > 0) {
			base = (const char*)midobj + size;
			nmemb -= mididx + 1;
		} else
			nmemb = mididx;
	}
	return NULL;
}

void bzero(void *dst, size_t n)
{
	memset(dst, 0, n);
}

/* * jrand48.c */
long jrand48(unsigned short xsubi[3])
{
	uint64_t x;
	/* The xsubi[] array is littleendian by spec */
	x = (uint64_t) (uint16_t) xsubi[0] +
	    ((uint64_t) (uint16_t) xsubi[1] << 16) +
	    ((uint64_t) (uint16_t) xsubi[2] << 32);
	x = (0x5deece66dULL * x) + 0xb;
	xsubi[0] = (unsigned short)(uint16_t) x;
	xsubi[1] = (unsigned short)(uint16_t) (x >> 16);
	xsubi[2] = (unsigned short)(uint16_t) (x >> 32);
	return (long)(int32_t) (x >> 16);
}

/* * lrand48.c */
extern unsigned short __rand48_seed[3];	/* Common with mrand48.c, srand48.c */
long lrand48(void)
{
	return (uint32_t) jrand48(__rand48_seed) >> 1;
}

/* * memccpy.c */
void *memccpy(void *dst, const void *src, int c, size_t n)
{
	char *q = dst;
	const char *p = src;
	char ch;
	while (n--) {
		*q++ = ch = *p++;
		if (ch == (char)c)
			return q;
	}
	return NULL;		/* No instance of "c" found */
}

size_t memfile_write(FILE *instance, const char *bp, size_t n)
{
    struct MemFile *f = (struct MemFile*)instance;
    size_t i = 0;
    while (n--)
    {
        f->bytes_written++;
        if (f->bytes_written <= f->size)
        {
            *f->buffer++ = *bp++;
            i++;
        }
    }
    return i;
}

const struct File_methods MemFile_methods = {
    &memfile_write,
    NULL
};

FILE *fmemopen_w(struct MemFile* storage, char *buffer, size_t size)
{
    storage->file.vmt = &MemFile_methods;
    storage->buffer = buffer;
    storage->bytes_written = 0;
    storage->size = size;
    return (FILE*)storage;
}

/* * memmove.c */
void *memmove(void *dst, const void *src, size_t n)
{
	const char *p = src;
	char *q = dst;
#if defined(__i386__) || defined(__x86_64__)
	if (q < p) {
		asm volatile("cld; rep; movsb"
			     : "+c" (n), "+S"(p), "+D"(q));
	} else {
		p += (n - 1);
		q += (n - 1);
		asm volatile("std; rep; movsb; cld"
			     : "+c" (n), "+S"(p), "+D"(q));
	}
#else
	if (q < p) {
		while (n--) {
			*q++ = *p++;
		}
	} else {
		p += n;
		q += n;
		while (n--) {
			*--q = *--p;
		}
	}
#endif
	return dst;
}


/* * memrchr.c */
void *memrchr(const void *s, int c, size_t n)
{
	const unsigned char *sp = (const unsigned char *)s + n - 1;
	while (n--) {
		if (*sp == (unsigned char)c)
			return (void *)sp;
		sp--;
	}
	return NULL;
}


/* * memset.c */
void *memset(void *dst, int c, size_t n)
{
	char *q = dst;
#if defined(__i386__)
	size_t nl = n >> 2;
	asm volatile ("cld ; rep ; stosl ; movl %3,%0 ; rep ; stosb"
		      : "+c" (nl), "+D" (q)
		      : "a" ((unsigned char)c * 0x01010101U), "r" (n & 3));
#elif defined(__x86_64__)
	size_t nq = n >> 3;
	asm volatile ("cld ; rep ; stosq ; movl %3,%%ecx ; rep ; stosb"
		      :"+c" (nq), "+D" (q)
		      : "a" ((unsigned char)c * 0x0101010101010101U),
			"r" ((uint32_t) n & 7));
#else
	while (n--) {
		*q++ = c;
	}
#endif
	return dst;
}

/*
 * memswap()
 *
 * Swaps the contents of two nonoverlapping memory areas.
 * This really could be done faster...
 */
void memswap(void *m1, void *m2, size_t n)
{
	char *p = m1;
	char *q = m2;
	char tmp;
	while (n--) {
		tmp = *p;
		*p = *q;
		*q = tmp;
		p++;
		q++;
	}
}

/* * mrand48.c */
extern unsigned short __rand48_seed[3];	/* Common with lrand48.c, srand48.c */
long mrand48(void)
{
	return jrand48(__rand48_seed);
}

/* * nrand48.c */
long nrand48(unsigned short xsubi[3])
{
	return (long)((uint32_t) jrand48(xsubi) >> 1);
}

/*
 * qsort.c
 *
 * This is actually combsort.  It's an O(n log n) algorithm with
 * simplicity/small code size being its main virtue.
 */
static inline size_t newgap(size_t gap)
{
    gap = (gap * 10) / 13;
    if (gap == 9 || gap == 10)
        gap = 11;
    if (gap < 1)
        gap = 1;
    return gap;
}

void qsort(void *base, size_t nmemb, size_t size,
       int (*compar) (const void *, const void *))
{
    size_t gap = nmemb;
    size_t i, j;
    char *p1, *p2;
    int swapped;
    if (!nmemb)
        return;
    do {
        gap = newgap(gap);
        swapped = 0;
        for (i = 0, p1 = base; i < nmemb - gap; i++, p1 += size) {
            j = i + gap;
            if (compar(p1, p2 = (char *)base + j * size) > 0) {
                memswap(p1, p2, size);
                swapped = 1;
            }
        }
    } while (gap > 1 || swapped);
}

/* * srand48.c */
unsigned short __rand48_seed[3];	/* Common with mrand48.c, lrand48.c */
void srand48(long seedval)
{
	__rand48_seed[0] = 0x330e;
	__rand48_seed[1] = (unsigned short)seedval;
	__rand48_seed[2] = (unsigned short)((uint32_t) seedval >> 16);
}

/* * sscanf() */
int sscanf(const char *str, const char *format, ...)
{
	va_list ap;
	int rv;
	va_start(ap, format);
	rv = vsscanf(str, format, ap);
	va_end(ap);
	return rv;
}

/* * strcasecmp.c */
int strcasecmp(const char *s1, const char *s2)
{
	const unsigned char *c1 = (const unsigned char *)s1;
	const unsigned char *c2 = (const unsigned char *)s2;
	unsigned char ch;
	int d = 0;
	while (1) {
		/* toupper() expects an unsigned char (implicitly cast to int)
		   as input, and returns an int, which is exactly what we want. */
		d = toupper(ch = *c1++) - toupper(*c2++);
		if (d || !ch)
			break;
	}
	return d;
}

/* * strcat.c */
char *strcat(char *dst, const char *src)
{
	strcpy(strchr(dst, '\0'), src);
	return dst;
}

/* * strchr.c */
char *strchr(const char *s, int c)
{
	while (*s != (char)c) {
		if (!*s)
			return NULL;
		s++;
	}
	return (char *)s;
}

/* * strcmp.c */
int strcmp(const char *s1, const char *s2)
{
	const unsigned char *c1 = (const unsigned char *)s1;
	const unsigned char *c2 = (const unsigned char *)s2;
	unsigned char ch;
	int d = 0;
	while (1) {
		d = (int)(ch = *c1++) - (int)*c2++;
		if (d || !ch)
			break;
	}
	return d;
}

/* * strcpy.c */
char *strcpy(char *dst, const char *src)
{
	char *q = dst;
	const char *p = src;
	char ch;
	do {
		*q++ = ch = *p++;
	} while (ch);
	return dst;
}

/*
FUNCTION
	<<strcspn>>---count characters not in string

INDEX
	strcspn

ANSI_SYNOPSIS
	size_t strcspn(const char *<[s1]>, const char *<[s2]>);

TRAD_SYNOPSIS
	size_t strcspn(<[s1]>, <[s2]>)
	char *<[s1]>;
	char *<[s2]>;

DESCRIPTION
	This function computes the length of the initial part of
	the string pointed to by <[s1]> which consists entirely of
	characters <[NOT]> from the string pointed to by <[s2]>
	(excluding the terminating null character).

RETURNS
	<<strcspn>> returns the length of the substring found.

PORTABILITY
<<strcspn>> is ANSI C.

<<strcspn>> requires no supporting OS subroutines.
 */
size_t strcspn(const char *s1, const char *s2)
{
  const char *s = s1;
  const char *c;
  while (*s1)
    {
      for (c = s2; *c; c++)
	{
	  if (*s1 == *c)
	    break;
	}
      if (*c)
	break;
      s1++;
    }
  return s1 - s;
}

/* * strdup.c */
char *strdup(const char *s)
{
	int l = strlen(s) + 1;
	char *d = malloc(l);
	if (d)
		memcpy(d, s, l);
	return d;
}

/* * strlcat.c */
size_t strlcat(char *dst, const char *src, size_t size)
{
	size_t bytes = 0;
	char *q = dst;
	const char *p = src;
	char ch;
	while (bytes < size && *q) {
		q++;
		bytes++;
	}
	if (bytes == size)
		return (bytes + strlen(src));
	while ((ch = *p++)) {
		if (bytes + 1 < size)
			*q++ = ch;
		bytes++;
	}
	*q = '\0';
	return bytes;
}

/* * strlcpy.c */
size_t strlcpy(char *dst, const char *src, size_t size)
{
	size_t bytes = 0;
	char *q = dst;
	const char *p = src;
	char ch;
	while ((ch = *p++)) {
		if (bytes + 1 < size)
			*q++ = ch;
		bytes++;
	}
	/* If size == 0 there is no space for a final null... */
	if (size)
		*q = '\0';
	return bytes;
}

/* * strlen() */
size_t strlen(const char *s)
{
	const char *ss = s;
	while (*ss)
		ss++;
	return ss - s;
}

/* * strncasecmp.c */
int strncasecmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *c1 = (const unsigned char *)s1;
	const unsigned char *c2 = (const unsigned char *)s2;
	unsigned char ch;
	int d = 0;
	while (n--) {
		/* toupper() expects an unsigned char (implicitly cast to int)
		   as input, and returns an int, which is exactly what we want. */
		d = toupper(ch = *c1++) - toupper(*c2++);
		if (d || !ch)
			break;
	}
	return d;
}

/* * strncat.c */
char *strncat(char *dst, const char *src, size_t n)
{
	char *q = strchr(dst, '\0');
	const char *p = src;
	char ch;
	while (n--) {
		*q++ = ch = *p++;
		if (!ch)
			return dst;
	}
	*q = '\0';
	return dst;
}

/* * strncmp.c */
int strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *c1 = (const unsigned char *)s1;
	const unsigned char *c2 = (const unsigned char *)s2;
	unsigned char ch;
	int d = 0;
	while (n--) {
		d = (int)(ch = *c1++) - (int)*c2++;
		if (d || !ch)
			break;
	}
	return d;
}

/* * strncpy.c */
char *strncpy(char *dst, const char *src, size_t n)
{
	char *q = dst;
	const char *p = src;
	char ch;
	while (n) {
		n--;
		*q++ = ch = *p++;
		if (!ch)
			break;
	}
	/* The specs say strncpy() fills the entire buffer with NUL.  Sigh. */
	memset(q, 0, n);
	return dst;
}

/* * strndup.c */
char *strndup(const char *s, size_t n)
{
	int l = n > strlen(s) ? strlen(s) + 1 : n + 1;
	char *d = malloc(l);
	if (!d)
		return NULL;
	memcpy(d, s, l);
	d[n] = '\0';
	return d;
}

/* * strnlen() */
size_t strnlen(const char *s, size_t maxlen)
{
	const char *ss = s;
	/* Important: the maxlen test must precede the reference through ss;
	   since the byte beyond the maximum may segfault */
	while ((maxlen > 0) && *ss) {
		ss++;
		maxlen--;
	}
	return ss - s;
}

/* * strntoimax.c */
intmax_t strntoimax(const char *nptr, char **endptr, int base, size_t n)
{
	return (intmax_t) strntoumax(nptr, endptr, base, n);
}

/* * strntoumax.c */
static inline int digitval(int ch)
{
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	} else if (ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 10;
	} else if (ch >= 'a' && ch <= 'z') {
		return ch - 'a' + 10;
	} else {
		return -1;
	}
}

uintmax_t strntoumax(const char *nptr, char **endptr, int base, size_t n)
{
	int minus = 0;
	uintmax_t v = 0;
	int d;
	while (n && isspace((unsigned char)*nptr)) {
		nptr++;
		n--;
	}
	/* Single optional + or - */
	if (n) {
		char c = *nptr;
		if (c == '-' || c == '+') {
			minus = (c == '-');
			nptr++;
			n--;
		}
	}
	if (base == 0) {
		if (n >= 2 && nptr[0] == '0' &&
		    (nptr[1] == 'x' || nptr[1] == 'X')) {
			n -= 2;
			nptr += 2;
			base = 16;
		} else if (n >= 1 && nptr[0] == '0') {
			n--;
			nptr++;
			base = 8;
		} else {
			base = 10;
		}
	} else if (base == 16) {
		if (n >= 2 && nptr[0] == '0' &&
		    (nptr[1] == 'x' || nptr[1] == 'X')) {
			n -= 2;
			nptr += 2;
		}
	}
	while (n && (d = digitval(*nptr)) >= 0 && d < base) {
		v = v * base + d;
		n--;
		nptr++;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return minus ? -v : v;
}

/*
FUNCTION
	<<strpbrk>>---find characters in string

INDEX
	strpbrk

ANSI_SYNOPSIS
	#include <string.h>
	char *strpbrk(const char *<[s1]>, const char *<[s2]>);

TRAD_SYNOPSIS
	#include <string.h>
	char *strpbrk(<[s1]>, <[s2]>)
	char *<[s1]>;
	char *<[s2]>;

DESCRIPTION
	This function locates the first occurence in the string
	pointed to by <[s1]> of any character in string pointed to by
	<[s2]> (excluding the terminating null character).

RETURNS
	<<strpbrk>> returns a pointer to the character found in <[s1]>, or a
	null pointer if no character from <[s2]> occurs in <[s1]>.

PORTABILITY
<<strpbrk>> requires no supporting OS subroutines.
*/
char *strpbrk(const char *s1, const char *s2)
{
  const char *c = s2;
  if (!*s1)
    return (char *) NULL;
  while (*s1)
    {
      for (c = s2; *c; c++)
	{
	  if (*s1 == *c)
	    break;
	}
      if (*c)
	break;
      s1++;
    }
  if (*c == '\0')
    s1 = NULL;
  return (char *) s1;
}

/* * strrchr.c */
char *strrchr(const char *s, int c)
{
	const char *found = NULL;
	while (*s) {
		if (*s == (char)c)
			found = s;
		s++;
	}
	return (char *)found;
}

/* * strsep.c */
char *strsep(char **stringp, const char *delim)
{
	char *s = *stringp;
	char *e;
	if (!s)
		return NULL;
	e = strpbrk(s, delim);
	if (e)
		*e++ = '\0';
	*stringp = e;
	return s;
}

/*
FUNCTION
	<<strspn>>---find initial match

INDEX
	strspn

ANSI_SYNOPSIS
	#include <string.h>
	size_t strspn(const char *<[s1]>, const char *<[s2]>);

TRAD_SYNOPSIS
	#include <string.h>
	size_t strspn(<[s1]>, <[s2]>)
	char *<[s1]>;
	char *<[s2]>;

DESCRIPTION
	This function computes the length of the initial segment of
	the string pointed to by <[s1]> which consists entirely of
	characters from the string pointed to by <[s2]> (excluding the
	terminating null character).

RETURNS
	<<strspn>> returns the length of the segment found.

PORTABILITY
<<strspn>> is ANSI C.

<<strspn>> requires no supporting OS subroutines.

QUICKREF
	strspn ansi pure
*/
size_t strspn(const char *s1, const char *s2)
{
  const char *s = s1;
  const char *c;
  while (*s1)
    {
      for (c = s2; *c; c++)
	{
	  if (*s1 == *c)
	    break;
	}
      if (*c == '\0')
	break;
      s1++;
    }
  return s1 - s;
}

/* * strstr.c */
char *strstr(const char *haystack, const char *needle)
{
	return (char *)memmem(haystack, strlen(haystack), needle,
			      strlen(needle));
}

/* * strtok.c */
char *strtok(char *s, const char *delim)
{
	static char *holder;
	return strtok_r(s, delim, &holder);
}

char *strtok_r(char *s, const char *delim, char **holder)
{
	if (s)
		*holder = s;
	do {
		s = strsep(holder, delim);
	} while (s && !*s);
	return s;
}

/* * sprintf.c */
int sprintf(char *buffer, const char *format, ...)
{
	va_list ap;
	int rv;
	va_start(ap, format);
	rv = vsnprintf(buffer, PTRDIFF_MAX, format, ap);
	va_end(ap);
	return rv;
}

/*
File: tinyprintf.c

Copyright (C) 2004  Kustaa Nyholm
Copyright (C) 2010  CJlano
Copyright (C) 2011  Petteri Aimonen

This file is dual-licensed. You can use either of these licenses:

1) GNU LGPL
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

2) BSD
Copyright (c) 2004,2012 Kustaa Nyholm / SpareTimeLabs
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Kustaa Nyholm or SpareTimeLabs nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

/* This is a smaller implementation of printf-family of functions,
 * based on tinyprintf code by Kustaa Nyholm.
 * The formats supported by this implementation are: 'd' 'u' 'c' 's' 'x' 'X'.
 * Zero padding and field width are also supported.
 * If the library is compiled with 'PRINTF_SUPPORT_LONG' defined then the
 * long specifier is also supported.
 * Otherwise it is ignored, so on 32 bit platforms there is no point to use
 * PRINTF_SUPPORT_LONG because int == long.
 */
struct param {
    int width; /**< field width */
    char lz;            /**< Leading zeros */
    char sign;          /**<  The sign to display (if any) */
    char alt;           /**< alternate form */
    char base;  /**<  number base (e.g.: 8, 10, 16) */
    char uc;            /**<  Upper case (for base16 only) */
    char *bf;           /**<  Buffer to output */
};

#ifdef PRINTF_LONG_SUPPORT
static void uli2a(unsigned long int num, struct param *p)
{
    int n = 0;
    unsigned long int d = 1;
    char *bf = p->bf;
    while (num / d >= (unsigned int)p->base)
        d *= p->base;
    while (d != 0) {
        int dgt = num / d;
        num %= d;
        d /= p->base;
        if (n || dgt > 0 || d == 0) {
            *bf++ = dgt + (dgt < 10 ? '0' : (p->uc ? 'A' : 'a') - 10);
            ++n;
        }
    }
    *bf = 0;
}

static void li2a(long num, struct param *p)
{
    if (num < 0) {
        num = -num;
        p->sign = '-';
    }
    uli2a(num, p);
}
#endif

static void ui2a(unsigned int num, struct param *p)
{
    int n = 0;
    unsigned int d = 1;
    char *bf = p->bf;
    while (num / d >= (unsigned int)p->base)
        d *= p->base;
    while (d != 0) {
        int dgt = num / d;
        num %= d;
        d /= p->base;
        if (n || dgt > 0 || d == 0) {
            *bf++ = dgt + (dgt < 10 ? '0' : (p->uc ? 'A' : 'a') - 10);
            ++n;
        }
    }
    *bf = 0;
}

static void i2a(int num, struct param *p)
{
    if (num < 0) {
        num = -num;
        p->sign = '-';
    }
    ui2a(num, p);
}

static int a2d(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else if (ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    else if (ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    else
        return -1;
}

static char a2i(char ch, const char **src, int base, int *nump)
{
    const char *p = *src;
    int num = 0;
    int digit;
    while ((digit = a2d(ch)) >= 0) {
        if (digit > base)
            break;
        num = num * base + digit;
        ch = *p++;
    }
    *src = p;
    *nump = num;
    return ch;
}

static int putf(FILE *putp, char c)
{
    if (fputc(c, putp) == EOF)
        return 0;
    else
        return 1;
}

static unsigned putchw(FILE *putp, struct param *p)
{
    unsigned written = 0;
    char ch;
    int n = p->width;
    char *bf = p->bf;

    /* Number of filling characters */
    while (*bf++ && n > 0)
        n--;
    if (p->sign)
        n--;
    if (p->alt && p->base == 16)
        n -= 2;
    else if (p->alt && p->base == 8)
        n--;
    /* Fill with space, before alternate or sign */
    if (!p->lz) {
        while (n-- > 0)
            written += putf(putp, ' ');
    }
    /* print sign */
    if (p->sign)
        written += putf(putp, p->sign);
    /* Alternate */
    if (p->alt && p->base == 16) {
        written += putf(putp, '0');
        written += putf(putp, (p->uc ? 'X' : 'x'));
    } else if (p->alt && p->base == 8) {
        written += putf(putp, '0');
    }
    /* Fill with zeros, after alternate or sign */
    if (p->lz) {
        while (n-- > 0)
            written += putf(putp, '0');
    }
    /* Put actual buffer */
    bf = p->bf;
    while ((ch = *bf++))
        written += putf(putp, ch);
    return written;
}

size_t tfp_format(FILE *putp, const char *fmt, va_list va)
{
    size_t written = 0;
    struct param p;
#ifdef PRINTF_LONG_SUPPORT
    char bf[23];
#else
    char bf[12];
#endif
    p.bf = bf;
    char ch;
    while ((ch = *(fmt++))) {
        if (ch != '%') {
            written += putf(putp, ch);
        } else {
            /* Init parameter struct */
            p.lz = 0;
            p.alt = 0;
            p.width = 0;
            p.sign = 0;
#ifdef PRINTF_LONG_SUPPORT
            char lng = 0;
#endif
            /* Flags */
            while ((ch = *(fmt++))) {
                switch (ch) {
                case '0':
                    p.lz = 1;
                    continue;
                case '#':
                    p.alt = 1;
                    continue;
                default:
                    break;
                }
                break;
            }
            /* Width */
            if (ch >= '0' && ch <= '9') {
                ch = a2i(ch, &fmt, 10, &(p.width));
            }
            if (ch == 'l') {
                ch = *(fmt++);
#ifdef PRINTF_LONG_SUPPORT
                lng = 1;
#endif
            }
            switch (ch) {
            case 0:
                goto abort;
            case 'u':
                p.base = 10;
#ifdef PRINTF_LONG_SUPPORT
                if (lng)
                    uli2a(va_arg(va, unsigned long int), &p);
                else
#endif
                    ui2a(va_arg(va, unsigned int), &p);
                written += putchw(putp, &p);
                break;
            case 'd':
            case 'i':
                p.base = 10;
#ifdef PRINTF_LONG_SUPPORT
                if (lng)
                    li2a(va_arg(va, unsigned long int), &p);
                else
#endif
                    i2a(va_arg(va, int), &p);
                written += putchw(putp, &p);
                break;
            case 'x':
            case 'X':
                p.base = 16;
                p.uc = (ch == 'X');
#ifdef PRINTF_LONG_SUPPORT
                if (lng)
                    uli2a(va_arg(va, unsigned long int), &p);
                else
#endif
                    ui2a(va_arg(va, unsigned int), &p);
                written += putchw(putp, &p);
                break;
            case 'o':
                p.base = 8;
                ui2a(va_arg(va, unsigned int), &p);
                written += putchw(putp, &p);
                break;
            case 'c':
                written += putf(putp, (char)(va_arg(va, int)));
                break;
            case 's':
                p.bf = va_arg(va, char *);
                written += putchw(putp, &p);
                p.bf = bf;
                break;
            case '%':
                written += putf(putp, ch);
            default:
                break;
            }
        }
    }
 abort:;
 return written;
}

int vfprintf(FILE *f, const char *fmt, va_list va) {return tfp_format(f, fmt, va);}

int fprintf(FILE *f, const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    int rv = vfprintf(f, fmt, va);
    va_end(va);
    return rv;
}

int printf(const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    int rv = vfprintf(stdout, fmt, va);
    va_end(va);
    return rv;
}

int vsnprintf(char *str, size_t size, const char *fmt, va_list va)
{
    struct MemFile state;
    FILE *f = fmemopen_w(&state, str, size - 1);
    tfp_format(f, fmt, va);
    *(state.buffer) = '\0';
    return state.bytes_written;
}

int snprintf(char *str, size_t size, const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    int rv = vsnprintf(str, size, fmt, va);
    va_end(va);
    return rv;
}

/* * vasprintf.c */
int vasprintf(char **bufp, const char *format, va_list ap)
{
	va_list ap1;
	int bytes;
	char *p;
	va_copy(ap1, ap);
	bytes = vsnprintf(NULL, 0, format, ap1) + 1;
	va_end(ap1);
	*bufp = p = malloc(bytes);
	if (!p)
		return -1;
	return vsnprintf(p, bytes, format, ap);
}

/* * vprintf.c */
int vprintf(const char *format, va_list ap) {return vfprintf(stdout, format, ap);}

/* * vsprintf.c */
int vsprintf(char *buffer, const char *format, va_list ap) {return vsnprintf(buffer, PTRDIFF_MAX, format, ap);}

/*
 * vsscanf.c
 *
 * vsscanf(), from which the rest of the scanf()
 * family is built
 */
#ifndef LONG_BIT
#define LONG_BIT (CHAR_BIT*sizeof(long))
#endif

enum flags {
	FL_SPLAT = 0x01,	/* Drop the value, do not assign */
	FL_INV   = 0x02,	/* Character-set with inverse */
	FL_WIDTH = 0x04,	/* Field width specified */
	FL_MINUS = 0x08,	/* Negative number */
};

enum ranks {
	rank_char     = -2,
	rank_short    = -1,
	rank_int      = 0,
	rank_long     = 1,
	rank_longlong = 2,
	rank_ptr      = INT_MAX	/* Special value used for pointers */
};

#define MIN_RANK	rank_char
#define MAX_RANK	rank_longlong
#define INTMAX_RANK	rank_longlong
#define SIZE_T_RANK	rank_long
#define PTRDIFF_T_RANK	rank_long

enum bail {
	bail_none = 0,		/* No error condition */
	bail_eof,		/* Hit EOF */
	bail_err		/* Conversion mismatch */
};

static inline const char *skipspace(const char *p)
{
	while (isspace((unsigned char)*p))
		p++;
	return p;
}

#undef set_bit
static inline void set_bit(unsigned long *bitmap, unsigned int bit)
{
	bitmap[bit / LONG_BIT] |= 1UL << (bit % LONG_BIT);
}

#undef test_bit
static inline int test_bit(unsigned long *bitmap, unsigned int bit)
{
	return (int)(bitmap[bit / LONG_BIT] >> (bit % LONG_BIT)) & 1;
}

int vsscanf(const char *buffer, const char *format, va_list ap)
{
	const char *p = format;
	char ch;
	unsigned char uc;
	const char *q = buffer;
	const char *qq;
	uintmax_t val = 0;
	int rank = rank_int;	/* Default rank */
	unsigned int width = UINT_MAX;
	int base;
	enum flags flags = 0;
	enum {
		st_normal,	/* Ground state */
		st_flags,	/* Special flags */
		st_width,	/* Field width */
		st_modifiers,	/* Length or conversion modifiers */
		st_match_init,	/* Initial state of %[ sequence */
		st_match,	/* Main state of %[ sequence */
		st_match_range,	/* After - in a %[ sequence */
	} state = st_normal;
	char *sarg = NULL;	/* %s %c or %[ string argument */
	enum bail bail = bail_none;
	int sign;
	int converted = 0;	/* Successful conversions */
	unsigned long matchmap[((1 << CHAR_BIT) + (LONG_BIT - 1)) / LONG_BIT];
	int matchinv = 0;	/* Is match map inverted? */
	unsigned char range_start = 0;
	(void)sign;
	while ((ch = *p++) && !bail) {
		switch (state) {
		case st_normal:
			if (ch == '%') {
				state = st_flags;
				flags = 0;
				rank = rank_int;
				width = UINT_MAX;
			} else if (isspace((unsigned char)ch)) {
				q = skipspace(q);
			} else {
				if (*q == ch)
					q++;
				else
					bail = bail_err; /* Match failure */
			}
			break;
		case st_flags:
			switch (ch) {
			case '*':
				flags |= FL_SPLAT;
				break;
			case '0': /* falls-through */
			case '1': /* falls-through */
			case '2': /* falls-through */
			case '3': /* falls-through */
			case '4': /* falls-through */
			case '5': /* falls-through */
			case '6': /* falls-through */
			case '7': /* falls-through */
			case '8': /* falls-through */
			case '9':
				width = (ch - '0');
				state = st_width;
				flags |= FL_WIDTH;
				break;
			default:
				state = st_modifiers;
				p--;	/* Process this character again */
				break;
			}
			break;
		case st_width:
			if (ch >= '0' && ch <= '9') {
				width = width * 10 + (ch - '0');
			} else {
				state = st_modifiers;
				p--;	/* Process this character again */
			}
			break;
		case st_modifiers:
			switch (ch) {
				/* Length modifiers - nonterminal sequences */
			case 'h':
				rank--;	/* Shorter rank */
				break;
			case 'l':
				rank++;	/* Longer rank */
				break;
			case 'j':
				rank = INTMAX_RANK;
				break;
			case 'z':
				rank = SIZE_T_RANK;
				break;
			case 't':
				rank = PTRDIFF_T_RANK;
				break;
			case 'L':
			case 'q':
				rank = rank_longlong;	/* long double/long long */
				break;
			default:
				/* Output modifiers - terminal sequences */
				/* Next state will be normal */
				state = st_normal;
				/* Canonicalize rank */
				if (rank < MIN_RANK)
					rank = MIN_RANK;
				else if (rank > MAX_RANK)
					rank = MAX_RANK;
				switch (ch) {
				case 'P':	/* Upper case pointer */
				case 'p':	/* Pointer */
					rank = rank_ptr;
					base = 0;
					sign = 0;
					goto scan_int;
				case 'i':	/* Base-independent integer */
					base = 0;
					sign = 1;
					goto scan_int;
				case 'd':	/* Decimal integer */
					base = 10;
					sign = 1;
					goto scan_int;
				case 'o':	/* Octal integer */
					base = 8;
					sign = 0;
					goto scan_int;
				case 'u':	/* Unsigned decimal integer */
					base = 10;
					sign = 0;
					goto scan_int;
				case 'x':	/* Hexadecimal integer */
				case 'X':
					base = 16;
					sign = 0;
					goto scan_int;
				case 'n':	/* # of characters consumed */
					val = (q - buffer);
					goto set_integer;
				      scan_int:
					q = skipspace(q);
					if (!*q) {
						bail = bail_eof;
						break;
					}
					val =
					    strntoumax(q, (char **)&qq, base,
						       width);
					if (qq == q) {
						bail = bail_err;
						break;
					}
					q = qq;
					if (!(flags & FL_SPLAT))
						converted++;
					/* fall through */
				      set_integer:
					if (!(flags & FL_SPLAT)) {
						switch (rank) {
						case rank_char:
							*va_arg(ap,
								unsigned char *)
								= val;
							break;
						case rank_short:
							*va_arg(ap,
								unsigned short
								*) = val;
							break;
						case rank_int:
							*va_arg(ap,
								unsigned int *)
							    = val;
							break;
						case rank_long:
							*va_arg(ap,
								unsigned long *)
								= val;
							break;
						case rank_longlong:
							*va_arg(ap,
								unsigned long
								long *) = val;
							break;
						case rank_ptr:
							*va_arg(ap, void **) =
								(void *)
								(uintptr_t)val;
							break;
						}
					}
					break;
				case 'c':	/* Character */
					/* Default width == 1 */
					width = (flags & FL_WIDTH) ? width : 1;
					if (flags & FL_SPLAT) {
						while (width--) {
							if (!*q) {
								bail = bail_eof;
								break;
							}
						}
					} else {
						sarg = va_arg(ap, char *);
						while (width--) {
							if (!*q) {
								bail = bail_eof;
								break;
							}
							*sarg++ = *q++;
						}
						if (!bail)
							converted++;
					}
					break;
				case 's':	/* String */
					uc = 1;	/* Anything nonzero */
					if (flags & FL_SPLAT) {
						while (width-- && (uc = *q) &&
						       !isspace(uc)) {
							q++;
						}
					} else {
						char *sp;
						sp = sarg = va_arg(ap, char *);
						while (width-- && (uc = *q) &&
						       !isspace(uc)) {
							*sp++ = uc;
							q++;
						}
						if (sarg != sp) {
							/* Terminate output */
							*sp = '\0';
							converted++;
						}
					}
					if (!uc)
						bail = bail_eof;
					break;
				case '[':	/* Character range */
					sarg = (flags & FL_SPLAT) ? NULL
						: va_arg(ap, char *);
					state = st_match_init;
					matchinv = 0;
					memset(matchmap, 0, sizeof matchmap);
					break;
				case '%':	/* %% sequence */
					if (*q == '%')
						q++;
					else
						bail = bail_err;
					break;
				default:	/* Anything else */
					/* Unknown sequence */
					bail = bail_err;
					break;
				}
			}
			break;
		case st_match_init:	/* Initial state for %[ match */
			if (ch == '^' && !(flags & FL_INV)) {
				matchinv = 1;
			} else {
				set_bit(matchmap, (unsigned char)ch);
				state = st_match;
			}
			break;
		case st_match:	/* Main state for %[ match */
			if (ch == ']') {
				goto match_run;
			} else if (ch == '-') {
				range_start = (unsigned char)ch;
				state = st_match_range;
			} else {
				set_bit(matchmap, (unsigned char)ch);
			}
			break;
		case st_match_range:	/* %[ match after - */
			if (ch == ']') {
				/* - was last character */
				set_bit(matchmap, (unsigned char)'-');
				goto match_run;
			} else {
				int i;
				for (i = range_start; i < (unsigned char)ch;
				     i++)
					set_bit(matchmap, i);
				state = st_match;
			}
			break;
		      match_run:	/* Match expression finished */
			qq = q;
			uc = 1;	/* Anything nonzero */
			while (width && (uc = *q)
			       && test_bit(matchmap, uc)^matchinv) {
				if (sarg)
					*sarg++ = uc;
				q++;
			}
			if (q != qq && sarg) {
				*sarg = '\0';
				converted++;
			} else {
				bail = bail_err;
			}
			if (!uc)
				bail = bail_eof;
			break;
		}
	}
	if (bail == bail_eof && !converted)
		converted = -1;	/* Return EOF (-1) */
	return converted;
}
