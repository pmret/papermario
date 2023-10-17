#include "common.h"
#include "sprite/player.h"

extern f32 JumpedOnSwitchX;
extern f32 JumpedOnSwitchZ;

// private functions
void initialize_jump(void);
void action_update_peach_step_down(void);
void action_update_peach_falling(void);

void initialize_jump(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    AnimID anim;

    playerStatus->actionSubstate = JUMP_SUBSTATE_0;
    playerStatus->timeInAir = 0;
    playerStatus->peakJumpTime = 0;
    playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_FLYING);
    playerStatus->flags |= PS_FLAG_JUMPING;
    playerStatus->jumpFromPos.x = playerStatus->pos.x;
    playerStatus->jumpFromPos.z = playerStatus->pos.z;
    playerStatus->jumpFromHeight = playerStatus->pos.y;

    phys_init_integrator_for_current_state();

    if (playerStatus->animFlags & PA_FLAG_8BIT_MARIO) {
        anim = ANIM_MarioW3_8bit_Jump;
    } else if (!(playerStatus->animFlags & (PA_FLAG_USING_WATT | PA_FLAG_WATT_IN_HANDS))) {
        anim = ANIM_Mario1_Jump;
    } else {
        anim = ANIM_MarioW1_JumpWatt;
    }
    suggest_player_anim_allow_backward(anim);

    collisionStatus->lastTouchedFloor = collisionStatus->curFloor;
    collisionStatus->curFloor = NO_COLLIDER;
}

void action_update_jump(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID anim;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        initialize_jump();

        if (playerStatus->actionState == ACTION_STATE_LAUNCH) {
            phys_adjust_cam_on_landing();
        } else {
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
        }

        if (playerStatus->actionState == ACTION_STATE_JUMP) {
            if (playerStatus->animFlags & PA_FLAG_8BIT_MARIO) {
                sfx_play_sound_at_player(SOUND_JUMP_8BIT_MARIO, SOUND_SPACE_DEFAULT);
            }
            else {
                sfx_play_sound_at_player(SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT);
            }
        }
    }

    if (playerStatus->animFlags & PA_FLAG_8BIT_MARIO) {
        anim = ANIM_MarioW3_8bit_Jump;
    } else if (!(playerStatus->animFlags & (PA_FLAG_USING_WATT | PA_FLAG_WATT_IN_HANDS))) {
        anim = ANIM_Mario1_Jump;
    } else {
        anim = ANIM_MarioW1_JumpWatt;
    }
    suggest_player_anim_allow_backward(anim);

    playerStatus->timeInAir++;
}

void action_update_landing_on_switch(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    AnimID anim;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        Entity* entity = get_entity_by_index(collisionStatus->curFloor);

        JumpedOnSwitchX = entity->pos.x;
        JumpedOnSwitchZ = entity->pos.z;
        initialize_jump();
        playerStatus->flags |= (PS_FLAG_SCRIPTED_FALL | PS_FLAG_ARMS_RAISED);
        disable_player_input();
    }

    playerStatus->timeInAir++;

    if (playerStatus->actionSubstate != JUMP_SUBSTATE_1) {
        return;
    }

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_JUMPING | PS_FLAG_FLYING);
        playerStatus->flags |= PS_FLAG_FALLING;

        if (!(playerStatus->animFlags & (PA_FLAG_USING_WATT | PA_FLAG_WATT_IN_HANDS))) {
            anim = ANIM_Mario1_Fall;
        } else {
            anim = ANIM_MarioW1_FallWatt;
        }

        suggest_player_anim_allow_backward(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
    }

    playerStatus->actionSubstate++;
}

void action_update_falling(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        action_update_peach_falling();
        return;
    }

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        s32 anim;

        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_JUMPING | PS_FLAG_FLYING);
        playerStatus->flags |= PS_FLAG_FALLING;

        if (playerStatus->animFlags & PA_FLAG_8BIT_MARIO) {
            anim = ANIM_MarioW3_8bit_Jump;
        } else  if (!(playerStatus->animFlags & (PA_FLAG_USING_WATT | PA_FLAG_WATT_IN_HANDS))) {
            anim = ANIM_Mario1_Fall;
        } else {
            anim = ANIM_MarioW1_FallWatt;
        }
        suggest_player_anim_allow_backward(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
    }
    playerStatus->timeInAir++;
}

void action_update_step_down(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 colliderID;
    s32 surfaceType;
    f32 posX, posY, posZ;
    f32 hitRx, hitRz;
    f32 hitDirX, hitDirZ;
    f32 height;

    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        action_update_peach_step_down();
        return;
    }

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_JUMPING | PS_FLAG_FLYING);
        playerStatus->flags |= PS_FLAG_FALLING;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
    }

    playerStatus->timeInAir++;
    phys_update_interact_collider();
    posX = playerStatus->pos.x;
    posY = playerStatus->pos.y;
    posZ = playerStatus->pos.z;
    height = playerStatus->colliderHeight;

    colliderID = player_raycast_below_cam_relative(playerStatus, &posX, &posY, &posZ, &height, &hitRx, &hitRz, &hitDirX, &hitDirZ);
    surfaceType = get_collider_flags(colliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
    if (!(surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) && check_input_jump()) {
        set_action_state(ACTION_STATE_JUMP);
        playerStatus->flags &= ~PS_FLAG_AIRBORNE;
        action_update_jump();
    }
}

void action_update_peach_falling(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID anim;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->flags &= ~(PS_FLAG_JUMPING | PS_FLAG_FLYING);
        playerStatus->flags |= PS_FLAG_FALLING;

        if (!(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS)) {
            anim = ANIM_Mario1_Fall;
        } else {
            anim = ANIM_Peach1_StepDown;
        }

        suggest_player_anim_allow_backward(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
    }
    playerStatus->timeInAir++;
}

void action_update_peach_step_down(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->flags &= ~(PS_FLAG_JUMPING | PS_FLAG_FLYING);
        playerStatus->flags |= PS_FLAG_FALLING;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;

        if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
            suggest_player_anim_allow_backward(ANIM_Peach1_StepDown);
        }
    }
    playerStatus->timeInAir++;
    phys_update_interact_collider();
}
