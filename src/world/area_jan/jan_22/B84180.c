#include "jan_22.h"

static char* N(exit_str_0) = "jan_03";
static char* N(exit_str_1) = "jan_16";
static char* N(exit_str_2) = "kzn_01";
static char* N(exit_str_3) = "";

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/SetCamera0Flag1000.inc.c"

#include "world/common/todo/UnsetCamera0Flag1000.inc.c"

ApiStatus PostChapter5StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(5);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
