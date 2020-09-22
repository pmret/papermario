#include "common.h"

INCLUDE_ASM("code_102610_len_2330", func_802E0D90);
// Needs rodata support, is above func
/*void create_shadow_callback(Shadow* shadow) {
    shadow->scale.x = 0.1f;
    shadow->scale.y = 0.1f;
    shadow->scale.z = 0.1f;
}*/

INCLUDE_ASM("code_102610_len_2330", func_802E0DB0);

INCLUDE_ASM("code_102610_len_2330", func_802E0DE0);

void save_game_at_player_position(void) {
    GameStatus* gameStatus = GAME_STATUS;

    gameStatus->savedPos[0] = gPlayerStatusPtr->position.x;
    gameStatus->savedPos[1] = gPlayerStatusPtr->position.y;
    gameStatus->savedPos[2] = gPlayerStatusPtr->position.z;
    fio_save_game(gameStatus->saveSlot);
}

INCLUDE_ASM("code_102610_len_2330", func_802E1204);

INCLUDE_ASM("code_102610_len_2330", func_802E153C);

INCLUDE_ASM("code_102610_len_2330", func_802E234C);

INCLUDE_ASM("code_102610_len_2330", func_802E246C);
