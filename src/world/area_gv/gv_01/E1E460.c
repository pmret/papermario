#include "gv_01.h"
#include "sprite.h"
#include "hud_element.h"

#include "world/common/atomic/Pipe.inc.c"

#include "world/common/UpdateTexturePan.inc.c"

ApiStatus func_802405EC_E1EA4C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
        set_curtain_scale_goal(1.0);
        set_curtain_fade(0);
    }

    script->functionTemp[0] += 5;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    set_screen_overlay_color(1, 208, 208, 208);
    set_screen_overlay_params_back(0, script->functionTemp[0]);
    set_screen_overlay_alpha(1, 0);
    return script->functionTemp[0] == 255;
}

ApiStatus func_80240688_E1EAE8(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->isBattle = FALSE;
    gGameStatusPtr->unk_76 = 0;
    gGameStatusPtr->disableScripts = 0;
    gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
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
    intro_logos_set_fade_alpha(255);
    intro_logos_set_fade_color(208);
    set_game_mode(GAME_MODE_TITLE_SCREEN);
    return ApiStatus_FINISH;
}
