#include "kpa_81.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_8024027C_A7873C);
/*
ApiStatus N(func_8024027C_A7873C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80240D98_A79258) = FALSE;
    }

    if (N(D_80240D98_A79258)) {
        N(D_80240D98_A79258) = FALSE;
        evt_set_variable(script, *args, N(D_80240D9C_A7925C));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_802402D0_A78790);
/*
ApiStatus N(func_802402D0_A78790)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80240D9C_A7925C) = evt_get_variable(script, *args);
    N(D_80240D98_A79258) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_80240308_A787C8);
/*
ApiStatus N(func_80240308_A787C8)(Evt* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_802403A4_A78864);
/*
ApiStatus N(func_802403A4_A78864)(Evt* script, s32 isInitialCall) {
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
