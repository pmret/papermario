#include "functions.h"
#include "npc.h"
#include "game_modes.h"

void state_world_draw_aux_ui(void);

void state_init_world(void) {
    game_mode_set_fpDrawAuxUI(0, state_world_draw_aux_ui);
}

void state_step_world(void) {
    update_encounters();
    update_npcs();
    update_player();
    update_item_entities();
    update_effects();
    iterate_models();
    update_cameras();
}

void state_drawUI_world(void) {
    draw_status_ui();
    draw_encounter_ui();
    imgfx_update_cache();
}

void state_world_draw_aux_ui(void) {
    draw_first_strike_ui();
}
