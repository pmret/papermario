#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000940_359CF0[];
extern Gfx D_090009A0_359D50[];
extern Gfx D_09000A80_359E30[];

Gfx* D_E004AE60[] = {
    D_090009A0_359D50, D_090009A0_359D50, D_09000A80_359E30,
    D_09000A80_359E30, D_09000A80_359E30, D_09000A80_359E30
};

void shockwave_init(EffectInstance* effect);
void shockwave_update(EffectInstance* effect);
void shockwave_render(EffectInstance* effect);
void shockwave_appendGfx(void* effect);

void shockwave_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    ShockwaveFXData* part;
    f32 zero = 0.0f;
    s32 numParts;
    s32 i;

    switch (arg0) {
        case 0:
            arg0 = 3;
            break;
        case 1:
            arg0 = 2;
            break;
        case 2:
            arg0 = 4;
            break;
        default:
            arg0 = 5;
            break;
    }

    switch (arg0) {
        case 1:
            numParts = 1;
            break;
        case 0:
        case 2:
        case 5:
            numParts = 3;
            break;
        default:
            numParts = 2;
            break;
    }

    numParts++;

    bpPtr->init = shockwave_init;
    bpPtr->update = shockwave_update;
    bpPtr->renderScene = shockwave_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = nullptr;
    bpPtr->effectID = EFFECT_SHOCKWAVE;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.shockwave = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.shockwave != nullptr);

    mem_clear(part, numParts * sizeof(*part));

    if (arg0 >= 2) {
        part->unk_28 = 60;
    } else {
        part->unk_28 = 30;
    }
    part->alpha = 255;
    part->unk_2C = 0;
    part->unk_00 = arg0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;

    switch (arg0) {
        case 0:
        case 1:
            part->prim.r = 0;
            part->prim.g = 255;
            part->prim.b = 122;
            part->env.r = 240;
            part->env.g = 255;
            part->env.b = 250;
            break;
        case 2:
            part->prim.r = 125;
            part->prim.g = 120;
            part->prim.b = 100;
            part->env.r = 255;
            part->env.g = 255;
            part->env.b = 240;
            break;
        case 3:
            part->prim.r = 220;
            part->prim.g = 210;
            part->prim.b = 200;
            part->env.r = 255;
            part->env.g = 255;
            part->env.b = 250;
            break;
        case 5:
            part->prim.r = 225;
            part->prim.g = 204;
            part->prim.b = 93;
            part->env.r = 232;
            part->env.g = 231;
            part->env.b = 171;
            break;
        default:
            part->unk_28 = 50;
            part->prim.r = 208;
            part->prim.g = 136;
            part->prim.b = 40;
            part->env.r = 216;
            part->env.g = 169;
            part->env.b = 65;
            break;
    }

    part++;
    for (i = 1; i < numParts; i++, part++) {
        switch (arg0) {
            case 0:
            case 1:
                part->unk_4C = 1 + i * -2;
                break;
            default:
                part->unk_4C = 2 + i * -3;
                break;
        }
        part->unk_34 = zero;
        part->unk_30 = i * 30;
    }
}

void shockwave_init(EffectInstance* effect) {
}

