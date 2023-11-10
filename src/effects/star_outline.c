#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000800_4147A0[];
extern Gfx D_09000B20_414AC0[];
extern Gfx D_09000B90_414B30[];

Gfx* D_E0126BC0[] = { D_09000B90_414B30 };
Gfx* D_E0126BC4[] = { D_09000B20_414AC0 };
Gfx* D_E0126BC8[] = { D_09000800_4147A0 };

void star_outline_init(EffectInstance* effect);
void star_outline_update(EffectInstance* effect);
void star_outline_render(EffectInstance* effect);
void star_outline_appendGfx(void* effect);

EffectInstance* star_outline_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 arg5) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    StarOutlineFXData* data;
    s32 numParts = 1;

    effectBp.init = star_outline_init;
    effectBp.update = star_outline_update;
    effectBp.renderWorld = star_outline_render;
    effectBp.unk_00 = 0;
    effectBp.renderUI = NULL;
    effectBp.effectID = EFFECT_STAR_OUTLINE;

    effect = create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.starOutline = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = 1;
    data->unk_02 = arg0;
    data->lifeTime = 0;
    if (arg5 <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = arg5;
    }
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_38 = arg4;
    data->unk_18 = 255;
    data->unk_1C = 255;
    data->unk_20 = 120;
    data->unk_28 = 255;
    data->unk_2C = 120;
    data->unk_30 = 0;
    data->unk_34 = 255;
    data->unk_24 = 255;
    data->unk_3C.x = 0;
    data->unk_3C.y = 0;
    data->unk_3C.z = 0;

    return effect;
}

void star_outline_init(EffectInstance* effect) {
}

void star_outline_update(EffectInstance* effect) {
    StarOutlineFXData* data = effect->data.starOutline;
    s32 temp_a2 = data->unk_02;
    s32 lifeTime;
    s32 temp;
    s32 temp2;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifeTime++;

    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }
    lifeTime = data->lifeTime;
    if (data->timeLeft < 16) {
        temp = data->timeLeft * 16;
        if (data->unk_24 > temp) {
            data->unk_24 = temp;
        }
        if (data->unk_34 > temp) {
            data->unk_34 = temp;
        }
    }
    if (lifeTime < 16) {
        temp2 = (lifeTime * 16) + 15;
        if (data->unk_24 < temp2) {
            data->unk_24 = temp2;
        }
        if (data->unk_34 < temp2) {
            data->unk_34 = temp2;
        }
    }
    data->unk_48 = data->unk_3C.x;
    data->unk_4C = data->unk_3C.y;
    data->unk_50 = data->unk_3C.z;
    data->unk_54 = data->unk_38;
    if (temp_a2 == 1) {
        f32 lifetimeF = lifeTime;

        data->unk_3C.x = lifeTime * 4;
        data->unk_24 = 255;
        data->unk_3C.y = (lifeTime * 4.0f * 0.4953);
        data->unk_3C.z = (lifeTime * 4.0f * 0.2234);
        data->unk_34 = ((sin_deg (lifetimeF * 7.12343)) * 127.0f) + 128.0f;
        data->unk_18 = ((sin_deg (lifetimeF * 1.231)) * 127.0f) + 215.0f;
        data->unk_1C = ((sin_deg (lifetimeF * 0.531)) * 127.0f) + 215.0f;
        data->unk_20 = ((sin_deg (lifetimeF * 3.231)) * 127.0f) + 215.0f;
        data->unk_28 = ((sin_deg (lifetimeF * 0.298)) * 127.0f) + 188.0f;
        data->unk_2C = ((sin_deg (lifetimeF * 0.831)) * 127.0f) + 188.0f;
        data->unk_30 = ((sin_deg (lifetimeF * 2.231)) * 127.0f) + 188.0f;
        data->unk_38 = ((sin_deg (lifetimeF * 2.044)) * 0.3) + 0.7;
    }
    if (lifeTime == 1) {
        data->unk_48 = data->unk_3C.x;
        data->unk_4C = data->unk_3C.y;
        data->unk_50 = data->unk_3C.z;
        data->unk_54 = data->unk_38;
    }
}

void star_outline_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = star_outline_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void star_outline_appendGfx(void* effect) {
    StarOutlineFXData* data = ((EffectInstance*)effect)->data.starOutline;
    s32 unk_18 = data->unk_18;
    s32 unk_1C = data->unk_1C;
    s32 unk_20 = data->unk_20;
    s32 unk_24 = data->unk_24;
    s32 unk_28 = data->unk_28;
    s32 unk_2C = data->unk_2C;
    s32 unk_30 = data->unk_30;
    s32 unk_34 = data->unk_34;
    Matrix4f sp20;
    Matrix4f sp60;

    if (unk_18 > 255) {
        unk_18 = 255;
    }
    if (unk_1C > 255) {
        unk_1C = 255;
    }
    if (unk_20 > 255) {
        unk_20 = 255;
    }
    if (unk_24 > 255) {
        unk_24 = 255;
    }
    if (unk_28 > 255) {
        unk_28 = 255;
    }
    if (unk_2C > 255) {
        unk_2C = 255;
    }
    if (unk_30 > 255) {
        unk_30 = 255;
    }
    if (unk_34 > 255) {
        unk_34 = 255;
    }
    if (unk_18 < 0) {
        unk_18 = 0;
    }
    if (unk_1C < 0) {
        unk_1C = 0;
    }
    if (unk_20 < 0) {
        unk_20 = 0;
    }
    if (unk_24 < 0) {
        unk_24 = 0;
    }
    if (unk_28 < 0) {
        unk_28 = 0;
    }
    if (unk_2C < 0) {
        unk_2C = 0;
    }
    if (unk_30 < 0) {
        unk_30 = 0;
    }
    if (unk_34 < 0) {
        unk_34 = 0;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_E0126BC8[0]);

    if (unk_34 != 0) {
        guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, (f32) ((f64) data->unk_54 * 0.4), data->pos.x, data->pos.y, data->pos.z);
        guPositionF(sp60, data->unk_48, data->unk_4C, data->unk_50, 1.0f, 0.0f, 0.0f, 0.0f);
        guMtxCatF(sp60, sp20, sp20);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        if (data->unk_00 == 0) {
            gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        } else {
            gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
        }

        gDPSetPrimColor(gMainGfxPos++, 0, 0, unk_18, unk_1C, unk_20, unk_34 >> 1);
        gDPSetEnvColor(gMainGfxPos++, unk_28, unk_2C, unk_30, unk_34 >> 1);
        gSPDisplayList(gMainGfxPos++, D_E0126BC4[0]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, data->unk_38 * 0.4, data->pos.x, data->pos.y, data->pos.z);
    guPositionF(sp60, data->unk_3C.x, data->unk_3C.y, data->unk_3C.z, 1.0f, 0.0f, 0.0f, 0.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (unk_34 != 0) {
        if (data->unk_00 == 0) {
            gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        } else {
            gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
        }
        gSPDisplayList(gMainGfxPos++, D_E0126BC4[0]);
    }

    if (data->unk_00 == 0) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, unk_18, unk_1C, unk_20, unk_24);
    gDPSetEnvColor(gMainGfxPos++, unk_28, unk_2C, unk_30, unk_24);
    gSPDisplayList(gMainGfxPos++, D_E0126BC0[0]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
