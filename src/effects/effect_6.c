#include "common.h"
#include "effects_internal.h"

typedef struct Effect6 {
    /* 0x00 */ u16 type;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
} Effect6; // size = 0x44

static s32 sDlists[] = { 0x09002B20, 0x09002B40, 0x09002B60, 0x09002B60, 0x09002B60 };
static s32 sDlists2[] = { 0x09002780, 0x09002868, 0x09002950, 0x09002A38, 0x09002A38 };

static s8 D_E000CC38[] = { 0x00, 0x01, 0x02, 0x1A, 0x03, 0x1B, 0x04, 0x1C, 0x05, 0x15, 0x35, 0x46, 0x46, 0x46, 0xFF,
                           0x00 };

static s8 D_E000CC48[] = { 0x00, 0x01, 0x02, 0x1A, 0x03, 0x1B, 0x04, 0x1C, 0x05, 0x1D, 0x06, 0x16, 0x26, 0x47, 0x57,
                           0x67, 0xFF, 0x00, 0x00, 0x00 };

static s8 D_E000CC5C[] = { 0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38, 0x01, 0x09, 0x11, 0x19, 0x21, 0x29, 0x31,
                           0x39, 0x02, 0x02, 0x0A, 0x0A, 0x12, 0x12, 0x1A, 0x1A, 0x22, 0x22, 0x2A, 0x2A, 0x32, 0x32,
                           0x3A, 0x3A, 0x03, 0x03, 0x0B, 0x0B, 0x13, 0x13, 0x1B, 0x1B, 0x23, 0x23, 0x2B, 0x2B, 0x33,
                           0x33, 0x3B, 0x3B, 0x04, 0x04, 0x0C, 0x0C, 0x14, 0x14, 0x1C, 0x1C, 0x24, 0x24, 0x2C, 0x2C,
                           0x34, 0x34, 0x3C, 0x3C, 0x05, 0x05, 0x0D, 0x0D, 0x15, 0x15, 0x1D, 0x1D, 0x25, 0x25, 0x2D,
                           0x2D, 0x35, 0x35, 0x3D, 0x3D, 0x06, 0x06, 0x06, 0x0E, 0x0E, 0x0E, 0x16, 0x16, 0x16, 0x1E,
                           0x1E, 0x1E, 0x26, 0x26, 0x26, 0x2E, 0x2E, 0x2E, 0x36, 0x36, 0x36, 0x3E, 0x3E, 0x3E, 0x47,
                           0x47, 0x47, 0x4F, 0x4F, 0x4F, 0x57, 0x57, 0x57, 0x5F, 0x5F, 0x5F, 0x67, 0x67, 0x67, 0x6F,
                           0x6F, 0x6F, 0x77, 0x77, 0x77, 0x7F, 0x7F, 0x7F, 0xFF, 0x00, 0x00, 0x00 };

static s8 D_E000CCE0[] = { 0x00, 0x10, 0x20, 0x30, 0x01, 0x11, 0x21, 0x31, 0x02, 0x0A, 0x12, 0x1A, 0x22, 0x2A, 0x32,
                           0x3A, 0x03, 0x0B, 0x13, 0x1B, 0x23, 0x2B, 0x33, 0x3B, 0x04, 0x0C, 0x14, 0x1C, 0x24, 0x2C,
                           0x34, 0x3C, 0x05, 0x0D, 0x15, 0x1D, 0x25, 0x2D, 0x35, 0x3D, 0x06, 0x06, 0x0E, 0x16, 0x16,
                           0x1E, 0x26, 0x26, 0x2E, 0x36, 0x36, 0x3E, 0x47, 0x47, 0x4F, 0x57, 0x57, 0x5F, 0x67, 0x67,
                           0x6F, 0x77, 0x77, 0x7F, 0xFF, 0x00, 0x00, 0x00 };

static s8* D_E000CD24[4] = { &D_E000CC38, &D_E000CC48, &D_E000CC5C, &D_E000CCE0 };

void fx_6_init(EffectInstance* effect);
void fx_6_update(EffectInstance* effect);
void fx_6_render(EffectInstance* effect);
void fx_6_appendGfx(EffectInstance* effect);

