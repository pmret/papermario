#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000200[];
extern Gfx D_09000688[];
extern Gfx D_09000808[];
extern Gfx* D_E00D6E40[];

void energy_in_out_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/energy_in_out", energy_in_out_main);

void energy_in_out_init(void) {
}

void energy_in_out_update(EffectInstance* effect) {
    EnergyInOutFXData* part = effect->data.energyInOut;
    s32 unk_10;
    s32 unk_14;
    f32 angle;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        part->unk_10 = 16;
    }

    if (part->unk_10 < 1000) {
        part->unk_10--;
    }

    part->unk_14++;
    if (part->unk_10 < 0) {
        shim_remove_effect(effect);
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
            part->unk_3C = shim_rand_int(359);
        }

        part->pos.x += part->unk_38;
        part->unk_3C += part->unk_40;

        angle = (part->unk_14 * 180) / part->unk_10;
        if ((angle < 0.0f) || (angle > 180.0f)) {
            part->unk_24 = 0;
        } else {
            part->unk_24 = shim_sin_deg(angle) * 255.0f;
        }
    }
}

void energy_in_out_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = energy_in_out_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
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

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, scale, part->pos.x, part->pos.y, part->pos.z);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, part->unk_18, part->unk_1C, part->unk_20, unk_24);
    gDPSetEnvColor(gMasterGfxPos++, part->unk_28, part->unk_2C, part->unk_30, 0);
    gSPDisplayList(gMasterGfxPos++, D_09000200);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        f32 scale = part->scale;

        gDPSetPrimColor(gMasterGfxPos++, 0, 0, unk_18, unk_1C, unk_20, (unk_24 * part->unk_24) / 255);

        shim_guRotateF(sp20, part->unk_3C, 0.0f, 0.0f, 1.0f);
        shim_guTranslateF(sp60, part->pos.x + unk_38, 0.0f, 0.0f);
        shim_guMtxCatF(sp60, sp20, sp20);
        if (D_E00D6E40[unk_00] == D_09000688 || D_E00D6E40[unk_00] == D_09000808) {
            shim_guScaleF(sp60, scale, 1.0f, 1.0f);
        } else {
            shim_guScaleF(sp60, scale, scale, 1.0f);
        }
        shim_guMtxCatF(sp60, sp20, sp20);
        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_E00D6E40[unk_00]);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
