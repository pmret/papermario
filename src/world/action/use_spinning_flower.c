#include "common.h"

BSS s32 SpinningFlower_EntityIndex;
BSS f32 D_802B6ED4;
BSS f32 D_802B6ED8;
BSS f32 D_802B6EDC;
BSS f32 D_802B6EE0;
BSS f32 D_802B6EE4;
BSS f32 D_802B6EE8;
BSS f32 SpinningFlower_AngleToCenter;
BSS f32 D_802B6EF0;
BSS f32 D_802B6EF4;

extern s16 D_802BCE30;
extern s16 D_802BCE32;
extern s16 D_802BCE34;

enum {
    SUBSTATE_ATTRACT    = 1,
    SUBSTATE_EJECT      = 2,
    SUBSTATE_SPIN_UP    = 3,
    SUBSTATE_ASCEND_A   = 4,
    SUBSTATE_ASCEND_B   = 5,
    SUBSTATE_BOOST      = 10,
    SUBSTATE_FINISH     = 11,
};

static s32 get_entity_below_spinning_flower(void) {
    f32 posX, posY, posZ, height;
    f32 hitRx, hitRz, hitDirX, hitDirZ;

    posX = gPlayerStatus.position.x;
    posZ = gPlayerStatus.position.z;
    height = gPlayerStatus.colliderHeight;
    posY = gPlayerStatus.position.y + (height * 0.5);
    return player_raycast_below_cam_relative(&gPlayerStatus, &posX, &posY, &posZ, &height, &hitRx, &hitRz, &hitDirX, &hitDirZ);
}

