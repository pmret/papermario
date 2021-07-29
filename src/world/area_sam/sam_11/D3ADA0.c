#include "sam_11.h"

#define UNK_ALPHA_FUNC_NPC 17

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802407D0_D3ADA0);
/*
ApiStatus N(func_802407D0_D3ADA0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80244F78_D3F548) == NULL) {
        N(D_80244F78_D3F548) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80244F78_D3F548)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80244F78_D3F548)[i];
        }
        heap_free(N(D_80244F78_D3F548));
        N(D_80244F78_D3F548) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#define NAMESPACE dup_sam_11
#include "world/common/Set80151310.inc.c"
#define NAMESPACE sam_11

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_8024090C_D3AEDC);
/*
ApiStatus N(func_8024090C_D3AEDC)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80240EBC_D3B48C);
/*
ApiStatus N(func_80240EBC_D3B48C)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80240F40_D3B510);
/*
ApiStatus N(func_80240F40_D3B510)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241158_D3B728);
/*
ApiStatus N(func_80241158_D3B728)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_8024120C_D3B7DC);
/*
ApiStatus N(func_8024120C_D3B7DC)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE0->unk_0C->unk_34 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241240_D3B810);
/*
ApiStatus N(func_80241240_D3B810)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802412C0_D3B890);
/*
ApiStatus N(func_802412C0_D3B890)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 0;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802412D8_D3B8A8);
/*
ApiStatus N(func_802412D8_D3B8A8)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802412F4_D3B8C4);
/*
ApiStatus N(func_802412F4_D3B8C4)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802417C8_D3BD98);
/*
void N(func_802417C8_D3BD98)(void) {
    s32 var = get_variable(NULL, D_8024DFD8);

    if (var == 1) {
        playFX_50(0, 0, 0, 0);
    } else if (var == 2) {
        playFX_50(1, 0, 0, 0);
    }
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241834_D3BE04);
/*
ApiStatus N(func_80241834_D3BE04)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFC0 = create_generic_entity_frontUI(NULL, N(func_80242468_95D668));
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241864_D3BE34);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802418B4_D3BE84);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241A6C_D3C03C);

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241DAC_D3C37C);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241FB0_D3C580);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241FE8_D3C5B8);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80242074_D3C644);
