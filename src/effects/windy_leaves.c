#include "common.h"
#include "effects_internal.h"

void windy_leaves_init(EffectInstance* effect);
void windy_leaves_update(EffectInstance* effect);
void windy_leaves_render(EffectInstance* effect);
void windy_leaves_appendGfx(void* effect);

extern Gfx D_09001180_33E790[];
extern Gfx D_09001258_33E868[];
extern Gfx D_09001280_33E890[];

void windy_leaves_main(s32 type, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    WindyLeavesFXData* part;
    s32 numParts;
    s32 i;

    bp.init = windy_leaves_init;
    bp.update = windy_leaves_update;
    bp.renderScene = windy_leaves_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_WINDY_LEAVES;

    numParts = 5;
    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    effect->data.windyLeaves = part = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(part != NULL);

    part->type = type;
    part->unk_04.x = arg1;
    part->unk_04.y = arg2;
    part->unk_04.z = arg3;
    part->unk_28 = 100;
    part->unk_2C = 0;
    part->alpha = 0;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        s32 temp_s0_2 = effect_rand_int(50);
        s32 temp_s1 = effect_rand_int(20);
        s32 temp_s2 = effect_rand_int(360);
        s32 temp_v0_2 = effect_rand_int(100);
        part->unk_04.x = temp_s0_2 + 75;
        part->unk_04.y = temp_s1 + 70;
        part->unk_04.z = 0;
        part->unk_18 = temp_s2;
        part->unk_20 = 360 - temp_s2;

        switch (type) {
            case 0:
                part->unk_10 = 0.0f;
                part->unk_14 = 0.0f;
                part->unk_34 = 0;
                part->unk_30 = -3.0f;
                part->unk_38 = 3.0f;
                part->unk_1C = (f32)temp_v0_2 * 0.1;
                break;
            case 1:
                part->unk_10 = 0.0f;
                part->unk_14 = 0.0f;
                part->unk_34 = 0;
                part->unk_30 = -6.0f;
                part->unk_38 = 6.0f;
                part->unk_1C = 2.0 * ((f32)temp_v0_2 * 0.1);
                break;
            case 2:
                part->unk_1C = 2.0 * ((f32)temp_v0_2 * 0.1);
                part->unk_10 = -part->unk_04.x * (rand_int(10) * 0.008 + 0.05);
                part->unk_14 = -part->unk_04.y * (rand_int(10) * 0.008 + 0.05);
                break;
            default:
                break;
        }
    }
}

void windy_leaves_init(EffectInstance* effect) {
}

