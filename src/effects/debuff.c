#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000240_364E40[];
extern Gfx D_090002E8_364EE8[];

Gfx* D_E00628C0[] = { D_090002E8_364EE8 };
Gfx* D_E00628C4[] = { D_09000240_364E40 };

void debuff_init(EffectInstance* effect);
void debuff_update(EffectInstance* effect);
void debuff_render(EffectInstance* effect);
void debuff_appendGfx(void* effect);

EffectInstance* debuff_main(s32 arg0, f32 x, f32 y, f32 z) {
    EffectBlueprint bp;
    EffectInstance* effect;
    DebuffFXData* data;
    s32 numParts = 8;
    s32 i;

    bp.unk_00 = 0;
    bp.init = debuff_init;
    bp.update = debuff_update;
    bp.renderWorld = debuff_render;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_DEBUFF;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    effect->data.debuff = data = shim_general_heap_malloc(numParts * sizeof(*data));

    ASSERT(data != NULL);

    shim_mem_clear(data, numParts * sizeof(*data));

    data->unk_24 = 30;
    data->unk_28 = 0;
    data->unk_00 = arg0;
    data->unk_04 = x;
    data->unk_08 = y;
    data->unk_0C = z;
    data->unk_34 = 255;

    if (arg0 == 0) {
        data->unk_3B = 20;
        data->unk_38 = 20;
        data->unk_3C = 21;
        data->unk_39 = 21;
        data->unk_3D = 242;
        data->unk_3A = 242;
    } else {
        data->unk_3B = 200;
        data->unk_38 = 200;
        data->unk_3C = 21;
        data->unk_39 = 21;
        data->unk_3D = 212;
        data->unk_3A = 212;
    }

    data++;
    for (i = 1; i < numParts; i++, data++) {
        s32 temp = ((i - 1) * 360) / (numParts - 1);
        f32 temp2 = 1.0f;

        data->unk_04 = shim_cos_deg(temp + 90.0f);
        data->unk_08 = shim_sin_deg(temp + 90.0f);
        data->unk_0C = 0.0f;
        data->unk_10 = 0.0f;
        data->unk_14 = 0.0f;
        data->unk_18 = 0.0f;
        data->unk_1C = 0.1f;
        data->unk_20 = 0.1f;
        data->unk_30 = temp2;
        data->unk_2C = temp;
    }

    return effect;
}

void debuff_init(EffectInstance* effect) {
}

void debuff_update(EffectInstance* effect) {
    DebuffFXData* data = effect->data.debuff;
    s32 temp;
    s32 i;

    data->unk_28++;
    data->unk_24--;
    if (data->unk_24 < 0) {
        shim_remove_effect(effect);
        return;
    }

    temp = data->unk_28;

    if (temp >= 11) {
        data->unk_34 *= 0.9;
    }

    data++;
    for (i = 1; i < effect->numParts; i++, data++) {
        if (temp > 10) {
            data->unk_1C += (1.0 - data->unk_1C) * 0.1;
            data->unk_20 += (2.4f - data->unk_20) * 0.1;
            data->unk_30 += ((100.0f - data->unk_30) * 0.07) * 0.2;
        }
        if (temp < 10) {
            data->unk_1C += (7.0f - data->unk_1C) * 0.05;
            data->unk_20 += (1.0f - data->unk_20) * 0.1;
            data->unk_30 += ((10.0f - data->unk_30) * 0.05) * 0.6;
        }
        data->unk_04 = shim_cos_deg(data->unk_2C + 90.0f) * data->unk_30;
        data->unk_08 = shim_sin_deg(data->unk_2C + 90.0f) * data->unk_30;
    }
}

void debuff_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = debuff_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void debuff_appendGfx(void* effect) {
    EffectInstance* eff = (EffectInstance*)effect;
    DebuffFXData* data = eff->data.debuff;
    Gfx* dlist = D_E00628C0[0];
    Gfx* dlist2 = D_E00628C4[0];
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(eff->graphics->data));
    gSPDisplayList(gMainGfxPos++, dlist2);

    shim_guTranslateF(sp18, data->unk_04, data->unk_08, data->unk_0C);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp98);
    shim_guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++,
              &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_38, data->unk_39, data->unk_3A, data->unk_34);
    gDPSetEnvColor(gMainGfxPos++, data->unk_3B, data->unk_3C, data->unk_3D, 0);

    data++;
    for (i = 1; i < eff->numParts; i++, data++) {
        shim_guTranslateF(sp18, data->unk_04, data->unk_08, data->unk_0C);
        shim_guRotateF(sp58, data->unk_2C, 0.0f, 0.0f, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guScaleF(sp58, data->unk_20, data->unk_1C, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++,
                  &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
