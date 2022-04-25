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

#include "world/common/enemy/state/CleftAI_52.inc.c"

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
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        npc->duration = 0;

        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
    }

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    if ((u32)script->AI_TEMP_STATE - 12 < 3 && N(CleftAI_CanSeePlayer)(script, npcAISettings, territoryPtr)) {
        script->AI_TEMP_STATE = 20;
    }

    switch (script->AI_TEMP_STATE) {
        case 0:
            N(CleftAI_00)(script, npcAISettings, territoryPtr);
        case 1:
            N(CleftAI_01)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != 2) {
                return ApiStatus_BLOCK;
            }
        case 2:
            N(CleftAI_02)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != 3) {
                return ApiStatus_BLOCK;
            }
        case 3:
            N(CleftAI_03)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != 4) {
                return ApiStatus_BLOCK;
            }
        case 4:
            N(CleftAI_04)(script, npcAISettings, territoryPtr);
        case 5:
            N(CleftAI_05)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 12:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != 13) {
                return ApiStatus_BLOCK;
            }
        case 13:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != 14) {
                return ApiStatus_BLOCK;
            }
        case 14:
            npc->duration--;
            if (npc->duration == 0) {
                script->AI_TEMP_STATE = 40;
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
            if (script->AI_TEMP_STATE != 41) {
                return ApiStatus_BLOCK;
            }
        case 41:
            N(CleftAI_41)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 50:
            N(CleftAI_50)(script, npcAISettings, territoryPtr);
        case 51:
            N(CleftAI_51)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != 52) {
                return ApiStatus_BLOCK;
            }
        case 52:
            N(CleftAI_52)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}
