#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000F20_338EE0[];
extern Gfx D_090011C8_339188[];
extern Gfx D_090011E0_3391A0[];
extern Gfx D_090011F8_3391B8[];
extern Gfx D_09001210_3391D0[];
extern Gfx D_09001228_3391E8[];
extern Gfx D_09001240_339200[];
extern Gfx D_09001258_339218[];
extern Gfx D_09001270_339230[];

Gfx* D_E0074B60[] = {
    D_09001210_3391D0, D_09001228_3391E8, D_09001240_339200, D_09001258_339218,
    D_09001270_339230, D_090011C8_339188, D_090011E0_3391A0, D_090011F8_3391B8
};

f32 D_E0074B80[] = {
    0.2f, 0.4f, 0.8f, 1.3f, 1.5f, 1.3f, 0.9f, 0.6f, 0.4f, 0.3f,
    0.2f, 0.4f, 0.8f, 1.3f, 1.5f, 1.3f, 0.9f, 0.6f, 0.4f, 0.3f
};

s32 D_E0074BD0[] = {
    0xC8FAFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFAC8, 0x00000000, 0x00000000, 0x00000000
};

void shimmer_wave_init(EffectInstance* effect);
void shimmer_wave_update(EffectInstance* effect);
void shimmer_wave_render(EffectInstance* effect);
void shimmer_wave_appendGfx(void* effect);

EffectInstance* shimmer_wave_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    s32 arg6,
    s32 arg7
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    ShimmerWaveFXData* part;
    f32 one = 1.0f;
    f32 temp;
    s32 i;

    arg6++;

    bp.init = shimmer_wave_init;
    bp.update = shimmer_wave_update;
    bp.renderWorld = shimmer_wave_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_SHIMMER_WAVE;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = arg6;
    part = effect->data.shimmerWave = shim_general_heap_malloc(arg6 * sizeof(*part));
    ASSERT(effect->data.shimmerWave != NULL);

    part->unk_00 = arg0;
    part->unk_3C = 0;
    if (arg7 <= 0) {
        part->unk_38 = 1000;
    } else {
        part->unk_38 = arg7;
    }
    part->unk_4C = 255;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_60 = one;
    part->unk_10 = arg4;
    part->unk_14 = arg5;
    part->unk_40 = 255;
    part->unk_44 = 255;
    part->unk_48 = 255;
    part->unk_50 = 255;
    part->unk_54 = 255;
    part->unk_58 = 127;
    part->unk_5C = 255;

    part++;

    if (arg7 < 20) {
        temp = 20.0f / (arg6 - 1);
    } else {
        temp = (f32) arg7 / (arg6 - 1);
    }

    for (i = 1; i < arg6; i++, part++) {
        part->unk_30 = (s32) (-(f32) i * temp) - 1;
    }

    return effect;
}

void shimmer_wave_init(EffectInstance* effect) {
}

void shimmer_wave_update(EffectInstance* effect) {
    ShimmerWaveFXData* part = effect->data.shimmerWave;
    f32 unk_10;
    f32 unk_14;
    s32 i;

    if (effect->flags & EFFECT_INSTANCE_FLAGS_10) {
        effect->flags &= ~EFFECT_INSTANCE_FLAGS_10;
        part->unk_38 = 16;
    }

    if (part->unk_38 < 1000) {
        part->unk_38--;
    }

    part->unk_3C++;

    if (part->unk_38 < 0) {
        shim_remove_effect(effect);
        return;
    }

    if (part->unk_38 < 8) {
        part->unk_4C = part->unk_38 * 32;
    }

    unk_10 = part->unk_10;
    unk_14 = part->unk_14;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_30++;
        if (part->unk_30 >= ARRAY_COUNT(D_E0074B80)) {
            part->unk_30 = 0;
        }

        if (part->unk_30 >= 0) {
            if (part->unk_30 == 0) {
                f32 rand = shim_rand_int(359);
                shim_rand_int(359);

                part->unk_04 = unk_10 * shim_sin_deg(rand);
                part->unk_08 = shim_rand_int(unk_14) - unk_14 * 0.5;
                part->unk_0C = unk_10 * shim_cos_deg(rand);
                part->unk_18 = shim_sin_deg(rand) * 15.0f;
                part->unk_1C = part->unk_08 * 0.4;
                part->unk_20 = shim_cos_deg(rand) * 15.0f;
                part->unk_24 = part->unk_18 * 0.5;
                part->unk_28 = part->unk_1C * 0.5;
                part->unk_2C = part->unk_20 * 0.5;
                part->unk_64 = shim_rand_int(15);
                part->unk_68 = shim_rand_int(15);
                part->unk_34 = 0.0f;
                part->unk_4C = 255;
            }

            part->unk_60 = 2.0f * D_E0074B80[part->unk_30];
            part->unk_34 += 4.0f;
            part->unk_04 += part->unk_18;
            part->unk_08 += part->unk_1C;
            part->unk_0C += part->unk_20;
            part->unk_64 += 0.2;
            part->unk_68 += 0.6;
            part->unk_18 += (part->unk_24 - part->unk_18) * 0.04;
            part->unk_1C += (part->unk_28 - part->unk_1C) * 0.04;
            part->unk_20 += (part->unk_2C - part->unk_20) * 0.04;
        }
    }
}

void shimmer_wave_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shimmer_wave_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void shimmer_wave_appendGfx(void* effect) {
    ShimmerWaveFXData* part = ((EffectInstance*)effect)->data.shimmerWave;
    s32 unk_50 = part->unk_50;
    s32 unk_54 = part->unk_54;
    s32 unk_58 = part->unk_58;
    f32 temp_4C = part->unk_4C / 255.0f;
    Gfx* savedGfxPos;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp20, part->unk_04, part->unk_08, part->unk_0C);
    shim_guScaleF(sp60, part->unk_60, part->unk_60, part->unk_60);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetEnvColor(gMasterGfxPos++, part->unk_40, part->unk_44, part->unk_48, part->unk_5C);
    gSPDisplayList(gMasterGfxPos++, D_09000F20_338EE0);

    savedGfxPos = gMasterGfxPos;
    gMasterGfxPos++;

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_30 >= 0) {
            shim_guPositionF(sp20, 0.0f, 0.0f, part->unk_34, part->unk_60 * temp_4C, part->unk_04, part->unk_08, part->unk_0C);
            shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, unk_50, unk_54, unk_58, part->unk_4C * temp_4C);
            gSPDisplayList(gMasterGfxPos++, D_E0074B60[i & 7]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPEndDisplayList(gMasterGfxPos++);
    gSPBranchList(savedGfxPos, gMasterGfxPos);
    gSPDisplayList(gMasterGfxPos++, savedGfxPos + 1);

    shim_guRotateF(sp20, 120.0f, 0.0f, 1.0f, 0.0f);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, savedGfxPos + 1);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

    shim_guRotateF(sp20, -120.0f, 0.0f, 1.0f, 0.0f);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, savedGfxPos + 1);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
