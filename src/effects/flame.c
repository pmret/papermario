#include "common.h"
#include "effects_internal.h"

void flame_appendGfx(void* effect);

u32 D_E0040840[2] = { 0xFF6DFF5C, 0x66BFFF4B };

s8 D_E0040848[56] = { 0x32, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x20, 0x00, 0x4B, 0x64, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x5C, 0x6B, 0xA8, 0xFF, 0x4B, 0x0A, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00, 0xFF, 0xFF, 0xFF, 0xF4, 0xF7, 0xAF, 0xAF, 0x16, 0x1E, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00 };

s32 D_E0040880[4] = { 0, 0, 0, 0 };

INCLUDE_ASM(s32, "effects/flame", flame_main);

void flame_init(void) {
}

INCLUDE_ASM(s32, "effects/flame", flame_update);

void flame_render(EffectInstance* effect) {
    FlameFXData* data = effect->data.flame;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 outDist;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 outS;

    shim_transform_point(gCameras[gCurrentCameraID].perspectiveMatrix[0], data->pos.x, data->pos.y, data->pos.z, 1.0f, &outX, &outY, &outZ, &outS);

    outDist = outZ + 5000;
    if (outDist < 0) {
        outDist = 0;
    } else if (outDist > 10000) {
        outDist = 10000;
    }

    if (outS < 0.01 && -0.01 < outS) {
        outDist = 0;
    }

    renderTaskPtr->appendGfx = flame_appendGfx;
    renderTaskPtr->distance = -outDist;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    shim_queue_render_task(renderTaskPtr);
}

INCLUDE_ASM(s32, "effects/flame", flame_appendGfx);
