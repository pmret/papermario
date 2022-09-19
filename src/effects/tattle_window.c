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

s32 D_E00D87E0[] = { 0x00000000, 0x00000000, 0x00000000, 0x09000000, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0x3D4ABCFF, 0x00191CFF };

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
        part->unk_10 = 0x3E8;
    } else {
        part->unk_10 = arg5;
    }
    part->pos.x = x;
    part->pos.y = y;
    part->pos.z = z;
    part->unk_1C = 0;
    part->unk_18 = arg4;
    part->unk_28 = 0.0f;
    part->unk_2C = part->unk_30 = part->unk_28;
    part->unk_20 = 0;
    part->unk_24 = 0;
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
    part->unk_28 = 0;
    part->unk_2C = 0;
    part->unk_1C = part->unk_18;
    if (old_unk_14 < 23) {
        part->unk_30 = D_E00D8818[old_unk_14].unk_00;
        part->unk_34 = D_E00D8818[old_unk_14].unk_02;
        part->unk_35 = D_E00D8818[old_unk_14].unk_03;
    } else {
        part->unk_30 = D_E00D8818[0x16].unk_00;
        part->unk_34 = D_E00D8818[0x16].unk_02;
        part->unk_35 = D_E00D8818[0x16].unk_03;
        part->unk_14 = 0x18;
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

INCLUDE_ASM(s32, "effects/tattle_window", func_E00D8334);

INCLUDE_ASM(s32, "effects/tattle_window", func_E00D8630);
