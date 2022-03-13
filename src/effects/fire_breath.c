#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000A00[];
extern Gfx D_09000B88[];
extern Gfx D_09000C00[];
extern Gfx D_09000C20[];

Gfx* D_E006EC00[] = { D_09000B88, D_09000B88, D_09000B88 };
Gfx* D_E006EC0C[] = { D_09000A00, D_09000A00, D_09000A00 };

void fire_breath_init(EffectInstance* effect);
void fire_breath_update(EffectInstance* effect);
void fire_breath_render(EffectInstance* effect);
void fire_breath_appendGfx(void* effect);

EffectInstance* fire_breath_main(s32 type, f32 startX, f32 startY, f32 startZ, f32 endX, f32 endY, f32 endZ,
                                 s32 numExtra, s32 spawnDelay, s32 lifetime)
{
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
    bp.unk_14 = 0;
    bp.effectID = EFFECT_FIRE_BREATH;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data != NULL);

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
    data->maxLifetime = lifetime;
    data->lifetime = lifetime;
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
    FireBreathFXData* data = effect->data;
    s32 maxLifetime;
    s32 lifetime;
    s32 spawnTimer;

    data->lifetime--;
    data->unk_5C = (data->spawnTimer * 4.0f) / 10.0f;
    data->spawnTimer++;

    if (data->lifetime < 0) {
        shim_remove_effect(effect);
        return;
    }

    lifetime = data->lifetime;
    maxLifetime = data->maxLifetime;
    spawnTimer = data->spawnTimer;

    if (lifetime >= 6 && data->type == FIRE_BREATH_LARGE) {
        data->scale += (2.5 - data->scale) * 0.05;
    }

    data->pos.x = data->initPos.x + ((((data->endPos.x - data->initPos.x) + data->unk_50.x) * spawnTimer) / maxLifetime);
    data->pos.y = data->initPos.y + ((((data->endPos.y - data->initPos.y) + data->unk_50.y) * spawnTimer) / maxLifetime);
    data->pos.z = data->initPos.z + ((((data->endPos.z - data->initPos.z) + data->unk_50.z) * spawnTimer) / maxLifetime);

    if (data->type == FIRE_BREATH_SMALL) {
        data->unk_60 += (f32) spawnTimer * 0.01;
        data->pos.y += data->unk_60;
    }

    if (spawnTimer == data->spawnDelay + 1 && data->numChildren > 0) {
        EffectInstance* spawned;

        shim_load_effect(EFFECT_FIRE_BREATH);
        spawned = fire_breath_main(
            data->type, data->initPos.x, data->initPos.y, data->initPos.z, data->endPos.x, data->endPos.y,
            data->endPos.z, data->numChildren - 1, data->spawnDelay, maxLifetime
        );

        spawned->data->primR = data->primR;
        spawned->data->primG = data->primG;
        spawned->data->primB = data->primB;
        spawned->data->envR = data->envR;
        spawned->data->envG = data->envG;
        spawned->data->envB = data->envB;
        spawned->data->unk_30 = spawned->data->scale = data->unk_30;
        spawned->data->unk_34 = data->unk_34;
        spawned->data->scaleChangeFactor = data->scaleChangeFactor;
    }

    if (lifetime < 10 && data->type == FIRE_BREATH_LARGE) {
        data->alpha = lifetime * 25;
    }

    if (data->type == FIRE_BREATH_SMALL) {
        data->scale += (0.3 - data->scale) * 0.008;
        data->alpha = (lifetime * 224) / maxLifetime;
    }

    if (data->type == FIRE_BREATH_TINY) {
        data->scale += (data->unk_34 - data->scale) * data->scaleChangeFactor;
        data->alpha = (lifetime * 224) / maxLifetime;
    }
}

void fire_breath_render(EffectInstance* effect) {
    FireBreathFXData* data = effect->data;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = fire_breath_appendGfx;
    renderTask.appendGfxArg = effect;

    if (gGameStatusPtr->isBattle == TRUE) {
        renderTask.distance = data->pos.z + 1000.0f;
    } else {
        renderTask.distance = 0;
    }

    renderTaskPointer->renderMode = RENDER_MODE_2D;
    retTask = shim_queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_MODE_2;
}

void fire_breath_appendGfx(void* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    FireBreathFXData* data = ((EffectInstance*)effect)->data;
    s32 type = data->type;
    s32 envAlpha = (data->unk_5C - (s32)data->unk_5C) * 256.0f;
    Gfx* dlist = D_E006EC00[type];
    Gfx* dlist2 = D_E006EC0C[type];
    s32 unk_5C = data->unk_5C;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    if (type == FIRE_BREATH_SMALL) {
        shim_guTranslateF(sp18, data->initPos.x, data->initPos.y, data->initPos.z);
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_09000C20);
        gSPDisplayList(gMasterGfxPos++, D_09000C00);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPDisplayList(gMasterGfxPos++, dlist2);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->primR, data->primG, data->primB, data->alpha);
    gDPSetEnvColor(gMasterGfxPos++, data->envR, data->envG, data->envB, envAlpha);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, ((unk_5C * 32) + 0)  * 4, 0, ((unk_5C * 32) + 32) * 4, 128);
    gDPSetTileSize(gMasterGfxPos++, 1,               ((unk_5C * 32) + 32) * 4, 0, ((unk_5C * 32) + 64) * 4, 128);

    shim_guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guScaleF(sp58, data->scale, data->scale, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, dlist);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
