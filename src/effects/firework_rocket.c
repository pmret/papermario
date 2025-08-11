#include "common.h"
#include "effects_internal.h"

void firework_rocket_init(EffectInstance* effect);
void firework_rocket_render(EffectInstance* effect);
void firework_rocket_update(EffectInstance* effect);
void firework_rocket_appendGfx(void* effect);

typedef struct FireworkRocketUnk {
    /* 0x00 */ Vec3b* sparks;
    /* 0x04 */ s32 num;
} FireworkRocketUnk; // size = 0x8

extern Gfx D_09000080_3E53D0[];
extern Gfx D_09000158_3E54A8[];

Gfx* D_E010ACC0[] = { D_09000158_3E54A8, D_09000158_3E54A8, D_09000158_3E54A8 };
Gfx* D_E010ACCC[] = { D_09000080_3E53D0, D_09000080_3E53D0, D_09000080_3E53D0 };

Vec3b D_E010ACD8[] = {
    {   36,    0,   93 }, {   54,  -40,   74 }, {   67,    0,   74 }, {   82,  -36,   45 }, {   89,    0,   45 },
    {   60,  -66,   45 }, {   21,  -64,   74 }, {   28,  -85,   45 }, {   10,  -98,   15 }, {   49,  -86,   15 },
    {  -90,  -40,   15 }, {  -87,  -19,   45 }, {  -99,    0,   15 }, {  -72,  -53,   45 }, {  -87,   19,   45 },
    {  -90,   40,   15 }, {  -66,   73,   15 }, {  -72,   53,   45 }, {  -45,   77,   45 }, {  -31,   94,   15 },
    {   -9,   89,   45 }, {  -72,   53,   45 }, {   11,  -34,   93 }, {    0,    0,  100 }, {  -54,  -40,   74 },
    {  -72,  -53,   45 }, {  -45,  -77,   45 }, {  -90,  -40,   15 }, {  -66,  -73,   15 }, {   11,  -34,   93 },
    {  -21,  -64,   74 }, {   21,  -64,   74 }, {   -9,  -89,   45 }, {   28,  -85,   45 }, {   10,   98,   15 },
    {   80,  -58,   15 }, {   97,  -21,   15 }, {   49,  -86,   15 }, {   10,  -98,   15 }, {  -31,  -94,   15 },
    {  -66,  -73,   15 }, {   49,   86,   15 }, {   80,   58,   15 }, {   97,   21,   15 }, {  -29,  -21,   93 },
    {    0,    0,  100 }, {   11,   34,   93 }, {  -29,   21,   93 }, {   21,   64,   74 }, {  -21,   64,   74 },
    {  -54,   40,   74 }, {   28,   85,   45 }, {   67,    0,   74 }, {   89,    0,   45 }, {   36,    0,   93 },
    {    0,    0,  100 }, {   11,   34,   93 }, {   54,   40,   74 }, {   21,   64,   74 }, {  -54,   40,   74 },
    {  -72,   53,   45 }, {    0,    0,  100 }, {  -29,  -21,   93 }, {  -67,    0,   74 }, {  -54,  -40,   74 },
    {  -29,   21,   93 }, {    0,    0,  100 }, {   60,  -66,   45 }, {   82,  -36,   45 }, {   89,    0,   45 },
    {   28,  -85,   45 }, {   28,  -85,   45 }, {   -9,  -89,   45 }, {  -45,  -77,   45 }, {  -72,  -53,   45 },
    {   60,   66,   45 }, {   28,   85,   45 }, {   82,   36,   45 }, {   28,   85,   45 }, {   89,    0,   45 },
    {   -9,   89,   45 }, {  -45,   77,   45 }, {  -72,   53,   45 }, {   49,   86,   15 }, {   10,   98,   15 },
    {   82,   36,   45 }, {   97,  -21,   15 }, {   97,   21,   15 }, {   60,   66,   45 }, {   28,   85,   45 },
    {  -87,   19,   45 }, {  -66,   73,   15 }, {  -90,   40,   15 }, {  -87,  -19,   45 }, {  -72,  -53,   45 },
};

