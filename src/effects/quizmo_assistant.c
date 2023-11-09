#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002400_409480[];
extern Gfx D_09002528_4095A8[];
extern Gfx D_090025B8_409638[];
extern Gfx D_09002648_4096C8[];
extern Gfx D_090026D8_409758[];
extern Gfx D_090027F0_409870[];

Gfx* D_E011C500[] = {
    D_09002528_4095A8, D_090025B8_409638, D_09002648_4096C8,
    D_090026D8_409758, D_090027F0_409870
};

Gfx* D_E011C514[] = { D_09002400_409480 };

s32 D_E011C518[] = { 1, 1, 2, 2, 2 };
s32 D_E011C52C[] = { 3, 3, 4, 4 };

void quizmo_assistant_init(EffectInstance* effect);
void quizmo_assistant_update(EffectInstance* effect);
void quizmo_assistant_render(EffectInstance* effect);
void quizmo_assistant_appendGfx(void* effect);

EffectInstance* quizmo_assistant_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    QuizmoAssistantFXData* data;
    s32 numParts = 1;

    bp.init = quizmo_assistant_init;
    bp.update = quizmo_assistant_update;
    bp.renderWorld = quizmo_assistant_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_QUIZMO_ASSISTANT;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.quizmoAssistant = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.quizmoAssistant != NULL);

    data->unk_00 = arg0;
    data->lifetime = 0;
    if (arg5 <= 0) {
        data->vanishTimer = 1000;
    } else {
        data->vanishTimer = arg5;
    }
    data->fadeInAmt = 255;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->anim = 0;

    return effect;
}

void quizmo_assistant_init(EffectInstance* effect) {
}

void quizmo_assistant_update(EffectInstance* effect) {
    QuizmoAssistantFXData* data = effect->data.quizmoAssistant;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->vanishTimer = 16;
    }

    if (data->vanishTimer < 1000) {
        data->vanishTimer--;
    }

    data->lifetime++;

    if (data->vanishTimer < 0) {
        remove_effect(effect);
        return;
    }

    if (data->vanishTimer < 16) {
        data->fadeInAmt = data->vanishTimer * 16;
    }
}

void quizmo_assistant_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = quizmo_assistant_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void quizmo_assistant_appendGfx(void* effect) {
    QuizmoAssistantFXData* data = ((EffectInstance*)effect)->data.quizmoAssistant;
    s32 lifetime = data->lifetime;
    s32 fadeInAmt = data->fadeInAmt;
    s32 idx;
    Matrix4f sp18;
    Matrix4f sp58;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guTranslateF(sp58, 89.5f, 0.0f, 2.0f);
    guMtxCatF(sp58, sp18, sp18);
    guScaleF(sp58, 5.0f / 7, 5.0f / 7, 5.0f / 7);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, fadeInAmt, fadeInAmt, fadeInAmt, 255);
    gSPDisplayList(gMainGfxPos++, D_E011C514[0]);

    switch (data->anim) {
        case 0:
            idx = 0;
            break;
        case 1:
            idx = D_E011C518[lifetime % ARRAY_COUNT(D_E011C518)];
            break;
        case 2:
        default:
            idx = D_E011C52C[lifetime % ARRAY_COUNT(D_E011C52C)];
            break;
    }

    gSPDisplayList(gMainGfxPos++, D_E011C500[idx]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
