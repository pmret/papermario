#include "dro_02.h"

#define UNK_ALPHA_FUNC_NPC 10

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240300_9694C0);
/*
ApiStatus N(func_80240300_9694C0)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_8024043C_9695FC);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240660_969820);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

#include "world/common/UnkFunc28.inc.c"

#include "world/common/UnkAlphaFunc.inc.c"

#include "world/common/UnkFunc29.inc.c"

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802409EC_969BAC);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240A70_969C30);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240C88_969E48);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240D3C_969EFC);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240D70_969F30);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240DF0_969FB0);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240E08_969FC8);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240E24_969FE4);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802412F8_96A4B8);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80241364_96A524);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80241394_96A554);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802414C0_96A680);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802415CC_96A78C);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802416FC_96A8BC);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80241874_96AA34);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_8024190C_96AACC);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80242214_96B3D4);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_8024240C_96B5CC);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80242EAC_96C06C);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_8024303C_96C1FC);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80243068_96C228);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802432C0_96C480);
/*
ApiStatus N(func_802432C0_96C480)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80243314_96C4D4);
/*
ApiStatus N(func_80243314_96C4D4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_8024334C_96C50C);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802433E8_96C5A8);

#include "world/common/Call800E9894.inc.c"

#include "world/common/Call800E98C4SyncStatusMenu.inc.c"

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802434CC_96C68C);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80243548_96C708);

#include "world/common/AwaitScriptComplete.inc.c"

#include "world/common/PartnerToggleAbilityScript.inc.c"

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80243644_96C804);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80243698_96C858);

#include "world/common/GetPartnerCall800EB168.inc.c"

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80243778_96C938);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802439FC_96CBBC);

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80243A40_96CC00);