Vec3b D_E010ADF8[] = {
    {  -48,  -15,    0 }, {  -36,  -26,   22 }, {  -45,    0,   22 }, {  -48,   15,    0 }, {  -36,   26,   22 },
    {  -29,   40,    0 }, {  -36,   26,   22 }, {  -14,   43,   22 }, {    0,   50,    0 }, {   14,   43,   22 },
    {    8,  -25,   43 }, {   14,  -43,   22 }, {   36,  -26,   22 }, {   26,    0,   43 }, {    0,    0,   50 },
    {    0,  -50,    0 }, {   29,  -40,    0 }, {   45,    0,   22 }, {   29,  -40,    0 }, {   36,  -26,   22 },
    {   14,  -43,   22 }, {   48,  -15,    0 }, {   45,    0,   22 }, {    0,  -50,    0 }, {   14,  -43,   22 },
    {  -14,  -43,   22 }, {  -29,  -40,    0 }, {  -36,  -26,   22 }, {   29,   40,    0 }, {   36,   26,   22 },
    {   48,   15,    0 }, {   14,   43,   22 }, {   45,    0,   22 }, {    0,    0,   50 }, {    8,   25,   43 },
    {  -21,   15,   43 }, {   14,   43,   22 }, {   26,    0,   43 }, {   45,    0,   22 }, {    0,    0,   50 },
    {    8,   25,   43 }, {  -21,  -15,   43 }, {    0,    0,   50 }, {  -36,  -26,   22 }, {    8,  -25,   43 },
    {    0,    0,   50 }, {  -21,   15,   43 }, {  -21,  -15,   43 }, {  -36,   26,   22 }, {  -14,   43,   22 },
    {  -36,   26,   22 }, {   29,   40,    0 }, {    0,   50,    0 }, {   36,   26,   22 }, {   48,  -15,    0 },
    {   48,   15,    0 }, {   14,   43,   22 }, {  -14,  -43,   22 }, {  -48,  -15,    0 }, {  -29,  -40,    0 },
    {   14,  -43,   22 }, {  -45,    0,   22 }, {  -36,  -26,   22 }, {  -29,   40,    0 }, {  -48,   15,    0 },
    {    0,    0,    0 },
};

Vec3b D_E010AEC0[] = {
    {   -9,  105,    0 }, {  -17,   87,    0 }, {   17,   87,    0 }, {    9,  105,    0 }, {    0,  122,    0 },
    {  -26,   69,    0 }, {   26,   69,    0 }, {  -35,   52,    0 }, {   35,   52,    0 }, {  -54,   49,    0 },
    {  -70,   -1,    0 }, {  -56,  -15,    0 }, {    0,  -56,    0 }, {   56,  -15,    0 }, {   70,   -1,    0 },
    {   54,   49,    0 }, {  -60,  -34,    0 }, {  -17,  -65,    0 }, {   17,  -65,    0 }, {   60,  -34,    0 },
    {   85,   13,    0 }, {   74,   46,    0 }, {   99,   27,    0 }, {   93,   43,    0 }, {   12,   33,    0 },
    {   12,   22,    0 }, {   24,   22,    0 }, {   24,   33,    0 }, {   12,   10,    0 }, {   24,   10,    0 },
    {   24,   45,    0 }, {  -24,   33,    0 }, {  -24,   22,    0 }, {  -24,   45,    0 }, {  113,   40,    0 },
    {  -63,  -53,    0 }, {  -66,  -73,    0 }, {  -74,   46,    0 }, {  -93,   43,    0 }, {   35,  -74,    0 },
    {   52,  -83,    0 }, {   12,   45,    0 }, {  -12,   22,    0 }, {  -12,   33,    0 }, {  -24,   10,    0 },
    {  -12,   10,    0 }, {  -12,   45,    0 }, {  -52,  -83,    0 }, {  -35,  -74,    0 }, {  -70,  -92,    0 },
    {  -85,   13,    0 }, {  -99,   27,    0 }, { -113,   40,    0 }, {   63,  -53,    0 }, {   66,  -73,    0 },
    {   70,  -92,    0 },
};

FireworkRocketUnk D_E010AF68[] = {
    {D_E010ACD8, ARRAY_COUNT(D_E010ACD8)},
    {D_E010ADF8, ARRAY_COUNT(D_E010ADF8)},
    {D_E010AEC0, ARRAY_COUNT(D_E010AEC0)}
};

s32 firework_rocket_frame_counter = 0;
s32 firework_rocket_blur_alpha = 0;

