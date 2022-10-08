#include "common.h"
#include "effects_internal.h"

extern Gfx D_090000B0_36E040[];
extern Gfx D_09000110_36E0A0[];
extern Gfx D_09000130_36E0C0[];
extern Gfx D_090001D8_36E168[];

Gfx* D_E006ADF0[] = {
    D_09000110_36E0A0, D_09000110_36E0A0, D_090000B0_36E040, D_090000B0_36E040
};

Gfx* D_E006AE00[] = {
    D_09000130_36E0C0, D_09000130_36E0C0, D_090001D8_36E168, D_090001D8_36E168
};

s32 D_E006AE10[] = {
    0, -20, 0, 1, 18, -10, -60, 45, -1, 4, -20, -20, 90, 1, 1, -10,
    -60, 135, 1, -4, 0, -20, 180, -8, 1, -10, -60, 225, -1, -1, -20, -20,
    270, 1, -9, -10, -60, 315, 4, 4, 0, 10, 22, 4, 1, -10, 20, 67,
    1, -1, -20, 10, 112, -1, -1, -10, 20, 157, -8, 1, 0, 10, 202, 1,
    -4, -10, 20, 247, 1, -18, -20, 10, 292, -1, 9, -10, 20, 337, 1, 1
};

void light_rays_init(EffectInstance* effect);
void light_rays_update(EffectInstance* effect);
void light_rays_render(EffectInstance* effect);
void light_rays_appendGfx(void* effect);

void func_E006A000(LightRaysFXData* part, s32 arg1) {
    s32 temp = arg1 * 3;

    part->unk_70 = func_E0200044(180, temp);
    part->unk_74 = func_E0200044(180, temp + 1);
    part->unk_78 = func_E0200044(180, temp + 2);
    part->unk_24 = 0;
    part->unk_2C = 0;
    part->unk_58 = part->unk_68;
    part->unk_28 = part->unk_7C;
    part->unk_8C = part->unk_6C;
    part->unk_5C = part->unk_70;
    part->unk_60 = part->unk_74;
    part->unk_64 = part->unk_78;
}

void func_E006A0BC(LightRaysFXData* part, s32 arg1) {
    s32 idx = (arg1 - 1) * 5;

    part->unk_58 = 0;
    part->unk_28 = arg1 * 2 + 30;
    part->unk_5C = D_E006AE10[idx++];
    part->unk_60 = D_E006AE10[idx++];
    part->unk_64 = D_E006AE10[idx++];
    part->unk_24 = 0;
    part->unk_2C = 0;
    part->unk_34 = part->unk_38 = 0.0f;
    part->unk_48 = 0.0f;
    part->unk_4C = -0.6f;
    part->unk_3C = 10.0f;
    part->unk_40 = 0.0f;
    part->unk_50 = 0.0f;
    part->unk_54 = 0.6f;
    part->unk_80 = 0.0f;
    part->unk_84 = (f32) D_E006AE10[idx++] * 0.0;
    part->unk_88 = (f32) D_E006AE10[idx++] * 0.1;
    part->unk_90 = 0;
}

void light_rays_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    EffectInstance** outEffect
) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    LightRaysFXData* part;
    s32 numParts;
    s32 temp2;
    s32 temp1;
    s32 i;

    if (arg0 < 2) {
        numParts = 9;
    } else {
        numParts = 17;
    }

    bpPtr->init = light_rays_init;
    bpPtr->update = light_rays_update;
    bpPtr->renderWorld = light_rays_render;
    bpPtr->unk_00 = 0;
    bpPtr->unk_14 = NULL;
    bpPtr->effectID = EFFECT_LIGHT_RAYS;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.lightRays = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.lightRays != NULL);

    part->unk_00 = arg0;
    part->unk_28 = 100;
    part->unk_2C = 0;
    part->unk_10 = arg1;
    part->unk_14 = arg2;
    part->unk_18 = arg3;
    part->unk_20 = arg4;
    part->unk_1C = arg4;

    switch (arg0) {
        case 0:
        case 1:
            part++;
            for (i = 1; i < effect->numParts; i++, part++) {
                temp1 = (i - 1) * 30 / (numParts - 1);
                temp2 = (i - 1) * 20 / (numParts - 1);

                part->unk_68 = temp1 - 10;
                part->unk_7C = 50 - temp2;
                part->unk_6C = 25.0f / part->unk_7C + 2.5;

                func_E006A000(part, i);
            }
            break;
        default:
            part++;
            for (i = 1; i < effect->numParts; i++, part++) {
                func_E006A0BC(part, i);
            }
    }

    *outEffect = effect;
}

void light_rays_init(EffectInstance* effect) {
}

