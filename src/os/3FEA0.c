#define MOVE_ADDU

#include "common.h"
#include "stdlib/stdarg.h"

s32 proutSprintf();

char spaces[] = "                                ";
char zeroes[] = "00000000000000000000000000000000";

INCLUDE_ASM(s32, "os/3FEA0", _Printf);

INCLUDE_ASM(s32, "os/3FEA0", _Putfld);

int sprintf(char* s, const char* fmt, ...) {
    s32 ret;
    va_list argp;
    va_start(argp, fmt);

    ret = _Printf(&proutSprintf, s, fmt, argp);

    if (ret < 0) {
        return ret;
    }

    s[ret] = 0;
    return ret;
}


INCLUDE_ASM(s32, "os/3FEA0", proutSprintf);
