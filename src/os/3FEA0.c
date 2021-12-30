#include "common.h"
#include "stdlib/stdarg.h"

char spaces[] = "                                ";
char zeroes[] = "00000000000000000000000000000000";

INCLUDE_ASM(s32, "os/3FEA0", _Printf);

INCLUDE_ASM(s32, "os/3FEA0", _Putfld);
