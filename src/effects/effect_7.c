#include "common.h"
#include "effects_internal.h"

typedef struct Effect7 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[0x44];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ s32 unk_74;
} Effect7; // size = 0x78

s8 D_E000E660[16] = { 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6, -1, 0 };

s8 D_E000E670[20] = { 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, -1, 0, 0, 0 };

s8* D_E000E684[2] = { D_E000E660, D_E000E670 };

extern Gfx D_09002780[];
extern Gfx D_09002868[];
extern Gfx D_09002950[];
extern Gfx D_09002B20[];
extern Gfx D_09002B40[];

void fx_7_init(EffectInstance* effect);
void fx_7_update(EffectInstance* effect);
void fx_7_render(EffectInstance* effect);
void fx_7_appendGfx(EffectInstance* effect);

void fx_7_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    Effect7* effectPart;
    s32 numParts = 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = fx_7_init;
    bp.update = fx_7_update;
    bp.renderWorld = fx_7_render;
    bp.unk_14 = NULL;
    bp.effectIndex = 7;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    effectPart = shim_general_heap_malloc(numParts * sizeof(*effectPart));
    effect->data = effectPart;
    ASSERT(effect->data != NULL);

    shim_mem_clear(effectPart, numParts * sizeof(*effectPart));
    effectPart->unk_6C = arg0 == 2;
    effectPart->unk_70 = 0;
    effectPart->unk_04 = arg0;

    for (i = 0; i < numParts; i++, effectPart++) {
        effectPart->unk_00 = 1;
        effectPart->unk_64 = arg4;
        effectPart->unk_68 = arg5;
        effectPart->unk_08 = arg1;
        effectPart->unk_0C = arg2;
        effectPart->unk_10 = arg3;
        effectPart->unk_58 = 0.33333334f;
        effectPart->unk_5C = 1.75f;
        effectPart->unk_60 = -0.16f;
    }
}

void fx_7_init(EffectInstance* effect) {
}

void fx_7_update(EffectInstance* effect) {
    Effect7* part = (Effect7*)effect->data;

    part->unk_74 = D_E000E684[part->unk_6C][part->unk_70++];

    if (part->unk_74 < 0) {
        shim_remove_effect(effect);
    } else {
        s32 i;

        for (i = 0; i < effect->numParts; i++, part++) {
            part->unk_08 += part->unk_58 * part->unk_64;
            part->unk_10 += part->unk_58 * part->unk_68;
            part->unk_5C = part->unk_5C + part->unk_60;
            part->unk_0C += part->unk_5C;
        }
    }
}

void fx_7_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_7_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void fx_7_appendGfx(EffectInstance* effect) {
    // effect temp needed to match - maybe EffectInstance is being cast to a a specific of EffectInstance for effect_7
    EffectInstance* effectTemp = effect;
    Effect7* part = (Effect7*)effect->data;
    s32 temp_t3 = part->unk_04;
    s32 temp_t4 = part->unk_74;
    s32 cond = FALSE;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 temp_a0;
    s32 temp_lo;
    s32 dlist;
    s32 dlist2;
    s32 phi_t1;
    s32 i;

    if (temp_t3 == 0) {
        dlist2 = D_09002B20;
    } else {
        dlist2 = D_09002B40;
    }

    switch (temp_t3) {
        case 1:
            dlist = D_09002868;
            break;
        default:
            dlist = D_09002950;
            break;
        case 0:
            dlist = D_09002780;
            break;
    }


    if ((part->unk_6C == 0 && temp_t4 == 6) || (part->unk_6C == 1 && temp_t4 == 7)) {
        cond = TRUE;
    }

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->effect->data));
    gSPDisplayList(gMasterGfxPos++, dlist);
    gDPSetEnvColor(gMasterGfxPos++, 0, 0, 0, 127);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 230, 222, 222, 110);

    if (temp_t3 == 0) {
        phi_t1 = 24;
    } else {
        phi_t1 = 32;
    }

    temp_lo = temp_t4 * phi_t1;
    temp_a0 = temp_lo + phi_t1;

    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, temp_lo * 4, 0, (temp_a0 - 1) * 4, ((phi_t1 - 1) * 4));

    if (cond) {
        gDPSetTileSize(gMasterGfxPos++, 1, temp_a0 * 4, 0, ((temp_lo + (phi_t1 * 2)) - 1) * 4, 0);
    } else {
        gDPSetTileSize(gMasterGfxPos++, 1, temp_a0 * 4, 0, ((temp_lo + (phi_t1 * 2)) - 1) * 4, (phi_t1 - 1) * 4);
    }

    for (i = 0; i < effectTemp->numParts; i++, part++) {
        shim_guTranslateF(sp18, part->unk_08, part->unk_0C, part->unk_10);
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, dlist2);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
    gDPPipeSync(gMasterGfxPos++);
}
