#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002780_32B620[];
extern Gfx D_09002868_32B708[];
extern Gfx D_09002950_32B7F0[];
extern Gfx D_09002A38_32B8D8[];
extern Gfx D_09002B20_32B9C0[];
extern Gfx D_09002B40_32B9E0[];
extern Gfx D_09002B60_32BA00[];

static Gfx* sDlists[] = { D_09002B20_32B9C0, D_09002B40_32B9E0, D_09002B60_32BA00, D_09002B60_32BA00, D_09002B60_32BA00 };
static Gfx* sDlists2[] = { D_09002780_32B620, D_09002868_32B708, D_09002950_32B7F0, D_09002A38_32B8D8, D_09002A38_32B8D8 };

static s8 D_E000CC38[] = { 0x00, 0x01, 0x02, 0x1A, 0x03, 0x1B, 0x04, 0x1C, 0x05, 0x15, 0x35, 0x46, 0x46, 0x46, 0xFF,
                           0x00 };

static s8 D_E000CC48[] = { 0x00, 0x01, 0x02, 0x1A, 0x03, 0x1B, 0x04, 0x1C, 0x05, 0x1D, 0x06, 0x16, 0x26, 0x47, 0x57,
                           0x67, 0xFF, 0x00, 0x00, 0x00 };

static s8 D_E000CC5C[] = {
    0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38, 0x01, 0x09, 0x11, 0x19, 0x21, 0x29, 0x31, 0x39, 0x02, 0x02, 0x0A,
    0x0A, 0x12, 0x12, 0x1A, 0x1A, 0x22, 0x22, 0x2A, 0x2A, 0x32, 0x32, 0x3A, 0x3A, 0x03, 0x03, 0x0B, 0x0B, 0x13, 0x13,
    0x1B, 0x1B, 0x23, 0x23, 0x2B, 0x2B, 0x33, 0x33, 0x3B, 0x3B, 0x04, 0x04, 0x0C, 0x0C, 0x14, 0x14, 0x1C, 0x1C, 0x24,
    0x24, 0x2C, 0x2C, 0x34, 0x34, 0x3C, 0x3C, 0x05, 0x05, 0x0D, 0x0D, 0x15, 0x15, 0x1D, 0x1D, 0x25, 0x25, 0x2D, 0x2D,
    0x35, 0x35, 0x3D, 0x3D, 0x06, 0x06, 0x06, 0x0E, 0x0E, 0x0E, 0x16, 0x16, 0x16, 0x1E, 0x1E, 0x1E, 0x26, 0x26, 0x26,
    0x2E, 0x2E, 0x2E, 0x36, 0x36, 0x36, 0x3E, 0x3E, 0x3E, 0x47, 0x47, 0x47, 0x4F, 0x4F, 0x4F, 0x57, 0x57, 0x57, 0x5F,
    0x5F, 0x5F, 0x67, 0x67, 0x67, 0x6F, 0x6F, 0x6F, 0x77, 0x77, 0x77, 0x7F, 0x7F, 0x7F, 0xFF, 0x00, 0x00, 0x00
};

static s8 D_E000CCE0[] = { 0x00, 0x10, 0x20, 0x30, 0x01, 0x11, 0x21, 0x31, 0x02, 0x0A, 0x12, 0x1A, 0x22, 0x2A, 0x32,
                           0x3A, 0x03, 0x0B, 0x13, 0x1B, 0x23, 0x2B, 0x33, 0x3B, 0x04, 0x0C, 0x14, 0x1C, 0x24, 0x2C,
                           0x34, 0x3C, 0x05, 0x0D, 0x15, 0x1D, 0x25, 0x2D, 0x35, 0x3D, 0x06, 0x06, 0x0E, 0x16, 0x16,
                           0x1E, 0x26, 0x26, 0x2E, 0x36, 0x36, 0x3E, 0x47, 0x47, 0x4F, 0x57, 0x57, 0x5F, 0x67, 0x67,
                           0x6F, 0x77, 0x77, 0x7F, 0xFF, 0x00, 0x00, 0x00 };

static s8* D_E000CD24[4] = { D_E000CC38, D_E000CC48, D_E000CC5C, D_E000CCE0 };

void landing_dust_init(EffectInstance* effect);
void landing_dust_update(EffectInstance* effect);
void landing_dust_render(EffectInstance* effect);
void landing_dust_appendGfx(void* effect);

