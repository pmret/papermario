#include "common.h"

extern f32 Munchlesia_LaunchVelocity;
extern f32 Munchlesia_LateralVelocity;
extern f32 Munchlesia_LaunchAccel;
extern f32 Munchlesia_LaunchYaw;
extern s32 D_802B62E0;

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

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = SUBSTATE_INIT;
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
        disable_player_static_collisions();
        disable_player_input();
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_INIT:
            suggest_player_anim_clearUnkFlag(ANIM_Mario_1002E);
            D_802B62E0 = 32;
            Munchlesia_LaunchVelocity = 16.0f;
            Munchlesia_LateralVelocity = 4.0f;
            Munchlesia_LaunchAccel = 1.0f;
            Munchlesia_LateralVelocity = 1.875f;
            playerStatus->actionSubstate++; // SUBSTATE_EJECT
            Munchlesia_LaunchYaw = playerStatus->targetYaw;
            break;
        case SUBSTATE_EJECT:
            playerStatus->position.y += Munchlesia_LaunchVelocity;
            Munchlesia_LaunchVelocity -= Munchlesia_LaunchAccel;
            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, Munchlesia_LateralVelocity, Munchlesia_LaunchYaw);
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
            if (Munchlesia_LaunchVelocity <= 0.0f) {
                playerStatus->actionSubstate++; // SUBSTATE_FALL
            }
            break;
        case SUBSTATE_FALL:
            playerStatus->position.y += Munchlesia_LaunchVelocity;
            Munchlesia_LaunchVelocity -= Munchlesia_LaunchAccel;
            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, Munchlesia_LateralVelocity, Munchlesia_LaunchYaw);
            gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
            gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
            gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
            hitPosY = player_check_collision_below(Munchlesia_LaunchVelocity, &colliderID);
            if (colliderID >= 0) {
                sfx_play_sound_at_player(SOUND_162, 0);
                suggest_player_anim_setUnkFlag(ANIM_Mario_80003);
                playerStatus->position.y = hitPosY;
                D_802B62E0 = 10;
                playerStatus->actionSubstate++; // SUBSTATE_CRASH
            }
            break;
        case SUBSTATE_CRASH:
            if (playerStatus->animNotifyValue != 0) {
                suggest_player_anim_setUnkFlag(ANIM_Mario_GetUp);
                playerStatus->actionSubstate = SUBSTATE_GET_UP;
                playerStatus->currentStateTime = 15;
                break;
            }
            break;
        case SUBSTATE_GET_UP:
            if (playerStatus->currentStateTime != 0) {
                playerStatus->currentStateTime--;
                break;
            }
            enable_player_static_collisions();
            enable_player_input();
            set_action_state(ACTION_STATE_IDLE);
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            break;
    }
}
