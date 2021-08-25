#include "common.h"
#include "world/actions.h"

extern f32 D_802B6770_E27C80;

//wip - not good yet
#ifdef NON_MATCHING
void func_802B6000_E28A30(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= 0x7FF7FFF1;
        playerStatus->fallState = 0;
        playerStatus->framesOnGround = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_8C = 0.0f;
    }

    if (playerStatus->animFlags & 0x400000) {
        if (gPartnerActionStatus.actionState.b[3]  == 8) {
            func_802BD100_317020(playerStatus->flags);
        } else if (gPartnerActionStatus.actionState.b[3]  == 7) {
            func_802BD100_317020(playerStatus->flags);
        }
    }
}
#else
INCLUDE_ASM(s32, "world/action/encounter", func_802B6000_E28A30);
#endif

//wip - not good yet
#ifdef NON_MATCHING
void func_802B609C_E28ACC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 cosTheta;
    f32 sinTheta;
    f32 *temp_a1;
    f32 *temp_a2;
    f32 *temp_a3;
    f32 *temp_v0;
    f32 temp_f20;
    f32 temp_f4;
    f32 temp_f6;
    f32 phi_f4;
    f32 zDelta;
    f32 phi_f20;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~(0x80080000 | 0x80000 | 0x8 | 0x4 | 0x2);
        playerStatus->fallState = 0;
        playerStatus->framesOnGround = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_8C = 0.0f;
        D_802B6770_E27C80 = D_8010C938;
    }

    switch (playerStatus->fallState) {
        case 0:
            playerStatus->fallState++;
        case 1:
            break;
        default:
            return;
    }

    sin_cos_rad((D_8010C990 * TAU) / 360.0f, &sinTheta, &cosTheta);
    temp_f20 = sinTheta * 3.0f;
    sin_cos_rad((D_802B6770_E27C80 * TAU) / 360.0f, &sinTheta, &cosTheta);
    temp_f4 = sinTheta * temp_f20;
    temp_f6 = cosTheta * temp_f20;

    if (!(fabs(temp_f4) < 0.1)) {
        phi_f4 = temp_f4;
    } else {
        phi_f4 = 0.1f;
        if (temp_f4 < 0.0f) {
            phi_f4 = -0.1f;
        }
    }

    zDelta = temp_f6;
    if (fabs(temp_f6) < 0.1) {
        zDelta = 0.1f;
        if (temp_f6 < 0.0f) {
            zDelta = -0.1f;
        }
    }

    temp_a1 = &sp30;
    temp_a2 = &sp34;
    temp_v0 = &sp3C;

    playerStatus->position.x += phi_f4;
    playerStatus->position.z -= zDelta;
    temp_a3 = &sp38;
    sp30 = playerStatus->position.x;
    sp34 = playerStatus->position.y;
    sp38 = playerStatus->position.z;
    sp3C = 5.0f;
    if (player_raycast_below_cam_relative(&gPlayerStatus, temp_a1, temp_a2, temp_a3, temp_v0, &sp40, &sp44, &sp48, &sp4C) >= 0) {
        playerStatus->position.y = sp34;
    }

    phi_f20 = 60.0f;
    if (gGameStatusPtr->areaID == AREA_SBK) {
        phi_f20 = 30.0f;
    }

    if (D_8010C990 < phi_f20) {
        set_action_state(ACTION_STATE_FALLING);
        gravity_use_fall_parms();
    }
}
#else
INCLUDE_ASM(s32, "world/action/encounter", func_802B609C_E28ACC);
#endif

void func_802B6350_E28D80(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~(0x80000000 | 0x80000 | 0x8 | 0x4 | 0x2);
        playerStatus->fallState = 0;
        playerStatus->framesOnGround = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_8C = 0.0f;

        if (playerStatus->animFlags & 0x1000) {
            return;
        }
        playerStatus->framesOnGround = 5;
    }

    playerStatus->framesOnGround--;
    if (playerStatus->framesOnGround == 0) {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void func_802B63D4_E28E04(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~(0x80000000 | 0x8 | 0x4 | 0x2);
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_8C = 0.0f;
        suggest_player_anim_setUnkFlag(0x10017);
        playerStatus->framesOnGround = 30;
    }

    if (playerStatus->framesOnGround != 0) {
        playerStatus->framesOnGround--;
    } else if (!gGameStatusPtr->isBattle) {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void func_802B6478_E28EA8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->flags |= 0x80000;
        playerStatus->framesOnGround = 0;
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_8C = 0.0f;
        suggest_player_anim_setUnkFlag(0x1001F);
    }

    if (!(playerStatus->animFlags & 0x200)) {
        set_action_state(ACTION_STATE_IDLE);
        playerStatus->flags &= ~0x80000;
    }
}

void func_802B6508_E28F38(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags < 0) {
        f32 angle;
        f32 magnitude;

        playerStatus->flags &= ~0x80000000;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_60 = 0;
        playerStatus->framesOnGround = 5;
        player_input_to_move_vector(&angle, &magnitude);

        if (((angle >= 45.0f) && (angle <= 135.0f)) || ((angle >= 225.0f) && (angle <= 315.0f))) {
            suggest_player_anim_setUnkFlag(0x80000 | 0x20);
        } else {
            suggest_player_anim_clearUnkFlag(0x60000 | 0x4);
        }
    }

    check_input_jump();

    if (playerStatus->animFlags & 0x800000) {
        if (playerStatus->framesOnGround != 0) {
            playerStatus->framesOnGround--;
            if (playerStatus->framesOnGround == 0) {
                set_action_state(ACTION_STATE_IDLE);
            }
        }
    }
}

void func_802B6638_E29068(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_60 = 0;

        if (!(playerStatus->animFlags & 0x1000)) {
            suggest_player_anim_setUnkFlag(0x80007);
        } else if (playerStatus->unk_C4 == 0) {
            if (!(playerStatus->animFlags & 0x2000)) {
                suggest_player_anim_setUnkFlag(0xC0000);
            } else {
                peach_set_disguise_anim(world_actions_peachDisguises[playerStatus->peachDisguise].unk_0C);
            }
        }
        playerStatus->framesOnGround = 30;
    }

    if (playerStatus->animFlags & 0x1000) {
        if (playerStatus->framesOnGround != 0) {
            playerStatus->framesOnGround--;
        } else if (playerStatus->unk_C4 == 0) {
            if (!(playerStatus->animFlags & 0x2000)) {
                suggest_player_anim_setUnkFlag(0xA0001);
            } else {
                peach_set_disguise_anim(world_actions_peachDisguises[playerStatus->peachDisguise].idle);
            }
        }
    }
}
