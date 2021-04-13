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

INCLUDE_ASM(s32, "7B440", func_800E205C);

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

void func_800E23FC(f32* arg0, f32* arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 stickX = gGameStatusPtr->stickX;
    f32 stickY = -gGameStatusPtr->stickY;
    f32 tempMax = 70.0f;
    f32 temp1;
    f32 temp2;

    temp1 = dist2D(0.0f, 0.0f, stickX, stickY);
    if (temp1 >= tempMax) {
        temp1 = tempMax;
    }

    temp2 = clamp_angle(atan2(0.0f, 0.0f, stickX, stickY) + gCameras[0].currentYaw);
    if (temp1 == 0.0f) {
        temp2 = playerStatus->targetYaw;
    }

    *arg0 = temp2;
    *arg1 = temp1;
}

extern s32 D_8010C9A0;

INCLUDE_ASM(s32, "7B440", func_800E24F8);
// void func_800E24F8(void) {
//     PlayerStatus* playerStatus = &gPlayerStatus;
//     Shadow* shadow = get_shadow_by_index(gPlayerStatus.shadowID);
//     Camera* camera = &gCameras[0];
//     f32 unk_28 = shadow->unk_28 + 180.0;
//     f32 unk_30 = shadow->unk_30 + 180.0;
//     s32* temp8010C9A0;
//     f32 temp;

//     if ((unk_28 != 0) || (unk_30 != 0)) {
//         switch (gPlayerStatus.actionState) {

//             case 3:
//             case 8:
//                 camera->unk_49C = 32.0f;
//                 break;
//             case 1:
//             case 2:
//                 if (camera->targetScreenCoords[1] < 130) {
//                     camera->unk_49C = 3.0f;
//                     return;
//                 }

//                 temp = 3.0f;

//                 temp8010C9A0 = &D_8010C9A0;

//                 (*temp8010C9A0)++;
//                 if (*temp8010C9A0 > 10) {
//                     *temp8010C9A0 = 10;
//                 }

//                 camera->unk_49C -= 2.0f;
//                 if (camera->unk_49C < 3.0f) {
//                     camera->unk_49C = 3.0f;
//                 }
//                 break;
//             case 17:
//                 camera->unk_49C = 3.0f;
//                 break;
//             default:
//                 D_8010C9A0 = 0;
//                 camera->unk_49C -= 2.0f;
//                 if (camera->unk_49C < 3.0f) {
//                     camera->unk_49C = 3.0f;
//                 }
//                 break;
//         }

//     } else {
//         switch (playerStatus->actionState) {
//             case 1:
//             case 2:
//             case 3:
//             case 17:
//                 camera->unk_49C = 7.2f;
//                 break;
//             default:
//                 camera->unk_49C = 24.0f;
//         }
//     }
// }
