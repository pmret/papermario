// this file and world/actions.c are candidates for merging

#include "common.h"
#include "world/partners.h"
#include "world/actions.h"
#include "npc.h"

extern s32 D_8010C924;
extern s32 D_8010C964;
extern s32 D_8010C96C; // npc list index
extern s32 gSpinHistoryBufferPos;
extern s16 D_8010C9B0;
extern s32 gSpinHistoryPosY[5];
extern s32 gSpinHistoryPosX[5];
extern s32 gSpinHistoryPosZ[5];
extern s16 gSpinHistoryPosAngle[5];

void func_800E5520(void) {
    D_8010C9B0 = 0;
}

INCLUDE_ASM(void, "7bb60_len_41b0", phys_adjust_cam_on_landing, void);

void phys_clear_spin_history(void) {
    s32 i;

    gSpinHistoryBufferPos = 0;

    for (i = 0; i < ARRAY_COUNT(gSpinHistoryPosY); i++) {
        gSpinHistoryPosAngle[i] = 180;
        gSpinHistoryPosY[i] = 0x80000000;
    }
}

f32 phys_get_spin_history(s32 lag, s32* x, s32* y, s32* z) {
    s32 idx = gSpinHistoryBufferPos;

    // Can't get this if/else to match otherwise...
    if (idx - lag >= 0) {
        idx -= lag;
    } else {
        idx = gSpinHistoryBufferPos - lag + 5;
    }

    *x = gSpinHistoryPosX[idx];
    *y = gSpinHistoryPosY[idx];
    *z = gSpinHistoryPosZ[idx];
    return gSpinHistoryPosAngle[idx];
}

void phys_reset_spin_history(void) {
    s32 i;

    mem_clear(&D_8010F250, sizeof(Temp8010F250));
    gSpinHistoryBufferPos = 0;

    for (i = 0; i < ARRAY_COUNT(gSpinHistoryPosAngle); i++) {
        gSpinHistoryPosAngle[i] = 0;
        gSpinHistoryPosX[i] = 0;
        gSpinHistoryPosY[i] = 0;
        gSpinHistoryPosZ[i] = 0;
    }

    D_8010C964 = 0;
    D_8010C924 = 0;
}

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_update_action_state);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_peach_update);

void set_action_state(s32 actionState) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    Temp8010F250* unknownStruct = &D_8010F250;

    if (playerStatus->flags & 0x200) {
        playerStatus->flags &= ~0x200;
        enable_player_input();
    }

    if (playerStatus->animFlags & 0x4000) {
        // TODO figure this out
#ifdef NON_EQUIVALENT
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
        s8 partner;

        if (playerStatus->unk_BF == 3) {
            actionState = ACTION_STATE_HIT_FIRE;
        }

        // Whilst Sushie, Lakilester, Parakarry's ability is active, hazards have no effect.
        partner = playerData->currentPartner;

        if (partner == PARTNER_SUSHIE || partner == PARTNER_LAKILESTER || partner == PARTNER_PARAKARRY) {
            if (gPartnerActionStatus.actionState.b[0] != 0) {
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

    if (unknownStruct->unk_30 != 0) {
        sfx_stop_sound(unknownStruct->unk_30);
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
            if (gPartnerActionStatus.actionState.b[0] != 1 || gPlayerData.currentPartner != PARTNER_WATT) {
                if (gPlayerData.hammerLevel != -1) {
                    set_action_state(ACTION_STATE_HAMMER);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

INCLUDE_ASM(s32, "7bb60_len_41b0", check_input_jump, void);

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


#ifdef NON_EQUIVALENT
Npc* peach_make_disguise_npc(s32 peachDisguise) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    NpcBlueprint blueprint;
    Npc* npc;
    f32 yaw;

    if (peachDisguise == 0) {
        return NULL;
    }

    playerStatus->colliderHeight = 37;
    playerStatus->colliderDiameter = 38;
    playerStatus->peachDisguise = gGameStatusPtr->peachDisguise = peachDisguise;

    blueprint.flags = NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_100 | NPC_FLAG_40000;
    blueprint.initialAnim = world_actions_peachDisguises[playerStatus->peachDisguise].idle;
    blueprint.onRender = NULL;
    blueprint.onUpdate = NULL;
    D_8010C96C = _create_npc_standard(&blueprint, &D_800F7C7C[playerStatus->peachDisguise]);
    npc = get_npc_by_index(D_8010C96C);

    disable_npc_shadow(npc);

    if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
        yaw = 180.0f;
    } else {
        yaw = 0.0f;
    }

    set_npc_yaw(npc, yaw);

    npc->pos.x = playerStatus->position.x;
    npc->pos.y = playerStatus->position.y;
    npc->pos.z = playerStatus->position.z;

    return npc;
}
#else
INCLUDE_ASM(Npc*, "7bb60_len_41b0", peach_make_disguise_npc, s32 peachDisguise);
#endif

INCLUDE_ASM(s32, "7bb60_len_41b0", peach_disguise_check_overlaps);

