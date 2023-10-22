#include "common.h"
#include "effects.h"
#include "sprite/player.h"

enum {
    SUBSTATE_INIT               = 0,
    SUBSTATE_DELAY_LAUNCH       = 1,
    SUBSTATE_LAUNCH             = 2,
    SUBSTATE_END_LAUNCH         = 3,
    SUBSTATE_RETURN_INIT        = 4,
    SUBSTATE_RETURN_MOTION      = 5,
    SUBSTATE_HOVER               = 6,
    SUBSTATE_BOUNCE             = 7,
    SUBSTATE_DELAY_DONE         = 8,
    SUBSTATE_DELAY_INIT_SINK    = 20,
    SUBSTATE_DELAY_INIT         = 21
};

void action_update_hit_lava(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 resetPosX, resetPosY, resetPosZ;
    f32 returnRadians;
    f32 dx, dy;
    f32 componentSpeed;
    s32 completeAxes; // number of axes along which the 'return motion' is complete

    static f32 LaunchVelocity;
    static f32 LaunchInterpPhase; // used to interp launch velocity
    static f32 ReturnAngle;
    static f32 InitialPosY;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->flags |= (PS_FLAG_SCRIPTED_FALL | PS_FLAG_FLYING);
        playerStatus->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
        playerStatus->flags |= PS_FLAG_HIT_FIRE;
        if (playerStatus->hazardType == HAZARD_TYPE_LAVA) {
            playerStatus->actionSubstate = SUBSTATE_DELAY_INIT_SINK;
            playerStatus->curStateTime = 2;
        } else {
            playerStatus->actionSubstate = SUBSTATE_INIT;
        }
        InitialPosY = playerStatus->pos.y;
        playerStatus->curSpeed = 0.0f;
        LaunchVelocity = 0.0f;

        gCameras[CAM_DEFAULT].moveFlags |= (CAMERA_MOVE_IGNORE_PLAYER_Y | CAMERA_MOVE_NO_INTERP_Y);
        LaunchInterpPhase = 90.0f;
        subtract_hp(1);
        open_status_bar_slowly();
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
        sfx_play_sound_at_player(SOUND_TOUCH_LAVA, SOUND_SPACE_DEFAULT);
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_DELAY_INIT:
            if (--playerStatus->curStateTime == -1) {
                playerStatus->actionSubstate = SUBSTATE_INIT;
            }
            break;
        case SUBSTATE_DELAY_INIT_SINK:
            if (--playerStatus->curStateTime == -1) {
                playerStatus->actionSubstate = SUBSTATE_INIT;
            }
            playerStatus->pos.y -= 4.0f;
            break;
        case SUBSTATE_INIT:
            if (playerStatus->hazardType == HAZARD_TYPE_LAVA) {
                fx_smoke_burst(0, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z, 1.0f, 40);
            }
            suggest_player_anim_always_forward(ANIM_MarioW2_TouchedLava);
            playerStatus->gravityIntegrator[1] = 0.0f;
            playerStatus->timeInAir = 0;
            playerStatus->peakJumpTime = 0;
            playerStatus->actionSubstate = SUBSTATE_LAUNCH;
            playerStatus->curStateTime = 1;
            playerStatus->gravityIntegrator[0] = 20.0f;
            playerStatus->gravityIntegrator[2] = 250.0f;
            playerStatus->gravityIntegrator[3] = InitialPosY;
            playerStatus->jumpFromPos.x = playerStatus->pos.x;
            playerStatus->jumpFromPos.z = playerStatus->pos.z;
            playerStatus->jumpFromHeight = playerStatus->pos.y;
            playerStatus->flags |= PS_FLAG_JUMPING;
            break;
        case SUBSTATE_DELAY_LAUNCH:
            if (--playerStatus->curStateTime <= 0) {
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_LAUNCH:
            if (playerStatus->hazardType == HAZARD_TYPE_LAVA && (playerStatus->timeInAir % 2) == 0) {
                fx_smoke_burst(0, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z, 0.7f, 18);
            }
            if (playerStatus->pos.y < playerStatus->gravityIntegrator[3] + playerStatus->gravityIntegrator[2]) {
                sin_cos_rad(DEG_TO_RAD(LaunchInterpPhase), &dx, &dy);
                LaunchVelocity = sin_rad(DEG_TO_RAD(LaunchInterpPhase)) * 16.0f;
                if (LaunchVelocity < -1.0f) {
                    LaunchVelocity = -1.0f;
                }
                playerStatus->pos.y += LaunchVelocity;
                LaunchInterpPhase += 3.0f;
                if (LaunchInterpPhase > 180.0f) {
                    LaunchInterpPhase = 180.0f;
                    playerStatus->actionSubstate++;
                }
            } else {
                playerStatus->pos.y = playerStatus->gravityIntegrator[3] + playerStatus->gravityIntegrator[2];
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_END_LAUNCH:
            if (playerStatus->hazardType == HAZARD_TYPE_LAVA && (playerStatus->timeInAir % 2) == 0) {
                fx_smoke_burst(0, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z, 0.7f, 18);
            }
            if (get_lava_reset_pos(&resetPosX, &resetPosY, &resetPosZ) == 0) {
                resetPosX = playerStatus->pos.x;
                resetPosZ = playerStatus->pos.z;
            }
            playerStatus->lastGoodPos.x = resetPosX;
            playerStatus->lastGoodPos.z = resetPosZ;
            playerStatus->jumpApexHeight = playerStatus->pos.y;
            LOAD_INTEGRATOR_FALL(playerStatus->gravityIntegrator);
            playerStatus->actionSubstate++;
            break;
        case SUBSTATE_RETURN_INIT:
            ReturnAngle = atan2(playerStatus->pos.x, playerStatus->pos.z, playerStatus->lastGoodPos.x, playerStatus->lastGoodPos.z);
            playerStatus->curSpeed = get_xz_dist_to_player(playerStatus->lastGoodPos.x, playerStatus->lastGoodPos.z) / 18.0f;
            playerStatus->actionSubstate++;
            break;
        case SUBSTATE_RETURN_MOTION:
            ReturnAngle = atan2(playerStatus->pos.x, playerStatus->pos.z, playerStatus->lastGoodPos.x, playerStatus->lastGoodPos.z);
            returnRadians = DEG_TO_RAD(ReturnAngle);
            // update motion along x axis
            componentSpeed = playerStatus->curSpeed * sin_rad(returnRadians);
            playerStatus->pos.x += componentSpeed;
            completeAxes = 0;
            if (componentSpeed >= 0.0f) {
                if (playerStatus->lastGoodPos.x <= playerStatus->pos.x) {
                    playerStatus->pos.x = playerStatus->lastGoodPos.x;
                    completeAxes++;
                }
            } else {
                if (playerStatus->pos.x <= playerStatus->lastGoodPos.x) {
                    playerStatus->pos.x = playerStatus->lastGoodPos.x;
                    completeAxes++;
                }
            }
            // update motion along z axis
            componentSpeed = playerStatus->curSpeed * cos_rad(returnRadians);
            playerStatus->pos.z -= componentSpeed;
            if (componentSpeed >= 0.0f) {
                if (playerStatus->pos.z <= playerStatus->lastGoodPos.z) {
                    playerStatus->pos.z = playerStatus->lastGoodPos.z;
                    completeAxes++;
                }
            } else {
                if (playerStatus->lastGoodPos.z <= playerStatus->pos.z) {
                    playerStatus->pos.z = playerStatus->lastGoodPos.z;
                    completeAxes++;
                }
            }
            // if both axes are done, continue to next substate
            if (completeAxes == 2) {
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_HOVER:
            if (playerStatus->hazardType == HAZARD_TYPE_LAVA && (playerStatus->timeInAir % 2) == 0) {
                fx_smoke_burst(0, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z, 0.7f, 18);
            }
            playerStatus->pos.y = player_check_collision_below(player_fall_distance(), &completeAxes);
            if (completeAxes >= 0) {
                exec_ShakeCamX(0, 2, 1, 0.8f);
                start_rumble(256, 50);
                phys_adjust_cam_on_landing();
                gCameras[CAM_DEFAULT].moveFlags &= ~CAMERA_MOVE_NO_INTERP_Y;
                sfx_play_sound_at_player(SOUND_PLAYER_COLLAPSE, SOUND_SPACE_DEFAULT);
                suggest_player_anim_always_forward(ANIM_MarioW2_Thrown);
                playerStatus->flags &= ~PS_FLAG_HIT_FIRE;
                playerStatus->flags &= ~PS_FLAG_FLYING;
                playerStatus->hazardType = HAZARD_TYPE_NONE;
                playerStatus->gravityIntegrator[0] = 6.0f;
                playerStatus->pos.y += 6.0f;
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_BOUNCE:
            playerStatus->gravityIntegrator[0] -= 1.0;
            playerStatus->pos.y = player_check_collision_below(playerStatus->gravityIntegrator[0], &completeAxes);
            if (completeAxes >= 0) {
                playerStatus->curStateTime = 10;
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_DELAY_DONE:
            if (--playerStatus->curStateTime <= 0) {
                set_action_state(ACTION_STATE_LAND);
                playerStatus->flags &= ~PS_FLAG_SCRIPTED_FALL;
                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            }
            break;
    }
    if (playerStatus->actionSubstate < SUBSTATE_BOUNCE) {
        playerStatus->timeInAir++;
    }
}
