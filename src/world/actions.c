#include "common.h"

s32 func_802B6000_E24920();
s32 func_802B6288_E23968();
s32 func_802B60B4_E240F4();
s32 func_802B6198_E241D8();
s32 func_802B6294_E242D4();
s32 func_802B6060_E27570();
s32 func_802B6348_E24388();
s32 func_802B61C0_E24AE0();
s32 func_802B6638_E29068();
s32 func_802B66A8_E25578();
s32 func_802B6350_E28D80();
s32 func_802B6508_E28F38();
s32 func_802B6230_E24800();
s32 func_802B6120_E2A7D0();
s32 func_802B63D4_E28E04();
s32 func_802B6478_E28EA8();
s32 func_802B60A4_E29514();
s32 func_802B609C_E28ACC();

f32 D_800F7B40 = 0.0f;
s32 D_800F7B44 = 0;
f32 D_800F7B48 = 0.0f;
s32 D_800F7B4C = 0;

s32 D_800F7B50[] = { 0x417C1B33, 0xC0EC5C14, 0x405C9AAA, 0xBF400000 };
s32 D_800F7B60[] = { 0x3E1E0C17, 0xBEB33DB0, 0xBE3AA2E4, 0x3C3CBE62 };
s32 D_800F7B70[] = { 0x40000000, 0x40800000, 0x42000000, 0xC2000000 };
s32 D_800F7B80[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 }; // possibly s16
s32 D_800F7B90[] = { 0x00000000, 0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x00390005, 0x00390008, 0x00390007, 0x00390013, 0x00390014, 0xFFFFFFFF, 0x005A0000, 0x005A0002, 0x005A0003, 0x005A0004, 0x005A0006, 0x005A0007, 0x005A0009, 0x005A000A, 0x005A000B, 0x005A001A, 0xFFFFFFFF, 0x00580000, 0x00580001, 0x00580002, 0x00580004, 0x00580005, 0x00580006, 0x00580007, 0x00580008, 0x00580009, 0x00580012, 0x00580014, 0x0058001B, 0xFFFFFFFF };
s32 D_800F7C1C[] = { 0x00580001, 0x00580004, 0x00580006, 0x00580008, 0x00580000 };
s32 D_800F7C30[] = { 0x0058001B, 0x00580001, 0x00580004, 0x00580006, 0x00580008, 0x00580000, 0x0058001B, 0x005A0003, 0x005A0006, 0x005A0009, 0x005A000B, 0x005A0000, 0x005A001A, 0x00390002, 0x00390003, 0x00390004, 0x00390005, 0x00390000, 0x00390014 };
s32 D_800F7C7C[] = { 0x800F7BE8, 0x800F7BE8, 0x800F7BBC, 0x800F7B94 };
s32 D_800F7C8C[] = {
    // TODO: struct for dma table
    // TODO: ld addrs
    (s32)&func_802B6000_E24920, &code_code_E23260_ROM_START, &code_code_E23260_ROM_END, 0x01000000,
    (s32)&func_802B6000_E24920, 0x00E236E0, 0x00E24040, 0x01000000,
    (s32)&func_802B6288_E23968, 0x00E236E0, 0x00E24040, 0x01000000,
    (s32)&func_802B60B4_E240F4, 0x00E24040, 0x00E245D0, 0x01000000,
    (s32)&func_802B60B4_E240F4, 0x00E24040, 0x00E245D0, 0x01000000,
    (s32)&func_802B60B4_E240F4, 0x00E24040, 0x00E245D0, 0x00000000,
    (s32)&func_802B60B4_E240F4, 0x00E24040, 0x00E245D0, 0x00000000,
    (s32)&func_802B6198_E241D8, 0x00E24040, 0x00E245D0, 0x00000000,
    (s32)&func_802B6294_E242D4, 0x00E24040, 0x00E245D0, 0x01000000,
    (s32)&func_802B6348_E24388, 0x00E24040, 0x00E245D0, 0x01000000,
    (s32)&func_802B6000_E24920, 0x00E24920, 0x00E24ED0, 0x01000000,
    (s32)&func_802B61C0_E24AE0, 0x00E24920, 0x00E24ED0, 0x01000000,
    (s32)&func_802B6638_E29068, 0x00E28A30, 0x00E291A0, 0x01000000,
    (s32)&func_802B6000_E24920, 0x00E26DE0, 0x00E27510, 0x00000000,
    (s32)&func_802B6000_E24920, 0x00E26DE0, 0x00E27510, 0x00000000,
    (s32)&func_802B6000_E24920, 0x00E26710, 0x00E26DE0, 0x00000000,
    (s32)&func_802B6000_E24920, 0x00E26710, 0x00E26DE0, 0x00000000,
    (s32)&func_802B6060_E27570, 0x00E27510, 0x00E27C90, 0x00000000,
    (s32)&func_802B66A8_E25578, 0x00E24ED0, 0x00E25D60, 0x00000000,
    (s32)&func_802B6350_E28D80, 0x00E28A30, 0x00E291A0, 0x01000000,
    (s32)&func_802B6508_E28F38, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32)&func_802B6000_E24920, 0x00E27C90, 0x00E27F40, 0x00000000,
    (s32)&func_802B6000_E24920, 0x00E287F0, 0x00E28A30, 0x00000000,
    (s32)&func_802B6000_E24920, 0x00E27F40, 0x00E287F0, 0x00000000,
    (s32)&func_802B6230_E24800, 0x00E245D0, 0x00E24920, 0x01000000,
    (s32)&func_802B6120_E2A7D0, 0x00E2A6B0, 0x00E2B530, 0x01000000,
    (s32)&func_802B6000_E24920, 0x00E25D60, 0x00E26710, 0x00000000,
    (s32)&func_802B63D4_E28E04, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32)&func_802B6478_E28EA8, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32)&func_802B60A4_E29514, 0x00E29470, 0x00E2A340, 0x00000000,
    (s32)&func_802B6000_E24920, 0x00E291A0, 0x00E29470, 0x00000000,
    (s32)&func_802B6000_E24920, 0x00E2A340, 0x00E2A6B0, 0x00000000,
    (s32)&func_802B6350_E28D80, 0x00E28A30, 0x00E291A0, 0x01000000,
    (s32)&func_802B6000_E24920, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32)&func_802B6000_E24920, 0x00E245D0, 0x00E24920, 0x01000000,
    (s32)&func_802B609C_E28ACC, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32)&func_802B6350_E28D80, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32)&func_802B6350_E28D80, 0x00E236E0, 0x00E24040, 0x00000000,
    (s32)&func_802B6350_E28D80, 0x00E28A30, 0x00E291A0, 0x01000000,
    NULL, // TODO: file split (world/actions.c)
};

