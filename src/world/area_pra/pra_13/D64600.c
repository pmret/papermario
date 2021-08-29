#include "pra_13.h"

#include "world/common/reflection.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_8024114C_D6572C);
/*
ApiStatus N(func_8024114C_D6572C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802422CC_D668AC) = FALSE;
    }

    if (N(D_802422CC_D668AC)) {
        N(D_802422CC_D668AC) = FALSE;
        evt_set_variable(script, *args, N(D_802422D0_D668B0));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802411A0_D65780);
/*
ApiStatus N(func_802411A0_D65780)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802422D0_D668B0) = evt_get_variable(script, *args);
    N(D_802422CC_D668AC) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802411D8_D657B8);
/*
ApiStatus N(func_802411D8_D657B8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_80241274_D65854);
/*
ApiStatus N(func_80241274_D65854)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_80241310_D658F0);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802413A4_D65984);
/*
ApiStatus N(func_802413A4_D65984)(Evt* script, s32 isInitialCall) {
    switch_to_partner(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802413D0_D659B0);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_8024140C_D659EC);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802414BC_D65A9C);