void func_E000C000(Effect6* part) {
    part->unk_18 += part->unk_1C;
    part->unk_14 += part->unk_18;
    part->unk_10 += part->unk_14;
    part->x += part->unk_10 * part->unk_30;
    part->z += part->unk_10 * part->unk_34;
    part->unk_28 += part->unk_2C;
    part->unk_24 += part->unk_28;
    part->unk_20 += part->unk_24;
    part->y += part->unk_20;
}

void func_E000C094(Effect6* part) {
    part->y += part->unk_20;
    part->unk_20 += part->unk_24;
    part->unk_24 *= part->unk_28;
}

void func_E000C0C8(Effect6* part) {
    part->x += part->unk_10 * part->unk_30;
    part->y += part->unk_20;
    part->z += part->unk_10 * part->unk_34;
    part->unk_20 += part->unk_24;
    part->unk_10 *= part->unk_14;
    part->unk_24 *= part->unk_28;
    part->unk_20 *= part->unk_2C;
}

void fx_6_main(s32 type, f32 x, f32 y, f32 z, f32 arg4) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    Effect6* effectPart;
    f32 theta;
    f32 temp_f20_2;
    s32 numParts;
    s32 i;

    switch (type) {
        case 2:
            numParts = 1;
            break;
        case 3:
            numParts = 4;
            break;
        case 4:
            numParts = 9;
            break;
        default:
            numParts = 3;
            break;
    }

    bpPtr->init = fx_6_init;
    bpPtr->update = fx_6_update;
    bpPtr->renderWorld = fx_6_render;
    bpPtr->unk_00 = 0;
    bpPtr->unk_14 = NULL;
    bpPtr->effectIndex = 6;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;

    effectPart = shim_general_heap_malloc(numParts * sizeof(Effect6));
    effect->data = effectPart;
    ASSERT(effect->data != NULL);

    shim_mem_clear(effectPart, numParts * sizeof(Effect6));

    switch (type) {
        case 0:
        case 1:
            effectPart->unk_38 = 0;
            break;
        case 3:
            effectPart->unk_38 = 2;
            break;
        case 2:
        case 4:
            effectPart->unk_38 = 3;
            break;
    }

    effectPart->unk_3C = 0;
    effectPart->type = type;
    effectPart->x = x;
    effectPart->y = y;
    effectPart->z = z;

    effectPart++;

    switch (type) {
        case 0:
        case 1:
            for (i = 1; i < numParts; i++, effectPart++) {
                effectPart->unk_10 = -3.0f;
                effectPart->unk_14 = 0.29999998f;
                effectPart->unk_18 = 0;
                effectPart->unk_1C = 0;
                effectPart->unk_20 = 1.75f;
                effectPart->unk_24 = -0.16f;
                effectPart->unk_28 = 0.0f;
                effectPart->unk_2C = 0.0f;
                effectPart->x = 0.0f;
                effectPart->y = 0.0f;
                effectPart->z = 4.0f;
                theta = shim_clamp_angle(90 + (180 * (i - 1)));
                effectPart->unk_30 = shim_sin_deg(theta);
                effectPart->unk_34 = shim_cos_deg(theta);
            }
            break;
        case 2:
            break;
        case 3:
            for (i = 1; i < numParts; i++, effectPart++) {
                switch (i - 1) {
                    case 0:
                        theta = 135.0f;
                        effectPart->x = -shim_sin_deg(theta) * 25.0f;
                        effectPart->y = 0.0f;
                        effectPart->z = -shim_cos_deg(theta) * 25.0f;
                        effectPart->unk_24 = -0.04f;
                        effectPart->unk_28 = 0.94f;
                        effectPart->unk_20 = 0.95f;
                        break;
                    case 1:
                        theta = -135.0f;
                        effectPart->x = -shim_sin_deg(theta) * 25.0f;
                        effectPart->y = 4.0f;
                        effectPart->z = -shim_cos_deg(theta) * 25.0f;
                        effectPart->unk_24 = -0.04f;
                        effectPart->unk_28 = 0.94f;
                        effectPart->unk_20 = 0.84999996f;
                        break;
                    case 2:
                        theta = 20.0f;
                        effectPart->x = -shim_sin_deg(theta) * 25.0f;
                        effectPart->y = 10.0f;
                        effectPart->z = -shim_cos_deg(theta) * 25.0f;
                        effectPart->unk_24 = -0.04f;
                        effectPart->unk_28 = 0.94f;
                        effectPart->unk_20 = 0.75f;
                        break;

                }
                effectPart->unk_30 = 0.0f;
                effectPart->unk_34 = 0.0f;
            }
            break;
        case 4:
            for (i = 1; i < numParts; i++, effectPart++) {
                effectPart->unk_10 = -3.0f;
                effectPart->unk_14 = 0.93f;
                effectPart->unk_20 = 0.0f;
                effectPart->unk_24 = 0.099999994f;
                effectPart->unk_28 = 0.94f;
                effectPart->unk_2C = 0.94f;
                theta = arg4 + ((i - 1) * 360 / (numParts - 1));
                effectPart->x = -shim_sin_deg(theta) * 10.0f;
                effectPart->y = 0.0f;
                effectPart->z = -shim_cos_deg(theta) * 10.0f;
                effectPart->unk_30 = shim_sin_deg(theta);
                effectPart->unk_34 = shim_cos_deg(theta);
            }
            break;
    }
}

