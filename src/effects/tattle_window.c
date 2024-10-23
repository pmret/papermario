#include "common.h"
#include "effects_internal.h"

void tattle_window_init(EffectInstance* effect);
void tattle_window_update(EffectInstance* effect);
void tattle_window_render(EffectInstance* effect);
void func_E00D8264(EffectInstance* effect);
void func_E00D8630(EffectInstance* effect);

extern u8 D_09000000_3D7040[];

WindowStyleCustom TattleWindowStyle = {
    .background = { 0 },
    .corners = {
        .imgData = D_09000000_3D7040,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 16, 8 },
        .size2 = { 16, 8 },
        .size3 = { 16, 8 },
        .size4 = { 16, 8 },
    },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 61, 74, 188, 255 },
    .color2 = { 0, 25, 28, 255},
};

typedef struct TattleAnimFrame {
    s16 offsetY;
    u8 closeAmtX;
    u8 closeAmtY;
} TattleAnimFrame; // size = 0x4

TattleAnimFrame TattleWindowAnimation[] = {
    { .offsetY = -200, .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -160, .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -120, .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -85,  .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -55,  .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -30,  .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -16,  .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -8,   .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -4,   .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -2,   .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = -1,   .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = 0,    .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = 0,    .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = 0,    .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = 0,    .closeAmtX = 255, .closeAmtY = 255 },
    { .offsetY = 0,    .closeAmtX = 230, .closeAmtY = 250 },
    { .offsetY = 0,    .closeAmtX = 120, .closeAmtY = 245 },
    { .offsetY = 0,    .closeAmtX = 0,   .closeAmtY = 240 },
    { .offsetY = 0,    .closeAmtX = 0,   .closeAmtY = 210 },
    { .offsetY = 0,    .closeAmtX = 0,   .closeAmtY = 170 },
    { .offsetY = 0,    .closeAmtX = 0,   .closeAmtY = 120 },
    { .offsetY = 0,    .closeAmtX = 0,   .closeAmtY = 60 },
    { .offsetY = 0,    .closeAmtX = 0,   .closeAmtY = 0 },
};

EffectInstance* tattle_window_main(s32 type, f32 x, f32 y, f32 z, f32 arg4, s32 duration) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    TattleWindowFXData* part;
    s32 numParts = 1;

    bp.init = tattle_window_init;
    bp.update = tattle_window_update;
    bp.renderScene = tattle_window_render;
    bp.renderUI = func_E00D8264;
    bp.unk_00 = 0;
    bp.effectID = EFFECT_TATTLE_WINDOW;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.tattleWindow = general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.tattleWindow != NULL);

    part->type = type;
    part->unk_14 = 0;
    if (duration <= 0) {
        part->timeLeft = 1000;
    } else {
        part->timeLeft = duration;
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
    part->closeAmt.x = 255;
    part->closeAmt.y = 255;

    return effect;
}

void tattle_window_init(EffectInstance* effect) {
}

void tattle_window_update(EffectInstance* effect) {
    s32 unk_10, unk_10_2;
    s32 old_unk_14;
    TattleWindowFXData* part = effect->data.tattleWindow;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->timeLeft = ARRAY_COUNT(TattleWindowAnimation);
    }

    if (part->timeLeft < 1000) {
        part->timeLeft--;
    }

    old_unk_14 = part->unk_14++;
    unk_10 = part->timeLeft;

    if (unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_10_2 = unk_10;
    part->rot.z = 0;
    part->offset.x = 0;
    part->scale = part->unk_18;

    if (old_unk_14 < ARRAY_COUNT(TattleWindowAnimation)) {
        part->offset.y = TattleWindowAnimation[old_unk_14].offsetY;
        part->closeAmt.x = TattleWindowAnimation[old_unk_14].closeAmtX;
        part->closeAmt.y = TattleWindowAnimation[old_unk_14].closeAmtY;
    } else {
        part->offset.y = TattleWindowAnimation[ARRAY_COUNT(TattleWindowAnimation) - 1].offsetY;
        part->closeAmt.x = TattleWindowAnimation[ARRAY_COUNT(TattleWindowAnimation) - 1].closeAmtX;
        part->closeAmt.y = TattleWindowAnimation[ARRAY_COUNT(TattleWindowAnimation) - 1].closeAmtY;
        part->unk_14 = ARRAY_COUNT(TattleWindowAnimation) + 1;
    }

    if (unk_10_2 < ARRAY_COUNT(TattleWindowAnimation)) {
        part->offset.y = TattleWindowAnimation[unk_10_2].offsetY;
        part->closeAmt.x = TattleWindowAnimation[unk_10_2].closeAmtX;
        part->closeAmt.y = TattleWindowAnimation[unk_10_2].closeAmtY;
    }
}

void tattle_window_render(EffectInstance* effect) {
}

void func_E00D8264(EffectInstance* effect) {
    func_E00D8630(effect);
}

void func_E00D8280(void) {
}

void tattle_window_fill_clipped_quad(s32 l, s32 t, s32 r, s32 b) {
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
    f32 closeFracX = data->closeAmt.x / 255.0f;
    f32 closeFracY = data->closeAmt.y / 255.0f;
    s32 xMid, yMid;
    s32 l, t, r, b;

    // draw the 'shades' which appear over the window and tattle viewport to animate opening and closing
    if (data->closeAmt.x > 0 || data->closeAmt.y > 0) {
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
        tattle_window_fill_clipped_quad(l, t, l + (xMid * closeFracX), b);
        tattle_window_fill_clipped_quad(r - (xMid * closeFracX), t, r, b);
        tattle_window_fill_clipped_quad(l, t, r, t + (yMid * closeFracY));
        tattle_window_fill_clipped_quad(l, b - (yMid * closeFracY), r, b);
    }
}

void func_E00D8630(EffectInstance* effect) {
    TattleWindowFXData* data = effect->data.tattleWindow;
    s32 flags;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    if (data->scale == 1.0f && data->rot.x == 0.0f && data->rot.y == 0.0f && data->rot.z == 0.0f) {
        flags = 0;
    } else {
        flags = 1;
    }

    draw_box(
        flags, &TattleWindowStyle,
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
