#include "common.h"
#include "world/actions.h"
#include "world/partner/goombario.h"

s32 action_update_ride(void) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 oldFlags = playerStatus->flags;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(
            PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_80000 | PS_FLAGS_AIRBORNE
        );
        playerStatus->actionSubstate = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
    }

    if (playerStatus->animFlags & PA_FLAGS_400000) {  
        if (partnerActionStatus->actingPartner == PARTNER_LAKILESTER) {
            return func_802BD100_317020(oldFlags);
        }
        if (partnerActionStatus->actingPartner == PARTNER_SUSHIE) {
            return func_802BD100_317020(oldFlags);
        }
    }

    #ifdef AVOID_UB
        return 0;
    #endif
}

extern f32 D_802B6770_E27C80;

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

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED
            | PS_FLAGS_80000 | PS_FLAGS_AIRBORNE);
        playerStatus->actionSubstate = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
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

void action_update_launch(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_80000 | PS_FLAGS_AIRBORNE);
        playerStatus->actionSubstate = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;

        if (playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
            return;
        }
        playerStatus->currentStateTime = 5;
    }

    playerStatus->currentStateTime--;
    if (playerStatus->currentStateTime == 0) {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void action_update_first_strike(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_AIRBORNE);
        playerStatus->actionSubstate = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
        suggest_player_anim_setUnkFlag(ANIM_Mario_FallBack);
        playerStatus->currentStateTime = 30;
    }

    if (playerStatus->currentStateTime != 0) {
        playerStatus->currentStateTime--;
    } else if (!gGameStatusPtr->isBattle) {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void action_update_raise_arms(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags |= PS_FLAGS_80000;
        playerStatus->currentStateTime = 0;
        playerStatus->actionSubstate = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;
        suggest_player_anim_setUnkFlag(ANIM_Mario_GotItem);
    }

    if (!(playerStatus->animFlags & PA_FLAGS_RAISED_ARMS)) {
        set_action_state(ACTION_STATE_IDLE);
        playerStatus->flags &= ~PS_FLAGS_80000;
    }
}

void action_update_pushing_block(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        f32 angle;
        f32 magnitude;

        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_60 = 0;
        playerStatus->currentStateTime = 5;
        player_input_to_move_vector(&angle, &magnitude);

        if (((angle >= 45.0f) && (angle <= 135.0f)) || ((angle >= 225.0f) && (angle <= 315.0f))) {
            suggest_player_anim_setUnkFlag(ANIM_Mario_80020);
        } else {
            suggest_player_anim_clearUnkFlag(ANIM_Mario_60004);
        }
    }

    check_input_jump();

    if (playerStatus->animFlags & PA_FLAGS_800000) {
        if (playerStatus->currentStateTime != 0) {
            playerStatus->currentStateTime--;
            if (playerStatus->currentStateTime == 0) {
                set_action_state(ACTION_STATE_IDLE);
            }
        }
    }
}

void action_update_talk(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_60 = 0;

        if (!(playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS)) {
            suggest_player_anim_setUnkFlag(ANIM_Mario_80007);
        } else if (playerStatus->peachItemHeld == 0) {
            if (!(playerStatus->animFlags & PA_FLAGS_IN_DISGUISE)) {
                suggest_player_anim_setUnkFlag(ANIM_Peach_C0000);
            } else {
                peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].talk);
            }
        }
        playerStatus->currentStateTime = 30;
    }

    if (playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
        if (playerStatus->currentStateTime != 0) {
            playerStatus->currentStateTime--;
        } else if (playerStatus->peachItemHeld == 0) {
            if (!(playerStatus->animFlags & PA_FLAGS_IN_DISGUISE)) {
                suggest_player_anim_setUnkFlag(ANIM_Peach_A0001);
            } else {
                peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].idle);
            }
        }
    }
}
