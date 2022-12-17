#include "common.h"
#include "effects_internal.h"

void stars_shimmer_init(EffectInstance* effect);
void stars_shimmer_update(EffectInstance* effect);
void stars_shimmer_render(EffectInstance* effect);
void stars_shimmer_appendGfx(void* effect);

extern Gfx D_09000F20[];
extern Gfx D_09001210[];
extern Gfx D_09001228[];
extern Gfx D_09001240[];
extern Gfx D_09001258[];
extern Gfx D_09001270[];
extern Gfx D_090011C8[];
extern Gfx D_090011E0[];
extern Gfx D_090011F8[];

Gfx* D_E0044DB0[] = {
    D_09001210, D_09001228, D_09001240, D_09001258, D_09001270, D_090011C8, D_090011E0, D_090011F8
};

u8 D_E0044DD0[] = {
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
    254, 213, 172,
};

u8 D_E0044DF4[] = {
    30, 60, 90, 100, 104, 106, 108, 110, 112, 113, 113, 110, 107, 103, 0x00, 0x00
};

u8 D_E0044E04[] = {
    30, 60, 90, 100, 104, 106, 108, 110, 112, 113, 113, 110, 107, 103, 0x00, 0x00
};

// ordering crap
#ifdef NON_EQUIVALENT
void stars_shimmer_main(s32 type, f32 x, f32 y, f32 z, f32 arg4, f32 arg5, s32 arg6, s32 arg7) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    StarsShimmerFXData* part;
    s32 numParts = arg6;
    f32 theta;
    f32 cosTheta;
    f32 sinTheta;
    f32 temp_f22;
    f32 temp_f8;
    f32 temp_ft;
    f32 sinT3;
    f32 temp5;
    f32 t3;
    s32 i;

    numParts = arg6 + 1;

    bpPtr->init = stars_shimmer_init;
    bpPtr->update = stars_shimmer_update;
    bpPtr->renderWorld = stars_shimmer_render;
    bpPtr->unk_00 = 0;
    bpPtr->unk_14 = NULL;
    bpPtr->effectID = EFFECT_STARS_SHIMMER;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.starsBurst = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.starsBurst != NULL);

    if (type == 6) {
        part->unk_00 = 1;
        type = 3;
    } else {
        part->unk_00 = 0;
    }
    part->pos.x = x;
    part->pos.y = y;
    part->pos.z = z;
    part->lifeTime = 0;
    part->unk_02 = type;
    part->timeLeft = arg7;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        temp_f22 = (360.0f / (numParts - 1)) * i;
        if (type > 1) {
            theta = temp_f22 + shim_rand_int(359);
        } else {
            theta = temp_f22 + 0.0f;
        }
        t3 = (temp_f22 * 10.0f) - 90.0f;
        sinTheta = shim_sin_deg(theta);
        cosTheta = shim_cos_deg(theta);
        sinT3 = shim_sin_deg(t3);
        temp_f8 = (arg4 * 0.4) - (arg4 * 0.1 * sinT3);
        temp_ft = (arg5 * 0.4) - (arg5 * 0.1 * sinT3);
        temp5 = (arg5 / (numParts - 1)) * (i - 1);

        part->timeLeft = i + 30;
        part->lifeTime = 0;
        part->unk_1C = 1.0f;

        switch (type) {
            case 0:
            case 1:
                part->unk_18 = 0;
                part->pos.z = 0.0f;
                part->unk_10 = sinTheta * temp_f8;
                part->unk_14 = cosTheta * temp_ft;
                break;
            case 3:
                part->pos.x = (sinTheta * arg4 * shim_rand_int(100)) * 0.005;
                part->pos.y = (cosTheta * arg5 * shim_rand_int(100)) * 0.005;
                part->pos.z = 0.0f;

                part->unk_18 = part->unk_10 = part->unk_14 = 0.0f;

                part->timeLeft += i * 2;
                break;
            case 2:
            case 4:
            case 5:
            default:
                part->unk_10 = sinTheta * temp_f8;
                part->pos.y = temp5;
                part->pos.z = cosTheta * temp_f8;
                part->unk_14 = -shim_rand_int(10) * 0.03f;
                part->unk_18 = (shim_rand_int(10) * 0.04f) + 0.01;
                break;
        }
    }
}
#else
INCLUDE_ASM(s32, "effects/stars_shimmer", stars_shimmer_main);
#endif

void stars_shimmer_init(EffectInstance* effect) {
}

