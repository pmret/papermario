void func_80035DCC(void);

void begin_state_world(void) {
    func_80112D84(0, func_80035DCC);
}

void step_world(void) {
    update_counters();
    update_npcs();
    update_player();
    update_item_entities();
    update_effects();
    func_80116674();
    update_cameras();
}

void func_80035DA0(void) {
    draw_status_ui();
    draw_encounter_ui();
    func_8013A6E8();
}

void func_80035DCC(void) {
    draw_first_strike_ui();
}
