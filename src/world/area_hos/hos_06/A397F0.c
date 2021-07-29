#include "hos_06.h"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240310_A397F0);
/*
ApiStatus N(func_80240310_A397F0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80242C08_A3C0E8) == NULL) {
        N(D_80242C08_A3C0E8) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80242C08_A3C0E8)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80242C08_A3C0E8)[i];
        }
        heap_free(N(D_80242C08_A3C0E8));
        N(D_80242C08_A3C0E8) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#define NAMESPACE dup2_hos_06
#include "world/common/GetItemName.inc.c"
#define NAMESPACE hos_06

#define NAMESPACE dup_hos_06
#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"
#define NAMESPACE hos_06

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240654_A39B34);
/*
ApiStatus N(func_80240654_A39B34)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80242C6C_A3C14C) = FALSE;
    }

    if (N(D_80242C6C_A3C14C)) {
        N(D_80242C6C_A3C14C) = FALSE;
        set_variable(script, *args, N(D_80242C70_A3C150));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_802406A8_A39B88);
/*
ApiStatus N(func_802406A8_A39B88)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80242C70_A3C150) = get_variable(script, *args);
    N(D_80242C6C_A3C14C) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_802406E0_A39BC0);
/*
ApiStatus N(func_802406E0_A39BC0)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_802409F8_A39ED8);
/*
ApiStatus N(func_802409F8_A39ED8)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240A3C_A39F1C);
/*
ApiStatus N(func_80240A3C_A39F1C)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240A68_A39F48);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240A94_A39F74);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240AD0_A39FB0);
