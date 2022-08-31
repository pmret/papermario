#include "common.h"
#include "effects_internal.h"

extern s32 D_E00789A8;

void bulb_glow_init(EffectInstance* effect);
void bulb_glow_update(EffectInstance* effect);
void bulb_glow_render(EffectInstance* effect);
void bulb_glow_appendGfx(EffectInstance* effect);

void bulb_glow_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, EffectInstance** outEffect) {
    EffectBlueprint bp;
    EffectInstance* effect;
    BulbGlowFXData* data;
    s32 numParts = 1;

    bp.init = bulb_glow_init;
    bp.update = bulb_glow_update;
    bp.renderWorld = bulb_glow_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_BULB_GLOW;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.bulbGlow = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.bulbGlow != NULL);

    data->unk_00 = arg0 & 0xFF;
    if (arg0 < 256) {
        data->unk_14 = 100;
    } else {
        data->unk_14 = 80;
    }
    data->unk_18 = 0;
    data->unk_10 = 127;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->unk_1C = D_E00789A8;

    D_E00789A8++;
    if (D_E00789A8 >= 16) {
        D_E00789A8 = 0;
    }

    data->unk_20 = shim_rand_int(7);
    *outEffect = effect;
}

void bulb_glow_init(EffectInstance* effect) {
}

void bulb_glow_update(EffectInstance* effect) {
    BulbGlowFXData* data = effect->data.bulbGlow;
    s32 unk18;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_14 = 10;
    }

    data->unk_18++;

    if (data->unk_14 < 100) {
        data->unk_14--;
    }
    if (data->unk_14 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk18 = data->unk_18;
    if (data->unk_00 == 0) {
        if (unk18 < 11) {
            data->unk_10 = (unk18 * 6) + 4;
        } else {
            data->unk_10 = 64;
        }

        if (unk18 & 1) {
            data->unk_10 *= 0.6;
        }

        if (unk18 >= 15) {
            data->unk_00 = 4;
            data->unk_10 = 127;
        }
    }
}

void bulb_glow_render(EffectInstance* effect) {
    BulbGlowFXData* data = effect->data.bulbGlow;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = bulb_glow_appendGfx;
    if (data->unk_00 == 5) {
        renderTask.distance = 0;
        renderTaskPtr->renderMode = RENDER_MODE_SURFACE_OPA;
    } else {
        renderTask.distance = -100;
        renderTaskPtr->renderMode = RENDER_MODE_2D;
    }

    retTask = shim_queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E0078274(void) {
}

INCLUDE_ASM(s32, "effects/bulb_glow", bulb_glow_appendGfx);
