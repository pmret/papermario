#include "common.h"
#include "effects_internal.h"

typedef struct Effect14 {
    /* 0x00 */ f32 xPos; //xPos
    /* 0x04 */ f32 yPos; //yPos
    /* 0x08 */ f32 zPos; //zPos
} Effect14; // size = 0x??

INCLUDE_ASM(s32, "effects/effect_14", fx_14_main);

void fx_14_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_14", fx_14_update);

void fx_14_appendGfx(EffectInstance* effect);
void fx_14_render(EffectInstance* effect) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Effect14* effect14 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskTemp = &renderTask;
    RenderTask* retTask;
    f32 effectPosVar = effect14->xPos;
    f32 playerPosVar = playerStatus->position.x;
    
    if ((effectPosVar - playerPosVar) > 200) {
        effect14->xPos = effectPosVar - 400;
    } else {
        if ((playerPosVar - effectPosVar) > 200) {
            effect14->xPos = effectPosVar + 400;
        }
    }

    effectPosVar = effect14->zPos;
    playerPosVar = playerStatus->position.z;
    if ((effectPosVar - playerPosVar) > 200) {
        effect14->zPos = effectPosVar - 400;
    } else {
        if ((playerPosVar - effectPosVar) > 200) {
            effect14->zPos = effectPosVar + 400;
        }
    }

    renderTaskTemp->appendGfx = &fx_14_appendGfx;
    renderTaskTemp->appendGfxArg = effect;
    renderTaskTemp->distance = 0;
    renderTaskTemp->renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(renderTaskTemp);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_14", fx_14_appendGfx);
