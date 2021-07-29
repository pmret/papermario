#include "common.h"
#include "world/partners.h"

extern s32 D_8010C96C; // npc list index
extern s16 D_8010C9B0;

void record_jump_apex(void) {
    gPlayerStatus.jumpApexHeight = gPlayerStatus.position.y;
}

s32 can_trigger_loading_zone(void) {
    PlayerData* playerData = &gPlayerData;
    s32 actionState = gPlayerStatusPtr->actionState;
    Temp8010EBB0* temp_8010EBB0 = &D_8010EBB0;

    if (actionState == ACTION_STATE_IDLE ||
        actionState == ACTION_STATE_WALK ||
        actionState == ACTION_STATE_RUN ||
        actionState == ACTION_STATE_USE_TWEESTER ||
        actionState == ACTION_STATE_SPIN
       ) {
        return TRUE;
    }

    if (actionState == ACTION_STATE_RIDE) {
        if (playerData->currentPartner == PARTNER_LAKILESTER || playerData->currentPartner == PARTNER_BOW) {
            if (temp_8010EBB0->unk_00 != 0) {
                return TRUE;
            } else {
                gPlayerStatusPtr->animFlags |= 4;
                return FALSE;
            }
        } else {
            if (temp_8010EBB0->unk_03 == 6 || temp_8010EBB0->unk_03 == 7) {
                return temp_8010EBB0->unk_00 != 0;
            }
            if (temp_8010EBB0->unk_03 == 4) {
                gPlayerStatusPtr->animFlags |= 4;
                return FALSE;
            }
        }
    }
    return FALSE;
}

void set_action_state(s32 actionState);

void move_player(s32 duration, f32 heading, f32 speed) {
    gPlayerStatus.flags |= 0x4000;
    gPlayerStatus.heading = heading;
    gPlayerStatus.moveFrames = duration;
    gPlayerStatus.currentSpeed = speed;

    if (!(gPlayerStatus.animFlags & 0x400000)) {
        set_action_state(speed > gPlayerStatus.walkSpeed ? ACTION_STATE_RUN : ACTION_STATE_WALK);
    }
}

INCLUDE_ASM(s32, "7bb60_len_41b0", collision_main_above);

INCLUDE_ASM(s32, "7bb60_len_41b0", func_800E29C8);

INCLUDE_ASM(s32, "7bb60_len_41b0", func_800E2BB0);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_update_jump);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_init_integrator_for_current_state);

#ifdef NON_MATCHING
// void gravity_use_fall_parms(void) {
//     f32* floats = D_800F7B60;
// do { } while (0);
//     if (gPlayerStatus.flags & 0x40000) {
//         gPlayerStatus.gravityIntegrator[0] = *floats++ / 12.0f;
//         gPlayerStatus.gravityIntegrator[1] = *floats++ / 12.0f;
//         gPlayerStatus.gravityIntegrator[2] = *floats++ / 12.0f;
//         gPlayerStatus.gravityIntegrator[3] = *floats++ / 12.0f;
//     } else {
//         gPlayerStatus.gravityIntegrator[0] = *floats++;
//         gPlayerStatus.gravityIntegrator[1] = *floats++;
//         gPlayerStatus.gravityIntegrator[2] = *floats++;
//         gPlayerStatus.gravityIntegrator[3] = *floats++;
//     }
// }
void gravity_use_fall_parms(void) {
    PlayerStatus* playerStatus;
    f32* floats = D_800F7B60;
    do {} while (0);
    playerStatus = &gPlayerStatus;
    if (playerStatus->flags & 0x40000) {
        playerStatus->gravityIntegrator[0] = (*(floats++)) / 12.0f;
        playerStatus->gravityIntegrator[1] = (*(floats++)) / 12.0f;
        playerStatus->gravityIntegrator[2] = (*(floats++)) / 12.0f;
        playerStatus->gravityIntegrator[3] = (*(floats++)) / 12.0f;
    } else {
        playerStatus->gravityIntegrator[0] = *(floats++);
        playerStatus->gravityIntegrator[1] = *(floats++);
        playerStatus->gravityIntegrator[2] = *(floats++);
        playerStatus->gravityIntegrator[3] = *(floats++);
    }
}
#else
INCLUDE_ASM(s32, "7bb60_len_41b0", gravity_use_fall_parms);
#endif

