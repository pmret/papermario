#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common_structs.h"
#include "enums.h"

void osCleanupThread(void);

void clone_model(u16 srcModelID, u16 newModelID);
void update_collider_transform(s16 colliderID);
s32 get_variable(script_context* script, s32 var);
s32 set_variable(script_context* script, s32 var, s32 value);
f32 get_float_variable(script_context* script, s32 var);
f32 set_float_variable(script_context* script, s32 var, f32 value);
void set_script_timescale(script_context* script, f32 timescale);
f32 sin_deg(f32 x);
f32 cos_deg(f32 x);
f32 atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);
s32 func_80055448(s32);
s32 func_80055464(s32, s32);
s32 func_800554A4(s32, s32);
s32 func_800554E8(s32, s32);
s32 func_800555E4(s32);
void func_80137D88(s32, f32);
void func_80137E10(s32, u8, u8, u8);
s32 rand_int(s32);
void sort_items(void);
s32 is_ability_active(s32 arg0);
f32 update_lerp(EASING easing, f32 start, f32 end, s32 elapsed, s32 duration);

npc* get_npc_safe(NPC npcID);
npc* get_npc_unsafe(NPC npcID);
npc* resolve_npc(script_context* script, NPC npcID);

s32 play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);
s32 set_music_track(s32 musicPlayer, s32 songID, s32 variation, s32 unk, s32 volume);
#endif
