#ifndef _AI_MELEE_HITBOX_INC_
#define _AI_MELEE_HITBOX_INC_ 0

#include "common.h"
#include "effects.h"

void N(MeleeHitbox_30)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_INIT;
    // if flipping, wait for it to finish
    if (npc->turnAroundYawAdjustment == 0) {
        enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_PRE;
        npc->duration = enemy->AI_VAR_MELEE_PRE_TIME;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_PRE];
        script->AI_TEMP_STATE = AI_STATE_MELEE_HITBOX_PRE;
    }
}

void N(MeleeHitbox_31)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_ACTIVE;
        npc->duration = enemy->AI_VAR_MELEE_HIT_TIME;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_HIT];
        script->AI_TEMP_STATE = AI_STATE_MELEE_HITBOX_ACTIVE;
    }
}

void N(MeleeHitbox_32)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* emoteTemp;

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_POST;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->duration = enemy->AI_VAR_MELEE_MISS_TIME;
        if (enemy->AI_VAR_MELEE_MISS_TIME >= 8) {
            fx_emote(EMOTE_FRUSTRATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, enemy->AI_VAR_MELEE_MISS_TIME - 1, &emoteTemp);
        }
        script->AI_TEMP_STATE = AI_STATE_MELEE_HITBOX_MISS;
    }
}

void N(MeleeHitbox_33)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_NONE;
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}

s32 N(MeleeHitbox_CanSeePlayer)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];
    Enemy* hitboxEnemy = get_enemy(enemy->npcID + 1);
    f32 angle;
    s32 ret = TRUE;

    if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z) > hitboxEnemy->AI_VAR_HITNPC_2) {
        ret = FALSE;
    }

    if (clamp_angle(get_clamped_angle_diff(camera->curYaw, npc->yaw)) < 180.0) {
        angle = 90.0f;
    } else {
        angle = 270.0f;
    }

    if (fabsf(get_clamped_angle_diff(angle, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x,
                                     gPlayerStatusPtr->pos.z))) > hitboxEnemy->AI_VAR_HITNPC_3) {
        ret = FALSE;
    }

    if ((2.0 * npc->collisionHeight) <= fabsf(npc->pos.y - gPlayerStatusPtr->pos.y)) {
        ret = FALSE;
    }

    if (gPartnerStatus.actingPartner == PARTNER_BOW) {
        ret = FALSE;
    }

    if (gPartnerStatus.actingPartner == PARTNER_SUSHIE) {
        ret = FALSE;
    }

    return ret;
}

API_CALLABLE(N(MeleeHitbox_Main)) {
    Enemy* hitboxEnemy = script->owner1.enemy;
    Npc* hitboxNpc = get_npc_unsafe(hitboxEnemy->npcID);
    Enemy* baseEnemy;
    Npc* baseNpc;
    f32 posX, posZ;

    #ifdef _DEAD_H_
    hitboxEnemy->unk_108.x = hitboxNpc->pos.x;
    hitboxEnemy->unk_108.y = hitboxNpc->pos.y;
    hitboxEnemy->unk_108.z = hitboxNpc->pos.z;
    hitboxEnemy->unk_114 = 0.0001f;
    hitboxEnemy->unk_118 = 0.0001f;
    #endif

    if (isInitialCall || (hitboxEnemy->aiFlags & ENEMY_AI_FLAG_SUSPEND)) {
        script->functionTemp[0] = 0;
        hitboxNpc->duration = 0;
        hitboxNpc->flags |= (NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION);
        hitboxEnemy->flags |= ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER;
        hitboxNpc->pos.x = NPC_DISPOSE_POS_X;
        hitboxNpc->pos.y = NPC_DISPOSE_POS_Y;
        hitboxNpc->pos.z = NPC_DISPOSE_POS_Z;
        if (hitboxEnemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
            hitboxEnemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case 0:
            baseEnemy = get_enemy(hitboxEnemy->npcID - 1);
            baseNpc = get_npc_unsafe(baseEnemy->npcID);
            hitboxEnemy->hitboxIsActive = TRUE;
            if (baseEnemy->AI_VAR_ATTACK_STATE == MELEE_HITBOX_STATE_ACTIVE) {
                if (hitboxEnemy->AI_VAR_HITNPC_SOUND != 0) {
                    ai_enemy_play_sound(baseNpc, hitboxEnemy->AI_VAR_HITNPC_SOUND, 0);
                }
                posX = baseNpc->pos.x;
                posZ = baseNpc->pos.z;
                add_vec2D_polar(&posX, &posZ, hitboxEnemy->AI_VAR_HITNPC_DIST, 270.0f - baseNpc->renderYaw);

                hitboxNpc->pos.x = posX;
                hitboxEnemy->unk_10.x = hitboxNpc->pos.x;

                hitboxNpc->pos.y = baseNpc->pos.y + hitboxEnemy->AI_VAR_HITNPC_YOFFSET;
                hitboxEnemy->unk_10.y = hitboxNpc->pos.y;

                hitboxNpc->pos.z = posZ;
                hitboxEnemy->unk_10.z = hitboxNpc->pos.z;

                hitboxNpc->yaw = atan2(hitboxNpc->pos.x, hitboxNpc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
                hitboxEnemy->flags &= ~(ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER);
                hitboxNpc->duration = 0;
                script->functionTemp[0] = 1;
            }
            break;
        case 1:
            baseEnemy = get_enemy(hitboxEnemy->npcID - 1);
            get_npc_unsafe(baseEnemy->npcID);
            hitboxNpc->duration++;
            if (hitboxNpc->duration >= hitboxEnemy->AI_VAR_HITNPC_4) {
                hitboxEnemy->hitboxIsActive = FALSE;
            }
            if (baseEnemy->AI_VAR_ATTACK_STATE == MELEE_HITBOX_STATE_POST) {
                hitboxEnemy->flags |= ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER;
                hitboxNpc->pos.x = NPC_DISPOSE_POS_X;
                hitboxNpc->pos.y = NPC_DISPOSE_POS_Y;
                hitboxNpc->pos.z = NPC_DISPOSE_POS_Z;
                hitboxEnemy->hitboxIsActive = TRUE;
                script->functionTemp[0] = 0;
            }
            break;
    }

    #ifdef _DEAD_H_
    if (hitboxEnemy->hitboxIsActive != 0) {
        hitboxEnemy->unk_114 = 7.0f;
        hitboxEnemy->unk_118 = 1.0f;
    }
    #endif

    return ApiStatus_BLOCK;
}

#endif
