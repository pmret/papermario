#include "common.h"
#include "effects_internal.h"

void fx_65_init(EffectInstance* effect);
void fx_65_update(EffectInstance* effect);
void fx_65_render(EffectInstance* effect);
void fx_65_appendGfx(void* effect);

EffectInstance* fx_65_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect65FXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = fx_65_init;
    bp.update = fx_65_update;
    bp.renderWorld = fx_65_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_65;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.unk_65 = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.unk_65 != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_34 = arg4;

    switch (arg0) {
        case 0:
            data->unk_18 = 255;
            data->unk_1C = 255;
            data->unk_20 = 255;
            data->unk_28 = 225;
            data->unk_2C = 225;
            data->unk_30 = 225;
            data->unk_24 = 255;
            break;
        case 1:
            data->unk_18 = 255;
            data->unk_1C = 245;
            data->unk_20 = 230;
            data->unk_28 = 45;
            data->unk_2C = 35;
            data->unk_30 = 15;
            data->unk_24 = 255;
            break;
        case 2:
            data->unk_18 = 255;
            data->unk_1C = 0;
            data->unk_20 = 0;
            data->unk_28 = 155;
            data->unk_2C = 125;
            data->unk_30 = 125;
            data->unk_24 = 255;
            break;
        case 3:
            data->unk_18 = 255;
            data->unk_1C = 255;
            data->unk_20 = 255;
            data->unk_28 = 255;
            data->unk_2C = 65;
            data->unk_30 = 20;
            data->unk_24 = 255;
            break;
    }

    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;

    for (i = 0; i < ARRAY_COUNT(data->unk_230); i++) {
        data->unk_230[i] = 0;
    }

    data->unk_2A8 = 0;
    data->unk_50[0] = arg1;
    data->unk_C8[0] = arg2;
    data->unk_140[0] = arg3;
    data->unk_230[0] = 1;
    data->unk_1B8[0] = 0;
    data->unk_2AC[0] = 0;
    data->unk_44 = shim_rand_int(30) + 10;
    data->unk_48 = 0;
    data->unk_4C = 0;

    return effect;
}

void fx_65_init(EffectInstance* effect) {
}

void fx_65_update(EffectInstance* effect) {
    Effect65FXData* data = effect->data.unk_65;
    s32 unk_00 = data->unk_00;
    s32 unk_14;
    f32 unk_2AC;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 tempX;
    f32 tempY;
    f32 tempZ;
    f32 dist;
    s32 idx;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_10 = 16;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;
    if (data->unk_10 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_14 = data->unk_14;

    if (data->unk_10 < 16) {
        data->unk_24 = data->unk_10 * 16;
    }

    if (unk_00 == 3) {
        data->unk_44 += shim_rand_int(10) - 5;
        data->unk_48 += shim_rand_int(10) - 5;
        data->pos.x += data->unk_44;
        data->pos.y += data->unk_48;
        data->pos.z += data->unk_4C;
    }

    idx = data->unk_2A8 % 30;

    posX = data->pos.x;
    posY = data->pos.y;
    posZ = data->pos.z;

    tempX = data->unk_50[idx];
    tempY = data->unk_C8[idx];
    tempZ = data->unk_140[idx];

    if ((posX != tempX) || (posY != tempY) || (posZ != tempZ)) {
        unk_2AC = data->unk_2AC[idx];

        data->unk_2A8++;
        if (data->unk_2A8 >= 30) {
            data->unk_2A8 = 0;
        }

        idx = data->unk_2A8;

        data->unk_230[idx] = 1;
        data->unk_50[idx] = posX;
        data->unk_C8[idx] = posY;
        data->unk_140[idx] = posZ;
        data->unk_1B8[idx] = unk_14;

        dist = SQ(posX - tempX) + SQ(posY - tempY) + SQ(posZ - tempZ);
        if (dist != 0.0f) {
            dist = shim_sqrtf(dist);
        }

        data->unk_2AC[idx] = unk_2AC + dist;
    }
}

void fx_65_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_65_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/effect_65", fx_65_appendGfx);
