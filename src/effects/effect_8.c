#include "common.h"
#include "effects_internal.h"

typedef struct Effect8 {
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
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ char unk_30[0x40];
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

void fx_8_init(EffectInstance* effect);
void fx_8_update(EffectInstance* effect);
void fx_8_render(EffectInstance* effect);
void fx_8_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_8", func_E0010000);

INCLUDE_ASM(s32, "effects/effect_8", func_E0010104);

void fx_8_main(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect8* part;
    s32 numParts = 5;
    f32 angle;
    s32 i;

    bp.init = fx_8_init;
    bp.update = fx_8_update;
    bp.renderWorld = fx_8_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectIndex = 8;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data = part;
    ASSERT(effect->data != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->unk_00 = 1;
        part->unk_28 = arg3 + (i * 72);
        part->unk_74 = 0.29999998f;
        part->unk_78 = 0.0f;
        part->unk_7C = 0.0f;
        part->unk_0C = arg0;
        part->unk_10 = arg1;
        part->unk_14 = arg2;
        part->unk_18 = 1.0f;
        part->unk_1C = 1.0f;
        part->unk_20 = 1.0f;
        part->unk_08 = -1;
        part->unk_06 = 60;
        part->unk_24 = 0;
        part->unk_2C = 0;
        part->unk_80 = 1.75f;
        part->unk_84 = -0.08f;
        part->unk_70 = -3.9f;
        part->unk_88 = 0;
        part->unk_8C = 0;
        angle = shim_clamp_angle(part->unk_28);
        part->unk_90 = shim_sin_deg(angle);
        part->unk_94 = shim_cos_deg(angle);
    }
}

void fx_8_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/effect_8", fx_8_update);

void fx_8_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_8_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_8", func_E00104F4);

INCLUDE_ASM(s32, "effects/effect_8", fx_8_appendGfx);
