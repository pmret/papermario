#include "common.h"
#include "../partners.h"
#include "effects.h"
#include "sprite/npc/WorldLakilester.h"
#include "sprite/player.h"

#define NAMESPACE world_lakilester

BSS s32 N(PutAwayState);
BSS b32 N(LockingPlayerInput);
BSS b32 N(PlayerCollisionDisabled);
BSS s32 N(MountState);
BSS b32 N(UpdatePushingWall);
BSS s32 N(AbilityState);
BSS s32 N(PlayerBounceOffset);
BSS s32 N(MoveSoundsTime);
BSS s32 N(MovePitchAdjustment);
BSS s32 N(MountingDeltaY);
BSS f32 N(CurrentGroundPitch);
BSS s32 N(D_802BFF2C); // unused (padding?)

enum {
    RIDE_STATE_BEGIN            = 40,
    RIDE_STATE_DELAY            = 41,
    RIDE_STATE_MOUNT_1          = 100,
    RIDE_STATE_MOUNT_2          = 101,
    RIDE_STATE_MOUNT_3          = 102,
    RIDE_STATE_MOUNT_4          = 103,
    RIDE_STATE_START_RIDING     = 104, // cannot dismount until this state is done
    RIDE_STATE_RIDING           = 1,
    RIDE_STATE_DISMOUNT_1       = 3,
    RIDE_STATE_DISMOUNT_2       = 4,
    RIDE_STATE_DISMOUNT_3       = 5,
    RIDE_STATE_FINISH_1         = 10,
    RIDE_STATE_FINISH_2         = 11,
};

// states for putting lakilester away, paralleling ride states
enum {
    PUT_AWAY_DISMOUNT_1         = 0,
    PUT_AWAY_DISMOUNT_2         = 1,
    PUT_AWAY_DISMOUNT_3         = 2,
    PUT_AWAY_FINISH_1           = 3,
    PUT_AWAY_FINISH_2           = 4,
    PUT_AWAY_FINISH_3           = 5,
};

enum {
    MOUNT_STATE_NONE            = 0,
    MOUNT_STATE_IN_PROGRESS     = 1,
    MOUNT_STATE_DONE            = 2,
};

void N(offset_player_from_camera)(f32 arg0);

void N(sync_player_position)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* lakilester = get_npc_unsafe(NPC_PARTNER);
    f32 speed;

    if (playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT) {
        speed = playerStatus->curSpeed;
        if (playerStatus->flags & PS_FLAG_ENTERING_BATTLE) {
            speed *= 0.5f;
        }

        add_vec2D_polar(&lakilester->pos.x, &lakilester->pos.z, speed, playerStatus->heading);
        lakilester->yaw = playerStatus->targetYaw;
    }

    playerStatus->pos.x = lakilester->pos.x;
    playerStatus->pos.y = lakilester->pos.y + 10.0f + abs(N(PlayerBounceOffset)) * 0.34f;
    playerStatus->pos.z = lakilester->pos.z;
    add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, 2.0f, gCameras[gCurrentCameraID].curYaw);
}

void N(init)(Npc* lakilester) {
    lakilester->collisionHeight = 38;
    lakilester->collisionDiameter = 36;
    lakilester->collisionChannel = COLLIDER_FLAG_IGNORE_PLAYER;
    N(PlayerBounceOffset) = 0;
    N(LockingPlayerInput) = FALSE;
    N(PlayerCollisionDisabled) = FALSE;
    N(MountState) = MOUNT_STATE_NONE;
    N(UpdatePushingWall) = TRUE;
    N(MoveSoundsTime) = 0;
    N(MovePitchAdjustment) = 0;
    N(MountingDeltaY) = 0;
    N(CurrentGroundPitch) = 0;
    lakilester->moveToPos.x = lakilester->pos.x;
    lakilester->moveToPos.y = lakilester->pos.y;
    lakilester->moveToPos.z = lakilester->pos.z;
}

API_CALLABLE(N(TakeOut)) {
    Npc* lakilester = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(lakilester);
    }

    if (partner_get_out(lakilester)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldLakilester_TakeOut = {
    EVT_CALL(N(TakeOut))
    EVT_RETURN
    EVT_END
};

BSS TweesterPhysics N(TweesterPhysicsData);
TweesterPhysics* N(TweesterPhysicsPtr) = &N(TweesterPhysicsData);

API_CALLABLE(N(Update)) {
    PlayerData* playerData = &gPlayerData;
    Npc* lakilester = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_flying_enable(lakilester, 1);
        mem_clear(N(TweesterPhysicsPtr), sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_LAKILESTER]++;
    lakilester->flags |= NPC_FLAG_DIRTY_SHADOW;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_flying_update_player_tracking(lakilester);
        partner_flying_update_motion(lakilester);
        return ApiStatus_BLOCK;
    }

    switch (N(TweesterPhysicsPtr)->state) {
        case TWEESTER_PARTNER_INIT:
            N(TweesterPhysicsPtr)->state++;
            N(TweesterPhysicsPtr)->prevFlags = lakilester->flags;
            N(TweesterPhysicsPtr)->radius = fabsf(dist2D(lakilester->pos.x, lakilester->pos.z, entity->pos.x, entity->pos.z));
            N(TweesterPhysicsPtr)->angle = atan2(entity->pos.x, entity->pos.z, lakilester->pos.x, lakilester->pos.z);
            N(TweesterPhysicsPtr)->angularVel = 6.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase = 50.0f;
            N(TweesterPhysicsPtr)->countdown = 120;
            lakilester->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_FLYING;
            lakilester->flags &= ~NPC_FLAG_GRAVITY;
        case TWEESTER_PARTNER_ATTRACT:
            sin_cos_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->angle), &sinAngle, &cosAngle);
            lakilester->pos.x = entity->pos.x + (sinAngle * N(TweesterPhysicsPtr)->radius);
            lakilester->pos.z = entity->pos.z - (cosAngle * N(TweesterPhysicsPtr)->radius);
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

            lakilester->pos.y += liftoffVelocity;
            lakilester->renderYaw = clamp_angle(360.0f - N(TweesterPhysicsPtr)->angle);
            N(TweesterPhysicsPtr)->angularVel += 0.8;

            if (N(TweesterPhysicsPtr)->angularVel > 40.0f) {
                N(TweesterPhysicsPtr)->angularVel = 40.0f;
            }

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state++;
            }
            break;
        case TWEESTER_PARTNER_HOLD:
            lakilester->flags = N(TweesterPhysicsPtr)->prevFlags;
            N(TweesterPhysicsPtr)->countdown = 30;
            N(TweesterPhysicsPtr)->state++;
            break;
        case TWEESTER_PARTNER_RELEASE:
            partner_flying_update_player_tracking(lakilester);
            partner_flying_update_motion(lakilester);

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldLakilester_Update = {
    EVT_CALL(N(Update))
    EVT_RETURN
    EVT_END
};

