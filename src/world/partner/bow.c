#include "common.h"
#include "../partners.h"
#include "npc.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/player.h"

#define NAMESPACE world_bow

BSS b32 N(IsHiding);
BSS b32 N(LockingPlayerInput);
BSS TweesterPhysics N(TweesterPhysicsData);
BSS s32 N(OuttaSightPosX);
BSS s32 N(OuttaSightPosY);
BSS s32 N(OuttaSightPosZ);

void N(end_outta_sight_cleanup)(Npc* partner);
s32 N(check_for_treadmill_overlaps)(void);

void N(init)(Npc* bow) {
    bow->collisionHeight = 26;
    bow->collisionDiameter = 24;
    bow->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    N(LockingPlayerInput) = FALSE;
    N(IsHiding) = FALSE;
}

API_CALLABLE(N(TakeOut)) {
    Npc* bow = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(bow);
    }

    if (partner_get_out(bow)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldBow_TakeOut = {
    EVT_CALL(N(TakeOut))
    EVT_RETURN
    EVT_END
};

TweesterPhysics* N(TweesterPhysicsPtr) = &N(TweesterPhysicsData);

API_CALLABLE(N(Update)) {
    PlayerData* playerData = &gPlayerData;
    Npc* bow = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_flying_enable(bow, 1);
        mem_clear(N(TweesterPhysicsPtr), sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    entity = TweesterTouchingPartner;
    playerData->partnerUsedTime[PARTNER_BOW]++;

    if (entity == NULL) {
        partner_flying_update_player_tracking(bow);
        partner_flying_update_motion(bow);
        return ApiStatus_BLOCK;
    }

    switch (N(TweesterPhysicsPtr)->state){
        case TWEESTER_PARTNER_INIT:
            N(TweesterPhysicsPtr)->state++;
            N(TweesterPhysicsPtr)->prevFlags = bow->flags;
            N(TweesterPhysicsPtr)->radius = fabsf(dist2D(bow->pos.x, bow->pos.z, entity->pos.x, entity->pos.z));
            N(TweesterPhysicsPtr)->angle = atan2(entity->pos.x, entity->pos.z, bow->pos.x, bow->pos.z);
            N(TweesterPhysicsPtr)->angularVel = 6.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase = 50.0f;
            N(TweesterPhysicsPtr)->countdown = 120;
            bow->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_8;
            bow->flags &= ~NPC_FLAG_GRAVITY;
        case TWEESTER_PARTNER_ATTRACT:
            sin_cos_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->angle), &sinAngle, &cosAngle);
            bow->pos.x = entity->pos.x + (sinAngle * N(TweesterPhysicsPtr)->radius);
            bow->pos.z = entity->pos.z - (cosAngle * N(TweesterPhysicsPtr)->radius);
            N(TweesterPhysicsPtr)->angle = clamp_angle(N(TweesterPhysicsPtr)->angle - N(TweesterPhysicsPtr)->angularVel);
            if (N(TweesterPhysicsPtr)->radius > 20.0f) {
                N(TweesterPhysicsPtr)->radius -= 1.0f;
            } else if (N(TweesterPhysicsPtr)->radius < 19.0f) {
                N(TweesterPhysicsPtr)->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->liftoffVelPhase)) * 3.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase += 3.0f;

            if (N(TweesterPhysicsPtr)->liftoffVelPhase > 150.0f) {
                N(TweesterPhysicsPtr)->liftoffVelPhase = 150.0f;
            }

            bow->pos.y += liftoffVelocity;
            bow->renderYaw = clamp_angle(360.0f - N(TweesterPhysicsPtr)->angle);
            N(TweesterPhysicsPtr)->angularVel += 0.8;

            if (N(TweesterPhysicsPtr)->angularVel > 40.0f) {
                N(TweesterPhysicsPtr)->angularVel = 40.0f;
            }
            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state++;
            }
            break;
        case TWEESTER_PARTNER_HOLD:
            bow->flags = N(TweesterPhysicsPtr)->prevFlags;
            N(TweesterPhysicsPtr)->countdown = 30;
            N(TweesterPhysicsPtr)->state++;
            break;
        case TWEESTER_PARTNER_RELEASE:
            partner_flying_update_player_tracking(bow);
            partner_flying_update_motion(bow);

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldBow_Update = {
    EVT_CALL(N(Update))
    EVT_RETURN
    EVT_END
};

