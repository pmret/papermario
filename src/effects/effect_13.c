#include "common.h"
#include "effects_internal.h"

s32 D_E001A610 = 0;

extern Gfx D_090002F0[];

void fx_13_init(EffectInstance* effect);
void fx_13_update(EffectInstance* effect);
void fx_13_render(EffectInstance* effect);
void fx_13_appendGfx(EffectInstance* effect);

void fx_13_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect13* part;
    s32 numParts = 1;
    f32 phi_f6;

    bp.unk_00 = 0;
    bp.init = fx_13_init;
    bp.update = fx_13_update;
    bp.renderWorld = fx_13_render;
    bp.unk_14 = 0;
    bp.effectIndex = 13;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = 1;
    part = effect->data = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data != NULL);

    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_0C = arg3;
    part->unk_10 = 0.0f;
    part->unk_14 = 0.0f;
    part->unk_18 = 0;
    part->unk_08 = arg2 + 10.0f;

    if (arg0 == 0) {
        part->unk_18 = 0;
        part->unk_24 = 0.0f;
        part->unk_28 = 0.0f;
        part->unk_1C = 0.12f;
        part->unk_20 = -0.0152f;
        part->unk_2C = 3.0f;
        if (D_E001A610 != 0) {
            phi_f6 = -10.0f;
        } else {
            phi_f6 = 10.0f;
        }
        part->unk_30 = phi_f6;
        part->unk_34 = arg4;
    } else {
        part->unk_1C = 0.12f;
        part->unk_20 = -0.0152f;
        part->unk_24 = (shim_rand_int(1) * 30) - 15;
        part->unk_28 = shim_rand_int(360);
        part->unk_2C = 0;
        part->unk_30 = (shim_rand_int(1) * 8) - 4;
        part->unk_34 = arg4;
        part->unk_38 = 0;
        part->unk_44 = shim_rand_int(10);
        part->unk_40 = shim_rand_int(20);
        part->unk_3C = (shim_rand_int(1) * 2) - 1;
    }

    D_E001A610++;
    if (D_E001A610 >= 2) {
        D_E001A610 = 0;
    }
}

void fx_13_init(EffectInstance* effect) {
}

void fx_13_update(EffectInstance* effect) {
    Effect13* data = effect->data;
    s32 unk_00 = data->unk_00;

    if (data->unk_34 < 150) {
        data->unk_10 -= 0.001;
        data->unk_04 += data->unk_10;
        data->unk_0C += data->unk_18;
        data->unk_24 += data->unk_2C;
        if (unk_00 == 0) {
            if (data->unk_24 < 10.0f) {
                data->unk_24 = 10.0f;
                data->unk_2C = -data->unk_2C;
            }
            if (data->unk_24 > 45.0f) {
                data->unk_24 = 45.0f;
                data->unk_2C = -data->unk_2C;
            }
        }
        data->unk_28 += data->unk_30;
        if (unk_00 == 0) {
            data->unk_14 = 1.4f;
        } else {
            data->unk_14 = 1.0f;
        }
    } else {
        data->unk_20 += 0.0007;
        data->unk_1C += data->unk_20;
        data->unk_14 += data->unk_1C;
        if (data->unk_14 > 1.0f) {
            data->unk_14 = 1.0f;
        }
    }

    if (unk_00 == 1) {
        data->unk_40 += data->unk_3C;
        if (data->unk_40 >= 20) {
            data->unk_40 = 20;
            data->unk_3C = -1;
        } else if (data->unk_40 <= 0) {
            data->unk_40 = 0;
            data->unk_3C = unk_00;
        }
    }
    data->unk_08 += data->unk_14;
    data->unk_34 += -1;
    data->unk_38 += 1;
    if (data->unk_34 < 0) {
        shim_remove_effect(effect);
    }
}

void fx_13_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_13_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void fx_13_appendGfx(EffectInstance* effect) {
    Matrix4f sp20, other;
    EffectInstance* effectTemp = effect;
    Effect13* part = effect->data;
    u32 alpha;
    u8 rgb, a;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->effect->data));

    shim_guPositionF(sp20, part->unk_24, part->unk_28, 0.0f, 1.0f, part->unk_04, part->unk_08, part->unk_0C);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    a = alpha = 255;

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (*D_801512F0 == 1) {
        shim_get_background_color_blend(&rgb, &rgb, &rgb, &a);
        alpha -= a;
    }

    if (alpha != 0) {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);
        gSPDisplayList(gMasterGfxPos++, D_090002F0);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
}
