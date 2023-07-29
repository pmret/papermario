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

EffectInstance* huff_puff_breath_main(s32 type, f32 posX, f32 posY, f32 posZ, f32 angle, f32 speed, f32 scale, s32 timeLeft) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    HuffPuffBreathFXData* data;
    s32 numParts = 1;

    effectBp.init = huff_puff_breath_init;
    effectBp.update = huff_puff_breath_update;
    effectBp.renderWorld = huff_puff_breath_render;
    effectBp.unk_00 = 0;
    effectBp.renderUI = NULL;
    effectBp.effectID = EFFECT_HUFF_PUFF_BREATH;

    effect = create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.huffPuffBreath = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->type = type;
    data->lifeTime = 0;
    if (timeLeft <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = timeLeft;
    }

    data->primA = 0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->scale = scale;
    data->primR = 255;
    data->envG = 230;
    data->primG = 255;
    data->primB = 255;
    data->envR = 255;
    data->envB = 50;
    data->envA = 255;
    data->angle = angle;
    data->speedY = 0;
    data->speedX = speed;
    data->texOffsetX = rand_int(32);
    data->texOffsetY = rand_int(16);
    data->primB = 150;
    data->envR = 215;
    data->envG = 210;
    data->primR = 255;
    data->primG = 255;
    data->envB = 10;

    return effect;
}

void huff_puff_breath_init(EffectInstance* effect) {
}

void huff_puff_breath_update(EffectInstance* effect) {
    HuffPuffBreathFXData* data = effect->data.huffPuffBreath;
    s32 temp_a2;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }
    temp_a2 = ++data->lifeTime;

    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }
    if (data->timeLeft < 16) {
        data->primA = data->timeLeft * 16;
    }
    if (temp_a2 < 16) {
        data->primA = (temp_a2 * 16) + 15;
    }
    data->texOffsetX += data->speedX;
    if (data->texOffsetX >= 256.0f) {
        data->texOffsetX -= 256.0f;
    }
    if (data->texOffsetX < 0.0f) {
        data->texOffsetX += 256.0f;
    }
    data->texOffsetY += data->speedY;
    if (data->texOffsetY >= 256.0f) {
        data->texOffsetY -= 256.0f;
    }
    if (data->texOffsetY < 0.0f) {
        data->texOffsetY += 256.0f;
    }
}

void huff_puff_breath_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = huff_puff_breath_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
}

void func_E00DC2FC(void) {
}

void huff_puff_breath_appendGfx(void* effect) {
    HuffPuffBreathFXData* data = ((EffectInstance*)effect)->data.huffPuffBreath;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 primA = data->primA;
    s32 unk_00 = data->type;
    s32 uls = data->texOffsetX * 4.0f;
    s32 ult = data->texOffsetY * 4.0f;
    Matrix4f sp18;
    Matrix4f sp58;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp58, data->angle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guScaleF(sp58, data->scale, data->scale, data->scale);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primR, data->primG, data->primB, primA);
    gDPSetEnvColor(gMainGfxPos++, data->envR, data->envG, data->envB, data->envA);
    gSPDisplayList(gMainGfxPos++, D_E00DC648[unk_00]);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, uls, ult, uls + 31 * 4, ult + 15 * 4);
    gSPDisplayList(gMainGfxPos++, D_E00DC640[unk_00]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
