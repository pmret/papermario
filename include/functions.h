#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common.h"
#include "map.h"
#include "enums.h"
#include "stdlib/stdarg.h"
#include "libc/xstdio.h"

f32 fabsf(f32 f);
f64 fabs(f64 f);
f32 cosine(s16 arg0);

void nuBoot(void);
void boot_idle(void* data);
void boot_main(void* data);

void is_debug_init(void);
void is_debug_panic(const char* message, char* file, s32 line);

f32 signF(f32 val);

s32 func_8002ACDC(void);
void load_obfuscation_shims(void);

void* heap_malloc(s32 size);
void* _heap_malloc(HeapNode* head, u32 size);
void* _heap_malloc_tail(HeapNode* head, u32 size);
u32 _heap_free(HeapNode* heapNodeList, void* addrToFree);
void* _heap_realloc(HeapNode* heapNodeList, void* addr, u32 newSize);
HeapNode* _heap_create(HeapNode* addr, u32 size);
u32 dma_copy(Addr romStart, Addr romEnd, void* vramDest);
f32 rand_float(void);
void copy_matrix(Matrix4f src, Matrix4f dest);

s8 set_global_byte(s32 index, s32 value);
s32 get_global_byte(s32 index);
s32 set_global_flag(s32 index);
s32 clear_global_flag(s32 index);
s32 get_global_flag(s32 index);
s8 set_area_byte(s32 index, s32 value);
s32 get_area_byte(s32 index);
s32 set_area_flag(s32 index);
s32 clear_area_flag(s32 index);
s32 get_area_flag(s32 index);

Shadow* get_shadow_by_index(s32 index);
s32 get_time_freeze_mode(void);
void render_player_model(void);
s16 get_game_mode(void);
s32 is_picking_up_item(void);

f32 integrate_gravity(void);
void gravity_use_fall_parms(void);
f32 get_clamped_angle_diff(f32, f32);
b32 startup_fade_screen_in(s16 subtractAlpha);
b32 startup_fade_screen_out(s16 addAlpha);
void startup_fade_screen_update(void);

u32 get_entity_type(s32 arg0);
Entity* get_entity_by_index(s32 index);
s32 create_entity(EntityBlueprint* bp, ...);
void entity_shattering_idle(Entity* entity);
void show_damage_fx(Actor* actor, f32 x, f32 y, f32 z, s32 damage);

s32 entity_raycast_down(f32*, f32*, f32*, f32*, f32*, f32*);

void step_game_loop(void);
s32 resume_all_group(s32 groupFlags);
f32 length2D(f32 x, f32 y);
void player_input_to_move_vector(f32* angle, f32* magnitude);
void game_input_to_move_vector(f32* x, f32* y);
void exec_ShakeCamX(s32 arg0, s32 arg1, s32 arg2, f32 arg3);
void exec_ShakeCam1(s32 arg0, s32 arg1, s32 arg2);
f32 func_800E5348(void);

void draw_number(s32 value, s32 x, s32 y, s32 variableWidthChars, s32 palette, s32 opacity, u16 style);

void set_entity_model_flags(s32 idx, s32 newFlags);
void clear_entity_model_flags(s32 idx, s32 newFlags);
void exec_entity_model_commandlist(s32 idx);
RenderTask* queue_render_task(RenderTask* task);

s32 create_mesh_animator(s16* animPos, s16* animBuffer);
void load_mesh_animator_tree(s32 index, StaticAnimatorNode** tree);

void setup_pause_menu_tab(MenuWindowBP* bpArray, s32 arraySize);

s32 draw_ci_image_with_clipping(IMG_PTR raster, s32 width, s32 height, s32 fmt, s32 bitDepth, PAL_PTR palette, s16 posX,
                                s16 posY, u16 clipULx, u16 clipULy, u16 clipLRx, u16 clipRLy, u8 opacity);

void render_frame(s32 flag);
void clear_windows(void);
void update_window_hierarchy(s32 windowIndex, u8 arg1);
void get_msg_properties(s32 msgID, s32* height, s32* width, s32* maxLineChars, s32* numLines, s32* maxLinesPerPage, s32* arg6, u16 charset);
void replace_window_update(s32 idx, s8 arg1, WindowUpdateFunc pendingFunc);
void decode_yay0(void* src, void* dst);

s32 ai_check_player_dist(Enemy* enemy, s32 arg1, f32 arg2, f32 arg3);

//pause
void pause_init(void);
void pause_handle_input(s32 buttonsPressed, s32 buttonsHeld);
void pause_cleanup(void);

// file menu stuff
void filemenu_init(s32);
void filemenu_cleanup(void);
void filemenu_update(void);
s32 func_80244BC4(void);
void filemenu_set_selected(MenuPanel* menu, s32 col, s32 row);
void filemenu_set_cursor_alpha(s32 arg0);
void filemenu_set_cursor_goal_pos(s32 windowIndex, s32 posX, s32 posY);
u8* filemenu_get_menu_message(s32 idx);

void gfx_task_background(void);

void update_enemy_shadows(void);
void update_hero_shadows(void);

// append gfx funcs
void appendGfx_background_texture(void);
void appendGfx_enemy_actor(void*);
void appendGfx_enemy_actor_blur(void*);
void appendGfx_enemy_actor_reflection(void*);
void appendGfx_partner_actor(void*);
void appendGfx_partner_actor_blur(void*);
void appendGfx_partner_actor_reflection(void*);
void appendGfx_player_actor(void*);
void appendGfx_player_actor_blur(Actor*);
void appendGfx_player_actor_reflection(void*);

void force_disable_actor_blur(Actor*);

void player_handle_floor_collider_type(s32 colliderID);
f32 player_fall_distance(void);
void func_800E4AD8(s32 arg0);
f32 player_check_collision_below(f32, s32* colliderID);
s32 can_trigger_loading_zone(void);
void update_damage_popups(void);
void show_action_rating(s32, Actor*, f32, f32, f32);
s32 render_with_adjusted_palettes(s32, ActorPart*, s32, Matrix4f, s32);