EffectInstance* firework_rocket_main(s32 variation, f32 centerX, f32 centerY, f32 centerZ, f32 velX, f32 velY, f32 velZ, f32 radius, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FireworkRocketFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = firework_rocket_init;
    bp.update = firework_rocket_update;
    bp.renderScene = firework_rocket_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_FIREWORK_ROCKET;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.fireworkRocket = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.fireworkRocket != nullptr);

    data->variation = variation;
    data->lifeTime = 0;
    if (duration <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = duration + 32;
    }
    data->isExploded = false;
    data->minBlurAlpha = 255;
    data->pos.x = centerX;
    data->pos.y = centerY;
    data->pos.z = centerZ;
    data->radius = 0;
    data->vel.x = velX;
    data->vel.y = velY;
    data->vel.z = velZ;
    data->maxRadius = radius;
    data->r = 255;
    data->g = 255;
    data->b = 100;
    data->unk_34 = 255;
    data->unk_38 = 100;
    data->unk_3C = 150;
    data->unk_40 = 255;

    for (i = 0; i < ROCKET_BUF_SIZE; i++) {
        data->rocketX[i] = data->pos.x;
        data->rocketY[i] = data->pos.y - 1000.0f;
        data->rocketZ[i] = data->pos.z;
        data->rocketVelX[i] = 0;
        data->rocketVelY[i] = 0;
        data->rocketVelZ[i] = 0;
    }

    return effect;
}

void firework_rocket_init(EffectInstance* effect) {
}

void firework_rocket_update(EffectInstance* effect) {
    FireworkRocketFXData* data = effect->data.fireworkRocket;
    f32 factor;
    s32 lifeTime;
    s32 i;

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

    if (data->timeLeft < 32) {
        data->minBlurAlpha = data->timeLeft * 8;
    }

    if (data->isExploded == true) {
        factor = 0.95f;
        data->pos.x += data->vel.x;
        data->pos.y += data->vel.y;
        data->pos.z += data->vel.z;
        data->vel.x *= factor;
        data->vel.y *= factor;
        data->vel.z *= factor;
        data->radius += (data->maxRadius - data->radius) * 0.11;
        data->vel.y -= 0.15;
        return;
    }

    i = lifeTime & 3;
    data->rocketX[i] = data->pos.x - data->vel.x * (32 - lifeTime);
    data->rocketY[i] = data->pos.y - data->vel.y * (32 - lifeTime)
        - (80.0f - sin_deg((s32)(lifeTime * 90) >> 5) * 80.0f);
    data->rocketZ[i] = data->pos.z - data->vel.z * (32 - lifeTime);
    data->rocketVelX[i] = (rand_int(10) - 5) * 0.1f;
    data->rocketVelY[i] = (rand_int(10) - 5) * 0.1f;
    data->rocketVelZ[i] = (rand_int(10) - 5) * 0.1f;

    for (i = 0; i < ROCKET_BUF_SIZE; i++) {
        data->rocketX[i] += data->rocketVelX[i];
        data->rocketY[i] += data->rocketVelY[i];
        data->rocketZ[i] += data->rocketVelZ[i];
        data->rocketVelY[i] -= 0.15;
        if (lifeTime >= 27) {
            data->rocketY[i] = NPC_DISPOSE_POS_Y;
        }
    }

    if (lifeTime >= 32) {
        data->isExploded = true;
        data->lifeTime = 1;
    }
}

