#include "common.h"
#include "effects_internal.h"

typedef struct UnkStruct {
    /* 0x00 */ u8 unk_00[0xC];
    /* 0x0C */ u8 unk_0C[0xC];
} UnkStruct; // size = 0x18

UnkStruct D_E00BCC30[] = {
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

UnkStruct D_E00BCD38[] = {
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

UnkStruct* D_E00BCE40[] = { D_E00BCC30, D_E00BCD38 };

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
    bp.renderWorld = lightning_bolt_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_LIGHTNING_BOLT;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.lightningBolt = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.lightningBolt != NULL);

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
    data->unk_4C = scale;

    temp = SQ(startX - endX) + SQ(startY - endY) + SQ(startZ - endZ);

    if (temp != 0.0f) {
        data->unk_114 = shim_sqrtf(temp) * 0.005;
        data->outerColor.r = 255;
        data->outerColor.g = 220;
        data->outerColor.b = 20;
        data->innerColor.r = 255;
        data->innerColor.g = 255;
        data->innerColor.b = 255;
        data->unk_110 = shim_rand_int(359);

        return effect;
    } else {
        return NULL;
    }
}

void lightning_bolt_init(EffectInstance* effect) {
}

f32 lightning_bolt_get_rand_symmetric(f32 interval) {
    return (f32)shim_rand_int(interval) - interval * 0.5;
}

