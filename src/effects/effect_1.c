#include "common.h"
#include "effects_internal.h"

typedef struct Effect1 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 y;
    /* 0x14 */ f32 z;
    /* 0x18 */ f32 partX;
    /* 0x1C */ f32 partY;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0x4];
} Effect1; // size = 0x2C

void fx_1_init(EffectInstance* effect);
void fx_1_update(EffectInstance* effect);
void fx_1_render(EffectInstance* effect);
void fx_1_appendGfx(EffectInstance* effect);

static f32 D_E0002760[10] = { 10.0f, 40.0f, 80.0f, 170.0f, 140.0f, 100.0f, 25.0f, 155.0f, 60.0f, 120.0f };
static f32 D_E0002788[10] = { 2.2f, 2.7f, 3.0f, 2.2f, 2.7f, 3.0f, 1.9f, 1.9f, 1.5f, 1.5f };
static f32 sPartScales[10] = { 1.4f, 1.3f, 1.2f, 1.3f, 1.4f, 1.3f, 1.6f, 1.6f, 1.6f, 1.6f };
static f32 sPartYaws[10] = { 0.0f, 234.0f, 468.0f, 702.0f, 936.0f, 1260.0f, 1404.0f, 1638.0f, 1902.0f, 1976.0f };

static s32 sDlists[7] = { 0x09000FA0, 0x09001060, 0x09001120, 0x090011E0, 0x090012A0, 0x09001360, 0x09001420 };

void fx_1_main(f32 x, f32 y, f32 z) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect1* effectData;
    f32 theta;
    f32 temp_f20;
    f32 cosTheta;
    f32 sinTheta;
    s32 numParts = 10;
    s32 i;

    bp.unk_00 = 0;
    bp.init = fx_1_init;
    bp.update = fx_1_update;
    bp.renderWorld = fx_1_render;
    bp.unk_14 = NULL;
    bp.effectIndex = 1;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    effectData = shim_general_heap_malloc(effect->numParts * sizeof(Effect1));
    effect->data = effectData;

    ASSERT(effectData != NULL);

    for (i = 0; i < effect->numParts; i++, effectData++) {
        effectData->unk_00 = 0;
        effectData->unk_02 = effectData->unk_04 = func_E0200000(6) + 0x10;
        effectData->unk_06 = 4;
        effectData->unk_08 = 0;
        effectData->x = x;
        effectData->y = y;
        effectData->z = z;
        effectData->partX = 0;
        effectData->partY = 0;

        theta = D_E0002760[i] + 90.0f;
        temp_f20 = 2.0 * D_E0002788[i];
        sinTheta = shim_sin_deg(theta);
        cosTheta = shim_cos_deg(theta);

        effectData->unk_20 = temp_f20 * sinTheta;
        effectData->unk_24 = -temp_f20 * cosTheta;
    }
}

void fx_1_init(EffectInstance* effect) {
}

void fx_1_update(EffectInstance* effect) {
    Effect1* effectData = effect->data;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, effectData++) {
        if (effectData->unk_02 >= 0) {
            effectData->unk_08--;

            if (effectData->unk_08 < 0) {
                effectData->partX += effectData->unk_20;
                effectData->partY += effectData->unk_24;
                effectData->unk_00++;
                effectData->unk_02--;
                cond = TRUE;

                if (effectData->unk_02 >= 0) {
                    effectData->unk_06--;
                    if (effectData->unk_06 < 0) {
                        effectData->unk_20 /= 1.25;
                        effectData->unk_24 /= 1.25;
                    }
                }
            }
        }
    }

    if (!cond) {
        shim_remove_effect(effect);
    }
}

void fx_1_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_1_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void fx_1_appendGfx(EffectInstance* effect) {
    Effect1* effectData = effect->data;
    Matrix4f mtx;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->effect->data));

    shim_guPositionF(&mtx, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, effectData->x, effectData->y,
                     effectData->z);
    shim_guMtxF2L(&mtx, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++,
              &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    for (i = 0; i < effect->numParts; i++, effectData++) {
        if (effectData->unk_02 >= 0 && effectData->unk_08 < 0) {
            s32 primAlpha = effectData->unk_02;
            f32 temp_f12;
            s32 envAlpha;
            s32 dlist;

            if (primAlpha > 16) {
                primAlpha = 16;
            }

            shim_guPositionF(&mtx, 0.0f, 0.0f, sPartYaws[i], sPartScales[i], effectData->partX,
                             effectData->partY, 0.0f);
            shim_guMtxF2L(&mtx, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++,
                      &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            temp_f12 = effectData->unk_00 - 1;

            if (effectData->unk_04 <= temp_f12) {
                envAlpha = 255;
                dlist = sDlists[ARRAY_COUNT(sDlists) - 1];
            } else {
                f32 temp = shim_sin_deg((((temp_f12 * 7.0f) / effectData->unk_04) * 90.0f) / 7.0f) * 7.0f;

                envAlpha = (s32)(temp * 255.0f) % 256;
                dlist = sDlists[(s32)temp];
            }

            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, (u32)(primAlpha * 105) / 8);
            gDPSetEnvColor(gMasterGfxPos++, 0, 0, 0, envAlpha);
            gSPDisplayList(gMasterGfxPos++, dlist);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}

void func_E0002738(EffectInstance* effect) {
    shim_remove_effect(effect);
}
