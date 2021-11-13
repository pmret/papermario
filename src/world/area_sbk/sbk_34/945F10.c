#include "sbk_34.h"

#if 0 // NON_MATCHING
ApiStatus N(func_80240040_945F10)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80240D9C_946C6C) == NULL) {
        N(D_80240D9C_946C6C) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80240D9C_946C6C)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80240D9C_946C6C)[i];
        }
        heap_free(N(D_80240D9C_946C6C));
        N(D_80240D9C_946C6C) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_34/945F10", func_80240040_945F10);
#endif

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_80240384_946254)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80240E00_946CD0) = FALSE;
    }

    if (N(D_80240E00_946CD0)) {
        N(D_80240E00_946CD0) = FALSE;
        evt_set_variable(script, *args, N(D_80240E04_946CD4));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_34/945F10", func_80240384_946254);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_802403D8_9462A8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80240E04_946CD4) = evt_get_variable(script, *args);
    N(D_80240E00_946CD0) = TRUE;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_34/945F10", func_802403D8_9462A8);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80240410_9462E0)(Evt* script, s32 isInitialCall) {
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
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_34/945F10", func_80240410_9462E0);
#endif

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_80240728_9465F8)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_34/945F10", func_80240728_9465F8);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_8024076C_94663C)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_34/945F10", func_8024076C_94663C);
#endif
