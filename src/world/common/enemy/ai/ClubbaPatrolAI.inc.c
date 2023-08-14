#include "common.h"
#include "world/partners.h"

// prerequisites
#include "world/common/enemy/ai/MeleeHitbox.inc.c"
#include "world/common/enemy/ai/States_PatrolAI.inc.c"

API_CALLABLE(N(ClubbaPatrolAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* npcAISettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detectPos.x;
    territory.pointZ = enemy->territory->patrol.detectPos.z;
    territory.sizeX = enemy->territory->patrol.detectSize.x;
    territory.sizeZ = enemy->territory->patrol.detectSize.z;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND)) {
        script->AI_TEMP_STATE = AI_STATE_PATROL_INIT;
        npc->duration = 0;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_FLYING;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_FLYING;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->functionTemp[1] = AI_STATE_PATROL_INIT;
            enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->AI_TEMP_STATE < AI_STATE_MELEE_HITBOX_INIT) && (enemy->varTable[0] == 0) && N(MeleeHitbox_CanSeePlayer)(script)) {
        script->AI_TEMP_STATE = AI_STATE_MELEE_HITBOX_INIT;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_PATROL_INIT:
            N(PatrolAI_MoveInit)(script, npcAISettings, territoryPtr);
            // fallthrough
        case AI_STATE_PATROL:
            N(PatrolAI_Move)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            N(PatrolAI_LoiterInit)(script, npcAISettings, territoryPtr);
            // fallthrough
        case AI_STATE_LOITER:
            N(PatrolAI_Loiter)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOITER_POST:
            N(PatrolAI_PostLoiter)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_ALERT_INIT:
            N(PatrolAI_JumpInit)(script, npcAISettings, territoryPtr);
            // fallthrough
        case AI_STATE_ALERT:
            N(PatrolAI_Jump)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            N(PatrolAI_ChaseInit)(script, npcAISettings, territoryPtr);
            // fallthrough
        case AI_STATE_CHASE:
            N(PatrolAI_Chase)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            N(PatrolAI_LosePlayer)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_MELEE_HITBOX_INIT:
            N(MeleeHitbox_30)(script);
            // fallthrough
        case AI_STATE_MELEE_HITBOX_PRE:
            N(MeleeHitbox_31)(script);
            if (script->functionTemp[0] != AI_STATE_MELEE_HITBOX_ACTIVE) {
                break;
            }
            // fallthrough
        case AI_STATE_MELEE_HITBOX_ACTIVE:
            N(MeleeHitbox_32)(script);
            if (script->functionTemp[0] != AI_STATE_MELEE_HITBOX_MISS) {
                break;
            }
            // fallthrough
        case AI_STATE_MELEE_HITBOX_MISS:
            N(MeleeHitbox_33)(script);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
            break;
    }

    return ApiStatus_BLOCK;
}
