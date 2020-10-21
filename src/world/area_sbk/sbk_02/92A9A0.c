#include "common.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_8024074C_92A9FC);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_8024091C);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240970);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_802409A8);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240A44);

#include "world/common/GetItemName.inc.c"

static ApiStatus PostChapter2StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = PLAYER_DATA;

    set_max_SP(2);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240B98_92AE48);

static ApiStatus GetItemCount(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}
