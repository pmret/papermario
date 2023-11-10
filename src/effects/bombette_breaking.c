#include "common.h"
#include "model.h"
#include "effects_internal.h"

void bombette_breaking_init(EffectInstance* effect);
void bombette_breaking_update(EffectInstance* effect);
void bombette_breaking_render(EffectInstance* effect);
void bombette_breaking_appendGfx(void* effect);

extern Gfx D_090017D0_37F1A0[];
extern Gfx D_090018C0_37F290[];
extern Gfx D_09001C80_37F650[];
extern Gfx D_09001CC8_37F698[];
extern Gfx D_09001D00_37F6D0[];

Gfx* D_E0084E10[] = { D_090018C0_37F290, D_090018C0_37F290, D_090018C0_37F290 };
Gfx* D_E0084E1C[] = { D_09001D00_37F6D0, D_09001CC8_37F698, D_09001C80_37F650 };
Gfx* D_E0084E28[] = { D_090017D0_37F1A0, D_090017D0_37F1A0, D_090017D0_37F1A0 };

void (*D_E0084E34)(u16, f32*, f32*, f32*, f32*, f32*, f32*) = get_model_center_and_size;
Model* (*D_E0084E38)(s32) = get_model_from_list_index;
s32 (*D_E0084E3C)(s32) = get_model_list_index_from_tree_index;

void bombette_breaking_get_model_center_and_size(s32 modelID,
                                                 f32* centerX, f32* centerY, f32* centerZ,
                                                 f32* sizeX, f32* sizeY, f32* sizeZ)
{
    D_E0084E34(modelID, centerX, centerY, centerZ, sizeX, sizeY, sizeZ);
}

Model* bombette_breaking_get_model_from_list_index(s32 listIndex) {
    return D_E0084E38(listIndex);
}

s32 bombette_breaking_get_model_list_index_from_tree_index(s32 listIndex) {
    return D_E0084E3C(listIndex);
}

EffectInstance* bombette_breaking_main(s32 type, s32 modelID, s32 treeIndex, f32 arg3, s32 arg4, s32 time) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    s32 numParts;
    BombetteBreakingFXData* data;
    f32 centerX, centerY, centerZ;
    f32 sizeX, sizeY, sizeZ;
    s32 xParts, yParts, zParts;
    s32 iX, iY, iZ;
    f32 f20, f30, f40;

    bombette_breaking_get_model_center_and_size(modelID & 0xFFFF, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);

    xParts = (sizeX * 0.0625f) + 1.0f;
    yParts = (sizeY * 0.0625f) + 1.0f;
    zParts = (sizeZ * 0.0625f) + 1.0f;

    f20 = (s32)sizeX % 16;
    f30 = (s32)sizeY % 16;
    f40 = (s32)sizeZ % 16;

    bp.unk_00 = 0;
    bp.init = bombette_breaking_init;
    bp.update = bombette_breaking_update;
    bp.renderWorld = bombette_breaking_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_BOMBETTE_BREAKING;

    f20 *= 0.5;
    f30 *= 0.5;
    f40 *= 0.5;

    numParts = (xParts * yParts * zParts) + 1;
    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    effect->data.bombetteBreaking = data = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_04 = -sizeY * 0.5;
    data->timeLeft = time;
    data->unk_48 = 0;
    data->type = type;
    data->unk_38 = arg3;
    data->alpha = 255;
    data->treeIndex = treeIndex;
    data->unk_3C = 2.0f * arg3;
    data->center.x = centerX;
    data->center.y = centerY;
    data->center.z = centerZ;
    data->unk_40 = sizeY * 0.05;
    if (data->unk_40 < 1.0f) {
        data->unk_40 = 1.0f;
    }

    data++;
    for (iX = 0; iX < xParts; iX++) {
        centerX = f20 - (sizeX * 0.5) + (iX * 16.0f);
        for (iY = 0; iY < yParts; iY++) {
            centerY = f30 - (sizeY * 0.5) + (iY * 16.0f);
            for (iZ = 0; iZ < zParts; iZ++) {
                centerZ = f30 - (sizeZ * 0.5) + (iZ * 16.0f);

                data->center.x = data->unk_14.x = centerX;
                data->center.y = data->unk_14.y = centerY;
                data->center.z = data->unk_14.z = centerZ;

                if (sizeX < sizeZ) {
                    if (xParts >= 2) {
                        data->unk_20.x = 2.0 * (centerX / (sizeX * 0.5));
                    } else {
                        if (iZ & 1) {
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
                        if (iX & 1) {
                            data->unk_20.z = 2.0f;
                        } else {
                            data->unk_20.z = -2.0f;
                        }
                    }
                }

                data->unk_20.y = centerY * 0.2;
                data->unk_2C.x = centerZ * 0.2 + (centerX < centerZ ? (centerZ < 0 ? -1.0 : (centerZ > 0 ? 1.0 : 0.0)) : 0.0);
                data->unk_2C.y = centerY * 0.2;
                data->unk_2C.z = centerX * 0.2 + (centerZ < centerX ? (centerX < 0 ? -1.0 : (centerX > 0 ? 1.0 : 0.0)) : 0.0);

                data->alpha = 255;
                data++;
            }
        }
    }
    return effect;
}

void bombette_breaking_init(EffectInstance* effect) {
}

void bombette_breaking_update(EffectInstance* effect) {
    BombetteBreakingFXData* data = effect->data.bombetteBreaking;
    f32 unk_04;
    s32 i;

    data->unk_48++;
    data->timeLeft--;

    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    unk_04 = data->unk_04;

    if (data->timeLeft < 25.0f) {
        data->alpha = data->timeLeft * 10.0f;
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
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void bombette_breaking_appendGfx(void* effect) {
    Matrix4f sp20;
    BombetteBreakingFXData* data = ((EffectInstance*)effect)->data.bombetteBreaking;
    s32 timeLeft = data->timeLeft;
    u16 type = data->type;
    Gfx* sp60 = D_E0084E10[type];
    Gfx* sp64 = D_E0084E28[type];
    f32 unk_38 = data->unk_38;
    f32 unk_40 = data->unk_40;
    s32 mainAlpha = data->alpha;
    s32 i;

    timeLeft *= 4;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    guTranslateF(sp20, data->center.x, data->center.y, data->center.z);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    mdl_draw_hidden_panel_surface(&gMainGfxPos, data->treeIndex);

    data++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        guPositionF(sp20, timeLeft + (130 * i), timeLeft - (40 * i), timeLeft + (80 * i), unk_40,
                         data->unk_14.x, data->unk_14.y, data->unk_14.z);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_E0084E1C[type]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPDisplayList(gMainGfxPos++, sp64);

    data = ((EffectInstance*)effect)->data.bombetteBreaking;
    data++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, (data->alpha * mainAlpha) / 255);
        guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, unk_38,
                         data->center.x, data->center.y, data->center.z);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, sp60);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
