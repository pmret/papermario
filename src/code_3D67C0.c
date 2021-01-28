#include "common.h"

INCLUDE_ASM(s32, "code_3D67C0", func_E00D8000);

void func_E00D8120(void){
}

INCLUDE_ASM(s32, "code_3D67C0", func_E00D8128);

void func_E00D825C(void){
}

INCLUDE_ASM(s32, "code_3D67C0", func_E00D8264);

void func_E00D8280(void){
}

void func_E00D8288(s32 l, s32 r, s32 t, s32 b) {
    if (l < 0) {
        l = 0;
    }
    if (r < 0) {
        r = 0;
    }
    if (t < 0) {
        t = 0;
    }
    if (b < 0) {
        b = 0;
    }

    if (l > 319) {
        l = 319;
    }
    if (r > 239) {
        r = 239;
    }
    if (t > 319) {
        t = 319;
    }
    if (b > 239) {
        b = 239;
    }

    gDPFillRectangle(gMasterGfxPos++, l, r, t, b);
}

INCLUDE_ASM(s32, "code_3D67C0", func_E00D8334);

INCLUDE_ASM(s32, "code_3D67C0", func_E00D8630);
