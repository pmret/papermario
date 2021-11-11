#include "common.h"

extern s32 D_802B6ED0;          // some entity index
extern f32 D_802B6ED4;
extern f32 D_802B6ED8;
extern f32 D_802B6EDC;
extern f32 D_802B6EE0;
extern f32 D_802B6EE4;
extern f32 D_802B6EE8;
extern f32 D_802B6EEC;
extern f32 D_802B6EF0;
extern f32 D_802B6EF4;
extern s16 D_802BCE30;
extern s16 D_802BCE32;
extern s16 D_802BCE34;

s32 func_802B6000_E29470(void) {
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
    sp2C = gPlayerStatus.position.y + (sp34 * 0.5);
    return player_raycast_below_cam_relative(&gPlayerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38, &sp3C, &sp40, &sp44);
}

void func_802B60A4_E29514(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Entity* entityByIndex;
    s32* TempPointer;
    s32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 tempY;
    f32 tempDistance;
    s8 switchCondition;

    if (playerStatus->flags & (1 << 31)) {
        playerStatus->flags &= ~0x80000000;
        gOverrideFlags |= 0x40;
        func_800EF300();
        playerStatus->fallState = 1;
        playerStatus->framesOnGround = 0;
        D_802B6EE4 = 0.0f;
        D_802B6EE8 = 0.0f;
        D_802B6EF4 = playerStatus->position.y;
        D_802B6EDC = 3.0f;
        disable_player_static_collisions();
        disable_player_input();
        playerStatus->flags |= 0x100000;
        sp20 = gCollisionStatus.currentFloor;

        TempPointer = &D_802B6ED0;
        if (sp20 >= 0){
            if(!(sp20 & 0x4000)) {
                D_802B6ED0 = -1;
            } else {
                D_802B6ED0 = sp20 & 0x3FF;
            }
        } else {
            D_802B6ED0 = -1;
        }
        if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
            suggest_player_anim_clearUnkFlag(0x1002B);
        }
    }
    switch(playerStatus->fallState) {
        case 1:
            gOverrideFlags |= 0x40;
            if (++D_802B6EE4 >= 20.0f) {
                D_802B6EE4 = 20.0f;
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            if (playerStatus->framesOnGround < 10) {
                playerStatus->framesOnGround++;
                D_802B6EF4++;
            }
            D_802B6EE8 += 8.0f;
            playerStatus->position.y = D_802B6EF4 + sin_rad(clamp_angle(D_802B6EE8) * TAU / 360.0f) * 4.0f;
            if (D_802B6ED0 >= 0) {
                entityByIndex = get_entity_by_index(D_802B6ED0);
                tempDistance = dist2D(entityByIndex->position.x, entityByIndex->position.z, playerStatus->position.x, playerStatus->position.z);
                D_802B6EEC = atan2(entityByIndex->position.x, entityByIndex->position.z, playerStatus->position.x, playerStatus->position.z);
                if (tempDistance > 4.0f) {
                    tempDistance--;
                }
                sin_cos_rad(D_802B6EEC * TAU / 360.0f, &sp10, &sp14);
                playerStatus->position.x = entityByIndex->position.x + (sp10 * tempDistance);
                playerStatus->position.z = entityByIndex->position.z - (sp14 * tempDistance);
                sin_cos_rad((D_802B6EEC - 91.0f) * TAU / 360.0f, &sp10, &sp14);
                D_802B6ED4 = sp10 * D_802B6EDC;
                D_802B6ED8 = -sp14 * D_802B6EDC;
            }
            game_input_to_move_vector(&sp18, &sp1C);
            if (sp1C != 0.0f) {
                sin_cos_rad((sp18 * TAU) / 360.0f, &sp10, &sp14);
                sp1C *= 0.03125f;
                if (sp1C < 0.1) {
                    sp1C = 0.1f;
                }
                playerStatus->position.x += sp10 * sp1C;
                playerStatus->position.z -= sp14 * sp1C;
            }
            gCameras->targetPos.x = playerStatus->position.x;
            gCameras->targetPos.y = playerStatus->position.y;
            gCameras->targetPos.z = playerStatus->position.z;
            sp20 = func_802B6000_E29470();
            if (sp20 < 0 || !(sp20 & 0x4000)) {
                playerStatus->framesOnGround = 20;
                D_802B6EE8 = 0.0f;
                D_802B6EF4 = playerStatus->position.y;
                playerStatus->fallState++;
                D_802B6EF0 = 1.6f;
                playerStatus->flags |= 0x800000;
            }
            if (gGameStatusPtr->pressedButtons & BUTTON_Z && !(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
                suggest_player_anim_setUnkFlag(0x10007);
                playerStatus->fallState = 3;
                playerStatus->framesOnGround = 30;
                D_802B6EE0 = 0.0f;
                gCollisionStatus.currentFloor = -1;
                exec_entity_commandlist(get_entity_by_index(D_802B6ED0));
            }
            break;
        case 2:
            gOverrideFlags |= 0x40;
            if (--D_802B6EE4 < 0.0f) {
                D_802B6EE4 = 0.0f;
                playerStatus->flags &= ~0x100000;
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            sin_cos_rad((D_802B6EEC - 60.0f) * TAU / 360.0f, &sp10, &sp14);
            D_802B6EDC += 0.2;
            D_802B6EF0 -= 0.72;
            D_802B6ED4 = sp10 * D_802B6EDC;
            D_802B6ED8 = -sp14 * D_802B6EDC;
            playerStatus->position.x += D_802B6ED4;
            playerStatus->position.z += D_802B6ED8;
            collision_lava_reset_check_additional_overlaps();
            playerStatus->position.y = player_check_collision_below(D_802B6EF0, &sp20);
            gCameras->targetPos.x = playerStatus->position.x;
            gCameras->targetPos.y = playerStatus->position.y;
            gCameras->targetPos.z = playerStatus->position.z;
            if (sp20 >= 0) {
                playerStatus->flags &= ~0x100000;
                enable_player_input();
                enable_player_static_collisions();
                set_action_state(ACTION_STATE_LAND);
                enable_partner_ai();
                gOverrideFlags &= ~0x40;
                return;
            }
    }

    switchCondition = playerStatus->fallState - 3;
    switch (switchCondition) {
        case 0:
            if (D_802B6ED0 >= 0) {
                entityByIndex = get_entity_by_index(D_802B6ED0);
                tempDistance = dist2D(entityByIndex->position.x, entityByIndex->position.z, playerStatus->position.x, playerStatus->position.z);
                D_802B6EEC = atan2(entityByIndex->position.x, entityByIndex->position.z, playerStatus->position.x, playerStatus->position.z);
                if (tempDistance > 4.0f) {
                    tempDistance -= 1.0f;
                }
                sin_cos_rad(D_802B6EEC * TAU / 360.0f, &sp10, &sp14);
                playerStatus->position.x = entityByIndex->position.x + (sp10 * tempDistance);
                playerStatus->position.z = entityByIndex->position.z - (sp14 * tempDistance);
                sin_cos_rad((D_802B6EEC - 91.0f) * TAU / 360.0f, &sp10, &sp14);
                D_802B6ED4 = sp10 * D_802B6EDC;
                D_802B6ED8 = -sp14 * D_802B6EDC;
            }
            D_802B6EE8 += 8.0f;

            playerStatus->position.y = D_802B6EF4 + sin_rad(clamp_angle(D_802B6EE8) * TAU / 360.0f) * 4.0f;
            gCameras->targetPos.z = playerStatus->position.z;
            gCameras->targetPos.x = playerStatus->position.x;
            gCameras->targetPos.y = playerStatus->position.y;
            if (playerStatus->framesOnGround != 0) {
                playerStatus->framesOnGround--;
                D_802B6EE4 += 2.0f;
                if (D_802B6EE4 >= 45.0f) {
                    D_802B6EE4 = 45.0f;
                }
                playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
                break;
            }
            playerStatus->fallState++;
            playerStatus->framesOnGround = 30;
            phys_adjust_cam_on_landing();
            break;
        case 1:
            D_802B6EE4 += 2.0f;
            if (D_802B6EE4 >= 45.0f) {
                D_802B6EE4 = 45.0f;
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            D_802B6EE0 += 2.0f;
            if (D_802B6EE0 > 45.0f) {
                D_802B6EE0 = 45.0f;
            }

            tempY = sin_rad(D_802B6EE0 * TAU / 360.0f) * 4.0f;
            playerStatus->position.y += tempY;
            gCameras->targetPos.x = playerStatus->position.x;
            gCameras->targetPos.y = playerStatus->position.y;
            gCameras->targetPos.z = playerStatus->position.z;
            tempDistance = fabsf(dist2D(D_802BCE34, D_802BCE32, playerStatus->position.x, playerStatus->position.z));
            if (tempDistance > 40.0f) {
                if (D_802BCE30 + 30 < playerStatus->position.y) {
                    playerStatus->fallState++;
                    sp18 = atan2(playerStatus->position.x, playerStatus->position.z, D_802BCE34, D_802BCE32);
                    sin_cos_rad(sp18 * TAU / 360.0f, &sp10, &sp14);
                    playerStatus->framesOnGround = 64;
                    D_802B6EEC = sp18;
                    D_802B6ED4 = (sp10 * tempDistance) * 0.015625;
                    D_802B6ED8 = (-sp14 * tempDistance) * 0.015625;
                }
                break;
            }
            if (playerStatus->framesOnGround == 0) {
                playerStatus->fallState = 0xA;
                playerStatus->framesOnGround = 20;
            } else {
                playerStatus->framesOnGround--;
            }
            break;
        case 2:
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            if (playerStatus->framesOnGround != 0) {
                playerStatus->framesOnGround--;
                if (D_802B6EE0-- < 0.0f) {
                    D_802B6EE0 = 0.0f;
                }
                tempY = 2.0f * sin_rad(D_802B6EE0 * TAU / 360.0f);
                playerStatus->position.x += D_802B6ED4;
                playerStatus->position.y += tempY;
                playerStatus->position.z += D_802B6ED8;
            } else {
                playerStatus->fallState = 0xB;
            }
            gCameras->targetPos.x = playerStatus->position.x;
            gCameras->targetPos.y = playerStatus->position.y;
            gCameras->targetPos.z = playerStatus->position.z;
            break;
        case 7:
            if (++D_802B6EE4 >= 45.0f) {
                D_802B6EE4 = 45.0f;
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            D_802B6EE0 += 2.0f;
            if (D_802B6EE0 > 45.0f) {
                D_802B6EE0 = 45.0f;
            }
            tempY = sin_rad(D_802B6EE0 * TAU / 360.0f) * 3.0f;
            playerStatus->position.y += tempY;
            if (playerStatus->framesOnGround != 0) {
                playerStatus->framesOnGround--;
                break;
            }
        case 8:
            enable_player_static_collisions();
            enable_player_input();
            playerStatus->flags &= ~0x100000;
            playerStatus->flags |= 0x800000;
            start_falling();
            enable_partner_ai();
            gOverrideFlags &= ~0x40;
            break;
    }
}
