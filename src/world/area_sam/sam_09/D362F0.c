#include "sam_09.h"

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240000_D362F0);
/*
ApiStatus N(func_80240000_D362F0)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &N(D_80241C68_BE09F8);
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
        ptr = &N(D_80241C68_BE09F8);
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240118_D36408);

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240158_D36448);

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240264_D36554);

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_802403A0_D36690);
