#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common.h"
#include "map.h"
#include "enums.h"
#include "stdlib/stdarg.h"

f32 fabsf(f32 f);
f32 cosine(s16 arg0);

s32 strcmp(const char* str1, const char* str2);

void nuBoot(void);
void boot_idle(void);
void boot_main(void);

void osCleanupThread(void);
OSThread* osGetActiveQueue(void);

f32 signF(f32 val);

void* heap_malloc(s32 size);
HeapNode* _heap_create(s32* addr, u32 size);
s32 dma_copy(Addr romStart, Addr romEnd, void* vramDest);

s32 _Printf(PrintCallback pfn, void* arg, const char* fmt, va_list ap);

s32 get_global_byte(s32 index);
s32 get_global_flag(s32 index);
s32 get_area_byte(s32 index);
s32 get_area_flag(s32 index);

Shadow* get_shadow_by_index(s32 index);
s32 get_time_freeze_mode(void);
void render_player_model(void);
s16 get_game_mode(void);
s32 is_picking_up_item(void);

f32 integrate_gravity(void);
void gravity_use_fall_parms(void);
f32 get_clamped_angle_diff(f32, f32);
s32 intro_logos_fade_out(s16 addAlpha);

void _render_transition_stencil(s32, f32, s32);
u32 get_entity_type(s32 arg0);
Entity* get_entity_by_index(s32 index);
s32 create_entity(StaticEntityData*, s32, s32, s32, s32, ...);
void entity_shattering_idle(Entity* entity);
void func_802666E4(Actor* actor, f32 x, f32 y, f32 z, s16 damage);

void step_game_loop(void);
s32 resume_all_group(s32 groupFlags);
f32 length2D(f32 x, f32 y);
void player_input_to_move_vector(f32* angle, f32* magnitude);
void game_input_to_move_vector(f32* x, f32* y);
void exec_ShakeCamX(s32 arg0, s32 arg1, s32 arg2, f32 arg3);
void exec_ShakeCam1(s32 arg0, s32 arg1, s32 arg2);
f32 func_800E5348(void);

void draw_number(s32 value, s32 x, s32 y, s32 arg3, s32 palette, s32 opacity, s32 style);

void set_entity_model_render_command_list(s32 idx, u32* commandList);
void set_entity_model_flags(s32 idx, s32 newFlags);
void clear_entity_model_flags(s32 idx, s32 newFlags);
void exec_entity_model_commandlist(s32 idx);
s32 load_entity_model(s32* cmdList);
RenderTask* queue_render_task(RenderTask* task);

void setup_pause_menu_tab(MenuWindowBP* bpArray, s32 arraySize);

// append gfx funcs
void func_80257B28(s32);
void func_8025595C(Actor*);
void func_80257B68(Actor*);
void func_80257B48(s32);
void func_8025599C(s32);
void func_80257B88(void);
void func_80257DA4(void);
void func_80254C50(void);
void func_80258E14(void);

f32 func_800E34D8(void);
void func_800E4AD8(s32 arg0);
f32 player_check_collision_below(f32, s32* colliderID);
s32 can_trigger_loading_zone(void);
void func_802667F0(s32, Actor*, f32, f32, f32);

void* general_heap_malloc(s32 size);
s32 general_heap_free(s32* size);

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

void get_screen_coords(s32 camID, f32 x, f32 y, f32 z, s32* screenX, s32* screenY, s32* screenZ);

void parent_collider_to_model(s32 colliderID, s16 modelIndex);
void clone_model(u16 srcModelID, u16 newModelID);
Model* get_model_from_list_index(s32 listIndex);
s32 get_model_list_index_from_tree_index(s32 treeIndex);
s32 get_transform_group_index(s32);
void get_model_center_and_size(u16 modelID, f32* centerX, f32* centerY, f32* centerZ, f32* sizeX, f32* sizeY,
                               f32* sizeZ);
