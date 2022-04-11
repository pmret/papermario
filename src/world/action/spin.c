#include "common.h"
#include "effects.h"

extern s32 gSpinHistoryBufferPos;
extern s32 gSpinHistoryPosY[5];
extern s32 gSpinHistoryPosX[5];
extern s32 gSpinHistoryPosZ[5];
extern s16 gSpinHistoryPosAngle[5];
void phys_clear_spin_history(void);

//INCLUDE_ASM(s32, "world/action/spin", func_802B6000_E25D60);
void func_802B6000_E25D60(void) {
    PlayerSpinState* playerSpinState = &gPlayerSpinState;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sp10;
    f32 sp14;
    f32 temp_f24;
    s32 phi_s2, phi_s3, phi_s4;
    s32 temp_v1_2;
    s32 phi_s5 = 0;
    
    if (playerStatus->flags & 0x80000000) {
        playerStatus->flags &= ~0x80080000;
        playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_40000;
        playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_SPINNING;
        playerStatus->flags |= 0x20000;
        playerStatus->currentStateTime = 0;
        playerStatus->fallState = 0;
        playerSpinState->stopSoundTimer = 0;
        playerSpinState->hasBufferedSpin = 0;
        playerSpinState->spinDirectionMagnitude = 0.0f;
        playerSpinState->spinDirection.x = 0.0f;
        playerSpinState->spinDirection.y = 0.0f;
        playerSpinState->hitWallTime = 0;
        playerSpinState->bufferedStickAxis.x = 0;
        playerSpinState->bufferedStickAxis.y = 0;
        playerSpinState->spinSoundID = 0;
        playerStatus->unk_D8 = NULL;
        playerSpinState->initialSpinTime = 25;
        playerSpinState->fullSpeedSpinTime = 15;
        playerSpinState->spinRate = 40.0f;
        playerSpinState->speedScale = 2.0f;
        playerSpinState->frictionScale = 0.5f;
        playerSpinState->spinCountdown = playerSpinState->initialSpinTime; //was unk2D access?
        phi_s5 = 1;

        if (is_ability_active(ABILITY_SPIN_ATTACK)) {
            phi_s2 = 1 << 2;
        } else {
            phi_s2 = 0;
        }

        if (is_ability_active(ABILITY_DIZZY_ATTACK) != 0) {
            phi_s2 = phi_s2 | 2;
        }
        
        if (is_ability_active(ABILITY_SPEEDY_SPIN) != 0) {
            playerSpinState->initialSpinTime = 30;
            playerSpinState->spinRate = 40.0f;
            playerSpinState->fullSpeedSpinTime = 20;
            playerSpinState->spinCountdown = playerSpinState->initialSpinTime; //was unk2D access?
            playerSpinState->speedScale = 2.7f;
            playerSpinState->frictionScale = 0.9f;
            phi_s2 |= 1;
        }
        
        phi_s4 = -1;
        phi_s3 = 0x10010;
        
        if (phi_s2 != 0) {
            if (phi_s2 & 4) {
                phi_s4 = 2;
                phi_s3 = 0x10012;
            } else if (phi_s2 & 2) {
                phi_s4 = 4;
            } else if (phi_s2 & 1) {
                phi_s4 = 0;
                phi_s3 = 0x10011;
            }
        }
        
        playerSpinState->spinSoundID = SOUND_2111;
        temp_v1_2 = phi_s2 & ~2;
        
        if (temp_v1_2 == 4) {
            playerSpinState->spinSoundID = SOUND_2113;
        }
        if (temp_v1_2 == 1) {
            playerSpinState->spinSoundID = SOUND_2112;
        }
        if (temp_v1_2 == 5) {
            playerSpinState->spinSoundID = SOUND_2114;
        }
        
        sfx_play_sound_at_player(playerSpinState->spinSoundID, 0);
        suggest_player_anim_setUnkFlag(phi_s3);
        
        if ((clamp_angle(playerStatus->targetYaw - gCameras[gCurrentCameraID].currentYaw) <= 180.0f)) {
            playerStatus->spinRate = playerSpinState->spinRate;
        } else {
            phi_s4++;
            playerStatus->spinRate = -playerSpinState->spinRate;
        }
        if (phi_s2 != 0) {
            playerStatus->unk_D8 = (void*)fx_46(phi_s4, (EffectWhirlwind* ) playerStatus, 1.0f, 1000);
        }
        
        phys_clear_spin_history();
        player_input_to_move_vector(&sp10, &sp14);
        playerStatus->targetYaw = sp10;
        playerSpinState->inputMagnitude = sp14;
    }
    
    gSpinHistoryPosAngle[gSpinHistoryBufferPos++] = playerStatus->spriteFacingAngle;
    
    if (gSpinHistoryBufferPos >= 6) {
        gSpinHistoryBufferPos = 0;
    }
    
    gSpinHistoryPosX[gSpinHistoryBufferPos] = playerStatus->position.x;
    gSpinHistoryPosY[gSpinHistoryBufferPos] = playerStatus->position.y;
    gSpinHistoryPosZ[gSpinHistoryBufferPos] = playerStatus->position.z;
    gSpinHistoryPosAngle[gSpinHistoryBufferPos] = playerStatus->spriteFacingAngle;
    gSpinHistoryBufferPos++;
    
    if (gSpinHistoryBufferPos >= 6) {
        gSpinHistoryBufferPos = 0;
    }
    
    if ((phi_s5 == 0) && ((check_input_hammer() != 0) || (check_input_jump() != 0))) {
        playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_SPINNING;
        playerStatus->flags &= ~0x00020000;
        sfx_stop_sound(playerSpinState->spinSoundID);
        player_input_to_move_vector(&sp10, &sp14);
        playerStatus->targetYaw = sp10;
        return;
    }
    
    if (playerSpinState->spinCountdown < 11 && playerStatus->pressedButtons & Z_TRIG) {
        playerSpinState->hasBufferedSpin = 1;
        playerSpinState->prevActionState = playerStatus->prevActionState;
        playerSpinState->bufferedStickAxis.x = playerStatus->stickAxis[0];
        playerSpinState->bufferedStickAxis.y = playerStatus->stickAxis[1];
    }
    
    if (playerStatus->fallState >= 2) {
        playerSpinState->spinDirectionMagnitude = playerSpinState->spinDirectionMagnitude - 1.0f;;
        if (playerSpinState->spinDirectionMagnitude < 0.0f) {
            playerSpinState->spinDirectionMagnitude = 0.0f;
        }
        
        sp10 = clamp_angle(playerStatus->targetYaw - gCameras[gCurrentCameraID].currentYaw);
        playerSpinState->spinDirection.x = sin_rad(sp10 * TAU / 360.0f) * playerSpinState->spinDirectionMagnitude;
        playerSpinState->spinDirection.y = -cos_rad((sp10 * TAU) / 360.0f) * playerSpinState->spinDirectionMagnitude;
        playerStatus->currentStateTime--;
        if ((playerStatus->currentStateTime) == 0) {
            playerSpinState->stopSoundTimer = 4;
            set_action_state(0);
            playerStatus->flags &= ~PLAYER_STATUS_ANIM_FLAGS_20000;
            playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_SPINNING;
            sfx_stop_sound(playerSpinState->spinSoundID);
        }
        playerStatus->currentSpeed = 0.0f;
        return;
    }
    
    if (playerStatus->fallState == 0) {
        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_40000) {
            playerStatus->fallState = 1;
        } else if (gCollisionStatus.pushingAgainstWall >= 0) {
            playerSpinState->hitWallTime++;
            if (playerSpinState->hitWallTime >= 10) {
                playerStatus->fallState = 1;
            }
        }
    }
    
    if (!(playerStatus->currentStateTime > playerSpinState->fullSpeedSpinTime)) {
        temp_f24 = (playerSpinState->inputMagnitude) ? playerSpinState->speedScale : 0.0f;
        playerSpinState->spinDirectionMagnitude = playerSpinState->spinDirectionMagnitude + 0.9;
        
        if (playerSpinState->spinDirectionMagnitude > 9.0f) {
            playerSpinState->spinDirectionMagnitude = 9.0f;
        }
        
        sp10 = clamp_angle(playerStatus->targetYaw - gCameras[gCurrentCameraID].currentYaw);
        playerSpinState->spinDirection.x = sin_rad(sp10 * TAU / 360.0f) * playerSpinState->spinDirectionMagnitude;
        playerSpinState->spinDirection.y = -cos_rad(sp10 * TAU / 360.0f) * playerSpinState->spinDirectionMagnitude;
    } else {
        temp_f24 = playerSpinState->speedScale - (playerStatus->currentStateTime - playerSpinState->fullSpeedSpinTime - 1) * playerSpinState->frictionScale;
        if (temp_f24 < 0.1) {
            temp_f24 = 0.1f;
        }
        
        if (playerSpinState->inputMagnitude == 0.0f) {
            temp_f24 = 0.0f;
        }

        playerSpinState->spinDirectionMagnitude -= 1.0f; 
        if (playerSpinState->spinDirectionMagnitude < 0.0f) {
            playerSpinState->spinDirectionMagnitude = 0.0f;
        }
    }

    playerStatus->currentStateTime++;
    
    switch (playerStatus->prevActionState) {
        case 0:
            player_input_to_move_vector(&sp10, &sp14);
            phys_update_interact_collider();
            if (check_input_jump()) {
                if (sp14 != 0.0f || playerStatus->targetYaw != sp10) {
                    playerStatus->targetYaw = sp10;
                }
            }
            playerStatus->currentSpeed = (sp14 != 0.0f) ? playerStatus->runSpeed * temp_f24 : 0.0f;
            break;
        case 1:
        case 2:
            playerStatus->currentSpeed = playerStatus->runSpeed * temp_f24;
            break;
    }
    if (playerStatus->fallState == 0) {
        playerSpinState->spinCountdown--;
        if (playerSpinState->spinCountdown > 0) {
            if (playerStatus->currentStateTime >= 2) {
                playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + playerStatus->spinRate);
            }
            return;
        } else {
            playerStatus->fallState = 1;
        }
    }
    
    if (playerStatus->fallState == 1) {
        sp10 = playerStatus->spriteFacingAngle;
        playerStatus->spriteFacingAngle = sp10 + playerStatus->spinRate;
        
        if (playerSpinState->hasBufferedSpin != 0) {
            playerStatus->currentStateTime = 2;
            playerStatus->fallState = 2;
            playerStatus->flags &= ~0x00020000;
            suggest_player_anim_clearUnkFlag(0x10002);
        } else if (sp10 < playerStatus->spriteFacingAngle) {
            if (playerStatus->spriteFacingAngle >= 180.0f && sp10 < 180.0f) {
                playerStatus->spriteFacingAngle = 180.0f;
                playerStatus->currentStateTime = 2;
                playerStatus->fallState = 2;
                playerStatus->flags &= ~0x00020000;
                suggest_player_anim_clearUnkFlag(0x10002);
            }
        } else if (playerStatus->spriteFacingAngle <= 0.0f && sp10 < 90.0f) {
            playerStatus->spriteFacingAngle = 0.0f;
            playerStatus->currentStateTime = 2;
            playerStatus->fallState = 2;
            playerStatus->flags &= ~0x00020000;
            suggest_player_anim_clearUnkFlag(0x10002);
        }
        playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle);
    }
}
