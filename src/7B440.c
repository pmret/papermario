#include "common.h"

s32 PeachDisguiseNpcIndex;
Entity* TweesterTouchingPartner;
Entity* TweesterTouchingPlayer;
s32 PrevPlayerDirection;
s32 PlayerRunStateTime;
f32 PlayerNormalYaw;
f32 PlayerNormalPitch;
PlayerSpinState gPlayerSpinState;

BSS s32 PlayerYInterpUpdateDelay;

void update_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 inputBufPos = playerStatus->inputBufPos;

    playerStatus->stickAxis[0] = gGameStatusPtr->stickX[0];
    playerStatus->stickAxis[1] = gGameStatusPtr->stickY[0];
    playerStatus->curButtons = gGameStatusPtr->curButtons[0];
    playerStatus->pressedButtons = gGameStatusPtr->pressedButtons[0];
    playerStatus->heldButtons = gGameStatusPtr->heldButtons[0];

    inputBufPos++;
    if (inputBufPos >= 10) {
        inputBufPos = 0;
    }

    playerStatus->stickXBuffer[inputBufPos] = playerStatus->stickAxis[0];
    playerStatus->stickYBuffer[inputBufPos] = playerStatus->stickAxis[1];
    playerStatus->curButtonsBuffer[inputBufPos] = playerStatus->curButtons;
    playerStatus->pressedButtonsBuffer[inputBufPos] = playerStatus->pressedButtons;
    playerStatus->heldButtonsBuffer[inputBufPos] = playerStatus->heldButtons;
    playerStatus->inputBufPos = inputBufPos;

    if (playerStatus->flags & (PS_FLAG_INPUT_DISABLED | PS_FLAG_NO_STATIC_COLLISION)) {
        playerStatus->stickAxis[0] = 0;
        playerStatus->stickAxis[1] = 0;
        playerStatus->curButtons = 0;
        playerStatus->pressedButtons = 0;
        playerStatus->heldButtons = 0;
    }

    if (playerStatus->animFlags & PA_FLAG_FORCE_USE_PARTNER) {
        playerStatus->animFlags |= PA_FLAG_PARTNER_USAGE_FORCED;
        playerStatus->pressedButtons |= 4;
    }
}

void reset_player_status(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    MapSettings* mapSettings;
    f32 one;
    f32* floatsTemp;

    PeachDisguiseNpcIndex = -1;
    TweesterTouchingPartner = nullptr;
    PulseStoneNotificationCallback = nullptr;
    TalkNotificationCallback = nullptr;
    InteractNotificationCallback = nullptr;
    D_8010C92C = 0;
    PrevPlayerDirection = 0;
    PlayerRunStateTime = 0;
    PrevPlayerCamRelativeYaw = 0;
    D_800F7B44 = 0;
    PlayerNormalYaw = 0;
    PlayerNormalPitch = 0.0f;
    playerStatus->availableDisguiseType = 1;
    playerStatus->renderMode = RENDER_MODE_ALPHATEST;

    playerStatus->curAlpha = 255;
    playerStatus->prevAlpha = 255;
    gGameStatusPtr->peachFlags &= ~PEACH_FLAG_BLOCK_NEXT_DISGUISE;
    gGameStatusPtr->peachFlags &= ~PEACH_FLAG_DEPRESSED;

    one = 1.0f;

    if (gGameStatusPtr->peachFlags & PEACH_FLAG_IS_PEACH) {
        playerStatus->colliderHeight = 55;
        playerStatus->colliderDiameter = 38;
        playerStatus->animFlags |= PA_FLAG_USING_PEACH_PHYSICS;

        if (gGameStatusPtr->peachFlags & PEACH_FLAG_DISGUISED) {
            D_8010C92C = 2;
            playerStatus->peachDisguise = gGameStatusPtr->peachDisguise;
        }
    } else {
        playerStatus->colliderHeight = 37;
        playerStatus->colliderDiameter = 26;
        gGameStatusPtr->peachBakingIngredient = PEACH_BAKING_NONE;
    }

    // TODO required to match
    floatsTemp = &(&D_800F7B74)[-1]; // index of 0 does not work
    playerStatus->walkSpeed = *floatsTemp++ * one;
    playerStatus->runSpeed = *floatsTemp++ * one;
    playerStatus->maxJumpSpeed = *floatsTemp++ * one;

    set_action_state(ACTION_STATE_IDLE);

    playerStatus->curSpeed = 0.0f;
    playerStatus->targetYaw = 0.0f;
    playerStatus->overlapPushAmount = 0.0f;
    playerStatus->overlapPushYaw = 0.0f;
    playerStatus->anim = 0;
    playerStatus->timeInAir = 0;
    playerStatus->pos.x = 0.0f;
    playerStatus->pos.y = 0.0f;
    playerStatus->pos.z = 0.0f;
    playerStatus->curYaw = 0.0f;
    playerStatus->flipYaw[CAM_DEFAULT] = 0.0f;
    playerStatus->flipYaw[CAM_BATTLE] = 0.0f;
    playerStatus->flipYaw[CAM_TATTLE] = 0.0f;
    playerStatus->flipYaw[CAM_HUD] = 0.0f;

    mapSettings = gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].settings;

    if (mapSettings->entryList != nullptr) {
        if (gGameStatusPtr->entryID < mapSettings->entryCount) {
            playerStatus->pos.x = (*mapSettings->entryList)[gGameStatusPtr->entryID].x;
            playerStatus->pos.y = (*mapSettings->entryList)[gGameStatusPtr->entryID].y;
            playerStatus->pos.z = (*mapSettings->entryList)[gGameStatusPtr->entryID].z;
            playerStatus->curYaw = (*mapSettings->entryList)[gGameStatusPtr->entryID].yaw;
        }
    }

    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;

    phys_reset_spin_history();
    mem_clear(&gPlayerSpinState, sizeof(gPlayerSpinState));
}

