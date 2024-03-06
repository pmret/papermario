#include "common.h"
#include "sprite/player.h"

enum {
    SUBSTATE_FLYING     = 0,
    SUBSTATE_FALLING    = 1
};

void action_update_hit_fire(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 dx, dy;
    f32 speed;

    static f32 ReturnAngle;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;

        playerStatus->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
        playerStatus->flags |= (PS_FLAG_HIT_FIRE | PS_FLAG_FLYING);

        suggest_player_anim_always_forward(ANIM_Mario1_TouchedFire);

        playerStatus->actionSubstate = SUBSTATE_FLYING;
        playerStatus->gravityIntegrator[0] = 18.3473f;
        playerStatus->gravityIntegrator[1] = -3.738f;
        playerStatus->gravityIntegrator[2] = 0.8059f;
        playerStatus->gravityIntegrator[3] = -0.0987f;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
        ReturnAngle = atan2(playerStatus->pos.x, playerStatus->pos.z, playerStatus->lastGoodPos.x, playerStatus->lastGoodPos.z);
        playerStatus->curSpeed = get_xz_dist_to_player(playerStatus->lastGoodPos.x, playerStatus->lastGoodPos.z) / 18.0f;
        subtract_hp(1);
        open_status_bar_slowly();
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
    }

    sin_cos_rad(DEG_TO_RAD(ReturnAngle), &dx, &dy);
    speed = playerStatus->curSpeed;

    if (playerStatus->flags & PS_FLAG_ENTERING_BATTLE) {
        speed *= 0.5;
    }

    playerStatus->pos.x += speed * dx;
    playerStatus->pos.z -= speed * dy;

    if (playerStatus->actionSubstate == SUBSTATE_FLYING) {
        integrate_gravity();
        playerStatus->pos.y += playerStatus->gravityIntegrator[0];
        if (playerStatus->gravityIntegrator[0] < 0.0f) {
            playerStatus->actionSubstate = SUBSTATE_FALLING;
            playerStatus->flags |= PS_FLAG_FALLING;
        }
    } else {
        s32 colliderID;

        playerStatus->pos.y = player_check_collision_below(player_fall_distance(), &colliderID);
        if (colliderID > NO_COLLIDER) {
            colliderID = get_collider_flags(colliderID); //TODO surfaceType
            set_action_state(ACTION_STATE_LAND);
            playerStatus->blinkTimer = 60;
            playerStatus->hazardType = HAZARD_TYPE_NONE;
            playerStatus->flags &= ~PS_FLAG_HIT_FIRE;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
        }
    }
}
