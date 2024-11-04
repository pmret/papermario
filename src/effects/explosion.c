#include "common.h"
#include "effects_internal.h"

void explosion_init(EffectInstance* effect);
void explosion_update(EffectInstance* effect);
void explosion_render(EffectInstance* effect);
void explosion_appendGfx(void* effect);

extern Gfx D_09000840_3447B0[];
extern Gfx D_090008F0_344860[];
extern Gfx D_09000910_344880[];
extern Gfx D_09000978_3448E8[];
extern Gfx D_090009D8_344948[];
extern Gfx D_09000A38_3449A8[];

Gfx* D_E00328B0[] = { D_09000978_3448E8, D_090009D8_344948, D_09000A38_3449A8 };

void explosion_main(s32 type, f32 x, f32 y, f32 z) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    ExplosionFXData* data;
    s32 numParts = 3;

    // TODO this terrible if-else required to match
    s32 dumb;
    s32 temp;
    if (type != 0) {
        dumb = 0;
    } else {
        temp = 0;
        dumb = temp;
    }

    bpPtr->unk_00 = 0;
    bpPtr->init = explosion_init;
    bpPtr->update = explosion_update;
    bpPtr->renderScene = explosion_render;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_EXPLOSION;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    effect->data.explosion = data = general_heap_malloc(effect->numParts * sizeof(*data));
    ASSERT(effect->data.explosion != NULL);

    data->pos.x = x;
    data->pos.y = y;
    data->pos.z = z;
    data->unk_34 = 0;
    data->unk_30 = 60;
    data->unk_00 = type;

    data++;
    data->unk_00 = type;
    if (type == 0) {
        data->unk_00 = -1;
    }
    data->unk_38 = 0;
    if (type == 1) {
        data->unk_20 = 1.0f;
    } else {
        data->unk_20 = 3.0f;
    }
    if (type == 1) {
        data->unk_24 = 1.0f;
    } else {
        data->unk_24 = 3.0f;
    }

    data++;
    data->unk_00 = type;
    data->unk_38 = 255;
    switch (type) {
        case 0:
            data->unk_20 = 9.9f;
            data->unk_24 = 1.6f;
            break;
        case 1:
            data->unk_20 = 13.9f;
            data->unk_24 = 2.4f;
            break;
        default:
            data->unk_20 = 17.8f;
            data->unk_24 = 3.2f;
            break;
    }
    data->unk_28 = 0.0f;
    data->unk_2C = 30.0f;
}

void explosion_init(EffectInstance* effect) {
}

EFFECT_DEF_SMOKE_RING(smoke_ring_main);
EFFECT_DEF_CONFETTI(confetti_main);

void explosion_update(EffectInstance* effect) {
    ExplosionFXData* part = effect->data.explosion;
    s32 unk_00;
    s32 unk_34;

    part->unk_30--;
    if (part->unk_30 < 0) {
        remove_effect(effect);
        return;
    }

    part->unk_34++;

    unk_00 = part->unk_00;
    unk_34 = part->unk_34;

    if (unk_34 == 7) {
        load_effect(EFFECT_SMOKE_RING);
        smoke_ring_main(unk_00, part->pos.x, part->pos.y, part->pos.z);
    } else if (unk_34 == 1) {
        load_effect(EFFECT_CONFETTI);
        confetti_main(unk_00 + 4, part->pos.x, part->pos.y, part->pos.z, 1.0f, 50);
    }

    part++;

    part->unk_20 += part->unk_24;

    if (unk_34 < 8) {
        part->unk_24 += (unk_00 == 2) ? 1.0f : 0.4;
        part->unk_38 = (255 - part->unk_38) * 0.6;
    } else {
        part->unk_24 *= 0.6;
        part->unk_38 *= 0.9;
    }

    part++;

    if (unk_34 >= 3) {
        if (unk_34 == 3) {
            part->unk_20 = 1.0f;
        }
        part->unk_20 += part->unk_24;
        if (unk_34 < 6) {
            part->unk_24 += 0.1;
        } else {
            part->unk_24 *= 0.5;
            part->unk_38 *= 0.9;
        }
    }

    part->unk_28 += part->unk_2C;
}

void explosion_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = explosion_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
}

void explosion_appendGfx(void* effect) {
    ExplosionFXData* part = ((EffectInstance*)effect)->data.explosion;
    s32 unk_34 = part->unk_34;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 primAlpha;
    s32 primB;
    s32 cond;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    part++;

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (part->unk_00 != -1) {
        gSPDisplayList(gMainGfxPos++, D_09000840_3447B0);

        guScaleF(sp18, part->unk_20, part->unk_20, 1.0f);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 240, part->unk_38);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_090008F0_344860);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    part++;

    gSPDisplayList(gMainGfxPos++, D_09000910_344880);

    guScaleF(sp18, part->unk_20, part->unk_20, part->unk_20);
    guRotateF(sp58, part->unk_28, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    switch (unk_34) {
        default:
            primAlpha = part->unk_38;
            break;
        case 2:
            primAlpha = 255;
            break;
        case 1:
            primAlpha = 192;
            break;
    }

    cond = (unk_34 < 3); // required to match
    if (!cond && unk_34 < 8) {
        primB = unk_34 * 16 + 128;
    } else {
        primB = 255;
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, primB, primAlpha);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_E00328B0[unk_34 % 3]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