void phys_update_falling(void) {
    if (gPlayerStatus.actionState != ACTION_STATE_LAND_ON_SWITCH && gPlayerStatus.actionState != ACTION_STATE_BOUNCE) {
        s32* colliderID;

        gPlayerStatus.position.y = player_check_collision_below(func_800E34D8(), &colliderID);

        func_800E315C(colliderID);
    }
}

INCLUDE_ASM(s32, "7bb60_len_41b0", func_800E315C);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_player_land);

f32 integrate_gravity(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & 0x40000) {
        playerStatus->gravityIntegrator[2] += playerStatus->gravityIntegrator[3] / 1.7f;
        playerStatus->gravityIntegrator[1] += playerStatus->gravityIntegrator[2] / 1.7f;
        playerStatus->gravityIntegrator[0] += playerStatus->gravityIntegrator[1] / 1.7f;
    } else {
        playerStatus->gravityIntegrator[2] += playerStatus->gravityIntegrator[3];
        playerStatus->gravityIntegrator[1] += playerStatus->gravityIntegrator[2];
        playerStatus->gravityIntegrator[0] += playerStatus->gravityIntegrator[1];
    }
    return playerStatus->gravityIntegrator[0];
}

f32 func_800E34D8(void) {
    f32 ret = integrate_gravity();

    if (func_800E0208() != 0) {
        ret = 0.0f;
    }
    return ret;
}

INCLUDE_ASM(f32, "7bb60_len_41b0", player_check_collision_below, f32 arg0, s32* colliderID);

INCLUDE_ASM(s32, "7bb60_len_41b0", collision_main_lateral);

//something weird with hitID
#ifdef NON_MATCHING
s32 collision_check_player_intersecting_world(s32 arg0, s32 arg1, f32 arg2) {
    f32 angle = 0.0f;
    s32 ret = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        f32 x = gPlayerStatusPtr->position.x;
        f32 y = gPlayerStatusPtr->position.y + arg1;
        f32 z = gPlayerStatusPtr->position.z;
        s32 hitID = player_test_lateral_overlap(arg0, gPlayerStatusPtr, &x, &y, &z, 0, angle);

        if (hitID >= 0) {
            ret = hitID;
        }

        gPlayerStatusPtr->position.x = x;
        gPlayerStatusPtr->position.z = z;
        angle += 90.0f;
    }

    return ret;
}
#else
INCLUDE_ASM(s32, "7bb60_len_41b0", collision_check_player_intersecting_world, s32 arg0, s32 arg1, f32 arg2);
#endif

s32 func_800E4404(s32 arg0, s32 arg1, f32 arg2, f32* outX, f32* outY, f32* outZ) {
    f32 angle = 0.0f;
    s32 ret = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        f32 x = *outX;
        f32 y = *outY + arg1;
        f32 z = *outZ;
        s32 hitID = player_test_lateral_overlap(arg0, gPlayerStatusPtr, &x, &y, &z, 0, angle);

        if (hitID >= 0) {
            ret = hitID;
        }

        *outX = x;
        *outZ = z;
        angle += 90.0f;
    }

    return ret;
}

void collision_check_player_overlaps(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 temp_64 = playerStatus->unk_64;

    if (temp_64 != 0.0f) {
        f32 x = playerStatus->position.x;
        f32 y = playerStatus->position.y;
        f32 z = playerStatus->position.z;

        player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, temp_64, playerStatus->unk_88);

        temp_64 -= playerStatus->runSpeed / 10.0f;
        playerStatus->position.x = x;
        playerStatus->position.y = y;
        playerStatus->position.z = z;

        if (temp_64 < 0.0f) {
            temp_64 = 0.0f;
        }

        playerStatus->unk_64 = temp_64;
    }
}

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_should_player_be_sliding);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_is_on_sloped_ground);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_main_collision_below);

void func_800E4AD8(s32 arg0) {
    Camera* currentCamera = &gCameras[gCurrentCameraID];

    collision_check_player_intersecting_world(arg0, 0, gPlayerStatus.spriteFacingAngle - 90.0f + currentCamera->currentYaw);
}

