#include "common.h"
#include "../src/world/partners.h"

BSS s32 D_802BEBB0;
BSS s32 D_802BEBB4;
BSS s32 D_802BEBB8;
BSS s32 D_802BEBBC;
BSS s32 D_802BEBC0_31CBE0;
BSS s32 D_802BEBC4;
BSS TweesterPhysics ParakarryTweesterPhysics;

void world_parakarry_init(Npc* parakarry) {
    parakarry->collisionHeight = 37;
    parakarry->collisionRadius = 40;
    D_802BEBB0 = 0;
    D_802BEBC0_31CBE0 = 0;
    D_802BEBB4 = 0;
    D_802BEBB8 = 0;
    D_802BEBBC = 0;
    D_802BEBC4 = 0;
}

ApiStatus ParakarryTakeOut(Evt* script, s32 isInitialCall) {
    Npc* parakarry = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(parakarry);
    }

    return partner_get_out(parakarry) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_parakarry_take_out = {
    EVT_CALL(ParakarryTakeOut)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* ParakarryTweesterPhysicsPtr = &ParakarryTweesterPhysics;

ApiStatus ParakarryUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* parakarry = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_flying_enable(parakarry, 1);
        mem_clear(ParakarryTweesterPhysicsPtr, sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_PARAKARRY]++;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_flying_update_player_tracking(parakarry);
        partner_flying_update_motion(parakarry);
        return ApiStatus_BLOCK;
    }

    switch (ParakarryTweesterPhysicsPtr->state) {
        case 0:
            ParakarryTweesterPhysicsPtr->state = 1;
            ParakarryTweesterPhysicsPtr->prevFlags = parakarry->flags;
            ParakarryTweesterPhysicsPtr->radius = fabsf(dist2D(parakarry->pos.x, parakarry->pos.z,
                                                     entity->position.x, entity->position.z));
            ParakarryTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z,
                                              parakarry->pos.x, parakarry->pos.z);
            ParakarryTweesterPhysicsPtr->angularVelocity = 6.0f;
            ParakarryTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            ParakarryTweesterPhysicsPtr->countdown = 120;
            parakarry->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            parakarry->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad(DEG_TO_RAD(ParakarryTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);
            parakarry->pos.x = entity->position.x + (sinAngle * ParakarryTweesterPhysicsPtr->radius);
            parakarry->pos.z = entity->position.z - (cosAngle * ParakarryTweesterPhysicsPtr->radius);
            ParakarryTweesterPhysicsPtr->angle = clamp_angle(ParakarryTweesterPhysicsPtr->angle - ParakarryTweesterPhysicsPtr->angularVelocity);

            if (ParakarryTweesterPhysicsPtr->radius > 20.0f) {
                ParakarryTweesterPhysicsPtr->radius--;
            } else if (ParakarryTweesterPhysicsPtr->radius < 19.0f) {
                ParakarryTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(ParakarryTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
            ParakarryTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (ParakarryTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                ParakarryTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            parakarry->pos.y += liftoffVelocity;
            parakarry->renderYaw = clamp_angle(360.0f - ParakarryTweesterPhysicsPtr->angle);
            ParakarryTweesterPhysicsPtr->angularVelocity += 0.8;

            if (ParakarryTweesterPhysicsPtr->angularVelocity > 40.0f) {
                ParakarryTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--ParakarryTweesterPhysicsPtr->countdown == 0) {
                ParakarryTweesterPhysicsPtr->state++;
            }
            break;
        case 2:
            parakarry->flags = ParakarryTweesterPhysicsPtr->prevFlags;
            ParakarryTweesterPhysicsPtr->countdown = 30;
            ParakarryTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_flying_update_player_tracking(parakarry);
            partner_flying_update_motion(parakarry);

            if (--ParakarryTweesterPhysicsPtr->countdown == 0) {
                ParakarryTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript world_parakarry_update = {
    EVT_CALL(ParakarryUpdate)
    EVT_RETURN
    EVT_END
};

void func_802BD514_319A84(Npc* parakarry) {
    if (TweesterTouchingPartner) {
        TweesterTouchingPartner = NULL;
        parakarry->flags = ParakarryTweesterPhysicsPtr->prevFlags;
        ParakarryTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking (parakarry);
    }
}

s32 func_802BD558_319AC8(void) {
    f32 sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    f32 colliderBaseHeight = gPlayerStatus.colliderHeight;
    s32 raycastResult;
    s32 surfaceType;

    sp28 = gPlayerStatus.position.x;
    sp2C = gPlayerStatus.position.y + (colliderBaseHeight * 0.5);
    sp30 = gPlayerStatus.position.z;
    sp34 = colliderBaseHeight * 0.5f;

    raycastResult = player_raycast_below_cam_relative(&gPlayerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38,
                                                      &sp3C, &sp40, &sp44);

    surfaceType = get_collider_flags(raycastResult) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
    if (surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) {
        gPlayerStatus.hazardType = HAZARD_TYPE_SPIKES;
        D_802BEBC0_31CBE0 = 0x15;
        gPlayerStatus.flags |= PS_FLAGS_800;
    }

    return raycastResult;
}

ApiStatus func_802BD660_319BD0(Evt* evt, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    Npc* parakarry = evt->owner2.npc;
    s32 buttonTemp = BUTTON_A;
    f32 x, y, z, sp30, sp2C;
    f32 diffZPlayer, diffXPlayer, diffZParakarry, diffXParakarry;
    f32 tempX, tempZ;
    s32 testMove;
    u32 tempFrameCounterU32, tempFrameCounterTwoU32;
    s32 tempConditional;
    s32 diffTemp;
    f32 tempYaw;
    f32 halfCollisionHeight;
    u16 tempFrameCounter, tempFrameCounterTwo;

    if (gCurrentEncounter.unk_08 == 0) {
        if (isInitialCall) {
            func_802BD514_319A84(parakarry);
            if (!(playerStatus->animFlags & PA_FLAGS_100000)) {
                if (partnerActionStatus->partnerAction_unk_1 == 0) {
                    if (!func_800EA52C(4)) {
                        return ApiStatus_DONE2;
                    }
                    D_802BEBC0_31CBE0 = 0x28;
                    parakarry->flags &= ~NPC_FLAG_4000;
                    parakarry->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
                } else {
                    partnerActionStatus->partnerAction_unk_1 = 0;
                    set_action_state(ACTION_STATE_RIDE);
                    parakarry->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_GRAVITY);
                    D_802BEBB0 = 1;
                    gCameras[0].moveFlags |= CAMERA_MOVE_FLAGS_1;
                    parakarry->currentAnim = 0x40009;
                    partnerActionStatus->actingPartner = PARTNER_PARAKARRY;
                    partnerActionStatus->partnerActionState = PARTNER_ACTION_PARAKARRY_HOVER;
                    parakarry->flags &= ~NPC_FLAG_4000;
                    parakarry->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
                }
            } else {
                return ApiStatus_DONE2;
            }
        }

        switch (D_802BEBC0_31CBE0) {
            case 0x28:
                if (playerStatus->inputEnabledCounter == 0) {
                    D_802BEBC4 = 3;
                    D_802BEBC0_31CBE0 = 0x29;
                    evt->functionTemp[2] = playerStatus->inputEnabledCounter;
                } else {
                    goto block_end_return_ApiStatus_DONE2; // TODO remove this goto
                }
            case 0x29:
                if (D_802BEBC4 == 0) {
                    if (evt->functionTemp[2] >= playerStatus->inputEnabledCounter) {
                        if (func_800EA52C(4)) {
                            D_802BEBC0_31CBE0 = 0x1E;
                            break;
                        }
                    }
                    return ApiStatus_DONE2;
                }
                D_802BEBC4--;
                break;
        }

        switch (D_802BEBC0_31CBE0) {
            case 0x1E:
                set_action_state(ACTION_STATE_RIDE);
                disable_player_input();
                disable_player_static_collisions();
                evt->functionTemp[2] = playerStatus->inputEnabledCounter;
                D_802BEBB4 = 1;
                D_802BEBB8 = 1;
                D_802BEBB0 = 1;
                gCameras[0].moveFlags |= CAMERA_MOVE_FLAGS_1;
                parakarry->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_GRAVITY);
                parakarry->flags |= NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
                partnerActionStatus->actingPartner = PARTNER_PARAKARRY;
                partnerActionStatus->partnerActionState = PARTNER_ACTION_PARAKARRY_HOVER;
                D_802BEBBC = func_800EF4E0();
                enable_npc_blur(parakarry);
                parakarry->yaw = atan2(parakarry->pos.x, parakarry->pos.z, playerStatus->position.x, playerStatus->position.z);
                parakarry->duration = 4;
                D_802BEBC0_31CBE0++;
                break;
            case 0x1F:
                if (playerStatus->actionState == ACTION_STATE_HIT_FIRE || playerStatus->actionState == ACTION_STATE_HIT_LAVA || playerStatus->actionState == ACTION_STATE_KNOCKBACK
                        || playerStatus->actionState == ACTION_STATE_JUMP  || playerStatus->actionState == ACTION_STATE_HOP) {
                    disable_npc_blur(parakarry);
                    D_802BEBC0_31CBE0 = 0x15;
                } else {
                    suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                    parakarry->moveToPos.x = playerStatus->position.x;
                    parakarry->moveToPos.y = playerStatus->position.y + 32.0f;
                    parakarry->moveToPos.z = playerStatus->position.z;
                    parakarry->currentAnim = 0x40003;
                    add_vec2D_polar(&parakarry->moveToPos.x, &parakarry->moveToPos.z, 0.0f, playerStatus->targetYaw);
                    tempYaw = playerStatus->targetYaw;

                    tempYaw += (D_802BEBBC == 0) ? 90.0f : -90.0f;

                    add_vec2D_polar(&parakarry->moveToPos.x, &parakarry->moveToPos.z, 5.0f, clamp_angle(tempYaw));

                    parakarry->pos.x += (parakarry->moveToPos.x - parakarry->pos.x) / parakarry->duration;
                    parakarry->pos.y += (parakarry->moveToPos.y - parakarry->pos.y) / parakarry->duration;
                    parakarry->pos.z += (parakarry->moveToPos.z - parakarry->pos.z) / parakarry->duration;
                    parakarry->duration--;
                    if (parakarry->duration != 0) {
                        if (evt->functionTemp[2] < playerStatus->inputEnabledCounter) {
                            disable_npc_blur(parakarry);
                            D_802BEBC0_31CBE0 = 0x16;
                        }
                    } else {
                        disable_npc_blur(parakarry);
                        parakarry->yaw = playerStatus->targetYaw;
                        parakarry->moveSpeed = 0.2f;
                        parakarry->currentAnim = 0x4000A;
                        parakarry->planarFlyDist = 0;
                        suggest_player_anim_setUnkFlag(ANIM_Mario_8000D);
                        sfx_play_sound_at_npc(SOUND_2009, 0, -4);
                        gCollisionStatus.lastTouchedFloor = -1;
                        gCollisionStatus.currentFloor = -1;
                        parakarry->currentFloor = -1;
                        D_802BEBC4 = 0x14;
                        D_802BEBC0_31CBE0 = 1;
                    }
                }
                break;
            case 1:
                if (playerStatus->actionState != ACTION_STATE_HIT_FIRE && playerStatus->actionState != ACTION_STATE_HIT_LAVA && playerStatus->actionState != ACTION_STATE_KNOCKBACK) {
                    if (partnerActionStatus->pressedButtons & (BUTTON_A | BUTTON_B | BUTTON_C_DOWN)) {
                        D_802BEBC0_31CBE0 = (partnerActionStatus->pressedButtons & BUTTON_A) ? 0x14 : 0x15;
                        suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                    } else {
                        tempFrameCounter = gGameStatusPtr->frameCounter;
                        tempFrameCounterU32 = tempFrameCounter;
                        tempFrameCounterU32 /= 6;
                        if (!((tempFrameCounter - tempFrameCounterU32 * 6) & 0xFFFF)) {
                            sfx_play_sound_at_npc(SOUND_2009, 0, -4);
                        }
                        sp2C = fabsf(sin_rad(DEG_TO_RAD((20 - D_802BEBC4) * 18))) * 1.3;
                        playerStatus->position.y += sp2C;
                        parakarry->pos.y += sp2C;
                        x = parakarry->pos.x;
                        y = parakarry->pos.y + parakarry->collisionHeight * 0.5f;
                        z = parakarry->pos.z;
                        sp2C = parakarry->collisionHeight * 0.5f;
                        halfCollisionHeight = sp2C;

                        if (npc_raycast_up(0x10000, &x, &y, &z, &sp2C)) {
                            if (sp2C < halfCollisionHeight) {
                                D_802BEBC4 = 0;
                            }
                        }

                        x = playerStatus->position.x;
                        z = playerStatus->position.z;
                        sp2C = playerStatus->colliderHeight * 0.5f;
                        y = playerStatus->position.y + playerStatus->colliderHeight * 0.5f;
                        halfCollisionHeight = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw;
                        if (player_raycast_up_corners(playerStatus, &x, &y, &z, &sp2C, halfCollisionHeight) >= 0) {
                            suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                            D_802BEBC0_31CBE0 = 0x15;
                            break;
                        }

                        x = playerStatus->position.x;
                        y = playerStatus->position.y;
                        z = playerStatus->position.z;
                        if (npc_test_move_complex_with_slipping(0x10000, &x, &y, &z, parakarry->moveSpeed, parakarry->yaw, playerStatus->colliderHeight, playerStatus->colliderDiameter) >= 2) {
                            playerStatus->position.x += (x - playerStatus->position.x) * 0.125f;
                            playerStatus->position.z += (z - playerStatus->position.z) * 0.125f;
                            parakarry->pos.x += (x - parakarry->pos.x) * 0.125f;
                            parakarry->pos.z += (z - parakarry->pos.z) * 0.125f;
                        }

                        x = parakarry->pos.x;
                        y = parakarry->pos.y;
                        z = parakarry->pos.z;
                        testMove = npc_test_move_complex_with_slipping(0x10000, &x, &y, &z, parakarry->moveSpeed, parakarry->yaw, parakarry->collisionHeight, parakarry->collisionRadius);
                        if (testMove >= 2) {
                            tempX = x;
                            tempZ = z;
                            diffXParakarry = (x - parakarry->pos.x) * 0.125f;
                            diffZParakarry = (z - parakarry->pos.z) * 0.125f;

                            x = parakarry->pos.x + diffXParakarry;
                            z = parakarry->pos.z + diffZParakarry;
                            x = parakarry->pos.x;
                            y = parakarry->pos.y;
                            diffXPlayer = (tempX - playerStatus->position.x) * 0.125f;
                            diffZPlayer = (tempZ - playerStatus->position.z) * 0.125f;
                            z = parakarry->pos.z;
                            testMove = npc_test_move_complex_with_slipping(0x10000, &x, &y, &z, parakarry->moveSpeed, parakarry->yaw, parakarry->collisionHeight, parakarry->collisionRadius);
                            if (testMove == 0) {
                                playerStatus->position.x += diffXPlayer;
                                playerStatus->position.z += diffZPlayer;
                                parakarry->pos.x += diffXParakarry;
                                parakarry->pos.z += diffZParakarry;
                            }
                        }

                        if (testMove == 0 && !(playerStatus->animFlags & PA_FLAGS_8000)) {
                            add_vec2D_polar(&parakarry->pos.x, &parakarry->pos.z, parakarry->moveSpeed, parakarry->yaw);
                            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, parakarry->moveSpeed, parakarry->yaw);
                            parakarry->planarFlyDist += parakarry->moveSpeed;
                        }

                        x = playerStatus->position.x;
                        y = playerStatus->position.y + playerStatus->colliderHeight * 0.5f;
                        z = playerStatus->position.z;
                        sp2C = playerStatus->colliderHeight * 0.5f;
                        if (npc_raycast_down_around(0x10000, &x, &y, &z, &sp2C, parakarry->yaw, parakarry->collisionRadius)) {
                            s32 surfaceType = get_collider_flags(D_8010C978) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                            if (surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) {
                                playerStatus->hazardType = HAZARD_TYPE_SPIKES;
                                D_802BEBC0_31CBE0 = 0x15;
                                playerStatus->flags |= PS_FLAGS_800;
                            }

                            playerStatus->position.y += (y - playerStatus->position.y) * 0.25f;
                            parakarry->pos.y = playerStatus->position.y + 32.0f;
                        }
                        if (!(parakarry->flags & NPC_FLAG_4000)) {
                            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
                            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
                            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
                            if (D_802BEBC4 != 0) {
                                D_802BEBC4--;
                            } else {
                                parakarry->jumpVelocity = -0.5f;
                                parakarry->jumpScale = -0.01f;
                                parakarry->moveToPos.y = playerStatus->position.y;
                                parakarry->duration = 0;
                                parakarry->currentAnim = 0x4000A;
                                parakarry->animationSpeed = 1.8f;
                                gCollisionStatus.currentFloor = -1;
                                D_802BEBC0_31CBE0++;
                            }
                        } else {
                            suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                            D_802BEBC0_31CBE0 = 0x15;
                        }
                    }
                } else {
                    D_802BEBC0_31CBE0 = 0x15;
                }
                break;
            case 2:
                gCollisionStatus.currentFloor = func_802BD558_319AC8();
                if (playerStatus->actionState != ACTION_STATE_HIT_FIRE && playerStatus->actionState != ACTION_STATE_HIT_LAVA && playerStatus->actionState != ACTION_STATE_KNOCKBACK) {
                    suggest_player_anim_setUnkFlag(ANIM_Mario_8000D);
                    if (!(playerStatus->flags & PS_FLAGS_800)) {
                        if (partnerActionStatus->pressedButtons & (BUTTON_A | BUTTON_B | BUTTON_C_DOWN)) {
                            if (partnerActionStatus->pressedButtons & buttonTemp) {   // TODO find a way to remove this while still loading 0x15 instead of moving it from register
                                if (!parakarry->pos.x) {

                                }
                            }
                            D_802BEBC0_31CBE0 = (partnerActionStatus->pressedButtons & BUTTON_A) ? 0x14 : 0x15;
                        } else {

                            tempFrameCounterTwoU32 = gGameStatusPtr->frameCounter;
                            tempFrameCounterTwo = tempFrameCounterTwoU32;
                            tempFrameCounterTwoU32 /= 6;
                            if (!((tempFrameCounterTwo - tempFrameCounterTwoU32 * 6) & 0xFFFF)) {
                                sfx_play_sound_at_npc(SOUND_2009, 0, -4);
                            }

                            parakarry->jumpVelocity -= parakarry->jumpScale;
                            if (parakarry->jumpVelocity > 0.0) {
                                parakarry->jumpVelocity = 0.0f;
                            }

                            parakarry->pos.y += parakarry->jumpVelocity;
                            playerStatus->position.y += parakarry->jumpVelocity;
                            if (!(playerStatus->animFlags & PA_FLAGS_8000)) {
                                parakarry->moveSpeed += 0.1;
                                if (parakarry->moveSpeed > 2.0) {
                                    parakarry->moveSpeed = 2.0f;
                                }

                                add_vec2D_polar(&parakarry->pos.x, &parakarry->pos.z, parakarry->moveSpeed, parakarry->yaw);
                                add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, parakarry->moveSpeed, parakarry->yaw);
                                parakarry->planarFlyDist += parakarry->moveSpeed;
                                parakarry->animationSpeed -= 0.05;
                                if (parakarry->animationSpeed < 1.5) {
                                    parakarry->animationSpeed = 1.5f;
                                }
                                if (parakarry->planarFlyDist > 80.0f) {
                                    parakarry->animationSpeed += 0.5;
                                }
                                if (!(playerStatus->animFlags & PA_FLAGS_8000)) {
                                    x = playerStatus->position.x;
                                    y = playerStatus->position.y;
                                    z = playerStatus->position.z;
                                    if (npc_test_move_complex_with_slipping(0x10000, &x, &y, &z, parakarry->moveSpeed, parakarry->yaw, playerStatus->colliderHeight, playerStatus->colliderDiameter)) {
                                        suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                                        D_802BEBC0_31CBE0 = 0x15;
                                    } else {
                                        x = parakarry->pos.x;
                                        y = parakarry->pos.y;
                                        z = parakarry->pos.z;
                                        if (!npc_test_move_complex_with_slipping(0x10000, &x, &y, &z, parakarry->moveSpeed, parakarry->yaw, parakarry->collisionHeight, parakarry->collisionRadius)) {
                                            tempConditional = FALSE;
                                            x = parakarry->pos.x;
                                            y = parakarry->pos.y + parakarry->collisionHeight * 0.5f;
                                            z = parakarry->pos.z;
                                            sp2C = parakarry->collisionHeight * 0.5f;

                                            halfCollisionHeight = sp2C;
                                            if (npc_raycast_up(0x10000, &x, &y, &z, &sp2C) && (sp2C < halfCollisionHeight)) {
                                                parakarry->pos.y =  y - parakarry->collisionHeight;
                                                playerStatus->position.y =  parakarry->pos.y - 32.0f;
                                                tempConditional = TRUE;
                                            }
                                            x = playerStatus->position.x;
                                            y = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
                                            z = playerStatus->position.z;
                                            sp2C = playerStatus->colliderHeight * 0.5f;

                                            if (!npc_raycast_down_around(0x10000, &x, &y, &z, &sp2C, parakarry->yaw, parakarry->collisionRadius)
                                                    || (playerStatus->position.y += (y - playerStatus->position.y) * 0.25f,
                                                        parakarry->pos.y = playerStatus->position.y + 32.0f,
                                                        y = parakarry->pos.y,
                                                        parakarry->pos.y = playerStatus->position.y,
                                                        func_8003D660(parakarry, 0),
                                                        parakarry->pos.y = y, (!tempConditional))) {
                                                if (!phys_adjust_cam_on_landing()) {
                                                    gCameras[0].moveFlags &= ~CAMERA_MOVE_FLAGS_2;
                                                }
                                                gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
                                                gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
                                                gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
                                                if (!(parakarry->flags & NPC_FLAG_4000)) {
                                                    parakarry->duration++;
                                                    if (!(parakarry->planarFlyDist < 100.0f)) {
                                                        D_802BEBC4 = 5;
                                                        D_802BEBC0_31CBE0 = 6;
                                                    }
                                                    break;
                                                }
                                            } else {
                                                D_802BEBC0_31CBE0 = 0x15;
                                                break;
                                            }
                                        }
                                        suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                                        D_802BEBC0_31CBE0 = 0x15;
                                    }
                                    break;
                                }
                            }
                            suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                            D_802BEBC0_31CBE0 = 0x15;
                        }
                    } else {
                        D_802BEBC0_31CBE0 = 0x14;
                    }
                } else {
                    D_802BEBC0_31CBE0 = 0x15;
                }
                break;
            case 6:
                if (D_802BEBC4 != 0) {
                    D_802BEBC4--;
                } else {
                    D_802BEBC0_31CBE0 = 0x15;
                }
                break;
        }

        if (D_802BEBC0_31CBE0 == 0x16 || D_802BEBC0_31CBE0 == 0x15 || D_802BEBC0_31CBE0 == 0x14) {
            parakarry->currentAnim = 0x40001;
            D_802BEBB0 = 0;
            parakarry->jumpVelocity = 0.0f;
            parakarry->flags &= ~ACTOR_FLAG_HP_OFFSET_BELOW;
            parakarry->animationSpeed = 1.0f;
            partner_clear_player_tracking(parakarry);
            partnerActionStatus->actingPartner = PARTNER_NONE;
            partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;
            enable_partner_ai();
            sfx_stop_sound(SOUND_2009);
            if (D_802BEBB4 != 0) {
                enable_player_input();
            }
            if (D_802BEBB8 != 0) {
                enable_player_static_collisions();
            }
            if (!(playerStatus->flags & PS_FLAGS_800)) {
                if (D_802BEBC0_31CBE0 == 0x14) {
                    start_bounce_b();
                } else if (D_802BEBC0_31CBE0 == 0x15) {
                    start_falling();
                    gravity_use_fall_parms();
                    playerStatus->flags |= PS_FLAGS_800000;
                } else {
                    set_action_state(ACTION_STATE_IDLE);
                }
            } else {
                set_action_state(ACTION_STATE_HIT_LAVA);
            }
block_end_return_ApiStatus_DONE2:
            return ApiStatus_DONE2;
        }
    }
    return ApiStatus_BLOCK;
}

EvtScript world_parakarry_use_ability = {
    EVT_CALL(func_802BD660_319BD0)
    EVT_RETURN
    EVT_END
};

ApiStatus ParakarryPutAway(Evt* script, s32 isInitialCall) {
    Npc* parakarry = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(parakarry);
    }

    return partner_put_away(parakarry) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_parakarry_put_away = {
    EVT_CALL(ParakarryPutAway)
    EVT_RETURN
    EVT_END
};

void world_parakarry_pre_battle(Npc* parakarry) {
    PartnerActionStatus* parakarryActionStatus = &gPartnerActionStatus;

    if (D_802BEBB0) {
        if (D_802BEBB8) {
            enable_player_static_collisions();
        }

        if (D_802BEBB4) {
            enable_player_input();
        }

        set_action_state(ACTION_STATE_IDLE);
        parakarryActionStatus->npc = *parakarry;
        parakarryActionStatus->partnerAction_unk_1 = 1;
        partner_clear_player_tracking(parakarry);
    }

    parakarryActionStatus->actingPartner = PARTNER_PARAKARRY;
}

void world_parakarry_post_battle(Npc* parakarry) {
    PartnerActionStatus* parakarryActionStatus = &gPartnerActionStatus;

    if (parakarryActionStatus->partnerAction_unk_1 != 0) {
        if (D_802BEBB8) {
            disable_player_static_collisions();
        }
        if (D_802BEBB4) {
            disable_player_input();
        }

        set_action_state(ACTION_STATE_RIDE);
        *parakarry = parakarryActionStatus->npc;
        parakarryActionStatus->actingPartner = PARTNER_NONE;
        parakarryActionStatus->partnerActionState = PARTNER_ACTION_NONE;
        partner_clear_player_tracking(parakarry);
        partner_use_ability();
    }
}
