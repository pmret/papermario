
#include "sprite/npc/Buzzar.h"
#include "battle/action_cmd/break_free.h"
#include "battle/action_cmd/whirlwind.h"
#include "sprite/player.h"

API_CALLABLE(b_area_iwa_whacka_IsHitEightTimes) {
    script->varTable[0] = 0;
    if (evt_get_variable(NULL, GB_IWA00_Whacka_HitCount) >= 8) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
