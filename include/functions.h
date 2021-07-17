#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common.h"
#include "map.h"
#include "enums.h"

f32 fabsf(f32 f);
f32 sqrtf(f32 f);
f64 sqrt(f64 d);
f32 cosine(s16 arg0);

s32 strcmp(const char* str1, const char* str2);

void nuBoot(void);
void boot_idle(void);
void boot_main(void);

void osCleanupThread(void);

void playFX_30(s32, f32, f32, f32);
void playFX_31(s32, f32, f32, f32);
f32 signF(f32 val);

void* heap_malloc(s32 size);
HeapNode* _heap_create(s32* addr, u32 size);
s32 dma_copy(Addr romStart, Addr romEnd, void* vramDest);

s32 get_global_byte(s32 index);
s32 get_global_flag(s32 index);
s32 get_area_byte(s32 index);
s32 get_area_flag(s32 index);

Shadow* get_shadow_by_index(s32 index);
s32 get_time_freeze_mode(void);
void render_player_model();
s16 get_game_mode(void);

f32 integrate_gravity(void);
f32 get_clamped_angle_diff(f32, f32);

void _render_transition_stencil(s32, f32, s32);
u32 get_entity_type(s32 arg0);
Entity* get_entity_by_index(s32 index);
s32 create_entity(StaticEntityData*, s32, s32, s32, s32, s32);
void playFX_22(s32, f32, f32, f32, f32, f32, s32, s32);
void entity_shattering_idle(Entity* entity);
void func_802666E4(Actor* actor, f32 arg1, f32 arg2, f32 arg3, s16);

void step_game_loop(void);
s32 resume_all_group(s32 groupFlags);
f32 length2D(f32 x, f32 y);
void player_input_to_move_vector(f32* angle, f32* magnitude);
void exec_ShakeCamX(s32 arg0, s32 arg1, s32 arg2, f32 arg3);
f32 func_800E5348(void);

void transform_point(Matrix4f mtx, f32, f32, f32, f32, f32*, f32*, f32*, f32*);
void draw_number(s32 value, s32 x, s32 y, s32 arg3, s32 palette, s32 opacity, s32 style);
void set_hud_element_scale(s32 index, f32 scale);

void set_entity_model_render_command_list(s32 idx, u32* commandList);
void set_entity_model_flags(s32 idx, s32 newFlags);
void clear_entity_model_flags(s32 idx, s32 newFlags);
void exec_entity_model_commandlist(s32 idx);
s32 load_entity_model(s32* cmdList);

f32 func_800E34D8(void);
f32 player_check_collision_below(f32, s32* colliderID);
s32 can_trigger_loading_zone(void);
void func_802667F0(s32, Actor*, f32, f32, f32);

void* general_heap_malloc(s32 size);
s32 general_heap_free(s32 size);

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

// todo remove once we have libultra's def
extern void guOrtho(Mtx *m, float l, float r, float b, float t,
		    float n, float f, float scale);
// Text
MessagePrintState* msg_get_printer_for_string(s32 stringID, s32* a1);

void get_screen_coords(Cam camID, f32 x, f32 y, f32 z, s32* screenX, s32* screenY, s32* screenZ);

void parent_collider_to_model(s32 colliderID, s16 modelIndex);
void clone_model(u16 srcModelID, u16 newModelID);
Model* get_model_from_list_index(s32 listIndex);
s32 get_model_list_index_from_tree_index(s32 treeIndex);
s32 get_transform_group_index(s32);
void get_model_center_and_size(u16 modelID, f32* centerX, f32* centerY, f32* centerZ, f32* sizeX, f32* sizeY,
                               f32* sizeZ);
s32 collision_main_above(void);
s32 player_test_lateral_overlap(s32, PlayerStatus*, f32*, f32*, f32*, f32, f32);
Npc* peach_make_disguise_npc(s32 peachDisguise);

void draw_box(s32 flags, s32 windowStyle, s16 posX, s16 posY, s32 posZ, s32 width, s32 height, s32 opacity,
              s32 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ, void (*fpDrawContents)(s32),
              s32 drawContentsArg0, Matrix4f rotScaleMtx, s32 translateX, s32 translateY, Matrix4f* outMtx);

