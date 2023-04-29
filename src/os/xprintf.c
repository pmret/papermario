#include "stdlib/stdarg.h"
#include "libc/xstdio.h"
#include "gcc/string.h"

#define isdigit(x) ((x >= '0' && x <= '9'))
#define LDSIGN(x) (((unsigned short *)&(x))[0] & 0x8000)

#define ATOI(dst, src)                   \
    for (dst = 0; isdigit(*src); ++src)  \
    {                                    \
        if (dst < 999)                   \
            dst = dst * 10 + *src - '0'; \
    }

#define MAX_PAD ((sizeof(spaces) - 1))
#define PAD(s, n)                                             \
    if (0 < (n))                                              \
    {                                                         \
        int i, j = (n);                                       \
        for (; 0 < j; j -= i)                                 \
        {                                                     \
            i = MAX_PAD < (unsigned int)j ? (int)MAX_PAD : j; \
            PUT(s, i);                                        \
        }                                                     \
    }
#define PUT(s, n)                                \
    if (0 < (n))                                 \
    {                                            \
        if ((arg = (*prout)(arg, s, n)) != NULL) \
            x.nchar += (n);                      \
        else                                     \
            return x.nchar;                      \
    }
static char spaces[] = "                                ";
static char zeroes[] = "00000000000000000000000000000000";

static void _Putfld(_Pft *pf, va_list *pap, char code, char *ac);

int _Printf(outfun prout, char *arg, const char *fmt, va_list args) {
    _Pft x;
    const char *s;
    char c;
    const char *t;
    static const char fchar[] = {' ', '+', '-', '#', '0', '\0'};
    static const int fbit[] = {FLAGS_SPACE, FLAGS_PLUS, FLAGS_MINUS, FLAGS_HASH, FLAGS_ZERO, 0};
    char ac[32];

    x.nchar = 0;

    for (;;) {
        s = fmt;

        for (c = *s; c != 0 && c != '%';) {
            c = *++s;
        }

        PUT(fmt, s - fmt);

        if (c == 0) {
            return x.nchar;
        }

        fmt = ++s;

        for (x.flags = 0; (t = strchr(fchar, *s)) != NULL; s++) {
            x.flags |= fbit[t - fchar];
        }

        if (*s == '*') {
            x.width = va_arg(args, int);

            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= FLAGS_MINUS;
            }
            s++;
        } else {
            ATOI(x.width, s);
        }

        if (*s != '.') {
            x.prec = -1;
        } else if (*++s == '*') {
            x.prec = va_arg(args, int);
            ++s;
        } else {
            ATOI(x.prec, s);
        }

        x.qual = strchr("hlL", *s) ? *s++ : '\0';

        if (x.qual == 'l' && *s == 'l') {
            x.qual = 'L';
            ++s;
        }

        _Putfld(&x, &args, *s, ac);
        x.width -= x.n0 + x.nz0 + x.n1 + x.nz1 + x.n2 + x.nz2;

        if (!(x.flags & FLAGS_MINUS)) {
            PAD(spaces, x.width);
        }

        PUT(ac, x.n0);
        PAD(zeroes, x.nz0);
        PUT(x.s, x.n1);
        PAD(zeroes, x.nz1);
        PUT(x.s + x.n1, x.n2);
        PAD(zeroes, x.nz2);

        if (x.flags & FLAGS_MINUS) {
            PAD(spaces, x.width);
        }

        fmt = s + 1;
    }
    return 0;
}

static void _Putfld(_Pft *x, va_list *args, char type, char *buff) {
    x->n0 = x->nz0 = x->n1 = x->nz1 = x->n2 =
        x->nz2 = 0;

    switch (type) {
        case 'c':
            buff[x->n0++] = va_arg(*args, int);
            break;
        case 'd':
        case 'i':
            if (x->qual == 'l') {
                x->v.ll = va_arg(*args, int);
            } else if (x->qual == 'L') {
                x->v.ll = va_arg(*args, s64);
            } else {
                x->v.ll = va_arg(*args, int);
            }

            if (x->qual == 'h') {
                x->v.ll = (s16)x->v.ll;
            }

            if (x->v.ll < 0) {
                buff[x->n0++] = '-';
            } else if (x->flags & FLAGS_PLUS) {
                buff[x->n0++] = '+';
            } else if (x->flags & FLAGS_SPACE) {
                buff[x->n0++] = ' ';
            }

            x->s = (char *)&buff[x->n0];

            _Litob(x, type);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            if (x->qual == 'l') {
                x->v.ll = va_arg(*args, int);
            } else if (x->qual == 'L') {
                x->v.ll = va_arg(*args, s64);
            } else {
                x->v.ll = va_arg(*args, int);
            }

            if (x->qual == 'h') {
                x->v.ll = (u16)x->v.ll;
            } else if (x->qual == 0) {
                x->v.ll = (unsigned int)x->v.ll;
            }

            if (x->flags & FLAGS_HASH) {
                buff[x->n0++] = '0';

                if (type == 'x' || type == 'X') {
                    buff[x->n0++] = type;
                }
            }

            x->s = (char *)&buff[x->n0];
            _Litob(x, type);
            break;
        case 'e':
        case 'f':
        case 'g':
        case 'E':
        case 'G':
            //... okay?
            x->v.ld = x->qual == 'L' ? va_arg(*args, f64) : va_arg(*args, f64);

            if (LDSIGN(x->v.ld))
                buff[x->n0++] = '-';
            else if (x->flags & FLAGS_PLUS)
                buff[x->n0++] = '+';
            else if (x->flags & FLAGS_SPACE)
                buff[x->n0++] = ' ';

            x->s = (char *)&buff[x->n0];
            _Ldtob(x, type);
            break;

        case 'n':
            if (x->qual == 'h') {
                *(va_arg(*args, u16 *)) = x->nchar;
            } else if (x->qual == 'l') {
                *va_arg(*args, unsigned int *) = x->nchar;
            } else if (x->qual == 'L') {
                *va_arg(*args, u64 *) = x->nchar;
            } else {
                *va_arg(*args, unsigned int *) = x->nchar;
            }

            break;
        case 'p':
            x->v.ll = (long)va_arg(*args, void *);
            x->s = (char *)&buff[x->n0];
            _Litob(x, 'x');
            break;
        case 's':
            x->s = va_arg(*args, char *);
            x->n1 = strlen(x->s);

            if (x->prec >= 0 && x->n1 > x->prec) {
                x->n1 = x->prec;
            }

            break;
        case '%':
            buff[x->n0++] = '%';
            break;
        default:
            buff[x->n0++] = type;
            break;
    }
}

static const s32 padding[] = {0, 0};
