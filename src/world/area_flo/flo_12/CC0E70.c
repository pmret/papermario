#include "flo_12.h"

#include "world/common/SomeMatrixOperations.inc.c"


INCLUDE_ASM(s32, "world/area_flo/flo_12/CC0E70", func_8024027C_CC10AC);
/*
ApiStatus N(func_8024027C_CC10AC)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802417EC_CC261C) == NULL) {
        N(D_802417EC_CC261C) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802417EC_CC261C)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802417EC_CC261C)[i];
        }
        heap_free(N(D_802417EC_CC261C));
        N(D_802417EC_CC261C) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_12/CC0E70", func_802405C0_CC13F0);
/*
ApiStatus N(func_802405C0_CC13F0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80241850_CC2680) = FALSE;
    }

    if (N(D_80241850_CC2680)) {
        N(D_80241850_CC2680) = FALSE;
        set_variable(script, *args, N(D_80241854_CC2684));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_12/CC0E70", func_80240614_CC1444);
/*
ApiStatus N(func_80240614_CC1444)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241854_CC2684) = get_variable(script, *args);
    N(D_80241850_CC2680) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_12/CC0E70", func_8024064C_CC147C);
/*
ApiStatus N(func_8024064C_CC147C)(ScriptInstance* script, s32 isInitialCall) {
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
            N(D_80244A20)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/
