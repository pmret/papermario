#include "common.h"

extern Vec3f* D_802B6DB0_E25C80;

s32 func_802B6000_E24ED0(s32 arg0) {
    if (arg0 & 0x1000000) {
        return TRUE;
    }

    switch (arg0 + ~0x6000F) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
        case 11:
            return TRUE;
    }
    return FALSE;
}

void func_802B6048_E24F18(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 phi_f24;
    s32 s2temp;
    s32 phi_s1;
    s32 soundID;
    f32 theta;
    f32 sinTheta;
    f32 cosTheta;
    s32 phi_s3;
    f32 xTemp;
    f32 yTemp;
    f32 zTemp;

    if (gPlayerData.hammerLevel == 2) {
        phi_f24 = 1.2f;
        s2temp = 1;
        phi_s1 = 28;
        soundID = 0x211A;
    } else if (gPlayerData.hammerLevel == 1) {
        phi_f24 = 0.8f;
        s2temp = 1;
        phi_s1 = 16;
        soundID = 0x2119;
    } else {
        phi_f24 = 0.4f;
        s2temp = 1;
        phi_s1 = 4;
        soundID = 0x2118;
    }

    theta = (func_800E5348() * TAU) / 360.0f;
    sinTheta = sin_rad(theta) * 25.0f;
    cosTheta = cos_rad(theta) * -25.0f;

    if (arg0 < 0) {
        phi_s3 = 6;
        xTemp = playerStatus->position.x + sinTheta;
        yTemp = playerStatus->position.y;
        zTemp = playerStatus->position.z + cosTheta;
    } else {
        phi_s3 = 3;
        xTemp = D_802B6DB0_E25C80->x + sinTheta;
        yTemp = D_802B6DB0_E25C80->y + playerStatus->colliderHeight - 5.0f;
        zTemp = D_802B6DB0_E25C80->z + cosTheta;
        phi_s1 = 1;
    }

    exec_ShakeCamX(0, 2, s2temp, phi_f24);
    func_80070370(0, xTemp, yTemp, zTemp, phi_s1, phi_s3, 0, (s2temp + 3) * 3);

    switch (is_ability_active(ABILITY_ATTACK_F_X)) {
        case 1:
            soundID = 0x372;
            break;
        case 2:
            soundID = 0xF1;
            break;
        case 3:
            soundID = 0xDC;
            break;
        case 4:
            soundID = 0x2072;
            break;
        case 5:
            soundID = 0x2073;
            break;
        case 6:
            soundID = 0x205B;
            break;
    }

    sfx_play_sound_at_player(soundID, 0);
    start_rumble(0x100, 0x32);
}

INCLUDE_ASM(s32, "world/action/hammer", func_802B62A4_E25174);

INCLUDE_ASM(void, "world/action/hammer", func_802B66A8_E25578, void);

INCLUDE_ASM(s32, "world/action/hammer", func_802B6820_E256F0);
