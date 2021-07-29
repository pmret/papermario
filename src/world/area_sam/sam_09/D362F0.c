#include "sam_09.h"

static char* N(exit_str_0) = "sam_08";
static char* N(exit_str_1) = "sam_10";

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240000_D362F0);
/*
ApiStatus N(func_80240000_D362F0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802406C0_D369B0) == NULL) {
        N(D_802406C0_D369B0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802406C0_D369B0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802406C0_D369B0)[i];
        }
        heap_free(N(D_802406C0_D369B0));
        N(D_802406C0_D369B0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240118_D36408);

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240158_D36448);

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240264_D36554);

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_802403A0_D36690);
