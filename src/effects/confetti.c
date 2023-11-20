#include "common.h"
#include "effects_internal.h"

void confetti_init(EffectInstance* effect);
void confetti_update(EffectInstance* effect);
void confetti_render(EffectInstance* effect);
void confetti_appendGfx(void* effect);

extern Gfx D_090009E8_38C588[];
extern Gfx D_09000A00_38C5A0[];
extern Gfx D_09000940_38C4E0[];

Gfx* D_E0088CC0[] = {
    D_090009E8_38C588, D_090009E8_38C588, D_090009E8_38C588, D_09000A00_38C5A0,
    D_090009E8_38C588, D_090009E8_38C588, D_090009E8_38C588
};

Color_RGB8 D_E0088CDC[] = {
    { 232, 160, 168 },
    { 168,  80,  88 },
    { 160, 168, 232 },
    {  72,  72, 232 },
    { 160, 232, 160 },
    {  96, 176, 120 },
    { 224, 224,  88 },
    { 176, 160,  56 },
    { 232, 160, 232 },
    { 176,  64, 160 },
    { 160, 216, 216 },
    {  88, 168, 168 },
};

u8 D_E0088D00[] = { 0, 1, 2, 3, 2, 1, 0, 0 };

u8 D_E0088D08[] = { 0, 45, 0, 60 };

void func_E0088000(ConfettiFXData* part) {
    part->unk_04 = rand_int(700) * 0.1f - 35.0f;
    part->unk_08 = 0;
    part->unk_0C = rand_int(300) * 0.1f - 15.0f;
    part->unk_10 = (part->unk_04 + rand_int(100) * 0.1f - 5.0f) * 0.03;
    part->unk_14 = -1.7 - rand_int(800) * 0.1f * 0.01;
    part->unk_18 = (rand_int(200) * 0.1f - 10.0f) * 0.05;
    part->unk_20 = 120;
}

EffectInstance* confetti_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    f32 sp28;
    ConfettiFXData* data;
    EffectInstance* effect;
    s32 numParts;
    f32 theta;
    f32 sinTheta;
    f32 cosTheta;
    f32 theta2;
    f32 sinTheta2;
    f32 cosTheta2;
    f32 temp_f28;
    f32 temp_f30;
    s32 temp_fp;
    s32 np;
    s32 var_v0;
    s32 i;

    switch (arg0) {
        case 0:
        case 4:
            np = 12;
            break;
        case 1:
        case 5:
            np = 18;
            break;
        case 2:
        case 6:
            np = 24;
            break;
        default:
            np = 48;
            break;
    }

    switch (arg0) {
        case 0:
        case 4:
            sp28 = 3.0f;
            break;
        case 1:
        case 5:
            sp28 = 4.0f;
            break;
        case 2:
        case 3:
        case 6:
        default:
            sp28 = 5.0f;
            break;
    }

    numParts = np + 1;

    bpPtr->init = confetti_init;
    bpPtr->update = confetti_update;
    bpPtr->renderWorld = confetti_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_CONFETTI;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    data = effect->data.confetti = (ConfettiFXData*)general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.confetti != NULL);

    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_24 = 0;
    data->unk_20 = arg5;
    data->unk_00 = arg0;
    data->unk_2C = np;
    data->unk_28 = 255;

    data++;
    temp_fp = rand_int(360);

    for (i = 0; i < np; i++, data++) {
        temp_f30 = sp28 * (effect_rand_int(100) * 0.01f);
        switch (arg0) {
            case 0:
            case 4:
                temp_f28 = sp28 * 0.5 * 2.0;
                break;
            case 1:
            case 5:
                temp_f28 = sp28 * 0.5 * 2.0;
                break;
            case 2:
            case 6:
                temp_f28 = sp28 * 0.5 * 2.0;
                break;
        }
        temp_f28 = sp28 * 0.5 * 2.0;
        theta2 = D_E0088D08[i % 4];
        theta = ((i * 360.0f) / np) + temp_fp;

        data->unk_00 = arg0;

        sinTheta = sin_deg(theta);
        cosTheta = cos_deg(theta);
        sinTheta2 = sin_deg(theta2);
        cosTheta2 = cos_deg(theta2);
        if (arg0 == 3) {
            func_E0088000(data);
            data->unk_30 = i * 3;
        } else {
            data->unk_04 = temp_f30 * sinTheta * cosTheta2;
            data->unk_08 = temp_f30 * cosTheta * cosTheta2;
            data->unk_0C = temp_f30 * sinTheta2;
            data->unk_10 = temp_f28 * sinTheta * cosTheta2;
            data->unk_14 = (temp_f28 * cosTheta * cosTheta2) + 1.0f;
            data->unk_18 = temp_f28 * sinTheta2;
            if (arg0 >= 4) {
                data->unk_1C = -0.02 - ((i + 1) % 3) * 0.02;
            } else {
                data->unk_1C = 0.0f;
            }
            data->unk_30 = i & 3;
        }
    }
    return effect;
}

