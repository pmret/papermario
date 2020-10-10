#include "common.h"

void func_800E26B0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->jumpApexHeight = playerStatus->position.y;
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E26C4);

void set_action_state(s32 actionState);

void move_player(s16 duration, f32 heading, f32 speed) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->flags |= 0x4000;
    playerStatus->heading = heading;
    playerStatus->moveFrames = duration;
    playerStatus->currentSpeed = speed;

    if (!(playerStatus->animFlags & 0x400000)) {
        set_action_state(speed > playerStatus->walkSpeed ? ActionState_RUN : ActionState_WALK);
    }
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", collision_main_above);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E29C8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E2BB0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", update_fall_state);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E2F60);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", gravity_use_fall_parms);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E3100);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E315C);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", phys_player_land);

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

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E3514);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", collision_main_lateral);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", collision_check_player_intersecting_world);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4404);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4508);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E45E0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E46C8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4744);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4AD8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4B40);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4BB8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4F10);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", check_input_midair_jump);

PartnerId get_current_partner_id(void) {
    return gPlayerData.currentPartner;
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5098);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5150);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5174);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E52F8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5348);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E546C);

void save_ground_pos(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->lastGoodPosition.x = playerStatus->position.x;
    playerStatus->lastGoodPosition.y = playerStatus->position.y;
    playerStatus->lastGoodPosition.z = playerStatus->position.z;
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5520);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5530);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E58F0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5938);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E59A0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5A2C);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5C78);

void set_action_state(s32 actionState) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    UNK_TYPE* unknownStruct = &D_8010F250;

    if (playerStatus->flags & 0x200) {
        playerStatus->flags &= ~0x200;
        enable_player_input();
    }

    if (playerStatus->animFlags & 0x4000) {
        if (actionState < ActionState_CONVERSATION) {
            if (actionState >= 0) {
                playerStatus->prevActionState = playerStatus->actionState;
                playerStatus->actionState = actionState;
                playerStatus->flags |= 0x80000000;
            }
        }
        return;
    }

    if (actionState == ActionState_HIT_HAZARD || actionState == ActionState_HIT_LAVA) {
        u8 partner;

        if (playerStatus->unk_BF == 3) {
            actionState = ActionState_HIT_HAZARD;
        }

        // Whilst Lakilester, Bow, or Parakarry's ability is active, hazards have no effect.
        partner = playerData->currentPartner;
        if (((u8)(partner - 7) < 2) || (playerData->currentPartner == PartnerId_PARAKARRY)) {
            if (D_8010EBB0[0]) {
                playerStatus->animFlags |= 0x4;
                playerStatus->flags |= 0x800;
                return;
            }
        }
    }

    if (actionState == ActionState_SLIDING) {
        playerStatus->flags |= 0x10;
        playerStatus->moveFrames = 0;
        playerStatus->flags &= ~0x4000;
    }

    playerStatus->prevActionState = playerStatus->actionState;
    if (actionState == ActionState_USE_TWEESTER) {
        playerStatus->prevActionState = ActionState_IDLE;
    }

    if (actionState == ActionState_ENEMY_FIRST_STRIKE) {
        playerStatus->animFlags |= 4;
    }
    playerStatus->actionState = actionState;
    playerStatus->flags |= 0x80000000;

    if (playerStatus->actionState == ActionState_SPIN) {
        return;
    }

    playerStatus->flags &= ~0x20000;
    playerStatus->animFlags &= ~0x10000;

    if (unknownStruct[0xC]) {
        stop_sound(unknownStruct[0xC]);
    }

    if (playerStatus->unk_D8) {
        playerStatus->unk_D8[3][9] = 0xA;
        playerStatus->unk_D8 = NULL;
    }
}

void update_locomotion_state(void) {
    PlayerStatus* playerStatus = (&gPlayerStatus);
    do { } while (0); // required to match

    set_action_state((!is_ability_active(Ability_SLOW_GO)
                      && (SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1]) >= 0xBD2)) ? ActionState_RUN : ActionState_WALK);
}

void start_falling(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    set_action_state(ActionState_FALLING);
    playerStatus->gravityIntegrator[0] = 0.1143f;
    playerStatus->gravityIntegrator[1] = -0.2871f;
    playerStatus->gravityIntegrator[2] = -0.1823f;
    playerStatus->gravityIntegrator[3] = 0.01152f;
}

void start_bounce_a(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    set_action_state(ActionState_BOUNCE);
    playerStatus->gravityIntegrator[0] = 10.0f;
    playerStatus->gravityIntegrator[1] = -2.0f;
    playerStatus->gravityIntegrator[2] = 0.8f;
    playerStatus->gravityIntegrator[3] = -0.75f;
}

void start_bounce_b(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    set_action_state(ActionState_BOUNCE);
    playerStatus->gravityIntegrator[0] = 8.0f;
    playerStatus->gravityIntegrator[1] = -1.0f;
    playerStatus->gravityIntegrator[2] = 0;
    playerStatus->gravityIntegrator[3] = 0;
    playerStatus->flags |= 0x800000;
}

s32 check_input_hammer(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (playerStatus->pressedButtons & Button_B) {
        if (!(playerStatus->flags & 4)) {
            if (D_8010EBB0[0] != 1 || playerData->currentPartner != PartnerId_WATT) {
                if (playerData->hammerLevel != -1) {
                    set_action_state(ActionState_HAMMER);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", check_input_jump);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", check_input_spin);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E636C);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E63A4);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E6428);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E6500);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", make_disguise_npc);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E66C4);
