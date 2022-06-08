#include"common.h"
#include "hud_element.h"
#include "ld_addrs.h"

s32 HudScript_UnusedBadge[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetCI(60, ui_pause_unused_badge_points)
	hs_Restart
	hs_End
};

s32 HudScript_UnusedBadge_disabled[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetCI_Explicit(60, ui_pause_unused_badge_points, ui_pause_unused_badge_points_disabled_disabled_)
	hs_Restart
	hs_End
};

s32 HudScript_UnusedCompass[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetCI(60, ui_pause_unused_compass)
	hs_Restart
	hs_End
};

s32 HudScript_UnusedCompass_disabled[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetCI_Explicit(60, ui_pause_unused_compass, ui_pause_unused_compass_disabled_disabled_)
	hs_Restart
	hs_End
};

s32 HudScript_CursorHand[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_cursor_hand)
	hs_Restart
	hs_End
};

s32 HudScript_AnimatedCursorHand[] = {
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

s32 HudScript_JpSuper[] = {
	hs_SetVisible
	hs_SetCustomSize(40, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_jp_super)
	hs_Restart
	hs_End
};

s32 HudScript_JpUltra[] = {
	hs_SetVisible
	hs_SetCustomSize(40, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_jp_ultra)
	hs_Restart
	hs_End
};

s32 HudScript_FilenameCaret[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_ClearFlags(HUD_ELEMENT_FLAGS_200000)
		hs_SetCI(9, ui_files_filename_caret)
		hs_SetFlags(HUD_ELEMENT_FLAGS_200000)
		hs_SetCI(6, ui_files_filename_caret)
	hs_Restart
	hs_End
};

s32 HudScript_FilenameSpace[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_files_filename_space)
	hs_Restart
	hs_End
};

s32 HudScript_HeaderStats[] = {
	hs_SetVisible
	hs_SetCustomSize(48, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_label_stats)
	hs_Restart
	hs_End
};

s32 HudScript_HeaderBadges[] = {
	hs_SetVisible
	hs_SetCustomSize(48, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_label_badges)
	hs_Restart
	hs_End
};

s32 HudScript_HeaderItems[] = {
	hs_SetVisible
	hs_SetCustomSize(48, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_label_items)
	hs_Restart
	hs_End
};

s32 HudScript_HeaderParty[] = {
	hs_SetVisible
	hs_SetCustomSize(48, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_label_party)
	hs_Restart
	hs_End
};

s32 HudScript_HeaderSpirits[] = {
	hs_SetVisible
	hs_SetCustomSize(48, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_label_spirits)
	hs_Restart
	hs_End
};

s32 HudScript_HeaderMap[] = {
	hs_SetVisible
	hs_SetCustomSize(48, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_label_map)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText0[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_0)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText1[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_1)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText2[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_2)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText3[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_3)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText4[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_4)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText5[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_5)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText6[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_6)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText7[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_7)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText8[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_8)
	hs_Restart
	hs_End
};

s32 HudScript_SmallText9[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_digit_9)
	hs_Restart
	hs_End
};

s32 HudScript_SmallTextBp[] = {
	hs_SetVisible
	hs_SetCustomSize(8, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_small_text_bp)
	hs_Restart
	hs_End
};

s32 HudScript_JpFile[] = {
	hs_SetVisible
	hs_SetCustomSize(32, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_label_jp_file)
	hs_Restart
	hs_End
};

s32 HudScript_JpFileDisabled[] = {
	hs_SetVisible
	hs_SetCustomSize(32, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_label_jp_file_disabled)
	hs_Restart
	hs_End
};

s32 HudScript_OptionMonoOn[] = {
	hs_SetVisible
	hs_SetCustomSize(64, 16)
	hs_Loop
		hs_SetCI(60, ui_files_label_mono)
	hs_Restart
	hs_End
};

s32 HudScript_OptionMonoOff[] = {
	hs_SetVisible
	hs_SetCustomSize(64, 16)
	hs_Loop
		hs_SetCI(60, ui_files_label_mono_off)
	hs_Restart
	hs_End
};

s32 HudScript_OptionStereoOn[] = {
	hs_SetVisible
	hs_SetCustomSize(64, 16)
	hs_Loop
		hs_SetCI(60, ui_files_label_stereo)
	hs_Restart
	hs_End
};

