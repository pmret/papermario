#include "common.h"
#include "effects_internal.h"

void chomp_drop_init(EffectInstance* effect);
void chomp_drop_update(EffectInstance* effect);
void chomp_drop_render(EffectInstance* effect);
void chomp_drop_appendGfx(void* effect);

extern Gfx D_09001040_398080[];
extern Gfx D_090010E8_398128[];
extern Gfx D_09001190_3981D0[];

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
    bp.renderUI = NULL;
    bp.effectID = EFFECT_CHOMP_DROP;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.chompDrop = general_heap_malloc(numParts * sizeof(*data));
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
    data->unk_38 = rand_int(360);
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

EFFECT_DEF_DUST(dust_main);

void chomp_drop_update(EffectInstance* effect) {
    ChompDropFXData* data = effect->data.chompDrop;
    s32 unk40;

    data->unk_40--;
    data->unk_44++;
    if (data->unk_40 < 0) {
        remove_effect(effect);
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
                load_effect(EFFECT_DUST);
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
    renderTask.dist = -10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void chomp_drop_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    ChompDropFXData* data = effectTemp->data.chompDrop;
    f32 temp_f22 = data->unk_34;
    s32 temp_s7 = data->unk_38;
    s32 primA = data->unk_3C;
    s32 temp_s6 = data->unk_44;
    Matrix4f sp20, sp60;
    Gfx* savedGfxPos;
    Vtx_t* vtxTemp;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effectTemp)->graphics->data));

    guScaleF(sp20, 0.01f, 0.01f, 0.01f);
    guPositionF(sp60, 0.0f, 0.0f, 0.0f, data->unk_24, data->unk_04 * 100.0f, data->unk_08 * 100.0f, data->unk_0C * 100.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(
        gMainGfxPos++, 0, 0,
        (sin_deg(temp_s6 * 30) * 25.0f) + 225.0f,
        (sin_deg(temp_s6 * 30) * 25.0f) + 225.0f,
        255,
        primA
    );

    if (data->unk_2C == 1) {
        gSPDisplayList(gMainGfxPos++, D_09001040_398080);
        gSPDisplayList(gMainGfxPos++, D_09001190_3981D0);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, ((30 - data->unk_30) * 255) / 30);
        gSPDisplayList(gMainGfxPos++, D_090010E8_398128);
        gSPDisplayList(gMainGfxPos++, D_09001190_3981D0);
    } else {
        if (data->unk_2C > 0) {
            gSPDisplayList(gMainGfxPos++, D_090010E8_398128);
        } else {
            gSPDisplayList(gMainGfxPos++, D_09001040_398080);
        }

        savedGfxPos = gMainGfxPos + 1;
        gSPBranchList(gMainGfxPos, gMainGfxPos + 0x41);
        gMainGfxPos = savedGfxPos;
        vtxTemp = (Vtx_t*) savedGfxPos;

        for (i = 0; i < 16; i++) {
            Vtx_t* vtx = &vtxTemp[i * 2];
            s32 temp_s1 = sin_deg(((temp_s6 * 10) + (i * 60)) + temp_s7) * 500.0f * temp_f22;
            s32 temp_v0_3 = (i * 400) + (s32) (sin_deg(((temp_s6 * 10) + (i * 6)) + temp_s7) * 200.0f * temp_f22);

            vtx->ob[0] = temp_s1 - 3200;
            vtx->ob[1] = temp_v0_3;
            vtx->ob[2] = 0;
            vtx->tc[0] = 0;
            vtx->tc[1] = i * 128;
            vtx++;

            vtx->ob[0] = temp_s1 + 3200;
            vtx->ob[1] = temp_v0_3;
            vtx->ob[2] = 0;
            vtx->tc[0] = 2048;
            vtx->tc[1] = i * 128;
        }

        gMainGfxPos += 0x40;
        gSPVertex(gMainGfxPos++, vtxTemp, 32, 0);

        for (i = 0; i < 15; i++) {
            s32 i2 = i * 2;
            gSP2Triangles(gMainGfxPos++,
                i2    , i2 + 2, i2 + 1, i2,
                i2 + 1, i2 + 2, i2 + 3, i2);
            };
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