void func_800E4B40(s32 arg0, f32* arg1, f32* arg2, f32* arg3) {
    Camera* currentCamera = &gCameras[gCurrentCameraID];

    func_800E4404(arg0, 0, gPlayerStatus.spriteFacingAngle - 90.0f + currentCamera->currentYaw, arg1, arg2, arg3);
}

INCLUDE_ASM(s32, "7bb60_len_41b0", collision_lava_reset_check_additional_overlaps);

void func_800E4F10(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 tempB = 0;
    f32 yaw = playerStatus->targetYaw;
    f32 x = playerStatus->position.x;
    f32 y = playerStatus->position.y;
    f32 z = playerStatus->position.z;
    s32 temp = player_test_move_without_slipping(&gPlayerStatus, &x, &y, &z, 0, yaw, &tempB);

    playerStatus->position.x = x;
    playerStatus->position.z = z;

    if (tempB != 0 && temp < 0 && playerStatus->actionState != ACTION_STATE_18 && playerStatus->currentSpeed != 0.0f) {
        set_action_state(ACTION_STATE_18);
    }
}

void check_input_midair_jump(void) {
    if (!(gPlayerStatus.flags & 0x800018) &&
        !(gPlayerStatus.animFlags & 0x4001) &&
        gPlayerStatus.unk_C2 >= 6 &&
        gPlayerStatus.decorationList < 0x12 &&
        gPlayerStatus.pressedButtons & A_BUTTON) {

        switch (gPlayerData.bootsLevel) {
            case 0:
                break;
            case 1:
                set_action_state(ACTION_STATE_SPIN_JUMP);
                gPlayerStatus.flags |= 8;
                break;
            case 2:
                set_action_state(ACTION_STATE_ULTRA_JUMP);
                gPlayerStatus.flags |= 8;
                break;
        }
    }
}

PartnerID get_current_partner_id(void) {
    return gPlayerData.currentPartner;
}

void try_player_footstep_sounds(s32 arg0) {
    if ((gGameStatusPtr->frameCounter % arg0) == 0) {
        u8 colliderType = get_collider_type_by_id(gCollisionStatus.currentFloor);
        s32 soundID;
        s32 soundID2;

        if (colliderType == 6 || colliderType == 9) {
            soundID = 0x143;
            soundID2 = 0x144;
        } else {
            soundID = SOUND_STEP1;
            soundID2 = SOUND_STEP2;
        }

        if (D_800F7B80 == 0) {
            soundID = soundID2;
        }

        sfx_play_sound_at_player(soundID, 0);
        D_800F7B80 ^= 1;
    }
}

void phys_update_interact_collider(void) {
    gCollisionStatus.unk_0A = phys_check_interactable_collision();
}

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_check_interactable_collision);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_can_player_interact);

INCLUDE_ASM(f32, "7bb60_len_41b0", func_800E5348, void);

void player_get_camera_facing_angle(void) {
    f32 angle = 0.0f;

    if (gPlayerStatus.spriteFacingAngle >= 90.0f && gPlayerStatus.spriteFacingAngle < 270.0f) {
        angle = 180.0f;
    }

    angle = angle + gCameras[0].currentYaw + 90.0f;

    clamp_angle(angle);
}

void phys_save_ground_pos(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->lastGoodPosition.x = playerStatus->position.x;
    playerStatus->lastGoodPosition.y = playerStatus->position.y;
    playerStatus->lastGoodPosition.z = playerStatus->position.z;
}

void func_800E5520(void) {
    D_8010C9B0 = 0;
}

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_adjust_cam_on_landing);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_clear_spin_history);

INCLUDE_ASM(f32, "7bb60_len_41b0", phys_get_spin_history, s32 lag, s32* x, s32* y, s32* z);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_reset_spin_history);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_update_action_state);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_peach_update);

