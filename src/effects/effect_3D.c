#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000240[];
extern Gfx D_090002E8[];

void fx_3D_init(EffectInstance* effect);
void fx_3D_update(EffectInstance* effect);
void fx_3D_render(EffectInstance* effect);
void fx_3D_appendGfx(void* effect);

void fx_3D_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7, EffectInstance** outEffect) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    Effect3DFXData* part;
    f32 temp_f22 = arg4;
    f32 temp_f24 = arg5;
    f32 temp_f26 = arg6;
    s32 numParts = arg7;
    f32 temp_f12;
    f32 temp_f28;
    f32 temp_f30;
    f32 sp70;
    Matrix4f sp30;
    s32 i;

    if (numParts != 0) {
        numParts++;

        temp_f12 = SQ(temp_f22) + SQ(temp_f24) + SQ(temp_f26);
        if (temp_f12 != 0.0f) {
            temp_f12 = -1.0f / shim_sqrtf(temp_f12);

            temp_f22 *= temp_f12;
            temp_f24 *= temp_f12;
            temp_f26 *= temp_f12;

            if (temp_f22 != 0.0f) {
                sp70 = 1.0f;
                temp_f30 = -temp_f24 / temp_f22;
                temp_f28 = 0.0f;
            } else if (temp_f24 != 0.0f) {
                sp70 = -temp_f22 / temp_f24;
                temp_f30 = 1.0f;
                temp_f28 = 0.0f;
            } else {
                sp70 = 0.0f;
                temp_f30 = 1.0f;
                temp_f28 = -temp_f22 / temp_f26;
            }

            temp_f12 = SQ(temp_f30) + SQ(sp70) + SQ(temp_f28);
            if (temp_f12 != 0.0f) {
                temp_f12 = 1.0f / shim_sqrtf(temp_f12);

                temp_f30 *= temp_f12;
                sp70 *= temp_f12;
                temp_f28 *= temp_f12;

                temp_f30 *=  8.0f;
                sp70 *= 8.0f;
                temp_f28 *= 8.0f;
                temp_f22 *= 8.0f;
                temp_f24 *= 8.0f;
                temp_f26 *= 8.0f;

                bpPtr->unk_00 = 0;
                bpPtr->init = fx_3D_init;
                bpPtr->update = fx_3D_update;
                bpPtr->renderWorld = fx_3D_render;
                bpPtr->unk_14 = NULL;
                bpPtr->effectID = EFFECT_3D;

                effect = shim_create_effect_instance(bpPtr);
                effect->numParts = numParts;
                part = effect->data.unk_3D = shim_general_heap_malloc(numParts * sizeof(*part));
                ASSERT(effect->data.unk_3D != NULL);

                part->unk_04 = 0;
                part->unk_00 = arg0;
                part->pos.x = arg1;
                part->pos.y = arg2;
                part->pos.z = arg3;
                part->unk_5C = 10;
                part->unk_60 = 0;

                part++;
                for (i = 1; i < numParts; i++, part++) {
                    part->pos.x = 0;
                    part->pos.y = 0;
                    part->pos.z = 0;
                    shim_guRotateF(sp30, i * 72, temp_f22, temp_f24, temp_f26);
                    part->unk_14 = part->unk_20 = 2.0f * temp_f22;
                    part->unk_18 = part->unk_24 = 2.0f * temp_f24;
                    part->unk_1C = part->unk_28 = 2.0f * temp_f26;
                    part->unk_38 = -temp_f22 * 0.05 * 4.0;
                    part->unk_3C = -temp_f24 * 0.05 * 4.0;
                    part->unk_40 = -temp_f26 * 0.05 * 4.0;
                    part->unk_2C = (sp30[0][0] * temp_f30 + sp30[1][0] * sp70 + sp30[2][0] * temp_f28) * 0.1 * 4.0;
                    part->unk_30 = (sp30[0][1] * temp_f30 + sp30[1][1] * sp70 + sp30[2][1] * temp_f28) * 0.1 * 4.0;
                    part->unk_34 = (sp30[0][2] * temp_f30 + sp30[1][2] * sp70 + sp30[2][2] * temp_f28) * 0.1 * 4.0;
                    part->unk_44 = 0.5f;
                    part->unk_48 = 4.0f;
                    part->unk_50 = 20.0f;
                    part->unk_4C = part->unk_54 = func_E0200000(360);
                    part->unk_58 = 255;
                    part->unk_64 = ((i - 1) / 5) * 2;
                    part->unk_5C = 10;
                }

                *outEffect = effect;
            }
        }
    }
}

