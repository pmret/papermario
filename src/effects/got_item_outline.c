#include "common.h"
#include "effects_internal.h"

extern IMG_BIN D_09000000_345B40[][0x1000];
extern IMG_BIN D_09004000_349B40[][0x1000];
extern Gfx D_09008100_34DC40[];
extern Gfx D_09008170_34DCB0[];
extern Gfx D_09008190_34DCD0[];
extern Gfx D_090081A8_34DCE8[];
extern Gfx D_090081C0_34DD00[];

Gfx* D_E0036630[] = {
    D_09008170_34DCB0, D_09008190_34DCD0, D_090081A8_34DCE8, D_090081C0_34DD00
};

u8 AnimScaleIn[]  = {  60, 120, 140, 147, 149, 150 };
u8 AnimScaleOut[] = { 150, 150, 150, 150, 150, 150 };

void got_item_outline_init(EffectInstance* effect);
void got_item_outline_update(EffectInstance* effect);
void got_item_outline_render(EffectInstance* effect);
void got_item_outline_appendGfx(void* effect);

void got_item_outline_main(
    s32 type,
    f32 posX,
    f32 posY,
    f32 posZ,
    f32 arg4,
    EffectInstance** outEffect
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    GotItemOutlineFXData* data;
    s32 numParts = 1;

    bp.init = got_item_outline_init;
    bp.update = got_item_outline_update;
    bp.renderScene = got_item_outline_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_GOT_ITEM_OUTLINE;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.gotItemOutline = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.gotItemOutline != nullptr);

    data->timeLeft = 100;
    data->type = type;
    data->lifetime = 0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->alpha = 255;

    *outEffect = effect;
}

void got_item_outline_init(EffectInstance* effect) {
}

void got_item_outline_update(EffectInstance* effect) {
    GotItemOutlineFXData* data = effect->data.gotItemOutline;
    s32 time;

    if (data->timeLeft < 100) {
        data->timeLeft--;
        if (data->timeLeft < 0) {
            remove_effect(effect);
            return;
        }
    }

    data->lifetime++;
    time = data->lifetime;

    if (data->timeLeft < 6) {
        data->scale = AnimScaleOut[5 - data->timeLeft] / 150.0f;
        data->alpha /= 2;
    } else {
        if (time < 7) {
            data->scale = AnimScaleIn[time - 1] / 150.0f;
        } else {
            data->scale = 1.0f;
        }

        if (time >= 7) {
            data->lifetime = 7;
        }
    }
}

void got_item_outline_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = got_item_outline_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E003621C(void) {
}

void got_item_outline_appendGfx(void* effect) {
    GotItemOutlineFXData* data = ((EffectInstance*)effect)->data.gotItemOutline;
    s32 type = data->type;
    f32 scale = data->scale;
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    s32 i;

    if (scale != 0.0f) {
        gDPPipeSync(gMainGfxPos++);
        gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
        gSPDisplayList(gMainGfxPos++, D_09008100_34DC40);

        if (type == 0) {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, data->alpha);
            gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, 255);
        } else {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, data->alpha);
            gDPSetEnvColor(gMainGfxPos++, 255, 255, 0, 255);
        }

        guTranslateF(mtxTransform, data->pos.x, data->pos.y, data->pos.z);
        guRotateF(mtxTemp, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        guTranslateF(mtxTemp, 0.0f, 0.0f, -2.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);

        scale *= 0.6;

        guScaleF(mtxTemp, scale, scale, 1.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        for (i = 0; i < 4; i++) {
            IMG_PTR img;

            if (type == 0) {
                img = D_09000000_345B40[i];
            } else {
                img = D_09004000_349B40[i];
            }

            gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_IA, G_IM_SIZ_8b, 128, img);
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
