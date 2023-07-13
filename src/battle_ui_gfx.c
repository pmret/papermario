#include "common.h"
#include "hud_element.h"

#include "ui/battle/menu/unused.png.inc.c"
#include "ui/battle/menu/unused.pal.inc.c"
#define ui_battle_menu_unused_disabled_png ui_battle_menu_unused_png
#include "ui/battle/menu/unused.disabled.pal.inc.c"

#include "ui/battle/menu/flee.png.inc.c"
#include "ui/battle/menu/flee.pal.inc.c"
#define ui_battle_menu_flee_disabled_png ui_battle_menu_flee_png
#include "ui/battle/menu/flee.disabled.pal.inc.c"

#include "ui/battle/menu/defend.png.inc.c"
#include "ui/battle/menu/defend.pal.inc.c"
#define ui_battle_menu_defend_disabled_png ui_battle_menu_defend_png
#include "ui/battle/menu/defend.disabled.pal.inc.c"

#include "ui/battle/menu/strategies.png.inc.c"
#include "ui/battle/menu/strategies.pal.inc.c"
#define ui_battle_menu_strategies_disabled_png ui_battle_menu_strategies_png
#include "ui/battle/menu/strategies.disabled.pal.inc.c"

#include "ui/battle/menu/nothing.png.inc.c"
#include "ui/battle/menu/nothing.pal.inc.c"
#define ui_battle_menu_nothing_disabled_png ui_battle_menu_nothing_png
#include "ui/battle/menu/nothing.disabled.pal.inc.c"

#include "ui/battle/menu/pouch.png.inc.c"
#include "ui/battle/menu/pouch.pal.inc.c"
#define ui_battle_menu_pouch_disabled_png ui_battle_menu_pouch_png
#include "ui/battle/menu/pouch.disabled.pal.inc.c"

#include "ui/battle/swap_Z.png.inc.c"
#include "ui/battle/swap_Z.pal.inc.c"

#include "ui/battle/swap_arrow_left.png.inc.c"
#include "ui/battle/swap_arrow_left.pal.inc.c"

#include "ui/battle/swap_arrow_right.png.inc.c"
#include "ui/battle/swap_arrow_right.pal.inc.c"

#include "ui/battle/menu/spirits.png.inc.c"
#include "ui/battle/menu/spirits.pal.inc.c"

#include "ui/battle/yellow_arrow.png.inc.c"
#include "ui/battle/yellow_arrow.pal.inc.c"

#include "ui/battle/hp_bar.png.inc.c"
#include "ui/battle/hp_bar.pal.inc.c"

#include "ui/battle/hp_0.png.inc.c"
#include "ui/battle/hp_0.pal.inc.c"

#include "ui/battle/hp_1.png.inc.c"
#include "ui/battle/hp_1.pal.inc.c"

#include "ui/battle/hp_2.png.inc.c"
#include "ui/battle/hp_2.pal.inc.c"

#include "ui/battle/hp_3.png.inc.c"
#include "ui/battle/hp_3.pal.inc.c"

#include "ui/battle/hp_4.png.inc.c"
#include "ui/battle/hp_4.pal.inc.c"

#include "ui/battle/hp_5.png.inc.c"
#include "ui/battle/hp_5.pal.inc.c"

#include "ui/battle/hp_6.png.inc.c"
#include "ui/battle/hp_6.pal.inc.c"

#include "ui/battle/hp_7.png.inc.c"
#include "ui/battle/hp_7.pal.inc.c"

#include "ui/battle/hp_8.png.inc.c"
#include "ui/battle/hp_8.pal.inc.c"

#include "ui/battle/hp_9.png.inc.c"
#include "ui/battle/hp_9.pal.inc.c"

#include "ui/battle/cont/b_up.png.inc.c"
#include "ui/battle/cont/b_up.pal.inc.c"

#include "ui/battle/cont/b_down.png.inc.c"
#include "ui/battle/cont/b_down.pal.inc.c"

#include "ui/battle/cont/c_left_up.png.inc.c"
#include "ui/battle/cont/c_left_up.pal.inc.c"

