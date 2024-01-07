#include "common.h"
#include "hud_element.h"
#include "sparkle_script.h"
#include "include_asset.h"
#include "include_asset.h"

INCLUDE_IMG("ui/input/a_button_unpressed.png", ui_input_a_button_unpressed_png);
INCLUDE_PAL("ui/input/a_button_unpressed.pal", ui_input_a_button_unpressed_pal);

INCLUDE_IMG("ui/input/a_button_pressed.png", ui_input_a_button_pressed_png);
INCLUDE_PAL("ui/input/a_button_pressed.pal", ui_input_a_button_pressed_pal);

INCLUDE_IMG("ui/input/analog_stick.png", ui_input_analog_stick_png);
INCLUDE_PAL("ui/input/analog_stick.pal", ui_input_analog_stick_pal);

INCLUDE_IMG("ui/input/analog_stick_left.png", ui_input_analog_stick_left_png);
INCLUDE_PAL("ui/input/analog_stick_left.pal", ui_input_analog_stick_left_pal);

INCLUDE_IMG("ui/input/analog_stick2.png", ui_input_analog_stick2_png);
INCLUDE_PAL("ui/input/analog_stick2.pal", ui_input_analog_stick2_pal);

INCLUDE_IMG("ui/input/analog_stick_right.png", ui_input_analog_stick_right_png);
INCLUDE_PAL("ui/input/analog_stick_right.pal", ui_input_analog_stick_right_pal);

INCLUDE_IMG("ui/input/analog_stick3.png", ui_input_analog_stick3_png);
INCLUDE_PAL("ui/input/analog_stick3.pal", ui_input_analog_stick3_pal);

INCLUDE_IMG("ui/input/analog_stick_down.png", ui_input_analog_stick_down_png);
INCLUDE_PAL("ui/input/analog_stick_down.pal", ui_input_analog_stick_down_pal);

INCLUDE_IMG("ui/input/analog_stick_up.png", ui_input_analog_stick_up_png);
INCLUDE_PAL("ui/input/analog_stick_up.pal", ui_input_analog_stick_up_pal);

INCLUDE_IMG("ui/unk_bar.png", ui_unk_bar_png);
INCLUDE_PAL("ui/unk_bar.pal", ui_unk_bar_pal);

INCLUDE_IMG("ui/ok.png", ui_ok_png);
INCLUDE_PAL("ui/ok.pal", ui_ok_pal);

INCLUDE_IMG("ui/input/start_button.png", ui_input_start_button_png);
INCLUDE_PAL("ui/input/start_button.pal", ui_input_start_button_pal);

INCLUDE_IMG("ui/input/start_button2.png", ui_input_start_button2_png);
INCLUDE_PAL("ui/input/start_button2.pal", ui_input_start_button2_pal);

INCLUDE_IMG("ui/input/start_text.png", ui_input_start_text_png);
INCLUDE_PAL("ui/input/start_text.pal", ui_input_start_text_pal);

INCLUDE_IMG("ui/hammer.png", ui_hammer_png);
INCLUDE_PAL("ui/hammer.pal", ui_hammer_pal);
#define ui_hammer_disabled_png ui_hammer_png
INCLUDE_PAL("ui/hammer.disabled.pal", ui_hammer_disabled_pal);

INCLUDE_IMG("ui/super_hammer.png", ui_super_hammer_png);
INCLUDE_PAL("ui/super_hammer.pal", ui_super_hammer_pal);
#define ui_super_hammer_disabled_png ui_super_hammer_png
INCLUDE_PAL("ui/super_hammer.disabled.pal", ui_super_hammer_disabled_pal);

INCLUDE_IMG("ui/ultra_hammer.png", ui_ultra_hammer_png);
INCLUDE_PAL("ui/ultra_hammer.pal", ui_ultra_hammer_pal);
#define ui_ultra_hammer_disabled_png ui_ultra_hammer_png
INCLUDE_PAL("ui/ultra_hammer.disabled.pal", ui_ultra_hammer_disabled_pal);

INCLUDE_IMG("ui/boots.png", ui_boots_png);
INCLUDE_PAL("ui/boots.pal", ui_boots_pal);
#define ui_boots_disabled_png ui_boots_png
INCLUDE_PAL("ui/boots.disabled.pal", ui_boots_disabled_pal);

INCLUDE_IMG("ui/super_boots.png", ui_super_boots_png);
INCLUDE_PAL("ui/super_boots.pal", ui_super_boots_pal);
#define ui_super_boots_disabled_png ui_super_boots_png
INCLUDE_PAL("ui/super_boots.disabled.pal", ui_super_boots_disabled_pal);

INCLUDE_IMG("ui/ultra_boots.png", ui_ultra_boots_png);
INCLUDE_PAL("ui/ultra_boots.pal", ui_ultra_boots_pal);
#define ui_ultra_boots_disabled_png ui_ultra_boots_png
INCLUDE_PAL("ui/ultra_boots.disabled.pal", ui_ultra_boots_disabled_pal);

INCLUDE_IMG("ui/item.png", ui_item_png);
INCLUDE_PAL("ui/item.pal", ui_item_pal);
#define ui_item_disabled_png ui_item_png
INCLUDE_PAL("ui/item.disabled.pal", ui_item_disabled_pal);

INCLUDE_IMG("ui/star_spirit.png", ui_star_spirit_png);
INCLUDE_PAL("ui/star_spirit.pal", ui_star_spirit_pal);
#define ui_star_spirit_disabled_png ui_star_spirit_png
INCLUDE_PAL("ui/star_spirit.disabled.pal", ui_star_spirit_disabled_pal);

INCLUDE_IMG("ui/arrow_left.png", ui_arrow_left_png);
INCLUDE_PAL("ui/arrow_left.pal", ui_arrow_left_pal);

INCLUDE_IMG("ui/arrow_right.png", ui_arrow_right_png);
INCLUDE_PAL("ui/arrow_right.pal", ui_arrow_right_pal);

INCLUDE_IMG("ui/point_right.png", ui_point_right_png);
INCLUDE_PAL("ui/point_right.pal", ui_point_right_pal);

INCLUDE_IMG("ui/pip.png", ui_pip_png);
INCLUDE_PAL("ui/pip.pal", ui_pip_pal);

INCLUDE_IMG("ui/pip2.png", ui_pip2_png);
INCLUDE_PAL("ui/pip2.pal", ui_pip2_pal);

INCLUDE_IMG("ui/coin_sparkle_0.png", ui_coin_sparkle_0_png);
INCLUDE_PAL("ui/coin_sparkle_0.pal", ui_coin_sparkle_0_pal);

INCLUDE_IMG("ui/coin_sparkle_1.png", ui_coin_sparkle_1_png);
INCLUDE_PAL("ui/coin_sparkle_1.pal", ui_coin_sparkle_1_pal);

INCLUDE_IMG("ui/coin_sparkle_2.png", ui_coin_sparkle_2_png);
INCLUDE_PAL("ui/coin_sparkle_2.pal", ui_coin_sparkle_2_pal);

INCLUDE_IMG("ui/coin_sparkle_3.png", ui_coin_sparkle_3_png);
INCLUDE_PAL("ui/coin_sparkle_3.pal", ui_coin_sparkle_3_pal);

INCLUDE_IMG("ui/coin_sparkle_4.png", ui_coin_sparkle_4_png);
INCLUDE_PAL("ui/coin_sparkle_4.pal", ui_coin_sparkle_4_pal);

INCLUDE_IMG("ui/coin_sparkle_5.png", ui_coin_sparkle_5_png);
INCLUDE_PAL("ui/coin_sparkle_5.pal", ui_coin_sparkle_5_pal);

INCLUDE_IMG("ui/coin_sparkle_none.png", ui_coin_sparkle_none_png);
INCLUDE_PAL("ui/coin_sparkle_none.pal", ui_coin_sparkle_none_pal);

INCLUDE_IMG("ui/status/star_point_shine.png", ui_status_star_point_shine_png);

INCLUDE_IMG("ui/status/star_piece_0.png", ui_status_star_piece_0_png);
INCLUDE_PAL("ui/status/star_piece_0.pal", ui_status_star_piece_0_pal);

INCLUDE_IMG("ui/status/star_piece_1.png", ui_status_star_piece_1_png);
INCLUDE_PAL("ui/status/star_piece_1.pal", ui_status_star_piece_1_pal);

INCLUDE_IMG("ui/status/star_piece_2.png", ui_status_star_piece_2_png);
INCLUDE_PAL("ui/status/star_piece_2.pal", ui_status_star_piece_2_pal);

INCLUDE_IMG("ui/menu_times.png", ui_menu_times_png);
INCLUDE_PAL("ui/menu_times.pal", ui_menu_times_pal);

INCLUDE_IMG("ui/fp_cost.png", ui_fp_cost_png);
INCLUDE_PAL("ui/fp_cost.pal", ui_fp_cost_pal);
#define ui_fp_cost_reduced_png ui_fp_cost_png
INCLUDE_PAL("ui/fp_cost.reduced.pal", ui_fp_cost_reduced_pal);
#define ui_fp_cost_reduced_twice_png ui_fp_cost_png
INCLUDE_PAL("ui/fp_cost.reduced_twice.pal", ui_fp_cost_reduced_twice_pal);
#define ui_fp_cost_notenough_png ui_fp_cost_png
INCLUDE_PAL("ui/fp_cost.notenough.pal", ui_fp_cost_notenough_pal);

INCLUDE_IMG("ui/pow_cost.png", ui_pow_cost_png);
INCLUDE_PAL("ui/pow_cost.pal", ui_pow_cost_pal);
#define ui_pow_cost_reduced_png ui_pow_cost_png
INCLUDE_PAL("ui/pow_cost.reduced.pal", ui_pow_cost_reduced_pal);
#define ui_pow_cost_reduced_twice_png ui_pow_cost_png
INCLUDE_PAL("ui/pow_cost.reduced_twice.pal", ui_pow_cost_reduced_twice_pal);
#define ui_pow_cost_notenough_png ui_pow_cost_png
INCLUDE_PAL("ui/pow_cost.notenough.pal", ui_pow_cost_notenough_pal);

#if VERSION_PAL
INCLUDE_IMG("de/ui/fp_cost.png", ui_fp_cost_de_png);
INCLUDE_PAL("de/ui/fp_cost.pal", ui_fp_cost_de_pal);
#define ui_fp_cost_de_reduced_png ui_fp_cost_de_png
INCLUDE_PAL("de/ui/fp_cost.reduced.pal", ui_fp_cost_de_reduced_pal);
#define ui_fp_cost_de_reduced_twice_png ui_fp_cost_de_png
INCLUDE_PAL("de/ui/fp_cost.reduced_twice.pal", ui_fp_cost_de_reduced_twice_pal);
#define ui_fp_cost_de_notenough_png ui_fp_cost_de_png
INCLUDE_PAL("de/ui/fp_cost.notenough.pal", ui_fp_cost_de_notenough_pal);

