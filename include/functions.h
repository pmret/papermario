#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common_structs.h"

void osCleanupThread(void);

void clone_model(u16 srcModelID, u16 newModelID);
void update_collider_transform(s16 colliderID);
s32 get_variable(script_context* script, s32 pos);
f32 get_float_variable(script_context* script, s32 pos);
f32 set_float_variable(script_context* script, s32 dest, f32 value);
void set_script_timescale(script_context* script, f32 timescale);
f32 sin_deg(f32 x);
f32 cos_deg(f32 x);
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

s32 play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);
s32 set_music_track(s32 musicPlayer, s32 songID, s32 variation, s32 unk, s32 volume);
#endif
