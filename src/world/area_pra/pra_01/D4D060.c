#include "pra_01.h"

#include "world/common/reflection.inc.c"

#include "common/UnkFogFunc.inc.c"

ApiStatus func_80240F60_D4DFA0(Evt* script, s32 isInitialCall) {
    gOverrideFlags &= ~0x80;
    return ApiStatus_DONE2;
}

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_802411AC_D4E1EC);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80241200_D4E240);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_80241238_D4E278);

INCLUDE_ASM(s32, "world/area_pra/pra_01/D4D060", func_802412D4_D4E314);

ApiStatus PostChapter7StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(7);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
