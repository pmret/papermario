#include "common.h"
#include "world/partners.h"
#include "effects.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/player.h"

#define NAMESPACE world_bombette

BSS b32 N(PlayerWasFacingLeft);
BSS b32 N(PlayingFuseSound);
BSS b32 N(IsBlasting); // TRUE for 3 frames while using ability
BSS b32 N(LockingPlayerInput);
BSS b32 N(MaintainPosAfterBlast);
BSS b32 N(TriggeredEarlyDetonation);
BSS b32 N(MovementBlocked);
BSS s32 N(D_802BE93C); // unused (padding?)

void entity_try_partner_interaction_trigger(s32 arg0);

void N(blast_affect_entities)(Npc* npc) {
    f32 x, y, z;
    f32 angle = 0.0f;

    // first pass looking for entities
    while (angle < 360.0f) {
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;
        if (npc_test_move_taller_with_slipping(COLLISION_ONLY_ENTITIES,
            &x, &y, &z, 30.0f, clamp_angle(npc->yaw + angle),
            npc->collisionHeight, npc->collisionDiameter)
        ) {
            break;
        }
        angle += 45.0f;
    }

    // second pass looking for everything but entities
    if (angle >= 360.0f) {
        angle = 0.0f;

        while (angle < 360.0f) {
            x = npc->pos.x;
            y = npc->pos.y;
            z = npc->pos.z;
            if (npc_test_move_taller_with_slipping(COLLISION_IGNORE_ENTITIES,
                &x, &y, &z, 30.0f, clamp_angle(npc->yaw + angle),
                npc->collisionHeight, npc->collisionDiameter)
            ) {
                break;
            }
            angle += 45.0f;
        }

        if (angle >= 360.0f) {
            return;
        }
    }

    // handle entity interaction if there was a collision
    if (NpcHitQueryColliderID >= 0 && (NpcHitQueryColliderID & COLLISION_WITH_ENTITY_BIT)) {
        entity_try_partner_interaction_trigger(NpcHitQueryColliderID & ~COLLISION_WITH_ENTITY_BIT);
    }
}

void N(init)(Npc* bombette) {
    bombette->collisionHeight = 28;
    bombette->collisionDiameter = 24;
    N(IsBlasting) = FALSE;
    N(PlayingFuseSound) = FALSE;
}

API_CALLABLE(N(TakeOut)) {
    Npc* bombette = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(bombette);
    }

    if (partner_get_out(bombette)) {
        return ApiStatus_DONE1;
     } else {
        return ApiStatus_BLOCK;
     }
}

EvtScript EVS_WorldBombette_TakeOut = {
    Call(N(TakeOut))
    Return
    End
};

BSS TweesterPhysics N(TweesterPhysicsData);
TweesterPhysics* N(TweesterPhysicsPtr) = &N(TweesterPhysicsData);