void set_action_state(s32 actionState) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    UNK_TYPE* unknownStruct = &D_8010F250;

    if (playerStatus->flags & 0x200) {
        playerStatus->flags &= ~0x200;
        enable_player_input();
    }

    if (playerStatus->animFlags & 0x4000) {
        // TODO figure this out
#ifdef NON_MATCHING
        if (
            actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK ||
            actionState == ACTION_STATE_RUN || actionState == ACTION_STATE_JUMP ||
            actionState == ACTION_STATE_BOUNCE || actionState == ACTION_STATE_HOP ||
            actionState == ACTION_STATE_LAUNCH || actionState == ACTION_STATE_LAND_ON_SWITCH ||
            actionState == ACTION_STATE_FALLING || actionState == ACTION_STATE_STEP_DOWN ||
            actionState == ACTION_STATE_LAND || actionState == ACTION_STATE_STEP_DOWN_LAND
        ) {
#else
        if (actionState < ACTION_STATE_TALK)
            if (actionState >= 0) {
#endif
            playerStatus->prevActionState = playerStatus->actionState;
            playerStatus->actionState = actionState;
            playerStatus->flags |= 0x80000000;
        }
        return;
    }

    if (actionState == ACTION_STATE_HIT_FIRE || actionState == ACTION_STATE_HIT_LAVA) {
        PartnerID partner;

        if (playerStatus->unk_BF == 3) {
            actionState = ACTION_STATE_HIT_FIRE;
        }

        // Whilst Sushie, Lakilester, Parakarry's ability is active, hazards have no effect.
        partner = playerData->currentPartner;

        if (partner == PARTNER_SUSHIE || partner == PARTNER_LAKILESTER || partner == PARTNER_PARAKARRY) {
            if (D_8010EBB0.unk_00 != 0) {
                playerStatus->animFlags |= 0x4;
                playerStatus->flags |= 0x800;
                return;
            }
        }
    }

    if (actionState == ACTION_STATE_SLIDE) {
        playerStatus->flags |= 0x10;
        playerStatus->moveFrames = 0;
        playerStatus->flags &= ~0x4000;
    }

    playerStatus->prevActionState = playerStatus->actionState;
    if (actionState == ACTION_STATE_USE_TWEESTER) {
        playerStatus->prevActionState = ACTION_STATE_IDLE;
    }

    if (actionState == ACTION_STATE_ENEMY_FIRST_STRIKE) {
        playerStatus->animFlags |= 4;
    }
    playerStatus->actionState = actionState;
    playerStatus->flags |= 0x80000000;

    if (playerStatus->actionState == ACTION_STATE_SPIN) {
        return;
    }

    playerStatus->flags &= ~0x20000;
    playerStatus->animFlags &= ~0x10000;

    if (unknownStruct[0xC]) {
        sfx_stop_sound(unknownStruct[0xC]);
    }

    if (playerStatus->unk_D8) {
        playerStatus->unk_D8[3][9] = 0xA;
        playerStatus->unk_D8 = NULL;
    }
}

void update_locomotion_state(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    do { } while (0); // required to match

    set_action_state((!is_ability_active(ABILITY_SLOW_GO)
                      && (SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1]) >= 0xBD2)) ? ACTION_STATE_RUN : ACTION_STATE_WALK);
}

void start_falling(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    set_action_state(ACTION_STATE_FALLING);
    playerStatus->gravityIntegrator[0] = 0.1143f;
    playerStatus->gravityIntegrator[1] = -0.2871f;
    playerStatus->gravityIntegrator[2] = -0.1823f;
    playerStatus->gravityIntegrator[3] = 0.01152f;
}

void start_bounce_a(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    set_action_state(ACTION_STATE_BOUNCE);
    playerStatus->gravityIntegrator[0] = 10.0f;
    playerStatus->gravityIntegrator[1] = -2.0f;
    playerStatus->gravityIntegrator[2] = 0.8f;
    playerStatus->gravityIntegrator[3] = -0.75f;
}

void start_bounce_b(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    set_action_state(ACTION_STATE_BOUNCE);
    playerStatus->gravityIntegrator[0] = 8.0f;
    playerStatus->gravityIntegrator[1] = -1.0f;
    playerStatus->gravityIntegrator[2] = 0;
    playerStatus->gravityIntegrator[3] = 0;
    playerStatus->flags |= 0x800000;
}

