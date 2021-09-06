#include "common.h"

extern f32 D_802B6730;
extern struct struct8015A578 D_8015A578;

typedef struct struct8015A578 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01[7];
    /* 0x02 */ f32 unk_08;
} struct8015A578;

void func_802B6000_E26DE0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Entity* entity;
    struct8015A578* tempStruct;
    s32 sp10;
    s32 tempCondition;
    f32 temp_f20;
    u32 entityType;
    u8 colliderType;

    if (playerStatus->flags & (1 << 31)) {
        playerStatus->flags &= ~0x80000006;
        playerStatus->flags |= 0xA;
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        D_802B6730 = 0.0f;
        playerStatus->gravityIntegrator[0] = 5.2f;
        suggest_player_anim_clearUnkFlag(0x1000A);
        disable_player_input();
        playerStatus->flags |= 0x200;
        gCameras[0].moveFlags |= 1;
        sfx_play_sound_at_player(0x146, 0);
    }

    tempCondition = 0;
    switch (playerStatus->fallState) {
        case 0:
            D_802B6730 = 40.0f;
            playerStatus->unk_8C += 40.0f;
            if (playerStatus->unk_8C >= 360.0f) {
                playerStatus->unk_8C = 360.0f;
            }
            if (playerStatus->gravityIntegrator[0] >= 0.0f) {
                playerStatus->gravityIntegrator[0] -= 0.54;
                if (collisionStatus->currentCeiling < 0) {
                    playerStatus->position.y += playerStatus->gravityIntegrator[0];
                } else if (collisionStatus->currentCeiling & 0x4000) {
                    entity = get_entity_by_index(collisionStatus->currentCeiling);
                    if (entity != NULL) {
                        playerStatus->position.y = entity->position.y - (playerStatus->colliderHeight * 0.5);
                    }
                }
            }
            if (playerStatus->unk_8C == 360.0f) {
                if (playerStatus->gravityIntegrator[0] <= 0.0f) {
                    playerStatus->framesOnGround = 5;
                    playerStatus->fallState = 2;
                    playerStatus->gravityIntegrator[0] = 2.0f;
                }
            }
            collisionStatus->currentCeiling = -1;
            break;
        case 2:
            if (playerStatus->gravityIntegrator[0] >= 0.0f) {
                playerStatus->gravityIntegrator[0] -= 1.4;
                if (collisionStatus->currentCeiling < 0) {
                    playerStatus->position.y += playerStatus->gravityIntegrator[0];
                }
            }
            if (--playerStatus->framesOnGround <= 0) {
                playerStatus->fallState++;
            }
            break;
        case 3:
            playerStatus->position.y = player_check_collision_below(0.0f, &sp10);
            D_802B6730 = 45.0f;
            playerStatus->unk_8C += 45.0f;
            if (playerStatus->unk_8C >= 360.0) {
                playerStatus->unk_8C = 0.0f;
                playerStatus->fallState++;
                playerStatus->gravityIntegrator[1] = -3.4744f;
                playerStatus->gravityIntegrator[2] = 0.4704f;
                playerStatus->gravityIntegrator[3] = -1.1904f;
                playerStatus->gravityIntegrator[0] = playerStatus->gravityIntegrator[1];
                suggest_player_anim_clearUnkFlag(0x1000B);
            }
            break;
        case 4:
            temp_f20 = func_800E34D8();
            playerStatus->position.y = player_check_collision_below(temp_f20, &sp10);
            if (temp_f20 < -100.0f) {
                playerStatus->gravityIntegrator[3] = 0.0f;
                playerStatus->gravityIntegrator[2] = 0.0f;
                playerStatus->gravityIntegrator[1] = 0.0f;
                playerStatus->gravityIntegrator[0] = -100.0f;
            }
            if (sp10 >= 0) {
                if (collisionStatus->currentFloor & 0x4000 && (entityType = get_entity_type(collisionStatus->currentFloor),
                                                               entityType == 8 || entityType == 7)) {
                    get_entity_by_index(collisionStatus->currentFloor)->collisionFlags |= 1;
                    playerStatus->fallState = 0xB;
                    playerStatus->flags &= ~0x8;
                    break;
                } else {
                    colliderType = get_collider_type_by_id(sp10);
                    if (colliderType == 3) {
                        playerStatus->unk_BF = 1;
                        set_action_state(ACTION_STATE_HIT_LAVA);
                        playerStatus->flags |= 0x800;
                        playerStatus->flags &= ~0x8;
                        return;
                    } else if (colliderType == 2) {
                            set_action_state(ACTION_STATE_HIT_LAVA);
                            playerStatus->flags &= ~0x8;
                            return;
                    } else {
                        playerStatus->gravityIntegrator[1] = -3.4744f;
                        playerStatus->gravityIntegrator[2] = 0.4704f;
                        playerStatus->gravityIntegrator[3] = -1.1904f;
                        playerStatus->gravityIntegrator[0] = 10.0f;
                        suggest_player_anim_clearUnkFlag(0x1000B);
                        playerStatus->actionState = 0xE;
                        playerStatus->decorationList = 0;
                        playerStatus->unk_280 = 0xC;
                        playerStatus->unk_8C = 0.0f;
                        playerStatus->fallState++;
                        exec_ShakeCam1(0, 0, 4);
                        sfx_play_sound_at_player(0x149, 0);
                        start_rumble(0x80, 0x19);
                        tempStruct = &D_8015A578;
                        tempStruct->unk_00 = 1;
                        tempStruct->unk_08 = playerStatus->position.y;
                        playerStatus->flags |= 0x400;
                    }
                }
            }
            break;
        case 5:
            temp_f20 = integrate_gravity();
            if (temp_f20 == 0.0f) {
                tempCondition = 1;
            } else {
                if (playerStatus->gravityIntegrator[0] > 0.0f) {
                    playerStatus->position.y += temp_f20;
                } else {
                    playerStatus->position.y = player_check_collision_below(temp_f20, &sp10);
                    if (playerStatus->gravityIntegrator[0] < 0.0f && sp10 >= 0) {
                        playerStatus->fallState++;
                    }
                }
                playerStatus->position.y = player_check_collision_below(0.0f, &sp10);
            }
            break;
        case 6:
            playerStatus->position.y = player_check_collision_below(0.0f, &sp10);
            if (sp10 >= 0) {
                playerStatus->gravityIntegrator[0] = 0.0f;
                playerStatus->gravityIntegrator[1] = 0.0f;
                playerStatus->gravityIntegrator[2] = 0.0f;
                playerStatus->gravityIntegrator[3] = 0.0f;
            }
        case 7:
            if (--playerStatus->unk_280 <= 0) {
                tempCondition = 1;
            }
            break;
        case 11:
            set_action_state(ACTION_STATE_LAND_ON_SWITCH);
            playerStatus->fallState++;
            enable_player_input();
            break;
        case 12:
            break;
    }

    if (tempCondition != 0) {
        set_action_state(ACTION_STATE_LAND);
        playerStatus->flags &= ~0x8;
    }
    if (playerStatus->gravityIntegrator[0] < 0.0f) {
        sp10 = func_802B6648_E27428();
        if (sp10 >= 0) {
            collisionStatus->lastTouchedFloor = -1;
            collisionStatus->currentFloor = sp10;
        }
    }
}

s32 func_802B6648_E27428(void) {
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
    return player_raycast_below_cam_relative(&gPlayerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38, &sp3C, &sp40, &sp44);
}
