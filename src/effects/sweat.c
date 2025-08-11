#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000200_35C750[];
extern Gfx D_090002C8_35C818[];
extern Gfx D_09000390_35C8E0[];
extern Gfx D_09000460_35C9B0[];

void sweat_init(EffectInstance* effect);
void sweat_update(EffectInstance* effect);
void sweat_render(EffectInstance* effect);
void sweat_appendGfx(void* effect);

void sweat_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 timeLeft) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    SweatFXData* data;
    Matrix4f matrix;
    f32 temp_f2;
    s32 numParts = 1;

    effectBp.init = (void*)sweat_init;
    effectBp.update = sweat_update;
    effectBp.renderScene = sweat_render;
    effectBp.unk_00 = 0;
    effectBp.renderUI = nullptr;
    effectBp.effectID = EFFECT_SWEAT;

    effect = create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.sweat = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != nullptr);

    data->unk_00 = arg0;
    guRotateF(matrix, -arg5, sin_deg(gCameras[gCurrentCameraID].curYaw), 0.0f, -cos_deg(gCameras[gCurrentCameraID].curYaw));
    temp_f2 = arg4 + 16.0f;
    data->pos.x = arg1 + (matrix[1][0] * temp_f2);
    data->pos.y = arg2 + (matrix[1][1] * temp_f2);
    data->pos.z = arg3 + (matrix[1][2] * temp_f2);
    data->unk_18 = matrix[1][0];
    data->unk_1C = matrix[1][1];
    data->unk_20 = matrix[1][2];
    data->unk_10 = arg5;
    data->timeLeft = timeLeft;
}

void sweat_init(EffectInstance* effect) {
}

void sweat_update(EffectInstance *effect) {
    SweatFXData* data = effect->data.sweat;

    data->timeLeft--;
    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }
    data->pos.x += data->unk_18;
    data->pos.y += data->unk_1C;
    data->pos.z += data->unk_20;
    data->unk_1C -= 0.05;
    data->unk_18 *= 0.94;
    if (data->unk_1C < -0.1) {
        data->unk_1C = -0.1f;
    }
    data->unk_20 *= 0.94;
}

void sweat_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sweat_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void sweat_appendGfx(void* effect) {
    SweatFXData* data = ((EffectInstance*)effect)->data.sweat;
    Matrix4f sp18;
    Matrix4f sp58;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, data->unk_10, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (data->unk_10 > 0.0f) {
        gSPDisplayList(gMainGfxPos++, data->unk_00 == 0 ? D_09000200_35C750 : D_090002C8_35C818);
    } else {
        gSPDisplayList(gMainGfxPos++, data->unk_00 == 0 ? D_09000390_35C8E0 : D_09000460_35C9B0);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
