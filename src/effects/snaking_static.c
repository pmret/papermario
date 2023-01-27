#include "common.h"
#include "effects_internal.h"

void snaking_static_update(EffectInstance*);
void snaking_static_init(EffectInstance* effect);
void snaking_static_render(EffectInstance* effect);
void snaking_static_appendGfx(void* effect);

extern Gfx D_09001000_3B3D90[];
extern Gfx D_090010F8_3B3E88[];

EffectInstance* snaking_static_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 timeLeft) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    SnakingStaticFXData* data;
    s32 numParts = 22;
    s32 i;

    effectBp.init = snaking_static_init;
    effectBp.update = snaking_static_update;
    effectBp.renderWorld = snaking_static_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_SNAKING_STATIC;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.snakingStatic = shim_general_heap_malloc(numParts * sizeof(*data));
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

    data->unk_18 = 255;
    data->unk_1C = 230;
    data->unk_20 = 0;

    data->unk_28 = 255;
    data->unk_2C = 255;
    data->unk_30 = 255;

    data++;
    for(i = 1; i < numParts; i++, data++) {
        data->timeLeft = 20;
        data->unk_3C = (i - 1) * 360 / (numParts - 1);
        data->lifeTime = 0;
        data->pos.x = 0;
        data->pos.y = 0;
        data->unk_34 = 1.0f;
        data->unk_40 = i & 15;
    }

    return effect;

}

void snaking_static_init(EffectInstance* effect) {
}

void snaking_static_update(EffectInstance* effect) {
    SnakingStaticFXData* data = effect->data.snakingStatic;
    f32 tempOffsetY;
    f32 tempOffsetX;
    f32 tempPosX;
    f32 tempPosY;
    s32 lifeTime;
    s32 timeLeft;
    s32 i;

    if (effect->flags & 16) {
        effect->flags &= ~16;
        data->timeLeft = 16;
    }

    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    timeLeft = data->timeLeft;
    data->lifeTime++;
    lifeTime = data->lifeTime;

    if (timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (timeLeft < 16) {
        data->unk_24 = timeLeft * 16;
    }
    if (lifeTime < 16) {
        data->unk_24 = (lifeTime * 16) + 15;
    }

    data++;
    for (i = 1; i < effect->numParts; i += 3, data += 3) {
        if (data->lifeTime >= data->timeLeft) {
            data->timeLeft = shim_rand_int(50) + 20;
            data->lifeTime = 0;
            data->unk_3C = shim_rand_int(360);
            data->pos.x = 0.0f;
            data->pos.y = 0.0f;
        }
        if (shim_rand_int(100) < 51) {
            tempPosX = data->pos.x;
            tempPosY = data->pos.y;
            tempOffsetX = shim_rand_int(16) - 8;
            tempOffsetY = shim_rand_int(16) - 8;
            data[2] = data[1];
            data[1] = data[0];
            data->pos.x = tempPosX + tempOffsetX;
            data->pos.y = tempPosY + tempOffsetY;
            data->unk_3C = shim_atan2(0.0f, 0.0f, tempOffsetX, tempOffsetY);
            if (tempOffsetX != 0.0f || tempOffsetY != 0.0f) {
                data->unk_34 = shim_sqrtf((tempOffsetX * tempOffsetX) + (tempOffsetY * tempOffsetY));
            } else {
                data->unk_34 = 0.0f;
            }
        }
        data->unk_24 = (shim_sin_deg(((data->lifeTime * 180) / data->timeLeft)) * 1024.0f);
        if (data->unk_24 >= 256) {
            data->unk_24 = 255;
        }
        data->lifeTime++;
    }
    data = effect->data.snakingStatic;
    data++;
    for (i = 1; i < effect->numParts; i++, data++) {
        data->unk_40 = shim_rand_int(15);
    }
}

void snaking_static_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = snaking_static_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00AE544(void) {
}

void snaking_static_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    SnakingStaticFXData* data = effectTemp->data.snakingStatic;
    Camera* camera = &gCameras[gCurrentCameraID];
    Matrix4f sp18, sp58;
    s32 lifeTime = data->lifeTime;
    s32 unk_24 = data->unk_24;
    s32 primR = data->unk_18;
    s32 primG = data->unk_1C;
    s32 primB = data->unk_20;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    shim_guScaleF(sp58, data->unk_38, data->unk_38, data->unk_38);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetEnvColor(gMasterGfxPos++, data->unk_28, data->unk_2C, data->unk_30, 0);
    gSPDisplayList(gMasterGfxPos++, D_09001000_3B3D90);

    data++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, primR, primG, primB, (data->unk_24 * unk_24) / 255);
        shim_guTranslateF(sp18, data->pos.x, data->pos.y, 0.0f);
        shim_guRotateF(sp58, data->unk_3C, 0.0f, 0.0f, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guScaleF(sp58, data->unk_34 * 0.0625f, data->unk_34 * 0.0625f, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, data->unk_40 * 64, 0, (data->unk_40 * 64) | 0x3C, 0x007C);
        gDPSetTileSize(gMasterGfxPos++, 1, (lifeTime * 12), 0, ((lifeTime * 3) + 0x1F) * 4, 0x007C);

        gSPDisplayList(gMasterGfxPos++, D_090010F8_3B3E88);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
    gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
