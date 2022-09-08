#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001910[];
extern Gfx D_09001A00[];
extern Gfx D_09001A20[];

Gfx* D_E00EAA50[2] = { D_09001A00, D_09001A20 };
Gfx* D_E00EAA58[2] = { D_09001910, NULL };

void fx_75_init(EffectInstance* effect);
void fx_75_update(EffectInstance* effect);
void fx_75_render(EffectInstance* effect);
void fx_75_appendGfx(void* effect);

EffectInstance* fx_75_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect75FXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = fx_75_init;
    bp.update = fx_75_update;
    bp.renderWorld = fx_75_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_75;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.unk_75 = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.unk_75 != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_24 = 0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_3C = arg4;
    data->unk_18 = 0;
    data->unk_1C = 180;
    data->unk_20 = 220;
    data->unk_28 = 0;
    data->unk_2C = 0;
    data->unk_30 = 0;
    data->unk_34 = 0;
    data->unk_38 = 0;
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

void fx_75_init(EffectInstance* effect) {
}

void fx_75_update(EffectInstance* effect) {
    Effect75FXData* data = effect->data.unk_75;
    s32 unk_14;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
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
        shim_remove_effect(effect);
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

    data->unk_34 = data->unk_60 + (shim_sin_deg(unk_14 * 20) * (data->unk_64 - data->unk_60) + (data->unk_64 - data->unk_60)) * 0.5;
}

void fx_75_render(EffectInstance* effect) {
    Effect75FXData* data = effect->data.unk_75;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 outDist;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 outS;

    shim_transform_point(&gCameras[gCurrentCameraID].perspectiveMatrix[0], data->unk_04, data->unk_08, data->unk_0C, 1.0f, &outX, &outY, &outZ, &outS);

    outDist = outZ + 5000;
    if (outDist < 0) {
        outDist = 0;
    } else if (outDist > 10000) {
        outDist = 10000;
    }

    if (outS < 0.01 && -0.01 < outS) {
        outDist = 0;
    }

    renderTaskPtr->appendGfx = fx_75_appendGfx;
    renderTaskPtr->distance = -outDist;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00EA664(void) {
}

void fx_75_appendGfx(void* effect) {
    Effect75FXData* data = ((EffectInstance*)effect)->data.unk_75;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_00 = data->unk_00;
    s32 temp_40 = data->unk_40 * 4.0f;
    s32 temp_44 = data->unk_44 * 4.0f;
    s32 temp_50 = data->unk_50 * 4.0f;
    s32 temp_54 = data->unk_54 * 4.0f;
    Matrix4f sp18;
    Matrix4f sp58;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, data->unk_04, data->unk_08, data->unk_0C);
    shim_guScaleF(sp58, data->unk_3C, data->unk_3C, data->unk_3C);
    shim_guMtxCatF(sp58, sp18, sp18);
    if (unk_00 == 1) {
        shim_guRotateF(sp58, 180.0f, 0.0f, 0.0f, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
    }
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, data->unk_34);
    gDPSetEnvColor(gMasterGfxPos++, data->unk_28, data->unk_2C, data->unk_30, data->unk_24 * data->unk_38 / 255);
    gSPDisplayList(gMasterGfxPos++, D_E00EAA58[0]);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, temp_40, temp_44, temp_40 + 252, temp_44 + 252);
    gDPSetTileSize(gMasterGfxPos++, 1, temp_50, temp_54, temp_50 + 252, temp_54 + 252);
    gSPDisplayList(gMasterGfxPos++, D_E00EAA50[unk_00]);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
