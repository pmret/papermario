#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002000_379F80[];
extern Gfx D_090020E8_37A068[];
extern Gfx D_090021D0_37A150[];
extern Gfx D_090023B0_37A330[];
extern Gfx D_090023C8_37A348[];
extern Gfx D_090023E0_37A360[];
extern Gfx D_090023F8_37A378[];
extern Gfx D_09002410_37A390[];
extern Gfx D_09002428_37A3A8[];
extern Gfx D_09002440_37A3C0[];
extern Gfx D_09002458_37A3D8[];

Gfx* D_E0076E90[] = { D_090023E0_37A360, D_090023E0_37A360, D_09002440_37A3C0, D_09002440_37A3C0 };
Gfx* D_E0076EA0[] = { D_090023F8_37A378, D_090023F8_37A378, D_09002458_37A3D8, D_09002458_37A3D8 };
Gfx* D_E0076EB0[] = { D_090023B0_37A330, D_090023B0_37A330, D_09002410_37A390, D_09002410_37A390 };
Gfx* D_E0076EC0[] = { D_090023C8_37A348, D_090023C8_37A348, D_09002428_37A3A8, D_09002428_37A3A8 };
Gfx* D_E0076ED0[] = { D_09002000_379F80, D_09002000_379F80, D_090020E8_37A068, D_090021D0_37A150 };

void aura_appendGfx(void* argEffect);
void aura_init(EffectInstance* effect);
void aura_update(EffectInstance* effect);
void aura_render(EffectInstance* effect);

void aura_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, EffectInstance** outEffect) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    AuraFXData* part;
    s32 numParts = 1;
    f32 zero;

    bp.init = aura_init;
    bp.update = aura_update;
    bp.renderWorld = aura_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_AURA;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;

    part = effect->data.aura = general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.aura != NULL);

    part->renderYaw = 0.0f;

    zero = 0.0f;
    part->unk_40 = zero;
    part->unk_34 = zero;
    part->unk_58 = zero;
    part->unk_4C = zero;

    part->fadeTime = 100;
    part->type = arg0;
    part->lifeTime = 0;
    part->primA = 0;
    part->posA.x = arg1;
    part->posA.y = arg2;
    part->posA.z = arg3;

    switch (arg0) {
        case 0:
            part->primR = 75;
            part->primG = 75;
            part->primB = 75;
            part->envR = 255;
            part->envG = 247;
            part->engB = 155;
            part->engA = 0;
            part->scale.x = arg4 * 2.0;
            part->scale.y = arg4 * 0.6;
            part->unk_24 = arg4;
            part->unk_38 = -0.9f;
            part->unk_44 = 0.04f;
            part->unk_3C = 0.04f;
            part->unk_48 = 0.9f;
            part->unk_50 = -0.9f;
            part->unk_5C = 0.04f;
            part->unk_54 = 0.04f;
            part->unk_60 = 0.9f;
            break;
        case 1:
            part->primR = 75;
            part->primG = 75;
            part->primB = 75;
            part->envR = 255;
            part->envG = 0;
            part->engB = 0;
            part->engA = 0;
            part->scale.x = arg4;
            part->scale.y = arg4;
            part->unk_24 = arg4;
            part->unk_38 = zero;
            part->unk_50 = zero;
            part->unk_44 = 0.04f;
            part->unk_3C = 0.04f;
            part->unk_48 = 0.9f;
            part->unk_5C = 0.04f;
            part->unk_54 = 0.04f;
            part->unk_60 = 0.9f;
            break;
        case 2:
            part->primR = 25;
            part->primG = 121;
            part->primB = 142;
            part->envR = 34;
            part->engB = 255;
            part->envG = 0;
            part->engA = 81;
            part->scale.x = arg4;
            part->scale.y = arg4;
            part->unk_24 = arg4;
            part->unk_38 = zero;
            part->unk_50 = zero;
            part->unk_44 = 0.04f;
            part->unk_3C = 0.2f;
            part->unk_48 = 1.3f;
            part->unk_5C = 0.04f;
            part->unk_54 = 0.16f;
            part->unk_60 = 1.04f;
            break;
        default:
            part->primR = 179;
            part->primG = 169;
            part->primB = 85;
            part->envR = 34;
            part->engB = 255;
            part->envG = 0;
            part->engA = 63;
            part->scale.x = arg4;
            part->scale.y = arg4;
            part->unk_24 = arg4;
            part->unk_38 = 0.0f;
            part->unk_50 = 0.0f;
            part->unk_44 = 0.04f;
            part->unk_3C = 0.1f;
            part->unk_48 = 1.7f;
            part->unk_5C = 0.04f;
            part->unk_54 = 0.08f;
            part->unk_60 = 1.36f;
            break;
    }

    part->posB.x = part->posA.x;
    part->posB.y = part->posA.y;
    part->posB.z = part->posA.z;

    *outEffect = effect;
}

void aura_init(EffectInstance* effect) {
}

