#include "common.h"

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
    playerStatus->unk_C2 = 0;
    playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_FLYING);
    playerStatus->flags |= PS_FLAGS_JUMPING;
    playerStatus->jumpFromPos.x = playerStatus->position.x;
    playerStatus->jumpFromPos.z = playerStatus->position.z;
    playerStatus->jumpFromHeight = playerStatus->position.y;

    phys_init_integrator_for_current_state();

    if (playerStatus->animFlags & PA_FLAGS_8BIT_MARIO) {
        anim = ANIM_Mario_90005;
    } else if (!(playerStatus->animFlags & (PA_FLAGS_HOLDING_WATT | PA_FLAGS_2))) {
        anim = ANIM_Mario_AnimMidairStill;
    } else {
        anim = ANIM_Mario_60009;
    }
    suggest_player_anim_clearUnkFlag(anim);

    collisionStatus->lastTouchedFloor = collisionStatus->currentFloor;
    collisionStatus->currentFloor = -1;
}

void action_update_jump(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID anim;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        initialize_jump();

        if (playerStatus->actionState == ACTION_STATE_LAUNCH) {
            phys_adjust_cam_on_landing();
        } else {
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
        }

        if (playerStatus->actionState == ACTION_STATE_JUMP) {
            if (playerStatus->animFlags & PA_FLAGS_8BIT_MARIO) {
                sfx_play_sound_at_player(SOUND_JUMP_8BIT_MARIO, 0);
            }
            else {
                sfx_play_sound_at_player(SOUND_JUMP_2081, 0);
            }
        }
    }

    if (playerStatus->animFlags & PA_FLAGS_8BIT_MARIO) {
        anim = ANIM_Mario_90005;
    } else if (!(playerStatus->animFlags & (PA_FLAGS_HOLDING_WATT | PA_FLAGS_2))) {
        anim = ANIM_Mario_AnimMidairStill;
    } else {
        anim = ANIM_Mario_60009;
    }
    suggest_player_anim_clearUnkFlag(anim);

    playerStatus->timeInAir++;
}

void action_update_landing_on_switch(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    AnimID anim;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        Entity* entity = get_entity_by_index(collisionStatus->currentFloor);

        JumpedOnSwitchX = entity->position.x;
        JumpedOnSwitchZ = entity->position.z;
        initialize_jump();
        playerStatus->flags |= (PS_FLAGS_800000 | PS_FLAGS_80000);
        disable_player_input();
    }

    playerStatus->timeInAir++;

    if (playerStatus->actionSubstate != JUMP_SUBSTATE_1) {
        return;
    }

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_JUMPING | PS_FLAGS_FLYING);
        playerStatus->flags |= PS_FLAGS_FALLING;

        if (!(playerStatus->animFlags & (PA_FLAGS_HOLDING_WATT | PA_FLAGS_2))) {
            anim = ANIM_Mario_AnimMidair;
        } else {
            anim = ANIM_Mario_6000A;
        }

        suggest_player_anim_clearUnkFlag(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }

    playerStatus->actionSubstate++;
}

void action_update_falling(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
        action_update_peach_falling();
        return;
    }

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        s32 anim;

        playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_JUMPING | PS_FLAGS_FLYING);
        playerStatus->flags |= PS_FLAGS_FALLING;

        if (playerStatus->animFlags & PA_FLAGS_8BIT_MARIO) {
            anim = ANIM_Mario_90005;
        } else  if (!(playerStatus->animFlags & (PA_FLAGS_HOLDING_WATT | PA_FLAGS_2))) {
            anim = ANIM_Mario_AnimMidair;
        } else {
            anim = ANIM_Mario_6000A;
        }
        suggest_player_anim_clearUnkFlag(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
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

    if (playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
        action_update_peach_step_down();
        return;
    }

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_JUMPING | PS_FLAGS_FLYING);
        playerStatus->flags |= PS_FLAGS_FALLING;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }

    playerStatus->timeInAir++;
    phys_update_interact_collider();
    posX = playerStatus->position.x;
    posY = playerStatus->position.y;
    posZ = playerStatus->position.z;
    height = playerStatus->colliderHeight;

    colliderID = player_raycast_below_cam_relative(playerStatus, &posX, &posY, &posZ, &height, &hitRx, &hitRz, &hitDirX, &hitDirZ);
    surfaceType = get_collider_flags(colliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
    if (!(surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) && check_input_jump()) {
        set_action_state(ACTION_STATE_JUMP);
        playerStatus->flags &= ~PS_FLAGS_AIRBORNE;
        action_update_jump();
    }
}

void action_update_peach_falling(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID anim;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags &= ~(PS_FLAGS_JUMPING | PS_FLAGS_FLYING);
        playerStatus->flags |= PS_FLAGS_FALLING;

        if (!(playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS)) {
            anim = ANIM_Mario_AnimMidair;
        } else {
            anim = ANIM_Peach_A0006;
        }

        suggest_player_anim_clearUnkFlag(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }
    playerStatus->timeInAir++;
}

void action_update_peach_step_down(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags &= ~(PS_FLAGS_JUMPING | PS_FLAGS_FLYING);
        playerStatus->flags |= PS_FLAGS_FALLING;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;

        if (playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
            suggest_player_anim_clearUnkFlag(ANIM_Peach_A0006);
        }
    }
    playerStatus->timeInAir++;
    phys_update_interact_collider();
}
