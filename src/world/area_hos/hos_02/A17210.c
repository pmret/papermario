#include "hos_02.h"

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_02/A17210", func_802411A0_A173C0);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_02/A17210", func_80241C44_A17E64);
/*
void N(func_80241C44_A17E64)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80244490_A1A6B0)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_02/A17210", func_802422FC_A1851C);
/*
ApiStatus N(func_802422FC_A1851C)(Evt* script, s32 isInitialCall) {
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
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(func_802421D8_A183F8)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(hos_02_UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
        case 1:
            N(func_802411A0_A173C0)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_80241888_A17AA8)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241C44_A17E64)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80241E48_A18068)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
*/

#include "world/common/UnkNpcAIFunc13.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_02/A17210", func_80242618_A18838);
/*
void N(func_80242618_A18838)(Evt *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    s32 flag;
    f32 temp_f6;

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1) == 0) {
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        npc->currentAnim = enemy->animList[0];
        npc->duration = 30;
        script->functionTemp[0] = 20;
        enemy->varTable[9] = 30;
        return;
    }

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    flag = 0;
    if (!(npc->flags & 8)) {
        x = npc->pos.x;
        y = npc->pos.y + npc->collisionHeight;
        z = npc->pos.z;
        w = npc->collisionHeight + 3.0;
        if ((npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &w) != 0) && (w < npc->collisionHeight)) {
            flag = 1;
        }
    }

    if (flag) {
        npc->pos.y = y + 1.0;
    } else {
        temp_f6 = npc->pos.y - (gPlayerStatusPtr->position.y + 6.0);
        if ((temp_f6 < 0.0) || (temp_f6 > 4.0)) {
            temp_f6 = -temp_f6;
            npc->pos.y += temp_f6 * 0.06;
        }
    }
    if (npc->duration > 0) {
        npc->duration--;
        return;
    }
    script->functionTemp[0] = 12;
}
*/

#include "world/common/UnkFunc45.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_02/A17210", func_802428F4_A18B14);
