#include "common.h"
#include "effects_internal.h"

void snowfall_init(EffectInstance* effect);
void snowfall_update(EffectInstance* effect);
void snowfall_render(EffectInstance* effect);
void snowfall_appendGfx(void* effect);

extern Gfx D_09000C00_38DC70[];
extern Gfx D_09000D50_38DDC0[];

Gfx* D_E008AA50[] = { D_09000D50_38DDC0, D_09000D50_38DDC0 };

void func_E008A000(SnowfallFXData* data) {
    Camera* camera = &gCameras[gCurrentCameraID];

    data->unk_08 = (camera->lookAt_eye.x + effect_rand_int(2000)) - 1000.0f;
    data->unk_0C = (camera->lookAt_eye.y + effect_rand_int(2000)) - 1000.0f;
    data->unk_10 = (camera->lookAt_eye.z + effect_rand_int(2000)) - 1000.0f;
    data->unk_14 = (effect_rand_int(20) - 10.0f) * 0.05;
    data->unk_18 = -1.2 - (effect_rand_int(80) * 0.01);
    data->unk_1C = (effect_rand_int(20) - 10.0f) * 0.05;
    data->unk_28 = 255;
}

EffectInstance* snowfall_main(s32 arg0, s32 arg1) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    SnowfallFXData* data;
    s32 numParts = arg1 + 1;
    s32 i;

    effectBp.init = snowfall_init;
    effectBp.update = snowfall_update;
    effectBp.renderScene = snowfall_render;
    effectBp.unk_00 = 0;
    effectBp.renderUI = NULL;
    effectBp.effectID = EFFECT_SNOWFALL;

    effect = create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.snowfall = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->timeLeft = 100;
    data->lifeTime = 0;
    data->unk_28 = 255;
    data->unk_04 = arg0;
    data->unk_2C = arg1;
    data->unk_00 = 1;

    data++;
    for (i = 0; i < arg1; i++, data++) {
        func_E008A000(data);
        data->unk_30 = 0;
    }

    return effect;
}

void snowfall_init(EffectInstance* effect) {
}

void func_E008A290(SnowfallFXData* data, s32 arg1, s32 arg2, s32 arg3) {
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 unk_08 = data->unk_08;
    f32 unk_0C = data->unk_0C;
    f32 unk_10 = data->unk_10;
    f32 lookX = camera->lookAt_obj.x;
    f32 lookY = camera->lookAt_obj.y;
    f32 lookZ = camera->lookAt_obj.z;
    s32 temp_f12;
    s32 temp_f12_2;
    s32 temp_f12_3;

    temp_f12 = unk_08 - lookX;
    if (arg1 < temp_f12) {
        temp_f12 = temp_f12 % arg1;
        data->unk_08 = (lookX - arg1) + temp_f12;
    } else if (-arg1 > temp_f12) {
        temp_f12 = -temp_f12;
        temp_f12 = temp_f12 % arg1;
        data->unk_08 = (lookX + arg1) - temp_f12;
    }

    temp_f12_2 = unk_0C - lookY;
    if (arg2 < temp_f12_2) {
        temp_f12_2 = temp_f12_2 % arg2;
        data->unk_0C = (lookY - arg2) + temp_f12_2;
    } else if (temp_f12_2 < -arg2) {
        if (arg3 < 100) {
            data->unk_18 = 0;
            data->unk_28 = 0;
        } else {
            temp_f12_2 = -temp_f12_2;
            temp_f12_2 = temp_f12_2 % arg2;
            data->unk_0C = (lookY + arg2) - temp_f12_2;
        }
    }

    temp_f12_3 = unk_10 - lookZ;
    if (arg1 < temp_f12_3) {
        temp_f12_3 = temp_f12_3 % arg1;
        data->unk_10 = (lookZ - arg1) + temp_f12_3;
    } else if (temp_f12_3 < -arg1) {
        temp_f12_3 = -temp_f12_3;
        temp_f12_3 = temp_f12_3 % arg1;
        data->unk_10 = (lookZ + arg1) - temp_f12_3;
    }
}

void snowfall_update(EffectInstance* effect) {
    Camera* camera = &gCameras[gCurrentCameraID];
    SnowfallFXData* data = effect->data.snowfall;
    s32 timeLeft;
    s32 boomLength;
    s32 temp_s5;
    s32 temp_s6;
    s32 i;

    if (data->timeLeft < 100) {
        data->timeLeft--;
    }
    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    data->lifeTime++;
    timeLeft = data->timeLeft;
    temp_s5 = data->unk_2C;
    if (timeLeft < 10) {
        data->unk_28 = timeLeft * 25;
    }
    boomLength = camera->curBoomLength;
    temp_s6 = (boomLength * 0.3) + 1.0;

    data++;
    for (i = 0; i < temp_s5; i++, data++) {
        if (data->unk_30 <= 0 || --data->unk_30 <= 0) {
            data->unk_08 += data->unk_14;
            data->unk_0C += data->unk_18;
            data->unk_10 += data->unk_1C;
            func_E008A290(data, boomLength, temp_s6, timeLeft);
        }
    }
}

void snowfall_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = snowfall_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void snowfall_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    SnowfallFXData* data = effectTemp->data.snowfall;
    Matrix4f sp18;
    Gfx* dlist;
    Mtx* mtx;
    u8 bgRGB;
    u8 bgAlpha;
    s32 unk_28;
    s32 unk_2C;
    s32 i;

    if (data->unk_00 != 0) {
        unk_28 = data->unk_28;
        bgAlpha = 255;
        unk_2C = data->unk_2C;
        dlist = D_E008AA50[data->unk_04];
        if (*gBackgroundTintModePtr == ENV_TINT_SHROUD) {
            mdl_get_shroud_tint_params(&bgRGB, &bgRGB, &bgRGB, &bgAlpha);
            unk_28 = 255 - bgAlpha;
        }

        if (unk_28 != 0) {
            gDPPipeSync(gMainGfxPos++);
            gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

            gSPDisplayList(gMainGfxPos++, D_09000C00_38DC70);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, unk_28);

            guRotateF(sp18, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            mtx = &gDisplayContext->matrixStack[gMatrixListPos++];

            data++;
            for (i = 0; i < unk_2C; i++, data++) {
                if (data->unk_30 <= 0 && data->unk_28 != 0) {
                    guTranslateF(sp18, data->unk_08, data->unk_0C, data->unk_10);
                    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

                    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPMatrix(gMainGfxPos++, mtx,
                              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                    gSPDisplayList(gMainGfxPos++, dlist);
                    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
                }
            }
            gDPPipeSync(gMainGfxPos++);
        }
    }
}