// tons of issues
#ifdef NON_EQUIVALENT
void stars_shimmer_update(EffectInstance* effect) {
    StarsShimmerFXData* data = effect->data.starsShimmer;
    u8** new_var = &D_E0044E04;
    s32 count = 0;
    f32 temp_f0;
    f32 temp_f8;
    f32 var_f20;
    s32 temp_s3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 new_var2;
    s32 temp_v1_4;
    s32 var_s2;
    s32 var_v0;
    s32 i;

    temp_s3 = data->unk_02;
    data->timeLeft--;
    data->lifeTime++;
    var_s2 = data->lifeTime;
    new_var2 = var_s2;
    if (!(temp_s3 != 0 && temp_s3 != 1) || temp_s3 == 3 || temp_s3 >= 10) {
        if (data->timeLeft < 0) {
            shim_remove_effect(effect);
            return;
        }
    }

    for (i = 0; i < effect->numParts - 1; i++, data++) {
        var_v0 = var_s2 + i;
        switch (temp_s3) {
            case 0:
            case 1:
                temp_v1 = var_s2 - 1;
                data->unk_28 = (var_s2 + i) & 7;
                data->unk_18 += -0.02;
                if (temp_v1 < 14) {
                    temp_f0 = (f32) D_E0044DF4[temp_v1] * 0.01;
                    data->pos.x = data->unk_10 * temp_f0;
                    data->pos.y = (data->unk_14 * temp_f0) + data->unk_18;
                    data->unk_1C = (f32) (*new_var)[var_s2 - 1] * 0.01;
                } else {
                    var_f20 = ((360.0f / (effect->numParts - 1)) * i) + 60.0f;
                    if (i % 2) {
                        var_f20 -= 120.0f;
                    }
                    data->unk_02 = 10;
                    data->unk_10 = shim_sin_deg(var_f20);
                    data->unk_14 = shim_cos_deg(var_f20);
                    data->unk_18 = -0.05f;
                }
                break;
            case 10:
            case 30:
                data->unk_10 *= 0.96;
                data->unk_14 *= 0.96;
                data->unk_14 += data->unk_18;
                data->unk_28 = (var_s2 + i) & 7;
                data->unk_1C += (0.1 - data->unk_1C) * 0.1;
                data->pos.x += data->unk_10;
                data->pos.y += data->unk_14;
                break;
            case 3:
                data->unk_28 = (var_s2 + i + i) & 7;
                if (var_s2 - 1 < 14) {
                    data->unk_1C = (f32) D_E0044E04[new_var2 - 1] * 0.01;
                    break;
                }
                data->unk_02 = 30;
                break;
            case 2:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
                var_v0 = var_s2 + i;
                /* fallthrough */
            default:
                data->unk_28 = (var_v0 + i) & 7;
                if (data->timeLeft < 0) {
                    count++;
                }
                data->timeLeft--;
                if (data->timeLeft >= 0x1FU) {
                    data->unk_28 = -1;
                } else {
                    var_s2 = data->lifeTime + 1;
                    data->lifeTime++;
                    if (data->lifeTime < 14) {
                        data->unk_1C = (f32) D_E0044E04[data->lifeTime] * 0.01;
                        if (temp_s3 == 5) {
                            data->unk_14 += data->unk_18;
                            data->pos.y += data->unk_14;
                        }
                    } else {
                        data->unk_14 += data->unk_18;
                        data->pos.y += data->unk_14;
                        data->unk_1C += (0.1 - data->unk_1C) * 0.1;
                    }
                    if (temp_s3 == 4) {
                        data->pos.x = data->unk_10 * shim_sin_deg(var_s2 * 12);
                        data->pos.z = data->unk_10 * shim_cos_deg(var_s2 * 12);
                    } else {
                        data->pos.x = data->unk_10;
                    }
                    data->unk_14 *= 0.96;
                }
                break;
        }
    }
    if (!(temp_s3 == 0 || temp_s3 == 1) && temp_s3 != 3 && temp_s3 < 10 && (count >= effect->numParts - 1)) {
        shim_remove_effect(effect);
    }
}
#else
INCLUDE_ASM(s32, "effects/stars_shimmer", stars_shimmer_update);
#endif

void stars_shimmer_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = stars_shimmer_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void stars_shimmer_appendGfx(void* effect) {
    Matrix4f sp18, sp58, sp98;
    StarsShimmerFXData* data = ((EffectInstance*)effect)->data.starsShimmer;
    s32 type;
    s32 temp_s4;
    s32 unk_28;
    f32 rf, gf, bf;
    s32 r, g, b;
    s32 i;

    type = data->unk_02;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, D_09000F20);

    temp_s4 = (data->lifeTime - 1) * 3;
    shim_guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp98);

    switch (type) {
        case 0:
        case 1:
        case 2:
        case 10:
            rf = 1.0f;
            gf = 0.5f;
            bf = 0.1f;
            break;
        case 3:
        case 30:
            rf = 1.0f;
            gf = 0.8f;
            bf = 0.7f;
            if (data->unk_00 != 0) {
                gDPSetRenderMode(gMasterGfxPos++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
            }
            break;
        case 5:
            rf = 1.4f;
            gf = 1.4f;
            bf = 0.7f;
            break;
        default:
            rf = 1.4f;
            gf = 0.7f;
            bf = 0.7f;
            break;
    }

    data++;
    for (i = 0; i < ((EffectInstance*)effect)->numParts - 1; i++, data++) {
        unk_28 = data->unk_28;
        if (unk_28 >= 0) {
            shim_guTranslateF(sp58, data->pos.x, data->pos.y, data->pos.z);
            sp58[0][0] = sp58[1][1] = sp58[2][2] = data->unk_1C;
            shim_guMtxCatF(sp58, sp98, sp18);
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
            if (temp_s4 >= 36) {
                temp_s4 = 0;
            }
            r = D_E0044DD0[temp_s4++] * rf;
            g = D_E0044DD0[temp_s4++] * gf;
            b = D_E0044DD0[temp_s4++] * bf;
            if (r > 255) {
                r = 255;
            }
            if (g > 255) {
                g = 255;
            }
            if (b > 255) {
                b = 255;
            }
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, r, g, b, 255);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_E0044DB0[unk_28 & 7]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMasterGfxPos++);
}
