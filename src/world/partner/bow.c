#include "common.h"
#include "../partners.h"
#include "npc.h"

BSS s32 D_802BE0C0;
BSS s32 D_802BE0C4;
BSS TweesterPhysics BowTweesterPhysics;
BSS s32 D_802BE0E4;
BSS s32 D_802BE0E8;
BSS s32 D_802BE0EC;

void func_802BDDF0_324740(Npc* partner);
s32 func_802BD540_323E90(void);

void world_bow_init(Npc* bow) {
    bow->collisionHeight = 26;
    bow->collisionRadius = 24;
    bow->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    D_802BE0C4 = FALSE;
    D_802BE0C0 = FALSE;
}

ApiStatus BowTakeOut(Evt* script, s32 isInitialCall) {
    Npc* bow = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(bow);
    }

    return partner_get_out(bow) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_bow_take_out = {
    EVT_CALL(BowTakeOut)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* BowTweesterPhysicsPtr = &BowTweesterPhysics;

ApiStatus BowUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* bow = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_flying_enable(bow, 1);
        mem_clear(BowTweesterPhysicsPtr, sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    entity = TweesterTouchingPartner;
    playerData->partnerUsedTime[PARTNER_BOW]++;

    if (entity == NULL) {
        partner_flying_update_player_tracking(bow);
        partner_flying_update_motion(bow);
        return 0;
    }

    switch (BowTweesterPhysicsPtr->state){
        case 0:
            BowTweesterPhysicsPtr->state = 1;
            BowTweesterPhysicsPtr->prevFlags = bow->flags;
            BowTweesterPhysicsPtr->radius = fabsf(dist2D(bow->pos.x, bow->pos.z, entity->position.x, entity->position.z));
            BowTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, bow->pos.x, bow->pos.z);
            BowTweesterPhysicsPtr->angularVelocity = 6.0f;
            BowTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            BowTweesterPhysicsPtr->countdown = 120;
            bow->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            bow->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad(DEG_TO_RAD(BowTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);
            bow->pos.x = entity->position.x + (sinAngle * BowTweesterPhysicsPtr->radius);
            bow->pos.z = entity->position.z - (cosAngle * BowTweesterPhysicsPtr->radius);
            BowTweesterPhysicsPtr->angle = clamp_angle(BowTweesterPhysicsPtr->angle - BowTweesterPhysicsPtr->angularVelocity);
            if (BowTweesterPhysicsPtr->radius > 20.0f) {
                BowTweesterPhysicsPtr->radius -= 1.0f;
            } else if (BowTweesterPhysicsPtr->radius < 19.0f) {
                BowTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(BowTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
            BowTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (BowTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                BowTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            bow->pos.y += liftoffVelocity;
            bow->renderYaw = clamp_angle(360.0f - BowTweesterPhysicsPtr->angle);
            BowTweesterPhysicsPtr->angularVelocity += 0.8;

            if (BowTweesterPhysicsPtr->angularVelocity > 40.0f) {
                BowTweesterPhysicsPtr->angularVelocity = 40.0f;
            }
            if (--BowTweesterPhysicsPtr->countdown == 0) {
                BowTweesterPhysicsPtr->state++;
            }
            break;
        case 2:
            bow->flags = BowTweesterPhysicsPtr->prevFlags;
            BowTweesterPhysicsPtr->countdown = 30;
            BowTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_flying_update_player_tracking(bow);
            partner_flying_update_motion(bow);

            if (--BowTweesterPhysicsPtr->countdown == 0) {
                BowTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return 0;
}

EvtScript world_bow_update = {
    EVT_CALL(BowUpdate)
    EVT_RETURN
    EVT_END
};

void func_802BD4FC_323E4C(Npc* bow) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        bow->flags = BowTweesterPhysicsPtr->prevFlags;
        BowTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking(bow);
    }
}

#ifdef NON_MATCHING
s32 func_802BD540_323E90(void) {
    f32 sp20, sp24, sp28;
    f32 temp_f12, temp_f22;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 tempX, tempZ;

    if (gGameStatusPtr->areaID != AREA_OMO) {
        return -1;
    } else {
        if (gPlayerStatus.extraVelocity.x != 0.0f || gPlayerStatus.extraVelocity.z != 0.0f) {
            temp_f22 = atan2(0.0f, 0.0f, gPlayerStatus.extraVelocity.x, gPlayerStatus.extraVelocity.z);
            temp_f12 = temp_f22 + 180.0f;
            sp20 = gPlayerStatus.position.x;
            sp24 = gPlayerStatus.position.z;
            sp28 = gPlayerStatus.position.y + (gPlayerStatus.colliderHeight * 0.5f);
            add_vec2D_polar(&sp20, &sp24, gPlayerStatus.colliderDiameter * 0.5f, clamp_angle(temp_f12));
            return player_test_lateral_overlap(0, &gPlayerStatus, &sp20, &sp28, &sp24,
                                               gPlayerStatus.colliderDiameter, temp_f22);
        }

        return -1;
    }
}
#else
INCLUDE_ASM(s32, "world/partner/bow", func_802BD540_323E90);
#endif

ApiStatus BowUseAbility(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Npc* bow = script->owner2.npc;
    f32 distance;

    if (isInitialCall) {
        func_802BD4FC_323E4C(bow);
        if (!(playerStatus->animFlags & PA_FLAGS_100000)) {
            if (func_800EA52C(9)) {
                if (playerStatus->animFlags & PA_FLAGS_200000) {
                    playerStatus->animFlags &= ~PA_FLAGS_200000;
                    script->functionTemp[2] = disable_player_input();
                    D_802BE0C4 = TRUE;
                    script->functionTemp[0] = 20;
                } else {
                    script->functionTemp[0] = 40;
                }
            } else {
                return ApiStatus_DONE2;
            }
        } else {
            return ApiStatus_DONE2;
        }
    }

    switch (script->functionTemp[0]) {
        case 40:
            if (playerStatus->inputEnabledCounter) {
                return ApiStatus_DONE2;
            }

            playerStatus->flags |= PS_FLAGS_100;
            script->functionTemp[1] = 3;
            script->functionTemp[2] = disable_player_input();
            D_802BE0C4 = TRUE;
            script->functionTemp[0]++;
            break;
        case 41:
            if ((!func_800EA52C(9) || is_starting_conversation()) &&
                 script->functionTemp[2] < playerStatus->inputEnabledCounter
                 && D_802BE0C4) {

                enable_player_input();
                D_802BE0C4 = FALSE;
                playerStatus->flags &= ~PS_FLAGS_100;
                return ApiStatus_DONE2;
            }
            script->functionTemp[1]--;
            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] < playerStatus->inputEnabledCounter) {
                    if (D_802BE0C4) {
                        enable_player_input();
                        D_802BE0C4 = FALSE;
                    }
                    playerStatus->flags &= ~PS_FLAGS_100;
                    return ApiStatus_DONE2;
                }
                script->functionTemp[0] = 20;
            }
            break;
    }

    switch (script->functionTemp[0]) {
        case 20:
            if (playerStatus->flags & PS_FLAGS_800) {
                playerStatus->flags &= ~PS_FLAGS_100;
                if (D_802BE0C4) {
                    enable_player_input();
                    D_802BE0C4 = FALSE;
                }
                return ApiStatus_DONE2;
            }
            if (script->functionTemp[2] != 0) {
                D_802BE0C4 = TRUE;
            }

            D_802BE0C0 = TRUE;
            bow->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_GRAVITY);
            partnerActionStatus->partnerActionState = 1;
            partnerActionStatus->actingPartner = 9;
            playerStatus->flags |= PS_FLAGS_8000;
            func_800EF4E0();
            bow->moveToPos.x = playerStatus->position.x;
            bow->moveToPos.y = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
            bow->moveToPos.z = playerStatus->position.z;
            bow->currentAnim = 0x50002;
            bow->yaw = playerStatus->targetYaw;
            add_vec2D_polar(&bow->moveToPos.x, &bow->moveToPos.z, -2.0f, gCameras[gCurrentCameraID].currentYaw);
            add_vec2D_polar(&bow->moveToPos.x, &bow->moveToPos.z,
                            playerStatus->colliderDiameter * 0.5f, bow->yaw);
            bow->duration = 5;
            bow->yaw = atan2(bow->pos.x, bow->pos.z, playerStatus->position.x, playerStatus->position.z);
            set_action_state(ACTION_STATE_RIDE);
            suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
            script->functionTemp[0]++;
            break;
        case 21:
            if (collisionStatus->currentFloor >= 0 &&
               (playerStatus->animFlags & PA_FLAGS_100000) == 0) {
                bow->moveToPos.x = playerStatus->position.x;
                bow->moveToPos.y = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
                bow->moveToPos.z = playerStatus->position.z;
                bow->pos.x += ((bow->moveToPos.x - bow->pos.x) / bow->duration);
                bow->pos.y += ((bow->moveToPos.y - bow->pos.y) / bow->duration);
                bow->pos.z += ((bow->moveToPos.z - bow->pos.z) / bow->duration);
                D_802BE0E4 = playerStatus->position.x - bow->pos.x;
                D_802BE0E8 = playerStatus->position.y - bow->pos.y;
                D_802BE0EC = playerStatus->position.z - bow->pos.z;
                bow->duration--;
                if (bow->duration == 0) {
                    bow->yaw = playerStatus->targetYaw;
                    func_8003D624(bow, 7, playerStatus->alpha1, 0, 0, 0, 0);
                    suggest_player_anim_setUnkFlag(ANIM_Mario_Crouch);
                    sfx_play_sound_at_npc(SOUND_BOW_VANISH, 0, -4);
                    script->functionTemp[0] = 1;
                }
                break;
            }

            func_802BDDF0_324740(bow);
            return ApiStatus_DONE2;
        case 1:
            if (collisionStatus->currentFloor >= 0) {
                playerStatus->alpha1 -= 8;
                if (playerStatus->alpha1 <= 128) {
                    playerStatus->alpha1 = 128;
                    bow->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
                    script->functionTemp[0]++;
                    playerStatus->flags &= ~PS_FLAGS_100;
                    bow->flags |= 0x40;
                }

                get_shadow_by_index(bow->shadowIndex)->alpha = playerStatus->alpha1 >> 1;
                func_8003D624(bow, 7, playerStatus->alpha1, 0, 0, 0, 0);
                bow->pos.x = playerStatus->position.x - D_802BE0E4;
                bow->pos.y = playerStatus->position.y - D_802BE0E8;
                bow->pos.z = playerStatus->position.z - D_802BE0EC;
                break;
            }

            func_802BDDF0_324740(bow);
            return ApiStatus_DONE2;
        case 2:
            if (collisionStatus->currentFloor < 0) {
                func_802BDDF0_324740(bow);
                return ApiStatus_DONE2;
            }

            bow->pos.x = playerStatus->position.x - D_802BE0E4;
            bow->pos.y = playerStatus->position.y - D_802BE0E8;
            bow->pos.z = playerStatus->position.z - D_802BE0EC;

            distance = dist2D(0.0f, 0.0f, partnerActionStatus->stickX, partnerActionStatus->stickY);
            if ((collisionStatus->currentFloor < 0) || distance > 10.0f ||
                 partnerActionStatus->pressedButtons & (BUTTON_B | BUTTON_C_DOWN) ||
                 playerStatus->flags & PS_FLAGS_800) {
                if (func_802BD540_323E90() < 0) {
                    script->functionTemp[0]++;
                    script->functionTemp[1] = 3;
                    script->functionTemp[2] = playerStatus->inputEnabledCounter;
                }
            }
            break;
        case 3:
            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] < playerStatus->inputEnabledCounter) {
                    script->functionTemp[0] = 2;
                    break;
                }
            } else {
                script->functionTemp[1]--;
                break;
            }

            sfx_play_sound_at_npc(SOUND_BOW_APPEAR, 0, -4);
            func_802BDDF0_324740(bow);
            return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

