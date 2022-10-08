#include "common.h"
#include "effects_internal.h"

s32 D_E00BCC30[] = { 0x05050505, 0x05050505, 0x05050505, 0x0A090301, 0x00000000, 0x00000000, 0x05050505, 0x05050505, 0x05050505, 0x08070605, 0x04030201, 0x00000000, 0x23051905, 0x00192305, 0x0F000000, 0x0A0D0F0C, 0x0B0D0A0C, 0x05010000, 0x2D0F230F, 0x00232D37, 0x19050200, 0x0D0A0C0A, 0x0D0A0D0A, 0x0C090501, 0x0F0F0F0F, 0x0F0F000F, 0x0F050200, 0x0E0A0F0A, 0x0D1E201E, 0x1832283C, 0x01050F0F, 0x232D2823, 0x19050200, 0x04060A05, 0x080E060A, 0x0E233232, 0x010F190F, 0x19232D28, 0x230F0500, 0x0202170C, 0x080F0F05, 0x0612263C, 0x1E190F05, 0x0F0F191E, 0x23190500, 0x0303030B, 0x030C0405, 0x020C2A32, 0x2121140C, 0x19110F14, 0x16140500, 0x03030302, 0x0A02020C, 0x02020214, 0x1E1E1919, 0x23140F0A, 0x0F0F0500, 0x02020202, 0x02020602, 0x02020605, 0x1B1B1616, 0x20110C07, 0x0C0C0200, 0x02020202, 0x02020202, 0x02020200 };

s32 D_E00BCD38[] = { 0x19191905, 0x19051919, 0x05191919, 0x04030201, 0x00000000, 0x00000000, 0x0F0F0F19, 0x0F0F0519, 0x190F1919, 0x04040404, 0x04030201, 0x00000000, 0x19191905, 0x0F190505, 0x0F050500, 0x04040404, 0x04040604, 0x04040000, 0x19191905, 0x19051919, 0x050F0500, 0x04040404, 0x04040604, 0x04040605, 0x0F0F0F2D, 0x232D2323, 0x19230F00, 0x04040404, 0x04040604, 0x04040605, 0x2D372319, 0x370F2D19, 0x2D230F00, 0x04040404, 0x04040604, 0x04040605, 0x55190F4B, 0x1941232D, 0x4B550F00, 0x04040404, 0x04040604, 0x04040605, 0x550F2337, 0x412D194B, 0x232D2328, 0x04040404, 0x04040604, 0x04040605, 0x550F2337, 0x412D194B, 0x232D2328, 0x04040404, 0x04040604, 0x04040605, 0x550F2337, 0x412D194B, 0x232D2328, 0x04040404, 0x04040604, 0x04040605, 0x1E1E1919, 0x23140F0A, 0x0F0F0500, 0x04040404, 0x04040404, 0x04040200 };

s32 D_E00BCE40[] = { D_E00BCC30, D_E00BCD38, 0x00000000, 0x00000000 };

void lightning_bolt_init(EffectInstance* effect);
void lightning_bolt_update(EffectInstance* effect);
void lightning_bolt_render(EffectInstance* effect);
void lightning_bolt_appendGfx(void* effect);

EffectInstance* lightning_bolt_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    f32 arg6,
    f32 arg7,
    s32 arg8)
{
    EffectBlueprint bp;
    EffectInstance* effect;
    LightningBoltFXData* data;
    s32 numParts = 1;
    f32 temp;

    bp.init = lightning_bolt_init;
    bp.update = lightning_bolt_update;
    bp.renderWorld = lightning_bolt_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_LIGHTNING_BOLT;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.lightningBolt = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.lightningBolt != NULL);

    data->unk_00 = arg0;
    data->unk_2C = 0;
    if (arg8 <= 0) {
        data->unk_28 = 1000;
    } else {
        data->unk_28 = arg8;
    }
    data->unk_3C = 255;
    data->unk_10 = arg1;
    data->unk_14 = arg2;
    data->unk_18 = arg3;
    data->unk_1C = arg4;
    data->unk_20 = arg5;
    data->unk_24 = arg6;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_4C = arg7;

    temp = SQ(arg1 - arg4) + SQ(arg2 - arg5) + SQ(arg3 - arg6);

    if (temp != 0.0f) {
        data->unk_114 = shim_sqrtf(temp) * 0.005;
        data->unk_30 = 255;
        data->unk_34 = 220;
        data->unk_38 = 20;
        data->unk_40 = 255;
        data->unk_44 = 255;
        data->unk_48 = 255;
        data->unk_110 = shim_rand_int(359);

        return effect;
    } else {
        return NULL;
    }
}

void lightning_bolt_init(EffectInstance* effect) {
}

f32 func_E00BC1D8(f32 arg0) {
    return (f32)shim_rand_int(arg0) - arg0 * 0.5;
}

void lightning_bolt_update(EffectInstance* effect) {
    LightningBoltFXData* data = effect->data.lightningBolt;
    s32 unk_00 = data->unk_00;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_28 = 16;
    }

    if (data->unk_28 < 1000) {
        data->unk_28--;
    }

    data->unk_2C++;

    if (data->unk_28 < 0) {
        shim_remove_effect(effect);
        return;
    }

    if (unk_00 == 2) {
        if (data->unk_2C >= 40) {
            data->unk_3C *= 0.5;
        }
    } else {
        if (data->unk_2C >= 11) {
            data->unk_3C *= 0.5;
        }
    }
}

void lightning_bolt_render(EffectInstance *effect) {
    LightningBoltFXData* effect94 = effect->data.lightningBolt;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = lightning_bolt_appendGfx;
    renderTask.appendGfxArg = effect;
    if (gGameStatusPtr->isBattle == TRUE) {
        renderTask.distance = effect94->unk_0C + 1000.0f;
    } else {
        renderTask.distance = 10;
    }

    renderTaskPointer->renderMode = RENDER_MODE_2D;
    retTask = shim_queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00BC36C(void) {
}

INCLUDE_ASM(s32, "effects/lightning_bolt", lightning_bolt_appendGfx);
