#include "common.h"
#include "model.h"
#include "effects_internal.h"

void bombette_breaking_appendGfx(void* effect);
void bombette_breaking_init(EffectInstance* effect);
void bombette_breaking_update(EffectInstance* effect);
void bombette_breaking_render(EffectInstance* effect);

extern Gfx D_090018C0[];
extern Gfx D_09001D00[];
extern Gfx D_09001CC8[];
extern Gfx D_09001C80[];
extern Gfx D_090017D0[];

Gfx* D_E0084E10[] = { D_090018C0, D_090018C0, D_090018C0 };
Gfx* D_E0084E1C[] = { D_09001D00, D_09001CC8, D_09001C80 };
Gfx* D_E0084E28[] = { D_090017D0, D_090017D0, D_090017D0 };

void (*D_E0084E34)(u16, f32*, f32*, f32*, f32*, f32*, f32*) = get_model_center_and_size;
Model* (*D_E0084E38)(s32) = get_model_from_list_index;
s32 (*D_E0084E3C)(s32) = get_model_list_index_from_tree_index;

void func_E0084000(s32 modelID, f32* centerX, f32* centerY, f32* centerZ, f32* sizeX, f32* sizeY, f32* sizeZ) {
    D_E0084E34(modelID, centerX, centerY, centerZ, sizeX, sizeY, sizeZ);
}

Model* func_E008403C(s32 listIndex) {
    return D_E0084E38(listIndex);
}

s32 func_E0084060(s32 listIndex) {
    return D_E0084E3C(listIndex);
}

INCLUDE_ASM(s32, "effects/bombette_breaking", bombette_breaking_main);
/*EffectInstance* bombette_breaking_main(s32 arg0, s32 modelID, s32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    s32 numParts;
    BombetteBreakingFXData* data;

    f32 centerX, centerY, centerZ;
    f32 sizeX, sizeY, sizeZ;
    s32 xParts, yParts, zParts;
    s32 xI, yI, zI;

    f32 f20, f30;
    f64 f0, f2;

    f64 temp_f0_6;

    func_E0084000(modelID & 0xFFFF, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);

    xParts = (sizeX * 0.0625f) + 1.0f;
    yParts = (sizeY * 0.0625f) + 1.0f;
    zParts = (sizeZ * 0.0625f) + 1.0f;

    f30 = (s32)sizeY % 16;
    f20 = (s32)sizeX % 16;

    bp.unk_00 = 0;
    bp.init = bombette_breaking_init;
    bp.update = bombette_breaking_update;
    bp.renderWorld = bombette_breaking_render;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_BOMBETTE_BREAKING;

    f20 *= 0.5;
    f30 *= 0.5;

    numParts = (xParts * yParts * zParts) + 1;
    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    effect->data = data = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_04 = -sizeY * 0.5;
    data->unk_44 = arg5;
    data->unk_48 = 0;
    data->unk_00 = arg0;
    data->unk_38 = arg3;
    data->unk_4C = 0xFF;
    data->unk_02 = arg2;
    data->unk_3C = 2.0f * arg3;
    data->center.x = centerX;
    data->center.y = centerY;
    data->center.z = centerZ;
    data->unk_40 = sizeY * 0.05;
    if (data->unk_40 < 1.0f) {
        data->unk_40 = 1.0f;
    }

    data++;
    for (xI = 0; xI < xParts; xI++) {
        centerX = (f20 - (sizeX * 0.5)) + (xI * 16.0f);
        for (yI = 0; yI < yParts; yI++) {
            centerY = (f30 - (sizeY * 0.5)) + (yI * 16.0f);
            for (zI = 0; zI < zParts; data++, zI++) {
                centerZ = (f30 - (sizeZ * 0.5)) + (zI * 16.0f);

                data->center.x = data->unk_14.x = centerX;
                data->center.y = data->unk_14.y = centerY;
                data->center.z = data->unk_14.z = centerZ;

                if (sizeX < sizeZ) {
                    if (xParts >= 2) {
                        data->unk_20.x = 2.0 * (centerX / (sizeX * 0.5));
                    } else {
                        if (zI & 1) {
                            data->unk_20.x = 2.0f;
                        } else {
                            data->unk_20.x = -2.0f;
                        }
                    }
                    data->unk_20.z = 0.0f;
                } else {
                    data->unk_20.x = 0.0f;
                    if (zParts >= 2) {
                        data->unk_20.z = 2.0 * (centerZ / (sizeZ * 0.5));
                    } else {
                        if (xI & 1) {
                            data->unk_20.z = 2.0f;
                        } else {
                            data->unk_20.z = -2.0f;
                        }
                    }
                }

                data->unk_20.y = centerY * 0.2;
                f0 = centerZ * 0.2;

                if (centerZ > centerX) {
                    if (centerZ < 0.0f) {
                        f2 = f0 + -1.0;
                    } else if (centerZ > 0.0f) {
                        f2 = f0 + 1.0;
                    } else {
                        f2 = f0 + 0.0;
                    }
                } else {
                    f2 = f0 + 0.0;
                }
                data->unk_2C.x = f2;
                data->unk_2C.y = centerY * 0.2;

                temp_f0_6 = centerX * 0.2;
                if (centerZ < centerX) {
                    if (centerX < 0.0f) {
                        data->unk_2C.z = temp_f0_6 + -1.0;
                    } else if (centerX > 0.0f) {
                        data->unk_2C.z = temp_f0_6 + 1.0;
                    } else {
                        data->unk_2C.z = temp_f0_6 + 0.0;
                    }
                } else {
                    data->unk_2C.z = temp_f0_6 + 0.0;
                }
                data->unk_4C = 0xFF;
            }
        }
    }
    return effect;
}*/

