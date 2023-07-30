#include "common.h"
#include "effects_internal.h"

#define MAX_POINTS (30)

void effect_65_init(EffectInstance* effect);
void effect_65_update(EffectInstance* effect);
void effect_65_render(EffectInstance* effect);
void effect_65_appendGfx(void* effect);

extern Gfx D_09000400_3D15E0[];

Gfx* D_E00CACB0[] = { D_09000400_3D15E0, D_09000400_3D15E0, D_09000400_3D15E0, D_09000400_3D15E0 };

EffectInstance* effect_65_main(
    s32 variation,
    f32 posX,
    f32 posY,
    f32 posZ,
    f32 scale,
    s32 duration
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect65FXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = effect_65_init;
    bp.update = effect_65_update;
    bp.renderWorld = effect_65_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_65;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.unk_65 = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.unk_65 != NULL);

    data->variation = variation;
    data->lifeTime = 0;
    if (duration <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = duration;
    }
    data->unk_04 = posX;
    data->unk_08 = posY;
    data->unk_0C = posZ;
    data->scale = scale;

    switch (variation) {
        case 0:
            data->primR = 255;
            data->primG = 255;
            data->primB = 255;
            data->envR = 225;
            data->envG = 225;
            data->envB = 225;
            data->alpha = 255;
            break;
        case 1:
            data->primR = 255;
            data->primG = 245;
            data->primB = 230;
            data->envR = 45;
            data->envG = 35;
            data->envB = 15;
            data->alpha = 255;
            break;
        case 2:
            data->primR = 255;
            data->primG = 0;
            data->primB = 0;
            data->envR = 155;
            data->envG = 125;
            data->envB = 125;
            data->alpha = 255;
            break;
        case 3:
            data->primR = 255;
            data->primG = 255;
            data->primB = 255;
            data->envR = 255;
            data->envG = 65;
            data->envB = 20;
            data->alpha = 255;
            break;
    }

    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;

    for (i = 0; i < MAX_POINTS; i++) {
        data->pathPointEnabled[i] = FALSE;
    }

    data->lastPointIndex = 0;
    data->pathX[0] = posX;
    data->pathY[0] = posY;
    data->pathZ[0] = posZ;
    data->pathPointEnabled[0] = TRUE;
    data->pathTimestamp[0] = 0;
    data->pathLength[0] = 0;
    data->pathJitterX = rand_int(30) + 10;
    data->pathJitterY = 0;
    data->pathJitterZ = 0;

    return effect;
}

void effect_65_init(EffectInstance* effect) {
}

void effect_65_update(EffectInstance* effect) {
    Effect65FXData* data = effect->data.unk_65;
    s32 variation = data->variation;
    s32 lifeTime;
    f32 pathLength;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 lastPointX;
    f32 lastPointY;
    f32 lastPointZ;
    f32 dist;
    s32 idx;

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
        data->alpha = data->timeLeft * 16;
    }

    if (variation == 3) {
        data->pathJitterX += rand_int(10) - 5;
        data->pathJitterY += rand_int(10) - 5;
        data->pos.x += data->pathJitterX;
        data->pos.y += data->pathJitterY;
        data->pos.z += data->pathJitterZ;
    }

    idx = data->lastPointIndex % MAX_POINTS;

    posX = data->pos.x;
    posY = data->pos.y;
    posZ = data->pos.z;

    lastPointX = data->pathX[idx];
    lastPointY = data->pathY[idx];
    lastPointZ = data->pathZ[idx];

    if (posX != lastPointX || posY != lastPointY || posZ != lastPointZ) {
        // add new point to the trajectory
        pathLength = data->pathLength[idx];

        data->lastPointIndex++;
        if (data->lastPointIndex >= MAX_POINTS) {
            data->lastPointIndex = 0;
        }

        idx = data->lastPointIndex;

        data->pathPointEnabled[idx] = TRUE;
        data->pathX[idx] = posX;
        data->pathY[idx] = posY;
        data->pathZ[idx] = posZ;
        data->pathTimestamp[idx] = lifeTime;

        dist = SQ(posX - lastPointX) + SQ(posY - lastPointY) + SQ(posZ - lastPointZ);
        if (dist != 0.0f) {
            dist = sqrtf(dist);
        }

        data->pathLength[idx] = pathLength + dist;
    }
}

