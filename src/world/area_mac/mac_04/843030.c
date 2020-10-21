#include "common.h"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240460_843030);

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240578_843148);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024058C_84315C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024059C_84316C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802407C0_843390);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024080C_8433DC);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024082C_8433FC);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024088C_84345C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802409D8_8435A8);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240B4C_84371C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240BD0_8437A0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240DE8_8439B8);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240E9C_843A6C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240ED0_843AA0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F50_843B20);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F68_843B38);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F84_843B54);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F9C_843B6C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240FCC_843B9C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241040_843C10);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802410E0_843CB0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024127C_843E4C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802412E0_843EB0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241370_843F40);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241458_844028);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802414C4_844094);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241720_8442F0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241774_844344);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802417AC_84437C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241848_844418);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802418AC_84447C);

static ApiStatus PostChapter4StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = PLAYER_DATA;

    set_max_SP(4);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241980_844550);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419AC_84457C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419D0_8445A0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419E4_8445B4);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241A64_844634);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241B90_844760);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241BB8_844788);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C20_8447F0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C40_844810);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C60_844830);
