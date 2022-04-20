#include "dead.h"
#include "common.h"

// Copy of flo_00 (C9DF60)

#define NAMESPACE EB8E90

#include "world/common/enemy/Dead_UnkAI_1.inc.c"

ApiStatus N(PostChapter6StatUpdate)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(6);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
