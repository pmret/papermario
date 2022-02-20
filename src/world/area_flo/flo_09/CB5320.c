#include "flo_09.h"

#include "world/common/UnkNpcAIFunc23.inc.c"

#include "world/common/UnkNpcAIFunc35.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80240F74_CB5F74)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_8024362C_CB862C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_8024162C_CB662C)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, npcAISettings);
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
            N(UnkNpcAIFunc23)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkNpcAIFunc35)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(func_80240F74_CB5F74)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkFunc6)(script, npcAISettings, territoryPtr);
    }

    return ApiStatus_BLOCK;
}
