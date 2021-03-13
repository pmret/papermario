#include "common.h"

INCLUDE_ASM(s32, "battle/item/fire_flower_716C60", func_802A1000_716C60);

extern s32 D_802A1D70;

//INCLUDE_ASM(s32, "battle/item/fire_flower_716C60", func_802A11D4_716E34);
ApiStatus func_802A11D4_716E34(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battlestatus = &gBattleStatus;
    s32 sellValue = gItemTable[battlestatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(battlestatus->playerActor, Ability_REFUND) && sellValue > 0) {
        free_icon(D_802A1D70);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/item/fire_flower_716C60", func_802A123C_716E9C);

#define NAMESPACE battle_item_fire_flower
#include "common/FadeBackgroundToBlack.inc.c"

INCLUDE_ASM(s32, "battle/item/fire_flower_716C60", func_802A1378_716FD8);
