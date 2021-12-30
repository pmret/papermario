#ifndef _EFFECTS_INTERNAL_H_
#define _EFFECTS_INTERNAL_H_

#include "effects.h"

s32 func_E0200000(s32);

EffectInstance* shim_create_effect_instance(EffectBlueprint* effectBp);
void shim_remove_effect(EffectInstance*);
s32 shim_rand_int(s32);
void* shim_general_heap_malloc(s32 size);
RenderTask* shim_queue_render_task(RenderTask* task);
float shim_sqrtf(float value);
f32 shim_atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);
f32 shim_sin_deg(f32 x);
f32 shim_cos_deg(f32 x);
f32 shim_clamp_angle(f32 theta);
void shim_get_background_color_blend(u8* r, u8* g, u8* b, u8* a);
void shim_guMtxF2L(float mf[4][4], Mtx *m);
void shim_guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);
void shim_guScaleF(float mf[4][4], float x, float y, float z);
void shim_guRotateF(float mf[4][4], float a, float x, float y, float z);
void shim_guTranslate(Mtx *m, float x, float y, float z);
void shim_guTranslateF(float mf[4][4], float x, float y, float z);
void shim_guPositionF(float mf[4][4], float r, float p, float h, float s, float x, float y, float z);
void shim_mem_clear(void* data, s32 numBytes);
void shim_transform_point(Matrix4f mtx, f32 inX, f32 inY, f32 inZ, f32 inS, f32* outX, f32* outY, f32* outZ, f32* outS);

s32 shim_load_effect(s32 effectIndex);

s32 shim_npc_raycast_down_sides(s32, f32*, f32*, f32*, f32*);
void shim_sfx_play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);

void fx_6_main(s32 type, f32 x, f32 y, f32 z, f32 arg4);

#endif
