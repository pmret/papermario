#ifndef _EFFECTS_INTERNAL_H_
#define _EFFECTS_INTERNAL_H_

#include "effects.h"

// Used by effects 8 and 9 (TODO: better name)
typedef struct Effect8 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 primAlpha;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ char unk_0A[0x2];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ Mtx unk_30;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ f32 unk_78;
    /* 0x7C */ f32 unk_7C;
    /* 0x80 */ f32 unk_80;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ f32 unk_8C;
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
} Effect8; // size = 0x98


u32 func_E0200000(s32);

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

#endif
