#include "common.h"
#include "effects_internal.h"

void firework_rocket_init(EffectInstance* effect);
void firework_rocket_render(EffectInstance* effect);
void firework_rocket_update(EffectInstance* effect);
void firework_rocket_appendGfx(void* effect);

typedef struct FireworkRocketUnk {
    /* 0x00 */ Color_RGB8* unk_00;
    /* 0x04 */ s32 num;
} FireworkRocketUnk; // size = 0x8

extern Gfx D_09000080_3E53D0[];
extern Gfx D_09000158_3E54A8[];

Gfx* D_E010ACC0[] = { D_09000158_3E54A8, D_09000158_3E54A8, D_09000158_3E54A8 };
Gfx* D_E010ACCC[] = { D_09000080_3E53D0, D_09000080_3E53D0, D_09000080_3E53D0 };

Color_RGB8 D_E010ACD8[] = {
    {36, 0, 93}, {54, 216, 74}, {67, 0, 74}, {82, 220, 45}, {89, 0, 45}, {60, 190, 45}, {21, 192, 74}, {28, 171, 45}, 
    {10, 158, 15}, {49, 170, 15}, {166, 216, 15}, {169, 237, 45}, {157, 0, 15}, {184, 203, 45}, {169, 19, 45}, 
    {166, 40, 15}, {190, 73, 15}, {184, 53, 45}, {211, 77, 45}, {225, 94, 15}, {247, 89, 45}, {184, 53, 45}, 
    {11, 222, 93}, {0, 0, 100}, {202, 216, 74}, {184, 203, 45}, {211, 179, 45}, {166, 216, 15}, {190, 183, 15}, 
    {11, 222, 93}, {235, 192, 74}, {21, 192, 74}, {247, 167, 45}, {28, 171, 45}, {10, 98, 15}, {80, 198, 15}, 
    {97, 235, 15}, {49, 170, 15}, {10, 158, 15}, {225, 162, 15}, {190, 183, 15}, {49, 86, 15}, {80, 58, 15}, 
    {97, 21, 15}, {227, 235, 93}, {0, 0, 100}, {11, 34, 93}, {227, 21, 93}, {21, 64, 74}, {235, 64, 74}, {202, 40, 74}, 
    {28, 85, 45}, {67, 0, 74}, {89, 0, 45}, {36, 0, 93}, {0, 0, 100}, {11, 34, 93}, {54, 40, 74}, {21, 64, 74}, 
    {202, 40, 74}, {184, 53, 45}, {0, 0, 100}, {227, 235, 93}, {189, 0, 74}, {202, 216, 74}, {227, 21, 93}, {0, 0, 100},
    {60, 190, 45}, {82, 220, 45}, {89, 0, 45}, {28, 171, 45}, {28, 171, 45}, {247, 167, 45}, {211, 179, 45}, 
    {184, 203, 45}, {60, 66, 45}, {28, 85, 45}, {82, 36, 45}, {28, 85, 45}, {89, 0, 45}, {247, 89, 45}, {211, 77, 45}, 
    {184, 53, 45}, {49, 86, 15}, {10, 98, 15}, {82, 36, 45}, {97, 235, 15}, {97, 21, 15}, {60, 66, 45}, {28, 85, 45}, 
    {169, 19, 45}, {190, 73, 15}, {166, 40, 15}, {169, 237, 45}, {184, 203, 45}
};

Color_RGB8 D_E010ADF8[] = {
    {208, 241, 0}, {220, 230, 22}, {211, 0, 22}, {208, 15, 0}, {220, 26, 22}, {227, 40, 0}, {220, 26, 22}, 
    {242, 43, 22}, {0, 50, 0}, {14, 43, 22}, {8, 231, 43}, {14, 213, 22}, {36, 230, 22}, {26, 0, 43}, {0, 0, 50}, 
    {0, 206, 0}, {29, 216, 0}, {45, 0, 22}, {29, 216, 0}, {36, 230, 22}, {14, 213, 22}, {48, 241, 0}, {45, 0, 22}, 
    {0, 206, 0}, {14, 213, 22}, {242, 213, 22}, {227, 216, 0}, {220, 230, 22}, {29, 40, 0}, {36, 26, 22}, {48, 15, 0}, 
    {14, 43, 22}, {45, 0, 22}, {0, 0, 50}, {8, 25, 43}, {235, 15, 43}, {14, 43, 22}, {26, 0, 43}, {45, 0, 22}, 
    {0, 0, 50}, {8, 25, 43}, {235, 241, 43}, {0, 0, 50}, {220, 230, 22}, {8, 231, 43}, {0, 0, 50}, {235, 15, 43}, 
    {235, 241, 43}, {220, 26, 22}, {242, 43, 22}, {220, 26, 22}, {29, 40, 0}, {0, 50, 0}, {36, 26, 22}, {48, 241, 0}, 
    {48, 15, 0}, {14, 43, 22}, {242, 213, 22}, {208, 241, 0}, {227, 216, 0}, {14, 213, 22}, {211, 0, 22}, 
    {220, 230, 22}, {227, 40, 0}, {208, 15, 0}, {0, 0, 0}
};

