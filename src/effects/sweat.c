#include "common.h"
#include "effects_internal.h"

void sweat_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/sweat", sweat_main);

void sweat_init(void) {
}

// INCLUDE_ASM(s32, "effects/sweat", sweat_update);
void sweat_update(EffectInstance *arg0) {
    f32 temp_f0;
    s32 *temp_v1;
    s32 temp_v0;

    temp_v1 = arg0->data.any;
    temp_v0 = temp_v1->unk24 - 1;
    temp_v1->unk24 = temp_v0;
    if (temp_v0 < 0) {
        shim_remove_effect(arg0);
        return;
    }
    temp_v1->unk4 = (f32) (temp_v1->unk4 + temp_v1->unk18);
    temp_v1->unk8 = (f32) (temp_v1->unk8 + temp_v1->unk1C);
    temp_v1->unkC = (f32) (temp_v1->unkC + temp_v1->unk20);
    temp_f0 = (f32) ((f64) temp_v1->unk1C - 0.05);
    temp_v1->unk1C = temp_f0;
    temp_v1->unk18 = (f32) ((f64) temp_v1->unk18 * 0.94);
    if ((f64) temp_f0 < -0.1) {
        temp_v1->unk1C = -0.1f;
    }
    temp_v1->unk20 = (f32) ((f64) temp_v1->unk20 * 0.94);
}

void sweat_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sweat_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/sweat", sweat_appendGfx);
