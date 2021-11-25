#include "common.h"
#include "effects_internal.h"

typedef struct Effect14 {
    /* 0x00 */ f32 xPos; //xPos
    /* 0x04 */ f32 yPos; //yPos
    /* 0x08 */ f32 zPos; //zPos
} Effect14; // size = 0x??

void fx_14_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_14", fx_14_main);

void fx_14_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_14", fx_14_update);

void fx_14_render(EffectInstance* effect) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Effect14* effect14 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    f32 effectPos = effect14->xPos;
    f32 playerPos = playerStatus->position.x;
    
    if (effectPos - playerPos > 200) {
        effect14->xPos = effectPos - 400;
    } else {
        if (playerPos - effectPos > 200) {
            effect14->xPos = effectPos + 400;
        }
    }

    effectPos = effect14->zPos;
    playerPos = playerStatus->position.z;
    if (effectPos - playerPos > 200) {
        effect14->zPos = effectPos - 400;
    } else {
        if (playerPos - effectPos > 200) {
            effect14->zPos = effectPos + 400;
        }
    }

    renderTaskPtr->appendGfx = &fx_14_appendGfx;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->distance = 0;
    renderTaskPtr->renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_14", fx_14_appendGfx);