API_CALLABLE(N(Update)) {
    PlayerData* playerData = &gPlayerData;
    Npc* bombette = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(bombette, 1);
        mem_clear(N(TweesterPhysicsPtr), sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_BOMBETTE]++;
    bombette->flags |= NPC_FLAG_DIRTY_SHADOW;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_walking_update_player_tracking(bombette);
        partner_walking_update_motion(bombette);
        return ApiStatus_BLOCK;
    }

    switch (N(TweesterPhysicsPtr)->state) {
        case TWEESTER_PARTNER_INIT:
            N(TweesterPhysicsPtr)->state++;
            N(TweesterPhysicsPtr)->prevFlags = bombette->flags;
            N(TweesterPhysicsPtr)->radius = fabsf(dist2D(bombette->pos.x, bombette->pos.z,
                                                     entity->pos.x, entity->pos.z));
            N(TweesterPhysicsPtr)->angle = atan2(entity->pos.x, entity->pos.z,
                                              bombette->pos.x, bombette->pos.z);
            N(TweesterPhysicsPtr)->angularVel = 6.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase = 50.0f;
            N(TweesterPhysicsPtr)->countdown = 120;
            bombette->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_FLYING;
            bombette->flags &= ~NPC_FLAG_GRAVITY;
        case TWEESTER_PARTNER_ATTRACT:
            sin_cos_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->angle), &sinAngle, &cosAngle);
            bombette->pos.x = entity->pos.x + (sinAngle * N(TweesterPhysicsPtr)->radius);
            bombette->pos.z = entity->pos.z - (cosAngle * N(TweesterPhysicsPtr)->radius);
            N(TweesterPhysicsPtr)->angle = clamp_angle(N(TweesterPhysicsPtr)->angle - N(TweesterPhysicsPtr)->angularVel);

            if (N(TweesterPhysicsPtr)->radius > 20.0f) {
                N(TweesterPhysicsPtr)->radius--;
            } else if (N(TweesterPhysicsPtr)->radius < 19.0f) {
                N(TweesterPhysicsPtr)->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->liftoffVelPhase)) * 3.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase += 3.0f;

            if (N(TweesterPhysicsPtr)->liftoffVelPhase > 150.0f) {
                N(TweesterPhysicsPtr)->liftoffVelPhase = 150.0f;
            }

            bombette->pos.y += liftoffVelocity;
            bombette->renderYaw = clamp_angle(360.0f - N(TweesterPhysicsPtr)->angle);
            N(TweesterPhysicsPtr)->angularVel += 0.8;

            if (N(TweesterPhysicsPtr)->angularVel > 40.0f) {
                N(TweesterPhysicsPtr)->angularVel = 40.0f;
            }

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state++;
            }
            break;
        case TWEESTER_PARTNER_HOLD:
            bombette->flags = N(TweesterPhysicsPtr)->prevFlags;
            N(TweesterPhysicsPtr)->countdown = 30;
            N(TweesterPhysicsPtr)->state++;
            break;
        case TWEESTER_PARTNER_RELEASE:
            partner_walking_update_player_tracking(bombette);
            partner_walking_update_motion(bombette);

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldBombette_Update = {
    Call(N(Update))
    Return
    End
};

void N(try_cancel_tweester)(Npc* npc) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        npc->flags = N(TweesterPhysicsPtr)->prevFlags;
        N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking(npc);
    }
}

s32 N(can_use_ability)(Npc* npc) {
    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) {
        N(TriggeredEarlyDetonation) = TRUE;
        return FALSE;
    }
    return TRUE;
}

s32 N(can_open_menus)(Npc* npc) {
    return gPartnerStatus.partnerActionState == PARTNER_ACTION_NONE;
}

