#include "arn_07.h"

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80240950_BED740);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80240B00_BED8F0);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_802411E8_BEDFD8);

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_802415A4_BEE394);

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_802417A8_BEE598);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80241B38_BEE928);

INCLUDE_ASM(s32, "world/area_arn/arn_07/BED740", func_80241C5C_BEEA4C);

ApiStatus PostChapter3StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(3);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
