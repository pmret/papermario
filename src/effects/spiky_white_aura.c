#include "common.h"
#include "effects_internal.h"

extern Gfx* D_09000440_34EBB0[];
extern Gfx* D_090004E8_34EC58[];

// RGB values? unused
u8 D_E00389F0[] = {
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

void spiky_white_aura_init(EffectInstance* effect);
void spiky_white_aura_update(EffectInstance* effect);
void spiky_white_aura_render(EffectInstance* effect);
void spiky_white_aura_appendGfx(void* effect);

void spiky_white_aura_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    SpikyWhiteAuraFXData* part;
    s32 numParts = 5;
    f32 fs1 = 0.0f;
    f32 fs2 = -1.0f;
    f32 fs3 = 0.0f;
    f32 var_f0;
    f32 var_f2;
    f32 var_f4;
    f32 temp_f12;
    f32 sinYaw;
    f32 cosYaw;
    f32 rotateA;
    Matrix4f sp30;
    s32 i;

    temp_f12 = SQ(fs3) + SQ(fs2) + SQ(fs1);
    if (temp_f12 != 0.0f) {
        temp_f12 = -1.0f / sqrtf(temp_f12);

        fs3 *= temp_f12;
        fs2 *= temp_f12;
        fs1 *= temp_f12;

        if (fs1 != 0.0f) {
            var_f0 = temp_f12 / fs1;
            var_f2 = 1.0f;
            var_f4 = 0.0f;
        } else if (fs2 != 0.0f) {
            var_f2 = -fs1 / fs2;
            var_f0 = 1.0f;
            var_f4 = 0.0f;
        } else {
            var_f4 = -fs1 / fs3;
            var_f2 = 0.0f;
            var_f0 = 1.0f;
        }

        temp_f12 = SQ(var_f0) + SQ(var_f2) + SQ(var_f4);
        if (temp_f12 != 0.0f) {
            temp_f12 = 1.0 / sqrtf(temp_f12);

            fs3 *= 18.0f;
            fs2 *= 18.0f;
            fs1 *= 18.0f;

            bpPtr->init = spiky_white_aura_init;
            bpPtr->update = spiky_white_aura_update;
            bpPtr->renderScene = spiky_white_aura_render;
            bpPtr->unk_00 = 0;
            bpPtr->renderUI = NULL;
            bpPtr->effectID = EFFECT_SPIKY_WHITE_AURA;

            effect = create_effect_instance(bpPtr);
            effect->numParts = numParts;
            part = effect->data.spikyWhiteAura = general_heap_malloc(numParts * sizeof(*part));
            ASSERT(effect->data.spikyWhiteAura != NULL);

            for (i = 0; i < numParts; i++, part++) {
                Camera* camera = &gCameras[gCurrentCameraID]; // required to match
                f32 (*matrix)[4] = &sp30[0]; // required to match

                part->unk_00 = arg0;
                part->unk_04 = arg1;
                part->unk_08 = arg2;
                part->unk_0C = arg3;

                sinYaw = sin_deg(gCameras[gCurrentCameraID].curYaw);
                cosYaw = -cos_deg(gCameras[gCurrentCameraID].curYaw);

                if (numParts != 1) {
                    rotateA = (i * 100) / (numParts - 1) - 50;
                } else {
                    rotateA = 0.0f;
                }

                guRotateF(matrix, rotateA, sinYaw, 0.0f, cosYaw);

                part->unk_10 = (sp30[0][0] * fs3 + sp30[1][0] * fs2 + sp30[2][0] * fs1) * 0.6;
                part->unk_14 = sp30[0][1] * fs3 + sp30[1][1] * fs2 + sp30[2][1] * fs1;
                part->unk_18 = (sp30[0][2] * fs3 + sp30[1][2] * fs2 + sp30[2][2] * fs1) * 0.6;
                part->unk_1C = 50 - (i * 100) / (numParts - 1);
                part->unk_20 = 0.5f;
                part->unk_28 = arg4;
                part->unk_2C = 0;
                part->unk_24 = 0;
            }
        }
    }
}

void spiky_white_aura_init(EffectInstance* effect) {
}

void spiky_white_aura_update(EffectInstance* effect) {
    SpikyWhiteAuraFXData* part = effect->data.spikyWhiteAura;
    s32 unk_28;
    s32 unk_2C;
    s32 i;

    part->unk_28--;
    part->unk_2C++;

    if (part->unk_28 < 0) {
        remove_effect(effect);
        return;
    }

    unk_28 = part->unk_28;
    unk_2C = part->unk_2C;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (unk_28 >= 6) {
            part->unk_10 *= 0.8;
            part->unk_14 *= 0.8;
            part->unk_18 *= 0.8;
            part->unk_24 += (255 - part->unk_24) * 0.4;
            part->unk_20 = sin_deg(part->unk_24 / 2) * 3.0f + sin_deg(unk_2C * 30.0f);
        }

        if (unk_28 < 5) {
            part->unk_24 *= 0.6;
            part->unk_10 *= 0.7;
            part->unk_14 *= 0.7;
            part->unk_18 *= 0.7;
            part->unk_20 = sin_deg(part->unk_24 / 2) * 3.0f + sin_deg(unk_2C * 30.0f) + (255 - part->unk_24) / 30.0f;
        }

        part->unk_04 += part->unk_10;
        part->unk_08 += part->unk_14;
        part->unk_0C += part->unk_18;
    }
}

void spiky_white_aura_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = spiky_white_aura_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void spiky_white_aura_appendGfx(void* effect) {
    SpikyWhiteAuraFXData* part = ((EffectInstance*)effect)->data.spikyWhiteAura;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;

    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, D_09000440_34EBB0);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, part->unk_24);

    for (i = 0; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
        guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp58, sp18, sp18);
        guRotateF(sp58, part->unk_1C, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guScaleF(sp58, part->unk_20, part->unk_20, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gDPPipeSync(gMainGfxPos++);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_090004E8_34EC58);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}
