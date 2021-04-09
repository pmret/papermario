#include "mac_03.h"

#define UNK_ALPHA_FUNC_NPC 23

#include "common/UnkFloatFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_802404B0_831CB0);
/*
ApiStatus N(func_802404B0_831CB0)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_802405EC_831DEC);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80240810_832010);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

#include "world/common/UnkFunc28.inc.c"

#include "world/common/UnkAlphaFunc.inc.c"

#include "world/common/UnkFunc29.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80240B9C_83239C);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80240C20_832420);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80240E38_832638);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80240EEC_8326EC);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80240F20_832720);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80240FA0_8327A0);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80240FB8_8327B8);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80240FD4_8327D4);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_802414A8_832CA8);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241514_832D14);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241770_832F70);
/*
ApiStatus N(func_80241770_832F70)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_802417C4_832FC4);
/*
ApiStatus N(func_802417C4_832FC4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_802417FC_832FFC);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241B14_833314);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241B58_833358);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241B84_833384);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241BD8_8333D8);
