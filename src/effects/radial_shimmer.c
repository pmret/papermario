#include "common.h"
#include "effects_internal.h"

void radial_shimmer_init(EffectInstance* effect);
void radial_shimmer_update(EffectInstance* effect);
void radial_shimmer_render(EffectInstance* effect);
void radial_shimmer_appendGfx(void* effect);

EffectInstance* radial_shimmer_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    RadialShimmerFXData* data;
    s32 numParts = 1;
    s32 arg5_2 = arg5;

    bp.init = radial_shimmer_init;
    bp.update = radial_shimmer_update;
    bp.renderWorld = radial_shimmer_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_RADIAL_SHIMMER;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.radialShimmer = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.radialShimmer != NULL);

    data->unk_00 = arg0;
    data->unk_28 = arg5_2;
    data->unk_24 = data->unk_2C = 0;
    data->unk_10 = arg1;
    data->unk_14 = arg2;
    data->unk_18 = arg3;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_20 = arg4;
    data->unk_68 = 255;
    data->unk_69 = 255;
    data->unk_6A = 0;
    data->unk_6B = 255;
    data->unk_6C = 255;
    data->unk_6D = 255;
    data->unk_5C = 4.0f;
    data->unk_1C = 10.0f;
    data->unk_60 = 50.0f;
    data->unk_40 = data->unk_44 = 0.0f;
    data->unk_48 = data->unk_4C = 0.0f;
    data->unk_30 = data->unk_34 = 0.0f;
    data->unk_38 = data->unk_3C = 0.0f;
    data->unk_50 = data->unk_58 = 0.0f;
    data->unk_54 = 0.0f;
    data->unk_64 = 0.0f;

    switch (arg0) {
        case 0:
        case 1:
            data->unk_40 = 128.0f;
            data->unk_44 = 128.0f / arg5_2;
            data->unk_60 = 70.0f;
            data->unk_64 = -100.0f;
            break;
        case 2:
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = 3.0f;
            data->unk_4C = -7.0f;
            break;
        case 3:
            data->unk_68 = 235;
            data->unk_69 = 235;
            data->unk_6A = 235;
            data->unk_40 = 256.0f;
            data->unk_48 = 256.0f;
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = -4.0f;
            break;
        case 4:
            data->unk_68 = 20;
            data->unk_69 = 200;
            data->unk_6A = 32;
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = -5.0f;
            break;
        case 5:
            data->unk_34 = 7.0f;
            data->unk_44 = 3.0f;
            data->unk_3C = 3.0f;
            data->unk_4C = 5.0f;
            break;
        case 6:
            data->unk_68 = 235;
            data->unk_69 = 235;
            data->unk_6A = 235;
            data->unk_34 = 7.0f;
            data->unk_44 = 3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = 4.0f;
            break;
        case 7:
            data->unk_68 = 255;
            data->unk_69 = 100;
            data->unk_6A = 32;
            data->unk_34 = 7.0f;
            data->unk_44 = 3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = 5.0f;
            break;
        case 8:
            data->unk_68 = 215;
            data->unk_69 = 208;
            data->unk_6A = 0;
            data->unk_6B = 215;
            data->unk_6C = 255;
            data->unk_6D = 0;
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = -2.0f;
            break;
        case 9:
            data->unk_40 = 128.0f;
            data->unk_44 = 128.0f / arg5_2;
            data->unk_64 = -100.0f;
            break;
        case 10:
            data->unk_68 = 0;
            data->unk_69 = 32;
            data->unk_6A = 255;
            data->unk_68 = 7;
            data->unk_69 = 0;
            data->unk_6A = 216;
            data->unk_6B = 228;
            data->unk_6C = 255;
            data->unk_6D = 0;
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = -2.0f;
            break;
        case 11:
            data->unk_68 = 7;
            data->unk_69 = 0;
            data->unk_6A = 216;
            data->unk_6B = 228;
            data->unk_6C = 255;
            data->unk_6D = 0;
            data->unk_34 = 7.0f;
            data->unk_44 = 8.0f;
            data->unk_3C = -3.0f;
            data->unk_4C = 6.0f;
            break;
        case 12:
        case 13:
            data->unk_34 = 7.0f;
            data->unk_44 = -3.0f;
            data->unk_3C = -5.0f;
            data->unk_4C = -4.0f;
            break;
        case 14:
        default:
            data->unk_40 = 4.0f;
            data->unk_34 = 7.0f;
            data->unk_4C = 3.5f;
            data->unk_60 = 20.0f;
            data->unk_64 = -106.0f;
            break;
    }

    return effect;
}

void radial_shimmer_init(EffectInstance* effect) {
}

void radial_shimmer_update(EffectInstance* effect) {
    RadialShimmerFXData* part = effect->data.radialShimmer;
    s32 unk_28;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 outS;
    s32 i;

    part->unk_28--;
    part->unk_2C++;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        part->unk_28 = 16;
    }

    if (part->unk_28 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_28 = part->unk_28;

    if (part->unk_2C < 11) {
        part->unk_24 = (part->unk_2C * 255) / 10;
    }

    if (unk_28 < 6) {
        part->unk_24 = (unk_28 * 255) / 6;
    }

    if (unk_28 < 10 && part->unk_00 == 4) {
        part->unk_1C *= 0.7;
    }

    part->unk_1C = part->unk_20;

    shim_transform_point(&gCameras[gCurrentCameraID].perspectiveMatrix[0], part->unk_04, part->unk_08, part->unk_0C, 1.0f, &outX, &outY, &outZ, &outS);

    outS = 1.0f / outS;
    outX *= outS;
    outY *= outS;
    outZ *= outS;

    part->unk_10 = outX;
    part->unk_14 = outY;
    part->unk_18 = 0.0f;

    for (i = 0; i < effect->numParts; i++, part++) {
        part->unk_58 += part->unk_5C;
        part->unk_50 += part->unk_54;
        part->unk_40 += part->unk_44;
        part->unk_30 += part->unk_34;
        part->unk_38 += part->unk_3C;
        part->unk_48 += part->unk_4C;

        if (part->unk_40 < 0.0f) {
            part->unk_40 += 512.0f;
        }

        if (part->unk_48 < 0.0f) {
            part->unk_48 += 512.0f;
        }
    }
}

void radial_shimmer_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = radial_shimmer_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/radial_shimmer", radial_shimmer_appendGfx);
