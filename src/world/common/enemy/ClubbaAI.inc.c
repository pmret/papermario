#include "common.h"
#include "effects.h"
#include "world/partners.h"

//TODO ClubbaWanderI_Main ?
ApiStatus N(func_80241170_C3ED60)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
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
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->AI_TEMP_STATE_AFTER_SUSPEND = AI_STATE_WANDER_INIT;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
        enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_NONE;
    }

    if (script->AI_TEMP_STATE < AI_STATE_MELEE_HITBOX_INIT
            && enemy->AI_VAR_ATTACK_STATE == MELEE_HITBOX_STATE_NONE
            && N(MeleeHitbox_CanSeePlayer)(script)) {
        script->AI_TEMP_STATE = AI_STATE_MELEE_HITBOX_INIT;
    }

    switch (script->AI_TEMP_STATE) {
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
        case AI_STATE_MELEE_HITBOX_INIT:
            N(MeleeHitbox_30)(script);
        case AI_STATE_MELEE_HITBOX_PRE:
            N(MeleeHitbox_31)(script);
            if (script->AI_TEMP_STATE != AI_STATE_MELEE_HITBOX_ACTIVE) {
                break;
            }
        case AI_STATE_MELEE_HITBOX_ACTIVE:
            N(MeleeHitbox_32)(script);
            if (script->AI_TEMP_STATE != AI_STATE_MELEE_HITBOX_MISS) {
                break;
            }
        case AI_STATE_MELEE_HITBOX_MISS:
            N(MeleeHitbox_33)(script);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
    }

    return ApiStatus_BLOCK;
}
