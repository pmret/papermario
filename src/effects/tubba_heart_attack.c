#include "common.h"
#include "effects_internal.h"

enum MiniHeartState {
    HEART_STATE_INIT        = 0,
    HEART_STATE_APPEAR      = 1,
    HEART_STATE_SWARM       = 2,
    HEART_STATE_MISS        = 20,
    HEART_STATE_WAIT        = 3,
    HEART_STATE_SQUEEZE     = 4,
    HEART_STATE_DISPERSE    = 5,
    HEART_STATE_VANISH      = 6,
    HEART_STATE_DONE        = 7,
};

extern Gfx D_09000400_3D2980[];
extern Gfx D_09000518_3D2A98[];

u8 AnimScalePct[] = { 94, 92, 100, 105, 107, 105, 100 };

u8 AppearScalePct[] = { 20, 40, 58, 73, 85, 92, 97, 100 };

u8 SwarmInterpPct[] = {
     0,  2,  5,  9,  14, 20, 27, 35, 44, 54,
    64, 74, 84, 94, 100
};

u8 MissInterpPct[] = {
      0,  10,  20,  30,  40,  50,  60,  70,  80,  90,
    100, 109, 117, 124, 130, 135, 139, 142, 144, 145
};

u8 SqueezeInterpPct[] = {
    100, 100, 100, 100, 100, 100, 100, 100, 101, 102,
    102, 103, 103, 104, 104, 104, 107, 107, 110, 110,
    118, 118, 126, 126, 134, 142, 145, 145, 145, 142,
    134, 126, 126, 118, 118, 110, 110, 105, 105, 105,
    102, 103, 103, 104, 104, 104, 107, 107, 110, 110,
    118, 118, 126, 126, 134, 142, 145, 145, 145, 142,
    134, 126, 126, 118, 118, 110, 110, 105, 105, 105
};

s8 HeartOffsetY[TUBBA_MINI_HEART_COUNT] = {
    -5, -5, -5, -4, -4,
    -4, -3, -3, -2, -2,
    -1, -1,  0,  0,  1,
     2,  2,  3,  3,  4,
     4,  4,  5,  5,  5,
};

void tubba_heart_attack_init(EffectInstance* effect);
void tubba_heart_attack_update(EffectInstance* effect);
void tubba_heart_attack_render(EffectInstance* effect);
void tubba_heart_attack_appendGfx(void* effect);

EffectInstance* tubba_heart_attack_main(
    s32 type,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 duration
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    TubbaHeartAttackFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = tubba_heart_attack_init;
    bp.update = tubba_heart_attack_update;
    bp.renderScene = tubba_heart_attack_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_TUBBA_HEART_ATTACK;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.tubbaHeartAttack = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.tubbaHeartAttack != NULL);

    data->type = type;
    data->lifetime = 0;
    if (duration <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = duration;
    }
    data->primA = 255;
    data->centerX = arg1;
    data->centerY = arg2;
    data->centerZ = arg3;
    data->overallScale = arg4;
    data->primR = 70;
    data->primG = 180;
    data->primB = 120;

    for (i = 0; i < TUBBA_MINI_HEART_COUNT; i++) {
        f32 sin = sin_deg(i * 1080 / TUBBA_MINI_HEART_COUNT);
        f32 cos = cos_deg(i * 1080 / TUBBA_MINI_HEART_COUNT);

        data->rotZ[i] = rand_int(359) - 180;
        data->finalX[i] = sin * 15.0f;
        data->finalY[i] = HeartOffsetY[i] + 10;
        data->finalZ[i] = cos * 15.0f;
        data->initialX[i] = sin * 120.0f;
        data->initialY[i] = HeartOffsetY[i] * 8 + 40;
        data->initialZ[i] = cos * 120.0f;
        data->appearDelay[i] = i * 2 + 1;
        data->shrinkVelY[i] = 0;
        data->state[i] = HEART_STATE_INIT;
        data->stateTime[i] = 0;
        data->rotXY[i] = 0;
    }

    return effect;
}

