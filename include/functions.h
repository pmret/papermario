#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common_structs.h"
#include "enums.h"

void osCleanupThread(void);

s32 heap_malloc(s32 size);
HeapNode* _heap_create(void* addr, s32 size);

s32 get_global_byte(s32 index);
s32 get_global_flag(s32 index);
s32 get_area_byte(s32 index);
s32 get_area_flag(s32 index);

Shadow* get_shadow_by_index(s32 index);

void render_player_model();

f32 integrate_gravity(void);

void parent_collider_to_model(s32 colliderID, s16 modelIndex);
void clone_model(u16 srcModelID, u16 newModelID);
Model* get_model_from_list_index(s32 listIndex);
s32 get_model_list_index_from_tree_index(s32 treeIndex);
void get_model_center_and_size(s32 modelID, f32* centerX, f32* centerY, f32* centerZ, f32* sizeX, f32* sizeY,
                               f32* sizeZ);

void update_collider_transform(s16 colliderID);
void get_collider_center(s32 colliderID, f32* x, f32* y, f32* z);

s32 is_trigger_bound(Trigger*, Bytecode* script);
Trigger* create_trigger(TriggerDefinition* def);
s32 _bound_script_trigger_handler(Trigger* trigger);


s32 func_800494C0(Npc* npc, s32 arg1, s32 arg2);

s32 get_variable(ScriptInstance* script, Bytecode var);
s32 set_variable(ScriptInstance* script, Bytecode var, s32 value);
f32 get_float_variable(ScriptInstance* script, Bytecode var);
f32 set_float_variable(ScriptInstance* script, Bytecode var, f32 value);
void set_script_timescale(ScriptInstance* script, f32 timescale);
f32 sin_deg(f32 x);
f32 cos_deg(f32 x);
f32 atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);
f32 clamp_angle(f32 theta);
s32 func_80055448(s32);
s32 func_80055464(s32, s32);
s32 func_800554A4(s32, s32);
s32 func_800554E8(s32, s32);
s32 func_800555E4(s32);
s32 osGetId();

s32 func_800EF394(f32);
s32 does_script_exist(s32 id);
ScriptInstance* start_script(Bytecode* script, s32 priority, s32 flags);
ScriptInstance* start_script_in_group(ScriptInstance* script, s32 priority, s32 flags, s32 groups);

void func_8011B7C0(u16, s32, s32);
void func_80137D88(s32, f32);
void func_80137DA4(s32, f32);
s32 func_80137E10(s32, u8, u8, u8);
void func_80137E4C(s32, s32, s32, s32);
s32 rand_int(s32);
void sort_items(void);
s32 is_ability_active(s32 arg0);
f32 update_lerp(Easing easing, f32 start, f32 end, s32 elapsed, s32 duration);

void make_item_entity_delayed(s32 itemID, f32 x, f32 y, f32 z, s32 unk1, s32 unk2, s32 unk3);

void set_cam_viewport(s16 id, s16 x, s16 y, s16 width, s16 height);

void disable_player_shadow(void);

Npc* get_npc_safe(NpcId npcId);
Npc* get_npc_unsafe(NpcId npcId);
Npc* resolve_npc(ScriptInstance* script, NpcId npcIdOrPtr);
void set_npc_yaw(Npc* npcPtr, f32 angle);

Enemy* get_enemy(NpcId npcId);

f32 dist2D(f32 ax, f32 ay, f32 bx, f32 by);
f32 dist3D(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz);
void add_vec2D_polar(f32* x, f32* y, f32 r, f32 theta);

s32 play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);
s32 set_music_track(s32 musicPlayer, s32 songID, s32 variation, s32 unk, s32 volume);

ScriptInstance* get_script_by_index(s32 index);

#endif
