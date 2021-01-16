#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common_structs.h"
#include "enums.h"


void nuBoot(void);
void boot_idle(void);
void boot_main(void);

void osCleanupThread(void);

void func_80070A90(s32, f32, f32, f32);
void func_80070AF0(s32, f32, f32, f32);

s32 heap_malloc(s32 size);
HeapNode* _heap_create(void* addr, s32 size);
s32 dma_copy(s32 romStart, s32 romEnd, void* vramDest);

s32 get_global_byte(s32 index);
s32 get_global_flag(s32 index);
s32 get_area_byte(s32 index);
s32 get_area_flag(s32 index);

Shadow* get_shadow_by_index(s32 index);

void render_player_model();

f32 integrate_gravity(void);
f32 get_clamped_angle_diff(f32, f32);

u32 get_entity_type(s32 arg0);
Entity* get_entity_by_index(s32 index);
s32 create_entity(StaticEntityData*, s32, s32, s32, s32, s32);
void func_80070550(s32, f32, f32, f32, f32, f32, s32, s32);
void func_802E263C(Entity* entity);

UNK_TYPE func_80072230(s32, f32, f32, f32, f32, s32);

// Text
PrintContext* load_string(s32 stringID, s32* a1);
void get_screen_coords(Cam camID, f32 x, f32 y, f32 z, f32* outX, f32* outY, f32* outZ);

void parent_collider_to_model(s32 colliderID, s16 modelIndex);
void clone_model(u16 srcModelID, u16 newModelID);
Model* get_model_from_list_index(s32 listIndex);
s32 get_model_list_index_from_tree_index(s32 treeIndex);
void get_model_center_and_size(s32 modelID, f32* centerX, f32* centerY, f32* centerZ, f32* sizeX, f32* sizeY,
                               f32* sizeZ);

void func_80027088(s32);

void func_8006FEF0(s32, f32, f32, f32, f32);
void func_80071090(s32, f32, f32, f32, s32);
void func_80071750(s32, f32, f32, f32, f32, s32);
void func_800720B0(s32, f32, f32, f32, f32, s32);
void func_80072950(s32, f32, f32, f32, f32, s32 time);

void update_collider_transform(s16 colliderID);
void get_collider_center(s32 colliderID, f32* x, f32* y, f32* z);

s32 is_trigger_bound(Trigger*, Bytecode* script);
Trigger* create_trigger(TriggerDefinition* def);
s32 _bound_script_trigger_handler(Trigger* trigger);
Trigger* get_trigger_by_id(s32 triggerID);

Actor* get_actor(ActorID actorID);
ActorPart* get_actor_part(Actor* actor, s32 partIndex);

s32 func_800494C0(Npc* npc, s32 arg1, s32 arg2);

s32 get_variable(ScriptInstance* script, Bytecode var);
s32 set_variable(ScriptInstance* script, Bytecode var, s32 value);
f32 get_float_variable(ScriptInstance* script, Bytecode var);
f32 set_float_variable(ScriptInstance* script, Bytecode var, f32 value);
void set_script_timescale(ScriptInstance* script, f32 timescale);
f32 sin_deg(f32 x);
f32 cos_deg(f32 x);
f32 sin_rad(f32 x);
f32 cos_rad(f32 x);
s16 round(f32);
f32 atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);
f32 clamp_angle(f32 theta);
s32 sign(s32 value);
s32 func_80055448(s32);
s32 func_80055464(s32, s32);
void func_800561A4(s32);
s32 osGetId();

void set_curtain_scale_goal(f32 scale);
void set_curtain_fade(f32 scale);

void fx_walk_normal(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5);
void fx_emote(s32, Npc*, f32, f32, f32, f32, f32, s32, s32*);

f32 func_800E0088(f32, f32);
void func_800E06C0(s32);
void func_800E97B8(void);
s32 func_800EB168(s32);

Shadow* create_shadow_type(s32 type, f32 x, f32 y, f32 z);

PlayerData* get_player_data(void);

// Pause
s32 pause_interp_vertical_scroll(s32 deltaBefore);
void pause_draw_rect(s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tileDescriptor, s32 uls, s32 ult, s32 dsdx, s32 dtdy);

s32 func_800DCB7C(s32, f32*, f32*, f32*, f32*);
s32 func_800DDC44(s32, f32*, f32*, f32*, f32, f32, f32, f32);

