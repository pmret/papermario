#include "common.h"
#include "effects_internal.h"

extern Gfx D_090037A8_3C1148[];
extern Gfx D_09003818_3C11B8[];

s8 D_E00C0A10[] = {
    100,  90,  82,  76,  72,  70,  74, 89, 103, 116,
    118, 120, 120, 120, 120, 118, 114
};

s8 D_E00C0A21 = 110;

u8 D_E00C0A24[] = {
    100,  90,  82,  76,  72,  70,  74,  89, 100, 108,
    110, 108, 102,  96,  95,  96,  99, 101, 100, 100,
    100, 100, 100, 100, 100, 100, 100
};

u8 D_E00C0A40[] = {
    100,  90,  82,  76,  72,  70,  70,  70,  70,  70,
     70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
     70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
     70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
     70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
     70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
     70,  70,  74,  89, 103, 116, 118, 120, 120, 120,
    120, 118, 114, 110
};

s8 D_E00C0A8C[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 0x0A, 0x10, 0x16, 0x1C, 0x21, 0x26, 0x28, 0x29,
    0x29, 0x28, 0x26, 0x21, 0x1C, 0x16, 0x10, 0x0A, 0x05, 0x01, 0x01, 0x05, 0x0A, 0x10, 0x16,
    0x1C, 0x21, 0x26, 0x28, 0x29, 0x29, 0x28, 0x26, 0x21, 0x1C, 0x16, 0x10, 0x0A, 0x05, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0x38, 0x00, 0xC8, 0x1E, 0x64, 0x64, 0x00, 0xFF, 0x4C, 0x00, 0xB4, 0x1E, 0x64,
    0x64, 0x00, 0xFF, 0x60, 0x00, 0xA0, 0x1E, 0x64, 0x64, 0x00, 0xFF, 0x74, 0x00, 0x8C, 0x1E,
    0x64, 0x64, 0x00, 0xFF, 0x88, 0x00, 0x78, 0x1E, 0x64, 0x64, 0x00, 0xFF, 0x9C, 0x00, 0x64,
    0x1E, 0x64, 0x64, 0x00, 0xFF, 0xB0, 0x00, 0x50, 0x1E, 0x64, 0x64, 0x00, 0xFF, 0xC4, 0x00,
    0x3C, 0x1E, 0x64, 0x64, 0x00, 0xFF, 0xD8, 0x00, 0x28, 0x1E, 0x64, 0x64, 0x00, 0xFF, 0xEC,
    0x00, 0x14, 0x1E, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x64, 0x64, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x78, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x82, 0x46, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x05, 0x87, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x8A, 0x3E,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8C,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x8C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0x8C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x8A, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0x87, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD, 0x82, 0x46, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFC, 0x78, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFA, 0x64, 0x64, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFA, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x64, 0x64, 0x00, 0x00,
    0x00, 0x00, 0x01, 0xF4, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x03, 0xEE, 0x64, 0x64, 0x00,
    0x00, 0x00, 0x00, 0x05, 0xE6, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x0A, 0xDC, 0x64, 0x64,
    0x00, 0x00, 0x00, 0x00, 0x0F, 0xD0, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x14, 0xC2, 0x64,
    0x64, 0x00, 0x00, 0x00, 0x00, 0x1C, 0xB2, 0x64, 0x64, 0x00, 0x00, 0x05, 0x00, 0x1E, 0xA0,
    0x64, 0x64, 0x00, 0x00, 0x08, 0x00, 0x1E, 0xA0, 0x64, 0x64, 0x00, 0x00, 0x0A, 0x00, 0x1E,
    0xA0, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void snowman_doll_init(EffectInstance* effect);
void snowman_doll_update(EffectInstance* effect);
void snowman_doll_render(EffectInstance* effect);
void snowman_doll_appendGfx(void* effect);

EffectInstance* snowman_doll_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SnowmanDollFXData* data;
    s32 numParts = 1;

    bp.init = snowman_doll_init;
    bp.update = snowman_doll_update;
    bp.renderScene = snowman_doll_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_SNOWMAN_DOLL;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.snowmanDoll = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.snowmanDoll != nullptr);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_24 = 0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_30 = 0;
    data->unk_34 = 200.0f;
    data->unk_38 = 0;
    data->unk_3C = 0;
    data->unk_40 = 0;
    data->unk_44 = 0;
    data->unk_54 = 0;
    data->unk_58 = 2;
    data->unk_28 = arg4;
    data->unk_5C = 0;
    data->unk_18 = 200;
    data->unk_1C = 220;
    data->unk_20 = 240;
    data->unk_2C = 0;
    data->unk_40 = -8.0f;
    data->unk_50 = -1.0f;

    return effect;
}

void snowman_doll_init(EffectInstance* effect) {
}

EFFECT_DEF_COLD_BREATH(cold_breath_main);
EFFECT_DEF_MISC_PARTICLES(misc_particles_main);

