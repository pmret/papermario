#include "mac_04.h"

#define UNK_ALPHA_FUNC_NPC 20

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240460_843030);
/*
ApiStatus N(func_80240460_843030)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_8024059C_84316C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802407C0_843390);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

#include "world/common/UnkFunc28.inc.c"

#include "world/common/UnkAlphaFunc.inc.c"

#include "world/common/UnkFunc29.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240B4C_84371C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240BD0_8437A0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240DE8_8439B8);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240E9C_843A6C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240ED0_843AA0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F50_843B20);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F68_843B38);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80240F84_843B54);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241458_844028);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802414C4_844094);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241720_8442F0);
/*
ApiStatus N(func_80241720_8442F0)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241774_844344);
/*
ApiStatus N(func_80241774_844344)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802417AC_84437C);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241848_844418);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802418AC_84447C);

ApiStatus PostChapter4StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(4);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241980_844550);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419AC_84457C);

#include "world/common/GetPlayerCoins.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419E4_8445B4);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241A64_844634);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241B90_844760);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241BB8_844788);

#include "world/common/Call800E9894.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C40_844810);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C60_844830);