void get_packed_buttons(s32* out) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    *out = (playerStatus->curButtons & 0xFFFF) | (playerStatus->pressedButtons << 16);
}

void player_input_to_move_vector(f32* outAngle, f32* outMagnitude) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 stickAxisX = playerStatus->stickAxis[0];
    f32 stickAxisY = -playerStatus->stickAxis[1];
    f32 maxRadius = 70.0f;
    f32 magnitude;
    f32 angle;

    magnitude = dist2D(0.0f, 0.0f, stickAxisX, stickAxisY);
    if (magnitude >= maxRadius) {
        magnitude = maxRadius;
    }

    angle = clamp_angle(atan2(0.0f, 0.0f, stickAxisX, stickAxisY) + gCameras[CAM_DEFAULT].curYaw);
    if (magnitude == 0.0f) {
        angle = playerStatus->targetYaw;
    }

    *outAngle = angle;
    *outMagnitude = magnitude;
}

void game_input_to_move_vector(f32* outAngle, f32* outMagnitude) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 stickX = gGameStatusPtr->stickX[0];
    f32 stickY = -gGameStatusPtr->stickY[0];
    f32 maxRadius = 70.0f;
    f32 magnitude;
    f32 angle;

    magnitude = dist2D(0.0f, 0.0f, stickX, stickY);
    if (magnitude >= maxRadius) {
        magnitude = maxRadius;
    }

    angle = clamp_angle(atan2(0.0f, 0.0f, stickX, stickY) + gCameras[CAM_DEFAULT].curYaw);
    if (magnitude == 0.0f) {
        angle = playerStatus->targetYaw;
    }

    *outAngle = angle;
    *outMagnitude = magnitude;
}

void calculate_camera_yinterp_rate(void) {
    Shadow* shadow = get_shadow_by_index(gPlayerStatus.shadowID);
    f32 x = shadow->rot.x + 180.0;
    f32 z = shadow->rot.z + 180.0;
    Camera* camera = &gCameras[CAM_DEFAULT];
    f32 rate;

    if (x != 0.0f || z != 0.0f) {
        switch (gPlayerStatus.actionState) {
            case ACTION_STATE_JUMP:
            case ACTION_STATE_FALLING:
                rate = 32.0f;
                camera->yinterpRate = rate;
                break;
            case ACTION_STATE_WALK:
            case ACTION_STATE_RUN:
                if (camera->targetScreenCoords.y < 130) {
                    camera->yinterpRate = 3.0f;
                    break;
                }
                rate = 3.0f;
                if (PlayerYInterpUpdateDelay++ <= 10) {
                    return;
                }
                PlayerYInterpUpdateDelay = 10;
                camera->yinterpRate -= 2.0f;
                if (camera->yinterpRate < rate) {
                    camera->yinterpRate = rate;
                }
                break;
            case ACTION_STATE_SLIDING:
                rate = 3.0f;
                camera->yinterpRate = rate;
                break;
            default:
                rate = 3.0f;
                PlayerYInterpUpdateDelay = 0;
                camera->yinterpRate -= 2.0f;
                if (camera->yinterpRate < rate) {
                    camera->yinterpRate = rate;
                }
                break;
        }
    } else {
        switch (gPlayerStatus.actionState) {
            case ACTION_STATE_WALK:
            case ACTION_STATE_RUN:
            case ACTION_STATE_JUMP:
            case ACTION_STATE_SLIDING:
                rate = 7.2f;
                break;
            default:
                rate = 24.0f;
                break;
        }

        camera->yinterpRate = rate;
    }
}
