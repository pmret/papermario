#include "common.h"
#include "effects_internal.h"

typedef struct Effect1 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
} Effect1; // size = 0x2C

void fx_1_init(EffectInstance* effect);
void fx_1_update(EffectInstance* effect);
void fx_1_renderWorld(EffectInstance* effect);
void* func_E0002300(EffectInstance* effect);

f32 D_E0002760[10] = { 10.0f, 40.0f, 80.0f, 170.0f, 140.0f, 100.0f, 25.0f, 155.0f, 60.0f, 120.0f };
f32 D_E0002788[10] = { 2.2f, 2.7f, 3.0f, 2.2f, 2.7f, 3.0f, 1.9f, 1.9f, 1.5f, 1.5f };
f32 D_E00027B0[10] = { 1.4f, 1.3f, 1.2f, 1.3f, 1.4f, 1.3f, 1.6f, 1.6f, 1.6f, 1.6f };
f32 D_E00027D8[10] = { 0.0f, 234.0f, 468.0f, 702.0f, 936.0f, 1260.0f, 1404.0f, 1638.0f, 1902.0f, 1976.0f };

s32 D_E0002800[] = { 0x09000FA0, 0x09001060, 0x09001120, 0x090011E0, 0x090012A0, 0x09001360, 0x09001420, 0x00000000 };

void fx_1_main(f32 arg0, f32 arg1, f32 arg2) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect1* effectData;
    f32 theta;
    f32 temp_f20;
    f32 cosTheta;
    f32 sinTheta;
    s32 numMatrices = 10;
    s32 i;

    bp.unk_00 = 0;
    bp.init = fx_1_init;
    bp.update = fx_1_update;
    bp.renderWorld = fx_1_renderWorld;
    bp.unk_14 = NULL;
    bp.effectIndex = 1;

    effect = shim_create_effect_instance(&bp);
    effect->totalMatricies = numMatrices;

    effectData = shim_general_heap_malloc(effect->totalMatricies * sizeof(Effect1));
    effect->data = effectData;

    ASSERT(effectData != NULL);

    for (i = 0; i < effect->totalMatricies; i++, effectData++) {
        effectData->unk_00 = 0;
        effectData->unk_02 = effectData->unk_04 = func_E0200000(6) + 0x10;
        effectData->unk_06 = 4;
        effectData->unk_08 = 0;
        effectData->unk_0C = arg0;
        effectData->unk_10 = arg1;
        effectData->unk_14 = arg2;
        effectData->unk_18 = 0;
        effectData->unk_1C = 0;

        theta = D_E0002760[i] + 90.0f;
        temp_f20 = 2.0 * D_E0002788[i];
        sinTheta = shim_sin_deg(theta);
        cosTheta = shim_cos_deg(theta);

        effectData->unk_20 = temp_f20 * sinTheta;
        effectData->unk_24 = -temp_f20 * cosTheta;
    }
}

void fx_1_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/effect_1", fx_1_update);

void fx_1_renderWorld(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = func_E0002300;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= 0x2;
}

INCLUDE_ASM(s32, "effects/effect_1", func_E0002300);

void func_E0002738(EffectInstance* effect) {
    shim_remove_effect(effect);
}