#include "common.h"
#include "world/partners.h"

extern s32 D_8010C96C; // npc list index
extern s16 D_8010C9B0;

void func_800E26B0(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    playerStatus->jumpApexHeight = playerStatus->position.y;
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E26C4);

void set_action_state(s32 actionState);

void move_player(s32 duration, f32 heading, f32 speed) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

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
    PlayerStatus* playerStatus = PLAYER_STATUS;

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

PartnerID get_current_partner_id(void) {
    return gPlayerData.currentPartner;
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5098);

void func_800E5150(void) {
    gCollisionStatus.unk_0A = func_800E5174();
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5174);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", can_player_interact);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5348);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E546C);

void save_ground_pos(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    playerStatus->lastGoodPosition.x = playerStatus->position.x;
    playerStatus->lastGoodPosition.y = playerStatus->position.y;
    playerStatus->lastGoodPosition.z = playerStatus->position.z;
}

void func_800E5520(void) {
    D_8010C9B0 = 0;
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5530);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E58F0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5938);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E59A0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5A2C);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5C78);

void set_action_state(s32 actionState) {
    PlayerStatus* playerStatus = PLAYER_STATUS;
    PlayerData* playerData = PLAYER_DATA;
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
        PartnerID partner;

        if (playerStatus->unk_BF == 3) {
            actionState = ActionState_HIT_HAZARD;
        }

        // Whilst Sushie, Lakilester, Parakarry's ability is active, hazards have no effect.
        partner = playerData->currentPartner;

        if (partner == PartnerID_SUSHIE || partner == PartnerID_LAKILESTER || partner == PartnerID_PARAKARRY) {
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
    PlayerStatus* playerStatus = PLAYER_STATUS;
    do { } while (0); // required to match

    set_action_state((!is_ability_active(Ability_SLOW_GO)
                      && (SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1]) >= 0xBD2)) ? ActionState_RUN : ActionState_WALK);
}

void start_falling(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    set_action_state(ActionState_FALLING);
    playerStatus->gravityIntegrator[0] = 0.1143f;
    playerStatus->gravityIntegrator[1] = -0.2871f;
    playerStatus->gravityIntegrator[2] = -0.1823f;
    playerStatus->gravityIntegrator[3] = 0.01152f;
}

void start_bounce_a(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    set_action_state(ActionState_BOUNCE);
    playerStatus->gravityIntegrator[0] = 10.0f;
    playerStatus->gravityIntegrator[1] = -2.0f;
    playerStatus->gravityIntegrator[2] = 0.8f;
    playerStatus->gravityIntegrator[3] = -0.75f;
}

void start_bounce_b(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    set_action_state(ActionState_BOUNCE);
    playerStatus->gravityIntegrator[0] = 8.0f;
    playerStatus->gravityIntegrator[1] = -1.0f;
    playerStatus->gravityIntegrator[2] = 0;
    playerStatus->gravityIntegrator[3] = 0;
    playerStatus->flags |= 0x800000;
}

s32 check_input_hammer(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;
    PlayerData* playerData = PLAYER_DATA;

    if (playerStatus->pressedButtons & Button_B) {
        if (!(playerStatus->flags & 4)) {
            if (D_8010EBB0[0] != 1 || playerData->currentPartner != PartnerID_WATT) {
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

void func_800E636C(s32 arg0) {
    s32 listIndex = D_8010C96C;

    if (listIndex >= 0) {
        get_npc_by_index(listIndex)->currentAnim = arg0;
    }
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E63A4);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E6428);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E6500);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", make_disguise_npc);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E66C4);