HeapNode* general_heap_create(void);
void* general_heap_malloc(s32 size);
s32 general_heap_free(void* data);

s32 integer_log(s32 number, u32 base);

void set_battle_stage(s32);
void load_battle(s32);

void entity_Shadow_init(Shadow* entity);
void entity_SaveBlock_idle(Entity* entity);
void entity_SaveBlock_pause_game(void);
void entity_SaveBlock_resume_game(void);
void entity_SaveBlock_save_data(void);
void entity_SaveBlock_show_tutorial_message(Entity* entity);
void entity_SaveBlock_wait_for_close_tutorial(Entity* entity);
void entity_SaveBlock_show_choice_message(void);
void entity_SaveBlock_show_result_message(void);
void entity_SaveBlock_wait_for_close_result(Entity* entity);
void entity_SaveBlock_wait_for_close_choice(Entity* entity);
void entity_SaveBlock_init(Entity* entity);
void entity_GreenStompSwitch_idle(Entity* entity);
void entity_GreenStompSwitch_retract(Entity* entity);
void entity_GreenStompSwitch_extend(Entity* entity);
void entity_HugeBlueSwitch_idle(Entity* entity);
void entity_small_switch_idle(Entity* entity);
void entity_RedSwitch_wait_and_reset(Entity* entity);
void entity_base_switch_anim_init(Entity* entity);
s32 entity_RedSwitch_animate_scale(Entity* entity);
void entity_base_switch_start_bound_script(Entity* entity);
void entity_base_switch_animate_scale(Entity* entity);
void entity_base_switch_init(Entity* entity);
f32 entity_block_hit_init_scale(Entity* entity);
void entity_block_hit_animate_scale(Entity* entity);
s32 entity_block_handle_collision(Entity* entity);
void entity_BlueSwitch_init(Entity* entity);
void entity_HugeBlueSwitch_init(Entity* entity);

s32 dispatch_damage_event_actor_0(Actor* actor, s32 damageAmount, s32 event);

// Text
MessagePrintState* msg_get_printer_for_msg(s32 msgID, s32* a1);
s32 msg_printer_load_msg(s32 msgID, MessagePrintState* printer);
void msg_printer_set_origin_pos(MessagePrintState* msgPrintState, s32 x, s32 y);

void get_screen_coords(s32 camID, f32 x, f32 y, f32 z, s32* screenX, s32* screenY, s32* screenZ);

void parent_collider_to_model(s16 colliderID, s16 modelIndex);
void clone_model(u16 srcModelID, u16 newModelID);
struct Model* get_model_from_list_index(s32 listIndex);
s32 create_model_animator(s16* animPos);
s32 get_model_list_index_from_tree_index(s32 treeIndex);
s32 get_transform_group_index(s32);
void get_model_center_and_size(u16 modelID, f32* centerX, f32* centerY, f32* centerZ, f32* sizeX, f32* sizeY,
                               f32* sizeZ);
s32 collision_main_above(void);
void collision_lava_reset_check_additional_overlaps(void);
s32 player_test_lateral_overlap(s32, PlayerStatus*, f32*, f32*, f32*, f32, f32);
Npc* peach_make_disguise_npc(s32 peachDisguise);
void peach_set_disguise_anim(AnimID);

s32 draw_box(s32 flags, WindowStyle windowStyle, s32 posX, s32 posY, s32 posZ, s32 width, s32 height, u8 opacity,
              u8 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ, void (*fpDrawContents)(s32, s32, s32, s32, s32, s32, s32),
              void* drawContentsArg0, Matrix4f rotScaleMtx, s32 translateX, s32 translateY, Matrix4f outMtx);
s32 get_msg_width(s32 msgID, u16 charset);

s32 partner_can_open_world_menus(void);
s32 disable_player_static_collisions(void);
s32 disable_player_input(void);
void func_80027088(s32);
void set_time_freeze_mode(s32);

s32 get_map_IDs_by_name(const char* mapName, s16* areaID, s16* mapID);

void transform_point(Matrix4f mtx, f32 inX, f32 inY, f32 inZ, f32 inS, f32* outX, f32* outY, f32* outZ, f32* outW);
void try_player_footstep_sounds(s32 arg0);
void phys_update_interact_collider(void);
void phys_reset_spin_history(void);
s32 phys_adjust_cam_on_landing(void);
s32 phys_should_player_be_sliding(void);
void phys_init_integrator_for_current_state(void);
void phys_player_land(void);
void phys_main_collision_below(void);
void phys_peach_update(void);
void check_input_spin(void);

b32 npc_test_move_simple_without_slipping(s32, f32*, f32*, f32*, f32, f32, f32, f32);

void update_collider_transform(s16 colliderID);
void get_collider_center(s32 colliderID, f32* x, f32* y, f32* z);

s32 is_another_trigger_bound(Trigger*, EvtScript* script);
Trigger* create_trigger(TriggerBlueprint* def);
s32 evt_trigger_on_activate_exec_script(Trigger* trigger);
Trigger* get_trigger_by_id(s32 triggerID);

Actor* get_actor(s32 actorID);
ActorPart* get_actor_part(Actor* actor, s32 partID);
s32 add_coins(s32 amt);
s32 is_partner_ability_active(s32);
s32 count_power_plus(s32);

s32 phys_can_player_interact(void);

void ai_enemy_play_sound(Npc* npc, s32 arg1, s32 arg2);

s32 player_test_move_without_slipping(PlayerStatus*, f32*, f32*, f32*, f32, f32, s32*);
s32 player_test_move_with_slipping(PlayerStatus* playerStatus, f32* posX, f32* posY, f32* posZ, f32 speed, f32 heading);