API_CALLABLE(N(UseAbility)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    Npc* npc = script->owner2.npc;
    u16 temp_ret;
    f32 x, y, z;
    f32 hitDepth;
    f32 temp_f0;
    f32 angleToPlayer;

    #define USE_STATE functionTemp[0]
    enum {
        BLAST_STATE_BEGIN       = 20,
        BLAST_STATE_GATHER      = 21,
        BLAST_STATE_LIFT        = 1,
        BLAST_STATE_DEPLOY      = 2,
        BLAST_STATE_EXPLODE     = 3,
        BLAST_STATE_LIFTOFF     = 4,
        BLAST_STATE_FLY         = 5,
        BLAST_STATE_FALL        = 6,
        BLAST_STATE_CANCEL      = 7,
        BLAST_STATE_FINISH      = 8,
    };

    if (gCurrentEncounter.unk_08 != 0) {
        return ApiStatus_BLOCK;
    }

    if (isInitialCall) {
        N(try_cancel_tweester)(npc);
        script->USE_STATE = BLAST_STATE_BEGIN;
    }

    switch (script->USE_STATE) {
        case BLAST_STATE_BEGIN:
            if ((playerStatus->inputDisabledCount != 0) || (playerStatus->flags & PS_FLAG_JUMPING) || !(npc->flags & NPC_FLAG_GROUNDED)) {
                return ApiStatus_DONE2;
            }
            disable_player_input();
            script->functionTemp[3] = playerStatus->inputDisabledCount;
            N(LockingPlayerInput) = TRUE;
            N(IsBlasting) = FALSE;
            N(MaintainPosAfterBlast) = FALSE;
            N(TriggeredEarlyDetonation) = FALSE;
            npc->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_GRAVITY | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_FLYING);
            partnerStatus->partnerActionState = PARTNER_ACTION_USE;
            partnerStatus->actingPartner = PARTNER_BOMBETTE;
            N(PlayerWasFacingLeft) = partner_force_player_flip_done();
            enable_npc_blur(npc);
            npc->duration = 4;
            npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
            script->USE_STATE = BLAST_STATE_GATHER;
        case BLAST_STATE_GATHER:
            if (playerStatus->actionState == ACTION_STATE_HIT_FIRE || playerStatus->actionState == ACTION_STATE_KNOCKBACK) {
                disable_npc_blur(npc);
                script->USE_STATE = BLAST_STATE_CANCEL;
                break;
            }
            if (playerStatus->flags & PS_FLAG_JUMPING) {
                script->USE_STATE = BLAST_STATE_CANCEL;
                break;
            }
            npc->moveToPos.x = playerStatus->pos.x;
            npc->moveToPos.y = playerStatus->pos.y;
            npc->moveToPos.z = playerStatus->pos.z;
            npc->curAnim = ANIM_WorldBombette_Run;
            add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, 0.0f, playerStatus->targetYaw);
            temp_f0 = clamp_angle(playerStatus->targetYaw + (N(PlayerWasFacingLeft) ? -90.0f : 90.0f));
            add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, playerStatus->colliderDiameter / 4, temp_f0);
            npc->pos.x += (npc->moveToPos.x - npc->pos.x) / npc->duration;
            npc->pos.y += (npc->moveToPos.y - npc->pos.y) / npc->duration;
            npc->pos.z += (npc->moveToPos.z - npc->pos.z) / npc->duration;
            npc->duration--;
            if (npc->duration != 0) {
                break;
            }
            if (script->functionTemp[3] < playerStatus->inputDisabledCount) {
                disable_npc_blur(npc);
                // TODO possible to remove float temp here? should be: evt->USE_STATE = BLAST_STATE_CANCEL
                temp_f0 = 0;
                script->functionTemp[(u8)temp_f0] = BLAST_STATE_CANCEL;
                break;
            }
            npc->pos.x = npc->moveToPos.x;
            npc->pos.y = npc->moveToPos.y;
            npc->pos.z = npc->moveToPos.z;
            disable_npc_blur(npc);
            suggest_player_anim_allow_backward(ANIM_MarioW1_Lift);
            npc->yaw = playerStatus->targetYaw;
            npc->curAnim = ANIM_WorldBombette_Walk;
            script->USE_STATE = BLAST_STATE_LIFT;
            script->functionTemp[1] = 10;
            // fallthrough
        case BLAST_STATE_LIFT:
            if (playerStatus->actionState == ACTION_STATE_HIT_FIRE || playerStatus->actionState == ACTION_STATE_KNOCKBACK) {
                script->USE_STATE = BLAST_STATE_CANCEL;
                break;
            }
            npc->pos.y = playerStatus->pos.y + playerStatus->colliderHeight;
            npc->yaw = playerStatus->targetYaw;
            if (script->functionTemp[1] == 1) {
                suggest_player_anim_allow_backward(ANIM_MarioW1_PlaceItem);
            }
            if (script->functionTemp[1] != 0) {
                script->functionTemp[1]--;
                break;
            }
            sfx_play_sound_at_npc(SOUND_LOOP_BOMBETTE_FUSE, SOUND_SPACE_DEFAULT, NPC_PARTNER);
            N(PlayingFuseSound) = TRUE;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 0.0f, npc->yaw);
            npc->curAnim = ANIM_WorldBombette_WalkLit;
            npc->jumpVel = 0.0f;
            N(MovementBlocked) = FALSE;
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_IGNORE_PLAYER_COLLISION;
            npc->moveSpeed = 1.0f;
            script->USE_STATE = BLAST_STATE_DEPLOY;
            script->functionTemp[1] = 50;
            // fallthrough
        case BLAST_STATE_DEPLOY:
            if ((playerStatus->animFlags & PA_FLAG_INTERRUPT_USE_PARTNER) || (playerStatus->actionState == ACTION_STATE_HIT_FIRE || playerStatus->actionState == ACTION_STATE_KNOCKBACK)) {
                script->USE_STATE = BLAST_STATE_CANCEL;
                break;
            }
            if (script->functionTemp[1] < 45) {
                if (!(npc->flags & NPC_FLAG_COLLDING_WITH_WORLD) && !N(MovementBlocked)) {
                    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                    spawn_surface_effects(npc, SURFACE_INTERACT_WALK);
                } else {
                    N(MovementBlocked) = TRUE;
                }
            }

            // start explosion immediately when touching lava or spikes
            x = npc->pos.x;
            y = npc->pos.y + 14.0f;
            z = npc->pos.z;
            hitDepth = 16.0f;
            if (npc_raycast_down_around(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, &hitDepth, npc->yaw, npc->collisionDiameter)) {
                s32 surfaceType = get_collider_flags(NpcHitQueryColliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                if (surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) {
                    if (playerStatus->actionState == ACTION_STATE_IDLE) {
                        suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                    }
                    npc->curAnim = ANIM_WorldBombette_AboutToExplode;
                    npc->flags &= ~NPC_FLAG_GRAVITY;
                    script->functionTemp[1] = 2;
                    script->USE_STATE = BLAST_STATE_EXPLODE;
                    if (N(LockingPlayerInput)) {
                        N(LockingPlayerInput) = FALSE;
                        enable_player_input();
                    }
                    break;
                }
            }

            // play walking sounds
            if (!(script->functionTemp[1] & 3)) {
                if (gGameStatusPtr->frameCounter & 1) {
                    sfx_play_sound_at_npc(SOUND_STEP_NORMAL1, SOUND_SPACE_DEFAULT, NPC_PARTNER);
                } else {
                    sfx_play_sound_at_npc(SOUND_STEP_NORMAL2, SOUND_SPACE_DEFAULT, NPC_PARTNER);
                }
            }

            // unlock player movement after 40 frames
            if (script->functionTemp[1] == 40) {
                if (playerStatus->actionState == ACTION_STATE_IDLE) {
                    suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                }
                enable_player_input();
                N(LockingPlayerInput) = FALSE;
            }

            npc_do_other_npc_collision(npc);
            if (npc->flags & NPC_FLAG_COLLIDING_WITH_NPC) {
                if (N(LockingPlayerInput)) {
                    N(LockingPlayerInput) = FALSE;
                    enable_player_input();
                }
            } else if (!N(TriggeredEarlyDetonation)) {
                if (script->functionTemp[1] != 0) {
                    script->functionTemp[1]--;
                    break;
                }
            }
            npc->curAnim = ANIM_WorldBombette_AboutToExplode;
            script->functionTemp[1] = 20;
            script->USE_STATE = BLAST_STATE_EXPLODE;
            if (playerStatus->actionState == ACTION_STATE_IDLE) {
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
            }
    }

    switch (script->USE_STATE) {
        case BLAST_STATE_EXPLODE:
            if (script->functionTemp[1] != 0) {
                script->functionTemp[1]--;
                break;
            }
            if (N(PlayingFuseSound)) {
                N(PlayingFuseSound) = FALSE;
                sfx_stop_sound(SOUND_LOOP_BOMBETTE_FUSE);
            }
            fx_explosion(gPlayerData.partners[gPlayerData.curPartner].level, npc->pos.x, npc->pos.y + (npc->collisionHeight * 0.5f), npc->pos.z);
            switch (gPlayerData.partners[gPlayerData.curPartner].level) {
                case PARTNER_RANK_NORMAL:
                    sfx_play_sound_at_npc(SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT, NPC_PARTNER);
                    break;
                case PARTNER_RANK_SUPER:
                    sfx_play_sound_at_npc(SOUND_BOMBETTE_BLAST_LV2, SOUND_SPACE_DEFAULT, NPC_PARTNER);
                    break;
                case PARTNER_RANK_ULTRA:
                    sfx_play_sound_at_npc(SOUND_BOMBETTE_BLAST_LV3, SOUND_SPACE_DEFAULT, NPC_PARTNER);
                    break;
            }
            exec_ShakeCam1(0, 0, 20);
            spawn_surface_effects(npc, SURFACE_INTERACT_LAND);
            collisionStatus->bombetteExploded = 0;
            collisionStatus->bombetteExplosionPos.x = npc->pos.x;
            collisionStatus->bombetteExplosionPos.y = npc->pos.y;
            collisionStatus->bombetteExplosionPos.z = npc->pos.z;
            N(blast_affect_entities)(npc);
            N(IsBlasting) = TRUE;
            partnerStatus->partnerActionState = PARTNER_ACTION_BOMBETTE_2;
            script->functionTemp[1] = 3;
            script->USE_STATE++;
            break;
        case BLAST_STATE_LIFTOFF:
            if (script->functionTemp[1] != 0) {
                script->functionTemp[1]--;
                break;
            }
            partnerStatus->partnerActionState = PARTNER_ACTION_BOMBETTE_3;
            N(IsBlasting) = FALSE;
            npc->jumpVel = ((playerStatus->pos.y - npc->pos.y) / 20.0f) + 30.0;
            npc->moveSpeed = 0.8f;
            npc->yaw = rand_int(360);
            npc->jumpScale = 0.8f;
            npc->pos.y += 10.0f;
            npc->moveToPos.y = npc->pos.y;
            collisionStatus->bombetteExploded = -1;
            collisionStatus->bombetteExplosionPos.x = npc->pos.x;
            collisionStatus->bombetteExplosionPos.y = npc->pos.y;
            collisionStatus->bombetteExplosionPos.z = npc->pos.z;
            npc->curAnim = ANIM_WorldBombette_Aftermath;
            angleToPlayer = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            if (!(get_clamped_angle_diff(camera->curYaw, angleToPlayer) < 0.0f)) {
                script->functionTemp[2] = 1;
            } else {
                script->functionTemp[2] = -1;
            }
            script->functionTemp[1] = 10;
            script->USE_STATE = BLAST_STATE_FLY;
            break;
        case BLAST_STATE_FLY:
            npc->pos.y += npc->jumpVel;
            npc->jumpVel -= npc->jumpScale;
            npc->rot.z -= (script->functionTemp[2] * 79) / 2;
            npc->rot.x -= (script->functionTemp[2] * 67) / 2;
            if (script->functionTemp[1] != 0) {
                script->functionTemp[1]--;
                break;
            }
            if (!N(MaintainPosAfterBlast)) {
                npc->pos.x = playerStatus->pos.x;
                npc->pos.z = playerStatus->pos.z;
            }
            npc->yaw = clamp_angle(gCameras[CAM_DEFAULT].curYaw + playerStatus->spriteFacingAngle);
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 10.0f, npc->yaw);
            npc->jumpVel = 0.0f;
            npc->curAnim = ANIM_WorldBombette_Aftermath;
            npc->flags |= NPC_FLAG_JUMPING;
            script->USE_STATE = BLAST_STATE_FALL;
            break;
        case BLAST_STATE_FALL:
            if (npc->pos.y + 10.0f < playerStatus->pos.y + playerStatus->colliderHeight) {
                npc->flags &= ~NPC_FLAG_JUMPING;
                if (fabsf(playerStatus->pos.y - npc->pos.y) < 500.0) {
                    script->USE_STATE = BLAST_STATE_FINISH;
                    break;
                } else if (npc_try_snap_to_ground(npc, npc->jumpVel)) {
                    script->USE_STATE = BLAST_STATE_CANCEL;
                    break;
                }
            }
            npc->pos.y += npc->jumpVel;
            npc->jumpVel -= npc->jumpScale;
            if (npc->jumpVel < -8.0) {
                npc->jumpVel = -8.0f;
            }
            npc->rot.z -= (script->functionTemp[2] * 79) / 2;
            npc->rot.x -= (script->functionTemp[2] * 67) / 2;
            break;
    }

    //TODO clean up this return
    temp_ret = ApiStatus_BLOCK;
    switch (script->USE_STATE) {
        case BLAST_STATE_CANCEL:
            if (playerStatus->actionState == ACTION_STATE_IDLE) {
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
            }
            if (N(LockingPlayerInput)) {
                N(LockingPlayerInput) = FALSE;
                enable_player_input();
            }
            partnerStatus->partnerActionState = ACTION_STATE_IDLE;
            partnerStatus->actingPartner = PARTNER_NONE;
            npc->jumpVel = 0.0f;
            N(IsBlasting) = FALSE;
            N(TriggeredEarlyDetonation) = FALSE;
            npc->pos.y = playerStatus->pos.y;
            npc->rot.x = 0.0f;
            npc->rot.z = 0.0f;
            npc->curAnim = ANIM_WorldBombette_Idle;
            partner_clear_player_tracking(npc);
            if (N(PlayingFuseSound)) {
                N(PlayingFuseSound) = FALSE;
                sfx_stop_sound(SOUND_LOOP_BOMBETTE_FUSE);
            }
            temp_ret = ApiStatus_DONE2;
            return temp_ret;
        case BLAST_STATE_FINISH:
            if (N(LockingPlayerInput)) {
                N(LockingPlayerInput) = FALSE;
                enable_player_input();
            }
            partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
            partnerStatus->actingPartner = PARTNER_NONE;
            npc->jumpVel = 0.0f;
            npc->pos.y = playerStatus->pos.y;
            npc->rot.x = 0.0f;
            npc->rot.z = 0.0f;
            npc->curAnim = ANIM_WorldBombette_Idle;
            npc->pos.x = playerStatus->pos.x;
            npc->pos.y = playerStatus->pos.y;
            npc->pos.z = playerStatus->pos.z;
            N(IsBlasting) = FALSE;
            N(TriggeredEarlyDetonation) = FALSE;
            if (!N(PlayerWasFacingLeft)) {
                add_vec2D_polar(&npc->pos.x, &npc->pos.z, playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw + 90.0f));
            } else {
                add_vec2D_polar(&npc->pos.x, &npc->pos.z, playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw - 90.0f));
            }
            npc->jumpVel = 0.0f;
            partner_clear_player_tracking(npc);
            temp_ret = ApiStatus_DONE2;
            if (N(PlayingFuseSound)) {
                N(PlayingFuseSound) = FALSE;
                sfx_stop_sound(SOUND_LOOP_BOMBETTE_FUSE);
            }
            temp_ret = ApiStatus_DONE2;
            break;
        default:
            return ApiStatus_BLOCK;
    }

    return temp_ret;
}

