#include "common.h"
#include "effects_internal.h"

s32 D_E00A29D0[] = { 0x09000200, 0x090002A8, 0x09000358 };

s32 D_E00A29DC[] = { 0x00000010, 0x00000010, 0x3F800000, 0x3F800000, 0x00000008, 0x00000008, 0x00000010, 0x00000010, 0x3F800000, 0x3F800000, 0x00000008, 0x00000008, 0x00000010, 0x00000010, 0x3F800000, 0x3F800000, 0x00000008, 0x00000008 };

s32 D_E00A2A24[] = { 0x00000064, 0x0000003C, 0x0000001E, 0x0000000A, 0x00000000, 0x00000000, 0x00000000 };

void motion_blur_flame_init(EffectInstance* effect);
void motion_blur_flame_update(EffectInstance* effect);
void motion_blur_flame_render(EffectInstance* effect);
void motion_blur_flame_appendGfx(void* effect);

EffectInstance* motion_blur_flame_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    MotionBlurFlameFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = motion_blur_flame_init;
    bp.update = motion_blur_flame_update;
    bp.renderWorld = motion_blur_flame_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_MOTION_BLUR_FLAME;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.motionBlurFlame = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.motionBlurFlame != NULL);

    data->unk_00 = arg0;
    if (arg5 < 0) {
        data->unk_50 = 1000;
    } else {
        data->unk_50 = arg5;
    }
    data->unk_4C = 127;
    data->unk_54 = 0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->position.x = 0;
    data->position.y = 0;
    data->position.z = 0;
    data->unk_5C = 255;
    data->unk_60 = 255;
    data->unk_64 = 255;
    data->unk_3C[1] = 0;
    data->unk_3C[2] = 0;
    data->unk_3C[3] = 0;

    return effect;
}

void motion_blur_flame_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/motion_blur_flame", motion_blur_flame_update);

void motion_blur_flame_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = motion_blur_flame_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 100;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00A2234(void) {
}

INCLUDE_ASM(s32, "effects/motion_blur_flame", motion_blur_flame_appendGfx);
