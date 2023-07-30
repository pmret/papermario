#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000940_38AC90[];
extern Gfx D_09000A00_38AD50[];
extern Gfx D_09000A20_38AD70[];
extern Gfx D_09000A40_38AD90[];
extern Gfx D_09000A60_38ADB0[];
extern Gfx D_09000A80_38ADD0[];

Gfx* D_E0086AA0[] = {
    D_09000A00_38AD50, D_09000A20_38AD70, D_09000A40_38AD90,
    D_09000A60_38ADB0, D_09000A80_38ADD0
};

Gfx* D_E0086AB4[] = { D_09000940_38AC90, D_09000940_38AC90, D_09000940_38AC90 };

u8 D_E0086AC0[] = { 0x0D, 0x0D, 0x0D, 0x00 };

u8 D_E0086AC4[] = {
    0x40, 0x68, 0x90, 0xA4, 0xB8, 0xC0, 0xD0, 0xD8,
    0xE0, 0xE8, 0xF0, 0xF8, 0xFF, 0x00, 0x00, 0x00
};

u8 D_E0086AD4[] = {
    0x0A, 0x14, 0x1C, 0x23, 0x2A, 0x30, 0x35, 0x39,
    0x3C, 0x3E, 0x3F, 0x40, 0x41, 0x00, 0x00, 0x00
};

u8 D_E0086AE4[] = {
    0xFF, 0xFF, 0xC8, 0x82, 0x3C, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

void firework_init(EffectInstance* effect);
void firework_update(EffectInstance* effect);
void firework_render(EffectInstance* effect);
void func_E0086398(EffectInstance* effect);
void func_E00863B4(EffectInstance* effect);

EffectInstance* firework_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FireworkFXData* part;
    s32 numParts = (arg5 * 5 + 20) / 3 + 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = firework_init;
    bp.update = firework_update;
    bp.renderWorld = firework_render;
    bp.renderUI = func_E0086398;
    bp.effectID = EFFECT_FIREWORK;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.firework = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.firework != NULL);

    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_30 = D_E0086AC0[arg0];
    part->unk_34 = 0;
    part->unk_38 = 0;
    switch (arg0) {
        case 0:
            part->unk_3C = 255;
            part->unk_3D = 255;
            part->unk_3E = 255;
            part->unk_3F = 255;
            part->unk_40 = 255;
            part->unk_41 = 255;
            break;
        case 1:
            part->unk_3C = 255;
            part->unk_3D = 255;
            part->unk_3E = 0;
            part->unk_3F = 255;
            part->unk_40 = 0;
            part->unk_41 = 0;
            break;
        case 2:
        default:
            part->unk_3C = 255;
            part->unk_3D = 255;
            part->unk_3E = 0;
            part->unk_3F = 200;
            part->unk_40 = 255;
            part->unk_41 = 230;
            break;
    }
    part->unk_28 = arg4;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        f32 unk_1C = (i * 360) / (numParts - 1);
        s32 unk_24 = rand_int(359);

        part->unk_04 = 0;
        part->unk_08 = 0;
        part->unk_0C = 0;
        part->unk_10 = 0;
        part->unk_14 = 0;
        part->unk_20 = 0;
        part->unk_00 = 0;
        part->unk_1C = unk_1C;
        part->unk_24 = unk_24;
        part->unk_10 = 0;
        part->unk_2C = 255;
    }

    return effect;
}

void firework_init(EffectInstance* effect) {
}

void firework_update(EffectInstance* effect) {
    FireworkFXData* part = effect->data.firework;
    s32 unk_00 = part->unk_00;
    s32 unk_34;
    s32 idx;
    s32 i;

    part->unk_30--;
    part->unk_34++;

    if (part->unk_30 < 0) {
        remove_effect(effect);
        return;
    }

    unk_34 = part->unk_34;

    if (D_E0086AC0[unk_00] >= unk_34) {
        part->unk_38 = D_E0086AC4[unk_34 - 1] / 256.0f;
    } else {
        part->unk_38 = 1.0f;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        if (D_E0086AC0[unk_00] >= unk_34) {
            idx = unk_34 - 1;
        } else {
            idx = 12;
        }
        part->unk_04 = D_E0086AD4[idx];
        part->unk_08 = 0;
        part->unk_0C = 0;
    }
}

