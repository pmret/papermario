#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000400_3D2980[];
extern Gfx D_09000518_3D2A98[];

u8 D_E00CCDD0[] = { 94, 92, 100, 105, 107, 105, 100 };

u8 D_E00CCDD8[] = { 20, 40, 58, 73, 85, 92, 97, 100 };

u8 D_E00CCDE0[] = {
     0,  2,  5,  9,  14, 20, 27, 35, 44, 54,
    64, 74, 84, 94, 100
};

u8 D_E00CCDF0[] = {
      0,  10,  20,  30,  40,  50,  60,  70,  80,  90,
    100, 109, 117, 124, 130, 135, 139, 142, 144, 145
};

u8 D_E00CCE04[] = {
    100, 100, 100, 100, 100, 100, 100, 100, 101, 102,
    102, 103, 103, 104, 104, 104, 107, 107, 110, 110,
    118, 118, 126, 126, 134, 142, 145, 145, 145, 142,
    134, 126, 126, 118, 118, 110, 110, 105, 105, 105,
    102, 103, 103, 104, 104, 104, 107, 107, 110, 110,
    118, 118, 126, 126, 134, 142, 145, 145, 145, 142,
    134, 126, 126, 118, 118, 110, 110, 105, 105, 105
};

s8 D_E00CCE4C[] = {
    -5, -5, -5, -4, -4, -4, -3, -3, -2, -2,
    -1, -1,  0,  0,  1,  2,  2,  3,  3,  4,
     4,  4,  5,  5,  5
};

void tubba_heart_attack_init(EffectInstance* effect);
void tubba_heart_attack_update(EffectInstance* effect);
void tubba_heart_attack_render(EffectInstance* effect);
void tubba_heart_attack_appendGfx(void* effect);

EffectInstance* tubba_heart_attack_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    TubbaHeartAttackFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = tubba_heart_attack_init;
    bp.update = tubba_heart_attack_update;
    bp.renderWorld = tubba_heart_attack_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_TUBBA_HEART_ATTACK;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.tubbaHeartAttack = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.tubbaHeartAttack != NULL);

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
    data->unk_28 = arg4;
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 120;

    for (i = 0; i < 25; i++) {
        f32 sin = sin_deg(i * 1080 / 25);
        f32 cos = cos_deg(i * 1080 / 25);

        data->unk_478[i] = rand_int(359) - 180;
        data->unk_284[i] = sin * 15.0f;
        data->unk_2E8[i] = D_E00CCE4C[i] + 10;
        data->unk_34C[i] = cos * 15.0f;
        data->unk_158[i] = sin * 120.0f;
        data->unk_1BC[i] = D_E00CCE4C[i] * 8 + 40;
        data->unk_220[i] = cos * 120.0f;
        data->unk_66C[i] = i * 2 + 1;
        data->unk_5A4[i] = 0;
        data->unk_6D0[i] = 0;
        data->unk_734[i] = 0;
        data->unk_4DC[i] = 0;
    }

    return effect;
}

void tubba_heart_attack_init(EffectInstance* effect) {
}

EFFECT_DEF_FLOATING_CLOUD_PUFF(floating_cloud_puff_main);

