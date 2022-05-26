#ifndef _STRING_H
#define _STRING_H
/*
	string.h
*/

#ifndef _SIZE_T_DEF
#define _SIZE_T_DEF
typedef unsigned size_t;
#endif

#include "memory.h"

char *stpcpy(char *,const char *);
char *strcat(char *,const char *);
char *strchr(const char *,int);
int  strcmp(const char *,const char *);
char *strcpy(char *,const char *);
size_t strcspn(const char *,const char *);
char *strdup(const char *);
char *strerror(int);
int  stricmp(const char *,const char *);
size_t strlen(const char *);
char *strlwr(char *);
char *strncat(char *,const char *,size_t);
int  strncmp(const char *,const char *,size_t);
char *strncpy(char *,const char *,size_t);
int  strnicmp(const char *,const char *,size_t);
char *strnset(char *,int,size_t);
char *strpbrk(const char *,const char *);
char *strrchr(const char *,int);
char *strrev(char *);
char *strset(char *,int);
size_t strspn(const char *,const char *);
char *strstr(const char *,const char *);
char *strtok(char *,const char *);
char *strupr(char *);

#define strcmpi(s1,s2)		stricmp(s1,s2)
#define strncmpi(s1,s2,n)	strnicmp(s1,s2,n)

#endif
