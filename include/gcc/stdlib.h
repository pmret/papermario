#ifndef _STDLIB_H
#define _STDLIB_H
/*
		stdlib.h
*/

#ifndef _SIZE_T_DEF
#define _SIZE_T_DEF
typedef unsigned size_t;
#endif

#ifndef _DIV_T_DEF
#define _DIV_T_DEF
typedef	struct DIV_T {
	int quot;
	int rem;
} div_t;
#endif

#ifndef _LDIV_T_DEF
#define _LDIV_T_DEF
typedef	struct LDIV_T {
	long quot;
	long rem;
} ldiv_t;
#endif

#ifndef _LLDIV_T_DEF
#define _LLDIV_T_DEF
typedef struct lldiv_t
{
    long long quot;
    long long rem;
} lldiv_t;
#endif

#ifndef NULL
#define NULL		0
#endif

#define	_max(a,b)	(((a) > (b)) ? (a) : (b))
#define	_min(a,b)	(((a) < (b)) ? (a) : (b))

#define	RAND_MAX	32767

int  rand(void);
void srand(unsigned);

int  abs(int);
long labs(long);

div_t  div(int,int);
ldiv_t ldiv(long,long);
lldiv_t lldiv(long long, long long);

int  atoi(const char *);
long atol(const char *);

long strtol(const char *,char **,int);
unsigned long strtoul(const char *,char **,int);

char *itoa(int,char *,int);
char *ltoa(long,char *,int);
char *ultoa(unsigned long,char *,int);

double atof(const char *);
double strtod(const char *,char **);

void qsort(void *,size_t,size_t,int (*)(const void *,const void *));
void *bsearch(const void *,const void *,size_t,size_t,int (*)(const void *,const void *));

void *malloc(size_t);
void *calloc(size_t,size_t);
void *realloc(void *,size_t);
void free(void *);

void exit(int);

void abort(void);

#endif
