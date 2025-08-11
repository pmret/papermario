#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000240_364E40[];
extern Gfx D_090002E8_364EE8[];

Gfx* D_E00628C0[] = { D_090002E8_364EE8 };
Gfx* D_E00628C4[] = { D_09000240_364E40 };

void debuff_init(EffectInstance* effect);
void debuff_update(EffectInstance* effect);
void debuff_render(EffectInstance* effect);
void debuff_appendGfx(void* effect);

EffectInstance* debuff_main(s32 type, f32 x, f32 y, f32 z) {
    EffectBlueprint bp;
    EffectInstance* effect;
    DebuffFXData* data;
    s32 numParts = 8;
    s32 i;

    bp.unk_00 = 0;
    bp.init = debuff_init;
    bp.update = debuff_update;
    bp.renderScene = debuff_render;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_DEBUFF;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;

    effect->data.debuff = data = general_heap_malloc(numParts * sizeof(*data));

    ASSERT(data != nullptr);

    mem_clear(data, numParts * sizeof(*data));

    data->timeLeft = 30;
    data->lifetime = 0;
    data->type = type;
    data->pos.x = x;
    data->pos.y = y;
    data->pos.z = z;
    data->alpha = 255;

    if (type == 0) {
        data->envCol.r  = 20;
        data->primCol.r = 20;
        data->envCol.g  = 21;
        data->primCol.g = 21;
        data->envCol.b  = 242;
        data->primCol.b = 242;
    } else {
        data->envCol.r  = 200;
        data->primCol.r = 200;
        data->envCol.g  = 21;
        data->primCol.g = 21;
        data->envCol.b  = 212;
        data->primCol.b = 212;
    }

    data++;
    for (i = 1; i < numParts; i++, data++) {
        s32 angle = ((i - 1) * 360) / (numParts - 1);
        f32 temp2 = 1.0f;

        data->pos.x = cos_deg(angle + 90.0f);
        data->pos.y = sin_deg(angle + 90.0f);
        data->pos.z = 0.0f;
        data->unk_10 = 0.0f;
        data->unk_14 = 0.0f;
        data->unk_18 = 0.0f;
        data->scaleY = 0.1f;
        data->scaleX = 0.1f;
        data->unk_30 = temp2;
        data->rotZ = angle;
    }

    return effect;
}

void debuff_init(EffectInstance* effect) {
}

void debuff_update(EffectInstance* effect) {
    DebuffFXData* data = effect->data.debuff;
    s32 time;
    s32 i;

    data->lifetime++;
    data->timeLeft--;
    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = data->lifetime;

    if (time > 10) {
        data->alpha *= 0.9;
    }

    data++;
    for (i = 1; i < effect->numParts; i++, data++) {
        if (time > 10) {
            data->scaleY += (1.0 - data->scaleY) * 0.1;
            data->scaleX += (2.4f - data->scaleX) * 0.1;
            data->unk_30 += ((100.0f - data->unk_30) * 0.07) * 0.2;
        }
        if (time < 10) {
            data->scaleY += (7.0f - data->scaleY) * 0.05;
            data->scaleX += (1.0f - data->scaleX) * 0.1;
            data->unk_30 += ((10.0f - data->unk_30) * 0.05) * 0.6;
        }
        data->pos.x = cos_deg(data->rotZ + 90.0f) * data->unk_30;
        data->pos.y = sin_deg(data->rotZ + 90.0f) * data->unk_30;
    }
}

void debuff_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = debuff_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void debuff_appendGfx(void* effect) {
    EffectInstance* eff = (EffectInstance*)effect;
    DebuffFXData* data = eff->data.debuff;
    Gfx* dlist = D_E00628C0[0];
    Gfx* dlist2 = D_E00628C4[0];
    Matrix4f mtxTranslate;
    Matrix4f mtxRotate;
    Matrix4f mtxTransform;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(eff->shared->graphics));
    gSPDisplayList(gMainGfxPos++, dlist2);

    guTranslateF(mtxTranslate, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(mtxRotate, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtxRotate, mtxTranslate, mtxTransform);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++,
              &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primCol.r, data->primCol.g, data->primCol.b, data->alpha);
    gDPSetEnvColor(gMainGfxPos++, data->envCol.r, data->envCol.g, data->envCol.b, 0);

    data++;
    for (i = 1; i < eff->numParts; i++, data++) {
        guTranslateF(mtxTranslate, data->pos.x, data->pos.y, data->pos.z);
        guRotateF(mtxRotate, data->rotZ, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxRotate, mtxTranslate, mtxTranslate);
        guScaleF(mtxRotate, data->scaleX, data->scaleY, 1.0f);
        guMtxCatF(mtxRotate, mtxTranslate, mtxTranslate);
        guMtxF2L(mtxTranslate, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++,
                  &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
