#ifndef _EFFECTS_INTERNAL_H_
#define _EFFECTS_INTERNAL_H_

#include "effects.h"

s32 func_E0200000(s32);

EffectInstance* shim_create_effect_instance(EffectBlueprint* effectBp);
void shim_remove_effect(EffectInstance*);
s32 shim_rand_int(s32);
void* shim_general_heap_malloc(s32 size);
RenderTask* shim_queue_render_task(RenderTask* task);
f32 shim_sin_deg(f32 x);
f32 shim_cos_deg(f32 x);
f32 shim_clamp_angle(f32 theta);
void shim_guMtxF2L(float mf[4][4], Mtx *m);
void shim_guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);
void shim_guScaleF(float mf[4][4], float x, float y, float z);
void shim_guRotateF(float mf[4][4], float a, float x, float y, float z);
void shim_guTranslateF(float mf[4][4], float x, float y, float z);
void shim_guPositionF(float mf[4][4], float r, float p, float h, float s, float x, float y, float z);
void shim_mem_clear(s8* data, s32 numBytes);
void shim_transform_point(Matrix4f mtx, f32 inX, f32 inY, f32 inZ, f32 inS, f32* outX, f32* outY, f32* outZ, f32* outS);
    
#endif
