#include "common.h"
#include "effects_internal.h"
#include "nu/nusys.h"

typedef struct UnkStruct {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char unk_09[3]; // likely padding
    /* 0x0C */ Gfx* unk_0C;
} UnkStruct; // size = 0x10

extern Gfx D_09000800_3543B0[];
extern Gfx D_090008F8_3544A8[];
extern Gfx D_09000918_3544C8[];
extern Gfx D_090009E0_354590[];

UnkStruct D_E0040840[] = {
    { 255, 109, 255,  92, 102, 191, 255, 75,  50, {}, D_09000800_3543B0 },
    { 255, 255, 255,   0, 255,  32,   0, 75, 100, {}, D_09000800_3543B0 },
    { 255,   0, 255,  92, 107, 168, 255, 75,  10, {}, D_09000800_3543B0 },
    { 255, 255, 255, 244, 247, 175, 175, 22,  30, {}, D_09000800_3543B0 }
};

s32 D_E0040880;

void flame_init(EffectInstance* effect);
void flame_update(EffectInstance* effect);
void flame_render(EffectInstance* effect);
void flame_appendGfx(void* effect);

void flame_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    EffectInstance** outEffect
) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    FlameFXData* data;
    s32 numParts = 1;

    if (arg0 > 3) {
        arg0 = 3;
    }

    bpPtr->init = flame_init;
    bpPtr->update = flame_update;
    bpPtr->renderWorld = flame_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_FLAME;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    data = effect->data.flame = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.flame != NULL);

    data->unk_00 = arg0;
    data->unk_18 = 0;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->unk_10 = arg4 * D_E0040840[arg0].unk_08 * 0.01;
    data->unk_1C = 0;
    data->unk_24 = 0;
    data->unk_20 = 0;
    data->unk_30 = 1.0f;
    data->unk_2C = 1.0f;
    data->unk_28 = 1.0f;

    if (outEffect != NULL) {
        *outEffect = effect;
    }
}

void flame_init(EffectInstance* effect) {
}

void flame_update(EffectInstance* effect) {
    FlameFXData* part = effect->data.flame;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        part->unk_1C += part->unk_20;
        if (part->unk_1C > 64.0f) {
            part->unk_1C -= 64.0f;
        }
        if (part->unk_1C < 0.0f) {
            part->unk_1C += 64.0f;
        }

        part->unk_24 += part->unk_28;
        if (part->unk_24 > 128.0f) {
            part->unk_24 -= 128.0f;
        }
        if (part->unk_24 < 0.0f) {
            part->unk_24 += 128.0f;
        }
    }
}

void flame_render(EffectInstance* effect) {
    FlameFXData* data = effect->data.flame;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 outDist;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 outW;

    transform_point(gCameras[gCurrentCameraID].perspectiveMatrix, data->pos.x, data->pos.y, data->pos.z, 1.0f,
                         &outX, &outY, &outZ, &outW);

    outDist = outZ + 5000;
    if (outDist < 0) {
        outDist = 0;
    } else if (outDist > 10000) {
        outDist = 10000;
    }

    if (outW < 0.01 && -0.01 < outW) {
        outDist = 0;
    }

    renderTaskPtr->appendGfx = flame_appendGfx;
    renderTaskPtr->dist = -outDist;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    queue_render_task(renderTaskPtr);
}

void flame_appendGfx(void* effect) {
    FlameFXData* data = ((EffectInstance*)effect)->data.flame;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_00 = data->unk_00;
    s32 uls = data->unk_1C * 4.0f;
    s32 ult = data->unk_24 * 4.0f;
    UnkStruct* unkStruct;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    if (D_E0040880 != gGameStatusPtr->frameCounter) {
        D_E0040880 = gGameStatusPtr->frameCounter;
        gSPDisplayList(gMainGfxPos++, D_09000918_3544C8);
        gDPSetTileSize(gMainGfxPos++, 1, uls, ult, uls + 128, ult + 256);
        gSPDisplayList(gMainGfxPos++, D_090009E0_354590);
        gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, VIRTUAL_TO_PHYSICAL(nuGfxCfb_ptr));
        gDPSetScissorFrac(gMainGfxPos++, G_SC_NON_INTERLACE,
            camera->viewportStartX * 4.0f,
            camera->viewportStartY * 4.0f,
            (camera->viewportStartX + camera->viewportW) * 4.0f,
            (camera->viewportStartY + camera->viewportH) * 4.0f);
    }

    unkStruct = &D_E0040840[unk_00];

    gSPDisplayList(gMainGfxPos++, unkStruct->unk_0C);
    gDPSetKeyR(gMainGfxPos++, unkStruct->unk_03, unkStruct->unk_00, 0);
    gDPSetKeyGB(gMainGfxPos++, unkStruct->unk_03, unkStruct->unk_01, 0, unkStruct->unk_03, unkStruct->unk_02, 0);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, unkStruct->unk_07, unkStruct->unk_07, unkStruct->unk_07, 0);
    gDPSetEnvColor(gMainGfxPos++, unkStruct->unk_04, unkStruct->unk_05, unkStruct->unk_06, 0);

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);
    guScaleF(sp58, data->unk_10 * data->unk_30, data->unk_10 * data->unk_2C, data->unk_10);
    guMtxCatF(sp58, sp98, sp98);
    guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_090008F8_3544A8);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
