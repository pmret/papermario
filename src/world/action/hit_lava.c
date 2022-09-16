#include "common.h"
#include "effects.h"

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

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags |= (PS_FLAGS_800000 | PS_FLAGS_FLYING);
        playerStatus->animFlags |= PA_FLAGS_4;
        playerStatus->flags |= PS_FLAGS_800;
        if (playerStatus->hazardType == HAZARD_TYPE_LAVA) {
            playerStatus->actionSubstate = SUBSTATE_DELAY_INIT_SINK;
            playerStatus->currentStateTime = 2;
        } else {
            playerStatus->actionSubstate = SUBSTATE_INIT;
        }
        InitialPosY = playerStatus->position.y;
        playerStatus->currentSpeed = 0.0f;
        LaunchVelocity = 0.0f;

        gCameras[CAM_DEFAULT].moveFlags |= (CAMERA_MOVE_FLAGS_1 | CAMERA_MOVE_FLAGS_2);
        LaunchInterpPhase = 90.0f;
        subtract_hp(1);
        open_status_menu_long();
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
        sfx_play_sound_at_player(SOUND_E8, 0);
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_DELAY_INIT:
            if (--playerStatus->currentStateTime == -1) {
                playerStatus->actionSubstate = SUBSTATE_INIT;
            }
            break;
        case SUBSTATE_DELAY_INIT_SINK:
            if (--playerStatus->currentStateTime == -1) {
                playerStatus->actionSubstate = SUBSTATE_INIT;
            }
            playerStatus->position.y -= 4.0f;
            break;
        case SUBSTATE_INIT:
            if (playerStatus->hazardType == HAZARD_TYPE_LAVA) {
                fx_smoke_burst(0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 1.0f, 40);
            }
            suggest_player_anim_setUnkFlag(ANIM_Mario_80002);
            playerStatus->gravityIntegrator[1] = 0.0f;
            playerStatus->timeInAir = 0;
            playerStatus->unk_C2 = 0;
            playerStatus->actionSubstate = SUBSTATE_LAUNCH;
            playerStatus->currentStateTime = 1;
            playerStatus->gravityIntegrator[0] = 20.0f;
            playerStatus->gravityIntegrator[2] = 250.0f;
            playerStatus->gravityIntegrator[3] = InitialPosY;
            playerStatus->jumpFromPos.x = playerStatus->position.x;
            playerStatus->jumpFromPos.z = playerStatus->position.z;
            playerStatus->jumpFromHeight = playerStatus->position.y;
            playerStatus->flags |= PS_FLAGS_JUMPING;
            break;
        case SUBSTATE_DELAY_LAUNCH:
            if (--playerStatus->currentStateTime <= 0) {
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_LAUNCH:
            if (playerStatus->hazardType == HAZARD_TYPE_LAVA && (playerStatus->timeInAir % 2) == 0) {
                fx_smoke_burst(0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 0.7f, 18);
            }
            if (playerStatus->position.y < playerStatus->gravityIntegrator[3] + playerStatus->gravityIntegrator[2]) {
                sin_cos_rad(DEG_TO_RAD(LaunchInterpPhase), &dx, &dy);
                LaunchVelocity = sin_rad(DEG_TO_RAD(LaunchInterpPhase)) * 16.0f;
                if (LaunchVelocity < -1.0f) {
                    LaunchVelocity = -1.0f;
                }
                playerStatus->position.y += LaunchVelocity;
                LaunchInterpPhase += 3.0f;
                if (LaunchInterpPhase > 180.0f) {
                    LaunchInterpPhase = 180.0f;
                    playerStatus->actionSubstate++;
                }
            } else {
                playerStatus->position.y = playerStatus->gravityIntegrator[3] + playerStatus->gravityIntegrator[2];
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_END_LAUNCH:
            if (playerStatus->hazardType == HAZARD_TYPE_LAVA && (playerStatus->timeInAir % 2) == 0) {
                fx_smoke_burst(0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 0.7f, 18);
            }
            if (get_lava_reset_pos(&resetPosX, &resetPosY, &resetPosZ) == 0) {
                resetPosX = playerStatus->position.x;
                resetPosZ = playerStatus->position.z;
            }
            playerStatus->lastGoodPosition.x = resetPosX;
            playerStatus->lastGoodPosition.z = resetPosZ;
            playerStatus->jumpApexHeight = playerStatus->position.y;
            LOAD_INTEGRATOR_FALL(playerStatus->gravityIntegrator);
            playerStatus->actionSubstate++;
            break;
        case SUBSTATE_RETURN_INIT:
            ReturnAngle = atan2(playerStatus->position.x, playerStatus->position.z, playerStatus->lastGoodPosition.x, playerStatus->lastGoodPosition.z);
            playerStatus->currentSpeed = get_xz_dist_to_player(playerStatus->lastGoodPosition.x, playerStatus->lastGoodPosition.z) / 18.0f;
            playerStatus->actionSubstate++;
            break;
        case SUBSTATE_RETURN_MOTION:
            ReturnAngle = atan2(playerStatus->position.x, playerStatus->position.z, playerStatus->lastGoodPosition.x, playerStatus->lastGoodPosition.z);
            returnRadians = DEG_TO_RAD(ReturnAngle);
            // update motion along x axis
            componentSpeed = playerStatus->currentSpeed * sin_rad(returnRadians);
            playerStatus->position.x += componentSpeed;
            completeAxes = 0;
            if (componentSpeed >= 0.0f) {
                if (playerStatus->lastGoodPosition.x <= playerStatus->position.x) {
                    playerStatus->position.x = playerStatus->lastGoodPosition.x;
                    completeAxes++;
                }
            } else {
                if (playerStatus->position.x <= playerStatus->lastGoodPosition.x) {
                    playerStatus->position.x = playerStatus->lastGoodPosition.x;
                    completeAxes++;
                }
            }
            // update motion along z axis
            componentSpeed = playerStatus->currentSpeed * cos_rad(returnRadians);
            playerStatus->position.z -= componentSpeed;
            if (componentSpeed >= 0.0f) {
                if (playerStatus->position.z <= playerStatus->lastGoodPosition.z) {
                    playerStatus->position.z = playerStatus->lastGoodPosition.z;
                    completeAxes++;
                }
            } else {
                if (playerStatus->lastGoodPosition.z <= playerStatus->position.z) {
                    playerStatus->position.z = playerStatus->lastGoodPosition.z;
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
                fx_smoke_burst(0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 0.7f, 18);
            }
            playerStatus->position.y = player_check_collision_below(func_800E34D8(), &completeAxes);
            if (completeAxes >= 0) {
                exec_ShakeCamX(0, 2, 1, 0.8f);
                start_rumble(256, 50);
                phys_adjust_cam_on_landing();
                gCameras[CAM_DEFAULT].moveFlags &= ~CAMERA_MOVE_FLAGS_2;
                sfx_play_sound_at_player(SOUND_3FB, 0);
                suggest_player_anim_setUnkFlag(ANIM_Mario_8001A);
                playerStatus->flags &= ~PS_FLAGS_800;
                playerStatus->flags &= ~PS_FLAGS_FLYING;
                playerStatus->hazardType = HAZARD_TYPE_NONE;
                playerStatus->gravityIntegrator[0] = 6.0f;
                playerStatus->position.y += 6.0f;
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_BOUNCE:
            playerStatus->gravityIntegrator[0] -= 1.0;
            playerStatus->position.y = player_check_collision_below(playerStatus->gravityIntegrator[0], &completeAxes);
            if (completeAxes >= 0) {
                playerStatus->currentStateTime = 10;
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_DELAY_DONE:
            if (--playerStatus->currentStateTime <= 0) {
                set_action_state(ACTION_STATE_LAND);
                playerStatus->flags &= ~PS_FLAGS_800000;
                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            }
            break;
    }
    if (playerStatus->actionSubstate < SUBSTATE_BOUNCE) {
        playerStatus->timeInAir++;
    }
}