INCLUDE_IMG("de/ui/pow_cost.png", ui_pow_cost_de_png);
INCLUDE_PAL("de/ui/pow_cost.pal", ui_pow_cost_de_pal);
#define ui_pow_cost_de_reduced_png ui_pow_cost_de_png
INCLUDE_PAL("de/ui/pow_cost.reduced.pal", ui_pow_cost_de_reduced_pal);
#define ui_pow_cost_de_reduced_twice_png ui_pow_cost_de_png
INCLUDE_PAL("de/ui/pow_cost.reduced_twice.pal", ui_pow_cost_de_reduced_twice_pal);
#define ui_pow_cost_de_notenough_png ui_pow_cost_de_png
INCLUDE_PAL("de/ui/pow_cost.notenough.pal", ui_pow_cost_de_notenough_pal);

INCLUDE_IMG("fr/ui/fp_cost.png", ui_fp_cost_fr_png);
INCLUDE_PAL("fr/ui/fp_cost.pal", ui_fp_cost_fr_pal);
#define ui_fp_cost_fr_reduced_png ui_fp_cost_fr_png
INCLUDE_PAL("fr/ui/fp_cost.reduced.pal", ui_fp_cost_fr_reduced_pal);
#define ui_fp_cost_fr_reduced_twice_png ui_fp_cost_fr_png
INCLUDE_PAL("fr/ui/fp_cost.reduced_twice.pal", ui_fp_cost_fr_reduced_twice_pal);
#define ui_fp_cost_fr_notenough_png ui_fp_cost_fr_png
INCLUDE_PAL("fr/ui/fp_cost.notenough.pal", ui_fp_cost_fr_notenough_pal);

INCLUDE_IMG("fr/ui/pow_cost.png", ui_pow_cost_fr_png);
INCLUDE_PAL("fr/ui/pow_cost.pal", ui_pow_cost_fr_pal);
#define ui_pow_cost_fr_reduced_png ui_pow_cost_fr_png
INCLUDE_PAL("fr/ui/pow_cost.reduced.pal", ui_pow_cost_fr_reduced_pal);
#define ui_pow_cost_fr_reduced_twice_png ui_pow_cost_fr_png
INCLUDE_PAL("fr/ui/pow_cost.reduced_twice.pal", ui_pow_cost_fr_reduced_twice_pal);
#define ui_pow_cost_fr_notenough_png ui_pow_cost_fr_png
INCLUDE_PAL("fr/ui/pow_cost.notenough.pal", ui_pow_cost_fr_notenough_pal);

INCLUDE_IMG("es/ui/fp_cost.png", ui_fp_cost_es_png);
INCLUDE_PAL("es/ui/fp_cost.pal", ui_fp_cost_es_pal);
#define ui_fp_cost_es_reduced_png ui_fp_cost_es_png
INCLUDE_PAL("es/ui/fp_cost.reduced.pal", ui_fp_cost_es_reduced_pal);
#define ui_fp_cost_es_reduced_twice_png ui_fp_cost_es_png
INCLUDE_PAL("es/ui/fp_cost.reduced_twice.pal", ui_fp_cost_es_reduced_twice_pal);
#define ui_fp_cost_es_notenough_png ui_fp_cost_es_png
INCLUDE_PAL("es/ui/fp_cost.notenough.pal", ui_fp_cost_es_notenough_pal);

INCLUDE_IMG("es/ui/pow_cost.png", ui_pow_cost_es_png);
INCLUDE_PAL("es/ui/pow_cost.pal", ui_pow_cost_es_pal);
#define ui_pow_cost_es_reduced_png ui_pow_cost_es_png
INCLUDE_PAL("es/ui/pow_cost.reduced.pal", ui_pow_cost_es_reduced_pal);
#define ui_pow_cost_es_reduced_twice_png ui_pow_cost_es_png
INCLUDE_PAL("es/ui/pow_cost.reduced_twice.pal", ui_pow_cost_es_reduced_twice_pal);
#define ui_pow_cost_es_notenough_png ui_pow_cost_es_png
INCLUDE_PAL("es/ui/pow_cost.notenough.pal", ui_pow_cost_es_notenough_pal);
#endif

INCLUDE_IMG("ui/green_arrow_down.png", ui_green_arrow_down_png);
INCLUDE_PAL("ui/green_arrow_down.pal", ui_green_arrow_down_pal);

INCLUDE_IMG("ui/green_arrow_up.png", ui_green_arrow_up_png);
INCLUDE_PAL("ui/green_arrow_up.pal", ui_green_arrow_up_pal);

INCLUDE_IMG("ui/kaime.png", ui_kaime_png);
INCLUDE_PAL("ui/kaime.pal", ui_kaime_pal);

INCLUDE_IMG("ui/unused_1.png", ui_unused_1_png);
INCLUDE_PAL("ui/unused_1.pal", ui_unused_1_pal);

INCLUDE_IMG("ui/unused_2.png", ui_unused_2_png);
INCLUDE_PAL("ui/unused_2.pal", ui_unused_2_pal);

INCLUDE_IMG("ui/unused_3.png", ui_unused_3_png);
INCLUDE_PAL("ui/unused_3.pal", ui_unused_3_pal);

INCLUDE_IMG("ui/red_bar1.png", ui_red_bar1_png);
INCLUDE_PAL("ui/red_bar1.pal", ui_red_bar1_pal);

INCLUDE_IMG("ui/empty_bar.png", ui_empty_bar_png);
INCLUDE_PAL("ui/empty_bar.pal", ui_empty_bar_pal);

INCLUDE_IMG("ui/red_bar2.png", ui_red_bar2_png);
INCLUDE_PAL("ui/red_bar2.pal", ui_red_bar2_pal);

INCLUDE_IMG("ui/eldstar.png", ui_eldstar_png);
INCLUDE_PAL("ui/eldstar.pal", ui_eldstar_pal);
#define ui_eldstar_disabled_png ui_eldstar_png
INCLUDE_PAL("ui/eldstar.disabled.pal", ui_eldstar_disabled_pal);

INCLUDE_IMG("ui/mamar.png", ui_mamar_png);
INCLUDE_PAL("ui/mamar.pal", ui_mamar_pal);
#define ui_mamar_disabled_png ui_mamar_png
INCLUDE_PAL("ui/mamar.disabled.pal", ui_mamar_disabled_pal);

INCLUDE_IMG("ui/skolar.png", ui_skolar_png);
INCLUDE_PAL("ui/skolar.pal", ui_skolar_pal);
#define ui_skolar_disabled_png ui_skolar_png
INCLUDE_PAL("ui/skolar.disabled.pal", ui_skolar_disabled_pal);

INCLUDE_IMG("ui/muskular.png", ui_muskular_png);
INCLUDE_PAL("ui/muskular.pal", ui_muskular_pal);
#define ui_muskular_disabled_png ui_muskular_png
INCLUDE_PAL("ui/muskular.disabled.pal", ui_muskular_disabled_pal);

INCLUDE_IMG("ui/misstar.png", ui_misstar_png);
INCLUDE_PAL("ui/misstar.pal", ui_misstar_pal);
#define ui_misstar_disabled_png ui_misstar_png
INCLUDE_PAL("ui/misstar.disabled.pal", ui_misstar_disabled_pal);

INCLUDE_IMG("ui/klevar.png", ui_klevar_png);
INCLUDE_PAL("ui/klevar.pal", ui_klevar_pal);
#define ui_klevar_disabled_png ui_klevar_png
INCLUDE_PAL("ui/klevar.disabled.pal", ui_klevar_disabled_pal);

INCLUDE_IMG("ui/kalmar.png", ui_kalmar_png);
INCLUDE_PAL("ui/kalmar.pal", ui_kalmar_pal);
#define ui_kalmar_disabled_png ui_kalmar_png
INCLUDE_PAL("ui/kalmar.disabled.pal", ui_kalmar_disabled_pal);

INCLUDE_IMG("ui/star_beam.png", ui_star_beam_png);
INCLUDE_PAL("ui/star_beam.pal", ui_star_beam_pal);
#define ui_star_beam_disabled_png ui_star_beam_png
INCLUDE_PAL("ui/star_beam.disabled.pal", ui_star_beam_disabled_pal);

INCLUDE_IMG("ui/peach_beam.png", ui_peach_beam_png);
INCLUDE_PAL("ui/peach_beam.pal", ui_peach_beam_pal);
#define ui_peach_beam_disabled_png ui_peach_beam_png
INCLUDE_PAL("ui/peach_beam.disabled.pal", ui_peach_beam_disabled_pal);

INCLUDE_IMG("ui/mario_head.png", ui_mario_head_png);
INCLUDE_PAL("ui/mario_head.pal", ui_mario_head_pal);

INCLUDE_IMG("ui/partner0.png", ui_partner0_png);
INCLUDE_PAL("ui/partner0.pal", ui_partner0_pal);
#define ui_partner0_disabled_png ui_partner0_png
INCLUDE_PAL("ui/partner0.disabled.pal", ui_partner0_disabled_pal);

INCLUDE_IMG("ui/goombario.png", ui_goombario_png);
INCLUDE_PAL("ui/goombario.pal", ui_goombario_pal);
#define ui_goombario_disabled_png ui_goombario_png
INCLUDE_PAL("ui/goombario.disabled.pal", ui_goombario_disabled_pal);

INCLUDE_IMG("ui/kooper.png", ui_kooper_png);
INCLUDE_PAL("ui/kooper.pal", ui_kooper_pal);
#define ui_kooper_disabled_png ui_kooper_png
INCLUDE_PAL("ui/kooper.disabled.pal", ui_kooper_disabled_pal);

INCLUDE_IMG("ui/bombette.png", ui_bombette_png);
INCLUDE_PAL("ui/bombette.pal", ui_bombette_pal);
#define ui_bombette_disabled_png ui_bombette_png
INCLUDE_PAL("ui/bombette.disabled.pal", ui_bombette_disabled_pal);

INCLUDE_IMG("ui/parakarry.png", ui_parakarry_png);
INCLUDE_PAL("ui/parakarry.pal", ui_parakarry_pal);
#define ui_parakarry_disabled_png ui_parakarry_png
INCLUDE_PAL("ui/parakarry.disabled.pal", ui_parakarry_disabled_pal);

INCLUDE_IMG("ui/bow.png", ui_bow_png);
INCLUDE_PAL("ui/bow.pal", ui_bow_pal);
#define ui_bow_disabled_png ui_bow_png
INCLUDE_PAL("ui/bow.disabled.pal", ui_bow_disabled_pal);

INCLUDE_IMG("ui/watt.png", ui_watt_png);
INCLUDE_PAL("ui/watt.pal", ui_watt_pal);
#define ui_watt_disabled_png ui_watt_png
INCLUDE_PAL("ui/watt.disabled.pal", ui_watt_disabled_pal);

INCLUDE_IMG("ui/sushie.png", ui_sushie_png);
INCLUDE_PAL("ui/sushie.pal", ui_sushie_pal);
#define ui_sushie_disabled_png ui_sushie_png
INCLUDE_PAL("ui/sushie.disabled.pal", ui_sushie_disabled_pal);

INCLUDE_IMG("ui/lakilester.png", ui_lakilester_png);
INCLUDE_PAL("ui/lakilester.pal", ui_lakilester_pal);
#define ui_lakilester_disabled_png ui_lakilester_png
INCLUDE_PAL("ui/lakilester.disabled.pal", ui_lakilester_disabled_pal);

