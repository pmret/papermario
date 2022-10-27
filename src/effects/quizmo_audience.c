#include "common.h"
#include "effects_internal.h"

s32 D_E00A8620[] = { 0x090030D8, 0x090030A0, 0x09003068, 0x09003030, 0x09002FF8, 0x09002FC0, 0x09002F88, 0x09002F50, 0x09002F18, 0x09002EE0 };

s32 D_E00A8648[] = { 0x00000100, 0x02000200, 0x03000300, 0x03000200, 0x02000100, 0x01000000, 0x0000FF00, 0xFE00FE00, 0xFD00FD00, 0xFD00FE00, 0xFE00FF00, 0xFF000000 };

s32 D_E00A8678[] = { 0x00000001, 0x00020002, 0x00030003, 0x00030002, 0x00020001, 0x00010000 };

s32 D_E00A8690[] = { D_E00A8648, 0x18000000, D_E00A8678, 0x0C000000 };

void quizmo_audience_appendGfx(void* effect);

void quizmo_audience_init(EffectInstance* effect);
void quizmo_audience_update(EffectInstance* effect);
void quizmo_audience_render(EffectInstance* effect);

EffectInstance* quizmo_audience_main(s32 arg0, f32 posX, f32 posY, f32 posZ) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    QuizmoAudienceFXData* data;
    s32 numParts = 1;
    s32 i;

    effectBp.init = quizmo_audience_init;
    effectBp.update = quizmo_audience_update;
    effectBp.renderWorld = quizmo_audience_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_QUIZMO_AUDIENCE;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.quizmoAudience = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->timeLeft = 100;
    data->unk_00 = arg0;
    data->unk_18 = 255;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->lifeTime = 0;

    for(i = 0; i < 10; i++) {
        data->unk_1C[i] = 0;
        data->unk_BC[i] = data->unk_E4[i] = 0.0f;
    }

    return effect;
}

void quizmo_audience_init(EffectInstance* effect) {
}

typedef struct UnkQuizAudienceUpdate {
    char unk_00[0x01];
    f32 unk_01;
    char unk_05[0x03];
} UnkQuizAudienceUpdate; // size = 0x08

INCLUDE_ASM(s32, "effects/quizmo_audience", quizmo_audience_update);

void quizmo_audience_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = quizmo_audience_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00A8318(void) {
}

INCLUDE_ASM(s32, "effects/quizmo_audience", quizmo_audience_appendGfx);