s32 HudScript_OptionStereoOff[] = {
	hs_SetVisible
	hs_SetCustomSize(64, 16)
	hs_Loop
		hs_SetCI(60, ui_files_label_stereo_off)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit1[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_eldstar)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit1Missing[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_eldstar_silhouette)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit2[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_mamar)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit2Missing[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_mamar_silhouette)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit3[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_skolar)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit3Missing[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_skolar_silhouette)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit4[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_muskular)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit4Missing[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_muskular_silhouette)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit5[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_misstar)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit5Missing[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_misstar_silhouette)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit6[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_klevar)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit6Missing[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_klevar_silhouette)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit7[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_kalmar)
	hs_Restart
	hs_End
};

s32 HudScript_Spirit7Missing[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_files_kalmar_silhouette)
	hs_Restart
	hs_End
};

s32 HudScript_MapWalk0[] = {
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

s32 HudScript_ListPrevPage[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_list_prev_page)
	hs_Restart
	hs_End
};

s32 HudScript_ListNextPage[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_list_next_page)
	hs_Restart
	hs_End
};

s32 HudScript_133F40_133FC0[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_unused_z_up_arrow)
	hs_Restart
	hs_End
};

s32 HudScript_133FE0_134060[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_unused_r_down_arrow)
	hs_Restart
	hs_End
};

s32 HudScript_LabelBpNeeded[] = {
	hs_SetVisible
	hs_SetCustomSize(48, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_bp_needed)
	hs_Restart
	hs_End
};

s32 HudScript_MarioHeadLarge[] = {
	hs_SetVisible
	hs_SetCustomSize(32, 32)
	hs_Loop
		hs_SetCI(60, ui_pause_mario_large)
	hs_Restart
	hs_End
};

s32 HudScript_Dash[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 8)
	hs_Loop
		hs_SetCI(60, ui_pause_dash)
	hs_Restart
	hs_End
};

s32 HudScript_DescMsgPrev[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_ClearFlags(HUD_ELEMENT_FLAGS_200000)
		hs_SetCI(9, ui_pause_desc_msg_prev)
		hs_SetFlags(HUD_ELEMENT_FLAGS_200000)
		hs_SetCI(6, ui_pause_desc_msg_prev)
	hs_Restart
	hs_End
};

s32 HudScript_DescMsgNext[] = {
	hs_SetVisible
	hs_SetCustomSize(16, 16)
	hs_Loop
		hs_ClearFlags(HUD_ELEMENT_FLAGS_200000)
		hs_SetCI(9, ui_pause_desc_msg_next)
		hs_SetFlags(HUD_ELEMENT_FLAGS_200000)
		hs_SetCI(6, ui_pause_desc_msg_next)
	hs_Restart
	hs_End
};

s32 HudScript_StatBoots0[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_boots0)
	hs_Restart
	hs_End
};

s32 HudScript_StatBoots1[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_boots1)
	hs_Restart
	hs_End
};

s32 HudScript_StatBoots2[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_boots2)
	hs_Restart
	hs_End
};

s32 HudScript_StatBoots3[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_boots3)
	hs_Restart
	hs_End
};

s32 HudScript_StatHammer0[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_hammer0)
	hs_Restart
	hs_End
};

s32 HudScript_StatHammer1[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_hammer1)
	hs_Restart
	hs_End
};

s32 HudScript_StatHammer2[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_hammer2)
	hs_Restart
	hs_End
};

s32 HudScript_StatHammer3[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_hammer3)
	hs_Restart
	hs_End
};

s32 HudScript_StatBp[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_bp)
	hs_Restart
	hs_End
};

s32 HudScript_MarioHeadSmall[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_mario)
	hs_Restart
	hs_End
};

s32 HudScript_Clock[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_time)
	hs_Restart
	hs_End
};

s32 HudScript_StatStarPiece_1[] = {
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

s32 HudScript_StatStarPiece_2[] = {
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

s32 HudScript_StatFp_1[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_fp)
	hs_Restart
	hs_End
};

s32 HudScript_StatFp_2[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_fp)
	hs_Restart
	hs_End
};

s32 HudScript_StatTimes[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_8x8)
	hs_Loop
		hs_SetCI(60, ui_pause_stat_times)
	hs_Restart
	hs_End
};

s32 HudScript_PartnerRank[] = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
	hs_Loop
		hs_SetCI(60, ui_pause_partner_rank)
	hs_Restart
	hs_End
};

s32 HudScript_134F60_135120[] = {
	hs_SetVisible
	hs_SetCustomSize(56, 16)
	hs_Loop
		hs_SetCI(60, ui_pause_unused_bubble)
	hs_Restart
	hs_End
};
