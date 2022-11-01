#include "common.h"
#include "effects_internal.h"

void star_outline_appendGfx(void* effect);

void star_outline_init(EffectInstance* effect);
void star_outline_update(EffectInstance* effect);
void star_outline_render(EffectInstance* effect);

EffectInstance* star_outline_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 arg5) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    StarOutlineFXData* data;
    s32 numParts = 1;

    effectBp.init = star_outline_init;
    effectBp.update = star_outline_update;
    effectBp.renderWorld = star_outline_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_STAR_OUTLINE;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.starOutline = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = 1;
    data->unk_02 = arg0;
    data->lifeTime = 0;
    if (arg5 <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = arg5;
    }
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_38 = arg4;
    data->unk_18 = 255;
    data->unk_1C = 255;
    data->unk_20 = 120;
    data->unk_28 = 255;
    data->unk_2C = 120;
    data->unk_30 = 0;
    data->unk_34 = 255;
    data->unk_24 = 255;
    data->unk_3C.x = 0;
    data->unk_3C.y = 0;
    data->unk_3C.z = 0;

    return effect;
}

void star_outline_init(EffectInstance* effect) {
}

void star_outline_update(EffectInstance* effect) {
    StarOutlineFXData* data = effect->data.starOutline;
    s32 temp_a2 = data->unk_02;
    s32 lifeTime;
    s32 temp;
    s32 temp2;

    if (effect->flags & 16) {
        effect->flags &= ~16;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifeTime++;

    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    lifeTime = data->lifeTime;
    if (data->timeLeft < 16) {
        temp = data->timeLeft * 16;
        if (data->unk_24 > temp) {
            data->unk_24 = temp;
        }
        if (data->unk_34 > temp) {
            data->unk_34 = temp;
        }
    }
    if (lifeTime < 16) {
        temp2 = (lifeTime * 16) + 15;
        if (data->unk_24 < temp2) {
            data->unk_24 = temp2;
        }
        if (data->unk_34 < temp2) {
            data->unk_34 = temp2;
        }
    }
    data->unk_48 = data->unk_3C.x;
    data->unk_4C = data->unk_3C.y;
    data->unk_50 = data->unk_3C.z;
    data->unk_54 = data->unk_38;
    if (temp_a2 == 1) {
        f32 lifetimeF = lifeTime;

        data->unk_3C.x = lifeTime * 4;
        data->unk_24 = 255;
        data->unk_3C.y = (lifeTime * 4.0f * 0.4953);
        data->unk_3C.z = (lifeTime * 4.0f * 0.2234);
        data->unk_34 = ((shim_sin_deg (lifetimeF * 7.12343)) * 127.0f) + 128.0f;
        data->unk_18 = ((shim_sin_deg (lifetimeF * 1.231)) * 127.0f) + 215.0f;
        data->unk_1C = ((shim_sin_deg (lifetimeF * 0.531)) * 127.0f) + 215.0f;
        data->unk_20 = ((shim_sin_deg (lifetimeF * 3.231)) * 127.0f) + 215.0f;
        data->unk_28 = ((shim_sin_deg (lifetimeF * 0.298)) * 127.0f) + 188.0f;
        data->unk_2C = ((shim_sin_deg (lifetimeF * 0.831)) * 127.0f) + 188.0f;
        data->unk_30 = ((shim_sin_deg (lifetimeF * 2.231)) * 127.0f) + 188.0f;
        data->unk_38 = ((shim_sin_deg (lifetimeF * 2.044)) * 0.3) + 0.7;
    }
    if (lifeTime == 1) {
        data->unk_48 = data->unk_3C.x;
        data->unk_4C = data->unk_3C.y;
        data->unk_50 = data->unk_3C.z;
        data->unk_54 = data->unk_38;
    }
}

void star_outline_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = star_outline_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/star_outline", star_outline_appendGfx);
