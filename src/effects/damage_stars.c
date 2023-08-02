#include "common.h"
#include "effects_internal.h"

extern Gfx D_090004C0_343500[];
extern Gfx D_090005E0_343620[];

u8 D_E0030E90[] = {
    254, 172, 172,
    254, 172, 213,
    254, 180, 154,
    213, 180, 254,
    180, 180, 254,
    180, 221, 254,
    180, 254, 254,
    180, 254, 213,
    180, 254, 180,
    213, 254, 180,
    254, 254, 180,
    254, 213, 172
};

f32 D_E0030EB4;

void damage_stars_init(EffectInstance* effect);
void damage_stars_update(EffectInstance* effect);
void damage_stars_render(EffectInstance* effect);
void damage_stars_appendGfx(void* effect);

void damage_stars_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    f32 arg6,
    s32 arg7
) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    DamageStarsFXData* part;
    f32 temp_f12;
    f32 var_f28;
    f32 var_f30;
    f32 rotateX;
    f32 rotateZ;
    f32 sp70;
    Matrix4f sp30;
    s32 i;

    if (arg7 != 0) {
        temp_f12 = SQ(arg4) + SQ(arg5) + SQ(arg6);
        if (temp_f12 != 0.0f) {
            temp_f12 = -1.0f / sqrtf(temp_f12);

            arg4 *= temp_f12;
            arg5 *= temp_f12;
            arg6 *= temp_f12;

            if (arg4 != 0.0f) {
                sp70 = 1.0f;
                var_f30 = -arg5 / arg4;
                var_f28 = 0.0f;
            } else if (arg5 != 0.0f) {
                sp70 = -arg4 / arg5;
                var_f30 = 1.0f;
                var_f28 = 0.0f;
            } else {
                sp70 = 0.0f;
                var_f30 = 1.0f;
                var_f28 = -arg4 / arg6;
            }

            temp_f12 = SQ(var_f30) + SQ(sp70) + SQ(var_f28);
            if (temp_f12 != 0) {
                temp_f12 = 1.0f / sqrtf(temp_f12);

                var_f30 *= temp_f12;
                sp70 *= temp_f12;
                var_f28 *= temp_f12;

                var_f30 *= 8.0f;
                sp70 *= 8.0f;
                var_f28 *= 8.0f;
                arg4 *= 8.0f;
                arg5 *= 8.0f;
                arg6 *= 8.0f;

                bpPtr->unk_00 = 0;
                bpPtr->init = damage_stars_init;
                bpPtr->update = damage_stars_update;
                bpPtr->renderWorld = damage_stars_render;
                bpPtr->renderUI = NULL;
                bpPtr->effectID = EFFECT_DAMAGE_STARS;

                effect = create_effect_instance(bpPtr);
                effect->numParts = arg7;
                part = effect->data.damageStars = general_heap_malloc(arg7 * sizeof(*part));
                ASSERT(effect->data.damageStars != NULL);

                for (i = 0; i < arg7; i++, part++) {
                    part->unk_00 = arg0;
                    part->unk_04 = arg1;
                    part->unk_08 = arg2;
                    part->unk_0C = arg3;

                    switch (arg0) {
                        case 0:
                        case 1:
                        case 2:
                            guRotateF(sp30, (i * 360) / (arg7 - 1), arg4, arg5, arg6);
                            part->unk_10 = arg4 + sp30[0][0] * var_f30 + sp30[1][0] * sp70 + sp30[2][0] * var_f28;
                            part->unk_14 = arg5 + sp30[0][1] * var_f30 + sp30[1][1] * sp70 + sp30[2][1] * var_f28;
                            part->unk_18 = arg6 + sp30[0][2] * var_f30 + sp30[1][2] * sp70 + sp30[2][2] * var_f28;
                            break;
                        case 3:
                            rotateX = sin_deg(gCameras[gCurrentCameraID].curYaw);
                            rotateZ = -cos_deg(gCameras[gCurrentCameraID].curYaw);
                            guRotateF(sp30,
                                (arg7 != 1) ? (i * 100) / (arg7 - 1) - 50 : 0.0f,
                                rotateX, 0.0f, rotateZ);
                            part->unk_10 = sp30[0][0] * arg4 + sp30[1][0] * arg5 + sp30[2][0] * arg6;
                            part->unk_14 = sp30[0][1] * arg4 + sp30[1][1] * arg5 + sp30[2][1] * arg6;
                            part->unk_18 = sp30[0][2] * arg4 + sp30[1][2] * arg5 + sp30[2][2] * arg6;
                            break;
                        case 4:
                            rotateX = sin_deg(gCameras[gCurrentCameraID].curYaw);
                            rotateZ = -cos_deg(gCameras[gCurrentCameraID].curYaw);
                            guRotateF(sp30, (i * 360.0f) / (arg7 - 1), rotateX, 0.0f, rotateZ);
                            part->unk_10 = sp30[0][0] * arg4 + sp30[1][0] * arg5 + sp30[2][0] * arg6;
                            part->unk_14 = sp30[0][1] * arg4 + sp30[1][1] * arg5 + sp30[2][1] * arg6;
                            part->unk_18 = sp30[0][2] * arg4 + sp30[1][2] * arg5 + sp30[2][2] * arg6;
                            break;
                    }

                    switch (arg0) {
                        case 0:
                            part->unk_20 = 0;
                            part->unk_28 = 24;
                            break;
                        case 1:
                            part->unk_20 = 20.0f;
                            part->unk_28 = 24;
                            break;
                        case 2:
                            part->unk_20 = 20.0f;
                            part->unk_28 = 40;
                            part->unk_10 *= 0.5;
                            part->unk_14 *= 0.5;
                            part->unk_18 *= 0.5;
                            break;
                        case 3:
                        case 4:
                            part->unk_20 = 20.0f;
                            part->unk_28 = 24;
                            break;
                    }

                    part->unk_1C = 0;
                    part->unk_2C = 0;
                    part->unk_24 = 255;
                }

                D_E0030EB4 += 15.0f;
                if (D_E0030EB4 > 360.0f) {
                    D_E0030EB4 = 0.0f;
                }
            }
        }
    }
}

