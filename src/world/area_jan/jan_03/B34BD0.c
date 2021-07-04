#include "jan_03.h"

static char* N(exit_str_0) = "jan_02";
static char* N(exit_str_1) = "jan_05";
static char* N(exit_str_2) = "jan_22";
static char* N(exit_str_3) = "";

#define UNK_ALPHA_FUNC_NPC 17

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

#include "world/common/UnkFunc25.inc.c"

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802405EC_B351BC);

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80240C9C_B3586C);
/*
ApiStatus N(func_80240C9C_B3586C)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2].s = 0;
    }
    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[0].s = 1;
    return ApiStatus_DONE1;
}
*/

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802411B4_B35D84);
/*
ApiStatus N(func_802411B4_B35D84)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0].s = 12;
            enemy->flags &= ~0x40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
#include "world/common/UnkNpcAIFunc24.inc.c"
        case 1:
            N(func_80240778_B35348)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(func_80240AE0_B356B0)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_80240C9C_B3586C)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(func_80240F6C_B35B3C)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(func_802410F4_B35CC4)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}
*/

static char* N(exit_str_4) = "tik_08";

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

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802419D8_B365A8);
/*
ApiStatus N(func_802419D8_B365A8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80247444_B3C014) = FALSE;
    }

    if (N(D_80247444_B3C014)) {
        N(D_80247444_B3C014) = FALSE;
        set_variable(script, *args, N(D_80247448_B3C018));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241A2C_B365FC);
/*
ApiStatus N(func_80241A2C_B365FC)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80247448_B3C018) = get_variable(script, *args);
    N(D_80247444_B3C014) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241A64_B36634);
/*
ApiStatus N(func_80241A64_B36634)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241B00_B366D0);
/*
ApiStatus N(func_80241B00_B366D0)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241B9C_B3676C);
/*
ApiStatus N(func_80241B9C_B3676C)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80247764_B3C334) == NULL) {
        N(D_80247764_B3C334) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80247764_B3C334)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80247764_B3C334)[i];
        }
        heap_free(N(D_80247764_B3C334));
        N(D_80247764_B3C334) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241CD8_B368A8);
/*
ApiStatus N(func_80241CD8_B368A8)(ScriptInstance *script, s32 isInitialCall) {
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
    temp_v0 = get_variable(NULL, SI_SAVE_VAR(0));

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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242288_B36E58);
/*
ApiStatus N(func_80242288_B36E58)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_8024230C_B36EDC);
/*
ApiStatus N(func_8024230C_B36EDC)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242524_B370F4);
/*
ApiStatus N(func_80242524_B370F4)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802425D8_B371A8);
/*
ApiStatus N(func_802425D8_B371A8)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE0->unk_0C->unk_34 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_8024260C_B371DC);
/*
ApiStatus N(func_8024260C_B371DC)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_8024268C_B3725C);
/*
ApiStatus N(func_8024268C_B3725C)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 0;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802426A4_B37274);
/*
ApiStatus N(func_802426A4_B37274)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFE8->unk_0C->unk_1C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802426C0_B37290);
/*
ApiStatus N(func_802426C0_B37290)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242B94_B37764);
/*
void N(func_80242B94_B37764)(void) {
    s32 var = get_variable(NULL, D_8024DFD8);

    if (var == 1) {
        playFX_50(0, 0, 0, 0);
    } else if (var == 2) {
        playFX_50(1, 0, 0, 0);
    }
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242C00_B377D0);
/*
ApiStatus N(func_80242C00_B377D0)(ScriptInstance *script, s32 isInitialCall) {
    D_8024DFC0 = create_generic_entity_frontUI(NULL, N(func_80242468_95D668));
    return ApiStatus_DONE2;
}
*/

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242EAC_B37A7C);
/*
ApiStatus N(func_80242EAC_B37A7C)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242EF0_B37AC0);
/*
ApiStatus N(func_80242EF0_B37AC0)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242F1C_B37AEC);