void windy_leaves_update(EffectInstance* effect) {
    WindyLeavesFXData* part = effect->data.windyLeaves;
    f32 temp_f0_2;
    f32 temp_f4;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_a1;
    s32 i;
    s32 temp;
    s32 temp2;

    part->unk_28--;
    part->unk_2C++;
    if (part->unk_28 < 0) {
        remove_effect(effect);
        return;
    }
    temp_a1 = part->unk_2C;
    temp_v0 = part->unk_28;
    temp = part->type;
    if (temp_a1 < 10) {
        part->alpha += (255 - part->alpha) * 0.3;
    }
    if (temp_v0 < 10) {
        part->alpha *= 0.8;
    }

    part++;
    switch (temp) {
        case 0:
            for (i = 1; i < effect->numParts; i++, part++) {
                f32 temp3 = (sin_deg(2.0f * part->unk_18) * 0.2);
                part->unk_14 += -0.05f;
                part->unk_10 += temp3;
                if (temp == 0) {
                    part->unk_10 *= 0.94;
                    part->unk_14 *= sin_deg(part->unk_18) * 0.05 + 0.95;
                } else {
                    part->unk_14 += -0.05f;
                    part->unk_10 *= 0.92;
                }
                part->unk_1C += effect_simple_rand(50, temp_a1 + i * 20) - 25;
                part->unk_18 += sin_deg(part->unk_1C) * 10.0f;
                part->unk_20 += cos_deg(part->unk_1C * 0.5) * 10.0f;
                part->unk_04.x += part->unk_10;
                part->unk_04.y += part->unk_14;
                if (part->unk_04.y < 30.0f) {
                    if (part->unk_04.x > -200.0f) {
                        part->unk_30 -= 0.4;
                    } else {
                        part->unk_30 += 0.4;
                    }
                    if (part->unk_04.z > 0.0f) {
                        part->unk_38 -= 0.4;
                    } else {
                        part->unk_38 += 0.4;
                    }
                    part->unk_30 *= 0.98;
                    part->unk_38 *= 0.98;
                    part->unk_14 *= 0.98;
                } else {
                    if(part->unk_04.x > 0.0f) {
                        part->unk_30 -= 0.4;
                    } else {
                        part->unk_30 += 0.4;
                    }
                    if (part->unk_04.z > 0.0f){
                        part->unk_38 -= 0.4;
                    } else {
                        part->unk_38 += 0.4;
                    }
                    part->unk_30 *= 0.98;
                    part->unk_38 *= 0.98;
                }
                part->unk_04.x += part->unk_30;
                part->unk_04.y += part->unk_34;
                part->unk_04.z += part->unk_38;
            }
            break;
        case 1:
            for (i = 1; i < effect->numParts; i++, part++) {
                part->unk_10 += (f32)(sin_deg(2.0f * part->unk_18) * 0.2 * 2.0);
                part->unk_14 += -0.05f;
                part->unk_10 *= 0.8464;
                part->unk_14 += -0.05f;
                part->unk_1C += effect_simple_rand(50, temp_a1 + i * 20) - 25;
                part->unk_18 += sin_deg(part->unk_1C) * 10.0f;
                part->unk_20 += cos_deg(part->unk_1C * 0.5) * 10.0f;
                part->unk_04.x += part->unk_10;
                part->unk_04.y += part->unk_14;
                if (part->unk_04.y < 30.0f) {
                    if (part->unk_04.x > -200.0f) {
                        part->unk_30 -= 0.8;
                    } else {
                        part->unk_30 += 0.8;
                    }
                    if (part->unk_04.z > 0.0f) {
                        part->unk_38 -= 0.8;
                    } else {
                        part->unk_38 += 0.8;
                    }
                    part->unk_30 *= 0.9603999999999999;
                    part->unk_38 *= 0.9603999999999999;
                    part->unk_14 *= 0.9603999999999999;
                } else {
                    if (part->unk_04.x > 0.0f){
                        part->unk_30 -= 0.8;
                    } else {
                        part->unk_30 += 0.8;
                    }
                    if (part->unk_04.z > 0.0f){
                        part->unk_38 -= 0.8;
                    } else {
                        part->unk_38 += 0.8;
                    }
                    part->unk_30 *= 0.9603999999999999;
                    part->unk_38 *= 0.9603999999999999;
                }
                part->unk_04.x += part->unk_30;
                part->unk_04.y += part->unk_34;
                part->unk_04.z += part->unk_38;
            }
            break;
        case 2:
            for (i = 1; i < effect->numParts; i++, part++) {
                part->unk_1C += effect_simple_rand(50,  temp_a1 + i * 20) - 25;
                part->unk_18 += sin_deg(part->unk_1C) * 10.0f;
                part->unk_20 += cos_deg(part->unk_1C * 0.5) * 10.0f;
                part->unk_04.x += part->unk_10;
                part->unk_04.y += part->unk_14;
            }
            break;
    }
}

void windy_leaves_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = windy_leaves_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void windy_leaves_appendGfx(void* effect) {
    WindyLeavesFXData* part = ((EffectInstance*)effect)->data.windyLeaves;
    Matrix4f sp18, sp58, sp98;
    Gfx* dlist;
    s32 i;

    dlist = D_09001280_33E890;
    if (part->type == 0) {
        dlist = D_09001258_33E868;
    }

    gSPSegment(gMainGfxPos++, 0x09, OS_K0_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, D_09001180_33E790);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 20, 100, 20, part->alpha);
    guTranslateF(sp18, part->unk_04.x, part->unk_04.y, part->unk_04.z);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        guTranslateF(sp58, part->unk_04.x, part->unk_04.y, part->unk_04.z);
        guMtxCatF(sp58, sp98, sp18);
        guRotateF(sp58, part->unk_18, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guRotateF(sp58, part->unk_20, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}

