#include "common.h"

#define NAMESPACE battle_star_peach_dash

#include "common/UnkStarFuncs.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnkBackgroundFunc2.inc.c"

#include "common/UnkBackgroundFunc.inc.c"

INCLUDE_ASM(s32, "battle/star/peach_dash/79D8A0", func_802A1494_79DD34);

#include "common/SetNpcCollision32.inc.c"

ApiStatus func_802A1518_79DDB8(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;

    if (is_ability_active(ABILITY_DEEP_FOCUS)) {
        playerData->specialBarsFilled += 128;
    }
    if (is_ability_active(ABILITY_SUPER_FOCUS)) {
        playerData->specialBarsFilled += 256;
    }

    playerData->specialBarsFilled += 128;

    if (playerData2->specialBarsFilled >= playerData2->maxStarPower * 256) {
        playerData2->specialBarsFilled = playerData2->maxStarPower * 256;
    }

    return ApiStatus_DONE2;
}
