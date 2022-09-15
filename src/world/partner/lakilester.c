#include "common.h"
#include "../partners.h"
#include "effects.h"

extern s16 D_8010C97A;

BSS s32 D_802BFF00;
BSS s32 D_802BFF04;
BSS s32 D_802BFF08;
BSS s32 D_802BFF0C;
BSS s32 D_802BFF10;
BSS s32 D_802BFF14;
BSS s32 D_802BFF18;
BSS s32 D_802BFF1C;
BSS s32 D_802BFF20;
BSS s32 D_802BFF24;
BSS f32 D_802BFF28;
BSS s32 D_802BFF2C;
BSS TweesterPhysics LakilesterTweesterPhysics;

void func_802BD100_320C50(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* lakilester = get_npc_unsafe(NPC_PARTNER);
    s32 playerFlags = playerStatus->flags;
    Camera* currentCamera;
    f32 playerSpeedCopy;
    s32 temp_v0_2;

    if (playerFlags & PS_FLAGS_4000) {
        playerSpeedCopy = playerStatus->currentSpeed;
        if (playerFlags & PS_FLAGS_40000) {
            playerSpeedCopy *= 0.5f;
        }

        add_vec2D_polar(&lakilester->pos.x, &lakilester->pos.z, playerSpeedCopy, playerStatus->heading);
        lakilester->yaw = playerStatus->targetYaw;
    }

    temp_v0_2 = abs(D_802BFF18);
    playerStatus->position.x = lakilester->pos.x;
    playerStatus->position.y = lakilester->pos.y + 10.0f + (temp_v0_2 * 0.34f);
    playerStatus->position.z = lakilester->pos.z;
    currentCamera = &gCameras[gCurrentCameraID];
    add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, 2.0f, currentCamera->currentYaw);
}

void world_lakilester_init(Npc* npc) {
    npc->collisionHeight = 38;
    npc->collisionRadius = 36;
    npc->collisionChannel = 0x10000;
    D_802BFF18 = 0;
    D_802BFF04 = 0;
    D_802BFF08 = 0;
    D_802BFF0C = 0;
    D_802BFF10 = 1;
    D_802BFF1C = 0;
    D_802BFF20 = 0;
    D_802BFF24 = 0;
    D_802BFF28 = 0;
    npc->moveToPos.x = npc->pos.x;
    npc->moveToPos.y = npc->pos.y;
    npc->moveToPos.z = npc->pos.z;
}

