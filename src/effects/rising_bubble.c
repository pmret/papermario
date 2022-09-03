#include "common.h"
#include "effects_internal.h"

void rising_bubble_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/rising_bubble", rising_bubble_main);

void rising_bubble_init(void) {
}

void rising_bubble_update(EffectInstance* effect) {
    RisingBubbleFXData* risingBubbleFXData = effect->data.risingBubble;
    s32 temp_a2 = risingBubbleFXData->unk_18;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;

    if (risingBubbleFXData->unk_08 >= risingBubbleFXData->unk_24) {
        risingBubbleFXData->unk_18--; 
        risingBubbleFXData->unk_1C++;
        
        if (risingBubbleFXData->unk_18 < 0) {
            shim_remove_effect(effect); 
            return;
        }
        
        if (temp_a2 >= 6) { 
            risingBubbleFXData->unk_14 += (0x78 - risingBubbleFXData->unk_14) * 0.3;
        } else {
            risingBubbleFXData->unk_14 = (temp_a2 * 0x14);
        }

        risingBubbleFXData->unk_20++;
        if (risingBubbleFXData->unk_20 >= 0x20) {
            risingBubbleFXData->unk_20 -= 0x20;
        }
        
        risingBubbleFXData->unk_10 += 0.1;
        return;
    }
    
    risingBubbleFXData->unk_14 = 0xFF;
    risingBubbleFXData->unk_1C++;
    risingBubbleFXData->unk_08 += 2.0f;
}



void rising_bubble_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = rising_bubble_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/rising_bubble", rising_bubble_appendGfx);
