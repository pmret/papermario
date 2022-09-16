#include "common.h"
#include "effects_internal.h"

extern Gfx D_090003A0[];
extern Gfx D_09000420[];

void fx_46_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_46", fx_46_main);

void fx_46_init(void) {
}

void fx_46_update(EffectInstance* effect) {
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
            part->unk_1C = unk_24 * 0x19;
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

    part->unk_08 = part->unk_04[10];
    part->unk_0C = part->unk_04[11];
    part->unk_10 = part->unk_04[12];

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

void fx_46_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_46_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void fx_46_appendGfx(void* effect) {
    Effect46FXData* part = ((EffectInstance*)effect)->data.unk_46;
    s32 unk_00;
    s32 unk_1C = part->unk_1C;
    f32 unk_14 = part->unk_14;
    f32 unk_18 = part->unk_18;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    unk_00 = part->unk_00;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, D_09000420);

    shim_guTranslateF(sp20, part->unk_08, part->unk_0C, part->unk_10);
    shim_guRotateF(sp60, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        f32 (*matrix)[4] = sp60; // required to match

        shim_guPositionF(sp20, part->unk_2C, 0.0f, part->unk_34, unk_14 * part->unk_14, part->unk_08, part->unk_0C, part->unk_10);
        shim_guRotateF(matrix, part->unk_30, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(matrix, sp20, sp20);
        if (unk_00 < 8) {
            shim_guTranslateF(matrix, 3.0f - (unk_14 - unk_18) * 3.0f / unk_18, 0.0f, 0.0f);
        } else {
            shim_guTranslateF(matrix, 2.0f, 0.0f, 0.0f);
        }
        shim_guMtxCatF(matrix, sp20, sp20);

        gDPSetPrimColor(gMasterGfxPos++, 0, 0, part->unk_44, part->unk_45, part->unk_46, unk_1C);

        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_090003A0);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
