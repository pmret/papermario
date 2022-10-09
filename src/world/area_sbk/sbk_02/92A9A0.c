#include "sbk_02.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

// needs data
#ifdef NON_MATCHING
API_CALLABLE(func_8024091C_92ABCC) {
    Bytecode* args = script->ptrReadPos;
    if (isInitialCall) {
        D_8024404C_92E2FC = FALSE;
    }
    if (D_8024404C_92E2FC) {
        D_8024404C_92E2FC = FALSE;
        evt_set_variable(script, *args++, D_80244050_92E300);
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
#else
INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_8024091C_92ABCC);
#endif

static s32 sbk_02_D_80245630[91];
extern s32 D_8024404C_92E2FC;
extern s32 D_80244050_92E300;

API_CALLABLE(func_80240970_92AC20) {
    Bytecode* args = script->ptrReadPos;

    D_80244050_92E300 = evt_get_variable(script, *args++);
    D_8024404C_92E2FC = TRUE;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802409A8_92AC58) {
    Bytecode* args = script->ptrReadPos;
    s32* buf = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (buf != NULL) {
        for (i = 0; *buf != NULL; i++) {
            sbk_02_D_80245630[i] = *buf++;
        }
        sbk_02_D_80245630[i] = 0;
    } else {
        for (i = 0; i <= 90; i++) {
            sbk_02_D_80245630[i] = i + 0x80;
            sbk_02_D_80245630[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

API_CALLABLE(PostChapter2StatUpdate) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(2);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CheckTradeEventTime)) {
    script->varTable[0] = (s32)((gPlayerData.frameCounter - gPlayerData.tradeEventStartTime) / 3600) < script->varTable[0];
    return ApiStatus_DONE2;
}

API_CALLABLE(GetItemCount) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}
