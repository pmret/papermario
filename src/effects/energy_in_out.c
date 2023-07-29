#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000200_3D6130[];
extern Gfx D_090003A8_3D62D8[];
extern Gfx D_090003C8_3D62F8[];
extern Gfx D_090003E8_3D6318[];
extern Gfx D_09000528_3D6458[];
extern Gfx D_09000540_3D6470[];
extern Gfx D_09000558_3D6488[];
extern Gfx D_09000688_3D65B8[];
extern Gfx D_09000808_3D6738[];

Gfx* D_E00D6E40[] = {
    D_090003A8_3D62D8, D_090003C8_3D62F8, D_090003E8_3D6318, D_09000528_3D6458,
    D_09000540_3D6470, D_09000558_3D6488, D_09000688_3D65B8, D_09000688_3D65B8,
    D_09000688_3D65B8, D_09000558_3D6488, D_09000808_3D6738, D_09000688_3D65B8,
    D_09000558_3D6488
};

u8 D_E00D6E74[] = {
    0x0B, 0x0B, 0x0B, 0x0B, 0x11, 0x0B, 0x0B, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x00, 0x00, 0x00
};

u8 D_E00D6E84[] = {
    0x14, 0x05, 0x14, 0x14, 0x0A, 0x14, 0x14, 0x08, 0x08, 0x08, 0x01, 0x01, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void energy_in_out_init(EffectInstance* effect);
void energy_in_out_update(EffectInstance* effect);
void energy_in_out_render(EffectInstance* effect);
void energy_in_out_appendGfx(void* effect);

EffectInstance* energy_in_out_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    EnergyInOutFXData* part;
    EnergyInOutFXData* firstPart;
    s32 numParts = D_E00D6E74[arg0];
    f32 randAngle;
    s32 i;

    bp.init = energy_in_out_init;
    bp.update = energy_in_out_update;
    bp.renderWorld = energy_in_out_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_ENERGY_IN_OUT;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    firstPart = part = effect->data.energyInOut = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.energyInOut != NULL);

    part->unk_00 = arg0;
    part->unk_14 = 0;
    if (arg5 <= 0) {
        part->unk_10 = 1000;
    } else {
        part->unk_10 = arg5;
    }
    part->unk_24 = 0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->scale = arg4;
    part->unk_18 = 255;
    part->unk_1C = 255;
    part->unk_20 = 255;
    part->unk_28 = 255;
    part->unk_2C = 245;
    part->unk_30 = 0;
    part->unk_44 = 1.0f;
    part->unk_38 = D_E00D6E84[arg0];

    randAngle = rand_int(360);

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_00 = arg0 % 3;

        switch (arg0) {
            case 0:
            case 1:
            case 2:
                part->unk_38 = -(rand_int(10) * 0.2 + 0.2);
                part->unk_10 = 20;
                part->unk_40 = 0;
                part->scale = 1.0 - (i % 3) * 0.1;
                break;
            case 3:
            case 5:
                part->unk_38 = rand_int(10) * 0.2 + 0.2;
                part->unk_10 = 20;
                part->unk_40 = 0;
                part->scale = 1.0 - (i % 3) * 0.1;
                break;
            case 6:
                part->unk_38 = -(rand_int(10) + 4);
                part->unk_10 = 10;
                part->unk_40 = 0;
                part->scale = 1.0 - (i % 3) * 0.3;
                break;
            case 7:
                part->unk_38 = -(rand_int(10) + 4);
                part->unk_10 = 10;
                part->unk_40 = 0;
                part->scale = 1.0 - (i % 3) * 0.3;
                break;
            case 8:
                part->unk_38 = rand_int(10) * 0.2 + 0.6;
                part->unk_10 = 20;
                part->unk_40 = -1.0f;
                part->scale = 1.0 - (i % 3) * 0.3;
                break;
            case 9:
                part->unk_38 = -(rand_int(10) * 0.2 + 0.6);
                part->unk_10 = 20;
                part->unk_40 = -2.0f;
                part->scale = 1.0 - (i % 3) * 0.3;
                firstPart->unk_18 = 255;
                firstPart->unk_1C = 245;
                firstPart->unk_20 = 215;
                firstPart->unk_28 = 220;
                firstPart->unk_2C = 60;
                firstPart->unk_30 = 10;
                break;
            case 10:
                part->unk_38 = rand_int(10) * 0.1 + 2.0;
                part->unk_10 = 10;
                part->unk_40 = 0;
                part->scale = (1.0 - (i % 3) * 0.3) * 0.5;
                break;
            case 11:
                part->unk_38 = rand_int(10) * 0.05 + 0.2;
                part->unk_40 = -1.0f;
                part->unk_10 = 30;
                part->scale = 1.0 - (i % 3) * 0.3;
                break;
            case 4:
            case 12:
                part->unk_38 = rand_int(10) * 0.2 + 0.6;
                part->unk_10 = 20;
                part->unk_40 = -2.0f;
                part->scale = 1.0 - (i % 3) * 0.3;
                break;
        }

        part->unk_14 = -rand_int(part->unk_10);

        if (part->unk_38 < 0.0f) {
            part->pos.x = (part->unk_10 - part->unk_14) * (-part->unk_38);
        } else {
            part->pos.x = (-part->unk_14) * part->unk_38;
        }
        part->pos.y = 0;
        part->pos.z = 0;

        part->unk_3C = (i - 1) * 360 / (numParts - 1) + randAngle;
    }

    return effect;
}

