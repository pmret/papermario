#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002170_336DE0[];
extern Gfx D_09002238_336EA8[];
extern Gfx D_090022E0_336F50[];
extern Gfx D_09002308_336F78[];
extern Gfx D_090023B0_337020[];
extern Gfx D_090023D8_337048[];
extern Gfx D_09002480_3370F0[];
extern Gfx D_090024A8_337118[];
extern Gfx D_09002550_3371C0[];
extern Gfx D_09002578_3371E8[];

Gfx* D_E0020C90[] = { D_090022E0_336F50, NULL, D_090023B0_337020, D_09002480_3370F0, D_09002550_3371C0 };

Gfx* D_E0020CA4[] = { D_09002238_336EA8, NULL, D_09002308_336F78, D_090023D8_337048, D_090024A8_337118 };

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

u8 D_E0020D94[] = {
    64,  0,  0,
    32,  0, 32,
     0,  0, 64,
     0, 32, 32,
     0, 64,  0,
    32, 32,  0,
     0,  0,  0
};

void emote_init(EffectInstance* effect);
void emote_update(EffectInstance* effect);
void emote_render(EffectInstance* effect);
void emote_appendGfx(void* effect);

void func_E0020000(EmoteFXData* part, s32 arg1) {
    f32 unk_1C = part->unk_1C;
    f32 unk_20 = part->unk_20;
    Npc* npc = part->unk_3C;
    Matrix4f sp18;
    f32 sin;
    f32 cos;

    sin = sin_deg(gCameras[gCurrentCameraID].curYaw);
    cos = cos_deg(gCameras[gCurrentCameraID].curYaw);
    guRotateF(sp18, -(unk_1C - 20.0f + arg1 * 20), sin, 0.0f, -cos);

    if (npc == PTR_LIST_END) {
        part->unk_04 = gPlayerStatus.pos.x + part->unk_10 + sp18[1][0] * (unk_20 + 16.0f);
        part->unk_08 = gPlayerStatus.pos.y + part->unk_14 + sp18[1][1] * (unk_20 + 16.0f);
        part->unk_0C = gPlayerStatus.pos.z + part->unk_18 + sp18[1][2] * (unk_20 + 16.0f);
    } else if (npc != NULL) {
        part->unk_04 = npc->pos.x + part->unk_10 + sp18[1][0] * (unk_20 + 16.0f);
        part->unk_08 = npc->pos.y + part->unk_14 + sp18[1][1] * (unk_20 + 16.0f);
        part->unk_0C = npc->pos.z + part->unk_18 + sp18[1][2] * (unk_20 + 16.0f);
    } else {
        part->unk_04 = part->unk_10 + sp18[1][0] * (unk_20 + 16.0f);
        part->unk_08 = part->unk_14 + sp18[1][1] * (unk_20 + 16.0f);
        part->unk_0C = part->unk_18 + sp18[1][2] * (unk_20 + 16.0f);
    }

    part->unk_24 = unk_1C - 20.0f + arg1 * 20;
    part->unk_28 = (unk_20 / 12.0f) * 0.5f + 0.5;
}

void emote_main(s32 arg0, Npc* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7, EffectInstance** arg8) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EmoteFXData* data;
    EffectInstance* effect;
    s32 numParts;

    if (arg0 == 1) {
        numParts = 3;
    } else {
        numParts = 1;
    }

    bp.unk_00 = 0;
    bp.init = emote_init;
    bp.update = emote_update;
    bp.renderWorld = emote_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_EMOTE;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    data = effect->data.emote = general_heap_malloc(numParts * sizeof(*data));

    ASSERT(effect->data.emote != NULL);
    data->unk_3C = arg1;
    data->unk_00 = arg0;
    data->unk_30 = arg0;

    if (arg7 <= 0) {
        arg7 = 10000;
    }
    data->unk_2C = arg7;
    data->unk_34 = 0;

    if (arg0 == 1) {
        s32 i;

        for (i = 0; i < numParts; i++, data++) {
            data->unk_10 = arg2;
            data->unk_14 = arg3;
            data->unk_18 = arg4;
            data->unk_1C = arg6;
            data->unk_20 = arg5;
            data->unk_3C = arg1;
            func_E0020000(data, i);
        }
    } else {
        data->unk_10 = arg2;
        data->unk_14 = arg3;
        data->unk_18 = arg4;
        data->unk_1C = arg6;
        data->unk_20 = arg5;
        data->unk_3C = arg1;
        func_E0020000(data, 1);
    }
    *arg8 = effect;
}

void emote_init(EffectInstance* effect) {
}

void emote_update(EffectInstance* effect) {
    EmoteFXData* part = effect->data.emote;
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
            remove_effect(effect);
            return;
        }
    }

    if (part->unk_2C < 10000) {
        part->unk_2C--;
    }

    if (part->unk_2C < 0) {
        remove_effect(effect);
        return;
    }

    if (part->unk_3C != NULL) {
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

void emote_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = emote_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void emote_appendGfx(void* effect) {
    EmoteFXData* part = ((EffectInstance*)effect)->data.emote;
    s32 type = part->unk_00;
    s32 unk_38;
    Gfx* dlist;
    Gfx* dlist2;
    Mtx* matrix;
    s32 w;
    s32 h;
    s32 uls;
    s32 ult;
    s32 idx;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    if (type != 1) {
        guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
        guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp58, sp18, sp18);

        matrix = &gDisplayContext->matrixStack[gMatrixListPos];

        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos++]);
        guScaleF(sp58, 1.0f, 0.8f, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guRotateF(sp58, part->unk_24, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_09002170_336DE0);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    } else {
        if (part->unk_38 == 0) {
            for (i = 0; i < 3; i++, part++) {
                guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
                guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
                guMtxCatF(sp58, sp18, sp18);
                guRotateF(sp58, part->unk_24, 0.0f, 0.0f, 1.0f);
                guMtxCatF(sp58, sp18, sp18);
                guScaleF(sp58, part->unk_28, part->unk_28, 1.0f);
                guMtxCatF(sp58, sp18, sp18);
                guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

                gDPSetPrimColor(gMainGfxPos++, 0, 0, 235, 28, 0, 255);
                gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(gMainGfxPos++, D_09002578_3371E8);
                gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            }
        }

        return;
    }

    gSPMatrix(gMainGfxPos++, matrix, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    unk_38 = part->unk_38;
    dlist = D_E0020CA4[type];
    dlist2 = D_E0020C90[type];

    switch (type) {
        case 0:
            w = 16;
            h = 16;
            uls = 128 - unk_38 * 16;
            ult = 0;
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 220, 0, 0, 255);
            break;
        case 2:
            w = 32;
            h = 48;
            uls = 128 - unk_38 * 32;
            ult = 0;
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 220, 0, 0, 255);
            break;
        case 3:
            w = 32;
            h = 32;
            uls = 128 - unk_38 * 32;
            ult = 0;
            idx = (part->unk_2C * 3) % (ARRAY_COUNT(D_E0020D94) / 3);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0020D94[idx], D_E0020D94[idx + 1], D_E0020D94[idx + 2], 255);
            break;
        case 4:
            w = 32;
            h = 8;
            uls = 128 - unk_38 * 32;
            ult = 0;
            break;
    }

    if (dlist != NULL) {
        gSPDisplayList(gMainGfxPos++, dlist);
    }

    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, uls * 4, ult * 4, (uls + w) * 4, (ult + h) * 4);

    if (dlist2 != NULL) {
        gSPDisplayList(gMainGfxPos++, dlist2);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
