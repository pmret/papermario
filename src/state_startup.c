#include "common.h"
#include "hud_element.h"
#include "fio.h"
#include "sprite.h"

void state_init_startup(void) {
    gOverrideFlags |= GLOBAL_OVERRIDES_8;
    gGameStatusPtr->introState = INTRO_STATE_3;
}

void state_step_startup(void) {
    GameStatus* gameStatus = gGameStatusPtr;
    s32 i;

    if (gameStatus->introState != INTRO_STATE_0) {
        gameStatus->introState--;
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
    gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
    gGameStatusPtr->creditsViewportMode = -1;
    gGameStatusPtr->demoFlags = 0;
    gGameStatusPtr->unk_A9 = -1;
    gGameStatusPtr->demoState = DEMO_STATE_NONE;

    general_heap_create();
    clear_render_tasks();
    clear_worker_list();
    clear_script_list();
    create_cameras_a();
    spr_init_sprites(PLAYER_SPRITES_MARIO_WORLD);
    clear_entity_models();
    clear_animator_list();
    clear_model_data();
    clear_sprite_shading_data();
    reset_background_settings();
    hud_element_set_aux_cache(0, 0);
    hud_element_clear_cache();
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

    if (D_800D95E8.saveSlot == 0) {
        gGameStatusPtr->soundOutputMode = SOUND_OUT_STEREO;
        audio_set_stereo();
    } else {
        gGameStatusPtr->soundOutputMode = SOUND_OUT_MONO;
        audio_set_mono();
    }

    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
    set_game_mode(GAME_MODE_LOGOS);
}

void state_drawUI_startup(void) {
    startup_draw_prim_rect(0, 0, 0x13F, 0xEF, 0, 0, 0, 0xFF);
}
