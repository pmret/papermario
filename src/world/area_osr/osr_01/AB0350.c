#include "osr_01.h"

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_80240360_AB0350);
/*
ApiStatus N(func_80240360_AB0350)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802411B8_AB11A8) == NULL) {
        N(D_802411B8_AB11A8) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802411B8_AB11A8)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802411B8_AB11A8)[i];
        }
        heap_free(N(D_802411B8_AB11A8));
        N(D_802411B8_AB11A8) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_802406A4_AB0694);
/*
ApiStatus N(func_802406A4_AB0694)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024121C_AB120C) = FALSE;
    }

    if (N(D_8024121C_AB120C)) {
        N(D_8024121C_AB120C) = FALSE;
        evt_set_variable(script, *args, N(D_80241220_AB1210));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_802406F8_AB06E8);
/*
ApiStatus N(func_802406F8_AB06E8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241220_AB1210) = evt_get_variable(script, *args);
    N(D_8024121C_AB120C) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_80240730_AB0720);
/*
ApiStatus N(func_80240730_AB0720)(Evt* script, s32 isInitialCall) {
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

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_80240A48_AB0A38);
/*
ApiStatus N(func_80240A48_AB0A38)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_80240A8C_AB0A7C);
/*
ApiStatus N(func_80240A8C_AB0A7C)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/
