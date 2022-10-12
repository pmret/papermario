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
    bp.renderWorld = fright_jar_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FRIGHT_JAR;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.frightJar = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.frightJar != NULL);

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

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_10 = 16;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        shim_remove_effect(effect);
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
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
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

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp10, data->unk_04, data->unk_08, data->unk_0C);
    shim_guScaleF(sp50, -data->unk_28, data->unk_28, data->unk_28);
    shim_guMtxCatF(sp50, sp10, sp10);
    shim_guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_09008BE0_3CA780);

    idx = 54 - unk_14;
    if (idx < 0) {
        idx = 0;
    }

    gSPVertex(gMasterGfxPos++, &D_09004040_3C5BE0[idx], 22, 0);

    alpha = D_E00C2990[unk_14 % 16];
    gDPSetEnvColor(gMasterGfxPos++, 0, 0, 0, alpha);

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

        gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, temp3);
        gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 64, &D_09002020_3C3BC0);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14);
        gDPLoadSync(gMasterGfxPos++);
        gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, temp1 * 4, 254, (temp1 + 15) * 4);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 8, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14);
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, temp1 * 4, 508, (temp1 + 15) * 4);
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, temp2 * 128.0f * 4.0f, 2000, 2000);
        gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 64, &D_09000000_3C1BA0);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x80, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14);
        gDPLoadSync(gMasterGfxPos++);
        gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, temp1 * 4, 254, (temp1 + 15) * 4);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 8, 0x80, 1, 1, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14, G_TX_NOMIRROR | G_TX_CLAMP, 7, 14);
        gDPSetTileSize(gMasterGfxPos++, 1, 0, temp1 * 4, 508, (temp1 + 15) * 4);
        gDPSetTileSize(gMasterGfxPos++, 1, 0, temp2 * 128.0f * 4.0f, 2000, 2000);

        switch (i) {
            case 0:
                gSP2Triangles(gMasterGfxPos++, 0, 1, 2, 0, 0, 2, 3, 0);
                break;
            case 1:
                gSP2Triangles(gMasterGfxPos++, 1, 4, 5, 0, 1, 5, 2, 0);
                break;
            case 2:
                gSP2Triangles(gMasterGfxPos++, 4, 6, 7, 0, 4, 7, 5, 0);
                break;
            case 3:
                gSP2Triangles(gMasterGfxPos++, 6, 8, 9, 0, 6, 9, 7, 0);
                break;
            case 4:
                gSP2Triangles(gMasterGfxPos++, 8, 10, 11, 0, 8, 11, 9, 0);
                break;
            case 5:
                gSP2Triangles(gMasterGfxPos++, 10, 12, 13, 0, 10, 13, 11, 0);
                break;
            case 6:
                gSP2Triangles(gMasterGfxPos++, 12, 14, 15, 0, 12, 15, 13, 0);
                break;
            case 7:
                gSP2Triangles(gMasterGfxPos++, 14, 16, 17, 0, 14, 17, 15, 0);
                break;
            case 8:
                gSP2Triangles(gMasterGfxPos++, 16, 18, 19, 0, 16, 19, 17, 0);
                break;
            case 9:
                gSP2Triangles(gMasterGfxPos++, 18, 20, 21, 0, 18, 21, 19, 0);
                break;
        }

        gDPPipeSync(gMasterGfxPos++);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
