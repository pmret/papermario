#include "sbk_02.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_8024091C_92ABCC);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240970_92AC20);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_802409A8_92AC58);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240A44_92ACF4);

#include "world/common/GetItemName.inc.c"

ApiStatus PostChapter2StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(2);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240B98_92AE48);

ApiStatus GetItemCount(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}
