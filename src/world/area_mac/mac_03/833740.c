#include "mac_03.h"

typedef struct LilOinkReward {
    /* 0x00 */ s32 itemID;
    /* 0x04 */ s32 quantity;
    /* 0x08 */ s32 chance;
} LilOinkReward; // size = 0x0C

extern LilOinkReward D_8024F800_841000[10];

#include "world/common/GetFloorCollider.inc.c"

#include "world/common/GetPlayerCoins.inc.c"

ApiStatus func_80241F80_833780(Evt* script, s32 isInitialCall) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_03/833740", func_80241FA0_8337A0);

INCLUDE_ASM(s32, "world/area_mac/mac_03/833740", func_8024206C_83386C);

INCLUDE_ASM(s32, "world/area_mac/mac_03/833740", func_802421E8_8339E8);

INCLUDE_ASM(s32, "world/area_mac/mac_03/833740", func_80242384_833B84);

INCLUDE_ASM(s32, "world/area_mac/mac_03/833740", func_802424A0_833CA0);

INCLUDE_ASM(s32, "world/area_mac/mac_03/833740", func_802425A8_833DA8);

INCLUDE_ASM(s32, "world/area_mac/mac_03/833740", func_80242608_833E08);

INCLUDE_ASM(s32, "world/area_mac/mac_03/833740", func_80242694_833E94);

ApiStatus func_802427D0_833FD0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, GB_MAC03_LilOink_00);
    s32 itemID = *args++;
    s32 quantity = *args++;
    s32 chance = *args++;
    LilOinkReward* reward = &D_8024F800_841000[index];

    evt_set_variable(script, itemID, reward->itemID);
    evt_set_variable(script, quantity, reward->quantity);
    evt_set_variable(script, chance, reward->chance);
    return ApiStatus_DONE2;
}

