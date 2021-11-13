#include "sbk_02.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_8024091C_92ABCC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024404C_92E2FC) = FALSE;
    }

    if (N(D_8024404C_92E2FC)) {
        N(D_8024404C_92E2FC) = FALSE;
        evt_set_variable(script, *args, N(D_80244050_92E300));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_8024091C_92ABCC);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80240970_92AC20)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80244050_92E300) = evt_get_variable(script, *args);
    N(D_8024404C_92E2FC) = TRUE;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240970_92AC20);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_802409A8_92AC58)(Evt* script, s32 isInitialCall) {
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
INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_802409A8_92AC58);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80240A44_92ACF4)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802441D8_92E488) == NULL) {
        N(D_802441D8_92E488) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802441D8_92E488)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802441D8_92E488)[i];
        }
        heap_free(N(D_802441D8_92E488));
        N(D_802441D8_92E488) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240A44_92ACF4);
#endif

#include "world/common/GetItemName.inc.c"

ApiStatus PostChapter2StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(2);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240B98_92AE48);

ApiStatus GetItemCount(Evt* script, s32 isInitialCall) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}
