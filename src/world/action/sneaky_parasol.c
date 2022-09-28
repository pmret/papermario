#include "common.h"
#include "npc.h"
#include "effects.h"

s32 peach_disguise_check_overlaps(void);
void peach_force_disguise_action(s32);

typedef struct TransformationData {
    /* 0x00 */ Npc* npc;
    /* 0x04 */ s32 reverted;
    /* 0x08 */ s32 disguiseTime;
    /* 0x0C */ s32 revertTime;
    /* 0x10 */ Vec3f position;
    /* 0x1C */ f32 playerRotationRate;
    /* 0x20 */ f32 playerYawOffset;
} TransformationData;

enum {
    SUBSTATE_DISGUISE_INIT              = 0,
    SUBSTATE_USE_PARASOL                = 1, // get parasol out and try copying an npc
    SUBSTATE_PUT_AWAY                   = 2, // put the parasol away
    SUBSTATE_DISGUISE_BEGIN             = 3,
    SUBSTATE_DISGUISE_WAIT_FOR_ANGLE    = 4, // sparkales?
    SUBSTATE_DISGUISE_MAKE_NPC          = 5, // npc?
    SUBSTATE_DISGUISE_SPIN_DOWN         = 6,
    SUBSTATE_DISGUISE_FINISH_SPIN       = 7,
    SUBSTATE_DISGUISE_DONE              = 8,
    SUBSTATE_REVERT_INIT                = 20, // begin undisguise process
    SUBSTATE_REVERT_WAIT_FOR_ANGLE      = 21,
    SUBSTATE_SPIN_DOWN                  = 22,
    SUBSTATE_FINISH_SPIN                = 23,
    SUBSTATE_REVERT_DONE                = 24,
    SUBSTATE_ABORT                      = 26,
    SUBSTATE_FAILED                     = 40,
    SUBSTATE_BLOCKED                    = 50, // cant raise parasol due to collisions with world
};

BSS TransformationData ParasolTransformation;

void parasol_update_spin(void);

