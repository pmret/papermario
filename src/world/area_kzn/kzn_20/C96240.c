#include "kzn_20.h"

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_80240310_C96240);
/*
ApiStatus N(func_80240310_C96240)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241780_C976B0) == NULL) {
        N(D_80241780_C976B0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241780_C976B0)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80241780_C976B0)[i];
        }
        heap_free(N(D_80241780_C976B0));
        N(D_80241780_C976B0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_80240654_C96584);
/*
ApiStatus N(func_80240654_C96584)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802417E4_C97714) = FALSE;
    }

    if (N(D_802417E4_C97714)) {
        N(D_802417E4_C97714) = FALSE;
        set_variable(script, *args, N(D_802417E8_C97718));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_802406A8_C965D8);
/*
ApiStatus N(func_802406A8_C965D8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802417E8_C97718) = get_variable(script, *args);
    N(D_802417E4_C97714) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_802406E0_C96610);
/*
ApiStatus N(func_802406E0_C96610)(ScriptInstance* script, s32 isInitialCall) {
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

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_802409F8_C96928);
/*
ApiStatus N(func_802409F8_C96928)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2].s);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4].s;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_80240A3C_C9696C);
/*
ApiStatus N(func_80240A3C_C9696C)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2].s)->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_80240A68_C96998);

#include "world/common/GetFloorCollider.inc.c"
