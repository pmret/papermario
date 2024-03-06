#include "common.h"
#include "sprite/player.h"

BSS f32 Munchlesia_LaunchVelocity;
BSS f32 Munchlesia_LateralVelocity;
BSS f32 Munchlesia_LaunchAccel;
BSS f32 Munchlesia_LaunchYaw;
BSS s32 D_802B62E0;

enum {
    SUBSTATE_INIT       = 0,
    SUBSTATE_EJECT      = 1,
    SUBSTATE_FALL       = 2,
    SUBSTATE_CRASH      = 3,
    SUBSTATE_GET_UP     = 5,
};

void action_update_use_munchlesia(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 colliderID;
    f32 hitPosY;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = SUBSTATE_INIT;
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
        disable_player_static_collisions();
        disable_player_input();
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_INIT:
            suggest_player_anim_allow_backward(ANIM_Mario1_FallBack);
            D_802B62E0 = 32;
            Munchlesia_LaunchVelocity = 16.0f;
            Munchlesia_LateralVelocity = 4.0f;
            Munchlesia_LaunchAccel = 1.0f;
            Munchlesia_LateralVelocity = 1.875f;
            playerStatus->actionSubstate++; // SUBSTATE_EJECT
            Munchlesia_LaunchYaw = playerStatus->targetYaw;
            break;
        case SUBSTATE_EJECT:
            playerStatus->pos.y += Munchlesia_LaunchVelocity;
            Munchlesia_LaunchVelocity -= Munchlesia_LaunchAccel;
            add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, Munchlesia_LateralVelocity, Munchlesia_LaunchYaw);
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
            if (Munchlesia_LaunchVelocity <= 0.0f) {
                playerStatus->actionSubstate++; // SUBSTATE_FALL
            }
            break;
        case SUBSTATE_FALL:
            playerStatus->pos.y += Munchlesia_LaunchVelocity;
            Munchlesia_LaunchVelocity -= Munchlesia_LaunchAccel;
            add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, Munchlesia_LateralVelocity, Munchlesia_LaunchYaw);
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
            hitPosY = player_check_collision_below(Munchlesia_LaunchVelocity, &colliderID);
            if (colliderID > NO_COLLIDER) {
                sfx_play_sound_at_player(SOUND_TRIP, SOUND_SPACE_DEFAULT);
                suggest_player_anim_always_forward(ANIM_MarioW2_Collapse);
                playerStatus->pos.y = hitPosY;
                D_802B62E0 = 10;
                playerStatus->actionSubstate++; // SUBSTATE_CRASH
            }
            break;
        case SUBSTATE_CRASH:
            if (playerStatus->animNotifyValue != 0) {
                suggest_player_anim_always_forward(ANIM_Mario1_GetUp);
                playerStatus->actionSubstate = SUBSTATE_GET_UP;
                playerStatus->curStateTime = 15;
                break;
            }
            break;
        case SUBSTATE_GET_UP:
            if (playerStatus->curStateTime != 0) {
                playerStatus->curStateTime--;
                break;
            }
            enable_player_static_collisions();
            enable_player_input();
            set_action_state(ACTION_STATE_IDLE);
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            break;
    }
}
