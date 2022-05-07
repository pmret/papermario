#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001D40[];
extern Gfx D_09001DE0[];
extern Gfx D_09001E50[];
extern Gfx D_09001E90[];
extern Gfx D_09001ED0[];
extern Gfx D_09001F10[];
extern Gfx D_09001F50[];
extern Gfx D_09001F90[];
extern Gfx D_09001FD0[];
extern Gfx D_09002010[];
extern Gfx D_09002050[];
extern Gfx D_09002090[];
extern Gfx D_090020D0[];
extern Gfx D_09002110[];
extern Gfx D_09002150[];
extern Gfx D_09002160[];
extern Gfx D_09002170[];
extern Gfx D_09002180[];
extern Gfx D_090021A8[];
extern Gfx D_09002190[];
extern Gfx D_090021C0[];
extern Gfx D_090021E0[];
extern Gfx D_09002200[];

Gfx *D_E003CCA0[] = {
    D_09001E50, D_09001E90, D_09001ED0, D_09001F10,
    D_09001F50, D_09001F90, D_09001FD0, D_09002010,
    D_09002050, D_09002090, D_090020D0, D_09002110
};

u8 D_E003CCD0[] = {
  0x32, 0x37, 0x3C, 0x46, 0x50, 0x64, 0x96, 0xDC,
  0xF0, 0xC8, 0x8C, 0x64, 0x8C, 0xA0, 0x8C, 0x96,
  0x9B, 0x96, 0x94, 0x96, 0x96, 0x96, 0x96, 0x96,
  0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x9B, 0xA0,
  0x9B, 0x91, 0x82, 0x6E, 0x55, 0x37, 0x19, 0x00
};

Color_RGB8 D_E003CCF8[] = {
    { 0xFE, 0xAC, 0xAC },
    { 0xFE, 0xAC, 0xD5 },
    { 0xFE, 0xB4, 0x9A },
    { 0xD5, 0xB4, 0xFE },
    { 0xB4, 0xB4, 0xFE },
    { 0xB4, 0xDD, 0xFE },
    { 0xB4, 0xFE, 0xFE },
    { 0xB4, 0xFE, 0xD5 },
    { 0xB4, 0xFE, 0xB4 },
    { 0xD5, 0xFE, 0xB4 },
    { 0xFE, 0xFE, 0xB4 },
    { 0xFE, 0xD5, 0xAC }
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

void damage_indicator_init(EffectInstance *effectInst);
void damage_indicator_update(EffectInstance *effectInst);
void damage_indicator_render(EffectInstance *effectInst);
void func_E003C47C(EffectInstance *effectInst);
void func_E003C498(EffectInstance *effectInst);

void damage_indicator_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 numParts, EffectInstance **effectOut) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    f32 temp_f20;
    DamageIndicatorFXData *part;
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

    effect->data = part = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data != NULL);

    part->unk_00 = arg0;
    part->unk_04.x = arg1;
    part->unk_04.y = arg2;
    part->unk_04.z = arg3;
    part->unk_28 = arg4;
    part->effectDurationTimer = 100;
    part->unk_34 = 0;
    part->numParts = origNumParts;

    part++;
    for(i = 1; i < numParts; i++, part++) {
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
        part->alpha = 0xFF;
    }
    *effectOut = effect;
}

void damage_indicator_init(EffectInstance *effectInst) {
}

void damage_indicator_update(EffectInstance* effectInst) {
    s32 temp_a2;
    s32 temp_t0;
    s32 duration;
    DamageIndicatorFXData* part = effectInst->data;
    f32 phi_f12;
    s32 i;

    /* decrement duration timer */
    if (part->effectDurationTimer < 100) {
        part->effectDurationTimer--;
    }

    temp_a2 = part->unk_34++;
    temp_t0 = part->unk_34;
    duration = part->effectDurationTimer;

    /* if duration is less than 0, remove effect*/
    if (duration < 0) {
        shim_remove_effect(effectInst);
        return;
    }

    part++;
    for(i = 1; i < effectInst->numParts; i++, part++) {
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

        part->unk_38 = (temp_t0 < 0x29) ? (f32)D_E003CCD0[temp_a2] * 0.01 : 0.0f;
    }
}

void damage_indicator_render(EffectInstance *effectInst) {
}

void func_E003C47C(EffectInstance *effectInst) {
    func_E003C498(effectInst);
}

#ifdef NON_MATCHING
void func_E003C498(EffectInstance *effectInst) {
    Matrix4f sp20;
    Matrix4f sp60;
    DamageIndicatorFXData* part = effectInst->data;
    s32 i;
    s32 numParts;
    s32 spA0;
    s32 spA4;
    s32 spA8;

    spA8 = part->numParts;
    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, OS_PHYSICAL_TO_K0(effectInst->graphics->data));
    shim_guTranslateF(sp20, part->unk_04.x, part->unk_04.y, part->unk_04.z);
    shim_guRotateF(sp60, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    numParts = effectInst->numParts;
    spA0 = part->unk_34 - 1;
    spA4 = numParts - 1;
    part = &((DamageIndicatorFXData *)effectInst->data)[numParts - 1];

    if (part->alpha == 0xFF) {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
        gDPSetCombineLERP(gMasterGfxPos++, 1, 0, SHADE, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 1, 0, SHADE, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    } else {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineLERP(gMasterGfxPos++, 1, 0, SHADE, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 1, 0, SHADE, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    }
    for(i = 1; i < effectInst->numParts; i++, part--) {
        s32 index = (i + spA0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, D_E003CCF8[index % 12].r, D_E003CCF8[index % 12].g, D_E003CCF8[index % 12].b, part->alpha);
        gSPDisplayList(gMasterGfxPos++, D_09001D40);
        if (i == spA4) {
            shim_guPositionF(sp20, 0.0f, 0.0f, 0.0f, part->unk_38, part->unk_10.x, part->unk_10.y, part->unk_10.z);
            shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_09002150);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            shim_guPositionF(sp20, 0.0f, 0.0f, 0.0f, part->unk_38, (part->unk_10.x + part->unk_04.x) * 0.5, (part->unk_10.y + part->unk_04.y) * 0.5, (part->unk_10.z + part->unk_04.z) * 0.5);
            shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_09002160);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
        gSPDisplayList(gMasterGfxPos++, D_09001D40);
        shim_guTranslateF(sp20, part->unk_04.x, part->unk_04.y, part->unk_04.z);
        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        shim_guScaleF(sp20, part->unk_38, part->unk_38, 1.0f);
        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        if (i == spA4) {
            gSPDisplayList(gMasterGfxPos++, &D_09002170);
        } else {
            gSPDisplayList(gMasterGfxPos++, &D_09002180);
        }
        if (i == spA4) {
            gSPDisplayList(gMasterGfxPos++, D_090021A8);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_09001DE0);
            if (spA8 < 10) {
                gSPDisplayList(gMasterGfxPos++, D_E003CCA0[i]);
                gSPDisplayList(gMasterGfxPos++, D_090021C0);
            } else {
                s32 temp = spA8 % 10;
                s32 temp2 = spA8 / 10;
                gSPDisplayList(gMasterGfxPos++, D_E003CCA0[temp]);
                gSPDisplayList(gMasterGfxPos++, D_09002200);
                gSPDisplayList(gMasterGfxPos++, D_E003CCA0[temp2]);
                gSPDisplayList(gMasterGfxPos++, D_090021E0);
            }
        } else {
            gSPDisplayList(gMasterGfxPos++, D_09002190);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
#else
INCLUDE_ASM(s32, "effects/damage_indicator", func_E003C498);
#endif