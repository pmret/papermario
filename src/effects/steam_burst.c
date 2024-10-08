#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000E00_362470[];
extern Gfx D_09000F30_3625A0[];

Gfx* D_E005C700[] = { D_09000F30_3625A0 };
Gfx* D_E005C704[] = { D_09000E00_362470 };

void steam_burst_init(EffectInstance* effect);
void steam_burst_update(EffectInstance* effect);
void steam_burst_render(EffectInstance* effect);
void steam_burst_appendGfx(void* effect);

void steam_burst_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SteamBurstFXData* part;
    s32 numParts = 2;
    s32 i;

    bp.init = steam_burst_init;
    bp.update = steam_burst_update;
    bp.renderScene = steam_burst_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_STEAM_BURST;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.steamBurst = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.steamBurst != NULL);

    mem_clear(part, numParts * sizeof(*part));

    part->unk_24 = arg5;
    part->unk_28 = 0;
    part->unk_2C = arg5;
    part->unk_30 = 0;
    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_1C = 10.0f;
    part->unk_20 = 30.0f;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        f32 zero = 0.0f;

        part->unk_04 = zero;
        part->unk_08 = zero;
        part->unk_0C = zero;
        part->unk_10 = sin_deg(0.0f);
        part->unk_14 = 0.0f;
        part->unk_18 = cos_deg(0.0f);
    }
}

void steam_burst_init(EffectInstance* effect) {
}

void steam_burst_update(EffectInstance* effect) {
    SteamBurstFXData* part = effect->data.steamBurst;
    f32 unk_1C;
    s32 i;

    part->unk_30 = part->unk_28 * 7.0f / part->unk_2C;
    part->unk_28++;
    part->unk_24--;

    if (part->unk_24 < 0) {
        remove_effect(effect);
        return;
    }

    part->unk_1C += (part->unk_20 - part->unk_1C) * 0.1;
    unk_1C = part->unk_1C;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_14 += 0.04;
        part->unk_14 *= 0.9;
        part->unk_04 = unk_1C * part->unk_10;
        part->unk_08 += part->unk_14;
        part->unk_0C = unk_1C * part->unk_18;
    }
}

void steam_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = steam_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void steam_burst_appendGfx(void* effect) {
    SteamBurstFXData* part = ((EffectInstance*)effect)->data.steamBurst;
    s32 unk_30_s32 = part->unk_30;
    s32 envAlpha = (part->unk_30 - unk_30_s32) * 256.0f;
    s32 cond = (unk_30_s32 == 6);
    Gfx* dlist = D_E005C700[part->unk_00];
    Gfx* dlist2 = D_E005C704[part->unk_00];
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, dlist2);

    guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);
    guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 230, 222, 222, 130);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, envAlpha);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE,
        (unk_30_s32 * 32     ) * 4, 0,
        (unk_30_s32 * 32 + 32) * 4, 32 * 4);

    if (cond) {
        gDPSetTileSize(gMainGfxPos++, 1,
            (unk_30_s32 * 32 + 32) * 4, 32 * 4,
            (unk_30_s32 * 32 + 64) * 4, 64 * 4);
    } else {
        gDPSetTileSize(gMainGfxPos++, 1,
            (unk_30_s32 * 32 + 32) * 4, 0,
            (unk_30_s32 * 32 + 64) * 4, 32 * 4);
    }

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
