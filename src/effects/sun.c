#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000898_40C438[];
extern Gfx D_09000980_40C520[];
extern Gfx D_09000998_40C538[];
extern Gfx D_090009B0_40C550[];
extern Gfx D_090009C8_40C568[];
extern Gfx D_090009E0_40C580[];

Gfx* D_E0120780[] = {
    D_09000980_40C520, D_09000998_40C538, D_090009B0_40C550,
    D_090009C8_40C568, D_090009E0_40C580
};

Gfx* D_E0120794[] = { D_09000898_40C438 };

void sun_init(EffectInstance* effect);
void sun_update(EffectInstance* effect);
void sun_render(EffectInstance* effect);
void sun_appendGfx(void* effect);

EffectInstance* sun_main(s32 shineFromRight, f32 offsetX, f32 offsetY, f32 offsetZ, f32 arg4, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SunFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = sun_init;
    bp.update = sun_update;
    bp.renderWorld = sun_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_SUN;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;

    data = effect->data.sun = general_heap_malloc(sizeof(*data));
    ASSERT(data != NULL);

    data->shineFromRight = shineFromRight;
    data->lifeTime = 0;
    if (duration <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = duration;
    }
    data->pos.x = offsetX;
    data->pos.y = offsetY;
    data->pos.z = offsetZ;
    data->unk_34 = arg4;
    data->primColor.r = 255;
    data->primColor.g = 255;
    data->primColor.b = 255;
    data->envColor.r = 255;
    data->envColor.g = 255;
    data->envColor.b = 255;
    data->envColor.a = 255;

    for (i = 0; i < ARRAY_COUNT(data->texScrollAmt); i++) {
        data->texScrollAmt[i] = 0.0f;
    }
    data->targetAlpha = 255;
    data->alpha = 0;

    return effect;
}

void sun_init(EffectInstance* effect) {
}

void sun_update(EffectInstance* effect) {
    SunFXData* data = effect->data.sun;
    s32 time;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifeTime++;
    if (data->lifeTime > 90*60*60) {
        data->lifeTime = 256;
    }
    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = data->lifeTime;
    if (data->timeLeft < 16) {
        data->alpha -= 16;
        if (data->alpha < 0) {
            data->alpha = 0;
        }
    }
    if (data->targetAlpha < 0) {
        data->targetAlpha = 0;
    } else if (data->targetAlpha > 255) {
        data->targetAlpha = 255;
    }

    if (data->alpha > data->targetAlpha) {
        data->alpha -= 8;
        if (data->alpha < data->targetAlpha) {
            data->alpha = data->targetAlpha;
        }
    } else if (data->alpha < data->targetAlpha) {
        data->alpha += 8;
        if (data->targetAlpha < data->alpha) {
            data->alpha = data->targetAlpha;
        }
    }

    for (i = 0; i < 5; i++) {
        data->texScrollAmt[i] -= 4.0
            * ((sin_deg((time * 2 + (20 * i))) * 0.01) + 0.05)
            * sin_deg(((f32) time * 0.25) + (SQ(i) * 20));

        if (data->texScrollAmt[i] < 0.0f) {
            data->texScrollAmt[i] += 256.0f;
        }
        if (data->texScrollAmt[i] > 256.0f) {
            data->texScrollAmt[i] -= 256.0f;
        }
    }
}

void sun_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sun_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void sun_appendGfx(void* argEffect) {
    EffectInstance* effect = (EffectInstance*) argEffect;
    SunFXData* data;
    Matrix4f mtx;
    Matrix4f mtxUnused;
    s32 alpha;
    s32 offsetS;
    s32 fromRight;
    s32 i;

    data = effect->data.sun;
    alpha = data->alpha;
    fromRight = data->shineFromRight;

    if (alpha != 0) {
        gDPPipeSync(gMainGfxPos++);
        gSPSegment(gMainGfxPos++, 0x9, VIRTUAL_TO_PHYSICAL(effect->graphics->data));

        if (!fromRight) {
            guOrthoF(mtx, -1600.0f, 1600.0f, -1200.0f, 1200.0f, -100.0f, 100.0f, 1.0f);
        } else {
            guOrthoF(mtx, 1600.0f, -1600.0f, -1200.0f, 1200.0f, -100.0f, 100.0f, 1.0f);
        }

        guMtxF2L(mtx, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
            G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        guTranslateF(mtx, 0.0f, 0.0f, 0.0f);
        guMtxF2L(mtx, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
            G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primColor.r, data->primColor.g, data->primColor.b, alpha >> 1);
        gDPSetEnvColor(gMainGfxPos++, data->envColor.r, data->envColor.g, data->envColor.b, data->envColor.a);
        gSPDisplayList(gMainGfxPos++, D_E0120794[0]);

        for (i = 0; i < ARRAY_COUNT(data->texScrollAmt); i++) {
            offsetS = data->texScrollAmt[i] * 4.0f;
            gDPSetTileSize(gMainGfxPos++, 1, offsetS + (44 * i), 0, offsetS + (44 * i) + 252, 124);
            gSPDisplayList(gMainGfxPos++, D_E0120780[i]);
        }
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID],
            G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gDPPipeSync(gMainGfxPos++);
    }
}
