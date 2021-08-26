#include "common.h"
#include "effects.h"

extern f32 D_802B68B0;
extern f32 D_802B68B4;
extern f32 D_802B68B8;
extern f32 D_802B68BC;

void func_802B6000_E27F40(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    s32 sp2C;
    f32 tempGravityIntegrator;
    f32 theta;
    f32 tempCurrentSpeed;

    if (playerStatus->flags & (1 << 31)) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->flags |= 0x800008;
        playerStatus->animFlags |= 4;
        playerStatus->flags |= 0x800;
        if (playerStatus->unk_BF == 1) {
            playerStatus->fallState = 0x14;
            playerStatus->framesOnGround = 2;
        } else {
            playerStatus->fallState = 0;
        }
        D_802B68BC = playerStatus->position.y;
        playerStatus->currentSpeed = 0.0f;
        D_802B68B0 = 0.0f;

        gCameras[0].moveFlags |= 3;
        D_802B68B4 = 90.0f;
        subtract_hp(1);
        open_status_menu_long();
        gOverrideFlags |= 0x40;
        sfx_play_sound_at_player(0xE8, 0);
    }

    switch (playerStatus->fallState) {
        case 21:
            if (--playerStatus->framesOnGround == -1) {
                playerStatus->fallState = 0;
            }
            break;
        case 20:
            if (--playerStatus->framesOnGround == -1) {
                playerStatus->fallState = 0;
            }
            playerStatus->position.y -= 4.0f;
            break;
        case 0:
            if (playerStatus->unk_BF == 1) {
                playFX_27(0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 1.0f, 0x28);
            }
            suggest_player_anim_setUnkFlag(0x80000 | 2);
            playerStatus->gravityIntegrator[1] = 0.0f;
            playerStatus->decorationList = 0;
            playerStatus->unk_C2 = 0;
            playerStatus->fallState = 2;
            playerStatus->framesOnGround = 1;
            playerStatus->gravityIntegrator[0] = 20.0f;
            playerStatus->gravityIntegrator[2] = 250.0f;
            playerStatus->gravityIntegrator[3] = D_802B68BC;
            playerStatus->unk_3C = playerStatus->position.x;
            playerStatus->unk_40 = playerStatus->position.z;
            playerStatus->unk_4C = playerStatus->position.y;
            playerStatus->flags |= 0x2;
            break;
        case 1:
            if (--playerStatus->framesOnGround << 16 <= 0) {
                playerStatus->fallState++;
            }
            break;
        case 2:
            if (playerStatus->unk_BF == 1 && !(playerStatus->decorationList & DECORATION_GOLDEN_FLAMES)) {
                playFX_27(0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 0.7f, 18);
            }
            if (playerStatus->position.y < playerStatus->gravityIntegrator[3] + playerStatus->gravityIntegrator[2]) {
                sin_cos_rad((D_802B68B4 * TAU) / 360.0f, &sp18, &sp1C);
                D_802B68B0 = sin_rad((D_802B68B4 * TAU) / 360.0f) * 16.0f;
                if (D_802B68B0 < -1.0f) {
                    D_802B68B0 = -1.0f;
                }
                playerStatus->position.y += D_802B68B0;
                D_802B68B4 += 3.0f;
                if (D_802B68B4 > 180.0f) {
                    D_802B68B4 = 180.0f;
                    playerStatus->fallState++;
                }
            } else {
                playerStatus->position.y = playerStatus->gravityIntegrator[3] + playerStatus->gravityIntegrator[2];
                playerStatus->fallState++;
            }
            break;
        case 3:
            if (playerStatus->unk_BF == 1) {
                if (!(playerStatus->decorationList & DECORATION_GOLDEN_FLAMES)) {
                    playFX_27(0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 0.7f, 18);
                }
            }
            if (get_lava_reset_pos(&sp20, &sp24, &sp28) == 0) {
                sp20 = playerStatus->position.x;
                sp28 = playerStatus->position.z;
            }
            playerStatus->lastGoodPosition.x = sp20;
            playerStatus->lastGoodPosition.z = sp28;
            playerStatus->jumpApexHeight = playerStatus->position.y;
            playerStatus->gravityIntegrator[0] = 0.1143f;
            playerStatus->gravityIntegrator[1] = -0.2871f;
            playerStatus->gravityIntegrator[2] = -0.1823f;
            playerStatus->gravityIntegrator[3] = 0.01152f;
            playerStatus->fallState++;
            break;
        case 4:
            D_802B68B8 = atan2(playerStatus->position.x, playerStatus->position.z, playerStatus->lastGoodPosition.x, playerStatus->lastGoodPosition.z);
            playerStatus->currentSpeed = get_xz_dist_to_player(playerStatus->lastGoodPosition.x, playerStatus->lastGoodPosition.z) / 18.0f;
            playerStatus->fallState++;
            break;
        case 5:
            D_802B68B8 = atan2(playerStatus->position.x, playerStatus->position.z, playerStatus->lastGoodPosition.x, playerStatus->lastGoodPosition.z);
            theta = D_802B68B8 * TAU  / 360.0f;
            tempCurrentSpeed = playerStatus->currentSpeed * sin_rad(theta);
            playerStatus->position.x += tempCurrentSpeed;
            sp2C = 0;
            if (tempCurrentSpeed >= 0.0f) {
                if (playerStatus->lastGoodPosition.x <= playerStatus->position.x) {
                    playerStatus->position.x = playerStatus->lastGoodPosition.x;
                    sp2C = 1;
                }
            } else {
                if (playerStatus->position.x <= playerStatus->lastGoodPosition.x) {
                    playerStatus->position.x = playerStatus->lastGoodPosition.x;
                    sp2C = 1;
                }
            }
            tempCurrentSpeed = playerStatus->currentSpeed * cos_rad(theta);
            playerStatus->position.z -= tempCurrentSpeed;
            if (tempCurrentSpeed >= 0.0f) {
                if (playerStatus->position.z <= playerStatus->lastGoodPosition.z) {
                    playerStatus->position.z = playerStatus->lastGoodPosition.z;
                    sp2C++;
                }
            } else {
                if (playerStatus->lastGoodPosition.z <= playerStatus->position.z) {
                    playerStatus->position.z = playerStatus->lastGoodPosition.z;
                    sp2C++;
                }
            }
            if (sp2C == 2) {
                playerStatus->fallState++;
            }
            break;
        case 6:
            if (playerStatus->unk_BF == 1 && (playerStatus->decorationList & DECORATION_GOLDEN_FLAMES) == 0) {
                playFX_27(0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 0.7f, 18);
            }
            playerStatus->position.y = player_check_collision_below(func_800E34D8(), &sp2C);
            if (sp2C >= 0) {
                exec_ShakeCamX(0, 2, 1, 0.8f);
                start_rumble(0x100, 0x32);
                phys_adjust_cam_on_landing();
                gCameras[0].moveFlags &= ~2;
                sfx_play_sound_at_player(0x3FB, 0);
                suggest_player_anim_setUnkFlag(0x8001A);
                playerStatus->flags &= ~0x800;
                playerStatus->flags &= ~8;
                playerStatus->unk_BF = 0;
                playerStatus->gravityIntegrator[0] = 6.0f;
                playerStatus->position.y += 6.0f;
                playerStatus->fallState++;
            }
            break;
        case 7:
            tempGravityIntegrator = playerStatus->gravityIntegrator[0] - 1.0;
            playerStatus->gravityIntegrator[0] = tempGravityIntegrator;
            playerStatus->position.y = player_check_collision_below(tempGravityIntegrator, &sp2C);
            if (sp2C >= 0) {
                playerStatus->framesOnGround = 0xA;
                playerStatus->fallState++;
            }
            break;
        case 8:
            if (--playerStatus->framesOnGround << 16 <= 0) {
                set_action_state(ACTION_STATE_LAND);
                playerStatus->flags &= ~0x800000;
                gOverrideFlags &= ~0x40;
            }
            break;
    }
    if (playerStatus->fallState < 7) {
        playerStatus->decorationList++;
    }
}
