#include "common.h"
#include "effects_internal.h"

static f32 D_E0002760[10] = { 10.0f, 40.0f, 80.0f, 170.0f, 140.0f, 100.0f, 25.0f, 155.0f, 60.0f, 120.0f };
static f32 D_E0002788[10] = { 2.2f, 2.7f, 3.0f, 2.2f, 2.7f, 3.0f, 1.9f, 1.9f, 1.5f, 1.5f };
static f32 sPartScales[10] = { 1.4f, 1.3f, 1.2f, 1.3f, 1.4f, 1.3f, 1.6f, 1.6f, 1.6f, 1.6f };
static f32 sPartYaws[10] = { 0.0f, 234.0f, 468.0f, 702.0f, 936.0f, 1260.0f, 1404.0f, 1638.0f, 1902.0f, 1976.0f };

extern Gfx D_09000FA0_3273B0[];
extern Gfx D_09001060_327470[];
extern Gfx D_09001120_327530[];
extern Gfx D_090011E0_3275F0[];
extern Gfx D_090012A0_3276B0[];
extern Gfx D_09001360_327770[];
extern Gfx D_09001420_327830[];

static Gfx* sDlists[7] = {
    D_09000FA0_3273B0, D_09001060_327470, D_09001120_327530, D_090011E0_3275F0, D_090012A0_3276B0, D_09001360_327770,
    D_09001420_327830
};

void big_smoke_puff_init(EffectInstance* effect);
void big_smoke_puff_update(EffectInstance* effect);
void big_smoke_puff_render(EffectInstance* effect);
void big_smoke_puff_appendGfx(void* effect);

void big_smoke_puff_main(f32 x, f32 y, f32 z) {
    EffectBlueprint bp;
    EffectInstance* effect;
    BigSmokePuffFXData* data;
    f32 theta;
    f32 temp_f20;
    f32 cosTheta;
    f32 sinTheta;
    s32 numParts = 10;
    s32 i;

    bp.unk_00 = 0;
    bp.init = big_smoke_puff_init;
    bp.update = big_smoke_puff_update;
    bp.renderScene = big_smoke_puff_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_BIG_SMOKE_PUFF;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;

    data = general_heap_malloc(effect->numParts * sizeof(*data));
    effect->data.bigSmokePuff = data;

    ASSERT(data != NULL);

    for (i = 0; i < effect->numParts; i++, data++) {
        data->unk_00 = 0;
        data->unk_02 = data->unk_04 = effect_rand_int(6) + 0x10;
        data->unk_06 = 4;
        data->unk_08 = 0;
        data->x = x;
        data->y = y;
        data->z = z;
        data->partX = 0;
        data->partY = 0;

        theta = D_E0002760[i] + 90.0f;
        temp_f20 = 2.0 * D_E0002788[i];
        sinTheta = sin_deg(theta);
        cosTheta = cos_deg(theta);

        data->unk_20 = temp_f20 * sinTheta;
        data->unk_24 = -temp_f20 * cosTheta;
    }
}

void big_smoke_puff_init(EffectInstance* effect) {
}

void big_smoke_puff_update(EffectInstance* effect) {
    BigSmokePuffFXData* data = effect->data.bigSmokePuff;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, data++) {
        if (data->unk_02 >= 0) {
            data->unk_08--;

            if (data->unk_08 < 0) {
                data->partX += data->unk_20;
                data->partY += data->unk_24;
                data->unk_00++;
                data->unk_02--;
                cond = TRUE;

                if (data->unk_02 >= 0) {
                    data->unk_06--;
                    if (data->unk_06 < 0) {
                        data->unk_20 /= 1.25;
                        data->unk_24 /= 1.25;
                    }
                }
            }
        }
    }

    if (!cond) {
        remove_effect(effect);
    }
}

void big_smoke_puff_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = big_smoke_puff_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void big_smoke_puff_appendGfx(void* effect) {
    EffectInstance* eff = (EffectInstance*)effect;
    BigSmokePuffFXData* data = ((EffectInstance*)effect)->data.bigSmokePuff;
    Matrix4f mtx;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guPositionF(mtx, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, data->x, data->y, data->z);
    guMtxF2L(mtx, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++,
              &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    for (i = 0; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        if (data->unk_02 >= 0 && data->unk_08 < 0) {
            s32 primAlpha = data->unk_02;
            f32 temp_f12;
            s32 envAlpha;
            Gfx* dlist;

            if (primAlpha > 16) {
                primAlpha = 16;
            }

            guPositionF(mtx, 0.0f, 0.0f, sPartYaws[i], sPartScales[i], data->partX,
                             data->partY, 0.0f);
            guMtxF2L(mtx, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++,
                      &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            temp_f12 = data->unk_00 - 1;

            if (data->unk_04 <= temp_f12) {
                envAlpha = 255;
                dlist = sDlists[ARRAY_COUNT(sDlists) - 1];
            } else {
                f32 temp = sin_deg((((temp_f12 * 7.0f) / data->unk_04) * 90.0f) / 7.0f) * 7.0f;

                envAlpha = (s32)(temp * 255.0f) % 256;
                dlist = sDlists[(s32)temp];
            }

            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, (u32)(primAlpha * 105) / 8);
            gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, envAlpha);
            gSPDisplayList(gMainGfxPos++, dlist);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}

void func_E0002738(EffectInstance* effect) {
    remove_effect(effect);
}
