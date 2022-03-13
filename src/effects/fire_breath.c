#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000A00[];
extern Gfx D_09000B88[];
extern Gfx D_09000C00[];
extern Gfx D_09000C20[];

Gfx* D_E006EC00[] = { D_09000B88, D_09000B88, D_09000B88 };
Gfx* D_E006EC0C[] = { D_09000A00, D_09000A00, D_09000A00 };

void fire_breath_init(EffectInstance* effect);
void fire_breath_update(EffectInstance* effect);
void fire_breath_render(EffectInstance* effect);
void fire_breath_appendGfx(void* effect);

EffectInstance* fire_breath_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7,
                                 s32 arg8, s32 arg9)
{
    EffectBlueprint bp;
    FireBreathFXData* data;
    EffectInstance* effect;
    s32 numParts = 1;
    s32* temp_a0;
    f32 phi_f0;

    bp.unk_00 = 0;
    bp.init = fire_breath_init;
    bp.update = fire_breath_update;
    bp.renderWorld = fire_breath_render;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_FIRE_BREATH;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data != NULL);

    data->unk_00 = arg0;
    data->unk_04 = arg7;
    data->unk_08 = arg8;
    data->unk_0C = arg1;
    data->unk_10 = arg2;
    data->unk_14 = arg3;
    data->unk_18 = arg1;
    data->unk_1C = arg2;
    data->unk_20 = arg3;
    data->unk_24 = arg4;
    data->unk_28 = arg5;
    data->unk_2C = arg6;

    if (arg0 == 0) {
        data->unk_38 = 0.05f;
    } else {
        data->unk_38 = 0.04f;
    }
    data->unk_30 = data->unk_38;
    data->unk_44 = arg9;
    data->unk_48 = arg9;
    data->unk_4C = 0;
    data->unk_40 = 255;
    data->unk_5C = 0.0f;
    data->unk_3C = 0.1f;
    data->unk_34 = data->unk_30;

    if (arg0 == 0) {
        data->unk_50 = (arg4 - arg1) * 0.2 * (func_E0200044(10, arg8 + 0) - 5) * 0.2;
        data->unk_54 = (arg5 - arg2) * 0.2 * (func_E0200044(10, arg8 + 1) - 5) * 0.2;
        data->unk_58 = (arg6 - arg3) * 0.2 * (func_E0200044(10, arg8 + 2) - 5) * 0.2;
    } else {
        data->unk_50 = (arg4 - arg1) * 0.2 * (func_E0200044(10, arg8 + 3) - 5);
        data->unk_54 = (arg5 - arg2) * 0.2 * (func_E0200044(10, arg8 + 4) - 5);
        data->unk_58 = (arg6 - arg3) * 0.2 * (func_E0200044(10, arg8 + 5) - 5);
    }

    data->unk_64 = 255;
    data->unk_68 = 170;
    data->unk_6C = 42;
    data->unk_70 = 243;
    data->unk_60 = 0.0f;
    data->unk_74 = 48;
    data->unk_78 = 0;

    return effect;
}

void fire_breath_init(EffectInstance* effect) {
}

void fire_breath_update(EffectInstance* effect) {
    FireBreathFXData* data = effect->data;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;

    data->unk_48--;
    data->unk_5C = (data->unk_4C * 4.0f) / 10.0f;
    data->unk_4C++;

    if (data->unk_48 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_48 = data->unk_48;
    unk_44 = data->unk_44;
    unk_4C = data->unk_4C;

    if (unk_48 >= 6 && data->unk_00 == 0) {
        data->unk_38 += (2.5 - data->unk_38) * 0.05;
    }

    data->unk_0C = data->unk_18 + ((((data->unk_24 - data->unk_18) + data->unk_50) * unk_4C) / unk_44);
    data->unk_10 = data->unk_1C + ((((data->unk_28 - data->unk_1C) + data->unk_54) * unk_4C) / unk_44);
    data->unk_14 = data->unk_20 + ((((data->unk_2C - data->unk_20) + data->unk_58) * unk_4C) / unk_44);

    if (data->unk_00 == 1) {
        data->unk_60 += (f32) unk_4C * 0.01;
        data->unk_10 += data->unk_60;
    }

    if (unk_4C == data->unk_08 + 1) {
        if (data->unk_04 > 0) {
            EffectInstance* spawned;

            shim_load_effect(EFFECT_FIRE_BREATH);
            spawned = fire_breath_main(
                data->unk_00, data->unk_18, data->unk_1C, data->unk_20, data->unk_24, data->unk_28, data->unk_2C,
                data->unk_04 - 1, data->unk_08, unk_44
            );
            spawned->data->unk_64 = data->unk_64;
            spawned->data->unk_68 = data->unk_68;
            spawned->data->unk_6C = data->unk_6C;
            spawned->data->unk_70 = data->unk_70;
            spawned->data->unk_74 = data->unk_74;
            spawned->data->unk_78 = data->unk_78;
            spawned->data->unk_30 = spawned->data->unk_38 = data->unk_30;
            spawned->data->unk_34 = data->unk_34;
            spawned->data->unk_3C = data->unk_3C;
        }
    }

    if (unk_48 < 10 && data->unk_00 == 0) {
        data->unk_40 = unk_48 * 25;
    }

    if (data->unk_00 == 1) {
        data->unk_38 += (0.3 - data->unk_38) * 0.008;
        data->unk_40 = (unk_48 * 224) / unk_44;
    }

    if (data->unk_00 == 2) {
        data->unk_38 += (data->unk_34 - data->unk_38) * data->unk_3C;
        data->unk_40 = (unk_48 * 224) / unk_44;
    }
}

void fire_breath_render(EffectInstance* effect) {
    FireBreathFXData* data = effect->data;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = fire_breath_appendGfx;
    renderTask.appendGfxArg = effect;

    if (gGameStatusPtr->isBattle == TRUE) {
        renderTask.distance = data->unk_14 + 1000.0f;
    } else {
        renderTask.distance = 0;
    }

    renderTaskPointer->renderMode = RENDER_MODE_2D;
    retTask = shim_queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_MODE_2;
}

void fire_breath_appendGfx(void* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    FireBreathFXData* data = ((EffectInstance*)effect)->data;
    s32 unk_00 = data->unk_00;
    s32 envAlpha = (data->unk_5C - (s32)data->unk_5C) * 256.0f;
    Gfx* dlist = D_E006EC00[unk_00];
    Gfx* dlist2 = D_E006EC0C[unk_00];
    s32 unk_5C = data->unk_5C;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    if (unk_00 == 1) {
        shim_guTranslateF(sp18, data->unk_18, data->unk_1C, data->unk_20);
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_09000C20);
        gSPDisplayList(gMasterGfxPos++, D_09000C00);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPDisplayList(gMasterGfxPos++, dlist2);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_64, data->unk_68, data->unk_6C, data->unk_40);
    gDPSetEnvColor(gMasterGfxPos++, data->unk_70, data->unk_74, data->unk_78, envAlpha);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, ((unk_5C * 32) + 0)  * 4, 0, ((unk_5C * 32) + 32) * 4, 128);
    gDPSetTileSize(gMasterGfxPos++, 1,               ((unk_5C * 32) + 32) * 4, 0, ((unk_5C * 32) + 64) * 4, 128);

    shim_guTranslateF(sp18, data->unk_0C, data->unk_10, data->unk_14);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guScaleF(sp58, data->unk_38, data->unk_38, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, dlist);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
