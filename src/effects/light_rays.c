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
      0,  -20,    0,   1,  18,
    -10,  -60,   45,  -1,   4,
    -20,  -20,   90,   1,   1,
    -10,  -60,  135,   1,  -4,
      0,  -20,  180,  -8,   1,
    -10,  -60,  225,  -1,  -1,
    -20,  -20,  270,   1,  -9,
    -10,  -60,  315,   4,   4,
      0,   10,   22,   4,   1,
    -10,   20,   67,   1,  -1,
    -20,   10,  112,  -1,  -1,
    -10,   20,  157,  -8,   1,
      0,   10,  202,   1,  -4,
    -10,   20,  247,   1, -18,
    -20,   10,  292,  -1,   9,
    -10,   20,  337,   1,   1
};

void light_rays_init(EffectInstance* effect);
void light_rays_update(EffectInstance* effect);
void light_rays_render(EffectInstance* effect);
void light_rays_appendGfx(void* effect);

void func_E006A000(LightRaysFXData* part, s32 beamIdx) {
    s32 temp = beamIdx * 3;

    part->initialRot.x = func_E0200044(180, temp);
    part->initialRot.y = func_E0200044(180, temp + 1);
    part->initialRot.z = func_E0200044(180, temp + 2);
    part->alpha = 0;
    part->lifetime = 0;
    part->unk_58 = part->unk_68;
    part->timeLeft = part->unk_7C;
    part->unk_8C = part->unk_6C;
    part->rot.x = part->initialRot.x;
    part->rot.y = part->initialRot.y;
    part->rot.z = part->initialRot.z;
}

void func_E006A0BC(LightRaysFXData* part, s32 beamIdx) {
    s32 idx = (beamIdx - 1) * 5;

    part->unk_58 = 0;
    part->timeLeft = beamIdx * 2 + 30;
    part->rot.x = D_E006AE10[idx++];
    part->rot.y = D_E006AE10[idx++];
    part->rot.z = D_E006AE10[idx++];
    part->alpha = 0;
    part->lifetime = 0;
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
    s32 type,
    f32 posX,
    f32 posY,
    f32 posZ,
    f32 scale,
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

    if (type < 2) {
        numParts = 9;
    } else {
        numParts = 17;
    }

    bpPtr->init = light_rays_init;
    bpPtr->update = light_rays_update;
    bpPtr->renderWorld = light_rays_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_LIGHT_RAYS;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.lightRays = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.lightRays != NULL);

    part->type = type;
    part->timeLeft = 100;
    part->lifetime = 0;
    part->pos.x = posX;
    part->pos.y = posY;
    part->pos.z = posZ;
    part->unk_1C = part->unk_20 = scale;

    switch (type) {
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
    s32 type = part->type;
    s32 timeLeft;
    s32 lifetime;
    s32 i;

    if (part->timeLeft < 11) {
        part->timeLeft--;
    }

    part->lifetime++;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->timeLeft = 10;
    }

    if (part->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    timeLeft = part->timeLeft;
    lifetime = part->lifetime;

    switch (type) {
        case 0:
        case 1:
            part++;
            for (i = 1; i < effect->numParts; i++, part++) {
                part->timeLeft--;
                part->lifetime++;
                if (part->lifetime < 10) {
                    part->alpha = part->lifetime * 12;
                }
                if (part->timeLeft < 5) {
                    part->alpha = part->timeLeft * 25;
                }
                part->unk_58 += part->unk_8C;
                if (part->timeLeft <= 0) {
                    func_E006A000(part, lifetime * 10 + 1);
                }
            }
            break;
        default:
            part++;
            for (i = 1; i < effect->numParts; i++, part++) {
                func_E006A464(part);
                part->timeLeft--;
                part->lifetime++;
                if (part->lifetime < 5) {
                    part->alpha = part->lifetime * 50;
                }
                if (part->timeLeft < 5) {
                    part->alpha = part->timeLeft * 50;
                }
                if (timeLeft < 10) {
                    part->alpha = (part->alpha * timeLeft) / 10;
                }
                if (part->timeLeft <= 0) {
                    func_E006A0BC(part, i);
                }
                if (part->unk_90 <= 0 || --part->unk_90 <= 0) {
                    part->rot.x += part->unk_80;
                    part->rot.y += part->unk_84;
                    part->rot.z += part->unk_88;
                }
            }
    }
}

void light_rays_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = light_rays_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E006A85C(LightRaysFXData* part) {
    s32 uls = part->unk_34 * 4.0f;
    s32 ult = part->unk_38 * 4.0f;
    s32 uls2 = part->unk_3C * 4.0f;
    s32 ult2 = part->unk_40 * 4.0f;

    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, uls, ult, uls + 512, ult + 256);
    gDPSetTileSize(gMainGfxPos++, 1, uls2, ult2, uls2 + 512, ult2 + 256);
}

void light_rays_appendGfx(void* effect) {
    LightRaysFXData* part = ((EffectInstance*)effect)->data.lightRays;
    s32 type = part->type;
    Gfx* dlist = D_E006ADF0[type];
    Gfx* dlist2 = D_E006AE00[type];
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    Matrix4f mtxTranslate;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, dlist2);

    guTranslateF(mtxTranslate, part->pos.x, part->pos.y, part->pos.z);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        f32 temp = part->alpha / 255.0f;
        f32 angleZ;
        f32 scaleX;
        f32 scaleY;
        f32 scaleZ;
        f32 unk_64;

        if (type >= 2) {
            func_E006A85C(part);
        }

        guRotateF(mtxTemp, part->rot.x, 1.0f, 0.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTranslate, mtxTransform);

        if (type >= 2) {
            unk_64 = part->rot.z;
            if (type == 3) {
                angleZ = unk_64 + 45.0f;
            } else {
                angleZ = unk_64 + 0.0f;
            }

            guRotateF(mtxTemp, angleZ, 0.0f, 0.0f, 1.0f);
            guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
            guRotateF(mtxTemp, part->rot.y, 0.0f, 1.0f, 0.0f);
            guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
            guTranslateF(mtxTemp, part->unk_58, 0.0f, 0.0f);
            guMtxCatF(mtxTemp, mtxTransform, mtxTransform);

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

            guScaleF(mtxTemp, scaleX, scaleY, scaleZ);
            guMtxCatF(mtxTemp, mtxTransform, mtxTransform);

            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 240, part->alpha);
        } else {
            guRotateF(mtxTemp, part->rot.y, 0.0f, 1.0f, 0.0f);
            guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
            guRotateF(mtxTemp, part->rot.z, 0.0f, 0.0f, 1.0f);
            guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
            guTranslateF(mtxTemp, part->unk_58, 0.0f, 0.0f);
            guMtxCatF(mtxTemp, mtxTransform, mtxTransform);

            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 181, part->alpha);
        }

        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMainGfxPos++);
}
