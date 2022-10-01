#include "common.h"
#include "effects_internal.h"

extern Gfx* D_E00DE810[][5];
extern Gfx* D_E00DE84C[];
extern s8 D_E00DE858[];
extern u8 D_E00DE8B4[];
extern u8 D_E00DE910[];
extern u8 D_E00DE96C[];

void cold_breath_init(EffectInstance* effect);
void cold_breath_render(EffectInstance* effect);
void cold_breath_update(EffectInstance* effect);
void cold_breath_appendGfx(void* effect);

EffectInstance* cold_breath_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    ColdBreathFXData* data;
    s32 numParts = 1;

    bp.init = cold_breath_init;
    bp.update = cold_breath_update;
    bp.renderWorld = cold_breath_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_COLD_BREATH;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.coldBreath = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.coldBreath != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_24 = 255;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_40 = arg4;
    data->unk_18 = 255;
    data->unk_1C = 255;
    data->unk_20 = 255;
    data->unk_28 = 255;
    data->unk_2C = 255;
    data->unk_30 = 255;
    data->unk_34 = 255;
    data->unk_38 = 0;
    data->unk_3C = 0;

    return effect;
}

void cold_breath_init(EffectInstance* effect) {
}

void cold_breath_update(EffectInstance* effect) {
    ColdBreathFXData* data = effect->data.coldBreath;
    s32 unk00 = data->unk_00;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_10 = 0x10;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (data->unk_10 < 16) {
        data->unk_24 = data->unk_10 * 16;
    }

    if (unk00 < 2) {
        if (unk00 >= 0) {
            data->unk_3C += 0.02;
        }
    }

    data->unk_08 += data->unk_3C;

    if (data->unk_3C > 0.5) {
        data->unk_3C = 0.5f;
    }
    if (data->unk_3C < -1.5) {
        data->unk_3C = -1.5f;
    }

    data->unk_38 += 1.0f;
}

void cold_breath_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = cold_breath_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 6;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void cold_breath_appendGfx(void* effect) {
    ColdBreathFXData* data = ((EffectInstance*)effect)->data.coldBreath;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk14 = data->unk_14;
    s32 unk24 = data->unk_24;
    s32 unk00 = data->unk_00;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 unkIndex;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp_f32;
    s32 temp_s32;
    s32 envAlpha;
    s32 cond;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp20, data->unk_04, data->unk_08, data->unk_0C);
    shim_guScaleF(sp60, data->unk_40, data->unk_40, data->unk_40);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, 0.5 * unk24);
    gDPSetAlphaDither(gMasterGfxPos++, G_AD_NOISE);
    gSPDisplayList(gMasterGfxPos++, D_E00DE84C[unk00]);

    unkIndex = (unk14 < 30 ? unk14 : 29) + unk00 * 30;
    temp1 = D_E00DE96C[unkIndex];
    temp2 = D_E00DE8B4[unkIndex];
    temp3 = D_E00DE858[unkIndex];

    shim_guPositionF(sp20, 0.0f, 0.0f, -temp1, temp2 * 0.01f, temp3, 0.0f, 0.0f);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    temp_f32 = D_E00DE910[unkIndex] * 5.0f / 256.0f;
    temp_s32 = temp_f32;
    envAlpha = (temp_f32 - temp_s32) * 256.0f;

    cond = temp_s32 >= 4;
    if (temp_s32 < 5) {
        if (cond) {
            gDPSetTileSize(gMasterGfxPos++, 1, 0, 0, 0, 0);
        } else {
            gDPSetTileSize(gMasterGfxPos++, 1, 0, 0, 31 << 2, 127 << 2);
        }
        gDPSetEnvColor(gMasterGfxPos++, data->unk_28, data->unk_2C, data->unk_30, envAlpha);
        gSPDisplayList(gMasterGfxPos++, D_E00DE810[unk00][temp_s32]);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPSetAlphaDither(gMasterGfxPos++, G_AD_DISABLE);
    gDPPipeSync(gMasterGfxPos++);
}
