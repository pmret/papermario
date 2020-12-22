#include "common.h"

extern s32 D_8010C920;
extern s32 D_8010C93C;
extern s32 D_8010C940;
extern s32 D_8010C950;
extern s32 D_8010C958;

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DC500);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DC778);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DCB7C, s32 arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DCE70);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD04C);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD228);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD44C);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD5B4);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD618);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD8FC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DDAE4);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DDC44);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DDCEC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DDD94);

INCLUDE_ASM(s32, "code_759b0_len_61b0", test_below_player);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DE46C);

INCLUDE_ASM(s32, "code_759b0_len_61b0", trace_below_player);

INCLUDE_ASM(s32, "code_759b0_len_61b0", collision_check_above);

INCLUDE_ASM(s32, "code_759b0_len_61b0", trace_above_player);

INCLUDE_ASM(s32, "code_759b0_len_61b0", do_lateral_collision);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DEE5C);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DF15C);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DF3FC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", test_player_lateral);

INCLUDE_ASM(s32, "code_759b0_len_61b0", update_player);

INCLUDE_ASM(s32, "code_759b0_len_61b0", check_input_use_partner);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFAAC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFBE8);

void clear_player_status(void) {
    mem_clear(&gPlayerStatus, sizeof(gPlayerStatus));
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFC74);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFCF4);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFD48);

void func_800DFEFC(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;
    s32 temp_v0 = func_800DFD48();

    if (temp_v0 != -1) {
        playerStatus->anim = temp_v0;
        playerStatus->unk_BC = 0;
        playerStatus->flags &= ~0x10000000;
    }
}

void func_800DFF50(s32 arg0) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    playerStatus->anim = arg0;
    playerStatus->unk_BC = 0;
    playerStatus->flags &= ~0x10000000;
}

void func_800DFF78(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;
    s32 temp_v0 = func_800DFD48();

    if (temp_v0 != -1) {
        playerStatus->anim = temp_v0;
        playerStatus->unk_BC = 0;
        playerStatus->flags |= 0x10000000;
    }
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFFCC);

// dist_to_player2D
f32 func_800E0088(f32 x, f32 z) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    return dist2D(x, z, playerStatus->position.x, playerStatus->position.z);
}

void enable_player_shadow(void) {
    get_shadow_by_index(D_8010F094)->flags &= ~1;
}

void disable_player_shadow(void) {
    get_shadow_by_index(D_8010F094)->flags |= 1;
}

s32 disable_player_static_collisions(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->flags |= 0x1000;
    playerStatus->enableCollisionOverlapsCheck++;
    return playerStatus->enableCollisionOverlapsCheck;
}

s32 enable_player_static_collisions(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->enableCollisionOverlapsCheck--;
    if (playerStatus->enableCollisionOverlapsCheck == 0) {
        playerStatus->flags &= ~0x1000;
    }
    return playerStatus->enableCollisionOverlapsCheck;
}

s32 disable_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->flags |= 0x2000;
    playerStatus->statusMenuCounterinputEnabledCounter++;
    return playerStatus->statusMenuCounterinputEnabledCounter;
}

s32 enable_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->statusMenuCounterinputEnabledCounter--;
    if (playerStatus->statusMenuCounterinputEnabledCounter == 0) {
        playerStatus->flags &= ~0x2000;
    }
    return playerStatus->statusMenuCounterinputEnabledCounter;
}

void func_800E01DC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->animFlags & 0x10) {
        playerStatus->flags |= 0x8000000;
    }
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0208);

void func_800E0260(void) {
    func_800E0658();
    func_800E0AD0();
    func_800E04D0();
    func_800E0330();
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0294);

void func_800E0330(void) {
    if ((gPlayerStatusPtr->animFlags & 0x100) && (D_8010C93C != 0)) {
        func_802B7000();
    }
}

void func_800E0374(void) {
    D_8010C93C = 0;
    gPlayerStatusPtr->animFlags &= ~0x100;
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0398);

void func_800E04D0(void) {
    if ((gPlayerStatusPtr->animFlags & 0x40) && (D_8010C920 != 0)) {
        func_802B71D4();
    }
}

void func_800E0514(void) {
    D_8010C920 = 0;
    gPlayerStatusPtr->animFlags &= ~0x40;
}

s32 func_800E0538(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;
    s32* unk_C8 = playerStatus->unk_C8;
    s32 ret = 0;
    s32 cond;

    if (unk_C8 != NULL && !(*unk_C8 & 0x10000000)) {
        cond = (playerStatus->flags & 0x2002000) == 0x2000000;
        ret = cond;
    }
    return ret;
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0580);

void func_800E0658(void) {
    if ((gPlayerStatusPtr->animFlags & 0x20) && (D_8010C940 != 0)) {
        func_802B71C8();
    }
}

void func_800E069C(void) {
    D_8010C940 = 0;
    gPlayerStatusPtr->animFlags &= ~0x20;
}

void func_800E06C0(s32 arg0) {
    D_8010C950 = (arg0 == 1);
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E06D8);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0818);

void func_800E0AD0(void) {
    if ((gPlayerStatusPtr->animFlags & 0x10) && (D_8010C958 != 0)) {
        func_802B71E8();
    }
}

void func_800E0B14(void) {
    D_8010C958 = 0;
    gPlayerStatusPtr->animFlags &= ~0x10;
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0B38);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0B90);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0FEC);

void render_player(void) {
    if (!GAME_STATUS->disableScripts) {
        render_player_model();
    }
}

INCLUDE_ASM(void, "code_759b0_len_61b0", render_player_model);

INCLUDE_ASM(s32, "code_759b0_len_61b0", appendGfx_player);

INCLUDE_ASM(s32, "code_759b0_len_61b0", appendGfx_player_spin);

INCLUDE_ASM(s32, "code_759b0_len_61b0", update_player_shadow);

INCLUDE_ASM(s32, "code_759b0_len_61b0", update_player_input);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E205C);

void func_800E22E4(s32* arg0) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    *arg0 = (u16)playerStatus->currentButtons | (playerStatus->pressedButtons << 16);
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", input_to_move_vector);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E23FC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E24F8);
