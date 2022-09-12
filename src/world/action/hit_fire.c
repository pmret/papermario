#include "common.h"

extern f32 D_802B62B0;

void action_update_hit_fire(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sinTheta;
    f32 cosTheta;
    f32 speed;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_4;
        playerStatus->flags |= (PLAYER_STATUS_FLAGS_800 | PLAYER_STATUS_FLAGS_FLYING);
        suggest_player_anim_setUnkFlag(ANIM_Mario_Scared);
        playerStatus->actionSubstate = 0;
        playerStatus->gravityIntegrator[0] = 18.3473f;
        playerStatus->gravityIntegrator[1] = -3.738f;
        playerStatus->gravityIntegrator[2] = 0.8059f;
        playerStatus->gravityIntegrator[3] = -0.0987f;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
        D_802B62B0 = atan2(playerStatus->position.x, playerStatus->position.z, playerStatus->lastGoodPosition.x, playerStatus->lastGoodPosition.z);
        playerStatus->currentSpeed = get_xz_dist_to_player(playerStatus->lastGoodPosition.x, playerStatus->lastGoodPosition.z) / 18.0f;
        subtract_hp(1);
        open_status_menu_long();
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
    }

    sin_cos_rad(D_802B62B0 * TAU / 360.0f, &sinTheta, &cosTheta);
    speed = playerStatus->currentSpeed;

    if (playerStatus->flags & 0x40000) {
        speed *= 0.5;
    }

    playerStatus->position.x += speed * sinTheta;
    playerStatus->position.z -= speed * cosTheta;

    if (playerStatus->actionSubstate == 0) {
        integrate_gravity();
        playerStatus->position.y += playerStatus->gravityIntegrator[0];
        if (playerStatus->gravityIntegrator[0] < 0.0f) {
            playerStatus->actionSubstate = 1;
            playerStatus->flags |= 4;
        }
    } else {
        s32 colliderID;

        playerStatus->position.y = player_check_collision_below(func_800E34D8(), &colliderID);
        if (colliderID >= 0) {
            colliderID = get_collider_flags(colliderID); //TODO surfaceType
            set_action_state(ACTION_STATE_LAND);
            playerStatus->blinkTimer = 60;
            playerStatus->unk_BF = 0;
            playerStatus->flags &= ~0x800;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
        }
    }
}
