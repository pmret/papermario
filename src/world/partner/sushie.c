#include "common.h"
#include "world/partners.h"
#include "npc.h"
#include "effects.h"
#include "sprite/npc/WorldSushie.h"
#include "sprite.h"

#define NAMESPACE world_sushie

BSS f32 OriginalPlayerY;
BSS s32 bss_802BFEE4;
BSS s32 bss_802BFEE8;
BSS s32 bss_802BFEEC;
BSS s32 bss_802BFEF0;
BSS s32 bss_802BFEF4;
BSS f32 bss_802BFEF8;
BSS f32 bss_802BFEFC;
BSS f32 bss_802BFF00;
BSS f32 bss_802BFF04;
BSS f32 bss_802BFF08;
BSS s32 bss_802BFF0C;
BSS TweesterPhysics SushieTweesterPhysics;

f32 D_802BFDB0_320B20 = 0.0f;
f32 D_802BFDB4_320B24 = 0.0f;
f32 D_802BFDB8_320B28 = 0.0f;
f32 D_802BFDBC_320B2C = 0.0f;

void func_802BF920_320690(Npc* sushie);

void func_802BD100_31DE70(void) {
    Npc* partnerNPC = get_npc_unsafe(NPC_PARTNER);
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    s32 phi_v1;

    playerStatus->position.x = partnerNPC->pos.x;
    playerStatus->position.y = partnerNPC->pos.y + 16.0f;
    playerStatus->position.z = partnerNPC->pos.z;
    playerStatus->targetYaw = partnerNPC->yaw;

    if (playerStatus->spriteFacingAngle < 90.0f || playerStatus->spriteFacingAngle > 270.0f) {
        phi_v1 = -8;
    } else {
        phi_v1 = 8;
    }

    playerStatus->position.z -= cos_rad(DEG_TO_RAD(
        camera->currentYaw + playerStatus->spriteFacingAngle - 90.0f + phi_v1)) * -4.0f;
}

void func_802BD20C_31DF7C(f32* arg0, f32* arg1) {
    f32 temp_f22;
    f32 phi_f20;
    f32 stickY = gPartnerActionStatus.stickY;
    f32 stickX = gPartnerActionStatus.stickX;

    D_802BFDB0_320B20 = stickX;
    D_802BFDB4_320B24 = stickY;
    temp_f22 = clamp_angle(atan2(0.0f, 0.0f, stickX, -stickY) + gCameras[CAM_DEFAULT].currentYaw);
    phi_f20 = 0.0f;

    if (dist2D(0.0f, 0.0f, D_802BFDB0_320B20, -D_802BFDB4_320B24) >= 1.0) {
        if (SQ(D_802BFDB0_320B20) + SQ(D_802BFDB4_320B24) > 3025.0f) {
            if (bss_802BFEE4) {
                phi_f20 = 2.0f;
            } else {
                phi_f20 = 4.0f;
            }
        } else {
            phi_f20 = 2.0f;
        }
    }

    *arg0 = temp_f22;
    *arg1 = phi_f20;
}

void func_802BD368_31E0D8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 sp20;

    arg2 += 100.0f;
    sp20 = 200.0f;

    if (npc_raycast_down_around(arg0, &arg1, &arg2, &arg3, &sp20, arg4, arg5) == 0) {
        collisionStatus->currentFloor = NO_COLLIDER;
    } else {
        collisionStatus->currentFloor = NpcHitQueryColliderID;
        OriginalPlayerY = arg2;
    }
}

