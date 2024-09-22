#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001910_3E4270[];
extern Gfx D_09001A00_3E4360[];
extern Gfx D_09001A20_3E4380[];

Gfx* D_E00EAA50[2] = { D_09001A00_3E4360, D_09001A20_3E4380 };
Gfx* D_E00EAA58[2] = { D_09001910_3E4270, NULL };

void effect_75_init(EffectInstance* effect);
void effect_75_update(EffectInstance* effect);
void effect_75_render(EffectInstance* effect);
void effect_75_appendGfx(void* effect);

EffectInstance* effect_75_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 scale, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect75FXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = effect_75_init;
    bp.update = effect_75_update;
    bp.renderWorld = effect_75_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_75;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.unk_75 = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.unk_75 != NULL);

    data->type = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_24 = 0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->scale = scale;
    data->primCol.r = 0;
    data->primCol.g = 180;
    data->primCol.b = 220;
    data->envCol.r = 0;
    data->envCol.g = 0;
    data->envCol.b = 0;
    data->unk_34 = 0;
    data->masterAlpha = 0;
    data->unk_40 = 0;
    data->unk_44 = 0;
    data->unk_50 = 0;
    data->unk_54 = 0;
    data->unk_48 = 1.0f;
    data->unk_68 = 1.0f;
    data->unk_4C = 0.9f;
    data->unk_6C = 0.9f;
    data->unk_58 = -2.0f;
    data->unk_70 = -2.0f;
    data->unk_5C = 1.25f;
    data->unk_74 = 1.25f;
    data->unk_60 = 190.0f;
    data->unk_78 = 190.0f;
    data->unk_64 = 220.0f;
    data->unk_7C = 220.0f;

    return effect;
}

void effect_75_init(EffectInstance* effect) {
}

void effect_75_update(EffectInstance* effect) {
    Effect75FXData* data = effect->data.unk_75;
    s32 unk_14;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 0x10;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;
    if (data->unk_14 > 108000) {
        data->unk_14 = 0;
    }

    if (data->unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_14 = data->unk_14;

    if (data->unk_10 < 16) {
        data->unk_24 = data->unk_10 * 16;
    }

    if (unk_14 < 16) {
        data->unk_24 = unk_14 * 16 + 15;
    }

    data->unk_48 += (data->unk_68 - data->unk_48) * 0.1;
    data->unk_4C += (data->unk_6C - data->unk_4C) * 0.1;
    data->unk_58 += (data->unk_70 - data->unk_58) * 0.1;
    data->unk_5C += (data->unk_74 - data->unk_5C) * 0.1;
    data->unk_60 += (data->unk_78 - data->unk_60) * 0.1;
    data->unk_64 += (data->unk_7C - data->unk_64) * 0.1;

    data->unk_40 += 2.0f * data->unk_48;
    data->unk_44 += 2.0f * data->unk_4C;
    data->unk_50 += 2.0f * data->unk_58;
    data->unk_54 += 2.0f * data->unk_5C;

    if (data->unk_40 < 0.0f) {
        data->unk_40 += 256.0f;
    }
    if (data->unk_44 < 0.0f) {
        data->unk_44 += 256.0f;
    }
    if (data->unk_50 < 0.0f) {
        data->unk_50 += 256.0f;
    }
    if (data->unk_54 < 0.0f) {
        data->unk_54 += 256.0f;
    }

    if (data->unk_40 > 256.0f) {
        data->unk_40 -= 256.0f;
    }
    if (data->unk_44 > 256.0f) {
        data->unk_44 -= 256.0f;
    }
    if (data->unk_50 > 256.0f) {
        data->unk_50 -= 256.0f;
    }
    if (data->unk_54 > 256.0f) {
        data->unk_54 -= 256.0f;
    }

    data->unk_34 = data->unk_60
        + (sin_deg(unk_14 * 20) * (data->unk_64 - data->unk_60)
        + (data->unk_64 - data->unk_60)) * 0.5;
}

void effect_75_render(EffectInstance* effect) {
    Effect75FXData* data = effect->data.unk_75;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 outDist;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 outS;

    transform_point(&gCameras[gCurrentCameraID].mtxPerspective[0],
        data->pos.x, data->pos.y, data->pos.z, 1.0f,
        &outX, &outY, &outZ, &outS);

    outDist = outZ + 5000;
    if (outDist < 0) {
        outDist = 0;
    } else if (outDist > 10000) {
        outDist = 10000;
    }

    if (outS < 0.01 && -0.01 < outS) {
        outDist = 0;
    }

    renderTaskPtr->appendGfx = effect_75_appendGfx;
    renderTaskPtr->dist = -outDist;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00EA664(void) {
}

void effect_75_appendGfx(void* effect) {
    Effect75FXData* data = ((EffectInstance*)effect)->data.unk_75;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 type = data->type;
    s32 uls0 = data->unk_40 * 4.0f;
    s32 ult0 = data->unk_44 * 4.0f;
    s32 uls1 = data->unk_50 * 4.0f;
    s32 ult1 = data->unk_54 * 4.0f;
    Matrix4f mtxTransfrom;
    Matrix4f mtxTemp;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(mtxTransfrom, data->pos.x, data->pos.y, data->pos.z);
    guScaleF(mtxTemp, data->scale, data->scale, data->scale);
    guMtxCatF(mtxTemp, mtxTransfrom, mtxTransfrom);
    if (type == 1) {
        guRotateF(mtxTemp, 180.0f, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxTemp, mtxTransfrom, mtxTransfrom);
    }
    guMtxF2L(mtxTransfrom, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primCol.r, data->primCol.g, data->primCol.b, data->unk_34);
    gDPSetEnvColor(gMainGfxPos++, data->envCol.r, data->envCol.g, data->envCol.b, data->unk_24 * data->masterAlpha / 255);
    gSPDisplayList(gMainGfxPos++, D_E00EAA58[0]);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, uls0, ult0, uls0 + 252, ult0 + 252);
    gDPSetTileSize(gMainGfxPos++, 1, uls1, ult1, uls1 + 252, ult1 + 252);
    gSPDisplayList(gMainGfxPos++, D_E00EAA50[type]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
