#include "common.h"
#include "effects_internal.h"

typedef struct QuizmoAudiencePositonOffsets {
    /* 0x00 */ Vec2b* offsets;
    /* 0x04 */ u8 count;
} QuizmoAudiencePositonOffsets; // size = 0x8

extern Gfx D_09002EE0_3AA680[];
extern Gfx D_09002F18_3AA6B8[];
extern Gfx D_09002F50_3AA6F0[];
extern Gfx D_09002F88_3AA728[];
extern Gfx D_09002FC0_3AA760[];
extern Gfx D_09002FF8_3AA798[];
extern Gfx D_09003030_3AA7D0[];
extern Gfx D_09003068_3AA808[];
extern Gfx D_090030A0_3AA840[];
extern Gfx D_090030D8_3AA878[];
extern Gfx D_09003110_3AA8B0[];

Gfx* quizmo_audience_renderAudienceMember[] = {
    D_090030D8_3AA878, D_090030A0_3AA840, D_09003068_3AA808, D_09003030_3AA7D0, D_09002FF8_3AA798,
    D_09002FC0_3AA760, D_09002F88_3AA728, D_09002F50_3AA6F0, D_09002F18_3AA6B8, D_09002EE0_3AA680
};

Vec2b quizmo_audience_horizontalPosOffsets[] = {
    {0, 0},
    {1, 0},
    {2, 0},
    {2, 0},
    {3, 0},
    {3, 0},
    {3, 0},
    {2, 0},
    {2, 0},
    {1, 0},
    {1, 0},
    {0, 0},
    {0, 0},
    {-1, 0},
    {-2, 0},
    {-2, 0},
    {-3, 0},
    {-3, 0},
    {-3, 0},
    {-2, 0},
    {-2, 0},
    {-1, 0},
    {-1, 0},
    {0, 0},
};

Vec2b quizmo_audience_verticalPosOffsets[] = {
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 2},
    {0, 3},
    {0, 3},
    {0, 3},
    {0, 2},
    {0, 2},
    {0, 1},
    {0, 1},
    {0, 0},
};

QuizmoAudiencePositonOffsets quizmo_audience_positionOffsets[] = {
    { quizmo_audience_horizontalPosOffsets, ARRAY_COUNT(quizmo_audience_horizontalPosOffsets) },
    { quizmo_audience_verticalPosOffsets, ARRAY_COUNT(quizmo_audience_verticalPosOffsets) },
};

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
    data->primColor = 255;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->lifeTime = 0;

    for(i = 0; i < 10; i++) {
        data->compState[i] = 0;
        data->compX[i] = data->compY[i] = 0.0f;
    }

    return effect;
}

void quizmo_audience_init(EffectInstance* effect) {
}

void quizmo_audience_update(EffectInstance* effect) {
    QuizmoAudienceFXData* data = effect->data.quizmoAudience;
    QuizmoAudiencePositonOffsets* unkStruct;
    s32 posIdx;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->timeLeft = 30;
    }

    if (data->timeLeft < 100) {
        data->timeLeft--;
    }

    data->lifeTime++;
    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }

    if (data->timeLeft < 16) {
        data->primColor = data->timeLeft * 16;
    }

    for (i = 0; i < MAX_QUIZMO_AUDIENCE; i++) {
        switch (data->compState[i]) {
            case 0:
                if (shim_rand_int(10) == 10) {
                    data->compState[i] = 1;
                    data->compType[i] = shim_rand_int(1);
                    data->compPosIdx[i] = 0;
                    data->compMoveMagnitude[i] = (shim_rand_int(50) * 0.01) + 0.5;
                }
                break;
            case 1:
                posIdx = data->compPosIdx[i];
                unkStruct = &quizmo_audience_positionOffsets[data->compType[i]];
                if (data->compPosIdx[i] >= unkStruct->count) {
                    data->compState[i] = 0;
                } else {
                    data->compX[i] = unkStruct->offsets[posIdx].x * data->compMoveMagnitude[i];
                    data->compY[i] = unkStruct->offsets[posIdx].y * data->compMoveMagnitude[i];
                    data->compPosIdx[i]++;
                }
                break;
        }
    }
}

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

void quizmo_audience_appendGfx(void* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    QuizmoAudienceFXData* data = ((EffectInstance*)effect)->data.quizmoAudience;
    s32 primColor = data->primColor;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, primColor, primColor, primColor, 255);
    gSPDisplayList(gMasterGfxPos++, D_09003110_3AA8B0);

    for (i = 0; i < MAX_QUIZMO_AUDIENCE; i++) {
        shim_guTranslateF(sp18, data->compX[i], data->compY[i], 0.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, quizmo_audience_renderAudienceMember[i]);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}

