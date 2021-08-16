#include "common.h"
#include "world/partners.h"

void record_jump_apex(void) {
    gPlayerStatus.jumpApexHeight = gPlayerStatus.position.y;
}

s32 can_trigger_loading_zone(void) {
    PlayerData* playerData = &gPlayerData;
    s32 actionState = gPlayerStatusPtr->actionState;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (actionState == ACTION_STATE_IDLE ||
        actionState == ACTION_STATE_WALK ||
        actionState == ACTION_STATE_RUN ||
        actionState == ACTION_STATE_USE_TWEESTER ||
        actionState == ACTION_STATE_SPIN
       ) {
        return TRUE;
    }

    if (actionState == ACTION_STATE_RIDE) {
        if (playerData->currentPartner == PARTNER_LAKILESTER || playerData->currentPartner == PARTNER_BOW) {
            if (partnerActionStatus->actionState.b[0] != 0) {
                return TRUE;
            } else {
                gPlayerStatusPtr->animFlags |= 4;
                return FALSE;
            }
        } else {
            if (partnerActionStatus->actionState.b[3] == 6 || partnerActionStatus->actionState.b[3] == 7) {
                return partnerActionStatus->actionState.b[0] != 0;
            }
            if (partnerActionStatus->actionState.b[3] == 4) {
                gPlayerStatusPtr->animFlags |= 4;
                return FALSE;
            }
        }
    }
    return FALSE;
}

void move_player(s32 duration, f32 heading, f32 speed) {
    gPlayerStatus.flags |= 0x4000;
    gPlayerStatus.heading = heading;
    gPlayerStatus.moveFrames = duration;
    gPlayerStatus.currentSpeed = speed;

    if (!(gPlayerStatus.animFlags & 0x400000)) {
        set_action_state(speed > gPlayerStatus.walkSpeed ? ACTION_STATE_RUN : ACTION_STATE_WALK);
    }
}

INCLUDE_ASM(s32, "7bb60_len_41b0", collision_main_above);

INCLUDE_ASM(s32, "7bb60_len_41b0", func_800E29C8);

INCLUDE_ASM(s32, "7bb60_len_41b0", func_800E2BB0);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_update_jump);


#ifdef NON_MATCHING
// Rodata issue.
extern s32 D_800F7B50;

void phys_init_integrator_for_current_state() {
    f32* temp_a0;
    s8 temp_v0;
    PlayerStatus* playerStatus = &gPlayerStatus;

    temp_v0 = playerStatus->actionState - 3;
    switch (temp_v0) {
    case 4:
        playerStatus->gravityIntegrator[0] = 10.0f;
        playerStatus->gravityIntegrator[1] = -5.0f;
        playerStatus->gravityIntegrator[2] = 1.5f;
        playerStatus->gravityIntegrator[3] = -0.3f;
        return;
    case 0:
    case 10:
    case 11:
    case 12:
    case 13:
    case 18:
    case 20:
            temp_a0 = &D_800F7B50 ;
        if ((playerStatus->flags & 0x40000) == 0) {
            playerStatus->gravityIntegrator[0] = *temp_a0++;
            playerStatus->gravityIntegrator[1] = *temp_a0++;
            playerStatus->gravityIntegrator[2] = *temp_a0++;
            playerStatus->gravityIntegrator[3] = *temp_a0++;
            return;
        }

        playerStatus->gravityIntegrator[0] = *temp_a0++ * 0.5f;
        playerStatus->gravityIntegrator[1] = *temp_a0++ * 0.5f;
        playerStatus->gravityIntegrator[2] = *temp_a0++ * 0.5f;
        playerStatus->gravityIntegrator[3] = *temp_a0++ * 0.5f;
    default:
        return;
    }
}
#else
INCLUDE_ASM(void, "7bb60_len_41b0", phys_init_integrator_for_current_state);
#endif // NON_MATCHING

// This function is wack. This weird stuff is needed to match
void gravity_use_fall_parms(void) {
    f32* floats = D_800F7B60;
    PlayerStatus* playerStatus;
    do {} while (0);
    playerStatus = &gPlayerStatus;

    if (playerStatus->flags & 0x40000) {
        playerStatus->gravityIntegrator[0] = *floats++ / 12.0f;
        playerStatus->gravityIntegrator[1] = *floats++ / 12.0f;
        playerStatus->gravityIntegrator[2] = *floats++ / 12.0f;
        playerStatus->gravityIntegrator[3] = *floats++ / 12.0f;
    } else {
        playerStatus->gravityIntegrator[0] = *floats++;
        playerStatus->gravityIntegrator[1] = *floats++;
        playerStatus->gravityIntegrator[2] = *floats++;
        playerStatus->gravityIntegrator[3] = *floats++;
    }
}

