#include "common.h"
#include "effects_internal.h"

typedef struct LightningPreset {
    /* 0x00 */ u8 offset[12];
    /* 0x0C */ u8 width[12];
} LightningPreset; // size = 0x18

LightningPreset D_E00BCC30[] = {
    {{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, {10, 9, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, {8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0}},
    {{35, 5, 25, 5, 0, 25, 35, 5, 15, 0, 0, 0}, {10, 13, 15, 12, 11, 13, 10, 12, 5, 1, 0, 0}},
    {{45, 15, 35, 15, 0, 35, 45, 55, 25, 5, 2, 0}, {13, 10, 12, 10, 13, 10, 13, 10, 12, 9, 5, 1}},
    {{15, 15, 15, 15, 15, 15, 0, 15, 15, 5, 2, 0}, {14, 10, 15, 10, 13, 30, 32, 30, 24, 50, 40, 60}},
    {{1, 5, 15, 15, 35, 45, 40, 35, 25, 5, 2, 0}, {4, 6, 10, 5, 8, 14, 6, 10, 14, 35, 50, 50}},
    {{1, 15, 25, 15, 25, 35, 45, 40, 35, 15, 5, 0}, {2, 2, 23, 12, 8, 15, 15, 5, 6, 18, 38, 60}},
    {{30, 25, 15, 5, 15, 15, 25, 30, 35, 25, 5, 0}, {3, 3, 3, 11, 3, 12, 4, 5, 2, 12, 42, 50}},
    {{33, 33, 20, 12, 25, 17, 15, 20, 22, 20, 5, 0}, {3, 3, 3, 2, 10, 2, 2, 12, 2, 2, 2, 20}},
    {{30, 30, 25, 25, 35, 20, 15, 10, 15, 15, 5, 0}, {2, 2, 2, 2, 2, 2, 6, 2, 2, 2, 6, 5}},
    {{27, 27, 22, 22, 32, 17, 12, 7, 12, 12, 2, 0}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0}},
};

LightningPreset D_E00BCD38[] = {
    {{25, 25, 25, 5, 25, 5, 25, 25, 5, 25, 25, 25}, {4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{15, 15, 15, 25, 15, 15, 5, 25, 25, 15, 25, 25}, {4, 4, 4, 4, 4, 3, 2, 1, 0, 0, 0, 0}},
    {{25, 25, 25, 5, 15, 25, 5, 5, 15, 5, 5, 0}, {4, 4, 4, 4, 4, 4, 6, 4, 4, 4, 0, 0}},
    {{25, 25, 25, 5, 25, 5, 25, 25, 5, 15, 5, 0}, {4, 4, 4, 4, 4, 4, 6, 4, 4, 4, 6, 5}},
    {{15, 15, 15, 45, 35, 45, 35, 35, 25, 35, 15, 0}, {4, 4, 4, 4, 4, 4, 6, 4, 4, 4, 6, 5}},
    {{45, 55, 35, 25, 55, 15, 45, 25, 45, 35, 15, 0}, {4, 4, 4, 4, 4, 4, 6, 4, 4, 4, 6, 5}},
    {{85, 25, 15, 75, 25, 65, 35, 45, 75, 85, 15, 0}, {4, 4, 4, 4, 4, 4, 6, 4, 4, 4, 6, 5}},
    {{85, 15, 35, 55, 65, 45, 25, 75, 35, 45, 35, 40}, {4, 4, 4, 4, 4, 4, 6, 4, 4, 4, 6, 5}},
    {{85, 15, 35, 55, 65, 45, 25, 75, 35, 45, 35, 40}, {4, 4, 4, 4, 4, 4, 6, 4, 4, 4, 6, 5}},
    {{85, 15, 35, 55, 65, 45, 25, 75, 35, 45, 35, 40}, {4, 4, 4, 4, 4, 4, 6, 4, 4, 4, 6, 5}},
    {{30, 30, 25, 25, 35, 20, 15, 10, 15, 15, 5, 0}, {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 0}},
};

LightningPreset* D_E00BCE40[] = { D_E00BCC30, D_E00BCD38 };

extern Gfx D_09001000_3BBEA0[];

void lightning_bolt_init(EffectInstance* effect);
void lightning_bolt_update(EffectInstance* effect);
void lightning_bolt_render(EffectInstance* effect);
void lightning_bolt_appendGfx(void* effect);

EffectInstance* lightning_bolt_main(
    s32 type,
    f32 startX,
    f32 startY,
    f32 startZ,
    f32 endX,
    f32 endY,
    f32 endZ,
    f32 scale,
    s32 duration)
{
    EffectBlueprint bp;
    EffectInstance* effect;
    LightningBoltFXData* data;
    s32 numParts = 1;
    f32 temp;

    bp.init = lightning_bolt_init;
    bp.update = lightning_bolt_update;
    bp.renderScene = lightning_bolt_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_LIGHTNING_BOLT;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.lightningBolt = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.lightningBolt != nullptr);

    data->type = type;
    data->lifetime = 0;
    if (duration <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = duration;
    }
    data->outerColor.a = 255;
    data->startPos.x = startX;
    data->startPos.y = startY;
    data->startPos.z = startZ;
    data->endPos.x = endX;
    data->endPos.y = endY;
    data->endPos.z = endZ;
    data->tipPos.x = startX;
    data->tipPos.y = startY;
    data->tipPos.z = startZ;
    data->widthScale = scale;

    temp = SQ(startX - endX) + SQ(startY - endY) + SQ(startZ - endZ);

    if (temp != 0.0f) {
        data->unk_114 = sqrtf(temp) * 0.005;
        data->outerColor.r = 255;
        data->outerColor.g = 220;
        data->outerColor.b = 20;
        data->innerColor.r = 255;
        data->innerColor.g = 255;
        data->innerColor.b = 255;
        data->unk_110 = rand_int(359);

        return effect;
    } else {
        return nullptr;
    }
}

void lightning_bolt_init(EffectInstance* effect) {
}

f32 lightning_bolt_get_rand_symmetric(f32 interval) {
    return (f32)rand_int(interval) - interval * 0.5;
}

void lightning_bolt_update(EffectInstance* effect) {
    LightningBoltFXData* data = effect->data.lightningBolt;
    s32 type = data->type;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->timeLeft = 16;
    }

    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifetime++;

    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    if (type == 2) {
        if (data->lifetime >= 40) {
            data->outerColor.a *= 0.5;
        }
    } else {
        if (data->lifetime >= 11) {
            data->outerColor.a *= 0.5;
        }
    }
}

