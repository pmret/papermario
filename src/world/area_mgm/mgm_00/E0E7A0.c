#include "mgm_00.h"

static char* N(exit_str_0) = "mac_03";
static char* N(exit_str_1) = "mgm_01";
static char* N(exit_str_2) = "mgm_02";
static char* N(exit_str_3) = "";

#include "world/common/atomic/Pipe.inc.c"

#include "world/common/enemy/PatrolAI_NoAttack.inc.c"

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
