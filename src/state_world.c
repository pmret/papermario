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
    func_80116674();
    update_cameras();
}

void state_drawUI_world(void) {
    draw_status_ui();
    draw_encounter_ui();
    func_8013A6E8();
}

void state_world_draw_aux_ui(void) {
    draw_first_strike_ui();
}
