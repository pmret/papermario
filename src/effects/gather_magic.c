#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000080_38F790[];
extern Gfx D_090001A8_38F8B8[];
extern Gfx D_090001C8_38F8D8[];

Gfx* D_E008E890[] = { D_090001A8_38F8B8, D_090001C8_38F8D8 };

void gather_magic_appendGfx(void* effect);
void gather_magic_init(EffectInstance* effect);
void gather_magic_update(EffectInstance* effect);
void gather_magic_render(EffectInstance* effect);

EffectInstance* gather_magic_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    GatherMagicFXData* data;
    s32 numParts = 31;
    s32 i;

    bp.unk_00 = 0;
    bp.init = gather_magic_init;
    bp.update = gather_magic_update;
    bp.renderScene = gather_magic_render;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_GATHER_MAGIC;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = general_heap_malloc(numParts * sizeof(*data));
    effect->data.gatherMagic = data;
    ASSERT(effect->data.gatherMagic != nullptr);

    data->unk_04 = arg0;
    data->unk_1C = 0;
    if (arg5 <= 0) {
        data->unk_18 = 100;
    } else {
        data->unk_18 = arg5;
    }
    data->unk_14 = 0;
    data->unk_08 = arg1;
    data->unk_0C = arg2;
    data->unk_10 = arg3;

    if (arg0 == 0) {
        data->unk_30 = 255;
        data->unk_34 = 0;
        data->unk_38 = 255;
        data->unk_3C = 255;
        data->unk_40 = 255;
        data->unk_44 = 255;
    } else {
        data->unk_30 = 255;
        data->unk_34 = 20;
        data->unk_38 = 33;
        data->unk_3C = 50;
        data->unk_40 = 20;
        data->unk_44 = 10;
    }

    data++;
    for (i = 1; i < numParts; i++, data++) {
        s32 d = numParts - 1;
        f32 zero = 0.0f;

        data->unk_20 = ((i - 1) * 3240) / d;
        data->unk_24 = zero;
        data->unk_2C = ((i - 1) * 100) / d;
        data->unk_00 = 0;
    }
    return effect;
}

void gather_magic_init(EffectInstance* effect) {
}

void gather_magic_update(EffectInstance* effect) {
    GatherMagicFXData* part = effect->data.gatherMagic;
    s32 unk_1C;
    s32 i;

    if (part->unk_18 < 100) {
        part->unk_18--;
    }

    part->unk_1C++;

    if (part->unk_18 < 0) {
        remove_effect(effect);
        return;
    }

    unk_1C = part->unk_1C;

    if (unk_1C < 21) {
        part->unk_14 = unk_1C * 12;
    } else {
        part->unk_14 = 255;
    }

    if (unk_1C % 2) {
        part->unk_14 *= 0.5;
    }

    unk_1C = part->unk_1C;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        f32 unk_20 = part->unk_20;
        f32 unk_2C = part->unk_2C;
        f32 unk_24 = part->unk_24;
        f32 sin_20 = sin_deg(unk_20);
        f32 cos_20 = cos_deg(unk_20);
        f32 sin_24 = sin_deg(unk_24);
        f32 cos_24 = cos_deg(unk_24);

        part->unk_08 = unk_2C * sin_20 * cos_24;
        part->unk_0C = unk_2C * cos_20 * cos_24;
        part->unk_10 = unk_2C * sin_24;

        part->unk_14 = ((100.0f - part->unk_2C) * 255.0f * 2.0f) / 100.0f;
        if (part->unk_14 >= 256) {
            part->unk_14 = 255;
        }

        part->unk_28 = part->unk_2C / 80.0f + 0.2;
        part->unk_2C -= (i & 3) * 2 + 2;

        if (part->unk_2C < 0.0f) {
            part->unk_2C = 0.0f;
            part->unk_28 = 0.0f;
        }

        part->unk_20 += (unk_1C % 2) ? 5.0f : 2.0f;
        part->unk_24 += (unk_1C % 2) ? 2.0f : 5.0f;
    }
}

void gather_magic_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = gather_magic_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void gather_magic_appendGfx(void* effect) {
    GatherMagicFXData* part = ((EffectInstance*)effect)->data.gatherMagic;
    s32 unk_30 = part->unk_30;
    s32 unk_34 = part->unk_34;
    s32 unk_38 = part->unk_38;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp18, part->unk_08, part->unk_0C, part->unk_10);
    guRotateF(sp98, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp98, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_09000080_38F790);
    gDPSetEnvColor(gMainGfxPos++, part->unk_3C, part->unk_40, part->unk_44, 0);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        f32 scale = part->unk_28;

        if (scale != 0.0f) {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, unk_30, unk_34, unk_38, part->unk_14);

            guTranslateF(sp18, part->unk_08, part->unk_0C, part->unk_10);
            guScaleF(sp58, scale, scale, scale);
            guMtxCatF(sp58, sp18, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_E008E890[i & 1]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