EvtScript world_bow_use_ability = {
    EVT_CALL(BowUseAbility)
    EVT_RETURN
    EVT_END
};

void func_802BDDF0_324740(Npc* bow) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    s32 actionState;

    playerStatus->alpha1 = 255;
    func_8003D624(bow, 0, 0, 0, 0, 0, 0);
    bow->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    get_shadow_by_index(bow->shadowIndex)->alpha = playerStatus->alpha1 >> 1;

    if (D_802BE0C4) {
        enable_player_input();
    }

    playerStatus->flags &= ~(PS_FLAGS_8000 | PS_FLAGS_JUMPING);
    bow->flags &= ~(NPC_FLAG_40 | NPC_FLAG_2);
    D_802BE0C4 = FALSE;
    actionState = ACTION_STATE_IDLE;

    if (playerStatus->flags & PS_FLAGS_800) {
        actionState = ACTION_STATE_HIT_LAVA;
    }

    set_action_state(actionState);
    partnerActionStatus->partnerActionState = 0;
    partnerActionStatus->actingPartner = 0;
    playerStatus->flags &= ~PS_FLAGS_100;
    partner_clear_player_tracking(bow);
    D_802BE0C0 = FALSE;
}

ApiStatus func_802BDF08_324858(Evt* script, s32 isInitialCall) {
    Npc* bow = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(bow);
        if (D_802BE0C0) {
            sfx_play_sound_at_npc(SOUND_BOW_APPEAR, 0, -4);
        }
        func_802BDDF0_324740(bow);
    }

    return partner_put_away(bow) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_bow_put_away = {
    EVT_CALL(func_802BDF08_324858)
    EVT_RETURN
    EVT_END
};

void world_bow_pre_battle(Npc* bow) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (D_802BE0C0) {
        enable_player_input();
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(bow);
        partnerActionStatus->partnerActionState = 0;
        partnerActionStatus->actingPartner = 0;
        D_802BE0C0 = FALSE;
        bow->flags &= ~NPC_FLAG_2;
    }
}
