#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common_structs.h"
#include "enums.h"

void osCleanupThread(void);

void clone_model(u16 srcModelID, u16 newModelID);
void update_collider_transform(s16 colliderID);
s32 get_variable(Script* script, bytecode var);
s32 set_variable(Script* script, bytecode var, s32 value);
f32 get_float_variable(Script* script, bytecode var);
f32 set_float_variable(Script* script, bytecode var, f32 value);
void set_script_timescale(Script* script, f32 timescale);
f32 sin_deg(f32 x);
f32 cos_deg(f32 x);
f32 atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);
f32 clamp_angle(f32 theta);
s32 func_80055448(s32);
s32 func_80055464(s32, s32);
s32 func_800554A4(s32, s32);
s32 func_800554E8(s32, s32);
s32 func_800555E4(s32);
void func_80137D88(s32, f32);
void func_80137DA4(s32, f32);
void func_80137E10(s32, u8, u8, u8);
void func_80137E4C(s32, s32, s32, s32);
s32 rand_int(s32);
void sort_items(void);
s32 is_ability_active(s32 arg0);
f32 update_lerp(EASING easing, f32 start, f32 end, s32 elapsed, s32 duration);

Npc* get_npc_safe(s32 npcID);
Npc* get_npc_unsafe(s32 npcID);
Npc* resolve_npc(Script* script, NPC npcID);

f32 dist2D(f32 ax, f32 ay, f32 bx, f32 by);
f32 dist3D(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz);
void add_vec2D_polar(f32* x, f32* y, f32 r, f32 theta);

s32 play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);
s32 set_music_track(s32 musicPlayer, s32 songID, s32 variation, s32 unk, s32 volume);
#endif
