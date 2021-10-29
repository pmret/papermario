#include "common.h"
#include "hud_element.h"
#include "fio.h"
#include "sprite.h"

void state_init_startup(void) {
    gOverrideFlags |= 0x8;
    gGameStatusPtr->loadMenuState = 3;
}

void state_step_startup(void) {
    GameStatus* gameStatus = gGameStatusPtr;
    s32 i;

    if (gameStatus->loadMenuState != 0) {
        gameStatus->loadMenuState--;
        return;
    }

    gOverrideFlags = 0;
    gGameStatusPtr->areaID = 0;
    gGameStatusPtr->isBattle = 0;
    gameStatus->prevArea = -1;
    gameStatus->mapID = 0;
    gameStatus->entryID = 0;
    gGameStatusPtr->unk_76 = 0;
    gGameStatusPtr->disableScripts = 0;
    gGameStatusPtr->unk_7D = 0;
    gGameStatusPtr->creditsViewportMode = -1;
    gGameStatusPtr->demoFlags = 0;
    gGameStatusPtr->unk_A9 = -1;
    gGameStatusPtr->demoState = 0;

    general_heap_create();
    clear_render_tasks();
    clear_generic_entity_list();
    clear_script_list();
    create_cameras_a();
    spr_init_sprites(0);
    clear_entity_models();
    clear_animator_list();
    clear_model_data();
    clear_sprite_shading_data();
    reset_background_settings();
    set_hud_element_nonworld_cache(0, 0);
    clear_hud_element_cache();
    clear_trigger_data();
    clear_printers();
    clear_entity_data(0);
    clear_screen_overlays();
    clear_player_status();
    clear_npcs();
    clear_player_data();
    reset_battle_status();
    init_encounter_status();
    clear_effect_data();
    clear_item_entity_data();
    clear_saved_variables();
    initialize_collision();
    bgm_init_music_players();
    clear_windows();
    partner_initialize_data();
    sfx_clear_sounds();
    bgm_reset_volume();
    initialize_curtains();

    for (i = 0; i < 4; i++) {
        gGameStatusPtr->unk_50[i] = 4;
        gGameStatusPtr->unk_48[i] = 0xF;
    }

    fio_has_valid_backup();

    if (D_800D9620 == 0) {
        gGameStatusPtr->unk_AB = 1;
        func_8005615C();
    } else {
        gGameStatusPtr->unk_AB = 0;
        func_80056180();
    }

    gOverrideFlags &= ~0x8;
    set_game_mode(1);
}

void state_drawUI_startup(void) {
    startup_draw_prim_rect(0, 0, 0x13F, 0xEF, 0, 0, 0, 0xFF);
}
