#include "mac_00.h"

#define UNK_ALPHA_FUNC_NPC 6

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240630_7EB340);
/*
ApiStatus N(func_80240630_7EB340)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80245DC0_7F0AD0) == NULL) {
        N(D_80245DC0_7F0AD0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80245DC0_7F0AD0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80245DC0_7F0AD0)[i];
        }
        heap_free(N(D_80245DC0_7F0AD0));
        N(D_80245DC0_7F0AD0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_8024076C_7EB47C);
/*
ApiStatus N(func_8024076C_7EB47C)(Evt *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemyID;
    u16 phi_s0 = get_variable(script, SI_SAVE_FLAG(1768));
    u16 phi_s7 = get_variable(script, SI_SAVE_FLAG(1769));
    u16 temp_s6 = get_variable(script, SI_SAVE_VAR(350));
    u16 phi_s5 = get_variable(script, SI_SAVE_VAR(351));
    s32 var;
    s32 i;

    s32 test2;
    u16 temp_s3 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 sp_10 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 temp_s2 = (enemy->varTable[0] & 0xFF00) >> 8;
    u16 sp_1e = (enemy->varTable[0] & 0xFF) >> 0;
    s32 temp_v0;
    s32 temp_s0_2;

    if (temp_s3 != temp_s6) {
        phi_s7 = 0;
        phi_s0 = 0;
    }

    if (phi_s0 == 0) {
        if (rand_int(100) < 30) {
            phi_s5 = rand_int(temp_s2 - 1);
            temp_s6 = temp_s3;
            set_variable(script, SI_SAVE_VAR(350), temp_s6);
            set_variable(script, SI_SAVE_VAR(351), phi_s5);
            phi_s0 = 1;
        }
    }

    set_variable(script, SI_SAVE_FLAG(1768), phi_s0);
    set_variable(script, SI_SAVE_FLAG(1769), phi_s7);
    temp_s0_2 = get_variable(NULL, SI_SAVE_VAR(352));
    temp_v0 = get_variable(NULL, SI_STORY_PROGRESS);

    for (i = 0; i < 8; i++) {
        if (temp_v0 < (*(N(quizRequirements) + i)).unk_00) {
            break;
        }
    }

    temp_v0 = temp_s0_2 < (*(N(quizRequirements) + i)).unk_04;
    test2 = var = temp_v0;

    if ((((sp_10 == temp_s6) && (sp_1e == phi_s5) && (phi_s7 == 0) && test2)) ||
        ((gGameStatusPtr->unk_75 != 0) && var)) {
        script->varTable[0] = 1;
    } else {
        kill_enemy(enemy);
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
*/

#include "world/common/UnkFunc31.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240D1C_7EBA2C);
/*
ApiStatus N(func_80240D1C_7EBA2C)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240DA0_7EBAB0);
/*
ApiStatus N(func_80240DA0_7EBAB0)(Evt *script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        Effect** effect = &D_8024DFE0;

        *effect = playFX_4E(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)));
        D_8024DFE4 = playFX_54(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)));
        D_8024DFE8 = playFX_80(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)), 1.0f, 0);

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

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80240FB8_7EBCC8);
/*
ApiStatus N(func_80240FB8_7EBCC8)(Evt *script, s32 isInitialCall) {
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
        free_generic_entity(D_8024DFC0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_8024106C_7EBD7C);
/*
ApiStatus N(func_8024106C_7EBD7C)(Evt *script, s32 isInitialCall) {
    D_8024DFE0->unk_0C->unk_34 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802410A0_7EBDB0);
/*
ApiStatus N(func_802410A0_7EBDB0)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241120_7EBE30);
/*
ApiStatus N(func_80241120_7EBE30)(Evt *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 0;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241138_7EBE48);
/*
ApiStatus N(func_80241138_7EBE48)(Evt *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241154_7EBE64);
/*
ApiStatus N(func_80241154_7EBE64)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241628_7EC338);
/*
void N(func_80241628_7EC338)(void) {
    s32 var = get_variable(NULL, D_8024DFD8);

    if (var == 1) {
        playFX_50(0, 0, 0, 0);
    } else if (var == 2) {
        playFX_50(1, 0, 0, 0);
    }
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241694_7EC3A4);
/*
ApiStatus N(func_80241694_7EC3A4)(Evt *script, s32 isInitialCall) {
    D_8024DFC0 = create_generic_entity_frontUI(NULL, N(func_80242468_95D668));
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802418F0_7EC600);
/*
ApiStatus N(func_802418F0_7EC600)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802483E8_7F30F8) = FALSE;
    }

    if (N(D_802483E8_7F30F8)) {
        N(D_802483E8_7F30F8) = FALSE;
        set_variable(script, *args, N(D_802483EC_7F30FC));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241944_7EC654);
/*
ApiStatus N(func_80241944_7EC654)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802483EC_7F30FC) = get_variable(script, *args);
    N(D_802483E8_7F30F8) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_8024197C_7EC68C);
/*
ApiStatus N(func_8024197C_7EC68C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241A18_7EC728);
/*
ApiStatus N(func_80241A18_7EC728)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241D30_7ECA40);
/*
ApiStatus N(func_80241D30_7ECA40)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241D74_7ECA84);
/*
ApiStatus N(func_80241D74_7ECA84)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241DA0_7ECAB0);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241E04_7ECB14);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241E80_7ECB90);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241FF0_7ECD00);

#include "world/common/UnkPositionFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80242178_7ECE88);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802421D0_7ECEE0);

ApiStatus func_80242224_7ECF34(Evt* script, s32 isInitialCall) {
    gPlayerData.curHP = 1;
    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80242250_7ECF60);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_8024228C_7ECF9C);