ApiStatus func_802BD29C_320DEC(Evt* script, s32 isInitialCall) {
    Npc* lakilester = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(lakilester);
    }

    return partner_get_out(lakilester) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_lakilester_take_out = {
    EVT_CALL(func_802BD29C_320DEC)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* LakilesterTweesterPhysicsPtr = &LakilesterTweesterPhysics;

ApiStatus func_802BD2D4_320E24(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* lakilester = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_flying_enable(lakilester, 1);
        mem_clear(LakilesterTweesterPhysicsPtr, sizeof(TweesterPhysics));
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

    switch (LakilesterTweesterPhysicsPtr->state) {
        case 0:
            LakilesterTweesterPhysicsPtr->state = 1;
            LakilesterTweesterPhysicsPtr->prevFlags = lakilester->flags;
            LakilesterTweesterPhysicsPtr->radius = fabsf(dist2D(lakilester->pos.x, lakilester->pos.z, entity->position.x, entity->position.z));
            LakilesterTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, lakilester->pos.x, lakilester->pos.z);
            LakilesterTweesterPhysicsPtr->angularVelocity = 6.0f;
            LakilesterTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            LakilesterTweesterPhysicsPtr->countdown = 120;
            lakilester->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            lakilester->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad(DEG_TO_RAD(LakilesterTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);
            lakilester->pos.x = entity->position.x + (sinAngle * LakilesterTweesterPhysicsPtr->radius);
            lakilester->pos.z = entity->position.z - (cosAngle * LakilesterTweesterPhysicsPtr->radius);
            LakilesterTweesterPhysicsPtr->angle = clamp_angle(LakilesterTweesterPhysicsPtr->angle - LakilesterTweesterPhysicsPtr->angularVelocity);

            if (LakilesterTweesterPhysicsPtr->radius > 20.0f) {
                LakilesterTweesterPhysicsPtr->radius--;
            } else if (LakilesterTweesterPhysicsPtr->radius < 19.0f) {
                LakilesterTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(LakilesterTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
            LakilesterTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (LakilesterTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                LakilesterTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            lakilester->pos.y += liftoffVelocity;
            lakilester->renderYaw = clamp_angle(360.0f - LakilesterTweesterPhysicsPtr->angle);
            LakilesterTweesterPhysicsPtr->angularVelocity += 0.8;

            if (LakilesterTweesterPhysicsPtr->angularVelocity > 40.0f) {
                LakilesterTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--LakilesterTweesterPhysicsPtr->countdown == 0) {
                LakilesterTweesterPhysicsPtr->state++;
            }
            break;
        case 2:
            lakilester->flags = LakilesterTweesterPhysicsPtr->prevFlags;
            LakilesterTweesterPhysicsPtr->countdown = 30;
            LakilesterTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_flying_update_player_tracking(lakilester);
            partner_flying_update_motion(lakilester);

            if (--LakilesterTweesterPhysicsPtr->countdown == 0) {
                LakilesterTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript world_lakilester_update = {
    EVT_CALL(func_802BD2D4_320E24)
    EVT_RETURN
    EVT_END
};

void func_802BD678_3211C8(Npc* npc) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        npc->flags = LakilesterTweesterPhysicsPtr->prevFlags;
        LakilesterTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking(npc);
    }
}

void func_802BD6BC_32120C(f32* outAngle, f32* outMagnitude) {
    PartnerActionStatus* lakilesterActionStatus = &gPartnerActionStatus;
    f32 stickX = lakilesterActionStatus->stickX;
    f32 stickY = lakilesterActionStatus->stickY;
    f32 angle = clamp_angle(atan2(0.0f, 0.0f, stickX, -stickY) + gCameras[CAM_DEFAULT].currentYaw);
    f32 magnitude = 0.0f;

    if (dist2D(0.0f, 0.0f, stickX, -stickY) >= 1.0) {
        magnitude = 3.0f;
        if (SQ(stickX) + SQ(stickY) > 3025.0f) {
            magnitude = 6.0f;
        }
    }

    *outAngle = angle;
    *outMagnitude = magnitude;
}

s32 func_802BD7DC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* currentCamera;
    f32 hitDirX, hitDirZ;
    f32 hitRx, hitRz;
    f32 outX, outY, outZ, outLength;
    Npc* npc = get_npc_unsafe(NPC_PARTNER);
    s32 colliderTypeID;
    s32 raycastResult;
    s32 ret;

    if (playerStatus->animFlags & PA_FLAGS_20000000) {
        playerStatus->animFlags &= ~PA_FLAGS_20000000;
        return TRUE;
    }

    ret = FALSE;
    outLength = 16.0f;
    outY = npc->moveToPos.y + 7.0f;
    outX = playerStatus->position.x;
    outZ = playerStatus->position.z;
    currentCamera = &gCameras[gCurrentCameraID];
    add_vec2D_polar(&outX, &outZ, 2.0f, currentCamera->currentYaw);
    raycastResult = player_raycast_below_cam_relative(playerStatus, &outX, &outY, &outZ, &outLength, &hitRx, &hitRz,
                                                      &hitDirX, &hitDirZ);
    colliderTypeID = raycastResult;

    //TODO find better match
    if (outLength <= 16.0f && colliderTypeID >= 0) {
        if (!(colliderTypeID & COLLISION_WITH_ENTITY_BIT) || !(get_entity_type(colliderTypeID) - 0x2E < 2)){
            colliderTypeID = get_collider_flags(colliderTypeID) & 0xFF; //TODO surface type
            if (!(colliderTypeID == SURFACE_TYPE_WATER || colliderTypeID == SURFACE_TYPE_SPIKES || colliderTypeID == SURFACE_TYPE_LAVA)) { //
                ret = FALSE;
                if (colliderTypeID != SURFACE_TYPE_SLIDE) {
                    npc->moveToPos.x = outX;
                    npc->moveToPos.y = outY;
                    npc->moveToPos.z = outZ;
                    ret = TRUE;
                }
            }
        }
    }

    return ret;
}

s32 func_802BD99C_3214EC(Npc* partner, f32 yOffset, f32 zOffset) {
    f32 outX = gPlayerStatus.position.x;
    f32 outY = gPlayerStatus.position.y + yOffset;
    f32 outZ = gPlayerStatus.position.z;
    f32 outLength = zOffset;
    f32 hitRx, hitRz;
    f32 hitDirX, hitDirZ;
    f32 temp_f4;

    D_802BFF24 = 0;

    if (player_raycast_below_cam_relative(&gPlayerStatus, &outX, &outY, &outZ, &outLength, &hitRx, &hitRz,
                                          &hitDirX, &hitDirZ) >= 0) {
        temp_f4 = outY - partner->moveToPos.y;
        if (temp_f4 != 0.0f) {
            if (fabs(temp_f4) < 10.0) {
                D_802BFF24 = temp_f4;
                partner->moveToPos.y = outY;
                return TRUE;
            } else {
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

void func_802BDA90_3215E0(Npc* lakilester) {
    f32 temp_f20 = lakilester->collisionRadius * 0.8f;
    f32 temp_f0 = clamp_angle(lakilester->yaw);
    f32 x = lakilester->pos.x;
    f32 y = lakilester->moveToPos.y;
    f32 z = lakilester->pos.z;

    if (npc_test_move_complex_with_slipping(lakilester->collisionChannel, &x, &y, &z, 0.0f, temp_f0, lakilester->collisionHeight, temp_f20)) {
        lakilester->flags |= (NPC_FLAG_4000 | NPC_FLAG_NO_PROJECT_SHADOW);
        lakilester->currentWall = D_8010C97A;
        lakilester->pos.x = x;
        lakilester->pos.z = z;
    } else {
        lakilester->flags &= ~(NPC_FLAG_4000 | NPC_FLAG_NO_PROJECT_SHADOW);
    }

    temp_f0 = clamp_angle(lakilester->yaw + 45.0f);
    x = lakilester->pos.x;
    y = lakilester->moveToPos.y;
    z = lakilester->pos.z;

    if (npc_test_move_taller_with_slipping(lakilester->collisionChannel, &x, &y, &z, 0.0f, temp_f0, lakilester->collisionHeight, temp_f20)) {
        lakilester->pos.x = x;
        lakilester->pos.z = z;
        lakilester->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
    } else {
        lakilester->flags &= ~NPC_FLAG_NO_PROJECT_SHADOW;
    }

    temp_f0 = clamp_angle(lakilester->yaw - 45.0f);
    x = lakilester->pos.x;
    y = lakilester->moveToPos.y;
    z = lakilester->pos.z;

    if (npc_test_move_taller_with_slipping(lakilester->collisionChannel, &x, &y, &z, 0.0f, temp_f0, lakilester->collisionHeight, temp_f20)) {
        lakilester->pos.x = x;
        lakilester->pos.z = z;
        lakilester->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
    } else {
        lakilester->flags &= ~NPC_FLAG_NO_PROJECT_SHADOW;
    }

    temp_f0 = clamp_angle(lakilester->yaw + 45.0f + 180.0f);
    x = lakilester->pos.x;
    y = lakilester->moveToPos.y;
    z = lakilester->pos.z;

    if (npc_test_move_simple_with_slipping(lakilester->collisionChannel, &x, &y, &z, 0.0f, temp_f0, lakilester->collisionHeight, temp_f20)) {
        lakilester->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
        lakilester->pos.x = x;
        lakilester->pos.z = z;
    } else {
        lakilester->flags &= ~NPC_FLAG_NO_PROJECT_SHADOW;
    }

    temp_f0 = clamp_angle(lakilester->yaw - 45.0f + 180.0f);
    x = lakilester->pos.x;
    y = lakilester->moveToPos.y;
    z = lakilester->pos.z;

    if (npc_test_move_simple_with_slipping(lakilester->collisionChannel, &x, &y, &z, 0.0f, temp_f0, lakilester->collisionHeight, temp_f20)) {
        lakilester->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
        lakilester->pos.x = x;
        lakilester->pos.z = z;
    } else {
        lakilester->flags &= ~NPC_FLAG_NO_PROJECT_SHADOW;
    }
}

void func_802BDDD8_321928(Npc* npc) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    f32 hitDepth, sp40, sp44, sp48, sp4C, sp50, sp54;
    f32 yaw = 0.0f;
    f32 moveSpeed = 0.0f;
    f32 x, y, z;
    f32 temp_f0_3;
    s32 raycastBelowResult;
    s32 currentSurfaceType;
    s32 belowSurfaceType;
    s32 pitchShift;
    f32 height;

    func_802BD6BC_32120C(&yaw, &moveSpeed);

    currentSurfaceType = get_collider_flags(npc->currentFloor) & 0xFF;
    if (currentSurfaceType == SURFACE_TYPE_LAVA) {
        moveSpeed *= 0.5f;
    }

    if (D_802BFF28 >= 20.0f) {
        moveSpeed *= 0.8f;
    }

    npc->moveSpeed = moveSpeed;

    if (moveSpeed != 0.0f) {
        D_802BFF1C += 1;
        D_802BFF20 += 1;
        if (!(D_802BFF1C & 7)) {
            if (D_802BFF20 >= 120) {
                D_802BFF20 = 0;
            }

            if (D_802BFF20 < 0x3C) {
                pitchShift = update_lerp(0,  0.0f, 100.0f, D_802BFF20, 60);
                sfx_play_sound_with_params(SOUND_295, 0, 0x40, pitchShift);
            } else {
                pitchShift = update_lerp(0, 100.0f, 0.0f, D_802BFF20 - 60, 60);
                sfx_play_sound_with_params(SOUND_295, 0, 0x40, pitchShift);
            }
        }
    }

    x = npc->pos.x;
    y = npc->moveToPos.y;
    z = npc->pos.z;

    if (npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, npc->collisionRadius, npc->yaw,
        npc->collisionHeight, npc->collisionRadius) != 0) {

        collisionStatus->currentInspect = (partnerActionStatus->pressedButtons & BUTTON_A) ? D_8010C97A : -1;
    }

    if (moveSpeed != 0.0f) {
        npc->yaw = yaw;
        x = npc->pos.x;
        y = npc->moveToPos.y;
        z = npc->pos.z;

        if (npc_test_move_complex_with_slipping(npc->collisionChannel, &x, &y, &z, npc->moveSpeed, npc->yaw,
            npc->collisionHeight, npc->collisionRadius) != 0) {

            if (D_802BFF10) {
                collisionStatus->pushingAgainstWall = D_8010C97A;
            }
            npc->pos.x += (x - npc->pos.x) / 5.0f;
            npc->pos.z += (z - npc->pos.z) / 5.0f;
        } else {
            npc_move_heading(npc, npc->moveSpeed, yaw);
            if (D_802BFF10) {
                collisionStatus->pushingAgainstWall = -1;
            }
        }

        yaw = clamp_angle(npc->yaw - 30.0f);
        x = npc->pos.x;
        y = npc->moveToPos.y;
        z = npc->pos.z;

        if (npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, npc->moveSpeed, yaw,
            npc->collisionHeight, npc->collisionRadius) != 0) {

            npc->pos.x += (x - npc->pos.x) / 5.0f;
            npc->pos.z += (z - npc->pos.z) / 5.0f;
        }

        yaw = clamp_angle(npc->yaw + 30.0f);
        x = npc->pos.x;
        y = npc->moveToPos.y;
        z = npc->pos.z;
        if (npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, npc->moveSpeed, yaw,
            npc->collisionHeight, npc->collisionRadius) != 0) {

            npc->pos.x += (x - npc->pos.x) / 5.0f;
            npc->pos.z += (z - npc->pos.z) / 5.0f;
        }

        func_8003D660(npc, 1);

    } else {
        yaw = 90.0f;
        x = npc->pos.x;
        y = npc->moveToPos.y;
        z = npc->pos.z;

        if (npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, 4.0f, yaw, npc->collisionHeight,
            npc->collisionRadius) != 0) {

            npc->pos.x += (x - npc->pos.x) / 5.0f;
            npc->pos.z += (z - npc->pos.z) / 5.0f;
        }

        yaw = 270.0f;
        x = npc->pos.x;
        y = npc->moveToPos.y;
        z = npc->pos.z;

        if (npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, 4.0f, yaw, npc->collisionHeight,
            npc->collisionRadius) != 0) {

            npc->pos.x += (x - npc->pos.x) / 5.0f;
            npc->pos.z +=(z - npc->pos.z) / 5.0f;
        }
    }

    func_802BDA90_3215E0(npc);
    npc->moveToPos.y -= npc->jumpScale;
    hitDepth = npc->collisionHeight + 2;
    y = npc->moveToPos.y + 12.0f;
    x = playerStatus->position.x;
    z = playerStatus->position.z;
    add_vec2D_polar(&x, &z, 2.0f, gCameras[gCurrentCameraID].currentYaw);
    raycastBelowResult = player_raycast_below_cam_relative(playerStatus, &x, &y, &z, &hitDepth, &sp40,
                                                            &sp44, &sp48, &sp4C);
    D_802BFF28 = get_player_normal_pitch();
    height = 12.0f;

    if (D_802BFF28 != 0.0f) {
        height = 32.0f;
    }

    if (D_802BFF28 > 0.0f && raycastBelowResult >= 0) {
        sin_cos_rad(DEG_TO_RAD(D_802BFF28), &sp50, &sp54);
        npc->pos.y = (npc->pos.y + fabs((sp50 / sp54) * playerStatus->runSpeed));
    }

    if (hitDepth <= height && raycastBelowResult >= 0) {
        playerStatus->lastGoodPosition.x = npc->pos.x;
        playerStatus->lastGoodPosition.y = npc->pos.y;
        playerStatus->lastGoodPosition.z = npc->pos.z;
        collisionStatus->currentFloor = raycastBelowResult;

        npc->currentFloor = raycastBelowResult;
        npc->moveToPos.y = y;
        npc->moveToPos.x = x;
        npc->moveToPos.z = z;
        npc->jumpScale = 0.0f;
        playerStatus->timeInAir = 0;

        belowSurfaceType = get_collider_flags(raycastBelowResult) & 0xFF;
        if (belowSurfaceType == SURFACE_TYPE_LAVA) {
            npc->currentAnim = 0x80006;
            npc->moveSpeed = moveSpeed * 0.5f;
        } else {
            npc->currentAnim = 0x80005;
            npc->moveSpeed = moveSpeed;
        }
        return;
    }

    collisionStatus->currentFloor = -1;
    playerStatus->timeInAir++;
    npc->currentFloor = -1;
    npc->jumpScale += 1.8;

    if (npc->jumpScale > 12.0f) {
        npc->jumpScale = 12.0f;
    }
}

s32 func_802BE6A0_3221F0(f32* arg0) {
    f32 colliderHeight = gPlayerStatus.colliderHeight;
    f32 hitDirX, hitDirZ;
    f32 hitRx, hitRz;
    f32 x, z;

    *arg0 = gPlayerStatus.position.y + colliderHeight;
    x = gPlayerStatus.position.x;
    z = gPlayerStatus.position.z;

    player_raycast_below_cam_relative(&gPlayerStatus, &x, arg0, &z, &colliderHeight, &hitRx, &hitRz,
                                      &hitDirX, &hitDirZ);
}

ApiStatus func_802BE724_322274(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    Npc* npc = script->owner2.npc;
    s32 colliderHeightTemp;
    f32 x, y, z, sp2C;
    f32 yaw, camYaw;
    s32 i;

    playerStatus->animFlags &= ~PA_FLAGS_400000;

    if (isInitialCall) {
        func_802BD678_3211C8(npc);
        if (!(playerStatus->animFlags & PA_FLAGS_100000)) {
            npc->flags = npc->flags & ~PA_FLAGS_40;
            npc->moveToPos.x = npc->pos.x;
            npc->moveToPos.y = npc->pos.y;
            npc->moveToPos.z = npc->pos.z;

            if (gGameStatusPtr->keepUsingPartnerOnMapChange ||
                (playerStatus->animFlags & PA_FLAGS_200000)) {
                if (playerStatus->animFlags & PA_FLAGS_200000) {
                    playerStatus->animFlags &= ~PA_FLAGS_200000;
                }
                D_802BFF14 = 100;
            } else {
                D_802BFF14 = 40;
            }

            if (partnerActionStatus->partnerAction_unk_1 == 0) {
                if (gGameStatusPtr->keepUsingPartnerOnMapChange == FALSE) {
                    if (playerStatus->actionState == ACTION_STATE_RIDE ||
                        playerStatus->actionState == ACTION_STATE_IDLE ||
                        playerStatus->actionState == ACTION_STATE_WALK ||
                        playerStatus->actionState == ACTION_STATE_RUN ||
                        playerStatus->actionState == ACTION_STATE_FALLING) {

                        playerStatus->flags |= PA_FLAGS_100;
                    } else {
                        return ApiStatus_DONE2;
                    }
                }
            } else {
                partnerActionStatus->partnerAction_unk_1 = 0;
                playerStatus->flags &= ~PS_FLAGS_100;
                npc->flags &= ~(NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT);
                npc->flags |= NPC_FLAG_100;
                set_action_state(ACTION_STATE_RIDE);
                suggest_player_anim_setUnkFlag(ANIM_Mario_8000E);
                npc->currentAnim = 0x80005;
                D_802BFF0C = 1;
                npc->flags &= ~(NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT);
                npc->flags |= (NPC_FLAG_100 | NPC_FLAG_400000);
                partnerActionStatus->actingPartner = PARTNER_LAKILESTER;
                partnerActionStatus->partnerActionState = PARTNER_ACTION_LAKILESTER_1;
                gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
                npc->pos.x = playerStatus->position.x;
                npc->pos.y = npc->moveToPos.y;
                npc->pos.z = playerStatus->position.z;
                npc->currentAnim = 0x80005;
                playerStatus->position.y = npc->pos.y + 10.0f;
                npc->moveSpeed = 3.0f;
                npc->jumpScale = 0.0f;
                npc->yaw = playerStatus->targetYaw;
                suggest_player_anim_setUnkFlag(ANIM_Mario_8000E);
                set_action_state(ACTION_STATE_RIDE);
                disable_player_static_collisions();
                D_802BFF08 = 1;

                if (D_802BFF04 == 0) {
                    disable_player_input();
                    D_802BFF04 = 1;
                }

                D_802BFF18 = 0;
                D_802BFF14 = 1;
                npc->flags |= NPC_FLAG_40;
            }
        } else {
            return ApiStatus_DONE2;
        }
    }

    switch (D_802BFF14) {
        case 40:
            if (playerStatus->flags & PS_FLAGS_800 ||
                playerStatus->inputEnabledCounter) {

                playerStatus->flags &= ~NPC_FLAG_100;
                return ApiStatus_DONE2;
            }
            script->functionTemp[1] = 3;
            script->functionTemp[2] = disable_player_input();
            D_802BFF04 = 1;
            D_802BFF14 += 1;
            break;
        case 41:
            if (playerStatus->flags & PA_FLAGS_800) {
                playerStatus->flags &= ~NPC_FLAG_100;
                if (D_802BFF04 != 0) {
                    enable_player_input();
                    D_802BFF04 = 0;
                }
                return ApiStatus_DONE2;
            }

            if (playerStatus->animFlags & PA_FLAGS_100000) {
                if (script->functionTemp[2] < playerStatus->inputEnabledCounter) {
                    enable_player_input();
                    D_802BFF04 = 0;
                }
                playerStatus->flags &= ~PS_FLAGS_100;
                return ApiStatus_DONE2;
            }

            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] < playerStatus->inputEnabledCounter) {
                    enable_player_input();
                    D_802BFF04 = 0;
                    playerStatus->flags &= ~PS_FLAGS_100;
                    return ApiStatus_DONE2;
                }
                D_802BFF14 = 100;
                break;
            }
            script->functionTemp[1]--;
            break;
    }

    switch (D_802BFF14) {
        case 100:
            disable_player_static_collisions();
            D_802BFF08 = 1;

            if (D_802BFF04 == 0) {
                disable_player_input();
                D_802BFF04 = 1;
            }

            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
            npc->flags |= (NPC_FLAG_400000 | NPC_FLAG_100);
            set_action_state(ACTION_STATE_RIDE);
            D_802BFF0C = 1;
            func_800EF4E0();
            npc->moveToPos.x = playerStatus->position.x;
            npc->moveToPos.y = playerStatus->position.y;
            npc->moveToPos.z = playerStatus->position.z;
            yaw = 0.0f;

            for (i = 0; i < 4; i++) {
                x = npc->moveToPos.x;
                y = npc->moveToPos.y;
                z = npc->moveToPos.z;
                npc_test_move_simple_with_slipping(0x10000, &x, &y, &z, npc->moveSpeed,
                                                    yaw, npc->collisionHeight, npc->collisionRadius);
                npc->moveToPos.x = x;
                npc->moveToPos.y = y;
                npc->moveToPos.z = z;
                yaw += 90.0f;
            }

            npc->yaw = atan2(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
            npc->duration = 12;
            npc->currentAnim = 0x80005;
            npc->jumpVelocity = 8.0f;
            npc->jumpScale = 1.4f;
            suggest_player_anim_clearUnkFlag(ANIM_Mario_BeforeJump);
            D_802BFF14 = 101;
            break;
        case 101:
            sfx_play_sound_at_npc(SOUND_JUMP_2081, 0, NPC_PARTNER);
            suggest_player_anim_clearUnkFlag(ANIM_Mario_AnimMidairStill);
            /* fallthrough */
        case 102:
            D_802BFF14 += 1;
            /* fallthrough */
        case 103:
            if (!(playerStatus->flags & PA_FLAGS_800)) {
                npc->pos.x += (npc->moveToPos.x - npc->pos.x) / npc->duration;
                npc->pos.z += (npc->moveToPos.z - npc->pos.z) / npc->duration;
                npc->pos.y += (npc->moveToPos.y - npc->pos.y) / npc->duration;
                playerStatus->position.y += npc->jumpVelocity;
                colliderHeightTemp = playerStatus->colliderHeight;
                func_802BD99C_3214EC(npc, colliderHeightTemp, (colliderHeightTemp * 2));
                playerStatus->position.y += D_802BFF24;
                npc->pos.y += D_802BFF24;
                npc->jumpVelocity -= npc->jumpScale;

                if (npc->jumpVelocity <= 0.0f) {
                    suggest_player_anim_clearUnkFlag(ANIM_Mario_AnimMidair);
                }

                npc->duration--;

                if (npc->duration > 0) {
                    if (npc->duration == 1) {
                        add_vec2D_polar(&npc->pos.x, &npc->pos.z, -2.0f,
                                        gCameras[gCurrentCameraID].currentYaw);
                    }
                } else {
                    playerStatus->position.y = npc->pos.y + 10.0f;
                    npc->moveSpeed = playerStatus->runSpeed;
                    npc->jumpScale = 0.0f;
                    npc->yaw = playerStatus->targetYaw;
                    npc->duration = 3;
                    set_action_state(ACTION_STATE_RIDE);
                    suggest_player_anim_setUnkFlag(ANIM_Mario_8000E);
                    disable_player_shadow();
                    partnerActionStatus->actingPartner = PARTNER_LAKILESTER;
                    partnerActionStatus->partnerActionState = PARTNER_ACTION_LAKILESTER_1;
                    playerStatus->flags &= ~PS_FLAGS_100;
                    gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
                    D_802BFF18 = 0;
                    D_802BFF0C = 2;
                    func_802BFB44_323694(2.0f);
                    D_802BFF14 = 104;
                    playerStatus->animFlags |= PA_FLAGS_400000;
                }
            } else {
                D_802BFF14 = 10;
            }
            break;
        case 104:
            if (playerStatus->flags & PA_FLAGS_800) {
                D_802BFF14 = 10;
                break;
            } else {
                npc->duration--;
                if (npc->duration != 0) {
                    if (partnerActionStatus->pressedButtons & (B_BUTTON | D_CBUTTONS) && func_802BD7DC()) {
                        D_802BFF14 = 3;
                    }
                    break;
                } else {
                    D_802BFF14 = 1;
                    npc->flags |= NPC_FLAG_40;
                }
            }
        case 1:
            func_802BDDD8_321928(npc);
            playerStatus->animFlags |= PA_FLAGS_400000;
            D_802BFF18++;
            npc->pos.y = npc->moveToPos.y + 2.0f;

            if (D_802BFF18 >= 10) {
                D_802BFF18 = D_802BFF18 - 18;
            }

            if (partnerActionStatus->inputDisabled == FALSE) {
                playerStatus->targetYaw = npc->yaw;
            }

            if (!(playerStatus->flags & PS_FLAGS_800)) {
                if (partnerActionStatus->pressedButtons & (B_BUTTON | D_CBUTTONS)) {
                    if (func_802BD7DC()) {
                        D_802BFF14 = 3;
                    } else {
                        if (!(playerStatus->animFlags & PA_FLAGS_40000000)) {
                            sfx_play_sound_at_npc(SOUND_MENU_ERROR, 0, NPC_PARTNER);
                        }
                        playerStatus->animFlags &= ~PA_FLAGS_40000000;
                    }
                }
            } else {
                D_802BFF14 = 10;
                break;
            }
            break;
        case 3:
            npc->flags &= ~NPC_FLAG_40;
            playerStatus->flags |= NPC_FLAG_100;
            func_802BD7DC();
            camYaw = camera->currentYaw;
            if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
                yaw = (180.0f + camYaw) - 90.0f;
            } else {
                yaw = (0.0f + camYaw) - 90.0f;
            }
            npc->yaw = yaw;
            sp2C = dist2D(playerStatus->position.x, playerStatus->position.z,
                            npc->moveToPos.x, npc->moveToPos.z);
            npc->yaw = atan2(playerStatus->position.x, playerStatus->position.z,
                            npc->moveToPos.x, npc->moveToPos.z);
            npc->duration = 14;
            npc->jumpScale = 1.2f;

            if (npc->moveToPos.y > npc->pos.y) {
                npc->jumpVelocity = ((npc->moveToPos.y - npc->pos.y) / 14.0f) + 6.0f;
            } else {
                npc->jumpVelocity = 6.0f;
            }

            npc->moveSpeed = sp2C / npc->duration;
            suggest_player_anim_clearUnkFlag(ANIM_Mario_BeforeJump);
            D_802BFF14 += 1;
            break;
        case 4:
            suggest_player_anim_clearUnkFlag(ANIM_Mario_AnimMidairStill);
            D_802BFF14++;
            /* fallthrough */
        case 5:
            gCameras[0].moveFlags |= CAMERA_MOVE_FLAGS_1;
            playerStatus->position.y += npc->jumpVelocity;
            sp2C = playerStatus->colliderHeight * 0.5f;

            x = playerStatus->position.x;
            y = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
            z = playerStatus->position.z;

            yaw = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw;

            if (player_raycast_up_corners(playerStatus, &x, &y, &z, &sp2C, yaw) >= 0) {
                D_802BFF14 = 10;
                break;
            }

            npc->jumpVelocity -= npc->jumpScale;
            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, npc->moveSpeed, npc->yaw);

            func_800E4AD8(0);
            if (func_802BE6A0_3221F0(&y) >= 0) {
                D_802BFF14 = 10;
                playerStatus->position.y = y;
            }
            break;
        }

        gCameras[0].targetPos.x = playerStatus->position.x;
        gCameras[0].targetPos.y = npc->moveToPos.y;
        gCameras[0].targetPos.z = playerStatus->position.z;

        if (D_802BFF14 == 10) {
            D_802BFF0C = 0;
            npc->flags &= ~(NPC_FLAG_40 | NPC_FLAG_400000 | NPC_FLAG_ENABLE_HIT_SCRIPT);

            if (D_802BFF08 != 0) {
                D_802BFF08 = 0;
                enable_player_static_collisions();
            }

            enable_player_shadow();
            gGameStatusPtr->keepUsingPartnerOnMapChange = 0;

            if (playerStatus->flags & PS_FLAGS_800) {
                partnerActionStatus->actingPartner = PARTNER_NONE;
                partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;

                if (D_802BFF04 != 0) {
                    D_802BFF04 = 0;
                    enable_player_input();
                }

                partner_clear_player_tracking(npc);
                set_action_state(ACTION_STATE_HIT_FIRE);
                playerStatus->flags &= ~PS_FLAGS_100;
                return ApiStatus_DONE1;
            }

            set_action_state(ACTION_STATE_FALLING);
            gravity_use_fall_parms();
            D_802BFF14 = 11;
            return ApiStatus_BLOCK;
        }

        if (D_802BFF14 == 11) {
            npc->flags &= ~(NPC_FLAG_40 | NPC_FLAG_400000 | NPC_FLAG_ENABLE_HIT_SCRIPT);
            partnerActionStatus->actingPartner = PARTNER_NONE;
            partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;
            playerStatus->flags &= ~PS_FLAGS_100;
            if (D_802BFF04 != 0) {
                D_802BFF04 = 0;
                enable_player_input();
            }

            gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
            partner_clear_player_tracking(npc);
            func_800EF3D4(2);
            return ApiStatus_DONE1;
        }
        return ApiStatus_BLOCK;
}


