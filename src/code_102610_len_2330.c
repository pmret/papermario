#include "common.h"

INCLUDE_ASM(s32, "code_102610_len_2330", create_shadow_callback);
// Needs rodata support
/*void create_shadow_callback(Shadow* shadow) {
    shadow->scale.x = 0.1f;
    shadow->scale.y = 0.1f;
    shadow->scale.z = 0.1f;
}*/

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E0DB0);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E0DE0);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E10F4);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E114C);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E117C);

void save_game_at_player_position(void) {
    GameStatus* gameStatus = GAME_STATUS;

    gameStatus->savedPos.x = gPlayerStatusPtr->position.x;
    gameStatus->savedPos.y = gPlayerStatusPtr->position.y;
    gameStatus->savedPos.z = gPlayerStatusPtr->position.z;
    fio_save_game(gameStatus->saveSlot);
}

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E1204);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E1270);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E1298);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E12F8);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E1328);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E1350);

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E13B8);
