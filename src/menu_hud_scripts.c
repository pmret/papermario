#include "common.h"
#include "hud_element.h"
#include "ld_addrs.h"
#include "include_asset.h"

INCLUDE_IMG("ui/pause/unused_badge_points.png", ui_pause_unused_badge_points_png);
INCLUDE_PAL("ui/pause/unused_badge_points.pal", ui_pause_unused_badge_points_pal);
INCLUDE_PAL("ui/pause/unused_badge_points.disabled.pal", ui_pause_unused_badge_points_disabled_disabled__pal);
INCLUDE_IMG("ui/pause/unused_compass.png", ui_pause_unused_compass_png);
INCLUDE_PAL("ui/pause/unused_compass.pal", ui_pause_unused_compass_pal);
INCLUDE_PAL("ui/pause/unused_compass.disabled.pal", ui_pause_unused_compass_disabled_disabled__pal);
INCLUDE_IMG("ui/pause/cursor_hand.png", ui_pause_cursor_hand_png);
INCLUDE_PAL("ui/pause/cursor_hand.pal", ui_pause_cursor_hand_pal);
INCLUDE_IMG("ui/files/filename_caret.png", ui_files_filename_caret_png);
INCLUDE_PAL("ui/files/filename_caret.pal", ui_files_filename_caret_pal);
INCLUDE_IMG("ui/files/filename_space.png", ui_files_filename_space_png);
INCLUDE_PAL("ui/files/filename_space.pal", ui_files_filename_space_pal);

#if !VERSION_JP
INCLUDE_IMG("ui/pause/label_stats.png", ui_pause_label_stats_png);
INCLUDE_PAL("ui/pause/label_stats.pal", ui_pause_label_stats_pal);
INCLUDE_IMG("ui/pause/label_badges.png", ui_pause_label_badges_png);
INCLUDE_PAL("ui/pause/label_badges.pal", ui_pause_label_badges_pal);
INCLUDE_IMG("ui/pause/label_items.png", ui_pause_label_items_png);
INCLUDE_PAL("ui/pause/label_items.pal", ui_pause_label_items_pal);
INCLUDE_IMG("ui/pause/label_party.png", ui_pause_label_party_png);
INCLUDE_PAL("ui/pause/label_party.pal", ui_pause_label_party_pal);
#endif

INCLUDE_IMG("ui/pause/label_spirits.png", ui_pause_label_spirits_png);
INCLUDE_PAL("ui/pause/label_spirits.pal", ui_pause_label_spirits_pal);
INCLUDE_IMG("ui/pause/label_map.png", ui_pause_label_map_png);
INCLUDE_PAL("ui/pause/label_map.pal", ui_pause_label_map_pal);

#if VERSION_PAL
INCLUDE_IMG("de/ui/pause/label_stats.png", de_ui_pause_label_stats_png);
INCLUDE_PAL("de/ui/pause/label_stats.pal", de_ui_pause_label_stats_pal);
INCLUDE_IMG("de/ui/pause/label_badges.png", de_ui_pause_label_badges_png);
INCLUDE_PAL("de/ui/pause/label_badges.pal", de_ui_pause_label_badges_pal);
INCLUDE_IMG("de/ui/pause/label_items.png", de_ui_pause_label_items_png);
INCLUDE_PAL("de/ui/pause/label_items.pal", de_ui_pause_label_items_pal);
INCLUDE_IMG("de/ui/pause/label_party.png", de_ui_pause_label_party_png);
INCLUDE_PAL("de/ui/pause/label_party.pal", de_ui_pause_label_party_pal);
INCLUDE_IMG("de/ui/pause/label_spirits.png", de_ui_pause_label_spirits_png);
INCLUDE_PAL("de/ui/pause/label_spirits.pal", de_ui_pause_label_spirits_pal);
INCLUDE_IMG("de/ui/pause/label_map.png", de_ui_pause_label_map_png);
INCLUDE_PAL("de/ui/pause/label_map.pal", de_ui_pause_label_map_pal);