void tubba_heart_attack_update(EffectInstance* effect) {
    TubbaHeartAttackFXData* data = effect->data.tubbaHeartAttack;
    EffectInstance* puffEffect;
    s32 unk_00 = data->unk_00;
    s32 unk_14;
    f32 factor;
    f32 angle;
    f32 sin;
    f32 cos;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;
    s32 j;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 64;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_14 = data->unk_14;

    for (i = 0; i < 25; i++) {
        f32 unk_158 = data->unk_158[i];
        f32 unk_1BC = data->unk_1BC[i];
        f32 unk_220 = data->unk_220[i];

        data->unk_414[i] = D_E00CCDD0[unk_14 % ARRAY_COUNT(D_E00CCDD0)] * 0.01f;
        data->unk_3B0[i] = 2.0f - data->unk_414[i];

        switch (data->unk_6D0[i]) {
            case 0:
                data->unk_2C[i] = unk_158;
                data->unk_90[i] = unk_1BC;
                data->unk_F4[i] = unk_220;
                data->unk_4DC[i] += 0.0f;

                if (data->unk_66C[i] != 0) {
                    data->unk_66C[i]--;
                } else {
                    data->unk_6D0[i] = 1;
                    data->unk_3B0[i] = data->unk_414[i] = D_E00CCDD8[data->unk_734[i]] * 0.01;
                    data->unk_734[i]++;
                }

                break;
            case 1:
                data->unk_3B0[i] = data->unk_414[i] = D_E00CCDD8[data->unk_734[i]] * 0.01;
                data->unk_4DC[i] += 0.0f;

                data->unk_734[i]++;
                if (data->unk_734[i] >= ARRAY_COUNT(D_E00CCDD8)) {
                    if (unk_00 == 0) {
                        data->unk_6D0[i] = 2;
                    } else {
                        data->unk_6D0[i] = 20;
                    }
                    data->unk_734[i] = 0;
                }

                break;
            case 20:
                data->unk_4DC[i] += 0.0f;

                factor = D_E00CCDF0[data->unk_734[i]] * 0.01;

                data->unk_3B0[i] = data->unk_414[i] = 1.0f;
                data->unk_2C[i] = unk_158 + (data->unk_284[i] - unk_158) * factor;
                data->unk_90[i] = unk_1BC + (data->unk_2E8[i] - unk_1BC) * factor;
                data->unk_F4[i] = unk_220 + (data->unk_34C[i] - unk_220) * factor;

                data->unk_734[i]++;
                if (data->unk_734[i] >= ARRAY_COUNT(D_E00CCDF0)) {
                    data->unk_6D0[i] = 5;
                    data->unk_734[i] = 0;
                    data->unk_540[i] = data->unk_284[i] * 0.5;
                    data->unk_5A4[i] = data->unk_2E8[i] * 0.5;
                    data->unk_608[i] = data->unk_34C[i] * 0.5;
                }

                break;
            case 2:
                data->unk_4DC[i] += 0.0f;

                factor = D_E00CCDE0[data->unk_734[i]] * 0.01;

                data->unk_414[i] = 1.0f;
                data->unk_3B0[i] = 1.0f;
                data->unk_2C[i] = unk_158 + (data->unk_284[i] - unk_158) * factor;
                data->unk_90[i] = unk_1BC + (data->unk_2E8[i] - unk_1BC) * factor;
                data->unk_F4[i] = unk_220 + (data->unk_34C[i] - unk_220) * factor;

                data->unk_734[i]++;
                if (data->unk_734[i] >= ARRAY_COUNT(D_E00CCDE0)) {
                    data->unk_6D0[i] = 3;
                    data->unk_734[i] = 0;
                }

                break;
            case 3:
                if (i == 24) {
                    for (j = 0; j < ARRAY_COUNT(data->unk_6D0); j++) {
                        data->unk_6D0[j] = 4;
                    }
                }

                break;
            case 4:
                factor = D_E00CCE04[data->unk_734[i]] * 0.01;
                angle = i * 1080 / 25 + (1.0f - factor) * 1080.0f * 0.5 * cos_deg(i * 180 / 25);
                sin = sin_deg(angle);
                cos = cos_deg(angle);

                data->unk_2C[i] = ((15.0f / factor) / factor) * sin;
                data->unk_90[i] = D_E00CCE4C[i] + 10;
                data->unk_F4[i] = ((15.0f / factor) / factor) * cos;

                data->unk_734[i]++;
                if (data->unk_734[i] >= ARRAY_COUNT(D_E00CCE04)) {
                    data->unk_6D0[i] = 5;
                    data->unk_734[i] = 0;
                    data->unk_540[i] = data->unk_284[i] * 0.5;
                    data->unk_5A4[i] = data->unk_2E8[i] * 0.5;
                    data->unk_608[i] = data->unk_34C[i] * 0.5;
                }

                break;
            case 5:
                data->unk_2C[i] += data->unk_540[i];
                data->unk_90[i] += data->unk_5A4[i];
                data->unk_F4[i] += data->unk_608[i];
                data->unk_540[i] *= 0.99;
                data->unk_5A4[i] *= 0.99;
                data->unk_608[i] *= 0.99;
                data->unk_5A4[i] += -0.1;

                data->unk_734[i]++;
                if (data->unk_734[i] >= 17) {
                    data->unk_734[i] = 0;
                    data->unk_6D0[i] = 6;
                }

                data->unk_478[i] *= 0.9;

                break;
            case 6:
                load_effect(EFFECT_FLOATING_CLOUD_PUFF);
                guRotateF(sp18, data->unk_4DC[i], 0.0f, 1.0f, 0.0f);
                guTranslateF(sp58, data->unk_2C[i], data->unk_90[i], data->unk_F4[i]);
                guMtxCatF(sp58, sp18, sp18);

                puffEffect = floating_cloud_puff_main(0, data->unk_04 + sp18[3][0], data->unk_08 + sp18[3][1], data->unk_0C + sp18[3][2], 1.0f, 16);
                puffEffect->data.floatingCloudPuff->unk_28 = 100;
                puffEffect->data.floatingCloudPuff->unk_2C = 0;
                puffEffect->data.floatingCloudPuff->unk_30 = 0;

                data->unk_6D0[i] = 7;

                break;
        }
    }
}

void tubba_heart_attack_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = tubba_heart_attack_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00CC9C8(void) {
}

void tubba_heart_attack_appendGfx(void* effect) {
    TubbaHeartAttackFXData* data = ((EffectInstance*)effect)->data.tubbaHeartAttack;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_24 = data->unk_24;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp18, data->unk_04, data->unk_08, data->unk_0C);
    guScaleF(sp58, data->unk_28, data->unk_28, data->unk_28);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, unk_24);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, 0);
    gSPDisplayList(gMainGfxPos++, D_09000400_3D2980);

    for (i = 0; i < 25; i++) {
        if (data->unk_6D0[i] != 0 && data->unk_6D0[i] != 7) {
            guRotateF(sp18, data->unk_4DC[i], 0.0f, 1.0f, 0.0f);
            guTranslateF(sp58, data->unk_2C[i], data->unk_90[i], data->unk_F4[i]);
            guMtxCatF(sp58, sp18, sp18);
            guRotateF(sp58, -data->unk_4DC[i], 0.0f, 1.0f, 0.0f);
            guMtxCatF(sp58, sp18, sp18);
            guRotateF(sp58, data->unk_478[i], 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp58, sp18, sp18);
            guScaleF(sp58, data->unk_3B0[i], data->unk_414[i], 1.0f);
            guMtxCatF(sp58, sp18, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPMatrix(gMainGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_09000518_3D2A98);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