void fx_6_init(EffectInstance* effect) {
}

void fx_6_update(EffectInstance* effect) {
    Effect6* effectPart = effect->data;

    effectPart->unk_40 = D_E000CD24[effectPart->unk_38][effectPart->unk_3C++];

    if (effectPart->unk_40 < 0) {
        shim_remove_effect(effect);
    } else {
        s32 type = effectPart->type;
        s32 i;

        effectPart++;

        for (i = 1; i < effect->numParts; i++, effectPart++) {
            switch (type) {
                case 0:
                case 1:
                    func_E000C000(effectPart);
                    break;
                case 2:
                    break;
                case 3:
                    func_E000C094(effectPart);
                    break;
                case 4:
                    func_E000C0C8(effectPart);
                    break;
            }
        }
    }
}

void fx_6_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_6_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void fx_6_appendGfx(EffectInstance* effect) {
    Effect6* part = effect->data;
    s32 type = part->type;
    s32 temp_t0 = part->unk_40;
    Matrix4f mtx1;
    Matrix4f mtx2;
    Matrix4f mtx3;
    s32 spD8;
    s32 spDC;
    s32 temp_lo;
    s32 envAlpha;
    s32 dlist1;
    s32 dlist2;
    s32 phi_a0;
    s32 temp;
    s32 i;

    envAlpha = (temp_t0 & 0x38) * 4;

    dlist1 = sDlists[type];
    dlist2 = sDlists2[type];

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->effect->data));
    gSPDisplayList(gMasterGfxPos++, dlist2);

    spD8 = temp_t0 & 7;
    spDC = temp_t0 & 0x40;

    shim_guTranslateF(mtx1, part->x, part->y, part->z);
    shim_guRotateF(mtx2, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(mtx2, mtx1, mtx3);
    shim_guMtxF2L(mtx3, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++,
              &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    switch (type) {
        case 0:
        case 1:
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 230, 222, 222, 110);
            gDPSetEnvColor(gMasterGfxPos++, 0, 0, 0, envAlpha);
            break;
        case 2:
        case 3:
        case 4:
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 230, 222, 222, 130);
            gDPSetEnvColor(gMasterGfxPos++, 0, 0, 0, envAlpha);
            break;
    }

    if (type == 0) {
        phi_a0 = 24;
    } else {
        phi_a0 = 32;
    }

    temp_lo = spD8 * phi_a0;
    temp = temp_lo + phi_a0;

    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, temp_lo * 4, 0, temp * 4, phi_a0 * 4);

    if (spDC) {
        gDPSetTileSize(gMasterGfxPos++, 1, temp * 4, phi_a0 * 4, (temp_lo + (phi_a0 * 2)) * 4, phi_a0 * 8);
    } else {
        gDPSetTileSize(gMasterGfxPos++, 1, temp * 4, 0,          (temp_lo + (phi_a0 * 2)) * 4, phi_a0 * 4);
    }

    if (type == 2) {
        gSPDisplayList(gMasterGfxPos++, dlist1);
    }

    part++;

    for (i = 1; i < effect->numParts; i++, part++) {
        shim_guTranslateF(mtx1, part->x, part->y, part->z);
        shim_guMtxF2L(mtx1, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, dlist1);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}