INCLUDE_IMG("fr/ui/pause/label_stats.png", fr_ui_pause_label_stats_png);
INCLUDE_PAL("fr/ui/pause/label_stats.pal", fr_ui_pause_label_stats_pal);
INCLUDE_IMG("fr/ui/pause/label_badges.png", fr_ui_pause_label_badges_png);
INCLUDE_PAL("fr/ui/pause/label_badges.pal", fr_ui_pause_label_badges_pal);
INCLUDE_IMG("fr/ui/pause/label_items.png", fr_ui_pause_label_items_png);
INCLUDE_PAL("fr/ui/pause/label_items.pal", fr_ui_pause_label_items_pal);
INCLUDE_IMG("fr/ui/pause/label_party.png", fr_ui_pause_label_party_png);
INCLUDE_PAL("fr/ui/pause/label_party.pal", fr_ui_pause_label_party_pal);
INCLUDE_IMG("fr/ui/pause/label_spirits.png", fr_ui_pause_label_spirits_png);
INCLUDE_PAL("fr/ui/pause/label_spirits.pal", fr_ui_pause_label_spirits_pal);
INCLUDE_IMG("fr/ui/pause/label_map.png", fr_ui_pause_label_map_png);
INCLUDE_PAL("fr/ui/pause/label_map.pal", fr_ui_pause_label_map_pal);

INCLUDE_IMG("es/ui/pause/label_stats.png", es_ui_pause_label_stats_png);
INCLUDE_PAL("es/ui/pause/label_stats.pal", es_ui_pause_label_stats_pal);
INCLUDE_IMG("es/ui/pause/label_badges.png", es_ui_pause_label_badges_png);
INCLUDE_PAL("es/ui/pause/label_badges.pal", es_ui_pause_label_badges_pal);
INCLUDE_IMG("es/ui/pause/label_items.png", es_ui_pause_label_items_png);
INCLUDE_PAL("es/ui/pause/label_items.pal", es_ui_pause_label_items_pal);
INCLUDE_IMG("es/ui/pause/label_party.png", es_ui_pause_label_party_png);
INCLUDE_PAL("es/ui/pause/label_party.pal", es_ui_pause_label_party_pal);
INCLUDE_IMG("es/ui/pause/label_spirits.png", es_ui_pause_label_spirits_png);
INCLUDE_PAL("es/ui/pause/label_spirits.pal", es_ui_pause_label_spirits_pal);
INCLUDE_IMG("es/ui/pause/label_map.png", es_ui_pause_label_map_png);
INCLUDE_PAL("es/ui/pause/label_map.pal", es_ui_pause_label_map_pal);
#endif

INCLUDE_IMG("ui/pause/small_digit_0.png", ui_pause_small_digit_0_png);
INCLUDE_PAL("ui/pause/small_digit_0.pal", ui_pause_small_digit_0_pal);
INCLUDE_IMG("ui/pause/small_digit_1.png", ui_pause_small_digit_1_png);
INCLUDE_PAL("ui/pause/small_digit_1.pal", ui_pause_small_digit_1_pal);
INCLUDE_IMG("ui/pause/small_digit_2.png", ui_pause_small_digit_2_png);
INCLUDE_PAL("ui/pause/small_digit_2.pal", ui_pause_small_digit_2_pal);
INCLUDE_IMG("ui/pause/small_digit_3.png", ui_pause_small_digit_3_png);
INCLUDE_PAL("ui/pause/small_digit_3.pal", ui_pause_small_digit_3_pal);
INCLUDE_IMG("ui/pause/small_digit_4.png", ui_pause_small_digit_4_png);
INCLUDE_PAL("ui/pause/small_digit_4.pal", ui_pause_small_digit_4_pal);
INCLUDE_IMG("ui/pause/small_digit_5.png", ui_pause_small_digit_5_png);
INCLUDE_PAL("ui/pause/small_digit_5.pal", ui_pause_small_digit_5_pal);
INCLUDE_IMG("ui/pause/small_digit_6.png", ui_pause_small_digit_6_png);
INCLUDE_PAL("ui/pause/small_digit_6.pal", ui_pause_small_digit_6_pal);
INCLUDE_IMG("ui/pause/small_digit_7.png", ui_pause_small_digit_7_png);
INCLUDE_PAL("ui/pause/small_digit_7.pal", ui_pause_small_digit_7_pal);
INCLUDE_IMG("ui/pause/small_digit_8.png", ui_pause_small_digit_8_png);
INCLUDE_PAL("ui/pause/small_digit_8.pal", ui_pause_small_digit_8_pal);
INCLUDE_IMG("ui/pause/small_digit_9.png", ui_pause_small_digit_9_png);
INCLUDE_PAL("ui/pause/small_digit_9.pal", ui_pause_small_digit_9_pal);
INCLUDE_IMG("ui/pause/small_text_bp.png", ui_pause_small_text_bp_png);
INCLUDE_PAL("ui/pause/small_text_bp.pal", ui_pause_small_text_bp_pal);
INCLUDE_IMG("ui/pause/label_jp_file.png", ui_pause_label_jp_file_png);
INCLUDE_PAL("ui/pause/label_jp_file.pal", ui_pause_label_jp_file_pal);
INCLUDE_IMG("ui/pause/label_jp_file_disabled.png", ui_pause_label_jp_file_disabled_png);
INCLUDE_PAL("ui/pause/label_jp_file_disabled.pal", ui_pause_label_jp_file_disabled_pal);

