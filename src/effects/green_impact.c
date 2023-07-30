#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000540_365EF0[];
extern Gfx D_090005A0_365F50[];

Gfx* D_E0064A60[] = { D_090005A0_365F50, D_090005A0_365F50 };

void green_impact_init(EffectInstance* effect);
void green_impact_update(EffectInstance* effect);
void green_impact_render(EffectInstance* effect);
void green_impact_appendGfx(void* effect);

EffectInstance* green_impact_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    GreenImpactFXData* part;
    s32 numParts;
    s32 temp;
    s32 i;

    if (arg0 == 0) {
        numParts = 4;
    } else {
        temp = 1; // Required to match
        numParts = temp;
    }
    numParts++;

    bpPtr->unk_00 = 0;
    bpPtr->init = green_impact_init;
    bpPtr->update = green_impact_update;
    bpPtr->renderWorld = green_impact_render;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_GREEN_IMPACT;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.greenImpact = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.greenImpact != NULL);

    mem_clear(part, numParts * sizeof(*part));

    part->unk_2C = 0;
    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_28 = 60;
    part->unk_38 = 255;
    part->unk_50.r = 0;
    part->unk_50.g = 255;
    part->unk_50.b = 122;
    part->unk_53.r = 240;
    part->unk_53.g = 255;
    part->unk_53.b = 250;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_4C = -1 + (i - 1) * (-4);
        part->unk_34 = arg4;
        part->unk_30 = i * 30;
    }

    return effect;
}

void green_impact_init(EffectInstance* effect) {
}

void green_impact_update(EffectInstance* effect) {
    GreenImpactFXData* part = effect->data.greenImpact;
    s32 i;

    part->unk_2C++;
    part->unk_28--;

    if (part->unk_28 < 0) {
        remove_effect(effect);
        return;
    }

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
                part->unk_20 = 10.0f;
                part->unk_3C = 32.0f;
                part->unk_40 = 32.0f;
                part->unk_48 = 32.0f;
                part->unk_1C = 0.5f;
                part->unk_24 = 0.5f;
                part->unk_44 = 32.0f;
            }
            part->unk_3C += part->unk_40;
            part->unk_40 *= 0.9;
            part->unk_44 += part->unk_48;
            part->unk_1C += 0.2;
            part->unk_20 += (0.1 - part->unk_20) * 0.2;
            part->unk_24 += 0.2;
            if (part->unk_3C > 128.0f) {
                part->unk_3C = 128.0f;
            }
        }
    }
}

void green_impact_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = green_impact_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = queue_render_task(&renderTask);
}

void green_impact_appendGfx(void* effect) {
    GreenImpactFXData* part = ((EffectInstance*)effect)->data.greenImpact;
    Gfx* dlist = D_E0064A60[part->unk_00];
    Gfx* dlist2;
    s32 alpha;
    s32 primR;
    s32 primG;
    s32 primB;
    s32 envR;
    s32 envG;
    s32 envB;
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

    primR = part->unk_50.r;
    primG = part->unk_50.g;
    primB = part->unk_50.b;
    envR = part->unk_53.r;
    envG = part->unk_53.g;
    envB = part->unk_53.b;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
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
    savedGfxPos2 = gMainGfxPos;

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_4C >= 0) {
            guTranslateF(sp20, part->unk_04, part->unk_08, part->unk_0C);
            guRotateF(sp60, part->unk_34, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guScaleF(sp60, part->unk_1C * 0.3, part->unk_20 * 0.3, part->unk_24 * 0.3);
            guMtxCatF(sp60, sp20, sp20);
            guRotateF(sp60, part->unk_30, 0.0f, 1.0f, 0.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            dlist2 = D_09000540_365EF0;

            gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, (s32) part->unk_3C, 252, (s32) part->unk_3C + 124);
            gDPSetTileSize(gMainGfxPos++, 1, 0, (s32) part->unk_44, 124, (s32) part->unk_44 + 124);
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
