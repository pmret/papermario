#include "common.h"

extern f32 D_8010C960;
extern f32 D_8010C97C;

void func_802B6508_E24548(void);
void func_802B647C_E244BC(void);

void func_802B6000_E24040(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    AnimID anim;

    playerStatus->fallState = 0;
    playerStatus->timeInAir = 0;
    playerStatus->unk_C2 = 0;
    playerStatus->flags &= ~0x80000008;
    playerStatus->flags |= 2;
    playerStatus->jumpFromPos.x = playerStatus->position.x;
    playerStatus->jumpFromPos.z = playerStatus->position.z;
    playerStatus->jumpFromHeight = playerStatus->position.y;

    phys_init_integrator_for_current_state();

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
        anim = ANIM_Mario_90005;
    } else if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
        anim = ANIM_Mario_AnimMidairStill;
    } else {
        anim = ANIM_Mario_60009;
    }
    suggest_player_anim_clearUnkFlag(anim);

    collisionStatus->lastTouchedFloor = collisionStatus->currentFloor;
    collisionStatus->currentFloor = -1;
}

void func_802B60B4_E240F4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID anim;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        func_802B6000_E24040();

        if (playerStatus->actionState == ACTION_STATE_LAUNCH) {
            phys_adjust_cam_on_landing();
        } else {
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
        }

        if (playerStatus->actionState == ACTION_STATE_JUMP) {
            if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
                sfx_play_sound_at_player(SOUND_JUMP_8BIT_MARIO, 0);
            }
            else {
                sfx_play_sound_at_player(SOUND_JUMP_2081, 0);
            }
        }
    }

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
        anim = ANIM_Mario_90005;
    } else if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
        anim = ANIM_Mario_AnimMidairStill;
    } else {
        anim = ANIM_Mario_60009;
    }
    suggest_player_anim_clearUnkFlag(anim);

    playerStatus->timeInAir++;
}

void func_802B6198_E241D8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    AnimID anim;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        Entity* entity = get_entity_by_index(collisionStatus->currentFloor);

        D_8010C960 = entity->position.x;
        D_8010C97C = entity->position.z;
        func_802B6000_E24040();
        playerStatus->flags |= 0x880000;
        disable_player_input();
    }

    playerStatus->timeInAir++;

    if (playerStatus->fallState != 1) {
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;

        if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
            anim = ANIM_Mario_AnimMidair;
        } else {
            anim = ANIM_Mario_6000A;
        }

        suggest_player_anim_clearUnkFlag(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }

    playerStatus->fallState++;
}

void func_802B6294_E242D4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B647C_E244BC();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        s32 anim;

        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
            anim = ANIM_Mario_90005;
        } else  if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
            anim = ANIM_Mario_AnimMidair;
        } else {
            anim = ANIM_Mario_6000A;
        }
        suggest_player_anim_clearUnkFlag(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }
    playerStatus->timeInAir++;
}

void func_802B6348_E24388(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 colliderID;
    s32 surfaceType;
    f32 posX, posY, posZ;
    f32 hitRx, hitRz;
    f32 hitDirX, hitDirZ;
    f32 height;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B6508_E24548();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }

    playerStatus->timeInAir++;
    phys_update_interact_collider();
    posX = playerStatus->position.x;
    posY = playerStatus->position.y;
    posZ = playerStatus->position.z;
    height = playerStatus->colliderHeight;

    colliderID = player_raycast_below_cam_relative(playerStatus, &posX, &posY, &posZ, &height, &hitRx, &hitRz, &hitDirX, &hitDirZ);
    surfaceType = get_collider_flags(colliderID) & COLLIDER_FLAGS_SURFACE_TYPE;
    if (!(surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) && check_input_jump()) {
        set_action_state(ACTION_STATE_JUMP);
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_AIRBORNE;
        func_802B60B4_E240F4();
    }
}

void func_802B647C_E244BC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID anim;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;

        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS)) {
            anim = ANIM_Mario_AnimMidair;
        } else {
            anim = ANIM_Peach_A0006;
        }

        suggest_player_anim_clearUnkFlag(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }
    playerStatus->timeInAir++;
}

void func_802B6508_E24548(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
            suggest_player_anim_clearUnkFlag(ANIM_Peach_A0006);
        }
    }
    playerStatus->timeInAir++;
    phys_update_interact_collider();
}
