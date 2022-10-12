#include "common.h"
#include "effects_internal.h"

void quizmo_stage_appendGfx(void* effect);

void quizmo_stage_init(EffectInstance* effect);
void quizmo_stage_update(EffectInstance* effect);
void quizmo_stage_render(EffectInstance* effect);

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

INCLUDE_ASM(s32, "effects/quizmo_stage", quizmo_stage_appendGfx);