s32 partner_player_can_pause(void);
s32 disable_player_static_collisions(void);
s32 disable_player_input(void);
void func_80027088(s32);
void set_time_freeze_mode(s32);

s32 get_map_IDs_by_name(const char* mapName, s16* areaID, s16* mapID);

void get_dpad_input_radial(f32* angle, f32* magnitude);
void transform_point(Matrix4f mtx, f32 inX, f32 inY, f32 inZ, f32 inS, f32* outX, f32* outY, f32* outZ, f32* outS);

void create_popup_menu(void*);
s32 npc_test_move_simple_without_slipping(s32, f32*, f32*, f32*, f32, f32, f32, f32);

void update_collider_transform(s16 colliderID);
void get_collider_center(s32 colliderID, f32* x, f32* y, f32* z);

s32 is_trigger_bound(Trigger*, Bytecode* script);
Trigger* create_trigger(TriggerDefinition* def);
s32 _bound_script_trigger_handler(Trigger* trigger);
Trigger* get_trigger_by_id(s32 triggerID);

Actor* get_actor(ActorID actorID);
ActorPart* get_actor_part(Actor* actor, s32 partIndex);
s32 add_coins(s32 amt);

void ai_enemy_play_sound(Npc* npc, s32 arg1, s32 arg2);

s32 player_test_move_without_slipping(PlayerStatus*, f32*, f32*, f32*, s32, f32, s32*);

s32 get_variable(ScriptInstance* script, Bytecode var);
s32 set_variable(ScriptInstance* script, Bytecode var, s32 value);
f32 get_float_variable(ScriptInstance* script, Bytecode var);
f32 set_float_variable(ScriptInstance* script, Bytecode var, f32 value);
void set_script_timescale(ScriptInstance* script, f32 timescale);
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
s32 osGetId();

s32 battle_heap_create(void);
void filemenu_init(s32);

s32 test_ray_zones(f32, f32, f32, f32*, f32*, f32*, f32*, f32*, f32*, f32*);

void mem_clear(s8* data, s32 numBytes);

HudElement* create_hud_element(s32* iconIndex);
void set_hud_element_render_pos(s32 iconIndex, s32 posX, s32 posY);

void intro_logos_set_fade_color(s16 color);
void intro_logos_set_fade_alpha(s16 alpha);

void set_game_mode(s16 idx);

