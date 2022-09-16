#include "common.h"
#include "world/partners.h"
#include "effects.h"

BSS s32 D_802BE920;
BSS s32 D_802BE924;
BSS s32 D_802BE928;
BSS s32 D_802BE92C;
BSS s32 D_802BE930;
BSS s32 D_802BE934;
BSS s32 D_802BE938;
BSS s32 D_802BE93C;
BSS TweesterPhysics BombetteTweesterPhysics;

void entity_interacts_with_current_partner(s32 arg0);

void func_802BD100_317E50(Npc* npc) {
    f32 x, y, z;
    f32 angle = 0.0f;

    while (angle < 360.0f) {
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;
        if (npc_test_move_taller_with_slipping(0x100000, &x, &y, &z, 30.0f, clamp_angle(npc->yaw + angle),
                                               npc->collisionHeight, npc->collisionRadius) != 0) {
            break;
        } else {
            angle += 45.0f;
        }
    }

    if (angle >= 360.0f) {
        angle = 0.0f;

        while (angle < 360.0f) {
            x = npc->pos.x;
            y = npc->pos.y;
            z = npc->pos.z;
            if (npc_test_move_taller_with_slipping(0x40000, &x, &y, &z, 30.0f, clamp_angle(npc->yaw + angle),
                                                   npc->collisionHeight, npc->collisionRadius) != 0) {
                break;
            } else {
                angle += 45.0f;
            }
        }

        if (!(angle >= 360.0f)) {
            if (D_8010C978 >= 0 && (D_8010C978 & COLLISION_WITH_ENTITY_BIT) != 0) {
                entity_interacts_with_current_partner(D_8010C978 & ~COLLISION_WITH_ENTITY_BIT);
            }
        }
    } else {
        if (D_8010C978 >= 0 && (D_8010C978 & COLLISION_WITH_ENTITY_BIT) != 0) {
            entity_interacts_with_current_partner(D_8010C978 & ~COLLISION_WITH_ENTITY_BIT);
        }
    }
}

void world_bombette_init(Npc* bombette) {
    bombette->collisionHeight = 28;
    bombette->collisionRadius = 24;
    D_802BE928 = 0;
    D_802BE924 = 0;
}

