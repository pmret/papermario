#include "hos_06.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80240F7C_A3A45C);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80240FD0_A3A4B0);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241008_A3A4E8);

#define NAMESPACE dup_hos_06
#include "world/common/StashVars.inc.c"
#define NAMESPACE hos_06

#include "world/common/GetItemName.inc.c"

s32 func_802411BC_A3A69C(s32 badgeID) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPlayerData.badges); i++) {
        if (gPlayerData.badges[i] == badgeID) {
            return TRUE;
        }
    }
    return FALSE;
}

ApiStatus func_802411F0_A3A6D0(Evt* script, s32 isInitialCall) {
    u32 i;

    for (i = 0; i < 79; i++) {
        evt_set_variable(NULL, AreaFlag(3) + i, 0);
    }
    for (i = 0; i < 16; i++) {
        evt_set_variable(NULL, AreaFlag(100) + i, 0);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_8024126C_A3A74C);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802414E4_A3A9C4);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241668_A3AB48);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802417EC_A3ACCC);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241860_A3AD40);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802418A4_A3AD84);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802418E8_A3ADC8);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241A58_A3AF38);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241B74_A3B054);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241CCC_A3B1AC);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241F98_A3B478);
