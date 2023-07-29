#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000CC0_33FCC0[];
extern Gfx D_09000D68_33FD68[];
extern Gfx D_09000E18_33FE18[];
extern Gfx D_09000E38_33FE38[];
extern Gfx D_09000E58_33FE58[];

void dust_init(EffectInstance* effect);
void dust_render(EffectInstance* effect);
void dust_update(EffectInstance* effect);
void dust_appendGfx(void* effect);

EffectInstance* dust_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    DustFXData* part;
    s32 numParts;
    s32 i;

    if (arg0 < 2) {
        numParts = 5;
    } else {
        numParts = 4;
    }

    bp.init = dust_init;
    bp.update = dust_update;
    bp.renderWorld = dust_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_DUST;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.dust = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.dust != NULL);

    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_2C = arg4;
    part->unk_18 = 255;
    part->unk_30 = 160;
    part->unk_34 = 160;
    part->unk_38 = 140;
    part->unk_3C = 160;
    part->unk_40 = 160;
    part->unk_44 = 140;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_04 = rand_int(200) - 100;
        part->unk_08 = rand_int(50);
        part->unk_0C = 0;
        part->unk_14 = 0;
        part->unk_1C = 1.0f;
        part->unk_20 = 1.0f;
        part->unk_10 = -1.0f;
        part->unk_24 = rand_int(10) / 200;
        switch (arg0) {
            case 0:
                part->unk_28 = part->unk_24 * 0.1;
                break;
            case 1:
                part->unk_28 = part->unk_24 * 0.2;
                break;
            default:
                part->unk_24 = 0.4f;
                part->unk_28 = 0.4f;
                part->unk_10 = 0;
                part->unk_04 = (rand_int(40) - 20) * 0.1;
                part->unk_08 = (rand_int(40) - 20) * 0.1;
                break;
        }
    }

    return effect;
}

void dust_init(EffectInstance* effect) {
}

void dust_update(EffectInstance* effect) {
    s32 i;
    s32 unk00;
    DustFXData* part = effect->data.dust;

    part->unk_2C--;
    if (part->unk_2C < 0) {
        remove_effect(effect);
        return;
    }

    unk00 = part->unk_00;
    if (part->unk_2C < 24) {
        part->unk_18 *= 0.9;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_10 += part->unk_14;
        part->unk_08 += part->unk_10;
        if (unk00 < 2) {
            part->unk_24 += 0.005;
        }
        part->unk_1C += part->unk_24;
        part->unk_20 += part->unk_28;
    }
}

void dust_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = dust_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void dust_appendGfx(void* effect) {
    DustFXData* part = ((EffectInstance*)effect)->data.dust;
    s32 unk_00;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Mtx* matrix;
    s32 i;

    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, part->unk_00 == 0 ? D_09000CC0_33FCC0 : D_09000D68_33FD68);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, part->unk_30, part->unk_34, part->unk_38, part->unk_18);
    gDPSetEnvColor(gMainGfxPos++, part->unk_3C, part->unk_40, part->unk_44, 0);

    guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);

    unk_00 = part->unk_00;
    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        matrix = &gDisplayContext->matrixStack[gMatrixListPos++];

        guScaleF(sp18, part->unk_20, part->unk_1C, part->unk_20);
        guMtxF2L(sp18, matrix);
        guTranslateF(sp58, part->unk_04, part->unk_08, part->unk_0C);
        guMtxCatF(sp58, sp98, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPMatrix(gMainGfxPos++, matrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        if (unk_00 < 2) {
            gSPDisplayList(gMainGfxPos++, (i % 2) ? D_09000E18_33FE18 : D_09000E38_33FE38);
        } else {
            gSPDisplayList(gMainGfxPos++, D_09000E58_33FE58);
        }

        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}