void firework_rocket_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = firework_rocket_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 700;
    renderTask.renderMode =  RENDER_MODE_SURFACE_OPA;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void firework_rocket_appendGfx(void* effect) {
    FireworkRocketFXData* data = ((EffectInstance*)effect)->data.fireworkRocket;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 minBlurAlpha = data->minBlurAlpha;
    s32 variation = data->variation;
    f32 mtx_0_0, mtx_0_1, mtx_0_2, mtx_0_3;
    f32 mtx_1_0, mtx_1_1, mtx_1_2, mtx_1_3;
    f32 mtx_2_0, mtx_2_1, mtx_2_2, mtx_2_3;
    f32 mtx_3_0, mtx_3_1, mtx_3_2, mtx_3_3;
    f32 sinTheta, cosTheta;
    f32 centerX, centerY, centerZ;
    f32 negYaw;
    f32 x, y, z;
    f32 outX, outY, outZ, outS;
    f32 radius;
    s32 isExploded;
    s32 numSparks;
    Vec3b* sparkDir;
    s32 i;

    negYaw = -camera->curYaw;
    sinTheta = sin_deg(negYaw);
    cosTheta = cos_deg(negYaw);
    isExploded = data->isExploded;
    if (firework_rocket_frame_counter != gGameStatusPtr->frameCounter) {
        // draw previous frame to create motion blur effect
        draw_prev_frame_buffer_at_screen_pos(10, 10, SCREEN_WIDTH - 10, SCREEN_HEIGHT - 10, firework_rocket_blur_alpha * 0.8);
        firework_rocket_frame_counter = gGameStatusPtr->frameCounter;
        firework_rocket_blur_alpha = 0;
    }
    if (firework_rocket_blur_alpha < minBlurAlpha) {
        firework_rocket_blur_alpha = minBlurAlpha;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    mtx_0_0 = camera->mtxPerspective[0][0];
    mtx_0_1 = camera->mtxPerspective[0][1];
    mtx_0_2 = camera->mtxPerspective[0][2];
    mtx_0_3 = camera->mtxPerspective[0][3];
    mtx_1_0 = camera->mtxPerspective[1][0];
    mtx_1_1 = camera->mtxPerspective[1][1];
    mtx_1_2 = camera->mtxPerspective[1][2];
    mtx_1_3 = camera->mtxPerspective[1][3];
    mtx_2_0 = camera->mtxPerspective[2][0];
    mtx_2_1 = camera->mtxPerspective[2][1];
    mtx_2_2 = camera->mtxPerspective[2][2];
    mtx_2_3 = camera->mtxPerspective[2][3];
    mtx_3_0 = camera->mtxPerspective[3][0];
    mtx_3_1 = camera->mtxPerspective[3][1];
    mtx_3_2 = camera->mtxPerspective[3][2];
    mtx_3_3 = camera->mtxPerspective[3][3];

    gSPDisplayList(gMainGfxPos++, D_E010ACCC[variation]);
    centerX = data->pos.x;
    centerY = data->pos.y;
    centerZ = data->pos.z;
    radius = data->radius;
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->r, data->g, data->b, minBlurAlpha);
    gDPSetEnvColor(gMainGfxPos++, data->r, data->g, data->b, 0);

    if (isExploded == true) {
        sparkDir = D_E010AF68[variation].sparks;
        numSparks = D_E010AF68[variation].num;
    } else {
        sparkDir = nullptr;
        numSparks = 4;
    }

    for (i = 0; i < numSparks; i++, sparkDir++) {
        if (isExploded == true) {
            // create blinking effect
            if (rand_int(16) < 6) {
                continue;
            }
            x = (sparkDir->x * cosTheta + sparkDir->z * sinTheta) * radius + centerX;
            y = sparkDir->y * radius + centerY;
            z = (-sparkDir->x * sinTheta + sparkDir->z * cosTheta) * radius + centerZ;
        } else {
            x = data->rocketX[i];
            y = data->rocketY[i];
            z = data->rocketZ[i];
        }

        // convert world coords to screen coords
        outX = mtx_0_0 * x + mtx_1_0 * y + mtx_2_0 * z + mtx_3_0;
        outY = mtx_0_1 * x + mtx_1_1 * y + mtx_2_1 * z + mtx_3_1;
        outZ = mtx_0_2 * x + mtx_1_2 * y + mtx_2_2 * z + mtx_3_2;
        outS = mtx_0_3 * x + mtx_1_3 * y + mtx_2_3 * z + mtx_3_3;

        if (outS != 0.0f) {
            outS = 1.0f / outS;
            x = outX * outS;
            y = -outY * outS;
            z = outZ * outS;

            if (z <= -1.0f || x <= -1.0f || x >= 1.0f || y <= -1.0f || y >= 1.0f) {
                continue;
            }
            z = 4.0f; // required to match

            x = (x + 1.0f) * camera->viewportW * 0.5;
            x += camera->viewportStartX;
            x *= 4.0f;

            y = (y + 1.0f) * camera->viewportH * 0.5;
            y += camera->viewportStartY;
            y *= 4.0f;

            gSPScisTextureRectangle(gMainGfxPos++,
                x, y, x + 8.0f, y + 8.0f,
                G_TX_RENDERTILE, 4 << 5, 4 << 5, 16 << 10, 16 << 10);
        }
    }
}

