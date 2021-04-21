#include "common.h"
#include "map.h"

s32 N(UnkFunc3)(s32 arg0) {
    s32 temp_v1 = arg0 >> 0x10;
    u32 temp_v1_2;

    switch ((u8)temp_v1) {
        case 1:
            if (arg0 > 0x1000C) {
                return arg0;
            }
            break;
        case 6:
        // unkfunc2 inlined
            temp_v1_2 = arg0 + 0xFFF9FFF4; // + ~0x0006000B
            if (temp_v1_2 < 16) {
                if (temp_v1_2 & 1) {
                    return arg0;
                } else {
                    return arg0 + 1;
                }
            }
            break;
        case 8:
        case 9:
            return arg0;
    }

    return arg0 | 0x1000000;
}
