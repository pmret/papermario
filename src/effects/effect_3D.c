#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000240_37D3C0[];
extern Gfx D_090002E8_37D468[];

void effect_3D_init(EffectInstance* effect);
void effect_3D_update(EffectInstance* effect);
void effect_3D_render(EffectInstance* effect);
void effect_3D_appendGfx(void* effect);

void effect_3D_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7, EffectInstance** outEffect) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    Effect3DFXData* part;
    f32 temp_f12;
    f32 temp_f28;
    f32 temp_f30;
    f32 sp70;
    Matrix4f sp30;
    s32 i;

    if (arg7 != 0) {
        arg7++;

        temp_f12 = SQ(arg4) + SQ(arg5) + SQ(arg6);
        if (temp_f12 != 0.0f) {
            temp_f12 = -1.0f / sqrtf(temp_f12);

            arg4 *= temp_f12;
            arg5 *= temp_f12;
            arg6 *= temp_f12;

            if (arg4 != 0.0f) {
                sp70 = 1.0f;
                temp_f30 = -arg5 / arg4;
                temp_f28 = 0.0f;
            } else if (arg5 != 0.0f) {
                sp70 = -arg4 / arg5;
                temp_f30 = 1.0f;
                temp_f28 = 0.0f;
            } else {
                sp70 = 0.0f;
                temp_f30 = 1.0f;
                temp_f28 = -arg4 / arg6;
            }

            temp_f12 = SQ(temp_f30) + SQ(sp70) + SQ(temp_f28);
            if (temp_f12 != 0.0f) {
                temp_f12 = 1.0f / sqrtf(temp_f12);

                temp_f30 *= temp_f12;
                sp70 *= temp_f12;
                temp_f28 *= temp_f12;

                temp_f30 *=  8.0f;
                sp70 *= 8.0f;
                temp_f28 *= 8.0f;
                arg4 *= 8.0f;
                arg5 *= 8.0f;
                arg6 *= 8.0f;

                bpPtr->unk_00 = 0;
                bpPtr->init = effect_3D_init;
                bpPtr->update = effect_3D_update;
                bpPtr->renderWorld = effect_3D_render;
                bpPtr->renderUI = NULL;
                bpPtr->effectID = EFFECT_3D;

                effect = create_effect_instance(bpPtr);
                effect->numParts = arg7;
                part = effect->data.unk_3D = general_heap_malloc(arg7 * sizeof(*part));
                ASSERT(effect->data.unk_3D != NULL);

                part->unk_04 = 0;
                part->unk_00 = arg0;
                part->pos.x = arg1;
                part->pos.y = arg2;
                part->pos.z = arg3;
                part->unk_5C = 10;
                part->unk_60 = 0;

                part++;
                for (i = 1; i < arg7; i++, part++) {
                    part->pos.x = 0;
                    part->pos.y = 0;
                    part->pos.z = 0;
                    guRotateF(sp30, i * 72, arg4, arg5, arg6);
                    part->unk_14 = part->unk_20 = 2.0f * arg4;
                    part->unk_18 = part->unk_24 = 2.0f * arg5;
                    part->unk_1C = part->unk_28 = 2.0f * arg6;
                    part->unk_38 = -arg4 * 0.05 * 4.0;
                    part->unk_3C = -arg5 * 0.05 * 4.0;
                    part->unk_40 = -arg6 * 0.05 * 4.0;
                    part->unk_2C = (sp30[0][0] * temp_f30 + sp30[1][0] * sp70 + sp30[2][0] * temp_f28) * 0.1 * 4.0;
                    part->unk_30 = (sp30[0][1] * temp_f30 + sp30[1][1] * sp70 + sp30[2][1] * temp_f28) * 0.1 * 4.0;
                    part->unk_34 = (sp30[0][2] * temp_f30 + sp30[1][2] * sp70 + sp30[2][2] * temp_f28) * 0.1 * 4.0;
                    part->unk_44 = 0.5f;
                    part->unk_48 = 4.0f;
                    part->unk_50 = 20.0f;
                    part->unk_4C = part->unk_54 = effect_rand_int(360);
                    part->unk_58 = 255;
                    part->unk_64 = ((i - 1) / 5) * 2;
                    part->unk_5C = 10;
                }

                *outEffect = effect;
            }
        }
    }
}

void effect_3D_init(EffectInstance* effect) {
}

void effect_3D_update(EffectInstance* effect) {
    Effect3DFXData* part = effect->data.unk_3D;
    s32 unk_04 = part->unk_04;
    s32 unk_5C;
    s32 saved_5C;
    s32 i;

    part->unk_5C--;
    part->unk_60++;
    if (part->unk_5C < 0 && unk_04 == 2) {
        remove_effect(effect);
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

            if (unk_5C >= 4 && unk_5C <= 6) {
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

void effect_3D_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = effect_3D_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E007A884(void) {
}

void effect_3D_appendGfx(void* effect) {
    Effect3DFXData* part = ((EffectInstance*)effect)->data.unk_3D;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000240_37D3C0);

    guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 200, 255, 255, part->unk_58);

        guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
        guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp58, sp18, sp18);
        guScaleF(sp58, part->unk_44, part->unk_48, part->unk_44);
        guMtxCatF(sp58, sp18, sp18);
        guRotateF(sp58, part->unk_4C, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_090002E8_37D468);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