s32 collision_main_above(void);
s32 collision_lava_reset_check_additional_overlaps(void);
s32 player_test_lateral_overlap(s32, PlayerStatus*, f32*, f32*, f32*, f32, f32);
Npc* peach_make_disguise_npc(s32 peachDisguise);
void peach_set_disguise_anim(s32);

void draw_box(s32 flags, s32 windowStyle, s32 posX, s32 posY, s32 posZ, s32 width, s32 height, s32 opacity,
              s32 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ, void (*fpDrawContents)(s32),
              s32 drawContentsArg0, Matrix4f rotScaleMtx, s32 translateX, s32 translateY, Matrix4f* outMtx);
s32 get_msg_width(s32 msgID, u16 charset);

s32 partner_player_can_pause(void);
s32 disable_player_static_collisions(void);
s32 disable_player_input(void);
void func_80027088(s32);
void set_time_freeze_mode(s32);

s32 get_map_IDs_by_name(const char* mapName, s16* areaID, s16* mapID);

void get_dpad_input_radial(f32* angle, f32* magnitude);
void transform_point(Matrix4f mtx, f32 inX, f32 inY, f32 inZ, f32 inS, f32* outX, f32* outY, f32* outZ, f32* outS);
void try_player_footstep_sounds(s32 arg0);
void phys_update_interact_collider(void);
void phys_adjust_cam_on_landing(void);
void phys_init_integrator_for_current_state(void);
void phys_player_land(void);
void phys_main_collision_below(void);

void create_popup_menu(PopupMenu*);
s32 npc_test_move_simple_without_slipping(s32, f32*, f32*, f32*, f32, f32, f32, f32);

void update_collider_transform(s16 colliderID);
void get_collider_center(s32 colliderID, f32* x, f32* y, f32* z);

s32 is_trigger_bound(Trigger*, EvtSource* script);
Trigger* create_trigger(TriggerDefinition* def);
s32 evt_bound_script_trigger_handler(Trigger* trigger);
Trigger* get_trigger_by_id(s32 triggerID);

Actor* get_actor(s32 actorID);
ActorPart* get_actor_part(Actor* actor, s32 partIndex);
s32 add_coins(s32 amt);

s32 phys_can_player_interact(void);

void ai_enemy_play_sound(Npc* npc, s32 arg1, s32 arg2);

s32 player_test_move_without_slipping(PlayerStatus*, f32*, f32*, f32*, s32, f32, s32*);
s32 player_test_move_with_slipping(PlayerStatus* playerStatus, f32* posX, f32* posY, f32* posZ, f32 speed, f32 heading);

s32 evt_get_variable(Evt* script, Bytecode var);
s32 evt_set_variable(Evt* script, Bytecode var, s32 value);
f32 evt_get_float_variable(Evt* script, Bytecode var);
f32 evt_set_float_variable(Evt* script, Bytecode var, f32 value);
void set_script_timescale(Evt* script, f32 timescale);
f32 sin_deg(f32 x);
f32 cos_deg(f32 x);
f32 sin_rad(f32 x);
f32 cos_rad(f32 x);
s32 round(f32);
f32 atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);
f32 clamp_angle(f32 theta);
s32 sign(s32 value);
s32 func_80055448(s32);
s32 func_80055464(s32, s32);
void func_800561A4(s32);

s32 battle_heap_create(void);
void filemenu_init(s32);

s32 test_ray_zones(f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX, f32* hitY, f32* hitZ,
                   f32* hitDepth, f32* nx, f32* ny, f32* nz);
s32 test_ray_colliders(s32 ignoreFlags, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX,
                       f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz);
s32 test_ray_entities(f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX, f32* hitY, f32* hitZ,
                      f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz);

void mem_clear(void* data, s32 numBytes);

void intro_logos_set_fade_color(s16 color);
void intro_logos_set_fade_alpha(s16 alpha);

void set_game_mode(s16 idx);

