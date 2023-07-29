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

Gfx* D_E01248A0[] = {
    D_09001210_3391D0, D_09001228_3391E8, D_09001240_339200,
    D_09001258_339218, D_09001270_339230, D_090011C8_339188,
    D_090011E0_3391A0, D_090011F8_3391B8
};

s8 D_E01248C0[] = {
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x40, 0x2E, 0x23, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x24, 0x25, 0x26, 0x2E, 0x2A, 0x3D, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2D, 0x2E, 0x2E, 0x2E, 0x3B, 0x3E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2C, 0x27, 0x2E, 0x2E, 0x2E, 0x2E, 0x29, 0x21, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x7E, 0x7E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x7B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x7E, 0x7E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x5D, 0x40, 0x40, 0x5E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x7E, 0x2F, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x28, 0x5F, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x23, 0x3A, 0x3C, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x5B, 0x7D, 0x7C, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x31, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x32, 0x33, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x34, 0x35, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x36, 0x37, 0x37, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x38, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x37, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x39, 0x30, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x37, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x61, 0x32, 0x32, 0x62, 0x2E, 0x2E, 0x2E, 0x63, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x64, 0x65, 0x65, 0x65, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x66, 0x2B, 0x2B, 0x2B, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x66, 0x66, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x66, 0x66, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x66, 0x66, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E,
    0x2E, 0x66, 0x2B, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E,
    0x66, 0x66, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x66, 0x2E,
    0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E,
    0x66, 0x66, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E,
    0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E,
    0x2E, 0x66, 0x2B, 0x2E, 0x66, 0x2B, 0x2B, 0x2B, 0x66, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2B, 0x66, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x66, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x67, 0x68, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2B, 0x67, 0x2E, 0x67, 0x67, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x68, 0x68, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x68, 0x68, 0x2E, 0x2E, 0x68, 0x68, 0x2E, 0x68, 0x68, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x68, 0x67, 0x2B, 0x67, 0x68, 0x67, 0x67, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x68, 0x67, 0x68, 0x67, 0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x68, 0x67, 0x67, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2B, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x67, 0x2B, 0x2E, 0x68, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E,
    0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E,
    0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x68, 0x67, 0x67, 0x2E,
    0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x67, 0x2E,
    0x2E, 0x2E, 0x67, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x68, 0x67, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x68, 0x2E, 0x2E, 0x2E
};

u8 D_E0124BC0[] = {
    0xFE, 0xAC, 0xAC,
    0xFE, 0xAC, 0xD5,
    0xFE, 0xB4, 0x9A,
    0xD5, 0xB4, 0xFE,
    0xB4, 0xB4, 0xFE,
    0xB4, 0xDD, 0xFE,
    0xB4, 0xFE, 0xFE,
    0xB4, 0xFE, 0xD5,
    0xB4, 0xFE, 0xB4,
    0xD5, 0xFE, 0xB4,
    0xFE, 0xFE, 0xB4,
    0xFE, 0xD5, 0xAC
};

u8 D_E0124BE4[] = {
    0x1E, 0x3C, 0x5A, 0x64, 0x68,
    0x6A, 0x6C, 0x6E, 0x70, 0x71,
    0x71, 0x6E, 0x6B, 0x67, 0x64,
    0x68, 0x6A, 0x6C, 0x6E, 0x70,
    0x71, 0x71, 0x6E, 0x6B, 0x67
};

void pink_sparkles_init(EffectInstance* effect);
void pink_sparkles_update(EffectInstance* effect);
void pink_sparkles_render(EffectInstance* effect);
void pink_sparkles_appendGfx(void* effect);

