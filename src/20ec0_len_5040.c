#include "common.h"
#include "map.h"

extern s32 D_800A0F40;

INCLUDE_ASM(s32, "20ec0_len_5040", func_80045AC0);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80045B10);

INCLUDE_ASM(s32, "20ec0_len_5040", update_merlee_messages);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80045BC8);

INCLUDE_ASM(s32, "20ec0_len_5040", draw_merlee_messages);

INCLUDE_ASM(s32, "20ec0_len_5040", get_current_merlee_message);

INCLUDE_ASM(s32, "20ec0_len_5040", dispose_merlee_message);

INCLUDE_ASM(s32, "20ec0_len_5040", show_merlee_message);

INCLUDE_ASM(s32, "20ec0_len_5040", update_merlee_message);

INCLUDE_ASM(s32, "20ec0_len_5040", draw_merlee_message_string);

INCLUDE_ASM(s32, "20ec0_len_5040", draw_merlee_message);

s32 is_merlee_message_done(void) {
    return D_800A0F40;
}

INCLUDE_ASM(s32, "20ec0_len_5040", func_80045FB4);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80046030);

INCLUDE_ASM(s32, "20ec0_len_5040", draw_all_status_icons);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_set);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_all_status_icons);

INCLUDE_ASM(s32, "20ec0_len_5040", set_status_icons_properties);

INCLUDE_ASM(s32, "20ec0_len_5040", func_800477F4);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047820);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_debuff);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_1);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047928);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_static);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_2);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047A30);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_transparent);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_3);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047B38);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_4);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_4);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_boost_jump);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_boost_jump);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_boost_jump);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_boost_hammer);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_boost_hammer);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_boost_hammer);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_boost_partner);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_boost_partner);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_boost_partner);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_surprise);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_surprise);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_surprise);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_peril);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_peril);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_peril);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_danger);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_danger);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_danger);
