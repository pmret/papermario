#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000240_32FD90[];

void func_E0018000(FootprintFXData* part);
void footprint_init(EffectInstance* effect);
void footprint_update(EffectInstance* effect);
void footprint_render(EffectInstance* effect);
void footprint_appendGfx(void* effect);

void func_E0018000(FootprintFXData* part) {
    Matrix4f sp18;
    Matrix4f sp58;

    shim_guTranslateF(sp18, part->unk_0C, part->unk_10, part->unk_14);
    shim_guRotateF(sp58, part->unk_28, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &part->mtx);
}

void footprint_main(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FootprintFXData* part;
    s32 numParts = 1;
    s32 i;
    f32 temp_f20;
    f32 temp_f20_2;

    bp.unk_00 = 0;
    bp.init = footprint_init;
    bp.update = footprint_update;
    bp.renderWorld = footprint_render;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_FOOTPRINT;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = 1;
    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data.footprint = part;

    ASSERT(effect->data.footprint != NULL);

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

void footprint_init(EffectInstance* effect) {
}

void footprint_update(EffectInstance* effect) {
    FootprintFXData* part = effect->data.footprint;
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

void footprint_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = footprint_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00183BC(EffectInstance* effect) {
    shim_remove_effect(effect);
}

void footprint_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    FootprintFXData* part = effectTemp->data.footprint;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));

    for (i = 0; i < effectTemp->numParts; i++, part++) {
        if (part->alive) {
            Gfx* dlist = D_09000240_32FD90;

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
