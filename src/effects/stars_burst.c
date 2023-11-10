#include "common.h"
#include "effects_internal.h"

extern Gfx D_090004C0_343500[];
extern Gfx D_090005E0_343620[];

u8 D_E0042780[] = {
    254, 172, 172,
    254, 172, 213,
    254, 180, 154,
    213, 180, 254,
    180, 180, 254,
    180, 221, 254,
    180, 254, 254,
    180, 254, 213,
    180, 254, 180,
    213, 254, 180,
    254, 254, 180,
    254, 213, 172,
};

void stars_burst_init(EffectInstance* effect);
void stars_burst_update(EffectInstance* effect);
void stars_burst_render(EffectInstance* effect);
void stars_burst_appendGfx(void* effect);

void stars_burst_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    s32 arg6
) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    StarsBurstFXData* part;
    Matrix4f unused;
    s32 numParts = arg6;
    f32 temp;
    s32 i;

    if (arg6 != 0) {
        numParts++;

        bpPtr->init = stars_burst_init;
        bpPtr->update = stars_burst_update;
        bpPtr->renderWorld = stars_burst_render;
        bpPtr->unk_00 = 0;
        bpPtr->renderUI = NULL;
        bpPtr->effectID = EFFECT_STARS_BURST;

        effect = create_effect_instance(bpPtr);
        effect->numParts = numParts;
        part = effect->data.starsBurst = general_heap_malloc(numParts * sizeof(*part));
        ASSERT(effect->data.starsBurst != NULL);

        part->unk_00 = arg0;
        part->unk_04 = arg1;
        part->unk_08 = arg2;
        part->unk_0C = arg3;
        part->unk_34 = 0;
        part->unk_30 = 30;
        part->unk_2C = 255;

        part++;
        for (i = 1; i < numParts; i++, part++) {
            temp = rand_int(10) * 0.25f + 5.0f;

            part->unk_00 = arg0;
            part->unk_04 = arg1;
            part->unk_08 = arg2;
            part->unk_0C = arg3;
            part->unk_10 = cos_deg(arg5 + (i & 2) * (i / 2) * 4) * sin_deg(arg4);
            part->unk_14 = sin_deg(arg5 + (i & 2) * (i / 2) * 4);
            part->unk_18 = cos_deg(arg5 + (i & 2) * (i / 2) * 4) * cos_deg(arg4);
            part->unk_28 = temp;
            part->unk_24 = temp / 10.0;
        }
    }
}

void stars_burst_init(EffectInstance* effect) {
}

void stars_burst_update(EffectInstance* effect) {
    StarsBurstFXData* part = effect->data.starsBurst;
    s32 unk_30;
    s32 i;

    part->unk_30--;
    part->unk_34++;

    if (part->unk_30 < 0) {
        remove_effect(effect);
        return;
    }

    unk_30 = part->unk_30;
    if (unk_30 < 10) {
        part->unk_2C *= 0.8;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_04 += part->unk_28 * part->unk_10;
        part->unk_08 += part->unk_28 * part->unk_14;
        part->unk_0C += part->unk_28 * part->unk_18;
        part->unk_28 *= 0.9;
        if (unk_30 < 10) {
            part->unk_24 += part->unk_28 / 10.0;
        }
    }
}

void stars_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = stars_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void stars_burst_appendGfx(void* effect) {
    StarsBurstFXData* part = ((EffectInstance*)effect)->data.starsBurst;
    Gfx* dlist = D_090005E0_343620;
    s32 unk_2C;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 baseIdx;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_090004C0_343500);

    unk_2C = part->unk_2C;

    baseIdx = (part->unk_34 - 1) * 3;
    baseIdx %= 36;

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        s32 rIdx = baseIdx + i * 3;
        s32 gIdx = baseIdx + 1 + i * 3;
        s32 bIdx = baseIdx + 2 + i * 3;

        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0042780[rIdx % 36], D_E0042780[gIdx % 36], D_E0042780[bIdx % 36], unk_2C);

        guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
        guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp58, sp18, sp18);
        guScaleF(sp58, part->unk_24, part->unk_24, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}
