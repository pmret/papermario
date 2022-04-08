#include "mgm_00.h"

static char* N(exit_str_0) = "mac_03";
static char* N(exit_str_1) = "mgm_01";
static char* N(exit_str_2) = "mgm_02";
static char* N(exit_str_3) = "";

#include "world/common/atomic/Pipe.inc.c"

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

#include "world/common/UnkNpcAIMainFunc.inc.c"

/* N(GetAvailableGamesCount) */
ApiStatus func_80241170_E0F910(Evt* script, s32 isInitialCall) {
    s32 numGames = 0;

    if (find_item(ITEM_GOLD_CREDIT) >= 0) {
        numGames = 2;
    } else if (find_item(ITEM_SILVER_CREDIT) >= 0) {
        numGames = 1;
    }

    evt_set_variable(script, LW(5), numGames);
    return ApiStatus_DONE2;
}
