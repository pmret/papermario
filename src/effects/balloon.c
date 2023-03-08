#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001280_3958F0[];
extern Gfx D_09001358_3959C8[];
extern Gfx D_09001430_395AA0[];
extern Gfx D_09001508_395B78[];

Gfx* D_E00963E0[] = { D_09001280_3958F0, D_09001358_3959C8, D_09001430_395AA0 };

void balloon_init(EffectInstance* effect);
void balloon_update(EffectInstance* effect);
void balloon_render(EffectInstance* effect);
void balloon_appendGfx(void* effect);

EffectInstance* balloon_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    BalloonFXData* data;
    BalloonFXData* part;
    s32 numParts = 1;

    bp.init = balloon_init;
    bp.update = balloon_update;
    bp.renderWorld = balloon_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_BALLOON;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    data = shim_general_heap_malloc(numParts * sizeof(*data));
    effect->data.balloon = data;
    part = data;

    ASSERT(data != NULL);

    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_10 = 0.0f;
    part->unk_1C = arg5;
    part->unk_18 = 0.67f;
    part->unk_20 = 0;
    part->unk_14 = arg4;

    return effect;
}

void balloon_init(EffectInstance* effect) {
}

void balloon_update(EffectInstance* effect) {
    BalloonFXData* part = effect->data.balloon;

    part->unk_1C--;
    part->unk_20++;

    if (part->unk_1C < 0) {
        shim_remove_effect(effect);
        return;
    }

    part->unk_10 += part->unk_14;
    if (part->unk_10 > 2.0f) {
        part->unk_10 = 2.0f;
    }
    part->unk_08 += part->unk_10;
}

void balloon_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = balloon_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void balloon_appendGfx(void* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    BalloonFXData* data = ((EffectInstance*)effect)->data.balloon;
    s32 idx = data->unk_00;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, data->unk_04, data->unk_08, data->unk_0C);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guScaleF(sp58, data->unk_18, data->unk_18, 1.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_E00963E0[idx]);
    gSPDisplayList(gMainGfxPos++, D_09001508_395B78);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
