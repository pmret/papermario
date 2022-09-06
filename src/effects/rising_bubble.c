#include "common.h"
#include "effects_internal.h"

void rising_bubble_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/rising_bubble", rising_bubble_main);

void rising_bubble_init(void) {
}

void rising_bubble_update(EffectInstance* effect) {
    RisingBubbleFXData* data = effect->data.risingBubble;
    s32 temp_a2 = data->unk_18;

    if (data->unk_08 >= data->unk_24) {
        data->unk_18--; 
        data->unk_1C++;
        
        if (data->unk_18 < 0) {
            shim_remove_effect(effect); 
            return;
        }
        
        if (temp_a2 >= 6) { 
            data->unk_14 += (120 - data->unk_14) * 0.3;
        } else {
            data->unk_14 = (temp_a2 * 20);
        }

        data->unk_20++;
        if (data->unk_20 >= 32) {
            data->unk_20 -= 32;
        }
        
        data->unk_10 += 0.1;
        return;
    }
    
    data->unk_14 = 255;
    data->unk_1C++;
    data->unk_08 += 2.0f;
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
