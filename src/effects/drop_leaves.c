#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001180_33E790[];
extern Gfx D_09001230_33E840[];

void drop_leaves_init(EffectInstance* effect);
void drop_leaves_render(EffectInstance* effect);
void drop_leaves_update(EffectInstance* effect);
void drop_leaves_appendGfx(void* effect);

void drop_leaves_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    DropLeavesFXData* part;
    s32 numParts = 5;
    s32 i;

    bp.init = drop_leaves_init;
    bp.update = drop_leaves_update;
    bp.renderWorld = drop_leaves_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_DROP_LEAVES;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.dropLeaves = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.dropLeaves != NULL);

    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_28 = arg4;
    part->unk_2C = 0;
    part->unk_24 = 0;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        if (arg0 == 0) {
            part->unk_04 = effect_rand_int(50) - 25;
            part->unk_08 = effect_rand_int(50) - 25;
            part->unk_0C = 0.0f;
            part->unk_18 = effect_rand_int(360);
            part->unk_20 = effect_rand_int(360);
            part->unk_1C = effect_rand_int(100) / 10.0f;
            part->unk_10 = 0;
            part->unk_14 = 0;
        } else {
            part->unk_04 = effect_rand_int(10) - 5;
            part->unk_08 = effect_rand_int(10) + 5;
            part->unk_0C = 10.0f;
            part->unk_18 = effect_rand_int(360);
            part->unk_20 = effect_rand_int(360);
            part->unk_1C = effect_rand_int(100) / 10.0f;
            part->unk_10 = 0;
            part->unk_14 = 2.0f;
        }
    }
}

void drop_leaves_init(EffectInstance* effect) {
}

void drop_leaves_update(EffectInstance *effect) {
    DropLeavesFXData* part = effect->data.dropLeaves;
    s32 unk_00;
    s32 unk_28;
    s32 unk_2C;
    f32 temp;
    s32 i;

    part->unk_28--;
    part->unk_2C++;

    if (part->unk_28 < 0) {
        remove_effect(effect);
        return;
    }

    unk_00 = part->unk_00;
    unk_28 = part->unk_28;
    unk_2C = part->unk_2C;

    if (unk_2C < 10) {
        part->unk_24 += (255 - part->unk_24) * 0.3;
    }
    if (unk_28 < 10) {
        part->unk_24 *= 0.8;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        temp = sin_deg(2.0f * part->unk_18) * 0.2;

        part->unk_14 += -0.05f;
        part->unk_10 += temp;

        if (unk_00 == 0) {
            part->unk_10 *= 0.94;
            part->unk_14 *= sin_deg(part->unk_18) * 0.05 + 0.95;
        } else {
            part->unk_14 += -0.05f;
            part->unk_10 *= 0.92;
        }

        part->unk_1C += effect_simple_rand(50, unk_2C + i * 20) - 25;
        part->unk_18 += sin_deg(part->unk_1C) * 10.0f;
        part->unk_20 += cos_deg(part->unk_1C * 0.5f) * 10.0f;
        part->unk_04 += part->unk_10;
        part->unk_08 += part->unk_14;
    }
}

void drop_leaves_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = drop_leaves_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void drop_leaves_appendGfx(void* effect) {
    DropLeavesFXData* part = ((EffectInstance*)effect)->data.dropLeaves;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 i;

    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09001180_33E790);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 20, 100, 20, part->unk_24);

    guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        guTranslateF(sp58, part->unk_04, part->unk_08, part->unk_0C);
        guMtxCatF(sp58, sp98, sp18);
        guRotateF(sp58, part->unk_18, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guRotateF(sp58, part->unk_20, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_09001230_33E840);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}
