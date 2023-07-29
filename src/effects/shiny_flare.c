#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000240_3D79B0[];
extern Gfx D_090002E0_3D7A50[];

u8 D_E00DA500[] = {
    255, 255,  82,
    255, 255,  82,
    181, 148,   0,
    181, 148,   0,
    255, 255, 214,
    255, 255, 214,
    181, 148,   0,
    181, 148,   0
};

void shiny_flare_init(EffectInstance* effect);
void shiny_flare_update(EffectInstance* effect);
void shiny_flare_render(EffectInstance* effect);
void shiny_flare_appendGfx(void* effect);

EffectInstance* shiny_flare_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    ShinyFlareFXData* data;
    s32 numParts = 1;

    effectBp.init = shiny_flare_init;
    effectBp.update = shiny_flare_update;
    effectBp.renderWorld = shiny_flare_render;
    effectBp.unk_00 = 0;
    effectBp.renderUI = NULL;
    effectBp.effectID = EFFECT_SHINY_FLARE;
    effect = create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.shinyFlare = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->lifeTime = 0;
    data->timeLeft = 10;
    data->unk_24 = 255;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->unk_28 = arg4;
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 120;
    data->unk_2C = 0;

    return effect;
}

void shiny_flare_init(EffectInstance* effect) {
}

void shiny_flare_update(EffectInstance *effect) {
    ShinyFlareFXData *data = effect->data.shinyFlare;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->timeLeft = 10;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifeTime++;
    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }
    if (data->timeLeft < 4) {
        data->unk_2C *= 0.5;
        return;
    }

    data->unk_2C = data->lifeTime * 0.2f + 0.3;
}

void shiny_flare_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shiny_flare_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00DA228(void) {
}

void shiny_flare_appendGfx(void* effect) {
    ShinyFlareFXData* data = ((EffectInstance*)effect)->data.shinyFlare;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_24 = data->unk_24;
    f32 scale = data->unk_28 * data->unk_2C;
    s32 idx;
    Matrix4f sp10;
    Matrix4f sp50;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp10, data->pos.x, data->pos.y, data->pos.z);
    guScaleF(sp50, scale, scale, scale);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_09000240_3D79B0);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, unk_24);

    idx = data->lifeTime * 3;

    gDPSetPrimColor(gMainGfxPos++, 0, 0,
        D_E00DA500[idx % ARRAY_COUNT(D_E00DA500)    ],
        D_E00DA500[idx % ARRAY_COUNT(D_E00DA500) + 1],
        D_E00DA500[idx % ARRAY_COUNT(D_E00DA500) + 2],
        unk_24);
    gSPDisplayList(gMainGfxPos++, D_090002E0_3D7A50);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
