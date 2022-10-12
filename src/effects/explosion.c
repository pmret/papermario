#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000840_3447B0[];
extern Gfx D_090008F0_344860[];
extern Gfx D_09000910_344880[];
extern Gfx D_09000978_3448E8[];
extern Gfx D_090009D8_344948[];
extern Gfx D_09000A38_3449A8[];

Gfx* D_E00328B0[] = { D_09000978_3448E8, D_090009D8_344948, D_09000A38_3449A8 };

void explosion_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/explosion", explosion_main);

void explosion_init(void) {
}

INCLUDE_ASM(s32, "effects/explosion", explosion_update);

void explosion_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = explosion_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void explosion_appendGfx(void* effect) {
    ExplosionFXData* part = ((EffectInstance*)effect)->data.explosion;
    s32 unk_34 = part->unk_34;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 primAlpha;
    s32 primB;
    s32 cond;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    part++;

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (part->unk_00 != -1) {
        gSPDisplayList(gMasterGfxPos++, D_09000840_3447B0);

        shim_guScaleF(sp18, part->unk_20, part->unk_20, 1.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 240, part->unk_38);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_090008F0_344860);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    part++;

    gSPDisplayList(gMasterGfxPos++, D_09000910_344880);

    shim_guScaleF(sp18, part->unk_20, part->unk_20, part->unk_20);
    shim_guRotateF(sp58, part->unk_28, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    switch (unk_34) {
        default:
            primAlpha = part->unk_38;
            break;
        case 2:
            primAlpha = 255;
            break;
        case 1:
            primAlpha = 192;
            break;
    }

    cond = (unk_34 < 3); // required to match
    if (!cond && unk_34 < 8) {
        primB = unk_34 * 16 + 128;
    } else {
        primB = 255;
    }

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, primB, primAlpha);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_E00328B0[unk_34 % 3]);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