void shockwave_update(EffectInstance* effect) {
    ShockwaveFXData* part = effect->data.shockwave;
    s32 unk_00;
    s32 unk_2C;
    s32 i;

    part->unk_2C++;
    part->unk_28--;

    if (part->unk_28 < 0) {
        remove_effect(effect);
        return;
    }

    unk_00 = part->unk_00;
    unk_2C = part->unk_2C;

    switch (unk_00) {
        case 0:
        case 1:
            if (unk_2C >= 8) {
                part->alpha *= 0.8;
            }
            break;
        default:
            if (unk_2C >= 8) {
                part->alpha *= 0.94;
            }
            break;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_4C++;
        if (part->unk_4C >= 0) {
            if (part->unk_4C == 0) {
                part->pos.x = 0.0f;
                part->pos.y = 0.0f;
                part->pos.z = 0.0f;
                part->unk_10 = -sin_deg(part->unk_34) * 0.5;
                part->unk_14 = cos_deg(part->unk_34) * 0.5;
                part->unk_18 = 0;
                part->unk_3C = 32.0f;
                part->unk_40 = 32.0f;
                part->unk_48 = 32.0f;
                part->unk_20 = 8.0 - (f32) i;

                switch (unk_00) {
                    case 0:
                    case 1:
                        part->unk_1C = i + 0.5;
                        part->unk_24 = (i + 0.5) * 0.5;
                        break;
                    case 2:
                    case 5:
                        part->unk_1C = i + 2;
                        part->unk_24 = (i + 2) * 0.5;
                        break;
                    case 3:
                        part->unk_1C = i + 3;
                        part->unk_24 = (i + 3) * 0.5;
                        part->unk_3C = 16.0f;
                        part->unk_40 = 16.0f;
                        part->unk_48 = 16.0f;
                        break;
                    case 4:
                    default:
                        part->unk_1C = (i + 3) * 0.5;
                        part->unk_24 = (i + 3) * 0.5 * 0.5;
                        part->unk_3C = 16.0f;
                        part->unk_40 = 16.0f;
                        part->unk_48 = 16.0f;
                        part->unk_20 *= 0.8;
                        break;
                }

                part->unk_44 = 32.0f;
            }

            part->unk_3C += part->unk_40;
            part->unk_44 += part->unk_48;

            switch (unk_00) {
                case 0:
                case 1:
                    part->unk_40 *= 0.9;
                    break;
                case 2:
                case 5:
                    part->unk_40 *= 0.75;
                    part->unk_48 *= 0.99;
                    break;
                default:
                    part->unk_40 *= 0.75;
                    part->unk_48 *= 0.95;
                    break;
            }

            part->unk_1C *= 1.002;
            part->unk_24 *= 1.002;
            if (part->unk_3C > 128.0f) {
                part->unk_3C = 128.0f;
            }
        }
    }
}

void shockwave_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shockwave_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void shockwave_appendGfx(void* effect) {
    ShockwaveFXData* data = ((EffectInstance*) effect)->data.shockwave;
    Matrix4f sp20, sp60;
    Gfx* dlist = D_09000940_359CF0;
    Gfx* dlist2;
    s32 primA;
    s32 primR, primG, primB;
    s32 envR, envG, envB;
    s32 primR2, primG2, primB2;
    s32 envR2, envG2, envB2;
    Gfx* savedGfxPos;
    Gfx* savedGfxPos2;
    s32 temp_v0;
    s32 i;

    primR = data->prim.r;
    primG = data->prim.g;
    primB = data->prim.b;
    envR = data->env.r;
    envG = data->env.g;
    envB = data->env.b;
    primR2 = data->prim.r;
    primG2 = data->prim.g;
    primB2 = data->prim.b;
    envR2 = data->env.r;
    envG2 = data->env.g;
    envB2 = data->env.b;

    temp_v0 = data->unk_00;
    dlist2 = D_E004AE60[temp_v0];

    if (temp_v0 >= 2) {
        primR2 = primR >> 2;
        primG2 = primG >> 2;
        primB2 = primB >> 2;
        envR2 = envR >> 2;
        envG2 = envG >> 2;
        envB2 = envB >> 2;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, dlist2);

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f,
                     data->pos.x, data->pos.y, data->pos.z);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    primA = data->alpha;

    savedGfxPos = gMainGfxPos;
    gMainGfxPos++;
    savedGfxPos2 = gMainGfxPos;

    data++;
    for (i = 1; i < ((EffectInstance*) effect)->numParts; i++, data++) {
        if (data->unk_4C >= 0) {
            guTranslateF(sp20, data->pos.x, data->pos.y, data->pos.z);
            guRotateF(sp60, data->unk_34, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guScaleF(sp60, data->unk_1C * 0.3, data->unk_20 * 0.3, data->unk_24 * 0.3);
            guMtxCatF(sp60, sp20, sp20);
            guRotateF(sp60, data->unk_30, 0.0f, 1.0f, 0.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, (s32) data->unk_3C, 0x00FC, (s32) data->unk_3C + 0x7C);
            gDPSetTileSize(gMainGfxPos++, 1, 0, (s32) data->unk_44, 0x007C, (s32) data->unk_44 + 0x7C);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, dlist);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gSPEndDisplayList(gMainGfxPos++);
    gSPBranchList(savedGfxPos, gMainGfxPos);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, primR2, primG2, primB2, primA);
    gDPSetEnvColor(gMainGfxPos++, envR2, envG2, envB2, 0);
    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_CULL_FRONT);
    gSPDisplayList(gMainGfxPos++, savedGfxPos2);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, primR, primG, primB, primA);
    gDPSetEnvColor(gMainGfxPos++, envR, envG, envB, 0);
    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_CULL_BACK);
    gSPDisplayList(gMainGfxPos++, savedGfxPos2);
    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_DISABLE);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
