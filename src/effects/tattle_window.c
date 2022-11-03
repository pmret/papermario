#include "common.h"
#include "effects_internal.h"

void tattle_window_init(EffectInstance* effect);
void tattle_window_update(EffectInstance* effect);
void tattle_window_render(EffectInstance* effect);
void func_E00D8264(EffectInstance* effect);
void func_E00D8630(EffectInstance* effect);

typedef struct D_E00D8818_Entry {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
} D_E00D8818_Entry; // size = 0x4

WindowStyleCustom D_E00D87E0 = {
    .background = {0},
    .corners = {
        .imgData = 0x09000000, // TODO change to sym when the graphics for this is done
        .packedTileFormat = 0x31,
        .size1 = {0x10, 0x08},
        .size2 = {0x10, 0x08},
        .size3 = {0x10, 0x08},
        .size4 = {0x10, 0x08},
    },
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 0x3D, 0x4A, 0xBC, 0xFF },
    .color2 = { 0x00, 0x19, 0x1C, 0xFF},
};

D_E00D8818_Entry D_E00D8818[] = {
    { .unk_00 = 0xFF38, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFF60, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFF88, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFFAB, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFFC9, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFFE2, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFFF0, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFFF8, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFFFC, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFFFE, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0xFFFF, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0x0000, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0x0000, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0x0000, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0x0000, .unk_02 = 0xFF, .unk_03 = 0xFF },
    { .unk_00 = 0x0000, .unk_02 = 0xE6, .unk_03 = 0xFA },
    { .unk_00 = 0x0000, .unk_02 = 0x78, .unk_03 = 0xF5 },
    { .unk_00 = 0x0000, .unk_02 = 0x00, .unk_03 = 0xF0 },
    { .unk_00 = 0x0000, .unk_02 = 0x00, .unk_03 = 0xD2 },
    { .unk_00 = 0x0000, .unk_02 = 0x00, .unk_03 = 0xAA },
    { .unk_00 = 0x0000, .unk_02 = 0x00, .unk_03 = 0x78 },
    { .unk_00 = 0x0000, .unk_02 = 0x00, .unk_03 = 0x3C },
    { .unk_00 = 0x0000, .unk_02 = 0x00, .unk_03 = 0x00 },
};

EffectInstance* tattle_window_main(s32 arg0, f32 x, f32 y, f32 z, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    TattleWindowFXData* part;
    s32 numParts = 1;

    bp.init = tattle_window_init;
    bp.update = tattle_window_update;
    bp.renderWorld = tattle_window_render;
    bp.unk_14 = func_E00D8264;
    bp.unk_00 = 0;
    bp.effectID = EFFECT_TATTLE_WINDOW;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.tattleWindow = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.tattleWindow != NULL);

    part->unk_00 = arg0;
    part->unk_14 = 0;
    if (arg5 <= 0) {
        part->unk_10 = 1000;
    } else {
        part->unk_10 = arg5;
    }
    part->pos.x = x;
    part->pos.y = y;
    part->pos.z = z;
    part->scale = 0.0f;
    part->unk_18 = arg4;
    part->rot.x = 0.0f;
    part->rot.y = 0.0f;
    part->rot.z = 0.0f;
    part->unk_2C = part->unk_30 = part->rot.z;
    part->unk_34 = 0xFF;
    part->unk_35 = 0xFF;

    return effect;
}

void tattle_window_init(EffectInstance* effect) {
}

