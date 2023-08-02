#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002000_3DB100[];
extern Gfx D_09002200_3DB300[];
extern Gfx D_09002220_3DB320[];
extern Gfx D_09002240_3DB340[];
extern Gfx D_09002260_3DB360[];
extern Gfx D_09002280_3DB380[];
extern Gfx D_090022A0_3DB3A0[];

Gfx* D_E00DE810[][5] = {
    { D_09002200_3DB300, D_09002220_3DB320, D_09002240_3DB340, D_09002260_3DB360, D_09002280_3DB380 },
    { D_09002200_3DB300, D_09002220_3DB320, D_09002240_3DB340, D_09002260_3DB360, D_09002280_3DB380 },
    { D_09002200_3DB300, D_09002220_3DB320, D_09002240_3DB340, D_09002260_3DB360, D_09002280_3DB380 }
};

Gfx* D_E00DE84C[] = {
    D_09002000_3DB100, D_090022A0_3DB3A0, D_09002000_3DB100
};

s8 D_E00DE858[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF8, 0xF1, 0xEB, 0xE6, 0xE2, 0xDE, 0xDB, 0xD9, 0xD8, 0xD7,
    0xD6, 0xD5, 0xD4, 0xD3, 0xD2, 0xD1, 0xD0, 0xCF, 0xCE, 0xCD,
    0xCC, 0xCB, 0xCA, 0xC9, 0xC8, 0xC7, 0xC6, 0xC5, 0xC4, 0xC3,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00
};

u8 D_E00DE8B4[] = {
    0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31,
    0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32,
    0x34, 0x37, 0x39, 0x3C, 0x3E, 0x41, 0x43, 0x46, 0x48, 0x4B,
    0x4D, 0x50, 0x52, 0x55, 0x57, 0x5A, 0x5C, 0x5F, 0x61, 0x64,
    0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31,
    0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x00, 0x00
};

u8 D_E00DE910[] = {
    0x00, 0x14, 0x28, 0x3C, 0x50, 0x64, 0x78, 0x8C, 0xA0, 0xB4,
    0xBE, 0xC3, 0xD2, 0xD0, 0xD3, 0xD6, 0xD9, 0xDC, 0xDF, 0xE2,
    0xE5, 0xE8, 0xEB, 0xEE, 0xF1, 0xF4, 0xF7, 0xFA, 0xFD, 0xFF,
    0x00, 0x14, 0x28, 0x3C, 0x50, 0x64, 0x78, 0x8C, 0xA0, 0xB4,
    0xBE, 0xC3, 0xD2, 0xD0, 0xD3, 0xD6, 0xD9, 0xDC, 0xDF, 0xE2,
    0xE5, 0xE8, 0xEB, 0xEE, 0xF1, 0xF4, 0xF7, 0xFA, 0xFD, 0xFF,
    0x00, 0x14, 0x28, 0x3C, 0x50, 0x64, 0x78, 0x8C, 0xA0, 0xB4,
    0xBE, 0xC3, 0xD2, 0xD0, 0xD3, 0xD6, 0xD9, 0xDC, 0xDF, 0xE2,
    0xE5, 0xE8, 0xEB, 0xEE, 0xF1, 0xF4, 0xF7, 0xFA, 0xFD, 0xFF,
    0x00, 0x00
};

u8 D_E00DE96C[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
    0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
    0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4,
    0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4,
    0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void cold_breath_init(EffectInstance* effect);
void cold_breath_update(EffectInstance* effect);
void cold_breath_render(EffectInstance* effect);
void cold_breath_appendGfx(void* effect);

EffectInstance* cold_breath_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    ColdBreathFXData* data;
    s32 numParts = 1;

    bp.init = cold_breath_init;
    bp.update = cold_breath_update;
    bp.renderWorld = cold_breath_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_COLD_BREATH;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.coldBreath = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.coldBreath != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_24 = 255;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_40 = arg4;
    data->unk_18 = 255;
    data->unk_1C = 255;
    data->unk_20 = 255;
    data->unk_28 = 255;
    data->unk_2C = 255;
    data->unk_30 = 255;
    data->unk_34 = 255;
    data->unk_38 = 0;
    data->unk_3C = 0;

    return effect;
}

void cold_breath_init(EffectInstance* effect) {
}

void cold_breath_update(EffectInstance* effect) {
    ColdBreathFXData* data = effect->data.coldBreath;
    s32 unk00 = data->unk_00;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 0x10;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        remove_effect(effect);
        return;
    }
    if (data->unk_10 < 16) {
        data->unk_24 = data->unk_10 * 16;
    }

    if (unk00 < 2) {
        if (unk00 >= 0) {
            data->unk_3C += 0.02;
        }
    }

    data->unk_08 += data->unk_3C;

    if (data->unk_3C > 0.5) {
        data->unk_3C = 0.5f;
    }
    if (data->unk_3C < -1.5) {
        data->unk_3C = -1.5f;
    }

    data->unk_38 += 1.0f;
}

void cold_breath_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = cold_breath_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 6;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void cold_breath_appendGfx(void* effect) {
    ColdBreathFXData* data = ((EffectInstance*)effect)->data.coldBreath;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk14 = data->unk_14;
    s32 unk24 = data->unk_24;
    s32 unk00 = data->unk_00;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 unkIndex;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp_f32;
    s32 temp_s32;
    s32 envAlpha;
    s32 cond;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp20, data->unk_04, data->unk_08, data->unk_0C);
    guScaleF(sp60, data->unk_40, data->unk_40, data->unk_40);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, 0.5 * unk24);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_NOISE);
    gSPDisplayList(gMainGfxPos++, D_E00DE84C[unk00]);

    unkIndex = (unk14 < 30 ? unk14 : 29) + unk00 * 30;
    temp1 = D_E00DE96C[unkIndex];
    temp2 = D_E00DE8B4[unkIndex];
    temp3 = D_E00DE858[unkIndex];

    guPositionF(sp20, 0.0f, 0.0f, -temp1, temp2 * 0.01f, temp3, 0.0f, 0.0f);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    temp_f32 = D_E00DE910[unkIndex] * 5.0f / 256.0f;
    temp_s32 = temp_f32;
    envAlpha = (temp_f32 - temp_s32) * 256.0f;

    cond = temp_s32 >= 4;
    if (temp_s32 < 5) {
        if (cond) {
            gDPSetTileSize(gMainGfxPos++, 1, 0, 0, 0, 0);
        } else {
            gDPSetTileSize(gMainGfxPos++, 1, 0, 0, 31 << 2, 127 << 2);
        }
        gDPSetEnvColor(gMainGfxPos++, data->unk_28, data->unk_2C, data->unk_30, envAlpha);
        gSPDisplayList(gMainGfxPos++, D_E00DE810[unk00][temp_s32]);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_DISABLE);
    gDPPipeSync(gMainGfxPos++);
}
