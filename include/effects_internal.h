#ifndef _EFFECTS_INTERNAL_H_
#define _EFFECTS_INTERNAL_H_

#include "effects.h"

s32 func_E0200000(s32);

EffectInstance* shim_create_effect_instance(EffectBlueprint* effectBp);
s32 shim_load_effect(s32 effectIndex);
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
s32 shim_npc_raycast_down_sides(s32, f32*, f32*, f32*, f32*);
void shim_sfx_play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);

#define FX_MAIN(name) void name(s32); // the actual signature is going to be wrong but doesn't matter

void big_smoke_puff_main(f32 x, f32 y, f32 z);
void landing_dust_main(s32 type, f32 x, f32 y, f32 z, f32);
void walking_dust_main(s32, f32, f32, f32, f32, f32);
void flower_splash_main(f32, f32, f32, f32);
void flower_trail_main(s32, f32, f32, f32, f32, f32);
void cloud_puff_main(f32, f32, f32, f32);
void fx_11_main(s32, f32, f32, f32);
void fx_12_main(f32, f32, f32, f32, f32, f32, f32, f32);
void fx_13_main(s32, f32, f32, f32, s32);
void fx_14_main(f32, f32, f32, s32, s32);
EffectInstance* fx_15_main(s32, f32, f32, f32, f32, f32, f32, f32);
void fx_16_main(s32, s32, f32, f32, f32, f32, f32, s32, EffectInstance**);
FX_MAIN(fx_17_main);
FX_MAIN(fx_18_main);
FX_MAIN(fx_19_main);
FX_MAIN(fx_20_main);
FX_MAIN(fx_21_main);
FX_MAIN(fx_22_main);
FX_MAIN(fx_23_main);
FX_MAIN(fx_24_main);
FX_MAIN(fx_25_main);
FX_MAIN(fx_26_main);
FX_MAIN(fx_27_main);
FX_MAIN(fx_28_main);
FX_MAIN(fx_29_main);
FX_MAIN(fx_30_main);
FX_MAIN(fx_31_main);
FX_MAIN(fx_32_main);
FX_MAIN(fx_33_main);
FX_MAIN(fx_34_main);
FX_MAIN(fx_35_main);
FX_MAIN(fx_36_main);
FX_MAIN(fx_37_main);
FX_MAIN(fx_38_main);
FX_MAIN(fx_39_main);
FX_MAIN(fx_40_main);
FX_MAIN(fx_41_main);
FX_MAIN(fx_43_main);
FX_MAIN(fx_44_main);
FX_MAIN(fx_45_main);
FX_MAIN(fx_46_main);
FX_MAIN(fx_47_main);
FX_MAIN(fx_48_main);
FX_MAIN(fx_49_main);
FX_MAIN(fx_50_main);
FX_MAIN(fx_51_main);
FX_MAIN(fx_52_main);
FX_MAIN(fx_53_main);
FX_MAIN(fx_54_main);
FX_MAIN(fx_55_main);
FX_MAIN(fx_56_main);
FX_MAIN(fx_57_main);
FX_MAIN(fx_58_main);
FX_MAIN(fx_59_main);
FX_MAIN(fx_60_main);
FX_MAIN(fx_61_main);
FX_MAIN(fx_62_main);
FX_MAIN(fx_63_main);
FX_MAIN(fx_64_main);
FX_MAIN(fx_65_main);
FX_MAIN(fx_66_main);
FX_MAIN(fx_67_main);
FX_MAIN(fx_68_main);
FX_MAIN(fx_69_main);
FX_MAIN(fx_70_main);
FX_MAIN(fx_71_main);
FX_MAIN(fx_72_main);
EffectInstance* fx_73_main(EffectInstanceDataThing*, f32, f32, f32, f32);
FX_MAIN(fx_74_main);
EffectInstance* fx_75_main(s32, f32, f32, f32, f32, s32);
FX_MAIN(fx_76_main);
FX_MAIN(fx_77_main);
FX_MAIN(fx_78_main);
FX_MAIN(fx_79_main);
FX_MAIN(fx_80_main);
FX_MAIN(fx_81_main);
FX_MAIN(fx_82_main);
FX_MAIN(fx_83_main);
FX_MAIN(fx_84_main);
FX_MAIN(fx_85_main);
FX_MAIN(fx_86_main);
FX_MAIN(fx_87_main);
FX_MAIN(fx_88_main);
FX_MAIN(fx_89_main);
FX_MAIN(fx_90_main);
FX_MAIN(fx_91_main);
FX_MAIN(fx_92_main);
FX_MAIN(fx_93_main);
FX_MAIN(fx_94_main);
FX_MAIN(fx_95_main);
FX_MAIN(fx_96_main);
FX_MAIN(fx_97_main);
FX_MAIN(fx_98_main);
FX_MAIN(fx_99_main);
FX_MAIN(fx_100_main);
FX_MAIN(fx_101_main);
FX_MAIN(fx_102_main);
FX_MAIN(fx_103_main);
FX_MAIN(fx_104_main);
FX_MAIN(fx_105_main);
FX_MAIN(fx_107_main);
FX_MAIN(fx_108_main);
FX_MAIN(fx_109_main);
FX_MAIN(fx_110_main);
FX_MAIN(fx_111_main);
FX_MAIN(fx_112_main);
FX_MAIN(fx_113_main);
FX_MAIN(fx_114_main);
FX_MAIN(fx_115_main);
FX_MAIN(fx_116_main);
FX_MAIN(fx_117_main);
FX_MAIN(fx_119_main);
FX_MAIN(fx_120_main);
FX_MAIN(fx_121_main);
FX_MAIN(fx_122_main);
FX_MAIN(fx_123_main);
FX_MAIN(fx_124_main);
FX_MAIN(fx_125_main);
FX_MAIN(fx_126_main);
FX_MAIN(fx_127_main);
FX_MAIN(fx_128_main);
FX_MAIN(fx_129_main);
FX_MAIN(fx_130_main);
FX_MAIN(fx_131_main);
FX_MAIN(fx_132_main);
FX_MAIN(fx_133_main);
EffectInstance* fx_134_main(s32, f32, f32, f32, f32, s32);

#endif