// English
INCLUDE_IMG("ui/files/option_mono_on.png", ui_files_option_mono_on_png);
INCLUDE_PAL("ui/files/option_mono_on.pal", ui_files_option_mono_on_pal);
INCLUDE_IMG("ui/files/option_mono_off.png", ui_files_option_mono_off_png);
INCLUDE_PAL("ui/files/option_mono_off.pal", ui_files_option_mono_off_pal);
INCLUDE_IMG("ui/files/option_stereo_on.png", ui_files_option_stereo_on_png);
INCLUDE_PAL("ui/files/option_stereo_on.pal", ui_files_option_stereo_on_pal);
INCLUDE_IMG("ui/files/option_stereo_off.png", ui_files_option_stereo_off_png);
INCLUDE_PAL("ui/files/option_stereo_off.pal", ui_files_option_stereo_off_pal);

#if VERSION_PAL
// German
INCLUDE_IMG("de/ui/files/option_mono_on.png", de_ui_files_option_mono_on_png);
INCLUDE_PAL("de/ui/files/option_mono_on.pal", de_ui_files_option_mono_on_pal);
INCLUDE_IMG("de/ui/files/option_mono_off.png", de_ui_files_option_mono_off_png);
INCLUDE_PAL("de/ui/files/option_mono_off.pal", de_ui_files_option_mono_off_pal);
INCLUDE_IMG("de/ui/files/option_stereo_on.png", de_ui_files_option_stereo_on_png);
INCLUDE_PAL("de/ui/files/option_stereo_on.pal", de_ui_files_option_stereo_on_pal);
INCLUDE_IMG("de/ui/files/option_stereo_off.png", de_ui_files_option_stereo_off_png);
INCLUDE_PAL("de/ui/files/option_stereo_off.pal", de_ui_files_option_stereo_off_pal);

// French
INCLUDE_IMG("fr/ui/files/option_mono_on.png", fr_ui_files_option_mono_on_png);
INCLUDE_PAL("fr/ui/files/option_mono_on.pal", fr_ui_files_option_mono_on_pal);
INCLUDE_IMG("fr/ui/files/option_mono_off.png", fr_ui_files_option_mono_off_png);
INCLUDE_PAL("fr/ui/files/option_mono_off.pal", fr_ui_files_option_mono_off_pal);
INCLUDE_IMG("fr/ui/files/option_stereo_on.png", fr_ui_files_option_stereo_on_png);
INCLUDE_PAL("fr/ui/files/option_stereo_on.pal", fr_ui_files_option_stereo_on_pal);
INCLUDE_IMG("fr/ui/files/option_stereo_off.png", fr_ui_files_option_stereo_off_png);
INCLUDE_PAL("fr/ui/files/option_stereo_off.pal", fr_ui_files_option_stereo_off_pal);

// Spanish
INCLUDE_IMG("es/ui/files/option_mono_on.png", es_ui_files_option_mono_on_png);
INCLUDE_PAL("es/ui/files/option_mono_on.pal", es_ui_files_option_mono_on_pal);
INCLUDE_IMG("es/ui/files/option_mono_off.png", es_ui_files_option_mono_off_png);
INCLUDE_PAL("es/ui/files/option_mono_off.pal", es_ui_files_option_mono_off_pal);
INCLUDE_IMG("es/ui/files/option_stereo_on.png", es_ui_files_option_stereo_on_png);
INCLUDE_PAL("es/ui/files/option_stereo_on.pal", es_ui_files_option_stereo_on_pal);
INCLUDE_IMG("es/ui/files/option_stereo_off.png", es_ui_files_option_stereo_off_png);
INCLUDE_PAL("es/ui/files/option_stereo_off.pal", es_ui_files_option_stereo_off_pal);
#endif

