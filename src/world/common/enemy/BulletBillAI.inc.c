#include "common.h"
#include "effects.h"

#define FIRST_BULLET_NPCID  50
#define LAST_BULLET_NPCID   59

enum AiStateBulletBill {
    AI_STATE_BULLET_INIT        = 0,
    AI_STATE_BULLET_READY       = 1,
    AI_STATE_BULLET_FIRED       = 2,
    AI_STATE_BULLET_HIT         = 3,
};

enum AiStateBillBlaster {
    AI_STATE_BLASTER_INIT       = 0,
    AI_STATE_BLASTER_PREPARE    = 10,
    AI_STATE_BLASTER_FIRE       = 11,
    AI_STATE_BLASTER_COOLDOWN   = 12,
};

#define AI_VAR_BULLET_BLASTER   varTable[1] // npcID of bullet's blaster
#define AI_VAR_BULLET_RANGE     varTable[2] // limiting x position of bullets

#define AI_VAR_BLASTER_BULLET   varTable[0] // npcID of blaster's last bullet
#define AI_VAR_BLASTER_RANGE    varTable[1] // limiting x position of bullets

static s32 N(BillBlasterAI_GetIdleBulletNpcID)(void) {
    s32 i;

    for (i = FIRST_BULLET_NPCID; i <= LAST_BULLET_NPCID; i++) {
        if (get_enemy(i)->VAR_PROJECTILE_HITBOX_STATE == PROJECTILE_HITBOX_STATE_NONE) {
            return i;
        }
    }

    return -1;
}

