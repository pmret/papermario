#include "common.h"

void begin_state_init(void) {
    D_8009A650[0] |= 0x8;
    GAME_STATUS->loadMenuState = 3;
}

#ifdef NON_MATCHING
void step_init_state(void) {
    GameStatus* gameStatus = GAME_STATUS;
    s32 i;

    if (gameStatus->loadMenuState != 0) {
        gameStatus->loadMenuState--;
        return;
    }

    D_8009A650[0] = 0;
    gameStatus->areaID = 0;
    gameStatus->isBattle = 0;
    gameStatus->prevArea = -1;
    gameStatus->mapID = 0;
    gameStatus->entryID = 0;

    GAME_STATUS->unk_76 = 0;
    GAME_STATUS->disableScripts = 0;
    GAME_STATUS->unk_7D = 0;
    GAME_STATUS->unk_A8 = -1;
    GAME_STATUS->unk_AA = 0;
    GAME_STATUS->unk_A9 = -1;
    GAME_STATUS->demoState = 0;

    general_heap_create();
    func_8011D890();
    clear_dynamic_entity_list();
    clear_script_list();
    create_cameras_a();
    func_802DD8F8(0);
    clear_virtual_models();
    func_8011E224();
    clear_model_data();
    func_80148040();
    func_80145DF8();
    func_801452E8(0, 0);
    func_80141100();
    clear_trigger_data();
    clear_printers();
    clear_entity_data(0);
    func_80138108();
    clear_player_status();
    clear_npcs();
    clear_player_data();
    func_80072B30();
    func_8003E338();
    func_80059C9C();
    clear_item_entity_data();
    clear_saved_variables();
    initialize_collision();
    func_8014AC08();
    func_801473F0();
    partner_initialize_data();
    func_80149618();
    func_8014A52C();
    initialize_curtains();

    for (i = 0; i < 4; i++) {
        gameStatus->unk_50[i] = 4;
        gameStatus->unk_48[i] = 0xF;
    }

    fio_has_valid_backup();

    if (D_800D9620 == 0) {
        GAME_STATUS->unk_AB = 1;
        func_8005615C();
    } else {
        GAME_STATUS->unk_AB = 0;
        func_80056180();
    }

    D_8009A650[0] &= ~0x8;
    set_game_mode(1);
}
#else
INCLUDE_ASM(s32, "code_e940_len_290", step_init_state);
#endif

void func_80033788(void) {
    func_8002AB5C(0, 0, 0x13F, 0xEF, 0, 0, 0, 0xFF);
}
