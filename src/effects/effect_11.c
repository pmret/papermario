#include "common.h"
#include "effects_internal.h"

extern Gfx D_090000E0[];
extern Gfx D_090001B8[];

void fx_11_init(EffectInstance* effect);
void fx_11_update(EffectInstance* effect);
void fx_11_render(EffectInstance* effect);
void fx_11_appendGfx(EffectInstance* effect);

void fx_11_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect11* part;
    s32 numParts = 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = fx_11_init;
    bp.update = fx_11_update;
    bp.renderWorld = fx_11_render;
    bp.unk_14 = 0;
    bp.effectIndex = 11;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = 1;
    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data = part;

    ASSERT(effect->data != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->alive = 1;
        part->unk_04 = arg0;
        part->unk_40 = 0;
        part->unk_44 = 0;
        part->unk_0C = arg1;
        part->unk_10 = arg2;
        part->unk_14 = arg3;
        part->unk_1C = 1.0f;
        part->unk_20 = 1.0f;
        part->unk_24 = 1.0f;
        part->alpha = -1;
        part->unk_28 = (shim_rand_int(10) * 0.03) + 1.4;
        part->unk_2C = (shim_rand_int(10) * 0.03) + 1.5;
        part->unk_30 = func_E0200000(60);
        part->unk_04 = arg0;
        part->lifetime = 15;
        part->unk_38 = 2.0f;
        part->unk_3C = -0.5f;
        part->unk_18 = func_E0200000(360);
        part->alpha = -1;
    }
}

void fx_11_init(EffectInstance* effect) {
}

void fx_11_update(EffectInstance* effect) {
    Effect11* part = (Effect11*)effect->data;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->alive) {
            part->lifetime--;
            if (part->lifetime <= 0) {
                part->alive = FALSE;
            } else {
                cond = TRUE;
                part->unk_30 = shim_clamp_angle(part->unk_30 + 12.0f);
                part->unk_1C = part->unk_28 + shim_sin_deg(part->unk_30) * 0.1;
                part->unk_20 = part->unk_2C + shim_cos_deg(part->unk_30) * 0.1;

                if (part->unk_04 == 0 && (part->lifetime == 5 && gPlayerActionState == ACTION_STATE_IDLE)) {
                    part->lifetime++;
                    return;
                }

                part->alpha -= 15;
                part->unk_3C += part->unk_40;
                part->unk_38 += part->unk_3C;
                part->unk_10 += part->unk_38;
                part->unk_28 += 0.14;
                part->unk_2C *= 0.94;

                if (part->unk_38 < 0.0f) {
                    part->unk_3C = 0.0f;
                    part->unk_38 = 0.0f;
                }
            }
        }
    }

    if (!cond) {
        shim_remove_effect(effect);
    }
}

void fx_11_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_11_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void fx_11_appendGfx(EffectInstance* effect) {
    EffectInstance* effectTemp = effect;
    Effect11* part = effect->data;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->effect->data));
    gSPDisplayList(gMasterGfxPos++, D_090000E0);

    for (i = 0; i < effectTemp->numParts; i++, part++) {
        if (part->alive) {
            shim_guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f,
                             part->unk_0C, part->unk_10, part->unk_14);
            shim_guScaleF(sp60, part->unk_1C, part->unk_20, part->unk_24);
            shim_guMtxCatF(sp60, sp20, sp20);
            shim_guRotateF(sp60, part->unk_18, 0.0f, 0.0f, 1.0f);
            shim_guMtxCatF(sp60, sp20, sp20);
            shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 112, 96, 24, part->alpha);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                        G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_090001B8);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMasterGfxPos++);
}
