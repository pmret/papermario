#include "common.h"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240460);

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240578);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024058C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024059C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802407C0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024080C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024082C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024088C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802409D8);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240B4C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240BD0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240DE8);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240E9C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240ED0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F50_843B20);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F68);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F84);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F9C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240FCC);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241040);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802410E0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024127C_843E4C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802412E0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241370);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241458);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802414C4_844094);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241720_8442F0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241774);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802417AC);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241848);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802418AC);

static ApiStatus PostChapter4StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = PLAYER_DATA;

    set_max_SP(4);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241980);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419AC);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419D0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419E4);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241A64);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241B90);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241BB8);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C20);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C40);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C60);
