#include "common.h"
#include "effects_internal.h"

typedef struct Effect73 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 unk_20;
} Effect73; // size = 0x24

extern Gfx D_09000330[];
extern Gfx D_09000370[];
extern Gfx D_090003B0[];
extern Gfx D_090003F0[];
extern Gfx D_09000430[];

Gfx* D_E0092690[] = { D_09000430, D_090003F0, D_090003B0, D_09000370, D_09000330 };

// Parameters for each part
s32 D_E00926A4[4 * 5] = {
    1, 0, 0, 0, 100,
    2, 4, -2, 0, 100,
    3, -2, 2, 0, 70,
    4, 2, 4, 0, 40,
};

void fx_73_init(EffectInstance* effect);
void fx_73_update(EffectInstance* effect);
void fx_73_render(EffectInstance* effect);
void fx_73_appendGfx(EffectInstance* effect);

EffectInstance* fx_73_main(EffectInstanceDataThing* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect73* data;
    Effect73* part;
    s32 numParts = 5;
    s32 i;

    bp.init = fx_73_init;
    bp.update = fx_73_update;
    bp.renderWorld = fx_73_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectIndex = 73;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    data = shim_general_heap_malloc(numParts * sizeof(*data));
    effect->data = data;
    part = data;

    ASSERT(data != NULL);

    part->unk_00 = arg0;
    part->unk_18 = 0.0f;
    part->unk_14 = 14;
    part->unk_08 = arg1;
    part->unk_0C = arg2;
    part->unk_10 = arg3;

    part++;
    for (i = 1; i < numParts; i++, part++) {
            part->unk_08 = D_E00926A4[1 + (i - 1) * 5];
            part->unk_0C = D_E00926A4[2 + (i - 1) * 5];
            part->unk_10 = D_E00926A4[3 + (i - 1) * 5];
            part->unk_04 = -1;
            part->unk_20 = D_E00926A4[0 + (i - 1) * 5];
            part->unk_1C = (arg4 * D_E00926A4[4 + (i - 1) * 5]) * 0.01;
    }
    return effect;
}

void fx_73_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/effect_73", fx_73_update);

INCLUDE_ASM(s32, "effects/effect_73", fx_73_render);

INCLUDE_ASM(s32, "effects/effect_73", func_E00922A0);
