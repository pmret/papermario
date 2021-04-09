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
/*
ApiStatus N(func_802409EC_969BAC)(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    u16 quizzesAnswered = gPlayerData.quizzesAnswered;

    if (quizzesAnswered < 0x3E7) {
        playerData->quizzesAnswered++;
    }

    if (script->varTable[0] == N(quizAnswers)[get_variable(NULL, SI_SAVE_VAR(352))]) {
        script->varTable[0] = 1;
        playerData->quizzesCorrect++;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240A70_969C30);
/*
ApiStatus N(func_80240A70_969C30)(ScriptInstance *script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        Effect** effect = &D_8024DFE0;

        *effect = func_800715D0(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)));
        D_8024DFE4 = func_80071810(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)));
        D_8024DFE8 = func_80072890(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)), 1.0f, 0);

        effectPtr = (*effect)->unk_0C;
        effectPtr->unk_18 = 0;
        effectPtr->unk_20 = 0;
        effectPtr->unk_24.s = 0;
        effectPtr->unk_28 = 0;
        effectPtr->unk_1C = 0;
    }

    effectPtr = D_8024DFE0->unk_0C;

    effectPtr->unk_20 += 10;
    effectPtr->unk_28 += 10;
    effectPtr->unk_24.s += 10;
    effectPtr->unk_18 += 10;
    effectPtr->unk_1C += 10;
    if (effectPtr->unk_18 >= 255) {
        effectPtr->unk_18 = 255;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240C88_969E48);
/*
ApiStatus N(func_80240C88_969E48)(ScriptInstance *script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        D_8024DFE4->flags |= 0x10;
        D_8024DFE8->flags |= 0x10;
    }

    effectPtr = D_8024DFE0->unk_0C;
    effectPtr->unk_18 -= 10;
    effectPtr->unk_20 -= 10;
    effectPtr->unk_24.s -= 10;
    effectPtr->unk_28 -= 10;
    effectPtr->unk_1C -= 10;

    if (effectPtr->unk_18 <= 0) {
        effectPtr->unk_18 = 0;
        remove_effect(D_8024DFE0, effectPtr);
        func_801235C0(D_8024DFC0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240D3C_969EFC);
/*
ApiStatus N(func_80240D3C_969EFC)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE0->unk_0C->unk_34 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240D70_969F30);
/*
ApiStatus N(func_80240D70_969F30)(ScriptInstance *script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
    EffectInstanceDataThing* effectPtr = D_8024DFE0->unk_0C;

    switch (var) {
        case 0:
            effectPtr->unk_38 = 0xC0;
            break;
        case 1:
            effectPtr->unk_38 = 0x80;
            break;
        case 2:
            effectPtr->unk_38 = 0x40;
            break;
        default:
            effectPtr->unk_38 = 0;
            break;
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240DF0_969FB0);
/*
ApiStatus N(func_80240DF0_969FB0)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 0;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240E08_969FC8);
/*
ApiStatus N(func_80240E08_969FC8)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80240E24_969FE4);
/*
ApiStatus N(func_80240E24_969FE4)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 2;
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_802412F8_96A4B8);
/*
void N(func_802412F8_96A4B8)(void) {
    s32 var = get_variable(NULL, D_8024DFD8);

    if (var == 1) {
        func_80071690(0, 0, 0, 0);
    } else if (var == 2) {
        func_80071690(1, 0, 0, 0);
    }
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80241364_96A524);
/*
ApiStatus N(func_80241364_96A524)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFC0 = bind_dynamic_entity_7(NULL, N(func_80242468_95D668));
    return ApiStatus_DONE2;
}
*/

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
/*
ApiStatus N(func_802439FC_96CBBC)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_dro/dro_02/9694C0", func_80243A40_96CC00);
/*
ApiStatus N(func_80243A40_96CC00)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/
