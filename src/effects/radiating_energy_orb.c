#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001200_3A1F60[];
extern Gfx D_090012A8_3A2008[];
extern Gfx D_09001490_3A21F0[];
extern Gfx D_090014B0_3A2210[];
extern Gfx D_090014D0_3A2230[];
extern Gfx D_090014F0_3A2250[];
extern Gfx D_09001510_3A2270[];

Gfx* D_E009EDF0[] = { D_09001490_3A21F0 };
Gfx* D_E009EDF4[] = { D_090014B0_3A2210 };
Gfx* D_E009EDF8[] = { D_090014D0_3A2230 };
Gfx* D_E009EDFC[] = { D_090014F0_3A2250 };

void radiating_energy_orb_init(EffectInstance* effect);
void radiating_energy_orb_update(EffectInstance* effect);
void radiating_energy_orb_render(EffectInstance* effect);
void radiating_energy_orb_appendGfx(void* effect);

EffectInstance* radiating_energy_orb_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    RadiatingEnergyOrbFXData* part;
    s32 numParts = 6;
    s32 i;

    bp.unk_00 = 0;
    bp.init = radiating_energy_orb_init;
    bp.update = radiating_energy_orb_update;
    bp.renderWorld = radiating_energy_orb_render;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_RADIATING_ENERGY_ORB;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.radiatingEnergyOrb = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.radiatingEnergyOrb != NULL);

    part->unk_04 = arg0;
    part->unk_1C = 0;
    if (arg5 <= 0) {
        part->unk_18 = 100;
    } else {
        part->unk_18 = arg5;
    }
    part->unk_14 = 0;
    part->unk_08 = arg1;
    part->unk_0C = arg2;
    part->unk_10 = arg3;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_20 = shim_rand_int(360);
        part->unk_2C = (i * 2) % 20 + 60;
        part->unk_28 = shim_rand_int(15) * 0.1 + 0.4;
        part->unk_30 = shim_rand_int(10) * 0.1 + 0.1;
    }

    return effect;
}

void radiating_energy_orb_init(EffectInstance* effect) {
}

void radiating_energy_orb_update(EffectInstance* effect) {
    RadiatingEnergyOrbFXData* part = effect->data.radiatingEnergyOrb;
    s32 unk_18;
    s32 unk_1C;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        part->unk_18 = 30;
    }

    if (part->unk_18 < 100) {
        part->unk_18--;
    }

    part->unk_1C++;

    if (part->unk_18 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_18 = part->unk_18;
    unk_1C = part->unk_1C;

    if (unk_1C < 21) {
        part->unk_14 = unk_1C * 12;
    } else if (unk_18 < 20) {
        part->unk_14 = unk_18 * 12;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_14 = shim_cos_deg((part->unk_2C - 70.0f) * 90.0f / 10.0f) * 255.0f;
        part->unk_2C += part->unk_30;
        if (part->unk_2C > 80.0f) {
            part->unk_2C = 60.0f;
            part->unk_28 = shim_rand_int(15) * 0.1 + 0.4;
            part->unk_30 = shim_rand_int(10) * 0.1 + 0.1;
            part->unk_20 = shim_rand_int(360);
        }
    }
}

void radiating_energy_orb_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = radiating_energy_orb_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void radiating_energy_orb_appendGfx(void* effect) {
    RadiatingEnergyOrbFXData* part = ((EffectInstance*)effect)->data.radiatingEnergyOrb;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_1C = part->unk_1C;
    s32 unk_14 = part->unk_14;
    s32 temp_s2 = unk_1C & 1;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f unused;
    s32 i;

    if (temp_s2) {
        unk_14 *= 0.95;
    }

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, part->unk_08, part->unk_0C, part->unk_10);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 64, 64, unk_14);

    shim_guRotateF(sp18, temp_s2 * 2 + unk_1C, 0.0f, 0.0f, 1.0f);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_090012A8_3A2008);
    gSPDisplayList(gMasterGfxPos++, D_09001510_3A2270);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_09001200_3A1F60);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        f32 scale = part->unk_28;

        if (scale != 0.0f) {
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 255, (part->unk_14 * unk_14) >> 8);
            gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);

            shim_guRotateF(sp18, part->unk_20, 0.0f, 0.0f, 1.0f);
            shim_guTranslateF(sp58, part->unk_2C, 0.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guScaleF(sp58, scale, scale, scale);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_E009EDFC[0]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

            shim_guRotateF(sp18, part->unk_20, 0.0f, 0.0f, 1.0f);
            shim_guTranslateF(sp58, part->unk_2C + 5.0f, 0.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guScaleF(sp58, 2.3 - scale, 2.3 - scale, 2.3 - scale);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_E009EDF8[0]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 0, 255, (part->unk_14 * unk_14) >> 9);
            gDPSetEnvColor(gMasterGfxPos++, 255, 128, 255, 0);
            gDPSetCombineLERP(gMasterGfxPos++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);

            shim_guRotateF(sp18, part->unk_20 + 14.0f, 0.0f, 0.0f, 1.0f);
            shim_guRotateF(sp58, (i * 10) % 45 + unk_1C, 0.0f, 1.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guTranslateF(sp58, 20.0f, 0.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guScaleF(sp58, (part->unk_2C - 60.0f) * 0.05 + 1.0, 2.0 - (part->unk_2C - 60.0f) * 0.05, 1.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_E009EDF4[0]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 64, 64, (part->unk_14 * unk_14) >> 8);

            shim_guRotateF(sp18, part->unk_20 + 34.0f + unk_1C, 0.0f, 0.0f, 1.0f);
            shim_guRotateF(sp58, i * 35, 0.0f, 1.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guTranslateF(sp58, 15.0f, 0.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guScaleF(sp58, (part->unk_2C - 60.0f) * 0.1 + 2.0, 1.0f, 1.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_E009EDF0[0]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
