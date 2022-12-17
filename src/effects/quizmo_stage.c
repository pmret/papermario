#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000218_398DD8[];
extern Gfx D_09001518_39A0D8[];
extern Mtx D_09004148_39CD08[];
extern Gfx D_09006D48_39F908[];
extern Gfx D_09006DA0_39F960[];
extern Gfx D_09006E28_39F9E8[];
extern Gfx D_09006F20_39FAE0[];
extern Gfx D_09006FB0_39FB70[];
extern Gfx D_09006FD8_39FB98[];
extern Gfx D_09007030_39FBF0[];
extern Gfx D_09007090_39FC50[];
extern Gfx D_090070E8_39FCA8[];
extern Gfx D_09007230_39FDF0[];

void quizmo_stage_init(EffectInstance* effect);
void quizmo_stage_update(EffectInstance* effect);
void quizmo_stage_render(EffectInstance* effect);
void quizmo_stage_appendGfx(void* effect);

EffectInstance* quizmo_stage_main(s32 arg0, f32 posX, f32 posY, f32 posZ) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    QuizmoStageFXData* data;
    s32 numParts = 1;

    effectBp.init = quizmo_stage_init;
    effectBp.update = quizmo_stage_update;
    effectBp.renderWorld = quizmo_stage_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_QUIZMO_STAGE;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.quizmoStage = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->vanishTimer = 100;
    data->microphoneRaiseAmt = 255;
    data->rearWallRaiseAmt = 255;
    data->leftWallRaiseAmt = 255;
    data->rightWallRaiseAmt = 255;
    data->podiumRaiseAmt = 255;
    data->lightScrollIncrement = 64;
    data->unk_00 = arg0;
    data->origin.x = posX;
    data->origin.y = posY;
    data->origin.z = posZ;
    data->lightScrollAmt = 0;
    data->lightScrollDelay = 15;
    data->unkEffectMode = 0;
    data->lifetime = 0;

    return effect;
}

void quizmo_stage_init(EffectInstance* effect) {
}

void quizmo_stage_update(EffectInstance *effect) {
    QuizmoStageFXData *data = effect->data.quizmoStage;
    s32 lifeTime;

    if (effect->flags & 16) {
        effect->flags &= ~16;
        data->vanishTimer = 30;
    }

    if (data->vanishTimer < 100) {
        data->vanishTimer--;
    }

    data->lifetime++;
    lifeTime = data->lifetime;

    if (data->vanishTimer < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (data->vanishTimer < 16) {
        data->microphoneRaiseAmt = data->vanishTimer * 16;
    }
    if ((lifeTime % data->lightScrollDelay) == 0) {
        data->lightScrollAmt += data->lightScrollIncrement;
        if (data->lightScrollAmt >= 1025) {
            data->lightScrollAmt -= 1024;
        }
    }
}

void quizmo_stage_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = quizmo_stage_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void quizmo_stage_appendGfx(void* effect) {
    QuizmoStageFXData* data = ((EffectInstance*)effect)->data.quizmoStage;
    s32 microphoneRaiseAmt = data->microphoneRaiseAmt;
    Matrix4f sp18;
    Matrix4f sp58;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, data->origin.x, data->origin.y, data->origin.z);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, microphoneRaiseAmt, microphoneRaiseAmt, microphoneRaiseAmt, 255);
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED);
    gSPDisplayList(gMasterGfxPos++, D_09007230_39FDF0);

    if (data->unk_3C != 255) {
        gSPMatrix(gMasterGfxPos++, &D_09004148_39CD08[2], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        shim_guRotateF(sp18, (data->rearWallRaiseAmt * 180) / 255 - 180, 1.0f, 0.0f, 0.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_09006E28_39F9E8);
        gSPDisplayList(gMasterGfxPos++, D_09001518_39A0D8);
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, data->lightScrollAmt, 0, data->lightScrollAmt + 252, 60);
        gSPDisplayList(gMasterGfxPos++, D_09006DA0_39F960);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        gSPMatrix(gMasterGfxPos++, &D_09004148_39CD08[0], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        shim_guRotateF(sp18, 90 - (data->leftWallRaiseAmt * 90) / 255, 0.0f, 0.0f, 1.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_09006FB0_39FB70);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        gSPMatrix(gMasterGfxPos++, &D_09004148_39CD08[1], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        shim_guRotateF(sp18, (data->rightWallRaiseAmt * 90) / 255 - 90, 0.0f, 0.0f, 1.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_09006F20_39FAE0);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_090070E8_39FCA8);
        gSPDisplayList(gMasterGfxPos++, D_09007030_39FBF0);
        gSPDisplayList(gMasterGfxPos++, D_09001518_39A0D8);
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, data->lightScrollAmt, 0, data->lightScrollAmt + 252, 60);
        gSPDisplayList(gMasterGfxPos++, D_09006FD8_39FB98);
        gSPMatrix(gMasterGfxPos++, &D_09004148_39CD08[3], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        shim_guRotateF(sp18, 90 - (data->podiumRaiseAmt * 90) / 255, 1.0f, 0.0f, 0.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_09006D48_39F908);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_09000218_398DD8);
        gSPDisplayList(gMasterGfxPos++, D_09007090_39FC50);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}
