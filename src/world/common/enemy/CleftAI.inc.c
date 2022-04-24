#include "common.h"
#include "npc.h"

#include "world/common/enemy/state/CleftAI_CanSeePlayer.inc.c"

#include "world/common/enemy/state/CleftAI_00.inc.c"

#include "world/common/enemy/state/CleftAI_01.inc.c"

#include "world/common/enemy/state/CleftAI_02.inc.c"

#include "world/common/enemy/state/CleftAI_03.inc.c"

#include "world/common/enemy/state/CleftAI_04.inc.c"

#include "world/common/enemy/state/CleftAI_05.inc.c"

#include "world/common/enemy/state/CleftAI_20.inc.c"

#include "world/common/enemy/state/CleftAI_21.inc.c"

#include "world/common/enemy/state/CleftAI_22.inc.c"

#include "world/common/enemy/state/CleftAI_40.inc.c"

#include "world/common/enemy/state/CleftAI_41.inc.c"

#include "world/common/enemy/state/CleftAI_50.inc.c"

#include "world/common/enemy/state/CleftAI_51.inc.c"

// need to separate
#include "world/common/UnkDurationCheck.inc.c"

s32 N(CleftAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;

    enemy->varTable[10] = evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 40.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
    }

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    if ((u32)script->functionTemp[0] - 12 < 3 && N(CleftAI_CanSeePlayer)(script, npcAISettings, territoryPtr)) {
        script->functionTemp[0] = 20;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(CleftAI_00)(script, npcAISettings, territoryPtr);
        case 1:
            N(CleftAI_01)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 2) {
                return ApiStatus_BLOCK;
            }
        case 2:
            N(CleftAI_02)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 3) {
                return ApiStatus_BLOCK;
            }
        case 3:
            N(CleftAI_03)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 4) {
                return ApiStatus_BLOCK;
            }
        case 4:
            N(CleftAI_04)(script, npcAISettings, territoryPtr);
        case 5:
            N(CleftAI_05)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 12:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                return ApiStatus_BLOCK;
            }
        case 13:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 14) {
                return ApiStatus_BLOCK;
            }
        case 14:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[0] = 40;
            }
            return ApiStatus_BLOCK;
        case 20:
            N(CleftAI_20)(script, npcAISettings, territoryPtr);
        case 21:
            N(CleftAI_21)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 22:
            N(CleftAI_22)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 40:
            N(CleftAI_40)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 41) {
                return ApiStatus_BLOCK;
            }
        case 41:
            N(CleftAI_41)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 50:
            N(CleftAI_50)(script, npcAISettings, territoryPtr);
        case 51:
            N(CleftAI_51)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 52) {
                return ApiStatus_BLOCK;
            }
        case 52:
            N(UnkDurationCheck)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}
