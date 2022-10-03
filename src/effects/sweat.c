#include "common.h"
#include "effects_internal.h"

void sweat_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/sweat", sweat_main);

void sweat_init(void) {
}

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C*/ f32 unkC;
    /* 0x10 */
    s32 unk24;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} _SweatFXData;

// INCLUDE_ASM(s32, "effects/sweat", sweat_update);
void sweat_update(EffectInstance *effect) {
    f32 temp_f0;
    _SweatFXData* data = effect->data.sweat;
    s32 temp_v0;

    temp_v0 = data->unk24 - 1;
    data->unk24 = temp_v0;
    if (temp_v0 < 0) {
        shim_remove_effect(effect);
        return;
    }
    data->pos.x = (f32) (data->pos.x + data->unk18);
    data->pos.y = (f32) (data->pos.y + data->unk1C);
    data->pos.z = (f32) (data->pos.z + data->unk20);
    temp_f0 = (f32) ((f64) data->unk1C - 0.05);
    data->unk1C = temp_f0;
    data->unk18 = (f32) ((f64) data->unk18 * 0.94);
    if ((f64) temp_f0 < -0.1) {
        data->unk1C = -0.1f;
    }
    data->unk20 = (f32) ((f64) data->unk20 * 0.94);
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
