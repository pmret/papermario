#include "common.h"
#include "effects_internal.h"

s32 D_E0116C60[] = { 0x09004458 };

s32 D_E0116C64[] = { 0x09004600 };

s32 D_E0116C68[] = { 0x09004360 };

s32 D_E0116C6C[] = { 0x09004508 };

s32 D_E0116C70[] = {
    0x09003F98, 0x09004010, 0x09004088,
    0x09004100, 0x09004178, 0x090041F0,
    0x09004268
};

Color_RGB8 D_E0116C8C[] = {
    { 255, 224,  65 },
    { 244, 227,  72 },
    { 211, 220,  22 },
    { 152, 214, 222 },
    { 211, 138, 239 },
    { 231, 174, 219 },
    { 255, 200,  11 },
    {   0,   0,   0 }
};

s16 D_E0116CA4[] = {
    0x0000, 0x003C, 0x0078, 0x00B4, 0x00F0, 0x012C, 0x0000, 0x003C, 0x0078, 0x00B4,
    0x00F0, 0x012C, 0x0000, 0x003C, 0x0078, 0x00B4, 0x00F0, 0x012C, 0x0000, 0x003C,
    0x0078, 0x00B4, 0x00F0, 0x012C, 0x0000, 0x001E, 0x003C, 0x005A, 0x0078, 0x0096,
    0x00B4, 0x00D2, 0x00F0, 0x010E, 0x012C, 0x014A, 0x0159, 0x0161, 0x0165, 0x0167,
    0x0000
};

s8 D_E0116CF8[] = {
    0x02, 0x14, 0x28, 0x3C, 0x50, 0x64, 0x78, 0xA0, 0xB4, 0xC8, 0xDC, 0xF0, 0xFF
};

s8 D_E0116D08[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x14, 0x28, 0x3C, 0x50, 0x64, 0x78, 0xA0, 0xB4, 0xC8, 0xDC,
    0xF0, 0xFF
};

u8 D_E0116D3C[] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE1, 0xB9, 0xA5,
    0x94, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE1,
    0xB9, 0xA5, 0x94, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xE1, 0xB9, 0xA5, 0x94, 0x80, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xE1, 0xB9, 0xA5, 0x94, 0x80
};

u8 D_E0116D6C[] = {
    0x32, 0x50, 0x64, 0x69, 0x6B, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C,
    0x6C, 0x6B, 0x69, 0x64, 0x5F, 0x5A, 0x55, 0x50, 0x4B, 0x46,
    0x41, 0x3C, 0x37, 0x32
};

void something_rotating_init(EffectInstance* effect);
void something_rotating_update(EffectInstance* effect);
void something_rotating_render(EffectInstance* effect);
void something_rotating_appendGfx(void* effect);

EffectInstance* something_rotating_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SomethingRotatingFXData* part;
    s32 numParts = 8;
    s32 i;

    bp.init = something_rotating_init;
    bp.update = something_rotating_update;
    bp.renderWorld = something_rotating_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_SOMETHING_ROTATING;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.somethingRotating = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.somethingRotating != NULL);

    part->unk_00 = arg0;
    part->unk_14 = 0;
    if (arg5 <= 0) {
        part->unk_10 = 1000;
    } else {
        part->unk_10 = arg5;
    }
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_18 = arg4;
    part->unk_1C = 30.0f;
    part->unk_20 = 0;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_24 = 0;
        part->unk_18 = arg4 * 0.5;
        part->unk_26 = 255;
        part->unk_27 = 255;
        part->unk_28 = 0;
        part->unk_25 = 0;
        part->unk_1C = 30.0f;
        part->unk_20 = 0;
        part->unk_29 = 0;
        part->unk_2C = 50.0f;
    }

    return effect;
}

void something_rotating_init(EffectInstance* effect) {
}