INCLUDE_IMG("ui/partner9.png", ui_partner9_png);
INCLUDE_PAL("ui/partner9.pal", ui_partner9_pal);
#define ui_partner9_disabled_png ui_partner9_png
INCLUDE_PAL("ui/partner9.disabled.pal", ui_partner9_disabled_pal);

INCLUDE_IMG("ui/partner10.png", ui_partner10_png);
INCLUDE_PAL("ui/partner10.pal", ui_partner10_pal);
#define ui_partner10_disabled_png ui_partner10_png
INCLUDE_PAL("ui/partner10.disabled.pal", ui_partner10_disabled_pal);

INCLUDE_IMG("ui/partner11.png", ui_partner11_png);
INCLUDE_PAL("ui/partner11.pal", ui_partner11_pal);
#define ui_partner11_disabled_png ui_partner11_png
INCLUDE_PAL("ui/partner11.disabled.pal", ui_partner11_disabled_pal);

INCLUDE_IMG("ui/status/text_times.png", ui_status_text_times_png);
INCLUDE_PAL("ui/status/text_times.pal", ui_status_text_times_pal);

INCLUDE_IMG("ui/status/text_slash.png", ui_status_text_slash_png);
INCLUDE_PAL("ui/status/text_slash.pal", ui_status_text_slash_pal);

INCLUDE_IMG("ui/status/text_0.png", ui_status_text_0_png);
INCLUDE_PAL("ui/status/text_0.pal", ui_status_text_0_pal);

INCLUDE_IMG("ui/status/text_1.png", ui_status_text_1_png);
INCLUDE_PAL("ui/status/text_1.pal", ui_status_text_1_pal);

INCLUDE_IMG("ui/status/text_2.png", ui_status_text_2_png);
INCLUDE_PAL("ui/status/text_2.pal", ui_status_text_2_pal);

INCLUDE_IMG("ui/status/text_3.png", ui_status_text_3_png);
INCLUDE_PAL("ui/status/text_3.pal", ui_status_text_3_pal);

INCLUDE_IMG("ui/status/text_4.png", ui_status_text_4_png);
INCLUDE_PAL("ui/status/text_4.pal", ui_status_text_4_pal);

INCLUDE_IMG("ui/status/text_5.png", ui_status_text_5_png);
INCLUDE_PAL("ui/status/text_5.pal", ui_status_text_5_pal);

INCLUDE_IMG("ui/status/text_6.png", ui_status_text_6_png);
INCLUDE_PAL("ui/status/text_6.pal", ui_status_text_6_pal);

INCLUDE_IMG("ui/status/text_7.png", ui_status_text_7_png);
INCLUDE_PAL("ui/status/text_7.pal", ui_status_text_7_pal);

INCLUDE_IMG("ui/status/text_8.png", ui_status_text_8_png);
INCLUDE_PAL("ui/status/text_8.pal", ui_status_text_8_pal);

INCLUDE_IMG("ui/status/text_9.png", ui_status_text_9_png);
INCLUDE_PAL("ui/status/text_9.pal", ui_status_text_9_pal);

INCLUDE_IMG("ui/status/text_hp.png", ui_status_text_hp_png);
INCLUDE_PAL("ui/status/text_hp.pal", ui_status_text_hp_pal);

INCLUDE_IMG("ui/status/text_fp.png", ui_status_text_fp_png);
INCLUDE_PAL("ui/status/text_fp.pal", ui_status_text_fp_pal);

#if VERSION_PAL
INCLUDE_IMG("de/ui/status/text_hp.png", ui_status_text_hp_de_png);
INCLUDE_PAL("de/ui/status/text_hp.pal", ui_status_text_hp_de_pal);

INCLUDE_IMG("de/ui/status/text_fp.png", ui_status_text_fp_de_png);
INCLUDE_PAL("de/ui/status/text_fp.pal", ui_status_text_fp_de_pal);

INCLUDE_IMG("fr/ui/status/text_hp.png", ui_status_text_hp_fr_png);
INCLUDE_PAL("fr/ui/status/text_hp.pal", ui_status_text_hp_fr_pal);

INCLUDE_IMG("fr/ui/status/text_fp.png", ui_status_text_fp_fr_png);
INCLUDE_PAL("fr/ui/status/text_fp.pal", ui_status_text_fp_fr_pal);

INCLUDE_IMG("es/ui/status/text_hp.png", ui_status_text_hp_es_png);
INCLUDE_PAL("es/ui/status/text_hp.pal", ui_status_text_hp_es_pal);

INCLUDE_IMG("es/ui/status/text_fp.png", ui_status_text_fp_es_png);
INCLUDE_PAL("es/ui/status/text_fp.pal", ui_status_text_fp_es_pal);
#endif

INCLUDE_IMG("ui/status/pow_unit_1.png", ui_status_pow_unit_1_png);
INCLUDE_PAL("ui/status/pow_unit_1.pal", ui_status_pow_unit_1_pal);

INCLUDE_IMG("ui/status/pow_unit_2.png", ui_status_pow_unit_2_png);
INCLUDE_PAL("ui/status/pow_unit_2.pal", ui_status_pow_unit_2_pal);

INCLUDE_IMG("ui/status/pow_unit_3.png", ui_status_pow_unit_3_png);
INCLUDE_PAL("ui/status/pow_unit_3.pal", ui_status_pow_unit_3_pal);

INCLUDE_IMG("ui/status/pow_unit_4.png", ui_status_pow_unit_4_png);
INCLUDE_PAL("ui/status/pow_unit_4.pal", ui_status_pow_unit_4_pal);

INCLUDE_IMG("ui/status/pow_unit_5.png", ui_status_pow_unit_5_png);
INCLUDE_PAL("ui/status/pow_unit_5.pal", ui_status_pow_unit_5_pal);

INCLUDE_IMG("ui/status/pow_unit_6.png", ui_status_pow_unit_6_png);
INCLUDE_PAL("ui/status/pow_unit_6.pal", ui_status_pow_unit_6_pal);

INCLUDE_IMG("ui/status/pow_unit_7.png", ui_status_pow_unit_7_png);
INCLUDE_PAL("ui/status/pow_unit_7.pal", ui_status_pow_unit_7_pal);

INCLUDE_IMG("ui/status/pow_unit_empty.png", ui_status_pow_unit_empty_png);
INCLUDE_PAL("ui/status/pow_unit_empty.pal", ui_status_pow_unit_empty_pal);

INCLUDE_IMG("ui/status/pow_star_1.png", ui_status_pow_star_1_png);
INCLUDE_PAL("ui/status/pow_star_1.pal", ui_status_pow_star_1_pal);

INCLUDE_IMG("ui/status/pow_star_2.png", ui_status_pow_star_2_png);
INCLUDE_PAL("ui/status/pow_star_2.pal", ui_status_pow_star_2_pal);

INCLUDE_IMG("ui/status/pow_star_3.png", ui_status_pow_star_3_png);
INCLUDE_PAL("ui/status/pow_star_3.pal", ui_status_pow_star_3_pal);

INCLUDE_IMG("ui/status/pow_star_4.png", ui_status_pow_star_4_png);
INCLUDE_PAL("ui/status/pow_star_4.pal", ui_status_pow_star_4_pal);

INCLUDE_IMG("ui/status/pow_star_5.png", ui_status_pow_star_5_png);
INCLUDE_PAL("ui/status/pow_star_5.pal", ui_status_pow_star_5_pal);

INCLUDE_IMG("ui/status/pow_star_6.png", ui_status_pow_star_6_png);
INCLUDE_PAL("ui/status/pow_star_6.pal", ui_status_pow_star_6_pal);

INCLUDE_IMG("ui/status/pow_star_7.png", ui_status_pow_star_7_png);
INCLUDE_PAL("ui/status/pow_star_7.pal", ui_status_pow_star_7_pal);

INCLUDE_IMG("ui/status/pow_star_empty.png", ui_status_pow_star_empty_png);
INCLUDE_PAL("ui/status/pow_star_empty.pal", ui_status_pow_star_empty_pal);

INCLUDE_IMG("ui/status/coin_0.png", ui_status_coin_0_png);
INCLUDE_PAL("ui/status/coin_0.pal", ui_status_coin_0_pal);

INCLUDE_IMG("ui/status/coin_1.png", ui_status_coin_1_png);
INCLUDE_PAL("ui/status/coin_1.pal", ui_status_coin_1_pal);

INCLUDE_IMG("ui/status/coin_2.png", ui_status_coin_2_png);
INCLUDE_PAL("ui/status/coin_2.pal", ui_status_coin_2_pal);

INCLUDE_IMG("ui/status/coin_3.png", ui_status_coin_3_png);
INCLUDE_PAL("ui/status/coin_3.pal", ui_status_coin_3_pal);

INCLUDE_IMG("ui/status/coin_4.png", ui_status_coin_4_png);
INCLUDE_PAL("ui/status/coin_4.pal", ui_status_coin_4_pal);

INCLUDE_IMG("ui/status/coin_5.png", ui_status_coin_5_png);
INCLUDE_PAL("ui/status/coin_5.pal", ui_status_coin_5_pal);

INCLUDE_IMG("ui/status/coin_6.png", ui_status_coin_6_png);
INCLUDE_PAL("ui/status/coin_6.pal", ui_status_coin_6_pal);

INCLUDE_IMG("ui/status/coin_7.png", ui_status_coin_7_png);
INCLUDE_PAL("ui/status/coin_7.pal", ui_status_coin_7_pal);

INCLUDE_IMG("ui/status/coin_8.png", ui_status_coin_8_png);
INCLUDE_PAL("ui/status/coin_8.pal", ui_status_coin_8_pal);

INCLUDE_IMG("ui/status/coin_9.png", ui_status_coin_9_png);
INCLUDE_PAL("ui/status/coin_9.pal", ui_status_coin_9_pal);

INCLUDE_IMG("ui/status/star_point_0.png", ui_status_star_point_0_png);
INCLUDE_PAL("ui/status/star_point_0.pal", ui_status_star_point_0_pal);

INCLUDE_IMG("ui/status/star_point_1.png", ui_status_star_point_1_png);
INCLUDE_PAL("ui/status/star_point_1.pal", ui_status_star_point_1_pal);

INCLUDE_IMG("ui/status/star_point_2.png", ui_status_star_point_2_png);
INCLUDE_PAL("ui/status/star_point_2.pal", ui_status_star_point_2_pal);

INCLUDE_IMG("ui/status/star_point_3.png", ui_status_star_point_3_png);
INCLUDE_PAL("ui/status/star_point_3.pal", ui_status_star_point_3_pal);

INCLUDE_IMG("ui/status/star_point_4.png", ui_status_star_point_4_png);
INCLUDE_PAL("ui/status/star_point_4.pal", ui_status_star_point_4_pal);

INCLUDE_IMG("ui/status/star_point_5.png", ui_status_star_point_5_png);
INCLUDE_PAL("ui/status/star_point_5.pal", ui_status_star_point_5_pal);

INCLUDE_IMG("ui/status/star_point_6.png", ui_status_star_point_6_png);
INCLUDE_PAL("ui/status/star_point_6.pal", ui_status_star_point_6_pal);

