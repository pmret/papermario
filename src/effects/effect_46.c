#include "common.h"
#include "effects_internal.h"

extern Gfx D_090003A0_38ED30[];
extern Gfx D_09000420_38EDB0[];

s32 D_E008CAF0[] = {
    0xFEACACFE, 0xACD5FEB4, 0x9AD5B4FE, 0xB4B4FEB4, 0xDDFEB4FE,
    0xFEB4FED5, 0xB4FEB4D5, 0xFEB4FEFE, 0xB4FED5AC
};

u8 D_E008CB14[] = { 255, 255,  64 };
u8 D_E008CB18[] = { 255,  64,  64 };
u8 D_E008CB1C[] = { 255,  64, 255 };

void effect_46_init(EffectInstance* effect);
void effect_46_update(EffectInstance* effect);
void effect_46_render(EffectInstance* effect);
void effect_46_appendGfx(void* effect);

EffectInstance* effect_46_main(s32 arg0, PlayerStatus* arg1, f32 arg2, s32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect46FXData* part;
    s32 numParts = 5;
    s32 index;
    s32 i;

    bp.init = effect_46_init;
    bp.update = effect_46_update;
    bp.renderWorld = effect_46_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_46;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.unk_46 = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.unk_46 != NULL);

    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_14 = arg2 * 1.2;
    part->unk_18 = arg2 * 1.2;
    part->unk_20 = arg3;
    part->unk_24 = arg3;
    part->unk_1C = 0;
    part->unk_28 = 0;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        switch (arg0) {
            case 0:
            case 2:
            case 4:
            case 6:
                part->unk_08 = 0.0f;
                part->unk_0C = i * 7 + 4;
                part->unk_10 = 0.0f;
                part->unk_38 = 0.0f;
                part->unk_3C = 60.0f;
                part->unk_40 = 0.0f;
                part->unk_2C = 0.0f;
                part->unk_30 = i * 120;
                part->unk_34 = 0.0f;
                part->unk_14 = 1.0f;
                break;
            case 1:
            case 3:
            case 5:
            case 7:
                part->unk_08 = 0.0f;
                part->unk_0C = i * 7 + 4;
                part->unk_10 = 0.0f;
                part->unk_38 = 0.0f;
                part->unk_3C = -60.0f;
                part->unk_40 = 0.0f;
                part->unk_2C = 0.0f;
                part->unk_30 = i * 120;
                part->unk_34 = 0.0f;
                part->unk_14 = 1.0f;
                part->unk_46 = 255;
                part->unk_45 = 255;
                part->unk_44 = 255;
                break;
            default:
                part->unk_08 = 0;
                part->unk_0C = arg1->colliderHeight * 0.5;
                part->unk_10 = 0;
                part->unk_38 = func_E0200000(1) * 8 - 4;
                part->unk_3C = 0;
                part->unk_40 = func_E0200000(1) * 8 - 4;
                part->unk_2C = i * 25;
                part->unk_30 = (i - 1) * 360 / (numParts - 1);
                part->unk_34 = 360 - i * 38;
                part->unk_14 = (f32) (i - 1) / (numParts - 1) * 0.5 + 0.5;
                break;
        }

        switch (arg0) {
            case 2:
            case 3:
                index = 1;
                break;
            case 4:
            case 5:
                index = 2;
                break;
            case 6:
            case 7:
                index = (i & 1) + 1;
                break;
            default:
                index = 0;
                break;
        }

        part->unk_44 = D_E008CB14[index];
        part->unk_45 = D_E008CB18[index];
        part->unk_46 = D_E008CB1C[index];
    }

    return effect;
}

void effect_46_init(EffectInstance* effect) {
}

void effect_46_update(EffectInstance* effect) {
    Effect46FXData* part = effect->data.unk_46;
    s32 unk_00;
    s32 unk_24;
    s32 i;

    part->unk_24--;
    part->unk_28++;

    if (part->unk_24 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_00 = part->unk_00;
    unk_24 = part->unk_24;

    if (unk_00 == 8) {
        if (unk_24 >= 6) {
            part->unk_1C += (255 - part->unk_1C) * 0.05;
        }
        part->unk_14 = (part->unk_18 * unk_24) / part->unk_20;
        if (unk_24 < 10) {
            part->unk_1C = unk_24 * 25;
        }
    } else {
        if (unk_24 >= 6) {
            part->unk_1C += (100 - part->unk_1C) * 0.3;
        }
        if (unk_24 < 10) {
            part->unk_1C *= 0.8;
            part->unk_14 += (2.0f * part->unk_18 - part->unk_14) * 0.1;
        }
    }

    part->unk_08 = part->unk_04->position.x;
    part->unk_0C = part->unk_04->position.y;
    part->unk_10 = part->unk_04->position.z;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        if (unk_00 == 8) {
            if (i % 2) {
                part->unk_3C += (40.0f - part->unk_3C) * 0.2;
            } else {
                part->unk_3C += (-40.0f - part->unk_3C) * 0.2;
            }
            part->unk_2C += part->unk_38;
            part->unk_30 += part->unk_3C;
            part->unk_34 += part->unk_40;
        } else if (unk_24 < 10) {
            part->unk_30 += (part->unk_3C * unk_24) / 10.0f;
        } else {
            part->unk_30 += part->unk_3C;
        }
    }
}

void effect_46_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = effect_46_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void effect_46_appendGfx(void* effect) {
    Effect46FXData* part = ((EffectInstance*)effect)->data.unk_46;
    s32 unk_00;
    s32 unk_1C = part->unk_1C;
    f32 unk_14 = part->unk_14;
    f32 unk_18 = part->unk_18;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    unk_00 = part->unk_00;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000420_38EDB0);

    shim_guTranslateF(sp20, part->unk_08, part->unk_0C, part->unk_10);
    shim_guRotateF(sp60, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        shim_guPositionF(sp20, part->unk_2C, 0.0f, part->unk_34, unk_14 * part->unk_14, part->unk_08, part->unk_0C, part->unk_10);
        shim_guRotateF(sp60, part->unk_30, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp60, sp20, sp20);

        if (unk_00 < 8) {
            shim_guTranslateF(sp60, 3.0f - (unk_14 - unk_18) * 3.0f / unk_18, 0.0f, 0.0f);
            shim_guMtxCatF(sp60, sp20, sp20);
        } else {
            shim_guTranslateF(sp60, 2.0f, 0.0f, 0.0f);
            shim_guMtxCatF(sp60, sp20, sp20);
        }

        gDPSetPrimColor(gMainGfxPos++, 0, 0, part->unk_44, part->unk_45, part->unk_46, unk_1C);

        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_090003A0_38ED30);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
