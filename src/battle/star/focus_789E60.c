#include "common.h"

#define NAMESPACE battle_star_focus

INCLUDE_ASM(s32, "battle/star/focus_789E60", func_802A1000_789E60);

INCLUDE_ASM(s32, "battle/star/focus_789E60", func_802A10AC_789F0C);

INCLUDE_ASM(s32, "battle/star/focus_789E60", func_802A116C_789FCC);

INCLUDE_ASM(s32, "battle/star/focus_789E60", func_802A1218_78A078);

#include "common/FadeBackgroundToBlack.inc.c"

INCLUDE_ASM(s32, "battle/star/focus_789E60", func_802A137C_78A1DC);

#include "common/UnkBackgroundFunc.inc.c"

INCLUDE_ASM(s32, "battle/star/focus_789E60", func_802A1494_78A2F4);

#include "common/SetNpcCollision32.inc.c"

INCLUDE_ASM(s32, "battle/star/focus_789E60", func_802A1518_78A378);

ApiStatus func_802A15B0_78A410(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;

    script->varTable[0] = 0;

    if (playerData->specialBarsFilled >= playerData->maxStarPower * 256) {
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }

    add_SP(128);

    if (playerData2->specialBarsFilled == playerData2->maxStarPower * 256) {
        script->varTable[0] = 2;
    }

    return ApiStatus_DONE2;
}
