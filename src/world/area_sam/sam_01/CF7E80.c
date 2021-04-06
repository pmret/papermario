#include "sam_01.h"

#define UNK_ALPHA_FUNC_NPC 14

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024053C_CF80AC);
/*
ApiStatus N(func_8024053C_CF80AC)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
    }

    ptr = &D_80241CCC_BE0A5C;
    if (*ptr != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
        set_variable(script, *args, D_80241CD0_BE0A60);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240590_CF8100);
/*
ApiStatus N(func_80240590_CF8100)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_802405C8_CF8138);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240664_CF81D4);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240700_CF8270);
/*
ApiStatus N(func_80240700_CF8270)(ScriptInstance* script, s32 isInitialCall) {
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

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024083C_CF83AC);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240A60_CF85D0);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240ACC_CF863C);

#include "world/common/UnkAlphaFunc.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240C78_CF87E8);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240DEC_CF895C);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240E70_CF89E0);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241088_CF8BF8);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024113C_CF8CAC);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241170_CF8CE0);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_802411F0_CF8D60);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241208_CF8D78);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241224_CF8D94);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_802416F8_CF9268);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241764_CF92D4);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241A10_CF9580);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241A54_CF95C4);

#include "common/GetItemEntityPosition.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241B20_CF9690);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241C90_CF9800);
/*
ApiStatus N(func_80241C90_CF9800)(ScriptInstance* script, s32 isInitialCall) {
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

#define NAMESPACE dup_sam_01
#include "world/common/GetItemName.inc.c"
#define NAMESPACE sam_01

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"