#include "ui/battle/cont/c_left_down.png.inc.c"
#include "ui/battle/cont/c_left_down.pal.inc.c"

#include "ui/battle/cont/c_right_up.png.inc.c"
#include "ui/battle/cont/c_right_up.pal.inc.c"

#include "ui/battle/cont/c_right_down.png.inc.c"
#include "ui/battle/cont/c_right_down.pal.inc.c"

#include "ui/battle/cont/c_up_up.png.inc.c"
#include "ui/battle/cont/c_up_up.pal.inc.c"

#include "ui/battle/cont/c_up_down.png.inc.c"
#include "ui/battle/cont/c_up_down.pal.inc.c"

#include "ui/battle/cont/c_down_up.png.inc.c"
#include "ui/battle/cont/c_down_up.pal.inc.c"

#include "ui/battle/cont/c_down_down.png.inc.c"
#include "ui/battle/cont/c_down_down.pal.inc.c"

#include "ui/battle/cmd/timing_1_chance.png.inc.c"
#include "ui/battle/cmd/timing_1_chance.pal.inc.c"

#include "ui/battle/cmd/timing_ready.png.inc.c"
#include "ui/battle/cmd/timing_ready.pal.inc.c"

#include "ui/battle/cmd/timing_wait.png.inc.c"
#include "ui/battle/cmd/timing_wait.pal.inc.c"

#include "ui/battle/cmd/charge_1.png.inc.c"
#include "ui/battle/cmd/charge_1.pal.inc.c"

#include "ui/battle/cmd/charge_2.png.inc.c"
#include "ui/battle/cmd/charge_2.pal.inc.c"

#include "ui/battle/cmd/charge_3.png.inc.c"
#include "ui/battle/cmd/charge_3.pal.inc.c"

#include "ui/battle/cmd/charge_4.png.inc.c"
#include "ui/battle/cmd/charge_4.pal.inc.c"

#include "ui/battle/cmd/timing_3_chances.png.inc.c"
#include "ui/battle/cmd/timing_3_chances.pal.inc.c"

#include "ui/battle/cmd/gauge_result.png.inc.c"
#include "ui/battle/cmd/gauge_result.pal.inc.c"

#include "ui/battle/cmd/timing_ok.png.inc.c"
#include "ui/battle/cmd/timing_ok.pal.inc.c"

#include "ui/battle/cmd/timing_miss.png.inc.c"
#include "ui/battle/cmd/timing_miss.pal.inc.c"

#include "ui/battle/cmd/flee_0.png.inc.c"
#include "ui/battle/cmd/flee_0.pal.inc.c"

#include "ui/battle/cmd/flee_1.png.inc.c"
#include "ui/battle/cmd/flee_1.pal.inc.c"

#include "ui/battle/cmd/flee_2.png.inc.c"
#include "ui/battle/cmd/flee_2.pal.inc.c"

#include "ui/battle/cmd/100pct.png.inc.c"
#include "ui/battle/cmd/100pct.pal.inc.c"

#include "ui/battle/cmd/right_on.png.inc.c"
#include "ui/battle/cmd/right_on.pal.inc.c"

#include "ui/battle/cmd/fill_result.png.inc.c"
#include "ui/battle/cmd/fill_result.pal.inc.c"

#include "ui/battle/cmd/aim/marker_0.png.inc.c"
#include "ui/battle/cmd/aim/marker_0.pal.inc.c"

#include "ui/battle/cmd/aim/marker_1.png.inc.c"
#include "ui/battle/cmd/aim/marker_1.pal.inc.c"

#include "ui/battle/cmd/aim/marker_2.png.inc.c"
#include "ui/battle/cmd/aim/marker_2.pal.inc.c"

#include "ui/battle/cmd/aim/marker_3.png.inc.c"
#include "ui/battle/cmd/aim/marker_3.pal.inc.c"

#include "ui/battle/cmd/aim/marker_4.png.inc.c"
#include "ui/battle/cmd/aim/marker_4.pal.inc.c"

