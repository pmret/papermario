#include "common.h"

void update_player_input(void) {
    PlayerStatus* ps = &gPlayerStatus;
    PlayerStatus* playerStatus = ps; // ??? necessary
    s32 inputBufPos = playerStatus->inputBufPos;

    playerStatus->stickAxis[0] = gGameStatusPtr->stickX;
    playerStatus->stickAxis[1] = gGameStatusPtr->stickY;
    playerStatus->currentButtons = gGameStatusPtr->currentButtons;
    playerStatus->pressedButtons = gGameStatusPtr->pressedButtons;
    playerStatus->heldButtons = gGameStatusPtr->heldButtons;

    inputBufPos++;
    if (inputBufPos >= 10) {
        inputBufPos = 0;
    }

    playerStatus->stickXBuffer[inputBufPos] = playerStatus->stickAxis[0];
    playerStatus->stickYBuffer[inputBufPos] = playerStatus->stickAxis[1];
    playerStatus->currentButtonsBuffer[inputBufPos] = playerStatus->currentButtons;
    playerStatus->pressedButtonsBuffer[inputBufPos] = playerStatus->pressedButtons;
    playerStatus->heldButtonsBuffer[inputBufPos] = playerStatus->heldButtons;
    playerStatus->inputBufPos = inputBufPos;

    if (playerStatus->flags & 0x3000) {
        playerStatus->stickAxis[0] = 0;
        playerStatus->stickAxis[1] = 0;
        playerStatus->currentButtons = 0;
        playerStatus->pressedButtons = 0;
        playerStatus->heldButtons = 0;
    }

    if (playerStatus->animFlags & 8) {
        playerStatus->animFlags |= 0x200000;
        playerStatus->pressedButtons |= 4;
    }
}

INCLUDE_ASM(s32, "code_7B440", func_800E205C);

void func_800E22E4(s32* arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    *arg0 = (u16)playerStatus->currentButtons | (playerStatus->pressedButtons << 16);
}

void input_to_move_vector(f32* angle, f32* magnitude) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerStatus* playerStatus2 = playerStatus;
    f32 stickAxisX;
    f32 stickAxisY;
    f32 ang;
    f32 mag;
    f32 magMax = 70.0f;

    stickAxisX = playerStatus2->stickAxis[0];
    stickAxisY = -playerStatus2->stickAxis[1];

    mag = dist2D(0.0f, 0.0f, stickAxisX, stickAxisY);
    if (mag >= magMax) {
        mag = magMax;
    }

    ang = clamp_angle(atan2(0.0f, 0.0f, stickAxisX, stickAxisY) + gCameras[0].currentYaw);
    if (mag == 0.0f) {
        ang = playerStatus2->targetYaw;
    }

    *angle = ang;
    *magnitude = mag;
}

INCLUDE_ASM(s32, "code_7B440", func_800E23FC);

INCLUDE_ASM(s32, "code_7B440", func_800E24F8);