EvtScript world_lakilester_use_ability = {
    EVT_CALL(func_802BE724_322274)
    EVT_RETURN
    EVT_END
};

ApiStatus func_802BF4F0_323040(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    Camera* cam = &gCameras[CAM_DEFAULT];
    Npc* lakilester = script->owner2.npc;
    f32 sp20, sp24, sp28, sp2C;
    f32 yaw;

    if (isInitialCall) {
        D_802BFF00 = (D_802BFF0C == 0) ? 3 : 0;
        partner_init_put_away(lakilester);
        func_802BD7DC();
        playerStatus->animFlags &= ~PA_FLAGS_400000;
        playerStatus->flags |= PS_FLAGS_100;
    }

    switch (D_802BFF00) {
        case 0:
            func_802BD7DC();
            yaw = cam->currentYaw;
            if ((playerStatus->spriteFacingAngle >= 90.0f) && (playerStatus->spriteFacingAngle < 270.0f)) {
                lakilester->yaw = (yaw + 180.0f) - 90.0f;
            } else {
                lakilester->yaw = (yaw + 0.0f) - 90.0f;
            }

            sp2C = dist2D(playerStatus->position.x, playerStatus->position.z,
                          lakilester->moveToPos.x, lakilester->moveToPos.z);
            lakilester->duration = 14;

            if (lakilester->moveToPos.y > lakilester->pos.y ) {
                lakilester->jumpVelocity = (lakilester->moveToPos.y - lakilester->pos.y) / 14.0f + 6.0f;
            } else {
                lakilester->jumpVelocity = 6.0f;
            }
            lakilester->jumpScale = 1.2f;
            lakilester->moveSpeed = sp2C / lakilester->duration;
            lakilester->yaw = atan2(playerStatus->position.x, playerStatus->position.z,
                                 lakilester->moveToPos.x, lakilester->moveToPos.z);
            suggest_player_anim_clearUnkFlag(ANIM_Mario_BeforeJump);
            D_802BFF00++;
            break;
        case 1:
            suggest_player_anim_clearUnkFlag(ANIM_Mario_AnimMidairStill);
            D_802BFF00++;
        case 2:
            playerStatus->position.y += lakilester->jumpVelocity;
            lakilester->jumpVelocity -= lakilester->jumpScale;
            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z,
                            lakilester->moveSpeed, lakilester->yaw);
            func_800E4AD8(0);
            if (lakilester->jumpVelocity <= 0.0f) {
                playerStatus->flags |= PS_FLAGS_FALLING;
                if (lakilester->jumpVelocity < -10.0) {
                    lakilester->jumpVelocity = -10.0f;
                }
            }
            sp20 = playerStatus->position.x;
            sp24 = playerStatus->position.y + playerStatus->colliderHeight;
            sp28 = playerStatus->position.z;
            sp2C = playerStatus->colliderHeight;
            if (npc_raycast_down_around(0, &sp20, &sp24, &sp28, &sp2C,
                                       lakilester->yaw, lakilester->collisionRadius)) {

                D_802BFF00 = 3;
                playerStatus->position.y = sp24;
            }
            break;
    }

    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;

    switch (D_802BFF00) {
        case 3:
            lakilester->flags &= ~(NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT);

            if (D_802BFF08) {
                D_802BFF08 = FALSE;
                enable_player_static_collisions();
            }

            enable_player_shadow();

            if (playerStatus->flags & PS_FLAGS_800) {
                partnerActionStatus->actingPartner = PARTNER_NONE;
                partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;
                if (D_802BFF04) {
                    D_802BFF04 = FALSE;
                    enable_player_input();
                }

                gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
                D_802BFF0C = 0;
                partner_clear_player_tracking(lakilester);
                set_action_state(ACTION_STATE_HIT_FIRE);
                return ApiStatus_DONE1;
            }

            if (D_802BFF0C == 0) {
                phys_main_collision_below();
            } else {
                set_action_state(ACTION_STATE_FALLING);
                gravity_use_fall_parms();
            }

            D_802BFF00++;
            break;
        case 4:
            partnerActionStatus->actingPartner = PARTNER_NONE;
            partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;
            playerStatus->flags &= ~PS_FLAGS_100;

            if (D_802BFF04) {
                D_802BFF04 = FALSE;
                enable_player_input();
            }
            gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
            D_802BFF0C = 0;
            partner_clear_player_tracking(lakilester);
            D_802BFF00++;
            break;
        case 5:
            if (partner_put_away(lakilester) == FALSE) {
                break;
            }
            return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

EvtScript world_lakilester_put_away = {
    EVT_CALL(func_802BF4F0_323040)
    EVT_RETURN
    EVT_END
};

void world_lakilester_pre_battle(Npc* npc) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (D_802BFF0C) {
        partnerActionStatus->npc = *npc;
        partnerActionStatus->partnerAction_unk_1 = 1;
        enable_player_static_collisions();
        enable_player_input();
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(npc);
    }

    partnerActionStatus->actingPartner = PARTNER_LAKILESTER;
    D_802BFF18 = 0;
}

