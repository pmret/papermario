#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000800[];
extern Gfx D_09000BA8[];
extern Gfx D_09000BC8[];
extern Gfx D_09000BE8[];
extern Gfx D_09000C08[];
extern Gfx D_09000C28[];
extern Gfx D_09000C48[];
extern Gfx D_09000C68[];
extern Gfx D_09000C88[];
extern Gfx D_09000CA8[];
extern Gfx D_09000CC8[];
extern Gfx D_09000CE8[];
extern Gfx D_09000D08[];

Gfx* D_E0128480[12] = {
    D_09000BA8, D_09000BC8, D_09000BE8, D_09000C08, D_09000C28, D_09000C48, D_09000C68, D_09000C88, D_09000CA8,
    D_09000CC8, D_09000CE8, D_09000D08
};

Gfx* D_E01284B0[] = { D_09000800 };

void fx_134_init(EffectInstance* effect);
void fx_134_update(EffectInstance* effect);
void fx_134_render(EffectInstance* effect);
void fx_134_appendGfx(void* effect);

EffectInstance* fx_134_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect134* data;
    Effect134* part;
    s32 numParts = 1;

    bp.init = fx_134_init;
    bp.update = fx_134_update;
    bp.renderWorld = fx_134_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_ID_86;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    data = shim_general_heap_malloc(numParts * sizeof(*data));
    effect->data = data;
    part = data;

    ASSERT(data != NULL);

    part->unk_00 = arg0;
    part->unk_14 = 0;
    if (arg5 <= 0) {
        part->unk_10 = 1000;
    } else {
        part->unk_10 = arg5;
    }
    part->unk_24 = 255;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_34 = arg4;
    part->unk_18 = 70;
    part->unk_1C = 180;
    part->unk_20 = 120;
    part->unk_28 = 20;
    part->unk_2C = 230;
    part->unk_30 = 50;

    return effect;
}

void fx_134_init(EffectInstance* effect) {
}

void fx_134_update(EffectInstance* effect) {
    Effect134* data = effect->data;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_10 = 0x10;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;
    if (data->unk_10 < 0) {
        shim_remove_effect(effect);
    }
}

void fx_134_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_134_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void fx_134_appendGfx(void* effect) {
    Matrix4f sp10;
    Matrix4f sp50;
    Effect134* part = ((EffectInstance*)effect)->data;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 primAlpha = part->unk_24;
    s32 dlistIdx = part->unk_00;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp10, part->unk_04, part->unk_08, part->unk_0C);
    shim_guScaleF(sp50, part->unk_34, part->unk_34, part->unk_34);
    shim_guMtxCatF(sp50, sp10, sp10);
    shim_guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, part->unk_18, part->unk_1C, part->unk_20, primAlpha);
    gDPSetEnvColor(gMasterGfxPos++, part->unk_28, part->unk_2C, part->unk_30, 0);
    gSPDisplayList(gMasterGfxPos++, D_E01284B0[0]);
    gSPDisplayList(gMasterGfxPos++, D_E0128480[dlistIdx % ARRAY_COUNT(D_E0128480)]);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
