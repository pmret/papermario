#include "kmr_02.h"

static char* N(exit_str_0) = "kmr_05";
static char* N(exit_str_1) = "kmr_00";
static char* N(exit_str_2) = "kmr_09";
static char* N(exit_str_3) = "";

#define UNK_ALPHA_FUNC_NPC 8

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

#include "world/common/UnkFunc25.inc.c"

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802402E0_8B0350);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240370_8B03E0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240390_8B0400);
/*
ApiStatus N(func_80240390_8B0400)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802455D0_8B5640) == NULL) {
        N(D_802455D0_8B5640) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802455D0_8B5640)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802455D0_8B5640)[i];
        }
        heap_free(N(D_802455D0_8B5640));
        N(D_802455D0_8B5640) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802404CC_8B053C);
/*
ApiStatus N(func_802404CC_8B053C)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240A7C_8B0AEC);
/*
ApiStatus N(func_80240A7C_8B0AEC)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240B00_8B0B70);
/*
ApiStatus N(func_80240B00_8B0B70)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240D18_8B0D88);
/*
ApiStatus N(func_80240D18_8B0D88)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240DCC_8B0E3C);
/*
ApiStatus N(func_80240DCC_8B0E3C)(Evt *script, s32 isInitialCall) {
    D_8024DFE0->unk_0C->unk_34 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240E00_8B0E70);
/*
ApiStatus N(func_80240E00_8B0E70)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240E80_8B0EF0);
/*
ApiStatus N(func_80240E80_8B0EF0)(Evt *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 0;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240E98_8B0F08);
/*
ApiStatus N(func_80240E98_8B0F08)(Evt *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240EB4_8B0F24);
/*
ApiStatus N(func_80240EB4_8B0F24)(Evt *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241388_8B13F8);
/*
void N(func_80241388_8B13F8)(void) {
    s32 var = get_variable(NULL, D_8024DFD8);

    if (var == 1) {
        playFX_50(0, 0, 0, 0);
    } else if (var == 2) {
        playFX_50(1, 0, 0, 0);
    }
}
*/

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802413F4_8B1464);
/*
ApiStatus N(func_802413F4_8B1464)(Evt *script, s32 isInitialCall) {
    D_8024DFC0 = create_generic_entity_frontUI(NULL, N(func_80242468_95D668));
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241424_8B1494);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802414D8_8B1548);

#include "world/common/NpcJumpFunc3.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

#include "world/common/UnkNpcAIFunc11.inc.c"

#include "world/common/UnkNpcAIFunc10.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241964_8B19D4);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241A10_8B1A80);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241C18_8B1C88);

static char* N(exit_str_4) = "nok_02";
static char* N(exit_str_5) = "kmr_03";
static char* N(exit_str_6) = "\0\0\0\0";

#include "world/common/UnkFunc41.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242014_8B2084);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024226C_8B22DC);
/*
ApiStatus N(func_8024226C_8B22DC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80247E30_8B7EA0) = FALSE;
    }

    if (N(D_80247E30_8B7EA0)) {
        N(D_80247E30_8B7EA0) = FALSE;
        set_variable(script, *args, N(D_80247E34_8B7EA4));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802422C0_8B2330);
/*
ApiStatus N(func_802422C0_8B2330)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80247E34_8B7EA4) = get_variable(script, *args);
    N(D_80247E30_8B7EA0) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802422F8_8B2368);
/*
ApiStatus N(func_802422F8_8B2368)(Evt* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242394_8B2404);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802426A0_8B2710);
/*
ApiStatus N(func_802426A0_8B2710)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802426E4_8B2754);
/*
ApiStatus N(func_802426E4_8B2754)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242710_8B2780);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242734_8B27A4);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242788_8B27F8);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802427B0_8B2820);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802427CC_8B283C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802427EC_8B285C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024280C_8B287C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242860_8B28D0);

#include "world/common/SyncStatusMenu.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024295C_8B29CC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242BA8_8B2C18);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242BC0_8B2C30);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F08_8B2F78);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F28_8B2F98);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F7C_8B2FEC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80243034_8B30A4);
