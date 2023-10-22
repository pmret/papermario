#include "common.h"
#include "../src/world/partners.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/player.h"

#define NAMESPACE world_parakarry

BSS b32 N(UsingAbility);
BSS b32 N(LockingPlayerInput);
BSS b32 N(PlayerCollisionDisabled); // minor bug: never gets properly reset to FALSE
BSS b32 N(PlayerWasFacingLeft);
BSS s32 N(AbilityState);
BSS s32 N(AbilityStateTime);
BSS TweesterPhysics N(TweesterPhysicsData);

enum {
    AIR_LIFT_NONE       = 0,  // only used for initial value
    // next two states lock input for a few frames, during which the ability can be canceled
    AIR_LIFT_INIT       = 40,
    AIR_LIFT_DELAY      = 41,
    AIR_LIFT_BEGIN      = 30,
    AIR_LIFT_GATHER     = 31,
    AIR_LIFT_PICKUP     = 1,   // pick up the player and lift them into the air
    AIR_LIFT_CARRY      = 2,   // carry the player through the air
    AIR_LIFT_HOLD       = 6,   // remain in one position for a short period of time
    AIR_LIFT_JUMP       = 20,  // player jumped off while being carried
    AIR_LIFT_DROP       = 21,  // dropping the player
    AIR_LIFT_CANCEL     = 22,
};

void N(init)(Npc* parakarry) {
    parakarry->collisionHeight = 37;
    parakarry->collisionDiameter = 40;
    N(UsingAbility)  = FALSE;
    N(AbilityState) = AIR_LIFT_NONE;
    N(LockingPlayerInput) = FALSE;
    N(PlayerCollisionDisabled) = FALSE;
    N(PlayerWasFacingLeft) = FALSE;
    N(AbilityStateTime) = 0;
}

API_CALLABLE(N(TakeOut)) {
    Npc* parakarry = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(parakarry);
    }

    if (partner_get_out(parakarry)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldParakarry_TakeOut = {
    EVT_CALL(N(TakeOut))
    EVT_RETURN
    EVT_END
};

TweesterPhysics* N(TweesterPhysicsPtr) = &N(TweesterPhysicsData);

API_CALLABLE(N(Update)) {
    PlayerData* playerData = &gPlayerData;
    Npc* parakarry = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_flying_enable(parakarry, 1);
        mem_clear(N(TweesterPhysicsPtr), sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_PARAKARRY]++;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_flying_update_player_tracking(parakarry);
        partner_flying_update_motion(parakarry);
        return ApiStatus_BLOCK;
    }

    switch (N(TweesterPhysicsPtr)->state) {
        case TWEESTER_PARTNER_INIT:
            N(TweesterPhysicsPtr)->state++;
            N(TweesterPhysicsPtr)->prevFlags = parakarry->flags;
            N(TweesterPhysicsPtr)->radius = fabsf(dist2D(parakarry->pos.x, parakarry->pos.z,
                                                     entity->pos.x, entity->pos.z));
            N(TweesterPhysicsPtr)->angle = atan2(entity->pos.x, entity->pos.z,
                                              parakarry->pos.x, parakarry->pos.z);
            N(TweesterPhysicsPtr)->angularVel = 6.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase = 50.0f;
            N(TweesterPhysicsPtr)->countdown = 120;
            parakarry->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_FLYING;
            parakarry->flags &= ~NPC_FLAG_GRAVITY;
        case TWEESTER_PARTNER_ATTRACT:
            sin_cos_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->angle), &sinAngle, &cosAngle);
            parakarry->pos.x = entity->pos.x + (sinAngle * N(TweesterPhysicsPtr)->radius);
            parakarry->pos.z = entity->pos.z - (cosAngle * N(TweesterPhysicsPtr)->radius);
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

            parakarry->pos.y += liftoffVelocity;
            parakarry->renderYaw = clamp_angle(360.0f - N(TweesterPhysicsPtr)->angle);
            N(TweesterPhysicsPtr)->angularVel += 0.8;

            if (N(TweesterPhysicsPtr)->angularVel > 40.0f) {
                N(TweesterPhysicsPtr)->angularVel = 40.0f;
            }

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state++;
            }
            break;
        case TWEESTER_PARTNER_HOLD:
            parakarry->flags = N(TweesterPhysicsPtr)->prevFlags;
            N(TweesterPhysicsPtr)->countdown = 30;
            N(TweesterPhysicsPtr)->state++;
            break;
        case TWEESTER_PARTNER_RELEASE:
            partner_flying_update_player_tracking(parakarry);
            partner_flying_update_motion(parakarry);

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldParakarry_Update = {
    EVT_CALL(N(Update))
    EVT_RETURN
    EVT_END
};

