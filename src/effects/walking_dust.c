#include "common.h"
#include "effects_internal.h"

s8 D_E000E660[16] = { 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6, -1, 0 };

s8 D_E000E670[20] = { 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, -1, 0, 0, 0 };

s8* D_E000E684[2] = { D_E000E660, D_E000E670 };

extern Gfx D_09002780_32B620[];
extern Gfx D_09002868_32B708[];
extern Gfx D_09002950_32B7F0[];
extern Gfx D_09002B20_32B9C0[];
extern Gfx D_09002B40_32B9E0[];

void walking_dust_init(EffectInstance* effect);
void walking_dust_update(EffectInstance* effect);
void walking_dust_render(EffectInstance* effect);
void walking_dust_appendGfx(void* effect);

void walking_dust_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    WalkingDustFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = walking_dust_init;
    bp.update = walking_dust_update;
    bp.renderScene = walking_dust_render;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_WALKING_DUST;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;

    data = general_heap_malloc(numParts * sizeof(*data));
    effect->data.walkingDust = data;
    ASSERT(effect->data.walkingDust != nullptr);

    mem_clear(data, numParts * sizeof(*data));
    data->unk_6C = arg0 == 2;
    data->unk_70 = 0;
    data->unk_04 = arg0;

    for (i = 0; i < numParts; i++, data++) {
        data->unk_00 = 1;
        data->unk_64 = arg4;
        data->unk_68 = arg5;
        data->unk_08 = arg1;
        data->unk_0C = arg2;
        data->unk_10 = arg3;
        data->unk_58 = 0.33333334f;
        data->unk_5C = 1.75f;
        data->unk_60 = -0.16f;
    }
}

void walking_dust_init(EffectInstance* effect) {
}

void walking_dust_update(EffectInstance* effect) {
    WalkingDustFXData* data = effect->data.walkingDust;

    data->unk_74 = D_E000E684[data->unk_6C][data->unk_70++];

    if (data->unk_74 < 0) {
        remove_effect(effect);
    } else {
        s32 i;

        for (i = 0; i < effect->numParts; i++, data++) {
            data->unk_08 += data->unk_58 * data->unk_64;
            data->unk_10 += data->unk_58 * data->unk_68;
            data->unk_5C = data->unk_5C + data->unk_60;
            data->unk_0C += data->unk_5C;
        }
    }
}

void walking_dust_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = walking_dust_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void walking_dust_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    WalkingDustFXData* data = effectTemp->data.walkingDust;
    s32 temp_t3 = data->unk_04;
    s32 temp_t4 = data->unk_74;
    s32 cond = false;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 temp_a0;
    s32 temp_lo;
    Gfx* dlist;
    Gfx* dlist2;
    s32 phi_t1;
    s32 i;

    if (temp_t3 == 0) {
        dlist2 = D_09002B20_32B9C0;
    } else {
        dlist2 = D_09002B40_32B9E0;
    }

    switch (temp_t3) {
        case 1:
            dlist = D_09002868_32B708;
            break;
        default:
            dlist = D_09002950_32B7F0;
            break;
        case 0:
            dlist = D_09002780_32B620;
            break;
    }

    if ((data->unk_6C == 0 && temp_t4 == 6) || (data->unk_6C == 1 && temp_t4 == 7)) {
        cond = true;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->shared->graphics));
    gSPDisplayList(gMainGfxPos++, dlist);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, 127);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 230, 222, 222, 110);

    if (temp_t3 == 0) {
        phi_t1 = 24;
    } else {
        phi_t1 = 32;
    }

    temp_lo = temp_t4 * phi_t1;
    temp_a0 = temp_lo + phi_t1;

    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, temp_lo * 4, 0, (temp_a0 - 1) * 4, ((phi_t1 - 1) * 4));

    if (cond) {
        gDPSetTileSize(gMainGfxPos++, 1, temp_a0 * 4, 0, ((temp_lo + (phi_t1 * 2)) - 1) * 4, 0);
    } else {
        gDPSetTileSize(gMainGfxPos++, 1, temp_a0 * 4, 0, ((temp_lo + (phi_t1 * 2)) - 1) * 4, (phi_t1 - 1) * 4);
    }

    for (i = 0; i < effectTemp->numParts; i++, data++) {
        guTranslateF(sp18, data->unk_08, data->unk_0C, data->unk_10);
        guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist2);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
    gDPPipeSync(gMainGfxPos++);
}