f32 get_xz_dist_to_player(f32, f32);
void func_800E06C0(s32);
void close_status_menu(void);
Evt* func_802C39F8(Evt* parentScript, Bytecode* nextLine, s32 newState);
Evt* start_child_script(Evt* parentScript, EvtSource* source, s32 initialState);
Evt* restart_script(Evt* script);
void clear_virtual_entity_list(void);
void reset_model_animators(void);
void init_virtual_entity_list(void);
void init_model_animators(void);
s32 heap_free(void* ptr);
void btl_state_update_switch_to_partner(void);
void switch_to_partner(s32 arg0);

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

// Pause
s32 pause_interp_vertical_scroll(s32 deltaBefore);
void pause_draw_rect(s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tileDescriptor, s32 uls, s32 ult, s32 dsdx, s32 dtdy);
s32 pause_get_total_equipped_bp_cost(void);
s32 pause_get_menu_msg(s32 index);
void pause_sort_item_list(s16* arr, s32 len, s32 (*compare)(s16*, s16 *));

s32 npc_raycast_down_ahead(s32, f32*, f32*, f32*, f32*, f32, f32);
s32 npc_raycast_down_sides(s32, f32*, f32*, f32*, f32*);
s32 player_raycast_below_cam_relative(PlayerStatus*, f32*, f32*, f32*, f32*, f32*, f32*, f32*, f32*);
s32 npc_test_move_taller_with_slipping(s32, f32*, f32*, f32*, f32, f32, f32, f32);
s32 npc_test_move_simple_with_slipping(s32, f32*, f32*, f32*, f32, f32, f32, f32);
s32 npc_test_move_complex_with_slipping(s32, f32*, f32*, f32*, f32, f32, f32, f32);

Npc* get_npc_by_index(s32 listIndex);

// Partner
void partner_walking_update_player_tracking(Npc* partner);
void partner_walking_update_motion(Npc* partner);
void enable_partner_ai(void);
void partner_walking_enable(Npc* partner, s32 val);
void partner_flying_enable(Npc* partner, s32 val);
void partner_flying_update_player_tracking(Npc* partner);
s32 partner_is_flying(void);
void partner_flying_update_motion(Npc* partner);
void partner_clear_player_tracking(Npc* partner);

void set_background_color_blend(u8 r, u8 g, u8 b, u8 a);

void partner_set_tether_distance(f32);
s32 does_script_exist(s32 id);
s32 does_script_exist_by_ref(Evt* script);
Evt* start_script(EvtSource* source, s32 priority, s32 initialState);
Evt* start_script_in_group(EvtSource* source, u8 priority, u8 initialState, u8 groupFlags);
f32 get_player_normal_yaw(void);
void set_standard_shadow_scale(Shadow* shadow, f32 scale);
void set_peach_shadow_scale(Shadow* shadow, f32 scale);
void set_animation_rate(s32 actorID, s32 partIndex, f32 rate);
void func_8011B7C0(u16, s32, s32);
AnimatedMesh* get_animator_by_index(s32 arg0);
void set_screen_overlay_params_front(u8, f32);
void set_screen_overlay_params_back(s32, f32);
void set_screen_overlay_alpha(s32, f32);
void get_screen_overlay_params(s32, f32*, f32*);
s32 set_screen_overlay_color(s32, u8, u8, u8);
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
void enable_entity_fog(void);
void set_entity_fog_dist(s32 start, s32 end);
void set_entity_fog_color(s32 r, s32 g, s32 b, s32 a);

ModelTransformGroup* get_transform_group(s32 index);

s32 make_item_entity(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 facingAngleSign,
                     s32 pickupVar);
s32 make_item_entity_delayed(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 pickupVar);
void set_item_entity_position(s32 itemEntityIndex, f32 x, f32 y, f32 z);
ItemEntity* get_item_entity(s32 itemEntityIndex);
s32 make_item_entity_nodelay(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupVar);
void set_item_entity_flags(s32 itemEntityIndex, s32 flag);

s32 create_generic_entity_frontUI(void (*updateFunc)(void), void (*drawFunc)(void));
DynamicEntity* get_generic_entity(s32 idx);

