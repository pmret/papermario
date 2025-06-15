#include "common.h"
#include "effects_internal.h"

extern s32 D_09000000_3C1BA0;
extern s32 D_09002020_3C3BC0;
extern Vtx D_09004040_3C5BE0[][22];
extern Gfx D_09008BE0_3CA780[];

u8 D_E00C2990[] = {
    0xFF, 0xFF, 0xDC, 0xBE, 0xA0, 0x78, 0x50, 0x28,
    0x00, 0x00, 0x28, 0x50, 0x78, 0xA0, 0xBE, 0xDC
};

void fright_jar_init(EffectInstance* effect);
void fright_jar_update(EffectInstance* effect);
void fright_jar_render(EffectInstance* effect);
void fright_jar_appendGfx(void* effect);

EffectInstance* fright_jar_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FrightJarFXData* data;
    s32 numParts = 1;

    bp.init = fright_jar_init;
    bp.update = fright_jar_update;
    bp.renderScene = fright_jar_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_FRIGHT_JAR;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.frightJar = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.frightJar != nullptr);

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
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 120;
    data->unk_28 = arg4 * 0.1;

    return effect;
}

void fright_jar_init(EffectInstance* effect) {
}

void fright_jar_update(EffectInstance* effect) {
    FrightJarFXData* data = effect->data.frightJar;
    s32 unk_10;

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

    unk_10 = data->unk_10;

    if (data->unk_14 < 16) {
        data->unk_24 = data->unk_14 * 16 + 15;
    } else {
        data->unk_24 = 255;
    }

    if (unk_10 < 16) {
        data->unk_24 = unk_10 * 16;
    }
}

void fright_jar_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fright_jar_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00C2214(void) {
}

void fright_jar_appendGfx(void* effect) {
    FrightJarFXData* data = ((EffectInstance*)effect)->data.frightJar;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_14 = data->unk_14;
    s32 unk_24 = data->unk_24;
    u32 alpha;
    s32 idx;
    Matrix4f sp10;
    Matrix4f sp50;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp10, data->unk_04, data->unk_08, data->unk_0C);
    guScaleF(sp50, -data->unk_28, data->unk_28, data->unk_28);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_09008BE0_3CA780);

    idx = 54 - unk_14;
    if (idx < 0) {
        idx = 0;
    }

    gSPVertex(gMainGfxPos++, &D_09004040_3C5BE0[idx], 22, 0);

    alpha = D_E00C2990[unk_14 % 16];
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, alpha);

    for (i = 0; i < 10; i++) {
        s32 temp1;
        f32 temp2;
        f32 temp3;

        if (i < 5) {
            temp1 = i * 12;
        } else {
            temp1 = i * 12 + 4;
        }

        temp2 = i * 0.1f;
        temp3 = unk_24 * (1.0f - temp2) * 2.0f;

        if (temp3 > 255.0f) {
            temp3 = 255.0f;
        }

        gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, temp3);
        gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 64, &D_09002020_3C3BC0);
        gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14);
        gDPLoadSync(gMainGfxPos++);
        gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, temp1 * 4, 254, (temp1 + 15) * 4);
        gDPPipeSync(gMainGfxPos++);
        gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 8, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14);
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, temp1 * 4, 508, (temp1 + 15) * 4);
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, temp2 * 128.0f * 4.0f, 2000, 2000);
        gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 64, &D_09000000_3C1BA0);
        gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x80, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14);
        gDPLoadSync(gMainGfxPos++);
        gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, temp1 * 4, 254, (temp1 + 15) * 4);
        gDPPipeSync(gMainGfxPos++);
        gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 8, 0x80, 1, 1, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14);
        gDPSetTileSize(gMainGfxPos++, 1, 0, temp1 * 4, 508, (temp1 + 15) * 4);
        gDPSetTileSize(gMainGfxPos++, 1, 0, temp2 * 128.0f * 4.0f, 2000, 2000);

        switch (i) {
            case 0:
                gSP2Triangles(gMainGfxPos++, 0, 1, 2, 0, 0, 2, 3, 0);
                break;
            case 1:
                gSP2Triangles(gMainGfxPos++, 1, 4, 5, 0, 1, 5, 2, 0);
                break;
            case 2:
                gSP2Triangles(gMainGfxPos++, 4, 6, 7, 0, 4, 7, 5, 0);
                break;
            case 3:
                gSP2Triangles(gMainGfxPos++, 6, 8, 9, 0, 6, 9, 7, 0);
                break;
            case 4:
                gSP2Triangles(gMainGfxPos++, 8, 10, 11, 0, 8, 11, 9, 0);
                break;
            case 5:
                gSP2Triangles(gMainGfxPos++, 10, 12, 13, 0, 10, 13, 11, 0);
                break;
            case 6:
                gSP2Triangles(gMainGfxPos++, 12, 14, 15, 0, 12, 15, 13, 0);
                break;
            case 7:
                gSP2Triangles(gMainGfxPos++, 14, 16, 17, 0, 14, 17, 15, 0);
                break;
            case 8:
                gSP2Triangles(gMainGfxPos++, 16, 18, 19, 0, 16, 19, 17, 0);
                break;
            case 9:
                gSP2Triangles(gMainGfxPos++, 18, 20, 21, 0, 18, 21, 19, 0);
                break;
        }

        gDPPipeSync(gMainGfxPos++);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
