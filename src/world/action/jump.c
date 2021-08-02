#include "common.h"

extern void phys_adjust_cam_on_landing();
extern void sfx_play_sound_at_player(s32 soundID, s32 arg0);
extern void suggest_player_anim_clearUnkFlag(s32 arg0);
extern void phys_init_integrator_for_current_state();
extern s32 check_input_jump();
extern s32 player_raycast_below_cam_relative(PlayerStatus*, f32*, f32*, f32*, f32*, f32*, f32*, f32*, f32*);

extern f32 D_8010C960;
extern f32 D_8010C97C;

void func_802B6000_E24040() {
    s32 temp_v1;
    s32 phi_a0;
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus;

    playerStatus->fallState = 0;
    playerStatus->decorationList = 0;
    playerStatus->unk_C2 = 0;
    playerStatus->flags &= 0x7FFFFFF7 ;
    playerStatus->flags |= 2;
    playerStatus->unk_3C = playerStatus->position.x;
    playerStatus->unk_40 = playerStatus->position.z;
    playerStatus->unk_4C = playerStatus->position.y;

    phys_init_integrator_for_current_state();
    collisionStatus = &gCollisionStatus;

    if ((playerStatus->animFlags & PLAYER_ANIM_FLAG_8BIT_MARIO)) {
        temp_v1 = 0x90005;
    }
    else {
        phi_a0 = (playerStatus->animFlags & PLAYER_ANIM_FLAG_3);
        temp_v1 = 0x60009;
        if (!phi_a0) {
            temp_v1 = 0x10007;
        }
    }
    suggest_player_anim_clearUnkFlag(temp_v1);
    collisionStatus->lastTouchedFloor = collisionStatus->currentFloor;
    collisionStatus->currentFloor = -1;
}

void func_802B60B4_E240F4() {
    s32 temp_v1;
    s32 phi_a0;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cam;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= 0x7FFFFFFF;
        func_802B6000_E24040();

        if (playerStatus->actionState == ACTION_STATE_LAUNCH) {
            phys_adjust_cam_on_landing();
        } else {
            cam = &gCameras;
            cam->moveFlags |= 1;
        }

        if (playerStatus->actionState == ACTION_STATE_JUMP) {
            phi_a0 = SOUND_JUMP_2081;
            if ((playerStatus->animFlags & PLAYER_ANIM_FLAG_8BIT_MARIO)) {
                phi_a0 = SOUND_JUMP_8BIT_MARIO;
            }
            sfx_play_sound_at_player(phi_a0, 0);
        }
    }

    if ((playerStatus->animFlags & PLAYER_ANIM_FLAG_8BIT_MARIO)) {
        phi_a0 = 0x90005;
    } else {
        temp_v1 = playerStatus->animFlags & PLAYER_ANIM_FLAG_3;
        phi_a0 = 0x60009;

        if (!temp_v1) {
          phi_a0 = 0x10007;
        }
    }
    suggest_player_anim_clearUnkFlag(phi_a0);
    playerStatus->decorationList++;
}

void func_802B6198_E241D8() {
    f32 temp_f2;
    s32 temp_s1;
    s32 phi_a0;
    Entity* temp_v0;
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Camera* cam;

    temp_s1 = 0x80000000;
    if (playerStatus->flags < 0) {
        temp_v0 = get_entity_by_index(collisionStatus->currentFloor);
        temp_f2 = temp_v0->position.z;
        D_8010C960 = temp_v0->position.x;
        D_8010C97C = temp_f2;
        func_802B6000_E24040();
        playerStatus->flags |= 0x880000;
        disable_player_input();
    }

    playerStatus->decorationList++;
    if (playerStatus->fallState == 1) {
        if ((playerStatus->flags & 0x80000000)) {

          playerStatus->flags &= 0x7FFFFFF5;
          playerStatus->flags |= 4;

          phi_a0 = 0x6000A;

          if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_3)) {
            phi_a0 = 0x10008;
          }

          temp_s1 = phi_a0;
          suggest_player_anim_clearUnkFlag(temp_s1);
          cam = &gCameras;
          cam->moveFlags |= 1;
        }
    } else {
        return;
    }
    playerStatus->fallState++;
}

void func_802B6294_E242D4() {
    s32 temp_v1;
    s32 phi_a0;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cam;

    if ((playerStatus->animFlags & PLAYER_ANIM_FLAG_PEACH_PHYSICS)) {
        func_802B647C_E244BC();
        return;
    }

    temp_v1 = playerStatus->flags;
    if ( playerStatus->flags < 0) {
        playerStatus->flags &= 0x7FFFFFF5;
        playerStatus->flags |= 4;

        if (playerStatus->animFlags & PLAYER_ANIM_FLAG_8BIT_MARIO) {
            phi_a0 = 0x90005;
        } else {
            temp_v1 = 0x6000A;
            phi_a0 = temp_v1;

            if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_3)) {
                phi_a0 = 0x10008;
            }
        }
        suggest_player_anim_clearUnkFlag(phi_a0);
        cam = &gCameras;
        cam->moveFlags |= 1;
    }
    playerStatus->decorationList++;
}

void func_802B6348_E24388() {
    f32* sub_arg1;
    f32* sub_arg2;
    f32* sub_arg3;
    f32* sub_arg4;
    f32 sub_arg5;
    f32 sub_arg6;
    f32 sub_arg7;
    f32 sub_arg8;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cam;

    if (playerStatus->animFlags & PLAYER_ANIM_FLAG_PEACH_PHYSICS) {
        func_802B6508_E24548();
        return;
    }

    if (playerStatus->flags < 0) {
        playerStatus->flags &= 0x7FFFFFF5;
        playerStatus->flags |= 4;
        cam = &gCameras;
        cam->moveFlags |= 1;
    }

    playerStatus->decorationList++;
    phys_update_interact_collider();
    sub_arg1 = &sp28;
    sub_arg2 = &sp2C;
    sub_arg3 = &sp30;
    sub_arg4 = &sp34;
    sub_arg6 = sub_arg6;
    sp28 = playerStatus->position.x;
    sp2C = playerStatus->position.y;
    sp30 = playerStatus->position.z;
    sp34 = playerStatus->colliderHeight;

    if (((get_collider_type_by_id(player_raycast_below_cam_relative(playerStatus, sub_arg1, sub_arg2, sub_arg3, sub_arg4,
                                    &sub_arg5, &sub_arg6, &sub_arg7, &sub_arg8)) & 0xFF) - 2 >= 2u) && check_input_jump()) {

        set_action_state(3);
        playerStatus->flags &= -0xF;
        func_802B60B4_E240F4();
    }
}

void func_802B647C_E244BC() {
    s32 temp_v1;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cam;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= 0x7FFFFFFF;
        playerStatus->flags &= ~0xA;
        playerStatus->flags |= 4;
        temp_v1 = 0xA0006;

        if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_PEACH_PHYSICS)) {
            temp_v1 = 0x10008;
        }
        suggest_player_anim_clearUnkFlag(temp_v1);
        cam = &gCameras;
        cam->moveFlags |= 1;
    }
    playerStatus->decorationList++;
}

void func_802B6508_E24548() {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cam;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= 0x7FFFFFFF;
        playerStatus->flags &= ~0xA;
        playerStatus->flags |= 4;
        cam = &gCameras;
        cam->moveFlags |= 1;

        if (playerStatus->animFlags & PLAYER_ANIM_FLAG_PEACH_PHYSICS) {
            suggest_player_anim_clearUnkFlag(0xA0006);
        }
    }
    playerStatus->decorationList++;
    phys_update_interact_collider();
}