INCLUDE_IMG("ui/status/star_point_7.png", ui_status_star_point_7_png);
INCLUDE_PAL("ui/status/star_point_7.pal", ui_status_star_point_7_pal);

INCLUDE_IMG("ui/bluepip.png", ui_bluepip_png);
INCLUDE_PAL("ui/bluepip.pal", ui_bluepip_pal);

INCLUDE_IMG("ui/bluepip2.png", ui_bluepip2_png);
INCLUDE_PAL("ui/bluepip2.pal", ui_bluepip2_pal);

INCLUDE_IMG("ui/battle/status/charge_jump.png", ui_battle_status_charge_jump_png);
INCLUDE_PAL("ui/battle/status/charge_jump.pal", ui_battle_status_charge_jump_pal);

INCLUDE_IMG("ui/battle/status/charge_hammer.png", ui_battle_status_charge_hammer_png);
INCLUDE_PAL("ui/battle/status/charge_hammer.pal", ui_battle_status_charge_hammer_pal);

INCLUDE_IMG("ui/battle/status/charge_goombario.png", ui_battle_status_charge_goombario_png);
INCLUDE_PAL("ui/battle/status/charge_goombario.pal", ui_battle_status_charge_goombario_pal);

INCLUDE_IMG("ui/battle/status/exclamation.png", ui_battle_status_exclamation_png);
INCLUDE_PAL("ui/battle/status/exclamation.pal", ui_battle_status_exclamation_pal);

INCLUDE_IMG("ui/battle/status/sleep_0.png", ui_battle_status_sleep_0_png);
INCLUDE_PAL("ui/battle/status/sleep_0.pal", ui_battle_status_sleep_0_pal);

INCLUDE_IMG("ui/battle/status/sleep_1.png", ui_battle_status_sleep_1_png);
INCLUDE_PAL("ui/battle/status/sleep_1.pal", ui_battle_status_sleep_1_pal);

INCLUDE_IMG("ui/battle/status/sleep_2.png", ui_battle_status_sleep_2_png);
INCLUDE_PAL("ui/battle/status/sleep_2.pal", ui_battle_status_sleep_2_pal);

INCLUDE_IMG("ui/battle/status/static_0.png", ui_battle_status_static_0_png);
INCLUDE_PAL("ui/battle/status/static_0.pal", ui_battle_status_static_0_pal);

INCLUDE_IMG("ui/battle/status/static_1.png", ui_battle_status_static_1_png);
INCLUDE_PAL("ui/battle/status/static_1.pal", ui_battle_status_static_1_pal);

INCLUDE_IMG("ui/battle/status/paralyze_0.png", ui_battle_status_paralyze_0_png);
INCLUDE_PAL("ui/battle/status/paralyze_0.pal", ui_battle_status_paralyze_0_pal);

INCLUDE_IMG("ui/battle/status/paralyze_1.png", ui_battle_status_paralyze_1_png);
INCLUDE_PAL("ui/battle/status/paralyze_1.pal", ui_battle_status_paralyze_1_pal);

INCLUDE_IMG("ui/battle/status/dizzy_0.png", ui_battle_status_dizzy_0_png);
INCLUDE_PAL("ui/battle/status/dizzy_0.pal", ui_battle_status_dizzy_0_pal);

INCLUDE_IMG("ui/battle/status/dizzy_1.png", ui_battle_status_dizzy_1_png);
INCLUDE_PAL("ui/battle/status/dizzy_1.pal", ui_battle_status_dizzy_1_pal);

INCLUDE_IMG("ui/battle/status/dizzy_2.png", ui_battle_status_dizzy_2_png);
INCLUDE_PAL("ui/battle/status/dizzy_2.pal", ui_battle_status_dizzy_2_pal);

INCLUDE_IMG("ui/battle/status/dizzy_3.png", ui_battle_status_dizzy_3_png);
INCLUDE_PAL("ui/battle/status/dizzy_3.pal", ui_battle_status_dizzy_3_pal);

INCLUDE_IMG("ui/battle/status/poison_0.png", ui_battle_status_poison_0_png);
INCLUDE_PAL("ui/battle/status/poison_0.pal", ui_battle_status_poison_0_pal);

INCLUDE_IMG("ui/battle/status/poison_1.png", ui_battle_status_poison_1_png);
INCLUDE_PAL("ui/battle/status/poison_1.pal", ui_battle_status_poison_1_pal);

INCLUDE_IMG("ui/battle/status/frozen_0.png", ui_battle_status_frozen_0_png);
INCLUDE_PAL("ui/battle/status/frozen_0.pal", ui_battle_status_frozen_0_pal);

INCLUDE_IMG("ui/battle/status/frozen_1.png", ui_battle_status_frozen_1_png);
INCLUDE_PAL("ui/battle/status/frozen_1.pal", ui_battle_status_frozen_1_pal);

INCLUDE_IMG("ui/battle/status/frozen_2.png", ui_battle_status_frozen_2_png);
INCLUDE_PAL("ui/battle/status/frozen_2.pal", ui_battle_status_frozen_2_pal);

INCLUDE_IMG("ui/battle/status/frozen_3.png", ui_battle_status_frozen_3_png);
INCLUDE_PAL("ui/battle/status/frozen_3.pal", ui_battle_status_frozen_3_pal);

INCLUDE_IMG("ui/battle/status/stop_0.png", ui_battle_status_stop_0_png);
INCLUDE_PAL("ui/battle/status/stop_0.pal", ui_battle_status_stop_0_pal);

INCLUDE_IMG("ui/battle/status/stop_1.png", ui_battle_status_stop_1_png);
INCLUDE_PAL("ui/battle/status/stop_1.pal", ui_battle_status_stop_1_pal);

INCLUDE_IMG("ui/battle/status/stop_2.png", ui_battle_status_stop_2_png);
INCLUDE_PAL("ui/battle/status/stop_2.pal", ui_battle_status_stop_2_pal);

INCLUDE_IMG("ui/battle/status/stop_3.png", ui_battle_status_stop_3_png);
INCLUDE_PAL("ui/battle/status/stop_3.pal", ui_battle_status_stop_3_pal);

INCLUDE_IMG("ui/battle/status/pdown_0.png", ui_battle_status_pdown_0_png);
INCLUDE_PAL("ui/battle/status/pdown_0.pal", ui_battle_status_pdown_0_pal);

INCLUDE_IMG("ui/battle/status/pdown_1.png", ui_battle_status_pdown_1_png);
INCLUDE_PAL("ui/battle/status/pdown_1.pal", ui_battle_status_pdown_1_pal);

INCLUDE_IMG("ui/battle/status/shrink_0.png", ui_battle_status_shrink_0_png);
INCLUDE_PAL("ui/battle/status/shrink_0.pal", ui_battle_status_shrink_0_pal);

INCLUDE_IMG("ui/battle/status/shrink_1.png", ui_battle_status_shrink_1_png);
INCLUDE_PAL("ui/battle/status/shrink_1.pal", ui_battle_status_shrink_1_pal);

INCLUDE_IMG("ui/battle/status/shrink_2.png", ui_battle_status_shrink_2_png);
INCLUDE_PAL("ui/battle/status/shrink_2.pal", ui_battle_status_shrink_2_pal);

INCLUDE_IMG("ui/battle/status/shrink_3.png", ui_battle_status_shrink_3_png);
INCLUDE_PAL("ui/battle/status/shrink_3.pal", ui_battle_status_shrink_3_pal);

INCLUDE_IMG("ui/battle/status/transparent_0.png", ui_battle_status_transparent_0_png);
INCLUDE_PAL("ui/battle/status/transparent_0.pal", ui_battle_status_transparent_0_pal);

INCLUDE_IMG("ui/battle/status/transparent_1.png", ui_battle_status_transparent_1_png);
INCLUDE_PAL("ui/battle/status/transparent_1.pal", ui_battle_status_transparent_1_pal);

INCLUDE_IMG("ui/battle/status/transparent_2.png", ui_battle_status_transparent_2_png);
INCLUDE_PAL("ui/battle/status/transparent_2.pal", ui_battle_status_transparent_2_pal);

INCLUDE_IMG("ui/battle/status/transparent_3.png", ui_battle_status_transparent_3_png);
INCLUDE_PAL("ui/battle/status/transparent_3.pal", ui_battle_status_transparent_3_pal);

INCLUDE_IMG("ui/battle/status/transparent_4.png", ui_battle_status_transparent_4_png);
INCLUDE_PAL("ui/battle/status/transparent_4.pal", ui_battle_status_transparent_4_pal);

INCLUDE_IMG("ui/battle/status/transparent_5.png", ui_battle_status_transparent_5_png);
INCLUDE_PAL("ui/battle/status/transparent_5.pal", ui_battle_status_transparent_5_pal);

INCLUDE_IMG("ui/battle/status/peril.png", ui_battle_status_peril_png);
INCLUDE_PAL("ui/battle/status/peril.pal", ui_battle_status_peril_pal);

INCLUDE_IMG("ui/battle/status/danger.png", ui_battle_status_danger_png);
INCLUDE_PAL("ui/battle/status/danger.pal", ui_battle_status_danger_pal);

INCLUDE_IMG("ui/battle/status/refund.png", ui_battle_status_refund_png);
INCLUDE_PAL("ui/battle/status/refund.pal", ui_battle_status_refund_pal);

INCLUDE_IMG("ui/battle/status/happy.png", ui_battle_status_happy_png);
INCLUDE_PAL("ui/battle/status/happy.pal", ui_battle_status_happy_pal);

INCLUDE_IMG("ui/battle/status/hp_drain.png", ui_battle_status_hp_drain_png);
INCLUDE_PAL("ui/battle/status/hp_drain.pal", ui_battle_status_hp_drain_pal);

#if VERSION_PAL
INCLUDE_IMG("de/ui/battle/status/peril.png", ui_battle_status_peril_de_png);
INCLUDE_PAL("de/ui/battle/status/peril.pal", ui_battle_status_peril_de_pal);

INCLUDE_IMG("de/ui/battle/status/danger.png", ui_battle_status_danger_de_png);
INCLUDE_PAL("de/ui/battle/status/danger.pal", ui_battle_status_danger_de_pal);

INCLUDE_IMG("de/ui/battle/status/refund.png", ui_battle_status_refund_de_png);
INCLUDE_PAL("de/ui/battle/status/refund.pal", ui_battle_status_refund_de_pal);

INCLUDE_IMG("de/ui/battle/status/happy.png", ui_battle_status_happy_de_png);
INCLUDE_PAL("de/ui/battle/status/happy.pal", ui_battle_status_happy_de_pal);

INCLUDE_IMG("de/ui/battle/status/hp_drain.png", ui_battle_status_hp_drain_de_png);
INCLUDE_PAL("de/ui/battle/status/hp_drain.pal", ui_battle_status_hp_drain_de_pal);

INCLUDE_IMG("fr/ui/battle/status/peril.png", ui_battle_status_peril_fr_png);
INCLUDE_PAL("fr/ui/battle/status/peril.pal", ui_battle_status_peril_fr_pal);

INCLUDE_IMG("fr/ui/battle/status/danger.png", ui_battle_status_danger_fr_png);
INCLUDE_PAL("fr/ui/battle/status/danger.pal", ui_battle_status_danger_fr_pal);

