#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000240_345420[];
extern Gfx D_090002E0_3454C0[];

Gfx* D_E0034780[] = { D_090002E0_3454C0, D_090002E0_3454C0 };
Gfx* D_E0034788[] = { D_09000240_345420, D_09000240_345420 };

u8 D_E0034790[] = {
    255, 255,  82,
    255, 255,  82,
    181, 148,   0,
    181, 148,   0,
    255, 255, 214,
    255, 255, 214,
    181, 148,   0,
    181, 148,   0
};

void lens_flare_init(EffectInstance* effect);
void lens_flare_update(EffectInstance* effect);
void lens_flare_render(EffectInstance* effect);
void lens_flare_appendGfx(void* effect);

void lens_flare_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    LensFlareFXData* data;
    s32 numParts = 1;

    bp.init = lens_flare_init;
    bp.update = lens_flare_update;
    bp.renderWorld = lens_flare_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_LENS_FLARE;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.lensFlare = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.lensFlare != NULL);

    data->unk_00 = arg0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_2C = arg4;
    data->unk_30 = 0;
    data->unk_24 = 0;
    data->unk_10 = 0;
    if (arg0 == 0) {
        data->unk_14 = 30.0f;
    } else {
        data->unk_14 = 0;
    }
    data->unk_18 = 0;
    data->unk_28 = 0;
    data->unk_20 = 0;
    data->unk_1C = 0.8f;
}

void lens_flare_init(EffectInstance* effect) {
}

void lens_flare_update(EffectInstance* effect) {
    LensFlareFXData* data = effect->data.lensFlare;
    s32 unk_2C;

    data->unk_2C--;
    data->unk_30++;

    if (data->unk_2C < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_2C = data->unk_2C;

    if (data->unk_30 < 7) {
        data->unk_24 += (218 - data->unk_24) * 0.5;
    } else {
        data->unk_24 *= 0.78;
    }

    data->unk_18 += data->unk_1C;
    data->unk_1C += 0.29;
    data->unk_10 += data->unk_14;
    data->unk_14 *= 0.93;
    data->unk_20 = shim_sin_deg(unk_2C * 50) * 0.5 + 0.9;
    data->unk_28 = shim_sin_deg(unk_2C * 40) * 64.0f + 144.0f;
}

void lens_flare_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = lens_flare_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 20;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void lens_flare_appendGfx(void* effect) {
    LensFlareFXData* data = ((EffectInstance*)effect)->data.lensFlare;
    s32 unk_00 = data->unk_00;
    s32 primA;
    s32 idx;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_E0034788[unk_00]);

    shim_guTranslateF(sp18, data->unk_04, data->unk_08, data->unk_0C);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp98);

    primA = data->unk_28;
    idx = data->unk_30 * 3;

    if (unk_00 == 0) {
        shim_guScaleF(sp58, data->unk_20, data->unk_20, data->unk_20);
        shim_guMtxCatF(sp58, sp98, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        idx %= ARRAY_COUNT(D_E0034790);

        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0034790[idx], D_E0034790[idx + 1], D_E0034790[idx + 2], primA);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_E0034780[0]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    primA = data->unk_24;
    if (primA > 255) {
        primA = 255;
    }

    if (primA > 0) {
        shim_guScaleF(sp58, data->unk_18, data->unk_18, data->unk_18);
        shim_guMtxCatF(sp58, sp98, sp18);
        shim_guRotateF(sp58, data->unk_10, 0.0f, 0.0f, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0034790[idx], D_E0034790[idx + 1], D_E0034790[idx + 2], primA);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, primA);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_E0034780[unk_00]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMainGfxPos++);
}
