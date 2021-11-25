#include "common.h"
#include "effects_internal.h"

typedef struct Effect32 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} Effect32; // size = 0x??

INCLUDE_ASM(s32, "effects/effect_32", fx_32_main);

void fx_32_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_32", fx_32_update);

void fx_32_appendGfx(EffectInstance* effect);
void fx_32_render(EffectInstance* effect) {
    Effect32* effect32 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskTemp = &renderTask;
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
    
    renderTaskTemp->appendGfx = fx_32_appendGfx;
    renderTaskTemp->distance = -outDist;
    renderTaskTemp->appendGfxArg = effect;
    renderTaskTemp->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    shim_queue_render_task(renderTaskTemp);
}

INCLUDE_ASM(s32, "effects/effect_32", fx_32_appendGfx);
