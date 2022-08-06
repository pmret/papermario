#include "common.h"
#include "effects_internal.h"

enum ArrowType {
    ARROW_TYPE_ATK_UP = 0,
    ARROW_TYPE_ATK_DOWN = 1,
    ARROW_TYPE_DEF_UP = 2,
};

typedef struct ExtraArrowDataEntry {
    u8 unk_00;
    u8 unk_01;
} ExtraArrowDataEntry;

typedef struct ArrowDataTableEntry {
    s32 type;
    s32 value;
} ArrowDataTableEntry;

s32 D_E00AC7B0[] = { 0x09002700, 0x09002700, 0x09002798 };

s32 D_E00AC7BC[] = { 0x09002860, 0x09002880, 0x09002860 };

s32 D_E00AC7C8[] = { 0x09002950, 0x09002990, 0x090029D0, 0x09002A10, 0x09002A50, 0x09002A90, 0x09002AD0, 0x09002B10, 0x09002B50, 0x09002B90, 0x09002BD0, 0x09002C10 };

ExtraArrowDataEntry D_E00AC7F8[] = {
    { .unk_00 = 0xFF, .unk_01 = 0x96 },
    { .unk_00 = 0xFF, .unk_01 = 0x82 },
    { .unk_00 = 0xFF, .unk_01 = 0x64 },
    { .unk_00 = 0xFF, .unk_01 = 0x46 },
    { .unk_00 = 0xFF, .unk_01 = 0x3C },
    { .unk_00 = 0xFF, .unk_01 = 0x50 },
    { .unk_00 = 0xFF, .unk_01 = 0x6E },
    { .unk_00 = 0xFF, .unk_01 = 0x73 },
    { .unk_00 = 0xFF, .unk_01 = 0x6B },
    { .unk_00 = 0xFF, .unk_01 = 0x5C },
    { .unk_00 = 0xFF, .unk_01 = 0x5A },
    { .unk_00 = 0xFF, .unk_01 = 0x5E },
    { .unk_00 = 0xFF, .unk_01 = 0x67 },
    { .unk_00 = 0xFF, .unk_01 = 0x68 },
    { .unk_00 = 0xFF, .unk_01 = 0x67 },
    { .unk_00 = 0xFF, .unk_01 = 0x64 },
    { .unk_00 = 0xFF, .unk_01 = 0x62 },
    { .unk_00 = 0xFF, .unk_01 = 0x63 },
    { .unk_00 = 0xFF, .unk_01 = 0x65 },
    { .unk_00 = 0xFF, .unk_01 = 0x64 },
    { .unk_00 = 0xF0, .unk_01 = 0x64 },
    { .unk_00 = 0xDC, .unk_01 = 0x64 },
    { .unk_00 = 0xC8, .unk_01 = 0x64 },
    { .unk_00 = 0xB4, .unk_01 = 0x64 },
    { .unk_00 = 0xA0, .unk_01 = 0x64 },
    { .unk_00 = 0x82, .unk_01 = 0x64 },
    { .unk_00 = 0x64, .unk_01 = 0x64 },
    { .unk_00 = 0x46, .unk_01 = 0x64 },
    { .unk_00 = 0x32, .unk_01 = 0x64 },
    { .unk_00 = 0x28, .unk_01 = 0x64 },
    { .unk_00 = 0x1E, .unk_01 = 0x64 },
    { .unk_00 = 0x14, .unk_01 = 0x64 },
    { .unk_00 = 0x0A, .unk_01 = 0x64 },
};

ExtraArrowDataEntry D_E00AC83C[] = {
    { .unk_00 = 0xFF, .unk_01 = 0x96 },
    { .unk_00 = 0xFF, .unk_01 = 0x82 },
    { .unk_00 = 0xFF, .unk_01 = 0x64 },
    { .unk_00 = 0xFF, .unk_01 = 0x46 },
    { .unk_00 = 0xFF, .unk_01 = 0x3C },
    { .unk_00 = 0xFF, .unk_01 = 0x50 },
    { .unk_00 = 0xFF, .unk_01 = 0x6E },
    { .unk_00 = 0xFF, .unk_01 = 0x73 },
    { .unk_00 = 0xFF, .unk_01 = 0x6B },
    { .unk_00 = 0xFF, .unk_01 = 0x5C },
    { .unk_00 = 0xFF, .unk_01 = 0x5A },
    { .unk_00 = 0xFF, .unk_01 = 0x5E },
    { .unk_00 = 0xFF, .unk_01 = 0x67 },
    { .unk_00 = 0xFF, .unk_01 = 0x68 },
    { .unk_00 = 0xFF, .unk_01 = 0x67 },
    { .unk_00 = 0xFF, .unk_01 = 0x64 },
    { .unk_00 = 0xFF, .unk_01 = 0x62 },
    { .unk_00 = 0xFF, .unk_01 = 0x63 },
    { .unk_00 = 0xFF, .unk_01 = 0x65 },
    { .unk_00 = 0xFF, .unk_01 = 0x64 },
    { .unk_00 = 0xF0, .unk_01 = 0x64 },
    { .unk_00 = 0xDC, .unk_01 = 0x64 },
    { .unk_00 = 0xC8, .unk_01 = 0x64 },
    { .unk_00 = 0xB4, .unk_01 = 0x64 },
    { .unk_00 = 0xA0, .unk_01 = 0x64 },
    { .unk_00 = 0x82, .unk_01 = 0x64 },
    { .unk_00 = 0x64, .unk_01 = 0x64 },
    { .unk_00 = 0x46, .unk_01 = 0x64 },
    { .unk_00 = 0x32, .unk_01 = 0x64 },
    { .unk_00 = 0x28, .unk_01 = 0x64 },
    { .unk_00 = 0x1E, .unk_01 = 0x64 },
    { .unk_00 = 0x14, .unk_01 = 0x64 },
    { .unk_00 = 0x0A, .unk_01 = 0x64 },
};

