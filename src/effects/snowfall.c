#include "common.h"
#include "effects_internal.h"


void snowfall_init(EffectInstance* effect);
void snowfall_update(EffectInstance* effect);
void snowfall_render(EffectInstance* effect);
void snowfall_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/snowfall", func_E008A000);

void func_E008A000(SnowfallFXData* data);

EffectInstance* snowfall_main(s32 arg0, s32 arg1) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    SnowfallFXData* data;
    s32 index;
    s32 temp_s0;

    effectBp.init = snowfall_init;
    effectBp.update = snowfall_update;
    effectBp.renderWorld = snowfall_render;
    temp_s0 = arg1 + 1;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_SNOWFALL;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = temp_s0;

    data = effect->data.snowfall = shim_general_heap_malloc(temp_s0 * sizeof(*data));
    ASSERT(data != NULL);

    data->timeLeft = 0x64;
    data->lifeTime = 0;
    data->unk_28 = 0xFF;
    data->unk_04 = arg0;
    data->unk_2C = arg1;
    data->unk_00 = 1;

    data++;
    for (index=0; index < arg1; index++, data++) {
        func_E008A000(data);
        data->unk_30 = 0;
    }

    return effect;
}

void snowfall_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/snowfall", func_E008A290);

INCLUDE_ASM(s32, "effects/snowfall", snowfall_update);

void snowfall_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = snowfall_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/snowfall", snowfall_appendGfx);
