#include "common.h"
#include "effects_internal.h"

void chomp_drop_init(EffectInstance* effect);
void chomp_drop_update(EffectInstance* effect);
void chomp_drop_render(EffectInstance* effect);
void chomp_drop_appendGfx(void* effect);

EffectInstance* chomp_drop_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, f32 arg6, s32 arg7, 
                                f32 arg8, s32 arg9) 
{
    EffectBlueprint bp;
    EffectInstance* effect;
    ChompDropFXData* data;
    s32 numParts = 1;

    bp.init = chomp_drop_init;
    bp.update = chomp_drop_update;
    bp.renderWorld = chomp_drop_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_CHOMP_DROP;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.chompDrop = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.chompDrop != NULL);

    data->unk_00 = arg0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_28 = arg8;
    data->unk_14 = arg4;
    data->unk_1C = arg5;
    data->unk_18 = arg6;
    data->unk_34 = 1.0f;
    data->unk_20 = arg7;
    data->unk_38 = shim_rand_int(0x168);
    data->unk_40 = arg9;
    data->unk_44 = 0;
    data->unk_3C = arg5;
    data->unk_24 = arg4;
    data->unk_10 = 0;
    data->unk_2C = 0;

    return effect;
}

void chomp_drop_init(EffectInstance* effect) {
}

