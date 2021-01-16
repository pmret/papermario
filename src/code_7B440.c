#include "common.h"

INCLUDE_ASM(s32, "code_7B440", update_player_input);

INCLUDE_ASM(s32, "code_7B440", func_800E205C);

void func_800E22E4(s32* arg0) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    *arg0 = (u16)playerStatus->currentButtons | (playerStatus->pressedButtons << 16);
}

INCLUDE_ASM(s32, "code_7B440", input_to_move_vector);

INCLUDE_ASM(s32, "code_7B440", func_800E23FC);

INCLUDE_ASM(s32, "code_7B440", func_800E24F8);
