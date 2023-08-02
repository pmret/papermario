#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000280_3E1550[];
extern Gfx D_090003A0_3E1670[];

Gfx* D_E00E6880[] = { D_090003A0_3E1670, D_090003A0_3E1670 };
Gfx* D_E00E6888[] = { D_09000280_3E1550, D_09000280_3E1550 };

// number of frames in animation for type 0 and type 1
s32 StaticEffectFrameCount[] = { 24, 12 };

f32 StaticEffectScaleVals0[] = {
     0.9f, 1.0f,  1.0f, 0.9f, 0.85f, 0.8f, 0.75f, 0.7f, 0.65f,  0.6f, 0.55f,  0.5f,
    0.45f, 0.4f, 0.35f, 0.3f, 0.25f, 0.2f, 0.15f, 0.1f, 0.05f, 0.03f, 0.02f, 0.01f
};

u8 StaticEffectAlphaVals0[] = {
    0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

f32 StaticEffectScaleVals1[] = {
    0.9f, 1.0f, 1.0f, 0.9f, 0.8f, 0.7f, 0.6f, 0.5f, 0.4f, 0.3f, 0.2f, 0.1f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
};

u8 StaticEffectAlphaVals1[] = {
    0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void static_status_init(EffectInstance* effect);
void static_status_update(EffectInstance* effect);
void static_status_render(EffectInstance* effect);
void static_status_appendGfx(void* effect);

EffectInstance* static_status_main(
    s32 type,
    f32 x,
    f32 y,
    f32 z,
    f32 scale,
    s32 numBolts,
    s32 duration)
{
    EffectBlueprint bp;
    EffectInstance* effect;
    StaticStatusFXData* part;
    f32 invisTime;
    s32 i;

    numBolts++;

    bp.init = static_status_init;
    bp.update = static_status_update;
    bp.renderWorld = static_status_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_STATIC_STATUS;

    effect = create_effect_instance(&bp);
    effect->numParts = numBolts;
    part = effect->data.staticStatus = general_heap_malloc(numBolts * sizeof(*part));
    ASSERT(effect->data.staticStatus != NULL);

    part->type = type;
    part->lifetime = 0;
    if (duration <= 0) {
        part->timeLeft = 1000;
    } else {
        part->timeLeft = duration;
    }
    part->alpha = 255;
    part->pos.x = x;
    part->pos.y = y;
    part->pos.z = z;
    part->scale = scale;

    invisTime = StaticEffectFrameCount[type] * 0.5f;

    part++;
    for (i = 1; i < numBolts; i++, part++) {
        part->frame = -1.0f - invisTime * (i & 1);
    }

    return effect;
}

void static_status_init(EffectInstance* effect) {
}

void static_status_update(EffectInstance* effect) {
    StaticStatusFXData* part = effect->data.staticStatus;
    s32 type = part->type;
    s32 unk_28;
    s32 time;
    f32 interpAmt;
    f32 initialAmt;
    f32 angle;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->timeLeft = 16;
    }

    if (part->timeLeft < 1000) {
        part->timeLeft--;
    }

    part->lifetime++;

    if (part->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = part->lifetime;

    if (part->timeLeft < 16) {
        part->alpha = part->timeLeft * 16;
    }

    if (type == 0) {
        initialAmt = 0.1f;
        interpAmt = 0.2f;
    } else {
        initialAmt = 0.2f;
        interpAmt = 0.2f;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->frame++;
        if (part->frame >= StaticEffectFrameCount[type]) {
            part->frame = 0;
        }

        if (part->frame >= 0) {
            if (part->frame == 0) {
                angle = (i * 360.0f) / (effect->numParts - 1);
                part->pos.x = sin_deg(angle) * 16.0f;
                part->pos.y = cos_deg(angle) * 16.0f;
                part->unk_10 = part->pos.x * initialAmt;
                part->unk_14 = part->pos.y * initialAmt;
                part->unk_18 = 0.0f;
                part->unk_1C = 0.0f;
                part->scale = 1.0f;
                part->rot = -angle - 45.0f;
            }

            if (type == 0) {
                part->alpha = StaticEffectAlphaVals0[part->frame];
                part->scale = StaticEffectScaleVals0[part->frame];
            } else {
                part->alpha = StaticEffectAlphaVals1[part->frame];
                part->scale = StaticEffectScaleVals1[part->frame];
            }

            if ((time & 1) == (i & 1)) {
                part->pos.x += part->unk_10;
                part->pos.y += part->unk_14;
            } else {
                part->pos.x += part->unk_10 * 0.2;
                part->pos.y += part->unk_14 * 0.2;
            }

            part->unk_10 += (part->unk_18 - part->unk_10) * interpAmt;
            part->unk_14 += (part->unk_1C - part->unk_14) * interpAmt;
        }
    }
}

void static_status_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = static_status_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00E651C(void) {
}

void static_status_appendGfx(void* effect) {
    StaticStatusFXData* part = ((EffectInstance*)effect)->data.staticStatus;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_30 = part->alpha;
    s32 unk_00 = part->type;
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(mtxTransform, part->pos.x, part->pos.y, part->pos.z);
    guScaleF(mtxTemp, part->scale, part->scale, part->scale);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_E00E6888[unk_00]);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->frame >= 0) {
            guPositionF(mtxTransform, 0.0f, 0.0f, part->rot, part->scale, part->pos.x, part->pos.y, 0.0f);
            guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, (unk_30 * part->alpha) >> 8);
            gSPDisplayList(gMainGfxPos++, D_E00E6880[unk_00]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
