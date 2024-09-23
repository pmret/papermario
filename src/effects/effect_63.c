#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001B70_3CF250[];
extern Gfx D_09001C98_3CF378[];

Gfx* D_E00C6C90[] = {
    D_09001C98_3CF378, D_09001C98_3CF378, D_09001C98_3CF378
};

Gfx* D_E00C6C9C[] = {
    D_09001B70_3CF250, D_09001B70_3CF250, D_09001B70_3CF250, NULL, NULL
};

void effect_63_init(EffectInstance* effect);
void effect_63_update(EffectInstance* effect);
void effect_63_render(EffectInstance* effect);
void effect_63_appendGfx(void* effect);

EffectInstance* effect_63_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    f32 arg6,
    f32 arg7,
    s32 arg8,
    s32 arg9
) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    Effect63FXData* part;
    f32 randInt;
    s32 numParts;
    s32 i;

    if (arg0 == 2) {
        numParts = 8;
    } else {
        numParts = 1;
    }

    bpPtr->init = effect_63_init;
    bpPtr->update = effect_63_update;
    bpPtr->renderWorld = effect_63_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_63;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.unk_63 = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.unk_63 != NULL);

    if (arg9 <= 0) {
        part->unk_20 = 1000;
    } else {
        part->unk_20 = arg9;
    }
    part->unk_00 = arg0;
    part->unk_24 = 0;
    part->unk_1C = arg8;
    part->unk_34 = 0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_10 = arg4;
    part->unk_14 = arg5;
    part->unk_18 = arg6;
    part->unk_48 = arg7;
    part->unk_60 = (part->unk_10 - part->unk_04) / arg8;
    part->unk_64 = (part->unk_14 - part->unk_08) / arg8;
    part->unk_68 = (part->unk_18 - part->unk_0C) / arg8;

    if (arg0 != 0) {
        if (arg0 == 1) {
            part->unk_28 = 255;
            part->unk_2C = 88;
            part->unk_30 = 70;
            part->unk_34 = 55;
            part->unk_38 = 11;
            part->unk_3C = 51;
            part->unk_40 = 123;
            part->unk_44 = 255;
            part->unk_4C = rand_int(64);
            part->unk_50 = rand_int(64);
            part->unk_54 = 0;
            part->unk_58 = 0;
            part->unk_74 = 0;
            part->unk_70 = 0.2f;
            part->unk_6C = 0.3f;
            part->unk_78 = -10.0f;
        } else {
            part->unk_28 = 255;
            part->unk_2C = 88;
            part->unk_30 = 70;
            part->unk_34 = 55;
            part->unk_38 = 11;
            part->unk_3C = 51;
            part->unk_40 = 123;
            part->unk_44 = 255;
            randInt = rand_int(360);

            for (i = 0; i < numParts; i++, part++) {
                part->unk_04 = arg1;
                part->unk_08 = arg2;
                part->unk_0C = arg3;
                part->unk_60 = sin_deg(i * 45 + randInt) * 5.0f;
                part->unk_64 = cos_deg(i * 45 + randInt) * 2.0f + 3.0f;
                part->unk_4C = rand_int(64);
                part->unk_50 = rand_int(64);
                part->unk_70 = 1.0f;
                part->unk_6C = 1.0f;
                part->unk_54 = 0;
                part->unk_58 = 0;
                part->unk_74 = -45.0f;
                part->unk_78 = -10.0f;
            }
        }
    }

    return effect;
}

void effect_63_init(EffectInstance* effect) {
}