s32 evt_get_variable(Evt* script, Bytecode var);
s32 evt_set_variable(Evt* script, Bytecode var, s32 value);
f32 evt_get_float_variable(Evt* script, Bytecode var);
f32 evt_set_float_variable(Evt* script, Bytecode var, f32 value);
s32 evt_get_variable_index(Evt* script, s32 var);
void set_script_timescale(Evt* script, f32 timescale);
f32 sin_deg(f32 x);
f32 cos_deg(f32 x);
f32 sin_rad(f32 x);
f32 cos_rad(f32 x);
s32 round(f32);
f32 atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);
f32 clamp_angle(f32 theta);
s32 sign(s32 value);

b32 check_player_action_debug(void);

s32 battle_heap_create(void);

s32 test_ray_zones(f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX, f32* hitY, f32* hitZ,
                   f32* hitDepth, f32* nx, f32* ny, f32* nz);
s32 test_ray_colliders(s32 ignoreFlags, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX,
                       f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz);
s32 test_ray_entities(f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX, f32* hitY, f32* hitZ,
                      f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz);

void mem_clear(void* data, s32 numBytes);

void startup_set_fade_screen_color(s16 color);
void startup_set_fade_screen_alpha(s16 alpha);

f32 get_xz_dist_to_player(f32, f32);
void func_800E06C0(s32);
void close_status_bar(void);
Evt* func_802C39F8(Evt* parentScript, Bytecode* nextLine, s32 newState);
Evt* start_child_script(Evt* parentScript, EvtScript* source, s32 initialState);
Evt* restart_script(Evt* script);
void clear_virtual_entity_list(void);
void reset_model_animators(void);
void init_virtual_entity_list(void);
void init_model_animators(void);
void play_model_animation(s32, s16*);
s32 heap_free(void* ptr);

void load_battle_hit_asset(const char* hitName);
void load_data_for_models(struct ModelNode* model, s32 romOffset, s32 size);
void load_player_actor(void);

void btl_state_update_normal_start(void);
void btl_state_draw_normal_start(void);
void btl_state_update_begin_turn(void);
void btl_state_draw_begin_turn(void);
void btl_state_update_begin_player_turn(void);
void btl_state_draw_begin_player_turn(void);
void btl_state_update_switch_to_player(void);
void btl_state_draw_switch_to_player(void);
void btl_state_update_begin_partner_turn(void);
void btl_state_draw_begin_partner_turn(void);
void btl_state_update_switch_to_partner(void);
void btl_state_draw_switch_to_partner(void);
void btl_state_update_9(void);
void btl_state_draw_9(void);
void btl_state_update_prepare_menu(void);
void btl_state_draw_prepare_menu(void);
void btl_state_update_end_turn(void);
void btl_state_draw_end_turn(void);
void btl_state_update_1C(void);
void btl_state_draw_1C(void);
void btl_state_update_victory(void);
void btl_state_draw_victory(void);
void btl_state_update_end_training_battle(void);
void btl_state_draw_end_training_battle(void);
void btl_state_update_end_battle(void);
void btl_state_draw_end_battle(void);
void btl_state_update_defend(void);
void btl_state_draw_defend(void);
void btl_state_update_run_away(void);
void btl_state_draw_run_away(void);
void btl_state_update_defeat(void);
void btl_state_draw_defeat(void);
void btl_state_update_change_partner(void);
void btl_state_draw_change_partner(void);
void btl_state_update_player_move(void);
void btl_state_draw_player_move(void);
void btl_state_update_end_player_turn(void);
void btl_state_update_partner_move(void);
void btl_state_draw_end_player_turn(void);
void btl_state_draw_partner_move(void);
void btl_state_update_end_partner_turn(void);
void btl_state_draw_end_partner_turn(void);
void btl_state_update_next_enemy(void);
void btl_state_draw_next_enemy(void);
void btl_state_update_enemy_move(void);
void btl_state_draw_enemy_move(void);
void btl_state_update_first_strike(void);
void btl_state_draw_first_stike(void);
void btl_state_update_partner_striking_first(void);
void btl_state_draw_partner_striking_first(void);
void btl_state_update_enemy_striking_first(void);
void btl_state_draw_enemy_striking_first(void);
void btl_state_update_end_demo_battle(void);
void btl_state_draw_end_demo_battle(void);

void btl_state_update_player_menu(void);
void btl_state_draw_player_menu(void);
void btl_state_update_partner_menu(void);
void btl_state_draw_partner_menu(void);
void btl_state_update_peach_menu(void);
void btl_state_draw_peach_menu(void);
void btl_state_update_twink_menu(void);
void btl_state_draw_twink_menu(void);
void btl_state_update_select_target(void);
void btl_state_draw_select_target(void);
void btl_state_update_22(void);
void btl_state_draw_22(void);

void btl_state_update_celebration(void);
void btl_draw_upgrade_windows(s32);
void btl_state_draw_celebration(void);

void btl_bonk_cleanup(void);
void set_actor_anim_by_ref(Actor*, ActorPart*, AnimID);
void update_action_ratings(void);
void update_health_bars(void);
s32 btl_cam_is_moving_done(void);
void btl_popup_messages_update(void);
void btl_popup_messages_draw_world_geometry(void);
void func_80255FD8(void);

void set_actor_glow_pal(Actor* actor, s32 arg1);

void btl_set_popup_duration(s32 duration);
void switch_to_partner(s32 arg0);
s8 get_current_partner_id(void);

void delete_trigger(Trigger* toDelete);
void kill_script_by_ID(s32 id);
void set_script_priority(Evt* script, s32 priority);
void set_script_group(Evt* script, s32 groupFlags);
void suspend_group_others(Evt* script, s32 groupFlags);
void resume_group_others(Evt* script, s32 groupFlags);
s32 suspend_all_script(s32 id);
s32 resume_all_script(s32 id);

s32 create_shadow_type(s32 type, f32 x, f32 y, f32 z);
s32 is_point_within_region(s32 shape, f32 pointX, f32 pointY, f32 centerX, f32 centerY, f32 sizeX, f32 sizeZ);
PlayerData* get_player_data(void);

