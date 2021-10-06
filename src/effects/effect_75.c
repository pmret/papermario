#include "common.h"
#include "effects_internal.h"

typedef struct Effect75 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} Effect75; // size = 0x24

extern Gfx D_09001280[];
extern Gfx D_09001358[];
extern Gfx D_09001430[];
extern Gfx D_09001508[];

Gfx* D_E00963E0[] = { D_09001280, D_09001358, D_09001430 };

void fx_75_init(EffectInstance* effect);
void fx_75_update(EffectInstance* effect);
void fx_75_render(EffectInstance* effect);
void fx_75_appendGfx(EffectInstance* effect);

EffectInstance* fx_75_main(EffectInstanceDataThing* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect75* data;
    Effect75* part;
    s32 numParts = 1;

    bp.init = fx_75_init;
    bp.update = fx_75_update;
    bp.renderWorld = fx_75_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectIndex = 75;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    data = shim_general_heap_malloc(numParts * sizeof(*data));
    effect->data = data;
    part = data;

    ASSERT(data != NULL);

    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_10 = 0.0f;
    part->unk_1C = arg5;
    part->unk_18 = 0.67f;
    part->unk_20 = 0;
    part->unk_14 = arg4;

    return effect;
}

void fx_75_init(EffectInstance* effect) {
}

void fx_75_update(EffectInstance* effect) {
    Effect75* part = (Effect75*)effect->data;

    part->unk_1C--;
    part->unk_20++;

    if (part->unk_1C < 0) {
        shim_remove_effect(effect);
        return;
    }

    part->unk_10 += part->unk_14;
    if (part->unk_10 > 2.0f) {
        part->unk_10 = 2.0f;
    }
    part->unk_08 += part->unk_10;
}

void fx_75_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_75_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

//INCLUDE_ASM(s32, "effects/effect_75", fx_75_appendGfx);

void fx_75_appendGfx(EffectInstance* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    Effect75* temp_s2;
    s32 temp_s3;
    f32 temp_a1;

    temp_s2 = effect->data;
    temp_s3 = temp_s2->unk_00;
    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->effect->data));

    shim_guTranslateF(sp18, temp_s2->unk_04, temp_s2->unk_08, temp_s2->unk_0C);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guScaleF(sp58, temp_s2->unk_18, temp_s2->unk_18, 1.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_E00963E0[temp_s3]);
    gSPDisplayList(gMasterGfxPos++, D_09001508);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}