Npc* get_npc_by_index(s32 listIndex);

// Partner
void func_800EBA3C(Npc* partner);
void func_800EBB40(Npc* partner);
void enable_partner_ai(void);
void enable_partner_walking(Npc* partner, s32 val);
void enable_partner_flying(Npc* partner, s32 val);
void update_player_move_history(Npc* partner);
s32 is_current_partner_flying(void);
void func_800ED5D0(Npc* partner);
void clear_partner_move_history(Npc* partner);

s32 func_800EF394(f32);
s32 does_script_exist(s32 id);
s32 does_script_exist_by_ref(ScriptInstance* script);
ScriptInstance* start_script(Bytecode* initialLine, s32 priority, s32 initialState);
ScriptInstance* start_script_in_group(Bytecode* initialLine, u8 priority, u8 initialState, u8 groupFlags);

void set_animation_rate(ActorID actorID, s32 partIndex, f32 rate);
void func_8011B7C0(u16, s32, s32);
AnimatedMesh* get_anim_mesh(s32 arg0);
void func_80137D88(s32, f32);
void func_80137DA4(s32, f32);
void func_80137DC0(s32, f32*, f32*);
s32 func_80137E10(s32, u8, u8, u8);
void func_80137E4C(s32, s32, s32, s32);
s32 rand_int(s32);
void sort_items(void);
s32 is_ability_active(s32 arg0);
f32 update_lerp(Easing easing, f32 start, f32 end, s32 elapsed, s32 duration);

s32 make_item_entity(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 facingAngleSign,
                     s32 pickupVar);
s32 make_item_entity_delayed(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 pickupVar);
void set_item_entity_position(s32 itemEntityIndex, f32 x, f32 y, f32 z);
ItemEntity* get_item_entity(s32 itemEntityIndex);
s32 make_item_entity_nodelay(s32 itemID, f32 x, f32 y, f32 z, ItemSpawnMode itemSpawnMode, s32 pickupVar);
void set_item_entity_flags(s32 itemEntityIndex, s32 flag);

void set_cam_viewport(s16 id, s16 x, s16 y, s16 width, s16 height);

void disable_player_shadow(void);
void move_player(s32 duration, f32 heading, f32 speed);

Npc* get_npc_safe(NpcId npcId);
Npc* get_npc_unsafe(NpcId npcId);
Npc* resolve_npc(ScriptInstance* script, NpcId npcIdOrPtr);
void set_npc_yaw(Npc* npcPtr, f32 angle);
void npc_move_heading(Npc* npc, f32 speed, f32 yaw);
void disable_npc_blur(Npc* npc);

f32 dist2D(f32 ax, f32 ay, f32 bx, f32 by);
f32 dist3D(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz);
void add_vec2D_polar(f32* x, f32* y, f32 r, f32 theta);

s32 func_801499EC(s32 soundID, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);
s32 set_music_track(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume);
s32 func_8014AA54(s32 playerIndex, s32 arg1, s16 arg2);

void player_create_target_list(Actor* actor);
void enemy_create_target_list(Actor* actor);

void set_actor_yaw(ActorID actorID, s32 yaw);
void set_part_yaw(ActorID actorID, s32 partIndex, s32 value);

ActorPart* get_actor_part(Actor* actor, s32 partIndex);

void add_part_decoration(ActorPart* part, s32 decorationIndex, DecorationId decorationType);
void add_actor_decoration(Actor* actor, s32 decorationIndex, DecorationId decorationType);
void remove_part_decoration(ActorPart* part, s32 decorationIndex);
void remove_actor_decoration(Actor* actor, s32 decorationIndex);

s32 heroes_is_ability_active(Actor* actor, Ability ability);

void create_part_shadow(ActorID actorID, s32 partIndex);
void remove_part_shadow(ActorID actorID, s32 partIndex);
void create_part_shadow_by_ref(UNK_TYPE arg0, ActorPart* part); // arg0 unused

ScriptInstance* get_script_by_index(s32 index);

void suspend_all_group(s32 groupFlags);
void kill_script(ScriptInstance* instanceToKill);
void func_8010FD68(Entity* entity);

void func_802D7460(f32 x, f32 y, f32 z, s32 arg3);
void func_802D74C0(f32 x, f32 y, f32 z, s32 arg3);

#endif
