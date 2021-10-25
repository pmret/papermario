#include "ultra64.h"

#ifndef _DEAD_H_
#define _DEAD_H_

// There can be multiple invalid references to a symbol from the dead code,
// so some symbols here have a "2" suffix.

#define gCameras dead_gCameras
#define evt_get_variable dead_evt_get_variable
#define evt_set_variable dead_evt_set_variable
#define evt_get_float_variable dead_evt_get_float_variable
#define cos_rad dead_cos_rad
#define evt_set_float_variable dead_evt_set_float_variable
#define playFX_11 dead_playFX_11
#define gPlayerStatusPtr dead_gPlayerStatusPtr
#define set_main_pan_u dead_set_main_pan_u
#define set_main_pan_v dead_set_main_pan_v
#define set_aux_pan_u dead_set_aux_pan_u
#define set_aux_pan_v dead_set_aux_pan_v
#define get_npc_unsafe dead_get_npc_unsafe
#define atan2 dead_atan2
#define clamp_angle dead_clamp_angle
#define rand_int dead_rand_int
#define gItemTable dead_gItemTable
#define set_screen_overlay_params_back dead_set_screen_overlay_params_back
#define get_npc_by_index dead_get_npc_by_index
#define dist2D dead_dist2D
#define sin_deg dead_sin_deg
#define cos_deg dead_cos_deg
#define gPlayerStatus dead_gPlayerStatus
#define gPlayerActionState dead_gPlayerActionState
#define is_point_within_region dead_is_point_within_region
#define npc_raycast_down_sides dead_npc_raycast_down_sides
#define func_800490B4 func_8004D1A4
#define fx_emote dead_fx_emote
#define ai_enemy_play_sound dead_ai_enemy_play_sound
#define npc_move_heading dead_npc_move_heading
#define get_clamped_angle_diff dead_get_clamped_angle_diff
#define get_enemy dead_get_enemy
#define npc_test_move_simple_with_slipping dead_npc_test_move_simple_with_slipping
#define get_screen_coords dead_get_screen_coords
#define func_800495A0 func_800495A0
#define func_8004DAD8 func_800496B8
#define func_8004D9C0 func_800496B8
#define func_8004E024 func_80049C04
#define func_8004A73C func_8004EB8C
#define gCurrentCameraID dead_gCurrentCameraID
#define add_vec2D_polar dead_add_vec2D_polar
#define gCurrentCamID dead_gCurrentCamID
#define gPartnerActionStatus dead_gPartnerActionStatus
#define get_npc_safe dead_get_npc_safe
#define sfx_adjust_env_sound_pos dead_sfx_adjust_env_sound_pos
#define playFX_83 dead_playFX_83
#define heap_malloc dead_heap_malloc
#define update_lerp dead_update_lerp
#define create_shadow_type dead_create_shadow_type
#define playFX_7B dead_playFX_7B
#define dist3D dead_dist3D
#define subtract_hp dead_subtract_hp
#define get_entity_by_index dead_get_entity_by_index
#define playFX_52 dead_playFX_52
#define playFX_33 dead_playFX_33
#define set_screen_overlay_color dead_set_screen_overlay_color
#define set_screen_overlay_params_front dead_set_screen_overlay_params_front
#define playFX_82 dead_playFX_82
#define set_message_images dead_set_message_images
#define general_heap_free dead_general_heap_free
#define decode_yay0 dead_decode_yay0
#define load_asset_by_name dead_load_asset_by_name
#define gCollisionStatus dead_gCollisionStatus
#define switch_to_partner dead_switch_to_partner
#define set_npc_yaw dead_set_npc_yaw
#define disable_npc_shadow dead_disable_npc_shadow
#define func_800EB2A4 func_800F2E98
#define partner_clear_player_tracking dead_partner_clear_player_tracking
#define sfx_play_sound_with_params dead_sfx_play_sound_with_params
#define sfx_get_spatialized_sound_params dead_sfx_get_spatialized_sound_params
#define npc_test_move_simple_without_slipping dead_npc_test_move_simple_without_slipping
#define func_8003D660 func_80041080
#define get_item_entity dead_get_item_entity
#define gOverrideFlags dead_gOverrideFlags
#define set_message_msg dead_set_message_msg
#define gPlayerData dead_gPlayerData
#define D_8008EF20 D_80094900
#define increment_status_menu_disabled dead_increment_status_menu_disabled
#define decrement_status_menu_disabled dead_decrement_status_menu_disabled
#define sync_status_menu dead_sync_status_menu
#define set_max_SP dead_set_max_SP
#define get_current_map_header dead_get_current_map_header
#define gGameStatusPtr dead_gGameStatusPtr
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> link the names of dead maps to their alive counterparts
#define guTranslateF dead_guTranslateF
#define get_model_from_list_index dead_get_model_from_list_index
#define get_model_list_index_from_tree_index dead_get_model_list_index_from_tree_index
#define guMtxCatF osSiRawReadIo
#define guMtxIdentF osGetCause
<<<<<<< HEAD
=======

>>>>>>> add information about dead maps
=======
>>>>>>> link the names of dead maps to their alive counterparts
//#define sqrtf dead_sqrtf // <- This somehow breaks things

#endif