INCLUDE_IMG("fr/ui/battle/status/refund.png", ui_battle_status_refund_fr_png);
INCLUDE_PAL("fr/ui/battle/status/refund.pal", ui_battle_status_refund_fr_pal);

INCLUDE_IMG("fr/ui/battle/status/happy.png", ui_battle_status_happy_fr_png);
INCLUDE_PAL("fr/ui/battle/status/happy.pal", ui_battle_status_happy_fr_pal);

INCLUDE_IMG("fr/ui/battle/status/hp_drain.png", ui_battle_status_hp_drain_fr_png);
INCLUDE_PAL("fr/ui/battle/status/hp_drain.pal", ui_battle_status_hp_drain_fr_pal);

INCLUDE_IMG("es/ui/battle/status/peril.png", ui_battle_status_peril_es_png);
INCLUDE_PAL("es/ui/battle/status/peril.pal", ui_battle_status_peril_es_pal);

INCLUDE_IMG("es/ui/battle/status/danger.png", ui_battle_status_danger_es_png);
INCLUDE_PAL("es/ui/battle/status/danger.pal", ui_battle_status_danger_es_pal);

INCLUDE_IMG("es/ui/battle/status/refund.png", ui_battle_status_refund_es_png);
INCLUDE_PAL("es/ui/battle/status/refund.pal", ui_battle_status_refund_es_pal);

INCLUDE_IMG("es/ui/battle/status/happy.png", ui_battle_status_happy_es_png);
INCLUDE_PAL("es/ui/battle/status/happy.pal", ui_battle_status_happy_es_pal);

INCLUDE_IMG("es/ui/battle/status/hp_drain.png", ui_battle_status_hp_drain_es_png);
INCLUDE_PAL("es/ui/battle/status/hp_drain.pal", ui_battle_status_hp_drain_es_pal);
#endif

INCLUDE_IMG("ui/move_basic.png", ui_move_basic_png);
INCLUDE_PAL("ui/move_basic.pal", ui_move_basic_pal);
#define ui_move_basic_disabled_png ui_move_basic_png
INCLUDE_PAL("ui/move_basic.disabled.pal", ui_move_basic_disabled_pal);

INCLUDE_IMG("ui/move_partner_1.png", ui_move_partner_1_png);
INCLUDE_PAL("ui/move_partner_1.pal", ui_move_partner_1_pal);
#define ui_move_partner_1_disabled_png ui_move_partner_1_png
INCLUDE_PAL("ui/move_partner_1.disabled.pal", ui_move_partner_1_disabled_pal);

INCLUDE_IMG("ui/move_partner_2.png", ui_move_partner_2_png);
INCLUDE_PAL("ui/move_partner_2.pal", ui_move_partner_2_pal);
#define ui_move_partner_2_disabled_png ui_move_partner_2_png
INCLUDE_PAL("ui/move_partner_2.disabled.pal", ui_move_partner_2_disabled_pal);

INCLUDE_IMG("ui/move_partner_3.png", ui_move_partner_3_png);
INCLUDE_PAL("ui/move_partner_3.pal", ui_move_partner_3_pal);
#define ui_move_partner_3_disabled_png ui_move_partner_3_png
INCLUDE_PAL("ui/move_partner_3.disabled.pal", ui_move_partner_3_disabled_pal);

Gfx D_801041A0[] = {
    gsSPEndDisplayList(),
};

INCLUDE_IMG("ui/stat_heart.png", ui_stat_heart_png);

Gfx D_801045A8[] = {
    gsSPEndDisplayList(),
};

INCLUDE_IMG("ui/stat_flower.png", ui_stat_flower_png);

HudScript HES_ArrowLeft = HES_TEMPLATE_CI_ENUM_SIZE(ui_arrow_left, 16, 16);

HudScript HES_ArrowRight = HES_TEMPLATE_CI_ENUM_SIZE(ui_arrow_right, 16, 16);

HudScript HES_HandPointer = HES_TEMPLATE_CI_ENUM_SIZE(ui_point_right, 16, 16);

HudScript HES_AnimatedHandPointer = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_AddTexelOffsetX(-1)
        hs_SetCI(4, ui_point_right)
        hs_AddTexelOffsetX(1)
        hs_SetCI(8, ui_point_right)
    hs_Restart
    hs_End
};

HudScript HES_FilledCircle = HES_TEMPLATE_CI_ENUM_SIZE(ui_pip, 8, 8);

HudScript HES_EmptyCircle = HES_TEMPLATE_CI_ENUM_SIZE(ui_pip2, 8, 8);

SparkleScript SparkleScript_Coin = {
    sp_Break(13)
    sp_SetCI(1, ui_coin_sparkle_0, 8, 8)
    sp_SetCI(1, ui_coin_sparkle_1, 8, 8)
    sp_SetCI(1, ui_coin_sparkle_2, 8, 8)
    sp_SetCI(2, ui_coin_sparkle_none, 8, 8)
    sp_SetCI(1, ui_coin_sparkle_2, 8, 8)
    sp_SetCI(1, ui_coin_sparkle_3, 8, 8)
    sp_SetCI(1, ui_coin_sparkle_none, 8, 8)
    sp_SetCI(1, ui_coin_sparkle_4, 8, 8)
    sp_SetCI(1, ui_coin_sparkle_none, 8, 8)
    sp_SetCI(1, ui_coin_sparkle_5, 8, 8)
    sp_SetCI(127, ui_coin_sparkle_none, 8, 8)
    sp_SetCI(127, ui_coin_sparkle_none, 8, 8)
    sp_End
};

HudScript HES_StatusSPShine = {
    hs_UseIA8
    hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
    hs_Loop
        hs_SetRGBA(60, ui_status_star_point_shine_png)
    hs_Restart
    hs_End
};

HudScript HES_StatusStarPiece = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(12, ui_status_star_piece_0)
        hs_SetCI(4, ui_status_star_piece_1)
        hs_SetCI(12, ui_status_star_piece_2)
        hs_SetCI(4, ui_status_star_piece_1)
    hs_Restart
    hs_End
};

HudScript HES_AsleepLoop = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(8, ui_battle_status_sleep_0)
        hs_SetCI(4, ui_battle_status_sleep_1)
        hs_SetCI(8, ui_battle_status_sleep_2)
        hs_SetCI(4, ui_battle_status_sleep_1)
    hs_Restart
    hs_End
};

HudScript HES_AsleepBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_Loop
        hs_SetCI(8, ui_battle_status_sleep_0)
        hs_SetCI(4, ui_battle_status_sleep_1)
        hs_SetCI(8, ui_battle_status_sleep_2)
        hs_SetCI(4, ui_battle_status_sleep_1)
    hs_Restart
    hs_End
};

HudScript HES_AsleepEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_sleep_0)
    hs_End
};

HudScript HES_ElectrifiedLoop = {
    hs_SetVisible
    hs_SetCustomSize( 16, 16)
    hs_Loop
        hs_SetCI(24,ui_battle_status_static_0)
        hs_SetCI(1, ui_battle_status_static_1)
        hs_SetCI(1, ui_battle_status_static_0)
        hs_SetCI(1, ui_battle_status_static_1)
        hs_SetCI(49,ui_battle_status_static_0)
        hs_SetCI(1, ui_battle_status_static_1)
        hs_SetCI(1, ui_battle_status_static_0)
        hs_SetCI_Explicit(1, ui_battle_status_static_1, ui_battle_status_static_0)
        hs_SetCI_Explicit(1, ui_battle_status_static_0, ui_battle_status_static_1)
        hs_SetCI_Explicit(1, ui_battle_status_static_1, ui_battle_status_static_0)
        hs_SetCI_Explicit(1, ui_battle_status_static_0, ui_battle_status_static_1)
        hs_SetCI_Explicit(1, ui_battle_status_static_1, ui_battle_status_static_0)
        hs_SetCI_Explicit(1, ui_battle_status_static_0, ui_battle_status_static_1)
    hs_Restart
    hs_End
};

HudScript HES_ElectrifiedBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_Loop
        hs_SetCI(24,ui_battle_status_static_0)
        hs_SetCI(1, ui_battle_status_static_1)
        hs_SetCI(1, ui_battle_status_static_0)
        hs_SetCI(1, ui_battle_status_static_1)
        hs_SetCI(49,ui_battle_status_static_0)
        hs_SetCI(1, ui_battle_status_static_1)
        hs_SetCI(1, ui_battle_status_static_0)
        hs_SetCI_Explicit(1, ui_battle_status_static_1, ui_battle_status_static_0)
        hs_SetCI_Explicit(1, ui_battle_status_static_0, ui_battle_status_static_1)
        hs_SetCI_Explicit(1, ui_battle_status_static_1, ui_battle_status_static_0)
        hs_SetCI_Explicit(1, ui_battle_status_static_0, ui_battle_status_static_1)
        hs_SetCI_Explicit(1, ui_battle_status_static_1, ui_battle_status_static_0)
        hs_SetCI_Explicit(1, ui_battle_status_static_0, ui_battle_status_static_1)
    hs_Restart
    hs_End
};

HudScript HES_ElectrifiedEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_static_0)
    hs_End
};

HudScript HES_ParalyzedLoop = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(24,ui_battle_status_paralyze_0)
        hs_SetCI(1, ui_battle_status_paralyze_1)
        hs_SetCI(1, ui_battle_status_paralyze_0)
        hs_SetCI(1, ui_battle_status_paralyze_1)
        hs_SetCI(49,ui_battle_status_paralyze_0)
        hs_SetCI(1, ui_battle_status_paralyze_1)
        hs_SetCI(1, ui_battle_status_paralyze_0)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_1, ui_battle_status_paralyze_0)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_0, ui_battle_status_paralyze_1)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_1, ui_battle_status_paralyze_0)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_0, ui_battle_status_paralyze_1)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_1, ui_battle_status_paralyze_0)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_0, ui_battle_status_paralyze_1)
    hs_Restart
    hs_End
};

HudScript HES_ParalyzedBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_Loop
        hs_SetCI(24,ui_battle_status_paralyze_0)
        hs_SetCI(1, ui_battle_status_paralyze_1)
        hs_SetCI(1, ui_battle_status_paralyze_0)
        hs_SetCI(1, ui_battle_status_paralyze_1)
        hs_SetCI(49,ui_battle_status_paralyze_0)
        hs_SetCI(1, ui_battle_status_paralyze_1)
        hs_SetCI(1, ui_battle_status_paralyze_0)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_1, ui_battle_status_paralyze_0)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_0, ui_battle_status_paralyze_1)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_1, ui_battle_status_paralyze_0)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_0, ui_battle_status_paralyze_1)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_1, ui_battle_status_paralyze_0)
        hs_SetCI_Explicit(1, ui_battle_status_paralyze_0, ui_battle_status_paralyze_1)
    hs_Restart
    hs_End
};

HudScript HES_ParalyzedEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_paralyze_0)
    hs_End
};

HudScript HES_DizzyLoop = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(4, ui_battle_status_dizzy_0)
        hs_SetCI(4, ui_battle_status_dizzy_1)
        hs_SetCI(4, ui_battle_status_dizzy_2)
        hs_SetCI(4, ui_battle_status_dizzy_3)
    hs_Restart
    hs_End
};

