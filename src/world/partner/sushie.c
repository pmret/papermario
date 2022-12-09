#include "common.h"
#include "world/partners.h"
#include "npc.h"
#include "effects.h"
#include "sprite/npc/WorldSushie.h"
#include "sprite.h"

extern s16 D_8010C97A;

BSS f32 OriginalPlayerY;
BSS s32 bss_802BFEE4;
BSS s32 bss_802BFEE8;
BSS s32 D_802BFEEC;
BSS s32 bss_802BFEF0;
BSS s32 bss_802BFEF4;
BSS s32 D_802BFEF8;
BSS f32 bss_802BFEFC;
BSS s32 bss_802BFF00;
BSS s32 bss_802BFF04;
BSS s32 bss_802BFF08;
BSS s32 bss_802BFF0C;
BSS TweesterPhysics SushieTweesterPhysics;


f32 D_802BFDB0_320B20 = 0.0f;
f32 D_802BFDB4_320B24 = 0.0f;
f32 D_802BFDB8_320B28 = 0.0f;
f32 D_802BFDBC_320B2C = 0.0f;


void func_802BD100_31DE70(void) {
    Npc* partnerNPC = get_npc_unsafe(NPC_PARTNER);
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cam = &gCameras[CAM_DEFAULT];
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
        cam->currentYaw + playerStatus->spriteFacingAngle - 90.0f + phi_v1)) * -4.0f;
}

void func_802BD20C_31DF7C(f32* arg0, f32* arg1) {
    f32 temp_f22;
    f32 phi_f20;
    f32 temp_f2 = gPartnerActionStatus.stickY;
    f32 temp_f0 = gPartnerActionStatus.stickX;

    D_802BFDB0_320B20 = temp_f0;
    D_802BFDB4_320B24 = temp_f2;
    temp_f22 = clamp_angle(atan2(0.0f, 0.0f, temp_f0, -temp_f2) + gCameras[CAM_DEFAULT].currentYaw);
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
        collisionStatus->currentFloor = -1;
    } else {
        collisionStatus->currentFloor = D_8010C97A;
        OriginalPlayerY = arg2;
    }
}

void func_802BD414_31E184(Npc*);
INCLUDE_ASM(s32, "world/partner/sushie", func_802BD414_31E184);

s32 func_802BE280_31EFF0(s32 arg0, f32* x, f32* y, f32* z, f32 length, f32 radius, f32* yaw) {
    f32 sinAngle, cosAngle, hitX, hitY, hitZ, totalLength, hitNx, hitNy, hitNz;
    s32 hitResult;

    sin_cos_rad(DEG_TO_RAD(*yaw), &sinAngle, &cosAngle);
    cosAngle = -cosAngle;
    totalLength = radius + length;
    hitResult = test_ray_colliders(0x10000, *x, *y, *z, sinAngle, 0.0f, cosAngle, &hitX, &hitY, &hitZ, &totalLength, &hitNx, &hitNy, &hitNz);

    if (hitResult >= 0) {
        *yaw = atan2(0.0f, 0.0f, hitNx, hitNz);
    }

    return hitResult;
}

ApiStatus func_802BE3A4_31F114(Evt* script, s32 isInitialCall);
// various issues
#ifdef WIP
extern s32 D_802BFF00;
extern s32 D_802BFF04;
extern s32 D_802BFF08;