#include "ui/battle/cmd/aim/marker_5.png.inc.c"
#include "ui/battle/cmd/aim/marker_5.pal.inc.c"

#include "ui/battle/cmd/aim/marker_6.png.inc.c"
#include "ui/battle/cmd/aim/marker_6.pal.inc.c"

#include "ui/battle/cmd/aim/marker_7.png.inc.c"
#include "ui/battle/cmd/aim/marker_7.pal.inc.c"

#include "ui/battle/cmd/aim/shimmer_0.png.inc.c"
#include "ui/battle/cmd/aim/shimmer_0.pal.inc.c"

#include "ui/battle/cmd/aim/shimmer_1.png.inc.c"
#include "ui/battle/cmd/aim/shimmer_1.pal.inc.c"

#include "ui/battle/cmd/aim/shimmer_2.png.inc.c"
#include "ui/battle/cmd/aim/shimmer_2.pal.inc.c"

#include "ui/battle/cmd/aim/shimmer_3.png.inc.c"
#include "ui/battle/cmd/aim/shimmer_3.pal.inc.c"

#include "ui/battle/cmd/aim/shimmer_4.png.inc.c"
#include "ui/battle/cmd/aim/shimmer_4.pal.inc.c"

#include "ui/battle/cmd/aim/shimmer_5.png.inc.c"
#include "ui/battle/cmd/aim/shimmer_5.pal.inc.c"

#include "ui/battle/cmd/aim/shimmer_6.png.inc.c"
#include "ui/battle/cmd/aim/shimmer_6.pal.inc.c"

#include "ui/battle/cmd/aim/shimmer_7.png.inc.c"
#include "ui/battle/cmd/aim/shimmer_7.pal.inc.c"

#include "ui/battle/cmd/aim/reticle_0.png.inc.c"
#include "ui/battle/cmd/aim/reticle_0.pal.inc.c"

#include "ui/battle/cmd/aim/reticle_1.png.inc.c"
#include "ui/battle/cmd/aim/reticle_1.pal.inc.c"

#include "ui/battle/cmd/aim/target_0.png.inc.c"
#include "ui/battle/cmd/aim/target_0.pal.inc.c"

#include "ui/battle/cmd/aim/target_1.png.inc.c"
#include "ui/battle/cmd/aim/target_1.pal.inc.c"

#include "ui/battle/solid_star.png.inc.c"
#include "ui/battle/solid_star.pal.inc.c"

Gfx D_8028F860[] = {
    gsSPEndDisplayList(),
};

#include "ui/battle/projector_spot.png.inc.c"

Gfx D_8028FC68[] = {
    gsSPEndDisplayList(),
};

#include "ui/battle/projector_beam.png.inc.c"

Gfx D_80290C70[] = {
    gsSPEndDisplayList(),
};

#include "ui/battle/projector_reel.png.inc.c"

Gfx D_80291C78[] = {
    gsSPEndDisplayList(),
};

#include "ui/battle/swap_background.png.inc.c"

HudScript HES_HPBar = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_bar, 32, 16);

HudScript HES_HPDigit0 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_0, 8, 8);

HudScript HES_HPDigit1 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_1, 8, 8);

HudScript HES_HPDigit2 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_2, 8, 8);

HudScript HES_HPDigit3 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_3, 8, 8);

HudScript HES_HPDigit4 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_4, 8, 8);

HudScript HES_HPDigit5 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_5, 8, 8);

HudScript HES_HPDigit6 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_6, 8, 8);

HudScript HES_HPDigit7 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_7, 8, 8);

HudScript HES_HPDigit8 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_8, 8, 8);

HudScript HES_HPDigit9 = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_hp_9, 8, 8);

HudScript HES_YellowArrow = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_yellow_arrow, 16, 16);

HudScript HES_MenuFlee = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_flee, 32, 32);

HudScript HES_MenuFleeDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_flee_disabled, 32, 32);

HudScript HES_MenuDefend = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_defend, 32, 32);

HudScript HES_MenuDefendDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_defend_disabled, 32, 32);

HudScript HES_MenuStrategies = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_strategies, 32, 32);

