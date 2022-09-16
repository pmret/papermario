#include "common.h"
#include "effects.h"

extern s32 gSpinHistoryBufferPos;
extern s32 gSpinHistoryPosY[5];
extern s32 gSpinHistoryPosX[5];
extern s32 gSpinHistoryPosZ[5];
extern s16 gSpinHistoryPosAngle[5];

void phys_clear_spin_history(void);

enum {
    SUBSTATE_SPIN_0     = 0,
    SUBSTATE_SPIN_1     = 1,
    SUBSTATE_SPIN_2     = 2,
    SUBSTATE_SPIN_3     = 3,
};

enum SpinTypeFlag {
    SPIN_TYPE_DEFAULT   = 0,
    SPIN_TYPE_SPEEDY    = 1,
    SPIN_TYPE_DIZZY     = 2,
    SPIN_TYPE_ATTACK    = 4,
};

void action_update_spin(void) {
    PlayerSpinState* playerSpinState = &gPlayerSpinState;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 angle, magnitude, speedModifier;

    s32 spinFlags, nonDizzyFlags;
    s32 effectType;
    AnimID anim;
    s32 firstCall = FALSE;

    // initialization
    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_80000);
        playerStatus->animFlags &= ~PA_FLAGS_40000;
        playerStatus->animFlags |= PA_FLAGS_SPINNING;
        playerStatus->flags |= PS_FLAGS_20000;
        playerStatus->currentStateTime = 0;
        playerStatus->actionSubstate = SUBSTATE_SPIN_0;
        playerSpinState->stopSoundTimer = 0;
        playerSpinState->hasBufferedSpin = FALSE;
        playerSpinState->spinDirectionMagnitude = 0.0f;
        playerSpinState->spinDirection.x = 0.0f;
        playerSpinState->spinDirection.y = 0.0f;
        playerSpinState->hitWallTime = 0;
        playerSpinState->bufferedStickAxis.x = 0;
        playerSpinState->bufferedStickAxis.y = 0;
        playerSpinState->spinSoundID = 0;
        playerStatus->specialDecorationEffect = NULL;
        playerSpinState->initialSpinTime = 25;
        playerSpinState->fullSpeedSpinTime = 15;
        playerSpinState->spinRate = 40.0f;
        playerSpinState->speedScale = 2.0f;
        playerSpinState->frictionScale = 0.5f;
        playerSpinState->spinCountdown = playerSpinState->initialSpinTime;
        spinFlags = SPIN_TYPE_DEFAULT;
        firstCall = TRUE;

        if (is_ability_active(ABILITY_SPIN_ATTACK)) {
            spinFlags |= SPIN_TYPE_ATTACK;
        }

        if (is_ability_active(ABILITY_DIZZY_ATTACK)) {
            spinFlags |= SPIN_TYPE_DIZZY;
        }

        if (is_ability_active(ABILITY_SPEEDY_SPIN)) {
            playerSpinState->initialSpinTime = 30;
            playerSpinState->spinRate = 40.0f;
            playerSpinState->fullSpeedSpinTime = 20;
            playerSpinState->spinCountdown = playerSpinState->initialSpinTime;
            playerSpinState->speedScale = 2.7f;
            playerSpinState->frictionScale = 0.9f;
            spinFlags |= SPIN_TYPE_SPEEDY;
        }

        effectType = -1;
        anim = ANIM_Mario_10010;

        if (spinFlags) {
            if (spinFlags & SPIN_TYPE_ATTACK) {
                effectType = 2;
                anim = ANIM_Mario_Flailing;
            } else if (spinFlags & SPIN_TYPE_DIZZY) {
                effectType = 4;
                anim = ANIM_Mario_10010;
            } else if (spinFlags & SPIN_TYPE_SPEEDY) {
                effectType = 0;
                anim = ANIM_Mario_Spinning;
            }
        }

        playerSpinState->spinSoundID = SOUND_2111;
        nonDizzyFlags = spinFlags & ~SPIN_TYPE_DIZZY;

        if (nonDizzyFlags == SPIN_TYPE_ATTACK) {
            playerSpinState->spinSoundID = SOUND_2113;
        }
        if (nonDizzyFlags == SPIN_TYPE_SPEEDY) {
            playerSpinState->spinSoundID = SOUND_2112;
        }
        if (nonDizzyFlags == (SPIN_TYPE_ATTACK | SPIN_TYPE_SPEEDY)) {
            playerSpinState->spinSoundID = SOUND_2114;
        }

        sfx_play_sound_at_player(playerSpinState->spinSoundID, 0);
        suggest_player_anim_setUnkFlag(anim);

        if ((clamp_angle(playerStatus->targetYaw - gCameras[gCurrentCameraID].currentYaw) <= 180.0f)) {
            playerStatus->spinRate = playerSpinState->spinRate;
        } else {
            effectType++;
            playerStatus->spinRate = -playerSpinState->spinRate;
        }
        if (spinFlags != 0) {
            playerStatus->specialDecorationEffect = fx_46(effectType, playerStatus, 1.0f, 1000);
        }

        phys_clear_spin_history();
        player_input_to_move_vector(&angle, &magnitude);
        playerStatus->targetYaw = angle;
        playerSpinState->inputMagnitude = magnitude;
    }

    // update saved position and rotation values for motion blur effect
    gSpinHistoryPosAngle[gSpinHistoryBufferPos++] = playerStatus->spriteFacingAngle;
    if (gSpinHistoryBufferPos > ARRAY_COUNT(gSpinHistoryPosX)) {
        gSpinHistoryBufferPos = 0;
    }
    gSpinHistoryPosX[gSpinHistoryBufferPos] = playerStatus->position.x;
    gSpinHistoryPosY[gSpinHistoryBufferPos] = playerStatus->position.y;
    gSpinHistoryPosZ[gSpinHistoryBufferPos] = playerStatus->position.z;
    gSpinHistoryPosAngle[gSpinHistoryBufferPos] = playerStatus->spriteFacingAngle;
    gSpinHistoryBufferPos++;
    if (gSpinHistoryBufferPos > ARRAY_COUNT(gSpinHistoryPosX)) {
        gSpinHistoryBufferPos = 0;
    }

    // check for spin cancel
    if (!firstCall && (check_input_hammer() || check_input_jump())) {
        playerStatus->animFlags &= ~PA_FLAGS_SPINNING;
        playerStatus->flags &= ~PS_FLAGS_20000;
        sfx_stop_sound(playerSpinState->spinSoundID);
        player_input_to_move_vector(&angle, &magnitude);
        playerStatus->targetYaw = angle;
        return;
    }

    // check for buffered next spin
    if (playerSpinState->spinCountdown < 11 && playerStatus->pressedButtons & BUTTON_Z) {
        playerSpinState->hasBufferedSpin = TRUE;
        playerSpinState->prevActionState = playerStatus->prevActionState;
        playerSpinState->bufferedStickAxis.x = playerStatus->stickAxis[0];
        playerSpinState->bufferedStickAxis.y = playerStatus->stickAxis[1];
    }

    // check for action finished
    if (playerStatus->actionSubstate >= SUBSTATE_SPIN_2) {
        playerSpinState->spinDirectionMagnitude -= 1.0f;
        if (playerSpinState->spinDirectionMagnitude < 0.0f) {
            playerSpinState->spinDirectionMagnitude = 0.0f;
        }

        angle = clamp_angle(playerStatus->targetYaw - gCameras[gCurrentCameraID].currentYaw);
        playerSpinState->spinDirection.x = sin_rad(DEG_TO_RAD(angle)) * playerSpinState->spinDirectionMagnitude;
        playerSpinState->spinDirection.y = -cos_rad(DEG_TO_RAD(angle)) * playerSpinState->spinDirectionMagnitude;
        playerStatus->currentStateTime--;
        if ((playerStatus->currentStateTime) == 0) {
            playerSpinState->stopSoundTimer = 4;
            set_action_state(ACTION_STATE_IDLE);
            playerStatus->flags &= ~PA_FLAGS_20000;
            playerStatus->animFlags &= ~PA_FLAGS_SPINNING;
            sfx_stop_sound(playerSpinState->spinSoundID);
        }
        playerStatus->currentSpeed = 0.0f;
        return;
    }

    if (playerStatus->actionSubstate == SUBSTATE_SPIN_0) {
        if (playerStatus->animFlags & PA_FLAGS_40000) {
            playerStatus->actionSubstate = SUBSTATE_SPIN_1;
        } else if (gCollisionStatus.pushingAgainstWall >= 0) {
            playerSpinState->hitWallTime++;
            if (playerSpinState->hitWallTime >= 10) {
                playerStatus->actionSubstate = SUBSTATE_SPIN_1;
            }
        }
    }

    if (!(playerStatus->currentStateTime > playerSpinState->fullSpeedSpinTime)) {
        speedModifier = (playerSpinState->inputMagnitude) ? playerSpinState->speedScale : 0.0f;
        playerSpinState->spinDirectionMagnitude = playerSpinState->spinDirectionMagnitude + 0.9;

        if (playerSpinState->spinDirectionMagnitude > 9.0f) {
            playerSpinState->spinDirectionMagnitude = 9.0f;
        }

        angle = clamp_angle(playerStatus->targetYaw - gCameras[gCurrentCameraID].currentYaw);
        playerSpinState->spinDirection.x = sin_rad(DEG_TO_RAD(angle)) * playerSpinState->spinDirectionMagnitude;
        playerSpinState->spinDirection.y = -cos_rad(DEG_TO_RAD(angle)) * playerSpinState->spinDirectionMagnitude;
    } else {
        speedModifier = playerSpinState->speedScale - (playerStatus->currentStateTime - playerSpinState->fullSpeedSpinTime - 1) * playerSpinState->frictionScale;
        if (speedModifier < 0.1) {
            speedModifier = 0.1f;
        }

        if (playerSpinState->inputMagnitude == 0.0f) {
            speedModifier = 0.0f;
        }

        playerSpinState->spinDirectionMagnitude -= 1.0f;
        if (playerSpinState->spinDirectionMagnitude < 0.0f) {
            playerSpinState->spinDirectionMagnitude = 0.0f;
        }
    }

    playerStatus->currentStateTime++;

    switch (playerStatus->prevActionState) {
        case ACTION_STATE_IDLE:
            player_input_to_move_vector(&angle, &magnitude);
            phys_update_interact_collider();
            if (check_input_jump()) {
                if (magnitude != 0.0f || playerStatus->targetYaw != angle) {
                    playerStatus->targetYaw = angle;
                }
            }
            playerStatus->currentSpeed = (magnitude != 0.0f) ? playerStatus->runSpeed * speedModifier : 0.0f;
            break;
        case ACTION_STATE_WALK:
        case ACTION_STATE_RUN:
            playerStatus->currentSpeed = playerStatus->runSpeed * speedModifier;
            break;
    }
    if (playerStatus->actionSubstate == SUBSTATE_SPIN_0) {
        playerSpinState->spinCountdown--;
        if (playerSpinState->spinCountdown > 0) {
            if (playerStatus->currentStateTime >= 2) {
                playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + playerStatus->spinRate);
            }
            return;
        } else {
            playerStatus->actionSubstate = SUBSTATE_SPIN_1;
        }
    }

    if (playerStatus->actionSubstate == SUBSTATE_SPIN_1) {
        angle = playerStatus->spriteFacingAngle;
        playerStatus->spriteFacingAngle = angle + playerStatus->spinRate;

        if (playerSpinState->hasBufferedSpin) {
            playerStatus->currentStateTime = 2;
            playerStatus->actionSubstate = SUBSTATE_SPIN_2;
            playerStatus->flags &= ~PS_FLAGS_20000;
            suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
        } else if (angle < playerStatus->spriteFacingAngle) {
            if (playerStatus->spriteFacingAngle >= 180.0f && angle < 180.0f) {
                playerStatus->spriteFacingAngle = 180.0f;
                playerStatus->currentStateTime = 2;
                playerStatus->actionSubstate = SUBSTATE_SPIN_2;
                playerStatus->flags &= ~PS_FLAGS_20000;
                suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
            }
        } else if (playerStatus->spriteFacingAngle <= 0.0f && angle < 90.0f) {
            playerStatus->spriteFacingAngle = 0.0f;
            playerStatus->currentStateTime = 2;
            playerStatus->actionSubstate = SUBSTATE_SPIN_2;
            playerStatus->flags &= ~PS_FLAGS_20000;
            suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
        }
        playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle);
    }
}