ArrowDataTableEntry D_E00AC880[] = {
    { .type = ARROW_TYPE_ATK_UP, .value = 1 },
    { .type = ARROW_TYPE_ATK_UP, .value = 2 },
    { .type = ARROW_TYPE_ATK_UP, .value = 3 },
    { .type = ARROW_TYPE_ATK_DOWN, .value = -1 },
    { .type = ARROW_TYPE_ATK_DOWN, .value = -2 },
    { .type = ARROW_TYPE_ATK_DOWN, .value = -3 },
    { .type = ARROW_TYPE_DEF_UP, .value = 1 },
    { .type = ARROW_TYPE_DEF_UP, .value = 2 },
    { .type = ARROW_TYPE_DEF_UP, .value = 3 },
    { .type = ARROW_TYPE_ATK_UP, .value = 0 },
};

void func_E00AC288(EffectInstance* effect);
void func_E00AC2A4(EffectInstance* effect);
void stat_change_init(EffectInstance* effect);
void stat_change_update(EffectInstance* effect);
void stat_change_render(EffectInstance* effect);

EffectInstance* stat_change_main(s32 arg0, f32 x, f32 y, f32 z, f32 scale, s32 time) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    StatChangeFXData* part;
    s32 numParts = 1;

    bp.init = stat_change_init;
    bp.update = stat_change_update;
    bp.renderWorld = stat_change_render;
    bp.unk_14 = func_E00AC288;
    bp.unk_00 = 0;
    bp.effectID = EFFECT_STAT_CHANGE;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.statChange = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.statChange != NULL);

    part->unk_00 = arg0;
    part->pos.x = x;
    part->pos.y = y;
    part->pos.z = z;
    part->timeLeft = time;

    part->unk_18 = 0;
    part->scale = scale;
    part->unk_24 = 255;
    part->scaleX = 0;
    part->scaleY = 0;
    part->unk_30 = 0;
    part->unk_38 = 0;
    part->unk_34 = 0;

    part->arrowType = D_E00AC880[arg0].type;
    part->arrowValue = D_E00AC880[arg0].value;

    return effect;
}

void stat_change_init(EffectInstance* effect) {
}

void stat_change_update(EffectInstance* effect) {
    StatChangeFXData* part = effect->data.statChange;
    s32 old_unk18;

    part->timeLeft--;
    old_unk18 = part->unk_18++;

    if (part->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }

    if (part->arrowType == ARROW_TYPE_ATK_DOWN) {
        if (old_unk18 >= ARRAY_COUNT(D_E00AC83C)) {
            part->unk_24 = 0;
            part->scaleX = 0.0f;
            part->scaleY = 0.0f;
        } else {
            part->unk_24 = D_E00AC83C[old_unk18].unk_00;
            part->scaleY = (f32)D_E00AC83C[old_unk18].unk_01 * 0.01;
            part->scaleX = 1.0f - part->scaleY + 1.0f;
        }
    } else {
        if (old_unk18 >= ARRAY_COUNT(D_E00AC7F8)) {
            part->unk_24 = 0;
            part->scaleX = 0.0f;
            part->scaleY = 0.0f;
        } else {
            part->unk_24 = D_E00AC7F8[old_unk18].unk_00;
            part->scaleX = (f32)D_E00AC7F8[old_unk18].unk_01 * 0.01;
            part->scaleY = 1.0f - part->scaleX + 1.0f;
        }
    }

    part->unk_3C = 0;
    part->unk_40 = 0;

    do {} while (0); // required to match

    part->pos.x += part->unk_30;
    part->pos.y += part->unk_38;
    part->pos.z += part->unk_34;
}

void stat_change_render(EffectInstance* effect) {
}

void func_E00AC288(EffectInstance* effect) {
    func_E00AC2A4(effect);
}

INCLUDE_ASM(s32, "effects/stat_change", func_E00AC2A4);
