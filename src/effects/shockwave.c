#include "common.h"
#include "effects_internal.h"

extern Gfx D_090009A0_359D50[];
extern Gfx D_09000A80_359E30[];

Gfx* D_E004AE60[] = {
    D_090009A0_359D50, D_090009A0_359D50, D_09000A80_359E30, D_09000A80_359E30,
    D_09000A80_359E30, D_09000A80_359E30, NULL, NULL
};

void shockwave_init(EffectInstance* effect);
void shockwave_update(EffectInstance* effect);
void shockwave_render(EffectInstance* effect);
void shockwave_appendGfx(void* effect);

void shockwave_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    ShockwaveFXData* part;
    f32 zero = 0.0f;
    s32 numParts;
    s32 i;

    switch (arg0) {
        case 0:
            arg0 = 3;
            break;
        case 1:
            arg0 = 2;
            break;
        case 2:
            arg0 = 4;
            break;
        default:
            arg0 = 5;
            break;
    }

    switch (arg0) {
        case 1:
            numParts = 1;
            break;
        case 0:
        case 2:
        case 5:
            numParts = 3;
            break;
        default:
            numParts = 2;
            break;
    }

    numParts++;

    bpPtr->init = shockwave_init;
    bpPtr->update = shockwave_update;
    bpPtr->renderWorld = shockwave_render;
    bpPtr->unk_00 = 0;
    bpPtr->unk_14 = NULL;
    bpPtr->effectID = EFFECT_SHOCKWAVE;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.shockwave = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.shockwave != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    if (arg0 >= 2) {
        part->unk_28 = 60;
    } else {
        part->unk_28 = 30;
    }
    part->unk_38 = 255;
    part->unk_2C = 0;
    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;

    switch (arg0) {
        case 0:
        case 1:
            part->unk_50.r = 0;
            part->unk_50.g = 255;
            part->unk_50.b = 122;
            part->unk_53.r = 240;
            part->unk_53.g = 255;
            part->unk_53.b = 250;
            break;
        case 2:
            part->unk_50.r = 125;
            part->unk_50.g = 120;
            part->unk_50.b = 100;
            part->unk_53.r = 255;
            part->unk_53.g = 255;
            part->unk_53.b = 240;
            break;
        case 3:
            part->unk_50.r = 220;
            part->unk_50.g = 210;
            part->unk_50.b = 200;
            part->unk_53.r = 255;
            part->unk_53.g = 255;
            part->unk_53.b = 250;
            break;
        case 5:
            part->unk_50.r = 225;
            part->unk_50.g = 204;
            part->unk_50.b = 93;
            part->unk_53.r = 232;
            part->unk_53.g = 231;
            part->unk_53.b = 171;
            break;
        default:
            part->unk_28 = 50;
            part->unk_50.r = 208;
            part->unk_50.g = 136;
            part->unk_50.b = 40;
            part->unk_53.r = 216;
            part->unk_53.g = 169;
            part->unk_53.b = 65;
            break;
    }

    part++;
    for (i = 1; i < numParts; i++, part++) {
        switch (arg0) {
            case 0:
            case 1:
                part->unk_4C = 1 + i * -2;
                break;
            default:
                part->unk_4C = 2 + i * -3;
                break;
        }
        part->unk_34 = zero;
        part->unk_30 = i * 30;
    }
}

void shockwave_init(EffectInstance* effect) {
}

void shockwave_update(EffectInstance* effect) {
    ShockwaveFXData* part = effect->data.shockwave;
    s32 unk_00;
    s32 unk_2C;
    s32 i;

    part->unk_2C++;
    part->unk_28--;

    if (part->unk_28 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_00 = part->unk_00;
    unk_2C = part->unk_2C;

    switch (unk_00) {
        case 0:
        case 1:
            if (unk_2C >= 8) {
                part->unk_38 *= 0.8;
            }
            break;
        default:
            if (unk_2C >= 8) {
                part->unk_38 *= 0.94;
            }
            break;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_4C++;
        if (part->unk_4C >= 0) {
            if (part->unk_4C == 0) {
                part->unk_04 = 0;
                part->unk_08 = 0;
                part->unk_0C = 0;
                part->unk_10 = -shim_sin_deg(part->unk_34) * 0.5;
                part->unk_14 = shim_cos_deg(part->unk_34) * 0.5;
                part->unk_18 = 0;
                part->unk_3C = 32.0f;
                part->unk_40 = 32.0f;
                part->unk_48 = 32.0f;
                part->unk_20 = 8.0 - (f32) i;

                switch (unk_00) {
                    case 0:
                    case 1:
                        part->unk_1C = i + 0.5;
                        part->unk_24 = (i + 0.5) * 0.5;
                        break;
                    case 2:
                    case 5:
                        part->unk_1C = i + 2;
                        part->unk_24 = (i + 2) * 0.5;
                        break;
                    case 3:
                        part->unk_1C = i + 3;
                        part->unk_24 = (i + 3) * 0.5;
                        part->unk_3C = 16.0f;
                        part->unk_40 = 16.0f;
                        part->unk_48 = 16.0f;
                        break;
                    case 4:
                    default:
                        part->unk_1C = (i + 3) * 0.5;
                        part->unk_24 = (i + 3) * 0.5 * 0.5;
                        part->unk_3C = 16.0f;
                        part->unk_40 = 16.0f;
                        part->unk_48 = 16.0f;
                        part->unk_20 *= 0.8;
                        break;
                }

                part->unk_44 = 32.0f;
            }

            part->unk_3C += part->unk_40;
            part->unk_44 += part->unk_48;

            switch (unk_00) {
                case 0:
                case 1:
                    part->unk_40 *= 0.9;
                    break;
                case 2:
                case 5:
                    part->unk_40 *= 0.75;
                    part->unk_48 *= 0.99;
                    break;
                default:
                    part->unk_40 *= 0.75;
                    part->unk_48 *= 0.95;
                    break;
            }

            part->unk_1C *= 1.002;
            part->unk_24 *= 1.002;
            if (part->unk_3C > 128.0f) {
                part->unk_3C = 128.0f;
            }
        }
    }
}

void shockwave_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shockwave_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/shockwave", shockwave_appendGfx);
