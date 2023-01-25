#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001000_3F9CC0[];
extern Gfx D_09001148_3F9E08[];
extern Gfx D_09001168_3F9E28[];

Gfx* D_E01108B0[] = { D_09001148_3F9E08 };
Gfx* D_E01108B4[] = { D_09001000_3F9CC0 };

void ice_shard_init(EffectInstance* effect);
void ice_shard_update(EffectInstance* effect);
void ice_shard_render(EffectInstance* effect);
void ice_shard_appendGfx(void* effect);

EffectInstance* ice_shard_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    IceShardFXData* data;
    s32 numParts = 1;

    bp.init = ice_shard_init;
    bp.update = ice_shard_update;
    bp.renderWorld = ice_shard_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_ICE_SHARD;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.iceShard = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.iceShard != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_24 = 255;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_38 = arg4;
    data->unk_18 = 255;
    data->unk_1C = 255;
    data->unk_20 = 255;
    data->unk_28 = 255;
    data->unk_2C = 255;
    data->unk_30 = 255;
    data->unk_34 = 255;
    data->unk_44 = 0;
    data->unk_48 = (shim_rand_int(1) * 2 - 1) * 0.25 * (shim_rand_int(4) * 0.1 + 0.1);
    data->unk_3C = shim_rand_int(359);
    data->unk_4C = shim_rand_int(10) - 5;
    data->unk_50 = shim_rand_int(10) - 5;
    data->unk_54 = shim_rand_int(10) - 5;
    data->unk_40 = shim_rand_int(40) - 20;
    data->unk_58 = -0.1f;

    return effect;
}

void ice_shard_init(EffectInstance* effect) {
}

void ice_shard_update(EffectInstance* effect) {
    IceShardFXData* data = effect->data.iceShard;
    s32 unk_00 = data->unk_00;

    if (effect->flags & EFFECT_INSTANCE_FLAG_10) {
        effect->flags &= ~EFFECT_INSTANCE_FLAG_10;
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

    if (data->unk_10 < 16) {
        data->unk_24 = data->unk_10 * 16;
    }

    data->unk_44 += data->unk_48;

    if (data->unk_44 < 0.0f) {
        data->unk_44 += 1.0f;
    }
    if (data->unk_44 > 1.0f) {
        data->unk_44 -= 1.0f;
    }

    data->unk_50 += data->unk_58;
    data->unk_04 += data->unk_4C;
    data->unk_08 += data->unk_50;
    data->unk_0C += data->unk_54;
    data->unk_3C += data->unk_40;

    if (unk_00 >= 2 && data->unk_08 < 0.0f && data->unk_50 < 0.0f) {
        data->unk_08 = 0.0f;
        data->unk_50 *= -0.7;
    }
}

void ice_shard_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = ice_shard_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void ice_shard_appendGfx(void* effect) {
    IceShardFXData* data = ((EffectInstance*)effect)->data.iceShard;
    s32 unk_24 = data->unk_24;
    s32 unk_00 = data->unk_00;
    s32 temp1;
    s32 temp2;
    s32 envAlpha;
    Matrix4f sp20;
    Matrix4f unused;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, data->unk_38, data->unk_04, data->unk_08, data->unk_0C);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    shim_guRotateF(sp20, data->unk_3C, 0.0f, 0.0f, 1.0f);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_E01108B4[0]);

    temp1 = (unk_00 % 2) * 32;
    temp2 = (s32) (data->unk_44 * 4.0f) * 32;
    envAlpha = (data->unk_44 * 4.0f - (s32) data->unk_44 * 4) * 256.0f;

    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE,
        (temp1     ) * 4, (temp2     ) * 4,
        (temp1 + 31) * 4, (temp2 + 31) * 4);
    gDPSetTileSize(gMasterGfxPos++, 1,
        (temp1     ) * 4, (temp2 + 32) * 4,
        (temp1 + 31) * 4, (temp2 + 63) * 4);

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, unk_24);
    gDPSetEnvColor(gMasterGfxPos++, data->unk_28, data->unk_2C, data->unk_30, envAlpha);
    gSPDisplayList(gMasterGfxPos++, D_E01108B0[0]);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

    if (unk_00 % 2 == 1 && (s32) (data->unk_44 * 4.0f) == 3) {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, unk_24 * envAlpha / 255);
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, SHADE, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, SHADE, 0, PRIMITIVE, 0);
        gSPDisplayList(gMasterGfxPos++, D_09001168_3F9E28);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
