#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001E40_36CD20[];
extern Gfx D_09001EA8_36CD88[];
extern Gfx D_09001F10_36CDF0[];
extern Gfx D_09001F78_36CE58[];
extern Gfx D_09002058_36CF38[];
extern Gfx D_09002078_36CF58[];

Gfx* D_E00685B0[] = {
    D_09001E40_36CD20, D_09001E40_36CD20, D_09002058_36CF38
};

Gfx* D_E00685BC[] = {
    D_09001E40_36CD20, D_09001E40_36CD20, D_09001E40_36CD20, D_09001E40_36CD20,
    D_09001E40_36CD20, D_09001EA8_36CD88, D_09001EA8_36CD88, D_09001F10_36CDF0,
    D_09001F10_36CDF0, D_09001F10_36CDF0, D_09001F10_36CDF0, D_09001F10_36CDF0,
    D_09001EA8_36CD88, D_09001EA8_36CD88
};

Gfx* D_E00685F4[] = {
    D_09001F78_36CE58, D_09001F78_36CE58, D_09002078_36CF58
};

void ending_decals_init(EffectInstance* effect);
void ending_decals_update(EffectInstance* effect);
void ending_decals_render(EffectInstance* effect);
void ending_decals_appendGfx(void* effect);

void ending_decals_main(s32 type, f32 posX, f32 posY, f32 posZ, f32 arg4, EffectInstance** outEffect) {
    EffectBlueprint bp;
    EffectInstance* effect;
    EndingDecalsFXData* data;
    s32 numParts = 1;

    bp.init = ending_decals_init;
    bp.update = ending_decals_update;
    bp.renderWorld = ending_decals_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_ENDING_DECALS;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.endingDecals = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.endingDecals != NULL);

    data->type = type;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->haloAlpha = 255;
    data->unk_14 = arg4;
    data->scale = arg4;
    data->unk_1C = 100;
    data->unk_20 = 0;

    switch (type) {
        case 0:
        case 1:
            data->unk_24 = 0;
            data->unk_25 = 0;
            data->unk_26 = 0;
            data->unk_27 = 255;
            data->unk_28 = 255;
            data->unk_29 = 255;
            break;
        case 2:
        default:
            data->unk_24 = 255;
            data->unk_25 = 255;
            data->unk_26 = 255;
            data->unk_27 = 225;
            data->unk_28 = 255;
            data->unk_29 = 235;
            break;
    }

    *outEffect = effect;
}

void ending_decals_init(EffectInstance* effect) {
}

void ending_decals_update(EffectInstance* effect) {
    EndingDecalsFXData* data = effect->data.endingDecals;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_1C = 10;
    }

    if (data->unk_1C < 11) {
        data->unk_1C--;
    }

    data->unk_20++;

    if (data->unk_1C < 0) {
        remove_effect(effect);
        return;
    }

    if (data->unk_1C < 10) {
        data->haloAlpha -= 25;
        if (data->haloAlpha < 0) {
            data->haloAlpha = 0;
        }
    }
}

void ending_decals_render(EffectInstance* effect) {
    EndingDecalsFXData* data = effect->data.endingDecals;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = ending_decals_appendGfx;
    renderTask.dist = 10;
    if (data->type == 0) {
        renderTaskPtr->renderMode = RENDER_MODE_SURFACE_OPA;
    } else {
        renderTaskPtr->renderMode = RENDER_MODE_2D;
    }

    retTask = queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void ending_decals_appendGfx(void* effect) {
    EndingDecalsFXData* data = ((EffectInstance*)effect)->data.endingDecals;
    Gfx* dlist1;
    Gfx* dlist2;
    u32 unk_20;
    s32 alpha;
    f64 temp_f64;
    Matrix4f sp20;

    unk_20 = data->unk_20;
    dlist1 = D_E00685F4[data->type];
    dlist2 = D_E00685B0[data->type];

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, data->scale, data->pos.x, data->pos.y, data->pos.z);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    temp_f64 = data->haloAlpha;
    if (unk_20 % 2 == 0) {
        alpha = temp_f64 * 0.97;
    } else {
        alpha = temp_f64;
    }

    gDPSetEnvColor(gMainGfxPos++, 26, 121, 29, 158);
    gDPSetColorDither(gMainGfxPos++, G_CD_BAYER);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_PATTERN);
    gSPDisplayList(gMainGfxPos++, dlist1);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_24, data->unk_25, data->unk_26, alpha);
    gDPSetEnvColor(gMainGfxPos++, data->unk_27, data->unk_28, data->unk_29, 0);

    if (dlist2 == D_09001E40_36CD20) {
        dlist2 = D_E00685BC[unk_20 % 14];
    }

    gSPDisplayList(gMainGfxPos++, dlist2);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_DISABLE);
    gDPPipeSync(gMainGfxPos++);
}