void fx_walk(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void fx_emote(s32, Npc*, f32, f32, f32, f32, f32, s32, s32*);

f32 get_xz_dist_to_player(f32, f32);
void func_800E06C0(s32);
void close_status_menu(void);
void btl_state_update_switch_to_partner(s32);

Shadow* create_shadow_type(s32 type, f32 x, f32 y, f32 z);
s32 is_point_within_region(s32 shape, f32 pointX, f32 pointY, f32 centerX, f32 centerY, f32 sizeX, f32 sizeZ);
PlayerData* get_player_data(void);

// Pause
s32 pause_interp_vertical_scroll(s32 deltaBefore);
void pause_draw_rect(s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tileDescriptor, s32 uls, s32 ult, s32 dsdx, s32 dtdy);

s32 npc_raycast_down_ahead(s32, f32*, f32*, f32*, f32*, f32, f32);
s32 npc_raycast_down_sides(s32, f32*, f32*, f32*, f32*);
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
s32 does_script_exist_by_ref(ScriptInstance* script);
ScriptInstance* start_script(Script* source, s32 priority, s32 initialState);
ScriptInstance* start_script_in_group(Script* source, u8 priority, u8 initialState, u8 groupFlags);

void set_animation_rate(ActorID actorID, s32 partIndex, f32 rate);
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
f32 update_lerp(Easing easing, f32 start, f32 end, s32 elapsed, s32 duration);
void sin_cos_deg(f32 rad, f32* outSinTheta, f32* outCosTheta);

void enable_world_fog(void);
void set_world_fog_dist(s32 start, s32 end);
void set_world_fog_color(s32 r, s32 g, s32 b, s32 a);

ModelTransformGroup* get_transform_group(s32 index);

s32 make_item_entity(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 facingAngleSign,
                     s32 pickupVar);
s32 make_item_entity_delayed(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 pickupVar);
void set_item_entity_position(s32 itemEntityIndex, f32 x, f32 y, f32 z);
ItemEntity* get_item_entity(s32 itemEntityIndex);
s32 make_item_entity_nodelay(s32 itemID, f32 x, f32 y, f32 z, ItemSpawnMode itemSpawnMode, s32 pickupVar);
void set_item_entity_flags(s32 itemEntityIndex, s32 flag);

s32 create_generic_entity_frontUI(void (*updateFunc)(void), void (*drawFunc)(void));
DynamicEntity* get_generic_entity(s32 idx);

void set_cam_viewport(s16 id, s16 x, s16 y, s16 width, s16 height);

void disable_player_shadow(void);
void move_player(s32 duration, f32 heading, f32 speed);
s32 enable_player_input(void);

Npc* get_npc_safe(NpcID npcId);
Npc* get_npc_unsafe(NpcID npcId);
Npc* resolve_npc(ScriptInstance* script, NpcID npcIdOrPtr);
void set_npc_yaw(Npc* npcPtr, f32 angle);
void npc_move_heading(Npc* npc, f32 speed, f32 yaw);
void disable_npc_blur(Npc* npc);

f32 dist2D(f32 ax, f32 ay, f32 bx, f32 by);
f32 dist3D(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz);
void add_vec2D_polar(f32* x, f32* y, f32 r, f32 theta);

s32 sfx_adjust_env_sound_pos(s32 soundID, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 sfx_play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);
s32 bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume);
void func_801497FC(s32 arg0);
s32 func_8014AA54(s32 playerIndex, s32 arg1, s16 arg2);

s32 basic_window_update(void);
s32 basic_hidden_window_update(void);

void player_create_target_list(Actor* actor);
void enemy_create_target_list(Actor* actor);

void set_actor_yaw(ActorID actorID, s32 yaw);
void set_part_yaw(ActorID actorID, s32 partIndex, s32 value);

ActorPart* get_actor_part(Actor* actor, s32 partIndex);

void add_part_decoration(ActorPart* part, s32 decorationIndex, DecorationID decorationType);
void add_actor_decoration(Actor* actor, s32 decorationIndex, DecorationID decorationType);
void remove_part_decoration(ActorPart* part, s32 decorationIndex);
void remove_actor_decoration(Actor* actor, s32 decorationIndex);

s32 player_team_is_ability_active(Actor* actor, Ability ability);

void create_part_shadow(ActorID actorID, s32 partIndex);
void remove_part_shadow(ActorID actorID, s32 partIndex);
void create_part_shadow_by_ref(UNK_TYPE arg0, ActorPart* part); // arg0 unused

ScriptInstance* get_script_by_index(s32 index);

void set_action_state(s32 actionState);
s32 get_collider_type_by_id(s32 colliderID);
void suggest_player_anim_setUnkFlag(s32 arg0);
void subtract_hp(s32 amt);
void open_status_menu_long(void);

void suspend_all_group(s32 groupFlags);
void kill_script(ScriptInstance* instanceToKill);
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
void state_drawUI_enter_world(void);
void state_init_change_map(void);
void state_step_change_map(void);
void state_drawUI_change_map(void);
void func_80036430(void);
void func_8003646C(void);
void func_80036640(void);
void state_init_enter_world(void);
void state_step_enter_world(void);
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