// TODO playerData isn't used
s32 check_input_hammer(void) {
    PlayerData* playerData = &gPlayerData;

    if (gPlayerStatus.pressedButtons & BUTTON_B) {
        if (!(gPlayerStatus.flags & 4)) {
            if (D_8010EBB0.unk_00 != 1 || gPlayerData.currentPartner != PARTNER_WATT) {
                if (gPlayerData.hammerLevel != -1) {
                    set_action_state(ACTION_STATE_HAMMER);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

INCLUDE_ASM(s32, "7bb60_len_41b0", check_input_jump);

void check_input_spin(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Temp8010F250* temp_8010F250 = &D_8010F250;
    Temp8010F250* temp2 = temp_8010F250;

    if (!(playerStatus->flags & (PLAYER_ANIM_FLAG_8BIT_MARIO | PLAYER_ANIM_FLAG_PEACH_PHYSICS)) &&
        !(playerStatus->animFlags & 1) &&
        !(playerStatus->currentButtons & D_CBUTTONS) &&
        !is_ability_active(ABILITY_SLOW_GO)) {

        s32 actionState = playerStatus->actionState;
        s32 btnPressed = playerStatus->pressedButtons & Z_TRIG;

        // TODO
        if (actionState != 0x21) {
            if (actionState < 0x22) {
                if (actionState < 3) {
                    if (actionState >= 0 && !(playerStatus->animFlags & 0x10000)) {
                        if (btnPressed || temp_8010F250->unk_01) {
                            set_action_state(ACTION_STATE_SPIN);
                            if (temp_8010F250->unk_01 != 0) {
                                if (temp_8010F250->unk_08 != 0 || temp_8010F250->unk_0C != 0) {
                                    playerStatus->prevActionState = temp2->unk_07;
                                } else {
                                    playerStatus->prevActionState = ACTION_STATE_IDLE;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void peach_set_disguise_anim(s32 arg0) {
    s32 listIndex = D_8010C96C;

    if (listIndex >= 0) {
        get_npc_by_index(listIndex)->currentAnim.w = arg0;
    }
}

void func_800E63A4(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (arg0 != 0) {
        set_action_state(ACTION_STATE_SNEAKY_PARASOL);
    } else {
        playerStatus->animFlags &= ~PLAYER_ANIM_FLAG_IN_DISGUISE;
        gGameStatusPtr->peachFlags &= ~0x2;
        playerStatus->peachDisguise = 0;
        free_npc_by_index(D_8010C96C);
        set_action_state(ACTION_STATE_IDLE);
        playerStatus->colliderHeight = 55;
        playerStatus->colliderDiameter = 38;
    }
}

void peach_check_for_parasol_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 actionState = playerStatus->actionState;
    Npc* disguiseNpc;

    if (actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK || actionState == ACTION_STATE_RUN) {
        if (D_8010C92C != 0) {
            D_8010C92C--;
            if (D_8010C92C == 0) {
                if (gGameStatusPtr->peachFlags & 2) {
                    playerStatus->animFlags |= PLAYER_ANIM_FLAG_IN_DISGUISE;
                    gGameStatusPtr->peachFlags |= 2;

                    disguiseNpc = peach_make_disguise_npc(gGameStatusPtr->peachDisguise);
                    if (disguiseNpc != NULL) {
                        disguiseNpc->flags &= ~NPC_FLAG_40000;
                    }
                }
            }
        } else if (gGameStatusPtr->peachFlags & 4 && playerStatus->pressedButtons & B_BUTTON) {
            set_action_state(ACTION_STATE_SNEAKY_PARASOL);
        }
    }
}

void peach_sync_disguise_npc(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (D_8010C96C >= 0) {
        Npc* npc = get_npc_by_index(D_8010C96C);

        if (npc->flags & NPC_FLAG_40000) {
            npc->renderYaw = playerStatus->spriteFacingAngle;
        } else {
            npc->yaw = playerStatus->targetYaw;
        }

        npc->pos.x = playerStatus->position.x;
        npc->pos.y = playerStatus->position.y;
        npc->pos.z = playerStatus->position.z;
    }
}

INCLUDE_ASM(Npc*, "7bb60_len_41b0", peach_make_disguise_npc, s32 peachDisguise);

INCLUDE_ASM(s32, "7bb60_len_41b0", peach_disguise_check_overlaps);

