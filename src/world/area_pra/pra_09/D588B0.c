#include "pra_09.h"

#include "world/common/atomic/Reflection.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_09/D588B0", func_8024114C_D599DC);

INCLUDE_ASM(s32, "world/area_pra/pra_09/D588B0", func_802411A0_D59A30);

extern s32 flo_18_shakeTree[];

ApiStatus func_802411D8_D59A68(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            flo_18_shakeTree[i] = ptr[i];
        }
        flo_18_shakeTree[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            flo_18_shakeTree[i] = i + 16;
            flo_18_shakeTree[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 D_80246BE8[];

ApiStatus func_80241274_D59B04(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80246BE8[i] = ptr[i];
        }
        D_80246BE8[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80246BE8[i] = i + 128;
            D_80246BE8[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_pra/pra_09/D588B0", func_80241310_D59BA0);

INCLUDE_ASM(s32, "world/area_pra/pra_09/D588B0", func_802413A4_D59C34);

INCLUDE_ASM(s32, "world/area_pra/pra_09/D588B0", func_802414F4_D59D84);

INCLUDE_ASM(s32, "world/area_pra/pra_09/D588B0", func_802415F8_D59E88);
