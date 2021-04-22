#include "common.h"

extern s32 D_8010C920;
extern s32 D_8010C940;
extern s32 D_8010C954;
extern s32 D_8010C958;
extern s32 D_8010C95C;
extern s32 D_8010C96C;
extern s32 D_8010C980;
extern s32 D_8010C9A0;
extern s32 D_800F7B40;
extern s32 D_800F7B44;
extern s32 D_8010C938;
extern s32 D_8010C990;

void update_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
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

#ifdef NON_MATCHING
void func_800E205C(void) {
    s32* temp8010C92C = &D_8010C92C;
    PlayerStatus* playerStatus = &gPlayerStatus;
    MapConfig* mapConfig;
    f32 one;
    f32* floatsTemp;

    D_8010C96C = -1;
    D_8010C954 = 0;
    D_8010C920 = 0;
    D_8010C940 = 0;
    D_8010C958 = 0;
    *temp8010C92C = 0;
    D_8010C95C = 0;
    D_8010C980 = 0;
    D_800F7B40 = 0;
    D_800F7B44 = 0;
    D_8010C938 = 0;
    D_8010C990 = 0;
    playerStatus->unk_0D = 1;
    playerStatus->renderMode = 0xD;

    playerStatus->alpha1 = 255;
    playerStatus->alpha2 = 255;
    gGameStatusPtr->peachFlags &= ~0x8;
    gGameStatusPtr->peachFlags &= ~0x10;

    one = 1.0f;

    if (gGameStatusPtr->peachFlags & 1) {
        playerStatus->colliderHeight = 55;
        playerStatus->colliderDiameter = 38;
        playerStatus->animFlags |= 0x1000;

        if (gGameStatusPtr->peachFlags & 2) {
            *temp8010C92C = 2;
            playerStatus->peachDisguise = gGameStatusPtr->peachDisguise;
        }
    } else {
        playerStatus->colliderHeight = 37;
        playerStatus->colliderDiameter = 26;
        gGameStatusPtr->peachAnimIdx = 0;
    }

    // This grossness is needed for matching
    floatsTemp = &D_800F7B70[0];
    playerStatus->walkSpeed = *(floatsTemp++) * one;
    playerStatus->runSpeed = *(floatsTemp++) * one;
    playerStatus->unk_6C = *(floatsTemp++) * one;

    set_action_state(ACTION_STATE_IDLE);

    playerStatus->currentSpeed = 0.0f;
    playerStatus->targetYaw = 0.0f;
    playerStatus->unk_64 = 0.0f;
    playerStatus->unk_88 = 0.0f;
    playerStatus->anim = 0;
    playerStatus->decorationList = 0;
    playerStatus->position.x = 0.0f;
    playerStatus->position.y = 0.0f;
    playerStatus->position.z = 0.0f;
    playerStatus->currentYaw = 0.0f;
    playerStatus->unk_90 = 0.0f;
    playerStatus->unk_94 = 0;
    playerStatus->unk_98 = 0;
    playerStatus->unk_9C = 0;

    mapConfig = gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].config;

    if (mapConfig->entryList != NULL) {
        if (gGameStatusPtr->entryID < mapConfig->entryCount) {
            playerStatus->position.x = (*mapConfig->entryList)[gGameStatusPtr->entryID].x;
            playerStatus->position.y = (*mapConfig->entryList)[gGameStatusPtr->entryID].y;
            playerStatus->position.z = (*mapConfig->entryList)[gGameStatusPtr->entryID].z;
            playerStatus->currentYaw = (*mapConfig->entryList)[gGameStatusPtr->entryID].yaw;
        }
    }

    gCameras->targetPos.x = playerStatus->position.x;
    gCameras->targetPos.y = playerStatus->position.y;
    gCameras->targetPos.z = playerStatus->position.z;

    func_800E59A0(mapConfig);
    mem_clear(&D_8010F250, sizeof(Temp8010F250));
}
#else
INCLUDE_ASM(s32, "7B440", func_800E205C);
#endif

void func_800E22E4(s32* arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    *arg0 = (u16)playerStatus->currentButtons | (playerStatus->pressedButtons << 16);
}

void input_to_move_vector(f32* angle, f32* magnitude) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 stickAxisX;
    f32 stickAxisY;
    f32 ang;
    f32 mag;
    f32 magMax = 70.0f;

    stickAxisX = playerStatus->stickAxis[0];
    stickAxisY = -playerStatus->stickAxis[1];

    mag = dist2D(0.0f, 0.0f, stickAxisX, stickAxisY);
    if (mag >= magMax) {
        mag = magMax;
    }

    ang = clamp_angle(atan2(0.0f, 0.0f, stickAxisX, stickAxisY) + gCameras[0].currentYaw);
    if (mag == 0.0f) {
        ang = playerStatus->targetYaw;
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

INCLUDE_ASM(s32, "7B440", func_800E24F8);
