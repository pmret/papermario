#include "common.h"
#include "effects_internal.h"

void tattle_window_init(EffectInstance* effect);
void tattle_window_update(EffectInstance* effect);
void tattle_window_render(EffectInstance* effect);
void func_E00D8264(EffectInstance* effect);
void func_E00D8630(EffectInstance* effect);

typedef struct D_E00D8818_Entry {
    s16 yOffset;
    u8 unk_02;
    u8 unk_03;
} D_E00D8818_Entry; // size = 0x4

extern u8 D_09000000_3D7040[];

WindowStyleCustom D_E00D87E0 = {
    .background = {0},
    .corners = {
        .imgData = D_09000000_3D7040,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = {16, 8},
        .size2 = {16, 8},
        .size3 = {16, 8},
        .size4 = {16, 8},
    },
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0,
                                            COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0,
                                                 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 61, 74, 188, 255 },
    .color2 = { 0, 25, 28, 255},
};

D_E00D8818_Entry D_E00D8818[] = {
    { .yOffset = -200, .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -160, .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -120, .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -85,  .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -55,  .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -30,  .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -16,  .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -8,   .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -4,   .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -2,   .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = -1,   .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = 0,    .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = 0,    .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = 0,    .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = 0,    .unk_02 = 255, .unk_03 = 255 },
    { .yOffset = 0,    .unk_02 = 230, .unk_03 = 250 },
    { .yOffset = 0,    .unk_02 = 120, .unk_03 = 245 },
    { .yOffset = 0,    .unk_02 = 0,   .unk_03 = 240 },
    { .yOffset = 0,    .unk_02 = 0,   .unk_03 = 210 },
    { .yOffset = 0,    .unk_02 = 0,   .unk_03 = 170 },
    { .yOffset = 0,    .unk_02 = 0,   .unk_03 = 120 },
    { .yOffset = 0,    .unk_02 = 0,   .unk_03 = 60 },
    { .yOffset = 0,    .unk_02 = 0,   .unk_03 = 0 },
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
    part->offset.x = part->offset.y = 0.0f;
    part->unk_34 = 255;
    part->unk_35 = 255;

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
    part->offset.x = 0;
    part->scale = part->unk_18;
    if (old_unk_14 < 23) {
        part->offset.y = D_E00D8818[old_unk_14].yOffset;
        part->unk_34 = D_E00D8818[old_unk_14].unk_02;
        part->unk_35 = D_E00D8818[old_unk_14].unk_03;
    } else {
        part->offset.y = D_E00D8818[22].yOffset;
        part->unk_34 = D_E00D8818[22].unk_02;
        part->unk_35 = D_E00D8818[22].unk_03;
        part->unk_14 = 24;
    }
    if (unk_10_2 < 23) {
        part->offset.y = D_E00D8818[unk_10_2].yOffset;
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

void func_E00D8288(s32 l, s32 t, s32 r, s32 b) {
    if (l < 0) {
        l = 0;
    }
    if (t < 0) {
        t = 0;
    }
    if (r < 0) {
        r = 0;
    }
    if (b < 0) {
        b = 0;
    }

    if (l > SCREEN_WIDTH - 1) {
        l = SCREEN_WIDTH - 1;
    }
    if (t > SCREEN_HEIGHT - 1) {
        t = SCREEN_HEIGHT - 1;
    }
    if (r > SCREEN_WIDTH - 1) {
        r = SCREEN_WIDTH - 1;
    }
    if (b > SCREEN_HEIGHT - 1) {
        b = SCREEN_HEIGHT - 1;
    }

    gDPFillRectangle(gMainGfxPos++, l, t, r, b);
}

void func_E00D8334(TattleWindowFXData* data, s32 left, s32 top, s32 right, s32 bottom) {
    f32 t1 = data->unk_34 / 255.0f;
    f32 t2 = data->unk_35 / 255.0f;
    s32 xMid, yMid;
    s32 l, t, r, b;

    if (data->unk_34 > 0 || data->unk_35 > 0) {
        gDPPipeSync(gMainGfxPos++);
        gSPTexture(gMainGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
        gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
        gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
        gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
        gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
        gDPSetTextureFilter(gMainGfxPos++, G_TF_AVERAGE);
        gDPSetTextureConvert(gMainGfxPos++, G_TC_FILT);
        gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 24, 48, 96, 255);
        l = left + 4;
        r = (left + right) - 4;
        t = top + 4;
        b = (top + bottom) - 4;
        xMid = (r - l) / 2;
        yMid = (b - t) / 2;
        func_E00D8288(l, t, l + (xMid * t1), b);
        func_E00D8288(r - (xMid * t1), t, r, b);
        func_E00D8288(l, t, r, t + (yMid * t2));
        func_E00D8288(l, b - (yMid * t2), r, b);
    }
}

void func_E00D8630(EffectInstance* effect) {
    TattleWindowFXData* data = effect->data.tattleWindow;
    s32 flags;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    if (data->scale == 1.0f && data->rot.x == 0.0f && data->rot.y == 0.0f && data->rot.z == 0.0f) {
        flags = 0;
    } else {
        flags = 1;
    }

    shim_draw_box(
        flags, &D_E00D87E0,
        (data->pos.x + data->offset.x) - 75.0f,
        (data->pos.y + data->offset.y) - 53.0f,
        data->pos.z,
        150, 107,
        255, 0,
        data->scale, data->scale,
        data->rot.x, data->rot.y, data->rot.z,
        (void (*)(void*)) func_E00D8334, data, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    gDPPipeSync(gMainGfxPos++);
}
