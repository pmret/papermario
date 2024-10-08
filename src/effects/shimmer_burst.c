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

Gfx* D_E0070CD0[] = {
    D_09001210_3391D0, D_09001228_3391E8, D_09001240_339200, D_09001258_339218,
    D_09001270_339230, D_090011C8_339188, D_090011E0_3391A0, D_090011F8_3391B8
};

f32 D_E0070CF0[] = {
    0.2f, 0.4f, 0.8f, 1.3f, 1.5f, 1.3f, 0.9f, 0.6f, 0.4f, 0.3f,
    0.2f, 0.4f, 0.8f, 1.3f, 1.5f, 1.3f, 0.9f, 0.6f, 0.4f, 0.3f
};

s32 D_E0070D70[] = {
    0xC8FAFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFAC8, 0x00000000, 0x00000000, 0x00000000
};

void shimmer_burst_init(EffectInstance* effect);
void shimmer_burst_update(EffectInstance* effect);
void shimmer_burst_render(EffectInstance* effect);
void shimmer_burst_appendGfx(void* effect);

EffectInstance* shimmer_burst_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    ShimmerBurstFXData* part;
    s32 numParts = 61;
    s32 temp30 = 30;
    f32 temp;
    s32 i;

    bp.init = shimmer_burst_init;
    bp.update = shimmer_burst_update;
    bp.renderScene = shimmer_burst_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_SHIMMER_BURST;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.shimmerBurst = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.shimmerBurst != NULL);

    part->unk_00 = arg0;
    part->unk_3C = 0;
    if (arg5 <= 0) {
        part->unk_38 = 1000;
    } else {
        part->unk_38 = arg5;
    }
    part->unk_4C = 255;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_60 = arg4;
    part->unk_10 = temp30;
    part->unk_14 = temp30;
    part->unk_40 = 255;
    part->unk_44 = 255;
    part->unk_48 = 255;

    if (arg0 == 0) {
        part->unk_50 = 215;
        part->unk_54 = 255;
        part->unk_58 = 235;
        part->unk_5C = 255;
    } else {
        part->unk_50 = 255;
        part->unk_54 = 127;
        part->unk_58 = 255;
        part->unk_5C = 255;
    }

    part++;

    if (arg5 < 20) {
        temp = 20.0f / (numParts - 1);
    } else {
        temp = (f32) arg5 / (numParts - 1);
    }

    for (i = 1; i < numParts; i++, part++) {
        part->unk_30 = (s32) (-(f32) i * temp) - 1;
    }

    return effect;
}

void shimmer_burst_init(EffectInstance* effect) {
}

void shimmer_burst_update(EffectInstance* effect) {
    ShimmerBurstFXData* part = effect->data.shimmerBurst;
    s32 unk_00 = part->unk_00;
    f32 unk_10;
    f32 unk_14;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->unk_38 = 16;
    }

    if (part->unk_38 < 1000) {
        part->unk_38--;
    }

    part->unk_3C++;

    if (part->unk_38 < 0) {
        remove_effect(effect);
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
        if (part->unk_30 >= ARRAY_COUNT(D_E0070CF0)) {
            part->unk_30 = 0;
        }

        if (part->unk_30 >= 0) {
            if (part->unk_30 == 0) {
                f32 rand1 = rand_int(359);
                f32 rand2 = rand_int(359);

                if (unk_00 == 0) {
                    part->unk_04 = unk_10 * sin_deg(rand1) * cos_deg(rand2);
                    part->unk_08 = unk_14 * cos_deg(rand1) * cos_deg(rand2);
                    part->unk_0C = unk_10 * sin_deg(rand2);
                    part->unk_18 = part->unk_04 * 0.4;
                    part->unk_1C = part->unk_08 * 0.4;
                    part->unk_20 = part->unk_0C * 0.4;
                    part->unk_24 = part->unk_18 * 0.1;
                    part->unk_28 = part->unk_1C * 0.1;
                    part->unk_2C = part->unk_20 * 0.1;
                } else {
                    part->unk_04 = rand_int(unk_10) - unk_10 * 0.5;
                    part->unk_08 = rand_int(unk_14) - unk_14 * 0.5;
                    part->unk_0C = rand_int(unk_10) - unk_10 * 0.5;
                    part->unk_18 = part->unk_04 * 0.3;
                    part->unk_1C = part->unk_08 * 0.3;
                    part->unk_20 = part->unk_0C * 0.3;
                    part->unk_24 = part->unk_18 * 0.02;
                    part->unk_28 = part->unk_1C * 0.02;
                    part->unk_2C = part->unk_20 * 0.02;
                }

                part->unk_64 = rand_int(15);
                part->unk_68 = rand_int(15);
                part->unk_34 = 0.0f;
                part->unk_4C = 255;
            }

            part->unk_60 = D_E0070CF0[part->unk_30];
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

void shimmer_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shimmer_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E0070738(void) {
}

void shimmer_burst_appendGfx(void* effect) {
    ShimmerBurstFXData* part = ((EffectInstance*)effect)->data.shimmerBurst;
    s32 unk_50 = part->unk_50;
    s32 unk_54 = part->unk_54;
    s32 unk_58 = part->unk_58;
    f32 temp_f20 = part->unk_4C / 255.0f;
    Gfx* savedGfxPos;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp20, part->unk_04, part->unk_08, part->unk_0C);
    guScaleF(sp60, part->unk_60, part->unk_60, part->unk_60);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetEnvColor(gMainGfxPos++, part->unk_40, part->unk_44, part->unk_48, part->unk_5C);
    gSPDisplayList(gMainGfxPos++, D_09000F20_338EE0);

    savedGfxPos = gMainGfxPos;
    gMainGfxPos++;

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_30 >= 0) {
            guPositionF(sp20, 0.0f, 0.0f, part->unk_34, part->unk_60 * temp_f20, part->unk_04, part->unk_08, part->unk_0C);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, unk_50, unk_54, unk_58, part->unk_4C * temp_f20);
            gSPDisplayList(gMainGfxPos++, D_E0070CD0[i & 7]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPEndDisplayList(gMainGfxPos++);
    gSPBranchList(savedGfxPos, gMainGfxPos);
    gSPDisplayList(gMainGfxPos++, savedGfxPos + 1);

    guRotateF(sp20, 120.0f, 0.4f, 0.0f, 0.8f);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, savedGfxPos + 1);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

    guRotateF(sp20, -120.0f, 0.4f, 0.0f, 0.8f);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, savedGfxPos + 1);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