EffectInstance* pink_sparkles_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    PinkSparklesFXData* part;
    s32 numParts = 101;
    s32 count;
    f32 angle;
    s32 i;
    s32 j;

    bp.init = pink_sparkles_init;
    bp.update = pink_sparkles_update;
    bp.renderWorld = pink_sparkles_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_PINK_SPARKLES;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.pinkSparkles = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.pinkSparkles != NULL);

    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_20 = 0;
    part->unk_00 = arg0;
    part->unk_1C = 80;

    part++;
    angle = arg5;
    count = 1;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            if (D_E01248C0[j + (15 - i) * 16 + arg0 * 256] != 46) {
                f32 temp_f20 = j * 2 - 16 + (rand_int(20) - 10) * 0.1;

                part->unk_04 = temp_f20 * cos_deg(angle);
                part->unk_08 = i * 2 + (rand_int(20) - 10) * 0.1;
                part->unk_0C = temp_f20 * sin_deg(angle);
                part->unk_10 = part->unk_04 * 0.04;
                part->unk_14 = part->unk_08 * 0.04;
                part->unk_18 = rand_int(10) * 0.001;
                part->unk_1C = rand_int(7) + 30;
                part->unk_20 = 0;

                count++;
                part++;

                if (count >= numParts) {
                    break;
                }
            }
        }

        if (count >= numParts) {
            break;
        }
    }

    for (; count < numParts; count++, part++) {
        part->unk_04 = part->unk_08 = part->unk_0C =
            part->unk_10 = part->unk_14 = part->unk_18 =
            part->unk_24 = 0.0f;
        part->unk_1C = -1;
        part->unk_20 = 0;
    };

    return effect;
}

void pink_sparkles_init(EffectInstance* effect) {
}

void pink_sparkles_update(EffectInstance* effect) {
    PinkSparklesFXData* part = effect->data.pinkSparkles;
    s32 unk_20;
    s32 count = 0;
    s32 i;

    part->unk_1C--;
    part->unk_20++;
    unk_20 = part->unk_20;

    part++;
    for (i = 0; i < effect->numParts - 1; i++, part++) {
        part->unk_28 = (unk_20 + i + i) & 7;

        if (part->unk_1C < 0) {
            count += 1;
        }

        part->unk_1C--;
        if (part->unk_1C < 0 || part->unk_1C >= 31) {
            part->unk_28 = -1;
        } else {
            part->unk_20++;
            unk_20 = part->unk_20;

            if (unk_20 - 1 < 25) {
                part->unk_24 = (f32) D_E0124BE4[unk_20 - 1] * 0.01 * 0.4;
            } else {
                part->unk_24 += (0.1 - part->unk_24) * 0.1;
            }

            part->unk_04 += part->unk_10;
            part->unk_08 += part->unk_14;
            part->unk_14 += part->unk_18;
            part->unk_0C += part->unk_10;
        }
    }

    if (count >= effect->numParts - 1) {
        remove_effect(effect);
    }
}

void pink_sparkles_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = pink_sparkles_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
}

void pink_sparkles_appendGfx(void* effect) {
    PinkSparklesFXData* part = ((EffectInstance*)effect)->data.pinkSparkles;
    s32 primR;
    s32 primG;
    s32 primB;
    f32 factorR = 1.4f;
    f32 factorG = 0.7f;
    f32 factorB = 0.7f;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 colorIdx;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000F20_338EE0);

    colorIdx = (part->unk_20 - 1) * 3;

    guTranslateF(sp98, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp98, sp98);

    part++;
    for (i = 0; i < ((EffectInstance*)effect)->numParts - 1; i++, part++) {
        s32 unk_28 = part->unk_28;

        if (unk_28 >= 0) {
            guTranslateF(sp58, part->unk_04, part->unk_08, part->unk_0C);

            sp58[0][0] = sp58[1][1] = sp58[2][2] = part->unk_24;

            guMtxCatF(sp58, sp98, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            if (colorIdx >= ARRAY_COUNT(D_E0124BC0)) {
                colorIdx = 0;
            }

            primR = D_E0124BC0[colorIdx++] * factorR;
            primG = D_E0124BC0[colorIdx++] * factorG;
            primB = D_E0124BC0[colorIdx++] * factorB;

            if (primR > 255) {
                primR = 255;
            }
            if (primG > 255) {
                primG = 255;
            }
            if (primB > 255) {
                primB = 255;
            }

            gDPSetPrimColor(gMainGfxPos++, 0, 0, primR, primG, primB, 255);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_E01248A0[unk_28 & 7]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gDPPipeSync(gMainGfxPos++);
}
