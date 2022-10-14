#include "common.h"
#include "effects_internal.h"

void shiny_flare_appendGfx(void* effect);
void shiny_flare_init(EffectInstance* effect);
void shiny_flare_update(EffectInstance* effect);
void shiny_flare_render(EffectInstance* effect);

EffectInstance* shiny_flare_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    ShinyFlareFXData* data;
    s32 numParts = 1;

    effectBp.init = shiny_flare_init;
    effectBp.update = shiny_flare_update;
    effectBp.renderWorld = shiny_flare_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_SHINY_FLARE;
    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.shinyFlare = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->lifeTime = 0;
    data->timeLeft = 10;
    data->unk_24 = 255;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->unk_28 = arg4;
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 120;
    data->unk_2C = 0;

    return effect;
}

void shiny_flare_init(EffectInstance* effect) {
}

void shiny_flare_update(EffectInstance *effect) {
    ShinyFlareFXData *data = effect->data.shinyFlare;

    if (effect->flags & 16) {
        effect->flags &= ~16;
        data->timeLeft = 10;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifeTime++;
    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (data->timeLeft < 4) {
        data->unk_2C *= 0.5;
        return;
    }

    data->unk_2C = data->lifeTime * 0.2f + 0.3;
}

void shiny_flare_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shiny_flare_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00DA228(void) {
}

INCLUDE_ASM(s32, "effects/shiny_flare", shiny_flare_appendGfx);
