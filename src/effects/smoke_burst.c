#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002950_32B7F0[];
extern Gfx D_09002B60_32BA00[];
extern Gfx D_09002C60_32BB00[];

Gfx* D_E004E5E0[] = {
    D_09002B60_32BA00, D_09002C60_32BB00, D_09002B60_32BA00
};

Gfx* D_E004E5EC[] = {
    D_09002950_32B7F0, D_09002950_32B7F0, D_09002950_32B7F0
};

void smoke_burst_init(EffectInstance* effect);
void smoke_burst_update(EffectInstance* effect);
void smoke_burst_render(EffectInstance* effect);
void smoke_burst_appendGfx(void* effect);

void smoke_burst_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 timeLeft) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    SmokeBurstFXData* data;
    s32 numParts = 1;

    effectBp.init = smoke_burst_init;
    effectBp.update = smoke_burst_update;
    effectBp.renderWorld = smoke_burst_render;
    effectBp.unk_00 = 0;
    effectBp.renderUI = NULL;
    effectBp.effectID = EFFECT_SMOKE_BURST;

    effect = create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.smokeBurst = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    mem_clear(data, numParts * sizeof(*data));
    data->timeLeft = timeLeft;
    data->lifeTime = 0;
    data->unk_1C = timeLeft;
    data->unk_20 = 0;
    data->unk_00 = arg0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_10 = arg4;

    switch (arg0) {
        case 0:
            data->rgba.b = 0;
            data->rgba.g = 0;
            data->rgba.r = 0;
            data->rgba.a = 130;
            break;
        case 1:
            data->rgba.r = 255;
            data->rgba.b = 0;
            data->rgba.g = 0;
            data->rgba.a = 130;
            break;
        default:
            data->rgba.r = 225;
            data->rgba.g = 215;
            data->rgba.b = 255;
            data->rgba.a = 180;
            break;
    }
}

void smoke_burst_init(EffectInstance* effect) {
}

void smoke_burst_update(EffectInstance *effect) {
    SmokeBurstFXData* data = effect->data.smokeBurst;

    data->unk_20 = (data->lifeTime * 8.0f) / data->unk_1C;
    data->lifeTime++;
    data->timeLeft--;

    if (data->timeLeft < 0) {
        remove_effect(effect);
    }
}

void smoke_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = smoke_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void smoke_burst_appendGfx(void* effect) {
    SmokeBurstFXData* data = ((EffectInstance*)effect)->data.smokeBurst;
    s32 unk_20_s32 = data->unk_20;
    s32 envAlpha = (data->unk_20 - unk_20_s32) * 256.0f;
    s32 cond = (unk_20_s32 == 7);
    s32 temp_a1;
    Gfx* dlist = D_E004E5E0[data->unk_00];
    Gfx* dlist2 = D_E004E5EC[0];
    Matrix4f sp20;
    Matrix4f sp60;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, dlist2);

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, data->unk_10, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp60, 20.0f, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->rgba.r, data->rgba.g, data->rgba.b, data->rgba.a);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, envAlpha);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_DITHER);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE,
        (unk_20_s32 * 32     ) * 4, 0,
        (unk_20_s32 * 32 + 31) * 4, 31 * 4);

    temp_a1 = unk_20_s32 * 32 + 32;

    if (cond) {
        gDPSetTileSize(gMainGfxPos++, 1,
            (temp_a1     ) * 4, 32 * 4,
            (temp_a1 + 31) * 4, 63 * 4);
    } else {
        gDPSetTileSize(gMainGfxPos++, 1,
            (temp_a1     ) * 4, 0,
            (temp_a1 + 31) * 4, 31 * 4);
    }

    gSPDisplayList(gMainGfxPos++, dlist);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