void damage_stars_init(EffectInstance* effect) {
}

void damage_stars_update(EffectInstance* effect) {
    DamageStarsFXData* part = effect->data.damageStars;
    s32 unk_28;
    s32 unk_2C;
    s32 i;

    part->unk_28--;
    part->unk_2C++;

    if (part->unk_28 < 0) {
        remove_effect(effect);
        return;
    }

    unk_28 = part->unk_28;
    unk_2C = part->unk_2C;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->unk_00 == 2) {
            part->unk_14 = cos_deg(unk_2C * 6) * 4.0f;
            part->unk_10 *= 0.94;
            part->unk_18 *= 0.94;
            if (part->unk_14 < 0.0f) {
                part->unk_20 *= 0.8;
                part->unk_24 *= 0.6;
            }
        } else {
            if (unk_28 >= 6) {
                part->unk_10 *= 0.8;
                part->unk_14 *= 0.8;
                part->unk_18 *= 0.8;
            }
            if (unk_28 >= 6 && unk_28 <= 19) {
                if (part->unk_00 == 0) {
                    part->unk_20 += 1.0f;
                }
            } else if (unk_28 < 5) {
                part->unk_20 *= 0.8;
                part->unk_24 *= 0.6;
                part->unk_10 *= 0.7;
                part->unk_14 *= 0.7;
                part->unk_18 *= 0.7;
            }
        }

        part->unk_04 += part->unk_10;
        part->unk_08 += part->unk_14;
        part->unk_0C += part->unk_18;
        part->unk_1C += part->unk_20;
    }
}

void damage_stars_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = damage_stars_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void damage_stars_appendGfx(void* effect) {
    DamageStarsFXData* part = ((EffectInstance*)effect)->data.damageStars;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 baseIdx;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_090004C0_343500);

    baseIdx = (part->unk_2C - 1) * 3;
    baseIdx %= 36;

    for (i = 0; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        s32 rIdx = baseIdx + i * 3;
        s32 gIdx = baseIdx + 1 + i * 3;
        s32 bIdx = baseIdx + 2 + i * 3;

        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0030E90[rIdx % 36], D_E0030E90[gIdx % 36], D_E0030E90[bIdx % 36], part->unk_24);
        guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
        guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        guRotateF(sp18, part->unk_1C, 0.0f, 0.0f, 1.0f);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_090005E0_343620);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}
