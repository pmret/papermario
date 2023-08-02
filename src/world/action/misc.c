#include "common.h"
#include "world/actions.h"
#include "world/partner/sushie.h"
#include "world/partner/lakilester.h"
#include "sprite/player.h"

BSS f32 D_802B6770_E27C80;

void action_update_ride(void) {
    PartnerStatus* partnerStatus = &gPartnerStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_ARMS_RAISED | PS_FLAG_AIRBORNE);
        playerStatus->actionSubstate = 0;
        playerStatus->curStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->curSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
    }

    if (playerStatus->animFlags & PA_FLAG_RIDING_PARTNER) {
        if (partnerStatus->actingPartner == PARTNER_LAKILESTER) {
            world_lakilester_sync_player_position();
        } else if (partnerStatus->actingPartner == PARTNER_SUSHIE) {
            world_sushie_sync_player_position();
        }
    }
}

void action_update_state_23(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 hitDirZ;
    f32 hitDirX;
    f32 hitRz;
    f32 hitRx;
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

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_ARMS_RAISED | PS_FLAG_AIRBORNE);
        playerStatus->actionSubstate = 0;
        playerStatus->curStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->curSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
        D_802B6770_E27C80 = D_8010C938;
    }

    switch (playerStatus->actionSubstate) {
        case 0:
            playerStatus->actionSubstate++;
        case 1:
            break;
        default:
            return;
    }

    sin_cos_rad(DEG_TO_RAD(D_8010C990), &sinTheta, &cosTheta);

    miscTempVariable = 3.0f;
    miscTempVariable = sinTheta * miscTempVariable;

    sin_cos_rad(DEG_TO_RAD(D_802B6770_E27C80), &sinTheta, &cosTheta);

    playerXOffset = sinTheta * miscTempVariable;
    playerZOffset = cosTheta * miscTempVariable;

    if (fabs(playerXOffset) < 0.1) {
        playerOffsetTempVar = 0.1f;
        if (playerXOffset < 0.0f) {
            playerOffsetTempVar = -0.1f;
        }
        playerXOffset = playerOffsetTempVar;
    }

    if (fabs(playerZOffset) < 0.1) {
        playerOffsetTempVar = 0.1f;
        if (playerZOffset < 0.0f) {
            playerOffsetTempVar = -0.1f;
        }
        playerZOffset = playerOffsetTempVar;
    }

    playerStatus->pos.x += playerXOffset;
    playerStatus->pos.z -= playerZOffset;
    outX = playerStatus->pos.x;
    outY = playerStatus->pos.y;
    outZ = playerStatus->pos.z;
    outLength = 5.0f;
    if (player_raycast_below_cam_relative(playerStatus, &outX, &outY, &outZ, &outLength, &hitRx, &hitRz, &hitDirX, &hitDirZ) >= 0) {
        playerStatus->pos.y = outY;
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

void action_update_launch(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_ARMS_RAISED | PS_FLAG_AIRBORNE);
        playerStatus->actionSubstate = 0;
        playerStatus->curStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->curSpeed = 0.0f;
        playerStatus->pitch = 0.0f;

        if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
            return;
        }
        playerStatus->curStateTime = 5;
    }

    playerStatus->curStateTime--;
    if (playerStatus->curStateTime == 0) {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void action_update_first_strike(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_AIRBORNE);
        playerStatus->actionSubstate = 0;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->curSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
        suggest_player_anim_always_forward(ANIM_Mario1_Hurt);
        playerStatus->curStateTime = 30;
    }

    if (playerStatus->curStateTime != 0) {
        playerStatus->curStateTime--;
    } else if (!gGameStatusPtr->isBattle) {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void action_update_raise_arms(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->flags |= PS_FLAG_ARMS_RAISED;
        playerStatus->curStateTime = 0;
        playerStatus->actionSubstate = 0;
        playerStatus->curSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
        suggest_player_anim_always_forward(ANIM_Mario1_UsePower);
    }

    if (!(playerStatus->animFlags & PA_FLAG_RAISED_ARMS)) {
        set_action_state(ACTION_STATE_IDLE);
        playerStatus->flags &= ~PS_FLAG_ARMS_RAISED;
    }
}

void action_update_pushing_block(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        f32 angle;
        f32 magnitude;

        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->curSpeed = 0.0f;
        playerStatus->unk_60 = 0;
        playerStatus->curStateTime = 5;
        player_input_to_move_vector(&angle, &magnitude);

        if (((angle >= 45.0f) && (angle <= 135.0f)) || ((angle >= 225.0f) && (angle <= 315.0f))) {
            suggest_player_anim_always_forward(ANIM_MarioW2_PushSide);
        } else {
            suggest_player_anim_allow_backward(ANIM_MarioW1_PushToward);
        }
    }

    check_input_jump();

    if (playerStatus->animFlags & PA_FLAG_ABORT_PUSHING_BLOCK) {
        if (playerStatus->curStateTime != 0) {
            playerStatus->curStateTime--;
            if (playerStatus->curStateTime == 0) {
                set_action_state(ACTION_STATE_IDLE);
            }
        }
    }
}

void action_update_talk(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->curSpeed = 0.0f;
        playerStatus->unk_60 = 0;

        if (!(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS)) {
            suggest_player_anim_always_forward(ANIM_MarioW2_SpeakUp);
        } else if (playerStatus->peachItemHeld == 0) {
            if (!(playerStatus->animFlags & PA_FLAG_INVISIBLE)) {
                suggest_player_anim_always_forward(ANIM_Peach2_RaiseArms);
            } else {
                peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].talk);
            }
        }
        playerStatus->curStateTime = 30;
    }

    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        if (playerStatus->curStateTime != 0) {
            playerStatus->curStateTime--;
        } else if (playerStatus->peachItemHeld == 0) {
            if (!(playerStatus->animFlags & PA_FLAG_INVISIBLE)) {
                suggest_player_anim_always_forward(ANIM_Peach1_Idle);
            } else {
                peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].idle);
            }
        }
    }
}
