#include "common.h"

INCLUDE_ASM(s32, "code_16F740", func_80240E60);

INCLUDE_ASM(s32, "code_16F740", func_80240FDC);

INCLUDE_ASM(s32, "code_16F740", func_80241190);

INCLUDE_ASM(s32, "code_16F740", begin_battle);

INCLUDE_ASM(s32, "code_16F740", func_80241AB8);

INCLUDE_ASM(s32, "code_16F740", func_80241B14);

void func_8024201C(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_heroes_start_turn);

void func_80242AC0(void) {
}

INCLUDE_ASM(s32, "code_16F740", switch_to_player);

void func_80242BA8(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_end_player_turn);

void func_80242EF8(void) {
}

INCLUDE_ASM(s32, "code_16F740", switch_to_partner);

void func_80242FD8(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80242FE0);

void func_80243910(void) {
}

INCLUDE_ASM(s32, "code_16F740", switch_order);

void func_802439D0(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_802439D8);

void func_80243FD4(void) {
}

void func_80243FDC(void) {
    func_8024E40C(2);
    func_80241190(12);
}

void func_80244000(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80244008);

void func_80244708(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80244710);

void func_80244A48(void) {
}

INCLUDE_ASM(s32, "code_16F740", end_battle);

INCLUDE_ASM(s32, "code_16F740", func_80244D90);

INCLUDE_ASM(s32, "code_16F740", func_80244E38);

void func_80244EF8(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_run_away);

void func_80245438(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80245440);

void func_802456B0(void) {
}

ApiStatus EnablePartnerBlur(ScriptInstance* script, s32 isInitialCall) {
    enable_partner_blur();
    return ApiStatus_DONE2;
}

ApiStatus DisablePartnerBlur(ScriptInstance* script, s32 isInitialCall) {
    disable_partner_blur();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_16F740", update_swap_partner);

void func_80245AC8(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_player_action);

void func_80246448(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_player_change_turn);

void func_80246B2C(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_partner_action);

void func_80247214(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_8024721C);

void func_802472A4(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_enemy_change_turn);

void func_80247568(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_enemy_action);

void func_80247AFC(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80247B04);

INCLUDE_ASM(s32, "code_16F740", func_802480F0);

INCLUDE_ASM(s32, "code_16F740", func_80248190);

INCLUDE_ASM(s32, "code_16F740", func_802485FC);

INCLUDE_ASM(s32, "code_16F740", func_80248660);

INCLUDE_ASM(s32, "code_16F740", func_80248AA4);

INCLUDE_ASM(s32, "code_16F740", func_80248B08);

INCLUDE_ASM(s32, "code_16F740", func_80248D78);
