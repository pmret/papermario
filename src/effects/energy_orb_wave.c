#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001000[];
extern Gfx D_090010A8[];
extern Gfx D_090011D0[];
extern Gfx D_090011F0[];
extern Gfx D_09001210[];

void energy_orb_wave_init(EffectInstance* effect);
void energy_orb_wave_update(EffectInstance* effect);
void energy_orb_wave_render(EffectInstance* effect);
void energy_orb_wave_appendGfx(void* effect);

EffectInstance* energy_orb_wave_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    EnergyOrbWaveFXData* data;
    s32 numParts = 1;

    bp.init = energy_orb_wave_init;
    bp.update = energy_orb_wave_update;
    bp.renderWorld = energy_orb_wave_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_ENERGY_ORB_WAVE;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.energyOrbWave = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.energyOrbWave != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 100;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_2C = 0;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->scale = arg4;
    data->unk_18 = 0;

    switch (arg0) {
        case 0:
            data->unk_1C = 0;
            break;
        case 1:
            data->unk_1C = 2;
            break;
        case 2:
            data->unk_1C = 4;
            break;
        case 3:
            data->unk_1C = 6;
            break;
        case 4:
            data->unk_1C = 7;
            break;
        case 5:
            data->unk_1C = 8;
            break;
        case 6:
            data->unk_1C = 9;
            break;
        default:
            data->unk_1C = 10;
            data->unk_34 = -(arg4 - 0.1) / arg5;
            break;
    }

    return effect;
}

void energy_orb_wave_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/energy_orb_wave", energy_orb_wave_update);

void energy_orb_wave_render(EffectInstance* effect) {
    EnergyOrbWaveFXData* effect82 = effect->data.energyOrbWave;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = energy_orb_wave_appendGfx;
    renderTask.distance = 10;
    renderTask.appendGfxArg = effect;
    renderTask.renderMode = RENDER_MODE_2D;
    if (effect82->unk_00 >= 3) {
        shim_queue_render_task(renderTaskPointer);
        return;
    }

    retTask = shim_queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00A4648(void) {
}

void energy_orb_wave_appendGfx(void* effect) {
    EnergyOrbWaveFXData* data = ((EffectInstance*)effect)->data.energyOrbWave;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_14 = data->unk_14;
    s32 unk_2C = data->unk_2C;
    s32 unk_00 = data->unk_00;
    Matrix4f sp18;
    Matrix4f sp58;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    shim_guScaleF(sp58, data->scale, data->scale, data->scale);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_20, data->unk_24, data->unk_28, unk_2C);
    gDPSetColorDither(gMasterGfxPos++, G_CD_BAYER);
    gDPSetAlphaDither(gMasterGfxPos++, G_AD_PATTERN);

    if (unk_00 < 3) {
        gSPDisplayList(gMasterGfxPos++, D_09001000);

        shim_guRotateF(sp18, unk_14, 0.0f, 0.0f, 1.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_090011D0);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        gDPSetColorDither(gMasterGfxPos++, G_CD_MAGICSQ);

        shim_guRotateF(sp18, -unk_14 * 8, 0.0f, 0.0f, 1.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_090011F0);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    } else {
        gSPDisplayList(gMasterGfxPos++, D_090010A8);
        gSPDisplayList(gMasterGfxPos++, D_09001210);
    }

    gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
    gDPSetAlphaDither(gMasterGfxPos++, G_AD_DISABLE);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
