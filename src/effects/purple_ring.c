#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000200_352EE0[];
extern Gfx D_090004E8_3531C8[];

void purple_ring_init(EffectInstance* effect);
void purple_ring_update(EffectInstance* effect);
void purple_ring_render(EffectInstance* effect);
void purple_ring_appendGfx(void* effect);

EffectInstance* purple_ring_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    f32 arg6,
    f32 arg7
) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    PurpleRingFXData* data;
    s32 numParts = 1;
    f32 temp_f12;
    f32 sp68;
    f32 sp6C;
    f32 sp70;
    f32 var_f24;
    f32 var_f20;
    f32 var_f22;
    Matrix4f unused;

    if (arg4 == 0.0f && arg5 == 0.0f && arg6 == 0.0f) {
        return NULL;
    }

    temp_f12 = SQ(arg4) + SQ(arg5) + SQ(arg6);
    if (temp_f12 == 0.0f) {
        return NULL;
    }

    temp_f12 = 1.0f / sqrtf(temp_f12);
    arg4 *= temp_f12;
    arg5 *= temp_f12;
    arg6 *= temp_f12;

    if (arg4 != 0.0f) {
        var_f20 = -arg4;
        var_f22 = arg6;
        var_f24 = 0.0f;
    } else if (arg6 != 0.0f) {
        var_f20 = -arg4;
        var_f22 = arg6;
        var_f24 = 0.0f;
    } else {
        var_f20 = 0.0f;
        var_f22 = 1.0f;
        var_f24 = 0.0f;
    }

    temp_f12 = SQ(var_f22) + SQ(var_f24) + SQ(var_f20);
    if (temp_f12 == 0.0f) {
        return NULL;
    }

    temp_f12 = 1.0f / sqrtf(temp_f12);
    var_f22 *= temp_f12;
    var_f24 *= temp_f12;
    var_f20 *= temp_f12;

    sp68 = var_f24 * arg6 - var_f20 * arg5;
    sp6C = var_f20 * arg4 - var_f22 * arg6;
    sp70 = var_f22 * arg5 - var_f24 * arg4;

    temp_f12 = SQ(sp68) + SQ(sp6C) + SQ(sp70);
    if (temp_f12 == 0.0f) {
        return NULL;
    }

    temp_f12 = 1.0f / sqrtf(temp_f12);
    sp68 *= temp_f12;
    sp6C *= temp_f12;
    sp70 *= temp_f12;

    bpPtr->init = purple_ring_init;
    bpPtr->update = purple_ring_update;
    bpPtr->renderWorld = purple_ring_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_PURPLE_RING;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    data = effect->data.purpleRing = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.purpleRing != NULL);

    data->unk_00 = arg0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_68 = 0;
    data->unk_6C = 16;
    data->unk_70 = 0;
    data->unk_74 = 248;
    data->unk_75 = 92;
    data->unk_76 = 229;
    data->unk_77 = 248;
    data->unk_78 = 92;
    data->unk_79 = 229;
    data->unk_10 = -arg4 * 4.0f;
    data->unk_14 = -arg5 * 4.0f;
    data->unk_18 = -arg6 * 4.0f;
    data->unk_1C[0][0] = var_f22;
    data->unk_1C[0][1] = var_f24;
    data->unk_1C[0][2] = var_f20;
    data->unk_1C[0][3] = 0;
    data->unk_1C[1][0] = sp68;
    data->unk_1C[1][1] = sp6C;
    data->unk_1C[1][2] = sp70;
    data->unk_1C[1][3] = 0;
    data->unk_1C[2][0] = arg4;
    data->unk_1C[2][1] = arg5;
    data->unk_1C[2][2] = arg6;
    data->unk_1C[2][3] = 0;
    data->unk_1C[3][0] = 0;
    data->unk_1C[3][1] = 0;
    data->unk_1C[3][2] = 0;
    data->unk_5C = 278.0f;
    data->unk_60 = 32.0f;
    data->unk_1C[3][3] = 1.0f;
    data->unk_64 = arg7 * 0.1;

    return effect;
}

void purple_ring_init(EffectInstance* effect) {
}

void purple_ring_update(EffectInstance* effect) {
    PurpleRingFXData* part = effect->data.purpleRing;
    s32 unk_6C;
    s32 i;

    part->unk_6C--;
    part->unk_70++;

    if (part->unk_6C < 0) {
        remove_effect(effect);
        return;
    }

    unk_6C = part->unk_6C;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (unk_6C >= 6) {
            part->unk_68 += (255 - part->unk_68) * 0.3;
            part->unk_10 *= 0.8;
            part->unk_14 *= 0.8;
            part->unk_18 *= 0.8;
        }
        if (unk_6C < 5) {
            part->unk_68 *= 0.6;
            part->unk_10 *= 0.7;
            part->unk_14 *= 0.7;
            part->unk_18 *= 0.7;
        }
        part->unk_04 += part->unk_10;
        part->unk_08 += part->unk_14;
        part->unk_0C += part->unk_18;
        part->unk_5C += part->unk_60;
        part->unk_64 *= 1.05;
    }
}

void purple_ring_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = purple_ring_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void purple_ring_appendGfx(void* effect) {
    PurpleRingFXData* data = ((EffectInstance*)effect)->data.purpleRing;
    s32 unk_5C = data->unk_5C;
    s32 temp = 64;
    Matrix4f sp10;
    Matrix4f sp50;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000200_352EE0);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_74, data->unk_75, data->unk_76, data->unk_68);

    guTranslateF(sp10, data->unk_04, data->unk_08, data->unk_0C);
    guMtxCatF(data->unk_1C, sp10, sp10);
    guScaleF(sp50, data->unk_64, data->unk_64, data->unk_64);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, unk_5C, temp * 4, unk_5C + temp);
    gSPDisplayList(gMainGfxPos++, D_090004E8_3531C8);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
