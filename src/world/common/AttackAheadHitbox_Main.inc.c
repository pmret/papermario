#include "common.h"
#include "npc.h"

ApiStatus N(AttackAheadHitbox_Main)(Evt *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->functionTemp[0] = AI_STATE_WANDER_INIT;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= 0x200;
            npc->flags &= ~0x8;
        } else {
            npc->flags &= ~0x200;
            npc->flags |= 0x8;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->functionTemp[0] = AI_STATE_SUSPEND;
            script->functionTemp[1] = AI_STATE_WANDER_INIT;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0] < AI_STATE_AHEAD_HITBOX_30) && (enemy->varTable[0] == 0) && N(AttackAheadHitbox_CanSeePlayer)(script)) {
        script->functionTemp[0] = AI_STATE_AHEAD_HITBOX_30;
    }

    switch (script->functionTemp[0]) {
        case AI_STATE_WANDER_INIT:
            basic_ai_wander_init(script, npcAISettings, territoryPtr);
        case AI_STATE_WANDER:
            basic_ai_wander(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            basic_ai_loiter_init(script, npcAISettings, territoryPtr);
        case AI_STATE_LOITER:
            basic_ai_loiter(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_JUMP_INIT:
            basic_ai_found_player_jump_init(script, npcAISettings, territoryPtr);
        case AI_STATE_JUMP:
            basic_ai_found_player_jump(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
        case AI_STATE_CHASE:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            basic_ai_lose_player(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_AHEAD_HITBOX_30:
            N(AttackAheadHitboxAI_30)(script);
        case AI_STATE_AHEAD_HITBOX_31:
            N(AttackAheadHitboxAI_31)(script);
            if (script->functionTemp[0] != AI_STATE_AHEAD_HITBOX_32) {
                break;
            }
        case AI_STATE_AHEAD_HITBOX_32:
            N(AttackAheadHitboxAI_32)(script);
            if (script->functionTemp[0] != AI_STATE_AHEAD_HITBOX_33) {
                break;
            }
        case AI_STATE_AHEAD_HITBOX_33:
            N(AttackAheadHitboxAI_33)(script);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
    }

    return ApiStatus_BLOCK;
}