void chomp_drop_update(EffectInstance* effect) {
    ChompDropFXData* data = effect->data.chompDrop;
    s32 unk40;

    data->unk_40--;
    data->unk_44++;
    if (data->unk_40 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk40 = data->unk_40;
    switch (data->unk_2C) {
        case 0:
            data->unk_24 += (data->unk_18 - data->unk_24) * data->unk_28;
            data->unk_3C += (data->unk_20 - data->unk_3C) * data->unk_28;
            data->unk_34 -= 0.02;
            if (data->unk_34 < 0.0f) {
                data->unk_30 = 10;
                data->unk_34 = 0.0f;
                data->unk_10 = 0.0f;
                data->unk_2C = 1;
            }
            break;
        case 1:
            data->unk_30--;
            if (data->unk_30 <= 0) {
                data->unk_2C = 2;
                data->unk_30 = 10;
            }
            break;
        case 2:
            data->unk_30--;
            if (data->unk_30 <= 0) {
                data->unk_2C = 3;
            }
            break;
        case 3:
            data->unk_10 -= 1.0f;
            data->unk_08 += data->unk_10;
            if (data->unk_08 < 0.0f) {
                data->unk_08 = 0.0f;
                shim_load_effect(EFFECT_DUST);
                dust_main(2, data->unk_04 + 5.0f, data->unk_08, data->unk_0C, 30);
                dust_main(2, data->unk_04 - 5.0f, data->unk_08, data->unk_0C, 30);
                data->unk_2C = 4;
                data->unk_30 = 20;
            }
            break;
        case 4:
            data->unk_30--;
            if (data->unk_30 <= 0) {
                data->unk_2C = 5;
            }
            break;
        case 5:
            if (unk40 < 10) {
                data->unk_3C = unk40 * 25;
            }
            data->unk_34 -= 0.05;
            break;
    }
}

void chomp_drop_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = chomp_drop_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = -10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

#ifdef WIP
extern Gfx D_09001040[];
extern Gfx D_090010E8[];
extern Gfx D_09001190[];

// wip
void chomp_drop_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    ChompDropFXData* data = effectTemp->data.chompDrop;
    Matrix4f sp20, sp60;
    s32 primA;
    Gfx* gfxPos;
    Vtx* temp_v0_2;
    Vtx* temp_s0_2;
    Vtx* temp_s0_3;
    f32 sinTheta;
    f32 sinTheta2;
    s32 i;

    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f20_3;
    f32 temp_f22;
    s16 temp_v0_3;
    s16 temp_v1_4;
    s32 temp_a1;
    s32 temp_s1;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_t0;
    u8 primR;
    u8 primG;

    temp_f22 = data->unk_34;
    temp_s7 = data->unk_38;
    primA = data->unk_3C;
    temp_s6 = data->unk_44;
    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effectTemp)->graphics->data));

    shim_guScaleF(sp20, 0.01f, 0.01f, 0.01f);
    shim_guPositionF(sp60, 0.0f, 0.0f, 0.0f, data->unk_24, data->unk_04 * 100.0f, data->unk_08 * 100.0f, data->unk_0C * 100.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    sinTheta = shim_sin_deg(temp_s6 * 30);
    sinTheta2 = shim_sin_deg(temp_s6 * 30);

    primR = (sinTheta * 25.0f) + 225.0f;
    primG = (sinTheta2 * 25.0f) + 225.0f;

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, primR, primG, 255, primA);

    temp_v1_2 = data->unk_2C;
    if (temp_v1_2 == 1) {
        gSPDisplayList(gMasterGfxPos++, D_09001040);
        gSPDisplayList(gMasterGfxPos++, D_09001190);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, ((30 - data->unk_30) * 255) / 30);
        gSPDisplayList(gMasterGfxPos++, D_090010E8);
        gSPDisplayList(gMasterGfxPos++, D_09001190);
    } else {
        if (temp_v1_2 > 0) {
            gSPDisplayList(gMasterGfxPos++, D_090010E8);
        } else {
            gSPDisplayList(gMasterGfxPos++, D_09001040);
        }
        temp_v0_2 = gMasterGfxPos;

        var_s5 = 0;
        var_s3 = temp_s6 * 10;
        var_s4 = var_s3;
        gfxPos = gMasterGfxPos;
        gSPBranchList(gMasterGfxPos++, gMasterGfxPos + 0x208);
        gMasterGfxPos = temp_v0_2;
        
        for (i = 0; i < 16; i++) {
            temp_s0_2 = &temp_v0_2[i];
            temp_s1 = (s32) (shim_sin_deg(var_s4 + temp_s7) * 500.0f * temp_f22);
            var_s3 += 6;
            var_s4 += 50;
            temp_v1_4 = i << 7;
            temp_f0_2 = shim_sin_deg(var_s3 + temp_s7) * 200.0f * temp_f22;
            temp_s0_2->v.ob[0] = temp_s1 - 3200;
            temp_s0_2->v.ob[2] = 0;
            temp_s0_2->v.tc[1] = 0;
            temp_s0_2->v.tc[2] = temp_v1_4;
            temp_v0_3 = var_s5 + (s32) temp_f0_2;
            temp_s0_2->v.ob[1] = temp_v0_3;
            temp_s0_3 = temp_s0_2 + 0x10;
            var_s5 += 0x190;
            temp_s0_3->v.ob[1] = temp_v0_3;
            temp_s0_3->v.tc[1] = 0x800;
            temp_s0_3->v.ob[0] = temp_s1 + 3200;
            temp_s0_3->v.ob[2] = 0;
            temp_s0_3->v.tc[2] = temp_v1_4;
        }

        gMasterGfxPos = gfxPos;
        gSPVertex(gMasterGfxPos++, temp_v0_2, 32, 0);
       
        for (i = 0; i < 15; i++) {
            temp_a1 = i * 2;
            if (temp_a1 == 0) {
                //var_v0_3 = (i << 0x11) | 0x402;
                // temp_a0_5->words.w0 = var_v0_3 | 06000000
                // temp_a0_5->words.w1 = 00020406
                gSP2Triangles(gMasterGfxPos++, i, 2, 1, 0, 1, 2, 3, 0);
            } else if (temp_a1 == 1) {
                gSP2Triangles(gMasterGfxPos++, 3, 2, 1, 0, 3, 4, 2, 0);
            } else {
                // var_v0_3 = ((var_a2 & 0xFF) << 0x10) | ((i << 0xA) & 0xFC00) | (var_a3 & 0xFF);
                // temp_a0_5->words.w0 = var_v0_3 | 06000000
                // temp_a0_5->words.w1 = ((var_t0 & 0xFF) << 0x10) | ((var_a2 & 0xFF) << 8) | (var_a3 & 0xFF);
                gSP2Triangles(gMasterGfxPos++, 
                    i, 
                    1 + 4 * i, 
                    2 + 4 * i, 
                    0, 
                    3 + 4 * i, 
                    1 + 4 * i, 
                    2 + 4 * i, 
                    0
                );
            }
        }
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}
#else
INCLUDE_ASM(s32, "effects/chomp_drop", chomp_drop_appendGfx);
#endif