void lightning_bolt_update(EffectInstance* effect) {
    LightningBoltFXData* data = effect->data.lightningBolt;
    s32 type = data->type;

    if (effect->flags & EFFECT_INSTANCE_FLAG_10) {
        effect->flags &= ~EFFECT_INSTANCE_FLAG_10;
        data->timeLeft = 16;
    }

    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifetime++;

    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
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
    if (gGameStatusPtr->isBattle == TRUE) {
        renderTask.distance = data->tipPos.z + 1000.0f;
    } else {
        renderTask.distance = 10;
    }

    renderTaskPointer->renderMode = RENDER_MODE_2D;
    retTask = shim_queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00BC36C(void) {
}

// float
#ifdef NON_MATCHING
void lightning_bolt_appendGfx(void* effect) {
    Vtx_t* sp90;
    f32 sp94;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 var_f20;
    f32 var_f22;
    f32 var_f2;
    s16 temp_s0_2;
    s32 temp_a0;
    s32 temp_s3;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_t3;
    UnkStruct* var_s2;
    Vtx_t* vtx;
    f32 zero;
    f32 t1, t2, t3, t4;
    LightningBoltFXData* data = ((EffectInstance*)effect)->data.lightningBolt;
    Matrix4f sp10;
    Matrix4f unused;
    s32 i;
    f32 temp_fs2;

    temp_s7 = data->lifetime;
    temp_s3 = data->outerColor.a;
    temp_s6 = data->type;
    sp94 = data->unk_4C;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guScaleF(sp10, 0.1f, 0.1f, 0.1f);
    shim_guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->outerColor.r, data->outerColor.g, data->outerColor.b, temp_s3);
    gDPSetEnvColor(gMasterGfxPos++, data->innerColor.r, data->innerColor.g, data->innerColor.b, 128);
    gSPDisplayList(gMasterGfxPos++, D_09001000_3BBEA0);

    temp_a0 = temp_s7 - 1;
    if (temp_s6 != 2) {
        if (temp_a0 <= 10) {
            var_s2 = &D_E00BCE40[temp_s6][temp_a0];
        } else {
            var_s2 = &D_E00BCE40[temp_s6][10];
        }
    } else if (temp_a0 < 8) {
        var_s2 = &D_E00BCE40[0][temp_a0];
    } else if (temp_a0 < 0x24) {
        var_s2 = &D_E00BCE40[0][temp_a0 % 6 + 2];
    } else {
        var_s2 = &D_E00BCE40[0][10];
    }

    for (i = 0; i < 12; i++) {
        temp_f24 = (data->endPos.x - data->startPos.x) * (1 / 11.0f);
        temp_f22 = (data->endPos.y - data->startPos.y) * (1 / 11.0f);
        temp_f28 = (data->unk_110 + (i - temp_s7) * 10) % 120 - 60;
        temp_f26 = var_s2->unk_00[i];

        temp_f20 = shim_sin_deg(temp_f28) * temp_f26 * 0.04;
        temp_f0 = shim_cos_deg(temp_f28) * temp_f26 * 0.04;

        t1 = (temp_f24 * temp_f0 - temp_f22 * temp_f20);
        t2 = (temp_f24 * temp_f20 + temp_f22 * temp_f0);
        t3 = 0.0f;

        data->unk_50[i] = data->startPos.x + (data->endPos.x - data->startPos.x) * i * (1 / 11.0f) + t1;
        data->unk_80[i] = data->startPos.y + (data->endPos.y - data->startPos.y) * i * (1 / 11.0f) + t2;
        data->unk_B0[i] = data->startPos.z + (data->endPos.z - data->startPos.z) * i * (1 / 11.0f) + t3;
        data->unk_E0[i] = (f32) var_s2->unk_0C[i] * 0.1;
    }

    sp90 = (Vtx_t*) (gMasterGfxPos + 1);
    vtx = (Vtx_t*) (gMasterGfxPos + 1);
    gSPBranchList(gMasterGfxPos, gMasterGfxPos + 0x31);
    gMasterGfxPos += 0x31;

    for (i = 0; i < 12; i++) { //s2: i
        if (i == 0) {
            temp_fs2 = 8.0f;
            var_f22 = -shim_atan2(data->unk_80[1], -data->unk_50[1], data->unk_80[0], -data->unk_50[0]);
        } else {
            temp_fs2 = 8.0f;
            if (i == 11) {
                var_f22 = -90.0f;
            } else {
                var_f20 = -shim_atan2(data->unk_80[i + 1], -data->unk_50[i + 1], data->unk_80[i], -data->unk_50[i]);
                var_f2 = -shim_atan2(data->unk_80[i], -data->unk_50[i], data->unk_80[i - 1], -data->unk_50[i - 1]);
                var_f22 = var_f2 - var_f20;
                if (var_f22 > 180.0f) {
                    var_f20 += 360.0f;
                } else if (var_f22 < -180.0f) {
                    var_f2 += 360.0f;
                }
                //var_f22 = (var_f20 + var_f2) * 0.5;
                var_f22 = (var_f20 + var_f2);
                var_f22 /= 2.0;
            }
        }

        temp_fs2 *= (sp94 * data->unk_E0[i]);
        temp_s0_2 = (128 - i * 12) * 32;
        temp_f20_2 = temp_fs2  * shim_sin_deg(var_f22);
        temp_f0_2 = temp_fs2 * shim_cos_deg(var_f22);
        zero = 0.0f;

        vtx->ob[0] = (data->unk_50[i] + temp_f20_2) * 10.0f;
        vtx->ob[1] = (data->unk_80[i] + temp_f0_2) * 10.0f;
        vtx->ob[2] = (data->unk_B0[i] + zero) * 10.0f; // 0.0f: fs4 (fs5)
        vtx->tc[0] = temp_s0_2;
        vtx->tc[1] = 0;
        vtx->cn[0] = i * 50; //s6
        vtx->cn[1] = i * 120; //s7
        vtx->cn[2] = i * 30; //s8
        vtx++;

        vtx->ob[0] = (data->unk_50[i] - temp_f20_2) * 10.0f;
        vtx->ob[1] = (data->unk_80[i] - temp_f0_2) * 10.0f;
        vtx->ob[2] = (data->unk_B0[i] + zero) * 10.0f;
        vtx->tc[0] = temp_s0_2;
        vtx->tc[1] = 0x400;
        vtx->cn[0] = i * 50;
        vtx->cn[1] = i * 120;
        vtx->cn[2] = i * 30;
        vtx++;
    }

    temp_t3 = i;

    gSPVertex(gMasterGfxPos++, sp90, i * 2, 0);
    gSPClearGeometryMode(gMasterGfxPos++, G_SHADING_SMOOTH);

    for (i = 0; i < temp_t3 - 1; i++) {
        gSP2Triangles(gMasterGfxPos++, i * 2 + 1, i * 2, i * 2 + 2, 0, i * 2 + 1, i * 2 + 2, i * 2 + 3, 0);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
#else
INCLUDE_ASM(s32, "effects/lightning_bolt", lightning_bolt_appendGfx);
#endif
