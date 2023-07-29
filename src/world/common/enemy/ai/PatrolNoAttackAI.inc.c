#ifndef _PATROL_AI_NO_ATTACK_
#define _PATROL_AI_NO_ATTACK_

#include "common.h"
#include "npc.h"

// prerequisites
#include "world/common/enemy/ai/States_PatrolAI.inc.c"

API_CALLABLE(N(PatrolNoAttackAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* npcAISettings = (MobileAISettings*)evt_get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detectPos.x;
    territory.pointZ = enemy->territory->patrol.detectPos.z;
    territory.sizeX = enemy->territory->patrol.detectSize.x;
    territory.sizeZ = enemy->territory->patrol.detectSize.z;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    #ifdef _DEAD_H_
    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;
    #endif

    if (isInitialCall || enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
        script->AI_TEMP_STATE = AI_STATE_PATROL_INIT;
        npc->duration = 0;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];

        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->patrol.isFlying) {
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
            enemy->flags &= ~ENEMY_FLAG_BEGIN_WITH_CHASING;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
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
        case AI_STATE_PATROL_15:
            N(PatrolNoAttackAI_15)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}

#endif