void firework_render(EffectInstance* effect) {
}

void func_E0086398(EffectInstance* effect) {
    func_E00863B4(effect);
}

void func_E00863B4(EffectInstance* effect) {
    FireworkFXData* part = effect->data.firework;
    Gfx* savedGfxPos;
    f32 temp_f32 = part->unk_38 * 5.0f;
    s32 envA;
    s32 temp_s32 = temp_f32;
    s32 primR;
    s32 primG;
    s32 primB;
    s32 envR;
    s32 envG;
    s32 engB;
    s32 primA;
    s32 unk_34 = part->unk_34;
    s32 unk_00 = part->unk_00;
    s32 var_v1;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    if (temp_s32 < 5) {
        s32 cond;
        f32 unk_28;

        gDPPipeSync(gMainGfxPos++);
        gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));

        unk_28 = part->unk_28;

        guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, unk_28, part->unk_04, part->unk_08, part->unk_0C);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        envA = (temp_f32 - temp_s32) * 256.0f;
        primA = part->unk_2C;
        cond = (temp_s32 >= 4);

        switch (unk_00) {
            case 1:
                if (unk_34 - 1 < 13) {
                    var_v1 = D_E0086AE4[unk_34 - 1];
                } else {
                    var_v1 = 0;
                }
                primR = part->unk_3C;
                primG = (part->unk_3D * var_v1) >> 8;
                primB = (part->unk_3E * var_v1) >> 8;
                envR = (part->unk_3F * var_v1) >> 8;
                envG = (part->unk_40 * var_v1) >> 8;
                engB = (part->unk_41 * var_v1) >> 8;
                break;
            case 2:
                if (unk_34 % 2 == 0) {
                    primR = 0;
                    primG = 0;
                    primB = 0;
                    envR = part->unk_3C;
                    envG = part->unk_3D;
                    engB = part->unk_3E;
                } else {
                    primR = part->unk_3C;
                    primG = part->unk_3D;
                    primB = part->unk_3E;
                    envR = part->unk_3F;
                    envG = part->unk_40;
                    engB = part->unk_41;
                }
                break;
            case 0:
            default:
                primR = part->unk_3C;
                primG = part->unk_3D;
                primB = part->unk_3E;
                envR = part->unk_3F;
                envG = part->unk_40;
                engB = part->unk_41;
                break;
        }

        savedGfxPos = gMainGfxPos++;
        gSPDisplayList(gMainGfxPos++, D_E0086AB4[unk_00]);

        part++;

        if (cond) {
            gDPSetTileSize(gMainGfxPos++, 1, 0, 0, 0, 0);
        }

        for (i = 1; i < effect->numParts; i++, part++) {
            gSPDisplayList(gMainGfxPos++, D_E0086AB4[part->unk_00]);

            guRotateF(sp20, part->unk_1C, 0.0f, 0.0f, 1.0f);
            guRotateF(sp60, part->unk_24, 0.0f, 1.0f, 0.0f);
            guMtxCatF(sp60, sp20, sp20);
            guTranslateF(sp60, part->unk_04, part->unk_08, part->unk_0C);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_E0086AA0[temp_s32]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }

        gSPEndDisplayList(gMainGfxPos++);
        gSPBranchList(savedGfxPos, gMainGfxPos);

        gDPSetPrimColor(gMainGfxPos++, 0, 0, primR, primG, primB, primA);
        gDPSetEnvColor(gMainGfxPos++, envR, envG, engB, envA);
        gSPDisplayList(gMainGfxPos++, savedGfxPos + 1);

        guRotateF(sp20, 120.0f, 1.0f, 1.0f, 1.0f);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, savedGfxPos + 1);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, savedGfxPos + 1);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        gDPPipeSync(gMainGfxPos++);
    }
}
