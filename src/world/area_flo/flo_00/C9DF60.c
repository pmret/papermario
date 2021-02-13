#include "flo_00.h"

INCLUDE_ASM(s32, "world/area_flo/flo_00/C9DF60", func_80240040_C9DF60);

INCLUDE_ASM(s32, "world/area_flo/flo_00/C9DF60", func_80240198_C9E0B8);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_00/C9DF60", func_80240500_C9E420);

INCLUDE_ASM(s32, "world/area_flo/flo_00/C9DF60", func_802406BC_C9E5DC);

#include "world/common/NpcJumpFunc2.inc.c"

# include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_00/C9DF60", func_8024098C_C9E8AC);

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_00/C9DF60", func_80240B14_C9EA34);

INCLUDE_ASM(s32, "world/area_flo/flo_00/C9DF60", func_80240BD4_C9EAF4);

ApiStatus PostChapter6StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = PLAYER_DATA;

    set_max_SP(6);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
