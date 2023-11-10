#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000DA0_33C970[];
extern Gfx D_09000E28_33C9F8[];
extern Gfx D_090010B0_33CC80[];
extern Gfx D_09001138_33CD08[];

Gfx* D_E00269F0[] = { D_090010B0_33CC80, D_09000DA0_33C970 };
Gfx* D_E00269F8[] = { D_09001138_33CD08, D_09000E28_33C9F8 };

u8 D_E0026A00[] = {
    0xFF, 0xC5, 0x9C, 0xFF, 0x9C, 0xFF, 0xFF, 0x73, 0xD6, 0xFF, 0x9C, 0xFF, 0xFF, 0xC5, 0x7B, 0xFF,
    0xB4, 0xFF, 0xDE, 0x73, 0xFF, 0xFF, 0x94, 0x9C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void gather_energy_pink_init(EffectInstance* effect);
void gather_energy_pink_update(EffectInstance* effect);
void gather_energy_pink_render(EffectInstance* effect);
void gather_energy_pink_appendGfx(void* effect);

void gather_energy_pink_main(s32 type, f32 posX, f32 posY, f32 posZ, f32 scale, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    GatherEnergyPinkFXData* data;
    s32 numParts = 1;

    bp.unk_00 = 0;
    bp.init = gather_energy_pink_init;
    bp.update = gather_energy_pink_update;
    bp.renderWorld = gather_energy_pink_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_GATHER_ENERGY_PINK;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.gatherEnergyPink = general_heap_malloc(sizeof(*data));
    ASSERT (data != NULL);

    data->unk_00 = type;
    data->unk_28 = duration;
    data->unk_2C = 0;
    data->unk_24 = 0;
    data->posB.x = posX;
    data->posB.y = posY;
    data->posB.z = posZ;
    data->unk_44 = 0;
    data->unk_40 = 0;
    data->unk_4C = 0;
    data->unk_48 = 0;
    data->unk_34 = 0;
    data->unk_30 = 0;
    data->unk_3C = 0;
    data->unk_38 = 0;
    data->posA.x = posX;
    data->posA.y = posY;
    data->posA.z = posZ;

    data->unk_1C = 10.0f;

    data->unk_58 = effect_rand_int(360);
    data->unk_5C = 4.0f;

    data->unk_50 = 0;
    data->unk_54 = 0;

    if (type == 1) {
        data->unk_3C = 96;
        data->unk_20 = scale;
    } else {
        data->unk_44 = -2;
        data->unk_4C = -4;
        data->unk_20 = scale * 0.2;
    }
    return;
}

void gather_energy_pink_init(EffectInstance* effect) {
}

void gather_energy_pink_update(EffectInstance* effect) {
    GatherEnergyPinkFXData* part = effect->data.gatherEnergyPink;
    s32 unk_28;
    s32 unk_2C;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    s32 i;

    part->unk_28--;
    part->unk_2C++;

    if (part->unk_28 < 0) {
        remove_effect(effect);
        return;
    }

    unk_28 = part->unk_28;
    unk_2C = part->unk_2C;

    if (unk_2C < 11) {
        part->unk_24 = (unk_2C * 255) / 10;
    }

    if (unk_28 < 6) {
        part->unk_24 = (unk_28 * 255) / 6;
    }

    if (unk_28 < 10 && part->unk_00 == 0) {
        part->unk_1C *= 0.7;
    }

    if (part->unk_00 == 1) {
        part->unk_1C += (part->unk_20 + sin_deg(unk_28 * 10) * 0.1 * part->unk_20 - part->unk_1C) * 0.4;
    } else {
        part->unk_1C += (part->unk_20 + sin_deg(unk_28 * 10) * 0.1 * part->unk_20 - part->unk_1C) * 0.3;
    }

    transform_point(&gCameras[gCurrentCameraID].perspectiveMatrix[0], part->posA.x, part->posA.y, part->posA.z, 1.0f, &sp28, &sp2C, &sp30, &sp34);

    sp34 = 1.0f / sp34;
    sp28 *= sp34;
    sp2C *= sp34;
    sp30 *= sp34;

    part->posB.x = sp28;
    part->posB.y = sp2C;
    part->posB.z = 0;

    for (i = 0; i < effect->numParts; i++, part++) {
        part->unk_30 += part->unk_34;
        part->unk_38 += part->unk_3C;
        part->unk_40 += part->unk_44;
        part->unk_48 += part->unk_4C;
        part->unk_58 += part->unk_5C;
        part->unk_50 += part->unk_54;
        if (part->unk_40 < 0) {
            part->unk_40 += 256;
        }
        if (part->unk_48 < 0) {
            part->unk_48 += 256;
        }
    }
}

void gather_energy_pink_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = gather_energy_pink_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void gather_energy_pink_appendGfx(void* effect) {
    GatherEnergyPinkFXData* part = ((EffectInstance*)effect)->data.gatherEnergyPink;
    s32 unk_00 = part->unk_00;
    Gfx* dlist = D_E00269F8[unk_00];
    Gfx* dlist2 = D_E00269F0[unk_00];
    Camera* camera = &gCameras[gCurrentCameraID];
    Matrix4f sp20;
    Matrix4f sp60;
    Matrix4f unused;
    u16 perspNorm;
    s32 alpha;
    s32 idx;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, dlist);

    guTranslateF(sp20, part->posB.x, part->posB.y, part->posB.z);
    guScaleF(sp60, part->unk_1C, part->unk_1C, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guPerspectiveF(sp60, &perspNorm, unk_00 == 1 ? 130.0f : 30.0f, (f32) camera->viewportW / camera->viewportH, 4.0f, 16384.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    switch (unk_00) {
        case 1:
            guTranslateF(sp20, 0.0f, 0.0f, -70.0f);
            break;
        case 0:
            guTranslateF(sp20, 0.0f, 0.0f, -80.0f);
            break;
    }

    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    idx = part->unk_2C * 3;
    alpha = part->unk_24;

    for (i = 0; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        s32 tempX;
        s32 tempY;
        s32 tempX2;
        s32 tempY2;

        idx += 30;
        idx %= 24;

        gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, alpha / 2);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0026A00[idx], 0, D_E0026A00[idx + 2], alpha);

        tempX = part->unk_30;
        tempY = part->unk_40;
        tempX2 = part->unk_38;
        tempY2 = part->unk_48;

        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, tempX, tempY, tempX + 256, tempY + 256);
        gDPSetTileSize(gMainGfxPos++, 1, tempX2, tempY2, tempX2 + 256, tempY2 + 256);
        gSPDisplayList(gMainGfxPos++, dlist2);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPPipeSync(gMainGfxPos++);
}
