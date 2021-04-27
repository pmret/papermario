#include "sbk_30.h"

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240000_93F5B0);

#include "world/common/UnkFunc27.inc.c"

#include "world/common/UnkFunc26.inc.c"

#include "world/common/SpawnSunEffect.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240370_93F920);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240424_93F9D4);

#include "world/common/NpcJumpFunc3.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

#include "world/common/UnkNpcAIFunc11.inc.c"

#include "world/common/UnkNpcAIFunc10.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_802408B0_93FE60);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_8024095C_93FF0C);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240B64_940114);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240DDC_94038C);
/*
ApiStatus N(func_80240DDC_94038C)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241FF4_9415A4) == NULL) {
        N(D_80241FF4_9415A4) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241FF4_9415A4)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241FF4_9415A4)[i];
        }
        heap_free(N(D_80241FF4_9415A4));
        N(D_80241FF4_9415A4) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241120_9406D0);
/*
ApiStatus N(func_80241120_9406D0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80242058_941608) = FALSE;
    }

    if (N(D_80242058_941608)) {
        N(D_80242058_941608) = FALSE;
        set_variable(script, *args, N(D_8024205C_94160C));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241174_940724);
/*
ApiStatus N(func_80241174_940724)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_8024205C_94160C) = get_variable(script, *args);
    N(D_80242058_941608) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_802411AC_94075C);
/*
ApiStatus N(func_802411AC_94075C)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241248_9407F8);
/*
ApiStatus N(func_80241248_9407F8)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241560_940B10);
/*
ApiStatus N(func_80241560_940B10)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_802415A4_940B54);
/*
ApiStatus N(func_802415A4_940B54)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

#include "world/common/SomeMatrixOperations.inc.c"
