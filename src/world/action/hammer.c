#include "common.h"

typedef struct HammerUnk {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} HammerUnk;

extern HammerUnk* D_802B6DB0_E25C80;

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
        xTemp = D_802B6DB0_E25C80->unk_00.x + sinTheta;
        yTemp = D_802B6DB0_E25C80->unk_00.y + playerStatus->colliderHeight - 5.0f;
        zTemp = D_802B6DB0_E25C80->unk_00.z + cosTheta;
        phi_s1 = 1;
    }

    exec_ShakeCamX(0, 2, s2temp, phi_f24);
    playFX_1D(0, xTemp, yTemp, zTemp, phi_s1, phi_s3, 0, (s2temp + 3) * 3);

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

void func_802B66A8_E25578(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    D_802B6DB0_E25C80->unk_1C = 0;

    if (playerStatus->flags < 0) {
        s32 animID;
        s32 soundID;

        playerStatus->flags &= ~0x80000000;
        playerStatus->flags |= 0x200000;
        D_802B6DB0_E25C80->unk_18 = 0;
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_BC = 0;
        D_802B6DB0_E25C80->unk_10 = func_802B62A4_E25174(D_802B6DB0_E25C80);

        if (gPlayerData.hammerLevel == 2) {
            soundID = 0x2117;
            animID = 0x6001A;
            if (D_802B6DB0_E25C80->unk_10 < 0) {
                animID = 0x60018;
                soundID = 0x2117;
            }
        } else if (gPlayerData.hammerLevel == 1) {
            soundID = 0x2116;
            animID = 0x60016;
            if (D_802B6DB0_E25C80->unk_10 < 0) {
                soundID = 0x2116;
                animID = 0x60014;
            }
        } else {
            soundID = 0x2115;
            animID = 0x60012;
            if (D_802B6DB0_E25C80->unk_10 < 0) {
                soundID = 0x2115;
                animID = 0x60010;
            }
        }

        suggest_player_anim_clearUnkFlag(animID);
        sfx_play_sound_at_player(soundID, 0);
        D_802B6DB0_E25C80->unk_0C = 0;
        D_802B6DB0_E25C80->unk_14 = 0;
    }

    playerStatus->flags &= ~0x1000000;
    if (D_802B6DB0_E25C80->unk_18 < 3 && (playerStatus->flags & 0x40000)) {
        playerStatus->flags |= 0x20000000;
    } else if (D_802B6DB0_E25C80->unk_18 < 2) {
        D_802B6DB0_E25C80->unk_18++;
    } else {
        func_802B6820_E256F0(D_802B6DB0_E25C80);
    }
}

INCLUDE_ASM(s32, "world/action/hammer", func_802B6820_E256F0);
