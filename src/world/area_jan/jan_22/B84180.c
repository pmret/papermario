#include "jan_22.h"

static char* N(exit_str_0) = "jan_03";
static char* N(exit_str_1) = "jan_16";
static char* N(exit_str_2) = "kzn_01";
static char* N(exit_str_3) = "";

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_22/B84180", func_80240B94_B84D14);

INCLUDE_ASM(s32, "world/area_jan/jan_22/B84180", func_80240E90_B85010);

#include "world/common/GetItemName.inc.c"

#include "world/common/SetCamera0Flag1000.inc.c"

#include "world/common/UnsetCamera0Flag1000.inc.c"

ApiStatus PostChapter5StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(5);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
