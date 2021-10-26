#include "common.h"
#include "effects_internal.h"

typedef struct Effect73 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 unk_20;
} Effect73; // size = 0x24

extern Gfx D_090002C0[];
extern Gfx D_09000330[];
extern Gfx D_09000370[];
extern Gfx D_090003B0[];
extern Gfx D_090003F0[];
extern Gfx D_09000430[];
extern Gfx D_09000470[];

static Gfx* sDlists[] = { D_09000430, D_090003F0, D_090003B0, D_09000370, D_09000330 };

static s32 sPartParams[4 * 5] = {
    1, 0, 0, 0, 100,
    2, 4, -2, 0, 100,
    3, -2, 2, 0, 70,
    4, 2, 4, 0, 40,
};

void fx_73_init(EffectInstance* effect);
void fx_73_update(EffectInstance* effect);
void fx_73_render(EffectInstance* effect);
void fx_73_appendGfx(EffectInstance* effect);

EffectInstance* fx_73_main(EffectInstanceDataThing* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect73* data;
    Effect73* part;
    s32 numParts = 5;
    s32 i;

    bp.init = fx_73_init;
    bp.update = fx_73_update;
    bp.renderWorld = fx_73_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectIndex = 73;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    data = shim_general_heap_malloc(numParts * sizeof(*data));
    effect->data = data;
    part = data;

    ASSERT(data != NULL);

    part->unk_00 = arg0;
    part->unk_18 = 0;
    part->unk_14 = 14;
    part->unk_08 = arg1;
    part->unk_0C = arg2;
    part->unk_10 = arg3;

    part++;
    for (i = 1; i < numParts; i++, part++) {
            part->unk_08 = sPartParams[1 + (i - 1) * 5];
            part->unk_0C = sPartParams[2 + (i - 1) * 5];
            part->unk_10 = sPartParams[3 + (i - 1) * 5];
            part->unk_04 = -1;
            part->unk_20 = sPartParams[0 + (i - 1) * 5];
            part->unk_1C = (arg4 * sPartParams[4 + (i - 1) * 5]) * 0.01;
    }
    return effect;
}

void fx_73_init(EffectInstance* effect) {
}

void fx_73_update(EffectInstance* effect) {
    Effect73* part = (Effect73*) effect->data;
    s32 i;

    part->unk_14--;
    part->unk_18++;

    if (part->unk_14 < 0) {
        shim_remove_effect(effect);
        return;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        if (part->unk_20 > 0) {
            part->unk_20--;
        }

        if (part->unk_20 <= 0) {
            part->unk_04++;
            if (part->unk_04 >= 10) {
                part->unk_20 = -1;
            }
        }
    }
}

void fx_73_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_73_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void fx_73_appendGfx(EffectInstance* effect) {
    Effect73* part = effect->data;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Mtx* spD8;
    s32 i;

    shim_guRotateF(sp98, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);
    spD8 = &gDisplayContext->matrixStack[gMatrixListPos++];
    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->effect->data));
    shim_guTranslateF(sp18, part->unk_08, part->unk_0C, part->unk_10);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_090002C0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 15, 255);

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        if (part->unk_20 == 0) {
            f32 temp_f20 = part->unk_1C;

            shim_guTranslateF(sp18, part->unk_08, part->unk_0C, part->unk_10);
            if (temp_f20 != 1.0f) {
                shim_guScaleF(sp58, temp_f20, temp_f20, 1.0f);
                shim_guMtxCatF(sp58, sp18, sp18);
            }
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPMatrix(gMasterGfxPos++, spD8, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, sDlists[part->unk_04 >> 1]);
            gSPDisplayList(gMasterGfxPos++, D_09000470);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}
