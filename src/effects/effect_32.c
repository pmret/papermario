#include "common.h"
#include "effects_internal.h"

typedef struct Effect32 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} Effect32; // size = 0x??

void fx_32_appendGfx(EffectInstance* effect);

u32 D_E0040840[2] = { 0xFF6DFF5C, 0x66BFFF4B };

s8 D_E0040848[56] = { 0x32, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x20, 0x00, 0x4B, 0x64, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x5C, 0x6B, 0xA8, 0xFF, 0x4B, 0x0A, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00, 0xFF, 0xFF, 0xFF, 0xF4, 0xF7, 0xAF, 0xAF, 0x16, 0x1E, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00 };

s32 D_E0040880[4] = { 0, 0, 0, 0 };

INCLUDE_ASM(s32, "effects/effect_32", fx_32_main);

void fx_32_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_32", fx_32_update);

void fx_32_render(EffectInstance* effect) {
    Effect32* effect32 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 outDist;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 outS;

    shim_transform_point(gCameras[gCurrentCameraID].perspectiveMatrix[0], effect32->unk_04, effect32->unk_08, effect32->unk_0C, 1.0f, &outX, &outY, &outZ, &outS);
    
    outDist = outZ + 5000;
    if (outDist < 0) {
        outDist = 0;
    } else if (outDist > 10000) {
        outDist = 10000;
    }

    if (outS < 0.01 && -0.01 < outS) {
        outDist = 0;
    }
    
    renderTaskPtr->appendGfx = fx_32_appendGfx;
    renderTaskPtr->distance = -outDist;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    shim_queue_render_task(renderTaskPtr);
}

INCLUDE_ASM(s32, "effects/effect_32", fx_32_appendGfx);