void tattle_window_update(EffectInstance* effect) {
    s32 unk_10, unk_10_2;
    s32 old_unk_14;
    TattleWindowFXData* part = effect->data.tattleWindow;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        part->unk_10 = 23;
    }

    if (part->unk_10 < 1000) {
        part->unk_10--;
    }

    old_unk_14 = part->unk_14++;
    unk_10 = part->unk_10;

    if (unk_10 < 0) {
        shim_remove_effect(effect);
        return;
    }
    unk_10_2 = unk_10;
    part->rot.z = 0;
    part->unk_2C = 0;
    part->scale = part->unk_18;
    if (old_unk_14 < 23) {
        part->unk_30 = D_E00D8818[old_unk_14].unk_00;
        part->unk_34 = D_E00D8818[old_unk_14].unk_02;
        part->unk_35 = D_E00D8818[old_unk_14].unk_03;
    } else {
        part->unk_30 = D_E00D8818[22].unk_00;
        part->unk_34 = D_E00D8818[22].unk_02;
        part->unk_35 = D_E00D8818[22].unk_03;
        part->unk_14 = 24;
    }
    if (unk_10_2 < 23) {
        part->unk_30 = D_E00D8818[unk_10_2].unk_00;
        part->unk_34 = D_E00D8818[unk_10_2].unk_02;
        part->unk_35 = D_E00D8818[unk_10_2].unk_03;
    }
}

void tattle_window_render(EffectInstance* effect) {
}

void func_E00D8264(EffectInstance* effect) {
    func_E00D8630(effect);
}

void func_E00D8280(void) {
}

void func_E00D8288(s32 l, s32 r, s32 t, s32 b) {
    if (l < 0) {
        l = 0;
    }
    if (r < 0) {
        r = 0;
    }
    if (t < 0) {
        t = 0;
    }
    if (b < 0) {
        b = 0;
    }

    if (l > SCREEN_WIDTH - 1) {
        l = SCREEN_WIDTH - 1;
    }
    if (r > SCREEN_HEIGHT - 1) {
        r = SCREEN_HEIGHT - 1;
    }
    if (t > SCREEN_WIDTH - 1) {
        t = SCREEN_WIDTH - 1;
    }
    if (b > SCREEN_HEIGHT - 1) {
        b = SCREEN_HEIGHT - 1;
    }

    gDPFillRectangle(gMasterGfxPos++, l, r, t, b);
}

void func_E00D8334(TattleWindowFXData* data, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 t1 = data->unk_34 / 255.0f;
    f32 t2 = data->unk_35 / 255.0f;
    s32 d1, d2;
    s32 l, r, t, b;

    if (data->unk_34 > 0 || data->unk_35 > 0) {
        gDPPipeSync(gMasterGfxPos++);
        gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
        gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
        gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
        gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
        gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
        gDPSetTextureFilter(gMasterGfxPos++, G_TF_AVERAGE);
        gDPSetTextureConvert(gMasterGfxPos++, G_TC_FILT);
        gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineMode(gMasterGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 24, 48, 96, 255);
        t = (arg1 + arg3) - 4;
        b = (arg2 + arg4) - 4;
        r = arg2 + 4;
        l = arg1 + 4;
        d1 = (t - l) / 2;
        d2 = (b - r) / 2;
        func_E00D8288(l, r, l + (d1 * t1), b);
        func_E00D8288(t - (d1 * t1), r, t, b);
        func_E00D8288(l, r, t, r + (d2 * t2));
        func_E00D8288(l, b - (d2 * t2), t, b);
    }
}

void func_E00D8630(EffectInstance* effect) {
    TattleWindowFXData* data = effect->data.tattleWindow;
    s32 flags;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    if (data->scale == 1.0f && data->rot.x == 0.0f && data->rot.y == 0.0f && data->rot.z == 0.0f) {
        flags = 0;
    } else {
        flags = 1;
    }

    shim_draw_box(
        flags, &D_E00D87E0,
        (data->pos.x + data->unk_2C) - 75.0f,
        (data->pos.y + data->unk_30) - 53.0f,
        data->pos.z,
        150, 107,
        255, 0,
        data->scale, data->scale,
        data->rot.x, data->rot.y, data->rot.z,
        (void (*)(void*)) func_E00D8334, data, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    gDPPipeSync(gMasterGfxPos++);
}
