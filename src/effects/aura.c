#include "common.h"
#include "effects_internal.h"

extern Gfx D_090023E0[];
extern Gfx D_09002440[];
extern Gfx D_090023F8[];
extern Gfx D_09002458[];
extern Gfx D_090023B0[];
extern Gfx D_09002410[];
extern Gfx D_090023C8[];
extern Gfx D_09002428[];
extern Gfx D_09002000[];
extern Gfx D_090020E8[];
extern Gfx D_090021D0[];

Gfx* D_E0076E90[] = { D_090023E0, D_090023E0, D_09002440, D_09002440 };
Gfx* D_E0076EA0[] = { D_090023F8, D_090023F8, D_09002458, D_09002458 };
Gfx* D_E0076EB0[] = { D_090023B0, D_090023B0, D_09002410, D_09002410 };
Gfx* D_E0076EC0[] = { D_090023C8, D_090023C8, D_09002428, D_09002428 };
Gfx* D_E0076ED0[] = { D_09002000, D_09002000, D_090020E8, D_090021D0 };

void aura_appendGfx(void* effect);

typedef struct AuraFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
               union {
                   s32 s;
                   f32 f;
               } unk_64;
    /* 0x68 */ u8 unk_68;
    /* 0x69 */ u8 unk_69;
    /* 0x6A */ u8 unk_6A;
    /* 0x6B */ u8 unk_6B;
    /* 0x6C */ u8 unk_6C;
    /* 0x6D */ u8 unk_6D;
    /* 0x6E */ u8 unk_6E;
} AuraFXData; // size = 0x70

void aura_init(EffectInstance* effect);
void aura_update(EffectInstance* effect);
void aura_render(EffectInstance* effect);

void aura_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, EffectInstance** outEffect) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    AuraFXData* part;
    s32 numParts = 1;
    f32 zero;

    bp.init = aura_init;
    bp.update = aura_update;
    bp.renderWorld = aura_render;
    bp.unk_00 = 0;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_AURA;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    
    part = effect->data = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data != NULL);

    part->unk_64.s = 0;
    zero = part->unk_64.f;
    part->unk_40 = zero;
    part->unk_34 = zero;
    part->unk_58 = zero;
    part->unk_4C = zero;
    part->unk_2C = 100;
    part->unk_00 = arg0;
    part->unk_30 = 0;
    part->unk_28 = 0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;

    switch (arg0) {
        case 0:
            part->unk_68 = 75;
            part->unk_69 = 75;
            part->unk_6A = 75;
            part->unk_6B = 255;
            part->unk_6C = 247;
            part->unk_6D = 155;
            part->unk_6E = 0;
            part->unk_24 = arg4;
            part->unk_20 = 0.6 * arg4;
            part->unk_1C = 2.0 * arg4;
            part->unk_38 = -0.9f;
            part->unk_44 = 0.04f;
            part->unk_3C = 0.04f;
            part->unk_48 = 0.9f;
            part->unk_50 = -0.9f;
            part->unk_5C = 0.04f;
            part->unk_54 = 0.04f;
            part->unk_60 = 0.9f;
            break;
        case 1:
            part->unk_68 = 75;
            part->unk_69 = 75;
            part->unk_6A = 75;
            part->unk_6B = 255;
            part->unk_6C = 0;
            part->unk_6D = 0;
            part->unk_6E = 0;
            part->unk_1C = arg4;
            part->unk_20 = arg4;
            part->unk_24 = arg4;
            part->unk_38 = zero;
            part->unk_50 = zero;
            part->unk_44 = 0.04f;
            part->unk_3C = 0.04f;
            part->unk_48 = 0.9f;
            part->unk_5C = 0.04f;
            part->unk_54 = 0.04f;
            part->unk_60 = 0.9f;
            break;
        case 2:
            part->unk_68 = 25;
            part->unk_69 = 121;
            part->unk_6A = 142;
            part->unk_6B = 34;
            part->unk_6D = 255;
            part->unk_6C = 0;
            part->unk_6E = 81;
            part->unk_1C = arg4;
            part->unk_20 = arg4;
            part->unk_24 = arg4;
            part->unk_38 = zero;
            part->unk_50 = zero;
            part->unk_44 = 0.04f;
            part->unk_3C = 0.2f;
            part->unk_48 = 1.3f;
            part->unk_5C = 0.04f;
            part->unk_54 = 0.16f;
            part->unk_60 = 1.04f;
            break;
        default:
            part->unk_68 = 179;
            part->unk_69 = 169;
            part->unk_6A = 85;
            part->unk_6B = 34;
            part->unk_6D = 255;
            part->unk_6C = 0;
            part->unk_6E = 63;
            part->unk_1C = arg4;
            part->unk_20 = arg4;
            part->unk_24 = arg4;
            part->unk_38 = 0;
            part->unk_50 = 0;
            part->unk_44 = 0.04f;
            part->unk_3C = 0.1f;
            part->unk_48 = 1.7f;
            part->unk_5C = 0.04f;
            part->unk_54 = 0.08f;
            part->unk_60 = 1.36f;
            break;
    }

    part->unk_10 = part->pos.x;
    part->unk_14 = part->pos.y;
    part->unk_18 = part->pos.z;

    *outEffect = effect;
}

void aura_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/aura", aura_update);

void aura_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = aura_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E007684C(void) {
}

void func_E0076854(void) {
}

INCLUDE_ASM(s32, "effects/aura", aura_appendGfx);
