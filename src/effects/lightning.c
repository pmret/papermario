#include "common.h"
#include "effects_internal.h"

extern Gfx D_09003280_371FE0[];
extern Gfx D_090032F8_372058[];
extern Gfx D_09003378_3720D8[];
extern Gfx D_090033E0_372140[];
extern Gfx D_09003580_3722E0[];
extern Gfx D_09003778_3724D8[];
extern Gfx D_09003888_3725E8[];
extern Gfx D_09003948_3726A8[];

Gfx* D_E006CB60[] = {
    D_09003778_3724D8, D_09003580_3722E0, D_090033E0_372140,
    D_09003378_3720D8, D_090032F8_372058, D_09003280_371FE0
};

Gfx* D_E006CB78[] = {
    D_09003888_3725E8, D_09003888_3725E8, D_09003888_3725E8,
    D_09003948_3726A8, D_09003948_3726A8, D_09003948_3726A8
};

void lightning_init(EffectInstance* effect);
void lightning_update(EffectInstance* effect);
void lightning_render(EffectInstance* effect);
void lightning_appendGfx(void* effect);

EFFECT_DEF_GATHER_MAGIC(gather_magic_main);
EFFECT_DEF_BULB_GLOW(bulb_glow_main);
EFFECT_DEF_SNAKING_STATIC(snaking_static_main);
EFFECT_DEF_FLASHING_BOX_SHOCKWAVE(flashing_box_shockwave_main);

EffectInstance* lightning_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    LightningFXData* data;
    s32 numParts = 1;

    bp.init = lightning_init;
    bp.update = lightning_update;
    bp.renderWorld = lightning_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_LIGHTNING;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.lightning = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.lightning != NULL);

    data->unk_00 = arg0;
    data->unk_18 = 0;
    if (arg0 >= 3) {
        data->unk_14 = 30;
    } else {
        data->unk_14 = 100;
    }
    data->unk_10 = 255;
    data->unk_3C = 4;
    data->unk_40 = 2;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_48 = NULL;
    data->unk_44 = NULL;
    data->unk_1C = data->unk_20 = 0.0f;
    data->unk_2C = 48.0f;
    data->unk_30 = 32.0f;
    data->unk_24 = data->unk_28 = 0.0f;
    data->unk_34 = 8.0f;
    data->unk_38 = 32.0f;

    if (arg0 == 1 || arg0 == 2) {
        if (arg0 == 1) {
            load_effect(EFFECT_GATHER_MAGIC);
            data->unk_44 = gather_magic_main(0, -118.0f, 184.0f, 79.0f, 1.0f, -1);

            load_effect(EFFECT_BULB_GLOW);
            bulb_glow_main(0, -120.0f, 189.0f, 77.0f, 1.0f, &data->unk_48);
        } else {
            load_effect(EFFECT_SNAKING_STATIC);
            data->unk_48 = snaking_static_main(0, -120.0f, 189.0f, 72.0f, 1.0f, 0);

            data->unk_48->data.snakingStatic->envCol.r = 255;
            data->unk_48->data.snakingStatic->envCol.g = 255;
            data->unk_48->data.snakingStatic->envCol.b = 255;
            data->unk_48->data.snakingStatic->unk_18 = 255;
            data->unk_48->data.snakingStatic->unk_1C = 0;
            data->unk_48->data.snakingStatic->unk_20 = 255;
        }
    }

    if (arg0 >= 3) {
        s32 effectArg0;

        load_effect(EFFECT_FLASHING_BOX_SHOCKWAVE);
        if (gGameStatusPtr->isBattle == TRUE) {
            effectArg0 = 3;
        } else {
            effectArg0 = 1;
        }
        flashing_box_shockwave_main(effectArg0, arg1, arg2, arg3, arg4, arg5);
    }

    return effect;
}

void lightning_init(EffectInstance* effect) {
}