EvtScript EVS_WorldBombette_UseAbility = {
    Call(N(UseAbility))
    Return
    End
};

API_CALLABLE(N(PutAway)) {
    Npc* bombette = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(bombette);
    }

    if (partner_put_away(bombette)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldBombette_PutAway = {
    Call(N(PutAway))
    Return
    End
};

s32 N(test_first_strike)(Npc* bombette, Npc* enemy) {
    f32 bombetteX, bombetteZ;
    f32 enemyX, enemyZ;
    f32 x, y, z, dist;
    f32 angle, distance;
    f32 enemyRadius, blastRadius;
    s32 hitResult;
    s32 enemyHit;

    if (!N(IsBlasting)) {
        return FALSE;
    }

    enemyX = enemy->pos.x;
    enemyZ = enemy->pos.z;

    bombetteX = bombette->pos.x;
    bombetteZ = bombette->pos.z;

    x = enemyX - bombetteX;
    y = enemy->pos.y + (f32)(enemy->collisionHeight * 0.5) - bombette->pos.y;
    z = enemyZ - bombetteZ;

    enemyRadius = enemy->collisionDiameter * 0.55;
    blastRadius = 35.0f;
    dist = sqrtf(SQ(x) + SQ(y) + SQ(z));
    enemyHit = FALSE;

    if (dist < (enemyRadius + blastRadius)) {
        enemyHit = TRUE;
    }

    angle = atan2(enemyX, enemyZ, bombetteX, bombetteZ);
    distance = dist2D(enemyX, enemyZ, bombetteX, bombetteZ);

    // check whether the enemy is protected from the explosion
    x = bombette->pos.x;
    y = bombette->pos.y;
    z = bombette->pos.z;
    hitResult = npc_test_move_taller_with_slipping(0, &x, &y, &z, distance, angle, 35.0f, 2.0f);

    if (hitResult) {
        return FALSE;
    }

    return enemyHit;
}

void N(pre_battle)(Npc* bombette) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE) {
        if (N(LockingPlayerInput)) {
            enable_player_input();
        }

        N(IsBlasting) = FALSE;
        playerStatus->flags &= ~PS_FLAG_JUMPING;
        bombette->jumpVel = 0.0f;
        bombette->flags &= ~NPC_FLAG_JUMPING;

        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(bombette);

        partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
        partnerStatus->actingPartner = 0;

        bombette->pos.x = playerStatus->pos.x;
        bombette->pos.y = playerStatus->pos.y;
        bombette->pos.z = playerStatus->pos.z;

        if (!N(PlayerWasFacingLeft)) {
            add_vec2D_polar(&bombette->pos.x, &bombette->pos.z,
                            playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw + 90.0f));
        } else {
            add_vec2D_polar(&bombette->pos.x, &bombette->pos.z,
                            playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw - 90.0f));
        }

        bombette->jumpVel = 0.0f;
        bombette->pos.y = playerStatus->pos.y;
        bombette->rot.x = 0.0f;
        bombette->rot.z = 0.0f;
        bombette->curAnim = ANIM_WorldBombette_Idle;
        partner_clear_player_tracking(bombette);
        disable_npc_blur(bombette);

        if (N(PlayingFuseSound)) {
            N(PlayingFuseSound) = FALSE;
            sfx_stop_sound(SOUND_LOOP_BOMBETTE_FUSE);
        }
    }
}