void energy_in_out_init(EffectInstance* effect) {
}

void energy_in_out_update(EffectInstance* effect) {
    EnergyInOutFXData* part = effect->data.energyInOut;
    s32 unk_10;
    s32 unk_14;
    f32 angle;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->unk_10 = 16;
    }

    if (part->unk_10 < 1000) {
        part->unk_10--;
    }

    part->unk_14++;
    if (part->unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_10 = part->unk_10;
    unk_14 = part->unk_14;

    if (unk_10 < 16) {
        part->unk_24 = unk_10 * 16;
    }

    if (unk_14 < 16) {
        part->unk_24 = unk_14 * 16 + 15;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_14++;
        if (part->unk_14 >= part->unk_10) {
            part->unk_14 = 0;
            if (part->unk_38 < 0.0f) {
                part->pos.x = -part->unk_10 * part->unk_38;
            } else {
                part->pos.x = 0.0f;
            }
            part->unk_3C = rand_int(359);
        }

        part->pos.x += part->unk_38;
        part->unk_3C += part->unk_40;

        angle = (part->unk_14 * 180) / part->unk_10;
        if (angle < 0.0f || angle > 180.0f) {
            part->unk_24 = 0;
        } else {
            part->unk_24 = sin_deg(angle) * 255.0f;
        }
    }
}

void energy_in_out_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = energy_in_out_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
}

void func_E00D6978(void) {
}

void energy_in_out_appendGfx(void* effect) {
    EnergyInOutFXData* part = ((EffectInstance*)effect)->data.energyInOut;
    s32 unk_24 = part->unk_24;
    s32 unk_00 = part->unk_00;
    f32 scale = part->scale * part->unk_44;
    s32 unk_18 = part->unk_18;
    s32 unk_1C = part->unk_1C;
    s32 unk_20 = part->unk_20;
    f32 unk_38 = part->unk_38;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, scale, part->pos.x, part->pos.y, part->pos.z);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, part->unk_18, part->unk_1C, part->unk_20, unk_24);
    gDPSetEnvColor(gMainGfxPos++, part->unk_28, part->unk_2C, part->unk_30, 0);
    gSPDisplayList(gMainGfxPos++, D_09000200_3D6130);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        f32 scale = part->scale;

        gDPSetPrimColor(gMainGfxPos++, 0, 0, unk_18, unk_1C, unk_20, (unk_24 * part->unk_24) / 255);

        guRotateF(sp20, part->unk_3C, 0.0f, 0.0f, 1.0f);
        guTranslateF(sp60, part->pos.x + unk_38, 0.0f, 0.0f);
        guMtxCatF(sp60, sp20, sp20);
        if (D_E00D6E40[unk_00] == D_09000688_3D65B8 || D_E00D6E40[unk_00] == D_09000808_3D6738) {
            guScaleF(sp60, scale, 1.0f, 1.0f);
        } else {
            guScaleF(sp60, scale, scale, 1.0f);
        }
        guMtxCatF(sp60, sp20, sp20);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_E00D6E40[unk_00]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
