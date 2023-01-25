#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000280_3E1550[];
extern Gfx D_090003A0_3E1670[];

Gfx* D_E00E6880[] = { D_090003A0_3E1670, D_090003A0_3E1670 };
Gfx* D_E00E6888[] = { D_09000280_3E1550, D_09000280_3E1550 };

s32 D_E00E6890[] = { 24, 12 };

f32 D_E00E6898[] = {
     0.9f, 1.0f,  1.0f, 0.9f, 0.85f, 0.8f, 0.75f, 0.7f, 0.65f,  0.6f, 0.55f,  0.5f,
    0.45f, 0.4f, 0.35f, 0.3f, 0.25f, 0.2f, 0.15f, 0.1f, 0.05f, 0.03f, 0.02f, 0.01f
};

u8 D_E00E68F8[] = {
    0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

f32 D_E00E6910[] = {
    0.9f, 1.0f, 1.0f, 0.9f, 0.8f, 0.7f, 0.6f, 0.5f, 0.4f, 0.3f, 0.2f, 0.1f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
};

u8 D_E00E6970[] = {
    0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void static_status_init(EffectInstance* effect);
void static_status_update(EffectInstance* effect);
void static_status_render(EffectInstance* effect);
void static_status_appendGfx(void* effect);

EffectInstance* static_status_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5,
    s32 arg6)
{
    EffectBlueprint bp;
    EffectInstance* effect;
    StaticStatusFXData* part;
    f32 temp_f0;
    s32 i;

    arg5++;

    bp.init = static_status_init;
    bp.update = static_status_update;
    bp.renderWorld = static_status_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_STATIC_STATUS;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = arg5;
    part = effect->data.staticStatus = shim_general_heap_malloc(arg5 * sizeof(*part));
    ASSERT(effect->data.staticStatus != NULL);

    part->unk_00 = arg0;
    part->unk_2C = 0;
    if (arg6 <= 0) {
        part->unk_28 = 1000;
    } else {
        part->unk_28 = arg6;
    }
    part->unk_30 = 255;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_34 = arg4;

    temp_f0 = D_E00E6890[arg0] * 0.5f;

    part++;
    for (i = 1; i < arg5; i++, part++) {
        part->unk_20 = -1.0f - temp_f0 * (i & 1);
    }

    return effect;
}

void static_status_init(EffectInstance* effect) {
}

void static_status_update(EffectInstance* effect) {
    StaticStatusFXData* part = effect->data.staticStatus;
    s32 unk_00 = part->unk_00;
    s32 unk_28;
    s32 unk_2C;
    f32 var_fs1;
    f32 var_fs2;
    f32 angle;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        part->unk_28 = 16;
    }

    if (part->unk_28 < 1000) {
        part->unk_28--;
    }

    part->unk_2C++;

    if (part->unk_28 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_28 = part->unk_28;
    unk_2C = part->unk_2C;

    if (unk_28 < 16) {
        part->unk_30 = unk_28 * 16;
    }

    if (unk_00 == 0) {
        var_fs2 = 0.1f;
        var_fs1 = 0.2f;
    } else {
        var_fs2 = 0.2f;
        var_fs1 = 0.2f;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_20++;
        if (part->unk_20 >= D_E00E6890[unk_00]) {
            part->unk_20 = 0;
        }

        if (part->unk_20 >= 0) {
            if (part->unk_20 == 0) {
                angle = (i * 360.0f) / (effect->numParts - 1);
                part->unk_04 = shim_sin_deg(angle) * 16.0f;
                part->unk_08 = shim_cos_deg(angle) * 16.0f;
                part->unk_10 = part->unk_04 * var_fs2;
                part->unk_14 = part->unk_08 * var_fs2;
                part->unk_18 = 0.0f;
                part->unk_1C = 0.0f;
                part->unk_34 = 1.0f;
                part->unk_24 = -angle - 45.0f;
            }

            if (unk_00 == 0) {
                part->unk_30 = D_E00E68F8[part->unk_20];
                part->unk_34 = D_E00E6898[part->unk_20];
            } else {
                part->unk_30 = D_E00E6970[part->unk_20];
                part->unk_34 = D_E00E6910[part->unk_20];
            }

            if ((unk_2C & 1) == (i & 1)) {
                part->unk_04 += part->unk_10;
                part->unk_08 += part->unk_14;
            } else {
                part->unk_04 += part->unk_10 * 0.2;
                part->unk_08 += part->unk_14 * 0.2;
            }

            part->unk_10 += (part->unk_18 - part->unk_10) * var_fs1;
            part->unk_14 += (part->unk_1C - part->unk_14) * var_fs1;
        }
    }
}

void static_status_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = static_status_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00E651C(void) {
}

void static_status_appendGfx(void* effect) {
    StaticStatusFXData* part = ((EffectInstance*)effect)->data.staticStatus;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_30 = part->unk_30;
    s32 unk_00 = part->unk_00;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp20, part->unk_04, part->unk_08, part->unk_0C);
    shim_guScaleF(sp60, part->unk_34, part->unk_34, part->unk_34);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_E00E6888[unk_00]);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_20 >= 0) {
            shim_guPositionF(sp20, 0.0f, 0.0f, part->unk_24, part->unk_34, part->unk_04, part->unk_08, 0.0f);
            shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, (unk_30 * part->unk_30) >> 8);
            gSPDisplayList(gMasterGfxPos++, D_E00E6880[unk_00]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
