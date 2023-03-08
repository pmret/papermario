#include "common.h"
#include "effects_internal.h"

extern char D_09000000_345B40[][0x1000];
extern char D_09004000_349B40[][0x1000];
extern Gfx D_09008100_34DC40[];
extern Gfx D_09008170_34DCB0[];
extern Gfx D_09008190_34DCD0[];
extern Gfx D_090081A8_34DCE8[];
extern Gfx D_090081C0_34DD00[];

Gfx* D_E0036630[] = {
    D_09008170_34DCB0, D_09008190_34DCD0, D_090081A8_34DCE8, D_090081C0_34DD00
};

u8 D_E0036640[] = { 0x3C, 0x78, 0x8C, 0x93, 0x95, 0x96, 0x00, 0x00 };
u8 D_E0036648[] = { 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x00, 0x00 };

void got_item_outline_init(EffectInstance* effect);
void got_item_outline_update(EffectInstance* effect);
void got_item_outline_render(EffectInstance* effect);
void got_item_outline_appendGfx(void* effect);

void got_item_outline_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    EffectInstance** outEffect
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    GotItemOutlineFXData* data;
    s32 numParts = 1;

    bp.init = got_item_outline_init;
    bp.update = got_item_outline_update;
    bp.renderWorld = got_item_outline_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_GOT_ITEM_OUTLINE;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.gotItemOutline = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.gotItemOutline != NULL);

    data->unk_14 = 100;
    data->unk_00 = arg0;
    data->unk_10 = 0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_1C = 255;

    *outEffect = effect;
}

void got_item_outline_init(EffectInstance* effect) {
}

void got_item_outline_update(EffectInstance* effect) {
    GotItemOutlineFXData* data = effect->data.gotItemOutline;
    s32 unk_10;

    if (data->unk_14 < 100) {
        data->unk_14--;
        if (data->unk_14 < 0) {
            shim_remove_effect(effect);
            return;
        }
    }

    data->unk_10++;
    unk_10 = data->unk_10;

    if (data->unk_14 < 6) {
        data->unk_18 = D_E0036648[5 - data->unk_14] / 150.0f;
        data->unk_1C /= 2;
    } else {
        if (unk_10 < 7) {
            data->unk_18 = D_E0036640[unk_10 - 1] / 150.0f;
        } else {
            data->unk_18 = 1.0f;
        }

        if (unk_10 >= 7) {
            data->unk_10 = 7;
        }
    }
}

void got_item_outline_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = got_item_outline_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E003621C(void) {
}

void got_item_outline_appendGfx(void* effect) {
    GotItemOutlineFXData* data = ((EffectInstance*)effect)->data.gotItemOutline;
    s32 unk_00 = data->unk_00;
    f32 unk_18 = data->unk_18;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;

    if (unk_18 != 0.0f) {
        gDPPipeSync(gMainGfxPos++);
        gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
        gSPDisplayList(gMainGfxPos++, D_09008100_34DC40);

        if (unk_00 == 0) {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, data->unk_1C);
            gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, 255);
        } else {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, data->unk_1C);
            gDPSetEnvColor(gMainGfxPos++, 255, 255, 0, 255);
        }

        shim_guTranslateF(sp18, data->unk_04, data->unk_08, data->unk_0C);
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guTranslateF(sp58, 0.0f, 0.0f, -2.0f);
        shim_guMtxCatF(sp58, sp18, sp18);

        unk_18 *= 0.6;

        shim_guScaleF(sp58, unk_18, unk_18, 1.0f);
        shim_guMtxCatF(sp58, sp18, sp18);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        for (i = 0; i < 4; i++) {
            char* temp;

            if (unk_00 == 0) {
                temp = D_09000000_345B40[i];
            } else {
                temp = D_09004000_349B40[i];
            }

            gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_IA, G_IM_SIZ_8b, 128, temp);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 0, G_TX_LOADTILE, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPLoadSync(gMainGfxPos++);
            gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 508, 124);
            gDPPipeSync(gMainGfxPos++);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 0, G_TX_RENDERTILE, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, 0, 508, 124);
            gSPDisplayList(gMainGfxPos++, D_E0036630[i]);
        }

        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        gDPPipeSync(gMainGfxPos++);
    }
}
