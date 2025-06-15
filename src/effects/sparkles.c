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

Gfx* D_E0022CD0[] = {
    D_09001210_3391D0, D_09001228_3391E8, D_09001240_339200,
    D_09001258_339218, D_09001270_339230, D_090011C8_339188,
    D_090011E0_3391A0, D_090011F8_3391B8
};

u8 D_E0022CF0[] = {
    254, 172, 172,
    254, 172, 213,
    254, 180, 154,
    213, 180, 254,
    180, 180, 254,
    180, 221, 254,
    180, 254, 254,
    180, 254, 213,
    180, 254, 180,
    213, 254, 180,
    254, 254, 180,
    254, 213, 172
};

u8 D_E0022D14[] = { 0x1E, 0x3C, 0x50, 0x5F, 0x64, 0x68, 0x6A };
u8 D_E0022D1C[] = { 0x3C, 0x5A, 0x64, 0x68, 0x6A, 0x6C, 0x6D };

void sparkles_init(EffectInstance* effect);
void sparkles_update(EffectInstance* effect);
void sparkles_render(EffectInstance* effect);
void sparkles_appendGfx(void* effect);

void sparkles_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    SparklesFXData* part;
    s32 numParts;
    f32 var_f30;
    f32 angle;
    f32 angle2;
    s32 i;

    switch (arg0) {
        case 0:
            numParts = 36;
            var_f30 = arg4;
            break;
        case 1:
            numParts = 4;
            var_f30 = arg4;
            break;
        case 2:
            numParts = 8;
            var_f30 = arg4;
            break;
        case 3:
            numParts = 4;
            var_f30 = 8.0f;
            break;
        default:
            numParts = 8;
            var_f30 = 8.0f;
            break;
    }

    numParts++;

    bpPtr->init = sparkles_init;
    bpPtr->update = sparkles_update;
    bpPtr->renderScene = sparkles_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = nullptr;
    bpPtr->effectID = EFFECT_SPARKLES;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.sparkles = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.sparkles != nullptr);

    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_20 = 0;
    part->unk_00 = arg0;
    part->unk_24 = 30;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        f32 rand1 = rand_int(arg4 * 1000.0f) / 1000.0f;
        f32 rand2 = rand_int(var_f30 * 1000.0f) / 1000.0f;

        switch (arg0) {
            case 0:
                angle = (360.0f / (numParts - 1)) * i;
                angle2 = (1800.0f / (numParts - 1)) * i - 90.0f;
                part->unk_18 = 0.0f;
                part->unk_10 = (sin_deg(angle) * (85.0f - sin_deg(angle2) * 15.0f - (i & 1) * 5) / 100.0f) * arg4;
                part->unk_14 = (cos_deg(angle) * (85.0f - sin_deg(angle2) * 15.0f - (i & 1) * 5) / 100.0f) * arg4;
                part->unk_0C = 0;
                part->unk_28 = 0;
                break;
            case 1:
            case 2:
                angle = (360.0f / (numParts - 1)) * i + rand_int(359);
                if (i & 1) {
                    part->unk_18 = -(rand_int(50) / 1000 + 0.05);
                } else {
                    part->unk_18 = 0;
                }
                part->unk_10 = 0;
                part->unk_14 = 0;
                part->unk_04 = rand1 * sin_deg(angle);
                part->unk_08 = rand2 * cos_deg(angle);
                part->unk_0C = 0;
                part->unk_1C = 1.0f;
                part->unk_24 = i * 2 + 30;
                part->unk_28 = i % 3;
                part->unk_20 = 0;
                break;
            case 3:
            case 4:
            default:
                angle = (360.0f / (numParts - 1)) * i + rand_int(359);
                part->unk_18 = -(rand_int(50) / 1000 + 0.05);
                part->unk_10 = 0.0f;
                part->unk_14 = 0.0f;
                part->unk_04 = rand1 * sin_deg(angle);
                part->unk_08 = rand2 * cos_deg(angle);
                part->unk_0C = 0;
                part->unk_1C = 1.0f;
                part->unk_24 = i * 2 + 18;
                part->unk_28 = i % 3;
                part->unk_20 = 0;
                break;
        }
    }
}