void effect_65_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = effect_65_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void effect_65_appendGfx(void* effect) {
    Effect65FXData* data = ((EffectInstance*)effect)->data.unk_65;
    Matrix4f mtx;
    s32 lifeTime;
    s32 variation;
    f32 scale;
    Vtx_t* vtxBuffer;
    Vtx_t* vtx;
    s32 firstPointIdx;
    s32 baseTexOffset;
    s32 phase;
    f32 deltaY;
    f32 deltaX;

    f32 width;
    f32 pathPointX;
    f32 pathPointY;
    f32 pathPointZ;
    f32 deltaAngle;
    f32 prevAngle;
    f32 nextAngle;
    f32 angle;
    s32 primAlpha;
    s32 texOffsetX;
    s32 numPoints;
    s32 pathPointLifetime;
    s32 r, g, b, a;
    f32 deltaZ;

    s32 idx;
    s32 next;
    s32 prev;
    s32 i;
    s32 fadeOutPhase;

    lifeTime = data->lifeTime;
    primAlpha = data->alpha;
    variation = data->variation;
    scale = data->scale;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(mtx, 0.0f, 0.0f, 0.0f);
    guMtxF2L(mtx, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_E00CACB0[variation]);

    if (variation >= 2) {
        gDPSetCombineLERP(gMainGfxPos++, SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, COMBINED, COMBINED, 0, PRIMITIVE, 0);
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primR, data->primG, data->primB, primAlpha);
    gDPSetEnvColor(gMainGfxPos++, data->envR, data->envG, data->envB, 0);
    gSPBranchList(gMainGfxPos, gMainGfxPos + 0x79);

    vtxBuffer = (Vtx_t*) (gMainGfxPos + 1);
    firstPointIdx = -1;
    baseTexOffset = (lifeTime & 0x3F) << 5;
    gMainGfxPos += 0x79;

    numPoints = 0;
    for (i = 0; i < MAX_POINTS; i++) {
        s32 a1 = i + 1;
        s32 idx = (data->lastPointIndex + a1) % MAX_POINTS;
        if (data->pathPointEnabled[idx]) {
            numPoints++;
        }
    }

    numPoints--;
    if (numPoints > 0) {
        phase = 0;
        for (i = 0; i < MAX_POINTS; i++) {
            s32 a1 = i + 1;
            vtx = &vtxBuffer[i * 2];
            fadeOutPhase = phase / numPoints;
            idx = (data->lastPointIndex + a1) % MAX_POINTS;

            a = sin_deg(fadeOutPhase) * 255.0f;
            if (a > 200) {
                a = 200;
            }

            if (!data->pathPointEnabled[idx]) {
                continue;
            }

            if (firstPointIdx == -1) {
                next = idx + 1;
                if (next >= MAX_POINTS) {
                    next = 0;
                }
                firstPointIdx = i;
                angle = -atan2(data->pathY[next], -data->pathX[next], data->pathY[idx], -data->pathX[idx]);
            } else {
                if (i != MAX_POINTS - 1) {
                    next = idx + 1;
                    prev = idx - 1;
                    if (next >= MAX_POINTS) {
                        next = 0;
                    }
                    if (prev < 0) {
                        prev = MAX_POINTS - 1;
                    }
                    nextAngle = -atan2(data->pathY[next], -data->pathX[next], data->pathY[idx], -data->pathX[idx]);
                    prevAngle = -atan2(data->pathY[idx], -data->pathX[idx], data->pathY[prev], -data->pathX[prev]);
                    deltaAngle = prevAngle - nextAngle;
                    if (deltaAngle > 180.0f) {
                        nextAngle += 360.0f;
                    } else if (deltaAngle < -180.0f) {
                        prevAngle += 360.0f;
                    }
                    angle = nextAngle + prevAngle;
                    angle *= 0.5;
                }
            }
            pathPointX = data->pathX[idx];
            pathPointY = data->pathY[idx];
            pathPointZ = data->pathZ[idx];
            pathPointLifetime = lifeTime - data->pathTimestamp[idx];
            width = sin_deg((lifeTime - data->pathTimestamp[idx] * 80) * 4) * 3.0f + 16.0f + pathPointLifetime;

            width *= scale;
            if (variation >= 0) {
                texOffsetX = (data->pathLength[idx] * 24.0f) + baseTexOffset;
            } else {
                texOffsetX = (data->pathLength[idx] * 24.0f) + baseTexOffset;
            }

            r = 255;
            g = 255;
            b = 255 - pathPointLifetime * 100;
            if (b < 0) {
                g = (f32) b * 0.8 + 255.0;
                b = 0;
                if (g < 0) {
                    r = (f32) g * 0.4 + 255.0;
                    g = 0;
                    if (r < 0) {
                        r = 0;
                    }
                }
            }

            deltaX = width * sin_deg(angle);
            deltaY = width * cos_deg(angle);
            deltaZ = 0.0f;

            vtx->ob[0] = pathPointX + deltaX;
            vtx->ob[1] = pathPointY + deltaY;
            vtx->ob[2] = pathPointZ + deltaZ;
            vtx->tc[0] = texOffsetX;
            vtx->tc[1] = 0x400;
            vtx->cn[0] = r;
            vtx->cn[1] = g;
            vtx->cn[2] = b;
            vtx->cn[3] = a;
            vtx++;

            vtx->ob[0] = pathPointX - deltaX;
            vtx->ob[1] = pathPointY - deltaY;
            vtx->ob[2] = pathPointZ + deltaZ;
            vtx->tc[0] = texOffsetX;
            vtx->tc[1] = 0;
            vtx->cn[0] = r;
            vtx->cn[1] = g;
            vtx->cn[2] = b;
            vtx->cn[3] = a;
            vtx++;

            phase += 180;
        }

        for (i = firstPointIdx; i < MAX_POINTS - 1; i++) {
            gSPVertex(gMainGfxPos++, &vtxBuffer[i * 2], 4, 0);
            gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
