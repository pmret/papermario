#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000400_3D84C0[];
extern Gfx D_090005E8_3D86A8[];
extern Gfx D_09000628_3D86E8[];

Gfx* D_E00DC640[] = { D_09000628_3D86E8, D_090005E8_3D86A8 };
Gfx* D_E00DC648[] = { D_09000400_3D84C0, D_09000400_3D84C0 };

void huff_puff_breath_init(EffectInstance* effect);
void huff_puff_breath_update(EffectInstance* effect);
void huff_puff_breath_render(EffectInstance* effect);
void huff_puff_breath_appendGfx(void* effect);

EffectInstance* huff_puff_breath_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, f32 arg5, f32 arg6, s32 timeLeft) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    HuffPuffBreathFXData* data;
    s32 numParts = 1;

    effectBp.init = huff_puff_breath_init;
    effectBp.update = huff_puff_breath_update;
    effectBp.renderWorld = huff_puff_breath_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_HUFF_PUFF_BREATH;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.huffPuffBreath = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->lifeTime = 0;
    if (timeLeft <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = timeLeft;
    }

    data->unk_24 = 0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_4C = arg6;
    data->unk_18 = 255;
    data->unk_2C = 230;
    data->unk_1C = 255;
    data->unk_20 = 255;
    data->unk_28 = 255;
    data->unk_30 = 50;
    data->unk_34 = 255;
    data->unk_48 = arg4;
    data->unk_44 = 0;
    data->unk_3C = arg5;
    data->unk_38 = shim_rand_int(32);
    data->unk_40 = shim_rand_int(16);
    data->unk_20 = 150;
    data->unk_28 = 215;
    data->unk_2C = 210;
    data->unk_18 = 255;
    data->unk_1C = 255;
    data->unk_30 = 10;

    return effect;
}

void huff_puff_breath_init(EffectInstance* effect) {
}

void huff_puff_breath_update(EffectInstance* effect) {
    HuffPuffBreathFXData* data = effect->data.huffPuffBreath;
    s32 temp_a2;

    if (effect->flags & 16) {
        effect->flags &= ~16;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }
    temp_a2 = ++data->lifeTime;

    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (data->timeLeft < 16) {
        data->unk_24 = data->timeLeft * 16;
    }
    if (temp_a2 < 16) {
        data->unk_24 = (temp_a2 * 16) + 15;
    }
    data->unk_38 += data->unk_3C;
    if (data->unk_38 >= 256.0f) {
        data->unk_38 -= 256.0f;
    }
    if (data->unk_38 < 0.0f) {
        data->unk_38 += 256.0f;
    }
    data->unk_40 += data->unk_44;
    if (data->unk_40 >= 256.0f) {
        data->unk_40 -= 256.0f;
    }
    if (data->unk_40 < 0.0f) {
        data->unk_40 += 256.0f;
    }
}

void huff_puff_breath_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = huff_puff_breath_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00DC2FC(void) {
}

void huff_puff_breath_appendGfx(void* effect) {
    HuffPuffBreathFXData* data = ((EffectInstance*)effect)->data.huffPuffBreath;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_24 = data->unk_24;
    s32 unk_00 = data->unk_00;
    s32 uls = data->unk_38 * 4.0f;
    s32 ult = data->unk_40 * 4.0f;
    Matrix4f sp18;
    Matrix4f sp58;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    shim_guRotateF(sp58, data->unk_48, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guScaleF(sp58, data->unk_4C, data->unk_4C, data->unk_4C);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, unk_24);
    gDPSetEnvColor(gMasterGfxPos++, data->unk_28, data->unk_2C, data->unk_30, data->unk_34);
    gSPDisplayList(gMasterGfxPos++, D_E00DC648[unk_00]);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, uls, ult, uls + 31 * 4, ult + 15 * 4);
    gSPDisplayList(gMasterGfxPos++, D_E00DC640[unk_00]);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