ApiStatus func_802BE3A4_31F114(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;

    Npc* npc = script->owner2.npc;
    f32 temp_f0;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f12;
    f32 temp_f2;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 var_a1;
    f32 var_a2;
    f32 var_a3;
    f64 temp_f0_2;
    f64 temp_f2_3;
    s16 temp_a0_4;

    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_6;
    s32 temp_v0_7;

    s32 var_v1;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 var_v0_4;

    if (isInitialCall) {
        func_802BF920_320690(npc);
        bss_802BFEFC = 0.0f;
        D_802BFEF8 = 0;
        D_802BFF00 = 0;
        D_802BFF04 = 0;
        D_802BFF08 = 0;
        script->functionTemp[0] = 0;
    }
    playerData->partnerUsedTime[7]++;
    playerStatus->animFlags &= ~0x400000;

    switch (script->functionTemp[0]) {
        case 0:
            if (gGameStatusPtr->keepUsingPartnerOnMapChange == 0) {
                if (collisionStatus->currentWall >= 0) {
                    if (!(collisionStatus->currentWall & 0x4000)) {
                        temp_v0 = get_collider_flags(collisionStatus->currentWall) & 0xFF;
                        sp40 = temp_v0;
                        if (temp_v0 != 4) {
                            return ApiStatus_DONE1;
                        }
                        script->functionTemp[0] = 0x14;
                        break;
                    }
                }
                return ApiStatus_DONE1;
            }
            temp_f2 = npc->pos.y;
            npc->moveToPos.y = temp_f2;
            playerStatus->position.y = temp_f2 + 16.0f;
            D_802BFEEC = 1;
            npc->flags = ((npc->flags | 8) & ~0x200) | 0x100;
            suggest_player_anim_setUnkFlag(0x8000FU);
            disable_player_shadow();
            disable_npc_shadow(npc);
            func_8003D624(npc, 4, 2, 0, 0, 0, 0);
            npc->currentAnim = 0x7000A;
            npc->moveSpeed = playerStatus->runSpeed;
            npc->jumpScale = 0.0f;
            partnerActionStatus->partnerActionState = 1;
            gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
            partnerActionStatus->actingPartner = 7;
            bss_802BFEE4 = 0;
            bss_802BFEE8 = 0;
            script->functionTemp[2] = 0;
            script->functionTemp[0] = 1;
            break;
        case 20:
            if (collisionStatus->currentWall >= 0) {
                get_collider_center(collisionStatus->currentWall, &sp20, &sp24, &sp28);
                sp2C = atan2(sp20, sp28, playerStatus->position.x, playerStatus->position.z);
                sp20 = playerStatus->position.x;
                sp24 = playerStatus->position.y;
                sp28 = playerStatus->position.z;
                temp_v0_2 = func_802BE280_31EFF0(0, &sp20, &sp24, &sp28, playerStatus->colliderDiameter * 0.5f, 2.0f * playerStatus->colliderDiameter, &sp2C);
                var_v1 = -1;
                sp40 = temp_v0_2;
                if (temp_v0_2 >= 0) {
                    var_v1 = get_collider_flags(temp_v0_2) & 0xFF;
                }
                if (var_v1 == 4) {
                    D_802BFEEC = 1;
                    set_action_state(0x21);
                    disable_player_static_collisions();
                    disable_player_input();
                    npc->collisionChannel = 0x80000;
                    npc->moveToPos.x = playerStatus->position.x;
                    npc->moveToPos.y = playerStatus->position.y;
                    npc->moveToPos.z = playerStatus->position.z;
                    npc->yaw = sp2C;
                    playerStatus->targetYaw = sp2C;
                    npc->renderYaw = 90.0f;
                    add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, 40.0f, npc->yaw);
                    sp20 = npc->moveToPos.x;
                    sp24 = npc->moveToPos.y;
                    sp28 = npc->moveToPos.z;
                    sp30 = 100.0f;
                    sp40 = npc_raycast_down_around(npc->collisionChannel, &sp20, &sp24, &sp28, &sp30, npc->yaw, npc->collisionRadius);
                    npc->currentAnim = 0x70003;
                    npc->duration = 12;
                    npc->moveToPos.y = sp24 - (npc->collisionHeight * 0.5f);
                    suggest_player_anim_clearUnkFlag(0x10002U);
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
                    sfx_play_sound_at_npc(0x2081, 0, -4);
                    suggest_player_anim_clearUnkFlag(0x10006U);
                }
                break;
            }
            npc->collisionChannel = 0x10000;
            npc->flags = (npc->flags | 8) & ~0x240;
            disable_npc_shadow(npc);
            func_8003D624(npc, 4, 2, 0, 0, 0, 0);
            npc->currentAnim = 0x7000A;
            playerStatus->flags |= 0x400000;
            temp_f0 = dist2D(playerStatus->position.x, playerStatus->position.z, npc->moveToPos.x, npc->moveToPos.z);
            npc->jumpVelocity = 5.0f;
            npc->jumpScale = 0.6f;
            temp_f6_2 = npc->moveToPos.y - playerStatus->position.y;
            sp30 = temp_f0;
            sp24 = temp_f6_2;
            npc->duration = (2.0f * npc->jumpVelocity) / 0.6f;
            npc->moveSpeed = temp_f0 / npc->duration;
            npc->jumpVelocity += temp_f6_2 / npc->duration;
            suggest_player_anim_clearUnkFlag(0x10007U);
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
                suggest_player_anim_clearUnkFlag(0x10008U);
            }
            gCameras->targetPos.x = playerStatus->position.x;
            gCameras->targetPos.y = playerStatus->position.y;
            gCameras->targetPos.z = playerStatus->position.z;

            if (npc->duration == 0) {
                set_action_state(0x21);
                disable_player_shadow();
                playerStatus->flags &= ~0x400000;
                suggest_player_anim_setUnkFlag(0x8000FU);
                sfx_play_sound_at_npc(0x2013, 0, -4);
                playerStatus->position.x = npc->pos.x;
                playerStatus->position.y = npc->pos.y;
                playerStatus->position.z = npc->pos.z;
                playerStatus->targetYaw = npc->yaw;
                npc->moveSpeed = 3.0f;
                partnerActionStatus->partnerActionState = 1;
                gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
                partnerActionStatus->actingPartner = 7;
                bss_802BFEE4 = 0;
                bss_802BFEE8 = 0;
                script->functionTemp[2] = 0;
                script->functionTemp[0] = 1;
            } else {
                npc->duration--;
            }
            break;
        case 1:
            playerStatus->animFlags |= 0x400000;
            func_802BD414_31E184(npc);
            if (bss_802BFEE4 == 0) {
                script->functionTemp[2]++;
                if (script->functionTemp[2] > 20) {
                    script->functionTemp[2] -= 40;
                }
                npc->pos.y = npc->moveToPos.y + (abs(script->functionTemp[2]) * 0.125f);
                if (script->functionTemp[2] == 5) {
                    func_802BD20C_31DF7C(&sp2C, &sp34);
                    if (bss_802BFEE4 == 0) {
                        if (sp34 != 0.0f) {
                            sfx_play_sound_at_npc(0x2015, 0, -4);
                        } else {
                            sfx_play_sound_at_npc(0x2014, 0, -4);
                        }
                    }
                }
                if ((D_802BFEF8 == 0.0f) && !((gGameStatusPtr->frameCounter % 10) & 0xFFFF)) {
                    fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + (npc->collisionHeight * 0.5f), npc->pos.z, 0.0f);
                }
            } else {
                npc->pos.y = npc->moveToPos.y;
            }
            if (!(playerStatus->animFlags & 0x400000)) {
                func_802BD100_31DE70();
            }

            if (bss_802BFEE4 == 1) {
                temp_a0_2 = gGameStatusPtr->frameCounter;
                temp_hi = MULTU_HI(temp_a0_2, 0xAF286BCB);
                if (!((temp_a0_2 - (((u32) (temp_hi + ((u32) (temp_a0_2 - temp_hi) >> 1)) >> 4) * 19)) & 0xFFFF)) {
                    var_a1 = npc->pos.x;
                    var_a3 = npc->pos.z;
                    var_a2 = npc->moveToPos.y + (npc->collisionHeight * 0.5f);
                    goto block_52;
                }
            } else if ((D_802BFEF8 != 0.0f) && (bss_802BFEE4 < 2)) {
                temp_a0_3 = gGameStatusPtr->frameCounter;
                temp_hi_2 = gGameStatusPtr->frameCounter / 7;
                if (!((temp_a0_3 - (((u32) (temp_hi_2 + ((u32) (temp_a0_3 - temp_hi_2) >> 1)) >> 2) * 7)) & 0xFFFF)) {
                    if (bss_802BFEE4 != 0) {

                    }
                    var_a1 = npc->pos.x;
                    var_a2 = npc->moveToPos.y + (npc->collisionHeight * 0.5f);
                    var_a3 = npc->pos.z;
block_52:
                    fx_rising_bubble(0, var_a1, var_a2, var_a3, 0); // MISSING ARG
                }
            }

            // if (bss_802BFEE4 == 1) {
            //     //temp_a0_4 = gGameStatusPtr->frameCounter % 19 & 0xFFFF;
            //     //temp_hi = temp_a0_4 % 3;
            //     if (!(gGameStatusPtr->frameCounter % 19)) {
            //         //need to fix tail merge here
            //         fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + (npc->collisionHeight * 0.5f), npc->pos.z, (OriginalPlayerY - npc->pos.y));
            //     }
            // } else if ((D_802BFEF8 != 0.0f) && (bss_802BFEE4 < 2)) {
            //     if (!((gGameStatusPtr->frameCounter - (gGameStatusPtr->frameCounter / 7 + ((gGameStatusPtr->frameCounter / 7 - gGameStatusPtr->frameCounter)))))) {
            //         if (gGameStatusPtr->frameCounter != 0) {
            //             fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + (npc->collisionHeight * 0.5f), npc->pos.z, (OriginalPlayerY - npc->pos.y));

            //         } else {
            //             fx_rising_bubble(0, npc->pos.x, npc->moveToPos.y + (npc->collisionHeight * 0.5f), npc->pos.z, (OriginalPlayerY - npc->pos.y));
            //         }
            //     }
            // }

            gCameras->targetPos.x = npc->pos.x;
            gCameras->targetPos.y = OriginalPlayerY;
            gCameras->targetPos.z = npc->pos.z;
            if ((partnerActionStatus->pressedButtons & 0x4004) || (((bss_802BFEF0 < 0x1E) == 0))) {
                if (bss_802BFEF4 == 0) {
                    sp20 = npc->pos.x;
                    sp28 = npc->pos.z;
                    sp24 = npc->moveToPos.y + npc->collisionHeight;
                    var_v0_4 = -1U;
                    if (npc_test_move_taller_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, 10.0f, npc->yaw, npc->collisionHeight, npc->collisionRadius) != 0) {
                        var_v0_4 = (u16) D_8010C97A;
                        npc->currentWall = (s16) var_v0_4;
                    }
                    collisionStatus->pushingAgainstWall = (s16) var_v0_4;
                    temp_a0_4 = npc->currentWall;
                    if ((temp_a0_4 < 0) || ((u16) npc->currentWall & 0x4000) || (temp_v0_6 = get_collider_flags(temp_a0_4) & 0xFF, sp40 = temp_v0_6, (temp_v0_6 != 4))) {
                        if (bss_802BFEE4 == 2) {
                            if (bss_802BFEE8 == 1) {
                                sfx_play_sound_at_npc(0x294, 0, -4);
                                break;
                            }
                        }
                        break;
                    }
                    bss_802BFEF0 = 0;
                    sp20 = npc->pos.x;
                    sp28 = npc->pos.z;
                    sp24 = npc->moveToPos.y + 100.0f;
                    add_vec2D_polar(&sp20, &sp28, 40.0f, npc->yaw);
                    sp30 = 100.0f;
                    temp_v0_7 = npc_raycast_down_around(npc->collisionChannel, &sp20, &sp24, &sp28, &sp30, npc->yaw, 0.0f);
                    sp40 = temp_v0_7;
                    if (temp_v0_7 != 0) {
                        get_collider_center(npc->currentWall, &sp20, &sp24, &sp28);
                        sp30 = dist2D(npc->pos.x, npc->pos.z, sp20, sp28);
                        sin_cos_rad((atan2(npc->pos.x, npc->pos.z, sp20, sp28) * 6.28318f) / 360.0f, &sp38, &sp3C);
                        temp_f2_3 = npc->pos.x + ((sp38 * sp30) * 0.6);
                        temp_f0_2 = npc->pos.z - ((sp3C * sp30) * 0.6);
                        sp30 = 100.0f;
                        sp20 = temp_f2_3;
                        sp28 = temp_f0_2;
                        npc_raycast_down_around(npc->collisionChannel, &sp20, &sp24, &sp28, &sp30, npc->yaw, 0.0f);
                        npc->moveToPos.y = sp24;
                        npc->moveToPos.x = sp20;
                        npc->moveToPos.z = sp28;
                        temp_f0_3 = atan2(playerStatus->position.x, playerStatus->position.z, sp20, sp28);
                        playerStatus->targetYaw = temp_f0_3;
                        npc->yaw = temp_f0_3;
                        temp_f0_4 = dist2D(playerStatus->position.x, playerStatus->position.z, npc->moveToPos.x, npc->moveToPos.z);
                        npc->jumpVelocity = 5.0f;
                        npc->jumpScale = 0.6f;
                        npc->duration = (2.0f * npc->jumpVelocity) / 0.6f;
                        npc->moveSpeed = temp_f0_4 / npc->duration;
                        sp30 = temp_f0_4;
                        npc->jumpVelocity += (npc->moveToPos.y - playerStatus->position.y) / npc->duration;
                        sfx_play_sound_at_npc(0x2081, 0, -4);
                        suggest_player_anim_clearUnkFlag(0x10006U);
                        enable_player_shadow();
                        playerStatus->flags |= 0x400000;
                        script->functionTemp[0] = 3;
                    }
                }
            }
            break;
        case 3:
            suggest_player_anim_clearUnkFlag(0x10007U);
            script->functionTemp[0]++;
            // fallthrough
        case 4:
            if (npc->jumpVelocity <= 0.0f) {
                suggest_player_anim_clearUnkFlag(0x10008U);
                script->functionTemp[0]++;
            }
            // fallthrough
        case 5:
            temp_f12 = npc->jumpVelocity;
            if (temp_f12 <= 0.0f) {
                temp_f0_5 = player_check_collision_below(temp_f12, &sp40);
                sp24 = temp_f0_5;
                playerStatus->position.y = temp_f0_5;
                if (sp40 > 0) {
                    suggest_player_anim_clearUnkFlag(0x10009U);
                }
            } else {
                playerStatus->position.y += temp_f12;
            }
            npc->jumpVelocity -= npc->jumpScale;
            gCameras->targetPos.x = playerStatus->position.x;
            gCameras->targetPos.y = playerStatus->position.y;
            gCameras->targetPos.z = playerStatus->position.z;
            if (npc->duration != 0) {
                add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, npc->moveSpeed, npc->yaw);
                npc->duration--;
                break;
            }
            if (sp40 >= 0) {
                playerStatus->flags &= ~0x400000;
                suggest_player_anim_clearUnkFlag(0x10002);
                npc->flags |= 0x40;
                temp_f0_6 = dist2D(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
                npc->jumpVelocity = 8.0f;
                npc->jumpScale = 1.0f;
                npc->moveSpeed = 4.0f;
                temp_f6_3 = npc->moveToPos.y - npc->pos.y;
                sp24 = temp_f6_3;
                npc->duration = (2.0f * npc->jumpVelocity) / 1.0f;
                temp_f0_7 = temp_f0_6 + (playerStatus->colliderDiameter * 0.5f);
                sp30 = temp_f0_7;
                npc->moveSpeed = temp_f0_7 / npc->duration;
                npc->jumpVelocity += temp_f6_3 / npc->duration;
                script->functionTemp[0] = 10;
            }
            break;
        case 10:
            temp_f0_8 = npc->jumpVelocity;
            npc->pos.y += temp_f0_8;
            npc->jumpVelocity = temp_f0_8 - npc->jumpScale;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, npc->moveSpeed, npc->yaw);
            if (npc->duration == 0) {
                enable_player_static_collisions();
                enable_player_input();
                set_action_state(0);
                enable_npc_shadow(npc);
                partner_clear_player_tracking(npc);
                D_802BFEEC = 0;
                npc->flags = ((npc->flags & ~8) | 0x200) & ~0x40;
                gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
                partnerActionStatus->partnerActionState = 0;
                partnerActionStatus->actingPartner = 0;
                func_802DDFF8(0x10002, 0, 0, 0, 0, 0, 0);
                func_8003D624(npc, 0, 0, 0, 0, 0, 0);
                return 1;
            }
            npc->duration--;
            break;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/partner/sushie", func_802BE3A4_31F114);
