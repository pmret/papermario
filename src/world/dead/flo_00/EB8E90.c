#include "flo_00.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

ApiStatus N(PostChapter6StatUpdate)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(6);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