void something_rotating_update(EffectInstance* effect) {
    SomethingRotatingFXData* part = effect->data.somethingRotating;
    f32 unk_04 = part->unk_04;
    f32 unk_08 = part->unk_08;
    f32 unk_0C = part->unk_0C;
    s32 unk_14;
    s32 unk_14_2;
    f32 factor;
    f32 angle1;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        part->unk_10 = 32;
    }

    if (part->unk_10 < 1000) {
        part->unk_10--;
    }

    part->unk_14++;

    if (part->unk_10 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_14 = part->unk_14;
    part->unk_20 = 90.0f;
    angle1 = 90.0f;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        f32 angle2 = unk_14 * 4.0f + (f32) i * 51.43;
        f32 temp_f24 = shim_sin_deg(angle2);
        f32 temp_f22 = part->unk_2C;

        part->unk_04 = unk_04 + temp_f22 * shim_sin_deg(angle1) * temp_f24;
        part->unk_08 = unk_08 + temp_f22 * shim_cos_deg(angle2);
        part->unk_0C = unk_0C + temp_f22 * shim_cos_deg(angle1) * temp_f24;

        switch (part->unk_29 - 1) {
            case 0:
                part->unk_14 = 0;
                part->unk_29++;
                // fallthrough
            case 1:
                unk_14_2 = part->unk_14;

                if (unk_14_2 < ARRAY_COUNT(D_E0116CA4)) {
                    part->unk_20 = D_E0116CA4[unk_14_2];
                } else {
                    part->unk_20 = D_E0116CA4[ARRAY_COUNT(D_E0116CA4) - 1];
                }
                if (unk_14_2 < ARRAY_COUNT(D_E0116CF8)) {
                    part->unk_24 = D_E0116CF8[unk_14_2];
                } else {
                    part->unk_24 = D_E0116CF8[ARRAY_COUNT(D_E0116CF8) - 1];
                }
                if (unk_14_2 < ARRAY_COUNT(D_E0116D08)) {
                    part->unk_25 = D_E0116D08[unk_14_2];
                } else {
                    part->unk_25 = D_E0116D08[ARRAY_COUNT(D_E0116D08) - 1];
                }

                if (unk_14_2 < ARRAY_COUNT(D_E0116D3C)) {
                    factor = D_E0116D3C[unk_14_2];
                } else {
                    factor = D_E0116D3C[ARRAY_COUNT(D_E0116D3C) - 1];
                }

                factor *= 0.0039215686; // 1 / 255
                part->unk_26 = factor * D_E0116C8C[i - 1].r;
                part->unk_27 = factor * D_E0116C8C[i - 1].g;
                part->unk_28 = factor * D_E0116C8C[i - 1].b;

                if (unk_14_2 < ARRAY_COUNT(D_E0116D6C)) {
                    part->unk_18 = (f32) D_E0116D6C[unk_14_2] * 0.01;
                } else {
                    part->unk_18 = (f32) D_E0116D6C[ARRAY_COUNT(D_E0116D6C) - 1] * 0.01;
                }

                break;
            case 2:
                part->unk_14 = 0;
                part->unk_29++;
                // fallthrough
            case 3:
                unk_14_2 = part->unk_14;

                if (unk_14_2 < 18) {
                    part->unk_2C = (shim_sin_deg(90 - unk_14_2 * 10) + 1.0f) * 50.0f * 0.5;
                } else {
                    part->unk_2C = 0.0f;
                    part->unk_29++;
                }

                break;
            case 4:
                break;
        }

        part->unk_14++;
    }
}

void something_rotating_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = something_rotating_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E01166E8(s32 arg0, SomethingRotatingFXData* part) {
    f32 temp;
    Matrix4f sp20;
    Matrix4f sp60;

    if (arg0 == 0) {
        temp = gCameras[gCurrentCameraID].currentYaw;
    } else {
        temp = 0.0f;
    }

    shim_guPositionF(sp20, 0.0f, part->unk_20 - temp, 0.0f, part->unk_18, part->unk_04 + 2.0f, part->unk_08, part->unk_0C + 2.0f);
    shim_guRotateF(sp60, part->unk_1C, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guTranslateF(sp60, 0.0f, 0.0f, -2.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

INCLUDE_ASM(s32, "effects/something_rotating", something_rotating_appendGfx);
