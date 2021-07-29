#include "kpa_82.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_8024027C_A7A77C);
/*
ApiStatus N(func_8024027C_A7A77C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80240C20_A7B120) = FALSE;
    }

    if (N(D_80240C20_A7B120)) {
        N(D_80240C20_A7B120) = FALSE;
        set_variable(script, *args, N(D_80240C24_A7B124));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_802402D0_A7A7D0);
/*
ApiStatus N(func_802402D0_A7A7D0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80240C24_A7B124) = get_variable(script, *args);
    N(D_80240C20_A7B120) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_80240308_A7A808);
/*
ApiStatus N(func_80240308_A7A808)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
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

INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_802403A4_A7A8A4);
/*
ApiStatus N(func_802403A4_A7A8A4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
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
