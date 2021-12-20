#include "common.h"

extern f32 D_8010C960;
extern f32 D_8010C97C;

void func_802B6508_E24548(void);
void func_802B647C_E244BC(void);

void func_802B6000_E24040(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 temp_v1;

    playerStatus->fallState = 0;
    playerStatus->decorationList = 0;
    playerStatus->unk_C2 = 0;
    playerStatus->flags &= ~0x80000008;
    playerStatus->flags |= 2;
    playerStatus->unk_3C = playerStatus->position.x;
    playerStatus->unk_40 = playerStatus->position.z;
    playerStatus->unk_4C = playerStatus->position.y;

    phys_init_integrator_for_current_state();

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
        temp_v1 = 0x90005;
    } else if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
        temp_v1 = 0x10007;
    } else {
        temp_v1 = 0x60009;
    }
    suggest_player_anim_clearUnkFlag(temp_v1);

    collisionStatus->lastTouchedFloor = collisionStatus->currentFloor;
    collisionStatus->currentFloor = -1;
}

void func_802B60B4_E240F4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 phi_a0;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        func_802B6000_E24040();

        if (playerStatus->actionState == ACTION_STATE_LAUNCH) {
            phys_adjust_cam_on_landing();
        } else {
            gCameras[0].moveFlags |= 1;
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
        phi_a0 = 0x90005;
    } else if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
        phi_a0 = 0x10007;
    } else {
        phi_a0 = 0x60009;
    }
    suggest_player_anim_clearUnkFlag(phi_a0);

    playerStatus->decorationList++;
}

void func_802B6198_E241D8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 temp_s1;
    s32 phi_a0;

    temp_s1 = 0x80000000; // weirdness with this - fake match

    if (playerStatus->flags < 0) {
        Entity* entity = get_entity_by_index(collisionStatus->currentFloor);

        D_8010C960 = entity->position.x;
        D_8010C97C = entity->position.z;
        func_802B6000_E24040();
        playerStatus->flags |= 0x880000;
        disable_player_input();
    }

    playerStatus->decorationList++;

    if (playerStatus->fallState != 1) {
        return;
    }

    if (playerStatus->flags & 0x80000000) {
        playerStatus->flags &= ~0x8000000A;
        playerStatus->flags |= 4;


        if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
            phi_a0 = 0x10008;
        } else {
            phi_a0 = 0x6000A;
        }

        temp_s1 = phi_a0;
        suggest_player_anim_clearUnkFlag(temp_s1);
        gCameras[0].moveFlags |= 1;
    }

    playerStatus->fallState++;
}

void func_802B6294_E242D4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B647C_E244BC();
        return;
    }

    if (playerStatus->flags < 0) {
        s32 phi_a0;

        playerStatus->flags &= ~0x8000000A;
        playerStatus->flags |= 4;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
            phi_a0 = 0x90005;
        } else  if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
            phi_a0 = 0x10008;
        } else {
            phi_a0 = 0x6000A;
        }
        suggest_player_anim_clearUnkFlag(phi_a0);
        gCameras[0].moveFlags |= 1;
    }
    playerStatus->decorationList++;
}

void func_802B6348_E24388(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sub_arg5;
    f32 sub_arg6;
    f32 sub_arg7;
    f32 sub_arg8;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B6508_E24548();
        return;
    }

    if (playerStatus->flags < 0) {
        playerStatus->flags &= 0x7FFFFFF5;
        playerStatus->flags |= 4;
        gCameras[0].moveFlags |= 1;
    }

    playerStatus->decorationList++;
    phys_update_interact_collider();
    sp28 = playerStatus->position.x;
    sp2C = playerStatus->position.y;
    sp30 = playerStatus->position.z;
    sp34 = playerStatus->colliderHeight;

    if (((get_collider_type_by_id(player_raycast_below_cam_relative(playerStatus, &sp28, &sp2C, &sp30, &sp34,
                                    &sub_arg5, &sub_arg6, &sub_arg7, &sub_arg8)) & 0xFF) - 2 >= 2U) && check_input_jump()) {

        set_action_state(ACTION_STATE_JUMP);
        playerStatus->flags &= ~0xE;
        func_802B60B4_E240F4();
    }
}

void func_802B647C_E244BC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 temp_v1;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->flags &= ~0xA;
        playerStatus->flags |= 4;

        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS)) {
            temp_v1 = 0x10008;
        } else {
            temp_v1 = 0xA0006;
        }

        suggest_player_anim_clearUnkFlag(temp_v1);
        gCameras[0].moveFlags |= 1;
    }
    playerStatus->decorationList++;
}

void func_802B6508_E24548(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->flags &= ~0xA;
        playerStatus->flags |= 4;
        gCameras[0].moveFlags |= 1;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
            suggest_player_anim_clearUnkFlag(0xA0006);
        }
    }
    playerStatus->decorationList++;
    phys_update_interact_collider();
}
