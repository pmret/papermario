#include "common.h"
#include "npc.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

void N(ShyGuyPatrolAI_14)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territoryPtr) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->moveSpeed *= 0.6;
    npc->curAnim = enemy->animList[12];
    npc->duration = 5;
    script->functionTemp[0] = 0xF;
}

void N(ShyGuyPatrolAI_15)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe((s32) enemy->npcID);
    f32 yaw = npc->yaw;

    if (!ai_check_fwd_collisions(npc, npc->moveSpeed, &yaw, NULL, NULL, NULL)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }

    npc->duration--;
    if (npc->duration == 0) {
        npc->moveSpeed *= 0.6;

        npc->curAnim = enemy->animList[11];
        npc->duration = 10;
        script->functionTemp[0] = 16;
    }
}

void N(ShyGuyPatrolAI_16)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 yaw = npc->yaw;

    if (!ai_check_fwd_collisions(npc, npc->moveSpeed, &yaw, NULL, NULL, NULL)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }

    npc->duration--;
    if (npc->duration == 0) {
        npc->duration = 30;
        script->functionTemp[0] = 17;
    }
}

void N(ShyGuyPatrolAI_17)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        script->functionTemp[0] = 0;
    }
}

API_CALLABLE(N(ShyGuyPatrolAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    Bytecode* args = script->ptrReadPos;
    MobileAISettings* aiSettings = (MobileAISettings*) evt_get_variable(script, *args++);
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 hitDepth;

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detectPos.x;
    territory.pointZ = enemy->territory->patrol.detectPos.z;
    territory.sizeX = enemy->territory->patrol.detectSize.x;
    territory.sizeZ = enemy->territory->patrol.detectSize.z;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

   if (isInitialCall || enemy->aiFlags & AI_FLAG_SUSPEND) {
        script->functionTemp[0] = 0;
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

        if (enemy->aiFlags & AI_FLAG_SUSPEND) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~AI_FLAG_SUSPEND;
        } else if (enemy->flags & ENEMY_FLAG_BEGIN_WITH_CHASING) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAG_BEGIN_WITH_CHASING;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        hitDepth = 100.0f;
        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0]) {
        case 0x0:
            N(PatrolAI_MoveInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case 0x1:
            N(PatrolAI_Move)(script, aiSettings, territoryPtr);
            break;
        case 0x2:
            N(PatrolAI_LoiterInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case 0x3:
            N(PatrolAI_Loiter)(script, aiSettings, territoryPtr);
            break;
        case 0x4:
            N(PatrolAI_PostLoiter)(script, aiSettings, territoryPtr);
            break;
        case 0xA:
            N(PatrolAI_JumpInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case 0xB:
            N(PatrolAI_Jump)(script, aiSettings, territoryPtr);
            break;
        case 0xC:
            N(PatrolAI_ChaseInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case 0xD:
            N(PatrolAI_Chase)(script, aiSettings, territoryPtr);
            break;
        case 0xE:
            N(ShyGuyPatrolAI_14)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0xF) {
                break;
            }
        case 0xF:
            N(ShyGuyPatrolAI_15)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0x10) {
                break;
            }
        case 0x10:
            N(ShyGuyPatrolAI_16)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0x11) {
                break;
            }
        case 0x11:
            N(ShyGuyPatrolAI_17)(script, aiSettings, territoryPtr);
            break;
        case 0x63:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}
