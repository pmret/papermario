#include "sam_11.h"

#define UNK_ALPHA_FUNC_NPC 17

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802407D0_D3ADA0);
/*
ApiStatus N(func_802407D0_D3ADA0)(ScriptInstance* script, s32 isInitialCall) {
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
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#define NAMESPACE dup_sam_11
#include "world/common/Set80151310.inc.c"
#define NAMESPACE sam_11

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_8024090C_D3AEDC);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80240B30_D3B100);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80240B9C_D3B16C);

#include "world/common/UnkAlphaFunc.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80240D48_D3B318);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80240EBC_D3B48C);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80240F40_D3B510);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241158_D3B728);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_8024120C_D3B7DC);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241240_D3B810);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802412C0_D3B890);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802412D8_D3B8A8);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802412F4_D3B8C4);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802417C8_D3BD98);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241834_D3BE04);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241864_D3BE34);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802418B4_D3BE84);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241A6C_D3C03C);

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241DAC_D3C37C);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241FB0_D3C580);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241FE8_D3C5B8);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80242074_D3C644);