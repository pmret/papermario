#include "common.h"
#include "effects_internal.h"

u8 D_E00B2BA0[] = { 255, 255, 255, 255, 255, 255, 255, 255, 255, 200, 128, 32, 0, 0, 0, 0 };

void squirt_init(EffectInstance* effect);
void squirt_update(EffectInstance* effect);
void squirt_render(EffectInstance* effect);
void squirt_appendGfx(void* effect);

extern Gfx D_09000800_3B5B40[];
extern Gfx D_090008A8_3B5BE8[];

EffectInstance* squirt_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SquirtFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = squirt_init;
    bp.update = squirt_update;
    bp.renderWorld = squirt_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_SQUIRT;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.squirt = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.squirt != NULL);

    data->unk_00 = arg0;
    data->unk_30 = 0;
    if (arg8 <= 0) {
        data->unk_2C = 1000;
    } else if (arg0 == 0) {
        data->unk_2C = arg8 * 2;
    } else {
        data->unk_2C = arg8 * 4;
    }
    data->unk_28 = arg8;
    if (arg0 == 0) {
        data->unk_40 = 200;
    } else {
        data->unk_40 = 255;
    }
    data->unk_10 = arg1;
    data->unk_14 = arg2;
    data->unk_18 = arg3;
    data->unk_04 = data->unk_10;
    data->unk_08 = data->unk_14;
    data->unk_0C = data->unk_18;
    data->unk_1C = arg4;
    data->unk_20 = arg5;
    data->unk_24 = arg6;
    data->unk_50 = arg7;
    data->unk_34 = 210;
    data->unk_38 = 230;
    data->unk_3C = 255;
    data->unk_44 = 0;
    data->unk_48 = 30;
    data->unk_4C = 205;
    data->unk_54 = 0;

    for (i = 0; i < 12; i++) {
        data->unk_58[i] = 10.0f;
        data->unk_88[i] = 2.0f;
        data->unk_B8[i] = 0;
        if (arg0 == 0) {
            data->unk_178[i] = i + 1;
        } else {
            data->unk_178[i] = i * 5 + 1;
        }
        data->unk_E8[i] = data->unk_04;
        data->unk_118[i] = data->unk_08;
        data->unk_148[i] = data->unk_0C;
        data->unk_1A8[i] = 0;
    }

    return effect;
}

void squirt_init(EffectInstance* effect) {
}

void squirt_update(EffectInstance* effect) {
    SquirtFXData* data = effect->data.squirt;
    s32 unk_00 = data->unk_00;
    s32 unk_28;
    s32 var_v1;
    f32 factor;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_2C = 16;
    }

    if (data->unk_2C < 1000) {
        data->unk_2C--;
    }

    data->unk_30++;

    if (data->unk_2C < 0) {
        remove_effect(effect);
        return;
    }

    unk_28 = data->unk_28;

    data->unk_54++;
    if (data->unk_54 > 12) {
        data->unk_54 = 12;
    }

    for (i = 0; i < 12; i++) {
        if (data->unk_178[i] == 0 || --data->unk_178[i] == 0) {
            data->unk_1A8[i]++;
            if (data->unk_1A8[i] >= unk_28) {
                var_v1 = unk_28;
            } else {
                var_v1 = data->unk_1A8[i];
            }

            factor = (f32) var_v1 / unk_28;

            if (unk_00 == 0) {
                data->unk_E8[i] = data->unk_10 + (data->unk_1C - data->unk_10) * factor;
                data->unk_118[i] = data->unk_14 + (data->unk_20 - data->unk_14) * factor;
                data->unk_148[i] = data->unk_18 + (data->unk_24 - data->unk_18) * factor;
            } else {
                data->unk_E8[i] = data->unk_10 + (data->unk_1C - data->unk_10) * factor;
                data->unk_118[i] = data->unk_14 + (data->unk_20 - data->unk_14) * factor + sin_deg(factor * 180.0f) * 120.0f;
                data->unk_148[i] = data->unk_18 + (data->unk_24 - data->unk_18) * factor;
                data->unk_1D8[i] = 255.0f - factor * 255.0f;
            }
        }
    }
}

