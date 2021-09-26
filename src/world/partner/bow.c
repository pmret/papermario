#include "common.h"
#include "../partners.h"
#include "../../npc.h"

extern s32 D_802BE0C0;
extern s32 D_802BE0C4;
extern s32 D_802BE0E4;
extern s32 D_802BE0E8;
extern s32 D_802BE0EC;

extern struct unkPartnerStruct* D_802BDFFC_32494C;

void func_802BDDF0_324740(Npc* partner);
s32 func_802BD540_323E90(void);

void func_802BD100_323A50(Npc* partner) {
    partner->collisionHeight = 26;
    partner->collisionRadius = 24;
    partner->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    D_802BE0C4 = 0;
    D_802BE0C0 = 0;
}

ApiStatus func_802BD130_323A80(Evt* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;
    if (isInitialCall) {
        partner_init_get_out(owner);
    }
    return partner_get_out(owner) != 0;
}

s32 func_802BD168_323AB8(Evt* evt, s32 arg1) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc;
    Entity* entity;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    npc = evt->owner2.npc;
    if (arg1 != 0) {
        partner_flying_enable(npc, 1);
        mem_clear(D_802BDFFC_32494C, sizeof(*D_802BDFFC_32494C));
        D_8010C954 = 0;
    }
    entity = D_8010C954;
    playerData->unk_2F4[9]++;
    if (entity == NULL) {
        partner_flying_update_player_tracking(npc);
        partner_flying_update_motion(npc);
        return 0;
    }

    switch (D_802BDFFC_32494C->unk_04){
        case 0:
            D_802BDFFC_32494C->unk_04 = 1;
            D_802BDFFC_32494C->unk_08 = npc->flags;
            D_802BDFFC_32494C->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BDFFC_32494C->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BDFFC_32494C->unk_14 = 6.0f;
            D_802BDFFC_32494C->unk_18 = 50.0f;
            D_802BDFFC_32494C->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BDFFC_32494C->unk_10 * TAU) / 360.0f, &sp10, &sp14);
            npc->pos.x = entity->position.x + (sp10 * D_802BDFFC_32494C->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BDFFC_32494C->unk_0C);
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
            npc->pos.y += tempY;
            npc->renderYaw = clamp_angle(360.0f - D_802BDFFC_32494C->unk_10);
            D_802BDFFC_32494C->unk_14 += 0.8;
            if (D_802BDFFC_32494C->unk_14 > 40.0f) {
                D_802BDFFC_32494C->unk_14 = 40.0f;
            }
            if (--D_802BDFFC_32494C->unk_00 == 0) {
                D_802BDFFC_32494C->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BDFFC_32494C->unk_08;
            D_802BDFFC_32494C->unk_00 = 0x1E;
            D_802BDFFC_32494C->unk_04++;
            break;
        case 3:
            partner_flying_update_player_tracking(npc);
            partner_flying_update_motion(npc);
            if (--D_802BDFFC_32494C->unk_00 == 0) {
                D_802BDFFC_32494C->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

void func_802BD4FC_323E4C(Npc* partner) {
    if (D_8010C954 != 0) {
        D_8010C954 = 0;
        partner->flags = D_802BDFFC_32494C->unk_08;
        D_802BDFFC_32494C->unk_04 = 0;
        partner_clear_player_tracking(partner);
    }
}

INCLUDE_ASM(s32, "world/partner/bow", func_802BD540_323E90);

s32 func_802BD694_323FE4(Evt* arg0, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Npc* npc;
    f32 distance;

    npc = arg0->owner2.npc;
    if (arg1 != 0) {
        func_802BD4FC_323E4C(npc);
        if (!(playerStatus->animFlags & 0x100000)) {
            if (func_800EA52C(9) != 0) {
                if (playerStatus->animFlags & 0x200000) {
                    playerStatus->animFlags &= ~0x200000;
                    arg0->functionTemp[2] = disable_player_input();
                    D_802BE0C4 = 1;
                    arg0->functionTemp[0] = 20;
                } else {
                    arg0->functionTemp[0] = 40;
                }
            } else {
                return 2;
            }
        } else {
            return 2;
        }
    }

    switch (arg0->functionTemp[0]) {
        case 40:
            if (playerStatus->statusMenuCounterinputEnabledCounter != 0) {
                return 2;
            }
            playerStatus->flags |= 0x100;
            arg0->functionTemp[1] = 3;
            arg0->functionTemp[2] = disable_player_input();
            D_802BE0C4 = 1;
            arg0->functionTemp[0]++;
            break;
        case 41:
            if ((func_800EA52C(9) == 0 || is_starting_conversation()) &&
                 arg0->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter
                 && D_802BE0C4 != 0) {

                enable_player_input();
                D_802BE0C4 = 0;
                playerStatus->flags &= ~0x100;
                return 2;
            }
            arg0->functionTemp[1]--;
            if (arg0->functionTemp[1] == 0) {
                if (arg0->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter) {
                    if (D_802BE0C4 != 0) {
                        enable_player_input();
                        D_802BE0C4 = 0;
                    }
                    playerStatus->flags &= ~0x100;
                    return 2;
                }
                arg0->functionTemp[0] = 20;
            }
            break;
    }

    switch (arg0->functionTemp[0]) {
        case 20:
            if ((playerStatus->flags & 0x800) != 0) {
                playerStatus->flags &= ~0x100;
                if (D_802BE0C4 != 0) {
                    enable_player_input();
                    D_802BE0C4 = 0;
                }
                return 2;
            }
            if (arg0->functionTemp[2] != 0) {
                D_802BE0C4 = 1;
            }

            D_802BE0C0 = 1;
            npc->flags &= ~0xA00;
            partnerActionStatus->actionState.b[0] = 1;
            partnerActionStatus->actionState.b[3] = 9;
            playerStatus->flags |= 0x8000;
            func_800EF4E0();
            npc->moveToPos.x = playerStatus->position.x;
            npc->moveToPos.y = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
            npc->moveToPos.z = playerStatus->position.z;
            npc->currentAnim.w = 0x50002;
            npc->yaw = playerStatus->targetYaw;
            add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, -2.0f, gCameras[gCurrentCameraID].currentYaw);
            add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z,
                            playerStatus->colliderDiameter * 0.5f, npc->yaw);
            npc->duration = 5;
            npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
            set_action_state(ACTION_STATE_RIDE);
            suggest_player_anim_clearUnkFlag(0x10002);
            arg0->functionTemp[0]++;
            break;
        case 21:
            if (collisionStatus->currentFloor >= 0 && (playerStatus->animFlags & 0x100000) == 0) {
                npc->moveToPos.x = playerStatus->position.x;
                npc->moveToPos.y = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
                npc->moveToPos.z = playerStatus->position.z;
                npc->pos.x += ((npc->moveToPos.x - npc->pos.x) / npc->duration);
                npc->pos.y += ((npc->moveToPos.y - npc->pos.y) / npc->duration);
                npc->pos.z += ((npc->moveToPos.z - npc->pos.z) / npc->duration);
                D_802BE0E4 = playerStatus->position.x - npc->pos.x;
                D_802BE0E8 = playerStatus->position.y - npc->pos.y;
                D_802BE0EC = playerStatus->position.z - npc->pos.z;
                npc->duration--;
                if (npc->duration == 0) {
                    npc->yaw = playerStatus->targetYaw;
                    func_8003D624(npc, 7, playerStatus->alpha1, 0, 0, 0, 0);
                    suggest_player_anim_setUnkFlag(0x10014);
                    sfx_play_sound_at_npc(SOUND_BOW_VANISH, 0, -4);
                    arg0->functionTemp[0] = 1;
                }
                break;
            }
            func_802BDDF0_324740(npc);
            return 2;
        case 1:
            if (collisionStatus->currentFloor >= 0) {
                playerStatus->alpha1 -= 8;
                if (playerStatus->alpha1 < 0x81) {
                    playerStatus->alpha1 = 0x80;
                    npc->renderMode = 0x16;
                    arg0->functionTemp[0]++;
                    playerStatus->flags &= ~0x100;
                    npc->flags |= 0x40;
                }
                get_shadow_by_index(npc->shadowIndex)->unk_05 = playerStatus->alpha1 >> 1;
                func_8003D624(npc, 7, playerStatus->alpha1, 0, 0, 0, 0);
                npc->pos.x = playerStatus->position.x - D_802BE0E4;
                npc->pos.y = playerStatus->position.y - D_802BE0E8;
                npc->pos.z = playerStatus->position.z - D_802BE0EC;
                break;
            }
            func_802BDDF0_324740(npc);
            return 2;
        case 2:
            if (collisionStatus->currentFloor < 0) {
                func_802BDDF0_324740(npc);
                return 2;
            }
            npc->pos.x = playerStatus->position.x - D_802BE0E4;
            npc->pos.y = playerStatus->position.y - D_802BE0E8;
            npc->pos.z = playerStatus->position.z - D_802BE0EC;

            distance = dist2D(0.0f, 0.0f, partnerActionStatus->stickX, partnerActionStatus->stickY);
            if ((collisionStatus->currentFloor < 0) || distance > 10.0f ||
                 partnerActionStatus->pressedButtons & (BUTTON_B | BUTTON_C_DOWN) || playerStatus->flags & 0x800) {
                if (func_802BD540_323E90() < 0) {
                    arg0->functionTemp[0]++;
                    arg0->functionTemp[1] = 3;
                    arg0->functionTemp[2] = playerStatus->statusMenuCounterinputEnabledCounter;
                }
            }
            break;
        case 3:
            if (arg0->functionTemp[1] == 0) {
                if (arg0->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter) {
                    arg0->functionTemp[0] = 2;
                    break;
                }
            } else {
                arg0->functionTemp[1]--;
                break;
            }

            sfx_play_sound_at_npc(SOUND_BOW_APPEAR, 0, -4);
            func_802BDDF0_324740(npc);
            return 1;
    }
    return 0;
}

