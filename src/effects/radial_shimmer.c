#include "common.h"
#include "effects_internal.h"

void radial_shimmer_init(EffectInstance* effect);
void radial_shimmer_update(EffectInstance* effect);
void radial_shimmer_render(EffectInstance* effect);
void radial_shimmer_appendGfx(void* effect);

extern Gfx D_09003428_36A188[];
extern Gfx D_09003508_36A268[];
extern Gfx D_090035E8_36A348[];
extern Gfx D_090036C8_36A428[];
extern Gfx D_09003830_36A590[];
extern Gfx D_090038B8_36A618[];
extern Gfx D_090039A8_36A708[];
extern Gfx D_09003A88_36A7E8[];

Gfx* D_E0066C50[] = {
    D_09003830_36A590, D_09003830_36A590, D_09003830_36A590, D_09003830_36A590, D_09003830_36A590,
    D_09003830_36A590, D_09003830_36A590, D_09003830_36A590, D_09003830_36A590, D_09003830_36A590,
    D_09003830_36A590, D_09003830_36A590, D_09003830_36A590, D_09003830_36A590, D_09003830_36A590
};

Gfx* D_E0066C8C[] = {
    D_09003508_36A268, D_090035E8_36A348, D_09003428_36A188, D_090039A8_36A708, D_09003A88_36A7E8,
    D_09003428_36A188, D_090039A8_36A708, D_09003A88_36A7E8, D_090038B8_36A618, D_09003508_36A268,
    D_090038B8_36A618, D_090038B8_36A618, D_09003428_36A188, D_09003A88_36A7E8, D_090036C8_36A428,
};

// todo ??? unused
s32 D_E0066CC8[] = {
    0xFFC59CFF, 0x9CFFFF73, 0xD6FF9CFF, 0xFFC57BFF, 0xB4FFDE73, 0xFFFF949C
};

EffectInstance* radial_shimmer_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    RadialShimmerFXData* data;
    s32 numParts = 1;
    s32 arg5_2 = arg5;

    bp.init = radial_shimmer_init;
    bp.update = radial_shimmer_update;
    bp.renderScene = radial_shimmer_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_RADIAL_SHIMMER;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.radialShimmer = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.radialShimmer != nullptr);

    data->unk_00 = arg0;
    data->timeLeft = arg5_2;
    data->unk_24 = data->lifeTime = 0;
    data->unk_10 = arg1;
    data->unk_14 = arg2;
    data->unk_18 = arg3;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_20 = arg4;
    data->unk_68 = 255;
    data->unk_69 = 255;
    data->unk_6A = 0;
    data->unk_6B = 255;
    data->unk_6C = 255;
    data->unk_6D = 255;
    data->unk_5C = 4.0f;
    data->unk_1C = 10.0f;
    data->unk_60 = 50.0f;
    data->unk_40 = data->unk_44 = 0.0f;
    data->unk_48 = data->unk_4C = 0.0f;
    data->unk_30 = data->unk_34 = 0.0f;
    data->unk_38 = data->unk_3C = 0.0f;
    data->unk_50 = data->unk_58 = 0.0f;
    data->unk_54 = 0.0f;
    data->unk_64 = 0.0f;

    switch (arg0) {
        case 0:
        case 1:
            data->unk_40 = 128.0f;
            data->unk_44 = 128.0f / arg5_2;
            data->unk_60 = 70.0f;
            data->unk_64 = -100.0f;
            break;
        case 2:
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = 3.0f;
            data->unk_4C = -7.0f;
            break;
        case 3:
            data->unk_68 = 235;
            data->unk_69 = 235;
            data->unk_6A = 235;
            data->unk_40 = 256.0f;
            data->unk_48 = 256.0f;
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = -4.0f;
            break;
        case 4:
            data->unk_68 = 20;
            data->unk_69 = 200;
            data->unk_6A = 32;
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = -5.0f;
            break;
        case 5:
            data->unk_34 = 7.0f;
            data->unk_44 = 3.0f;
            data->unk_3C = 3.0f;
            data->unk_4C = 5.0f;
            break;
        case 6:
            data->unk_68 = 235;
            data->unk_69 = 235;
            data->unk_6A = 235;
            data->unk_34 = 7.0f;
            data->unk_44 = 3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = 4.0f;
            break;
        case 7:
            data->unk_68 = 255;
            data->unk_69 = 100;
            data->unk_6A = 32;
            data->unk_34 = 7.0f;
            data->unk_44 = 3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = 5.0f;
            break;
        case 8:
            data->unk_68 = 215;
            data->unk_69 = 208;
            data->unk_6A = 0;
            data->unk_6B = 215;
            data->unk_6C = 255;
            data->unk_6D = 0;
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = -2.0f;
            break;
        case 9:
            data->unk_40 = 128.0f;
            data->unk_44 = 128.0f / arg5_2;
            data->unk_64 = -100.0f;
            break;
        case 10:
            data->unk_68 = 0;
            data->unk_69 = 32;
            data->unk_6A = 255;
            data->unk_68 = 7;
            data->unk_69 = 0;
            data->unk_6A = 216;
            data->unk_6B = 228;
            data->unk_6C = 255;
            data->unk_6D = 0;
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = -2.0f;
            break;
        case 11:
            data->unk_68 = 7;
            data->unk_69 = 0;
            data->unk_6A = 216;
            data->unk_6B = 228;
            data->unk_6C = 255;
            data->unk_6D = 0;
            data->unk_34 = 7.0f;
            data->unk_44 = 8.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = 6.0f;
            break;
        case 12:
        case 13:
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -5.0f;
            data->unk_4C = -4.0f;
            break;
        case 14:
        default:
            data->unk_40 = 4.0f;
            data->unk_34 = 7.0f;
            data->unk_4C = 3.5f;
            data->unk_60 = 20.0f;
            data->unk_64 = -106.0f;
            break;
    }

    return effect;
}

