#include "common.h"
#include "effects_internal.h"

extern Gfx* D_09000240[];

void func_E0018000(Effect12* part);
void fx_12_init(EffectInstance* effect);
void fx_12_update(EffectInstance* effect);
void fx_12_render(EffectInstance* effect);
void fx_12_appendGfx(EffectInstance* effect);

void func_E0018000(Effect12* part) {
    Matrix4f sp18;
    Matrix4f sp58;

    shim_guTranslateF(sp18, part->unk_0C, part->unk_10, part->unk_14);
    shim_guRotateF(sp58, part->unk_28, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &part->mtx);
}

void fx_12_main(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect12* part;
    s32 numParts = 1;
    s32 i;
    f32 temp_f20;
    f32 temp_f20_2;

    bp.unk_00 = 0;
    bp.init = fx_12_init;
    bp.update = fx_12_update;
    bp.renderWorld = fx_12_render;
    bp.unk_14 = 0;
    bp.effectIndex = 12;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = 1;
    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data = part;

    ASSERT(effect->data != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->alive = TRUE;
        part->unk_7C = 0;
        part->unk_0C = arg0;
        part->unk_10 = arg1;
        part->unk_14 = arg2;
        part->alpha = 255;
        part->unk_18 = 1.0f;
        part->unk_1C = 1.0f;
        part->unk_20 = 1.0f;
        part->unk_70 = 0;
        part->unk_80 = 0;
        part->unk_84 = 0;
        part->lifetime = 100;
        part->unk_24 = 0.0f;
        part->unk_28 = (arg3 + (arg4 * 30.0f)) - 15.0f;
        part->unk_2C = 0.0f;
        temp_f20 = shim_clamp_angle(arg3);
        part->unk_90 = shim_sin_deg(temp_f20);
        part->unk_94 = shim_cos_deg(temp_f20);
        temp_f20_2 = (temp_f20 + 45.0f) - (arg4 * 180.0f);
        part->unk_0C += shim_sin_deg(temp_f20_2) * 5.0f;
        part->unk_14 += shim_cos_deg(temp_f20_2) * 5.0f;
        part->alpha = 200;
    }
}

void fx_12_init(EffectInstance* effect) {
}

void fx_12_update(EffectInstance* effect) {
    Effect12* part = (Effect12*)effect->data;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->alive) {
            part->lifetime--;
            if (part->lifetime <= 0) {
                part->alive = FALSE;
            } else {
                cond = TRUE;
                func_E0018000(part);
                part->alpha -= 2;
            }
        }
    }

    if (!cond) {
        shim_remove_effect(effect);
    }
}

void fx_12_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_12_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00183BC(EffectInstance* effect) {
    shim_remove_effect(effect);
}

void fx_12_appendGfx(EffectInstance* effect) {
    EffectInstance* effectTemp = effect;
    Effect12* part = effect->data;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->effect->data));

    for (i = 0; i < effectTemp->numParts; i++, part++) {
        if (part->alive) {
            Gfx** dlist = D_09000240;

            gDisplayContext->matrixStack[gMatrixListPos] = part->mtx;

            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 112, 96, 24, part->alpha);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                        G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, dlist);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMasterGfxPos++);
}
