#include "common.h"

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DC500);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DC778);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DCB7C);

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

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFEFC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFF50);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFF78);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DFFCC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0088);

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

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E01DC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0208);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0260);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0294);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0330);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0374);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0398);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E04D0);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0514);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0538);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0580);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0658);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E069C);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E06C0);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E06D8);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0818);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0AD0);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E0B14);

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

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E22E4);

INCLUDE_ASM(s32, "code_759b0_len_61b0", input_to_move_vector);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E23FC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800E24F8);
