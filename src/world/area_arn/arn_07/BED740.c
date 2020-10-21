#include "common.h"

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80240950_BED740);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80240B00_BED8F0);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80241128_BEDF18);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_802411E8_BEDFD8);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_8024152C);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_802415A4_BEE394);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80241610_BEE400);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80241744_BEE534);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_802417A8_BEE598);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80241B38);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80241C5C_BEEA4C);

static ApiStatus PostChapter3StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = PLAYER_DATA;

    set_max_SP(3);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