void radial_shimmer_init(EffectInstance* effect) {
}

void radial_shimmer_update(EffectInstance* effect) {
    RadialShimmerFXData* part = effect->data.radialShimmer;
    s32 unk_28;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 outS;
    s32 i;

    part->timeLeft--;
    part->lifeTime++;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->timeLeft = 16;
    }

    if (part->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    unk_28 = part->timeLeft;

    if (part->lifeTime <= 10) {
        part->unk_24 = (part->lifeTime * 255) / 10;
    }

    if (unk_28 < 6) {
        part->unk_24 = (unk_28 * 255) / 6;
    }

    if (unk_28 < 10 && part->unk_00 == 4) {
        part->unk_1C *= 0.7;
    }

    part->unk_1C = part->unk_20;

    transform_point(&gCameras[gCurrentCameraID].mtxPerspective[0], part->unk_04, part->unk_08, part->unk_0C,
                         1.0f, &outX, &outY, &outZ, &outS);

    outS = 1.0f / outS;
    outX *= outS;
    outY *= outS;
    outZ *= outS;

    part->unk_10 = outX;
    part->unk_14 = outY;
    part->unk_18 = 0.0f;

    for (i = 0; i < effect->numParts; i++, part++) {
        part->unk_58 += part->unk_5C;
        part->unk_50 += part->unk_54;
        part->unk_40 += part->unk_44;
        part->unk_30 += part->unk_34;
        part->unk_38 += part->unk_3C;
        part->unk_48 += part->unk_4C;

        if (part->unk_40 < 0.0f) {
            part->unk_40 += 512.0f;
        }

        if (part->unk_48 < 0.0f) {
            part->unk_48 += 512.0f;
        }
    }
}

void radial_shimmer_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = radial_shimmer_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void radial_shimmer_appendGfx(void* effect) {
    Matrix4f sp20, sp60;
    u16 spA0;
    EffectInstance* effectTemp = effect;
    RadialShimmerFXData* dataOrig = effectTemp->data.radialShimmer;
    RadialShimmerFXData* data = effectTemp->data.radialShimmer;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 temp_f0;
    s32 temp_f2;
    s32 temp_f4;
    s32 temp_f6;
    Gfx* dlist2;
    Gfx* dlist1;
    s32 temp_s5;
    s32 temp_t1;
    s32 var_a3;
    s32 alpha;
    s32 other;
    s32 t1;
    s32 t2;
    s32 i;

    temp_s5 = data->unk_00;
    dlist1 = D_E0066C8C[temp_s5];
    dlist2 = D_E0066C50[temp_s5];

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp20, data->unk_10, data->unk_14, data->unk_18);
    guScaleF(sp60, data->unk_1C, data->unk_1C, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guPerspectiveF(sp60, &spA0, data->unk_60, (f32) camera->viewportW / camera->viewportH, 4.0f, 16384.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    guTranslateF(sp20, 0.0f, 0.0f, data->unk_64);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    alpha = data->unk_24;
    gDPSetEnvColor(gMainGfxPos++, data->unk_6B, data->unk_6C, data->unk_6D, 127);
    gSPDisplayList(gMainGfxPos++, dlist1);

    for (i = 0; i < effectTemp->numParts; i++, data++) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_68, data->unk_69, data->unk_6A, alpha);

        switch (temp_s5) {
            case 0:
            case 1:
                other = 0x3F;
                var_a3 = 0x1FF;
                break;
            case 8:
                other = 0x3F;
                var_a3 = 0x7F;
                break;
            case 11:
                other = 0x3F;
                var_a3 = 0xFF;
                break;
            default:
                other = 0x3F;
                var_a3 = 0x1FF;
                break;
        }

        temp_f0 = data->unk_30;
        temp_f2 = data->unk_40;
        temp_f4 = data->unk_38;
        temp_f6 = data->unk_48;

        gDPSetTileSize(gMainGfxPos++, 0, temp_f0, temp_f2, temp_f0 + other * 4, temp_f2 + var_a3 * 4);
        gDPSetTileSize(gMainGfxPos++, G_TX_MIRROR, temp_f4, temp_f6, temp_f4 + other * 4, temp_f6 + var_a3 * 4);
        gSPDisplayList(gMainGfxPos++, dlist2);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID],
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPPipeSync(gMainGfxPos++);
}
