#include "common.h"
#include "effects_internal.h"

s32 D_E001C5E0 = 0;

extern Gfx D_09000900[];
extern Gfx D_090009E8[];

void fx_14_init(EffectInstance* effect);
void fx_14_update(EffectInstance* effect);
void fx_14_render(EffectInstance* effect);
void fx_14_appendGfx(EffectInstance* effect);

void fx_14_main(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect14* part;
    s32 numParts = 1;
    f32 phi_f4;

    bp.unk_00 = 0;
    bp.init = fx_14_init;
    bp.update = fx_14_update;
    bp.renderWorld = fx_14_render;
    bp.unk_14 = 0;
    bp.effectIndex = 14;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = 1;
    part = effect->data = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data != NULL);

    part->xPos = arg0;
    part->yPos = arg1;
    part->zPos = arg2;
    part->unk_0C = 0;
    part->unk_14 = 0;
    part->unk_18 = 0;
    part->unk_1C = 0;
    part->unk_10 = -3.0f;
    part->unk_20 = 3.0f;
    if (D_E001C5E0 != 0) {
        phi_f4 = -10.0f;
    } else {
        phi_f4 = 10.0f;
    }
    part->unk_24 = phi_f4;
    part->unk_28 = arg3;

    D_E001C5E0++;
    if (D_E001C5E0 >= 2) {
        D_E001C5E0 = 0;
    }
}

void fx_14_init(EffectInstance* effect) {
}

void fx_14_update(EffectInstance* effect) {
    Effect14* data = effect->data;

    data->unk_28--;
    if (data->unk_28 < 0) {
        shim_remove_effect(effect);
        return;
    }

    data->xPos += data->unk_0C;
    data->yPos += data->unk_10;
    data->zPos += data->unk_14;
    data->unk_18 += data->unk_20;
    if (data->unk_18 < 10.0f) {
        data->unk_18 = 10.0f;
        data->unk_20 = -data->unk_20;
    }
    if (data->unk_18 > 45.0f) {
        data->unk_18 = 45.0f;
        data->unk_20 = -data->unk_20;
    }
    data->unk_1C += data->unk_24;
}

void fx_14_render(EffectInstance* effect) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Effect14* effect14 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    f32 effectPos = effect14->xPos;
    f32 playerPos = playerStatus->position.x;

    if (effectPos - playerPos > 200) {
        effect14->xPos = effectPos - 400;
    } else {
        if (playerPos - effectPos > 200) {
            effect14->xPos = effectPos + 400;
        }
    }

    effectPos = effect14->zPos;
    playerPos = playerStatus->position.z;
    if (effectPos - playerPos > 200) {
        effect14->zPos = effectPos - 400;
    } else {
        if (playerPos - effectPos > 200) {
            effect14->zPos = effectPos + 400;
        }
    }

    renderTaskPtr->appendGfx = &fx_14_appendGfx;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->distance = 0;
    renderTaskPtr->renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_MODE_2;
}

void fx_14_appendGfx(EffectInstance* effect) {
    Matrix4f sp18, sp58, sp98, spD8, sp118;
    EffectInstance* effectTemp = effect;
    Effect14* part = effect->data;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->effect->data));
    gSPDisplayList(gMasterGfxPos++, D_09000900);

    shim_guTranslateF(sp18, part->xPos, part->yPos, part->zPos);
    shim_guRotateF(spD8, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(spD8, sp18, sp118);
    shim_guMtxF2L(sp118, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, 255);

    shim_guRotateF(sp58, part->unk_18, 1.0f, 0.0f, 0.0f);
    shim_guRotateF(sp98, part->unk_1C, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp98, sp118);
    shim_guMtxF2L(sp118, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_090009E8);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