void func_802BD414_31E184(Npc* npc) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 var_f20;
    f32 sp20;
    f32 sp24;
    f32 sinTheta, cosTheta;
    f32 x, y, z;
    f32 sp3C;

    func_802BD20C_31DF7C(&sp20, &sp24);
    if (bss_802BFEE4 != 0) {
        var_f20 = 80.0f;
    } else {
        var_f20 = 32.0f;
    }

    if (sp24 != 0.0f) {
        f32 t1;
        f32 t2;
        f32 t3;

        t3 = D_802BFDB0_320B20 * D_802BFDB8_320B28;
        t1 = 8.0f;
        t2 = 32.0f;

        if (t3 > 0.0f) {
            D_802BFDB8_320B28 += D_802BFDB0_320B20 / t2;
        } else {
            D_802BFDB8_320B28 += D_802BFDB0_320B20 / t1;
        }
        if (D_802BFDB0_320B20 > 0.0f) {
            if (D_802BFDB0_320B20 < D_802BFDB8_320B28) {
                D_802BFDB8_320B28 = D_802BFDB0_320B20;
            }
        } else {
            if (D_802BFDB8_320B28 < D_802BFDB0_320B20) {
                D_802BFDB8_320B28 = D_802BFDB0_320B20;
            }
        }

        if (D_802BFDB4_320B24 * D_802BFDBC_320B2C > 0.0f) {
            D_802BFDBC_320B2C += D_802BFDB4_320B24 / t2;
        } else {
            D_802BFDBC_320B2C += D_802BFDB4_320B24 / t1;
        }
        if (D_802BFDB4_320B24 > 0.0f) {
            if (D_802BFDB4_320B24 < D_802BFDBC_320B2C) {
                D_802BFDBC_320B2C = D_802BFDB4_320B24;
            }
        } else {
            if (D_802BFDBC_320B2C < D_802BFDB4_320B24) {
                D_802BFDBC_320B2C = D_802BFDB4_320B24;
            }
        }

        sp20 = clamp_angle(atan2(0.0f, 0.0f, D_802BFDB8_320B28, -D_802BFDBC_320B2C) + gCameras[CAM_DEFAULT].currentYaw);
        if (bss_802BFEF8 <= sp24) {
            bss_802BFEF8 = bss_802BFEF8 + ((sp24 - bss_802BFEF8) / var_f20);
            if (bss_802BFEF8 > sp24) {
                bss_802BFEF8 = sp24;
            }
        } else {
            bss_802BFEF8 += (sp24 - bss_802BFEF8) / var_f20;
        }
        sp24 = bss_802BFEF8;
        bss_802BFEFC = sp20;
        sin_cos_rad(DEG_TO_RAD(sp20), &sinTheta, &cosTheta);
        bss_802BFF00 += (sp24 * sinTheta) / var_f20;
        bss_802BFF04 += (-sp24 * cosTheta) / var_f20;
    } else {
        bss_802BFEF8 -= 0.15;
        if (bss_802BFEF8 < 0.0f) {
            bss_802BFEF8 = 0.0f;
            D_802BFDBC_320B2C = 0.0f;
            D_802BFDB8_320B28 = 0.0f;
        }
        sp24 = bss_802BFEF8;
        sp20 = bss_802BFEFC;
        sin_cos_rad(DEG_TO_RAD(bss_802BFEFC), &sinTheta, &cosTheta);
        bss_802BFF00 = sp24 * sinTheta;
        bss_802BFF04 = -sp24 * cosTheta;
    }
    npc->moveSpeed = sp24;
    if (sp24 != 0.0f) {
        npc->yaw = sp20;
        x = npc->pos.x;
        z = npc->pos.z;
        y = npc->moveToPos.y + -6.0f;
        sp3C = (npc->collisionHeight * 0.5f) + (playerStatus->colliderHeight * 0.8f);
        if (npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, npc->moveSpeed, sp20, sp3C,
                                               npc->collisionRadius) != 0)
        {
            collisionStatus->pushingAgainstWall = NpcHitQueryColliderID;
            if ((get_collider_flags(NpcHitQueryColliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK) == SURFACE_TYPE_DOCK_WALL) {
                bss_802BFEF0++;
            } else {
                bss_802BFEF0 = 0;
            }
            npc->pos.x += (x - npc->pos.x) * 0.5f;
            npc->pos.z += (z - npc->pos.z) * 0.5f;
        } else {
            npc_move_heading(npc, sp24, sp20);
            collisionStatus->pushingAgainstWall = NO_COLLIDER;
        }
        sp24 = 2.0f;
        sp20 = clamp_angle(npc->yaw - 30.0f);
        x = npc->pos.x;
        z = npc->pos.z;
        y = npc->moveToPos.y + -6.0f;
        sp3C = (npc->collisionHeight * 0.5f) + (playerStatus->colliderHeight * 0.8f);
        if (npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, sp24, sp20, sp3C, npc->collisionRadius) != 0) {
            npc->pos.x += (x - npc->pos.x) / 5.0f;
            npc->pos.z += (z - npc->pos.z) / 5.0f;
        }
        sp20 = clamp_angle(npc->yaw + 30.0f);
        x = npc->pos.x;
        z = npc->pos.z;
        y = npc->moveToPos.y + -6.0f;
        sp3C = (npc->collisionHeight * 0.5f) + (playerStatus->colliderHeight * 0.8f);
        if (npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, sp24, sp20, sp3C, npc->collisionRadius) != 0) {
            npc->pos.x += (x - npc->pos.x) / 5.0f;
            npc->pos.z += (z - npc->pos.z) / 5.0f;
        }
    }
    if (bss_802BFEE4 == 0) {
        func_802BD368_31E0D8(npc->collisionChannel, npc->pos.x, npc->pos.y, npc->pos.z, npc->yaw,
                             npc->collisionRadius * 0.5f);
        if (bss_802BFEE4 == 0) {
            npc->moveSpeed = 3.0f;
            npc->moveToPos.y = OriginalPlayerY - (npc->collisionHeight * 0.5f);
            bss_802BFEE8 = 0;
            if (partnerActionStatus->pressedButtons & BUTTON_C_DOWN) {
                bss_802BFEE4 = 1;
                npc->moveSpeed = 2.0f;
            } else {
                return;
            }
        }
    }

    if (bss_802BFEE4 == 1 && (partnerActionStatus->currentButtons & 4) && bss_802BFEE8 == 0) {
        bss_802BFEE4 = 2;
    }
    bss_802BFEE8++;
    if (bss_802BFEE4 == 2) {
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;
        sp3C = npc->collisionHeight;
        if (npc_raycast_down_around(npc->collisionChannel, &x, &y, &z, &sp3C, npc->yaw, npc->collisionRadius) != 0) {
            var_f20 = ((OriginalPlayerY - (playerStatus->colliderHeight * 2)) - npc->moveToPos.y) * 0.1f;
            npc->moveToPos.y += var_f20;
            if (npc->moveToPos.y < y + 5.0f) {
                npc->moveToPos.y = y + 5.0f;
            }
        } else {
            var_f20 = ((OriginalPlayerY - (playerStatus->colliderHeight * 2)) - npc->moveToPos.y) * 0.1f;
            npc->moveToPos.y += var_f20;
        }
        if (bss_802BFEE8 == ((bss_802BFEE8 / 6) * 6)) {
            fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + (npc->collisionHeight * 0.5f), npc->pos.z,
                             (OriginalPlayerY - npc->moveToPos.y) - (npc->collisionHeight * 0.5f));
        }
        if (bss_802BFEE8 == 1) {
            suggest_player_anim_always_forward(ANIM_MarioW2_DiveSushie);
            npc->currentAnim = ANIM_WorldSushie_Ride;
        }
        if (bss_802BFEF4 == 0 && (playerStatus->position.y + (playerStatus->colliderHeight * 0.5f) < OriginalPlayerY)) {
            bss_802BFEF4 = 1;
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
            func_802DDFF8(playerStatus->trueAnimation, 4, 2, 0, 0, 0, 0);
            func_8003D624(npc, FOLD_TYPE_4, 2, 0, 0, 0, 0);
        }
        if (bss_802BFEE8 >= 10 && (!(partnerActionStatus->currentButtons & BUTTON_C_DOWN) || bss_802BFEE8 >= 30)) {
            npc->currentAnim = ANIM_WorldSushie_Rise;
            sfx_play_sound_at_npc(SOUND_294 | SOUND_ID_TRIGGER_CHANGE_SOUND, SOUND_SPACE_MODE_0, NPC_PARTNER);
            bss_802BFEE4 = 3;
        }
    }

    x = npc->pos.x;
    y = npc->moveToPos.y;
    z = npc->pos.z;
    sp3C = (npc->collisionHeight * 0.5f) + playerStatus->colliderHeight;
    if (npc_raycast_up_corners(npc->collisionChannel, &x, &y, &z, &sp3C, npc->yaw, npc->collisionRadius * 0.3f) >= 0) {
        npc->moveToPos.y += (((npc->moveToPos.y - y) + sp3C) - ((npc->collisionHeight * 0.5f) + playerStatus->colliderHeight)) * 0.2f;
        if (bss_802BFEE8 == ((bss_802BFEE8 / 9) * 9)) {
            fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + (npc->collisionHeight * 0.5f), npc->pos.z,
                             (OriginalPlayerY - npc->moveToPos.y) - (npc->collisionHeight * 0.5f));
        }
    } else if (bss_802BFEE4 == 3) {
        bss_802BFF08 += 0.14;
        if (bss_802BFF08 > 1.8) {
            bss_802BFF08 = 1.8f;
        }
        npc->moveToPos.y += bss_802BFF08;
        if (bss_802BFEE8 == ((bss_802BFEE8 / 9) * 9)) {
            fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + npc->collisionHeight * 0.5f, npc->pos.z,
                             (OriginalPlayerY - npc->moveToPos.y) - npc->collisionHeight * 0.5f);
        }
        if ((OriginalPlayerY - npc->moveToPos.y) - (npc->collisionHeight * 0.5f) <= 0.0f) {
            if (bss_802BFEF4 != 0) {
                bss_802BFEF4 = 0;
                func_802DDFF8(ANIM_Mario1_Idle, 0, 0, 0, 0, 0, 0);
                func_8003D624(npc, FOLD_TYPE_NONE, 0, 0, 0, 0, 0);
            }
            bss_802BFEE4 = 0;
            npc->currentAnim = ANIM_WorldSushie_Ride;
            npc->moveToPos.y = OriginalPlayerY - (npc->collisionHeight * 0.5f);
            suggest_player_anim_always_forward(ANIM_MarioW2_RideSushie);
        }
    }
}