void confetti_init(EffectInstance* effect) {
}

void confetti_update(EffectInstance* effect) {
    ConfettiFXData* part = effect->data.confetti;
    s32 unk_00;
    s32 unk_24;
    s32 unk_2C;
    s32 i;

    part->unk_20--;
    if (part->unk_20 < 0) {
        remove_effect(effect);
        return;
    }

    part->unk_24++;
    if (part->unk_24 > 324000) {
        part->unk_24 = 10;
    }

    unk_24 = part->unk_24;
    unk_00 = part->unk_00;
    unk_2C = part->unk_2C;

    if (part->unk_20 < 10) {
        part->unk_28 = part->unk_20 * 25;
    }

    part++;
    for (i = 0; i < unk_2C; i++, part++) {
        if (unk_00 == 3) {
            if (part->unk_30 <= 0 || --part->unk_30 <= 0) {
                part->unk_20--;
                if (part->unk_20 < 0) {
                    func_E0088000(part);
                    part->unk_20--;
                }
                part->unk_04 += part->unk_10;
                part->unk_08 += part->unk_14;
                part->unk_0C += part->unk_18;
            }
        } else {
            if (part->unk_30 <= 0 || --part->unk_30 <= 0) {
                if (unk_00 >= 4) {
                    part->unk_10 *= 0.98;
                    part->unk_14 *= 0.98;
                    part->unk_18 *= 0.98;
                    if (unk_24 >= 6 && part->unk_14 > -0.5) {
                        part->unk_14 += part->unk_1C;
                    }
                }
                part->unk_04 += part->unk_10;
                part->unk_08 += part->unk_14;
                part->unk_0C += part->unk_18;
            }
        }
    }
}

void confetti_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = confetti_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
}

void confetti_appendGfx(void* effect) {
    ConfettiFXData* part = ((EffectInstance*)effect)->data.confetti; //s3
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;
    s32 uly;
    s32 width = 0x3C;
    s32 height = 0x3C;
    s32 ulx = 0;
    s32 unk_28;
    s32 unk_2C;
    Gfx* spA0;
    s32 spA4;
    Gfx* savedGfxPos;
    s32 unk_24;
    Color_RGB8* color;

    unk_24 = part->unk_24;
    unk_2C = part->unk_2C;
    unk_28 = part->unk_28;
    spA0 = D_E0088CC0[part->unk_00];

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000940_38C4E0);

    guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    savedGfxPos = gMainGfxPos++;

    part++;
    for (i = 0; i < unk_2C; i++, part++) {
        color = &D_E0088CDC[i % 12];

        if (part->unk_30 <= 0) {
            guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gDPSetPrimColor(gMainGfxPos++, 0, 0, color->r, color->g, color->b, unk_28);

            switch ((unk_24 + i) % 3) {
                case 0:
                    gDPSetCombineMode(gMainGfxPos++, PM_CC_45, PM_CC_46);
                    break;
                case 1:
                    gDPSetCombineMode(gMainGfxPos++, PM_CC_45, PM_CC_45);
                    break;
                case 2:
                    gDPSetCombineMode(gMainGfxPos++, PM_CC_45, PM_CC_47);
                    break;
            }
            uly = ((i + D_E0088D00[unk_24 % 6]) & 0xF) * 16;

            gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, ulx << 2, uly << 2,
                           (ulx << 2) + ((width >> 1) << 1), (uly << 2) + height);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, spA0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPEndDisplayList(gMainGfxPos++);
    gSPBranchList(savedGfxPos, gMainGfxPos);
    savedGfxPos++;
    gSPDisplayList(gMainGfxPos++, savedGfxPos);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}

