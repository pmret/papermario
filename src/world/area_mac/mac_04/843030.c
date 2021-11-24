#include "mac_04.h"

#define UNK_ALPHA_FUNC_NPC 20

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240460_843030);

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

#include "world/common/UnkQuizFunc.inc.c"

#include "world/common/UnkFunc31.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240B4C_84371C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240BD0_8437A0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240DE8_8439B8);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240E9C_843A6C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240ED0_843AA0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F50_843B20);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F68_843B38);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F84_843B54);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241458_844028);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802414C4_844094);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241720_8442F0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241774_844344);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802417AC_84437C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241848_844418);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802418AC_84447C);

ApiStatus PostChapter4StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(4);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

#include "world/common/GetFloorCollider.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419AC_84457C);

#include "world/common/GetPlayerCoins.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419E4_8445B4);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241A64_844634);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241B90_844760);

ApiStatus N(SetNpcShadowScale)(Evt* script, s32 isInitialCall) {
    s32 npcID;
    f32 newShadowScale;

    Bytecode* args = script->ptrReadPos;
    npcID = evt_get_variable(script, *args++);
    newShadowScale = evt_get_float_variable(script, *args++);

    resolve_npc(script, npcID)->shadowScale = newShadowScale;
    return ApiStatus_DONE2;
}

#include "world/common/Call800E9894.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C40_844810);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C60_844830);
