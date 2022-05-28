#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002000[];
extern Gfx D_090020E8[];
extern Gfx D_090021D0[];
extern Gfx D_090023B0[];
extern Gfx D_090023C8[];
extern Gfx D_090023E0[];
extern Gfx D_090023F8[];
extern Gfx D_09002410[];
extern Gfx D_09002428[];
extern Gfx D_09002440[];
extern Gfx D_09002458[];

Gfx* D_E0076E90[] = { D_090023E0, D_090023E0, D_09002440, D_09002440 };
Gfx* D_E0076EA0[] = { D_090023F8, D_090023F8, D_09002458, D_09002458 };
Gfx* D_E0076EB0[] = { D_090023B0, D_090023B0, D_09002410, D_09002410 };
Gfx* D_E0076EC0[] = { D_090023C8, D_090023C8, D_09002428, D_09002428 };
Gfx* D_E0076ED0[] = { D_09002000, D_09002000, D_090020E8, D_090021D0 };

void aura_appendGfx(void* effect);
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
    bp.unk_14 = 0;
    bp.effectID = EFFECT_AURA;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;

    part = effect->data = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data != NULL);

    part->unk_64.s = 0;

    zero = part->unk_64.f;
    part->unk_40 = zero;
    part->unk_34 = zero;
    part->unk_58 = zero;
    part->unk_4C = zero;

    part->unk_2C = 100;
    part->type = arg0;
    part->unk_30 = 0;
    part->primA = 0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;

    switch (arg0) {
        case 0:
            part->primR = 75;
            part->primG = 75;
            part->primB = 75;
            part->envR = 255;
            part->envG = 247;
            part->engB = 155;
            part->engA = 0;
            part->unk_24 = arg4;
            part->unk_20 = arg4 * 0.6;
            part->unk_1C = arg4 * 2.0;
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
            part->unk_1C = arg4;
            part->unk_20 = arg4;
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
            part->unk_1C = arg4;
            part->unk_20 = arg4;
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
            part->unk_1C = arg4;
            part->unk_20 = arg4;
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

    part->unk_10 = part->pos.x;
    part->unk_14 = part->pos.y;
    part->unk_18 = part->pos.z;

    *outEffect = effect;
}

void aura_init(EffectInstance* effect) {
}

void aura_update(EffectInstance* effect) {
    AuraFXData* data;
    s32 type;
    s32 unk_2C;
    s32 unk_30;

    data = effect->data;
    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_2C = 5;
    }

    data->unk_30++;
    if (data->unk_30 > 324000) {
        data->unk_30 = 256;
    }

    if (data->unk_2C <= 10) {
        data->unk_2C--;
    }

    if (data->unk_2C < 0) {
        shim_remove_effect(effect);
        return;
    }

    type = data->type;
    unk_2C = data->unk_2C;
    unk_30 = data->unk_30;

    if (type < 2) {
        if (unk_30 <= 10) {
            data->primA += (128 - data->primA) * 0.5;
        }
    } else {
        if (unk_30 <= 10) {
            data->primA = (unk_30 * 0xFF) / 10;
        }
    }

    if (unk_2C < 10) {
        data->primA *= 0.5;
    }

    if (type == 0) {
        data->unk_38 += (data->unk_3C - data->unk_38) * 0.02;
        data->unk_44 += (data->unk_48 - data->unk_44) * 0.02;
        data->unk_1C += (data->unk_24 - data->unk_1C) * 0.04;
        data->unk_20 += (data->unk_24 - data->unk_20) * 0.04;
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

    data->unk_10 += (data->pos.x - data->unk_10) * 0.1;
    data->unk_14 += (data->pos.y - data->unk_14) * 0.1;
    data->unk_18 += (data->pos.z - data->unk_18) * 0.1;
}

void aura_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = aura_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E007684C(void) {
}

void func_E0076854(void) {
}

void aura_appendGfx(void* effect) {
    Matrix4f sp18, sp58, sp98;
    EffectInstance* eff = (EffectInstance*)effect;
    AuraFXData* data = ((EffectInstance*)effect)->data;
    s32 type = data->type;
    s32 primA = data->primA;
    s32 v1, v2;

    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, D_E0076ED0[type]);

    shim_guTranslateF(sp18, data->unk_10, data->unk_14, data->unk_18);
    if (type == 2) {
        shim_guRotateF(sp58, data->unk_64.f, 0.0f, 1.0f, 0.0f);
    } else {
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    }
    shim_guMtxCatF(sp58, sp18, sp98);
    shim_guScaleF(sp58, data->unk_1C, data->unk_20, 1.0f);
    shim_guMtxCatF(sp58, sp98, sp98);
    if (type == 0) {
        shim_guTranslateF(sp58, (-(data->unk_1C - data->unk_24) / data->unk_24) * 10.0f, 0.0f, 0.0f);
        shim_guMtxCatF(sp58, sp98, sp98);
    }
    shim_guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_E0076EC0[type]);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

    shim_guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    if (type == 2) {
        shim_guRotateF(sp58, data->unk_64.f, 0.0f, 1.0f, 0.0f);
    } else {
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    }
    shim_guMtxCatF(sp58, sp18, sp98);
    shim_guScaleF(sp58, data->unk_1C, data->unk_20, 1.0f);
    shim_guMtxCatF(sp58, sp98, sp98);
    if (type == 0) {
        shim_guTranslateF(sp58, (-(data->unk_1C - data->unk_24) / data->unk_24) * 10.0f, 0.0f, 0.0f);
        shim_guMtxCatF(sp58, sp98, sp98);
    }
    shim_guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_E0076EB0[type]);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->primR, data->primG, data->primB, primA);
    gDPSetEnvColor(gMasterGfxPos++, data->envR, data->envG, data->engB, data->engA);

    v1 = data->unk_34 * 4.0f;
    v2 = data->unk_40 * 4.0f;

    gDPSetTileSize(gMasterGfxPos++, 1, v1, v2, v1 + 124, v2 + 508);
    gSPDisplayList(gMasterGfxPos++, D_E0076E90[type]);

    v1 = data->unk_4C * 4.0f;
    v2 = data->unk_58 * 4.0f;

    gDPSetTileSize(gMasterGfxPos++, 1, v1 + 30, v2 + 30, v1 + 282, v2 + 538);
    gSPDisplayList(gMasterGfxPos++, D_E0076EA0[type]);
    gDPPipeSync(gMasterGfxPos++);
}