s32 func_802BE280_31EFF0(s32 arg0, f32* x, f32* y, f32* z, f32 length, f32 radius, f32* yaw) {
    f32 sinAngle, cosAngle, hitX, hitY, hitZ, totalLength, hitNx, hitNy, hitNz;
    s32 hitResult;

    sin_cos_rad(DEG_TO_RAD(*yaw), &sinAngle, &cosAngle);
    cosAngle = -cosAngle;
    totalLength = radius + length;
    hitResult = test_ray_colliders(COLLISION_CHANNEL_10000, *x, *y, *z, sinAngle, 0.0f, cosAngle, &hitX, &hitY, &hitZ, &totalLength, &hitNx, &hitNy, &hitNz);

    if (hitResult >= 0) {
        *yaw = atan2(0.0f, 0.0f, hitNx, hitNz);
    }

    return hitResult;
}

API_CALLABLE(func_802BE3A4_31F114) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    Npc* npc = script->owner2.npc;
    s32 colliderFlags;
    f32 yTemp;
    f64 zTemp;
    f64 xTemp;
    f32 x, y, z;
    f32 angle;
    f32 dist;
    f32 sp34;
    f32 sinTheta;
    f32 cosTheta;
    s32 collider;
    s32 t;

    if (isInitialCall) {
        func_802BF920_320690(npc);
        bss_802BFEFC = 0.0f;
        bss_802BFEF8 = 0.0f;
        bss_802BFF00 = 0.0f;
        bss_802BFF04 = 0.0f;
        bss_802BFF08 = 0.0f;
        script->functionTemp[0] = 0;
    }
    playerData->partnerUsedTime[PARTNER_SUSHIE]++;
    playerStatus->animFlags &= ~PA_FLAG_RIDING_PARTNER;

    switch (script->functionTemp[0]) {
        case 0:
            if (!gGameStatusPtr->keepUsingPartnerOnMapChange) {
                collider = collisionStatus->currentWall;
                if (collider >= 0 && (collider & COLLISION_WITH_ENTITY_BIT) == 0) {
                    collider = get_collider_flags(collider) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                    if (collider != SURFACE_TYPE_DOCK_WALL) {
                        return ApiStatus_DONE1;
                    }
                    script->functionTemp[0] = 20;
                    break;
                }
                return ApiStatus_DONE1;
            }
            npc->moveToPos.y = npc->pos.y;
            playerStatus->position.y = npc->moveToPos.y + 16.0f;
            bss_802BFEEC = 1;
            npc->flags |= NPC_FLAG_8;
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
            suggest_player_anim_always_forward(ANIM_MarioW2_RideSushie);
            disable_player_shadow();
            disable_npc_shadow(npc);
            func_8003D624(npc, FOLD_TYPE_4, 2, 0, 0, 0, 0);
            npc->currentAnim = ANIM_WorldSushie_Ride;
            npc->moveSpeed = playerStatus->runSpeed;
            npc->jumpScale = 0.0f;
            partnerActionStatus->partnerActionState = PARTNER_ACTION_USE;
            gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
            partnerActionStatus->actingPartner = PARTNER_SUSHIE;
            bss_802BFEE4 = 0;
            bss_802BFEE8 = 0;
            script->functionTemp[2] = 0;
            script->functionTemp[0] = 1;
            break;
        case 20:
            if (collisionStatus->currentWall >= 0) {
                get_collider_center(collisionStatus->currentWall, &x, &y, &z);
                angle = atan2(x, z, playerStatus->position.x, playerStatus->position.z);
                x = playerStatus->position.x;
                y = playerStatus->position.y;
                z = playerStatus->position.z;
                collider = func_802BE280_31EFF0(0, &x, &y, &z, playerStatus->colliderDiameter * 0.5f,
                                                2.0f * playerStatus->colliderDiameter, &angle);
                colliderFlags = -1;
                if (collider >= 0) {
                    colliderFlags = get_collider_flags(collider) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                }
                if (colliderFlags == SURFACE_TYPE_DOCK_WALL) {
                    bss_802BFEEC = 1;
                    set_action_state(ACTION_STATE_RIDE);
                    disable_player_static_collisions();
                    disable_player_input();
                    npc->collisionChannel = COLLISION_CHANNEL_80000;
                    npc->moveToPos.x = playerStatus->position.x;
                    npc->moveToPos.y = playerStatus->position.y;
                    npc->moveToPos.z = playerStatus->position.z;
                    npc->yaw = angle;
                    playerStatus->targetYaw = angle;
                    npc->renderYaw = 90.0f;
                    add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, 40.0f, npc->yaw);
                    x = npc->moveToPos.x;
                    y = npc->moveToPos.y;
                    z = npc->moveToPos.z;
                    dist = 100.0f;
                    collider = npc_raycast_down_around(npc->collisionChannel, &x, &y, &z, &dist,
                                                       npc->yaw, npc->collisionRadius);
                    npc->currentAnim = ANIM_WorldSushie_Run;
                    npc->duration = 12;
                    npc->moveToPos.y = y - (npc->collisionHeight * 0.5f);
                    suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                    script->functionTemp[0]++;
                    break;
                }
            }
            return ApiStatus_DONE1;
        case 21:
            npc->pos.x += ((npc->moveToPos.x - npc->pos.x) / npc->duration);
            npc->pos.y += ((npc->moveToPos.y - npc->pos.y) / npc->duration);
            npc->pos.z += ((npc->moveToPos.z - npc->pos.z) / npc->duration);
            npc->duration--;
            if (npc->duration != 0) {
                if (npc->duration == 2) {
                    sfx_play_sound_at_npc(SOUND_JUMP_2081, SOUND_SPACE_MODE_0, NPC_PARTNER);
                    suggest_player_anim_allow_backward(ANIM_Mario1_BeforeJump);
                }
                break;
            }
            npc->collisionChannel = COLLISION_CHANNEL_10000;
            npc->flags |= NPC_FLAG_8;
            npc->flags &= ~(NPC_FLAG_GRAVITY | NPC_FLAG_IGNORE_WORLD_COLLISION);
            disable_npc_shadow(npc);
            func_8003D624(npc, FOLD_TYPE_4, 2, 0, 0, 0, 0);
            npc->currentAnim = ANIM_WorldSushie_Ride;
            playerStatus->flags |= PS_FLAG_MOVEMENT_LOCKED;
            dist = dist2D(playerStatus->position.x, playerStatus->position.z, npc->moveToPos.x, npc->moveToPos.z);
            npc->jumpVelocity = 5.0f;
            npc->jumpScale = 0.6f;
            y = npc->moveToPos.y - playerStatus->position.y;
            npc->duration = (2.0f * npc->jumpVelocity) / 0.6f;
            npc->moveSpeed = dist / npc->duration;
            npc->jumpVelocity += y / npc->duration;
            suggest_player_anim_allow_backward(ANIM_Mario1_Jump);
            script->functionTemp[0]++;
            fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + (npc->collisionHeight * 0.5f), npc->pos.z, 0.0f);
            return 0;
        case 23:
            fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + (npc->collisionHeight * 0.5f), npc->pos.z, 0.0f);
            // fallthrough
        case 22:
        case 24:
            script->functionTemp[0]++;
            // fallthrough
        case 25:
            playerStatus->position.y += npc->jumpVelocity;
            npc->jumpVelocity -= npc->jumpScale;
            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, npc->moveSpeed, npc->yaw);
            if (npc->jumpVelocity <= 0.0f) {
                suggest_player_anim_allow_backward(ANIM_Mario1_Fall);
            }
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;

            if (npc->duration == 0) {
                set_action_state(ACTION_STATE_RIDE);
                disable_player_shadow();
                playerStatus->flags &= ~PS_FLAG_MOVEMENT_LOCKED;
                suggest_player_anim_always_forward(ANIM_MarioW2_RideSushie);
                sfx_play_sound_at_npc(SOUND_2013, SOUND_SPACE_MODE_0, NPC_PARTNER);
                playerStatus->position.x = npc->pos.x;
                playerStatus->position.y = npc->pos.y;
                playerStatus->position.z = npc->pos.z;
                playerStatus->targetYaw = npc->yaw;
                npc->moveSpeed = 3.0f;
                partnerActionStatus->partnerActionState = PARTNER_ACTION_USE;
                gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
                partnerActionStatus->actingPartner = PARTNER_SUSHIE;
                bss_802BFEE4 = 0;
                bss_802BFEE8 = 0;
                script->functionTemp[2] = 0;
                script->functionTemp[0] = 1;
            } else {
                npc->duration--;
            }
            break;
        case 1:
            playerStatus->animFlags |= PA_FLAG_RIDING_PARTNER;
            func_802BD414_31E184(npc);
            if (bss_802BFEE4 == 0) {
                script->functionTemp[2]++;
                if (script->functionTemp[2] > 20) {
                    script->functionTemp[2] -= 40;
                }
                npc->pos.y = npc->moveToPos.y + (abs(script->functionTemp[2]) * 0.125f);
                if (script->functionTemp[2] == 5) {
                    func_802BD20C_31DF7C(&angle, &sp34);
                    if (bss_802BFEE4 == 0) {
                        if (sp34 != 0.0f) {
                            sfx_play_sound_at_npc(SOUND_2015, SOUND_SPACE_MODE_0, NPC_PARTNER);
                        } else {
                            sfx_play_sound_at_npc(SOUND_2014, SOUND_SPACE_MODE_0, NPC_PARTNER);
                        }
                    }
                }
                if (bss_802BFEF8 == 0.0f && !((gGameStatusPtr->frameCounter % 10) & 0xFFFF)) {
                    fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + (npc->collisionHeight * 0.5f), npc->pos.z, 0.0f);
                }
            } else {
                npc->pos.y = npc->moveToPos.y;
            }
            if (!(playerStatus->animFlags & PA_FLAG_RIDING_PARTNER)) {
                func_802BD100_31DE70();
            }

            if (bss_802BFEE4 == 1) {
                if (!(gGameStatusPtr->frameCounter % 19)) {
                    yTemp = npc->moveToPos.y + (npc->collisionHeight * 0.5f);
                    fx_rising_bubble(0,npc->pos.x, yTemp, npc->pos.z, OriginalPlayerY - npc->pos.y);
                }
            } else if (bss_802BFEF8 != 0.0f && bss_802BFEE4 < 2) {
                if (!(gGameStatusPtr->frameCounter % 7)) {
                    yTemp = npc->moveToPos.y + (npc->collisionHeight * 0.5f);

                    fx_rising_bubble(0, npc->pos.x, yTemp, npc->pos.z, bss_802BFEE4 != 0 ? OriginalPlayerY - npc->pos.y : 0.0f);
                }
            }

            gCameras[CAM_DEFAULT].targetPos.x = npc->pos.x;
            gCameras[CAM_DEFAULT].targetPos.y = OriginalPlayerY;
            gCameras[CAM_DEFAULT].targetPos.z = npc->pos.z;
            if ((partnerActionStatus->pressedButtons & (BUTTON_B | BUTTON_C_DOWN)) || bss_802BFEF0 >= 30) {
                if (bss_802BFEF4 == 0) {
                    x = npc->pos.x;
                    y = npc->moveToPos.y + npc->collisionHeight;
                    z = npc->pos.z;

                    t = npc_test_move_taller_with_slipping(npc->collisionChannel, &x, &y, &z, 10.0f, npc->yaw,
                                                           npc->collisionHeight, npc->collisionRadius);
                    if (t != 0) {
                        collisionStatus->pushingAgainstWall = npc->currentWall = NpcHitQueryColliderID;
                    } else {
                        collisionStatus->pushingAgainstWall = NO_COLLIDER;
                    }

                    if (npc->currentWall < 0 || npc->currentWall & COLLISION_WITH_ENTITY_BIT) {
                        if (bss_802BFEE4 == 2 && bss_802BFEE8 == 1) {
                            sfx_play_sound_at_npc(SOUND_294, SOUND_SPACE_MODE_0, NPC_PARTNER);
                        }
                        break;
                    }
                    collider = get_collider_flags(npc->currentWall) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                    if (collider != SURFACE_TYPE_DOCK_WALL) {
                        if (bss_802BFEE4 == 2 && bss_802BFEE8 == 1) {
                            sfx_play_sound_at_npc(SOUND_294, SOUND_SPACE_MODE_0, NPC_PARTNER);
                        }
                        break;
                    }
                    bss_802BFEF0 = 0;
                    x = npc->pos.x;
                    z = npc->pos.z;
                    y = npc->moveToPos.y + 100.0f;
                    add_vec2D_polar(&x, &z, 40.0f, npc->yaw);
                    dist = 100.0f;
                    collider = npc_raycast_down_around(npc->collisionChannel, &x, &y, &z, &dist, npc->yaw, 0.0f);
                    if (collider != 0) {
                        get_collider_center(npc->currentWall, &x, &y, &z);
                        dist = dist2D(npc->pos.x, npc->pos.z, x, z);
                        sin_cos_rad(DEG_TO_RAD(atan2(npc->pos.x, npc->pos.z, x, z)), &sinTheta, &cosTheta);
                        xTemp = npc->pos.x + ((sinTheta * dist) * 0.6);
                        zTemp = npc->pos.z - ((cosTheta * dist) * 0.6);
                        dist = 100.0f;
                        x = xTemp;
                        z = zTemp;
                        npc_raycast_down_around(npc->collisionChannel, &x, &y, &z, &dist, npc->yaw, 0.0f);
                        npc->moveToPos.y = y;
                        npc->moveToPos.x = x;
                        npc->moveToPos.z = z;
                        playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z, x, z);
                        npc->yaw = playerStatus->targetYaw;
                        dist = dist2D(playerStatus->position.x, playerStatus->position.z, npc->moveToPos.x, npc->moveToPos.z);
                        npc->jumpVelocity = 5.0f;
                        npc->jumpScale = 0.6f;
                        npc->duration = (2.0f * npc->jumpVelocity) / 0.6f;
                        npc->moveSpeed = dist / npc->duration;
                        npc->jumpVelocity += (npc->moveToPos.y - playerStatus->position.y) / npc->duration;
                        sfx_play_sound_at_npc(SOUND_JUMP_2081, SOUND_SPACE_MODE_0, NPC_PARTNER);
                        suggest_player_anim_allow_backward(ANIM_Mario1_BeforeJump);
                        enable_player_shadow();
                        playerStatus->flags |= PS_FLAG_MOVEMENT_LOCKED;
                        script->functionTemp[0] = 3;
                    }
                }
            }
            break;
        case 3:
            suggest_player_anim_allow_backward(ANIM_Mario1_Jump);
            script->functionTemp[0]++;
            // fallthrough
        case 4:
            if (npc->jumpVelocity <= 0.0f) {
                suggest_player_anim_allow_backward(ANIM_Mario1_Fall);
                script->functionTemp[0]++;
            }
            // fallthrough
        case 5:
            if (npc->jumpVelocity <= 0.0f) {
                playerStatus->position.y = y = player_check_collision_below(npc->jumpVelocity, &collider);
                if (collider > 0) {
                    suggest_player_anim_allow_backward(ANIM_Mario1_Land);
                }
            } else {
                playerStatus->position.y += npc->jumpVelocity;
            }
            npc->jumpVelocity -= npc->jumpScale;
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
            if (npc->duration != 0) {
                add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, npc->moveSpeed, npc->yaw);
                npc->duration--;
                break;
            }
            if (collider >= 0) {
                playerStatus->flags &= ~PS_FLAG_MOVEMENT_LOCKED;
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                npc->flags |= NPC_FLAG_IGNORE_WORLD_COLLISION;
                dist = dist2D(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z) +
                            (playerStatus->colliderDiameter * 0.5f);
                npc->jumpVelocity = 8.0f;
                npc->jumpScale = 1.0f;
                npc->moveSpeed = 4.0f;
                y = npc->moveToPos.y - npc->pos.y;
                npc->duration = (2.0f * npc->jumpVelocity) / npc->jumpScale;
                npc->moveSpeed = dist / npc->duration;
                npc->jumpVelocity += y / npc->duration;
                script->functionTemp[0] = 10;
            }
            break;
        case 10:
            npc->pos.y += npc->jumpVelocity;
            npc->jumpVelocity = npc->jumpVelocity - npc->jumpScale;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, npc->moveSpeed, npc->yaw);
            if (npc->duration == 0) {
                enable_player_static_collisions();
                enable_player_input();
                set_action_state(ACTION_STATE_IDLE);
                enable_npc_shadow(npc);
                partner_clear_player_tracking(npc);
                bss_802BFEEC = 0;
                npc->flags &= ~NPC_FLAG_8;
                npc->flags |= NPC_FLAG_GRAVITY;
                npc->flags &= ~NPC_FLAG_IGNORE_WORLD_COLLISION;
                gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
                partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;
                partnerActionStatus->actingPartner = 0;
                func_802DDFF8(ANIM_Mario1_Idle, 0, 0, 0, 0, 0, 0);
                func_8003D624(npc, FOLD_TYPE_NONE, 0, 0, 0, 0, 0);
                return ApiStatus_DONE1;
            }
            npc->duration--;
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldSushie_UseAbility = {
    EVT_CALL(func_802BE3A4_31F114)
    EVT_RETURN
    EVT_END
};

