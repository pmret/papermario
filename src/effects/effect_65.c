#include "common.h"
#include "effects_internal.h"

void effect_65_init(EffectInstance* effect);
void effect_65_update(EffectInstance* effect);
void effect_65_render(EffectInstance* effect);
void effect_65_appendGfx(void* effect);

extern Gfx D_09000400_3D15E0[];

Gfx* D_E00CACB0[] = { D_09000400_3D15E0, D_09000400_3D15E0, D_09000400_3D15E0, D_09000400_3D15E0 };

EffectInstance* effect_65_main(
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

    bp.init = effect_65_init;
    bp.update = effect_65_update;
    bp.renderWorld = effect_65_render;
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
        data->unk_230[i] = FALSE;
    }

    data->unk_2A8 = 0;
    data->unk_50[0] = arg1;
    data->unk_C8[0] = arg2;
    data->unk_140[0] = arg3;
    data->unk_230[0] = TRUE;
    data->unk_1B8[0] = 0;
    data->unk_2AC[0] = 0;
    data->unk_44 = shim_rand_int(30) + 10;
    data->unk_48 = 0;
    data->unk_4C = 0;

    return effect;
}

void effect_65_init(EffectInstance* effect) {
}

void effect_65_update(EffectInstance* effect) {
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

    if (posX != tempX || posY != tempY || posZ != tempZ) {
        unk_2AC = data->unk_2AC[idx];

        data->unk_2A8++;
        if (data->unk_2A8 >= 30) {
            data->unk_2A8 = 0;
        }

        idx = data->unk_2A8;

        data->unk_230[idx] = TRUE;
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

void effect_65_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = effect_65_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

extern int COMBINED;
extern int ENVIRONMENT;
extern int SHADE;

// floats and more
#ifdef NON_MATCHING
void effect_65_appendGfx(void* effect) {
    Effect65FXData* data = ((EffectInstance*)effect)->data.unk_65; //s6
    Matrix4f sp10;
    f32 padding[2];
    s32 sp50;
    s32 sp54;
    Vtx_t* sp5C;
    Vtx_t* vtx;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    f32 temp_f0;
    f32 temp_f20;
    f32 sp58;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f2;
    f32 var_f12;
    f32 var_f20;
    f32 var_f30;
    s32 primAlpha;
    s32 temp_s5_2;
    s32 var_fp;
    s32 temp_s1;
    s32 a;
    s32 r, g, b;

    s32 idx; //s3
    s32 next; //v1
    s32 prev;
    s32 i;

    float new_var;

    primAlpha = data->unk_24;
    sp50 = data->unk_14;
    sp54 = data->unk_00;
    sp58 = data->unk_34;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp10, 0.0f, 0.0f, 0.0f);
    shim_guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_E00CACB0[sp54]);

    if (sp54 >= 2) {
        gDPSetCombineLERP(gMainGfxPos++, SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, COMBINED, COMBINED, 0, PRIMITIVE, 0);
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, primAlpha);
    gDPSetEnvColor(gMainGfxPos++, data->unk_28, data->unk_2C, data->unk_30, 0);
    gSPBranchList(gMainGfxPos, gMainGfxPos + 0x79);

    sp5C = (Vtx_t*) (gMainGfxPos + 1);
    sp60 = -1;
    sp64 = (sp50 & 0x3F) << 5;
    gMainGfxPos += 0x79;

    // use i in iteration?
    var_fp = 0;
    for (i = 0; i < 30; i++) {
        s32 a1 = i + 1;
        s32 idx = (data->unk_2A8 + a1) % 30;
        if (data->unk_230[idx]) {
            var_fp++;
        }
    }

    var_fp--;
    if (var_fp > 0) {
        sp68 = 0;
        for (i = 0; i < 30; i++) {
            s32 a1 = i + 1;
            vtx = &sp5C[i * 2];
            prev = sp68 / var_fp;
            idx = (data->unk_2A8 + a1) % 30;
            a = shim_sin_deg(prev) * 255.0f;
            if (a > 200) {
                a = 200;
            }

            if (data->unk_230[idx]) {
                if (sp60 == -1) {
                    do {
                        next = idx + 1;
                        if (next >= 30) {
                            next = 0;
                        }
                        sp60 = i;
                        var_f30 = -shim_atan2(data->unk_C8[next], -data->unk_50[next], data->unk_C8[idx], -data->unk_50[idx]);
                    } while (0); // TODO required to match
                } else {
                    if (i != 29) {
                        next = idx + 1;
                        prev = idx - 1;
                        if (next >= 30) {
                            next = 0;
                        }
                        if (prev < 0) {
                            prev = 29;
                        }
                        var_f20 = -shim_atan2(data->unk_C8[next], -data->unk_50[next], data->unk_C8[idx], -data->unk_50[idx]);
                        var_f12 = -shim_atan2(data->unk_C8[idx], -data->unk_50[idx], data->unk_C8[prev], -data->unk_50[prev]);
                        temp_f2 = var_f12 - var_f20;
                        if (temp_f2 > 180.0f) {
                            var_f20 += 360.0f;
                        } else if (temp_f2 < -180.0f) {
                            var_f12 += 360.0f;
                        }
                        var_f30 = (var_f20 + var_f12);
                        var_f30 *= 0.5;
                    }
                }
                temp_f24 = data->unk_50[idx];
                temp_f26 = data->unk_C8[idx];
                temp_f28 = data->unk_140[idx];
                new_var = 24.0f;
                //temp_v1 = data->unk_1B8[idx];
                temp_s1 = sp50 - data->unk_1B8[idx];
                temp_f22 = (shim_sin_deg((sp50 - data->unk_1B8[idx] * 80) * 4) * 3.0f + 16.0f + temp_s1);
                temp_f22 *= sp58;
                temp_s5_2 = sp64;
                temp_s5_2 = (data->unk_2AC[idx] * new_var) + temp_s5_2;

                do {} while (0);

                r = 255;
                g = 255;
                b = 255 - temp_s1 * 100;
                if (b < 0) {
                    g = (f32) b * 0.8 + 255.0;
                    b = 0;
                    if (g < 0) {
                        r = (f32) g * 0.4 + 255.0;
                        g = 0;
                        sp54 = r < 0;
                        if (sp54) {
                            r = 0;
                        }
                    }
                }

                temp_f20 = temp_f22 * shim_sin_deg(var_f30);
                temp_f0 = temp_f22 * shim_cos_deg(var_f30);

                vtx->ob[0] = temp_f24 + temp_f20;
                vtx->ob[1] = temp_f26 + temp_f0;
                vtx->ob[2] = temp_f28 + 0.0f;
                vtx->tc[0] = temp_s5_2;
                vtx->tc[1] = 0x400;
                vtx->cn[0] = r;
                vtx->cn[1] = g;
                vtx->cn[2] = b;
                vtx->cn[3] = a;
                vtx++;

                vtx->ob[0] = temp_f24 - temp_f20;
                vtx->ob[1] = temp_f26 - temp_f0;
                vtx->ob[2] = temp_f28 + 0.0f;
                vtx->tc[0] = temp_s5_2;
                vtx->tc[1] = 0;
                vtx->cn[0] = r;
                vtx->cn[1] = g;
                vtx->cn[2] = b;
                vtx->cn[3] = a;
                vtx++;

                sp68 += 180;
            }
        }

        for (i = sp60; i < 29; i++) {
            gSPVertex(gMainGfxPos++, &sp5C[i * 2], 4, 0);
            gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
#else
INCLUDE_ASM(s32, "effects/effect_65", effect_65_appendGfx);
#endif