HudScript HES_DizzyBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_Loop
        hs_SetCI(4, ui_battle_status_dizzy_0)
        hs_SetCI(4, ui_battle_status_dizzy_1)
        hs_SetCI(4, ui_battle_status_dizzy_2)
        hs_SetCI(4, ui_battle_status_dizzy_3)
    hs_Restart
    hs_End
};

HudScript HES_DizzyEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_dizzy_0)
    hs_End
};

HudScript HES_PoisonedLoop = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(27, ui_battle_status_poison_0)
        hs_SetCI(3, ui_battle_status_poison_1)
        hs_SetCI(3, ui_battle_status_poison_0)
        hs_SetCI(3, ui_battle_status_poison_1)
    hs_Restart
    hs_End
};

HudScript HES_PoisonedBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_Loop
        hs_SetCI(27, ui_battle_status_poison_0)
        hs_SetCI(3, ui_battle_status_poison_1)
        hs_SetCI(3, ui_battle_status_poison_0)
        hs_SetCI(3, ui_battle_status_poison_1)
    hs_Restart
    hs_End
};

HudScript HES_PoisonedEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_poison_0)
    hs_End
};

HudScript HES_FrozenLoop = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(24, ui_battle_status_frozen_0)
        hs_SetCI(3, ui_battle_status_frozen_1)
        hs_SetCI(4, ui_battle_status_frozen_2)
        hs_SetCI(3, ui_battle_status_frozen_3)
    hs_Restart
    hs_End
};

HudScript HES_FrozenBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_Loop
        hs_SetCI(24, ui_battle_status_frozen_0)
        hs_SetCI(3, ui_battle_status_frozen_1)
        hs_SetCI(4, ui_battle_status_frozen_2)
        hs_SetCI(3, ui_battle_status_frozen_3)
    hs_Restart
    hs_End
};

HudScript HES_FrozenEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_frozen_0)
    hs_End
};

HudScript HES_WeakenedLoop = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(6, ui_battle_status_pdown_0)
        hs_SetCI(6, ui_battle_status_pdown_1)
    hs_Restart
    hs_End
};

HudScript HES_WeakenedBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_Loop
        hs_SetCI(6, ui_battle_status_pdown_0)
        hs_SetCI(6, ui_battle_status_pdown_1)
    hs_Restart
    hs_End
};

HudScript HES_WeakenedEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_pdown_0)
    hs_End
};

HudScript HES_Stopped = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(5, ui_battle_status_stop_0)
        hs_SetCI(5, ui_battle_status_stop_1)
        hs_SetCI(5, ui_battle_status_stop_2)
        hs_SetCI(5, ui_battle_status_stop_3)
    hs_Restart
    hs_End
};

HudScript HES_StoppedBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_Loop
        hs_SetCI(5, ui_battle_status_stop_0)
        hs_SetCI(5, ui_battle_status_stop_1)
        hs_SetCI(5, ui_battle_status_stop_2)
        hs_SetCI(5, ui_battle_status_stop_3)
    hs_Restart
    hs_End
};

HudScript HES_StoppedEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_stop_0)
    hs_End
};

HudScript HES_ShrunkLoop = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(5, ui_battle_status_shrink_0)
        hs_SetCI(6, ui_battle_status_shrink_1)
        hs_SetCI(6, ui_battle_status_shrink_2)
        hs_SetCI(5, ui_battle_status_shrink_3)
    hs_Restart
    hs_End
};

HudScript HES_ShrunkBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_Loop
        hs_SetCI(5, ui_battle_status_shrink_0)
        hs_SetCI(6, ui_battle_status_shrink_1)
        hs_SetCI(6, ui_battle_status_shrink_2)
        hs_SetCI(5, ui_battle_status_shrink_3)
    hs_Restart
    hs_End
};

HudScript HES_ShrunkEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_shrink_0)
    hs_End
};

HudScript HES_TransparentLoop = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_Loop
        hs_SetCI(3, ui_battle_status_transparent_0)
        hs_SetCI(3, ui_battle_status_transparent_1)
        hs_SetCI(3, ui_battle_status_transparent_2)
        hs_SetCI(3, ui_battle_status_transparent_3)
        hs_SetCI(3, ui_battle_status_transparent_4)
        hs_SetCI(3, ui_battle_status_transparent_5)
    hs_Restart
    hs_End
};

HudScript HES_TransparentBegin = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_Loop
        hs_SetCI(3, ui_battle_status_transparent_0)
        hs_SetCI(3, ui_battle_status_transparent_1)
        hs_SetCI(3, ui_battle_status_transparent_2)
        hs_SetCI(3, ui_battle_status_transparent_3)
        hs_SetCI(3, ui_battle_status_transparent_4)
        hs_SetCI(3, ui_battle_status_transparent_5)
    hs_Restart
    hs_End
};

HudScript HES_TransparentEnd = {
    hs_SetVisible
    hs_SetCustomSize(16, 16)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(240)
    hs_SetTexelOffset(1, -1)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(220)
    hs_SetTexelOffset(2, -2)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(200)
    hs_SetTexelOffset(3, -3)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(170)
    hs_SetTexelOffset(4, -4)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(120)
    hs_SetTexelOffset(5, -5)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(80)
    hs_SetTexelOffset(6, -6)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(50)
    hs_SetTexelOffset(8, -8)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_SetAlpha(30)
    hs_SetTexelOffset(10, -10)
    hs_SetCI(1, ui_battle_status_transparent_0)
    hs_End
};

HudScript HES_BoostJumpLoop = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_status_charge_jump, 24, 24);

HudScript HES_BoostJumpBegin = {
    hs_SetVisible
    hs_SetCustomSize(24, 24)
    hs_SetAlpha(30)
    hs_SetTexelOffset(0, -10)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(50)
    hs_SetTexelOffset(0, -8)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(80)
    hs_SetTexelOffset(0, -6)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(120)
    hs_SetTexelOffset(0, -5)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(170)
    hs_SetTexelOffset(0, -4)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(200)
    hs_SetTexelOffset(0, -3)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(220)
    hs_SetTexelOffset(0, -2)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(240)
    hs_SetTexelOffset(0, -1)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_Loop
        hs_SetCI(60, ui_battle_status_charge_jump)
    hs_Restart
    hs_End
};

HudScript HES_BoostJumpEnd = {
    hs_SetVisible
    hs_SetCustomSize(24, 24)
    hs_SetAlpha(240)
    hs_SetTexelOffset(0, -1)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(220)
    hs_SetTexelOffset(-3, -3)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(200)
    hs_SetTexelOffset(-6, -5)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(170)
    hs_SetTexelOffset(-8, -6)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(120)
    hs_SetTexelOffset(-10, -5)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(80)
    hs_SetTexelOffset(-12, -3)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(50)
    hs_SetTexelOffset(-13, 0)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetAlpha(30)
    hs_SetTexelOffset(-14, 4)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetTexelOffset(-15, 9)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_SetTexelOffset(-15, 15)
    hs_SetCI(1, ui_battle_status_charge_jump)
    hs_End
};

HudScript HES_BoostHammerLoop = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_status_charge_hammer, 24, 24);

HudScript HES_BoostHammerBegin = {
    hs_SetVisible
    hs_SetCustomSize(24, 24)
    hs_SetAlpha(30)
    hs_SetTexelOffset(0, -10)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(50)
    hs_SetTexelOffset(0, -8)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(80)
    hs_SetTexelOffset(0, -6)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(120)
    hs_SetTexelOffset(0, -5)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(170)
    hs_SetTexelOffset(0, -4)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(200)
    hs_SetTexelOffset(0, -3)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(220)
    hs_SetTexelOffset(0, -2)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(240)
    hs_SetTexelOffset(0, -1)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(255)
    hs_SetTexelOffset(0, 0)
    hs_Loop
        hs_SetCI(60, ui_battle_status_charge_hammer)
    hs_Restart
    hs_End
};

HudScript HES_BoostHammerEnd = {
    hs_SetVisible
    hs_SetCustomSize(24, 24)
    hs_SetAlpha(240)
    hs_SetTexelOffset(0, -1)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(220)
    hs_SetTexelOffset(-3, -3)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(200)
    hs_SetTexelOffset(-6, -5)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(170)
    hs_SetTexelOffset(-8, -6)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(120)
    hs_SetTexelOffset(-10, -5)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(80)
    hs_SetTexelOffset(-12, -3)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(50)
    hs_SetTexelOffset(-13, 0)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetAlpha(30)
    hs_SetTexelOffset(-14, 4)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetTexelOffset(-15, 9)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_SetTexelOffset(-15, 15)
    hs_SetCI(1, ui_battle_status_charge_hammer)
    hs_End
};

HudScript HES_BoostPartner = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_status_charge_goombario, 24, 24);

HudScript HES_Surprise = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_battle_status_exclamation, 24, 24);

HudScript HES_FPCost = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost, 16, 8);

HudScript HES_FPCostReduced = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_reduced, 16, 8);

HudScript HES_FPCostReducedTwice = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_reduced_twice, 16, 8);

HudScript HES_NotEnoughFP = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_notenough, 16, 8);

HudScript HES_POWCost = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost, 16, 8);

HudScript HES_POWCostReduced = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_reduced, 16, 8);

HudScript HES_POWCostReducedTwice = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_reduced_twice, 16, 8);

HudScript HES_NotEnoughPOW = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_notenough, 16, 8);

#if VERSION_PAL
HudScript HES_FPCost_de = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_de, 16, 8);
HudScript HES_FPCostReduced_de = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_de_reduced, 16, 8);
HudScript HES_FPCostReducedTwice_de = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_de_reduced_twice, 16, 8);
HudScript HES_NotEnoughFP_de = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_de_notenough, 16, 8);
HudScript HES_POWCost_de = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_de, 16, 8);
HudScript HES_POWCostReduced_de = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_de_reduced, 16, 8);
HudScript HES_POWCostReducedTwice_de = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_de_reduced_twice, 16, 8);
HudScript HES_NotEnoughPOW_de = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_de_notenough, 16, 8);

HudScript HES_FPCost_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_fr, 16, 8);
HudScript HES_FPCostReduced_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_fr_reduced, 16, 8);
HudScript HES_FPCostReducedTwice_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_fr_reduced_twice, 16, 8);
HudScript HES_NotEnoughFP_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_fr_notenough, 16, 8);
HudScript HES_POWCost_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_fr, 16, 8);
HudScript HES_POWCostReduced_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_fr_reduced, 16, 8);
HudScript HES_POWCostReducedTwice_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_fr_reduced_twice, 16, 8);
HudScript HES_NotEnoughPOW_fr = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_fr_notenough, 16, 8);

HudScript HES_FPCost_es = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_es, 16, 8);
HudScript HES_FPCostReduced_es = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_es_reduced, 16, 8);
HudScript HES_FPCostReducedTwice_es = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_es_reduced_twice, 16, 8);
HudScript HES_NotEnoughFP_es = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_fp_cost_es_notenough, 16, 8);
HudScript HES_POWCost_es = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_es, 16, 8);
HudScript HES_POWCostReduced_es = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_es_reduced, 16, 8);
HudScript HES_POWCostReducedTwice_es = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_es_reduced_twice, 16, 8);
HudScript HES_NotEnoughPOW_es = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_pow_cost_es_notenough, 16, 8);
#endif