ApiStatus N(BulletBillAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *script->ptrReadPos);
    s32 hitDetected = FALSE;
    s32 done = FALSE;
    Npc* blasterNpc;
    f32 nextX, nextZ;
    f32 deltaY;
    
    if (isInitialCall || enemy->VAR_PROJECTILE_HITBOX_STATE == PROJECTILE_HITBOX_STATE_DONE) {
        script->AI_TEMP_STATE = AI_STATE_BULLET_INIT;
        npc->duration = 0;
        enemy->aiFlags |= ENEMY_AI_FLAGS_8;
        enemy->flags |= ENEMY_FLAGS_200000;
        npc->flags |= NPC_FLAG_40000;
        enemy->VAR_PROJECTILE_HITBOX_STATE = PROJECTILE_HITBOX_STATE_NONE;
        enemy->AI_VAR_BULLET_BLASTER = -1;
    }
    
    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->aiPaused != 0) {
            return 0;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_BULLET_INIT:
            npc->pos.x = 0.0f;
            npc->pos.y = -1000.0f;
            npc->pos.z = 0.0f;
            npc->rotation.y = 0.0f;
            npc->duration = 0;
            npc->flags |= NPC_FLAG_2;
            npc->flags &= ~NPC_FLAG_LOCK_ANIMS;
            disable_npc_shadow(npc);
            enemy->VAR_PROJECTILE_HITBOX_STATE = PROJECTILE_HITBOX_STATE_NONE;
            script->AI_TEMP_STATE = AI_STATE_BULLET_READY;
            // fallthrough
        case AI_STATE_BULLET_READY:
            if (enemy->VAR_PROJECTILE_HITBOX_STATE != PROJECTILE_HITBOX_STATE_PRE) {
                break;
            }
            enemy->VAR_PROJECTILE_HITBOX_STATE = PROJECTILE_HITBOX_STATE_ACTIVE;
            blasterNpc = get_npc_unsafe(get_enemy(enemy->AI_VAR_BULLET_BLASTER)->npcID);
            npc->flags &= ~NPC_FLAG_2;
            npc->pos.x = blasterNpc->pos.x;
            npc->pos.y = blasterNpc->pos.y + 11.0;
            npc->pos.z = blasterNpc->pos.z + 1.0;
            npc->yaw = blasterNpc->yaw;
            npc->moveSpeed = aiSettings->chaseSpeed;
            npc->currentAnim = enemy->animList[ENEMY_ANIM_RUN];
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 25.0f, npc->yaw);
            if (npc->yaw < 180.0f) {
                npc->renderYaw = 180.0f;
            } else {
                npc->renderYaw = 0.0f;
            }
            npc->currentAnim = enemy->animList[ENEMY_ANIM_CHASE];
            npc->duration = 300;
            npc->flags |= (NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_LOCK_ANIMS);
            enable_npc_shadow(npc);
            script->AI_TEMP_STATE = AI_STATE_BULLET_FIRED;
            // fallthrough
        case AI_STATE_BULLET_FIRED:
            deltaY = (npc->pos.y - gPlayerStatusPtr->position.y);
            if ((deltaY > 190.0) || (deltaY < -120.0)) {
                done = TRUE;
                break;
            }

            nextX = npc->pos.x;
            nextZ = npc->pos.z;
            add_vec2D_polar(&nextX, &nextZ, npc->moveSpeed, npc->yaw);
            if (npc->yaw < 180.0f) {
                if (enemy->AI_VAR_BULLET_RANGE <= nextX) {
                    hitDetected = TRUE;
                }
            } else {
                if (nextX <= enemy->AI_VAR_BULLET_RANGE) {
                    hitDetected = TRUE;
                }
            }

            if (hitDetected) {
                npc->currentAnim = enemy->animList[ENEMY_ANIM_HIT];
                ai_enemy_play_sound(npc, SOUND_B0000018, 0);
                fx_ring_blast(0, npc->pos.x, npc->pos.y + 5.0f, npc->pos.z + 1.0f, 0.05f, 20);
                fx_smoke_burst(0, npc->pos.x, npc->pos.y + 5.0f, npc->pos.z + 0.0f, 1.2f, 25);
                npc->duration = 1;
                script->AI_TEMP_STATE = AI_STATE_BULLET_HIT;
            } else {
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            }

            if (script->AI_TEMP_STATE != AI_STATE_BULLET_HIT) {
                break;
            }
            // fallthrough
        case AI_STATE_BULLET_HIT:
            npc->duration--;
            if (npc->duration <= 0) {
                done = TRUE;
            }
            break;
    }
    if (done != 0) {
        enemy->VAR_PROJECTILE_HITBOX_STATE = PROJECTILE_HITBOX_STATE_DONE;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(BillBlasterAI_Main)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args++);
    s32 bulletNpcID;
    Enemy* bulletEnemy;
    f32 deltaY;
    
    if (isInitialCall) {
        script->AI_TEMP_STATE = AI_STATE_BLASTER_INIT;
        npc->duration = 30;
        npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];
        enemy->flags |= ENEMY_FLAGS_200000;
        disable_npc_shadow(npc);
    }
    
    deltaY = npc->pos.y - gPlayerStatusPtr->position.y;
    if ((deltaY > 190.0) || (deltaY < -80.0)) {
        return ApiStatus_BLOCK;
    }
    
    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];
        if (enemy->aiPaused != 0) {
            return ApiStatus_BLOCK;
        } 
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }
    
    switch (script->AI_TEMP_STATE) {
        case AI_STATE_BLASTER_INIT:
            npc->duration--;
            if (npc->duration <= 0) {
                script->AI_TEMP_STATE = AI_STATE_BLASTER_PREPARE;
            }
            break;
        case AI_STATE_BLASTER_PREPARE:
            bulletNpcID = N(BillBlasterAI_GetIdleBulletNpcID)();
            enemy->AI_VAR_BLASTER_BULLET = bulletNpcID;
            if (bulletNpcID > 0) {
                bulletEnemy = get_enemy(bulletNpcID);
                bulletEnemy->VAR_PROJECTILE_HITBOX_STATE = PROJECTILE_HITBOX_STATE_INIT;
                bulletEnemy->AI_VAR_BULLET_BLASTER = enemy->npcID;
                bulletEnemy->AI_VAR_BULLET_RANGE = enemy->AI_VAR_BLASTER_RANGE;
                npc->currentAnim = enemy->animList[ENEMY_ANIM_MELEE_PRE];
                npc->duration = 10;
                script->AI_TEMP_STATE = AI_STATE_BLASTER_FIRE;
            } else {
                npc->duration = (rand_int(1000) % 60) + 40;
                script->AI_TEMP_STATE =AI_STATE_BLASTER_INIT;
            }
            break;
        case AI_STATE_BLASTER_FIRE:
            npc->duration--;
            if (npc->duration > 0) {
                break;
            }
            npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];
            bulletEnemy = get_enemy(enemy->AI_VAR_BLASTER_BULLET);
            bulletEnemy->VAR_PROJECTILE_HITBOX_STATE = PROJECTILE_HITBOX_STATE_PRE;            
            ai_enemy_play_sound(npc, SOUND_328, 0x200000);
            npc->duration = 5;
            script->AI_TEMP_STATE = AI_STATE_BLASTER_COOLDOWN;
            // fallthrough
        case AI_STATE_BLASTER_COOLDOWN:
            npc->duration--;
             if (npc->duration <= 0) {
                npc->duration = (rand_int(1000) % 60) + 40;
                script->AI_TEMP_STATE = AI_STATE_BLASTER_INIT;
            }
            break;
    }
    return ApiStatus_BLOCK;
}