void world_lakilester_post_battle(Npc* npc) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (partnerActionStatus->partnerAction_unk_1 != 0) {
        if (D_802BFF0C) {
            *npc = partnerActionStatus->npc;
            gGameStatusPtr->keepUsingPartnerOnMapChange = 1;
            set_action_state(ACTION_STATE_RIDE);
            partnerActionStatus->actingPartner = PARTNER_NONE;
            partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;
            disable_player_input();
            partner_use_ability();
        }
    }
}

void func_802BFB44_323694(f32 arg0) {
    Camera* currentCamera = &gCameras[gCurrentCameraID];
    PlayerStatus* playerStatus = &gPlayerStatus;

    add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, arg0, currentCamera->currentYaw);
}

s32 func_802BFBA0_3236F0(Evt* script, s32 isInitialCall) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(NPC_PARTNER);
    f32 temp_f0, temp_f2, temp_f4;
    f32* temp_s0_2;
    s32 temp_v0_2;
    s32 tempVar;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    tempVar = script->functionTemp[0];

    switch (tempVar) {
        case 0:
            if (script->varTable[12] == 0) {
                temp_f0 = playerStatus->position.x;
                npc->pos.x = temp_f0;
                npc->moveToPos.x = temp_f0;
                temp_f4 = playerStatus->position.z;
                npc->pos.z = temp_f4;
                npc->moveToPos.z = temp_f4;
                playerStatus->position.y = npc->pos.y + 10.0f;
                partner_kill_ability_script();
            } else {
                set_action_state(ACTION_STATE_RIDE);
                disable_player_static_collisions();
                disable_player_input();
                npc->moveToPos.x = npc->pos.x = playerStatus->position.x;
                npc->moveToPos.y = npc->pos.y = playerStatus->position.y;
                npc->moveToPos.z = npc->pos.z = playerStatus->position.z;
                playerStatus->position.y = npc->pos.y + 10.0f;
            }

            script->functionTemp[1] = script->varTable[4];
            temp_s0_2 = (f32*)&script->varTable[5];
            temp_f2 = atan2(npc->pos.x, npc->pos.z, script->varTable[1], script->varTable[3]);
            npc->yaw = temp_f2;

            if (script->varTable[12] != 0) {
                if (temp_f2 >= 0.0f && temp_f2 <= 180.0f) {
                    npc->yawCamOffset = temp_f2;
                    npc->isFacingAway = 1;
                }
            }

            sfx_play_sound_at_npc(SOUND_295, 0, -4);
            playerStatus->anim = ANIM_Mario_8000E;
            playerStatus->animNotifyValue = 0;
            playerStatus->flags |= PS_FLAGS_10000000;
            func_802BFB44_323694(2.0f);
            gGameStatusPtr->keepUsingPartnerOnMapChange = 1;
            npc->flags |= NPC_FLAG_100;
            npc->moveSpeed = *temp_s0_2;
            npc->jumpScale = 0.0f;
            D_802BFF10 = 0;
            D_802BFF18 = 0;
            script->functionTemp[0] = 1;
            break;

        case 1:
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            playerStatus->position.x = npc->pos.x;
            playerStatus->position.y = npc->pos.y + 10.0f;
            playerStatus->position.z = npc->pos.z;
            playerStatus->targetYaw = npc->yaw;
            func_802BFB44_323694(2.0f);
            script->functionTemp[1] -= 1;

            if (script->functionTemp[1] == 0) {
                if (script->varTable[12] != 0) {
                    partnerActionStatus->partnerAction_unk_1 = tempVar;
                    set_action_state(ACTION_STATE_RIDE);
                    partnerActionStatus->actingPartner = PARTNER_NONE;
                    partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;
                    partner_use_ability();
                    enable_player_static_collisions();
                    enable_player_input();
                }
                return ApiStatus_DONE2;
            }
    }

    return ApiStatus_BLOCK;
}

EvtScript world_lakilester_while_riding = {
    EVT_CALL(func_802BFBA0_3236F0)
    EVT_RETURN
    EVT_END
};
