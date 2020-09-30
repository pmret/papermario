void func_80035DCC(void);

void begin_state_world(void) {
    func_80112D84(0, func_80035DCC);
}

void step_world(void) {
    func_8003E524();
    update_npcs();
    update_player();
    update_item_entities();
    func_80059D50();
    func_80116674();
    update_cameras();
}

void func_80035DA0(void) {
    draw_status_ui();
    func_8003E5B0();
    func_8013A6E8();
}

void func_80035DCC(void) {
    func_8003E63C();
}
