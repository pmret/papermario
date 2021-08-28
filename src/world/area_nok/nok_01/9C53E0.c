#include "nok_01.h"

static char* N(exit_str_0) = "nok_13";
static char* N(exit_str_1) = "nok_02";

#define UNK_ALPHA_FUNC_NPC 15

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240000_9C53E0);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802400B4_9C5494);

#include "world/common/NpcJumpFunc3.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

#include "world/common/UnkNpcAIFunc11.inc.c"

#include "world/common/UnkNpcAIFunc10.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240540_9C5920);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802405EC_9C59CC);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802407F4_9C5BD4);

#include "world/common/Call800E9894.inc.c"

#include "world/common/Call800E98C4SyncStatusMenu.inc.c"

#include "world/common/UnkFunc32.inc.c"

#include "world/common/CamSetFOV.inc.c"

#include "world/common/AwaitScriptComplete.inc.c"

#include "world/common/PartnerToggleAbilityScript.inc.c"

#include "world/common/DoesPlayerNeedSleep.inc.c"

#include "world/common/UnkFunc35.inc.c"

#include "world/common/GetPartnerCall800EB168.inc.c"

#include "world/common/UnkFunc36.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240D68_9C6148);
/*
ApiStatus N(func_80240D68_9C6148)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80245F44_9CB324) == NULL) {
        N(D_80245F44_9CB324) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80245F44_9CB324)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80245F44_9CB324)[i];
        }
        heap_free(N(D_80245F44_9CB324));
        N(D_80245F44_9CB324) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240EA4_9C6284);
/*
ApiStatus N(func_80240EA4_9C6284)(Evt *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemyID;
    u16 phi_s0 = get_variable(script, EVT_SAVE_FLAG(1768));
    u16 phi_s7 = get_variable(script, EVT_SAVE_FLAG(1769));
    u16 temp_s6 = get_variable(script, EVT_SAVE_VAR(350));
    u16 phi_s5 = get_variable(script, EVT_SAVE_VAR(351));
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
            set_variable(script, EVT_SAVE_VAR(350), temp_s6);
            set_variable(script, EVT_SAVE_VAR(351), phi_s5);
            phi_s0 = 1;
        }
    }

    set_variable(script, EVT_SAVE_FLAG(1768), phi_s0);
    set_variable(script, EVT_SAVE_FLAG(1769), phi_s7);
    temp_s0_2 = get_variable(NULL, EVT_SAVE_VAR(352));
    temp_v0 = get_variable(NULL, EVT_STORY_PROGRESS);

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

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241454_9C6834);
/*
ApiStatus N(func_80241454_9C6834)(Evt *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    u16 quizzesAnswered = gPlayerData.quizzesAnswered;

    if (quizzesAnswered < 0x3E7) {
        playerData->quizzesAnswered++;
    }

    if (script->varTable[0] == N(quizAnswers)[get_variable(NULL, EVT_SAVE_VAR(352))]) {
        script->varTable[0] = 1;
        playerData->quizzesCorrect++;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802414D8_9C68B8);
/*
ApiStatus N(func_802414D8_9C68B8)(Evt *script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        Effect** effect = &D_8024DFE0;

        *effect = playFX_4E(0, get_variable(script, EVT_ARRAY(1)), get_variable(script, EVT_ARRAY(2)), get_variable(script, EVT_ARRAY(3)));
        D_8024DFE4 = playFX_54(0, get_variable(script, EVT_ARRAY(1)), get_variable(script, EVT_ARRAY(2)), get_variable(script, EVT_ARRAY(3)));
        D_8024DFE8 = playFX_80(0, get_variable(script, EVT_ARRAY(1)), get_variable(script, EVT_ARRAY(2)), get_variable(script, EVT_ARRAY(3)), 1.0f, 0);

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

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802416F0_9C6AD0);
/*
ApiStatus N(func_802416F0_9C6AD0)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802417A4_9C6B84);
/*
ApiStatus N(func_802417A4_9C6B84)(Evt *script, s32 isInitialCall) {
    D_8024DFE0->unk_0C->unk_34 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802417D8_9C6BB8);
/*
ApiStatus N(func_802417D8_9C6BB8)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241858_9C6C38);
/*
ApiStatus N(func_80241858_9C6C38)(Evt *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 0;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241870_9C6C50);
/*
ApiStatus N(func_80241870_9C6C50)(Evt *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_8024188C_9C6C6C);
/*
ApiStatus N(func_8024188C_9C6C6C)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241D60_9C7140);
/*
void N(func_80241D60_9C7140)(void) {
    s32 var = get_variable(NULL, D_8024DFD8);

    if (var == 1) {
        playFX_50(0, 0, 0, 0);
    } else if (var == 2) {
        playFX_50(1, 0, 0, 0);
    }
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241DCC_9C71AC);
/*
ApiStatus N(func_80241DCC_9C71AC)(Evt *script, s32 isInitialCall) {
    D_8024DFC0 = create_generic_entity_frontUI(NULL, N(func_80242468_95D668));
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242028_9C7408);
/*
ApiStatus N(func_80242028_9C7408)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024856C_9CD94C) = FALSE;
    }

    if (N(D_8024856C_9CD94C)) {
        N(D_8024856C_9CD94C) = FALSE;
        set_variable(script, *args, N(D_80248570_9CD950));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_8024207C_9C745C);
/*
ApiStatus N(func_8024207C_9C745C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80248570_9CD950) = get_variable(script, *args);
    N(D_8024856C_9CD94C) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802420B4_9C7494);
/*
ApiStatus N(func_802420B4_9C7494)(Evt* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802423CC_9C77AC);
/*
ApiStatus N(func_802423CC_9C77AC)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242410_9C77F0);
/*
ApiStatus N(func_80242410_9C77F0)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_8024243C_9C781C);

#include "common/UnkFloatFunc.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802426A4_9C7A84);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242760_9C7B40);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242790_9C7B70);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802427C0_9C7BA0);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242804_9C7BE4);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242858_9C7C38);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242898_9C7C78);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802428B8_9C7C98);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802428D8_9C7CB8);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242910_9C7CF0);
/*
ApiStatus N(func_80242910_9C7CF0)(Evt *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->unk_328 = playerData->frameCounter;
    return ApiStatus_DONE2;
}
*/