b32 npc_raycast_down_around(s32, f32*, f32*, f32*, f32*, f32, f32);
b32 npc_raycast_down_sides(s32 ignoreFlags, f32* posX, f32* posY, f32* posZ, f32* hitDepth);
s32 npc_raycast_up(s32, f32*, f32*, f32*, f32*);
s32 npc_raycast_up_corners(s32 ignoreFlags, f32* posX, f32* posY, f32* posZ, f32* hitDepth, f32 yaw, f32 radius);
s32 player_raycast_up_corners(PlayerStatus*, f32*, f32*, f32*, f32*, f32);
s32 player_raycast_below_cam_relative(PlayerStatus* playerStatus, f32* outX, f32* outY, f32* outZ, f32* outLength,
                                      f32* hitRx, f32* hitRz, f32* hitDirX, f32* hitDirZ);
b32 npc_test_move_taller_with_slipping(s32, f32*, f32*, f32*, f32, f32, f32, f32);
b32 npc_test_move_simple_with_slipping(s32, f32*, f32*, f32*, f32, f32, f32, f32);
s32 npc_test_move_complex_with_slipping(s32, f32*, f32*, f32*, f32, f32, f32, f32);

// Partner
EvtScript* partner_get_enter_map_script(void);
void partner_handle_before_battle(void);
void partner_walking_update_player_tracking(Npc* partner);
void partner_walking_update_motion(Npc* partner);
void enable_partner_ai(void);
void partner_walking_enable(Npc* partner, s32 val);
void partner_flying_enable(Npc* partner, s32 val);
void partner_flying_update_player_tracking(Npc* partner);
s32 partner_is_flying(void);
void partner_flying_update_motion(Npc* partner);
void partner_clear_player_tracking(Npc* partner);

void partner_set_tether_distance(f32);

void btl_delete_player_actor(Actor* player);

s32 cancel_message(MessagePrintState* msgPrintState);

void set_message_images(MessageImageData* images);

void kill_all_scripts(void);
s32 does_script_exist(s32 id);
s32 does_script_exist_by_ref(Evt* script);
Evt* start_script(EvtScript* source, s32 priority, s32 initialState);
Evt* start_script_in_group(EvtScript* source, u8 priority, u8 initialState, u8 groupFlags);
f32 get_player_normal_yaw(void);
void set_standard_shadow_scale(Shadow* shadow, f32 scale);
void set_npc_shadow_scale(Shadow* shadow, f32 height, f32 npcRadius);
void set_npc_animation(Npc* npc, u32 animID);
void set_peach_shadow_scale(Shadow* shadow, f32 scale);
s32 is_block_on_ground(Entity* block);
void set_actor_anim(s32 actorID, s32 partID, AnimID animID);
void set_actor_anim_rate(s32 actorID, s32 partID, f32 rate);
void mdl_group_set_visibility(u16, s32, s32);
void init_enter_world_shared(void);
s16 update_enter_map_screen_overlay(s16* progress);
s16 update_exit_map_screen_overlay(s16* progress);
void set_screen_overlay_params_front(u8, f32);
void set_screen_overlay_params_back(u8, f32);
void set_screen_overlay_alpha(s32, f32);
void get_screen_overlay_params(s32, u8* type, f32* zoom);
void set_screen_overlay_color(s32, u8, u8, u8);
void set_screen_overlay_center(s32, s32, s32, s32);
s32 rand_int(s32);
void sort_items(void);
s32 is_ability_active(s32 arg0);
s32 is_starting_conversation(void);
f32 update_lerp(s32 easing, f32 start, f32 end, s32 elapsed, s32 duration);
void sin_cos_deg(f32 rad, f32* outSinTheta, f32* outCosTheta);

void set_main_pan_u(s32 texPannerID, s32 value);
void set_main_pan_v(s32 texPannerID, s32 value);
void set_aux_pan_u(s32 texPannerID, s32 value);
void set_aux_pan_v(s32 texPannerID, s32 value);

void enable_world_fog(void);
void set_world_fog_dist(s32 start, s32 end);
void set_world_fog_color(s32 r, s32 g, s32 b, s32 a);
s32 is_world_fog_enabled(void);
void get_world_fog_color(s32* r, s32* g, s32* b, s32* a);
void enable_entity_fog(void);
void set_entity_fog_dist(s32 start, s32 end);
void set_entity_fog_color(s32 r, s32 g, s32 b, s32 a);

struct ModelTransformGroup* get_transform_group(s32 index);
void mdl_make_transform_group(u16 modelID);
void enable_transform_group(u16 modelID);
void disable_transform_group(u16 modelID);
void set_map_transition_effect(ScreenTransition);

void set_tex_panner(struct Model* model, s32 texPannerID);
void set_custom_gfx(s32 customGfxIndex, Gfx* pre, Gfx* post);

s32 make_item_entity(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 angle, s32 pickupVar);
s32 make_item_entity_delayed(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 pickupVar);
void set_item_entity_position(s32 itemEntityIndex, f32 x, f32 y, f32 z);
ItemEntity* get_item_entity(s32 itemEntityIndex);
s32 make_item_entity_nodelay(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupVar);
void set_item_entity_flags(s32 itemEntityIndex, s32 flag);
void clear_item_entity_flags(s32 index, s32 flags);

s32 create_worker_frontUI(void (*updateFunc)(void), void (*drawFunc)(void));
Worker* get_worker(s32 idx);
Trigger* bind_trigger_1(EvtScript* script, s32 flags, s32 triggerFlagIndex, s32 triggerVar0, s32 triggerVar1, s32 priority);

void set_cam_viewport(s16 id, s16 x, s16 y, s16 width, s16 height);

void disable_player_shadow(void);
void move_player(s32 duration, f32 heading, f32 speed);
s32 enable_player_input(void);
s32 enable_player_static_collisions(void);
b32 check_input_jump(void);
b32 check_input_hammer(void);