INCLUDE_IMG("ui/files/eldstar.png", ui_files_eldstar_png);
INCLUDE_PAL("ui/files/eldstar.pal", ui_files_eldstar_pal);
INCLUDE_IMG("ui/files/eldstar_silhouette.png", ui_files_eldstar_silhouette_png);
INCLUDE_PAL("ui/files/eldstar_silhouette.pal", ui_files_eldstar_silhouette_pal);
INCLUDE_IMG("ui/files/mamar.png", ui_files_mamar_png);
INCLUDE_PAL("ui/files/mamar.pal", ui_files_mamar_pal);
INCLUDE_IMG("ui/files/mamar_silhouette.png", ui_files_mamar_silhouette_png);
INCLUDE_PAL("ui/files/mamar_silhouette.pal", ui_files_mamar_silhouette_pal);
INCLUDE_IMG("ui/files/skolar.png", ui_files_skolar_png);
INCLUDE_PAL("ui/files/skolar.pal", ui_files_skolar_pal);
INCLUDE_IMG("ui/files/skolar_silhouette.png", ui_files_skolar_silhouette_png);
INCLUDE_PAL("ui/files/skolar_silhouette.pal", ui_files_skolar_silhouette_pal);
INCLUDE_IMG("ui/files/muskular.png", ui_files_muskular_png);
INCLUDE_PAL("ui/files/muskular.pal", ui_files_muskular_pal);
INCLUDE_IMG("ui/files/muskular_silhouette.png", ui_files_muskular_silhouette_png);
INCLUDE_PAL("ui/files/muskular_silhouette.pal", ui_files_muskular_silhouette_pal);
INCLUDE_IMG("ui/files/misstar.png", ui_files_misstar_png);
INCLUDE_PAL("ui/files/misstar.pal", ui_files_misstar_pal);
INCLUDE_IMG("ui/files/misstar_silhouette.png", ui_files_misstar_silhouette_png);
INCLUDE_PAL("ui/files/misstar_silhouette.pal", ui_files_misstar_silhouette_pal);
INCLUDE_IMG("ui/files/klevar.png", ui_files_klevar_png);
INCLUDE_PAL("ui/files/klevar.pal", ui_files_klevar_pal);
INCLUDE_IMG("ui/files/klevar_silhouette.png", ui_files_klevar_silhouette_png);
INCLUDE_PAL("ui/files/klevar_silhouette.pal", ui_files_klevar_silhouette_pal);
INCLUDE_IMG("ui/files/kalmar.png", ui_files_kalmar_png);
INCLUDE_PAL("ui/files/kalmar.pal", ui_files_kalmar_pal);
INCLUDE_IMG("ui/files/kalmar_silhouette.png", ui_files_kalmar_silhouette_png);
INCLUDE_PAL("ui/files/kalmar_silhouette.pal", ui_files_kalmar_silhouette_pal);
INCLUDE_IMG("ui/pause/map_walk0.png", ui_pause_map_walk0_png);
INCLUDE_PAL("ui/pause/map_walk0.pal", ui_pause_map_walk0_pal);
INCLUDE_IMG("ui/pause/map_walk1.png", ui_pause_map_walk1_png);
INCLUDE_PAL("ui/pause/map_walk1.pal", ui_pause_map_walk1_pal);
INCLUDE_IMG("ui/pause/map_walk2.png", ui_pause_map_walk2_png);
INCLUDE_PAL("ui/pause/map_walk2.pal", ui_pause_map_walk2_pal);
INCLUDE_IMG("ui/pause/jp_super.png", ui_pause_jp_super_png);
INCLUDE_PAL("ui/pause/jp_super.pal", ui_pause_jp_super_pal);
INCLUDE_IMG("ui/pause/jp_ultra.png", ui_pause_jp_ultra_png);
INCLUDE_PAL("ui/pause/jp_ultra.pal", ui_pause_jp_ultra_pal);
INCLUDE_IMG("ui/pause/list_prev_page.png", ui_pause_list_prev_page_png);
INCLUDE_PAL("ui/pause/list_prev_page.pal", ui_pause_list_prev_page_pal);
INCLUDE_IMG("ui/pause/list_next_page.png", ui_pause_list_next_page_png);
INCLUDE_PAL("ui/pause/list_next_page.pal", ui_pause_list_next_page_pal);
INCLUDE_IMG("ui/pause/unused_z_up_arrow.png", ui_pause_unused_z_up_arrow_png);
INCLUDE_PAL("ui/pause/unused_z_up_arrow.pal", ui_pause_unused_z_up_arrow_pal);
INCLUDE_IMG("ui/pause/unused_r_down_arrow.png", ui_pause_unused_r_down_arrow_png);
INCLUDE_PAL("ui/pause/unused_r_down_arrow.pal", ui_pause_unused_r_down_arrow_pal);
INCLUDE_IMG("ui/pause/desc_msg_prev.png", ui_pause_desc_msg_prev_png);
INCLUDE_PAL("ui/pause/desc_msg_prev.pal", ui_pause_desc_msg_prev_pal);
INCLUDE_IMG("ui/pause/desc_msg_next.png", ui_pause_desc_msg_next_png);
INCLUDE_PAL("ui/pause/desc_msg_next.pal", ui_pause_desc_msg_next_pal);