void phys_update_falling(void) {
    if (gPlayerStatus.actionState != ACTION_STATE_LAND_ON_SWITCH && gPlayerStatus.actionState != ACTION_STATE_BOUNCE) {
        s32* colliderID;

        gPlayerStatus.position.y = player_check_collision_below(func_800E34D8(), &colliderID);

        func_800E315C(colliderID);
    }
}

// Matches but we need to decomp collision_main_lateral since there's a rodata padding issue
#ifdef NON_MATCHING
void func_800E315C(s32 colliderID) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (colliderID >= 0) {
        u8 colliderType = get_collider_type_by_id(colliderID);

        switch (colliderType) {
            case 1:
            case 4:
            case 5:
                set_action_state(ACTION_STATE_LAND);
                break;
            case 3:
                if ((partnerActionStatus->actionState.i & 0xFF0000FF) != 0x01000009) {
                    if (playerStatus->unk_10 == 0) {
                        if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
                            playerStatus->unk_BF = 1;
                            set_action_state(ACTION_STATE_HIT_LAVA);
                        }
                    } else {
                        set_action_state(ACTION_STATE_UNKNOWN_16);
                    }
                }
                break;
            case 2:
                if ((partnerActionStatus->actionState.i & 0xFF0000FF) != 0x01000009) {
                    if (playerStatus->unk_10 == 0) {
                        if (playerStatus->actionState != ACTION_STATE_HIT_FIRE) {
                            playerStatus->unk_BF = 2;
                            set_action_state(ACTION_STATE_HIT_LAVA);
                        }
                        break;
                    }
                    set_action_state(ACTION_STATE_UNKNOWN_16);
                }
                break;
            default:
                phys_player_land();
                break;
        }
    }
}
#else
INCLUDE_ASM(s32, "7bb60_len_41b0", func_800E315C);
#endif

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_player_land);

f32 integrate_gravity(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & 0x40000) {
        playerStatus->gravityIntegrator[2] += playerStatus->gravityIntegrator[3] / 1.7f;
        playerStatus->gravityIntegrator[1] += playerStatus->gravityIntegrator[2] / 1.7f;
        playerStatus->gravityIntegrator[0] += playerStatus->gravityIntegrator[1] / 1.7f;
    } else {
        playerStatus->gravityIntegrator[2] += playerStatus->gravityIntegrator[3];
        playerStatus->gravityIntegrator[1] += playerStatus->gravityIntegrator[2];
        playerStatus->gravityIntegrator[0] += playerStatus->gravityIntegrator[1];
    }
    return playerStatus->gravityIntegrator[0];
}

f32 func_800E34D8(void) {
    f32 ret = integrate_gravity();

    if (func_800E0208() != 0) {
        ret = 0.0f;
    }
    return ret;
}

INCLUDE_ASM(f32, "7bb60_len_41b0", player_check_collision_below, f32 arg0, s32* colliderID);

INCLUDE_ASM(s32, "7bb60_len_41b0", collision_main_lateral);

//something weird with hitID
#ifdef NON_MATCHING
s32 collision_check_player_intersecting_world(s32 arg0, s32 arg1, f32 arg2) {
    f32 angle = 0.0f;
    s32 ret = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        f32 x = gPlayerStatusPtr->position.x;
        f32 y = gPlayerStatusPtr->position.y + arg1;
        f32 z = gPlayerStatusPtr->position.z;
        s32 hitID = player_test_lateral_overlap(arg0, gPlayerStatusPtr, &x, &y, &z, 0, angle);

        if (hitID >= 0) {
            ret = hitID;
        }

        gPlayerStatusPtr->position.x = x;
        gPlayerStatusPtr->position.z = z;
        angle += 90.0f;
    }

    return ret;
}
#else
INCLUDE_ASM(s32, "7bb60_len_41b0", collision_check_player_intersecting_world, s32 arg0, s32 arg1, f32 arg2);
#endif

s32 func_800E4404(s32 arg0, s32 arg1, f32 arg2, f32* outX, f32* outY, f32* outZ) {
    f32 angle = 0.0f;
    s32 ret = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        f32 x = *outX;
        f32 y = *outY + arg1;
        f32 z = *outZ;
        s32 hitID = player_test_lateral_overlap(arg0, gPlayerStatusPtr, &x, &y, &z, 0, angle);

        if (hitID >= 0) {
            ret = hitID;
        }

        *outX = x;
        *outZ = z;
        angle += 90.0f;
    }

    return ret;
}

void collision_check_player_overlaps(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 temp_64 = playerStatus->unk_64;

    if (temp_64 != 0.0f) {
        f32 x = playerStatus->position.x;
        f32 y = playerStatus->position.y;
        f32 z = playerStatus->position.z;

        player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, temp_64, playerStatus->unk_88);

        temp_64 -= playerStatus->runSpeed / 10.0f;
        playerStatus->position.x = x;
        playerStatus->position.y = y;
        playerStatus->position.z = z;

        if (temp_64 < 0.0f) {
            temp_64 = 0.0f;
        }

        playerStatus->unk_64 = temp_64;
    }
}

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_should_player_be_sliding);