void world_sushie_init(Npc* sushie) {
    sushie->collisionHeight = 24;
    sushie->collisionRadius = 36;
    sushie->collisionChannel = COLLISION_CHANNEL_10000;
    bss_802BFEEC = 0;
    bss_802BFEE4 = 0;
    bss_802BFEE8 = 0;
    bss_802BFEF0 = 0;
    bss_802BFEF4 = 0;
}

API_CALLABLE(SushieTakeOut) {
    Npc* sushie = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(sushie);
    }

    return partner_get_out(sushie) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript EVS_WorldSushie_TakeOut = {
    EVT_CALL(SushieTakeOut)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* SushieTweesterPhysicsPtr = &SushieTweesterPhysics;

API_CALLABLE(SushieUpdate) {
    Npc* sushie = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(sushie, 1);
        mem_clear(SushieTweesterPhysicsPtr, sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_walking_update_player_tracking(sushie);
        partner_walking_update_motion(sushie);
        return ApiStatus_BLOCK;
    }

    switch (SushieTweesterPhysicsPtr->state) {
        case TWEESTER_PARTNER_INIT:
            SushieTweesterPhysicsPtr->state++;
            SushieTweesterPhysicsPtr->prevFlags = sushie->flags;
            SushieTweesterPhysicsPtr->radius = fabsf(dist2D(sushie->pos.x, sushie->pos.z,
                                                     entity->position.x, entity->position.z));
            SushieTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, sushie->pos.x, sushie->pos.z);
            SushieTweesterPhysicsPtr->angularVelocity = 6.0f;
            SushieTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            SushieTweesterPhysicsPtr->countdown = 120;
            sushie->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_8;
            sushie->flags &= ~NPC_FLAG_GRAVITY;
        case TWEESTER_PARTNER_ATTRACT:
            sin_cos_rad(DEG_TO_RAD(SushieTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);
            sushie->pos.x = entity->position.x + (sinAngle * SushieTweesterPhysicsPtr->radius);
            sushie->pos.z = entity->position.z - (cosAngle * SushieTweesterPhysicsPtr->radius);
            SushieTweesterPhysicsPtr->angle = clamp_angle(SushieTweesterPhysicsPtr->angle - SushieTweesterPhysicsPtr->angularVelocity);

            if (SushieTweesterPhysicsPtr->radius > 20.0f) {
                SushieTweesterPhysicsPtr->radius--;
            } else if (SushieTweesterPhysicsPtr->radius < 19.0f) {
                SushieTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(SushieTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
            SushieTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (SushieTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                SushieTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            sushie->pos.y += liftoffVelocity;
            sushie->renderYaw = clamp_angle(360.0f - SushieTweesterPhysicsPtr->angle);
            SushieTweesterPhysicsPtr->angularVelocity += 0.8;

            if (SushieTweesterPhysicsPtr->angularVelocity > 40.0f) {
                SushieTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--SushieTweesterPhysicsPtr->countdown == 0) {
                SushieTweesterPhysicsPtr->state++;
            }
            break;
        case TWEESTER_PARTNER_HOLD:
            sushie->flags = SushieTweesterPhysicsPtr->prevFlags;
            SushieTweesterPhysicsPtr->countdown = 30;
            SushieTweesterPhysicsPtr->state++;
            break;
        case TWEESTER_PARTNER_RELEASE:
            partner_walking_update_player_tracking(sushie);
            partner_walking_update_motion(sushie);

            if (--SushieTweesterPhysicsPtr->countdown == 0) {
                SushieTweesterPhysicsPtr->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = NULL;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldSushie_Update = {
    EVT_CALL(SushieUpdate)
    EVT_RETURN
    EVT_END
};

void func_802BF920_320690(Npc* sushie) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        sushie->flags = SushieTweesterPhysicsPtr->prevFlags;
        SushieTweesterPhysicsPtr->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking(sushie);
    }
}

API_CALLABLE(SushiePutAway) {
    Npc* sushie = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(sushie);
        gPlayerStatusPtr->animFlags &= ~PA_FLAG_RIDING_PARTNER;
    }

    return partner_put_away(sushie) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript EVS_WorldSushie_PutAway = {
    EVT_CALL(SushiePutAway)
    EVT_RETURN
    EVT_END
};

void world_sushie_pre_battle(Npc* sushie) {
    PartnerActionStatus* sushieActionStatus = &gPartnerActionStatus;

    if (bss_802BFEEC) {
        sushieActionStatus->npc = *sushie;
        sushieActionStatus->partnerAction_unk_1 = TRUE;
        enable_player_static_collisions();
        enable_player_input();
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(sushie);
    }

    sushieActionStatus->actingPartner = PARTNER_SUSHIE;
}

void world_sushie_post_battle(Npc* sushie) {
    PartnerActionStatus* sushieActionStatus = &gPartnerActionStatus;

    if (sushieActionStatus->partnerAction_unk_1) {
        *sushie = sushieActionStatus->npc;
        partner_use_ability();
    }
}

API_CALLABLE(func_802BFAB8_320828) {
    Npc* partnerNPC = get_npc_unsafe(NPC_PARTNER);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        OriginalPlayerY = playerStatus->position.y;
    }

    switch (script->functionTemp[0]) {
        case 0:
            gGameStatusPtr->keepUsingPartnerOnMapChange = TRUE;
            disable_player_static_collisions();
            disable_player_input();
            partnerNPC->pos.x = playerStatus->position.x;
            partnerNPC->pos.z = playerStatus->position.z;
            partnerNPC->pos.y = playerStatus->position.y;
            func_802BD368_31E0D8(partnerNPC->collisionChannel, partnerNPC->pos.x, partnerNPC->pos.y, partnerNPC->pos.z,
                                partnerNPC->yaw, partnerNPC->collisionRadius * 0.5f);
            partnerNPC->pos.y = OriginalPlayerY - (partnerNPC->collisionHeight * 0.5f);
            partnerNPC->yaw = atan2(partnerNPC->pos.x, partnerNPC->pos.z, script->varTable[1], script->varTable[3]);
            partnerNPC->currentAnim = ANIM_WorldSushie_Ride;
            partnerNPC->jumpScale = 0.0f;
            partnerNPC->moveSpeed = 3.0f;
            partnerNPC->moveToPos.x = partnerNPC->pos.x;
            partnerNPC->moveToPos.y = partnerNPC->pos.y;
            partnerNPC->moveToPos.z = partnerNPC->pos.z;
            partnerNPC->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_8;
            partnerNPC->flags &= ~NPC_FLAG_GRAVITY;
            disable_npc_shadow(partnerNPC);
            disable_player_shadow();

            if (script->varTable[12] == 0) {
                partner_kill_ability_script();
            } else {
                suggest_player_anim_always_forward(ANIM_MarioW2_RideSushie);
                if ((partnerNPC->yaw >= 0.0f) && (partnerNPC->yaw <= 180.0f)) {
                    partnerNPC->yawCamOffset = partnerNPC->yaw;
                    partnerNPC->isFacingAway = TRUE;
                }
            }

            script->functionTemp[1] = 25;
            script->functionTemp[0] = 1;
            break;
        case 1:
            npc_move_heading(partnerNPC, partnerNPC->moveSpeed, partnerNPC->yaw);
            func_802BD100_31DE70();

            if (!(script->functionTemp[1] & 3)) {
                fx_rising_bubble(0, partnerNPC->pos.x, partnerNPC->moveToPos.y +
                        (partnerNPC->collisionHeight * 0.5f), partnerNPC->pos.z, 0);
            }

            script->functionTemp[1]--;
            if (script->functionTemp[1] == 0) {
                if (script->varTable[12] == 1) {
                    set_action_state(ACTION_STATE_RIDE);
                    partner_use_ability();
                    return ApiStatus_DONE2;
                }

                enable_player_static_collisions();
                enable_player_input();
                return ApiStatus_DONE2;
            }

            break;
    }

    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldSushie_EnterMap = {
    EVT_CALL(func_802BFAB8_320828)
    EVT_RETURN
    EVT_END
};
