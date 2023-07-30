#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001D40_351F60[];
extern Gfx D_09001DE0_352000[];
extern Gfx D_09001E50_352070[];
extern Gfx D_09001E90_3520B0[];
extern Gfx D_09001ED0_3520F0[];
extern Gfx D_09001F10_352130[];
extern Gfx D_09001F50_352170[];
extern Gfx D_09001F90_3521B0[];
extern Gfx D_09001FD0_3521F0[];
extern Gfx D_09002010_352230[];
extern Gfx D_09002050_352270[];
extern Gfx D_09002090_3522B0[];
extern Gfx D_090020D0_3522F0[];
extern Gfx D_09002110_352330[];
extern Gfx D_09002150_352370[];
extern Gfx D_09002160_352380[];
extern Gfx D_09002170_352390[];
extern Gfx D_09002180_3523A0[];
extern Gfx D_09002190_3523B0[];
extern Gfx D_090021A8_3523C8[];
extern Gfx D_090021C0_3523E0[];
extern Gfx D_090021E0_352400[];
extern Gfx D_09002200_352420[];

Gfx* D_E003CCA0[] = {
    D_09001E50_352070, D_09001E90_3520B0, D_09001ED0_3520F0, D_09001F10_352130,
    D_09001F50_352170, D_09001F90_3521B0, D_09001FD0_3521F0, D_09002010_352230,
    D_09002050_352270, D_09002090_3522B0, D_090020D0_3522F0, D_09002110_352330
};

u8 D_E003CCD0[] = {
  0x32, 0x37, 0x3C, 0x46, 0x50, 0x64, 0x96, 0xDC,
  0xF0, 0xC8, 0x8C, 0x64, 0x8C, 0xA0, 0x8C, 0x96,
  0x9B, 0x96, 0x94, 0x96, 0x96, 0x96, 0x96, 0x96,
  0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x9B, 0xA0,
  0x9B, 0x91, 0x82, 0x6E, 0x55, 0x37, 0x19, 0x00
};

u8 D_E003CCF8[] = {
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

f32 D_E003CD1C[] = {
    0.0f,
    0.1f,
    0.2f,
    0.3f,
    0.4f,
    0.5f,
    0.6f,
    0.7f,
    0.8f
};

void damage_indicator_init(EffectInstance* effect);
void damage_indicator_update(EffectInstance* effect);
void damage_indicator_render(EffectInstance* effect);
void damage_indicator_render_ui(EffectInstance* effect);
void damage_indicator_render_impl(EffectInstance* effect);

void damage_indicator_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 starsRadius, f32 starsAngle, s32 damageAmt, EffectInstance** effectOut) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    f32 angle;
    DamageIndicatorFXData* part;
    s32 trueDamageAmt = damageAmt;
    s32 i;

    // limit number of stars that can appear
    if (damageAmt > 20) {
        damageAmt = 20;
    }
    damageAmt++;

    bp.init = damage_indicator_init;
    bp.update = damage_indicator_update;
    bp.renderWorld = damage_indicator_render;
    bp.renderUI = damage_indicator_render_ui;
    bp.unk_00 = 0;
    bp.effectID = EFFECT_DAMAGE_INDICATOR;

    effect = create_effect_instance(bpPtr);
    effect->numParts = damageAmt;

    effect->data.damageIndicator = part = general_heap_malloc(damageAmt * sizeof(*part));
    ASSERT(effect->data.damageIndicator != NULL);

    part->unk_00 = arg0;
    part->basePos.x = posX;
    part->basePos.y = posY;
    part->basePos.z = posZ;
    part->radius = starsRadius;
    part->timeLeft = 100;
    part->lifetime = 0;
    part->damageAmt = trueDamageAmt;

    part++;
    for (i = 1; i < damageAmt; i++, part++) {
        part->basePos.x = 0.0f;
        part->basePos.y = 0.0f;
        part->basePos.z = 0.0f;
        part->curPos.x = part->basePos.x;
        part->curPos.y = part->basePos.y;
        part->curPos.z = part->basePos.z;
        angle = starsAngle + (((s32) ((((i % 2) * 2) - 1) * i) / 2) * (30.0f - damageAmt));
        part->scale = 0.2f;
        part->relPos.x = -sin_deg(angle) * starsRadius * 1.5;
        part->relPos.y = cos_deg(angle) * starsRadius * 1.5;
        part->relPos.z = 0;
        part->alpha = 255;
    }
    *effectOut = effect;
}

void damage_indicator_init(EffectInstance* effect) {
}

