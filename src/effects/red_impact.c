#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000940_359CF0[];
extern Gfx D_090009A0_359D50[];

Gfx* D_E00D0B10[] = { D_090009A0_359D50, D_090009A0_359D50 };

void red_impact_init(EffectInstance* effect);
void red_impact_update(EffectInstance* effect);
void red_impact_render(EffectInstance* effect);
void red_impact_appendGfx(void* effect);

EffectInstance* red_impact_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    RedImpactFXData* part;
    f32 zero = 0.0f;
    s32 numParts;
    s32 temp;
    s32 i;

    if (arg0 == 0) {
        numParts = 7;
    } else {
        temp = 3; // Required to match
        numParts = temp;
    }
    numParts++;

    bpPtr->unk_00 = 0;
    bpPtr->init = red_impact_init;
    bpPtr->update = red_impact_update;
    bpPtr->renderScene = red_impact_render;
    bpPtr->renderUI = nullptr;
    bpPtr->effectID = EFFECT_RED_IMPACT;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.redImpact = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.redImpact != nullptr);

    part->unk_2C = 0;
    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_24 = arg4;
    part->unk_20 = arg4;
    part->unk_1C = arg4;
    part->unk_28 = 60;
    part->unk_38 = 255;
    part->unk_50.r = 255;
    part->unk_50.g = 0;
    part->unk_50.b = 0;
    part->unk_53.r = 255;
    part->unk_53.g = 200;
    part->unk_53.b = 100;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_4C = -1 + (i - 1) * (-2);
        part->unk_34 = zero;
        part->unk_30 = i * 30;
    }

    return effect;
}

void red_impact_init(EffectInstance* effect) {
}

void red_impact_update(EffectInstance* effect) {
    RedImpactFXData* part = effect->data.redImpact;
    s32 unk_00;
    s32 i;

    part->unk_2C++;
    part->unk_28--;

    if (part->unk_28 < 0) {
        remove_effect(effect);
        return;
    }

    unk_00 = part->unk_00;

    if (part->unk_2C >= 8) {
        part->unk_38 *= 0.8;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_4C++;
        if (part->unk_4C >= 0) {
            if (part->unk_4C == 0) {
                part->unk_04 = 0;
                part->unk_08 = 0;
                part->unk_0C = 0;
                part->unk_10 = -sin_deg(part->unk_34) * 0.5;
                part->unk_14 = cos_deg(part->unk_34) * 0.5;
                part->unk_18 = 0;
                part->unk_3C = 32.0f;
                part->unk_40 = 32.0f;
                part->unk_48 = 32.0f;
                part->unk_20 = 8.0 - (f32) i;
                if (unk_00 == 0) {
                    part->unk_1C = 2 + i * 2;
                    part->unk_24 = (2 + i * 2) * 0.5;
                } else {
                    part->unk_1C = i + 0.5;
                    part->unk_20 *= 0.6;
                    part->unk_24 = (i + 0.5) * 0.5;
                }
                part->unk_44 = 32.0f;
            }
            part->unk_3C += part->unk_40;
            part->unk_44 += part->unk_48;
            part->unk_40 *= 0.9;
            part->unk_1C *= 1.002;
            part->unk_24 *= 1.002;
            if (part->unk_3C > 128.0f) {
                part->unk_3C = 128.0f;
            }
        }
    }
}

void red_impact_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = red_impact_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void red_impact_appendGfx(void* effect) {
    RedImpactFXData* part = ((EffectInstance*)effect)->data.redImpact;
    Gfx* dlist = D_E00D0B10[part->unk_00];
    Gfx* dlist2;
    f32 temp_1C = part->unk_1C * 0.3;
    f32 temp_20 = part->unk_20 * 0.3;
    f32 temp_24 = part->unk_24 * 0.3;
    s32 alpha;
    s32 primR = part->unk_50.r;
    s32 primG = part->unk_50.g;
    s32 primB = part->unk_50.b;
    s32 envR = part->unk_53.r;
    s32 envG = part->unk_53.g;
    s32 envB = part->unk_53.b;
    s32 primR2;
    s32 primG2;
    s32 primB2;
    s32 envR2;
    s32 envG2;
    s32 envB2;
    Gfx* savedGfxPos;
    Gfx* savedGfxPos2;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, dlist);

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, part->unk_04, part->unk_08, part->unk_0C);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    alpha = part->unk_38;
    primR2 = primR;
    primG2 = primG;
    primB2 = primB;
    envR2 = envR;
    envG2 = envG;
    envB2 = envB;

    savedGfxPos = gMainGfxPos;
    gMainGfxPos++;
    savedGfxPos2 = savedGfxPos + 1;

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_4C >= 0) {
            guTranslateF(sp20, part->unk_04, part->unk_08, part->unk_0C);
            guRotateF(sp60, part->unk_34, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guScaleF(sp60, part->unk_1C * temp_1C, part->unk_20 * temp_20, part->unk_24 * temp_24);
            guMtxCatF(sp60, sp20, sp20);
            guRotateF(sp60, part->unk_30, 0.0f, 1.0f, 0.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            dlist2 = D_09000940_359CF0;

            gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, (s32) part->unk_3C, 0x00FC, (s32) part->unk_3C + 0x7C);
            gDPSetTileSize(gMainGfxPos++, 1, 0, (s32) part->unk_44, 0x007C, (s32) part->unk_44 + 0x7C);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, dlist2);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPEndDisplayList(gMainGfxPos++);
    gSPBranchList(savedGfxPos, gMainGfxPos);

    gDPSetPrimColor(gMainGfxPos++, 0, 0, primR2, primG2, primB2, alpha);
    gDPSetEnvColor(gMainGfxPos++, envR2, envG2, envB2, 0);
    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_CULL_FRONT);
    gSPDisplayList(gMainGfxPos++, savedGfxPos2);

    gDPSetPrimColor(gMainGfxPos++, 0, 0, primR, primG, primB, alpha);
    gDPSetEnvColor(gMainGfxPos++, envR, envG, envB, 0);
    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_CULL_BACK);
    gSPDisplayList(gMainGfxPos++, savedGfxPos2);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
