#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000A00_373DE0[];
extern Gfx D_09000B88_373F68[];
extern Gfx D_09000C00_373FE0[];
extern Gfx D_09000C20_374000[];

Gfx* D_E006EC00[] = { D_09000B88_373F68, D_09000B88_373F68, D_09000B88_373F68 };
Gfx* D_E006EC0C[] = { D_09000A00_373DE0, D_09000A00_373DE0, D_09000A00_373DE0 };

void fire_breath_init(EffectInstance* effect);
void fire_breath_update(EffectInstance* effect);
void fire_breath_render(EffectInstance* effect);
void fire_breath_appendGfx(void* effect);

EffectInstance* fire_breath_main(
    s32 type,
    f32 startX, f32 startY, f32 startZ,
    f32 endX, f32 endY, f32 endZ,
    s32 numExtra, s32 spawnDelay, s32 lifetime
) {
    EffectBlueprint bp;
    FireBreathFXData* data;
    EffectInstance* effect;
    s32 numParts = 1;
    s32* temp_a0;
    f32 phi_f0;

    bp.unk_00 = 0;
    bp.init = fire_breath_init;
    bp.update = fire_breath_update;
    bp.renderWorld = fire_breath_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_FIRE_BREATH;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.fireBreath = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.fireBreath != NULL);

    data->type = type;
    data->numChildren = numExtra;
    data->spawnDelay = spawnDelay;
    data->pos.x = startX;
    data->pos.y = startY;
    data->pos.z = startZ;
    data->initPos.x = startX;
    data->initPos.y = startY;
    data->initPos.z = startZ;
    data->endPos.x = endX;
    data->endPos.y = endY;
    data->endPos.z = endZ;

    if (type == FIRE_BREATH_LARGE) {
        data->scale = 0.05f;
    } else {
        data->scale = 0.04f;
    }

    data->unk_30 = data->scale;
    data->lifeTime = lifetime;
    data->timeLeft = lifetime;
    data->spawnTimer = 0;
    data->alpha = 255;
    data->unk_5C = 0.0f;
    data->scaleChangeFactor = 0.1f;
    data->unk_34 = data->unk_30;

    if (type == FIRE_BREATH_LARGE) {
        data->unk_50.x = (endX - startX) * 0.2 * (func_E0200044(10, spawnDelay + 0) - 5) * 0.2;
        data->unk_50.y = (endY - startY) * 0.2 * (func_E0200044(10, spawnDelay + 1) - 5) * 0.2;
        data->unk_50.z = (endZ - startZ) * 0.2 * (func_E0200044(10, spawnDelay + 2) - 5) * 0.2;
    } else {
        data->unk_50.x = (endX - startX) * 0.2 * (func_E0200044(10, spawnDelay + 3) - 5);
        data->unk_50.y = (endY - startY) * 0.2 * (func_E0200044(10, spawnDelay + 4) - 5);
        data->unk_50.z = (endZ - startZ) * 0.2 * (func_E0200044(10, spawnDelay + 5) - 5);
    }

    data->primR = 255;
    data->primG = 170;
    data->primB = 42;
    data->unk_60 = 0.0f;
    data->envR = 243;
    data->envG = 48;
    data->envB = 0;

    return effect;
}

void fire_breath_init(EffectInstance* effect) {
}