void tubba_heart_attack_init(EffectInstance* effect) {
}

EFFECT_DEF_FLOATING_CLOUD_PUFF(floating_cloud_puff_main);

void tubba_heart_attack_update(EffectInstance* effect) {
    TubbaHeartAttackFXData* data = effect->data.tubbaHeartAttack;
    EffectInstance* puffEffect;
    s32 type = data->type;
    s32 time;
    f32 factor;
    f32 angle;
    f32 sin;
    f32 cos;
    Matrix4f mtx;
    Matrix4f tempMtx;
    s32 i;
    s32 j;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->timeLeft = 64;
    }

    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifetime++;

    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = data->lifetime;

    for (i = 0; i < TUBBA_MINI_HEART_COUNT; i++) {
        f32 x = data->initialX[i];
        f32 y = data->initialY[i];
        f32 z = data->initialZ[i];

        data->scaleY[i] = AnimScalePct[time % ARRAY_COUNT(AnimScalePct)] * 0.01f;
        data->scaleX[i] = 2.0f - data->scaleY[i];

        switch (data->state[i]) {
            case HEART_STATE_INIT:
                data->posX[i] = x;
                data->posY[i] = y;
                data->posZ[i] = z;
                data->rotXY[i] += 0.0f;

                if (data->appearDelay[i] != 0) {
                    data->appearDelay[i]--;
                    break;
                }

                data->state[i] = HEART_STATE_APPEAR;
                data->scaleX[i] = data->scaleY[i] = AppearScalePct[data->stateTime[i]] * 0.01;
                data->stateTime[i]++;
                break;
            case HEART_STATE_APPEAR:
                data->scaleX[i] = data->scaleY[i] = AppearScalePct[data->stateTime[i]] * 0.01;
                data->rotXY[i] += 0.0f;

                data->stateTime[i]++;
                if (data->stateTime[i] >= ARRAY_COUNT(AppearScalePct)) {
                    if (type == FX_HEART_SWARM_HIT) {
                        data->state[i] = HEART_STATE_SWARM;
                    } else {
                        data->state[i] = HEART_STATE_MISS;
                    }
                    data->stateTime[i] = 0;
                }
                break;
            case HEART_STATE_MISS:
                data->rotXY[i] += 0.0f;

                factor = MissInterpPct[data->stateTime[i]] * 0.01;

                data->scaleX[i] = data->scaleY[i] = 1.0f;
                data->posX[i] = x + (data->finalX[i] - x) * factor;
                data->posY[i] = y + (data->finalY[i] - y) * factor;
                data->posZ[i] = z + (data->finalZ[i] - z) * factor;

                data->stateTime[i]++;
                if (data->stateTime[i] >= ARRAY_COUNT(MissInterpPct)) {
                    data->state[i] = HEART_STATE_DISPERSE;
                    data->stateTime[i] = 0;
                    data->shrinkVelX[i] = data->finalX[i] * 0.5;
                    data->shrinkVelY[i] = data->finalY[i] * 0.5;
                    data->shrinkVelZ[i] = data->finalZ[i] * 0.5;
                }
                break;
            case HEART_STATE_SWARM:
                data->rotXY[i] += 0.0f;

                factor = SwarmInterpPct[data->stateTime[i]] * 0.01;

                data->scaleY[i] = 1.0f;
                data->scaleX[i] = 1.0f;
                data->posX[i] = x + (data->finalX[i] - x) * factor;
                data->posY[i] = y + (data->finalY[i] - y) * factor;
                data->posZ[i] = z + (data->finalZ[i] - z) * factor;

                data->stateTime[i]++;
                if (data->stateTime[i] >= ARRAY_COUNT(SwarmInterpPct)) {
                    data->state[i] = HEART_STATE_WAIT;
                    data->stateTime[i] = 0;
                }
                break;
            case HEART_STATE_WAIT:
                if (i == 24) {
                    for (j = 0; j < ARRAY_COUNT(data->state); j++) {
                        data->state[j] = HEART_STATE_SQUEEZE;
                    }
                }
                break;
            case HEART_STATE_SQUEEZE:
                factor = SqueezeInterpPct[data->stateTime[i]] * 0.01;
                angle = i * 1080 / TUBBA_MINI_HEART_COUNT + (1.0f - factor) * 1080.0f * 0.5 * cos_deg(i * 180 / TUBBA_MINI_HEART_COUNT);
                sin = sin_deg(angle);
                cos = cos_deg(angle);

                data->posX[i] = ((15.0f / factor) / factor) * sin;
                data->posY[i] = HeartOffsetY[i] + 10;
                data->posZ[i] = ((15.0f / factor) / factor) * cos;

                data->stateTime[i]++;
                if (data->stateTime[i] >= ARRAY_COUNT(SqueezeInterpPct)) {
                    data->state[i] = HEART_STATE_DISPERSE;
                    data->stateTime[i] = 0;
                    data->shrinkVelX[i] = data->finalX[i] * 0.5;
                    data->shrinkVelY[i] = data->finalY[i] * 0.5;
                    data->shrinkVelZ[i] = data->finalZ[i] * 0.5;
                }
                break;
            case HEART_STATE_DISPERSE:
                data->posX[i] += data->shrinkVelX[i];
                data->posY[i] += data->shrinkVelY[i];
                data->posZ[i] += data->shrinkVelZ[i];
                data->shrinkVelX[i] *= 0.99;
                data->shrinkVelY[i] *= 0.99;
                data->shrinkVelZ[i] *= 0.99;
                data->shrinkVelY[i] += -0.1;

                data->stateTime[i]++;
                if (data->stateTime[i] >= 17) {
                    data->stateTime[i] = 0;
                    data->state[i] = HEART_STATE_VANISH;
                }

                data->rotZ[i] *= 0.9;
                break;
            case HEART_STATE_VANISH:
                load_effect(EFFECT_FLOATING_CLOUD_PUFF);
                guRotateF(mtx, data->rotXY[i], 0.0f, 1.0f, 0.0f);
                guTranslateF(tempMtx, data->posX[i], data->posY[i], data->posZ[i]);
                guMtxCatF(tempMtx, mtx, mtx);

                puffEffect = floating_cloud_puff_main(0, data->centerX + mtx[3][0], data->centerY + mtx[3][1], data->centerZ + mtx[3][2], 1.0f, 16);
                puffEffect->data.floatingCloudPuff->unk_28 = 100;
                puffEffect->data.floatingCloudPuff->unk_2C = 0;
                puffEffect->data.floatingCloudPuff->unk_30 = 0;

                data->state[i] = HEART_STATE_DONE;
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
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00CC9C8(void) {
}

void tubba_heart_attack_appendGfx(void* effect) {
    TubbaHeartAttackFXData* data = ((EffectInstance*)effect)->data.tubbaHeartAttack;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 alpha = data->primA;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp18, data->centerX, data->centerY, data->centerZ);
    guScaleF(sp58, data->overallScale, data->overallScale, data->overallScale);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primR, data->primG, data->primB, alpha);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, 0);
    gSPDisplayList(gMainGfxPos++, D_09000400_3D2980);

    for (i = 0; i < TUBBA_MINI_HEART_COUNT; i++) {
        if (data->state[i] != HEART_STATE_INIT && data->state[i] != HEART_STATE_DONE) {
            guRotateF(sp18, data->rotXY[i], 0.0f, 1.0f, 0.0f);
            guTranslateF(sp58, data->posX[i], data->posY[i], data->posZ[i]);
            guMtxCatF(sp58, sp18, sp18);
            guRotateF(sp58, -data->rotXY[i], 0.0f, 1.0f, 0.0f);
            guMtxCatF(sp58, sp18, sp18);
            guRotateF(sp58, data->rotZ[i], 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp58, sp18, sp18);
            guScaleF(sp58, data->scaleX[i], data->scaleY[i], 1.0f);
            guMtxCatF(sp58, sp18, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_09000518_3D2A98);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