void squirt_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = squirt_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00B24A8(void) {
}

void squirt_appendGfx(void* effect) {
    SquirtFXData* data = ((EffectInstance*)effect)->data.squirt;
    s32 zero = 0;
    s32 unk_00 = data->unk_00;
    Gfx* savedGfxPos;
    f32 unk_50 = data->unk_50;
    Matrix4f sp10, sp50;
    Vtx_t* vtx;
    s32 savedIdx;
    s32 i;

    f32 cosComp;
    f32 sinComp;
    f32 var_f22;
    f32 theta;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp10, 0.0f, 0.0f, 0.0f);
    guScaleF(sp50, 0.05f, 0.05f, 0.05f);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_34, data->unk_38, data->unk_3C, data->unk_40);
    gDPSetEnvColor(gMainGfxPos++, data->unk_44, data->unk_48, data->unk_4C, 200);

    gSPBranchList(gMainGfxPos, &gMainGfxPos[49]);
    savedGfxPos = gMainGfxPos + 1;

    gMainGfxPos = &gMainGfxPos[49];

    vtx = (Vtx_t*) savedGfxPos;
    for (i = 0; i < 12; i++) {
        s32 inc = i + 1;
        s32 tc0;
        s32 cnA;

        if (i == 0 || zero == i || (i != 11 && data->unk_178[i] == 0)) {
            theta = data->unk_118[inc];
            theta = -atan2(theta, -data->unk_E8[i + 1], data->unk_118[i], -data->unk_E8[i]);
        }

        if (data->unk_00 == 0) {
            var_f22 = ((f32) data->unk_1A8[i] * 0.5) + 2.0;
            if (var_f22 > 6.0f) {
                var_f22 = 6.0f;
            }
            cnA = D_E00B2BA0[i];
        } else {
            var_f22 = ((f32) data->unk_1A8[i] * 0.5) + 1.0;
            if (var_f22 > 30.0f) {
                do {} while (0); // TODO required to match
                var_f22 = 30.0f;
            }
            cnA = (D_E00B2BA0[i] * data->unk_1D8[i]) / 255;
        }
        tc0 = i * 5;
        tc0 *= 64;

        var_f22 *= unk_50;
        sinComp = var_f22 * sin_deg(theta);
        cosComp = var_f22 * cos_deg(theta);

        vtx->ob[0] = (data->unk_E8[i] + sinComp) * 20.0f;
        vtx->ob[1] = (data->unk_118[i] + cosComp) * 20.0f;
        vtx->ob[2] = (data->unk_148[i] + 0.0f) * 20.0f;
        vtx->tc[0] = tc0;
        vtx->tc[1] = 0;
        vtx->cn[0] = (i & 1) * 255;
        vtx->cn[1] = ((i >> 1) & 1) * 255;
        vtx->cn[2] = ((i >> 2) & 1) * 255;
        vtx->cn[3] = cnA;
        vtx++;

        vtx->ob[0] = (data->unk_E8[i] - sinComp) * 20.0f;
        vtx->ob[1] = (data->unk_118[i] - cosComp) * 20.0f;
        vtx->ob[2] = (data->unk_148[i] + 0.0f) * 20.0f;
        vtx->tc[0] = tc0;
        vtx->tc[1] = 1024;
        vtx->cn[0] = (i & 1) * 255;
        vtx->cn[1] = ((i >> 1) & 1) * 255;
        vtx->cn[2] = ((i >> 2) & 1) * 255;
        vtx->cn[3] = cnA;
        vtx++;
    }

    gSPVertex(gMainGfxPos++, savedGfxPos, i * 2, 0);

    savedIdx = i;
    gSPDisplayList(gMainGfxPos++, unk_00 == 0 ? D_09000800_3B5B40 : D_090008A8_3B5BE8);

    for (i = 0; i < savedIdx - 1; i++) {
        s32 i2 = i * 2;

        if (i < zero) {
            continue;
        }
        gSP2Triangles(gMainGfxPos++,
            i2,     i2 + 2, i2 + 1, i2,
            i2 + 1, i2 + 2, i2 + 3, i2);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
