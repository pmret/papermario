#include "common.h"
#include "npc.h"
#include "effects.h"

typedef struct SneakyParasolUnk {
    /* 0x00 */ Npc* npc;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 time;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ Vec3f position;
    /* 0x1C */ f32 playerRotationRate;
    /* 0x20 */ f32 playerYawOffset;
} SneakyParasolUnk;

enum {
    SUBSTATE_0      = 0,
    SUBSTATE_1      = 1,
    SUBSTATE_2      = 2,
    SUBSTATE_3      = 3,
    SUBSTATE_4      = 4,
    SUBSTATE_5      = 5,
    SUBSTATE_6      = 6,
    SUBSTATE_7      = 7,
    SUBSTATE_8      = 8,
    SUBSTATE_20     = 20,
    SUBSTATE_21     = 21,
    SUBSTATE_22     = 22,
    SUBSTATE_23     = 23,
    SUBSTATE_24     = 24,
    SUBSTATE_26     = 26,
    SUBSTATE_40     = 40,
    SUBSTATE_50     = 50
};

extern SneakyParasolUnk D_802B6E80;

void func_802B6CF0_E2B3A0(void);

Npc* parasol_get_npc(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 angle;
    Npc* ret = NULL;
    do {                // TODO fix this do...while
        if (playerStatus->unk_0D != 0) {
            if (gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_8) {
                gGameStatusPtr->peachFlags &= ~PEACH_STATUS_FLAG_8;
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

void action_update_parasol(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SneakyParasolUnk* parasolStruct = &D_802B6E80;
    Camera* cam = &gCameras[gCurrentCameraID];
    GameStatus* gameStatus;
    GameStatus* gameStatus2;
    Npc* disguiseNpc;
    f32* tempUnk_1C;
    f32 prevFacingAngle;
    f32 tempX;
    f64 tempZ;
    f64 temp_f22;
    f32 phi_f4;
    s32 phi_v0;
    f32 phi_f20;
    f32 phi_f22;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        mem_clear(&D_802B6E80, sizeof(D_802B6E80));
        disable_player_static_collisions();
        tempUnk_1C = &parasolStruct->playerRotationRate;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0;
        playerStatus->pitch = 0;
        
        if (playerStatus->spriteFacingAngle >= 90 && playerStatus->spriteFacingAngle < 270) {
            phi_f4 = 2;
        } else {
            phi_f4 = -2;
        }
        *tempUnk_1C = phi_f4;

        if (!(playerStatus->animFlags & PA_FLAGS_IN_DISGUISE)) {
            playerStatus->currentStateTime = 20;
            playerStatus->actionSubstate = SUBSTATE_0;
            parasolStruct->time = 15;
            parasolStruct->npc = parasol_get_npc();
        } else {
            playerStatus->actionSubstate = SUBSTATE_20;
            playerStatus->currentStateTime = 40;
            parasolStruct->unk_04 = 1;
            parasolStruct->unk_0C = 12;
            disguiseNpc = get_npc_by_index(PeachDisguiseNpcIndex);
            disguiseNpc->flags |= NPC_FLAG_40000;
            playerStatus->flags |= PS_FLAGS_100000;
            sfx_play_sound_at_player(SOUND_FD, 0);
        }
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_0:
            if (playerStatus->flipYaw[CAM_DEFAULT] == 0) {
                if (peach_disguise_check_overlaps() < 0) {
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_C0024);
                    sfx_play_sound_at_player(SOUND_92, 0);
                    playerStatus->actionSubstate++; // SUBSTATE_1
                } else {
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_C0027);
                    playerStatus->actionSubstate = SUBSTATE_50;
                    playerStatus->currentStateTime = 10;
                    parasolStruct->time = 0;
                }
            }
        case SUBSTATE_1:
            if (--playerStatus->currentStateTime == 0) {
                suggest_player_anim_clearUnkFlag(ANIM_Peach_C0025);
                playerStatus->actionSubstate = SUBSTATE_2;
                if (parasolStruct->npc == NULL) {
                    playerStatus->actionSubstate = SUBSTATE_40;
                } else {
                    set_time_freeze_mode(TIME_FREEZE_FULL);
                }
            }
            break;
        case SUBSTATE_2:
            if (playerStatus->unk_BC != 0) {
                playerStatus->currentStateTime = 12;
                playerStatus->flags |= PS_FLAGS_100000; // SUBSTATE_3
                playerStatus->actionSubstate++;
                sfx_play_sound_at_player(SOUND_FD, 0);
            }
            break;
        case SUBSTATE_3:
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->currentStateTime = 10;
                parasolStruct->unk_0C = 10;
                playerStatus->actionSubstate++; // SUBSTATE_4
            }
            func_802B6CF0_E2B3A0();
            break;
        case SUBSTATE_4:
            prevFacingAngle = playerStatus->spriteFacingAngle;
            func_802B6CF0_E2B3A0();
            playerStatus->targetYaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
            if (playerStatus->currentStateTime == 0) {
                phi_v0 = FALSE;
                if (parasolStruct->playerRotationRate > 0) {
                    if (prevFacingAngle < 270 && playerStatus->spriteFacingAngle >= 270) {
                        phi_v0 = TRUE;
                    }
                }
                if (parasolStruct->playerRotationRate < 0 && prevFacingAngle > 270 && playerStatus->spriteFacingAngle <= 270) {
                    phi_v0 = TRUE;
                }
                if (phi_v0) {
                    playerStatus->actionSubstate = SUBSTATE_6;
                    playerStatus->currentStateTime = 2;
                    if (peach_make_disguise_npc(playerStatus->unk_0D) != 0) {
                        playerStatus->actionSubstate = SUBSTATE_5;
                        peach_sync_disguise_npc();
                    }
                }
            } else {
                playerStatus->currentStateTime--;
            }
            break;
        case SUBSTATE_5:
            gameStatus = gGameStatusPtr;
            playerStatus->animFlags |= PA_FLAGS_IN_DISGUISE;
            gameStatus->peachFlags |= 2;
            playerStatus->actionSubstate++; // SUBSTATE_6
        case SUBSTATE_6:
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->actionSubstate++; // SUBSTATE_7
            }
            func_802B6CF0_E2B3A0();
            break;
        case SUBSTATE_7:
            if (parasolStruct->playerRotationRate > 0.0f) {
                parasolStruct->playerYawOffset -= 2.35;
                if (parasolStruct->playerYawOffset <= 0) {
                    parasolStruct->playerYawOffset = 0;
                    playerStatus->currentStateTime = 10;
                    playerStatus->actionSubstate++; // SUBSTATE_8
                    playerStatus->spriteFacingAngle = 180;
                    disguiseNpc = get_npc_by_index(PeachDisguiseNpcIndex);
                    disguiseNpc->isFacingAway = 1;
                    disguiseNpc->yaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
                    disguiseNpc->yawCamOffset = disguiseNpc->yaw;
                }
            } else {
                parasolStruct->playerYawOffset += 2.35;
                if (parasolStruct->playerYawOffset >= 0) {
                    parasolStruct->playerYawOffset = 0;
                    playerStatus->currentStateTime = 10;
                    playerStatus->spriteFacingAngle = 0;
                    playerStatus->actionSubstate++; // SUBSTATE_8
                    disguiseNpc = get_npc_by_index(PeachDisguiseNpcIndex);
                    disguiseNpc->isFacingAway = 0;
                    disguiseNpc->yaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
                    disguiseNpc->yawCamOffset = disguiseNpc->yaw;
                }
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + parasolStruct->playerYawOffset);
            playerStatus->targetYaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
            break;
        case SUBSTATE_8:
            if (--playerStatus->currentStateTime == 0) {
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                disguiseNpc = get_npc_by_index(PeachDisguiseNpcIndex);
                disguiseNpc->flags &= ~NPC_FLAG_40000;
                playerStatus->flags &= ~PS_FLAGS_100000;
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
        case SUBSTATE_20:
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->actionSubstate++; // SUBSTATE_21
            }
            func_802B6CF0_E2B3A0();
            playerStatus->targetYaw = clamp_angle(cam->currentYaw - playerStatus->spriteFacingAngle - 90);
            break;
        case SUBSTATE_21:
            prevFacingAngle = playerStatus->spriteFacingAngle;
            func_802B6CF0_E2B3A0();
            playerStatus->targetYaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
            if (playerStatus->currentStateTime == 0) {
                phi_v0 = FALSE;
                if (parasolStruct->playerRotationRate > 0) {
                    if (prevFacingAngle < 270 && playerStatus->spriteFacingAngle >= 270) {
                        phi_v0 = TRUE;
                    }
                }
                if (parasolStruct->playerRotationRate < 0 && prevFacingAngle > 270 && playerStatus->spriteFacingAngle <= 270) {
                    phi_v0 = TRUE;
                }
                if (phi_v0) {
                    playerStatus->currentStateTime = 2;
                    playerStatus->actionSubstate++; // SUBSTATE_22
                    gameStatus2 = gGameStatusPtr;
                    playerStatus->animFlags &= ~PA_FLAGS_IN_DISGUISE;
                    gameStatus2->peachFlags &= ~PEACH_STATUS_FLAG_DISGUISED;
                    playerStatus->peachDisguise = 0;
                    free_npc_by_index(PeachDisguiseNpcIndex);
                    playerStatus->colliderHeight = 55;
                    playerStatus->colliderDiameter = 38;
                }
            } else {
                playerStatus->currentStateTime--;
            }
            break;
        case SUBSTATE_22:
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->actionSubstate++; // SUBSTATE_23
            }
            func_802B6CF0_E2B3A0();
            break;
        case SUBSTATE_23:
            if (parasolStruct->playerRotationRate > 0) {
                parasolStruct->playerYawOffset -= 2.35;
                if (parasolStruct->playerYawOffset <= 0) {
                    parasolStruct->playerYawOffset = 0;
                    playerStatus->currentStateTime = 10;
                    playerStatus->actionSubstate++; // SUBSTATE_24
                    playerStatus->spriteFacingAngle = 180;
                    PrevPlayerDirection = 1;
                    playerStatus->currentYaw = clamp_angle((cam->currentYaw - 180) - 90);
                    PrevPlayerCamRelativeYaw = playerStatus->currentYaw;
                }
            } else {
                parasolStruct->playerYawOffset += 2.35;
                if (parasolStruct->playerYawOffset >= 0) {
                    parasolStruct->playerYawOffset = 0;
                    playerStatus->currentStateTime = 10;
                    playerStatus->spriteFacingAngle = 0;
                    playerStatus->actionSubstate++; // SUBSTATE_24
                    PrevPlayerDirection = 0;
                    playerStatus->currentYaw = clamp_angle((cam->currentYaw - 0) - 90);
                    PrevPlayerCamRelativeYaw = playerStatus->currentYaw;
                }
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + parasolStruct->playerYawOffset);
            playerStatus->targetYaw = clamp_angle(cam->currentYaw - playerStatus->spriteFacingAngle - 90);
            break;
        case SUBSTATE_24:
            if (--playerStatus->currentStateTime == 0) {
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                playerStatus->flags &= ~PS_FLAGS_100000;
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
        case SUBSTATE_26:
            func_800E63A4(0);
            enable_player_static_collisions();
            break;
        case SUBSTATE_40:
            if (playerStatus->unk_BC != 0) {
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
        case SUBSTATE_50:
            if (--playerStatus->currentStateTime == 0) {
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
    }

    if (parasolStruct->time > 0) {
        if (--parasolStruct->time == 10) {
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
        if (parasolStruct->time <= 10 && parasolStruct->time & 1) {
            fx_sparkles(FX_SPARKLES_3, parasolStruct->position.x - 8, parasolStruct->position.y + 50, parasolStruct->position.z, 2);
            
            /*
            TODO something like:
            phi_f20 = (((cam->currentYaw + playerStatus->spriteFacingAngle) - 90) * TAU) / 360;
            parasolStruct->position.x += sin_rad(phi_f20) * 10.0;
            parasolStruct->position.z -= cos_rad(phi_f20) * 10.0;
            */
            
            temp_f22 = parasolStruct->position.x;
            tempX = (((cam->currentYaw + playerStatus->spriteFacingAngle) - 90) * TAU) / 360;

            phi_f20 = tempX;
            tempX = temp_f22 + (sin_rad(phi_f20) * 10.0);
            tempZ = parasolStruct->position.z;

            parasolStruct->position.x = tempX;
            parasolStruct->position.z = (tempZ - (cos_rad(phi_f20) * 10.0));
        }
    } else if (parasolStruct->time == 0) {
        parasolStruct->time = -1;
        if (parasolStruct->npc != NULL) {
            fx_pink_sparkles(playerStatus->unk_0D - 1, parasolStruct->npc->pos.x, parasolStruct->npc->pos.y, parasolStruct->npc->pos.z, 1, parasolStruct->npc->yawCamOffset);
        }
    }
    if (parasolStruct->unk_0C != 0) {
        if (parasolStruct->unk_0C <= 10) {
            if (parasolStruct->unk_0C == 10) {
                sfx_play_sound_at_player(SOUND_FE, 0);
            }
            if ((parasolStruct->unk_0C & 3) == 0) {
                fx_stars_shimmer(4, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 50, 50, 40, 30);
            }
        }
        parasolStruct->unk_0C--;
    }
}

void func_802B6CF0_E2B3A0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SneakyParasolUnk* temp = &D_802B6E80;

    temp->playerYawOffset += temp->playerRotationRate;
    if (temp->playerYawOffset > 50.0f) {
        temp->playerYawOffset = 50.0f;
    } else if (temp->playerYawOffset < -50.0f) {
        temp->playerYawOffset = -50.0f;
    }

    playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + temp->playerYawOffset);
}