void func_E006A464(LightRaysFXData* part) {
    part->unk_34 += part->unk_48;
    if (part->unk_34 > 256.0f) {
        part->unk_34 -= 256.0f;
    }
    if (part->unk_34 < 0.0f) {
        part->unk_34 += 256.0f;
    }

    part->unk_3C += part->unk_50;
    if (part->unk_3C > 256.0f) {
        part->unk_3C -= 256.0f;
    }
    if (part->unk_3C < 0.0f) {
        part->unk_3C += 256.0f;
    }

    part->unk_38 += part->unk_4C;
    if (part->unk_38 > 256.0f) {
        part->unk_38 -= 256.0f;
    }
    if (part->unk_38 < 0.0f) {
        part->unk_38 += 256.0f;
    }

    part->unk_40 += part->unk_54;
    if (part->unk_40 > 256.0f) {
        part->unk_40 -= 256.0f;
    }
    if (part->unk_40 < 0.0f) {
        part->unk_40 += 256.0f;
    }
}

void light_rays_update(EffectInstance* effect) {
    LightRaysFXData* part = effect->data.lightRays;
    s32 unk_00 = part->unk_00;
    s32 unk_28;
    s32 unk_2C;
    s32 i;

    if (part->unk_28 < 11) {
        part->unk_28--;
    }

    part->unk_2C++;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        part->unk_28 = 10;
    }

    if (part->unk_28 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_28 = part->unk_28;
    unk_2C = part->unk_2C;

    switch (unk_00) {
        case 0:
        case 1:
            part++;
            for (i = 1; i < effect->numParts; i++, part++) {
                part->unk_28--;
                part->unk_2C++;
                if (part->unk_2C < 10) {
                    part->unk_24 = part->unk_2C * 12;
                }
                if (part->unk_28 < 5) {
                    part->unk_24 = part->unk_28 * 25;
                }
                part->unk_58 += part->unk_8C;
                if (part->unk_28 <= 0) {
                    func_E006A000(part, unk_2C * 10 + 1);
                }
            }
            break;
        default:
            part++;
            for (i = 1; i < effect->numParts; i++, part++) {
                func_E006A464(part);
                part->unk_28--;
                part->unk_2C++;
                if (part->unk_2C < 5) {
                    part->unk_24 = part->unk_2C * 50;
                }
                if (part->unk_28 < 5) {
                    part->unk_24 = part->unk_28 * 50;
                }
                if (unk_28 < 10) {
                    part->unk_24 = (part->unk_24 * unk_28) / 10;
                }
                if (part->unk_28 <= 0) {
                    func_E006A0BC(part, i);
                }
                if (part->unk_90 <= 0 || --part->unk_90 <= 0) {
                    part->unk_5C += part->unk_80;
                    part->unk_60 += part->unk_84;
                    part->unk_64 += part->unk_88;
                }
            }
    }
}

void light_rays_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = light_rays_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E006A85C(LightRaysFXData* part) {
    s32 uls = part->unk_34 * 4.0f;
    s32 ult = part->unk_38 * 4.0f;
    s32 uls2 = part->unk_3C * 4.0f;
    s32 ult2 = part->unk_40 * 4.0f;

    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, uls, ult, uls + 512, ult + 256);
    gDPSetTileSize(gMasterGfxPos++, 1, uls2, ult2, uls2 + 512, ult2 + 256);
}

void light_rays_appendGfx(void* effect) {
    LightRaysFXData* part = ((EffectInstance*)effect)->data.lightRays;
    s32 unk_00 = part->unk_00;
    Gfx* dlist = D_E006ADF0[unk_00];
    Gfx* dlist2 = D_E006AE00[unk_00];
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, dlist2);

    shim_guTranslateF(sp98, part->unk_10, part->unk_14, part->unk_18);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        f32 temp = part->unk_24 / 255.0f;
        f32 rotateA;
        f32 scaleX;
        f32 scaleY;
        f32 scaleZ;
        f32 unk_64;

        if (unk_00 >= 2) {
            func_E006A85C(part);
        }

        shim_guRotateF(sp58, part->unk_5C, 1.0f, 0.0f, 0.0f);
        shim_guMtxCatF(sp58, sp98, sp18);

        if (unk_00 >= 2) {
            unk_64 = part->unk_64;
            if (unk_00 == 3) {
                rotateA = unk_64 + 45.0f;
            } else {
                rotateA = unk_64 + 0.0f;
            }

            shim_guRotateF(sp58, rotateA, 0.0f, 0.0f, 1.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guRotateF(sp58, part->unk_60, 0.0f, 1.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guTranslateF(sp58, part->unk_58, 0.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);

            scaleX = scaleZ = (temp + 3.0f) * 0.25;
            switch (i & 3) {
                case 0:
                    scaleY = temp * 0.3;
                    break;
                case 1:
                    scaleY = temp * 0.5;
                    break;
                case 2:
                    scaleY = temp * 0.9;
                    break;
                case 3:
                default:
                    scaleY = temp;
                    break;
            }

            shim_guScaleF(sp58, scaleX, scaleY, scaleZ);
            shim_guMtxCatF(sp58, sp18, sp18);

            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 240, part->unk_24);
        } else {
            shim_guRotateF(sp58, part->unk_60, 0.0f, 1.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guRotateF(sp58, part->unk_64, 0.0f, 0.0f, 1.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guTranslateF(sp58, part->unk_58, 0.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);

            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 181, part->unk_24);
        }

        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, dlist);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMasterGfxPos++);
}