Npc* resolve_npc(Evt* script, s32 npcIdOrPtr);
void enable_npc_blur(Npc* npc);
void disable_npc_blur(Npc* npc);
void enable_partner_blur(void);
void disable_partner_blur(void);

void partner_initialize_data(void);

f32 dist2D(f32 ax, f32 ay, f32 bx, f32 by);
f32 dist3D(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz);
void add_vec2D_polar(f32* x, f32* y, f32 r, f32 theta);

//TODO -- remove these and use audio/public.h instead

enum AuResult bgm_set_track_volumes(s32 playerIndex, s16 trackVolSet);
enum AuResult bgm_clear_track_volumes(s32 playerIndex, s16 trackVolSet);
enum AuResult bgm_set_variation(s32 playerIndex, s16 arg1);
void bgm_quiet_max_volume(void);
void bgm_reset_max_volume(void);
void bgm_reset_volume(void);
s32 bgm_init_music_players(void);
s32 bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume);
void bgm_set_battle_song(s32, s32);
void bgm_push_battle_song(void);
s32 bgm_adjust_proximity(s32 playerIndex, s32 arg1, s16 arg2);
void func_801491E4(Matrix4f mtx, s32, s32, s32, s32, s32 alpha);
s32 func_8014A964(s32 playerIndex, s32 songID, s32 variation, s32 fadeInTime, s16 arg4, s16 arg5);

#include "audio/public.h"