void set_cam_viewport(s16 id, s16 x, s16 y, s16 width, s16 height);

void disable_player_shadow(void);
void move_player(s32 duration, f32 heading, f32 speed);
s32 enable_player_input(void);
s32 enable_player_static_collisions(void);
s32 check_input_jump(void);
s32 check_input_hammer(void);

Npc* get_npc_safe(s32 npcId);
Npc* get_npc_unsafe(s32 npcId);
Npc* resolve_npc(Evt* script, s32 npcIdOrPtr);
void set_npc_yaw(Npc* npcPtr, f32 angle);
void npc_move_heading(Npc* npc, f32 speed, f32 yaw);
void enable_npc_blur(Npc* npc);
void disable_npc_blur(Npc* npc);

f32 dist2D(f32 ax, f32 ay, f32 bx, f32 by);
f32 dist3D(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz);
void add_vec2D_polar(f32* x, f32* y, f32 r, f32 theta);

s32 sfx_adjust_env_sound_pos(s32 soundID, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
void sfx_play_sound(s32 soundID);
void sfx_play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);
void sfx_play_sound_at_player(s32 soundID, s32 arg0);
void sfx_play_sound_at_npc(s32 soundID, s32 arg1, s32 npcID);
s32 bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume);
void func_801497FC(s32 arg0);
s32 func_8014AA54(s32 playerIndex, s32 arg1, s16 arg2);

s32 basic_window_update(void);
s32 basic_hidden_window_update(void);

void player_create_target_list(Actor* actor);
void enemy_create_target_list(Actor* actor);

void set_actor_yaw(s32 actorID, s32 yaw);
void set_part_yaw(s32 actorID, s32 partIndex, s32 value);

void add_part_decoration(ActorPart* part, s32 decorationIndex, s32 decorationType);
void add_actor_decoration(Actor* actor, s32 decorationIndex, s32 decorationType);
void remove_part_decoration(ActorPart* part, s32 decorationIndex);
void remove_actor_decoration(Actor* actor, s32 decorationIndex);

s32 player_team_is_ability_active(Actor* actor, s32 ability);

void create_part_shadow(s32 actorID, s32 partIndex);
void remove_part_shadow(s32 actorID, s32 partIndex);
void create_part_shadow_by_ref(UNK_TYPE arg0, ActorPart* part); // arg0 unused

Evt* get_script_by_index(s32 index);

s32 get_lava_reset_pos(f32* x, f32* y, f32* z);
void start_rumble(s32, s32);
void start_falling(void);

void set_action_state(s32 actionState);
s32 get_collider_type_by_id(s32 colliderID);
void suggest_player_anim_setUnkFlag(s32 arg0);
void suggest_player_anim_clearUnkFlag(s32 arg0);
void subtract_hp(s32 amt);
void open_status_menu_long(void);

void suspend_all_group(s32 groupFlags);
void kill_script(Evt* instanceToKill);
void exec_entity_commandlist(Entity* entity);

void sfx_reset_door_sounds(void);

void func_802D7460(f32 x, f32 y, f32 z, s32 arg3);
void func_802D74C0(f32 x, f32 y, f32 z, s32 arg3);

void show_damage_popup(f32 x, f32 y, f32 z, s32 damageAmount, s32);
void add_xz_vec3f(Vec3f* vector, f32 speed, f32 angleDeg);
void play_movement_dust_effects(s32 var0, f32 xPos, f32 yPos, f32 zPos, f32 angleDeg);

void func_80138D88(s32, s32, s32, s32, f32);

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
void func_80036430(void);
void func_8003646C(void);
void func_80036640(void);
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

void func_802B2078(void);
void spr_update_player_sprite(s32, s32, f32);

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

// Dead functions:
void func_8006CAC0(float mf[4][4], float x, float y, float z);