HudScript HES_MenuStrategiesDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_strategies_disabled, 32, 32);

HudScript HES_MenuPouch = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_pouch, 32, 32);

HudScript HES_MenuPouchDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_pouch_disabled, 32, 32);

HudScript HES_MenuDoNothing = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_nothing, 32, 32);

HudScript HES_MenuDoNothingDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_menu_nothing_disabled, 32, 32);

HudScript HES_TimingBar1Chance = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_timing_1_chance, 72, 24);

HudScript HES_BButton = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_b_up, 48, 40);

HudScript HES_BButtonHeld = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_b_down, 48, 40);

HudScript HES_MashBButton1 = {
    hs_SetVisible
    hs_SetCustomSize(48, 40)
    hs_Loop
        hs_SetCI(2, ui_battle_cont_b_up)
        hs_SetCI(2, ui_battle_cont_b_down)
    hs_Restart
    hs_End
};

HudScript HES_PressBButton = {
    hs_SetVisible
    hs_SetCustomSize(48, 40)
    hs_Loop
        hs_SetCI(3, ui_battle_cont_b_down)
        hs_SetCI(10, ui_battle_cont_b_up)
        hs_SetCI(7, ui_battle_cont_b_down)
    hs_Restart
    hs_End
};

HudScript HES_MashBButton2 = {
    hs_SetVisible
    hs_SetCustomSize(48, 40)
    hs_Loop
        hs_SetCI(2, ui_battle_cont_b_down)
        hs_SetCI(2, ui_battle_cont_b_up)
    hs_Restart
    hs_End
};

HudScript HES_CLeftButton = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_c_left_up, 40, 34);

HudScript HES_CLeftButtonHeld = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_c_left_down, 40, 34);

HudScript HES_MashCLeftButton = {
    hs_SetVisible
    hs_SetCustomSize(40, 34)
    hs_Loop
        hs_SetCI(2, ui_battle_cont_c_left_up)
        hs_SetCI(2, ui_battle_cont_c_left_down)
    hs_Restart
    hs_End
};

HudScript HES_CRightButton = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_c_right_up, 40, 34);

HudScript HES_CRightButtonHeld = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_c_right_down, 40, 34);

HudScript HES_MashCRightButton1 = {
    hs_SetVisible
    hs_SetCustomSize(40, 34)
    hs_Loop
        hs_SetCI(2, ui_battle_cont_c_right_up)
        hs_SetCI(2, ui_battle_cont_c_right_down)
    hs_Restart
    hs_End
};

HudScript HES_MashCRightButton2 = {
    hs_SetVisible
    hs_SetCustomSize(40, 34)
    hs_Loop
        hs_SetCI(2, ui_battle_cont_c_right_down)
        hs_SetCI(2, ui_battle_cont_c_right_up)
    hs_Restart
    hs_End
};

HudScript HES_CUpButton = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_c_up_up, 40, 34);

HudScript HES_CUpButtonHeld = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_c_up_down, 40, 34);

HudScript HES_MashCUpButton = {
    hs_SetVisible
    hs_SetCustomSize(40, 34)
    hs_Loop
        hs_SetCI(2, ui_battle_cont_c_up_up)
        hs_SetCI(2, ui_battle_cont_c_up_down)
    hs_Restart
    hs_End
};

HudScript HES_CDownButton = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_c_down_up, 40, 34);

HudScript HES_CDownButtonHeld = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cont_c_down_down, 40, 34);

HudScript HES_MashCDownButton1 = {
    hs_SetVisible
    hs_SetCustomSize(40, 34)
    hs_Loop
        hs_SetCI(2, ui_battle_cont_c_down_up)
        hs_SetCI(2, ui_battle_cont_c_down_down)
    hs_Restart
    hs_End
};

HudScript HES_PressCDownButton = {
    hs_SetVisible
    hs_SetCustomSize(40, 34)
    hs_Loop
        hs_SetCI(6, ui_battle_cont_c_down_down)
        hs_SetCI(10, ui_battle_cont_c_down_up)
        hs_SetCI(4, ui_battle_cont_c_down_down)
    hs_Restart
    hs_End
};

