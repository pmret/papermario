#ifndef _AI_PROJECTILE_HITBOX_INC_
#define _AI_PROJECTILE_HITBOX_INC_ 0

#include "common.h"
#include "npc.h"
#include "effects.h"

s32 N(ProjectileHitbox_GetUsableProjectileID)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[gCurrentCamID];
    Npc* npc = get_npc_unsafe(enemy->npcID);
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args++);
    f32 facingAngle;
    f32 angleToPlayer;
    f32 deltaAngle;
    s32 i;

    if (ai_check_player_dist(enemy, 0, aiSettings->chaseRadius, aiSettings->chaseOffsetDist)) {
        if (clamp_angle(get_clamped_angle_diff(camera->curYaw, npc->yaw)) < 180.0) {
            facingAngle = 90.0f;
        } else {
            facingAngle = 270.0f;
        }

        angleToPlayer = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        deltaAngle = get_clamped_angle_diff(facingAngle, angleToPlayer);
        if (fabsf(deltaAngle) > 75.0 || (2.0 * npc->collisionHeight <= fabsf(npc->pos.y - gPlayerStatusPtr->pos.y))) {
           return -1;
        }
        if (gPartnerStatus.actingPartner == PARTNER_BOW) {
            return -1;
        }
        if (gPartnerStatus.actingPartner == PARTNER_SUSHIE) {
            return -1;
        }

        // choose the first idle projectile hitbox
        for (i = 0; i < enemy->AI_PROJECTILE_AMMO_COUNT; i++) {
            s32 projectileNpcID = enemy->npcID + i + 1;
            Enemy* projectileEnemy = get_enemy(projectileNpcID);

            get_npc_unsafe(projectileNpcID);

            if (projectileEnemy->VAR_PROJECTILE_HITBOX_STATE == 0) {
                return projectileNpcID;
            }
        }
    }
    return -1;
}

void N(UnkNpcAIFunc48)(Evt* script, f32 arg1, f32 arg2, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (basic_ai_check_player_dist(territory, enemy, arg1, arg2, 1) == 0) {
        EffectInstance* sp28;

        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &sp28);
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->duration = 20;
        script->functionTemp[0] = 33;
    } else {
        s32 npcID = N(ProjectileHitbox_GetUsableProjectileID)(script);

        if (npcID != NPC_SELF && get_enemy(npcID)->varTable[0] == 0 && npc->turnAroundYawAdjustment == 0) {
            npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_PRE];
            npc->duration = enemy->varTable[1];
            script->functionTemp[0] = 30;
        }
    }
}

void N(ProjectileHitbox_30)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 npcID;

    npc->duration--;
    if (npc->duration <= 0) {
        npcID = N(ProjectileHitbox_GetUsableProjectileID)(script);
        if (npcID < 0) {
            EffectInstance* emoteTemp;

            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
            npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        } else {
            Enemy* hitboxEnemy;

            npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_HIT];
            hitboxEnemy = get_enemy(npcID);
            hitboxEnemy->varTable[4] = enemy->npcID;
            hitboxEnemy->varTable[0] = 1;
        }
        npc->duration = enemy->varTable[2];
        script->functionTemp[0] = AI_STATE_PROJECTILE_HITBOX_33;
    }
}

void N(ProjectileHitbox_31)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;

    get_npc_unsafe(enemy->npcID)->duration = enemy->varTable[2];
    script->functionTemp[0] = AI_STATE_PROJECTILE_HITBOX_33;
}

void N(ProjectileHitbox_32)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Enemy* enemy2 = get_enemy(enemy->npcID + 1);
    Npc* npc2 = get_npc_unsafe(enemy2->npcID);

    npc->yaw = atan2(npc->pos.x, npc->pos.z, npc2->pos.x, npc2->pos.z);
    if (enemy2->varTable[0] == 0) {
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->duration = enemy->varTable[2];
        script->functionTemp[0] = AI_STATE_PROJECTILE_HITBOX_33;
    }
}

// TODO same as ParatroopaAI_Reset, but removes the extra args since it affects codegen...?
void N(ProjectileHitbox_33)(Evt* script) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = AI_STATE_WANDER_INIT;
    }
}

