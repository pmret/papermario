#include "common.h"
#include "effects_internal.h"
extern Gfx D_09000E20[];
extern Gfx D_09000E38[];

void fx_9_init(EffectInstance* effect);
void fx_9_update(EffectInstance* effect);
void fx_9_render(EffectInstance* effect);
void fx_9_appendGfx(EffectInstance* effect);

void func_E0012000(Effect8* effect) {
    Matrix4f sp18;
    Matrix4f sp58;

    shim_guRotateF(sp18, effect->unk_24, 1.0f, 0.0f, 0.0f);
    shim_guRotateF(sp58, effect->unk_2C, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guRotateF(sp58, effect->unk_28, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp18, sp58, sp18);
    shim_guScaleF(sp58, effect->unk_18, effect->unk_1C, effect->unk_20);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guTranslateF(sp58, effect->unk_0C, effect->unk_10, effect->unk_14);
    shim_guMtxCatF(sp18, sp58, sp18);
    shim_guMtxF2L(sp18, &effect->unk_30);
}

void func_E0012104(Effect8* effect) {
    if (effect->unk_04 == 0 && effect->unk_78 != 0.0f && gPlayerActionState == ACTION_STATE_IDLE) {
        effect->unk_06++;
        return;
    }

    effect->primAlpha -= 12;
    effect->unk_88 += effect->unk_8C;
    effect->unk_84 += effect->unk_88;
    effect->unk_80 += effect->unk_84;
    effect->unk_2C += effect->unk_80 * effect->unk_70;
    effect->unk_0C -= effect->unk_80 * effect->unk_74 * effect->unk_90;
    effect->unk_14 -= effect->unk_80 * effect->unk_74 * effect->unk_94;

    if (effect->unk_80 < 0.0f) {
        effect->unk_78 = 0.0f;
    }
}

void fx_9_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect8* part;
    s32 numParts = 1;
    f32 angle;
    f32 temp;
    s32 i;

    bp.init = fx_9_init;
    bp.update = fx_9_update;
    bp.renderWorld = fx_9_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectIndex = 9;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data = part;
    ASSERT(effect->data != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->unk_00 = 1;
        part->unk_04 = arg0;
        part->unk_7C = 0.0f;
        part->unk_0C = arg1;
        part->unk_10 = arg2;
        part->unk_14 = arg3;
        part->unk_18 = 1.0f;
        part->unk_1C = 1.0f;
        part->unk_20 = 1.0f;
        part->primAlpha = 255;
        part->unk_78 = 1.0f;
        part->unk_74 = 5.4f;

        if (arg5 != 0.0f) {
            part->unk_70 = -10.0f;
        } else {
            part->unk_70 = 10.0f;
        }

        part->unk_8C = 0;
        part->unk_06 = 15;
        part->unk_28 = arg4;
        part->unk_24 = 0;
        part->unk_2C = 0;
        part->unk_80 = 0.5f;
        part->unk_84 = -0.07f;
        part->unk_88 = 0.003f;
        part->unk_09 = (shim_rand_int(100) >> 4) & 1;

        if (arg5 != 0.0f) {
            temp = -90.0f;
            angle = shim_clamp_angle(arg4 + temp);
        } else {
            temp = 90.0f;
            angle = shim_clamp_angle(arg4 + temp);
        }

        part->unk_90 = shim_sin_deg(angle);
        part->unk_94 = shim_cos_deg(angle);
    }
}

void fx_9_init(EffectInstance* effect) {
}

void fx_9_update(EffectInstance* effect) {
    Effect8* part = (Effect8*)effect->data;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->unk_00 != 0) {
            part->unk_06--;
            if (part->unk_06 <= 0) {
                part->unk_00 = 0;
            } else {
                cond = TRUE;
                func_E0012104(part);
                func_E0012000(part);
            }
        }
    }

    if (!cond) {
        shim_remove_effect(effect);
    }
}

void fx_9_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_9_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E0012548(EffectInstance* effect) {
    shim_remove_effect(effect);
}

void fx_9_appendGfx(EffectInstance* effect) {
    EffectInstance* effectTemp = effect;
    Effect8* part = (Effect8*)effectTemp->data;
    Gfx* dlist;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->effect->data));

    for (i = 0; i < effectTemp->numParts; i++, part++) {
        if (part->unk_00 != 0) {
            if (part->unk_09 != 0) {
                dlist = D_09000E20;
            } else {
                dlist = D_09000E38;
            }

            gDisplayContext->matrixStack[gMatrixListPos] = part->unk_30;

            gDPPipeSync(gMasterGfxPos++);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 112, 96, 24, part->primAlpha);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                        G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, dlist);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMasterGfxPos++);
}
