#include "common.h"

extern f32 D_802B62D0;
extern f32 D_802B62D4;
extern f32 D_802B62D8;
extern f32 D_802B62DC;
extern s32 D_802B62E0;

void func_802B6000_E291A0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 sp10;
    f32 tempCollision;

    if (playerStatus->flags & (1 << 31)) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->fallState = 0;
        gOverrideFlags |= 0x40;
        disable_player_static_collisions();
        disable_player_input();
    }

    switch (playerStatus->fallState) {
        case 0:
            suggest_player_anim_clearUnkFlag(0x1002E);
            D_802B62E0 = 0x20;
            D_802B62D0 = 16.0f;
            D_802B62D4 = 4.0f;
            D_802B62D8 = 1.0f;
            D_802B62D4 = 1.875f;
            playerStatus->fallState++;
            D_802B62DC = playerStatus->targetYaw;
            break;
        case 1:
            playerStatus->position.y += D_802B62D0;
            D_802B62D0 -= D_802B62D8;
            add_vec2D_polar(&playerStatus->position, &playerStatus->position.z, D_802B62D4, D_802B62DC);
            gCameras[0].targetPos.x = playerStatus->position.x;
            gCameras[0].targetPos.y = playerStatus->position.y;
            gCameras[0].targetPos.z = playerStatus->position.z;
            if (D_802B62D0 <= 0.0f) {
                playerStatus->fallState++;
            }
            break;
        case 2:
            playerStatus->position.y += D_802B62D0;
            D_802B62D0 -= D_802B62D8;
            add_vec2D_polar(&playerStatus->position, &playerStatus->position.z, D_802B62D4, D_802B62DC);
            gCameras[0].targetPos.x = playerStatus->position.x;
            gCameras[0].targetPos.y = playerStatus->position.y;
            gCameras[0].targetPos.z = playerStatus->position.z;
            tempCollision = player_check_collision_below(D_802B62D0, &sp10);
            if (sp10 >= 0) {
                sfx_play_sound_at_player(SOUND_UNKNOWN_162, 0);
                suggest_player_anim_setUnkFlag(0x80003);
                playerStatus->position.y = tempCollision;
                D_802B62E0 = 0xA;
                playerStatus->fallState++;
            }
            break;
        case 3:
            if (playerStatus->unk_BC != 0) {
                suggest_player_anim_setUnkFlag(0x10030);
                playerStatus->fallState = 5;
                playerStatus->framesOnGround = 15;
                break;
            }
            break;
        case 5:
            if (playerStatus->framesOnGround != 0) {
                playerStatus->framesOnGround--;
                break;
            }
            enable_player_static_collisions();
            enable_player_input();
            set_action_state(ACTION_STATE_IDLE);
            gOverrideFlags &= ~0x40;
            break;
    }
}