void lightning_bolt_render(EffectInstance *effect) {
    LightningBoltFXData* data = effect->data.lightningBolt;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = lightning_bolt_appendGfx;
    renderTask.appendGfxArg = effect;
    if (gGameStatusPtr->context == CONTEXT_BATTLE) {
        renderTask.dist = data->tipPos.z + 1000.0f;
    } else {
        renderTask.dist = 10;
    }

    renderTaskPointer->renderMode = RENDER_MODE_CLOUD_NO_ZCMP;
    retTask = queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00BC36C(void) {
}

void lightning_bolt_appendGfx(void* effect) {
    Vtx_t* vtxBuffer;
    f32 widthScale;
    f32 cosAngle;
    f32 edgeDeltaY;
    f32 temp;
    f32 sinAngle;
    f32 edgeDeltaX;
    f32 avgDeltaY;
    f32 avgDeltaX;
    f32 deltaPos;
    f32 theta;
    f32 nextAngle;
    f32 edgeAngle;
    f32 prevAngle;
    s16 texOffsetX;
    s32 temp_a0;
    s32 alpha;
    s32 type;
    s32 lifetime;
    s32 quadCount;
    LightningPreset* preset;
    Vtx_t* vtx;
    f32 edgeDeltaZ;
    f32 deltaX, deltaY, deltaZ;
    LightningBoltFXData* data = ((EffectInstance*)effect)->data.lightningBolt;
    Matrix4f sp10;
    Matrix4f unused;
    s32 i;
    f32 edgeLength;

    lifetime = data->lifetime;
    alpha = data->outerColor.a;
    type = data->type;
    widthScale = data->widthScale;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guScaleF(sp10, 0.1f, 0.1f, 0.1f);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->outerColor.r, data->outerColor.g, data->outerColor.b, alpha);
    gDPSetEnvColor(gMainGfxPos++, data->innerColor.r, data->innerColor.g, data->innerColor.b, 128);
    gSPDisplayList(gMainGfxPos++, D_09001000_3BBEA0);

    temp_a0 = lifetime - 1;
    if (type != 2) {
        if (temp_a0 <= 10) {
            preset = &D_E00BCE40[type][temp_a0];
        } else {
            preset = &D_E00BCE40[type][10];
        }
    } else if (temp_a0 < 8) {
        preset = &D_E00BCE40[0][temp_a0];
    } else if (temp_a0 < 0x24) {
        preset = &D_E00BCE40[0][temp_a0 % 6 + 2];
    } else {
        preset = &D_E00BCE40[0][10];
    }

    for (i = 0; i < ARRAY_COUNT(data->boltVertexPosX); i++) {
        avgDeltaX = (data->endPos.x - data->startPos.x) * (1 / 11.0f);
        avgDeltaY = (data->endPos.y - data->startPos.y) * (1 / 11.0f);
        theta = (data->unk_110 + (i - lifetime) * 10) % 120 - 60;
        deltaPos = preset->offset[i];

        sinAngle = sin_deg(theta) * deltaPos * 0.04;
        cosAngle = cos_deg(theta) * deltaPos * 0.04;

        deltaX = avgDeltaX * cosAngle - avgDeltaY * sinAngle;
        deltaY = avgDeltaX * sinAngle + avgDeltaY * cosAngle;
        deltaZ = 0.0f;

        data->boltVertexPosX[i] = data->startPos.x + (data->endPos.x - data->startPos.x) * i * (1 / 11.0f) + deltaX;
        data->boltVertexPosY[i] = data->startPos.y + (data->endPos.y - data->startPos.y) * i * (1 / 11.0f) + deltaY;
        data->boltVertexPosZ[i] = data->startPos.z + (data->endPos.z - data->startPos.z) * i * (1 / 11.0f) + deltaZ;
        data->edgeLength[i] = (f32) preset->width[i] * 0.1;
    }

    vtxBuffer = (Vtx_t*) (gMainGfxPos + 1);
    vtx = (Vtx_t*) (gMainGfxPos + 1);
    gSPBranchList(gMainGfxPos, gMainGfxPos + 0x31);
    gMainGfxPos += 0x31;

    for (i = 0; i < ARRAY_COUNT(data->boltVertexPosX); i++) {
        if (i == 0) {
            edgeLength = 8.0f;
            edgeAngle = -atan2(data->boltVertexPosY[1], -data->boltVertexPosX[1], data->boltVertexPosY[0], -data->boltVertexPosX[0]);
        } else {
            edgeLength = 8.0f;
            if (i == ARRAY_COUNT(data->boltVertexPosX) - 1) {
                edgeAngle = -90.0f;
            } else {
                nextAngle = -atan2(data->boltVertexPosY[i + 1], -data->boltVertexPosX[i + 1], data->boltVertexPosY[i], -data->boltVertexPosX[i]);
                prevAngle = -atan2(data->boltVertexPosY[i], -data->boltVertexPosX[i], data->boltVertexPosY[i - 1], -data->boltVertexPosX[i - 1]);
                if (prevAngle - nextAngle > 180.0f) {
                    nextAngle += 360.0f;
                } else if (prevAngle - nextAngle < -180.0f) {
                    prevAngle += 360.0f;
                }
                temp = nextAngle + prevAngle; // required to match
                edgeAngle = temp;
                edgeAngle *= 0.5;

                if (prevAngle + nextAngle < 0.0f) { // required to match
                    nextAngle += 360.0f;
                }
            }
        }

        edgeLength *= (widthScale * data->edgeLength[i]);
        texOffsetX = (128 - i * 12) * 32;
        edgeDeltaX = edgeLength  * sin_deg(edgeAngle);
        edgeDeltaY = edgeLength * cos_deg(edgeAngle);
        edgeDeltaZ = 0.0f;

        vtx->ob[0] = (data->boltVertexPosX[i] + edgeDeltaX) * 10.0f;
        vtx->ob[1] = (data->boltVertexPosY[i] + edgeDeltaY) * 10.0f;
        vtx->ob[2] = (data->boltVertexPosZ[i] + edgeDeltaZ) * 10.0f;
        vtx->tc[0] = texOffsetX;
        vtx->tc[1] = 0;
        vtx->cn[0] = i * 50;
        vtx->cn[1] = i * 120;
        vtx->cn[2] = i * 30;
        vtx++;

        vtx->ob[0] = (data->boltVertexPosX[i] - edgeDeltaX) * 10.0f;
        vtx->ob[1] = (data->boltVertexPosY[i] - edgeDeltaY) * 10.0f;
        vtx->ob[2] = (data->boltVertexPosZ[i] + edgeDeltaZ) * 10.0f;
        vtx->tc[0] = texOffsetX;
        vtx->tc[1] = 0x400;
        vtx->cn[0] = i * 50;
        vtx->cn[1] = i * 120;
        vtx->cn[2] = i * 30;
        vtx++;
    }

    quadCount = i;

    gSPVertex(gMainGfxPos++, vtxBuffer, i * 2, 0);
    gSPClearGeometryMode(gMainGfxPos++, G_SHADING_SMOOTH);

    for (i = 0; i < quadCount - 1; i++) {
        gSP2Triangles(gMainGfxPos++, i * 2 + 1, i * 2 + 0, i * 2 + 2, 0,
                                       i * 2 + 1, i * 2 + 2, i * 2 + 3, 0);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
