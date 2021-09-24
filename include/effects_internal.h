#ifndef _EFFECT_INTERNAL_H_
#define _EFFECT_INTERNAL_H_

#include "effects.h"

u32 func_E0200000(s32);

EffectInstance* shim_create_effect_instance(EffectBlueprint* effectBp);
void shim_remove_effect(EffectInstance*);
void* shim_general_heap_malloc(s32 size);
RenderTask* shim_queue_render_task(RenderTask* task);
f32 shim_sin_deg(f32 x);
f32 shim_cos_deg(f32 x);
f32 shim_clamp_angle(f32 theta);
void shim_guMtxF2L(float mf[4][4], Mtx *m);
void shim_guPositionF(float mf[4][4], float r, float p, float h, float s, float x, float y, float z);
void shim_mem_clear(s8* data, s32 numBytes);

#endif
