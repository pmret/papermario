#include "common.h"
#include "npc.h"
#include "effects.h"

typedef struct SneakyParasolUnk {
    /* 0x00 */ Npc* npc;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ Vec3f position;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
} SneakyParasolUnk;

extern SneakyParasolUnk D_802B6E80;

Npc *func_802B6000_E2A6B0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 angle;
    Npc* ret = NULL;
    do {                // TODO fix this do...while
        if (playerStatus->unk_0D != 0) {
            if (gGameStatusPtr->peachFlags & 8) {
                gGameStatusPtr->peachFlags &= ~0x8;
            } else {
                ret = npc_find_closest(playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 100.0f);
                if (ret != 0) {
                    if (fabs(ret->pos.y - playerStatus->position.y) - 1.0 > 0.0) {
                        ret = 0;
                    } else {
                        angle = clamp_angle(atan2(playerStatus->position.x, playerStatus->position.z, ret->pos.x, ret->pos.z));
                        if (fabs(angle - func_800E5348()) > 30.0) {
                            ret = 0;
                        }
                    }
                }
            }
        }
        return ret;
    } while (0);
}

void func_802B6120_E2A7D0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SneakyParasolUnk* parasolStruct = &D_802B6E80;
    Camera* cam = &gCameras[gCurrentCameraID];
    GameStatus* gameStatus;
    GameStatus* gameStatus2;
    Npc* temp_v0;
    f32* tempUnk_1C;
    f32 temp_f0_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 tempX;
    f64 tempZ;
    f64 temp_f22;
    s32 temp_v0_4;
    f32 phi_f4;
    s32 phi_v0;
    s32 phi_v0_2;
    f32 phi_f12;
    f32 phi_f12_2;
    f32 phi_f20;
    f32 phi_f22;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        mem_clear(&D_802B6E80, sizeof(D_802B6E80));
        disable_player_static_collisions();
        tempUnk_1C = &parasolStruct->unk_1C;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0;
        playerStatus->unk_8C = 0;
        phi_f4 = -2;

        if (playerStatus->spriteFacingAngle >= 90 && playerStatus->spriteFacingAngle < 270) {
            phi_f4 = 2;
        }
        *tempUnk_1C = phi_f4;
        if (!(playerStatus->animFlags & 0x2000)) {
            playerStatus->framesOnGround = 20;
            playerStatus->fallState = 0;
            parasolStruct->unk_08 = 0xF;
            parasolStruct->npc = func_802B6000_E2A6B0();
        } else {
            playerStatus->fallState = 0x14;
            playerStatus->framesOnGround = 40;
            parasolStruct->unk_04 = 1;
            parasolStruct->unk_0C = 0xC;
            temp_v0 = get_npc_by_index(D_8010C96C);
            temp_v0->flags |= 0x40000;
            playerStatus->flags |= 0x100000;
            sfx_play_sound_at_player(0xFD, 0);
        }
    }

    switch (playerStatus->fallState) {
        case 0:
            if (playerStatus->unk_90 == 0) {
                if (peach_disguise_check_overlaps() < 0) {
                    suggest_player_anim_clearUnkFlag(0xC0024);
                    sfx_play_sound_at_player(0x92, 0);
                    playerStatus->fallState++;
                } else {
                    suggest_player_anim_clearUnkFlag(0xC0027);
                    playerStatus->fallState = 0x32;
                    playerStatus->framesOnGround = 10;
                    parasolStruct->unk_08 = 0;
                }
            }
        case 1:
            if (--playerStatus->framesOnGround == 0) {
                suggest_player_anim_clearUnkFlag(0xC0025);
                playerStatus->fallState = 2;
                if (parasolStruct->npc == NULL) {
                    playerStatus->fallState = 0x28;
                } else {
                    set_time_freeze_mode(TIME_FREEZE_FULL);
                }
            }
            break;
        case 2:
            if (playerStatus->unk_BC != 0) {
                playerStatus->framesOnGround = 12;
                playerStatus->flags |= 0x100000;
                playerStatus->fallState++;
                sfx_play_sound_at_player(0xFD, 0);
            }
            break;
        case 3:
            if (--playerStatus->framesOnGround == 0) {
                playerStatus->framesOnGround = 10;
                parasolStruct->unk_0C = 0xA;
                playerStatus->fallState++;
            }
            func_802B6CF0_E2B3A0();
            break;
        case 4:
            temp_f20 = playerStatus->spriteFacingAngle;
            func_802B6CF0_E2B3A0();
            playerStatus->targetYaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
            if (playerStatus->framesOnGround == 0) {
                phi_v0 = 0;
                if (parasolStruct->unk_1C > 0) {
                    if (temp_f20 < 270 && playerStatus->spriteFacingAngle >= 270) {
                        phi_v0 = 1;
                    }
                }
                if (parasolStruct->unk_1C < 0 && temp_f20 > 270 && playerStatus->spriteFacingAngle <= 270) {
                    phi_v0 = 1;
                }
                if (phi_v0 != 0) {
                    playerStatus->fallState = 6;
                    playerStatus->framesOnGround = 2;
                    if (peach_make_disguise_npc(playerStatus->unk_0D) != 0) {
                        playerStatus->fallState = 5;
                        peach_sync_disguise_npc();
                    }
                }
            } else {
                playerStatus->framesOnGround--;
            }
            break;
        case 5:
            gameStatus = gGameStatusPtr;
            playerStatus->animFlags |= 0x2000;
            gameStatus->peachFlags |= 2;
            playerStatus->fallState++;
        case 6:
            if (--playerStatus->framesOnGround == 0) {
                playerStatus->fallState++;
            }
            func_802B6CF0_E2B3A0();
            break;
        case 7:
            if (parasolStruct->unk_1C > 0.0f) {
                parasolStruct->unk_20 -= 2.35;
                if (parasolStruct->unk_20 <= 0) {
                    parasolStruct->unk_20 = 0;
                    playerStatus->framesOnGround = 10;
                    playerStatus->fallState++;
                    playerStatus->spriteFacingAngle = 180;
                    temp_v0 = get_npc_by_index(D_8010C96C);
                    temp_v0->isFacingAway = 1;
                    temp_f0_3 = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
                    temp_v0_4 = temp_f0_3;
                    temp_v0->yaw = temp_f0_3;
                    temp_v0->yawCamOffset = temp_v0_4;
                }
            } else {
                parasolStruct->unk_20 += 2.35;
                if (parasolStruct->unk_20 >= 0) {
                    parasolStruct->unk_20 = 0;
                    playerStatus->framesOnGround = 10;
                    playerStatus->spriteFacingAngle = 0;
                    playerStatus->fallState++;
                    temp_v0 = get_npc_by_index(D_8010C96C);
                    temp_v0->isFacingAway = 0;
                    temp_f0_3 = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
                    temp_v0_4 = temp_f0_3;
                    temp_v0->yaw = temp_f0_3;
                    temp_v0->yawCamOffset = temp_v0_4;
                }
            }

            temp_f0_3 = clamp_angle(playerStatus->spriteFacingAngle + parasolStruct->unk_20);
            playerStatus->spriteFacingAngle = temp_f0_3;
            phi_f12_2 = cam->currentYaw - temp_f0_3;
            playerStatus->targetYaw = clamp_angle(phi_f12_2 - 90);
            break;
        case 8:
            if (--playerStatus->framesOnGround == 0) {
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                temp_v0 = get_npc_by_index(D_8010C96C);
                temp_v0->flags &= ~0x40000;
                playerStatus->flags &= ~0x100000;
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
        case 20:
            if (--playerStatus->framesOnGround == 0) {
                playerStatus->fallState++;
            }
            func_802B6CF0_E2B3A0();
            playerStatus->targetYaw = clamp_angle(cam->currentYaw - playerStatus->spriteFacingAngle - 90);
            break;
        case 21:
            temp_f20_2 = playerStatus->spriteFacingAngle;
            func_802B6CF0_E2B3A0();
            playerStatus->targetYaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
            if (playerStatus->framesOnGround == 0) {
                phi_v0_2 = 0;
                if (parasolStruct->unk_1C > 0) {
                    if (temp_f20_2 < 270 && playerStatus->spriteFacingAngle >= 270) {
                        phi_v0_2 = 1;
                    }
                }
                if (parasolStruct->unk_1C < 0 && temp_f20_2 > 270 && playerStatus->spriteFacingAngle <= 270) {
                    phi_v0_2 = 1;
                }
                if (phi_v0_2 != 0) {
                    playerStatus->framesOnGround = 2;
                    playerStatus->fallState++;
                    gameStatus2 = gGameStatusPtr;
                    playerStatus->animFlags &= -0x2001;
                    gameStatus2->peachFlags &= 0xFD;
                    playerStatus->peachDisguise = 0;
                    free_npc_by_index(D_8010C96C);
                    playerStatus->colliderHeight = 0x37;
                    playerStatus->colliderDiameter = 0x26;
                }
            } else {
                playerStatus->framesOnGround--;
            }
            break;
        case 22:
            if (--playerStatus->framesOnGround == 0) {
                playerStatus->fallState++;
            }
            func_802B6CF0_E2B3A0();
            break;
        case 23:
            if (parasolStruct->unk_1C > 0) {
                parasolStruct->unk_20 -= 2.35;
                if (parasolStruct->unk_20 <= 0) {
                    parasolStruct->unk_20 = 0;
                    playerStatus->framesOnGround = 10;
                    playerStatus->fallState++;
                    playerStatus->spriteFacingAngle = 180;
                    D_8010C95C = 1;
                    phi_f12 = (cam->currentYaw - 180) - 90;
                    temp_f0_3 = clamp_angle((cam->currentYaw - 180) - 90);
                    D_800F7B40 = temp_f0_3;
                    playerStatus->currentYaw = temp_f0_3;
                }
            } else {
                parasolStruct->unk_20 += 2.35;
                if (parasolStruct->unk_20 >= 0) {
                    parasolStruct->unk_20 = 0;
                    playerStatus->framesOnGround = 10;
                    playerStatus->spriteFacingAngle = 0;
                    playerStatus->fallState++;
                    D_8010C95C = 0;
                    phi_f12 = (cam->currentYaw - 0) - 90;
                    temp_f0_3 = clamp_angle(phi_f12);
                    D_800F7B40 = temp_f0_3;
                    playerStatus->currentYaw = temp_f0_3;
                }
            }
            temp_f0_3 = clamp_angle(playerStatus->spriteFacingAngle + parasolStruct->unk_20);
            playerStatus->spriteFacingAngle = temp_f0_3;
            playerStatus->targetYaw = clamp_angle(cam->currentYaw - temp_f0_3 - 90);
            break;
        case 24:
            if (--playerStatus->framesOnGround == 0) {
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                playerStatus->flags &= ~0x100000;
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
        case 26:
            func_800E63A4(0);
            enable_player_static_collisions();
            break;
        case 40:
            if (playerStatus->unk_BC != 0) {
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
        case 50:
            if (--playerStatus->framesOnGround == 0) {
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
    }

    if (parasolStruct->unk_08 > 0) {
        if (--parasolStruct->unk_08 == 0xA) {
            if (playerStatus->spriteFacingAngle >= 90 && playerStatus->spriteFacingAngle < 270) {
                phi_f20 = ((cam->currentYaw - 270) * TAU) / 360;
                phi_f22 = 46;
            } else {
                phi_f20 = ((cam->currentYaw - 90) * TAU) / 360;
                phi_f22 = 30;
            }
            parasolStruct->position.x = playerStatus->position.x + (phi_f22 * sin_rad(phi_f20));
            parasolStruct->position.z = playerStatus->position.z - (phi_f22 * cos_rad(phi_f20));
            parasolStruct->position.y = playerStatus->position.y - 20;
        }
        if (parasolStruct->unk_08 < 0xB && parasolStruct->unk_08 & 1) {
            playFX_11(3, parasolStruct->position.x - 8, parasolStruct->position.y + 50, parasolStruct->position.z, 2);
            temp_f22 = parasolStruct->position.x;
            tempX = (((cam->currentYaw + playerStatus->spriteFacingAngle) - 90) * TAU) / 360;

            phi_f20 = tempX;
            tempX = temp_f22 + (sin_rad(phi_f20) * 10.0);
            tempZ = parasolStruct->position.z;

            parasolStruct->position.x = tempX;
            parasolStruct->position.z = (tempZ - (cos_rad(phi_f20) * 10.0));
        }
    } else if (parasolStruct->unk_08 == 0) {
        parasolStruct->unk_08 = -1;
        if (parasolStruct->npc != NULL) {
            playFX_84(playerStatus->unk_0D - 1, parasolStruct->npc->pos.x, parasolStruct->npc->pos.y, parasolStruct->npc->pos.z, 1, parasolStruct->npc->yawCamOffset);
        }
    }
    if (parasolStruct->unk_0C != 0) {
        if (parasolStruct->unk_0C < 0xB) {
            if (parasolStruct->unk_0C == 0xA) {
                sfx_play_sound_at_player(0xFE, 0);
            }
            if ((parasolStruct->unk_0C & 3) == 0) {
                playFX_22(4, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 50, 50, 0x28, 0x1E);
            }
        }
        parasolStruct->unk_0C += -1;
    }
}

void func_802B6CF0_E2B3A0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SneakyParasolUnk* temp = &D_802B6E80;

    temp->unk_20 += temp->unk_1C;
    if (temp->unk_20 > 50.0f) {
        temp->unk_20 = 50.0f;
    } else if (temp->unk_20 < -50.0f) {
        temp->unk_20 = -50.0f;
    }

    playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + temp->unk_20);
}