void func_E000C000(LandingDustFXData* part) {
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

void func_E000C094(LandingDustFXData* part) {
    part->y += part->unk_20;
    part->unk_20 += part->unk_24;
    part->unk_24 *= part->unk_28;
}

void func_E000C0C8(LandingDustFXData* part) {
    part->x += part->unk_10 * part->unk_30;
    part->y += part->unk_20;
    part->z += part->unk_10 * part->unk_34;
    part->unk_20 += part->unk_24;
    part->unk_10 *= part->unk_14;
    part->unk_24 *= part->unk_28;
    part->unk_20 *= part->unk_2C;
}

void landing_dust_main(s32 type, f32 x, f32 y, f32 z, f32 arg4) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    LandingDustFXData* data;
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

    bpPtr->init = landing_dust_init;
    bpPtr->update = landing_dust_update;
    bpPtr->renderWorld = landing_dust_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_LANDING_DUST;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;

    data = general_heap_malloc(numParts * sizeof(*data));
    effect->data.landingDust = data;
    ASSERT(effect->data.landingDust != NULL);

    mem_clear(data, numParts * sizeof(*data));

    switch (type) {
        case 0:
        case 1:
            data->unk_38 = 0;
            break;
        case 3:
            data->unk_38 = 2;
            break;
        case 2:
        case 4:
            data->unk_38 = 3;
            break;
    }

    data->unk_3C = 0;
    data->type = type;
    data->x = x;
    data->y = y;
    data->z = z;

    data++;

    switch (type) {
        case 0:
        case 1:
            for (i = 1; i < numParts; i++, data++) {
                data->unk_10 = -3.0f;
                data->unk_14 = 0.29999998f;
                data->unk_18 = 0;
                data->unk_1C = 0;
                data->unk_20 = 1.75f;
                data->unk_24 = -0.16f;
                data->unk_28 = 0.0f;
                data->unk_2C = 0.0f;
                data->x = 0.0f;
                data->y = 0.0f;
                data->z = 4.0f;
                theta = clamp_angle(90 + (180 * (i - 1)));
                data->unk_30 = sin_deg(theta);
                data->unk_34 = cos_deg(theta);
            }
            break;
        case 2:
            break;
        case 3:
            for (i = 1; i < numParts; i++, data++) {
                switch (i - 1) {
                    case 0:
                        theta = 135.0f;
                        data->x = -sin_deg(theta) * 25.0f;
                        data->y = 0.0f;
                        data->z = -cos_deg(theta) * 25.0f;
                        data->unk_24 = -0.04f;
                        data->unk_28 = 0.94f;
                        data->unk_20 = 0.95f;
                        break;
                    case 1:
                        theta = -135.0f;
                        data->x = -sin_deg(theta) * 25.0f;
                        data->y = 4.0f;
                        data->z = -cos_deg(theta) * 25.0f;
                        data->unk_24 = -0.04f;
                        data->unk_28 = 0.94f;
                        data->unk_20 = 0.84999996f;
                        break;
                    case 2:
                        theta = 20.0f;
                        data->x = -sin_deg(theta) * 25.0f;
                        data->y = 10.0f;
                        data->z = -cos_deg(theta) * 25.0f;
                        data->unk_24 = -0.04f;
                        data->unk_28 = 0.94f;
                        data->unk_20 = 0.75f;
                        break;

                }
                data->unk_30 = 0.0f;
                data->unk_34 = 0.0f;
            }
            break;
        case 4:
            for (i = 1; i < numParts; i++, data++) {
                data->unk_10 = -3.0f;
                data->unk_14 = 0.93f;
                data->unk_20 = 0.0f;
                data->unk_24 = 0.099999994f;
                data->unk_28 = 0.94f;
                data->unk_2C = 0.94f;
                theta = arg4 + ((i - 1) * 360 / (numParts - 1));
                data->x = -sin_deg(theta) * 10.0f;
                data->y = 0.0f;
                data->z = -cos_deg(theta) * 10.0f;
                data->unk_30 = sin_deg(theta);
                data->unk_34 = cos_deg(theta);
            }
            break;
    }
}

void landing_dust_init(EffectInstance* effect) {
}

void landing_dust_update(EffectInstance* effect) {
    LandingDustFXData* data = effect->data.landingDust;

    data->unk_40 = D_E000CD24[data->unk_38][data->unk_3C++];

    if (data->unk_40 < 0) {
        remove_effect(effect);
    } else {
        s32 type = data->type;
        s32 i;

        data++;

        for (i = 1; i < effect->numParts; i++, data++) {
            switch (type) {
                case 0:
                case 1:
                    func_E000C000(data);
                    break;
                case 2:
                    break;
                case 3:
                    func_E000C094(data);
                    break;
                case 4:
                    func_E000C0C8(data);
                    break;
            }
        }
    }
}

void landing_dust_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = landing_dust_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void landing_dust_appendGfx(void* effect) {
    LandingDustFXData* part = ((EffectInstance*)effect)->data.landingDust;
    s32 type = part->type;
    s32 temp_t0 = part->unk_40;
    Matrix4f mtx1;
    Matrix4f mtx2;
    Matrix4f mtx3;
    s32 spD8;
    s32 spDC;
    s32 temp_lo;
    s32 envAlpha;
    Gfx* dlist1;
    Gfx* dlist2;
    s32 phi_a0;
    s32 temp;
    s32 i;

    envAlpha = (temp_t0 & 0x38) * 4;

    dlist1 = sDlists[type];
    dlist2 = sDlists2[type];

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, dlist2);

    spD8 = temp_t0 & 7;
    spDC = temp_t0 & 0x40;

    guTranslateF(mtx1, part->x, part->y, part->z);
    guRotateF(mtx2, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtx2, mtx1, mtx3);
    guMtxF2L(mtx3, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++,
              &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    switch (type) {
        case 0:
        case 1:
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 230, 222, 222, 110);
            gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, envAlpha);
            break;
        case 2:
        case 3:
        case 4:
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 230, 222, 222, 130);
            gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, envAlpha);
            break;
    }

    if (type == 0) {
        phi_a0 = 24;
    } else {
        phi_a0 = 32;
    }

    temp_lo = spD8 * phi_a0;
    temp = temp_lo + phi_a0;

    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, temp_lo * 4, 0, temp * 4, phi_a0 * 4);

    if (spDC) {
        gDPSetTileSize(gMainGfxPos++, 1, temp * 4, phi_a0 * 4, (temp_lo + (phi_a0 * 2)) * 4, phi_a0 * 8);
    } else {
        gDPSetTileSize(gMainGfxPos++, 1, temp * 4, 0,          (temp_lo + (phi_a0 * 2)) * 4, phi_a0 * 4);
    }

    if (type == 2) {
        gSPDisplayList(gMainGfxPos++, dlist1);
    }

    part++;

    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        guTranslateF(mtx1, part->x, part->y, part->z);
        guMtxF2L(mtx1, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist1);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
