#include "common.h"
#include "effects.h"

typedef struct HammerUnk {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} HammerUnk;

extern HammerUnk* D_802B6DB0_E25C80;

void func_802B6820_E256F0(void);

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
        soundID = SOUND_211A;
    } else if (gPlayerData.hammerLevel == 1) {
        phi_f24 = 0.8f;
        s2temp = 1;
        phi_s1 = 16;
        soundID = SOUND_2119;
    } else {
        phi_f24 = 0.4f;
        s2temp = 1;
        phi_s1 = 4;
        soundID = SOUND_2118;
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
    fx_smoke_impact(0, xTemp, yTemp, zTemp, phi_s1, phi_s3, 0, (s2temp + 3) * 3);

    switch (is_ability_active(ABILITY_ATTACK_FX)) {
        case 1:
            soundID = SOUND_372;
            break;
        case 2:
            soundID = SOUND_F1;
            break;
        case 3:
            soundID = SOUND_DC;
            break;
        case 4:
            soundID = SOUND_2072;
            break;
        case 5:
            soundID = SOUND_2073;
            break;
        case 6:
            soundID = SOUND_205B;
            break;
    }

    sfx_play_sound_at_player(soundID, 0);
    start_rumble(0x100, 50);
}

s32 func_802B62A4_E25174(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw;
    f32 angle;
    f32 outSinTheta;
    f32 outCosTheta;
    f32 playerX, playerY, playerZ;
    f32 x, y, z;
    s32 ret;
    s32 i;

    yaw = func_800E5348();
    if (func_802B6000_E24ED0(playerStatus->trueAnimation)) {
        angle = clamp_angle(yaw + 90.0f - gCameras[gCurrentCameraID].currentYaw);
        if (angle >= 90.0f && angle < 270.0f) {
            yaw += -30.0f;
        } else {
            yaw += 30.0f;
        }
    }

    sin_cos_rad(yaw * TAU / 360.0f, &outSinTheta, &outCosTheta);
    playerX = playerStatus->position.x;
    playerY = playerStatus->position.y;
    playerZ = playerStatus->position.z;

    for (i = 1; i < 16; i++) {
        x = playerX + (outSinTheta * i);
        y = playerY;
        z = playerZ - (outCosTheta * i);
        ret = player_test_lateral_overlap(3, playerStatus, &x, &y, &z, 4.0f, yaw);
        if (ret >= 0) {
            D_802B6DB0_E25C80->unk_00.x = x;
            D_802B6DB0_E25C80->unk_00.y = y;
            D_802B6DB0_E25C80->unk_00.z = z;
            break;
        }
    }

    if (i >= 0x10) {
        yaw = func_800E5348();
        if (!func_802B6000_E24ED0(playerStatus->trueAnimation)) {
            angle = clamp_angle(yaw + 90.0f - gCameras[gCurrentCameraID].currentYaw);
            if (angle >= 90.0f && angle < 270.0f) {
                yaw += 15.0f;
            } else {
                yaw += -15.0f;
            }
        }

        sin_cos_rad(yaw * TAU / 360.0f, &outSinTheta, &outCosTheta);
        for (i = 1; i < 16; i++) {
            x = playerX + (outSinTheta * i);
            y = playerY;
            z = playerZ - (outCosTheta * i);

            ret = player_test_lateral_overlap(3, playerStatus, &x, &y, &z, 4.0f, yaw);
            if (ret >= 0) {
                D_802B6DB0_E25C80->unk_00.x = x;
                D_802B6DB0_E25C80->unk_00.y = y;
                D_802B6DB0_E25C80->unk_00.z = z;
                break;
            }
        }
    }

    if (ret >= 0 && (ret & 0x4000)) {
        s32 hammerLevel = gPlayerData.hammerLevel;

        switch (get_entity_type(ret)) {
            case ENTITY_TYPE_HAMMER1_BLOCK:
            case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
                if (hammerLevel >= 0) {
                    ret = -1;
                } else {
                    playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_SHIVERING;
                }
                break;
            case ENTITY_TYPE_HAMMER2_BLOCK:
            case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
                if (hammerLevel >= 1) {
                    ret = -1;
                } else {
                    playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_SHIVERING;
                }
                break;
            case ENTITY_TYPE_HAMMER3_BLOCK:
            case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
                if (hammerLevel >= 2) {
                    ret = -1;
                } else {
                    playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_SHIVERING;
                }
                break;
            case ENTITY_TYPE_WOODEN_CRATE:
            case ENTITY_TYPE_BOMBABLE_ROCK:
                playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_SHIVERING;
                break;
            case ENTITY_TYPE_BLUE_SWITCH:
            case ENTITY_TYPE_RED_SWITCH:
            case ENTITY_TYPE_BRICK_BLOCK:
                ret = -1;
                break;
        }
    }

    return ret;
}