void effect_63_update(EffectInstance* effect) {
    Effect63FXData* part = effect->data.unk_63;
    s32 unk_00 = part->unk_00;
    s32 unk_24;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->unk_20 = 0x10;
    }

    if (part->unk_20 < 1000) {
        part->unk_20--;
    }

    part->unk_24++;
    if (part->unk_20 == 1 && unk_00 == 1) {
        load_effect(EFFECT_63);
        effect_63_main(2, part->unk_04, part->unk_08, part->unk_0C, part->unk_10, part->unk_14, part->unk_18, 1.0f, 32, 32);
    }

    if (part->unk_20 < 0) {
        remove_effect(effect);
        return;
    }

    unk_24 = part->unk_24;

    switch (unk_00) {
        case 0:
            if (!(unk_24 & (1 | 2))) {
                load_effect(EFFECT_63);
                effect_63_main(1, part->unk_04, part->unk_08, part->unk_0C, part->unk_10, part->unk_14, part->unk_18, 1.0f, part->unk_1C, part->unk_1C);
            }
            break;
        case 1:
            part->unk_60 *= 0.97;
            part->unk_68 *= 0.97;
            part->unk_04 += part->unk_60;
            part->unk_74 += part->unk_78;
            part->unk_0C += part->unk_68;
            part->unk_64 += (1.0f - part->unk_64) * 0.02;
            part->unk_70 += (1.0 - part->unk_70) * 0.05;
            part->unk_6C += (1.0 - part->unk_6C) * 0.1;
            part->unk_08 += part->unk_64;
            break;
        case 2:
            for (i = 0; i < effect->numParts; i++, part++) {
                part->unk_60 *= 0.9;
                part->unk_64 -= 0.2;
                part->unk_04 += part->unk_60;
                part->unk_08 += part->unk_64;
                if (part->unk_08 < 0.0f) {
                    part->unk_08 = 0.0f;
                    if (part->unk_64 < 0.0f) {
                        part->unk_64 *= -0.6;
                    }
                }
                part->unk_70 += (0.0f - part->unk_70) * 0.07;
                part->unk_6C += (0.0f - part->unk_6C) * 0.05;
                part->unk_74 += part->unk_78;
            }
            break;
    }
}

void effect_63_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = effect_63_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void effect_63_appendGfx(void* effect) {
    Effect63FXData* part = ((EffectInstance*)effect)->data.unk_63;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_34 = part->unk_34;
    s32 unk_00 = part->unk_00;
    f32 unk_48 = part->unk_48;
    Matrix4f sp18;
    Matrix4f sp58;
    f32 angle;
    s32 tempX;
    s32 tempY;
    s32 i;

    if (part->unk_00 != 0) {
        gDPPipeSync(gMainGfxPos++);
        gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
        gDPSetPrimColor(gMainGfxPos++, 0, 0, part->unk_28, part->unk_2C, part->unk_30, unk_34);
        gDPSetEnvColor(gMainGfxPos++, part->unk_38, part->unk_3C, part->unk_40, part->unk_44);
        gSPDisplayList(gMainGfxPos++, D_E00C6C9C[unk_00]);

        for (i = 0; i < ((EffectInstance*)effect)->numParts; i++, part++) {
            part->unk_4C += part->unk_54;
            part->unk_50 += part->unk_58;

            angle = -atan2(0.0f, 0.0f, part->unk_60, part->unk_64) + part->unk_74;
            part->unk_54 = sin_deg(angle);
            part->unk_58 = cos_deg(angle);

            if (part->unk_4C < 0.0f) {
                part->unk_4C += 128.0f;
            }

            if (part->unk_50 > 128.0f) {
                part->unk_50 -= 128.0f;
            }

            tempX = part->unk_4C * 4.0f;
            tempY = part->unk_50 * 4.0f;

            guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
            guScaleF(sp58, unk_48, unk_48, unk_48);
            guMtxCatF(sp58, sp18, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            guScaleF(sp18, part->unk_70, part->unk_6C, 1.0f);
            guRotateF(sp58, part->unk_74, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp58, sp18, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetTileSize(gMainGfxPos++, 1, tempX, tempY, (tempX + 0x3F) * 4, (tempY + 0xF) * 4);
            gSPDisplayList(gMainGfxPos++, D_E00C6C90[unk_00]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
}