HudScript HES_GreenArrowDown = {
    hs_SetVisible
    hs_SetCustomSize(16, 8)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(9, ui_green_arrow_down)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(6, ui_green_arrow_down)
    hs_Restart
    hs_End
};

HudScript HES_GreenArrowUp = {
    hs_SetVisible
    hs_SetCustomSize(16, 8)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(9, ui_green_arrow_up)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(6, ui_green_arrow_up)
    hs_Restart
    hs_End
};

HudScript HES_UnusedPinkFrame = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_kaime, 56, 24);

HudScript HES_UnusedDigit1 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_unused_1, 16, 16);

HudScript HES_UnusedDigit2 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_unused_2, 16, 16);

HudScript HES_UnusedDigit3 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_unused_3, 16, 16);

HudScript HES_RedBar1 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_red_bar1, 112, 8);

HudScript HES_EmptyBar = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_empty_bar, 112, 8);

HudScript HES_RedBar2 = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_red_bar2, 104, 8);

HudScript HES_MarioHead = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_mario_head, 16, 16);

HudScript HES_Eldstar = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_eldstar, 32, 32);

HudScript HES_EldstarDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_eldstar_disabled, 32, 32);

HudScript HES_Mamar = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_mamar, 32, 32);

HudScript HES_MamarDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_mamar_disabled, 32, 32);

HudScript HES_Skolar = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_skolar, 32, 32);

HudScript HES_SkolarDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_skolar_disabled, 32, 32);

HudScript HES_Muskular = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_muskular, 32, 32);

HudScript HES_MuskularDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_muskular_disabled, 32, 32);

HudScript HES_Misstar = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_misstar, 32, 32);

HudScript HES_MisstarDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_misstar_disabled, 32, 32);

HudScript HES_Klevar = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_klevar, 32, 32);

HudScript HES_KlevarDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_klevar_disabled, 32, 32);

HudScript HES_Kalmar = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_kalmar, 32, 32);

HudScript HES_KalmarDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_kalmar_disabled, 32, 32);

HudScript HES_StarBeam = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_star_beam, 32, 32);

HudScript HES_StarBeamDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_star_beam_disabled, 32, 32);

HudScript HES_PeachBeam = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_peach_beam, 32, 32);

HudScript HES_PeachBeamDisabled = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_peach_beam_disabled, 32, 32);

HudScript HES_Partner0 = HES_TEMPLATE_CI_ENUM_SIZE(ui_partner0, 32, 32);

HudScript HES_Partner0Disabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_partner0_disabled, 32, 32);

HudScript HES_Goombario = HES_TEMPLATE_CI_ENUM_SIZE(ui_goombario, 32, 32);

HudScript HES_GoombarioDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_goombario_disabled, 32, 32);

HudScript HES_Kooper = HES_TEMPLATE_CI_ENUM_SIZE(ui_kooper, 32, 32);

HudScript HES_KooperDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_kooper_disabled, 32, 32);

HudScript HES_Bombette = HES_TEMPLATE_CI_ENUM_SIZE(ui_bombette, 32, 32);

HudScript HES_BombetteDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_bombette_disabled, 32, 32);

HudScript HES_Parakarry = HES_TEMPLATE_CI_ENUM_SIZE(ui_parakarry, 32, 32);

HudScript HES_ParakarryDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_parakarry_disabled, 32, 32);

HudScript HES_Bow = HES_TEMPLATE_CI_ENUM_SIZE(ui_bow, 32, 32);

HudScript HES_BowDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_bow_disabled, 32, 32);

HudScript HES_Watt = HES_TEMPLATE_CI_ENUM_SIZE(ui_watt, 32, 32);

HudScript HES_WattDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_watt_disabled, 32, 32);

HudScript HES_Sushie = HES_TEMPLATE_CI_ENUM_SIZE(ui_sushie, 32, 32);

HudScript HES_SushieDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_sushie_disabled, 32, 32);

HudScript HES_Lakilester = HES_TEMPLATE_CI_ENUM_SIZE(ui_lakilester, 32, 32);

HudScript HES_LakilesterDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_lakilester_disabled, 32, 32);

HudScript HES_Partner9 = HES_TEMPLATE_CI_ENUM_SIZE(ui_partner9, 32, 32);

HudScript HES_Partner9Disabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_partner9_disabled, 32, 32);

HudScript HES_PartnerA = HES_TEMPLATE_CI_ENUM_SIZE(ui_partner10, 32, 32);

HudScript HES_PartnerADisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_partner10_disabled, 32, 32);

HudScript HES_PartnerB = HES_TEMPLATE_CI_ENUM_SIZE(ui_partner11, 32, 32);

HudScript HES_PartnerBDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_partner11_disabled, 32, 32);

HudScript HES_StatusTimes = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_times, 8, 8);

HudScript HES_StatusSlash = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_slash, 8, 16);

HudScript HES_StatusDigit0 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_0, 16, 16);

HudScript HES_StatusDigit1 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_1, 16, 16);

HudScript HES_StatusDigit2 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_2, 16, 16);

HudScript HES_StatusDigit3 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_3, 16, 16);

HudScript HES_StatusDigit4 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_4, 16, 16);

HudScript HES_StatusDigit5 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_5, 16, 16);

HudScript HES_StatusDigit6 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_6, 16, 16);

HudScript HES_StatusDigit7 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_7, 16, 16);

HudScript HES_StatusDigit8 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_8, 16, 16);

HudScript HES_StatusDigit9 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_9, 16, 16);

HudScript HES_StatusHP = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_hp, 16, 16);

HudScript HES_StatusFP = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_fp, 16, 16);

#if VERSION_PAL
HudScript HES_StatusHP_de = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_hp_de, 16, 16);
HudScript HES_StatusFP_de = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_fp_de, 16, 16);

HudScript HES_StatusHP_fr = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_hp_fr, 16, 16);
HudScript HES_StatusFP_fr = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_fp_fr, 16, 16);

HudScript HES_StatusHP_es = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_hp_es, 16, 16);
HudScript HES_StatusFP_es = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_text_fp_es, 16, 16);
#endif

HudScript HES_StatusSPIncrement1 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_unit_1, 8, 8);

HudScript HES_StatusSPIncrement2 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_unit_2, 8, 8);

HudScript HES_StatusSPIncrement3 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_unit_3, 8, 8);

HudScript HES_StatusSPIncrement4 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_unit_4, 8, 8);

HudScript HES_StatusSPIncrement5 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_unit_5, 8, 8);

HudScript HES_StatusSPIncrement6 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_unit_6, 8, 8);

HudScript HES_StatusSPIncrement7 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_unit_7, 8, 8);

HudScript HES_StatusSPEmptyIncrement = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_unit_empty, 8, 8);

HudScript HES_StatusStar1 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_star_1, 8, 8);

HudScript HES_StatusStar2 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_star_2, 8, 8);

HudScript HES_StatusStar3 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_star_3, 8, 8);

HudScript HES_StatusStar4 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_star_4, 8, 8);

HudScript HES_StatusStar5 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_star_5, 8, 8);

HudScript HES_StatusStar6 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_star_6, 8, 8);

HudScript HES_StatusStar7 = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_star_7, 8, 8);

HudScript HES_StatusStarEmpty = HES_TEMPLATE_CI_ENUM_SIZE(ui_status_pow_star_empty, 8, 8);

HudScript HES_StatusHeart = {
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetRGBA(60, ui_stat_heart_png)
    hs_Restart
    hs_End
};

HudScript HES_StatusFlower = {
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetRGBA(60, ui_stat_flower_png)
    hs_Restart
    hs_End
};

HudScript HES_StatusCoin = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_op_15(0)
        hs_SetCI(3, ui_status_coin_0)
        hs_SetCI(3, ui_status_coin_1)
        hs_SetCI(3, ui_status_coin_4)
        hs_SetCI(3, ui_status_coin_5)
        hs_SetCI(3, ui_status_coin_6)
        hs_SetCI(3, ui_status_coin_7)
        hs_SetCI(3, ui_status_coin_8)
        hs_SetCI(3, ui_status_coin_9)
        hs_RandomRestart(100, 70)
        hs_op_15(1)
        hs_SetCI(3, ui_status_coin_0)
        hs_SetCI(2, ui_status_coin_1)
        hs_SetCI(1, ui_status_coin_2)
        hs_SetCI(1, ui_status_coin_3)
        hs_SetCI(2, ui_status_coin_4)
        hs_SetCI(3, ui_status_coin_5)
        hs_SetCI(3, ui_status_coin_6)
        hs_SetCI(3, ui_status_coin_7)
        hs_SetCI(3, ui_status_coin_8)
        hs_SetCI(3, ui_status_coin_9)
    hs_Restart
    hs_End
};

HudScript HES_StatusStarPoint = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_16x16)
    hs_Loop
        hs_SetCI(2, ui_status_star_point_0)
        hs_SetCI(2, ui_status_star_point_1)
        hs_SetCI(2, ui_status_star_point_2)
        hs_SetCI(2, ui_status_star_point_3)
        hs_SetCI(2, ui_status_star_point_4)
        hs_SetCI(2, ui_status_star_point_5)
        hs_SetCI(2, ui_status_star_point_6)
        hs_SetCI(2, ui_status_star_point_7)
    hs_Restart
    hs_End
};

HudScript HES_MenuBoots1 = HES_TEMPLATE_CI_ENUM_SIZE(ui_boots, 32, 32);

HudScript HES_MenuBoots1Disabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_boots_disabled, 32, 32);

HudScript HES_MenuBoots2 = HES_TEMPLATE_CI_ENUM_SIZE(ui_super_boots, 32, 32);

HudScript HES_MenuBoots2Disabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_super_boots_disabled, 32, 32);

HudScript HES_MenuBoots3 = HES_TEMPLATE_CI_ENUM_SIZE(ui_ultra_boots, 32, 32);

HudScript HES_MenuBoots3Disabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_ultra_boots_disabled, 32, 32);

HudScript HES_MenuHammer1 = HES_TEMPLATE_CI_ENUM_SIZE(ui_hammer, 32, 32);

HudScript HES_MenuHammer1Disabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_hammer_disabled, 32, 32);

HudScript HES_MenuHammer2 = HES_TEMPLATE_CI_ENUM_SIZE(ui_super_hammer, 32, 32);

HudScript HES_MenuHammer2Disabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_super_hammer_disabled, 32, 32);

HudScript HES_MenuHammer3 = HES_TEMPLATE_CI_ENUM_SIZE(ui_ultra_hammer, 32, 32);

HudScript HES_MenuHammer3Disabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_ultra_hammer_disabled, 32, 32);

HudScript HES_MenuItem = HES_TEMPLATE_CI_ENUM_SIZE(ui_item, 32, 32);

HudScript HES_MenuItemDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_item_disabled, 32, 32);

HudScript HES_MenuStarPower = HES_TEMPLATE_CI_ENUM_SIZE(ui_star_spirit, 32, 32);

