#include "common.h"
#include "npc.h"

void N(ShyGuyWanderAI_14)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territoryPtr) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->moveSpeed *= 0.6;
    npc->curAnim = enemy->animList[12];
    npc->duration = 5;
    script->functionTemp[0] = 0xF;
}

void N(ShyGuyWanderAI_15)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe((s32) enemy->npcID);
    f32 yaw = npc->yaw;

    if (ai_check_fwd_collisions(npc, npc->moveSpeed, &yaw, NULL, NULL, NULL) == 0) {
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

void N(ShyGuyWanderAI_16)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 yaw = npc->yaw;

    if (ai_check_fwd_collisions(npc, npc->moveSpeed, &yaw, NULL, NULL, NULL) == 0) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }

    npc->duration--;
    if (npc->duration == 0) {
        npc->duration = 30;
        script->functionTemp[0] = 17;
    }
}

void N(ShyGuyWanderAI_17)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->curAnim = *enemy->animList;
        script->functionTemp[0] = 0;
    }
}

API_CALLABLE(N(ShyGuyWanderAI_Main)) {
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
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

   if (isInitialCall || enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
        script->functionTemp[0] = 0;
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
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
        } else if (enemy->flags & ENEMY_FLAG_BEGIN_WITH_CHASING) {
            script->functionTemp[0] = 12;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        enemy->flags &= ~ENEMY_FLAG_BEGIN_WITH_CHASING;

        hitDepth = 100.0f;
        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0]) {
        case 0x0:
            basic_ai_wander_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0x1:
            basic_ai_wander(script, aiSettings, territoryPtr);
            break;
        case 0x2:
            basic_ai_loiter_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0x3:
            basic_ai_loiter(script, aiSettings, territoryPtr);
            break;
        case 0xA:
            basic_ai_found_player_jump_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0xB:
            basic_ai_found_player_jump(script, aiSettings, territoryPtr);
            break;
        case 0xC:
            basic_ai_chase_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0xD:
            basic_ai_chase(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0xE) {
                break;
            }
           // fallthrough
        case 0xE:
            N(ShyGuyWanderAI_14)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0xF) {
                break;
            }
           // fallthrough
        case 0xF:
            N(ShyGuyWanderAI_15)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0x10) {
                break;
            }
            // fallthrough
        case 0x10:
            N(ShyGuyWanderAI_16)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0x11) {
                break;
            }
            // fallthrough
        case 0x11:
            N(ShyGuyWanderAI_17)(script, aiSettings, territoryPtr);
            break;
        case 0x63:
            basic_ai_suspend(script);
            break;
    }

    return ApiStatus_BLOCK;
}