void bombette_breaking_init(EffectInstance* effect) {
}

void bombette_breaking_update(EffectInstance* effect) {
    BombetteBreakingFXData* data = effect->data;
    f32 unk_04;
    s32 i;

    data->unk_48++;
    data->lifetime--;

    if (data->lifetime < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_04 = data->unk_04;

    if (data->lifetime < 25.0f) {
        data->alpha = data->lifetime * 10.0f;
    }
    data->unk_38 += (data->unk_3C - data->unk_38) * 0.1;

    data++;
    for (i = 1; i < effect->numParts; i++, data++) {
        data->unk_20.x *= 0.9;
        data->unk_20.y *= 0.9;
        data->unk_20.z *= 0.9;
        data->center.x += data->unk_20.x;
        data->center.y += data->unk_20.y;
        data->center.z += data->unk_20.z;
        if (data->center.y < unk_04 && data->unk_20.y < 0.0f) {
            data->center.y = unk_04;
            data->unk_20.y *= -0.7;
        }

        data->unk_2C.x *= 0.95;
        data->unk_2C.y -= 0.4;
        data->unk_2C.z *= 0.95;
        data->unk_14.x += data->unk_2C.x;
        data->unk_14.y += data->unk_2C.y;
        data->unk_14.z += data->unk_2C.z;
        if (data->unk_14.y < unk_04 && data->unk_2C.y < 0.0f) {
            data->unk_14.y = unk_04;
            data->unk_2C.y *= -0.4;
        }
    }
}

void bombette_breaking_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = bombette_breaking_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void bombette_breaking_appendGfx(void* effect) {
    Matrix4f sp20;
    BombetteBreakingFXData* data = ((EffectInstance*)effect)->data;
    s32 lifetime = data->lifetime;
    u16 unk_00 = data->unk_00;
    Gfx* sp60 = D_E0084E10[unk_00];
    Gfx* sp64 = D_E0084E28[unk_00];
    f32 unk_38 = data->unk_38;
    f32 unk_40 = data->unk_40;
    s32 alpha = data->alpha;
    s32 i;

    lifetime *= 4;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    shim_guTranslateF(sp20, data->center.x, data->center.y, data->center.z);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    shim_mdl_draw_hidden_panel_surface(&gMasterGfxPos, data->unk_02);

    data++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        shim_guPositionF(sp20, lifetime + (130 * i), lifetime - (40 * i), lifetime + (80 * i), unk_40,
                         data->unk_14.x, data->unk_14.y, data->unk_14.z);
        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_E0084E1C[unk_00]);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPDisplayList(gMasterGfxPos++, sp64);

    data = ((EffectInstance*)effect)->data;
    data++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 255, (data->alpha * alpha) / 255);
        shim_guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, unk_38,
                         data->center.x, data->center.y, data->center.z);
        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, sp60);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
