#include "common.h"
#include "effects.h"

typedef struct HammerHitData {
    /* 0x00 */ Vec3f hitPos;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 hitID;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 timer;
    /* 0x1C */ s32 unk_1C;
} HammerHitData;

extern HammerHitData* HammerHit;

s32 action_hammer_is_swinging_away(s32 animID) {
    if (animID & 0x1000000) {
        return TRUE;
    }

    // away-facing swing anims
    switch (animID) {
        case 0x60011:
        case 0x60013:
        case 0x60015:
        case 0x60017:
        case 0x60019:
        case 0x6001B:
            return TRUE;
    }
    return FALSE;
}

void action_hammer_play_hit_fx(s32 hitID) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 shakeAmt;
    s32 time;
    s32 radius;
    s32 soundID;
    f32 theta, sinTheta, cosTheta;
    s32 numParticles;
    f32 x, y, z;

    if (gPlayerData.hammerLevel == 2) {
        shakeAmt = 1.2f;
        time = 1;
        radius = 28;
        soundID = 0x211A;
    } else if (gPlayerData.hammerLevel == 1) {
        shakeAmt = 0.8f;
        time = 1;
        radius = 16;
        soundID = 0x2119;
    } else {
        shakeAmt = 0.4f;
        time = 1;
        radius = 4;
        soundID = 0x2118;
    }

    theta = (func_800E5348() * TAU) / 360.0f;
    sinTheta = sin_rad(theta) * 25.0f;
    cosTheta = cos_rad(theta) * -25.0f;

    if (hitID < 0) {
        numParticles = 6;
        x = playerStatus->position.x + sinTheta;
        y = playerStatus->position.y;
        z = playerStatus->position.z + cosTheta;
    } else {
        numParticles = 3;
        x = HammerHit->hitPos.x + sinTheta;
        y = HammerHit->hitPos.y + playerStatus->colliderHeight - 5.0f;
        z = HammerHit->hitPos.z + cosTheta;
        radius = 1;
    }

    exec_ShakeCamX(0, 2, time, shakeAmt);
    fx_smoke_impact(0, x, y, z, radius, numParticles, 0, (time + 3) * 3);

    switch (is_ability_active(ABILITY_ATTACK_FX)) {
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

void action_hammer_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    HammerHit->unk_1C = 0;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        s32 animID;
        s32 soundID;

        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags |= PLAYER_STATUS_FLAGS_200000;
        HammerHit->timer = 0;
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_BC = 0;
        HammerHit->hitID = func_802B62A4_E25174(HammerHit);

        if (gPlayerData.hammerLevel == 2) {
            soundID = 0x2117;
            animID = 0x6001A;
            if (HammerHit->hitID < 0) {
                soundID = 0x2117;
                animID = 0x60018;
            }
        } else if (gPlayerData.hammerLevel == 1) {
            soundID = 0x2116;
            animID = 0x60016;
            if (HammerHit->hitID < 0) {
                soundID = 0x2116;
                animID = 0x60014;
            }
        } else {
            soundID = 0x2115;
            animID = 0x60012;
            if (HammerHit->hitID < 0) {
                soundID = 0x2115;
                animID = 0x60010;
            }
        }

        suggest_player_anim_clearUnkFlag(animID);
        sfx_play_sound_at_player(soundID, 0);
        HammerHit->unk_0C = 0;
        HammerHit->unk_14 = 0;
    }

    playerStatus->flags &= ~PLAYER_STATUS_FLAGS_1000000;
    if (HammerHit->timer < 3 && (playerStatus->flags & PLAYER_STATUS_FLAGS_40000)) {
        playerStatus->flags |= PLAYER_STATUS_FLAGS_20000000;
    } else if (HammerHit->timer < 2) {
        HammerHit->timer++;
    } else {
        func_802B6820_E256F0(HammerHit);
    }
}

INCLUDE_ASM(s32, "world/action/hammer", func_802B6820_E256F0);
