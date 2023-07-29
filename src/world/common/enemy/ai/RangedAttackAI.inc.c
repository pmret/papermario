// Used by:
// - Monty Mole
// - Spy Guy
// - Dry Bones
// - Hammer Bros

#include "common.h"
#include "npc.h"
#include "effects.h"

// prerequisites
#include "world/common/enemy/ai/ProjectileHitbox.inc.c"

API_CALLABLE(N(RangedAttackAI_Main)) {
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    MobileAISettings* settings = (MobileAISettings*) evt_get_variable(script, *args++);
    f32 dist;

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 40.0f;
    territory.detectFlags = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND)) {
        script->AI_TEMP_STATE = 0;
        npc->duration = 0;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;

        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_8;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_8;
        }

        if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        } else if (enemy->flags & ENEMY_FLAG_BEGIN_WITH_CHASING) {
            script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        enemy->flags &= ~ENEMY_FLAG_BEGIN_WITH_CHASING;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_WANDER_INIT:
            basic_ai_wander_init(script, settings, territoryPtr);
            // fallthrough
        case AI_STATE_WANDER:
            basic_ai_wander(script, settings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            basic_ai_loiter_init(script, settings, territoryPtr);
            // fallthrough
        case AI_STATE_LOITER:
            basic_ai_loiter(script, settings, territoryPtr);
            break;
        case AI_STATE_ALERT_INIT:
            basic_ai_found_player_jump_init(script, settings, territoryPtr);
            // fallthrough
        case AI_STATE_ALERT:
            basic_ai_found_player_jump(script, settings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            dist = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
            if (enemy->varTable[0] == 0 || enemy->varTable[0] < dist) {
                N(UnkNpcAIFunc48)(script, settings->chaseRadius, settings->chaseOffsetDist, territoryPtr);
                if (script->AI_TEMP_STATE != AI_STATE_CHASE_INIT) {
                    break;
                }
            }
            basic_ai_chase_init(script, settings, territoryPtr);
            // fallthrough
        case AI_STATE_CHASE:
            basic_ai_chase(script, settings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            basic_ai_lose_player(script, settings, territoryPtr);
            break;
        case AI_STATE_PROJECTILE_HITBOX_30:
            N(ProjectileHitbox_30(script));
            break;
        case AI_STATE_PROJECTILE_HITBOX_31:
            N(ProjectileHitbox_31(script));
            break;
        case AI_STATE_PROJECTILE_HITBOX_32:
            N(ProjectileHitbox_32(script));
            break;
        case AI_STATE_PROJECTILE_HITBOX_33:
            N(ProjectileHitbox_33(script));
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}
