#include "common.h"
#include "effects_internal.h"

void lil_oink_appendGfx(void* effect);
void lil_oink_init(EffectInstance* effect);
void lil_oink_update(EffectInstance* effect);
void lil_oink_render(EffectInstance* effect);

extern Gfx D_09002D70_401FC0[];
extern Gfx D_09002DD8_402028[];
extern Gfx D_09002E70_4020C0[];
extern Gfx D_09002E98_4020E8[];
extern Gfx D_09002F30_402180[];
extern Gfx D_09002FC8_402218[];
extern Gfx D_09003060_4022B0[];
extern Gfx D_090030F8_402348[];
extern Gfx D_09003190_4023E0[];
extern Gfx D_09003228_402478[];
extern Gfx D_090032C0_402510[];
extern Gfx D_09003358_4025A8[];
extern Gfx D_09003370_4025C0[];
extern Gfx D_09003388_4025D8[];

Gfx* lil_oink_FramesGfx[][3] = {
    [LIL_OINK_TYPE_BLACK]       { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
    [LIL_OINK_TYPE_WHITE]       { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
    [LIL_OINK_TYPE_PINK]        { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
    [LIL_OINK_TYPE_PIKACHU]     { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
    [LIL_OINK_TYPE_SHROOM]      { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
    [LIL_OINK_TYPE_FLOWER]      { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
    [LIL_OINK_TYPE_STAR]        { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
    [LIL_OINK_TYPE_QUESTION]    { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
    [LIL_OINK_TYPE_SILVER]      { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
    [LIL_OINK_TYPE_GOLD]        { D_09003358_4025A8, D_09003370_4025C0, D_09003388_4025D8 },
};

Gfx* D_E0114718[] = {
    [LIL_OINK_TYPE_BLACK]       D_09002DD8_402028,
    [LIL_OINK_TYPE_WHITE]       D_09002E70_4020C0,
    [LIL_OINK_TYPE_PINK]        D_09002E98_4020E8,
    [LIL_OINK_TYPE_PIKACHU]     D_09002F30_402180,
    [LIL_OINK_TYPE_SHROOM]      D_09002FC8_402218,
    [LIL_OINK_TYPE_FLOWER]      D_09003060_4022B0,
    [LIL_OINK_TYPE_STAR]        D_090030F8_402348,
    [LIL_OINK_TYPE_QUESTION]    D_09003190_4023E0,
    [LIL_OINK_TYPE_SILVER]      D_09003228_402478,
    [LIL_OINK_TYPE_GOLD]        D_090032C0_402510
};

s8 lil_oink_AnimateGfxSelect[] = { 1, 2, 1, 0 };

EffectInstance* lil_oink_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    LilOinkFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = lil_oink_init;
    bp.update = lil_oink_update;
    bp.renderWorld = lil_oink_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_LIL_OINK;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.lilOink = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->lifetime = 0;
    data->timeLeft = 1000;

    for (i = 0; i < MAX_LIL_OINKS; i++) {
        data->x[i] = 0.0f;
        data->y[i] = 0.0f;
        data->z[i] = 0.0f;
        data->rot[i] = 0.0f;
        data->flags[i] = 0;
        data->anim[i] = LIL_OINK_ANIM_1;
        data->gfxFrame[i] = 1;
        data->jumpOffset[i] = 0.0f;
        data->animTime[i] = 0;
    }

    return effect;
}

void lil_oink_init(EffectInstance* effect) {
}

void lil_oink_update(EffectInstance* effect) {
    LilOinkFXData* data = effect->data.lilOink;
    s32 i;

    data->lifetime++;

    for (i = 0; i < MAX_LIL_OINKS; i++) {
        s32 time = data->animTime[i];
        s32 animDone = FALSE;

        switch (data->anim[i]) {
            case LIL_OINK_ANIM_0:
                animDone = TRUE;
                break;
            case LIL_OINK_ANIM_1:
                data->gfxFrame[i] = 1;
                animDone = TRUE;
                break;
            case LIL_OINK_ANIM_3:
                data->gfxFrame[i] = lil_oink_AnimateGfxSelect[time % ARRAY_COUNT(lil_oink_AnimateGfxSelect)];
                data->rot[i] = data->rot[i] + sin_deg(time * 10);
                if (time >= 36) {
                    animDone = TRUE;
                    data->animTime[i] = 0;
                }
                break;
            case LIL_OINK_ANIM_2:
                data->gfxFrame[i] = lil_oink_AnimateGfxSelect[time % ARRAY_COUNT(lil_oink_AnimateGfxSelect)];
                data->jumpOffset[i] = sin_deg(time * 20) * 2.0f;
                animDone = TRUE;
                if (time >= 9) {
                    data->jumpOffset[i] = 0.0f;
                    data->animTime[i] = 0;
                }
                break;
            case LIL_OINK_ANIM_4:
                data->gfxFrame[i] = lil_oink_AnimateGfxSelect[time % ARRAY_COUNT(lil_oink_AnimateGfxSelect)];
                data->jumpOffset[i] = sin_deg(time * 20) * 4.0f;
                if (!(time < 9)) {
                    animDone = TRUE;
                    data->jumpOffset[i] = 0.0f;
                    data->animTime[i] = 0;
                }
                break;
            case LIL_OINK_ANIM_5:
            default:
                data->gfxFrame[i] = lil_oink_AnimateGfxSelect[time % ARRAY_COUNT(lil_oink_AnimateGfxSelect)];
                data->jumpOffset[i] = sin_deg(time * 5) * 12.0f;
                if (!(time < 36)) {
                    animDone = TRUE;
                    data->jumpOffset[i] = 0.0f;
                    data->animTime[i] = 0;
                }
                break;
        }
        data->animTime[i]++;
        if (animDone) {
            if (data->flags[i] & LIL_OINK_FLAG_ANIM_CHANGED) {
                data->flags[i] &= ~LIL_OINK_FLAG_ANIM_CHANGED;
                data->animTime[i] = 0;
                data->anim[i] = data->nextAnim[i];
            }
        }
    }
}

void lil_oink_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = lil_oink_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void lil_oink_appendGfx(void* effect) {
    Matrix4f mtxTransform;
    EffectInstance* eff = effect;
    LilOinkFXData* data = eff->data.lilOink;
    s32 angle = data->lifetime * 30;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x9, VIRTUAL_TO_PHYSICAL(eff->graphics->data));

    gSPDisplayList(gMainGfxPos++, D_09002D70_401FC0);
    gSPLookAt(gMainGfxPos++, &gDisplayContext->lookAt);

    for (i = 0; i < MAX_LIL_OINKS; i++) {
        if (data->flags[i] & LIL_OINK_FLAG_VISIBLE) {
            guPositionF(mtxTransform, 0.0f, 180.0f - data->rot[i], 0.0f, 1.0f,
                             data->x[i], data->y[i] + data->jumpOffset[i], data->z[i]);
            guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_E0114718[data->type[i]]);
            if (data->type[i] == LIL_OINK_TYPE_SILVER || data->type[i] == LIL_OINK_TYPE_GOLD) {
                f32 shineVariation = sin_deg(angle) * 63.0f;
                s8 primColor = shineVariation + 63.0f;

                gDPSetPrimColor(gMainGfxPos++, 0, 0, primColor, primColor, primColor, 0);
            }
            gSPDisplayList(gMainGfxPos++, lil_oink_FramesGfx[data->type[i]][data->gfxFrame[i]]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
        angle += 20;
    }
}
