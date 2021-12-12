#include "common.h"
#include "../partners.h"
#include "npc.h"

extern s32 D_802BE0C0;
extern s32 D_802BE0C4;
extern s32 D_802BE0E4;
extern s32 D_802BE0E8;
extern s32 D_802BE0EC;

extern struct unkPartnerStruct* D_802BDFFC_32494C;

void func_802BDDF0_324740(Npc* partner);
s32 func_802BD540_323E90(void);

void func_802BD100_323A50(Npc* bow) {
    bow->collisionHeight = 26;
    bow->collisionRadius = 24;
    bow->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    D_802BE0C4 = FALSE;
    D_802BE0C0 = FALSE;
}

ApiStatus func_802BD130_323A80(Evt* script, s32 isInitialCall) {
    Npc* bow = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(bow);
    }

    return partner_get_out(bow) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

ApiStatus func_802BD168_323AB8(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* bow = script->owner2.npc;
    Entity* entity;
    f32 sp10, sp14, tempY;

    if (isInitialCall) {
        partner_flying_enable(bow, 1);
        mem_clear(D_802BDFFC_32494C, sizeof(*D_802BDFFC_32494C));
        D_8010C954 = NULL;
    }

    entity = D_8010C954;
    playerData->unk_2F4[9]++;

    if (entity == NULL) {
        partner_flying_update_player_tracking(bow);
        partner_flying_update_motion(bow);
        return 0;
    }

    switch (D_802BDFFC_32494C->unk_04){
        case 0:
            D_802BDFFC_32494C->unk_04 = 1;
            D_802BDFFC_32494C->flags = bow->flags;
            D_802BDFFC_32494C->unk_0C = fabsf(dist2D(bow->pos.x, bow->pos.z, entity->position.x, entity->position.z));
            D_802BDFFC_32494C->unk_10 = atan2(entity->position.x, entity->position.z, bow->pos.x, bow->pos.z);
            D_802BDFFC_32494C->unk_14 = 6.0f;
            D_802BDFFC_32494C->unk_18 = 50.0f;
            D_802BDFFC_32494C->unk_00 = 120;
            bow->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            bow->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad((D_802BDFFC_32494C->unk_10 * TAU) / 360.0f, &sp10, &sp14);
            bow->pos.x = entity->position.x + (sp10 * D_802BDFFC_32494C->unk_0C);
            bow->pos.z = entity->position.z - (sp14 * D_802BDFFC_32494C->unk_0C);
            D_802BDFFC_32494C->unk_10 = clamp_angle(D_802BDFFC_32494C->unk_10 - D_802BDFFC_32494C->unk_14);
            if (D_802BDFFC_32494C->unk_0C > 20.0f) {
                D_802BDFFC_32494C->unk_0C -= 1.0f;
            } else if (D_802BDFFC_32494C->unk_0C < 19.0f) {
                D_802BDFFC_32494C->unk_0C++;
            }

            tempY = sin_rad((D_802BDFFC_32494C->unk_18 * TAU) / 360.0f) * 3.0f;
            D_802BDFFC_32494C->unk_18 += 3.0f;

            if (D_802BDFFC_32494C->unk_18 > 150.0f) {
                D_802BDFFC_32494C->unk_18 = 150.0f;
            }

            bow->pos.y += tempY;
            bow->renderYaw = clamp_angle(360.0f - D_802BDFFC_32494C->unk_10);
            D_802BDFFC_32494C->unk_14 += 0.8;

            if (D_802BDFFC_32494C->unk_14 > 40.0f) {
                D_802BDFFC_32494C->unk_14 = 40.0f;
            }
            if (--D_802BDFFC_32494C->unk_00 == 0) {
                D_802BDFFC_32494C->unk_04++;
            }
            break;
        case 2:
            bow->flags = D_802BDFFC_32494C->flags;
            D_802BDFFC_32494C->unk_00 = 30;
            D_802BDFFC_32494C->unk_04++;
            break;
        case 3:
            partner_flying_update_player_tracking(bow);
            partner_flying_update_motion(bow);

            if (--D_802BDFFC_32494C->unk_00 == 0) {
                D_802BDFFC_32494C->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

void func_802BD4FC_323E4C(Npc* bow) {
    if (D_8010C954 != NULL) {
        D_8010C954 = NULL;
        bow->flags = D_802BDFFC_32494C->flags;
        D_802BDFFC_32494C->unk_04 = 0;
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

ApiStatus func_802BD694_323FE4(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Npc* bow = script->owner2.npc;
    f32 distance;

    if (isInitialCall) {
        func_802BD4FC_323E4C(bow);
        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_100000)) {
            if (func_800EA52C(9) != 0) {
                if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_200000) {
                    playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_200000;
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
            if (playerStatus->statusMenuCounterinputEnabledCounter) {
                return ApiStatus_DONE2;
            }

            playerStatus->flags |= PLAYER_STATUS_FLAGS_100;
            script->functionTemp[1] = 3;
            script->functionTemp[2] = disable_player_input();
            D_802BE0C4 = TRUE;
            script->functionTemp[0]++;
            break;
        case 41:
            if ((func_800EA52C(9) == 0 || is_starting_conversation()) &&
                 script->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter
                 && D_802BE0C4) {

                enable_player_input();
                D_802BE0C4 = FALSE;
                playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
                return ApiStatus_DONE2;
            }
            script->functionTemp[1]--;
            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter) {
                    if (D_802BE0C4) {
                        enable_player_input();
                        D_802BE0C4 = FALSE;
                    }
                    playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
                    return ApiStatus_DONE2;
                }
                script->functionTemp[0] = 20;
            }
            break;
    }

    switch (script->functionTemp[0]) {
        case 20:
            if (playerStatus->flags & PLAYER_STATUS_FLAGS_800) {
                playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
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
            bow->flags &= ~(NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_GRAVITY);
            partnerActionStatus->actionState.b[0] = 1;
            partnerActionStatus->actionState.b[3] = 9;
            playerStatus->flags |= PLAYER_STATUS_FLAGS_8000;
            func_800EF4E0();
            bow->moveToPos.x = playerStatus->position.x;
            bow->moveToPos.y = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
            bow->moveToPos.z = playerStatus->position.z;
            bow->currentAnim.w = 0x50002;
            bow->yaw = playerStatus->targetYaw;
            add_vec2D_polar(&bow->moveToPos.x, &bow->moveToPos.z, -2.0f, gCameras[gCurrentCameraID].currentYaw);
            add_vec2D_polar(&bow->moveToPos.x, &bow->moveToPos.z,
                            playerStatus->colliderDiameter * 0.5f, bow->yaw);
            bow->duration = 5;
            bow->yaw = atan2(bow->pos.x, bow->pos.z, playerStatus->position.x, playerStatus->position.z);
            set_action_state(ACTION_STATE_RIDE);
            suggest_player_anim_clearUnkFlag(0x10002);
            script->functionTemp[0]++;
            break;
        case 21:
            if (collisionStatus->currentFloor >= 0 &&
               (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_100000) == 0) {
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
                    suggest_player_anim_setUnkFlag(0x10014);
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
                    playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
                    bow->flags |= 0x40;
                }

                get_shadow_by_index(bow->shadowIndex)->unk_05 = playerStatus->alpha1 >> 1;
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
                 playerStatus->flags & PLAYER_STATUS_FLAGS_800) {
                if (func_802BD540_323E90() < 0) {
                    script->functionTemp[0]++;
                    script->functionTemp[1] = 3;
                    script->functionTemp[2] = playerStatus->statusMenuCounterinputEnabledCounter;
                }
            }
            break;
        case 3:
            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter) {
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

void func_802BDDF0_324740(Npc* bow) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    s32 actionState;

    playerStatus->alpha1 = 255;
    func_8003D624(bow, 0, 0, 0, 0, 0, 0);
    bow->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    get_shadow_by_index(bow->shadowIndex)->unk_05 = playerStatus->alpha1 >> 1;

    if (D_802BE0C4) {
        enable_player_input();
    }

    playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_8000 | PLAYER_STATUS_FLAGS_JUMPING);
    bow->flags &= ~(NPC_FLAG_40 | NPC_FLAG_2);
    D_802BE0C4 = FALSE;
    actionState = ACTION_STATE_IDLE;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_800) {
        actionState = ACTION_STATE_HIT_LAVA;
    }

    set_action_state(actionState);
    partnerActionStatus->actionState.b[0] = 0;
    partnerActionStatus->actionState.b[3] = 0;
    playerStatus->flags &= ~PLAYER_STATUS_FLAGS_100;
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

void func_802BDF64_3248B4(Npc* bow) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (D_802BE0C0) {
        enable_player_input();
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(bow);
        partnerActionStatus->actionState.b[0] = 0;
        partnerActionStatus->actionState.b[3] = 0;
        D_802BE0C0 = FALSE;
        bow->flags &= ~NPC_FLAG_2;
    }
}
