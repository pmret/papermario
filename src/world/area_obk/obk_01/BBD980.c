#include "obk_01.h"

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_802407E0_BBD980);
/*
ApiStatus N(func_802407E0_BBD980)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802440F0_BC1290) == NULL) {
        N(D_802440F0_BC1290) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802440F0_BC1290)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802440F0_BC1290)[i];
        }
        heap_free(N(D_802440F0_BC1290));
        N(D_802440F0_BC1290) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80240B24_BBDCC4);
/*
ApiStatus N(func_80240B24_BBDCC4)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80244154_BC12F4) = FALSE;
    }

    if (N(D_80244154_BC12F4)) {
        N(D_80244154_BC12F4) = FALSE;
        evt_set_variable(script, *args, N(D_80244158_BC12F8));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80240B78_BBDD18);
/*
ApiStatus N(func_80240B78_BBDD18)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80244158_BC12F8) = evt_get_variable(script, *args);
    N(D_80244154_BC12F4) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80240BB0_BBDD50);
/*
ApiStatus N(func_80240BB0_BBDD50)(Evt* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80240EC8_BBE068);
/*
ApiStatus N(func_80240EC8_BBE068)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80240F0C_BBE0AC);
/*
ApiStatus N(func_80240F0C_BBE0AC)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80240F38_BBE0D8);

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80241094_BBE234);
