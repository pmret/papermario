#include "common.h"
#include "effects_internal.h"

void fx_75_appendGfx(void* effect);

s32 D_E00EAA50[2] = { 0x09001A00, 0x09001A20 };

s32 D_E00EAA58[2] = { 0x09001910, 0x00000000 };

INCLUDE_ASM(s32, "effects/effect_75", fx_75_main);

void fx_75_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_75", fx_75_update);

void fx_75_render(EffectInstance* effect) {
    Effect75FXData* data = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 outDist;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 outS;

    shim_transform_point(gCameras[gCurrentCameraID].perspectiveMatrix[0], data->unk_04, data->unk_08, data->unk_0C, 1.0f, &outX, &outY, &outZ, &outS);

    outDist = outZ + 5000;
    if (outDist < 0) {
        outDist = 0;
    } else if (outDist > 10000) {
        outDist = 10000;
    }

    if (outS < 0.01 && -0.01 < outS) {
        outDist = 0;
    }

    renderTaskPtr->appendGfx = fx_75_appendGfx;
    renderTaskPtr->distance = -outDist;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00EA664(void) {
}

INCLUDE_ASM(s32, "effects/effect_75", fx_75_appendGfx);
