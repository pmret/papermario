#include "common.h"
#include "effects_internal.h"

void sleep_bubble_appendGfx(void* effect);
void sleep_bubble_init(EffectInstance* effect);
void sleep_bubble_update(EffectInstance* effect);
void sleep_bubble_render(EffectInstance* effect);

f32 D_E00529E0[] = { 4.4f, 3.2f, 5.4f, 2.7f, 6.0f, 4.9f, 5.2f, 3.1f, 2.4f, 4.5f, 2.6f, 5.7f, 3.8f, 2.9f, 3.1f, 5.2f, 2.3f, 5.4f, 3.5f, 2.6f, 2.4f, 3.1f, 5.2f, 4.9f, 6.0f, 2.7f, 5.4f, 3.2f, 4.4f, 2.6f, 3.5f, 5.4f, 2.3f, 5.2f, 3.1f, 2.9f, 3.8f, 5.7f, 2.6f, 4.5f };

typedef struct SleepBubbleFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 timeLeft;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ Vec2f points[20];
    /* 0xC4 */ f32 unk_C4;
    /* 0xC8 */ f32 unk_C8;
} SleepBubbleFXData; // size = 0xCC

void sleep_bubble_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, EffectInstance** arg6) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    SleepBubbleFXData* part;
    s32 numParts = 1;

    bp.unk_00 = 0;
    bp.init = sleep_bubble_init;
    bp.update = sleep_bubble_update;
    bp.renderWorld = sleep_bubble_render;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_SLEEP_BUBBLE;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data != NULL);

    part->unk_00 = arg0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->unk_10 = arg5;
    part->timeLeft = 100;
    part->unk_14 = arg4;
    part->unk_18 = 0;
    part->unk_20 = 0;

    *arg6 = effect;
}

void sleep_bubble_init(EffectInstance* effect) {
}

// seems extremely fake
void sleep_bubble_update(EffectInstance* effect) {
    SleepBubbleFXData* part = effect->data;
    f32* xPtr = &part->points->x;
    f32* yPtr;
    s32 xAngle, yAngle, i, timeLeft, unk_20;
    f32 angle, temp1, temp2;

    if (part->timeLeft < 100) {
        part->timeLeft--;
    }

    part->unk_20++;
    if (part->unk_20 > 324000) {
        part->unk_20 = 256;
    }

    if (part->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    
    unk_20 = part->unk_20;
    timeLeft = part->timeLeft;

    temp1 = part->unk_18 + (part->unk_14 - part->unk_18) * 0.1f;
    part->unk_18 = temp1;
    temp2 = temp1 + (temp1 * shim_sin_deg(unk_20 * 3)) * 0.1;

    i = 0;
    yPtr = &part->points->y;
    xAngle = yAngle = i;

    do {
        angle = i * 360.0f / 21.0f + 17.0f;
        
        *xPtr = temp2 * shim_sin_deg(angle);
        *yPtr = -temp2 * shim_cos_deg(angle);

        *xPtr += shim_sin_deg((f32)unk_20 * (shim_sin_deg(xAngle) * 0.1 + 2.0) + (i + 5.0f) * 30.0f) * 1.5;
        *yPtr += shim_cos_deg((f32)unk_20 * (shim_cos_deg(yAngle) * 0.1 + 2.0) + (i + 5.0f) * 50.0f) * 1.5;

        xAngle += 53;
        yAngle += 36;

        xPtr += 2;
        yPtr += 2;
        i++;
    } while (i < ARRAY_COUNT(part->points));

    part->unk_C4 = 0.0f;
    if (timeLeft < 100) {
        part->unk_C8 += 1.0f;
    } else {
        part->unk_C8 = temp2 * 1.2;
    }
}

void sleep_bubble_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sleep_bubble_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/sleep_bubble", sleep_bubble_appendGfx);
