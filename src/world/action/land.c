#include "common.h"

void func_802B62CC_E24BEC(void);
void func_802B644C_E24D6C(void);

void action_update_land(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;
    s32 jumpInputCheck;
    AnimID anim;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B62CC_E24BEC();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(
            PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED |
            PLAYER_STATUS_FLAGS_800000 |
            PLAYER_STATUS_FLAGS_80000 |
            PLAYER_STATUS_FLAGS_AIRBORNE
        );
        playerStatus->actionSubstate = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->landPos.x = playerStatus->position.x;
        playerStatus->landPos.z = playerStatus->position.z;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
            anim = ANIM_Mario_90002;
        } else if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT)) {
            anim = ANIM_Mario_10009;
        } else {
            anim = ANIM_Mario_6000B;
        }

        suggest_player_anim_clearUnkFlag(anim);
        sfx_play_sound_at_player(SOUND_8161, 0);
        sfx_play_sound_at_player(SOUND_SOFT_LAND, 0);

        if (!(collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }

        collisionStatus->lastTouchedFloor = -1;
        playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_40000;
        camera->moveFlags &= ~CAMERA_MOVE_FLAGS_4;
    }
    playerStatus->actionSubstate++;
    playerStatus->currentSpeed *= 0.6f;

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

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B644C_E24D6C();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
         playerStatus->flags &= ~(
            PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED |
            PLAYER_STATUS_FLAGS_800000 |
            PLAYER_STATUS_FLAGS_80000 |
            PLAYER_STATUS_FLAGS_AIRBORNE
        );
        playerStatus->actionSubstate = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->landPos.x = playerStatus->position.x;
        playerStatus->landPos.z = playerStatus->position.z;

        if (!(collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }

        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->actionSubstate++;
    playerStatus->currentSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);
    check_input_jump();

    if (inputMoveMagnitude != 0.0f) {
        playerStatus->targetYaw = inputMoveAngle;
    }

    update_locomotion_state();
}

void func_802B62CC_E24BEC(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_AIRBORNE;
        playerStatus->landPos.x = playerStatus->position.x;
        playerStatus->landPos.z = playerStatus->position.z;

        sfx_play_sound_at_player(SOUND_SOFT_LAND, 0);

        if (!(collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }

        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->actionSubstate++;
    playerStatus->currentSpeed *= 0.6f;

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

void func_802B644C_E24D6C(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_AIRBORNE;
        playerStatus->landPos.x = playerStatus->position.x;
        playerStatus->landPos.z = playerStatus->position.z;

        if (!(collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }
        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->actionSubstate++;
    playerStatus->currentSpeed *= 0.6f;
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