HudScript HES_MashCDownButton2 = {
    hs_SetVisible
    hs_SetCustomSize(40, 34)
    hs_Loop
        hs_SetCI(1, ui_battle_cont_c_down_up)
        hs_SetCI(2, ui_battle_cont_c_down_down)
        hs_SetCI(1, ui_battle_cont_c_down_up)
    hs_Restart
    hs_End
};

HudScript HES_TimingWait = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_timing_wait, 16, 16);

HudScript HES_TimingReady = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_timing_ready, 16, 16);

HudScript HES_TimingBlink = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(10, ui_battle_cmd_timing_ready)
        hs_SetCI(6, ui_battle_cmd_timing_wait)
    hs_Restart
    hs_End
};

HudScript HES_TimingCharge4a = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_charge_4, 8, 8);

HudScript HES_TimingCharge1 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_charge_1, 8, 8);

HudScript HES_TimingCharge4b = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_charge_4, 8, 8);

HudScript HES_TimingCharge2 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_charge_2, 8, 8);

HudScript HES_TimingCharge4c = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_charge_4, 8, 8);

HudScript HES_TimingCharge3 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_charge_3, 8, 8);

HudScript HES_RunningAway = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(16, 24)
        hs_SetCI(1, ui_battle_cmd_flee_0)
        hs_SetCI(1, ui_battle_cmd_flee_1)
        hs_SetCI(1, ui_battle_cmd_flee_2)
        hs_SetCI(1, ui_battle_cmd_flee_0)
        hs_SetCI(1, ui_battle_cmd_flee_2)
        hs_SetCI(1, ui_battle_cmd_flee_1)
    hs_Restart
    hs_End
};

HudScript HES_100pct = {
    hs_SetVisible
    hs_SetCustomSize(64, 48)
    hs_Loop
        hs_SetTexelOffset(0, -16)
        hs_SetScale(1.00)
        hs_SetCI(1, ui_battle_cmd_100pct)
        hs_SetScale(1.20)
        hs_SetCI(1, ui_battle_cmd_100pct)
        hs_SetScale(1.30)
        hs_SetCI(1, ui_battle_cmd_100pct)
        hs_SetScale(1.27)
        hs_SetCI(1, ui_battle_cmd_100pct)
        hs_SetScale(1.15)
        hs_SetCI(1, ui_battle_cmd_100pct)
        hs_SetScale(1.05)
        hs_SetCI(1, ui_battle_cmd_100pct)
    hs_Restart
    hs_End
};

HudScript HES_RightOn = {
    hs_SetVisible
    hs_SetCustomSize(56, 24)
    hs_Loop
        hs_SetTexelOffset(0, -16)
        hs_SetScale(1.00)
        hs_SetCI(1, ui_battle_cmd_right_on)
        hs_SetScale(1.10)
        hs_SetCI(1, ui_battle_cmd_right_on)
        hs_SetScale(1.20)
        hs_SetCI(1, ui_battle_cmd_right_on)
        hs_SetScale(1.30)
        hs_SetCI(2, ui_battle_cmd_right_on)
        hs_SetScale(1.27)
        hs_SetCI(2, ui_battle_cmd_right_on)
        hs_SetScale(1.15)
        hs_SetCI(2, ui_battle_cmd_right_on)
        hs_SetScale(1.05)
        hs_SetCI(2, ui_battle_cmd_right_on)
    hs_Restart
    hs_End
};

HudScript HES_TimingBar3Chances = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_timing_3_chances, 96, 24);

HudScript HES_TimingGaugeResult = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_gauge_result, 32, 24);

HudScript HES_TimingOK = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_timing_ok, 24, 24);

HudScript HES_TimingMiss = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_timing_miss, 24, 24);

HudScript HES_FillGaugeResult = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_cmd_fill_result, 32, 24);

HudScript HES_ProjectorReel = {
    hs_UseIA8
    hs_SetCustomSize(64, 64)
    hs_Loop
        hs_SetRGBA(60, ui_battle_projector_reel_png)
    hs_Restart
    hs_End
};

