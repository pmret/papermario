#include "common.h"
#include "effects_internal.h"

void fx_11_init(EffectInstance* effect);
void fx_11_update(EffectInstance* effect);
void fx_11_render(EffectInstance* effect);
void fx_11_appendGfx(EffectInstance* effect);

typedef struct Effect11 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16 unk_04;
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
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ char unk_34[0x4];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ char unk_48[0x8];
} Effect11; // size = 0x50

void fx_11_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect11* part;
    s32 numParts = 1;
    s32 i;

    bp.init = fx_11_init;
    bp.update = fx_11_update;
    bp.renderWorld = fx_11_render;
    bp.unk_00 = 0;
    bp.unk_14 = 0;
    bp.effectIndex = 11;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = 1;
    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data = part;

    ASSERT(effect->data != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->unk_00 = 1;
        part->unk_04 = arg0;
        part->unk_40 = 0;
        part->unk_44 = 0;
        part->unk_0C = arg1;
        part->unk_10 = arg2;
        part->unk_14 = arg3;
        part->unk_1C = 1.0f;
        part->unk_20 = 1.0f;
        part->unk_24 = 1.0f;
        part->unk_08 = -1;
        part->unk_28 = (shim_rand_int(10) * 0.03) + 1.4;
        part->unk_2C = (shim_rand_int(10) * 0.03) + 1.5;
        part->unk_30 = func_E0200000(60);
        part->unk_04 = arg0;
        part->unk_06 = 15;
        part->unk_38 = 2.0f;
        part->unk_3C = -0.5f;
        part->unk_18 = func_E0200000(360);
        part->unk_08 = -1;
    }
}

void fx_11_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/effect_11", fx_11_update);

void fx_11_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_11_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_11", fx_11_appendGfx);