void N(try_cancel_tweester)(Npc* bow) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        bow->flags = N(TweesterPhysicsPtr)->prevFlags;
        N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking(bow);
    }
}

// check whether the player would collide with an obstacle while on a treadmill in AREA_OMO
s32 N(check_for_treadmill_overlaps)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 yaw;

    if (gGameStatusPtr->areaID != AREA_OMO) {
        return NO_COLLIDER;
    }

    if (playerStatus->pushVel.x == 0.0f && playerStatus->pushVel.z == 0.0f) {
        return NO_COLLIDER;
    }

    yaw = atan2(0.0f, 0.0f, playerStatus->pushVel.x, playerStatus->pushVel.z);
    x = playerStatus->pos.x;
    y = playerStatus->pos.y + (playerStatus->colliderHeight * 0.5f);
    z = playerStatus->pos.z;

    add_vec2D_polar(&x, &z, playerStatus->colliderDiameter * 0.5f, clamp_angle(yaw + 180.0f));
    return player_test_lateral_overlap(0, playerStatus, &x, &y, &z, playerStatus->colliderDiameter, yaw);
}

API_CALLABLE(N(UseAbility)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Npc* bow = script->owner2.npc;
    f32 stickInputMag;

    #define USE_STATE functionTemp[0]
    enum {
        // first two states lock input for a few frames, during which the ability can be canceled
        OUTTA_SIGHT_INIT        = 40,
        OUTTA_SIGHT_DELAY       = 41,
        OUTTA_SIGHT_BEGIN       = 20,
        OUTTA_SIGHT_GATHER      = 21, // move to player
        OUTTA_SIGHT_VANISH      = 1,  // hide
        OUTTA_SIGHT_IDLE        = 2,  // remain hidden
        OUTTA_SIGHT_REAPPEAR    = 3,
    };

    if (isInitialCall) {
        N(try_cancel_tweester)(bow);
        if (playerStatus->animFlags & PA_FLAG_CHANGING_MAP || !func_800EA52C(PARTNER_BOW)) {
            return ApiStatus_DONE2;
        }
        if (playerStatus->animFlags & PA_FLAG_PARTNER_USAGE_FORCED) {
            playerStatus->animFlags &= ~PA_FLAG_PARTNER_USAGE_FORCED;
            script->functionTemp[2] = disable_player_input();
            N(LockingPlayerInput) = TRUE;
            script->USE_STATE = OUTTA_SIGHT_BEGIN;
        } else {
            script->USE_STATE = OUTTA_SIGHT_INIT;
        }
    }

    switch (script->USE_STATE) {
        case OUTTA_SIGHT_INIT:
            if (playerStatus->inputDisabledCount != 0) {
                return ApiStatus_DONE2;
            }

            playerStatus->flags |= PS_FLAG_PAUSE_DISABLED;
            script->functionTemp[1] = 3;
            script->functionTemp[2] = disable_player_input();
            N(LockingPlayerInput) = TRUE;
            script->USE_STATE++; // OUTTA_SIGHT_DELAY
            break;
        case OUTTA_SIGHT_DELAY:
            if ((!func_800EA52C(PARTNER_BOW) || is_starting_conversation())
                && script->functionTemp[2] < playerStatus->inputDisabledCount
                && N(LockingPlayerInput)
            ) {
                enable_player_input();
                N(LockingPlayerInput) = FALSE;
                playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                return ApiStatus_DONE2;
            }
            script->functionTemp[1]--;
            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] < playerStatus->inputDisabledCount) {
                    if (N(LockingPlayerInput)) {
                        enable_player_input();
                        N(LockingPlayerInput) = FALSE;
                    }
                    playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                    return ApiStatus_DONE2;
                }
                script->USE_STATE = OUTTA_SIGHT_BEGIN;
            }
            break;
    }

    switch (script->USE_STATE) {
        case OUTTA_SIGHT_BEGIN:
            if (playerStatus->flags & PS_FLAG_HIT_FIRE) {
                playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                if (N(LockingPlayerInput)) {
                    enable_player_input();
                    N(LockingPlayerInput) = FALSE;
                }
                return ApiStatus_DONE2;
            }
            if (script->functionTemp[2] != 0) {
                N(LockingPlayerInput) = TRUE;
            }

            N(IsHiding) = TRUE;
            bow->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_GRAVITY);
            partnerStatus->partnerActionState = 1;
            partnerStatus->actingPartner = 9;
            playerStatus->flags |= PS_FLAG_HAZARD_INVINCIBILITY;
            partner_force_player_flip_done();
            bow->moveToPos.x = playerStatus->pos.x;
            bow->moveToPos.y = playerStatus->pos.y + (playerStatus->colliderHeight * 0.5f);
            bow->moveToPos.z = playerStatus->pos.z;
            bow->curAnim = ANIM_WorldBow_Walk;
            bow->yaw = playerStatus->targetYaw;
            add_vec2D_polar(&bow->moveToPos.x, &bow->moveToPos.z, -2.0f, gCameras[gCurrentCameraID].curYaw);
            add_vec2D_polar(&bow->moveToPos.x, &bow->moveToPos.z, playerStatus->colliderDiameter * 0.5f, bow->yaw);
            bow->duration = 5;
            bow->yaw = atan2(bow->pos.x, bow->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            set_action_state(ACTION_STATE_RIDE);
            suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
            script->USE_STATE++; // OUTTA_SIGHT_GATHER
            break;

        case OUTTA_SIGHT_GATHER:
            if (collisionStatus->curFloor >= 0 && !(playerStatus->animFlags & PA_FLAG_CHANGING_MAP)) {
                bow->moveToPos.x = playerStatus->pos.x;
                bow->moveToPos.y = playerStatus->pos.y + (playerStatus->colliderHeight * 0.5f);
                bow->moveToPos.z = playerStatus->pos.z;
                bow->pos.x += ((bow->moveToPos.x - bow->pos.x) / bow->duration);
                bow->pos.y += ((bow->moveToPos.y - bow->pos.y) / bow->duration);
                bow->pos.z += ((bow->moveToPos.z - bow->pos.z) / bow->duration);
                N(OuttaSightPosX) = playerStatus->pos.x - bow->pos.x;
                N(OuttaSightPosY) = playerStatus->pos.y - bow->pos.y;
                N(OuttaSightPosZ) = playerStatus->pos.z - bow->pos.z;
                bow->duration--;
                if (bow->duration == 0) {
                    bow->yaw = playerStatus->targetYaw;
                    npc_set_imgfx_params(bow, IMGFX_SET_ALPHA, playerStatus->alpha1, 0, 0, 0, 0);
                    suggest_player_anim_always_forward(ANIM_Mario1_Crouch);
                    sfx_play_sound_at_npc(SOUND_BOW_VANISH, SOUND_SPACE_MODE_0, NPC_PARTNER);
                    script->USE_STATE = OUTTA_SIGHT_VANISH;
                }
                break;
            }
            N(end_outta_sight_cleanup)(bow);
            return ApiStatus_DONE2;

        case OUTTA_SIGHT_VANISH:
            if (collisionStatus->curFloor >= 0) {
                playerStatus->alpha1 -= 8;
                if (playerStatus->alpha1 <= 128) {
                    playerStatus->alpha1 = 128;
                    bow->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
                    script->USE_STATE++; // OUTTA_SIGHT_IDLE
                    playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                    bow->flags |= NPC_FLAG_IGNORE_WORLD_COLLISION;
                }

                get_shadow_by_index(bow->shadowIndex)->alpha = playerStatus->alpha1 >> 1;
                npc_set_imgfx_params(bow, IMGFX_SET_ALPHA, playerStatus->alpha1, 0, 0, 0, 0);
                bow->pos.x = playerStatus->pos.x - N(OuttaSightPosX);
                bow->pos.y = playerStatus->pos.y - N(OuttaSightPosY);
                bow->pos.z = playerStatus->pos.z - N(OuttaSightPosZ);
                break;
            }
            N(end_outta_sight_cleanup)(bow);
            return ApiStatus_DONE2;

        case OUTTA_SIGHT_IDLE:
            if (collisionStatus->curFloor <= NO_COLLIDER) {
                N(end_outta_sight_cleanup)(bow);
                return ApiStatus_DONE2;
            }

            bow->pos.x = playerStatus->pos.x - N(OuttaSightPosX);
            bow->pos.y = playerStatus->pos.y - N(OuttaSightPosY);
            bow->pos.z = playerStatus->pos.z - N(OuttaSightPosZ);

            stickInputMag = dist2D(0.0f, 0.0f, partnerStatus->stickX, partnerStatus->stickY);
            if ((collisionStatus->curFloor <= NO_COLLIDER)
                || stickInputMag > 10.0f
                || partnerStatus->pressedButtons & (BUTTON_B | BUTTON_C_DOWN)
                || playerStatus->flags & PS_FLAG_HIT_FIRE
            ) {
                // prevent exiting from the ground while underneath a wall
                if (N(check_for_treadmill_overlaps)() <= NO_COLLIDER) {
                    script->USE_STATE++; // OUTTA_SIGHT_REAPPEAR
                    script->functionTemp[1] = 3;
                    script->functionTemp[2] = playerStatus->inputDisabledCount;
                }
            }
            break;

        case OUTTA_SIGHT_REAPPEAR:
            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] < playerStatus->inputDisabledCount) {
                    script->USE_STATE = OUTTA_SIGHT_IDLE;
                    break;
                }
            } else {
                script->functionTemp[1]--;
                break;
            }

            sfx_play_sound_at_npc(SOUND_BOW_APPEAR, SOUND_SPACE_MODE_0, NPC_PARTNER);
            N(end_outta_sight_cleanup)(bow);
            return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldBow_UseAbility = {
    EVT_CALL(N(UseAbility))
    EVT_RETURN
    EVT_END
};