void N(try_cancel_tweester)(Npc* lakilester) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        lakilester->flags = N(TweesterPhysicsPtr)->prevFlags;
        N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking(lakilester);
    }
}

void N(get_movement_from_input)(f32* outAngle, f32* outSpeed) {
    PartnerStatus* partnerStatus = &gPartnerStatus;
    f32 stickX = partnerStatus->stickX;
    f32 stickY = partnerStatus->stickY;
    f32 moveAngle = clamp_angle(atan2(0.0f, 0.0f, stickX, -stickY) + gCameras[CAM_DEFAULT].curYaw);
    f32 moveSpeed = 0.0f;

    if (dist2D(0.0f, 0.0f, stickX, -stickY) >= 1.0) {
        moveSpeed = 3.0f;
        if (SQ(stickX) + SQ(stickY) > SQ(55)) {
            moveSpeed = 6.0f;
        }
    }

    *outAngle = moveAngle;
    *outSpeed = moveSpeed;
}

s32 N(can_dismount)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* currentCamera;
    f32 hitDirX, hitDirZ;
    f32 hitRx, hitRz;
    f32 outX, outY, outZ, outLength;
    Npc* lakilester = get_npc_unsafe(NPC_PARTNER);
    s32 temp;
    s32 hitResult;
    s32 canDismount;
    s32 entityType;

    if (playerStatus->animFlags & PA_FLAG_DISMOUNTING_ALLOWED) {
        playerStatus->animFlags &= ~PA_FLAG_DISMOUNTING_ALLOWED;
        return TRUE;
    }

    canDismount = FALSE;
    outLength = 16.0f;
    outY = lakilester->moveToPos.y + 7.0f;
    outX = playerStatus->pos.x;
    outZ = playerStatus->pos.z;
    currentCamera = &gCameras[gCurrentCameraID];
    add_vec2D_polar(&outX, &outZ, 2.0f, currentCamera->curYaw);
    hitResult = player_raycast_below_cam_relative(playerStatus, &outX, &outY, &outZ, &outLength, &hitRx, &hitRz,
                                                      &hitDirX, &hitDirZ);
    temp = hitResult;

    //TODO find better match
    if (outLength <= 16.0f && temp >= 0) {
        if (!(temp & COLLISION_WITH_ENTITY_BIT) ||
            (entityType = get_entity_type(temp),
            !(entityType == ENTITY_TYPE_SIMPLE_SPRING || entityType == ENTITY_TYPE_SCRIPT_SPRING))
        ) {
            temp = get_collider_flags(temp) & COLLIDER_FLAGS_SURFACE_TYPE_MASK; //TODO 'temp' is now 'surfaceType'
            if (!(temp == SURFACE_TYPE_WATER || temp == SURFACE_TYPE_SPIKES || temp == SURFACE_TYPE_LAVA)) {
                if (temp != SURFACE_TYPE_SLIDE) {
                    lakilester->moveToPos.x = outX;
                    lakilester->moveToPos.y = outY;
                    lakilester->moveToPos.z = outZ;
                    canDismount = TRUE;
                }
            }
        }
    }
    return canDismount;
}

