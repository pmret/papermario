#include "hos_03.h"

#define UNK_ALPHA_FUNC_NPC 7

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80240CB0_A1BDB0);
/*
void N(func_80240CB0_A1BDB0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.point.x, enemy->territory->wander.point.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[0].s = 1;
}
*/

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80240E60_A1BF60);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80241904_A1CA04);
/*
void N(func_80241904_A1CA04)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_802436DC_BE6E8C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80241FBC_A1D0BC);
/*
ApiStatus N(func_80241FBC_A1D0BC)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_34 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(func_80241E98_A1CF98)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240CB0_A1BDB0)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240E60_A1BF60)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_80241548_A1C648)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241904_A1CA04)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80241B08_A1CC08)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
*/

#include "world/common/Call800E9894.inc.c"

#include "world/common/Call800E98C4SyncStatusMenu.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_802421F0_A1D2F0);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_8024226C_A1D36C);

#include "world/common/AwaitScriptComplete.inc.c"

#include "world/common/PartnerToggleAbilityScript.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242368_A1D468);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_802423BC_A1D4BC);

#include "world/common/GetPartnerCall800EB168.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_8024249C_A1D59C);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_802424A4_A1D5A4);
/*
ApiStatus N(func_802424A4_A1D5A4)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_802425E0_A1D6E0);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242804_A1D904);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242870_A1D970);

#include "world/common/UnkAlphaFunc.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242A1C_A1DB1C);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242B90_A1DC90);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242C14_A1DD14);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242E2C_A1DF2C);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242EE0_A1DFE0);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242F14_A1E014);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242F94_A1E094);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242FAC_A1E0AC);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80242FC8_A1E0C8);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_8024349C_A1E59C);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1BDB0", func_80243508_A1E608);