INCLUDE_IMG("ui/pause/bp_needed.png", ui_pause_bp_needed_png);
INCLUDE_PAL("ui/pause/bp_needed.pal", ui_pause_bp_needed_pal);

#if VERSION_PAL
INCLUDE_IMG("de/ui/pause/bp_needed.png", de_ui_pause_bp_needed_png);
INCLUDE_PAL("de/ui/pause/bp_needed.pal", de_ui_pause_bp_needed_pal);

INCLUDE_IMG("fr/ui/pause/bp_needed.png", fr_ui_pause_bp_needed_png);
INCLUDE_PAL("fr/ui/pause/bp_needed.pal", fr_ui_pause_bp_needed_pal);

INCLUDE_IMG("es/ui/pause/bp_needed.png", es_ui_pause_bp_needed_png);
INCLUDE_PAL("es/ui/pause/bp_needed.pal", es_ui_pause_bp_needed_pal);
#endif

INCLUDE_IMG("ui/pause/mario_large.png", ui_pause_mario_large_png);
INCLUDE_PAL("ui/pause/mario_large.pal", ui_pause_mario_large_pal);
INCLUDE_IMG("ui/pause/dash.png", ui_pause_dash_png);
INCLUDE_PAL("ui/pause/dash.pal", ui_pause_dash_pal);
INCLUDE_IMG("ui/pause/stat_bp.png", ui_pause_stat_bp_png);
INCLUDE_PAL("ui/pause/stat_bp.pal", ui_pause_stat_bp_pal);
INCLUDE_IMG("ui/pause/stat_mario.png", ui_pause_stat_mario_png);
INCLUDE_PAL("ui/pause/stat_mario.pal", ui_pause_stat_mario_pal);
INCLUDE_IMG("ui/pause/stat_time.png", ui_pause_stat_time_png);
INCLUDE_PAL("ui/pause/stat_time.pal", ui_pause_stat_time_pal);
INCLUDE_IMG("ui/pause/stat_star_piece0.png", ui_pause_stat_star_piece0_png);
INCLUDE_PAL("ui/pause/stat_star_piece0.pal", ui_pause_stat_star_piece0_pal);
INCLUDE_IMG("ui/pause/stat_star_piece1.png", ui_pause_stat_star_piece1_png);
INCLUDE_PAL("ui/pause/stat_star_piece1.pal", ui_pause_stat_star_piece1_pal);
INCLUDE_IMG("ui/pause/stat_star_piece2.png", ui_pause_stat_star_piece2_png);
INCLUDE_PAL("ui/pause/stat_star_piece2.pal", ui_pause_stat_star_piece2_pal);
INCLUDE_IMG("ui/pause/stat_fp.png", ui_pause_stat_fp_png);
INCLUDE_PAL("ui/pause/stat_fp.pal", ui_pause_stat_fp_pal);
INCLUDE_IMG("ui/pause/stat_times.png", ui_pause_stat_times_png);
INCLUDE_PAL("ui/pause/stat_times.pal", ui_pause_stat_times_pal);
INCLUDE_IMG("ui/pause/stat_boots0.png", ui_pause_stat_boots0_png);
INCLUDE_PAL("ui/pause/stat_boots0.pal", ui_pause_stat_boots0_pal);
INCLUDE_IMG("ui/pause/stat_boots1.png", ui_pause_stat_boots1_png);
INCLUDE_PAL("ui/pause/stat_boots1.pal", ui_pause_stat_boots1_pal);
INCLUDE_IMG("ui/pause/stat_boots2.png", ui_pause_stat_boots2_png);
INCLUDE_PAL("ui/pause/stat_boots2.pal", ui_pause_stat_boots2_pal);
INCLUDE_IMG("ui/pause/stat_boots3.png", ui_pause_stat_boots3_png);
INCLUDE_PAL("ui/pause/stat_boots3.pal", ui_pause_stat_boots3_pal);
INCLUDE_IMG("ui/pause/stat_hammer0.png", ui_pause_stat_hammer0_png);
INCLUDE_PAL("ui/pause/stat_hammer0.pal", ui_pause_stat_hammer0_pal);
INCLUDE_IMG("ui/pause/stat_hammer1.png", ui_pause_stat_hammer1_png);
INCLUDE_PAL("ui/pause/stat_hammer1.pal", ui_pause_stat_hammer1_pal);
INCLUDE_IMG("ui/pause/stat_hammer2.png", ui_pause_stat_hammer2_png);
INCLUDE_PAL("ui/pause/stat_hammer2.pal", ui_pause_stat_hammer2_pal);
INCLUDE_IMG("ui/pause/stat_hammer3.png", ui_pause_stat_hammer3_png);
INCLUDE_PAL("ui/pause/stat_hammer3.pal", ui_pause_stat_hammer3_pal);
INCLUDE_IMG("ui/pause/partner_rank.png", ui_pause_partner_rank_png);
INCLUDE_PAL("ui/pause/partner_rank.pal", ui_pause_partner_rank_pal);
INCLUDE_IMG("ui/pause/unused_bubble.png", ui_pause_unused_bubble_png);
INCLUDE_PAL("ui/pause/unused_bubble.pal", ui_pause_unused_bubble_pal);