void fire_breath_update(EffectInstance* effect) {
    FireBreathFXData* data = effect->data.fireBreath;
    s32 lifeTime;
    s32 timeLeft;
    s32 spawnTimer;

    data->timeLeft--;
    data->unk_5C = (data->spawnTimer * 4.0f) / 10.0f;
    data->spawnTimer++;

    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    timeLeft = data->timeLeft;
    lifeTime = data->lifeTime;
    spawnTimer = data->spawnTimer;

    if (timeLeft >= 6 && data->type == FIRE_BREATH_LARGE) {
        data->scale += (2.5 - data->scale) * 0.05;
    }

    data->pos.x = data->initPos.x + (((data->endPos.x - data->initPos.x + data->unk_50.x) * spawnTimer) / lifeTime);
    data->pos.y = data->initPos.y + (((data->endPos.y - data->initPos.y + data->unk_50.y) * spawnTimer) / lifeTime);
    data->pos.z = data->initPos.z + (((data->endPos.z - data->initPos.z + data->unk_50.z) * spawnTimer) / lifeTime);

    if (data->type == FIRE_BREATH_SMALL) {
        data->unk_60 += (f32) spawnTimer * 0.01;
        data->pos.y += data->unk_60;
    }

    if (spawnTimer == data->spawnDelay + 1 && data->numChildren > 0) {
        EffectInstance* spawned;

        load_effect(EFFECT_FIRE_BREATH);
        spawned = fire_breath_main(
            data->type, data->initPos.x, data->initPos.y, data->initPos.z, data->endPos.x, data->endPos.y,
            data->endPos.z, data->numChildren - 1, data->spawnDelay, lifeTime
        );

        spawned->data.fireBreath->primR = data->primR;
        spawned->data.fireBreath->primG = data->primG;
        spawned->data.fireBreath->primB = data->primB;
        spawned->data.fireBreath->envR = data->envR;
        spawned->data.fireBreath->envG = data->envG;
        spawned->data.fireBreath->envB = data->envB;
        spawned->data.fireBreath->unk_30 = spawned->data.fireBreath->scale = data->unk_30;
        spawned->data.fireBreath->unk_34 = data->unk_34;
        spawned->data.fireBreath->scaleChangeFactor = data->scaleChangeFactor;
    }

    if (timeLeft < 10 && data->type == FIRE_BREATH_LARGE) {
        data->alpha = timeLeft * 25;
    }

    if (data->type == FIRE_BREATH_SMALL) {
        data->scale += (0.3 - data->scale) * 0.008;
        data->alpha = (timeLeft * 224) / lifeTime;
    }

    if (data->type == FIRE_BREATH_TINY) {
        data->scale += (data->unk_34 - data->scale) * data->scaleChangeFactor;
        data->alpha = (timeLeft * 224) / lifeTime;
    }
}

void fire_breath_render(EffectInstance* effect) {
    FireBreathFXData* data = effect->data.fireBreath;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = fire_breath_appendGfx;
    renderTask.appendGfxArg = effect;

    if (gGameStatusPtr->isBattle == TRUE) {
        renderTask.dist = data->pos.z + 1000.0f;
    } else {
        renderTask.dist = 0;
    }

    renderTaskPointer->renderMode = RENDER_MODE_2D;
    retTask = queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void fire_breath_appendGfx(void* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    FireBreathFXData* data = ((EffectInstance*)effect)->data.fireBreath;
    s32 type = data->type;
    s32 envAlpha = (data->unk_5C - (s32)data->unk_5C) * 256.0f;
    Gfx* dlist = D_E006EC00[type];
    Gfx* dlist2 = D_E006EC0C[type];
    s32 unk_5C = data->unk_5C;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    if (type == FIRE_BREATH_SMALL) {
        guTranslateF(sp18, data->initPos.x, data->initPos.y, data->initPos.z);
        guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_09000C20_374000);
        gSPDisplayList(gMainGfxPos++, D_09000C00_373FE0);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPDisplayList(gMainGfxPos++, dlist2);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primR, data->primG, data->primB, data->alpha);
    gDPSetEnvColor(gMainGfxPos++, data->envR, data->envG, data->envB, envAlpha);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, ((unk_5C * 32) + 0)  * 4, 0, ((unk_5C * 32) + 32) * 4, 128);
    gDPSetTileSize(gMainGfxPos++, 1,               ((unk_5C * 32) + 32) * 4, 0, ((unk_5C * 32) + 64) * 4, 128);

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guScaleF(sp58, data->scale, data->scale, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, dlist);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