void damage_indicator_update(EffectInstance* effect) {
    DamageIndicatorFXData* part = effect->data.damageIndicator;
    s32 temp_a2;
    s32 temp_t0;
    s32 timeLeft;
    f32 phi_f12;
    s32 i;

    if (part->timeLeft < 100) {
        part->timeLeft--;
    }

    temp_a2 = part->lifetime++;
    temp_t0 = part->lifetime;
    timeLeft = part->timeLeft;

    if (timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        f32 x, y, z;

        if (timeLeft > 5) {
            part->relPos.x = part->relPos.x * 0.75;
            part->relPos.y = part->relPos.y * 0.75;
            part->relPos.z = part->relPos.z * 0.75;
        }
        if (timeLeft < 5) {
            part->alpha = part->alpha * 0.6;
            part->relPos.x = part->relPos.x * 0.7;
            part->relPos.y = part->relPos.y * 0.7;
            part->relPos.z = part->relPos.z * 0.7;
        }
        phi_f12 = 1.0f;
        if (temp_a2 < 9) {
            phi_f12 = D_E003CD1C[temp_a2];
        }
        part->curPos.x = part->basePos.x * phi_f12;
        part->curPos.y = part->basePos.y * phi_f12;
        part->curPos.z = part->basePos.z * phi_f12;
        part->basePos.x += part->relPos.x;
        part->basePos.y += part->relPos.y;
        part->basePos.z += part->relPos.z;

        if (temp_t0 <= 40) {
            part->scale = (f32)D_E003CCD0[temp_a2] * 0.01;
        } else {
            part->scale = 0.0f;
        }
    }
}

void damage_indicator_render(EffectInstance* effect) {
}

void damage_indicator_render_ui(EffectInstance* effect) {
    damage_indicator_render_impl(effect);
}

void damage_indicator_render_impl(EffectInstance* effect) {
    DamageIndicatorFXData* part = effect->data.damageIndicator;
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    s32 spA0;
    s32 lastPartIdx;
    s32 numParts = part->damageAmt;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));

    guTranslateF(mtxTransform, part->basePos.x, part->basePos.y, part->basePos.z);
    guRotateF(mtxTemp, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    spA0 = part->lifetime - 1;
    lastPartIdx = effect->numParts - 1;
    part = &(effect->data.damageIndicator)[effect->numParts - 1];

    if (part->alpha == 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
        gDPSetCombineLERP(gMainGfxPos++, 1, 0, SHADE, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 1, 0, SHADE, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineLERP(gMainGfxPos++, 1, 0, SHADE, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 1, 0, SHADE, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    }

    for(i = 1; i < effect->numParts; i++, part--) {
        s32 rIdx = ((i + spA0) % 12) * 3;

        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E003CCF8[rIdx], D_E003CCF8[rIdx + 1], D_E003CCF8[rIdx + 2], part->alpha);
        gSPDisplayList(gMainGfxPos++, D_09001D40_351F60);

        if (i == lastPartIdx) {
            guPositionF(mtxTransform, 0.0f, 0.0f, 0.0f, part->scale, part->curPos.x, part->curPos.y, part->curPos.z);
            guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_09002150_352370);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

            guPositionF(mtxTransform, 0.0f, 0.0f, 0.0f, part->scale,
                (part->curPos.x + part->basePos.x) * 0.5,
                (part->curPos.y + part->basePos.y) * 0.5,
                (part->curPos.z + part->basePos.z) * 0.5);
            guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_09002160_352380);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }

        gSPDisplayList(gMainGfxPos++, D_09001D40_351F60);

        guTranslateF(mtxTransform, part->basePos.x, part->basePos.y, part->basePos.z);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        guScaleF(mtxTransform, part->scale, part->scale, 1.0f);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        if (i == lastPartIdx) {
            gSPDisplayList(gMainGfxPos++, D_09002170_352390);
        } else {
            gSPDisplayList(gMainGfxPos++, D_09002180_3523A0);
        }

        if (i == lastPartIdx) {
            gSPDisplayList(gMainGfxPos++, D_090021A8_3523C8);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_09001DE0_352000);
            if (numParts < 10) {
                gSPDisplayList(gMainGfxPos++, D_E003CCA0[i]);
                gSPDisplayList(gMainGfxPos++, D_090021C0_3523E0);
            } else {
                s32 onesDigit = numParts % 10;
                s32 tensDigit = numParts / 10;
                gSPDisplayList(gMainGfxPos++, D_E003CCA0[onesDigit]); // GfxLoadDigitTex
                gSPDisplayList(gMainGfxPos++, D_09002200_352420); // GfxDrawOnesQuad
                gSPDisplayList(gMainGfxPos++, D_E003CCA0[tensDigit]);
                gSPDisplayList(gMainGfxPos++, D_090021E0_352400); // GfxDrawTensQuad
            }
        } else {
            gSPDisplayList(gMainGfxPos++, D_09002190_3523B0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }

        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
