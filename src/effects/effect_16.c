#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002170[];
extern Gfx D_09002238[];
extern Gfx D_090022E0[];
extern Gfx D_09002308[];
extern Gfx D_090023B0[];
extern Gfx D_090023D8[];
extern Gfx D_09002480[];
extern Gfx D_090024A8[];
extern Gfx D_09002550[];
extern Gfx D_09002578[];

Gfx* D_E0020C90[] = { D_090022E0, NULL, D_090023B0, D_09002480, D_09002550 };

Gfx* D_E0020CA4[] = { D_09002238, NULL, D_09002308, D_090023D8, D_090024A8 };

s8 D_E0020CB8[40] = {
    0, 0, 1, 2, 3, 5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    -1, 0
};

s8 D_E0020CE0[28] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, -1, 0, 0, 0
};

s8 D_E0020CFC[40] = {
    0, 0, 2, 1, 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, -1,
    0, 0
};

s8 D_E0020D24[12] = { 0, 0, 1, 1, 2, 2, 3, 3, -13, 0, 0, 0 };

s8 D_E0020D30[80] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, -1, 0
};

s8* D_E0020D80[5] = { D_E0020CB8, D_E0020CE0, D_E0020CFC, D_E0020D24, D_E0020D30 };

s8 D_E0020D94[] = {
    64, 0, 0, 32, 0, 32, 0, 0, 64, 0, 32, 32, 0, 64, 0, 32, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void func_E0020000(Effect16* part, s32 arg1);
void fx_16_init(EffectInstance* effect);
void fx_16_update(EffectInstance* effect);
void fx_16_render(EffectInstance* effect);
void fx_16_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_16", func_E0020000);

void fx_16_main(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7, EffectInstance** arg8) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    Effect16* part;
    EffectInstance* effect;
    s32 numParts;

    if (arg0 == 1) {
        numParts = 3;
    } else {
        numParts = 1;
    }

    bp.unk_00 = 0;
    bp.init = fx_16_init;
    bp.update = fx_16_update;
    bp.renderWorld = fx_16_render;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_ID_10;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data != NULL);
    part->unk_3C = arg1;
    part->unk_00 = arg0;
    part->unk_30 = arg0;

    if (arg7 <= 0) {
        arg7 = 10000;
    }
    part->unk_2C = arg7;
    part->unk_34 = 0;

    if (arg0 == 1) {
        s32 i;

        for (i = 0; i < numParts; i++, part++) {
            part->unk_10 = arg2;
            part->unk_14 = arg3;
            part->unk_18 = arg4;
            part->unk_1C = arg6;
            part->unk_20 = arg5;
            part->unk_3C = arg1;
            func_E0020000(part, i);
        }
    } else {
        part->unk_10 = arg2;
        part->unk_14 = arg3;
        part->unk_18 = arg4;
        part->unk_1C = arg6;
        part->unk_20 = arg5;
        part->unk_3C = arg1;
        func_E0020000(part, 1);
    }
    *arg8 = effect;
}

void fx_16_init(EffectInstance* effect) {
}

void fx_16_update(EffectInstance* effect) {
    Effect16* part = effect->data;
    s32 temp_a0 = D_E0020D80[part->unk_30][part->unk_34];
    s32 type = part->unk_00;

    part->unk_34++;
    part->unk_38 = temp_a0;
    if (part->unk_38 < 0) {
        if (part->unk_38 != -1) {
            part->unk_30 = -part->unk_38 - 10;
            part->unk_34 = 0;
            part->unk_38 = D_E0020D80[part->unk_30][0];
            part->unk_34 = 1;
        } else {
            shim_remove_effect(effect);
            return;
        }
    }

    if (part->unk_2C < 10000) {
        part->unk_2C--;
    }

    if (part->unk_2C < 0) {
        shim_remove_effect(effect);
        return;
    }

    if (part->unk_3C != 0) {
        if (type == 1) {
            s32 i;

            for (i = 0; i < effect->numParts; i++, part++) {
                func_E0020000(part, i);
            }
        } else {
            func_E0020000(part, 1);
        }
    }
}

void fx_16_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_16_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

// lots of issues
#ifdef NON_EQUIVALENT
void fx_16_appendGfx(void* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    EffectInstance* effectTemp = effect;
    Effect16* part = effectTemp->data;
    s32 idx;
    s32 type;
    Gfx* temp_a3;
    Gfx* temp_t0;
    Mtx* blah;

    s32 sp9C;
    s32 spA0;
    s32 temp_a0_3;
    s32 phi_t1;
    s32 phi_s7;
    s32 phi_fp;

    type = part->unk_00;
    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));
    //phi_s7 = saved_reg_s7;
    //phi_fp = saved_reg_fp;

    if (type != 1) {
        shim_guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos++]);
        shim_guScaleF(sp58, 1.0f, 0.8f, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guRotateF(sp58, part->unk_24, 0.0f, 0.0f, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_09002170)
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    } else {
        if (part->unk_38 == 0) {
            s32 i;

            for (i = 0; i < 3; i++, part++) {
                shim_guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
                shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
                shim_guMtxCatF(sp58, sp18, sp18);
                shim_guRotateF(sp58, part->unk_24, 0.0f, 0.0f, 1.0f);
                shim_guMtxCatF(sp58, sp18, sp18);
                shim_guScaleF(sp58, part->unk_28, part->unk_28, 1.0f);
                shim_guMtxCatF(sp58, sp18, sp18);
                shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
                gDPSetPrimColor(gMasterGfxPos++, 0, 0, 235, 28, 0, 255);
                gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(gMasterGfxPos++, D_09002578);
                gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            }
        }
    }

    temp_a0_3 = part->unk_38;
    temp_a3 = D_E0020CA4[type];
    temp_t0 = D_E0020C90[type];

    switch (type) {
        case 2:
            sp9C = 0x20;
            phi_t1 = 0x30;
            phi_s7 = 0x80 - (temp_a0_3 << 5);
            spA0 = phi_t1;
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 220, 0, 0, 255);
            phi_fp = 0;
            break;
        case 3:
            sp9C = 0x20;
            spA0 = 0x20;
            idx = (part->unk_2C * 3) % 7;
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, D_E0020D94[idx], D_E0020D94[idx + 1], D_E0020D94[idx + 2], 255);
            phi_s7 = 0x80 - (temp_a0_3 << 5);
            phi_fp = 0;
            break;
        case 4:
            sp9C = 0x20;
            spA0 = 8;
            phi_s7 = 0x80 - (temp_a0_3 << 5);
            phi_fp = 0;
            break;
        default:
            phi_t1 = 0x10;
            if (type == 0) {
                sp9C = 0x10;
                phi_s7 = 0x80 - (temp_a0_3 * 0x10);
                spA0 = phi_t1;
                gDPSetPrimColor(gMasterGfxPos++, 0, 0, 220, 0, 0, 255);
                phi_fp = 0;
            }
            break;
    }

    if (temp_a3 != NULL) {
        gSPDisplayList(gMasterGfxPos++, temp_a3);
    }

    gDPSetTileSize(gMasterGfxPos++, 2, phi_s7, 0, phi_s7 + sp9C, spA0);

    if (temp_t0 != NULL) {
        gSPDisplayList(gMasterGfxPos++, temp_t0);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
#else
INCLUDE_ASM(s32, "effects/effect_16", fx_16_appendGfx);
#endif