ApiStatus func_802BD300_318050(Evt* script, s32 isInitialCall) {
    Npc* bombette = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(bombette);
    }

    return partner_get_out(bombette) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_bombette_take_out = {
    EVT_CALL(func_802BD300_318050)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* BombetteTweesterPhysicsPtr = &BombetteTweesterPhysics;

ApiStatus func_802BD338_318088(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* bombette = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(bombette, 1);
        mem_clear(BombetteTweesterPhysicsPtr, sizeof(TweesterPhysics));
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

    switch (BombetteTweesterPhysicsPtr->state) {
        case 0:
            BombetteTweesterPhysicsPtr->state = 1;
            BombetteTweesterPhysicsPtr->prevFlags = bombette->flags;
            BombetteTweesterPhysicsPtr->radius = fabsf(dist2D(bombette->pos.x, bombette->pos.z,
                                                     entity->position.x, entity->position.z));
            BombetteTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z,
                                              bombette->pos.x, bombette->pos.z);
            BombetteTweesterPhysicsPtr->angularVelocity = 6.0f;
            BombetteTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            BombetteTweesterPhysicsPtr->countdown = 120;
            bombette->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            bombette->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad(DEG_TO_RAD(BombetteTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);
            bombette->pos.x = entity->position.x + (sinAngle * BombetteTweesterPhysicsPtr->radius);
            bombette->pos.z = entity->position.z - (cosAngle * BombetteTweesterPhysicsPtr->radius);
            BombetteTweesterPhysicsPtr->angle = clamp_angle(BombetteTweesterPhysicsPtr->angle - BombetteTweesterPhysicsPtr->angularVelocity);

            if (BombetteTweesterPhysicsPtr->radius > 20.0f) {
                BombetteTweesterPhysicsPtr->radius--;
            } else if (BombetteTweesterPhysicsPtr->radius < 19.0f) {
                BombetteTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(BombetteTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
            BombetteTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (BombetteTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                BombetteTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            bombette->pos.y += liftoffVelocity;
            bombette->renderYaw = clamp_angle(360.0f - BombetteTweesterPhysicsPtr->angle);
            BombetteTweesterPhysicsPtr->angularVelocity += 0.8;

            if (BombetteTweesterPhysicsPtr->angularVelocity > 40.0f) {
                BombetteTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--BombetteTweesterPhysicsPtr->countdown == 0) {
                BombetteTweesterPhysicsPtr->state++;
            }
            break;
        case 2:
            bombette->flags = BombetteTweesterPhysicsPtr->prevFlags;
            BombetteTweesterPhysicsPtr->countdown = 0x1E;
            BombetteTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_walking_update_player_tracking(bombette);
            partner_walking_update_motion(bombette);

            if (--BombetteTweesterPhysicsPtr->countdown == 0) {
                BombetteTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript world_bombette_update = {
    EVT_CALL(func_802BD338_318088)
    EVT_RETURN
    EVT_END
};

void func_802BD6DC_31842C(Npc* npc) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        npc->flags = BombetteTweesterPhysicsPtr->prevFlags;
        BombetteTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking(npc);
    }
}

s32 world_bombette_can_use_ability(Npc* npc) {
    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE) {
        D_802BE934 = 1;
        return FALSE;
    }
    return TRUE;
}

s32 world_bombette_can_player_pause(Npc* npc) {
    return gPartnerActionStatus.partnerActionState == PARTNER_ACTION_NONE;
}

ApiStatus func_802BD758_3184A8(Evt* evt, s32 isInitialCall);
// control flol
#ifdef NON_MATCHING
ApiStatus func_802BD758_3184A8(Evt* evt, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    f32 x, y, z, hitDepth;
    Npc* npc = evt->owner2.npc;
    f32* zPtr;
    f32* xPtr;

    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_5;
    s32 var_v0_5;
    f32 temp1;

    if (gCurrentEncounter.unk_08 != 0) {
        return 0;
    }
    if (isInitialCall) {
        func_802BD6DC_31842C(npc);
        evt->functionTemp[0] = 20;
    }

    switch (evt->functionTemp[0]) {
        case 20:
            if ((playerStatus->inputEnabledCounter != 0) || (playerStatus->flags & 2) || !(npc->flags & 0x1000)) {
                return ApiStatus_DONE2;
            }
            disable_player_input();
            evt->functionTemp[3] = playerStatus->inputEnabledCounter;
            D_802BE92C = 1;
            D_802BE928 = 0;
            D_802BE930 = 0;
            D_802BE934 = 0;
            npc->flags &= ~0xA48;
            partnerActionStatus->partnerActionState = 1;
            partnerActionStatus->actingPartner = 3;
            D_802BE920 = func_800EF4E0();
            enable_npc_blur(npc);
            npc->duration = 4;
            npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
            suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
            evt->functionTemp[0] = 21;
        case 21:
            if (playerStatus->actionState == 0x15 || playerStatus->actionState == 0x16) {
                disable_npc_blur(npc);
                evt->functionTemp[0] = 7;
                break;
            }

            if ((playerStatus->flags & 2)) {
                evt->functionTemp[0] = 7;
                break;
            }

            npc->moveToPos.x = playerStatus->position.x;
            npc->moveToPos.y = playerStatus->position.y;
            npc->moveToPos.z = playerStatus->position.z;
            npc->currentAnim = 0x30007;
            add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, 0.0f, playerStatus->targetYaw);

            temp_f0 = clamp_angle(playerStatus->targetYaw + ((D_802BE920 != 0) ? -90.0f : 90.0f));
            add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, playerStatus->colliderDiameter / 4, temp_f0);
            npc->pos.x += (npc->moveToPos.x -  npc->pos.x) / npc->duration;
            npc->pos.y += (npc->moveToPos.y - npc->pos.y) /  npc->duration;
            npc->pos.z += (npc->moveToPos.z - npc->pos.z) /  npc->duration;
            npc->duration--;

            if (npc->duration != 0) {
                break;
            }

            if (evt->functionTemp[3] < playerStatus->inputEnabledCounter) {
                disable_npc_blur(npc);
                evt->functionTemp[0] = 7;
            } else {
                npc->pos.x = npc->moveToPos.x;
                npc->pos.y = npc->moveToPos.y;
                npc->pos.z = npc->moveToPos.z;
                disable_npc_blur(npc);
                suggest_player_anim_clearUnkFlag(ANIM_Mario_6000C);
                npc->yaw = playerStatus->targetYaw;
                npc->currentAnim = 0x30005;
                evt->functionTemp[0] = 1;
                evt->functionTemp[1] = 10;
            }
        case 1:
            if (!(playerStatus->actionState == 0x15 || playerStatus->actionState == 0x16)) {
                npc->pos.y = playerStatus->position.y + playerStatus->colliderHeight;
                npc->yaw = playerStatus->targetYaw;
                if (evt->functionTemp[1] == 1) {
                    suggest_player_anim_clearUnkFlag(ANIM_Mario_60006);
                }

                if (evt->functionTemp[1] != 0) {
                    evt->functionTemp[1]--;
                    break;
                }

                sfx_play_sound_at_npc(0x80000000, 0, -4);
                D_802BE924 = 1;
                add_vec2D_polar(&npc->pos.x, &npc->pos.z, 0.0f, npc->yaw);
                npc->currentAnim = 0x30006;
                npc->jumpVelocity = 0.0f;
                D_802BE938 = 0;
                npc->flags = (npc->flags | 0x200) & ~0x100;
                npc->moveSpeed = 1.0f;
                evt->functionTemp[0] = 2;
                evt->functionTemp[1] = 50;
            } else {
                evt->functionTemp[1] = 7;
                break;
            }
        case 2:
            if ((playerStatus->animFlags & 4) || (playerStatus->actionState == 0x15 || playerStatus->actionState == 0x16)) {
                evt->functionTemp[0] = 7;
                break;
            }

            if (evt->functionTemp[1] < 45) {
                if (!(npc->flags & 0x2000) && (D_802BE938 == 0)) {
                    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                    func_8003D660(npc, 0);
                } else {
                    D_802BE938 = 1;
                }
            }

            x = npc->pos.x;
            y = npc->pos.y + 14.0f;
            z = npc->pos.z;
            hitDepth = 16.0f;
            if ((npc_raycast_down_around(0x10000, &x, &y, &z, &hitDepth, npc->yaw, npc->collisionRadius) != 0) && ((u32) ((get_collider_flags(D_8010C978) & 0xFF) - 2) < 2U)) {
                if (playerStatus->actionState == 0) {
                    suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                }
                npc->currentAnim = 0x30010;
                npc->flags &= ~0x200;
                evt->functionTemp[1] = 2;
                evt->functionTemp[0] = 3;
                if (D_802BE92C != 0) {
                    D_802BE92C = 0;
                    enable_player_input();
                }
            } else {
                if (!(evt->functionTemp[1] & 3)) {
                    if (gGameStatusPtr->frameCounter & 1) {
                        sfx_play_sound_at_npc(0x141, 0, -4);
                    } else {
                        sfx_play_sound_at_npc(0x142, 0, -4);
                    }
                }
                if (evt->functionTemp[1] == 40) {
                    if (playerStatus->actionState == 0) {
                        suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                    }
                    enable_player_input();
                    D_802BE92C = 0;
                }
                npc_do_other_npc_collision(npc);

                if (npc->flags & 0x02000000) {
                    if (D_802BE92C != 0) {
                        D_802BE92C = 0;
                        enable_player_input();
                    }
                } else {
                    if (D_802BE934 == 0) {
                        if (evt->functionTemp[1] != 0) {
                            evt->functionTemp[1]--;
                            break;
                        }
                    }
                }

                npc->currentAnim = 0x30000 | 0x10;
                evt->functionTemp[1] = 0x14;
                evt->functionTemp[0] = 3;
                if (playerStatus->actionState == 0) {
                    suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                }
            }
    }

    switch (evt->functionTemp[0]) {
        case 3:
            if (evt->functionTemp[1] != 0) {
                evt->functionTemp[1]--;
                break;
            }

            if (D_802BE924 != 0) {
                D_802BE924 = 0;
                sfx_stop_sound(0x80000000);
            }
            fx_explosion(gPlayerData.partners[gPlayerData.currentPartner].level, npc->pos.x, npc->pos.y + (npc->collisionHeight * 0.5f), npc->pos.z);

            switch (gPlayerData.partners[gPlayerData.currentPartner].level) {
                case 0:
                    sfx_play_sound_at_npc(0x2016, 0, -4);
                    break;
                case 1:
                    sfx_play_sound_at_npc(0x2017, 0, -4);
                    break;
                case 2:
                    sfx_play_sound_at_npc(0x2018, 0, -4);
                    break;
            }

            exec_ShakeCam1(0, 0, 0x14);
            func_8003D660(npc, 2);
            collisionStatus->bombetteExploded = 0;
            collisionStatus->bombetteExplosionPos.x = npc->pos.x;
            collisionStatus->bombetteExplosionPos.y = npc->pos.y;
            collisionStatus->bombetteExplosionPos.z = npc->pos.z;
            func_802BD100_317E50(npc);
            D_802BE928 = 1;
            partnerActionStatus->partnerActionState = 2;
            evt->functionTemp[1] = 3;
            evt->functionTemp[0]++;
            break;
        case 4:
            if (evt->functionTemp[1] != 0) {
                evt->functionTemp[1]--;
                break;
            }

            partnerActionStatus->partnerActionState = 3;
            D_802BE928 = 0;
            npc->jumpVelocity = ((playerStatus->position.y - npc->pos.y) / 20.0f) + 30.0;
            npc->moveSpeed = 0.8f;
            npc->yaw = rand_int(360);
            npc->jumpScale = 0.8f;
            npc->pos.y += 10.0f;
            npc->moveToPos.y = npc->pos.y ;
            collisionStatus->bombetteExploded = -1;
            collisionStatus->bombetteExplosionPos.x = npc->pos.x;
            collisionStatus->bombetteExplosionPos.y = npc->pos.y;
            collisionStatus->bombetteExplosionPos.z = npc->pos.z;
            npc->currentAnim = 0x30011;
            temp1 = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
            if (!(get_clamped_angle_diff(camera->currentYaw, temp1) < 0.0f)) {
                evt->functionTemp[2] = 1;
            } else {
                evt->functionTemp[2] = -1;
            }
            evt->functionTemp[1] = 10;
            evt->functionTemp[0] = 5;
            break;
        case 5:
            npc->pos.y += npc->jumpVelocity;
            npc->jumpVelocity -= npc->jumpScale;
            npc->rotation.z -= ((evt->functionTemp[2] * 0x4F) / 2);
            npc->rotation.x -= ((evt->functionTemp[2] * 0x43) / 2);
            if (evt->functionTemp[1] != 0) {
                evt->functionTemp[1]--;
                break;
            }

            if (D_802BE930 == 0) {
                npc->pos.x = playerStatus->position.x;
                npc->pos.z = playerStatus->position.z;
            }
            npc->yaw = clamp_angle(gCameras[CAM_DEFAULT].currentYaw + playerStatus->spriteFacingAngle);
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 10.0f, npc->yaw);
            npc->jumpVelocity = 0.0f;
            npc->currentAnim = 0x30011;
            npc->flags |= 0x800;
            evt->functionTemp[0] = 6;
            break;
        case 6:
            if (npc->pos.y + 10.0f < playerStatus->position.y + playerStatus->colliderHeight) {
                npc->flags &= ~0x800;
                if (fabsf(playerStatus->position.y - npc->pos.y) < 500.0) {
                    evt->functionTemp[0] = 8;
                    break;
                } else if (func_800397E8(npc, npc->jumpVelocity)) {
                    evt->functionTemp[0] = 7;
                    break;
                }
            }
            npc->pos.y += npc->jumpVelocity;
            npc->jumpVelocity -= npc->jumpScale;
            if (npc->jumpVelocity < -8.0) {
                npc->jumpVelocity = -8.0f;
            }
            npc->rotation.z -= ((evt->functionTemp[2] * 0x4F) / 2);
            npc->rotation.x -= ((evt->functionTemp[2] * 0x43) / 2);
            break;
    }


    switch (evt->functionTemp[0]) {
        case 7:
            if (playerStatus->actionState == 0) {
                suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
            }
            if (D_802BE92C != 0) {
                D_802BE92C = 0;
                enable_player_input();
            }
            partnerActionStatus->partnerActionState = 0;
            partnerActionStatus->actingPartner = 0;
            npc->jumpVelocity = 0.0f;
            D_802BE928 = 0;
            D_802BE934 = 0;
            npc->pos.y = playerStatus->position.y;
            npc->rotation.x = 0.0f;
            npc->rotation.z = 0.0f;
            npc->currentAnim = 0x30003;
            partner_clear_player_tracking(npc);
            if (D_802BE924 == 0) {
                return ApiStatus_DONE2;
            }
            D_802BE924 = 0;
            sfx_stop_sound(0x80000000);
            return ApiStatus_DONE2;
        case 8:
            if (D_802BE92C != 0) {
                D_802BE92C = 0;
                enable_player_input();
            }
            partnerActionStatus->partnerActionState = 0;
            partnerActionStatus->actingPartner = 0;
            npc->jumpVelocity = 0.0f;
            npc->pos.y = playerStatus->position.y;
            npc->rotation.x = 0.0f;
            npc->rotation.z = 0.0f;
            npc->currentAnim = 0x30003;
            npc->pos.x = playerStatus->position.x;
            npc->pos.y = playerStatus->position.y;
            npc->pos.z = playerStatus->position.z;
            D_802BE928 = 0;
            D_802BE934 = 0;
            xPtr = &npc->pos.x;
            zPtr = &npc->pos.z;
            if (D_802BE920 == 0) {
                temp_f0_5 = clamp_angle(playerStatus->targetYaw + 90.0f);
            } else {
                temp_f0_5 = clamp_angle(playerStatus->targetYaw - 90.0f);
            }

            add_vec2D_polar(xPtr, zPtr, playerStatus->colliderDiameter / 4, temp_f0_5);
            npc->jumpVelocity = 0.0f;
            partner_clear_player_tracking(npc);
            if (D_802BE924 == 0) {
                return ApiStatus_DONE2;
            }
            D_802BE924 = 0;
            sfx_stop_sound(0x80000000);
            break;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/partner/bombette", func_802BD758_3184A8);
#endif

EvtScript world_bombette_use_ability = {
    EVT_CALL(func_802BD758_3184A8)
    EVT_RETURN
    EVT_END
};

ApiStatus func_802BE4E8_319238(Evt* script, s32 isInitialCall) {
    Npc* bombette = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(bombette);
    }

    return partner_put_away(bombette) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_bombette_put_away = {
    EVT_CALL(func_802BE4E8_319238)
    EVT_RETURN
    EVT_END
};

s32 world_bombette_test_first_strike(Npc* bombette, Npc* enemy) {
    f32 adjustedDistanceX, adjustedDistanceY, adjustedDistanceZ;
    f32 temp_f6, temp_f20, npcZPos, bombetteZPos, npcXPos, bombetteXPos;
    s32 slippingResult;
    f32 distance;
    s32 ret;
    f32 temp2;
    f32 height;

    if (D_802BE928 == 0) {
        return FALSE;
    }

    npcXPos = enemy->pos.x;
    bombetteXPos = bombette->pos.x;
    adjustedDistanceX = enemy->pos.x - bombette->pos.x;

    adjustedDistanceY = (enemy->pos.y + (f32)(enemy->collisionHeight * 0.5) - bombette->pos.y);

    npcZPos = enemy->pos.z;
    bombetteZPos = bombette->pos.z;
    adjustedDistanceZ = npcZPos - bombetteZPos;

    temp_f6 = enemy->collisionRadius * 0.55;
    height = 35.0f;
    temp2 = sqrtf(SQ(adjustedDistanceX) + SQ(adjustedDistanceY) + SQ(adjustedDistanceZ));
    ret = FALSE;

    if (temp2 < (temp_f6 + height)) {
        ret = TRUE;
    }

    temp_f20 = atan2(npcXPos, npcZPos, bombetteXPos, bombetteZPos);
    distance = dist2D(npcXPos, npcZPos, bombetteXPos, bombetteZPos);

    adjustedDistanceX = bombette->pos.x;
    adjustedDistanceY = bombette->pos.y;
    adjustedDistanceZ = bombette->pos.z;

    slippingResult = npc_test_move_taller_with_slipping(0, &adjustedDistanceX, &adjustedDistanceY, &adjustedDistanceZ,
                                                        distance, temp_f20, height, 2.0f);

    if (slippingResult) {
        return FALSE;
    }

    return ret;
}

void world_bombette_pre_battle(Npc* bombette) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* bombetteActionStatus = &gPartnerActionStatus;

    if (bombetteActionStatus->partnerActionState != PARTNER_ACTION_NONE) {
        if (D_802BE92C) {
            enable_player_input();
        }

        D_802BE928 = 0;
        playerStatus->flags &= ~PS_FLAGS_JUMPING;
        bombette->jumpVelocity = 0.0f;
        bombette->flags &= ~NPC_FLAG_JUMPING;

        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(bombette);

        bombetteActionStatus->partnerActionState = 0;
        bombetteActionStatus->actingPartner = 0;

        bombette->pos.x = playerStatus->position.x;
        bombette->pos.y = playerStatus->position.y;
        bombette->pos.z = playerStatus->position.z;

        if (D_802BE920 == 0) {
            add_vec2D_polar(&bombette->pos.x, &bombette->pos.z,
                            playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw + 90.0f));
        } else {
            add_vec2D_polar(&bombette->pos.x, &bombette->pos.z,
                            playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw - 90.0f));
        }

        bombette->jumpVelocity = 0.0f;
        bombette->pos.y = playerStatus->position.y;
        bombette->rotation.x = 0.0f;
        bombette->rotation.z = 0.0f;
        bombette->currentAnim = 0x30003;
        partner_clear_player_tracking(bombette);
        disable_npc_blur(bombette);

        if (D_802BE924) {
            D_802BE924 = 0;
            sfx_stop_sound(0x80000000);
        }
    }
}