#endif

EvtScript world_sushie_use_ability = {
    EVT_CALL(func_802BE3A4_31F114)
    EVT_RETURN
    EVT_END
};

void world_sushie_init(Npc* sushie) {
    sushie->collisionHeight = 24;
    sushie->collisionRadius = 36;
    sushie->collisionChannel = COLLISION_CHANNEL_10000;
    D_802BFEEC = 0;
    bss_802BFEE4 = 0;
    bss_802BFEE8 = 0;
    bss_802BFEF0 = 0;
    bss_802BFEF4 = 0;
}

s32 SushieTakeOut(Evt* script, s32 isInitialCall) {
    Npc* sushie = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(sushie);
    }

    return partner_get_out(sushie) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_sushie_take_out = {
    EVT_CALL(SushieTakeOut)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* SushieTweesterPhysicsPtr = &SushieTweesterPhysics;

ApiStatus SushieUpdate(Evt* script, s32 isInitialCall) {
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
        case 0:
            SushieTweesterPhysicsPtr->state = 1;
            SushieTweesterPhysicsPtr->prevFlags = sushie->flags;
            SushieTweesterPhysicsPtr->radius = fabsf(dist2D(sushie->pos.x, sushie->pos.z,
                                                     entity->position.x, entity->position.z));
            SushieTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, sushie->pos.x, sushie->pos.z);
            SushieTweesterPhysicsPtr->angularVelocity = 6.0f;
            SushieTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            SushieTweesterPhysicsPtr->countdown = 120;
            sushie->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            sushie->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
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
        case 2:
            sushie->flags = SushieTweesterPhysicsPtr->prevFlags;
            SushieTweesterPhysicsPtr->countdown = 30;
            SushieTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_walking_update_player_tracking(sushie);
            partner_walking_update_motion(sushie);

            if (--SushieTweesterPhysicsPtr->countdown == 0) {
                SushieTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

EvtScript world_sushie_update = {
    EVT_CALL(SushieUpdate)
    EVT_RETURN
    EVT_END
};

void func_802BF920_320690(Npc* sushie) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        sushie->flags = SushieTweesterPhysicsPtr->prevFlags;
        SushieTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking(sushie);
    }
}