API_CALLABLE(N(ProjectileAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    s32 phi_s6 = 0;
    f32 x, y, z;
    f32 hitDepth;
    Npc* npc;
    Npc* npc2;
    MobileAISettings* aiSettings;
    u32 vt0;

    if (get_enemy_safe(enemy->npcID) != nullptr) {
        if (enemy->varTable[0] != 5) {
            aiSettings = (MobileAISettings*)evt_get_variable(script, *args++);
            npc = get_npc_unsafe(enemy->npcID);

            if (enemy->varTable[1] & 2) {
                npc->verticalRenderOffset = npc->collisionHeight / 2;
            }

            if (isInitialCall || (enemy->aiFlags & AI_FLAG_SUSPEND)) {
                script->functionTemp[0] = 0;
                npc->duration = 0;
                npc->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_INVISIBLE;
                disable_npc_shadow(npc);
                npc->flags &= ~NPC_FLAG_JUMPING;
                enemy->varTable[0] = 0;
                enemy->flags |= ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_HAMMER |
                                ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN |
                                ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_PROJECTILE;
                if (enemy->aiFlags & AI_FLAG_SUSPEND) {
                    enemy->aiFlags &= ~AI_FLAG_SUSPEND;
                }
            }

            switch (script->functionTemp[0]) {
                default:
                    return 0;
                case 0:
                    npc->flags |= NPC_FLAG_INVISIBLE;
                    disable_npc_shadow(npc);
                    enemy->varTable[0] = 0;
                    script->functionTemp[0] = 1;
                    // fallthrough
                case 1:
                    vt0 = enemy->varTable[0];

                    if (enemy->varTable[0] == 1) {
                        enemy->varTable[0] = 2;
                        npc2 = get_npc_unsafe(enemy->varTable[4]);
                        npc->pos.x = npc2->pos.x;
                        npc->pos.z = npc2->pos.z;
                        add_vec2D_polar(&npc->pos.x, &npc->pos.z, enemy->varTable[3], 270.0f - npc2->renderYaw);
                        npc->pos.y = npc2->pos.y + enemy->varTable[2];
                        enemy->hitboxIsActive = vt0;
                        enemy->unk_10.x = npc->pos.x;
                        enemy->unk_10.y = npc->pos.y;
                        enemy->unk_10.z = npc->pos.z;
                        npc->rot.x = 0.0f;
                        npc->rot.y = 0.0f;
                        npc->rot.z = 0.0f;
                        npc->moveSpeed = aiSettings->moveSpeed;
                        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
                        npc->jumpVel = aiSettings->alertRadius;
                        npc->jumpScale = aiSettings->alertOffsetDist;
                        npc->moveToPos.y = npc2->pos.y;
                        npc->flags &= ~NPC_FLAG_INVISIBLE;
                        enable_npc_shadow(npc);
                        npc->flags |= NPC_FLAG_JUMPING;
                        enemy->flags &= ~(ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_HAMMER |
                                          ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_TOUCH);
                        npc->duration = 90;
                        script->functionTemp[0] = 2;
                        break;
                    }
                    return 0;
                case 2:
                    break;
            }

            x = npc->pos.x;
            y = npc->pos.y + (npc->collisionHeight * 0.5);
            z = npc->pos.z;
            if (npc_test_move_taller_with_slipping(
                0, &x, &y, &z, npc->moveSpeed, npc->yaw, npc->collisionDiameter, npc->collisionHeight) != 0)
            {
                phi_s6 = 1;
            }

            x = npc->pos.x;
            y = npc->pos.y;
            z = npc->pos.z;
            hitDepth = 1000.0f;
            if ((npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &hitDepth) != 0) &&
                (hitDepth < fabsf(npc->jumpVel)) &&
                (fabsf(y - npc->moveToPos.y) < 20.0))
            {
                npc->pos.y = y;
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                phi_s6 = 10;
            }

            if (hitDepth < 1.0) {
                phi_s6 = 11;
            }
            npc->duration--;
            if (npc->duration <= 0) {
                phi_s6 = 20;
            }

            if (phi_s6 == 0) {
                if (enemy->varTable[1] & 1) {
                    npc->rot.z += 40.0;
                }
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                npc->pos.y += npc->jumpVel;
                npc->jumpVel -= npc->jumpScale;
            } else {
                fx_walking_dust(2, npc->pos.x, npc->pos.y, npc->pos.z, 0, 0);
                enemy->varTable[0] = 0;
                npc->pos.x = NPC_DISPOSE_POS_X;
                npc->pos.y = NPC_DISPOSE_POS_Y;
                npc->pos.z = NPC_DISPOSE_POS_Z;
                npc->jumpVel = 0.0f;
                npc->flags |= NPC_FLAG_INVISIBLE;
                disable_npc_shadow(npc);
                npc->flags &= ~NPC_FLAG_JUMPING;
                enemy->flags |= ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_HAMMER |
                                ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_TOUCH;
                script->functionTemp[0] = 0;
            }
        }
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(ProjectileAI_Reflect)) {
    Enemy* enemy = script->owner1.enemy;
    Camera* camera = &gCameras[gCurrentCamID];
    s32 phi_s4 = 0;
    Npc* npc;
    f32 x, y, z;
    f32 hitDepth;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f22;
    f32 yaw;
    s32 cond;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (get_enemy_safe(enemy->npcID) == nullptr) {
        evt_set_variable(script, LVar0, 0);
        return ApiStatus_DONE2;
    }
    if (enemy->varTable[0] == 5) {
        evt_set_variable(script, LVar0, 0);
        return ApiStatus_DONE2;
    }
    if (get_enemy_safe(enemy->npcID) == nullptr) {
        evt_set_variable(script, LVar0, 0);
        return ApiStatus_DONE2;
    }

    npc = get_npc_unsafe(enemy->npcID);
    switch (script->functionTemp[0]) {
        case 0:
            fx_walking_dust(2, npc->pos.x, npc->pos.y, npc->pos.z, 0.0f, 0.0f);
            yaw = clamp_angle(camera->curYaw);
            temp_f20_2 = clamp_angle(yaw + 180.0);
            temp_f22 = clamp_angle(yaw + 90.0);
            temp_f20_3 = clamp_angle(temp_f20_2 + 90.0);
            if (clamp_angle(get_clamped_angle_diff(camera->curYaw, gPlayerStatusPtr->curYaw)) < 180.0) {
                npc->yaw = temp_f22;
            } else {
                npc->yaw = temp_f20_3;
            }
            npc->duration = 30;
            npc->jumpVel = 10.0f;
            npc->jumpScale = 0.9f;
            npc->moveSpeed *= 1.2;
            script->functionTemp[0] = 1;
            // fallthrough
        case 1:
            x = npc->pos.x;
            y = npc->pos.y;
            z = npc->pos.z;
            if (npc_test_move_simple_with_slipping(0, &x, &y, &z, npc->moveSpeed, npc->yaw, npc->collisionDiameter,
                npc->collisionHeight) == 0)
            {
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            } else {
                phi_s4 = 1;
            }

            cond = false;
            if (npc->jumpVel < 0.0) {
                x = npc->pos.x;
                y = npc->pos.y + 13.0;
                z = npc->pos.z;
                hitDepth = fabsf(npc->jumpVel) + 16.0;
                if ((npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &hitDepth) != 0) &&
                    (hitDepth <= (fabsf(npc->jumpVel) + 13.0)))
                {
                    cond = true;
                }
            }

            if (!cond) {
                npc->pos.y += npc->jumpVel;
                npc->jumpVel -= npc->jumpScale;
            } else {
                phi_s4 = 10;
            }

            npc->duration--;
            if (npc->duration <= 0) {
                phi_s4 = 11;
            }

            if (phi_s4 != 0) {
                fx_walking_dust(2, npc->pos.x, npc->pos.y, npc->pos.z, 0, 0);
                enemy->varTable[0] = 0;
                npc->pos.x = NPC_DISPOSE_POS_X;
                npc->pos.y = NPC_DISPOSE_POS_Y;
                npc->pos.z = NPC_DISPOSE_POS_Z;
                npc->flags |= NPC_FLAG_INVISIBLE;
                disable_npc_shadow(npc);
                npc->flags &= ~NPC_FLAG_JUMPING;
                enemy->flags |= ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_HAMMER |
                                ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_TOUCH;
                script->functionTemp[0] = 0;
                evt_set_variable(script, LVar0, 1);
                return ApiStatus_DONE2;
            }
            if (enemy->varTable[1] & 1) {
                npc->rot.z += 60.0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

#endif
