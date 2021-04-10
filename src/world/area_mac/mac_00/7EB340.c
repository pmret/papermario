#include "mac_00.h"

#define UNK_ALPHA_FUNC_NPC 6

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240630_7EB340);
/*
ApiStatus N(func_80240630_7EB340)(ScriptInstance* script, s32 isInitialCall) {
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

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_8024076C_7EB47C);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240990_7EB6A0);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802409FC_7EB70C);

#include "world/common/UnkAlphaFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240BA8_7EB8B8);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240D1C_7EBA2C);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240DA0_7EBAB0);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240FB8_7EBCC8);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_8024106C_7EBD7C);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802410A0_7EBDB0);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241120_7EBE30);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241138_7EBE48);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241154_7EBE64);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241628_7EC338);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241694_7EC3A4);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802418F0_7EC600);
/*
ApiStatus N(func_802418F0_7EC600)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241944_7EC654);
/*
ApiStatus N(func_80241944_7EC654)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_8024197C_7EC68C);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241A18_7EC728);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241D30_7ECA40);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241D74_7ECA84);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241DA0_7ECAB0);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241E04_7ECB14);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241E80_7ECB90);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241FF0_7ECD00);

#include "world/common/UnkPositionFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80242178_7ECE88);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802421D0_7ECEE0);

ApiStatus func_80242224_7ECF34(ScriptInstance* script, s32 isInitialCall) {
    gPlayerData.curHP = 1;
    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80242250_7ECF60);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_8024228C_7ECF9C);
