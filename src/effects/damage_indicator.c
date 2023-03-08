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
void func_E003C47C(EffectInstance* effect);
void func_E003C498(EffectInstance* effect);

void damage_indicator_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 numParts, EffectInstance** effectOut) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    f32 temp_f20;
    DamageIndicatorFXData* part;
    s32 origNumParts = numParts;
    s32 i;

    if (numParts > 20) {
        numParts = 20;
    }
    numParts++;

    bp.init = damage_indicator_init;
    bp.update = damage_indicator_update;
    bp.renderWorld = damage_indicator_render;
    bp.unk_14 = func_E003C47C;
    bp.unk_00 = 0;
    bp.effectID = EFFECT_DAMAGE_INDICATOR;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;

    effect->data.damageIndicator = part = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.damageIndicator != NULL);

    part->unk_00 = arg0;
    part->unk_04.x = arg1;
    part->unk_04.y = arg2;
    part->unk_04.z = arg3;
    part->unk_28 = arg4;
    part->effectDurationTimer = 100;
    part->unk_34 = 0;
    part->numParts = origNumParts;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_04.x = 0.0f;
        part->unk_04.y = 0.0f;
        part->unk_04.z = 0.0f;
        part->unk_10.x = part->unk_04.x;
        part->unk_10.y = part->unk_04.y;
        part->unk_10.z = part->unk_04.z;
        temp_f20 = arg5 + (((s32) ((((i % 2) * 2) - 1) * i) / 2) * (30.0f - numParts));
        part->unk_38 = 0.2f;
        part->unk_1C.x = -shim_sin_deg(temp_f20) * arg4 * 1.5;
        part->unk_1C.y = shim_cos_deg(temp_f20) * arg4 * 1.5;
        part->unk_1C.z = 0;
        part->alpha = 255;
    }
    *effectOut = effect;
}

void damage_indicator_init(EffectInstance* effect) {
}

void damage_indicator_update(EffectInstance* effect) {
    s32 temp_a2;
    s32 temp_t0;
    s32 duration;
    DamageIndicatorFXData* part = effect->data.damageIndicator;
    f32 phi_f12;
    s32 i;

    /* decrement duration timer */
    if (part->effectDurationTimer < 100) {
        part->effectDurationTimer--;
    }

    temp_a2 = part->unk_34++;
    temp_t0 = part->unk_34;
    duration = part->effectDurationTimer;

    /* if duration is less than 0, remove effect */
    if (duration < 0) {
        shim_remove_effect(effect);
        return;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        f32 x, y, z;

        if (duration > 5) {
            part->unk_1C.x = part->unk_1C.x * 0.75;
            part->unk_1C.y = part->unk_1C.y * 0.75;
            part->unk_1C.z = part->unk_1C.z * 0.75;
        }
        if (duration < 5) {
            part->alpha = part->alpha * 0.6;
            part->unk_1C.x = part->unk_1C.x * 0.7;
            part->unk_1C.y = part->unk_1C.y * 0.7;
            part->unk_1C.z = part->unk_1C.z * 0.7;
        }
        phi_f12 = 1.0f;
        if (temp_a2 < 9) {
            phi_f12 = D_E003CD1C[temp_a2];
        }
        part->unk_10.x = part->unk_04.x * phi_f12;
        part->unk_10.y = part->unk_04.y * phi_f12;
        part->unk_10.z = part->unk_04.z * phi_f12;
        part->unk_04.x += part->unk_1C.x;
        part->unk_04.y += part->unk_1C.y;
        part->unk_04.z += part->unk_1C.z;

        part->unk_38 = (temp_t0 <= 40) ? (f32)D_E003CCD0[temp_a2] * 0.01 : 0.0f;
    }
}

void damage_indicator_render(EffectInstance* effect) {
}

void func_E003C47C(EffectInstance* effect) {
    func_E003C498(effect);
}

void func_E003C498(EffectInstance* effect) {
    DamageIndicatorFXData* part = effect->data.damageIndicator;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 spA0;
    s32 lastPartIdx;
    s32 numParts = part->numParts;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));

    shim_guTranslateF(sp20, part->unk_04.x, part->unk_04.y, part->unk_04.z);
    shim_guRotateF(sp60, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    spA0 = part->unk_34 - 1;
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
            shim_guPositionF(sp20, 0.0f, 0.0f, 0.0f, part->unk_38, part->unk_10.x, part->unk_10.y, part->unk_10.z);
            shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_09002150_352370);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

            shim_guPositionF(sp20, 0.0f, 0.0f, 0.0f, part->unk_38, (part->unk_10.x + part->unk_04.x) * 0.5, (part->unk_10.y + part->unk_04.y) * 0.5, (part->unk_10.z + part->unk_04.z) * 0.5);
            shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_09002160_352380);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }

        gSPDisplayList(gMainGfxPos++, D_09001D40_351F60);

        shim_guTranslateF(sp20, part->unk_04.x, part->unk_04.y, part->unk_04.z);
        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        shim_guScaleF(sp20, part->unk_38, part->unk_38, 1.0f);
        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

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
                s32 temp = numParts % 10;
                s32 temp2 = numParts / 10;
                gSPDisplayList(gMainGfxPos++, D_E003CCA0[temp]);
                gSPDisplayList(gMainGfxPos++, D_09002200_352420);
                gSPDisplayList(gMainGfxPos++, D_E003CCA0[temp2]);
                gSPDisplayList(gMainGfxPos++, D_090021E0_352400);
            }
        } else {
            gSPDisplayList(gMainGfxPos++, D_09002190_3523B0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }

        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
