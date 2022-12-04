#include "common.h"
#include "effects_internal.h"

s32 D_E00BCC30[] = { 0x05050505, 0x05050505, 0x05050505, 0x0A090301, 0x00000000, 0x00000000, 0x05050505, 0x05050505, 0x05050505, 0x08070605, 0x04030201, 0x00000000, 0x23051905, 0x00192305, 0x0F000000, 0x0A0D0F0C, 0x0B0D0A0C, 0x05010000, 0x2D0F230F, 0x00232D37, 0x19050200, 0x0D0A0C0A, 0x0D0A0D0A, 0x0C090501, 0x0F0F0F0F, 0x0F0F000F, 0x0F050200, 0x0E0A0F0A, 0x0D1E201E, 0x1832283C, 0x01050F0F, 0x232D2823, 0x19050200, 0x04060A05, 0x080E060A, 0x0E233232, 0x010F190F, 0x19232D28, 0x230F0500, 0x0202170C, 0x080F0F05, 0x0612263C, 0x1E190F05, 0x0F0F191E, 0x23190500, 0x0303030B, 0x030C0405, 0x020C2A32, 0x2121140C, 0x19110F14, 0x16140500, 0x03030302, 0x0A02020C, 0x02020214, 0x1E1E1919, 0x23140F0A, 0x0F0F0500, 0x02020202, 0x02020602, 0x02020605, 0x1B1B1616, 0x20110C07, 0x0C0C0200, 0x02020202, 0x02020202, 0x02020200 };

s32 D_E00BCD38[] = { 0x19191905, 0x19051919, 0x05191919, 0x04030201, 0x00000000, 0x00000000, 0x0F0F0F19, 0x0F0F0519, 0x190F1919, 0x04040404, 0x04030201, 0x00000000, 0x19191905, 0x0F190505, 0x0F050500, 0x04040404, 0x04040604, 0x04040000, 0x19191905, 0x19051919, 0x050F0500, 0x04040404, 0x04040604, 0x04040605, 0x0F0F0F2D, 0x232D2323, 0x19230F00, 0x04040404, 0x04040604, 0x04040605, 0x2D372319, 0x370F2D19, 0x2D230F00, 0x04040404, 0x04040604, 0x04040605, 0x55190F4B, 0x1941232D, 0x4B550F00, 0x04040404, 0x04040604, 0x04040605, 0x550F2337, 0x412D194B, 0x232D2328, 0x04040404, 0x04040604, 0x04040605, 0x550F2337, 0x412D194B, 0x232D2328, 0x04040404, 0x04040604, 0x04040605, 0x550F2337, 0x412D194B, 0x232D2328, 0x04040404, 0x04040604, 0x04040605, 0x1E1E1919, 0x23140F0A, 0x0F0F0500, 0x04040404, 0x04040404, 0x04040200 };

s32* D_E00BCE40[] = { D_E00BCC30, D_E00BCD38 };

void lightning_bolt_init(EffectInstance* effect);
void lightning_bolt_update(EffectInstance* effect);
void lightning_bolt_render(EffectInstance* effect);
void lightning_bolt_appendGfx(void* effect);

EffectInstance* lightning_bolt_main(
    s32 type,
    f32 startX,
    f32 startY,
    f32 startZ,
    f32 endX,
    f32 endY,
    f32 endZ,
    f32 scale,
    s32 duration)
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

    data->type = type;
    data->lifetime = 0;
    if (duration <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = duration;
    }
    data->outerColor.a = 255;
    data->startPos.x = startX;
    data->startPos.y = startY;
    data->startPos.z = startZ;
    data->endPos.x = endX;
    data->endPos.y = endY;
    data->endPos.z = endZ;
    data->tipPos.x = startX;
    data->tipPos.y = startY;
    data->tipPos.z = startZ;
    data->unk_4C = scale;

    temp = SQ(startX - endX) + SQ(startY - endY) + SQ(startZ - endZ);

    if (temp != 0.0f) {
        data->unk_114 = shim_sqrtf(temp) * 0.005;
        data->outerColor.r = 255;
        data->outerColor.g = 220;
        data->outerColor.b = 20;
        data->innerColor.r = 255;
        data->innerColor.g = 255;
        data->innerColor.b = 255;
        data->unk_110 = shim_rand_int(359);

        return effect;
    } else {
        return NULL;
    }
}

void lightning_bolt_init(EffectInstance* effect) {
}

f32 lightning_bolt_get_rand_symmetric(f32 interval) {
    return (f32)shim_rand_int(interval) - interval * 0.5;
}

void lightning_bolt_update(EffectInstance* effect) {
    LightningBoltFXData* data = effect->data.lightningBolt;
    s32 type = data->type;

    if (effect->flags & EFFECT_INSTANCE_FLAGS_10) {
        effect->flags &= ~EFFECT_INSTANCE_FLAGS_10;
        data->timeLeft = 16;
    }

    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifetime++;

    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }

    if (type == 2) {
        if (data->lifetime >= 40) {
            data->outerColor.a *= 0.5;
        }
    } else {
        if (data->lifetime >= 11) {
            data->outerColor.a *= 0.5;
        }
    }
}

void lightning_bolt_render(EffectInstance *effect) {
    LightningBoltFXData* data = effect->data.lightningBolt;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = lightning_bolt_appendGfx;
    renderTask.appendGfxArg = effect;
    if (gGameStatusPtr->isBattle == TRUE) {
        renderTask.distance = data->tipPos.z + 1000.0f;
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
