#include "common.h"

INCLUDE_ASM("code_102610_len_2330", create_shadow_callback);
// Needs rodata support
/*void create_shadow_callback(Shadow* shadow) {
    shadow->scale.x = 0.1f;
    shadow->scale.y = 0.1f;
    shadow->scale.z = 0.1f;
}*/

INCLUDE_ASM("code_102610_len_2330", func_802E0DB0);

INCLUDE_ASM("code_102610_len_2330", func_802E0DE0);

INCLUDE_ASM("code_102610_len_2330", func_802E10F4);

INCLUDE_ASM("code_102610_len_2330", func_802E114C);

INCLUDE_ASM("code_102610_len_2330", func_802E117C);

void save_game_at_player_position(void) {
    GameStatus* gameStatus = GAME_STATUS;

    gameStatus->savedPos[0] = gPlayerStatusPtr->position.x;
    gameStatus->savedPos[1] = gPlayerStatusPtr->position.y;
    gameStatus->savedPos[2] = gPlayerStatusPtr->position.z;
    fio_save_game(gameStatus->saveSlot);
}

INCLUDE_ASM("code_102610_len_2330", func_802E1204);

INCLUDE_ASM("code_102610_len_2330", func_802E1270);

INCLUDE_ASM("code_102610_len_2330", func_802E1298);

INCLUDE_ASM("code_102610_len_2330", func_802E12F8);

INCLUDE_ASM("code_102610_len_2330", func_802E1328);

INCLUDE_ASM("code_102610_len_2330", func_802E1350);

INCLUDE_ASM("code_102610_len_2330", func_802E13B8);

INCLUDE_ASM("code_102610_len_2330", func_802E1400);

INCLUDE_ASM("code_102610_len_2330", func_802E1460);

INCLUDE_ASM("code_102610_len_2330", func_802E14D8);

INCLUDE_ASM("code_102610_len_2330", func_802E153C);

INCLUDE_ASM("code_102610_len_2330", func_802E1614);

INCLUDE_ASM("code_102610_len_2330", func_802E1660);

INCLUDE_ASM("code_102610_len_2330", func_802E1740);

INCLUDE_ASM("code_102610_len_2330", func_802E176C);

INCLUDE_ASM("code_102610_len_2330", func_802E17A8);

INCLUDE_ASM("code_102610_len_2330", func_802E1EA8);

INCLUDE_ASM("code_102610_len_2330", func_802E1EDC);

INCLUDE_ASM("code_102610_len_2330", func_802E234C);

INCLUDE_ASM("code_102610_len_2330", entity_init_BlueSwitch);

INCLUDE_ASM("code_102610_len_2330", entity_init_HugeBlueSwitch);

INCLUDE_ASM("code_102610_len_2330", func_802E2450);

INCLUDE_ASM("code_102610_len_2330", func_802E246C);

INCLUDE_ASM("code_102610_len_2330", func_802E263C);

INCLUDE_ASM("code_102610_len_2330", func_802E2BA4);

INCLUDE_ASM("code_102610_len_2330", func_802E2EB0);

INCLUDE_ASM("code_102610_len_2330", func_802E2FD0);
