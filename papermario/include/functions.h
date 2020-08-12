#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common_structs.h"

void osCleanupThread(void);

void clone_model(u16 srcModelID, u16 newModelID);
void update_collider_transform(s16 colliderID);
s32 get_variable(script_context* script, s32 pos);
f32 get_float_variable(script_context* script, s32 pos);
f32 sin_deg(f32 x);
f32 cos_deg(f32 x);
s32 func_80055448(s32);
s32 func_80055464(s32, s32);
s32 func_800554A4(s32, s32);
s32 func_800554E8(s32, s32);
s32 func_800555E4(s32);

#endif