void func_800495A0(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory);
void func_800496B8(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory);
void func_80049C04(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory);
void func_80049E3C(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory);
void func_80049ECC(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory);
void func_80049F7C(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory);
void func_8004A124(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory);
void func_8004A3E8(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory);
void func_8004A73C(Evt* script);

s32 create_generic_entity_world(void (*updateFunc)(void), void (*drawFunc)(void));
EntityModel* get_entity_model(s32 idx);
f32 phys_get_spin_history(s32 lag, s32* x, s32* y, s32* z);

void sfx_get_spatialized_sound_params(f32 arg0, f32 arg1, f32 arg2, s16* arg3, s16* arg4, s32 arg5);
void sfx_play_sound_with_params(s32 arg0, u8 arg1, u8 arg2, s16 arg3);
s32 func_8004A784(Npc* npc, f32 arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5);
void base_UnkNpcAIFunc1(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
void DeadUnkNpcAIFunc1(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory);

s32** spr_get_npc_palettes(s32 npcSpriteID);
void spr_draw_player_sprite(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Matrix4f arg4);
void spr_draw_npc_sprite(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Matrix4f* arg4);
s32 spr_update_sprite(s32 arg0, s32 arg1, f32 arg2);
void sin_cos_rad(f32 rad, f32* outSinTheta, f32* outCosTheta);


void* load_asset_by_name(const char* assetName, u32* decompressedSize);

void mdl_draw_hidden_panel_surface(Gfx** arg0, u16 treeIndex);
s32 func_8011CFBC(void);
s32 set_screen_overlay_center_worldpos(void);
s32 mdl_get_next_texture_address(s32);
void draw_msg(s32 msgID, s32 posX, s32 posY, s32 opacity, s32 palette, s32 style);
void get_background_color_blend(u8* r, u8* g, u8* b, u8* a);

s8 set_global_byte(s32 index, s32 value);

s32 entity_base_block_idle(Entity* entity);
s32 recover_hp(s32 amt);
s32 recover_fp(s32 amt);
void entity_set_render_script(Entity* entity, u32* commandList);
s32 entity_can_collide_with_jumping_player(Entity* entity);
s32 set_global_flag(s32 index);
void entity_base_block_init(Entity* entity);
s32 entity_start_script(Entity* entity);
void remove_item_entity_by_index(s32 index);
void set_entity_commandlist(Entity* entity, s32* entityScript);
void func_800EF3E4(void);
void func_80268858(void);
void func_80269118(void);
s32 func_80268224(s32);
void func_80149A6C(s32, s32);
void func_800EF300(void);
void enable_player_shadow(void);
s32 get_msg_lines(s32 messageID);
void set_window_properties(s32 panelID, s32 posX, s32 posY, s32 width, s32 height, s32, void* drawContents, PopupMessage* popup, s32 parent);
void set_window_update(s32 panelID, s32);
void snd_stop_sound(s32 soundID);
void partner_disable_input(void);
void func_80268798(s32, s32, s32, s32);
void func_802687E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void sfx_stop_sound(s32 soundID);
void close_message(MessagePrintState* msgPrintState);
void show_foreground_models_unchecked(void);
void hide_foreground_models_unchecked(void);
void show_foreground_models(void);
void hide_foreground_models(void);
void btl_set_state(s32 battleState);
void draw_entity_model_E(s32, Mtx*);
void draw_entity_model_A(s32, Mtx*);
void free_entity_model_by_index(s32 idx);
s32 func_802DDFF8(s32, s32, s32, s32, s32, s32, u16);
void func_8024E40C(s32);
void btl_cam_set_zoffset(s16);
void btl_cam_target_actor(s32);
void btl_cam_set_zoom(s16);
void btl_cam_move(s16);
void func_8024E60C(void);
void dispatch_event_actor(Actor*, s32);
void btl_show_variable_battle_message(s32, s32, s32);
s32 btl_is_popup_displayed(void);
void func_8024E3D8(s32);
s32 inflict_status(Actor*, s32, s32);

void enforce_hpfp_limits(void);

#endif