s32 N(test_mounting_height_adjustment)(Npc* lakilester, f32 height, f32 dist) {
    f32 x = gPlayerStatus.pos.x;
    f32 y = gPlayerStatus.pos.y + height;
    f32 z = gPlayerStatus.pos.z;
    f32 depth = dist;
    f32 hitRx, hitRz;
    f32 hitDirX, hitDirZ;
    f32 deltaY;

    N(MountingDeltaY) = 0;

    if (player_raycast_below_cam_relative(&gPlayerStatus, &x, &y, &z, &depth,
            &hitRx, &hitRz, &hitDirX, &hitDirZ) > NO_COLLIDER)
    {
        deltaY = y - lakilester->moveToPos.y;
        if (deltaY != 0.0f) {
            if (fabs(deltaY) < 10.0) {
                N(MountingDeltaY) = deltaY;
                lakilester->moveToPos.y = y;
                return TRUE;
            } else {
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

void N(apply_riding_static_collisions)(Npc* lakilester) {
    f32 radius = lakilester->collisionDiameter * 0.8f;
    f32 x, y, z, yaw;

    // combine testing boilerplate
    #define TEST_MOVE_AT_ANGLE(testFunc, angle) \
    ( \
        yaw = clamp_angle(angle), \
        x = lakilester->pos.x, \
        y = lakilester->moveToPos.y, \
        z = lakilester->pos.z, \
        testFunc(lakilester->collisionChannel, &x, &y, &z, 0.0f, yaw, lakilester->collisionHeight, radius) \
    )

    if (TEST_MOVE_AT_ANGLE(npc_test_move_complex_with_slipping, lakilester->yaw)) {
        lakilester->flags |= (NPC_FLAG_COLLDING_FORWARD_WITH_WORLD | NPC_FLAG_COLLDING_WITH_WORLD);
        lakilester->curWall = NpcHitQueryColliderID;
        lakilester->pos.x = x;
        lakilester->pos.z = z;
    } else {
        lakilester->flags &= ~(NPC_FLAG_COLLDING_FORWARD_WITH_WORLD | NPC_FLAG_COLLDING_WITH_WORLD);
    }

    if (TEST_MOVE_AT_ANGLE(npc_test_move_taller_with_slipping, lakilester->yaw + 45.0f)) {
        lakilester->pos.x = x;
        lakilester->pos.z = z;
        lakilester->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
    } else {
        lakilester->flags &= ~NPC_FLAG_COLLDING_WITH_WORLD;
    }

    if (TEST_MOVE_AT_ANGLE(npc_test_move_taller_with_slipping, lakilester->yaw - 45.0f)) {
        lakilester->pos.x = x;
        lakilester->pos.z = z;
        lakilester->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
    } else {
        lakilester->flags &= ~NPC_FLAG_COLLDING_WITH_WORLD;
    }

    if (TEST_MOVE_AT_ANGLE(npc_test_move_simple_with_slipping, lakilester->yaw + 45.0f + 180.0f)) {
        lakilester->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
        lakilester->pos.x = x;
        lakilester->pos.z = z;
    } else {
        lakilester->flags &= ~NPC_FLAG_COLLDING_WITH_WORLD;
    }

    if (TEST_MOVE_AT_ANGLE(npc_test_move_simple_with_slipping, lakilester->yaw - 45.0f + 180.0f)) {
        lakilester->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
        lakilester->pos.x = x;
        lakilester->pos.z = z;
    } else {
        lakilester->flags &= ~NPC_FLAG_COLLDING_WITH_WORLD;
    }
}

void N(update_riding_physics)(Npc* lakilester) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    f32 hitDepth, sp40, sp44, sp48, sp4C, sinAngle, cosAngle;
    f32 moveAngle, moveSpeed;
    f32 x, y, z;
    f32 temp_f0_3;
    s32 raycastBelowResult;
    s32 currentSurfaceType;
    s32 belowSurfaceType;
    s32 pitchShift;
    f32 height;

    moveAngle = 0.0f;
    moveSpeed = 0.0f;
    N(get_movement_from_input)(&moveAngle, &moveSpeed);

    currentSurfaceType = get_collider_flags(lakilester->curFloor) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
    if (currentSurfaceType == SURFACE_TYPE_LAVA) {
        moveSpeed *= 0.5f;
    }

    if (N(CurrentGroundPitch) >= 20.0f) {
        moveSpeed *= 0.8f;
    }

    lakilester->moveSpeed = moveSpeed;

    if (moveSpeed != 0.0f) {
        N(MoveSoundsTime)++;
        N(MovePitchAdjustment)++;
        if (N(MoveSoundsTime) % 8 == 0) {
            if (N(MovePitchAdjustment) >= 120) {
                N(MovePitchAdjustment) = 0;
            }

            if (N(MovePitchAdjustment) < 60) {
                pitchShift = update_lerp(EASING_LINEAR,  0.0f, 100.0f, N(MovePitchAdjustment), 60);
                sfx_play_sound_with_params(SOUND_FLIGHT, 0, 64, pitchShift);
            } else {
                pitchShift = update_lerp(EASING_LINEAR, 100.0f, 0.0f, N(MovePitchAdjustment) - 60, 60);
                sfx_play_sound_with_params(SOUND_FLIGHT, 0, 64, pitchShift);
            }
        }
    }

    x = lakilester->pos.x;
    y = lakilester->moveToPos.y;
    z = lakilester->pos.z;

    if (npc_test_move_taller_with_slipping(lakilester->collisionChannel, &x, &y, &z,
        lakilester->collisionDiameter, lakilester->yaw, lakilester->collisionHeight, lakilester->collisionDiameter))
    {
        collisionStatus->curInspect = (partnerStatus->pressedButtons & BUTTON_A) ? NpcHitQueryColliderID : NO_COLLIDER;
    }

    if (moveSpeed != 0.0f) {
        lakilester->yaw = moveAngle;
        x = lakilester->pos.x;
        y = lakilester->moveToPos.y;
        z = lakilester->pos.z;
        if (npc_test_move_complex_with_slipping(lakilester->collisionChannel, &x, &y, &z,
            lakilester->moveSpeed, lakilester->yaw, lakilester->collisionHeight, lakilester->collisionDiameter))
        {
            if (N(UpdatePushingWall)) {
                collisionStatus->pushingAgainstWall = NpcHitQueryColliderID;
            }
            lakilester->pos.x += (x - lakilester->pos.x) / 5.0f;
            lakilester->pos.z += (z - lakilester->pos.z) / 5.0f;
        } else {
            npc_move_heading(lakilester, lakilester->moveSpeed, moveAngle);
            if (N(UpdatePushingWall)) {
                collisionStatus->pushingAgainstWall = NO_COLLIDER;
            }
        }

        moveAngle = clamp_angle(lakilester->yaw - 30.0f);
        x = lakilester->pos.x;
        y = lakilester->moveToPos.y;
        z = lakilester->pos.z;
        if (npc_test_move_taller_with_slipping(lakilester->collisionChannel, &x, &y, &z,
            lakilester->moveSpeed, moveAngle, lakilester->collisionHeight, lakilester->collisionDiameter))
        {
            lakilester->pos.x += (x - lakilester->pos.x) / 5.0f;
            lakilester->pos.z += (z - lakilester->pos.z) / 5.0f;
        }

        moveAngle = clamp_angle(lakilester->yaw + 30.0f);
        x = lakilester->pos.x;
        y = lakilester->moveToPos.y;
        z = lakilester->pos.z;
        if (npc_test_move_taller_with_slipping(lakilester->collisionChannel, &x, &y, &z,
            lakilester->moveSpeed, moveAngle, lakilester->collisionHeight, lakilester->collisionDiameter))
        {
            lakilester->pos.x += (x - lakilester->pos.x) / 5.0f;
            lakilester->pos.z += (z - lakilester->pos.z) / 5.0f;
        }

        spawn_surface_effects(lakilester, SURFACE_INTERACT_RUN);

    } else {
        moveAngle = 90.0f;
        x = lakilester->pos.x;
        y = lakilester->moveToPos.y;
        z = lakilester->pos.z;
        if (npc_test_move_taller_with_slipping(lakilester->collisionChannel, &x, &y, &z,
            4.0f, moveAngle, lakilester->collisionHeight, lakilester->collisionDiameter))
        {
            lakilester->pos.x += (x - lakilester->pos.x) / 5.0f;
            lakilester->pos.z += (z - lakilester->pos.z) / 5.0f;
        }

        moveAngle = 270.0f;
        x = lakilester->pos.x;
        y = lakilester->moveToPos.y;
        z = lakilester->pos.z;
        if (npc_test_move_taller_with_slipping(lakilester->collisionChannel, &x, &y, &z,
            4.0f, moveAngle, lakilester->collisionHeight, lakilester->collisionDiameter))
        {
            lakilester->pos.x += (x - lakilester->pos.x) / 5.0f;
            lakilester->pos.z += (z - lakilester->pos.z) / 5.0f;
        }
    }

    N(apply_riding_static_collisions)(lakilester);
    lakilester->moveToPos.y -= lakilester->jumpScale;
    hitDepth = lakilester->collisionHeight + 2;
    y = lakilester->moveToPos.y + 12.0f;
    x = playerStatus->pos.x;
    z = playerStatus->pos.z;
    add_vec2D_polar(&x, &z, 2.0f, gCameras[gCurrentCameraID].curYaw);
    raycastBelowResult = player_raycast_below_cam_relative(playerStatus, &x, &y, &z, &hitDepth, &sp40,
                                                            &sp44, &sp48, &sp4C);
    N(CurrentGroundPitch) = get_player_normal_pitch();
    height = 12.0f;

    if (N(CurrentGroundPitch) != 0.0f) {
        height = 32.0f;
    }

    if (N(CurrentGroundPitch) > 0.0f && raycastBelowResult >= 0) {
        sin_cos_rad(DEG_TO_RAD(N(CurrentGroundPitch)), &sinAngle, &cosAngle);
        lakilester->pos.y = (lakilester->pos.y + fabs((sinAngle / cosAngle) * playerStatus->runSpeed));
    }

    if (hitDepth <= height && raycastBelowResult > NO_COLLIDER) {
        playerStatus->lastGoodPos.x = lakilester->pos.x;
        playerStatus->lastGoodPos.y = lakilester->pos.y;
        playerStatus->lastGoodPos.z = lakilester->pos.z;
        collisionStatus->curFloor = raycastBelowResult;

        lakilester->curFloor = raycastBelowResult;
        lakilester->moveToPos.y = y;
        lakilester->moveToPos.x = x;
        lakilester->moveToPos.z = z;
        lakilester->jumpScale = 0.0f;
        playerStatus->timeInAir = 0;

        belowSurfaceType = get_collider_flags(raycastBelowResult) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
        if (belowSurfaceType == SURFACE_TYPE_LAVA) {
            lakilester->curAnim = ANIM_WorldLakilester_StrainWalk;
            lakilester->moveSpeed = moveSpeed * 0.5f;
        } else {
            lakilester->curAnim = ANIM_WorldLakilester_Walk;
            lakilester->moveSpeed = moveSpeed;
        }
        return;
    }

    collisionStatus->curFloor = NO_COLLIDER;
    playerStatus->timeInAir++;
    lakilester->curFloor = NO_COLLIDER;
    lakilester->jumpScale += 1.8;

    if (lakilester->jumpScale > 12.0f) {
        lakilester->jumpScale = 12.0f;
    }
}

s32 N(test_dismount_height)(f32* posY) {
    f32 colliderHeight = gPlayerStatus.colliderHeight;
    f32 hitDirX, hitDirZ;
    f32 hitRx, hitRz;
    f32 posX, posZ;

    *posY = gPlayerStatus.pos.y + colliderHeight;
    posX = gPlayerStatus.pos.x;
    posZ = gPlayerStatus.pos.z;

    return player_raycast_below_cam_relative(&gPlayerStatus, &posX, posY, &posZ,
            &colliderHeight, &hitRx, &hitRz, &hitDirX, &hitDirZ);
}

API_CALLABLE(N(UseAbility)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    Npc* lakilester = script->owner2.npc;
    f32 x, y, z, dist;
    f32 yaw, camYaw;
    s32 i;

    playerStatus->animFlags &= ~PA_FLAG_RIDING_PARTNER;

    if (isInitialCall) {
        N(try_cancel_tweester)(lakilester);
        if (!(playerStatus->animFlags & PA_FLAG_CHANGING_MAP)) {
            lakilester->flags = lakilester->flags & ~PA_FLAG_PULSE_STONE_VISIBLE;
            lakilester->moveToPos.x = lakilester->pos.x;
            lakilester->moveToPos.y = lakilester->pos.y;
            lakilester->moveToPos.z = lakilester->pos.z;

            if (gGameStatusPtr->keepUsingPartnerOnMapChange
                || (playerStatus->animFlags & PA_FLAG_PARTNER_USAGE_FORCED)
            ) {
                if (playerStatus->animFlags & PA_FLAG_PARTNER_USAGE_FORCED) {
                    playerStatus->animFlags &= ~PA_FLAG_PARTNER_USAGE_FORCED;
                }
                N(AbilityState) = RIDE_STATE_MOUNT_1;
            } else {
                N(AbilityState) = RIDE_STATE_BEGIN;
            }

            if (!partnerStatus->shouldResumeAbility) {
                if (!gGameStatusPtr->keepUsingPartnerOnMapChange) {
                    if (playerStatus->actionState == ACTION_STATE_RIDE
                     || playerStatus->actionState == ACTION_STATE_IDLE
                     || playerStatus->actionState == ACTION_STATE_WALK
                     || playerStatus->actionState == ACTION_STATE_RUN
                     || playerStatus->actionState == ACTION_STATE_FALLING
                    ) {
                        playerStatus->flags |= PS_FLAG_PAUSE_DISABLED;
                    } else {
                        return ApiStatus_DONE2;
                    }
                }
            } else {
                partnerStatus->shouldResumeAbility = FALSE;
                playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                lakilester->flags &= ~(NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_FLYING);
                lakilester->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
                set_action_state(ACTION_STATE_RIDE);
                suggest_player_anim_always_forward(ANIM_MarioW2_RideLaki);
                lakilester->curAnim = ANIM_WorldLakilester_Walk;
                N(MountState) = MOUNT_STATE_IN_PROGRESS; // unexpected
                lakilester->flags &= ~(NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_FLYING);
                lakilester->flags |= (NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_TOUCHES_GROUND);
                partnerStatus->actingPartner = PARTNER_LAKILESTER;
                partnerStatus->partnerActionState = PARTNER_ACTION_LAKILESTER_1;
                gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
                lakilester->pos.x = playerStatus->pos.x;
                lakilester->pos.y = lakilester->moveToPos.y;
                lakilester->pos.z = playerStatus->pos.z;
                lakilester->curAnim = ANIM_WorldLakilester_Walk;
                playerStatus->pos.y = lakilester->pos.y + 10.0f;
                lakilester->moveSpeed = 3.0f;
                lakilester->jumpScale = 0.0f;
                lakilester->yaw = playerStatus->targetYaw;
                suggest_player_anim_always_forward(ANIM_MarioW2_RideLaki);
                set_action_state(ACTION_STATE_RIDE);
                disable_player_static_collisions();
                N(PlayerCollisionDisabled) = TRUE;

                if (!N(LockingPlayerInput)) {
                    disable_player_input();
                    N(LockingPlayerInput) = TRUE;
                }

                N(PlayerBounceOffset) = 0;
                N(AbilityState) = RIDE_STATE_RIDING;
                lakilester->flags |= NPC_FLAG_IGNORE_WORLD_COLLISION;
            }
        } else {
            return ApiStatus_DONE2;
        }
    }

    switch (N(AbilityState)) {
        case RIDE_STATE_BEGIN:
            if (playerStatus->flags & PS_FLAG_HIT_FIRE || playerStatus->inputDisabledCount != 0) {
                playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                return ApiStatus_DONE2;
            }
            script->functionTemp[1] = 3;
            script->functionTemp[2] = disable_player_input();
            N(LockingPlayerInput) = TRUE;
            N(AbilityState)++; // RIDE_STATE_DELAY
            break;
        case RIDE_STATE_DELAY:
            if (playerStatus->flags & PS_FLAG_HIT_FIRE) {
                playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                if (N(LockingPlayerInput)) {
                    enable_player_input();
                    N(LockingPlayerInput) = FALSE;
                }
                return ApiStatus_DONE2;
            }

            if (playerStatus->animFlags & PA_FLAG_CHANGING_MAP) {
                if (script->functionTemp[2] < playerStatus->inputDisabledCount) {
                    enable_player_input();
                    N(LockingPlayerInput) = FALSE;
                }
                playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                return ApiStatus_DONE2;
            }

            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] < playerStatus->inputDisabledCount) {
                    enable_player_input();
                    N(LockingPlayerInput) = FALSE;
                    playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                    return ApiStatus_DONE2;
                }
                N(AbilityState) = RIDE_STATE_MOUNT_1;
                break;
            }
            script->functionTemp[1]--;
            break;
    }

    switch (N(AbilityState)) {
        case RIDE_STATE_MOUNT_1:
            disable_player_static_collisions();
            N(PlayerCollisionDisabled) = TRUE;

            if (!N(LockingPlayerInput)) {
                disable_player_input();
                N(LockingPlayerInput) = TRUE;
            }

            lakilester->flags &= ~NPC_FLAG_FLYING;
            lakilester->flags |= (NPC_FLAG_TOUCHES_GROUND | NPC_FLAG_IGNORE_PLAYER_COLLISION);
            set_action_state(ACTION_STATE_RIDE);
            N(MountState) = MOUNT_STATE_IN_PROGRESS;
            partner_force_player_flip_done();
            lakilester->moveToPos.x = playerStatus->pos.x;
            lakilester->moveToPos.y = playerStatus->pos.y;
            lakilester->moveToPos.z = playerStatus->pos.z;
            yaw = 0.0f;

            for (i = 0; i < 4; i++) {
                x = lakilester->moveToPos.x;
                y = lakilester->moveToPos.y;
                z = lakilester->moveToPos.z;
                npc_test_move_simple_with_slipping(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, lakilester->moveSpeed,
                                                    yaw, lakilester->collisionHeight, lakilester->collisionDiameter);
                lakilester->moveToPos.x = x;
                lakilester->moveToPos.y = y;
                lakilester->moveToPos.z = z;
                yaw += 90.0f;
            }

            lakilester->yaw = atan2(lakilester->pos.x, lakilester->pos.z, lakilester->moveToPos.x, lakilester->moveToPos.z);
            lakilester->duration = 12;
            lakilester->curAnim = ANIM_WorldLakilester_Walk;
            lakilester->jumpVel = 8.0f;
            lakilester->jumpScale = 1.4f;
            suggest_player_anim_allow_backward(ANIM_Mario1_BeforeJump);
            N(AbilityState) = RIDE_STATE_MOUNT_2;
            break;
        case RIDE_STATE_MOUNT_2:
            sfx_play_sound_at_npc(SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT, NPC_PARTNER);
            suggest_player_anim_allow_backward(ANIM_Mario1_Jump);
            // fallthrough
        case RIDE_STATE_MOUNT_3:
            N(AbilityState)++;
            // fallthrough
        case RIDE_STATE_MOUNT_4:
            if (!(playerStatus->flags & PS_FLAG_HIT_FIRE)) {
                lakilester->pos.x += (lakilester->moveToPos.x - lakilester->pos.x) / lakilester->duration;
                lakilester->pos.z += (lakilester->moveToPos.z - lakilester->pos.z) / lakilester->duration;
                lakilester->pos.y += (lakilester->moveToPos.y - lakilester->pos.y) / lakilester->duration;
                playerStatus->pos.y += lakilester->jumpVel;
                N(test_mounting_height_adjustment)(lakilester, playerStatus->colliderHeight, 2 * playerStatus->colliderHeight);
                playerStatus->pos.y += N(MountingDeltaY);
                lakilester->pos.y += N(MountingDeltaY);
                lakilester->jumpVel -= lakilester->jumpScale;

                if (lakilester->jumpVel <= 0.0f) {
                    suggest_player_anim_allow_backward(ANIM_Mario1_Fall);
                }

                lakilester->duration--;

                if (lakilester->duration > 0) {
                    if (lakilester->duration == 1) {
                        add_vec2D_polar(&lakilester->pos.x, &lakilester->pos.z, -2.0f,
                                        gCameras[gCurrentCameraID].curYaw);
                    }
                } else {
                    playerStatus->pos.y = lakilester->pos.y + 10.0f;
                    lakilester->moveSpeed = playerStatus->runSpeed;
                    lakilester->jumpScale = 0.0f;
                    lakilester->yaw = playerStatus->targetYaw;
                    lakilester->duration = 3;
                    set_action_state(ACTION_STATE_RIDE);
                    suggest_player_anim_always_forward(ANIM_MarioW2_RideLaki);
                    disable_player_shadow();
                    partnerStatus->actingPartner = PARTNER_LAKILESTER;
                    partnerStatus->partnerActionState = PARTNER_ACTION_LAKILESTER_1;
                    playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                    gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
                    N(PlayerBounceOffset) = 0;
                    N(MountState) = MOUNT_STATE_DONE;
                    N(offset_player_from_camera)(2.0f);
                    N(AbilityState) = RIDE_STATE_START_RIDING;
                    playerStatus->animFlags |= PA_FLAG_RIDING_PARTNER;
                }
            } else {
                N(AbilityState) = RIDE_STATE_FINISH_1;
            }
            break;
        case RIDE_STATE_START_RIDING:
            if (playerStatus->flags & PS_FLAG_HIT_FIRE) {
                N(AbilityState) = RIDE_STATE_FINISH_1;
                break;
            }
            lakilester->duration--;
            if (lakilester->duration != 0) {
                if (partnerStatus->pressedButtons & (BUTTON_B | D_CBUTTONS)) {
                    if (N(can_dismount)()) {
                        N(AbilityState) = RIDE_STATE_DISMOUNT_1;
                    }
                }
                break;
            } else {
                N(AbilityState) = RIDE_STATE_RIDING;
                lakilester->flags |= NPC_FLAG_IGNORE_WORLD_COLLISION;
            }
            // fallthrough
        case RIDE_STATE_RIDING:
            N(update_riding_physics)(lakilester);
            playerStatus->animFlags |= PA_FLAG_RIDING_PARTNER;
            lakilester->pos.y = lakilester->moveToPos.y + 2.0f;

            N(PlayerBounceOffset)++;
            if (N(PlayerBounceOffset) >= 10) {
                N(PlayerBounceOffset) -= 18;
            }

            if (partnerStatus->inputDisabledCount == 0) {
                playerStatus->targetYaw = lakilester->yaw;
            }
            if (playerStatus->flags & PS_FLAG_HIT_FIRE) {
                N(AbilityState) = RIDE_STATE_FINISH_1;
                break;
            }
            if (partnerStatus->pressedButtons & (BUTTON_B | D_CBUTTONS)) {
                if (N(can_dismount)()) {
                    N(AbilityState) = RIDE_STATE_DISMOUNT_1;
                } else {
                    if (!(playerStatus->animFlags & PA_FLAG_FORCED_PARTNER_ABILITY_END)) {
                        sfx_play_sound_at_npc(SOUND_MENU_ERROR, SOUND_SPACE_DEFAULT, NPC_PARTNER);
                    }
                    playerStatus->animFlags &= ~PA_FLAG_FORCED_PARTNER_ABILITY_END;
                }
            }
            break;
        case RIDE_STATE_DISMOUNT_1:
            lakilester->flags &= ~NPC_FLAG_IGNORE_WORLD_COLLISION;
            playerStatus->flags |= PS_FLAG_PAUSE_DISABLED;
            N(can_dismount)();
            camYaw = camera->curYaw;
            if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
                yaw = (180.0f + camYaw) - 90.0f;
            } else {
                yaw = (0.0f + camYaw) - 90.0f;
            }
            lakilester->yaw = yaw;
            dist = dist2D(playerStatus->pos.x, playerStatus->pos.z,
                            lakilester->moveToPos.x, lakilester->moveToPos.z);
            lakilester->yaw = atan2(playerStatus->pos.x, playerStatus->pos.z,
                            lakilester->moveToPos.x, lakilester->moveToPos.z);
            lakilester->duration = 14;
            lakilester->jumpScale = 1.2f;

            if (lakilester->moveToPos.y > lakilester->pos.y) {
                lakilester->jumpVel = 6.0f + (lakilester->moveToPos.y - lakilester->pos.y) / 14.0f;
            } else {
                lakilester->jumpVel = 6.0f;
            }

            lakilester->moveSpeed = dist / lakilester->duration;
            suggest_player_anim_allow_backward(ANIM_Mario1_BeforeJump);
            N(AbilityState)++;
            break;
        case RIDE_STATE_DISMOUNT_2:
            suggest_player_anim_allow_backward(ANIM_Mario1_Jump);
            N(AbilityState)++;
            // fallthrough
        case RIDE_STATE_DISMOUNT_3:
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
            playerStatus->pos.y += lakilester->jumpVel;
            dist = playerStatus->colliderHeight * 0.5f;

            x = playerStatus->pos.x;
            y = playerStatus->pos.y + (playerStatus->colliderHeight * 0.5f);
            z = playerStatus->pos.z;

            yaw = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw;

            if (player_raycast_up_corners(playerStatus, &x, &y, &z, &dist, yaw) >= 0) {
                N(AbilityState) = RIDE_STATE_FINISH_1;
                break;
            }

            lakilester->jumpVel -= lakilester->jumpScale;
            add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, lakilester->moveSpeed, lakilester->yaw);

            func_800E4AD8(0);
            if (N(test_dismount_height)(&y) > NO_COLLIDER) {
                N(AbilityState) = RIDE_STATE_FINISH_1;
                playerStatus->pos.y = y;
            }
            break;
        }

        gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
        gCameras[CAM_DEFAULT].targetPos.y = lakilester->moveToPos.y;
        gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;

        if (N(AbilityState) == RIDE_STATE_FINISH_1) {
            N(MountState) = MOUNT_STATE_NONE;
            lakilester->flags &= ~(NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_TOUCHES_GROUND | NPC_FLAG_FLYING);

            if (N(PlayerCollisionDisabled)) {
                N(PlayerCollisionDisabled) = FALSE;
                enable_player_static_collisions();
            }

            enable_player_shadow();
            gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;

            if (playerStatus->flags & PS_FLAG_HIT_FIRE) {
                partnerStatus->actingPartner = PARTNER_NONE;
                partnerStatus->partnerActionState = PARTNER_ACTION_NONE;

                if (N(LockingPlayerInput)) {
                    N(LockingPlayerInput) = FALSE;
                    enable_player_input();
                }

                partner_clear_player_tracking(lakilester);
                set_action_state(ACTION_STATE_HIT_FIRE);
                playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
                return ApiStatus_DONE1;
            }

            set_action_state(ACTION_STATE_FALLING);
            gravity_use_fall_parms();
            N(AbilityState) = RIDE_STATE_FINISH_2;
            return ApiStatus_BLOCK;
        }

        if (N(AbilityState) == RIDE_STATE_FINISH_2) {
            lakilester->flags &= ~(NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_TOUCHES_GROUND | NPC_FLAG_FLYING);
            partnerStatus->actingPartner = PARTNER_NONE;
            partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
            playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;
            if (N(LockingPlayerInput)) {
                N(LockingPlayerInput) = FALSE;
                enable_player_input();
            }

            gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
            partner_clear_player_tracking(lakilester);
            func_800EF3D4(2);
            return ApiStatus_DONE1;
        }

        return ApiStatus_BLOCK;
}

