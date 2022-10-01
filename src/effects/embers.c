#include "common.h"
#include "effects_internal.h"

extern f32 D_E00E0A48[];

void embers_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/embers", embers_main);

void embers_init(void) {
}

void embers_update(EffectInstance* effect) {
    EmbersFXData* part = effect->data.embers;
    f32 unk_10;
    f32 unk_14;
    s32 unk_1C;
    f32 unk_68;
    f32 unk_6C;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        part->unk_18 = 0x10;
    }

    if (part->unk_18 < 1000) {
        part->unk_18--;
    }

    part->unk_1C++;
    if (part->unk_1C > 324000) {
        part->unk_1C = 256;
    }

    if (part->unk_18 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_1C = part->unk_1C;

    if (part->unk_18 < 16) {
        part->unk_2C = part->unk_18 * 16;
    }

    if (unk_1C < 16) {
        part->unk_2C = unk_1C * 16 + 15;
    }

    unk_10 = part->unk_10;
    unk_14 = part->unk_14;
    unk_68 = part->unk_68;
    unk_6C = part->unk_6C;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_64++;
        if (part->unk_64 >= 30) {
            part->unk_64 = 0;
        }

        if (part->unk_64 >= 0) {
            if (part->unk_64 == 0) {
                part->unk_04 = shim_rand_int(unk_10) - unk_10 * 0.5;
                part->unk_08 = shim_rand_int(unk_14);
                part->unk_0C = 0.0f;
                part->unk_44 = (f32) (shim_rand_int(20) - 10) * 0.05;
                part->unk_48 = (shim_rand_int(40) - 1) * unk_68 * 0.05;
                part->unk_4C = 0.0f;
                part->unk_50 = (f32) (shim_rand_int(20) - 10) * 0.05;
                part->unk_54 = (shim_rand_int(30) - 1) * unk_6C * 0.05;
                part->unk_58 = 0.0f;
                part->unk_5C = shim_rand_int(15);
                part->unk_60 = shim_rand_int(15);
            }
            part->unk_40 = D_E00E0A48[part->unk_64];
            part->unk_04 += part->unk_44;
            part->unk_08 += part->unk_48;
            part->unk_0C += part->unk_4C;
            part->unk_5C += 0.1;
            part->unk_60 += 0.3;
            part->unk_44 += (part->unk_50 - part->unk_44) * 0.04;
            part->unk_48 += (part->unk_54 - part->unk_48) * 0.04;
            part->unk_4C += (part->unk_58 - part->unk_4C) * 0.04;
        }
    }
}

void embers_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = embers_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00E05F8(void) {
}

INCLUDE_ASM(s32, "effects/embers", embers_appendGfx);
