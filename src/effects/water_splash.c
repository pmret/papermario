#include "common.h"
#include "nu/nusys.h"
#include "effects_internal.h"

extern Gfx D_09000100_3BCB90[];
extern Gfx D_09000268_3BCCF8[];
extern Gfx D_09000288_3BCD18[];
extern Gfx D_090002A8_3BCD38[];

Gfx* D_E00BEAF0[] = {
    D_09000268_3BCCF8, D_09000288_3BCD18, D_09000268_3BCCF8, D_090002A8_3BCD38
};

void water_splash_init(EffectInstance *effect);
void water_splash_render(EffectInstance *effect);
void water_splash_update(EffectInstance *effect);
void water_splash_appendGfx(void* effect);

EffectInstance* water_splash_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance *effect;
    WaterSplashFXData* part;
    s32 i;
    s32 numParts;

    switch (arg0) {
        case 0:
        case 1:
            numParts = 21;
            break;
        case 2:
            numParts = 41;
            break;
        default:
            numParts = 11;
            break;
    }

    bpPtr->init = water_splash_init;
    bpPtr->update = water_splash_update;
    bpPtr->renderWorld = water_splash_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_WATER_SPLASH;
    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    effect->data.waterSplash = part = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(part != NULL);

    part->unk_00 = arg0;
    part->unk_20 = 0;
    if (arg5 <= 0) {
        part->unk_1C = 1000;
    } else {
        part->unk_1C = arg5;
    }
    part->unk_30 = 255;
    part->unk_04.x = arg1;
    part->unk_04.y = arg2;
    part->unk_04.z = arg3;
    part->unk_34 = arg4;
    part->unk_24 = 70;
    part->unk_28 = 180;
    part->unk_2C = 255;
    part++;

    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_04.x = 0.0f;
        part->unk_04.y = 0.0f;
        part->unk_04.z = 0.0f;
        part->unk_34 = 2.0f;
        switch (arg0) {
            case 0:
                part->unk_10.x = rand_int(10) - 2;
                part->unk_10.y = rand_int(10) - 5;
                part->unk_10.z = rand_int(10) - 5;
                break;
            case 1:
                part->unk_10.x = 2 - rand_int(10);
                part->unk_10.y = rand_int(10) - 5;
                part->unk_10.z = rand_int(10) - 5;
                break;
            case 2:
                part->unk_10.x = (rand_int(100) - 50) * 0.07f;
                part->unk_10.y = (rand_int(100) + 10) * 0.2f;
                part->unk_10.z = (rand_int(100) - 50) * 0.07f;
                break;
            default:
                part->unk_10.x = (rand_int(10) - 5) * 0.5;
                part->unk_10.y = (rand_int(10) - 5) * 0.5;
                part->unk_10.z = (rand_int(10) - 5) * 0.5;
                part->unk_1C = i;
                part->unk_34 = 0.4f;
                break;
        }
        part->unk_30 = 0xFF;
    }
    return effect;
}

void water_splash_init(EffectInstance* effect) {
}

void water_splash_update(EffectInstance *effect) {
    WaterSplashFXData *part;
    s32 temp_a1_3;
    s32 temp_a2;
    s32 i;

    part = effect->data.waterSplash;
    temp_a2 = part->unk_00;
    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->unk_1C = 0x10;
    }

    if (part->unk_1C < 1000) {
        part->unk_1C--;
    }

    temp_a1_3 = part->unk_1C;
    part->unk_20++;
    if (temp_a1_3 < 0) {
        remove_effect(effect);
        return;
    }

    if (temp_a1_3 < 4) {
        part->unk_30 = temp_a1_3 * 64;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_04.x += part->unk_10.x;
        part->unk_04.y += part->unk_10.y;
        part->unk_04.z += part->unk_10.z;
        part->unk_30 *= 0.98;
        if (temp_a2 == 2) {
            part->unk_10.y += -0.8;
        }
        part->unk_10.y += -0.1;
        part->unk_10.x *= 0.98;
        part->unk_10.y *= 0.98;
        part->unk_10.z *= 0.98;
        if (temp_a2 == 3) {
            part->unk_34 *= 1.2;
        } else {
            part->unk_34 *= 0.9;
        }
    }
}

void water_splash_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = water_splash_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
}

void func_E00BE5B4(void) {
}

void water_splash_appendGfx(void* effect) {
    Matrix4f sp10;
    Matrix4f sp50;
    WaterSplashFXData* data = ((EffectInstance*)effect)->data.waterSplash;
    s32 sp90 = data->unk_30;
    s32 sp94 = data->unk_04.x;
    s32 temp_fp = data->unk_04.y;
    Camera* currentCamera = &gCameras[gCurrentCameraID];
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, OS_K0_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    guTranslateF(sp10, sp94, temp_fp, data->unk_04.z);
    guScaleF(sp50, data->unk_34, data->unk_34, data->unk_34);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, currentCamera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_09000100_3BCB90);

    data++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        s32 temp_t2 = (s32)data->unk_04.x + sp94;
        s32 temp_t3 = (s32)data->unk_04.y + temp_fp;

        if (temp_t2 < 0) {
            temp_t2 = -(temp_t2 & 0x7F);
        } else {
            temp_t2 = temp_t2 & 0x7F;
        }

        if (temp_t3 > 0) {
            temp_t3 = -(temp_t3 & 0x3F);
        } else {
            temp_t3 = temp_t3 & 0x3F;
        }

        gDPLoadMultiTile(gMainGfxPos++, OS_K0_TO_PHYSICAL(nuGfxCfb_ptr), 0x100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0,
                         temp_t2 + 0xA0, temp_t3 + 0x78, temp_t2 + 0xBF, temp_t3 + 0x97, 0,
                         G_TX_WRAP, G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

        guTranslateF(sp10, data->unk_04.x, data->unk_04.y, data->unk_04.z);
        guScaleF(sp50, data->unk_34, data->unk_34, data->unk_34);
        guMtxCatF(sp50, sp10, sp10);
        guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 200, 255, 255, (sp90 * data->unk_30) / 255);
        gDPSetEnvColor(gMainGfxPos++, 0, 32, 32, 0);
        gSPDisplayList(gMainGfxPos++, D_E00BEAF0[(i + (gGameStatusPtr->frameCounter / 2)) & 3]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