void aura_update(EffectInstance* effect) {
    AuraFXData* data;
    s32 type;
    s32 fadeTime;
    s32 lifeTime;

    data = effect->data.aura;
    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->fadeTime = 5;
    }

    data->lifeTime++;
    if (data->lifeTime > 90*60*60) {
        data->lifeTime = 256;
    }

    if (data->fadeTime <= 10) {
        data->fadeTime--;
    }

    if (data->fadeTime < 0) {
        remove_effect(effect);
        return;
    }

    type = data->type;
    fadeTime = data->fadeTime;
    lifeTime = data->lifeTime;

    if (type < 2) {
        if (lifeTime <= 10) {
            data->primA += (128 - data->primA) * 0.5;
        }
    } else {
        if (lifeTime <= 10) {
            data->primA = (lifeTime * 0xFF) / 10;
        }
    }

    if (fadeTime < 10) {
        data->primA *= 0.5;
    }

    if (type == 0) {
        data->unk_38 += (data->unk_3C - data->unk_38) * 0.02;
        data->unk_44 += (data->unk_48 - data->unk_44) * 0.02;
        data->scale.x += (data->unk_24 - data->scale.x) * 0.04;
        data->scale.y += (data->unk_24 - data->scale.y) * 0.04;
    } else {
        data->unk_38 += (data->unk_3C - data->unk_38) * 0.02;
        data->unk_44 += (data->unk_48 - data->unk_44) * 0.02;
        data->unk_50 += (data->unk_54 - data->unk_50) * 0.02;
        data->unk_5C += (data->unk_60 - data->unk_5C) * 0.02;
    }

    data->unk_34 += data->unk_38;
    if (data->unk_34 < 0.0f) {
        data->unk_34 += 64.0f;
    } else if (data->unk_34 > 64.0f) {
        data->unk_34 -= 64.0f;
    }

    data->unk_40 += data->unk_44;
    if (data->unk_40 < 0.0f) {
        data->unk_40 += 128.0f;
    } else if (data->unk_40 > 128.0f) {
        data->unk_40 -= 128.0f;
    }

    data->unk_4C += data->unk_50;
    if (data->unk_4C < 0.0f) {
        data->unk_4C += 64.0f;
    } else if (data->unk_4C > 64.0f) {
        data->unk_4C -= 64.0f;
    }

    data->unk_58 += data->unk_5C;
    if (data->unk_58 < 0.0f) {
        data->unk_58 += 128.0f;
    } else if (data->unk_58 > 128.0f) {
        data->unk_58 -= 128.0f;
    }

    data->posB.x += (data->posA.x - data->posB.x) * 0.1;
    data->posB.y += (data->posA.y - data->posB.y) * 0.1;
    data->posB.z += (data->posA.z - data->posB.z) * 0.1;
}

void aura_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = aura_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E007684C(void) {
}

void func_E0076854(void) {
}

void aura_appendGfx(void* argEffect) {
    Matrix4f translateMtx, tempMtx, transformMtx;
    EffectInstance* effect = argEffect;
    AuraFXData* data = effect->data.aura;
    s32 type = data->type;
    s32 primA = data->primA;
    s32 v1, v2;

    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_E0076ED0[type]);

    guTranslateF(translateMtx, data->posB.x, data->posB.y, data->posB.z);
    if (type == 2) {
        guRotateF(tempMtx, data->renderYaw, 0.0f, 1.0f, 0.0f);
    } else {
        guRotateF(tempMtx, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    }
    guMtxCatF(tempMtx, translateMtx, transformMtx);
    guScaleF(tempMtx, data->scale.x, data->scale.y, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    if (type == 0) {
        guTranslateF(tempMtx, (-(data->scale.x - data->unk_24) / data->unk_24) * 10.0f, 0.0f, 0.0f);
        guMtxCatF(tempMtx, transformMtx, transformMtx);
    }
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_E0076EC0[type]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

    guTranslateF(translateMtx, data->posA.x, data->posA.y, data->posA.z);
    if (type == 2) {
        guRotateF(tempMtx, data->renderYaw, 0.0f, 1.0f, 0.0f);
    } else {
        guRotateF(tempMtx, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    }
    guMtxCatF(tempMtx, translateMtx, transformMtx);
    guScaleF(tempMtx, data->scale.x, data->scale.y, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    if (type == 0) {
        guTranslateF(tempMtx, (-(data->scale.x - data->unk_24) / data->unk_24) * 10.0f, 0.0f, 0.0f);
        guMtxCatF(tempMtx, transformMtx, transformMtx);
    }
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_E0076EB0[type]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primR, data->primG, data->primB, primA);
    gDPSetEnvColor(gMainGfxPos++, data->envR, data->envG, data->engB, data->engA);

    v1 = data->unk_34 * 4.0f;
    v2 = data->unk_40 * 4.0f;

    gDPSetTileSize(gMainGfxPos++, 1, v1, v2, v1 + 124, v2 + 508);
    gSPDisplayList(gMainGfxPos++, D_E0076E90[type]);

    v1 = data->unk_4C * 4.0f;
    v2 = data->unk_58 * 4.0f;

    gDPSetTileSize(gMainGfxPos++, 1, v1 + 30, v2 + 30, v1 + 282, v2 + 538);
    gSPDisplayList(gMainGfxPos++, D_E0076EA0[type]);
    gDPPipeSync(gMainGfxPos++);
}
