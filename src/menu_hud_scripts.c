#include"common.h"
#include "hud_element.h"
#include "ld_addrs.h"

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
HudScript HES_HeaderStats = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_spirits, 32, 16);

HudScript HES_HeaderBadges = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pause_label_map, 32, 16);
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
