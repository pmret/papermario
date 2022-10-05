#include "common.h"
#include "effects_internal.h"

extern Gfx D_090004C0_343500[];
extern Gfx D_090005E0_343620[];
extern u8 D_E0030E90[];

void damage_stars_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/damage_stars", damage_stars_main);

void damage_stars_init(void) {
}

void damage_stars_update(EffectInstance* effect) {
    DamageStarsFXData* part = effect->data.damageStars;
    s32 unk_28;
    s32 unk_2C;
    s32 i;

    part->unk_28--;
    part->unk_2C++;

    if (part->unk_28 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_28 = part->unk_28;
    unk_2C = part->unk_2C;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->unk_00 == 2) {
            part->unk_14 = shim_cos_deg(unk_2C * 6) * 4.0f;
            part->unk_10 *= 0.94;
            part->unk_18 *= 0.94;
            if (part->unk_14 < 0.0f) {
                part->unk_20 *= 0.8;
                part->unk_24 *= 0.6;
            }
        } else {
            if (unk_28 >= 6) {
                part->unk_10 *= 0.8;
                part->unk_14 *= 0.8;
                part->unk_18 *= 0.8;
            }
            if (unk_28 - 6 < 0xEU) {
                if (part->unk_00 == 0) {
                    part->unk_20 += 1.0f;
                }
            } else if (unk_28 < 5) {
                part->unk_20 *= 0.8;
                part->unk_24 *= 0.6;
                part->unk_10 *= 0.7;
                part->unk_14 *= 0.7;
                part->unk_18 *= 0.7;
            }
        }

        part->unk_04 += part->unk_10;
        part->unk_08 += part->unk_14;
        part->unk_0C += part->unk_18;
        part->unk_1C += part->unk_20;
    }
}

void damage_stars_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = damage_stars_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void damage_stars_appendGfx(void* effect) {
    DamageStarsFXData* part = ((EffectInstance*)effect)->data.damageStars;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 baseIdx;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, D_090004C0_343500);

    baseIdx = (part->unk_2C - 1) * 3;
    baseIdx %= 36;

    for (i = 0; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        s32 rIdx = baseIdx + i * 3;
        s32 gIdx = baseIdx + 1 + i * 3;
        s32 bIdx = baseIdx + 2 + i * 3;

        gDPSetPrimColor(gMasterGfxPos++, 0, 0, D_E0030E90[rIdx % 36], D_E0030E90[gIdx % 36], D_E0030E90[bIdx % 36], part->unk_24);
        shim_guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        shim_guRotateF(sp18, part->unk_1C, 0.0f, 0.0f, 1.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_090005E0_343620);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
}
