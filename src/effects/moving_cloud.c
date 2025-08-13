#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000100_3E1DD0[];
extern Gfx D_090001E8_3E1EB8[];

Gfx* D_E00E8630[] = { D_090001E8_3E1EB8 };
Gfx* D_E00E8634[] = { D_09000100_3E1DD0 };

void moving_cloud_init(EffectInstance* effect);
void moving_cloud_update(EffectInstance* effect);
void moving_cloud_render(EffectInstance* effect);
void moving_cloud_appendGfx(void* effect);

EffectInstance* moving_cloud_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    f32 arg6,
    f32 arg7,
    f32 arg8
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    MovingCloudFXData* data;
    s32 numParts = 1;
    f32 var_f12;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    s32 var_v0;

    bp.init = moving_cloud_init;
    bp.update = moving_cloud_update;
    bp.renderScene = moving_cloud_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_MOVING_CLOUD;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.movingCloud = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.movingCloud != nullptr);

    data->unk_00 = arg0;
    data->unk_20 = 0;

    temp_f24 = arg4 - arg1;
    temp_f22 = arg5 - arg2;
    temp_f20 = arg6 - arg3;
    var_f12 = SQ(temp_f24) + SQ(temp_f22) + SQ(temp_f20);

    if (var_f12 != 0.0f) {
        var_f12 = sqrtf(var_f12);
    }

    if (arg7 > 0.0f) {
        var_v0 = var_f12 / arg7;
    } else {
        var_v0 = 0;
    }

    if (var_v0 != 0) {
        var_f12 = 1.0f / var_v0;
        data->unk_10 = temp_f24 * var_f12;
        data->unk_14 = temp_f22 * var_f12;
        data->unk_18 = temp_f20 * var_f12;
    } else {
        data->unk_10 = 0.0f;
        data->unk_14 = 0.0f;
        data->unk_18 = 0.0f;
    }

    if (var_v0 < 0) {
        data->unk_1C = 1000;
    } else {
        data->unk_1C = var_v0;
    }

    data->unk_30 = 0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_44 = arg8;

    switch (arg0) {
        case 0:
        case 2:
            data->unk_24 = 215;
            data->unk_28 = 215;
            data->unk_2C = 185;
            data->unk_34 = 215;
            data->unk_38 = 200;
            data->unk_3C = 100;
            data->unk_40 = 255;
            break;
        case 1:
        default:
            data->unk_24 = 255;
            data->unk_28 = 255;
            data->unk_2C = 255;
            data->unk_34 = 220;
            data->unk_38 = 245;
            data->unk_3C = 255;
            data->unk_40 = 255;
            break;
    }

    return effect;
}

void moving_cloud_init(EffectInstance* effect) {
}

void moving_cloud_update(EffectInstance* effect) {
    MovingCloudFXData* data = effect->data.movingCloud;
    s32 unk_00 = data->unk_00;
    s32 unk_1C;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_1C = 16;
    }

    if (data->unk_1C < 1000) {
        data->unk_1C--;
    }

    data->unk_20++;

    if (data->unk_1C < 0) {
        remove_effect(effect);
        return;
    }

    unk_1C = data->unk_1C;

    if (unk_00 == 0 || unk_00 == 2) {
        if (data->unk_20 < 16) {
            data->unk_30 = data->unk_20 * 16 + 15;
        } else {
            data->unk_30 = 255;
        }
        if (unk_1C < 16) {
            data->unk_30 = unk_1C * 16;
        }
    } else {
        if (data->unk_20 < 4) {
            data->unk_30 = data->unk_20 * 64 + 63;
        } else {
            data->unk_30 = 255;
        }
        if (unk_1C < 4) {
            data->unk_30 = unk_1C * 64;
        }
    }

    data->unk_04 += data->unk_10;
    data->unk_08 += data->unk_14;
    data->unk_0C += data->unk_18;
}

void moving_cloud_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = moving_cloud_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void moving_cloud_appendGfx(void* effect) {
    MovingCloudFXData* data = ((EffectInstance*)effect)->data.movingCloud;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_30 = data->unk_30;
    Matrix4f sp10;
    Matrix4f sp50;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp10, data->unk_04, data->unk_08, data->unk_0C);
    guScaleF(sp50, data->unk_44, data->unk_44, data->unk_44);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_24, data->unk_28, data->unk_2C, unk_30);
    gDPSetEnvColor(gMainGfxPos++, data->unk_34, data->unk_38, data->unk_3C, data->unk_40);
    gSPDisplayList(gMainGfxPos++, D_E00E8634[0]);
    gSPDisplayList(gMainGfxPos++, D_E00E8630[0]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
