#include "common.h"
#include "effects_internal.h"

void fx_65_init(EffectInstance* effect);
void fx_65_update(EffectInstance* effect);
void fx_65_render(EffectInstance* effect);
void fx_65_appendGfx(void* effect);

extern Gfx D_09000400_3D15E0[];

Gfx* D_E00CACB0[] = { D_09000400_3D15E0, D_09000400_3D15E0, D_09000400_3D15E0, D_09000400_3D15E0 };

EffectInstance* fx_65_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect65FXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = fx_65_init;
    bp.update = fx_65_update;
    bp.renderWorld = fx_65_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_65;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.unk_65 = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.unk_65 != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_34 = arg4;

    switch (arg0) {
        case 0:
            data->unk_18 = 255;
            data->unk_1C = 255;
            data->unk_20 = 255;
            data->unk_28 = 225;
            data->unk_2C = 225;
            data->unk_30 = 225;
            data->unk_24 = 255;
            break;
        case 1:
            data->unk_18 = 255;
            data->unk_1C = 245;
            data->unk_20 = 230;
            data->unk_28 = 45;
            data->unk_2C = 35;
            data->unk_30 = 15;
            data->unk_24 = 255;
            break;
        case 2:
            data->unk_18 = 255;
            data->unk_1C = 0;
            data->unk_20 = 0;
            data->unk_28 = 155;
            data->unk_2C = 125;
            data->unk_30 = 125;
            data->unk_24 = 255;
            break;
        case 3:
            data->unk_18 = 255;
            data->unk_1C = 255;
            data->unk_20 = 255;
            data->unk_28 = 255;
            data->unk_2C = 65;
            data->unk_30 = 20;
            data->unk_24 = 255;
            break;
    }

    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;

    for (i = 0; i < ARRAY_COUNT(data->unk_230); i++) {
        data->unk_230[i] = 0;
    }

    data->unk_2A8 = 0;
    data->unk_50[0] = arg1;
    data->unk_C8[0] = arg2;
    data->unk_140[0] = arg3;
    data->unk_230[0] = 1;
    data->unk_1B8[0] = 0;
    data->unk_2AC[0] = 0;
    data->unk_44 = shim_rand_int(30) + 10;
    data->unk_48 = 0;
    data->unk_4C = 0;

    return effect;
}

void fx_65_init(EffectInstance* effect) {
}

