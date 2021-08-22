#include "pra_31.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_8024024C_D7EFAC);
/*
ApiStatus N(func_8024024C_D7EFAC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024119C_D7FEFC) = FALSE;
    }

    if (N(D_8024119C_D7FEFC)) {
        N(D_8024119C_D7FEFC) = FALSE;
        set_variable(script, *args, N(D_802411A0_D7FF00));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_802402A0_D7F000);
/*
ApiStatus N(func_802402A0_D7F000)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802411A0_D7FF00) = get_variable(script, *args);
    N(D_8024119C_D7FEFC) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_802402D8_D7F038);
/*
ApiStatus N(func_802402D8_D7F038)(Evt* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_80240374_D7F0D4);
/*
ApiStatus N(func_80240374_D7F0D4)(Evt* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_80240410_D7F170);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_80240468_D7F1C8);
