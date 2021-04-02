#include "sam_02.h"

#define UNK_ALPHA_FUNC_NPC 8

#include "world/common/Call800E9894.inc.c"

#include "world/common/Call800E98C4SyncStatusMenu.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80240878_D05FA8);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_802408F4_D06024);

#include "world/common/AwaitScriptComplete.inc.c"

#include "world/common/PartnerToggleAbilityScript.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_802409F0_D06120);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80240A44_D06174);

#include "world/common/GetPartnerCall800EB168.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80240B24_D06254);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80240B2C_D0625C);
/*
ApiStatus N(func_80240B2C_D0625C)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &D_80241C68_BE09F8;
    s32 i;
    s32* test;

    if (*ptr == NULL) {
        i = heap_malloc(16 * sizeof(s32));
        *ptr = i;
        for (i = 0, test = *ptr; i < 16; i++) {
            *test++ = script->varTable[i];
        }
    } else {
        for (i = 0, test = *ptr; i < 16; i++) {
            script->varTable[i] = *test++;
        }
        ptr = &D_80241C68_BE09F8;
        heap_free(*ptr);
        *ptr = NULL;
    }
    return 2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80240C68_D06398);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80240E8C_D065BC);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80240EF8_D06628);

#include "world/common/UnkAlphaFunc.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_802410A4_D067D4);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", begin_battle_D06948);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_8024129C_D069CC);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_802414B4_D06BE4);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241568_D06C98);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_8024159C_D06CCC);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_8024161C_D06D4C);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241634_D06D64);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241650_D06D80);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241B24_D07254);

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241B90_D072C0);