void action_update_use_spinning_flower(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Entity* entityByIndex;
    s32* TempPointer;
    s32 entityID;
    f32 inputMagnitude;
    f32 inputAngle;
    f32 dz;
    f32 dx;
    f32 ascentVelocity;
    f32 distToCenter;
    s8 switchCondition;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
        func_800EF300();
        playerStatus->actionSubstate = SUBSTATE_ATTRACT;
        playerStatus->currentStateTime = 0;
        D_802B6EE4 = 0.0f;
        D_802B6EE8 = 0.0f;
        D_802B6EF4 = playerStatus->position.y;
        D_802B6EDC = 3.0f;
        disable_player_static_collisions();
        disable_player_input();
        playerStatus->flags |= PS_FLAG_ROTATION_LOCKED;
        entityID = gCollisionStatus.currentFloor;

        TempPointer = &SpinningFlower_EntityIndex;
        if (entityID >= 0){
            if (!(entityID & COLLISION_WITH_ENTITY_BIT)) {
                SpinningFlower_EntityIndex = -1;
            } else {
                SpinningFlower_EntityIndex = entityID & 0x3FF;
            }
        } else {
            SpinningFlower_EntityIndex = -1;
        }
        if (!(playerStatus->animFlags & (PA_FLAG_USING_WATT | PA_FLAG_WATT_IN_HANDS))) {
            suggest_player_anim_allow_backward(ANIM_Mario1_Flail);
        }
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_ATTRACT:
            gOverrideFlags |= GLOBAL_OVERRIDES_40;
            D_802B6EE4 += 1.0f;
            if (D_802B6EE4 >= 20.0f) {
                D_802B6EE4 = 20.0f;
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            if (playerStatus->currentStateTime < 10) {
                playerStatus->currentStateTime++;
                D_802B6EF4++;
            }
            D_802B6EE8 += 8.0f;
            playerStatus->position.y = D_802B6EF4 + sin_rad(DEG_TO_RAD(clamp_angle(D_802B6EE8))) * 4.0f;
            if (SpinningFlower_EntityIndex >= 0) {
                entityByIndex = get_entity_by_index(SpinningFlower_EntityIndex);
                distToCenter = dist2D(entityByIndex->position.x, entityByIndex->position.z, playerStatus->position.x, playerStatus->position.z);
                SpinningFlower_AngleToCenter = atan2(entityByIndex->position.x, entityByIndex->position.z, playerStatus->position.x, playerStatus->position.z);
                if (distToCenter > 4.0f) {
                    distToCenter--;
                }
                sin_cos_rad(DEG_TO_RAD(SpinningFlower_AngleToCenter), &dx, &dz);
                playerStatus->position.x = entityByIndex->position.x + (dx * distToCenter);
                playerStatus->position.z = entityByIndex->position.z - (dz * distToCenter);
                sin_cos_rad(DEG_TO_RAD(SpinningFlower_AngleToCenter - 91.0f), &dx, &dz);
                D_802B6ED4 =  dx * D_802B6EDC;
                D_802B6ED8 = -dz * D_802B6EDC;
            }
            game_input_to_move_vector(&inputAngle, &inputMagnitude);
            if (inputMagnitude != 0.0f) {
                sin_cos_rad(DEG_TO_RAD(inputAngle), &dx, &dz);
                inputMagnitude *= 0.03125f;
                if (inputMagnitude < 0.1) {
                    inputMagnitude = 0.1f;
                }
                playerStatus->position.x += dx * inputMagnitude;
                playerStatus->position.z -= dz * inputMagnitude;
            }
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
            entityID = get_entity_below_spinning_flower();
            if (entityID < 0 || !(entityID & COLLISION_WITH_ENTITY_BIT)) {
                playerStatus->currentStateTime = 20;
                D_802B6EE8 = 0.0f;
                D_802B6EF4 = playerStatus->position.y;
                playerStatus->actionSubstate++;
                D_802B6EF0 = 1.6f;
                playerStatus->flags |= PS_FLAG_SCRIPTED_FALL;
            }
            if (gGameStatusPtr->pressedButtons[0] & BUTTON_Z &&
                !(playerStatus->animFlags & (PA_FLAG_USING_WATT | PA_FLAG_WATT_IN_HANDS))) {
                suggest_player_anim_always_forward(ANIM_Mario1_Jump);
                playerStatus->actionSubstate = SUBSTATE_SPIN_UP;
                playerStatus->currentStateTime = 30;
                D_802B6EE0 = 0.0f;
                gCollisionStatus.currentFloor = NO_COLLIDER;
                exec_entity_commandlist(get_entity_by_index(SpinningFlower_EntityIndex));
            }
            break;
        case SUBSTATE_EJECT:
            gOverrideFlags |= GLOBAL_OVERRIDES_40;
            if (--D_802B6EE4 < 0.0f) {
                D_802B6EE4 = 0.0f;
                playerStatus->flags &= ~PS_FLAG_ROTATION_LOCKED;
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            sin_cos_rad(DEG_TO_RAD(SpinningFlower_AngleToCenter - 60.0f), &dx, &dz);
            D_802B6EDC += 0.2;
            D_802B6EF0 -= 0.72;
            D_802B6ED4 =  dx * D_802B6EDC;
            D_802B6ED8 = -dz * D_802B6EDC;
            playerStatus->position.x += D_802B6ED4;
            playerStatus->position.z += D_802B6ED8;
            collision_lava_reset_check_additional_overlaps();
            playerStatus->position.y = player_check_collision_below(D_802B6EF0, &entityID);
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
            if (entityID >= 0) {
                playerStatus->flags &= ~PS_FLAG_ROTATION_LOCKED;
                enable_player_input();
                enable_player_static_collisions();
                set_action_state(ACTION_STATE_LAND);
                enable_partner_ai();
                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                return;
            }
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_SPIN_UP:
            if (SpinningFlower_EntityIndex >= 0) {
                entityByIndex = get_entity_by_index(SpinningFlower_EntityIndex);
                distToCenter = dist2D(entityByIndex->position.x, entityByIndex->position.z, playerStatus->position.x, playerStatus->position.z);
                SpinningFlower_AngleToCenter = atan2(entityByIndex->position.x, entityByIndex->position.z, playerStatus->position.x, playerStatus->position.z);
                if (distToCenter > 4.0f) {
                    distToCenter -= 1.0f;
                }
                sin_cos_rad(DEG_TO_RAD(SpinningFlower_AngleToCenter), &dx, &dz);
                playerStatus->position.x = entityByIndex->position.x + (dx * distToCenter);
                playerStatus->position.z = entityByIndex->position.z - (dz * distToCenter);
                sin_cos_rad(DEG_TO_RAD(SpinningFlower_AngleToCenter - 91.0f), &dx, &dz);
                D_802B6ED4 =  dx * D_802B6EDC;
                D_802B6ED8 = -dz * D_802B6EDC;
            }
            D_802B6EE8 += 8.0f;

            playerStatus->position.y = D_802B6EF4 + sin_rad(DEG_TO_RAD(clamp_angle(D_802B6EE8))) * 4.0f;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
            if (playerStatus->currentStateTime != 0) {
                playerStatus->currentStateTime--;
                D_802B6EE4 += 2.0f;
                if (D_802B6EE4 >= 45.0f) {
                    D_802B6EE4 = 45.0f;
                }
                playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
                break;
            }
            playerStatus->actionSubstate++; // SUBSTATE_ASCEND_A
            playerStatus->currentStateTime = 30;
            phys_adjust_cam_on_landing();
            break;
        case SUBSTATE_ASCEND_A:
            D_802B6EE4 += 2.0f;
            if (D_802B6EE4 >= 45.0f) {
                D_802B6EE4 = 45.0f;
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            D_802B6EE0 += 2.0f;
            if (D_802B6EE0 > 45.0f) {
                D_802B6EE0 = 45.0f;
            }

            ascentVelocity = sin_rad(DEG_TO_RAD(D_802B6EE0)) * 4.0f;
            playerStatus->position.y += ascentVelocity;
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
            distToCenter = fabsf(dist2D(D_802BCE34, D_802BCE32, playerStatus->position.x, playerStatus->position.z));
            if (distToCenter > 40.0f) {
                if (D_802BCE30 + 30 < playerStatus->position.y) {
                    playerStatus->actionSubstate++; // SUBSTATE_ASCEND_B
                    inputAngle = atan2(playerStatus->position.x, playerStatus->position.z, D_802BCE34, D_802BCE32);
                    sin_cos_rad(DEG_TO_RAD(inputAngle), &dx, &dz);
                    playerStatus->currentStateTime = 64;
                    SpinningFlower_AngleToCenter = inputAngle;
                    D_802B6ED4 = (dx * distToCenter) * 0.015625;
                    D_802B6ED8 = (-dz * distToCenter) * 0.015625;
                }
                break;
            }
            if (playerStatus->currentStateTime == 0) {
                playerStatus->actionSubstate = SUBSTATE_BOOST;
                playerStatus->currentStateTime = 20;
            } else {
                playerStatus->currentStateTime--;
            }
            break;
        case SUBSTATE_ASCEND_B:
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            if (playerStatus->currentStateTime != 0) {
                playerStatus->currentStateTime--;
                if (D_802B6EE0-- < 0.0f) {
                    D_802B6EE0 = 0.0f;
                }
                ascentVelocity = 2.0f * sin_rad(DEG_TO_RAD(D_802B6EE0));
                playerStatus->position.x += D_802B6ED4;
                playerStatus->position.y += ascentVelocity;
                playerStatus->position.z += D_802B6ED8;
            } else {
                playerStatus->actionSubstate = SUBSTATE_FINISH;
            }
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
            break;
        case SUBSTATE_BOOST:
            D_802B6EE4 += 1.0f;
            if (D_802B6EE4 >= 45.0f) {
                D_802B6EE4 = 45.0f;
            }
            playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + D_802B6EE4);
            D_802B6EE0 += 2.0f;
            if (D_802B6EE0 > 45.0f) {
                D_802B6EE0 = 45.0f;
            }
            ascentVelocity = sin_rad(DEG_TO_RAD(D_802B6EE0)) * 3.0f;
            playerStatus->position.y += ascentVelocity;
            if (playerStatus->currentStateTime != 0) {
                playerStatus->currentStateTime--;
                break;
            }
        case SUBSTATE_FINISH:
            enable_player_static_collisions();
            enable_player_input();
            playerStatus->flags &= ~PS_FLAG_ROTATION_LOCKED;
            playerStatus->flags |= PS_FLAG_SCRIPTED_FALL;
            start_falling();
            enable_partner_ai();
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            break;
    }
}

MATCHING_BSS(0x100);
