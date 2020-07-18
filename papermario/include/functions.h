#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common_structs.h"

s32 get_variable(ScriptContext* script, s32 pos);
f32 get_float_variable(ScriptContext* script, s32 pos);
f32 sin_deg(f32 x);
f32 cos_deg(f32 x);

#endif