HudScript HES_UnusedBadge = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_unused_badge_points, 24, 24);

HudScript HES_UnusedBadge_disabled = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
    hs_Loop
        hs_SetCI_Explicit(60, ui_pause_unused_badge_points, ui_pause_unused_badge_points_disabled_disabled_)
    hs_Restart
    hs_End
};

HudScript HES_UnusedCompass = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_unused_compass, 24, 24);

HudScript HES_UnusedCompass_disabled = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
    hs_Loop
        hs_SetCI_Explicit(60, ui_pause_unused_compass, ui_pause_unused_compass_disabled_disabled_)
    hs_Restart
    hs_End
};

HudScript HES_CursorHand = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_cursor_hand, 16, 16);

HudScript HES_AnimatedCursorHand = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_AddTexelOffsetX(-1)
        hs_SetCI(4, ui_pause_cursor_hand)
        hs_AddTexelOffsetX(1)
        hs_SetCI(8, ui_pause_cursor_hand)
    hs_Restart
    hs_End
};

HudScript HES_JpSuper = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_jp_super, 40, 16);

HudScript HES_JpUltra = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_jp_ultra, 40, 16);

HudScript HES_FilenameCaret = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(9, ui_files_filename_caret)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(6, ui_files_filename_caret)
    hs_Restart
    hs_End
};

HudScript HES_FilenameSpace = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_filename_space, 8, 8);

#if VERSION_JP
HudScript HES_HeaderSpirits = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_spirits, 32, 16);

HudScript HES_HeaderMap = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_map, 32, 16);
#else
HudScript HES_HeaderStats = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_stats, 48, 16);

HudScript HES_HeaderBadges = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_badges, 48, 16);

HudScript HES_HeaderItems = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_items, 48, 16);

HudScript HES_HeaderParty = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_party, 48, 16);