HudScript HES_ProjectorSpot = {
    hs_UseIA8
    hs_SetCustomSize(32, 32)
    hs_Loop
        hs_SetRGBA(60, ui_battle_projector_spot_png)
    hs_Restart
    hs_End
};

HudScript HES_ProjectorBeam = {
    hs_UseIA8
    hs_SetCustomSize(64, 64)
    hs_Loop
        hs_SetRGBA(60, ui_battle_projector_beam_png)
    hs_Restart
    hs_End
};

HudScript HES_SwapZ = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_swap_Z, 16, 16);

HudScript HES_SwapArrowLeft = {
    hs_SetVisible
    hs_SetCustomSize(8, 16)
    hs_Loop
        hs_SetCI(12, ui_battle_swap_arrow_left)
        hs_SetCI(8, ui_battle_swap_arrow_left)
    hs_Restart
    hs_End
};

HudScript HES_SwapArrowRight = {
    hs_SetVisible
    hs_SetCustomSize(8, 16)
    hs_Loop
        hs_SetCI(10, ui_battle_swap_arrow_right)
        hs_SetCI(10, ui_battle_swap_arrow_right)
    hs_Restart
    hs_End
};

HudScript HES_SwapBackground = {
    hs_UseIA8
    hs_SetCustomSize(48, 16)
    hs_Loop
        hs_SetRGBA(60, ui_battle_swap_background_png)
    hs_Restart
    hs_End
};

HudScript HES_AimMarkerA = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetCI(3, ui_battle_cmd_aim_marker_1)
        hs_SetCI(3, ui_battle_cmd_aim_marker_2)
        hs_SetCI(3, ui_battle_cmd_aim_marker_3)
        hs_SetCI(3, ui_battle_cmd_aim_marker_4)
        hs_SetCI(3, ui_battle_cmd_aim_marker_5)
        hs_SetCI(3, ui_battle_cmd_aim_marker_6)
        hs_SetCI(3, ui_battle_cmd_aim_marker_7)
    hs_Restart
    hs_End
};

HudScript HES_AimMarkerB = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_marker_1)
        hs_SetCI(3, ui_battle_cmd_aim_marker_2)
        hs_SetCI(3, ui_battle_cmd_aim_marker_3)
        hs_SetCI(3, ui_battle_cmd_aim_marker_4)
        hs_SetCI(3, ui_battle_cmd_aim_marker_5)
        hs_SetCI(3, ui_battle_cmd_aim_marker_6)
        hs_SetCI(3, ui_battle_cmd_aim_marker_7)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
    hs_Restart
    hs_End
};

HudScript HES_AimMarkerC = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_marker_2)
        hs_SetCI(3, ui_battle_cmd_aim_marker_3)
        hs_SetCI(3, ui_battle_cmd_aim_marker_4)
        hs_SetCI(3, ui_battle_cmd_aim_marker_5)
        hs_SetCI(3, ui_battle_cmd_aim_marker_6)
        hs_SetCI(3, ui_battle_cmd_aim_marker_7)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetCI(3, ui_battle_cmd_aim_marker_1)
    hs_Restart
    hs_End
};

HudScript HES_AimMarkerD = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_marker_3)
        hs_SetCI(3, ui_battle_cmd_aim_marker_4)
        hs_SetCI(3, ui_battle_cmd_aim_marker_5)
        hs_SetCI(3, ui_battle_cmd_aim_marker_6)
        hs_SetCI(3, ui_battle_cmd_aim_marker_7)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetCI(3, ui_battle_cmd_aim_marker_1)
        hs_SetCI(3, ui_battle_cmd_aim_marker_2)
    hs_Restart
    hs_End
};

HudScript HES_AimMarkerE = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_marker_4)
        hs_SetCI(3, ui_battle_cmd_aim_marker_5)
        hs_SetCI(3, ui_battle_cmd_aim_marker_6)
        hs_SetCI(3, ui_battle_cmd_aim_marker_7)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetCI(3, ui_battle_cmd_aim_marker_1)
        hs_SetCI(3, ui_battle_cmd_aim_marker_2)
        hs_SetCI(3, ui_battle_cmd_aim_marker_3)
    hs_Restart
    hs_End
};