void basic_window_update(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void basic_hidden_window_update(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);

void create_current_pos_target_list(Actor* actor);
void create_home_target_list(Actor* actor);

void set_actor_yaw(s32 actorID, s32 yaw);
void set_part_yaw(s32 actorID, s32 partID, s32 value);

void add_part_decoration(ActorPart* part, s32 decorationIndex, s32 decorationType);
void add_actor_decoration(Actor* actor, s32 decorationIndex, s32 decorationType);
void remove_part_decoration(ActorPart* part, s32 decorationIndex);
void remove_actor_decoration(Actor* actor, s32 decorationIndex);

s32 player_team_is_ability_active(Actor* actor, s32 ability);

void create_part_shadow(s32 actorID, s32 partID);
void remove_part_shadow(s32 actorID, s32 partID);
void create_part_shadow_by_ref(s32 arg0, ActorPart* part);

void spawn_drops(Enemy* enemy);

void set_part_pal_adjustment(ActorPart*, s32);
char* int_to_string(s32, char*, s32);

Evt* get_script_by_index(s32 index);
Evt* get_script_by_id(s32 id);
s32 partner_test_enemy_collision(Npc* enemy);

s32 get_lava_reset_pos(f32* x, f32* y, f32* z);
void start_rumble(s32, s32);
void update_locomotion_state(void);
void start_rumble_type(u32);
void start_falling(void);
void start_bounce_a(void);
void start_bounce_b(void);

void update_input(void);
void update_max_rumble_duration(void);
void mdl_reset_transform_flags(void);
void update_workers(void);
void update_triggers(void);
void update_scripts(void);
void update_messages(void);
void update_entities(void);
void func_80138198(void);
void bgm_update_music_settings(void);
s32 func_8014AD40(void);
void update_ambient_sounds(void);
void update_windows(void);
void player_render_interact_prompts(void);
void func_802C3EE4(void);
void render_screen_overlay_backUI(void);
void render_workers_backUI(void);
void render_effects_UI(void);
void render_window_root(void);
void render_messages(void);
void render_workers_frontUI(void);
void render_screen_overlay_frontUI(void);
void render_curtains(void);
void fio_init_flash(void);
void func_80028838(void);
void clear_screen_overlays(void);
void bgm_reset_sequence_players(void);
void reset_ambient_sounds(void);
void poll_rumble(void);
void bgm_pop_song(void);
void bgm_push_song(s32 songID, s32 variation);
void bgm_pop_battle_song(void);
s32 play_ambient_sounds(s32 fadeInTime, s32 fadeOutTime);
s32 get_fortress_key_count(void);
s32 subtract_fortress_keys(s32 amt);
s32 add_star_points(s32 amt);
s32 add_star_pieces(s32 amt);
s32 make_item_entity_at_player(s32 itemID, s32 arg1, s32 pickupMsgFlags);

void set_action_state(s32 actionState);
s32 get_collider_flags(s32 colliderID);
void suggest_player_anim_always_forward(AnimID anim);
void suggest_player_anim_allow_backward(AnimID anim);
void subtract_hp(s32 amt);
void draw_status_ui(void);
void open_status_bar_slowly(void);

void suspend_all_group(s32 groupFlags);
void kill_script(Evt* instanceToKill);
void exec_entity_commandlist(Entity* entity);

void show_start_recovery_shimmer(f32 x, f32 y, f32 z, s32 arg3);
void show_recovery_shimmer(f32 x, f32 y, f32 z, s32 arg3);

void show_next_damage_popup(f32 x, f32 y, f32 z, s32 damageAmount, s32);
void add_xz_vec3f(Vec3f* vector, f32 speed, f32 angleDeg);
void add_xz_vec3f_copy1(Vec3f* vector, f32 speed, f32 angleDeg);
void add_xz_vec3f_copy2(Vec3f* vector, f32 speed, f32 angleDeg);
void play_movement_dust_effects(s32 var0, f32 xPos, f32 yPos, f32 zPos, f32 angleDeg);

void draw_prev_frame_buffer_at_screen_pos(s32, s32, s32, s32, f32);
void func_8013A4D0(void);

void btl_draw_ui(void);
void btl_restore_world_cameras(void);

void btl_popup_messages_draw_ui(void);
void btl_cam_set_target_pos(f32, f32, f32);
void btl_cam_unfreeze(void);

void deduct_current_move_fp(void);
void load_partner_actor(void);
void dispatch_event_partner(s32);
void dispatch_event_player(s32);
s32 btl_are_all_enemies_defeated(void);
s32 btl_check_enemies_defeated(void);
s32 btl_check_player_defeated(void);
void btl_show_battle_message(s32 messageIndex, s32 duration);
void btl_update_ko_status(void);
void reset_actor_turn_info(void);
void startup_draw_prim_rect(s16 left, s16 top, s16 right, s16 bottom, u16 r, u16 g, u16 b, u16 a);
void startup_draw_prim_rect_COPY(s16 left, s16 top, s16 right, s16 bottom, u16 r, u16 g, u16 b, u16 a);
void btl_draw_prim_quad(u8 r, u8 g, u8 b, u8 a, u16 left, u16 top, u16 arg6, u16 arg7);
void reset_all_actor_sounds(Actor*);
void decrement_status_bar_disabled(void);
void increment_status_bar_disabled(void);
void btl_delete_actor(Actor* actor);
void create_status_debuff(s32, s32);
void create_status_static(s32, s32);
void create_status_transparent(s32, s32);
void remove_status_chill_out(s32);
void remove_status_debuff(s32);
void remove_status_icon_boost_hammer(s32);
void remove_status_icon_boost_jump(s32);
void remove_status_icon_boost_partner(s32);
void remove_status_icon_danger(s32);
void remove_status_icon_peril(s32);
void remove_status_icon_surprise(s32);
void remove_status_static(s32);
void remove_status_transparent(s32);
void remove_all_status_icons(s32);
s32 create_status_icon_set(void);
s32 find_item(s32);

void enable_background_wave(void);

void set_map_change_fade_rate(s16);
void load_map_by_IDs(s16 areaID, s16 mapID, s16 loadType);

// State funcs
void state_init_startup(void);
void state_step_startup(void);
void state_drawUI_startup(void);
void state_init_logos(void);
void state_step_logos(void);
void state_drawUI_logos(void);
void state_init_title_screen(void);
void state_step_title_screen(void);
void state_drawUI_title_screen(void);
void state_init_enter_demo(void);
void state_step_enter_world(void);
void state_init_change_map(void);
void state_step_change_map(void);
void state_drawUI_change_map(void);
void state_init_game_over(void);
void state_step_game_over(void);
void state_drawUI_game_over(void);
void state_init_enter_world(void);
void state_drawUI_enter_world(void);
void state_init_world(void);
void state_step_world(void);
void state_drawUI_world(void);
void state_init_battle(void);
void state_step_battle(void);
void state_drawUI_battle(void);
void state_init_end_battle(void);
void state_step_end_battle(void);
void state_drawUI_end_battle(void);
void state_init_pause(void);
void state_step_pause(void);
void state_drawUI_pause(void);
void state_init_unpause(void);
void state_step_unpause(void);
void state_drawUI_unpause(void);
void state_init_language_select(void);
void state_step_language_select(void);
void state_drawUI_language_select(void);
void state_init_exit_language_select(void);
void state_step_exit_language_select(void);
void state_drawUI_exit_language_select(void);
void state_init_file_select(void);
void state_step_file_select(void);
void state_drawUI_file_select(void);
void state_init_exit_file_select(void);
void state_step_exit_file_select(void);
void state_drawUI_exit_file_select(void);
void state_init_intro(void);
void state_step_intro(void);
void state_drawUI_intro(void);
void state_init_demo(void);
void state_step_demo(void);
void state_drawUI_demo(void);

void btl_set_player_idle_anims(void);

void shim_create_audio_system_obfuscated(void);
void shim_load_engine_data_obfuscated(void);
void shim_general_heap_create_obfuscated(void);
void shim_battle_heap_create_obfuscated(void);
void appendGfx_ispy_icon(void);
void interact_inspect_setup(void);
void interact_speech_setup(void);
void pulse_stone_notification_setup(void);
void appendGfx_speech_bubble(void);
void appendGfx_pulse_stone_icon(void);
void ispy_notification_setup(void);

void initialize_curtains(void);
void update_curtains(void);
// render_curtains
void set_curtain_scale_goal(f32 scale);
void set_curtain_scale(f32 scale);
void set_curtain_draw_callback(UNK_FUN_PTR(callback));
void set_curtain_fade_goal(f32 fade);
void set_curtain_fade(f32 fade);

void crash_screen_init(void);
void crash_screen_set_draw_info(u16* frameBufPtr, s16 width, s16 height);

void basic_ai_wander_init(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory);
void basic_ai_wander(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory);
void basic_ai_loiter(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory);
void basic_ai_found_player_jump_init(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory);
void basic_ai_found_player_jump(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory);
void basic_ai_chase_init(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory);
void basic_ai_chase(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory);
void basic_ai_lose_player(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory);
void basic_ai_suspend(Evt* script);

// This legally allows all functions to be pointers without warnings.
// Perhaps the void arg functions can be changed later to remove this need.
typedef union {
  void (*func1)(Evt*, s32);
  void (*func2)(void);
} WorldArgs TRANSPARENT_UNION;

s32 create_worker_world(WorldArgs, WorldArgs);

void init_entity_models(void);
f32 phys_get_spin_history(s32 lag, s32* x, s32* y, s32* z);
void imgfx_update(u32, ImgFXType, s32, s32, s32, s32, s32);
s32 imgfx_appendGfx_component(s32, ImgFXTexture*, u32, Matrix4f);
void imgfx_update_cache(void);
s32 imgfx_get_free_instances(s32);
void free_worker(s32);

s32 ai_check_fwd_collisions(Npc* npc, f32 arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5);
void basic_ai_loiter_init(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory);
void PatrolAI_LoiterInit(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory);

s32 func_80263230(Actor*, Actor*);
void set_part_glow_pal(ActorPart*, s32);
void clear_actor_static_pal_adjustments(Actor*);
void set_actor_flash_mode(Actor* actor, s32 arg1);
void remove_player_buffs(s32);
s32 is_actor_health_bar_visible(Actor*);

void sin_cos_rad(f32 rad, f32* outSinTheta, f32* outCosTheta);

void load_font(s32 font);
#if VERSION_IQUE
void load_font_data(Addr offset, u32 size, void* dest);
#else
void load_font_data(Addr offset, u16 size, void* dest);
#endif

void* load_asset_by_name(const char* assetName, u32* decompressedSize);

Gfx* mdl_get_copied_gfx(s32 copyIndex);
void mdl_get_copied_vertices(s32 copyIndex, Vtx** firstVertex, Vtx** copiedVertices, s32* numCopied);
void mdl_draw_hidden_panel_surface(Gfx** arg0, u16 treeIndex);
s32 is_point_visible(f32 x, f32 y, f32 z, s32 depthQueryID, f32* screenX, f32* screenY);
void set_screen_overlay_center_worldpos(s32 idx, s32 posIdx, s32 x, s32 y, s32 z);
void* mdl_get_next_texture_address(s32);
s32 cancel_current_message(void);
void draw_msg(s32 msgID, s32 posX, s32 posY, s32 opacity, s32 palette, u8 style);
void mdl_get_shroud_tint_params(u8* r, u8* g, u8* b, u8* a);

s32 entity_base_block_idle(Entity* entity);
void add_star_power(s32 amt);
s32 recover_hp(s32 amt);
s32 recover_fp(s32 amt);
s32 entity_can_collide_with_jumping_player(Entity* entity);
void entity_base_block_init(Entity* entity);
s32 entity_start_script(Entity* entity);
void init_item_entity_list(void);
void init_script_list(void);
void init_entity_data(void);
void init_trigger_list(void);
void partner_init_after_battle(s32 arg0);
void load_map_script_lib(void);
void remove_item_entity_by_index(s32 index);
void set_entity_commandlist(Entity* entity, s32* entityScript);
s32 is_player_dismounted(void);
void func_800EF300(void);
void func_800EF314(void);
void func_800EF43C(void);
void func_800EF3E4(void);
void enable_player_shadow(void);
s32 get_msg_lines(s32 messageID);
void set_window_properties(s32 panelID, s32 posX, s32 posY, s32 width, s32 height, u8, void* drawContents, void* drawContentsArg, s8 parent);
void set_window_update(s32 panelID, s32);
void set_windows_visible(s32 groupIdx);

void partner_disable_input(void);
void partner_set_goal_pos(s32 x, s32 z);
void close_message(MessagePrintState* msgPrintState);
void show_foreground_models_unchecked(void);
void hide_foreground_models_unchecked(void);
void show_foreground_models(void);
void hide_foreground_models(void);
void btl_set_state(s32 battleState);
void draw_entity_model_A(s32, Mtx*);
void draw_entity_model_B(s32, Mtx*, s32, Vec3s*);
void draw_entity_model_C(s32, Mtx*);
void draw_entity_model_D(s32, Mtx*, s32, Vec3s*);
void draw_entity_model_E(s32, Mtx*);
void free_entity_model_by_index(s32 idx);
void btl_cam_use_preset(s32);
void btl_cam_set_params(s16, s16, s16, s16, s32, s32, s32, s32);
void btl_cam_set_zoffset(s16);
void btl_cam_target_actor(s32);
void btl_cam_set_zoom(s16);
void btl_cam_move(s16);
void func_8024E60C(void);

void initialize_battle(void);

void dispatch_event_actor(Actor*, s32);
s32 dispatch_damage_event_actor_1(Actor* actor, s32 damageAmount, s32 event);

void reset_battle_status(void);
void btl_show_variable_battle_message(s32, s32, s32);
s32 btl_is_popup_displayed(void);
void btl_cam_use_preset_immediately(s32);
s32 inflict_status(Actor*, s32, s32);
s32 try_inflict_status(Actor*, s32, s32);
s32 inflict_status_set_duration(Actor* actor, s32 statusTypeKey, s32 statusDurationKey, s32 duration);
void mdl_set_all_tint_type(s32);
void load_model_animator_tree(s32, StaticAnimatorNode**);

s32 inflict_partner_ko(Actor* target, s32 statusTypeKey, s32 duration);
s32 get_defense(Actor* actor, s32* defenseTable, s32 elementFlags);

void btl_popup_messages_init(void);

void remove_all_effects(void);
void update_effects(void);
void update_cameras(void);
void clear_render_tasks(void);
void clear_worker_list(void);
void clear_printers(void);
void clear_item_entity_data(void);
void clear_player_data(void);

void phys_update_jump(void);
void phys_update_falling(void);
void check_input_midair_jump(void);
void collision_check_player_overlaps(void);

void update_player_input(void);
void phys_update_action_state(void);
void collision_main_lateral(void);
void handle_floor_behavior(void);
void check_input_open_menus(void);
void check_input_status_bar(void);

void update_player(void);

void enforce_hpfp_limits(void);
s32 should_collider_allow_interact(s32);
void show_coin_counter(void);
s32 add_item(s32 itemID);
s32 add_badge(s32 itemID);
void hide_coin_counter_immediately(void);
void hide_popup_menu(void);
void destroy_popup_menu(void);
void reset_player_status(void);
void player_reset_data(void);
void partner_reset_data(void);
s32 has_valid_conversation_npc(void);
s32 func_800E06D8(void);
void func_800E01DC(void);
void collision_lateral_peach(void);
void func_800E5520(void);
void clear_world_menus(void);
void setup_status_bar_for_battle(void);
void enable_status_bar_input(void);
void disable_status_bar_input(void);
b32 can_control_status_bar(void);
void status_bar_respond_to_changes(void);
void status_bar_always_show_on(void);
void status_bar_always_show_off(void);
void func_800F0C9C(void);
void func_800F0CB0(s32, f32, f32, f32);
void func_800F0D5C(void);
void func_800F0D80(void);
void func_800F102C(void);
s32 get_item_count(void);
s32 get_stored_empty_count(void);
s32 get_stored_count(void);
s32 get_item_empty_count(void);
void shop_open_item_select_popup(s32 mode);
void hide_coin_counter(void);
void set_message_text_var(s32 msgID, s32 index);
void set_message_int_var(s32 value, s32 index);
s32 store_item(s32 itemID);
void open_status_bar_quickly(void);
void show_immune_bonk(f32 x, f32 y, f32 z, s32, s32, s32);
void show_primary_damage_popup(f32 x, f32 y, f32 z, s32 attack, s32 a);
s32 dispatch_damage_event_partner(s32 damageAmount, s32 event, s32 stopMotion);
void disable_actor_blur(Actor*);
void reset_actor_blur(Actor*);
void enable_actor_blur(Actor*);
void apply_shock_effect(Actor*);
void part_glow_off(s32, ActorPart*, s32 yaw, b32 arg3);
void part_flash_off(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection);
void part_flash_on(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection);
void _add_part_decoration(ActorPart*);
void _remove_part_decoration(ActorPart* part, s32 decorationIndex);
void remove_part_decor_none(ActorPart*, s32);
void remove_part_decor_golden_flames(ActorPart*, s32);
void remove_part_decor_sweat(ActorPart*, s32);
void remove_part_decor_seeing_stars(ActorPart*, s32);
void remove_part_decor_red_flames(ActorPart*, s32);
void remove_part_decor_smoky_trail(ActorPart*, s32);
void remove_part_decor_fiery_trail(ActorPart*, s32);
void remove_part_decor_whirlwind(ActorPart*, s32);
void remove_part_decor_steam(ActorPart*, s32);
void remove_part_decor_sparkles(ActorPart*, s32);
void remove_part_decor_bowser_aura(ActorPart*, s32);
void remove_part_decor_radiating_stars(ActorPart*, s32);
void status_bar_ignore_changes(void);
void imgfx_release_instance(u32);

void set_script_flags(Evt* script, s32 flags);
void clear_script_flags(Evt* script, s32 flags);

void disable_player_blur(void);
void enable_player_blur(void);
void reset_player_blur(void);
void force_disable_player_blur(void);
void force_disable_player_blur_immediately(void);

void func_8023E104(void);
void func_8023E11C(void);

void set_goal_pos_to_part(ActorState* state, s32 actorID, s32 partID);

void init_encounters_ui(void);
void initialize_collision(void);
void render_entities(void);
void render_player(void);
void render_workers_world(void);
void render_effects_world(void);
s32 get_asset_offset(char*, s32*);
void initialize_status_bar(void);
void status_bar_start_blinking_fp(void);
s32 is_status_bar_visible(void);
void status_bar_start_blinking_starpoints(void);
void status_bar_stop_blinking_starpoints(void);
void status_bar_start_blinking_hp(void);
void status_bar_start_blinking_sp(void);
void status_bar_stop_blinking_fp(void);
void status_bar_stop_blinking_hp(void);
void status_bar_stop_blinking_sp(void);
void status_bar_start_blinking_sp_bars(s32 numBarsToBlink);
void status_bar_draw_number(s32 iconID, s32 x, s32 y, s32 value, s32 numDigits);
void status_bar_draw_stat(s32 id, s32 x, s32 y, s32, s32);
void set_background_size(s16, s16, s16, s16);
void set_background(BackgroundHeader*);
void set_max_star_power(s8);
void sync_status_bar(void);
void create_cameras_a(void);
void func_80045AC0(void);
void func_8005AF84(void);
void npc_follow_init(Npc*, s32, FollowAnims*, f32, f32, s32, s32);
void npc_update_npc_tracking(Npc*);
void npc_follow_npc(Npc*);
void create_encounters(void);
void update_encounters_neutral(void);
void update_encounters_pre_battle(void);
void update_encounters_conversation(void);
void update_encounters_post_battle(void);
void load_map_bg(char* optAssetName);
void reset_background_settings(void);
void func_80138188(void);
void func_80266970(Actor*);
void show_actor_health_bar(Actor*);
void hide_actor_health_bar(Actor*);
void clear_part_pal_adjustment(ActorPart*);
void calculate_camera_yinterp_rate(void);
void load_tattle_flags(s32);
s32 use_consumable(s32 invSlot);
void remove_consumable(void);
void delete_shadow(s32);
void partner_reset_tether_distance(void);
void save_tattle_flags(s32);
void update_merlee_messages(void);
void draw_merlee_messages(void);
void show_merlee_message(s16, s16);
s32 is_merlee_message_done(void);
void close_action_command_instruction_popup(void);
void draw_encounters_conversation(void);
void draw_encounters_post_battle(void);
void draw_encounters_pre_battle(void);
void draw_encounters_neutral(void);
void show_first_strike_message(void);
void entity_upgrade_block_hide_content(s32);
s32 lookup_defense(s32*, s32);
s32 lookup_status_chance(s32*, s32);
void peach_check_for_parasol_input(void);
void peach_sync_disguise_npc(void);
s32 check_conversation_trigger(void);

void clear_player_status(void);
void clear_entity_models(void);
void bind_entity_model_setupGfx(s32 idx, void* setupGfxCallbackArg0, void (*fpSetupGfxCallback)(void*));
void clear_animator_list(void);
void clear_model_data(void);
void init_sprite_shading_data(void);
void clear_sprite_shading_data(void);
void clear_character_set(void);
void clear_trigger_data(void);
void clear_script_list(void);
void clear_entity_data(b32);
void clear_effect_data(void);

void clear_saved_variables(void);
void clear_area_flags(void);

f32 get_player_normal_pitch(void);
void partner_kill_ability_script(void);
void func_800EF3D4(s32);

void mdl_update_transform_matrices(void);
void mdl_group_set_custom_gfx(u16, s32, s32, b32);

void backup_map_collision_data(void);
void reset_status_bar(void);
void btl_save_world_cameras(void);
void load_battle_section(void);
void btl_update(void);
void update_item_entities(void);
void iterate_models(void);
void restore_map_collision_data(void);
void mdl_load_all_textures(struct ModelNode* model, s32 romOffset, s32 size);
void mdl_calculate_model_sizes(void);

#endif
