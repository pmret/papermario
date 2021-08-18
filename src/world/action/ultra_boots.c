#include "common.h"

extern s32 gSpinHistoryBufferPos;
extern s32 gSpinHistoryPosY;
extern s16 gSpinHistoryPosAngle;
extern s32 D_8015A578;

typedef struct struct8015A578 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01[7];
    /* 0x08 */ f32 unk_08;
} struct8015A578;

void func_802B6000_E26710(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    struct8015A578* tempStruct;
    struct8015A578* tempStruct2;
    Entity* currentFloorEntity;
    f32 temp_f0;
    f32 temp_f20;
    s32 temp_a0;
    s32 temp_v0_2;
    s32 temp_v1_2;
    u32 temp_v0;
    f32 phi_f4;
    s32 sp12;
    s32 sp10;

    if (playerStatus->flags < 0) {
        temp_a0 = playerStatus->flags;
        playerStatus->flags &= ~0x80000000;
        playerStatus->flags |= 0x2000A;
        phys_clear_spin_history(temp_a0);
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->gravityIntegrator[0] = 16.0f;
        playerStatus->gravityIntegrator[1] = -7.38624f;
        playerStatus->gravityIntegrator[2] = 3.44694f;
        playerStatus->gravityIntegrator[3] = -0.75f;
        suggest_player_anim_setUnkFlag(0x80000);
        disable_player_input();
        playerStatus->flags |= 0x200;
        gCameras->moveFlags = gCameras->moveFlags | 1;
        temp_f0 = clamp_angle(playerStatus->targetYaw - gCameras[gCurrentCameraID].currentYaw);
        phi_f4 = -60.0f;
        if (temp_f0 <= 180.0f) {
            phi_f4 = 60.0f;
        }
        playerStatus->unk_D4 = phi_f4;
    }
    if (playerStatus->fallState < 4) {
        if (playerStatus->unk_D4 >= 0.0f) {
            playerStatus->spriteFacingAngle += playerStatus->unk_D4;
            if (playerStatus->spriteFacingAngle >= 360.0f) {
                playerStatus->spriteFacingAngle -= 360.0f;
            }
        } else {
            playerStatus->spriteFacingAngle += playerStatus->unk_D4;
            if (playerStatus->spriteFacingAngle < 0.0f) {
                playerStatus->spriteFacingAngle += 360.0f;
            }
        }
    }
    if (playerStatus->gravityIntegrator[0] <= 0.0f) {
        *(&gSpinHistoryPosY + (gSpinHistoryBufferPos)) = playerStatus->position.y;
    }

    *(&gSpinHistoryPosAngle + gSpinHistoryBufferPos++) = playerStatus->spriteFacingAngle;

    if (gSpinHistoryBufferPos >= 6) {
        gSpinHistoryBufferPos = 0;
    }

    switch (playerStatus->fallState) {
    case 0:
        temp_f20 = integrate_gravity();
        playerStatus->position.y = player_check_collision_below(temp_f20, &sp10);
        if (sp10 >= 0 && collisionStatus->currentFloor & 0x4000 && (get_entity_type(collisionStatus->currentFloor) - 7 < 2)) {
            currentFloorEntity = get_entity_by_index(collisionStatus->currentFloor);
            currentFloorEntity->collisionFlags |= 1;
            disable_player_input();
            playerStatus->fallState = 0xB;
        } else {
            if (temp_f20 <= 0.0f) {
                record_jump_apex();
                playerStatus->framesOnGround = 3;
                playerStatus->flags |= 4;
                playerStatus->fallState++;
                sfx_play_sound_at_player(0x147, 0);
            }
            if (sp10 >= 0) {
                playerStatus->flags &= ~0x00020008;
                set_action_state(ACTION_STATE_LAND);
            }
        }
        break;
    case 1:
        if (--playerStatus->framesOnGround <= 0) {
            playerStatus->fallState++;
        }
        break;
    case 2:
        temp_f20 = integrate_gravity();
        playerStatus->position.y = player_check_collision_below(temp_f20, &sp10);
        if (temp_f20 < -100.0f) {
            playerStatus->gravityIntegrator[3] = 0.0f;
            playerStatus->gravityIntegrator[2] = 0.0f;
            playerStatus->gravityIntegrator[1] = 0.0f;
            playerStatus->gravityIntegrator[0] = -100.0f;
        }
        if (sp10 >= 0) {
            if (collisionStatus->currentFloor & 0x4000) {
                temp_v0 = get_entity_type(collisionStatus->currentFloor);
                if (temp_v0 - 0x2E < 2) {
                    playerStatus->flags &= ~0x00020008;
                    set_action_state(ACTION_STATE_LAND);
                    return;
                }
                if (temp_v0 - 7 < 2) {
                    playerStatus->flags &= ~0x00020008;
                    phys_player_land();
                    exec_ShakeCam1(0, 0, 4);
                    sfx_play_sound_at_player(0x14A, 0);
                    start_rumble(0x100, 0x32);

                    tempStruct = &D_8015A578;
                    tempStruct->unk_00 = 1;
                    tempStruct->unk_08 = playerStatus->position.y;
                    playerStatus->flags |= 0x400;
                    return;
                }
            }
            temp_v1_2 = get_collider_type_by_id(sp10) & 0xFF;
            if (temp_v1_2 == 3) {
                playerStatus->unk_BF = 1;
                playerStatus->flags &= ~0x00020008;
                set_action_state(ACTION_STATE_HIT_LAVA);
                playerStatus->flags |= 0x800;
                return;
            }
            if (temp_v1_2 == 2) {
                set_action_state(ACTION_STATE_HIT_LAVA);
                playerStatus->flags &= ~0x00020008;
                return;
            }
            playerStatus->framesOnGround = 8;
            playerStatus->decorationList = 0;
            playerStatus->actionState = 0x10;
            playerStatus->fallState++;
            exec_ShakeCam1(0, 0, 4);
            sfx_play_sound_at_player(0x14A, 0);
            start_rumble(0x100, 0x32);

            tempStruct2 = &D_8015A578;
            tempStruct2->unk_00= 1;
            tempStruct2->unk_08 = playerStatus->position.y;
            playerStatus->flags |= 0x400;
        }
        break;
    case 3:
        if (--playerStatus->framesOnGround == 0) {
            playerStatus->fallState++;
            playerStatus->flags &= ~0x00020008;
            set_action_state(ACTION_STATE_LAND);
        }
        break;
    case 11:
        set_action_state(ACTION_STATE_LAND_ON_SWITCH);
        playerStatus->fallState++;
        enable_player_input();
    case 12:
    }

    if (playerStatus->gravityIntegrator[0] < 0.0f) {
        temp_v0_2 = func_802B65F8_E26D08();
        sp10 = temp_v0_2;
        if (temp_v0_2 >= 0) {
            collisionStatus->lastTouchedFloor = -1;
            collisionStatus->currentFloor = sp10;
        }
    }
    return;
}

void func_802B65F8_E26D08(void) {
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    f32 sp44;

    sp28 = gPlayerStatus.position.x;
    sp34 = gPlayerStatus.colliderHeight;
    sp30 = gPlayerStatus.position.z;
    sp2C = gPlayerStatus.position.y + (sp34 * 0.5f);
    player_raycast_below_cam_relative(&gPlayerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38, &sp3C, &sp40, &sp44);
}
