#include "common.h"
#include "effects_internal.h"

extern Gfx D_090003A0_396490[];
extern Gfx D_090003E0_3964D0[];
extern Gfx D_09000410_396500[];
extern Gfx D_09000450_396540[];

Gfx* D_E0098510[] = {
    D_090003A0_396490, D_090003E0_3964D0, D_09000410_396500,
    D_090003A0_396490, D_090003E0_3964D0, D_09000410_396500
};

void floating_rock_init(EffectInstance* effect);
void floating_rock_update(EffectInstance* effect);
void floating_rock_render(EffectInstance* effect);
void floating_rock_appendGfx(void* effect);

EffectInstance* floating_rock_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FloatingRockFXData* data;
    s32 numParts = 1;

    bp.init = floating_rock_init;
    bp.update = floating_rock_update;
    bp.renderWorld = floating_rock_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FLOATING_ROCK;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.floatingRock = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.floatingRock != NULL);

    data->unk_00 = arg0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_10 = arg4;
    data->unk_18 = arg5;
    data->unk_20 = arg6;
    data->unk_48 = arg8;
    data->unk_4C = 0;
    data->unk_14 = 0;
    data->unk_1C = 0;
    data->unk_24 = 0;
    data->unk_28 = shim_rand_int(360);
    data->unk_2C = shim_rand_int(360);
    data->unk_30.x = 0;
    data->unk_44 = 255;
    data->unk_40 = 0;
    data->unk_30.z = 20.0f;
    data->unk_30.y = -20.0f;
    data->unk_3C = 2.0f * arg7;

    return effect;
}

void floating_rock_init(EffectInstance* effect) {
}

void floating_rock_update(EffectInstance* effect) {
    FloatingRockFXData* data = effect->data.floatingRock;
    s32 unk48;

    data->unk_48--;
    data->unk_4C++;
    if (data->unk_48 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk48 = data->unk_48;
    if (data->unk_08 != data->unk_10) {
        data->unk_18 += data->unk_20;
        data->unk_08 += data->unk_18;
        data->unk_24 += data->unk_30.x;
        data->unk_2C += data->unk_30.z;
        data->unk_28 += data->unk_30.y;
        if (data->unk_08 <= data->unk_10) {
            data->unk_08 = data->unk_10;
            shim_load_effect(EFFECT_DUST);
            dust_main(2, data->unk_04, data->unk_08, data->unk_0C, 20);
            data->unk_48 = 30;
        }
    }

    if (unk48 < 10) {
        data->unk_44 *= 0.8;
    }
}

void floating_rock_render(EffectInstance *effect) {
    FloatingRockFXData* effect76 = effect->data.floatingRock;
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = floating_rock_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = effect76->unk_0C;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void floating_rock_appendGfx(void* effect) {
    FloatingRockFXData* data = ((EffectInstance*)effect)->data.floatingRock;
    s32 unk_44 = data->unk_44;
    Matrix4f sp20;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guPositionF(sp20, data->unk_24, data->unk_2C, data->unk_28, data->unk_3C, data->unk_04, data->unk_08, data->unk_0C);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 215, 215, 110, unk_44);

    if (unk_44 != 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    }

    gSPDisplayList(gMainGfxPos++, D_09000450_396540);
    gSPDisplayList(gMainGfxPos++, D_E0098510[data->unk_00]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
