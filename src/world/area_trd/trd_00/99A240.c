#include "trd_00.h"

ApiStatus PostChapter1StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(1);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

#include "world/common/SyncStatusMenu.inc.c"
