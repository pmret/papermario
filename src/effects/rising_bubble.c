#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000200_356730[];
extern Gfx D_090002E8_356818[];
extern Gfx D_09000308_356838[];
extern Gfx D_090003F0_356920[];
extern Gfx D_09000410_356940[];
extern Gfx D_09000430_356960[];

Gfx* D_E0046600[] = { D_090002E8_356818 };

Gfx* D_E0046604[] = {
    D_090003F0_356920, D_09000410_356940, D_090003F0_356920, D_09000430_356960
};

Gfx* D_E0046614[] = { D_09000200_356730 };
Gfx* D_E0046618[] = { D_09000308_356838 };

void rising_bubble_init(EffectInstance* effect);
void rising_bubble_update(EffectInstance* effect);
void rising_bubble_render(EffectInstance* effect);
void rising_bubble_appendGfx(void* effect);

void rising_bubble_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    RisingBubbleFXData* data;
    s32 numParts = 1;

    effectBp.unk_00 = 0;
    effectBp.init = rising_bubble_init;
    effectBp.update = rising_bubble_update;
    effectBp.renderWorld = rising_bubble_render;
    effectBp.renderUI = NULL;
    effectBp.effectID = EFFECT_RISING_BUBBLE;

    effect = create_effect_instance(&effectBp);
    effect->numParts = numParts;
    data = effect->data.risingBubble = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_14 = 0;
    data->lifeTime = 0;
    if (arg4 != 0.0f) {
        data->unk_10 = ((rand_int(3) * 0.1) + 0.7) * 0.4;
    } else {
        data->unk_10 = 1.0f;
    }
    data->timeLeft = 32;
    data->unk_20 = rand_int(31);
    data->unk_24 = posY + arg4;
}

void rising_bubble_init(EffectInstance* effect) {
}

void rising_bubble_update(EffectInstance* effect) {
    RisingBubbleFXData* data = effect->data.risingBubble;
    s32 timeLeft = data->timeLeft;

    if (data->pos.y >= data->unk_24) {
        data->timeLeft--;
        data->lifeTime++;

        if (data->timeLeft < 0) {
            remove_effect(effect);
            return;
        }

        if (timeLeft >= 6) {
            data->unk_14 += (120 - data->unk_14) * 0.3;
        } else {
            data->unk_14 = timeLeft * 20;
        }

        data->unk_20++;
        if (data->unk_20 >= 32) {
            data->unk_20 -= 32;
        }

        data->unk_10 += 0.1;
        return;
    }

    data->unk_14 = 255;
    data->lifeTime++;
    data->pos.y += 2.0f;
}

void rising_bubble_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = rising_bubble_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void rising_bubble_appendGfx(void* effect) {
    RisingBubbleFXData* data = ((EffectInstance*)effect)->data.risingBubble;
    s32 lifeTime = data->lifeTime;
    Matrix4f sp20;
    Matrix4f sp60;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    if (data->pos.y >= data->unk_24) {
        s32 uls;
        s32 ult;

        gSPDisplayList(gMainGfxPos++, D_E0046614[0]);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 127, 127, 127, data->unk_14);

        uls = 0;
        ult = data->unk_20;

        gDPSetTileSize(gMainGfxPos++, 1,
            (uls     ) * 4, (ult     ) * 4,
            (uls + 32) * 4, (ult + 32) * 4);

        guTranslateF(sp20, data->pos.x, data->pos.y, data->pos.z);
        guScaleF(sp60, data->unk_10, 1.0f, data->unk_10);
        guMtxCatF(sp60, sp20, sp20);
    } else {
        gSPDisplayList(gMainGfxPos++, D_E0046618[0]);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, data->unk_14);
        gDPSetEnvColor(gMainGfxPos++, 128, 128, 255, data->unk_14);

        guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, data->unk_10, data->pos.x, data->pos.y, data->pos.z);
    }

    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (data->pos.y >= data->unk_24) {
        gSPDisplayList(gMainGfxPos++, D_E0046600[0]);
    } else {
        gSPDisplayList(gMainGfxPos++, D_E0046604[(lifeTime >> 1) & 3]);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
