#include "common.h"
#include "world/actions.h"

s32 func_802B6000_E28A30(void) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 oldFlags = playerStatus->flags;
    
    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(
            PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_80000 | PLAYER_STATUS_FLAGS_FLYING |
            PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING
        );
        playerStatus->fallState = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
    }

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_400000) {  
        if(partnerActionStatus->actingPartner == PARTNER_LAKILESTER) {
            return func_802BD100_317020(oldFlags);
        }
        if(partnerActionStatus->actingPartner == PARTNER_SUSHIE) {
            return func_802BD100_317020(oldFlags);
        }
    }

    #ifdef AVOID_UB
        return 0;
    #endif
}

extern f32 D_802B6770_E27C80;

void func_802B609C_E28ACC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 hitDirZ;
    s32 hitDirX;
    s32 hitRz;
    s32 hitRx;
    f32 outLength;
    f32 outZ;
    f32 outY;
    f32 outX;
    f32 cosTheta;
    f32 sinTheta;
    f32 miscTempVariable;
    f32 playerXOffset;
    f32 playerZOffset;
    f32 zDelta;
    f32 playerOffsetTempVar;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(
            PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_80000 | PLAYER_STATUS_FLAGS_FLYING | 
            PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING
        );
        playerStatus->fallState = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
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

    miscTempVariable = 3.0f;
    miscTempVariable = sinTheta * miscTempVariable;

    sin_cos_rad((D_802B6770_E27C80 * TAU) / 360.0f, &sinTheta, &cosTheta);
    
    playerXOffset = sinTheta * miscTempVariable;
    playerZOffset = cosTheta * miscTempVariable;

    if (fabs(playerXOffset) < 0.1f) {
        playerOffsetTempVar = 0.1f;
        if (playerXOffset < 0.0f) {
            playerOffsetTempVar = -0.1f;
        }
        playerXOffset = playerOffsetTempVar;
    }
    
    if (fabs(playerZOffset) < 0.1f) {
        playerOffsetTempVar = 0.1f;
        if (playerZOffset < 0.0f) {
            playerOffsetTempVar = -0.1f;
        }
        playerZOffset = playerOffsetTempVar;
    }
    
    playerStatus->position.x += playerXOffset;
    playerStatus->position.z -= playerZOffset;
    outX = playerStatus->position.x;
    outY = playerStatus->position.y;
    outZ = playerStatus->position.z;
    outLength = 5.0f;
    if (player_raycast_below_cam_relative(playerStatus, &outX, &outY, &outZ, &outLength, &hitRx, &hitRz, &hitDirX, &hitDirZ) >= 0) {
        playerStatus->position.y = outY;
    }

    if (gGameStatusPtr->areaID == AREA_SBK) {
        miscTempVariable = 30.0f;
    } else {
        miscTempVariable = 60.0f;
    }

    if (D_8010C990 < miscTempVariable) {
        set_action_state(ACTION_STATE_FALLING);
        gravity_use_fall_parms();
    }
}

void func_802B6350_E28D80(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(0x80000000 | 0x80000 | 0x8 | 0x4 | 0x2);
        playerStatus->fallState = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;

        if (playerStatus->animFlags & 0x1000) {
            return;
        }
        playerStatus->currentStateTime = 5;
    }

    playerStatus->currentStateTime--;
    if (playerStatus->currentStateTime == 0) {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void func_802B63D4_E28E04(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(0x80000000 | 0x8 | 0x4 | 0x2);
        playerStatus->fallState = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
        suggest_player_anim_setUnkFlag(0x10017);
        playerStatus->currentStateTime = 30;
    }

    if (playerStatus->currentStateTime != 0) {
        playerStatus->currentStateTime--;
    } else if (!gGameStatusPtr->isBattle) {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void func_802B6478_E28EA8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->flags |= 0x80000;
        playerStatus->currentStateTime = 0;
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
        suggest_player_anim_setUnkFlag(0x1001F);
    }

    if (!(playerStatus->animFlags & 0x200)) {
        set_action_state(ACTION_STATE_IDLE);
        playerStatus->flags &= ~0x80000;
    }
}

void func_802B6508_E28F38(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        f32 angle;
        f32 magnitude;

        playerStatus->flags &= ~0x80000000;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_60 = 0;
        playerStatus->currentStateTime = 5;
        player_input_to_move_vector(&angle, &magnitude);

        if (((angle >= 45.0f) && (angle <= 135.0f)) || ((angle >= 225.0f) && (angle <= 315.0f))) {
            suggest_player_anim_setUnkFlag(0x80000 | 0x20);
        } else {
            suggest_player_anim_clearUnkFlag(0x60000 | 0x4);
        }
    }

    check_input_jump();

    if (playerStatus->animFlags & 0x800000) {
        if (playerStatus->currentStateTime != 0) {
            playerStatus->currentStateTime--;
            if (playerStatus->currentStateTime == 0) {
                set_action_state(ACTION_STATE_IDLE);
            }
        }
    }
}

void func_802B6638_E29068(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_60 = 0;

        if (!(playerStatus->animFlags & 0x1000)) {
            suggest_player_anim_setUnkFlag(0x80007);
        } else if (playerStatus->unk_C4 == 0) {
            if (!(playerStatus->animFlags & 0x2000)) {
                suggest_player_anim_setUnkFlag(0xC0000);
            } else {
                peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].talk);
            }
        }
        playerStatus->currentStateTime = 30;
    }

    if (playerStatus->animFlags & 0x1000) {
        if (playerStatus->currentStateTime != 0) {
            playerStatus->currentStateTime--;
        } else if (playerStatus->unk_C4 == 0) {
            if (!(playerStatus->animFlags & 0x2000)) {
                suggest_player_anim_setUnkFlag(0xA0001);
            } else {
                peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].idle);
            }
        }
    }
}
