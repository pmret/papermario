#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001000_3DDD50[];
extern Vtx_t D_090010A8_3DDDF8[];

Gfx* D_E00E29F0[] = { D_09001000_3DDD50 };

u8 D_E00E29F4[] = {
    120, 130, 140, 150, 160, 170, 180, 190, 200, 200,
    190, 180, 170, 160, 150, 140, 130
};

u8 D_E00E2A08[] = {
    170, 160, 150, 140, 130, 120, 130, 140, 150, 160,
    170, 180, 190, 200, 200, 190, 180
};

u8 D_E00E2A1C[] = {
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255
};

void hieroglyphs_init(EffectInstance* effect);
void hieroglyphs_update(EffectInstance* effect);
void hieroglyphs_render(EffectInstance* effect);
void hieroglyphs_appendGfx(void* effect);

EffectInstance* hieroglyphs_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 timeLeft) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    HieroglyphsFXData* data;
    s32 numParts = 1;

    effectBp.init = hieroglyphs_init;
    effectBp.update = hieroglyphs_update;
    effectBp.renderWorld = hieroglyphs_render;
    effectBp.unk_00 = 0;
    effectBp.renderUI = NULL;
    effectBp.effectID = EFFECT_HIEROGLYPHS;

    effect = create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.hieroglyphs = general_heap_malloc(numParts * sizeof(*data));
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
    data->unk_38 = arg4;
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 120;
    data->unk_28 = 20;
    data->unk_2C = 230;
    data->unk_30 = 50;
    data->unk_34 = 255;

    return effect;
}

void hieroglyphs_init(EffectInstance* effect) {
}

void hieroglyphs_update(EffectInstance* effect) {
    HieroglyphsFXData* data = effect->data.hieroglyphs;
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
        data->unk_24 = data->timeLeft * 16;
    }
    if (temp_a2 < 16) {
        data->unk_24 = (temp_a2 * 16) + 15;
    }
}

void hieroglyphs_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = hieroglyphs_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00E2210(void) {
}

void hieroglyphs_appendGfx(void* effect) {
    HieroglyphsFXData* data = ((EffectInstance*)effect)->data.hieroglyphs;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 lifeTime = data->lifeTime;
    s32 unk_24 = data->unk_24;
    Gfx* savedGfxPos;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp20, data->pos.x, data->pos.y, data->pos.z);
    guScaleF(sp60, data->unk_38, data->unk_38, data->unk_38);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, unk_24);
    gDPSetEnvColor(gMainGfxPos++, data->unk_28, data->unk_2C, data->unk_30, data->unk_34);
    gSPDisplayList(gMainGfxPos++, D_E00E29F0[0]);
    gSPBranchList(gMainGfxPos, gMainGfxPos + 52);

    savedGfxPos = gMainGfxPos + 1;

    gDPSetTileSize(savedGfxPos, G_TX_RENDERTILE,
        (lifeTime * 2      ) * 4, 0,
        (lifeTime * 2 + 127) * 4, 31 * 4);
    gMainGfxPos += 2;

    guRotateF(sp20, 20.0f, 1.0f, 0.0f, 0.0f);
    guPositionF(sp60, 0.0f, sin_deg(lifeTime * 8 + 78.75) * -30.0f, 0.0f, 1.0f, 6.0f, 0.0f, 0.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    for (i = 0; i < 16; i++) {
        f32 angle = i * 48 + lifeTime * 8;

        guPositionF(sp20, 0.0f, sin_deg(angle) * 30.0f, 6.0f, (f32) i * 0.01 + 1.0, 8.0f, 0.0f, 0.0f);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPVertex(gMainGfxPos++, &D_090010A8_3DDDF8[i * 2], 2, i * 2);
    }

    for (i = 0; i < 15; i++) {
        s32 i2 = i * 2;
        gSP2Triangles(gMainGfxPos++,
            i2    , i2 + 2, i2 + 1, i2,
            i2 + 1, i2 + 2, i2 + 3, i2);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPEndDisplayList(gMainGfxPos++);

    for (i = 0; i < 2; i++) {
        s32 idx = (lifeTime + i * 4) % 17;

        guPositionF(sp20, 0.0f, 0.0f, -0x11A + i * 0x24, 1.0f, 0.0f, 0.0f, 0.0f);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E00E29F4[idx], D_E00E2A08[idx], D_E00E2A1C[idx], data->unk_24);
        gDPSetEnvColor(gMainGfxPos++, 255, 255, 255, 0);
        gSPDisplayList(gMainGfxPos++, savedGfxPos);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