// Effect funcs
void playFX_01(f32, f32, f32);
void playFX_11(s32, f32, f32, f32, f32);
void playFX_18(s32, f32, f32, f32, f32, f32, f32, s32);
void playFX_3D(s32 var1, f32 var2, f32 var3, f32 var4, f32 var5, f32 var6, f32 var7, s32 var8, s32* unk);
EffectInstance* playFX_40(s32, f32, f32, f32, s32);
EffectInstance* playFX_52(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_6B(s32, f32, f32, f32, f32, s32);
//EffectInstance* playFX_82(s32, f32, f32, f32, f32, s32 time);
EffectInstance* playFX_4E(s32, f32, f32, f32);
EffectInstance* playFX_54(s32, f32, f32, f32);
EffectInstance* playFX_80(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_51(s32, f32, f32, f32, f32, s32);
void playFX_50(s32, f32, f32, f32);
EffectInstance* playFX_3F(s32 a0, f32 a1, f32 a2, f32 a3, s32 a4);
EffectInstance* playFX_36(s32, f32, f32, f32, f32, f32);
EffectInstance* playFX_83(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
EffectInstance* playFX_7B(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void playFX_32(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
EffectInstance* playFX_56(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void playFX_33(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
EffectInstance* playFX_69(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void playFX_2D(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5);
void playFX_2E(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void playFX_17(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
void playFX_19(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
void playFX_1D(s32, f32, f32, f32, f32, s32, f32, s32);
void fx_sweat(s32, f32, f32, f32, f32, f32, s32);
void playFX_2F(s32, f32, f32, f32, f32, s32, EffectInstanceData**);
void playFX_3B(s32, f32, f32, f32, f32, EffectInstanceData**);
void fx_land(s32, f32, f32, f32, f32);
EffectInstance* playFX_6F(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_72(s32, f32, f32, f32, f32, f32, f32, s32, s32);
void playFX_26(s32, f32, f32, f32);

void func_802B2078(void);
extern f32 gCurtainScale;
extern f32 gCurtainScaleGoal;
extern f32 gCurtainFade;
extern f32 gCurtainFadeGoal;
extern UNK_FUN_PTR(gCurtainDrawCallback);
void spr_update_player_sprite(s32, s32, f32);

void initialize_curtains(void);
void update_curtains(void);
// render_curtains
void set_curtain_scale_goal(f32 scale);
void set_curtain_scale(f32 scale);
void set_curtain_draw_callback(UNK_FUN_PTR(callback));
void set_curtain_fade_goal(f32 fade);
void set_curtain_fade(f32 fade);

// Dead functions:
Npc* func_8003E4BC(NpcID npcId); // get_npc_safe
Npc* func_8003E534(NpcID npcId); // get_npc_safe
void func_80077BD0(s32, s32, s32, s32, s32, s32);

void dead_playFX_11(s32, f32, f32, f32, f32);
s32 dead_get_variable(ScriptInstance* script, Bytecode var);
f32 dead_get_float_variable(ScriptInstance* script, Bytecode var);
s32 dead_set_variable(ScriptInstance* script, Bytecode var, s32 value);
f32 dead_set_float_variable(ScriptInstance* script, Bytecode var, f32 value);

f32 dead_cos_rad(f32 x);
f32 dead_atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);

s32 create_generic_entity_world(void (*updateFunc)(void), void (*drawFunc)(void));
EntityModel* get_entity_model(s32 idx);
f32 phys_get_spin_history(s32 lag, s32* x, s32* y, s32* z);

void sfx_get_spatialized_sound_params(f32 arg0, f32 arg1, f32 arg2, s16* arg3, s16* arg4, s32 arg5);
void sfx_play_sound_with_params(s32 arg0, u8 arg1, u8 arg2, s16 arg3);
void func_8004A784(Npc* npc, f32 arg1, f32* arg2, s32* arg3, s32* arg4, s32* arg5);
void base_UnkNpcAIFunc1(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory);

s32* spr_get_npc_palettes(u16 arg0);
void spr_draw_player_sprite(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void spr_draw_npc_sprite(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Matrix4f* arg4);
void guRotateRPYF(float mf[4][4], f32 x, f32 y, f32 z);
s32 spr_update_sprite(s32 arg0, s32 arg1, f32 arg2);
s32 npc_raycast_down_ahead(s32, f32*, f32*, f32*, f32*, f32, f32);
void sin_cos_rad(f32 rad, f32* outSinTheta, f32* outCosTheta);
void playFX_08(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void playFX_09(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

void* load_asset_by_name(const char* assetName, u32* decompressedSize);

#endif
