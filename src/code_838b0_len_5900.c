#include "common.h"

INCLUDE_ASM(s32, "code_838b0_len_5900", use_consumable);

void remove_consumable(void) {
    gPlayerData.invItems[D_8010CD20] = 0;
    sort_items();
}

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA4B0);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA514);

s32 func_800EA524(void) {
    return 1;
}

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA52C);

INCLUDE_ASM(s32, "code_838b0_len_5900", is_current_partner_flying);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA5B8);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA5D0);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA6A8);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA6CC);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EB168, s8 arg0);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EB200);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EB2A4);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_use_ability);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_player_can_pause);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_can_use_ability);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_reset_data);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_initialize_data);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_test_enemy_collision);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_get_ride_script);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_handle_before_battle);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_handle_after_battle);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_kill_ability_script);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_suspend_ability_script);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_resume_ability_script);

INCLUDE_ASM(void, "code_838b0_len_5900", enable_partner_walking, Npc* partner, s32 val);

INCLUDE_ASM(void, "code_838b0_len_5900", func_800EBA3C, Npc* partner);

INCLUDE_ASM(void, "code_838b0_len_5900", func_800EBB40, Npc* partner);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EBC74);

INCLUDE_ASM(void, "code_838b0_len_5900", enable_partner_flying, Npc* partner, s32 val);

INCLUDE_ASM(void, "code_838b0_len_5900", update_player_move_history, Npc* partner);

INCLUDE_ASM(void, "code_838b0_len_5900", func_800ED5D0, Npc* partner);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800ED9F8);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EE994);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EE9B8);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EECC4);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EECE8);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF300);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF314);

INCLUDE_ASM(s32, "code_838b0_len_5900", enable_partner_ai);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF394, f32 arg0);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF3A4);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF3C0);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF3D4);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF3E4);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF414);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF43C);

INCLUDE_ASM(s32, "code_838b0_len_5900", clear_partner_move_history);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF4E0);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF600);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF628);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF640);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF82C);