void N(try_cancel_tweester)(Npc* parakarry) {
    if (TweesterTouchingPartner) {
        TweesterTouchingPartner = NULL;
        parakarry->flags = N(TweesterPhysicsPtr)->prevFlags;
        N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking (parakarry);
    }
}

s32 N(update_current_floor)(void) {
    f32 x, y, z, length, hitRx, hitRz, hitDirX, hitDirZ;
    f32 colliderBaseHeight = gPlayerStatus.colliderHeight;
    s32 hitResult;
    s32 surfaceType;

    x = gPlayerStatus.pos.x;
    y = gPlayerStatus.pos.y + (colliderBaseHeight * 0.5);
    z = gPlayerStatus.pos.z;
    length = colliderBaseHeight / 2.0f;

    hitResult = player_raycast_below_cam_relative(&gPlayerStatus, &x, &y, &z, &length, &hitRx,
                                                      &hitRz, &hitDirX, &hitDirZ);

    surfaceType = get_collider_flags(hitResult) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
    if (surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) {
        gPlayerStatus.hazardType = HAZARD_TYPE_SPIKES;
        gPlayerStatus.flags |= PS_FLAG_HIT_FIRE;
        N(AbilityState) = AIR_LIFT_DROP;
    }

    return hitResult;
}

API_CALLABLE(N(UseAbility)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    Npc* parakarry = script->owner2.npc;
    s32 buttonTemp = BUTTON_A;
    f32 x, y, z, yaw, length;
    f32 playerDeltaX, playerDeltaZ;
    f32 parakarryDeltaX, parakarryDeltaZ;
    f32 halfCollisionHeight;
    s32 hitCount;
    b32 hitAbove;

    if (gCurrentEncounter.unk_08 != 0) {
         return ApiStatus_BLOCK;
    }

    if (isInitialCall) {
        N(try_cancel_tweester)(parakarry);
        if ((playerStatus->animFlags & PA_FLAG_CHANGING_MAP)) {
            return ApiStatus_DONE2;
        }

        if (!partnerStatus->shouldResumeAbility) {
            if (!func_800EA52C(PARTNER_PARAKARRY)) {
                return ApiStatus_DONE2;
            }
            N(AbilityState) = AIR_LIFT_INIT;
            parakarry->flags &= ~NPC_FLAG_COLLDING_FORWARD_WITH_WORLD;
            parakarry->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
        } else {
            partnerStatus->shouldResumeAbility = FALSE;
            set_action_state(ACTION_STATE_RIDE);
            parakarry->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_GRAVITY);
            N(UsingAbility)  = TRUE;
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
            parakarry->curAnim = ANIM_WorldParakarry_CarryLight;
            partnerStatus->actingPartner = PARTNER_PARAKARRY;
            partnerStatus->partnerActionState = PARTNER_ACTION_PARAKARRY_HOVER;
            parakarry->flags &= ~NPC_FLAG_COLLDING_FORWARD_WITH_WORLD;
            parakarry->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
        }
    }

    switch (N(AbilityState)) {
        case AIR_LIFT_INIT:
            if (playerStatus->inputDisabledCount != 0) {
                return ApiStatus_DONE2;
            }
            N(AbilityStateTime) = 3;
            N(AbilityState) = AIR_LIFT_DELAY;
            script->functionTemp[2] = playerStatus->inputDisabledCount;
            // fallthrough
        case AIR_LIFT_DELAY:
            if (N(AbilityStateTime) == 0) {
                if (script->functionTemp[2] < playerStatus->inputDisabledCount || !func_800EA52C(PARTNER_PARAKARRY)) {
                    return ApiStatus_DONE2;
                }
                N(AbilityState) = AIR_LIFT_BEGIN;
            } else {
                N(AbilityStateTime)--;
            }
            break;
    }

    switch (N(AbilityState)) {
        case AIR_LIFT_BEGIN:
            set_action_state(ACTION_STATE_RIDE);
            disable_player_input();
            disable_player_static_collisions();
            script->functionTemp[2] = playerStatus->inputDisabledCount;
            N(LockingPlayerInput) = TRUE;
            N(PlayerCollisionDisabled) = TRUE;
            N(UsingAbility) = TRUE;
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
            parakarry->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_GRAVITY);
            parakarry->flags |= NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_FLYING;
            partnerStatus->actingPartner = PARTNER_PARAKARRY;
            partnerStatus->partnerActionState = PARTNER_ACTION_PARAKARRY_HOVER;
            N(PlayerWasFacingLeft) = partner_force_player_flip_done();
            enable_npc_blur(parakarry);
            parakarry->yaw = atan2(parakarry->pos.x, parakarry->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            parakarry->duration = 4;
            N(AbilityState)++; // AIR_LIFT_GATHER
            break;
        case AIR_LIFT_GATHER:
            if (playerStatus->actionState == ACTION_STATE_HIT_FIRE
             || playerStatus->actionState == ACTION_STATE_HIT_LAVA
             || playerStatus->actionState == ACTION_STATE_KNOCKBACK
             || playerStatus->actionState == ACTION_STATE_JUMP
             || playerStatus->actionState == ACTION_STATE_HOP
            ) {
                disable_npc_blur(parakarry);
                N(AbilityState) = AIR_LIFT_DROP;
            } else {
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                parakarry->moveToPos.x = playerStatus->pos.x;
                parakarry->moveToPos.y = playerStatus->pos.y + 32.0f;
                parakarry->moveToPos.z = playerStatus->pos.z;
                parakarry->curAnim = ANIM_WorldParakarry_Run;
                add_vec2D_polar(&parakarry->moveToPos.x, &parakarry->moveToPos.z, 0.0f, playerStatus->targetYaw);
                yaw = playerStatus->targetYaw;

                yaw += !N(PlayerWasFacingLeft) ? 90.0f : -90.0f;

                add_vec2D_polar(&parakarry->moveToPos.x, &parakarry->moveToPos.z, 5.0f, clamp_angle(yaw));

                parakarry->pos.x += (parakarry->moveToPos.x - parakarry->pos.x) / parakarry->duration;
                parakarry->pos.y += (parakarry->moveToPos.y - parakarry->pos.y) / parakarry->duration;
                parakarry->pos.z += (parakarry->moveToPos.z - parakarry->pos.z) / parakarry->duration;
                parakarry->duration--;
                if (parakarry->duration != 0) {
                    if (script->functionTemp[2] < playerStatus->inputDisabledCount) {
                        disable_npc_blur(parakarry);
                        N(AbilityState) = AIR_LIFT_CANCEL;
                    }
                } else {
                    disable_npc_blur(parakarry);
                    parakarry->yaw = playerStatus->targetYaw;
                    parakarry->moveSpeed = 0.2f;
                    parakarry->curAnim = ANIM_WorldParakarry_CarryHeavy;
                    parakarry->planarFlyDist = 0;
                    suggest_player_anim_always_forward(ANIM_MarioW2_HoldOnto);
                    sfx_play_sound_at_npc(SOUND_PARAKARRY_FLAP, SOUND_SPACE_DEFAULT, NPC_PARTNER);
                    gCollisionStatus.lastTouchedFloor = NO_COLLIDER;
                    gCollisionStatus.curFloor = NO_COLLIDER;
                    parakarry->curFloor = NO_COLLIDER;
                    N(AbilityStateTime) = 20;
                    N(AbilityState) = AIR_LIFT_PICKUP;
                }
            }
            break;
        case AIR_LIFT_PICKUP:
            if (playerStatus->actionState == ACTION_STATE_HIT_FIRE
             || playerStatus->actionState == ACTION_STATE_HIT_LAVA
             || playerStatus->actionState == ACTION_STATE_KNOCKBACK
            ) {
                N(AbilityState) = AIR_LIFT_DROP;
                break;
            }
            // handle jump/cancel inputs
            if (partnerStatus->pressedButtons & (BUTTON_A | BUTTON_B | BUTTON_C_DOWN)) {
                N(AbilityState) = (partnerStatus->pressedButtons & BUTTON_A) ? AIR_LIFT_JUMP : AIR_LIFT_DROP;
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                break;
            }

            if (gGameStatusPtr->frameCounter % 6 == 0) {
                sfx_play_sound_at_npc(SOUND_PARAKARRY_FLAP, SOUND_SPACE_DEFAULT, NPC_PARTNER);
            }

            length = fabsf(sin_rad(DEG_TO_RAD((20 - N(AbilityStateTime)) * 18))) * 1.3;
            playerStatus->pos.y += length;
            parakarry->pos.y += length;
            x = parakarry->pos.x;
            y = parakarry->pos.y + parakarry->collisionHeight / 2.0f;
            z = parakarry->pos.z;
            length = parakarry->collisionHeight / 2.0f;
            halfCollisionHeight = length;

            if (npc_raycast_up(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, &length)) {
                if (length < halfCollisionHeight) {
                    N(AbilityStateTime) = 0;
                }
            }

            length = playerStatus->colliderHeight / 2.0f;
            x = playerStatus->pos.x;
            y = playerStatus->pos.y + playerStatus->colliderHeight / 2.0f;
            z = playerStatus->pos.z;
            halfCollisionHeight = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw;
            if (player_raycast_up_corners(playerStatus, &x, &y, &z, &length, halfCollisionHeight) >= 0) {
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                N(AbilityState) = AIR_LIFT_DROP;
                break;
            }

            x = playerStatus->pos.x;
            y = playerStatus->pos.y;
            z = playerStatus->pos.z;
            hitCount = npc_test_move_complex_with_slipping(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, parakarry->moveSpeed, parakarry->yaw, playerStatus->colliderHeight, playerStatus->colliderDiameter);
            if (hitCount > 1) {
                playerStatus->pos.x += (x - playerStatus->pos.x) / 8.0f;
                playerStatus->pos.z += (z - playerStatus->pos.z) / 8.0f;
                parakarry->pos.x += (x - parakarry->pos.x) / 8.0f;
                parakarry->pos.z += (z - parakarry->pos.z) / 8.0f;
            }

            x = parakarry->pos.x;
            y = parakarry->pos.y;
            z = parakarry->pos.z;
            hitCount = npc_test_move_complex_with_slipping(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, parakarry->moveSpeed, parakarry->yaw, parakarry->collisionHeight, parakarry->collisionDiameter);
            if (hitCount > 1) {
                playerDeltaX = (x - playerStatus->pos.x) / 8.0f;
                playerDeltaZ = (z - playerStatus->pos.z) / 8.0f;
                parakarryDeltaX = (x - parakarry->pos.x) / 8.0f;
                parakarryDeltaZ = (z - parakarry->pos.z) / 8.0f;

                x = parakarry->pos.x + parakarryDeltaX;
                z = parakarry->pos.z + parakarryDeltaZ;

                x = parakarry->pos.x;
                y = parakarry->pos.y;
                z = parakarry->pos.z;
                hitCount = npc_test_move_complex_with_slipping(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, parakarry->moveSpeed, parakarry->yaw, parakarry->collisionHeight, parakarry->collisionDiameter);
                if (hitCount == 0) {
                    playerStatus->pos.x += playerDeltaX;
                    playerStatus->pos.z += playerDeltaZ;
                    parakarry->pos.x += parakarryDeltaX;
                    parakarry->pos.z += parakarryDeltaZ;
                }
            }

            if (hitCount == 0 && !(playerStatus->animFlags & PA_FLAG_NPC_COLLIDED)) {
                add_vec2D_polar(&parakarry->pos.x, &parakarry->pos.z, parakarry->moveSpeed, parakarry->yaw);
                add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, parakarry->moveSpeed, parakarry->yaw);
                parakarry->planarFlyDist += parakarry->moveSpeed;
            }

            x = playerStatus->pos.x;
            y = playerStatus->pos.y + playerStatus->colliderHeight / 2.0f;
            z = playerStatus->pos.z;
            length = playerStatus->colliderHeight / 2.0f;
            if (npc_raycast_down_around(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, &length, parakarry->yaw, parakarry->collisionDiameter)) {
                s32 surfaceType = get_collider_flags(NpcHitQueryColliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                if (surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) {
                    playerStatus->hazardType = HAZARD_TYPE_SPIKES;
                    playerStatus->flags |= PS_FLAG_HIT_FIRE;
                    N(AbilityState) = AIR_LIFT_DROP;
                }

                playerStatus->pos.y += (y - playerStatus->pos.y) / 4.0f;
                parakarry->pos.y = playerStatus->pos.y + 32.0f;
            }

            if (parakarry->flags & NPC_FLAG_COLLDING_FORWARD_WITH_WORLD) {
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                N(AbilityState) = AIR_LIFT_DROP;
                break;
            }

            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
            if (N(AbilityStateTime) != 0) {
                N(AbilityStateTime)--;
            } else {
                parakarry->jumpVel = -0.5f;
                parakarry->jumpScale = -0.01f;
                parakarry->moveToPos.y = playerStatus->pos.y;
                parakarry->duration = 0;
                parakarry->curAnim = ANIM_WorldParakarry_CarryHeavy;
                parakarry->animationSpeed = 1.8f;
                gCollisionStatus.curFloor = NO_COLLIDER;
                N(AbilityState)++; // AIR_LIFT_CARRY
            }
            break;
        case AIR_LIFT_CARRY:
            gCollisionStatus.curFloor = N(update_current_floor)();
            if (playerStatus->actionState == ACTION_STATE_HIT_FIRE
             || playerStatus->actionState == ACTION_STATE_HIT_LAVA
             || playerStatus->actionState == ACTION_STATE_KNOCKBACK
            ) {
                N(AbilityState) = AIR_LIFT_DROP;
                break;
            }

            suggest_player_anim_always_forward(ANIM_MarioW2_HoldOnto);
            if (playerStatus->flags & PS_FLAG_HIT_FIRE) {
                N(AbilityState) = AIR_LIFT_JUMP;
                break;
            }

            // handle jump/cancel inputs
            if (partnerStatus->pressedButtons & (BUTTON_A | BUTTON_B | BUTTON_C_DOWN)) {
                if (partnerStatus->pressedButtons & buttonTemp) {   // TODO find a way to remove this while still loading 0x15 instead of moving it from register
                    if (!parakarry->pos.x) {

                    }
                }
                N(AbilityState) = (partnerStatus->pressedButtons & BUTTON_A) ? AIR_LIFT_JUMP : AIR_LIFT_DROP;
                break;
            }

            if (gGameStatusPtr->frameCounter % 6 == 0) {
                sfx_play_sound_at_npc(SOUND_PARAKARRY_FLAP, SOUND_SPACE_DEFAULT, NPC_PARTNER);
            }

            parakarry->jumpVel -= parakarry->jumpScale;
            if (parakarry->jumpVel > 0.0) {
                parakarry->jumpVel = 0.0f;
            }

            parakarry->pos.y += parakarry->jumpVel;
            playerStatus->pos.y += parakarry->jumpVel;
            if (!(playerStatus->animFlags & PA_FLAG_NPC_COLLIDED)) {
                parakarry->moveSpeed += 0.1;
                if (parakarry->moveSpeed > 2.0) {
                    parakarry->moveSpeed = 2.0f;
                }

                add_vec2D_polar(&parakarry->pos.x, &parakarry->pos.z, parakarry->moveSpeed, parakarry->yaw);
                add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, parakarry->moveSpeed, parakarry->yaw);
                parakarry->planarFlyDist += parakarry->moveSpeed;
                parakarry->animationSpeed -= 0.05;
                if (parakarry->animationSpeed < 1.5) {
                    parakarry->animationSpeed = 1.5f;
                }
                if (parakarry->planarFlyDist > 80.0f) {
                    parakarry->animationSpeed += 0.5;
                }
                if (!(playerStatus->animFlags & PA_FLAG_NPC_COLLIDED)) {
                    x = playerStatus->pos.x;
                    y = playerStatus->pos.y;
                    z = playerStatus->pos.z;
                    if (npc_test_move_complex_with_slipping(COLLIDER_FLAG_IGNORE_PLAYER,
                            &x, &y, &z, parakarry->moveSpeed, parakarry->yaw,
                            playerStatus->colliderHeight, playerStatus->colliderDiameter)
                    ) {
                        suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                        N(AbilityState) = AIR_LIFT_DROP;
                        break;
                    }

                    x = parakarry->pos.x;
                    y = parakarry->pos.y;
                    z = parakarry->pos.z;
                    if (!npc_test_move_complex_with_slipping(COLLIDER_FLAG_IGNORE_PLAYER,
                            &x, &y, &z, parakarry->moveSpeed, parakarry->yaw,
                            parakarry->collisionHeight, parakarry->collisionDiameter)
                    ) {
                        hitAbove = FALSE;
                        x = parakarry->pos.x;
                        y = parakarry->pos.y + parakarry->collisionHeight / 2.0f;
                        z = parakarry->pos.z;
                        length = parakarry->collisionHeight / 2.0f;

                        halfCollisionHeight = length;
                        if (npc_raycast_up(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, &length) && (length < halfCollisionHeight)) {
                            parakarry->pos.y =  y - parakarry->collisionHeight;
                            playerStatus->pos.y = parakarry->pos.y - 32.0f;
                            hitAbove = TRUE;
                        }
                        x = playerStatus->pos.x;
                        y = playerStatus->pos.y + playerStatus->colliderHeight / 2.0f;
                        z = playerStatus->pos.z;
                        length = playerStatus->colliderHeight / 2.0f;

                        if (npc_raycast_down_around(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, &length, parakarry->yaw, parakarry->collisionDiameter)) {
                            playerStatus->pos.y += (y - playerStatus->pos.y) / 4.0f;
                            parakarry->pos.y = playerStatus->pos.y + 32.0f;
                            y = parakarry->pos.y;
                            parakarry->pos.y = playerStatus->pos.y;
                            spawn_surface_effects(parakarry, SURFACE_INTERACT_WALK);
                            parakarry->pos.y = y;

                            if (hitAbove) {
                                N(AbilityState) = AIR_LIFT_DROP;
                                break;
                            }
                        }

                        if (!phys_adjust_cam_on_landing()) {
                            gCameras[CAM_DEFAULT].moveFlags &= ~CAMERA_MOVE_NO_INTERP_Y;
                        }
                        gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
                        gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
                        gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
                        if (!(parakarry->flags & NPC_FLAG_COLLDING_FORWARD_WITH_WORLD)) {
                            parakarry->duration++;
                            if (!(parakarry->planarFlyDist < 100.0f)) {
                                N(AbilityStateTime) = 5;
                                N(AbilityState) = AIR_LIFT_HOLD;
                            }
                            break;
                        }
                    }
                }
            }
            suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
            N(AbilityState) = AIR_LIFT_DROP;
            break;
        case AIR_LIFT_HOLD:
            if (N(AbilityStateTime) != 0) {
                N(AbilityStateTime)--;
            } else {
                N(AbilityState) = AIR_LIFT_DROP;
            }
            break;
    }

    if (N(AbilityState) == AIR_LIFT_JUMP
     || N(AbilityState) == AIR_LIFT_DROP
     || N(AbilityState) == AIR_LIFT_CANCEL
    ) {
        parakarry->curAnim = ANIM_WorldParakarry_Idle;
        N(UsingAbility)  = FALSE;
        parakarry->jumpVel = 0.0f;
        parakarry->flags &= ~NPC_FLAG_JUMPING;
        parakarry->animationSpeed = 1.0f;
        partner_clear_player_tracking(parakarry);
        partnerStatus->actingPartner = PARTNER_NONE;
        partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
        enable_partner_ai();
        sfx_stop_sound(SOUND_PARAKARRY_FLAP);
        if (N(LockingPlayerInput)) {
            enable_player_input();
        }
        if (N(PlayerCollisionDisabled)) {
            enable_player_static_collisions();
        }
        if ((playerStatus->flags & PS_FLAG_HIT_FIRE)) {
            set_action_state(ACTION_STATE_HIT_LAVA);
        } else if (N(AbilityState) == AIR_LIFT_JUMP) {
            start_bounce_b();
        } else if (N(AbilityState) == AIR_LIFT_DROP) {
            start_falling();
            gravity_use_fall_parms();
            playerStatus->flags |= PS_FLAG_SCRIPTED_FALL;
        } else {
            set_action_state(ACTION_STATE_IDLE);
        }
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldParakarry_UseAbility = {
    EVT_CALL(N(UseAbility))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(PutAway)) {
    Npc* parakarry = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(parakarry);
    }

    if (partner_put_away(parakarry)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldParakarry_PutAway = {
    EVT_CALL(N(PutAway))
    EVT_RETURN
    EVT_END
};

void N(pre_battle)(Npc* parakarry) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (N(UsingAbility)) {
        if (N(PlayerCollisionDisabled)) {
            enable_player_static_collisions();
        }

        if (N(LockingPlayerInput)) {
            enable_player_input();
        }

        set_action_state(ACTION_STATE_IDLE);
        partnerStatus->npc = *parakarry;
        partnerStatus->shouldResumeAbility = TRUE;
        partner_clear_player_tracking(parakarry);
    }

    partnerStatus->actingPartner = PARTNER_PARAKARRY;
}

void N(post_battle)(Npc* parakarry) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (partnerStatus->shouldResumeAbility) {
        if (N(PlayerCollisionDisabled)) {
            disable_player_static_collisions();
        }
        if (N(LockingPlayerInput)) {
            disable_player_input();
        }

        set_action_state(ACTION_STATE_RIDE);
        *parakarry = partnerStatus->npc;
        partnerStatus->actingPartner = PARTNER_NONE;
        partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
        partner_clear_player_tracking(parakarry);
        partner_use_ability();
    }
}
