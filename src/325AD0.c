#include "common.h"

extern u32 D_E0200690;
extern u32 D_E0200734[];

u32 func_E0200000(s32 arg0) {
    s32 temp_v0 = D_E0200690 * 4;

    D_E0200690 = (u32)((temp_v0 + 2) * (temp_v0 + 3)) / 4;

    return D_E0200690 % (arg0 + 1);
}

s32 func_E0200044(s32 arg0, s32 arg1) {
    s32 temp_v0 = D_E0200734[arg1 - ((arg1 / 128) * 128)];

    if (temp_v0 < 0) {
        temp_v0 = -temp_v0;
    }

    return temp_v0 % (arg0 + 1);
}

INCLUDE_ASM(s32, "325AD0", func_E02000AC);
