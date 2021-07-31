#include "common.h"

extern f32 D_802B6240; // bss? angle to lastGoodPosition

void func_802B6000_E287F0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 dx;
    f32 dy;
    f32 speed;

    if (playerStatus->flags & 0x80000000) {
        playerStatus->flags &= ~0x80000000;

        suggest_player_anim_setUnkFlag(0x10017);

        playerStatus->flags |= 8;
        playerStatus->fallState = 0;
        playerStatus->gravityIntegrator[0] = 18.3473f;
        playerStatus->gravityIntegrator[1] = -3.738f;
        playerStatus->gravityIntegrator[2] = 0.8059f;
        playerStatus->gravityIntegrator[3] = -0.0987f;

        gCameras[0].moveFlags |= 1;

        D_802B6240 = atan2(playerStatus->position.x, playerStatus->position.z, playerStatus->lastGoodPosition.x,
                           playerStatus->lastGoodPosition.z);
        playerStatus->currentSpeed = get_xz_dist_to_player(playerStatus->lastGoodPosition.x, playerStatus->lastGoodPosition.z) / 18.0f;
    }

    sin_cos_rad((D_802B6240 * TAU) / 360.0f, &dx, &dy);

    speed = playerStatus->currentSpeed;

    if (playerStatus->flags & 0x40000) {
        speed *= 0.5f;
    }

    playerStatus->position.x += speed * dx;
    playerStatus->position.z -= speed * dy;

    if (playerStatus->fallState == 0) {
        integrate_gravity();

        playerStatus->position.y += playerStatus->gravityIntegrator[0];

        if (playerStatus->gravityIntegrator[0] < 0.0f) {
            playerStatus->fallState = 1; // Now start checking for floor
            playerStatus->flags |= 4;
        }
    } else {
        s32 colliderID;

        playerStatus->position.y = player_check_collision_below(func_800E34D8(), &colliderID);

        if (colliderID >= 0) {
            colliderID = get_collider_type_by_id(colliderID); // what
            set_action_state(ACTION_STATE_LAND);
        }
    }
}
