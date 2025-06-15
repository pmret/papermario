#include "common.h"
#include "effects_internal.h"

extern Vtx D_09002D40_3ADD70[][6]; // TODO confirm this type is correct
extern Gfx D_09003880_3AE8B0[];
extern Gfx D_090038F8_3AE928[];
extern Gfx D_09003968_3AE998[];
extern Gfx D_090039D8_3AEA08[];
extern Gfx D_09003A48_3AEA78[];
extern Gfx D_09003AB8_3AEAE8[];
extern Gfx D_09003B28_3AEB58[];
extern Gfx D_09003B98_3AEBC8[];
extern Gfx D_09003C08_3AEC38[];
extern Gfx D_09003C78_3AECA8[];
extern Gfx D_09003CE8_3AED18[];
extern Gfx D_09003D58_3AED88[];
extern Gfx D_09003DC8_3AEDF8[];

Gfx* D_E00AA6C0[11] = {
    D_090038F8_3AE928, D_09003968_3AE998, D_090039D8_3AEA08, D_09003A48_3AEA78, D_09003AB8_3AEAE8, D_09003B28_3AEB58, D_09003B98_3AEBC8, D_09003C08_3AEC38, D_09003C78_3AECA8, D_09003CE8_3AED18, D_09003D58_3AED88
};

s8 D_E00AA6EC[] = {
    -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -17, -15, -13, -11, -9, -7, -5, -3, -1, 0, 0, 0, 0, 0, 0, 0, 0
};

void butterflies_init(EffectInstance* effect);
void butterflies_update(EffectInstance* effect);
void butterflies_render(EffectInstance* effect);
void butterflies_appendGfx(void* effect);

EffectInstance* butterflies_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    ButterfliesFXData* part;
    s32 numParts = 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = butterflies_init;
    bp.update = butterflies_update;
    bp.renderScene = butterflies_render;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_BUTTERFLIES;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.butterflies = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.butterflies != nullptr);

    part->unk_04 = 1000;
    part->unk_00 = arg0;
    part->unk_24 = 255;
    part->unk_0C = arg1;
    part->unk_18 = arg1;
    part->unk_10 = arg2;
    part->unk_1C = arg2;
    part->unk_14 = arg3;
    part->unk_20 = arg3;
    part->unk_08 = 0;
    part->unk_2C = 0;
    part->unk_30 = 0;
    part->unk_34 = 50.0f;
    part->unk_38 = 30.0f;
    return effect;
}

void butterflies_init(EffectInstance* effect) {
}

void butterflies_update(EffectInstance* effect) {
    ButterfliesFXData* temp_s0;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;
    f32 var_f12;
    f32 var_f20;
    f32 var_f22;
    f32 var_f24;

    temp_s0 = effect->data.butterflies;
    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        temp_s0->unk_04 = 900;
    }

    if (temp_s0->unk_04 < 1000) {
        temp_s0->unk_04--;
    }
    temp_s0->unk_08++;
    if (temp_s0->unk_04 < 0) {
        remove_effect(effect);
        return;
    }
    if (temp_s0->unk_04 < 0x10) {
        temp_s0->unk_24 = temp_s0->unk_04 * 0x10;
    }

    temp_s0->unk_30--;
    if (temp_s0->unk_30 <= 0) {
        s32 t;

        temp_f20 = rand_int(359);
        temp_f24 = temp_s0->unk_18 + (temp_s0->unk_34 * sin_deg(temp_f20));
        temp_f22 = temp_s0->unk_1C + rand_int(temp_s0->unk_38);
        temp_f20_2 = temp_s0->unk_20 + (temp_s0->unk_34 * cos_deg(temp_f20));
        t = rand_int(100) + 10;
        temp_f4 = temp_s0->unk_0C;
        temp_f6 = temp_s0->unk_10;
        temp_f8 = temp_s0->unk_14;
        var_f24 = temp_f24 - temp_f4;
        var_f22 = temp_f22 - temp_f6;
        var_f20 = temp_f20_2 - temp_f8;
        temp_s0->unk_30 = t;
        if (var_f24 == 0.0f && var_f22 == 0.0f && var_f20 == 0.0f) {
            var_f24 = temp_s0->unk_18 - temp_f4;
            var_f22 = temp_s0->unk_1C - temp_f6;
            var_f20 = temp_s0->unk_20 - temp_f8;
            if (var_f24 == 0.0f && var_f22 == 0.0f && var_f20 == 0.0f) {
                var_f24 = 1.0f;
                var_f20 = 0.0f;
                var_f22 = 0.0f;
            }
        }
        var_f12 = SQ(var_f24) + SQ(var_f22) + SQ(var_f20);
        if (var_f12 != 0.0f) {
            var_f12 = 1.0f / sqrtf(var_f12);
        }
        var_f24 *= var_f12;
        var_f22 *= var_f12;
        var_f20 *= var_f12;
        temp_s0->unk_3C = var_f24;
        temp_s0->unk_40 = var_f22;
        temp_s0->unk_44 = var_f20;
        temp_s0->unk_28 = atan2(0.0f, 0.0f, -temp_s0->unk_3C, temp_s0->unk_44);
    }
    temp_s0->unk_2C += 3;
    if (temp_s0->unk_2C >= 30) {
        temp_s0->unk_2C -= 30;
    }
    temp_s0->unk_0C += temp_s0->unk_3C;
    temp_s0->unk_10 += temp_s0->unk_40;
    temp_s0->unk_14 += temp_s0->unk_44;
}

void butterflies_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = butterflies_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void butterflies_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    ButterfliesFXData* data = effectTemp->data.butterflies;
    Matrix4f sp18;
    Matrix4f sp58;

    s32 primColor = data->unk_24;
    s32 type = data->unk_00;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->shared->graphics));

    guTranslateF(sp18, data->unk_0C, data->unk_10 + D_E00AA6EC[data->unk_2C] * 0.3f, data->unk_14);
    guRotateF(sp58, data->unk_28, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guScaleF(sp58, 0.02f, 0.02f, 0.02f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, primColor, primColor, primColor, 255);
    gSPDisplayList(gMainGfxPos++, D_09003880_3AE8B0);
    gSPDisplayList(gMainGfxPos++, D_E00AA6C0[type]);
    gSPVertex(gMainGfxPos++, &D_09002D40_3ADD70[data->unk_2C], 6, 0);
    gSPDisplayList(gMainGfxPos++, D_09003DC8_3AEDF8);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
