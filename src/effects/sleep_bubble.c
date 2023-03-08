#include "common.h"
#include "effects_internal.h"

void sleep_bubble_appendGfx(void* effect);
void sleep_bubble_init(EffectInstance* effect);
void sleep_bubble_update(EffectInstance* effect);
void sleep_bubble_render(EffectInstance* effect);

f32 D_E00529E0[] = {
    4.4f, 3.2f, 5.4f, 2.7f, 6.0f, 4.9f, 5.2f, 3.1f, 2.4f, 4.5f,
    2.6f, 5.7f, 3.8f, 2.9f, 3.1f, 5.2f, 2.3f, 5.4f, 3.5f, 2.6f,
    2.4f, 3.1f, 5.2f, 4.9f, 6.0f, 2.7f, 5.4f, 3.2f, 4.4f, 2.6f,
    3.5f, 5.4f, 2.3f, 5.2f, 3.1f, 2.9f, 3.8f, 5.7f, 2.6f, 4.5f
};

extern Vtx D_09000180_35D690[];
extern Gfx D_090002E0_35D7F0[];
extern Gfx D_09000390_35D8A0[];
extern Gfx D_09000440_35D950[];

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
    part = effect->data.sleepBubble = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.sleepBubble != NULL);

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
    SleepBubbleFXData* part = effect->data.sleepBubble;
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

    for (i = 0; i < ARRAY_COUNT(part->points); i++) {
        angle = i * 360.0f / 21.0f + 17.0f;

        *xPtr = temp2 * shim_sin_deg(angle);
        *yPtr = -temp2 * shim_cos_deg(angle);

        *xPtr += shim_sin_deg((f32)unk_20 * (shim_sin_deg(xAngle) * 0.1 + 2.0) + (i + 5.0f) * 30.0f) * 1.5;
        *yPtr += shim_cos_deg((f32)unk_20 * (shim_cos_deg(yAngle) * 0.1 + 2.0) + (i + 5.0f) * 50.0f) * 1.5;

        xAngle += 53;
        yAngle += 36;

        xPtr += 2;
        yPtr += 2;
    }

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
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void sleep_bubble_appendGfx(void* effect) {
    SleepBubbleFXData* data = ((EffectInstance*)effect)->data.sleepBubble;
    Matrix4f sp18, sp58;
    s32 timeLeft;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    timeLeft = data->timeLeft;
    if (timeLeft == 0) {
        gSPDisplayList(gMainGfxPos++, D_09000440_35D950);
    } else if (timeLeft == 1) {
        gSPDisplayList(gMainGfxPos++, D_09000390_35D8A0);
    } else {
        gSPDisplayList(gMainGfxPos++, D_090002E0_35D7F0);
    }

    shim_guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gMainGfxPos++, &D_09000180_35D690[1], 1, 0);

    shim_guRotateF(sp18, data->unk_10, 0.0f, 0.0f, 1.0f);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    shim_guRotateF(sp18, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guTranslateF(sp58, data->unk_C4, data->unk_C8, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPVertex(gMainGfxPos++, &D_09000180_35D690[0], 1, 1);

    for (i = 0; i < ARRAY_COUNT(data->points); i++) {
        shim_guTranslateF(sp18, data->points[i].x, data->points[i].y, 0.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPVertex(gMainGfxPos++, &D_09000180_35D690[i + 2], 1, i + 2);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

    if (timeLeft < 100) {
        gSP1Triangle(gMainGfxPos++, 21, 2, 1, 0);

        for (i = 0; i < ARRAY_COUNT(data->points) - 1; i++) {
            gSP1Triangle(gMainGfxPos++, i + 2, i + 3, 1, 0);
        }
    } else {
        gSP1Triangle(gMainGfxPos++, 0, 1, 2, 0);
        gSP1Triangle(gMainGfxPos++, 0, 21, 1, 0);

        for (i = 0; i < ARRAY_COUNT(data->points) - 1; i++) {
            gSP1Triangle(gMainGfxPos++, i + 2, i + 3, 1, 0);
        }
    }
}