HudScript HES_HeaderSpirits = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_spirits, 48, 16);

HudScript HES_HeaderMap = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_map, 48, 16);
#endif

#if VERSION_PAL
HudScript HES_HeaderStats_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_pause_label_stats, 48, 16);
HudScript HES_HeaderBadges_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_pause_label_badges, 48, 16);
HudScript HES_HeaderItems_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_pause_label_items, 48, 16);
HudScript HES_HeaderParty_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_pause_label_party, 48, 16);
HudScript HES_HeaderSpirits_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_pause_label_spirits, 48, 16);
HudScript HES_HeaderMap_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_pause_label_map, 48, 16);

HudScript HES_HeaderStats_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_pause_label_stats, 48, 16);
HudScript HES_HeaderBadges_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_pause_label_badges, 48, 16);
HudScript HES_HeaderItems_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_pause_label_items, 48, 16);
HudScript HES_HeaderParty_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_pause_label_party, 48, 16);
HudScript HES_HeaderSpirits_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_pause_label_spirits, 48, 16);
HudScript HES_HeaderMap_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_pause_label_map, 48, 16);

HudScript HES_HeaderStats_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_pause_label_stats, 48, 16);
HudScript HES_HeaderBadges_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_pause_label_badges, 48, 16);
HudScript HES_HeaderItems_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_pause_label_items, 48, 16);
HudScript HES_HeaderParty_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_pause_label_party, 48, 16);
HudScript HES_HeaderSpirits_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_pause_label_spirits, 48, 16);
HudScript HES_HeaderMap_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_pause_label_map, 48, 16);
#endif

HudScript HES_SmallText0 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_0, 8, 8);

HudScript HES_SmallText1 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_1, 8, 8);

HudScript HES_SmallText2 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_2, 8, 8);

HudScript HES_SmallText3 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_3, 8, 8);

HudScript HES_SmallText4 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_4, 8, 8);

HudScript HES_SmallText5 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_5, 8, 8);

HudScript HES_SmallText6 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_6, 8, 8);

HudScript HES_SmallText7 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_7, 8, 8);

HudScript HES_SmallText8 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_8, 8, 8);

HudScript HES_SmallText9 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_digit_9, 8, 8);

HudScript HES_SmallTextBp = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_small_text_bp, 8, 8);

HudScript HES_JpFile = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_jp_file, 32, 16);

HudScript HES_JpFileDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_jp_file_disabled, 32, 16);

HudScript HES_OptionMonoOn = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_option_mono_on, 64, 16);

HudScript HES_OptionMonoOff = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_option_mono_off, 64, 16);

HudScript HES_OptionStereoOn = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_option_stereo_on, 64, 16);

HudScript HES_OptionStereoOff = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_option_stereo_off, 64, 16);

#if VERSION_PAL
HudScript HES_OptionMonoOn_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_files_option_mono_on, 64, 16);
HudScript HES_OptionMonoOff_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_files_option_mono_off, 64, 16);
HudScript HES_OptionStereoOn_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_files_option_stereo_on, 64, 16);
HudScript HES_OptionStereoOff_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_files_option_stereo_off, 64, 16);

HudScript HES_OptionMonoOn_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_files_option_mono_on, 64, 16);
HudScript HES_OptionMonoOff_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_files_option_mono_off, 64, 16);
HudScript HES_OptionStereoOn_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_files_option_stereo_on, 64, 16);
HudScript HES_OptionStereoOff_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_files_option_stereo_off, 64, 16);

HudScript HES_OptionMonoOn_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_files_option_mono_on, 64, 16);
HudScript HES_OptionMonoOff_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_files_option_mono_off, 64, 16);
HudScript HES_OptionStereoOn_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_files_option_stereo_on, 64, 16);
HudScript HES_OptionStereoOff_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_files_option_stereo_off, 64, 16);
#endif

HudScript HES_Spirit1 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_eldstar, 16, 16);

HudScript HES_Spirit1Missing = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_eldstar_silhouette, 16, 16);

HudScript HES_Spirit2 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_mamar, 16, 16);

HudScript HES_Spirit2Missing = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_mamar_silhouette, 16, 16);

HudScript HES_Spirit3 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_skolar, 16, 16);

HudScript HES_Spirit3Missing = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_skolar_silhouette, 16, 16);