void fx_3D_init(EffectInstance* effect) {
}

void fx_3D_update(EffectInstance* effect) {
    Effect3DFXData* part = effect->data.unk_3D;
    s32 unk_04 = part->unk_04;
    s32 unk_5C;
    s32 saved_5C;
    s32 i;

    part->unk_5C--;
    part->unk_60++;
    if (part->unk_5C < 0 && unk_04 == 2) {
        shim_remove_effect(effect);
        return;
    }

    saved_5C = part->unk_5C;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        if (part->unk_64 <= 0 || --part->unk_64 <= 0) {
            unk_5C = --part->unk_5C;
            if (unk_5C < 0) {
                if (unk_04 == 0) {
                    part->unk_58 = 255;
                    part->pos.x = 0.0f;
                    part->pos.y = 0.0f;
                    part->pos.z = 0.0f;
                    part->unk_14 = part->unk_20;
                    part->unk_18 = part->unk_24;
                    part->unk_1C = part->unk_28;
                    part->unk_44 = 0.5f;
                    part->unk_48 = 4.0f;
                    part->unk_50 = 20.0f;
                    part->unk_4C = part->unk_54;
                    part->unk_5C = 9;
                    unk_5C = 9;
                } else {
                    part->pos.x = 0.0f;
                    part->pos.y = 0.0f;
                    part->pos.z = 0.0f;
                    part->unk_14 = 0.0f;
                    part->unk_18 = 0.0f;
                    part->unk_1C = 0.0f;
                    part->unk_58 = 0;
                    part->unk_5C = 0;
                }
            }

            if (unk_5C - 4 < 3U) {
                part->unk_14 += part->unk_2C;
                part->unk_18 += part->unk_30;
                part->unk_1C += part->unk_34;
            }

            if (unk_5C < 8) {
                part->unk_44 += (3.0 - part->unk_44) * 0.03 * 8.0;
                part->unk_48 += (0.5 - part->unk_48) * 0.03 * 6.0;
            }

            part->unk_14 += part->unk_38;
            part->unk_18 += part->unk_3C;
            part->unk_1C += part->unk_40;

            if (part->unk_18 < 0.0f) {
                part->unk_50 *= 0.2;
                part->unk_14 *= 0.225;
                part->unk_18 *= 0.45;
                part->unk_1C *= 0.225;
                part->unk_58 *= 0.8;
            }

            part->pos.x += part->unk_14;
            part->pos.y += part->unk_18;
            part->pos.z += part->unk_1C;
            part->unk_4C += part->unk_50;
        }
    }

    if (saved_5C < 0) {
        part = effect->data.unk_3D;
        part->unk_5C = 10;
        part->unk_60 = 0;
    }
}

void fx_3D_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_3D_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E007A884(void) {
}

void fx_3D_appendGfx(void* effect) {
    Effect3DFXData* part = ((EffectInstance*)effect)->data.unk_3D;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, D_09000240);

    shim_guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 200, 255, 255, part->unk_58);

        shim_guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guScaleF(sp58, part->unk_44, part->unk_48, part->unk_44);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guRotateF(sp58, part->unk_4C, 0.0f, 0.0f, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_090002E8);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}
