#include "common.h"
#include "sprite/player.h"

enum {
    SUBSTATE_INIT   = 0,
    SUBSTATE_DONE   = 1,
};

void action_update_peach_land(void);
void action_update_peach_step_down_land(void);

void action_update_land(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;
    s32 jumpInputCheck;
    AnimID anim;

    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        action_update_peach_land();
        return;
    }

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(
            PS_FLAG_ACTION_STATE_CHANGED |
            PS_FLAG_SCRIPTED_FALL |
            PS_FLAG_ARMS_RAISED |
            PS_FLAG_AIRBORNE
        );
        playerStatus->actionSubstate = SUBSTATE_INIT;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->landPos.x = playerStatus->pos.x;
        playerStatus->landPos.z = playerStatus->pos.z;

        if (playerStatus->animFlags & PA_FLAG_8BIT_MARIO) {
            anim = ANIM_MarioW3_8bit_Still;
        } else if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
            anim = ANIM_Mario1_Land;
        } else {
            anim = ANIM_MarioW1_LandWatt;
        }

        suggest_player_anim_allow_backward(anim);
        sfx_play_sound_at_player(SOUND_161 | SOUND_ID_STOP, SOUND_SPACE_MODE_0);
        sfx_play_sound_at_player(SOUND_SOFT_LAND, SOUND_SPACE_MODE_0);

        if (!(collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }

        collisionStatus->lastTouchedFloor = -1;
        playerStatus->animFlags &= ~PA_FLAG_INTERRUPT_SPIN;
        camera->moveFlags &= ~CAMERA_MOVE_FLAG_4;
    }
    playerStatus->actionSubstate++; // SUBSTATE_DONE
    playerStatus->curSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);
    jumpInputCheck = check_input_jump();

    if (jumpInputCheck != 0 || jumpInputCheck < playerStatus->actionSubstate) {
        if (inputMoveMagnitude == 0.0f) {
            set_action_state(ACTION_STATE_IDLE);
            return;
        }
        if (inputMoveMagnitude != 0.0f) {
            playerStatus->targetYaw = inputMoveAngle;
        }
        update_locomotion_state();
    }
}

void action_update_step_down_land(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;

    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        action_update_peach_step_down_land();
        return;
    }

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
         playerStatus->flags &= ~(
            PS_FLAG_ACTION_STATE_CHANGED |
            PS_FLAG_SCRIPTED_FALL |
            PS_FLAG_ARMS_RAISED |
            PS_FLAG_AIRBORNE
        );
        playerStatus->actionSubstate = SUBSTATE_INIT;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->landPos.x = playerStatus->pos.x;
        playerStatus->landPos.z = playerStatus->pos.z;

        if (!(collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }

        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->actionSubstate++; // SUBSTATE_DONE
    playerStatus->curSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);
    check_input_jump();

    if (inputMoveMagnitude != 0.0f) {
        playerStatus->targetYaw = inputMoveAngle;
    }

    update_locomotion_state();
}

void action_update_peach_land(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = SUBSTATE_INIT;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->flags &= ~PS_FLAG_AIRBORNE;
        playerStatus->landPos.x = playerStatus->pos.x;
        playerStatus->landPos.z = playerStatus->pos.z;

        sfx_play_sound_at_player(SOUND_SOFT_LAND, SOUND_SPACE_MODE_0);

        if (!(collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }

        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->actionSubstate++; // SUBSTATE_DONE
    playerStatus->curSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);

    if (inputMoveMagnitude == 0.0f) {
        set_action_state(ACTION_STATE_IDLE);
    } else {
        if (inputMoveMagnitude != 0.0f) {
            playerStatus->targetYaw = inputMoveAngle;
        }

        if (sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) > 55.0f) {
            set_action_state(ACTION_STATE_RUN);
        } else {
            set_action_state(ACTION_STATE_WALK);
        }
    }
}

void action_update_peach_step_down_land(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = SUBSTATE_INIT;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->flags &= ~PS_FLAG_AIRBORNE;
        playerStatus->landPos.x = playerStatus->pos.x;
        playerStatus->landPos.z = playerStatus->pos.z;

        if (!(collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }
        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->actionSubstate++; // SUBSTATE_DONE
    playerStatus->curSpeed *= 0.6f;
    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);

    if (inputMoveMagnitude != 0.0f) {
        playerStatus->targetYaw = inputMoveAngle;
    }

    if (sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) > 55.0f) {
        set_action_state(ACTION_STATE_RUN);
    } else {
        set_action_state(ACTION_STATE_WALK);
    }
}
