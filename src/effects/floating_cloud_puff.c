#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000080_3D4F10[];
extern Gfx D_09000168_3D4FF8[];

u8 D_E00D2500[] = { 0x00, 0x1E, 0x50, 0x78, 0x70, 0x68, 0x64, 0x00 };
u8 D_E00D2508[] = { 0x5E, 0x5C, 0x64, 0x69, 0x6B, 0x69, 0x64, 0x00 };

void floating_cloud_puff_init(EffectInstance* effect);
void floating_cloud_puff_update(EffectInstance* effect);
void floating_cloud_puff_render(EffectInstance* effect);
void floating_cloud_puff_appendGfx(void* effect);

EffectInstance* floating_cloud_puff_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FloatingCloudPuffFXData* data;
    s32 numParts = 1;

    bp.init = floating_cloud_puff_init;
    bp.update = floating_cloud_puff_update;
    bp.renderWorld = floating_cloud_puff_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_FLOATING_CLOUD_PUFF;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.floatingCloudPuff = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.floatingCloudPuff != NULL);

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
    data->unk_34 = arg4;
    data->unk_18 = 255;
    data->unk_1C = 255;
    data->unk_20 = 255;
    data->unk_28 = 10;
    data->unk_2C = 10;
    data->unk_30 = 120;

    return effect;
}

void floating_cloud_puff_init(EffectInstance* effect) {
}

void floating_cloud_puff_update(EffectInstance* effect) {
    FloatingCloudPuffFXData* data = effect->data.floatingCloudPuff;
    s32 unk_14;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 16;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_14 = data->unk_14;

    if (data->unk_10 < 16) {
        data->unk_24 = data->unk_10 * 16;
    }

    data->unk_08 += 0.6;

    if (unk_14 < 7) {
        data->unk_38 = D_E00D2500[unk_14] * 0.01;
    } else {
        data->unk_38 = D_E00D2508[(unk_14 - 7) % 7] * 0.01;
    }
}

void floating_cloud_puff_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = floating_cloud_puff_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00D227C(void) {
}

void floating_cloud_puff_appendGfx(void* effect) {
    FloatingCloudPuffFXData* data = ((EffectInstance*)effect)->data.floatingCloudPuff;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_24 = data->unk_24;
    f32 scale = data->unk_34 * data->unk_38;
    Matrix4f sp10;
    Matrix4f sp50;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp10, data->unk_04, data->unk_08, data->unk_0C);
    guScaleF(sp50, scale, scale, scale);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, unk_24);
    gDPSetEnvColor(gMainGfxPos++, data->unk_28, data->unk_2C, data->unk_30, 0);
    gSPDisplayList(gMainGfxPos++, D_09000080_3D4F10);
    gSPDisplayList(gMainGfxPos++, D_09000168_3D4FF8);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