EvtScript EVS_WorldLakilester_UseAbility = {
    EVT_CALL(N(UseAbility))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(PutAway)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    Camera* cam = &gCameras[CAM_DEFAULT];
    Npc* lakilester = script->owner2.npc;
    f32 sp20, sp24, sp28, sp2C;
    f32 yaw;

    if (isInitialCall) {
        N(PutAwayState) = (N(MountState) == MOUNT_STATE_NONE) ? PUT_AWAY_FINISH_1 : PUT_AWAY_DISMOUNT_1;
        partner_init_put_away(lakilester);
        N(can_dismount)();
        playerStatus->animFlags &= ~PA_FLAG_RIDING_PARTNER;
        playerStatus->flags |= PS_FLAG_PAUSE_DISABLED;
    }

    switch (N(PutAwayState)) {
        case PUT_AWAY_DISMOUNT_1:
            N(can_dismount)();
            yaw = cam->curYaw;
            if ((playerStatus->spriteFacingAngle >= 90.0f) && (playerStatus->spriteFacingAngle < 270.0f)) {
                lakilester->yaw = (yaw + 180.0f) - 90.0f;
            } else {
                lakilester->yaw = (yaw + 0.0f) - 90.0f;
            }

            sp2C = dist2D(playerStatus->pos.x, playerStatus->pos.z,
                          lakilester->moveToPos.x, lakilester->moveToPos.z);
            lakilester->duration = 14;

            if (lakilester->moveToPos.y > lakilester->pos.y ) {
                lakilester->jumpVel = (lakilester->moveToPos.y - lakilester->pos.y) / 14.0f + 6.0f;
            } else {
                lakilester->jumpVel = 6.0f;
            }
            lakilester->jumpScale = 1.2f;
            lakilester->moveSpeed = sp2C / lakilester->duration;
            lakilester->yaw = atan2(playerStatus->pos.x, playerStatus->pos.z,
                                 lakilester->moveToPos.x, lakilester->moveToPos.z);
            suggest_player_anim_allow_backward(ANIM_Mario1_BeforeJump);
            N(PutAwayState)++;
            break;
        case PUT_AWAY_DISMOUNT_2:
            suggest_player_anim_allow_backward(ANIM_Mario1_Jump);
            N(PutAwayState)++;
        case PUT_AWAY_DISMOUNT_3:
            playerStatus->pos.y += lakilester->jumpVel;
            lakilester->jumpVel -= lakilester->jumpScale;
            add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z,
                            lakilester->moveSpeed, lakilester->yaw);
            func_800E4AD8(0);
            if (lakilester->jumpVel <= 0.0f) {
                playerStatus->flags |= PS_FLAG_FALLING;
                if (lakilester->jumpVel < -10.0) {
                    lakilester->jumpVel = -10.0f;
                }
            }
            sp20 = playerStatus->pos.x;
            sp24 = playerStatus->pos.y + playerStatus->colliderHeight;
            sp28 = playerStatus->pos.z;
            sp2C = playerStatus->colliderHeight;
            if (npc_raycast_down_around(0, &sp20, &sp24, &sp28, &sp2C,
                                       lakilester->yaw, lakilester->collisionDiameter)) {

                N(PutAwayState) = PUT_AWAY_FINISH_1;
                playerStatus->pos.y = sp24;
            }
            break;
    }

    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;

    switch (N(PutAwayState)) {
        case PUT_AWAY_FINISH_1:
            lakilester->flags &= ~(NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_FLYING);

            if (N(PlayerCollisionDisabled)) {
                N(PlayerCollisionDisabled) = FALSE;
                enable_player_static_collisions();
            }

            enable_player_shadow();

            if (playerStatus->flags & PS_FLAG_HIT_FIRE) {
                partnerStatus->actingPartner = PARTNER_NONE;
                partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
                if (N(LockingPlayerInput)) {
                    N(LockingPlayerInput) = FALSE;
                    enable_player_input();
                }

                gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
                N(MountState) = MOUNT_STATE_NONE;
                partner_clear_player_tracking(lakilester);
                set_action_state(ACTION_STATE_HIT_FIRE);
                return ApiStatus_DONE1;
            }

            if (N(MountState) == MOUNT_STATE_NONE) {
                phys_main_collision_below();
            } else {
                set_action_state(ACTION_STATE_FALLING);
                gravity_use_fall_parms();
            }

            N(PutAwayState)++;
            break;
        case PUT_AWAY_FINISH_2:
            partnerStatus->actingPartner = PARTNER_NONE;
            partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
            playerStatus->flags &= ~PS_FLAG_PAUSE_DISABLED;

            if (N(LockingPlayerInput)) {
                N(LockingPlayerInput) = FALSE;
                enable_player_input();
            }
            gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
            N(MountState) = MOUNT_STATE_NONE;
            partner_clear_player_tracking(lakilester);
            N(PutAwayState)++;
            break;
        case PUT_AWAY_FINISH_3:
            if (partner_put_away(lakilester)) {
                return ApiStatus_DONE1;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldLakilester_PutAway = {
    EVT_CALL(N(PutAway))
    EVT_RETURN
    EVT_END
};

void N(pre_battle)(Npc* lakilester) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (N(MountState) != MOUNT_STATE_NONE) {
        partnerStatus->npc = *lakilester;
        partnerStatus->shouldResumeAbility = TRUE;
        enable_player_static_collisions();
        enable_player_input();
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(lakilester);
    }

    partnerStatus->actingPartner = PARTNER_LAKILESTER;
    N(PlayerBounceOffset) = 0;
}

void N(post_battle)(Npc* lakilester) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (partnerStatus->shouldResumeAbility) {
        if (N(MountState) != MOUNT_STATE_NONE) {
            *lakilester = partnerStatus->npc;
            gGameStatusPtr->keepUsingPartnerOnMapChange = TRUE;
            set_action_state(ACTION_STATE_RIDE);
            partnerStatus->actingPartner = PARTNER_NONE;
            partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
            disable_player_input();
            partner_use_ability();
        }
    }
}