Color_RGB8 D_E010AEC0[] = {
    {247, 105, 0}, {239, 87, 0}, {17, 87, 0}, {9, 105, 0}, {0, 122, 0}, {230, 69, 0}, {26, 69, 0}, {221, 52, 0}, 
    {35, 52, 0}, {202, 49, 0}, {186, 255, 0}, {200, 241, 0}, {0, 200, 0}, {56, 241, 0}, {70, 255, 0}, {54, 49, 0}, 
    {196, 222, 0}, {239, 191, 0}, {17, 191, 0}, {60, 222, 0}, {85, 13, 0}, {74, 46, 0}, {99, 27, 0}, {93, 43, 0}, 
    {12, 33, 0}, {12, 22, 0}, {24, 22, 0}, {24, 33, 0}, {12, 10, 0}, {24, 10, 0}, {24, 45, 0}, {232, 33, 0}, 
    {232, 22, 0}, {232, 45, 0}, {113, 40, 0}, {193, 203, 0}, {190, 183, 0}, {182, 46, 0}, {163, 43, 0}, {35, 182, 0}, 
    {52, 173, 0}, {12, 45, 0}, {244, 22, 0}, {244, 33, 0}, {232, 10, 0}, {244, 10, 0}, {244, 45, 0}, {204, 173, 0}, 
    {221, 182, 0}, {186, 164, 0}, {171, 13, 0}, {157, 27, 0}, {143, 40, 0}, {63, 203, 0}, {66, 183, 0}, {70, 164, 0}
};

FireworkRocketUnk D_E010AF68[] = {
    {D_E010ACD8, ARRAY_COUNT(D_E010ACD8)},
    {D_E010ADF8, ARRAY_COUNT(D_E010ADF8)},
    {D_E010AEC0, ARRAY_COUNT(D_E010AEC0)}
};

s32 D_E010AF80 = 0;
s32 D_E010AF84 = 0;

EffectInstance* firework_rocket_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FireworkRocketFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = firework_rocket_init;
    bp.update = firework_rocket_update;
    bp.renderWorld = firework_rocket_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FIREWORK_ROCKET;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.fireworkRocket = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.fireworkRocket != NULL);

    data->unk_00 = arg0;
    data->unk_20 = 0;
    if (arg8 <= 0) {
        data->unk_1C = 1000;
    } else {
        data->unk_1C = arg8 + 32;
    }
    data->unk_4C = 0;
    data->unk_30 = 255;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_44 = 0;
    data->unk_10 = arg4;
    data->unk_14 = arg5;
    data->unk_18 = arg6;
    data->unk_48 = arg7;
    data->unk_2C = 100;
    data->unk_38 = 100;
    data->unk_24 = 255;
    data->unk_28 = 255;
    data->unk_34 = 255;
    data->unk_3C = 150;
    data->unk_40 = 255;

    for (i = 0; i < 4; i++) {
        data->unk_50[i] = data->unk_04;
        data->unk_60[i] = data->unk_08 - 1000.0f;
        data->unk_70[i] = data->unk_0C;
        data->unk_80[i] = 0;
        data->unk_90[i] = 0;
        data->unk_A0[i] = 0;
    }

    return effect;
}

void firework_rocket_init(EffectInstance* effect) {
}

void firework_rocket_update(EffectInstance* effect) {
    FireworkRocketFXData* data = effect->data.fireworkRocket;
    f32 factor;
    s32 unk_20;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_1C = 16;
    }

    if (data->unk_1C < 1000) {
        data->unk_1C--;
    }

    data->unk_20++;

    if (data->unk_1C < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_20 = data->unk_20;

    if (data->unk_1C < 32) {
        data->unk_30 = data->unk_1C * 8;
    }

    if (data->unk_4C == 1) {
        factor = 0.95f;
        data->unk_04 += data->unk_10;
        data->unk_08 += data->unk_14;
        data->unk_0C += data->unk_18;
        data->unk_10 *= factor;
        data->unk_14 *= factor;
        data->unk_18 *= factor;
        data->unk_44 += (data->unk_48 - data->unk_44) * 0.11;
        data->unk_14 -= 0.15;
        return;
    }

    i = unk_20 & 3;
    data->unk_50[i] = data->unk_04 - data->unk_10 * (32 - unk_20);
    data->unk_60[i] = data->unk_08 - data->unk_14 * (32 - unk_20)
        - (80.0f - shim_sin_deg((s32) (unk_20 * 90) >> 5) * 80.0f);
    data->unk_70[i] = data->unk_0C - data->unk_18 * (32 - unk_20);
    data->unk_80[i] = (shim_rand_int(10) - 5) * 0.1f;
    data->unk_90[i] = (shim_rand_int(10) - 5) * 0.1f;
    data->unk_A0[i] = (shim_rand_int(10) - 5) * 0.1f;

    for (i = 0; i < 4; i++) {
        data->unk_50[i] += data->unk_80[i];
        data->unk_60[i] += data->unk_90[i];
        data->unk_70[i] += data->unk_A0[i];
        data->unk_90[i] -= 0.15;
        if (unk_20 >= 27) {
            data->unk_60[i] = -1000.0f;
        }
    }

    if (unk_20 >= 32) {
        data->unk_4C = 1;
        data->unk_20 = 1;
    }
}

void firework_rocket_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = firework_rocket_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 700;
    renderTask.renderMode =  RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/firework_rocket", firework_rocket_appendGfx);
