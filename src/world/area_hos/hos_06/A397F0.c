#include "hos_06.h"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240310_A397F0);
/*
ApiStatus N(func_80240310_A397F0)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &N(D_80241C68_BE09F8);
    s32 i;
    s32* test;

    if (*ptr == NULL) {
        i = heap_malloc(16 * sizeof(s32));
        *ptr = i;
        for (i = 0, test = *ptr; i < 16; i++) {
            *test++ = script->varTable[i];
        }
    } else {
        for (i = 0, test = *ptr; i < 16; i++) {
            script->varTable[i] = *test++;
        }
        ptr = &N(D_80241C68_BE09F8);
        heap_free(*ptr);
        *ptr = NULL;
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
    s32* ptr;

    if (isInitialCall) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
    }

    ptr = &D_80241CCC_BE0A5C;
    if (*ptr != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
        set_variable(script, *args, D_80241CD0_BE0A60);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_802406A8_A39B88);
/*
ApiStatus N(func_802406A8_A39B88)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
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
            N(D_80244A20)[0x70] = 0;
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