void func_802B66A8_E25578(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    D_802B6DB0_E25C80->unk_1C = 0;

    if (playerStatus->flags < 0) {
        s32 animID;
        s32 soundID;

        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags |= PLAYER_STATUS_FLAGS_200000;
        D_802B6DB0_E25C80->unk_18 = 0;
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_BC = 0;
        D_802B6DB0_E25C80->unk_10 = func_802B62A4_E25174();

        if (gPlayerData.hammerLevel == 2) {
            soundID = SOUND_2117;
            animID = 0x6001A;
            if (D_802B6DB0_E25C80->unk_10 < 0) {
                soundID = SOUND_2117;
                animID = 0x60018;
            }
        } else if (gPlayerData.hammerLevel == 1) {
            soundID = SOUND_2116;
            animID = 0x60016;
            if (D_802B6DB0_E25C80->unk_10 < 0) {
                soundID = SOUND_2116;
                animID = 0x60014;
            }
        } else {
            soundID = SOUND_2115;
            animID = 0x60012;
            if (D_802B6DB0_E25C80->unk_10 < 0) {
                soundID = SOUND_2115;
                animID = 0x60010;
            }
        }

        suggest_player_anim_clearUnkFlag(animID);
        sfx_play_sound_at_player(soundID, 0);
        D_802B6DB0_E25C80->unk_0C = 0;
        D_802B6DB0_E25C80->unk_14 = 0;
    }

    playerStatus->flags &= ~PLAYER_STATUS_FLAGS_1000000;
    if (D_802B6DB0_E25C80->unk_18 < 3 && (playerStatus->flags & PLAYER_STATUS_FLAGS_40000)) {
        playerStatus->flags |= PLAYER_STATUS_FLAGS_20000000;
    } else if (D_802B6DB0_E25C80->unk_18 < 2) {
        D_802B6DB0_E25C80->unk_18++;
    } else {
        func_802B6820_E256F0();
    }
}