HudScript HES_AimMarkerF = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_marker_5)
        hs_SetCI(3, ui_battle_cmd_aim_marker_6)
        hs_SetCI(3, ui_battle_cmd_aim_marker_7)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetCI(3, ui_battle_cmd_aim_marker_1)
        hs_SetCI(3, ui_battle_cmd_aim_marker_2)
        hs_SetCI(3, ui_battle_cmd_aim_marker_3)
        hs_SetCI(3, ui_battle_cmd_aim_marker_4)
    hs_Restart
    hs_End
};

HudScript HES_AimMarkerG = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_marker_6)
        hs_SetCI(3, ui_battle_cmd_aim_marker_7)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetCI(3, ui_battle_cmd_aim_marker_1)
        hs_SetCI(3, ui_battle_cmd_aim_marker_2)
        hs_SetCI(3, ui_battle_cmd_aim_marker_3)
        hs_SetCI(3, ui_battle_cmd_aim_marker_4)
        hs_SetCI(3, ui_battle_cmd_aim_marker_5)
    hs_Restart
    hs_End
};

HudScript HES_AimMarkerH = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_marker_7)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetCI(3, ui_battle_cmd_aim_marker_1)
        hs_SetCI(3, ui_battle_cmd_aim_marker_2)
        hs_SetCI(3, ui_battle_cmd_aim_marker_3)
        hs_SetCI(3, ui_battle_cmd_aim_marker_4)
        hs_SetCI(3, ui_battle_cmd_aim_marker_5)
        hs_SetCI(3, ui_battle_cmd_aim_marker_6)
    hs_Restart
    hs_End
};

HudScript HES_AimShimmerA = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_0)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_1)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_2)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_3)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_4)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_5)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_6)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_7)
    hs_Restart
    hs_End
};

HudScript HES_AimShimmerB = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_1)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_2)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_3)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_4)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_5)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_6)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_7)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_0)
    hs_Restart
    hs_End
};

HudScript HES_AimShimmerC = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_2)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_3)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_4)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_5)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_6)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_7)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_0)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_1)
    hs_Restart
    hs_End
};

HudScript HES_AimShimmerD = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_3)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_4)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_5)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_6)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_7)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_0)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_1)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_2)
    hs_Restart
    hs_End
};

HudScript HES_AimShimmerE = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_4)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_5)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_6)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_7)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_0)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_1)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_2)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_3)
    hs_Restart
    hs_End
};

HudScript HES_AimShimmerF = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_5)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_6)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_7)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_0)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_1)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_2)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_3)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_4)
    hs_Restart
    hs_End
};

HudScript HES_AimShimmerG = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_6)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_7)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_0)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_1)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_2)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_3)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_4)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_5)
    hs_Restart
    hs_End
};

HudScript HES_AimShimmerH = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_7)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_0)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_1)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_2)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_3)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_4)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_5)
        hs_SetCI(3, ui_battle_cmd_aim_shimmer_6)
    hs_Restart
    hs_End
};

HudScript HES_AimReticle = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_32x32)
    hs_Loop
        hs_SetCI(8, ui_battle_cmd_aim_reticle_0)
        hs_SetCI(5, ui_battle_cmd_aim_reticle_1)
    hs_Restart
    hs_End
};

HudScript HES_AimTarget = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
    hs_Loop
        hs_SetCI(2, ui_battle_cmd_aim_target_0)
        hs_SetCI(2, ui_battle_cmd_aim_target_1)
    hs_Restart
    hs_End
};

HudScript HES_AimBlinkA = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
    hs_Restart
    hs_End
};

HudScript HES_AimBlinkB = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
    hs_Restart
    hs_End
};

HudScript HES_AimBlinkC = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(3, ui_battle_cmd_aim_marker_0)
    hs_Restart
    hs_End
};
