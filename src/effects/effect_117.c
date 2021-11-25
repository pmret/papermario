#include "common.h"
#include "effects_internal.h"

typedef struct Effect117 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} Effect117; // size = 0x??

s32 D_E00EAA50[2] = { 0x09001A00, 0x09001A20 };

s32 D_E00EAA58[2] = { 0x09001910, 0x00000000 };

INCLUDE_ASM(s32, "effects/effect_117", fx_117_main);

void fx_117_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_117", fx_117_update);

void fx_117_appendGfx(EffectInstance* effect);
void fx_117_render(EffectInstance* effect) {
    Effect117* effect117 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 outDist;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 outS;

    shim_transform_point(gCameras[gCurrentCameraID].perspectiveMatrix[0], effect117->unk_04, effect117->unk_08, effect117->unk_0C, 1.0f, &outX, &outY, &outZ, &outS);
    
    outDist = outZ + 5000;
    if (outDist < 0) {
        outDist = 0;
    } else if (outDist > 10000) {
        outDist = 10000;
    }

    if (outS < 0.01 && -0.01 < outS) {
        outDist = 0;
    }
    
    renderTaskPtr->appendGfx = fx_117_appendGfx;
    renderTaskPtr->distance = -outDist;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00EA664(void) {
}

INCLUDE_ASM(s32, "effects/effect_117", fx_117_appendGfx);
