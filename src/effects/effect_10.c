#include "common.h"
#include "effects_internal.h"

void fx_10_init(EffectInstance* effect);
void fx_10_update(EffectInstance* effect);
void fx_10_render(EffectInstance* effect);
void fx_10_appendGfx(EffectInstance* effect);

typedef struct Effect10 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x2];
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char unk_09[0x3];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ u32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
} Effect10; // size = 0x4C

// void fx_10_main(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
//     EffectBlueprint bp;
//     EffectInstance* effect;
//     f32 temp_f20;
//     Effect10* part;
//     s32 numParts = 8;
//     s32 i;
//     s32 b;

//     bp.init = fx_10_init;
//     bp.update = fx_10_update;
//     bp.renderWorld = fx_10_render;
//     bp.unk_00 = 0;
//     bp.unk_14 = NULL;
//     bp.effectIndex = 10;

//     effect = shim_create_effect_instance(&bp);
//     effect->numParts = numParts;
//     part = shim_general_heap_malloc(numParts * sizeof(*part));
//     effect->data = part;
//     ASSERT(effect->data != NULL);

//     shim_mem_clear(part, numParts * sizeof(*part));

//     for (i = 0, ; i < numParts; i++, part++, b += 45) {
//         part->unk_00 = 1;
//         part->unk_40 = 0;
//         part->unk_0C = arg0;
//         part->unk_10 = arg1;
//         part->unk_14 = arg2;
//         part->unk_18 = 1.0f;
//         part->unk_1C = 1.0f;
//         part->unk_20 = 1.0f;
//         part->unk_08 = 0xFF;
//         part->unk_24 = (shim_rand_int(10) * 0.03) + 1.0;
//         part->unk_28 = (shim_rand_int(10) * 0.03) + 1.7;
//         part->unk_2C = func_E0200000(60);
//         part->unk_06 = 30;
//         part->unk_34 = 0.5f;
//         part->unk_38 = -0.02f;
//         part->unk_3C = 0.00005f;
//         part->unk_30 = -3.9f;
//         temp_f20 = shim_clamp_angle(arg3 + b);
//         part->unk_44 = shim_sin_deg(temp_f20);
//         part->unk_48 = shim_cos_deg(temp_f20);
//     }
// }
INCLUDE_ASM(s32, "effects/effect_10", fx_10_main);

void fx_10_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/effect_10", fx_10_update);

void fx_10_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_10_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_10", fx_10_appendGfx);
