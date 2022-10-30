#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001040_3583E0[];
extern Gfx D_090010F8_358498[];

Gfx* D_E0048A00[] = { D_090010F8_358498, D_090010F8_358498 };
Gfx* D_E0048A08[] = { D_09001040_3583E0, D_09001040_3583E0 };

void ring_blast_init(EffectInstance* effect);
void ring_blast_update(EffectInstance* effect);
void ring_blast_render(EffectInstance* effect);
void ring_blast_appendGfx(void* effect);

void ring_blast_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 arg5) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    RingBlastFXData* data;
    s32 numParts = 1;

    effectBp.init = ring_blast_init;
    effectBp.update = ring_blast_update;
    effectBp.renderWorld = ring_blast_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_RING_BLAST;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;
    data = effect->data.ringBlast = shim_general_heap_malloc(numParts * sizeof(*data));

    ASSERT(data != NULL);
    shim_mem_clear(data, numParts * sizeof(*data));

    data->timeLeft = arg5;
    data->lifeTime = 0;
    data->unk_1C = arg5;
    data->unk_20 = 0;
    data->unk_00 = arg0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_10 = arg4;
    data->unk_24 = 0;
    if (arg0 == 0) {
        data->unk_28 = 0;
        return;
    }
    data->unk_28 = 40;
}

void ring_blast_init(EffectInstance* effect) {
}

void ring_blast_update(EffectInstance* effect) {
    RingBlastFXData* data = effect->data.ringBlast;

    data->unk_20 = data->lifeTime * 8.0f / data->unk_1C;

    data->lifeTime++;
    data->timeLeft--;

    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    data->unk_24 += data->unk_28;
    if (data->unk_00 == 0) {
        data->unk_10 += 0.1;
    }
}

void ring_blast_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = ring_blast_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void ring_blast_appendGfx(void* effect) {
    RingBlastFXData* data = ((EffectInstance*)effect)->data.ringBlast;
    s32 unk_00 = data->unk_00;
    s32 unk_20_s32 = data->unk_20;
    s32 envAlpha = (data->unk_20 - unk_20_s32) * 256.0f;
    s32 cond = (unk_20_s32 == 7);
    Gfx* dlist = D_E0048A00[unk_00];
    Gfx* dlist2 = D_E0048A08[unk_00];
    Matrix4f sp20;
    Matrix4f sp60;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, dlist2);

    shim_guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, data->unk_10, data->pos.x, data->pos.y, data->pos.z);
    shim_guRotateF(sp60, data->unk_24, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (unk_00 == 0) {
        f32 var_f4 = 1.0f;

        if (data->unk_20 > 5.0f) {
            var_f4 = 1.0f - (data->unk_20 - 5.0f);
            if (var_f4 < 0.0f) {
                var_f4 = 0.0f;
            }
        }

        gDPSetPrimColor(gMasterGfxPos++, 0, 0, var_f4 * 255.0f, var_f4 * 18.0f, var_f4 * 59.0f, 0);
        gDPSetEnvColor(gMasterGfxPos++, var_f4 * 255.0f, var_f4 * 53.0f, var_f4 * 24.0f, envAlpha);
        gDPSetKeyR(gMasterGfxPos++, var_f4 * 211.0f, 0, 0);
        gDPSetKeyGB(gMasterGfxPos++, var_f4 * 255.0f, 0, 0, var_f4 * 216.0f, 0, 0);
        gDPSetCombineLERP(gMasterGfxPos++, TEXEL1, TEXEL0, ENV_ALPHA, TEXEL0, TEXEL1, TEXEL0, ENVIRONMENT, TEXEL0, PRIMITIVE, CENTER, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, TEXEL1, TEXEL0, ENV_ALPHA, TEXEL0, TEXEL1, TEXEL0, ENVIRONMENT, TEXEL0, 1, COMBINED, PRIMITIVE, COMBINED, 0, 0, 0, COMBINED);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 40, 127);
        gDPSetEnvColor(gMasterGfxPos++, 255, 255, 139, envAlpha);
    }

    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE,
        (unk_20_s32 * 32     ) * 4, 0,
        (unk_20_s32 * 32 + 32) * 4, 32 * 4);

    if (cond) {
        gDPSetTileSize(gMasterGfxPos++, 1,
            (unk_20_s32 * 32 + 32) * 4, 32 * 4,
            (unk_20_s32 * 32 + 64) * 4, 64 * 4);
    } else {
        gDPSetTileSize(gMasterGfxPos++, 1,
            (unk_20_s32 * 32 + 32) * 4, 0,
            (unk_20_s32 * 32 + 64) * 4, 32 * 4);
    }

    gSPDisplayList(gMasterGfxPos++, dlist);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
