#include "common.h"
#include "effects_internal.h"

void stars_shimmer_init(EffectInstance* effect);
void stars_shimmer_update(EffectInstance* effect);
void stars_shimmer_render(EffectInstance* effect);
void stars_shimmer_appendGfx(void* effect);

extern Gfx D_09000F20_338EE0[];
extern Gfx D_090011C8_339188[];
extern Gfx D_090011E0_3391A0[];
extern Gfx D_090011F8_3391B8[];
extern Gfx D_09001210_3391D0[];
extern Gfx D_09001228_3391E8[];
extern Gfx D_09001240_339200[];
extern Gfx D_09001258_339218[];
extern Gfx D_09001270_339230[];

Gfx* D_E0044DB0[] = {
    D_09001210_3391D0, D_09001228_3391E8, D_09001240_339200, D_09001258_339218,
    D_09001270_339230, D_090011C8_339188, D_090011E0_3391A0, D_090011F8_3391B8
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

void stars_shimmer_main(s32 type, f32 x, f32 y, f32 z, f32 arg4, f32 arg5, s32 numParts, s32 arg7) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    StarsShimmerFXData* part;
    f32 cosTheta;
    f32 sinTheta;
    f32 temp_f22;
    f32 temp_f8;
    f32 temp_ft;
    f32 theta;
    f32 temp5;
    f32 t3;
    f32 new_var;
    s32 i;

    numParts++;

    bpPtr->init = stars_shimmer_init;
    bpPtr->update = stars_shimmer_update;
    bpPtr->renderWorld = stars_shimmer_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_STARS_SHIMMER;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.starsShimmer = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.starsShimmer != NULL);

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
    part->state = type;
    part->timeLeft = arg7;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        temp_f22 = (360.0f / (numParts - 1)) * i;
        if (type > 1) {
            theta = temp_f22 + rand_int(359);
        } else {
            theta = temp_f22 + 0.0f;
        }
        t3 = (temp_f22 * 10.0f) - 90.0f;
        sinTheta = sin_deg(theta);
        cosTheta = cos_deg(theta);
        temp_f22 = sin_deg(t3);
        temp_f8 = (arg4 * 0.4) - (arg4 * 0.1 * temp_f22);
        temp_ft = (arg5 * 0.4) - (arg5 * 0.1 * temp_f22);
        new_var = 1.0f; // TODO dumb temp and cast later required to match
        temp5 = (arg5 / (numParts - 1)) * (i - 1);

        part->unk_1C = (u8) new_var;
        part->lifeTime = 0;
        part->timeLeft = i + 30;

        switch (type) {
            case 0:
            case 1:
                part->unk_18 = 0;
                part->pos.z = 0.0f;
                part->unk_10 = sinTheta * temp_f8;
                part->unk_14 = cosTheta * temp_ft;
                break;
            case 3:
                part->pos.x = (sinTheta * arg4 * rand_int(100)) * 0.005;
                part->pos.y = (cosTheta * arg5 * rand_int(100)) * 0.005;
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
                part->unk_14 = -rand_int(10) * 0.03f;
                part->unk_18 = (rand_int(10) * 0.04f) + 0.01;
                break;
        }
    }
}

void stars_shimmer_init(EffectInstance* effect) {
}

void stars_shimmer_update(EffectInstance* effect) {
    StarsShimmerFXData* data = effect->data.starsShimmer;
    StarsShimmerFXData* it = data;
    s32 deadParts = 0;
    s32 state = it->state;
    s32 lifeTime;
    s32 i;

    it->timeLeft--;
    it->lifeTime++;
    lifeTime = it->lifeTime;
    if (state == 0 || state == 1 || state == 3 || state >= 10) {
        if (it->timeLeft < 0) {
            remove_effect(effect);
            return;
        }
    }

    it++;
    for (i = 0; i < effect->numParts - 1; i++, it++) {
        switch (state) {
            case 0:
            case 1:
                it->unk_28 = (lifeTime + i) & 7;
                it->unk_18 += -0.02;
                if (lifeTime - 1 < 14) {
                    f32 temp_f0 = (f32) D_E0044DF4[lifeTime - 1] * 0.01;

                    it->pos.x = it->unk_10 * temp_f0;
                    it->pos.y = (it->unk_14 * temp_f0) + it->unk_18;
                    it->unk_1C = (f32) D_E0044E04[lifeTime - 1] * 0.01;
                } else {
                    f32 var_f20 = ((360.0f / (effect->numParts - 1)) * i) + 60.0f;

                    if (i % 2 != 0) {
                        var_f20 -= 120.0f;
                    }
                    data->state = 10;
                    it->unk_10 = sin_deg(var_f20);
                    it->unk_14 = cos_deg(var_f20);
                    it->unk_18 = -0.05f;
                }
                break;
            case 10:
            case 30:
                it->unk_28 = (lifeTime + i) & 7;
                it->unk_10 *= 0.96;
                it->unk_14 *= 0.96;
                it->unk_14 += it->unk_18;
                it->unk_1C += (0.1 - it->unk_1C) * 0.1;
                it->pos.x += it->unk_10;
                it->pos.y += it->unk_14;
                break;
            case 3:
                it->unk_28 = (lifeTime + i + i) & 7;
                if (lifeTime - 1 < 14) {
                    it->unk_1C = (f32) D_E0044E04[lifeTime - 1] * 0.01;
                    break;
                }
                data->state = 30;
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
            default:
                it->unk_28 = (lifeTime + i + i) & 7;
                if (it->timeLeft < 0) {
                    deadParts++;
                }
                it->timeLeft--;
                if ((u32) it->timeLeft > 30) {
                    it->unk_28 = -1;
                } else {
                    it->lifeTime++;
                    lifeTime = it->lifeTime;
                    if (lifeTime - 1 < 14) {
                        it->unk_1C = (f32) D_E0044E04[lifeTime - 1] * 0.01;
                        if (state == 5) {
                            it->unk_14 += it->unk_18;
                            it->pos.y += it->unk_14;
                        }
                    } else {
                        it->unk_14 += it->unk_18;
                        it->pos.y += it->unk_14;
                        it->unk_1C += (0.1 - it->unk_1C) * 0.1;
                    }
                    if (state == 4) {
                        it->pos.x = (it->unk_10 * sin_deg(lifeTime * 12));
                        it->pos.z = (it->unk_10 * cos_deg(lifeTime * 12));
                    } else {
                        it->pos.x = it->unk_10;
                    }
                    it->unk_14 *= 0.96;
                }
        }
    }

    if (state != 0 && state != 1 && state != 3 && state < 10 && deadParts >= effect->numParts - 1) {
        remove_effect(effect);
    }
}

void stars_shimmer_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = stars_shimmer_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
}

void stars_shimmer_appendGfx(void* effect) {
    Matrix4f sp18, sp58, sp98;
    StarsShimmerFXData* data = ((EffectInstance*)effect)->data.starsShimmer;
    s32 state;
    s32 temp_s4;
    s32 unk_28;
    f32 rf, gf, bf;
    s32 r, g, b;
    s32 i;

    state = data->state;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000F20_338EE0);

    temp_s4 = (data->lifeTime - 1) * 3;
    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);

    switch (state) {
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
                gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
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
            guTranslateF(sp58, data->pos.x, data->pos.y, data->pos.z);
            sp58[0][0] = sp58[1][1] = sp58[2][2] = data->unk_1C;
            guMtxCatF(sp58, sp98, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
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
            gDPSetPrimColor(gMainGfxPos++, 0, 0, r, g, b, 255);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_E0044DB0[unk_28 & 7]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMainGfxPos++);
}