void N(end_outta_sight_cleanup)(Npc* bow) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    s32 actionState;

    playerStatus->alpha1 = 255;
    npc_set_imgfx_params(bow, IMGFX_CLEAR, 0, 0, 0, 0, 0);
    bow->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    get_shadow_by_index(bow->shadowIndex)->alpha = playerStatus->alpha1 / 2;

    if (N(LockingPlayerInput)) {
        enable_player_input();
    }

    playerStatus->flags &= ~(PS_FLAG_HAZARD_INVINCIBILITY | PS_FLAG_JUMPING);
    bow->flags &= ~(NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_INVISIBLE);
    N(LockingPlayerInput) = FALSE;
    actionState = ACTION_STATE_IDLE;

    if (playerStatus->flags & PS_FLAG_HIT_FIRE) {
        actionState = ACTION_STATE_HIT_LAVA;
    }

    set_action_state(actionState);
    partnerStatus->partnerActionState = 0;
    partnerStatus->actingPartner = 0;
    playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
    partner_clear_player_tracking(bow);
    N(IsHiding) = FALSE;
}

API_CALLABLE(N(PutAway)) {
    Npc* bow = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(bow);
        if (N(IsHiding)) {
            sfx_play_sound_at_npc(SOUND_BOW_APPEAR, SOUND_SPACE_MODE_0, NPC_PARTNER);
        }
        N(end_outta_sight_cleanup)(bow);
    }

    if (partner_put_away(bow)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldBow_PutAway = {
    EVT_CALL(N(PutAway))
    EVT_RETURN
    EVT_END
};

void N(pre_battle)(Npc* bow) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (N(IsHiding)) {
        enable_player_input();
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(bow);
        partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
        partnerStatus->actingPartner = PARTNER_NONE;
        N(IsHiding) = FALSE;
        bow->flags &= ~NPC_FLAG_INVISIBLE;
    }
}