void sparkles_init(EffectInstance* effect) {
}

void sparkles_update(EffectInstance *effect) {
    SparklesFXData* part = effect->data.sparkles;
    SparklesFXData* firstPart = part;
    s32 unk_00 = part->unk_00;
    f32 unk_10;
    f32 unk_14;
    s32 unk_20;
    s32 count = 0;
    f32 temp_f20;
    f32 angle;
    s32 i;

    part->unk_24--;
    part->unk_20++;

    unk_20 = part->unk_20;

    if ((unk_00 == 0 || unk_00 == 10) && part->unk_24 < 0) {
        remove_effect(effect);
        return;
    }

    part++;
    for (i = 0; i < effect->numParts - 1; i++, part++) {
        part->unk_2C = (unk_20 + i) & 7;
        switch (unk_00) {
            case 0:
                part->unk_18 += -0.02;
                if (unk_20 - 1 < 7) {
                    part->unk_04 = part->unk_10 * D_E0022D14[unk_20 - 1] * 0.01;
                    part->unk_08 = part->unk_14 * D_E0022D14[unk_20 - 1] * 0.01 + part->unk_18;
                    part->unk_1C = (f32) D_E0022D1C[unk_20 - 1] * 0.01;
                } else {
                    angle = effect_simple_rand(360, i + 177);
                    temp_f20 = (i & 3) * 0.5f + 1.0f;
                    firstPart->unk_00 = 10;
                    part->unk_10 = temp_f20 * sin_deg(angle);
                    part->unk_14 = temp_f20 * cos_deg(angle);
                    part->unk_18 = -0.05f;
                }
                break;
            case 10:
                part->unk_10 *= 0.96;
                part->unk_1C += (0.1 - part->unk_1C) * 0.1;
                part->unk_14 *= 0.96;
                part->unk_14 += part->unk_18;
                part->unk_04 += part->unk_10;
                part->unk_08 += part->unk_14;
                break;
            default:
                part->unk_10 *= 0.9;
                part->unk_14 += part->unk_18;
                unk_10 = part->unk_10;
                unk_14 = part->unk_14;
                if (part->unk_24 < 0) {
                    count++;
                }
                part->unk_04 += unk_10;
                part->unk_08 += unk_14;
                part->unk_24--;
                if (part->unk_24 < 0 || part->unk_24 >= 21) {
                    part->unk_2C = -1;
                } else {
                    part->unk_20++;
                    unk_20 = part->unk_20;
                    if (unk_20 - 1 < 7) {
                        part->unk_1C = (f32) D_E0022D1C[unk_20 - 1] * 0.01;
                    } else {
                        part->unk_1C += (0.1 - part->unk_1C) * 0.1;
                    }
                }
                break;
        }
    }

    if (unk_00 != 0 && unk_00 != 10 && count >= effect->numParts - 1) {
        remove_effect(effect);
    }
}

void sparkles_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sparkles_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
}

void sparkles_appendGfx(void* effect) {
    SparklesFXData* part = ((EffectInstance*)effect)->data.sparkles;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 colorIdx;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, D_09000F20_338EE0);

    colorIdx = (part->unk_20 - 1) * 3;

    guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);

    part++;
    for (i = 0; i < ((EffectInstance*)effect)->numParts - 1; i++, part++) {
        s32 unk_2C = part->unk_2C;

        if (unk_2C >= 0) {
            guTranslateF(sp58, part->unk_04, part->unk_08, part->unk_0C);

            sp58[0][0] = part->unk_1C;
            sp58[1][1] = part->unk_1C;
            sp58[2][2] = part->unk_1C;
            colorIdx += 3;

            guMtxCatF(sp58, sp98, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            colorIdx %= ARRAY_COUNT(D_E0022CF0);

            gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0022CF0[colorIdx], D_E0022CF0[colorIdx + 1], D_E0022CF0[colorIdx + 2], 255);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_E0022CD0[unk_2C & 7]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gDPPipeSync(gMainGfxPos++);
}
