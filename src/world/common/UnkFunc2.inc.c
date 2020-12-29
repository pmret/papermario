#include "common.h"
#include "map.h"

s32 M(UnkFunc2)(s32 arg0) {
    u32 val;

    arg0 &= ~0x1000000;
    val = arg0 + ~0x6000B;
    if (val < 0x10 && val & 1) {
        arg0--;
    }

    return arg0;
}