void snowman_doll_update(EffectInstance* effect) {
    SnowmanDollFXData* data = effect->data.snowmanDoll;
    s32 unk_14;
    s32 unk_58;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 16;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_14 = data->unk_14;

    if (data->unk_10 < 16) {
        data->unk_24 = data->unk_10 * 16;
    }

    if (unk_14 < 16) {
        data->unk_24 = unk_14 * 16 + 15;
    }

    if (data->unk_3C != 0.0f) {
        f32 unk_40 = data->unk_40;

        if (unk_40 < 0.0f) {
            unk_40 = -unk_40;
        }

        if (data->unk_3C < 0.0f) {
            data->unk_2C -= unk_40;
        } else {
            data->unk_2C += unk_40;
        }
    }

    unk_58 = data->unk_58;

    switch (unk_58) {
        case 0:
            data->unk_4C = (f32) D_E00C0A24[data->unk_54++] * 0.01;
            data->unk_48 = 2.0f - data->unk_4C;
            if (data->unk_54 >= ARRAY_COUNT(D_E00C0A24)) {
                data->unk_58 = 2;
            }
            break;
        case 1:
            data->unk_4C = (f32) D_E00C0A10[data->unk_54++] * 0.01;
            data->unk_48 = 2.0f - data->unk_4C;
            if (data->unk_54 >= ARRAY_COUNT(D_E00C0A10) + 1) {
                data->unk_58 = 2;
            }
            if (data->unk_54 >= 8) {
                data->unk_30 += data->unk_3C;
                data->unk_34 += data->unk_40;
                data->unk_38 += data->unk_44;
                data->unk_40 += -1.0f;
            }
            break;
        case 3:
            data->unk_4C = (f32) D_E00C0A40[data->unk_54++] * 0.01;
            data->unk_48 = 2.0f - data->unk_4C;
            data->unk_2C = D_E00C0A8C[data->unk_54++];
            if (data->unk_54 >= ARRAY_COUNT(D_E00C0A40)) {
                data->unk_58 = 2;
            }
            if (data->unk_54 >= 64) {
                data->unk_30 += data->unk_3C;
                data->unk_34 += data->unk_40;
                data->unk_38 += data->unk_44;
                data->unk_40 += -1.0f;
            }
            break;
        case 2:
            data->unk_30 += data->unk_3C;
            data->unk_34 += data->unk_40;
            data->unk_38 += data->unk_44;
            data->unk_40 += data->unk_50;
            data->unk_4C = (f32) D_E00C0A21 * 0.01;
            data->unk_48 = 2.0f - data->unk_4C;
            if (data->unk_34 < 0.0f) {
                switch (data->unk_5C) {
                    case 0:
                        data->unk_58 = 0;
                        break;
                    case 1:
                        data->unk_58 = 1;
                        data->unk_3C = 2.0f;
                        data->unk_44 = 2.0f;
                        data->unk_40 = 10.0f;
                        break;
                    case 2:
                        data->unk_58 = 1;
                        data->unk_3C = 2.0f;
                        data->unk_44 = -2.0f;
                        data->unk_40 = 10.0f;
                        break;
                    case 3:
                        data->unk_58 = 1;
                        data->unk_3C = -2.0f;
                        data->unk_44 = -2.0f;
                        data->unk_40 = 10.0f;
                        break;
                    case 4:
                        data->unk_44 = 0.0f;
                        data->unk_58 = 1;
                        data->unk_3C = 10.0f;
                        data->unk_40 = 14.0f;
                        data->unk_50 = -1.0f;
                        break;
                    default:
                        data->unk_3C = 0.0f;
                        data->unk_40 = 0.0f;
                        data->unk_44 = 0.0f;
                        data->unk_34 = 0.0f;
                        data->unk_58 = unk_58;
                        break;
                }
                data->unk_34 = 0.0f;
                data->unk_54 = 0;
                data->unk_5C++;
            }
            break;
    }

    if ((unk_14 & 7) == 1) {
        load_effect(EFFECT_COLD_BREATH);
        cold_breath_main(2,
            data->unk_04 + data->unk_30 + rand_int(60) - 30.0f,
            data->unk_08 + data->unk_34 + rand_int(100) + 50.0f,
            data->unk_0C + data->unk_38,
            4.0f, 40);
        load_effect(EFFECT_MISC_PARTICLES);
        misc_particles_main(1,
            data->unk_04 + data->unk_30,
            data->unk_08 + data->unk_34 + 10.0f,
            data->unk_0C + data->unk_38 + 60.0f,
            60.0f, 100.0f, 2.0f, 10, 30);
    }
}

void snowman_doll_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = snowman_doll_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = -10;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00C0758(void) {
}

void snowman_doll_appendGfx(void* effect) {
    SnowmanDollFXData* data = ((EffectInstance*)effect)->data.snowmanDoll;
    s32 unk_24 = data->unk_24;
    Matrix4f sp18;
    Matrix4f sp58;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp18, data->unk_04, data->unk_08, data->unk_0C);
    guScaleF(sp58, data->unk_28, data->unk_28, data->unk_28);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    guTranslateF(sp18, data->unk_30, data->unk_34, data->unk_38);
    guScaleF(sp58, data->unk_48, data->unk_4C, data->unk_48);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, data->unk_2C, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, unk_24);
    gSPDisplayList(gMainGfxPos++, D_090037A8_3C1148);
    gSPDisplayList(gMainGfxPos++, D_09003818_3C11B8);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