s32 SushiePutAway(Evt* script, s32 isInitialCall) {
    Npc* sushie = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(sushie);
        gPlayerStatusPtr->animFlags &= ~PA_FLAGS_RIDING_PARTNER;
    }

    return partner_put_away(sushie) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_sushie_put_away = {
    EVT_CALL(SushiePutAway)
    EVT_RETURN
    EVT_END
};

void world_sushie_pre_battle(Npc* sushie) {
    PartnerActionStatus* sushieActionStatus = &gPartnerActionStatus;

    if (D_802BFEEC) {
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

s32 func_802BFAB8_320828(Evt* script, s32 isInitialCall) {
    Npc* partnerNPC = get_npc_unsafe(NPC_PARTNER);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        OriginalPlayerY = playerStatus->position.y;
    }

    switch (script->functionTemp[0]) {
        case 0:
            gGameStatusPtr->keepUsingPartnerOnMapChange = 1;
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
            partnerNPC->flags |= NPC_FLAG_100 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            partnerNPC->flags &= ~NPC_FLAG_GRAVITY;
            disable_npc_shadow(partnerNPC);
            disable_player_shadow();

            if (script->varTable[12] == 0) {
                partner_kill_ability_script();
            } else {
                suggest_player_anim_setUnkFlag(ANIM_Mario_8000F);
                if ((partnerNPC->yaw >= 0.0f) && (partnerNPC->yaw <= 180.0f)) {
                    partnerNPC->yawCamOffset = partnerNPC->yaw;
                    partnerNPC->isFacingAway = 1;
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

EvtScript world_sushie_while_riding = {
    EVT_CALL(func_802BFAB8_320828)
    EVT_RETURN
    EVT_END
};
