#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000800_415860[];
extern Gfx D_09000BA8_415C08[];
extern Gfx D_09000BC8_415C28[];
extern Gfx D_09000BE8_415C48[];
extern Gfx D_09000C08_415C68[];
extern Gfx D_09000C28_415C88[];
extern Gfx D_09000C48_415CA8[];
extern Gfx D_09000C68_415CC8[];
extern Gfx D_09000C88_415CE8[];
extern Gfx D_09000CA8_415D08[];
extern Gfx D_09000CC8_415D28[];
extern Gfx D_09000CE8_415D48[];
extern Gfx D_09000D08_415D68[];

Gfx* D_E0128480[12] = {
    D_09000BA8_415C08, D_09000BC8_415C28, D_09000BE8_415C48, D_09000C08_415C68,
    D_09000C28_415C88, D_09000C48_415CA8, D_09000C68_415CC8, D_09000C88_415CE8,
    D_09000CA8_415D08, D_09000CC8_415D28, D_09000CE8_415D48, D_09000D08_415D68
};

Gfx* D_E01284B0[] = { D_09000800_415860 };

void effect_86_init(EffectInstance* effect);
void effect_86_update(EffectInstance* effect);
void effect_86_render(EffectInstance* effect);
void effect_86_appendGfx(void* effect);

EffectInstance* effect_86_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect86FXData* data;
    Effect86FXData* part;
    s32 numParts = 1;

    bp.init = effect_86_init;
    bp.update = effect_86_update;
    bp.renderWorld = effect_86_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_86;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;

    data = general_heap_malloc(numParts * sizeof(*data));
    effect->data.unk_86 = data;
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

void effect_86_init(EffectInstance* effect) {
}

void effect_86_update(EffectInstance* effect) {
    Effect86FXData* data = effect->data.unk_86;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 0x10;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;
    if (data->unk_10 < 0) {
        remove_effect(effect);
    }
}

void effect_86_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = effect_86_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void effect_86_appendGfx(void* effect) {
    Matrix4f sp10;
    Matrix4f sp50;
    Effect86FXData* part = ((EffectInstance*)effect)->data.unk_86;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 primAlpha = part->unk_24;
    s32 dlistIdx = part->unk_00;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp10, part->unk_04, part->unk_08, part->unk_0C);
    guScaleF(sp50, part->unk_34, part->unk_34, part->unk_34);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, part->unk_18, part->unk_1C, part->unk_20, primAlpha);
    gDPSetEnvColor(gMainGfxPos++, part->unk_28, part->unk_2C, part->unk_30, 0);
    gSPDisplayList(gMainGfxPos++, D_E01284B0[0]);
    gSPDisplayList(gMainGfxPos++, D_E0128480[dlistIdx % ARRAY_COUNT(D_E0128480)]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