void fx_65_update(EffectInstance* effect) {
    Effect65FXData* data = effect->data.unk_65;
    s32 unk_00 = data->unk_00;
    s32 unk_14;
    f32 unk_2AC;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 tempX;
    f32 tempY;
    f32 tempZ;
    f32 dist;
    s32 idx;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_10 = 16;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;
    if (data->unk_10 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_14 = data->unk_14;

    if (data->unk_10 < 16) {
        data->unk_24 = data->unk_10 * 16;
    }

    if (unk_00 == 3) {
        data->unk_44 += shim_rand_int(10) - 5;
        data->unk_48 += shim_rand_int(10) - 5;
        data->pos.x += data->unk_44;
        data->pos.y += data->unk_48;
        data->pos.z += data->unk_4C;
    }

    idx = data->unk_2A8 % 30;

    posX = data->pos.x;
    posY = data->pos.y;
    posZ = data->pos.z;

    tempX = data->unk_50[idx];
    tempY = data->unk_C8[idx];
    tempZ = data->unk_140[idx];

    if ((posX != tempX) || (posY != tempY) || (posZ != tempZ)) {
        unk_2AC = data->unk_2AC[idx];

        data->unk_2A8++;
        if (data->unk_2A8 >= 30) {
            data->unk_2A8 = 0;
        }

        idx = data->unk_2A8;

        data->unk_230[idx] = 1;
        data->unk_50[idx] = posX;
        data->unk_C8[idx] = posY;
        data->unk_140[idx] = posZ;
        data->unk_1B8[idx] = unk_14;

        dist = SQ(posX - tempX) + SQ(posY - tempY) + SQ(posZ - tempZ);
        if (dist != 0.0f) {
            dist = shim_sqrtf(dist);
        }

        data->unk_2AC[idx] = unk_2AC + dist;
    }
}

void fx_65_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_65_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

// floats and more
#ifdef NON_MATCHING
void fx_65_appendGfx(void* effect) {
    Effect65FXData* data = ((EffectInstance*)effect)->data.unk_65;
    Matrix4f sp10;
    s32 sp50;
    s32 sp54;
    f32 sp58;
    Gfx* vtxBuffer;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    s32 idx;
    s32 idx2;
    f32 posX, posY, posZ;
    f32 deltaX, deltaY;
    Vtx_t* vtx;
    s32 i;

    f32 temp_f22;
    f32 temp_f2;
    f32 var_f12;
    f32 var_f20;
    f32 var_f30;
    s32 temp_fp;
    s32 temp_s1;
    s32 temp_s5;
    s32 temp_s5_2;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_fp;
    s32 vtxG;
    s32 var_s1;
    s32 vtxB;
    s32 vtxR;
    s32 vtxA;

    sp50 = data->unk_14;
    temp_s5 = data->unk_24;
    sp54 = data->unk_00;
    sp58 = data->unk_34;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp10, 0.0f, 0.0f, 0.0f);
    shim_guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_E00CACB0[sp54]);

    if (sp54 >= 2) {
        gDPSetCombineLERP(gMasterGfxPos++, SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, COMBINED, COMBINED, 0, PRIMITIVE, 0);
    }
    var_fp = 0;
    sp60 = -1;
    sp64 = (sp50 & 0x3F) << 5;
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, temp_s5);
    gDPSetEnvColor(gMasterGfxPos++, data->unk_28, data->unk_2C, data->unk_30, 0);
    gSPBranchList(gMasterGfxPos, &gMasterGfxPos[121]);

    vtxBuffer = (Vtx_t*) (gMasterGfxPos + 1);
    gMasterGfxPos = &gMasterGfxPos[121];

    for (i = 1; i < 30; i++) {
        if (data->unk_230[(data->unk_2A8 + i) % 30] != 0) {
            var_fp += 1;
        }
    }

    temp_fp = var_fp - 1;
    i = 0;
    if (temp_fp > 0) {
        sp68 = 0;

        for (; i < 30; i++) {
            Vtx_t* vtx = &vtxBuffer[i * 2];

            idx2 = (data->unk_2A8 + (i + 1)) % 30;
            vtxA = shim_sin_deg((f32) (sp68 / temp_fp)) * 255.0f;
            if (vtxA > 200) {
                vtxA = 200;
            }
            if (data->unk_230[idx2] != 0) {
                if (sp60 == -1) {
                    idx = idx2 + 1;
                    if (idx >= 30) {
                        idx = 0;
                    }
                    sp60 = i;
                    var_f30 = -shim_atan2(data->unk_C8[idx], -data->unk_50[idx], data->unk_C8[idx2], -data->unk_50[idx2]);
                } else {
                    idx = idx2 + 1;
                    if (i != 0x1D) {
                        var_s1 = idx2 - 1;
                        if (idx >= 30) {
                            idx = 0;
                        }
                        if (var_s1 < 0) {
                            var_s1 = 29;
                        }
                        var_f20 = -shim_atan2(data->unk_C8[idx], -data->unk_50[idx], data->unk_C8[idx2], -data->unk_50[idx2]);
                        var_f12 = -shim_atan2(data->unk_C8[idx2], -data->unk_50[idx2], data->unk_C8[var_s1], -data->unk_50[var_s1]);
                        temp_f2 = var_f12 - var_f20;
                        if (temp_f2 > 180.0f) {
                            var_f20 += 360.0f;
                        } else if (temp_f2 < -180.0f) {
                            var_f12 += 360.0f;
                        }
                        var_f30 = (f64) (var_f20 + var_f12) * 0.5;
                    }
                }
                temp_v1_2 = data->unk_1B8[idx2];
                posX = data->unk_50[idx2];
                posY = data->unk_C8[idx2];
                posZ = data->unk_140[idx2];
                temp_s1 = sp50 - temp_v1_2;
                //temp_f22 = ((shim_sin_deg(((sp50 - (temp_v1_2 * 80)) * 4)) * 3.0f) + 16.0f + temp_s1) * sp58;
                temp_f22 = ((shim_sin_deg((sp50 - (temp_v1_2 * 80)) * 4) * 3.0f) + 16.0f) + temp_s1;
                temp_f22 = temp_f22 * sp58;
                temp_s5_2 = (data->unk_2AC[idx2] * 24.0f) + sp64;

                do {
                    vtxR = 0xFF;
                    vtxG = 0xFF;
                    vtxB = 0xFF - (temp_s1 * 100);
                    if (vtxB < 0) {
                        vtxG = ((f32) vtxB * 0.8) + 255.0;
                        vtxB = 0;
                        if (vtxG < 0) {
                            vtxR = ((f32) vtxG * 0.4) + 255.0;
                            vtxG = 0;
                            if (vtxR < 0) {
                                vtxR = 0;
                            }
                        }
                    }
                } while (0);

                deltaX = temp_f22 * shim_sin_deg(var_f30);
                deltaY = temp_f22 * shim_cos_deg(var_f30);
                sp68 += 180;

                vtx->ob[0] = posX + deltaX;
                vtx->ob[1] = posY + deltaY;
                vtx->ob[2] = posZ + 0.0f;
                vtx->tc[0] = temp_s5_2;
                vtx->tc[1] = 0x400;
                vtx->cn[0] = vtxR;
                vtx->cn[1] = vtxG;
                vtx->cn[2] = vtxB;
                vtx->cn[3] = vtxA;
                vtx++;

                vtx->ob[0] = posX - deltaX;
                vtx->ob[1] = posY - deltaY;
                vtx->ob[2] = posZ + 0.0f;
                vtx->tc[0] = temp_s5_2;
                vtx->tc[1] = 0;
                vtx->cn[0] = vtxR;
                vtx->cn[1] = vtxG;
                vtx->cn[2] = vtxB;
                vtx->cn[3] = vtxA;
                vtx++;
            }
        }

        for (i = sp60; i < 29; i++) {
            gSPVertex(gMasterGfxPos++, &vtxBuffer[i * 4], 4, 0);
            gSP2Triangles(gMasterGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
        }
    }
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
#else
INCLUDE_ASM(s32, "effects/effect_65", fx_65_appendGfx);
#endif