void func_802B6820_E256F0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus;
    f32 yaw;
    f32 angle;
    f32 outSinTheta;
    f32 outCosTheta;
    f32 playerX, playerY, playerZ;
    f32 x, y, z;
    s32 result;
    s32 hammerLevel;
    s32 soundID;
    u32 unk_BC;
    s32 ten;
    s32 ret;
    s32 i;

    do {
        collisionStatus = &gCollisionStatus;
    } while (0); // required to match;

    yaw = func_800E5348();
    if (func_802B6000_E24ED0(playerStatus->trueAnimation)) {
        angle = clamp_angle(yaw + 90.0f - gCameras[gCurrentCameraID].currentYaw);
        if (angle >= 90.0f && angle < 270.0f) {
            yaw += -30.0f;
        } else {
            yaw += 30.0f;
        }
    }

    sin_cos_rad(yaw * TAU / 360.0f, &outSinTheta, &outCosTheta);
    playerX = playerStatus->position.x;
    playerY = playerStatus->position.y;
    playerZ = playerStatus->position.z;

    for (i = 1; i < 0x10; i++) {
        x = playerX + (outSinTheta * i);
        y = playerY;
        z = playerZ - (outCosTheta * i);
        result = player_test_lateral_overlap(3, playerStatus, &x, &y, &z, 4.0f, yaw);
        if (D_802B6DB0_E25C80->unk_14 == 0) {
            collisionStatus->lastWallHammered = result;
            if (result >= 0) {
                if (result & 0x4000) {
                    get_entity_by_index(result)->unk_07 = 0;
                }
            }
        }

        if (result >= 0) {
            break;
        }
    }

    if (i >= 0x10) {
        yaw = func_800E5348();
        if (func_802B6000_E24ED0(playerStatus->trueAnimation) == 0) {
            angle = clamp_angle(yaw + 90.0f - gCameras[gCurrentCameraID].currentYaw);
            if (angle >= 90.0f && angle < 270.0f) {
                yaw += 15.0f;
            } else {
                yaw += -15.0f;
            }
        }
        sin_cos_rad(yaw * TAU / 360.0f, &outSinTheta, &outCosTheta);

        for (i = 1; i < 0x10; i++) {
            x = playerX + (outSinTheta * i);
            y = playerY;
            z = playerZ - (outCosTheta * i);
            result = player_test_lateral_overlap(3, playerStatus, &x, &y, &z, 4.0f, yaw);
            if (D_802B6DB0_E25C80->unk_14 == 0) {
                collisionStatus->lastWallHammered = result;
                if (result >= 0) {
                    if (result & 0x4000) {
                        get_entity_by_index(result)->unk_07 = 0;
                    }
                }
            }

            if (result >= 0) {
                break;
            }
        }
    }

    if (D_802B6DB0_E25C80->unk_18 == 2) {
        hammerLevel = gPlayerData.hammerLevel;
        if (hammerLevel == D_802B6DB0_E25C80->unk_18) {
            soundID = SOUND_2117;
        } else if (hammerLevel == 1) {
            soundID = SOUND_2116;
        } else {
            soundID = SOUND_2115;
        }
        sfx_play_sound_at_player(soundID, 0);

        func_802B6048_E24F18(D_802B6DB0_E25C80->unk_10);

        if (collisionStatus->lastWallHammered >= 0 && (collisionStatus->lastWallHammered & 0x4000)) {
            get_entity_by_index(collisionStatus->lastWallHammered)->unk_07 = 0;
            playerStatus->flags |= PLAYER_STATUS_FLAGS_1000000;
        } else if (D_802B6DB0_E25C80->unk_10 < 0) {
            playerStatus->flags |= PLAYER_STATUS_FLAGS_1000000;
        }

        if (D_802B6DB0_E25C80->unk_10 < 0 && gPlayerData.hammerLevel >= 2) {
            D_8015A578.unk_00 = 1;
            D_8015A578.unk_08 = playerStatus->position.y;
        }
    }

    if (playerStatus->fallState == 0 && result >= 0 && D_802B6DB0_E25C80->unk_14 == 0) {
        playerStatus->fallState++;
    }
    if (playerStatus->fallState == 1 && result < 0) {
        playerStatus->fallState = 2;
    }
    D_802B6DB0_E25C80->unk_18 += 1;
    if (result >= 0) {
        D_802B6DB0_E25C80->unk_14 = 1;
    }
    if (D_802B6DB0_E25C80->unk_18 == 6) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_200000;
    }

    unk_BC = playerStatus->unk_BC;
    if (unk_BC == 1) {
        if (D_802B6DB0_E25C80->unk_18 >= 7 && (playerStatus->pressedButtons & BUTTON_B)) {
            D_802B6DB0_E25C80->unk_1C = unk_BC;
        }

        D_802B6DB0_E25C80->unk_14 = 0;
        ten = 10; // required to match
        if (D_802B6DB0_E25C80->unk_1C != 0 || D_802B6DB0_E25C80->unk_18 > ten) {
            playerStatus->flags &= ~PLAYER_STATUS_FLAGS_1000000;
            set_action_state(ACTION_STATE_IDLE);
        }
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_200000;
    }
}