void N(offset_player_from_camera)(f32 speed) {
    Camera* currentCamera = &gCameras[gCurrentCameraID];
    PlayerStatus* playerStatus = &gPlayerStatus;

    add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, speed, currentCamera->curYaw);
}

API_CALLABLE(N(EnterMap)) {
    PartnerStatus* partnerStatus = &gPartnerStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* lakilester = get_npc_unsafe(NPC_PARTNER);
    f32 temp_f0, temp_f2, temp_f4;
    f32* temp_s0_2;
    s32 temp_v0_2;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            if (!script->varTable[12]) {
                temp_f0 = playerStatus->pos.x;
                lakilester->pos.x = temp_f0;
                lakilester->moveToPos.x = temp_f0;
                temp_f4 = playerStatus->pos.z;
                lakilester->pos.z = temp_f4;
                lakilester->moveToPos.z = temp_f4;
                playerStatus->pos.y = lakilester->pos.y + 10.0f;
                partner_kill_ability_script();
            } else {
                set_action_state(ACTION_STATE_RIDE);
                disable_player_static_collisions();
                disable_player_input();
                lakilester->moveToPos.x = lakilester->pos.x = playerStatus->pos.x;
                lakilester->moveToPos.y = lakilester->pos.y = playerStatus->pos.y;
                lakilester->moveToPos.z = lakilester->pos.z = playerStatus->pos.z;
                playerStatus->pos.y = lakilester->pos.y + 10.0f;
            }

            script->functionTemp[1] = script->varTable[4];
            temp_s0_2 = (f32*)&script->varTable[5];
            temp_f2 = atan2(lakilester->pos.x, lakilester->pos.z, script->varTable[1], script->varTable[3]);
            lakilester->yaw = temp_f2;

            if (script->varTable[12]) {
                if (temp_f2 >= 0.0f && temp_f2 <= 180.0f) {
                    lakilester->yawCamOffset = temp_f2;
                    lakilester->isFacingAway = TRUE;
                }
            }

            sfx_play_sound_at_npc(SOUND_FLIGHT, SOUND_SPACE_DEFAULT, NPC_PARTNER);
            playerStatus->anim = ANIM_MarioW2_RideLaki;
            playerStatus->animNotifyValue = 0;
            playerStatus->flags |= PS_FLAG_FACE_FORWARD;
            N(offset_player_from_camera)(2.0f);
            gGameStatusPtr->keepUsingPartnerOnMapChange = TRUE;
            lakilester->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
            lakilester->moveSpeed = *temp_s0_2;
            lakilester->jumpScale = 0.0f;
            N(UpdatePushingWall) = FALSE;
            N(PlayerBounceOffset) = 0;
            script->functionTemp[0] = 1;
            break;

        case 1:
            npc_move_heading(lakilester, lakilester->moveSpeed, lakilester->yaw);
            playerStatus->pos.x = lakilester->pos.x;
            playerStatus->pos.y = lakilester->pos.y + 10.0f;
            playerStatus->pos.z = lakilester->pos.z;
            playerStatus->targetYaw = lakilester->yaw;
            N(offset_player_from_camera)(2.0f);
            script->functionTemp[1] -= 1;

            if (script->functionTemp[1] == 0) {
                if (script->varTable[12]) {
                    partnerStatus->shouldResumeAbility = TRUE;
                    set_action_state(ACTION_STATE_RIDE);
                    partnerStatus->actingPartner = PARTNER_NONE;
                    partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
                    partner_use_ability();
                    enable_player_static_collisions();
                    enable_player_input();
                }
                return ApiStatus_DONE2;
            }
    }

    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldLakilester_EnterMap = {
    EVT_CALL(N(EnterMap))
    EVT_RETURN
    EVT_END
};

MATCHING_BSS(0xB0);