s32 phys_is_on_sloped_ground(void) {
    Shadow* playerShadow = get_shadow_by_index(gPlayerStatus.shadowID);
    f32 rotZ = playerShadow->rotation.z + 180.0;
    f32 rotX = playerShadow->rotation.x + 180.0;
    s32 ret = TRUE;

    if (fabsf(rotZ) < 20.0f && fabsf(rotX) < 20.0f) {
        ret = FALSE;
    }

    return ret;
}

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_main_collision_below);

void func_800E4AD8(s32 arg0) {
    Camera* currentCamera = &gCameras[gCurrentCameraID];

    collision_check_player_intersecting_world(arg0, 0, gPlayerStatus.spriteFacingAngle - 90.0f + currentCamera->currentYaw);
}

void func_800E4B40(s32 arg0, f32* arg1, f32* arg2, f32* arg3) {
    Camera* currentCamera = &gCameras[gCurrentCameraID];

    func_800E4404(arg0, 0, gPlayerStatus.spriteFacingAngle - 90.0f + currentCamera->currentYaw, arg1, arg2, arg3);
}

INCLUDE_ASM(s32, "7bb60_len_41b0", collision_lava_reset_check_additional_overlaps);

void func_800E4F10(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 tempB = 0;
    f32 yaw = playerStatus->targetYaw;
    f32 x = playerStatus->position.x;
    f32 y = playerStatus->position.y;
    f32 z = playerStatus->position.z;
    s32 temp = player_test_move_without_slipping(&gPlayerStatus, &x, &y, &z, 0, yaw, &tempB);

    playerStatus->position.x = x;
    playerStatus->position.z = z;

    if (tempB != 0 && temp < 0 && playerStatus->actionState != ACTION_STATE_18 && playerStatus->currentSpeed != 0.0f) {
        set_action_state(ACTION_STATE_18);
    }
}

void check_input_midair_jump(void) {
    if (!(gPlayerStatus.flags & 0x800018) &&
        !(gPlayerStatus.animFlags & 0x4001) &&
        gPlayerStatus.unk_C2 >= 6 &&
        gPlayerStatus.decorationList < 0x12 &&
        gPlayerStatus.pressedButtons & A_BUTTON) {

        switch (gPlayerData.bootsLevel) {
            case 0:
                break;
            case 1:
                set_action_state(ACTION_STATE_SPIN_JUMP);
                gPlayerStatus.flags |= 8;
                break;
            case 2:
                set_action_state(ACTION_STATE_ULTRA_JUMP);
                gPlayerStatus.flags |= 8;
                break;
        }
    }
}

PartnerID get_current_partner_id(void) {
    return gPlayerData.currentPartner;
}

void try_player_footstep_sounds(s32 arg0) {
    if ((gGameStatusPtr->frameCounter % arg0) == 0) {
        u8 colliderType = get_collider_type_by_id(gCollisionStatus.currentFloor);
        s32 soundID;
        s32 soundID2;

        if (colliderType == 6 || colliderType == 9) {
            soundID = 0x143;
            soundID2 = 0x144;
        } else {
            soundID = SOUND_STEP1;
            soundID2 = SOUND_STEP2;
        }

        if (D_800F7B80 == 0) {
            soundID = soundID2;
        }

        sfx_play_sound_at_player(soundID, 0);
        D_800F7B80 ^= 1;
    }
}

void phys_update_interact_collider(void) {
    gCollisionStatus.unk_0A = phys_check_interactable_collision();
}

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_check_interactable_collision);

s32 phys_can_player_interact(void) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 ret = TRUE;

    if (gPartnerActionStatus.actionState.b[0] != 0) {
        if (gPartnerActionStatus.actionState.b[3] == 3) {
            if (gPartnerActionStatus.actionState.b[0] < 3) {
                ret = FALSE;
            }
        } else {
            ret = FALSE;
        }
    } else if (!(gPlayerStatus.actionState == ACTION_STATE_IDLE ||
                 gPlayerStatus.actionState == ACTION_STATE_WALK ||
                 gPlayerStatus.actionState == ACTION_STATE_RUN)) {
        ret = FALSE;
    }
    return ret;
}

INCLUDE_ASM(f32, "7bb60_len_41b0", func_800E5348, void);

void player_get_camera_facing_angle(void) {
    f32 angle = 0.0f;

    if (gPlayerStatus.spriteFacingAngle >= 90.0f && gPlayerStatus.spriteFacingAngle < 270.0f) {
        angle = 180.0f;
    }

    angle = angle + gCameras[0].currentYaw + 90.0f;

    clamp_angle(angle);
}

void phys_save_ground_pos(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->lastGoodPosition.x = playerStatus->position.x;
    playerStatus->lastGoodPosition.y = playerStatus->position.y;
    playerStatus->lastGoodPosition.z = playerStatus->position.z;
}
