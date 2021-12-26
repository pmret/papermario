#include "common.h"
#include "effects_internal.h"

extern Gfx D_090000E0[];
extern Gfx D_090001B8[];

void fx_10_init(EffectInstance* effect);
void fx_10_update(EffectInstance* effect);
void fx_10_render(EffectInstance* effect);
void fx_10_appendGfx(EffectInstance* effect);

void fx_10_main(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    f32 temp_f20;
    Effect10* part;
    s32 numParts = 8;
    s32 i;

    bp.unk_00 = 0;
    bp.init = fx_10_init;
    bp.update = fx_10_update;
    bp.renderWorld = fx_10_render;
    bp.unk_14 = NULL;
    bp.effectIndex = 10;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data = part;
    ASSERT(effect->data != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->alive = TRUE;
        part->unk_40 = 0;
        part->unk_0C = arg0;
        part->unk_10 = arg1;
        part->unk_14 = arg2;
        part->unk_18 = 1.0f;
        part->unk_1C = 1.0f;
        part->unk_20 = 1.0f;
        part->alpha = 255;
        part->unk_24 = (shim_rand_int(10) * 0.03) + 1.0;
        part->unk_28 = (shim_rand_int(10) * 0.03) + 1.7;
        part->unk_2C = func_E0200000(60);
        part->lifetime = 30;
        part->unk_34 = 0.5f;
        part->unk_38 = -0.02f;
        part->unk_3C = 0.00005f;
        part->unk_30 = -3.9f;
        temp_f20 = shim_clamp_angle(arg3 + i * 45);
        part->unk_44 = shim_sin_deg(temp_f20);
        part->unk_48 = shim_cos_deg(temp_f20);
    }
}

void fx_10_init(EffectInstance* effect) {
}

void fx_10_update(EffectInstance* effect) {
    Effect10* part = (Effect10*)effect->data;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->alive) {
            part->lifetime--;
            if (part->lifetime <= 0) {
                part->alive = FALSE;
            } else {
                cond = TRUE;
                part->unk_2C = shim_clamp_angle(part->unk_2C + 12.0f);
                part->unk_18 = part->unk_24 + shim_sin_deg(part->unk_2C) * 0.1;
                part->unk_1C = part->unk_28 + shim_cos_deg(part->unk_2C) * 0.1;
                part->unk_30 *= 0.83;
                part->unk_0C += part->unk_30 * part->unk_44;
                part->unk_14 += part->unk_30 * part->unk_48;
                part->unk_24 += (7.5 - part->unk_24) * 0.006;
                part->unk_38 += part->unk_3C;
                part->unk_34 += part->unk_38;
                part->unk_10 += part->unk_34;
                part->unk_28 *= 0.98;

                if (part->lifetime < 10) {
                    part->unk_28 *= 0.9;
                }

                if (part->lifetime < 15) {
                    part->alpha -= 16;
                }
            }
        }
    }

    if (!cond) {
        shim_remove_effect(effect);
    }
}

void fx_10_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_10_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void fx_10_appendGfx(EffectInstance* effect) {
    EffectInstance* effectTemp = effect;
    Effect10* part = effect->data;
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
            shim_guScaleF(sp60, part->unk_18, part->unk_1C, part->unk_20);
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