HudScript HES_MenuStarPowerDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_star_spirit_disabled, 32, 32);

HudScript HES_Peril = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x16)
    hs_Loop
        hs_PlaySound(SOUND_PERIL)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(15, ui_battle_status_peril)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(10, ui_battle_status_peril)
    hs_Restart
    hs_End
};

HudScript HES_Danger = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x16)
    hs_Loop
        hs_PlaySound(SOUND_DANGER)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(15, ui_battle_status_danger)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(10, ui_battle_status_danger)
    hs_Restart
    hs_End
};

HudScript HES_Refund = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x24)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(8, ui_battle_status_refund)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(4, ui_battle_status_refund)
    hs_Restart
    hs_End
};

HudScript HES_Happy = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_status_happy, 40, 16);

HudScript HES_HPDrain = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_status_hp_drain, 40, 16);

#if VERSION_PAL
// German
HudScript HES_Peril_de = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x16)
    hs_Loop
        hs_PlaySound(SOUND_PERIL)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(15, ui_battle_status_peril_de)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(10, ui_battle_status_peril_de)
    hs_Restart
    hs_End
};

HudScript HES_Danger_de = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x16)
    hs_Loop
        hs_PlaySound(SOUND_DANGER)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(15, ui_battle_status_danger_de)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(10, ui_battle_status_danger_de)
    hs_Restart
    hs_End
};

HudScript HES_Refund_de = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x24)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(8, ui_battle_status_refund_de)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(4, ui_battle_status_refund_de)
    hs_Restart
    hs_End
};

HudScript HES_Happy_de = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_status_happy_de, 40, 16);

HudScript HES_HPDrain_de = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_status_hp_drain_de, 40, 16);

// French
HudScript HES_Peril_fr = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x16)
    hs_Loop
        hs_PlaySound(SOUND_PERIL)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(15, ui_battle_status_peril_fr)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(10, ui_battle_status_peril_fr)
    hs_Restart
    hs_End
};

HudScript HES_Danger_fr = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x16)
    hs_Loop
        hs_PlaySound(SOUND_DANGER)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(15, ui_battle_status_danger_fr)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(10, ui_battle_status_danger_fr)
    hs_Restart
    hs_End
};

HudScript HES_Refund_fr = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x24)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(8, ui_battle_status_refund_fr)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(4, ui_battle_status_refund_fr)
    hs_Restart
    hs_End
};

HudScript HES_Happy_fr = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_status_happy_fr, 40, 16);

HudScript HES_HPDrain_fr = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_status_hp_drain_fr, 40, 16);

// Spanish
HudScript HES_Peril_es = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x16)
    hs_Loop
        hs_PlaySound(SOUND_PERIL)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(15, ui_battle_status_peril_es)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(10, ui_battle_status_peril_es)
    hs_Restart
    hs_End
};

HudScript HES_Danger_es = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x16)
    hs_Loop
        hs_PlaySound(SOUND_DANGER)
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(15, ui_battle_status_danger_es)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(10, ui_battle_status_danger_es)
    hs_Restart
    hs_End
};

HudScript HES_Refund_es = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_40x24)
    hs_Loop
        hs_ClearFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(8, ui_battle_status_refund_es)
        hs_SetFlags(HUD_ELEMENT_FLAG_200000)
        hs_SetCI(4, ui_battle_status_refund_es)
    hs_Restart
    hs_End
};

HudScript HES_Happy_es = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_status_happy_es, 40, 16);

HudScript HES_HPDrain_es = HES_TEMPLATE_CI_ENUM_SIZE(ui_battle_status_hp_drain_es, 40, 16);
#endif

HudScript HES_BlueMeter = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_unk_bar, 72, 16);

HudScript HES_AButton = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_input_a_button_unpressed, 48, 40);

HudScript HES_AButtonDown = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_input_a_button_pressed, 48, 40);

HudScript HES_MashAButton = {
    hs_SetVisible
    hs_SetCustomSize(48, 40)
    hs_Loop
        hs_SetCI(2, ui_input_a_button_unpressed)
        hs_SetCI(2, ui_input_a_button_pressed)
    hs_Restart
    hs_End
};

HudScript HES_PressAButton = {
    hs_SetVisible
    hs_SetCustomSize(48, 40)
    hs_Loop
        hs_SetCI(10, ui_input_a_button_unpressed)
        hs_SetCI(10, ui_input_a_button_pressed)
    hs_Restart
    hs_End
};

HudScript HES_SlowlyPressAButton = {
    hs_SetVisible
    hs_SetCustomSize(48, 40)
    hs_Loop
        hs_SetCI(30, ui_input_a_button_unpressed)
        hs_SetCI(30, ui_input_a_button_pressed)
    hs_Restart
    hs_End
};

HudScript HES_SlowlyMashAButton = {
    hs_SetVisible
    hs_SetCustomSize(48, 40)
    hs_Loop
        hs_SetCI(4, ui_input_a_button_unpressed)
        hs_SetCI(4, ui_input_a_button_pressed)
    hs_Restart
    hs_End
};

HudScript HES_StartButton = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_input_start_button, 48, 40);

HudScript HES_StartButtonDown = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_input_start_button2, 48, 40);

HudScript HES_MashStartButton = {
    hs_SetVisible
    hs_SetCustomSize(48, 40)
    hs_Loop
        hs_SetCI(2, ui_input_start_button)
        hs_SetCI(2, ui_input_start_button2)
    hs_Restart
    hs_End
};

HudScript HES_PressStartButton = {
    hs_SetVisible
    hs_SetCustomSize(48, 40)
    hs_Loop
        hs_SetCI(10, ui_input_start_button)
        hs_SetCI(10, ui_input_start_button2)
    hs_Restart
    hs_End
};

HudScript HES_StartButtonText = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_input_start_text, 24, 8);

HudScript HES_RotateStickCW = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(2, ui_input_analog_stick_up)
        hs_SetCustomSize(40, 32)
        hs_SetTexelOffset(5, 0)
        hs_SetCI(2, ui_input_analog_stick_right)
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(2, ui_input_analog_stick_down)
        hs_SetCustomSize(40, 32)
        hs_SetTexelOffset(-4, 0)
        hs_SetCI(2, ui_input_analog_stick_left)
    hs_Restart
    hs_End
};

HudScript HES_StickNeutral = HES_TEMPLATE_CI_CUSTOM_SIZE(ui_input_analog_stick, 32, 32);

HudScript HES_StickHoldLeft = {
    hs_SetVisible
    hs_SetCustomSize(40, 32)
    hs_SetTexelOffset(-4, 0)
    hs_Loop
        hs_SetCI(60, ui_input_analog_stick_left)
    hs_Restart
    hs_End
};

HudScript HES_StickBackAndForth = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(40, 32)
        hs_SetTexelOffset(-4, 0)
        hs_SetCI(2, ui_input_analog_stick_left)
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(1, ui_input_analog_stick3)
        hs_SetCustomSize(40, 32)
        hs_SetTexelOffset(5, 0)
        hs_SetCI(2, ui_input_analog_stick_right)
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(1, ui_input_analog_stick2)
    hs_Restart
    hs_End
};

HudScript HES_StickMashLeft = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(40, 32)
        hs_SetTexelOffset(-4, 0)
        hs_SetCI(6, ui_input_analog_stick_left)
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(1, ui_input_analog_stick)
    hs_Restart
    hs_End
};

HudScript HES_StickTapLeft = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(40, 32)
        hs_SetTexelOffset(-4, 0)
        hs_SetCI(22, ui_input_analog_stick_left)
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(8, ui_input_analog_stick)
    hs_Restart
    hs_End
};

HudScript HES_StickTapNeutral = {
    hs_SetVisible
    hs_SetCustomSize(32, 32)
    hs_SetTexelOffset(0, 0)
    hs_SetCI(1, ui_input_analog_stick3)
    hs_SetCustomSize(32, 32)
    hs_SetCI(1, ui_input_analog_stick2)
    hs_SetCustomSize(32, 32)
    hs_SetCI(1, ui_input_analog_stick3)
    hs_SetCustomSize(32, 32)
    hs_SetCI(20, ui_input_analog_stick2)
    hs_Loop
        hs_SetCI(60, ui_input_analog_stick2)
    hs_Restart
    hs_End
};

HudScript HES_StickHoldDown = {
    hs_SetVisible
    hs_SetCustomSize(32, 32)
    hs_SetTexelOffset(0, 0)
    hs_Loop
        hs_SetCI(60, ui_input_analog_stick_down)
    hs_Restart
    hs_End
};

HudScript HES_StickMashDown = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(2, ui_input_analog_stick)
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(1, ui_input_analog_stick_down)
    hs_Restart
    hs_End
};

HudScript HES_StickTapDown = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(12, ui_input_analog_stick)
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(10, ui_input_analog_stick_down)
    hs_Restart
    hs_End
};

HudScript HES_StickSlowlyTapDown = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(6, ui_input_analog_stick)
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(1, ui_input_analog_stick_down)
    hs_Restart
    hs_End
};

HudScript HES_StickTapRight = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(32, 32)
        hs_SetTexelOffset(0, 0)
        hs_SetCI(6, ui_input_analog_stick)
        hs_SetCustomSize(40, 32)
        hs_SetTexelOffset(5, 0)
        hs_SetCI(2, ui_input_analog_stick_right)
    hs_Restart
    hs_End
};

HudScript HES_RunAwayOK = {
    hs_SetVisible
    hs_Loop
        hs_SetCustomSize(24, 16)
        hs_SetCI(60, ui_ok)
    hs_Restart
    hs_End
};

HudScript HES_MenuTimes = HES_TEMPLATE_CI_ENUM_SIZE(ui_menu_times, 8, 8);

HudScript HES_PartnerRank1A = HES_TEMPLATE_CI_ENUM_SIZE(ui_bluepip, 16, 16);

HudScript HES_PartnerRank1B = HES_TEMPLATE_CI_ENUM_SIZE(ui_bluepip, 16, 16);

HudScript HES_PartnerRank2A = HES_TEMPLATE_CI_ENUM_SIZE(ui_bluepip2, 16, 16);

HudScript HES_PartnerRank2B = HES_TEMPLATE_CI_ENUM_SIZE(ui_bluepip2, 16, 16);

HudScript HES_MoveDiamond = HES_TEMPLATE_CI_ENUM_SIZE(ui_move_basic, 32, 32);

HudScript HES_MoveBlueOrb = HES_TEMPLATE_CI_ENUM_SIZE(ui_move_partner_1, 32, 32);

HudScript HES_MoveGreenOrb = HES_TEMPLATE_CI_ENUM_SIZE(ui_move_partner_2, 32, 32);

HudScript HES_MoveRedOrb = HES_TEMPLATE_CI_ENUM_SIZE(ui_move_partner_3, 32, 32);

HudScript HES_MoveDiamond_disabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_move_basic_disabled, 32, 32);

HudScript HES_MoveBlueOrbDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_move_partner_1_disabled, 32, 32);

HudScript HES_MoveGreenOrbDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_move_partner_2_disabled, 32, 32);

HudScript HES_MoveRedOrbDisabled = HES_TEMPLATE_CI_ENUM_SIZE(ui_move_partner_3_disabled, 32, 32);
