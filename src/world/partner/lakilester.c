#include "common.h"
#include "../partners.h"
#include "effects.h"
#include "functions.h"

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
BSS unkPartnerStruct D_802BFF30;

void func_802BD100_320C50(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* lakilester = get_npc_unsafe(NPC_PARTNER);
    s32 playerFlags = playerStatus->flags;
    Camera* currentCamera;
    f32 playerSpeedCopy;
    s32 temp_v0_2;

    if (playerFlags & PLAYER_STATUS_FLAGS_4000) {
        playerSpeedCopy = playerStatus->currentSpeed;
        if (playerFlags & PLAYER_STATUS_FLAGS_40000) {
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

unkPartnerStruct* D_802BFE7C_3239CC = &D_802BFF30;

ApiStatus func_802BD2D4_320E24(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* lakilester = script->owner2.npc;
    Entity* entity;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    if (isInitialCall) {
        partner_flying_enable(lakilester, 1);
        mem_clear(D_802BFE7C_3239CC, sizeof(*D_802BFE7C_3239CC));
        D_8010C954 = NULL;
    }

    playerData->unk_2F4[8]++;
    lakilester->flags |= NPC_FLAG_DIRTY_SHADOW;
    entity = D_8010C954;

    if (entity == NULL) {
        partner_flying_update_player_tracking(lakilester);
        partner_flying_update_motion(lakilester);
        return ApiStatus_BLOCK;
    }

    switch (D_802BFE7C_3239CC->unk_04) {
        case 0:
            D_802BFE7C_3239CC->unk_04 = 1;
            D_802BFE7C_3239CC->flags = lakilester->flags;
            D_802BFE7C_3239CC->unk_0C = fabsf(dist2D(lakilester->pos.x, lakilester->pos.z, entity->position.x, entity->position.z));
            D_802BFE7C_3239CC->unk_10 = atan2(entity->position.x, entity->position.z, lakilester->pos.x, lakilester->pos.z);
            D_802BFE7C_3239CC->unk_14 = 6.0f;
            D_802BFE7C_3239CC->unk_18 = 50.0f;
            D_802BFE7C_3239CC->unk_00 = 120;
            lakilester->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            lakilester->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad((D_802BFE7C_3239CC->unk_10 * TAU) / 360.0f, &sp10, &sp14);
            lakilester->pos.x = entity->position.x + (sp10 * D_802BFE7C_3239CC->unk_0C);
            lakilester->pos.z = entity->position.z - (sp14 * D_802BFE7C_3239CC->unk_0C);
            D_802BFE7C_3239CC->unk_10 = clamp_angle(D_802BFE7C_3239CC->unk_10 - D_802BFE7C_3239CC->unk_14);

            if (D_802BFE7C_3239CC->unk_0C > 20.0f) {
                D_802BFE7C_3239CC->unk_0C--;
            } else if (D_802BFE7C_3239CC->unk_0C < 19.0f) {
                D_802BFE7C_3239CC->unk_0C++;
            }

            tempY = sin_rad((D_802BFE7C_3239CC->unk_18 * TAU) / 360.0f) * 3.0f;
            D_802BFE7C_3239CC->unk_18 += 3.0f;

            if (D_802BFE7C_3239CC->unk_18 > 150.0f) {
                D_802BFE7C_3239CC->unk_18 = 150.0f;
            }

            lakilester->pos.y += tempY;
            lakilester->renderYaw = clamp_angle(360.0f - D_802BFE7C_3239CC->unk_10);
            D_802BFE7C_3239CC->unk_14 += 0.8;

            if (D_802BFE7C_3239CC->unk_14 > 40.0f) {
                D_802BFE7C_3239CC->unk_14 = 40.0f;
            }

            if (--D_802BFE7C_3239CC->unk_00 == 0) {
                D_802BFE7C_3239CC->unk_04++;
            }
            break;
        case 2:
            lakilester->flags = D_802BFE7C_3239CC->flags;
            D_802BFE7C_3239CC->unk_00 = 30;
            D_802BFE7C_3239CC->unk_04++;
            break;
        case 3:
            partner_flying_update_player_tracking(lakilester);
            partner_flying_update_motion(lakilester);

            if (--D_802BFE7C_3239CC->unk_00 == 0) {
                D_802BFE7C_3239CC->unk_04 = 0;
                D_8010C954 = NULL;
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
    if (D_8010C954 != NULL) {
        D_8010C954 = NULL;
        npc->flags = D_802BFE7C_3239CC->flags;
        D_802BFE7C_3239CC->unk_04 = 0;
        partner_clear_player_tracking(npc);
    }
}

void func_802BD6BC_32120C(f32* arg0, f32* arg1) {
    PartnerActionStatus* lakilesterActionStatus = &gPartnerActionStatus;
    f32 temp_f24 = lakilesterActionStatus->stickX;
    f32 temp_f26 = lakilesterActionStatus->stickY;
    f32 temp_f22 = -temp_f26;
    f32 atan = atan2(0.0f, 0.0f, temp_f24, temp_f22);
    f32 temp = clamp_angle(atan + gCameras->currentYaw);
    f32 phi_f20 = 0.0f;

    if (dist2D(0.0f, 0.0f, temp_f24, temp_f22) >= 1.0) {
        phi_f20 = 3.0f;
        if (SQ(temp_f24) + SQ(temp_f26) > 3025.0f) {
            phi_f20 = 6.0f;
        }
    }

    *arg0 = temp;
    *arg1 = phi_f20;
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

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_20000000) {
        playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_20000000;
        return TRUE;
    }

    ret = 0;
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
        if (!(colliderTypeID & 0x4000) || !(get_entity_type(colliderTypeID) - 0x2E < 2)){
            colliderTypeID = get_collider_type_by_id(colliderTypeID) & 0xFF;
            if (colliderTypeID - 1 >= 3U) {
                ret = FALSE;
                if (colliderTypeID != 5) {
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
    f32 sp3C, sp40, sp44, sp48, sp4C, sp50, sp54;
    f32 yaw = 0.0f;
    f32 moveSpeed = 0.0f;
    f32 x, y, z;
    f32 temp_f0_3;
    s32 raycastBelowResult;
    s32 phi_a3;
    f32 phi_f20;


    func_802BD6BC_32120C(&yaw, &moveSpeed);

    if ((u8)(get_collider_type_by_id(npc->currentFloor)) == 3) {
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
                phi_a3 = update_lerp(0,  0.0f, 100.0f, D_802BFF20, 60);
                sfx_play_sound_with_params(SOUND_295, 0, 0x40, phi_a3);
            } else {
                phi_a3 = update_lerp(0, 100.0f, 0.0f, D_802BFF20 - 60, 60);
                sfx_play_sound_with_params(SOUND_295, 0, 0x40, phi_a3);
            }
        }
    }

    x = npc->pos.x;
    y = npc->moveToPos.y;
    z = npc->pos.z;

    if (npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, npc->collisionRadius, npc->yaw,
        npc->collisionHeight, npc->collisionRadius) != 0) {

        collisionStatus->unk_0A = (partnerActionStatus->pressedButtons & 0x8000) ? D_8010C97A : -1;
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
    sp3C = npc->collisionHeight + 2;
    y = npc->moveToPos.y + 12.0f;
    x = playerStatus->position.x;
    z = playerStatus->position.z;
    add_vec2D_polar(&x, &z, 2.0f, gCameras[gCurrentCameraID].currentYaw);
    raycastBelowResult = player_raycast_below_cam_relative(playerStatus, &x, &y, &z, &sp3C, &sp40,
                                                            &sp44, &sp48, &sp4C);
    D_802BFF28 = get_player_normal_pitch();
    phi_f20 = 12.0f;

    if (D_802BFF28 != 0.0f) {
        phi_f20 = 32.0f;
    }

    if (D_802BFF28 > 0.0f && raycastBelowResult >= 0) {
        sin_cos_rad((D_802BFF28 * TAU) / 360.0f, &sp50, &sp54);
        npc->pos.y = (npc->pos.y + fabs((sp50 / sp54) * playerStatus->runSpeed));
    }

    if (sp3C <= phi_f20 && raycastBelowResult >= 0) {
        playerStatus->lastGoodPosition.x = npc->pos.x;
        playerStatus->lastGoodPosition.y = npc->pos.y;
        playerStatus->lastGoodPosition.z = npc->pos.z;
        collisionStatus->currentFloor = raycastBelowResult;

        npc->currentFloor = raycastBelowResult;
        npc->moveToPos.y = y;
        npc->moveToPos.x = x;
        npc->moveToPos.z = z;
        npc->jumpScale = 0.0f;
        playerStatus->decorationList = 0;

        if ((get_collider_type_by_id(raycastBelowResult) & 0xFF) == 3) {

            npc->currentAnim.w = 0x80006;
            npc->moveSpeed = moveSpeed * 0.5f;
        } else {
            npc->currentAnim.w = 0x80005;
            npc->moveSpeed = moveSpeed;
        }
        return;
    }

    collisionStatus->currentFloor = -1;
    playerStatus->decorationList = playerStatus->decorationList + 1;
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

    playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_400000;

    if (isInitialCall) {
        func_802BD678_3211C8(npc);
        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_100000)) {
            npc->flags = npc->flags & ~PLAYER_STATUS_ANIM_FLAGS_40;
            npc->moveToPos.x = npc->pos.x;
            npc->moveToPos.y = npc->pos.y;
            npc->moveToPos.z = npc->pos.z;

            if (gGameStatusPtr->keepUsingPartnerOnMapChange ||
                (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_200000)) {
                if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_200000) {
                    playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_200000;
                }
                D_802BFF14 = 100;
            } else {
                D_802BFF14 = 40;
            }

            if (partnerActionStatus->actionState.b[1] == 0) {
                if (gGameStatusPtr->keepUsingPartnerOnMapChange == FALSE) {
                    if (playerStatus->actionState == ACTION_STATE_RIDE ||
                        playerStatus->actionState == ACTION_STATE_IDLE ||
                        playerStatus->actionState == ACTION_STATE_WALK ||
                        playerStatus->actionState == ACTION_STATE_RUN ||
                        playerStatus->actionState == ACTION_STATE_FALLING) {

                        playerStatus->flags |= PLAYER_STATUS_ANIM_FLAGS_100;
                    } else {
                        return ApiStatus_DONE2;
                    }
                }
            } else {
                partnerActionStatus->actionState.b[1] = 0;
                playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
                npc->flags &= ~(NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT);
                npc->flags |= NPC_FLAG_100;
                set_action_state(ACTION_STATE_RIDE);
                suggest_player_anim_setUnkFlag(0x8000E);
                npc->currentAnim.w = 0x80005;
                D_802BFF0C = 1;
                npc->flags &= ~(NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT);
                npc->flags |= (NPC_FLAG_100 | NPC_FLAG_400000);
                partnerActionStatus->actionState.b[3] = 8;
                partnerActionStatus->actionState.b[0] = 1;
                gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
                npc->pos.x = playerStatus->position.x;
                npc->pos.y = npc->moveToPos.y;
                npc->pos.z = playerStatus->position.z;
                npc->currentAnim.w = 0x80005;
                playerStatus->position.y = npc->pos.y + 10.0f;
                npc->moveSpeed = 3.0f;
                npc->jumpScale = 0.0f;
                npc->yaw = playerStatus->targetYaw;
                suggest_player_anim_setUnkFlag(0x8000E);
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
            if (playerStatus->flags & PLAYER_STATUS_FLAGS_800 ||
                playerStatus->statusMenuCounterinputEnabledCounter) {

                playerStatus->flags &= ~NPC_FLAG_100;
                return ApiStatus_DONE2;
            }
            
            script->functionTemp[1] = 3;
            script->functionTemp[2] = disable_player_input();
            D_802BFF04 = 1;
            D_802BFF14 += 1;
            break;
        case 41:
            if (playerStatus->flags & PLAYER_STATUS_ANIM_FLAGS_800) {
                playerStatus->flags &= ~NPC_FLAG_100;
                if (D_802BFF04 != 0) {
                    enable_player_input();
                    D_802BFF04 = 0;
                }
                return ApiStatus_DONE2;
            }

            if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_100000) {
                if (script->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter) {
                    enable_player_input();
                    D_802BFF04 = 0;
                }
                playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
                return ApiStatus_DONE2;
            }

            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter) {
                    enable_player_input();
                    D_802BFF04 = 0;
                    playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
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
            npc->currentAnim.w = 0x80005;
            npc->jumpVelocity = 8.0f;
            npc->jumpScale = 1.4f;
            suggest_player_anim_clearUnkFlag(0x10006);
            D_802BFF14 = 101;
            break;
        case 101:
            sfx_play_sound_at_npc(SOUND_JUMP_2081, 0, NPC_PARTNER);
            suggest_player_anim_clearUnkFlag(0x10007);
            /* fallthrough */
        case 102:
            D_802BFF14 += 1;
            /* fallthrough */
        case 103:
            if (!(playerStatus->flags & PLAYER_STATUS_ANIM_FLAGS_800)) {
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
                    suggest_player_anim_clearUnkFlag(0x10008);
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
                    suggest_player_anim_setUnkFlag(0x8000E);
                    disable_player_shadow();
                    partnerActionStatus->actionState.b[3] = 8;
                    partnerActionStatus->actionState.b[0] = 1;
                    playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
                    gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
                    D_802BFF18 = 0;
                    D_802BFF0C = 2;
                    func_802BFB44_323694(2.0f);
                    D_802BFF14 = 104;
                    playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_400000;
                }
            } else {
                D_802BFF14 = 10;
            }
            break;
        case 104:
            if (playerStatus->flags & PLAYER_STATUS_ANIM_FLAGS_800) {
                D_802BFF14 = 10;
            } else {
                npc->duration--;
                if (npc->duration != 0) {
                    if (partnerActionStatus->pressedButtons & (B_BUTTON | D_CBUTTONS) &&
                        func_802BD7DC() != 0) {
                            
                        D_802BFF14 = 3;
                    }
                } else {
                    D_802BFF14 = 1;
                    npc->flags |= NPC_FLAG_40;
                case 1:
                    func_802BDDD8_321928(npc);
                    playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_400000;
                    D_802BFF18++;
                    npc->pos.y = npc->moveToPos.y + 2.0f;

                    if (D_802BFF18 >= 10) {
                        D_802BFF18 = D_802BFF18 - 18;
                    }

                    if (partnerActionStatus->inputDisabled == FALSE) {
                        playerStatus->targetYaw = npc->yaw;
                    }

                    if (!(playerStatus->flags & PLAYER_STATUS_FLAGS_800)) {
                        if (partnerActionStatus->pressedButtons & (B_BUTTON | D_CBUTTONS)) {
                            if (func_802BD7DC() != 0) {
                                D_802BFF14 = 3;
                            } else {
                                if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_40000000)) {
                                    sfx_play_sound_at_npc(SOUND_MENU_ERROR, 0, NPC_PARTNER);
                                }
                                playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_40000000;
                            }
                        }
                    } else {
                        D_802BFF14 = 10;
                        break;
                    }
                }
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
            suggest_player_anim_clearUnkFlag(0x10006);
            D_802BFF14 += 1;
            break;
        case 4: 
            suggest_player_anim_clearUnkFlag(0x10007);
            D_802BFF14++;
            /* fallthrough */
        case 5:
            gCameras[0].moveFlags |= 1;
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

            if (playerStatus->flags & PLAYER_STATUS_FLAGS_800) {
                partnerActionStatus->actionState.b[3] = 0;
                partnerActionStatus->actionState.b[0] = 0;

                if (D_802BFF04 != 0) {
                    D_802BFF04 = 0;
                    enable_player_input();
                }

                partner_clear_player_tracking(npc);
                set_action_state(ACTION_STATE_HIT_FIRE);
                playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
                return ApiStatus_DONE1;
            }

            set_action_state(ACTION_STATE_FALLING);
            gravity_use_fall_parms();
            D_802BFF14 = 11;
            return ApiStatus_BLOCK;
        }

        if (D_802BFF14 == 11) {
            npc->flags &= ~(NPC_FLAG_40 | NPC_FLAG_400000 | NPC_FLAG_ENABLE_HIT_SCRIPT);
            partnerActionStatus->actionState.b[3] = 0;
            partnerActionStatus->actionState.b[0] = 0;
            playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
            
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
        playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_400000;
        playerStatus->flags |= PLAYER_STATUS_FLAGS_100;
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
            suggest_player_anim_clearUnkFlag(0x10006);
            D_802BFF00++;
            break;
        case 1:
            suggest_player_anim_clearUnkFlag(0x10007);
            D_802BFF00++;
        case 2:
            playerStatus->position.y += lakilester->jumpVelocity;
            lakilester->jumpVelocity -= lakilester->jumpScale;
            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z,
                            lakilester->moveSpeed, lakilester->yaw);
            func_800E4AD8(0);
            if (lakilester->jumpVelocity <= 0.0f) {
                playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;
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

    gCameras->targetPos.x = playerStatus->position.x;
    gCameras->targetPos.y = playerStatus->position.y;
    gCameras->targetPos.z = playerStatus->position.z;

    switch (D_802BFF00) {
        case 3:
            lakilester->flags &= ~(NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT);

            if (D_802BFF08) {
                D_802BFF08 = FALSE;
                enable_player_static_collisions();
            }

            enable_player_shadow();

            if (playerStatus->flags & PLAYER_STATUS_FLAGS_800) {
                partnerActionStatus->actionState.b[3] = 0;
                partnerActionStatus->actionState.b[0] = 0;
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
            partnerActionStatus->actionState.b[3] = 0;
            partnerActionStatus->actionState.b[0] = 0;
            playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;

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
        partnerActionStatus->actionState.b[1] = 1;
        enable_player_static_collisions();
        enable_player_input();
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(npc);
    }

    partnerActionStatus->actionState.b[3] = 8;
    D_802BFF18 = 0;
}

void world_lakilester_post_battle(Npc* npc) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (partnerActionStatus->actionState.b[1] != 0) {
        if (D_802BFF0C) {
            *npc = partnerActionStatus->npc;
            gGameStatusPtr->keepUsingPartnerOnMapChange = 1;
            set_action_state(ACTION_STATE_RIDE);
            partnerActionStatus->actionState.b[3] = 0;
            partnerActionStatus->actionState.b[0] = 0;
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

            sfx_play_sound_at_npc(0x295, 0, -4);
            playerStatus->anim = 0x8000E;
            playerStatus->unk_BC = 0;
            playerStatus->flags |= PLAYER_STATUS_FLAGS_10000000;
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
                    partnerActionStatus->actionState.b[1] = tempVar;
                    set_action_state(ACTION_STATE_RIDE);
                    partnerActionStatus->actionState.b[3] = 0;
                    partnerActionStatus->actionState.b[0] = 0;
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
