#include "pra_13.h"

#include "world/common/atomic/Reflection.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_8024114C_D6572C);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802411A0_D65780);

extern s32 D_80243720[];

ApiStatus func_802411D8_D657B8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80243720[i] = ptr[i];
        }
        D_80243720[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80243720[i] = i + 16;
            D_80243720[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 pra_13_802438E8[];

ApiStatus func_80241274_D65854(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            pra_13_802438E8[i] = ptr[i];
        }
        pra_13_802438E8[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            pra_13_802438E8[i] = i + 128;
            pra_13_802438E8[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_80241310_D658F0);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802413A4_D65984);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802413D0_D659B0);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_8024140C_D659EC);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802414BC_D65A9C);