void lightning_update(EffectInstance* effect) {
    LightningFXData* data = effect->data.lightning;
    s32 unk_00;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_14 = 0;
    }

    unk_00 = data->unk_00;

    if (data->unk_14 < 100) {
        data->unk_14--;
    }

    data->unk_18++;

    if (data->unk_14 < 0) {
        remove_effect(effect);

        if (data->unk_48 != NULL) {
            remove_effect(data->unk_48);
            data->unk_48 = NULL;
        }

        if (data->unk_44 != NULL) {
            remove_effect(data->unk_44);
            data->unk_44 = NULL;
        }
    } else {
        s32 unk_14 = data->unk_14;
        s32 unk_18 = data->unk_18;

        if (data->unk_44 != NULL && unk_18 >= 18) {
            remove_effect(data->unk_44);
            data->unk_44 = NULL;
        }

        if (unk_00 < 3 || unk_18 < 7) {
            data->unk_1C += data->unk_2C;
            if (data->unk_1C < 0.0f) {
                data->unk_1C += 256.0f;
            } else if (data->unk_1C > 256.0f) {
                data->unk_1C -= 256.0f;
            }

            if (unk_18 % data->unk_3C == 0) {
                data->unk_20 += data->unk_30;
                if (data->unk_20 < 0.0f) {
                    data->unk_20 += 64.0f;
                } else if (data->unk_20 > 64.0f) {
                    data->unk_20 -= 64.0f;
                }
            }

            if (unk_18 % data->unk_40 == 0) {
                data->unk_24 += data->unk_34;
                if (data->unk_24 < 0.0f) {
                    data->unk_24 += 256.0f;
                } else if (data->unk_24 > 256.0f) {
                    data->unk_24 -= 256.0f;
                }
            }

            data->unk_28 += data->unk_38;
            if (data->unk_28 < 0.0f) {
                data->unk_28 += 64.0f;
            }
            else if (data->unk_28 > 64.0f) {
                data->unk_28 -= 64.0f;
            }
        }

        if (unk_00 >= 3) {
            if (unk_18 >= 7) {
                data->unk_10 -= 13;
                if (data->unk_10 < 0) {
                    data->unk_10 = 0;
                }
            }
        } else if (unk_14 < 10) {
            data->unk_10 -= 25;
            if (data->unk_10 < 0) {
                data->unk_10 = 0;
            }
        }
    }
}

void lightning_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = lightning_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void lightning_appendGfx(void* effect) {
    LightningFXData* data = ((EffectInstance*)effect)->data.lightning;
    s32 unk_00 = data->unk_00;
    s32 unk_18 = data->unk_18;
    Gfx* dlist = D_E006CB60[unk_00];
    Gfx* dlist2 = D_E006CB78[unk_00];
    Camera* camera = &gCameras[gCurrentCameraID];
    Matrix4f sp20;
    Matrix4f sp60;
    u16 perspNorm;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    if (unk_00 != 1 || unk_18 >= 18) {
        s32 ult2;
        s32 uls2;
        s32 uls;
        s32 ult;
        f32* unk_28; // TODO required to match

        gSPDisplayList(gMainGfxPos++, dlist2);

        uls = data->unk_1C * 4.0f;
        ult = data->unk_20 * 4.0f;
        uls2 = data->unk_24 * 4.0f;
        unk_28 = &data->unk_28; // TODO dumb pointer temp required to match
        ult2 = *(unk_28) * 4.0f;

        switch (unk_00) {
            case 0:
            case 1:
            case 2:
                guPerspectiveF(sp20, &perspNorm, 30.0f, (f32) camera->viewportW / (f32) camera->viewportH, 4.0f, 16384.0f, 1.0f);
                guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

                gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

                guTranslateF(sp20, data->unk_04, data->unk_08, -500.0f);
                guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

                gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 47, 198, 255);
                break;
            default:
                guTranslateF(sp20, data->unk_04, data->unk_08, data->unk_0C);
                guRotateF(sp60, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
                guMtxCatF(sp60, sp20, sp20);
                guTranslateF(sp60, 0.0f, 0.0f, 1.0f);
                guMtxCatF(sp60, sp20, sp20);
                guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

                gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 0, data->unk_10);
                break;
        }

        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, uls, ult, uls + 1020, ult + 124);
        gDPSetTileSize(gMainGfxPos++, 1, uls2, ult2, uls2 + 1020, ult2 + 124);
        gSPDisplayList(gMainGfxPos++, dlist);
        gDPPipeSync(gMainGfxPos++);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

        if (unk_00 < 3) {
            gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        }

        gDPPipeSync(gMainGfxPos++);
    }
}