void func_802BDDF0_324740(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    s32 actionState;

    playerStatus->alpha1 = 0xFF;
    func_8003D624(partner, 0, 0, 0, 0, 0, 0);
    partner->renderMode = 0x11;
    get_shadow_by_index(partner->shadowIndex)->unk_05 = playerStatus->alpha1 >> 1;

    if (D_802BE0C4 != 0) {
        enable_player_input();
    }

    playerStatus->flags &= ~0x8002;
    partner->flags &= ~0x42;
    D_802BE0C4 = 0;
    actionState = ACTION_STATE_IDLE;
    if ((playerStatus->flags & 0x800) != 0) {
        actionState = ACTION_STATE_HIT_LAVA;
    }

    set_action_state(actionState);
    partnerActionStatus->actionState.b[0] = 0;
    partnerActionStatus->actionState.b[3] = 0;
    playerStatus->flags &= ~0x100;
    partner_clear_player_tracking(partner);
    D_802BE0C0 = 0;
}

s32 func_802BDF08_324858(Evt* arg0, s32 arg1) {
    Npc* partner = arg0->owner2.npc;
    if (arg1 != 0) {
        partner_init_put_away(partner);
        if (D_802BE0C0 != 0) {
            sfx_play_sound_at_npc(SOUND_BOW_APPEAR, 0, -4);
        }
        func_802BDDF0_324740(partner);
    }
    return partner_put_away(partner) != 0;
}

void func_802BDF64_3248B4(Npc* arg0) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (D_802BE0C0 != 0) {
        enable_player_input();
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(arg0);
        partnerActionStatus->actionState.b[0] = 0;
        partnerActionStatus->actionState.b[3] = 0;
        D_802BE0C0 = 0;
        arg0->flags &= ~0x2;
    }
}