HudScript HES_Spirit4 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_muskular, 16, 16);

HudScript HES_Spirit4Missing = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_muskular_silhouette, 16, 16);

HudScript HES_Spirit5 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_misstar, 16, 16);

HudScript HES_Spirit5Missing = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_misstar_silhouette, 16, 16);

HudScript HES_Spirit6 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_klevar, 16, 16);

HudScript HES_Spirit6Missing = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_klevar_silhouette, 16, 16);

HudScript HES_Spirit7 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_kalmar, 16, 16);

HudScript HES_Spirit7Missing = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_files_kalmar_silhouette, 16, 16);

HudScript HES_MapWalk0 = {
    hs_SetVisible
    hs_SetCustomSize(24, 24)
    hs_Loop
        hs_SetCI(16, ui_pause_map_walk0)
        hs_SetCI(5, ui_pause_map_walk1)
        hs_SetCI(16, ui_pause_map_walk2)
        hs_SetCI(4, ui_pause_map_walk1)
    hs_Restart
    hs_End
};

HudScript HES_ListPrevPage = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_list_prev_page, 16, 16);

HudScript HES_ListNextPage = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_list_next_page, 16, 16);

HudScript HES_133F40_133FC0 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_unused_z_up_arrow, 16, 16);

HudScript HES_133FE0_134060 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_unused_r_down_arrow, 16, 16);

HudScript HES_LabelBpNeeded = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_bp_needed, 48, 8);

#if VERSION_PAL
HudScript HES_LabelBpNeeded_de = HES_TEMPLATE_CI_CUSTOM_SIZE(de_ui_pause_bp_needed, 48, 8);
HudScript HES_LabelBpNeeded_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(fr_ui_pause_bp_needed, 48, 8);
HudScript HES_LabelBpNeeded_es = HES_TEMPLATE_CI_CUSTOM_SIZE(es_ui_pause_bp_needed, 48, 8);
#endif

HudScript HES_MarioHeadLarge = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_mario_large, 32, 32);

HudScript HES_Dash = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_dash, 16, 8);

HudScript HES_DescMsgPrev = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(9, ui_pause_desc_msg_prev)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(6, ui_pause_desc_msg_prev)
    hs_Restart
    hs_End
};

HudScript HES_DescMsgNext = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(9, ui_pause_desc_msg_next)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(6, ui_pause_desc_msg_next)
    hs_Restart
    hs_End
};

HudScript HES_StatBoots0 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_boots0, 16, 16);

HudScript HES_StatBoots1 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_boots1, 16, 16);

HudScript HES_StatBoots2 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_boots2, 16, 16);

HudScript HES_StatBoots3 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_boots3, 16, 16);

HudScript HES_StatHammer0 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_hammer0, 16, 16);

HudScript HES_StatHammer1 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_hammer1, 16, 16);

HudScript HES_StatHammer2 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_hammer2, 16, 16);

HudScript HES_StatHammer3 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_hammer3, 16, 16);

HudScript HES_StatBp = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_bp, 16, 16);

HudScript HES_MarioHeadSmall = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_mario, 16, 16);

HudScript HES_Clock = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_time, 16, 16);

HudScript HES_StatStarPiece_1 = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(12, ui_pause_stat_star_piece0)
        hs_SetCI(4, ui_pause_stat_star_piece1)
        hs_SetCI(12, ui_pause_stat_star_piece2)
        hs_SetCI(4, ui_pause_stat_star_piece1)
    hs_Restart
    hs_End
};

HudScript HES_StatStarPiece_2 = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(12, ui_pause_stat_star_piece0)
        hs_SetCI(4, ui_pause_stat_star_piece1)
        hs_SetCI(12, ui_pause_stat_star_piece2)
        hs_SetCI(4, ui_pause_stat_star_piece1)
    hs_Restart
    hs_End
};

HudScript HES_StatFp_1 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_fp, 16, 16);

HudScript HES_StatFp_2 = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_fp, 16, 16);

HudScript HES_StatTimes = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_stat_times, 8, 8);

HudScript HES_PartnerRank = HES_TEMPLATE_CI_ENUM_SIZE(ui_pause_partner_rank, 16, 16);

HudScript HES_134F60_135120 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_unused_bubble, 56, 16);