Npc* parasol_get_npc(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 angle;
    Npc* ret = NULL;
    do {                // TODO fix this do...while
        if (playerStatus->availableDisguiseType != 0) {
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
    TransformationData* transformation = &ParasolTransformation;
    Camera* cam = &gCameras[gCurrentCameraID];
    GameStatus* gameStatus;
    GameStatus* gameStatus2;
    Npc* disguiseNpc;
    f32* tempUnk_1C;
    f32 prevFacingAngle;
    f32 phi_f4;
    s32 reachedTangentAngle;
    f32 angle;
    f32 radius;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        mem_clear(&ParasolTransformation, sizeof(ParasolTransformation));
        disable_player_static_collisions();
        tempUnk_1C = &transformation->playerRotationRate;
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
            playerStatus->actionSubstate = SUBSTATE_DISGUISE_INIT;
            transformation->disguiseTime = 15;
            transformation->npc = parasol_get_npc();
        } else {
            playerStatus->actionSubstate = SUBSTATE_REVERT_INIT;
            playerStatus->currentStateTime = 40;
            transformation->reverted = 1;
            transformation->revertTime = 12;
            disguiseNpc = get_npc_by_index(PeachDisguiseNpcIndex);
            disguiseNpc->flags |= NPC_FLAG_40000;
            playerStatus->flags |= PS_FLAGS_100000;
            sfx_play_sound_at_player(SOUND_FD, 0);
        }
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_DISGUISE_INIT:
            if (playerStatus->flipYaw[CAM_DEFAULT] == 0) {
                if (peach_disguise_check_overlaps() < 0) {
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_C0024);
                    sfx_play_sound_at_player(SOUND_92, 0);
                    playerStatus->actionSubstate++; // SUBSTATE_USE_PARASOL
                } else {
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_C0027);
                    playerStatus->actionSubstate = SUBSTATE_BLOCKED;
                    playerStatus->currentStateTime = 10;
                    transformation->disguiseTime = 0;
                }
            }
        case SUBSTATE_USE_PARASOL:
            if (--playerStatus->currentStateTime == 0) {
                suggest_player_anim_clearUnkFlag(ANIM_Peach_C0025);
                playerStatus->actionSubstate = SUBSTATE_PUT_AWAY;
                if (transformation->npc == NULL) {
                    playerStatus->actionSubstate = SUBSTATE_FAILED;
                } else {
                    set_time_freeze_mode(TIME_FREEZE_FULL);
                }
            }
            break;
        case SUBSTATE_PUT_AWAY:
            if (playerStatus->animNotifyValue != 0) {
                playerStatus->currentStateTime = 12;
                playerStatus->flags |= PS_FLAGS_100000;
                playerStatus->actionSubstate++; // SUBSTATE_DISGUISE_BEGIN
                sfx_play_sound_at_player(SOUND_FD, 0);
            }
            break;
        case SUBSTATE_DISGUISE_BEGIN:
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->currentStateTime = 10;
                transformation->revertTime = 10;
                playerStatus->actionSubstate++; // SUBSTATE_DISGUISE_WAIT_FOR_ANGLE
            }
            parasol_update_spin();
            break;
        case SUBSTATE_DISGUISE_WAIT_FOR_ANGLE:
            prevFacingAngle = playerStatus->spriteFacingAngle;
            parasol_update_spin();
            playerStatus->targetYaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
            if (playerStatus->currentStateTime == 0) {
                // wait for the sprite to rotate into a position where it's tangent to the camera
                reachedTangentAngle = FALSE;
                if (transformation->playerRotationRate > 0) {
                    if (prevFacingAngle < 270 && playerStatus->spriteFacingAngle >= 270) {
                        reachedTangentAngle = TRUE;
                    }
                }
                if (transformation->playerRotationRate < 0) {
                    if (prevFacingAngle > 270 && playerStatus->spriteFacingAngle <= 270) {
                        reachedTangentAngle = TRUE;
                    }
                }
                if (reachedTangentAngle) {
                    playerStatus->actionSubstate = SUBSTATE_DISGUISE_SPIN_DOWN;
                    playerStatus->currentStateTime = 2;
                    if (peach_make_disguise_npc(playerStatus->availableDisguiseType) != NULL) {
                        playerStatus->actionSubstate = SUBSTATE_DISGUISE_MAKE_NPC;
                        peach_sync_disguise_npc();
                    }
                }
            } else {
                playerStatus->currentStateTime--;
            }
            break;
        case SUBSTATE_DISGUISE_MAKE_NPC:
            gameStatus = gGameStatusPtr;
            playerStatus->animFlags |= PA_FLAGS_IN_DISGUISE;
            gameStatus->peachFlags |= PEACH_STATUS_FLAG_DISGUISED;
            playerStatus->actionSubstate++; // SUBSTATE_DISGUISE_SPIN_DOWN
        case SUBSTATE_DISGUISE_SPIN_DOWN:
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->actionSubstate++; // SUBSTATE_DISGUISE_FINISH_SPIN
            }
            parasol_update_spin();
            break;
        case SUBSTATE_DISGUISE_FINISH_SPIN:
            if (transformation->playerRotationRate > 0.0f) {
                transformation->playerYawOffset -= 2.35;
                if (transformation->playerYawOffset <= 0) {
                    transformation->playerYawOffset = 0;
                    playerStatus->currentStateTime = 10;
                    playerStatus->actionSubstate++; // SUBSTATE_DISGUISE_DONE
                    playerStatus->spriteFacingAngle = 180;
                    disguiseNpc = get_npc_by_index(PeachDisguiseNpcIndex);
                    disguiseNpc->isFacingAway = 1;
                    disguiseNpc->yaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
                    disguiseNpc->yawCamOffset = disguiseNpc->yaw;
                }
            } else {
                transformation->playerYawOffset += 2.35;
                if (transformation->playerYawOffset >= 0) {
                    transformation->playerYawOffset = 0;
                    playerStatus->currentStateTime = 10;
                    playerStatus->spriteFacingAngle = 0;
                    playerStatus->actionSubstate++; // SUBSTATE_DISGUISE_DONE
                    disguiseNpc = get_npc_by_index(PeachDisguiseNpcIndex);
                    disguiseNpc->isFacingAway = 0;
                    disguiseNpc->yaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
                    disguiseNpc->yawCamOffset = disguiseNpc->yaw;
                }
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + transformation->playerYawOffset);
            playerStatus->targetYaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
            break;
        case SUBSTATE_DISGUISE_DONE:
            if (--playerStatus->currentStateTime == 0) {
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                disguiseNpc = get_npc_by_index(PeachDisguiseNpcIndex);
                disguiseNpc->flags &= ~NPC_FLAG_40000;
                playerStatus->flags &= ~PS_FLAGS_100000;
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
        case SUBSTATE_REVERT_INIT:
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->actionSubstate++; // SUBSTATE_REVERT_WAIT_FOR_ANGLE
            }
            parasol_update_spin();
            playerStatus->targetYaw = clamp_angle(cam->currentYaw - playerStatus->spriteFacingAngle - 90);
            break;
        case SUBSTATE_REVERT_WAIT_FOR_ANGLE:
            prevFacingAngle = playerStatus->spriteFacingAngle;
            parasol_update_spin();
            playerStatus->targetYaw = clamp_angle((cam->currentYaw - playerStatus->spriteFacingAngle) - 90);
            if (playerStatus->currentStateTime == 0) {
                // wait for the sprite to rotate into a position where it's tangent to the camera
                reachedTangentAngle = FALSE;
                if (transformation->playerRotationRate > 0) {
                    if (prevFacingAngle < 270 && playerStatus->spriteFacingAngle >= 270) {
                        reachedTangentAngle = TRUE;
                    }
                }
                if (transformation->playerRotationRate < 0) {
                    if (prevFacingAngle > 270 && playerStatus->spriteFacingAngle <= 270) {
                        reachedTangentAngle = TRUE;
                    }
                }
                if (reachedTangentAngle) {
                    playerStatus->currentStateTime = 2;
                    playerStatus->actionSubstate++; // SUBSTATE_SPIN_DOWN
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
        case SUBSTATE_SPIN_DOWN:
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->actionSubstate++; // SUBSTATE_FINISH_SPIN
            }
            parasol_update_spin();
            break;
        case SUBSTATE_FINISH_SPIN:
            if (transformation->playerRotationRate > 0) {
                transformation->playerYawOffset -= 2.35;
                if (transformation->playerYawOffset <= 0) {
                    transformation->playerYawOffset = 0;
                    playerStatus->currentStateTime = 10;
                    playerStatus->actionSubstate++; // SUBSTATE_REVERT_DONE
                    playerStatus->spriteFacingAngle = 180;
                    PrevPlayerDirection = 1;
                    playerStatus->currentYaw = clamp_angle((cam->currentYaw - 180) - 90);
                    PrevPlayerCamRelativeYaw = playerStatus->currentYaw;
                }
            } else {
                transformation->playerYawOffset += 2.35;
                if (transformation->playerYawOffset >= 0) {
                    transformation->playerYawOffset = 0;
                    playerStatus->currentStateTime = 10;
                    playerStatus->spriteFacingAngle = 0;
                    playerStatus->actionSubstate++; // SUBSTATE_REVERT_DONE
                    PrevPlayerDirection = 0;
                    playerStatus->currentYaw = clamp_angle((cam->currentYaw - 0) - 90);
                    PrevPlayerCamRelativeYaw = playerStatus->currentYaw;
                }
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + transformation->playerYawOffset);
            playerStatus->targetYaw = clamp_angle(cam->currentYaw - playerStatus->spriteFacingAngle - 90);
            break;
        case SUBSTATE_REVERT_DONE:
            if (--playerStatus->currentStateTime == 0) {
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                playerStatus->flags &= ~PS_FLAGS_100000;
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
        case SUBSTATE_ABORT:
            peach_force_disguise_action(FALSE);
            enable_player_static_collisions();
            break;
        case SUBSTATE_FAILED:
            if (playerStatus->animNotifyValue != 0) {
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
        case SUBSTATE_BLOCKED:
            if (--playerStatus->currentStateTime == 0) {
                set_action_state(ACTION_STATE_IDLE);
                enable_player_static_collisions();
            }
            break;
    }

    if (transformation->disguiseTime > 0) {
        if (--transformation->disguiseTime == 10) {
            if (playerStatus->spriteFacingAngle >= 90 && playerStatus->spriteFacingAngle < 270) {
                angle = DEG_TO_RAD(cam->currentYaw - 270);
                radius = 46;
            } else {
                angle = DEG_TO_RAD(cam->currentYaw - 90);
                radius = 30;
            }
            transformation->position.x = playerStatus->position.x + (radius * sin_rad(angle));
            transformation->position.z = playerStatus->position.z - (radius * cos_rad(angle));
            transformation->position.y = playerStatus->position.y - 20;
        }
        if (transformation->disguiseTime <= 10 && transformation->disguiseTime & 1) {
            f64 tempX, tempZ;

            fx_sparkles(FX_SPARKLES_3,
                transformation->position.x - 8,
                transformation->position.y + 50,
                transformation->position.z,
                2);

            /*
            TODO something like:
            angle = DEG_TO_RAD((cam->currentYaw + playerStatus->spriteFacingAngle) - 90);
            transformation->position.x += (10.0 * sin_rad(angle));
            transformation->position.z -= (10.0 * cos_rad(angle));
            */

            angle = DEG_TO_RAD((cam->currentYaw + playerStatus->spriteFacingAngle) - 90);

            tempX = transformation->position.x;
            tempX += 10.0 * sin_rad(angle);
            transformation->position.x = tempX;

            tempZ = transformation->position.z;
            transformation->position.z = tempZ - (10.0 * cos_rad(angle));
        }
    } else if (transformation->disguiseTime == 0) {
        transformation->disguiseTime = -1;
        if (transformation->npc != NULL) {
            fx_pink_sparkles(playerStatus->availableDisguiseType - 1,
                transformation->npc->pos.x,
                transformation->npc->pos.y,
                transformation->npc->pos.z,
                1, transformation->npc->yawCamOffset);
        }
    }
    if (transformation->revertTime != 0) {
        if (transformation->revertTime <= 10) {
            if (transformation->revertTime == 10) {
                sfx_play_sound_at_player(SOUND_FE, 0);
            }
            if ((transformation->revertTime & 3) == 0) {
                fx_stars_shimmer(4,
                    playerStatus->position.x,
                    playerStatus->position.y,
                    playerStatus->position.z,
                    50, 50, 40, 30);
            }
        }
        transformation->revertTime--;
    }
}

void parasol_update_spin(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    TransformationData* transformation = &ParasolTransformation;

    transformation->playerYawOffset += transformation->playerRotationRate;
    if (transformation->playerYawOffset > 50.0f) {
        transformation->playerYawOffset = 50.0f;
    } else if (transformation->playerYawOffset < -50.0f) {
        transformation->playerYawOffset = -50.0f;
    }

    playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + transformation->playerYawOffset);
}
