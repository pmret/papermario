#include "common.h"
#include "effects_internal.h"

s32 D_E001C5E0 = 0;

extern Gfx D_09000900_331800[];
extern Gfx D_090009E8_3318E8[];

void snowflake_init(EffectInstance* effect);
void snowflake_update(EffectInstance* effect);
void snowflake_render(EffectInstance* effect);
void snowflake_appendGfx(void* effect);

void snowflake_main(f32 x, f32 y, f32 z, s32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SnowflakeFXData* part;
    s32 numParts = 1;
    f32 phi_f4;

    bp.unk_00 = 0;
    bp.init = snowflake_init;
    bp.update = snowflake_update;
    bp.renderWorld = snowflake_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_SNOWFLAKE;

    effect = create_effect_instance(&bp);
    effect->numParts = 1;
    part = effect->data.snowflake = general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.snowflake != NULL);

    part->pos.x = x;
    part->pos.y = y;
    part->pos.z = z;
    part->unk_0C = 0;
    part->unk_10 = -3.0f;
    part->unk_14 = 0;
    part->unk_18 = 0;
    part->unk_1C = 0;
    part->unk_20 = 3.0f;
    if (D_E001C5E0 != 0) {
        phi_f4 = -10.0f;
    } else {
        phi_f4 = 10.0f;
    }
    part->unk_24 = phi_f4;
    part->unk_28 = arg3;

    D_E001C5E0++;
    if (D_E001C5E0 >= 2) {
        D_E001C5E0 = 0;
    }
}

void snowflake_init(EffectInstance* effect) {
}

void snowflake_update(EffectInstance* effect) {
    SnowflakeFXData* data = effect->data.snowflake;

    data->unk_28--;
    if (data->unk_28 < 0) {
        remove_effect(effect);
        return;
    }

    data->pos.x += data->unk_0C;
    data->pos.y += data->unk_10;
    data->pos.z += data->unk_14;
    data->unk_18 += data->unk_20;
    if (data->unk_18 < 10.0f) {
        data->unk_18 = 10.0f;
        data->unk_20 = -data->unk_20;
    }
    if (data->unk_18 > 45.0f) {
        data->unk_18 = 45.0f;
        data->unk_20 = -data->unk_20;
    }
    data->unk_1C += data->unk_24;
}

void snowflake_render(EffectInstance* effect) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SnowflakeFXData* data = effect->data.snowflake;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    f32 effectPos = data->pos.x;
    f32 playerPos = playerStatus->pos.x;

    if (effectPos - playerPos > 200) {
        data->pos.x = effectPos - 400;
    } else {
        if (playerPos - effectPos > 200) {
            data->pos.x = effectPos + 400;
        }
    }

    effectPos = data->pos.z;
    playerPos = playerStatus->pos.z;
    if (effectPos - playerPos > 200) {
        data->pos.z = effectPos - 400;
    } else {
        if (playerPos - effectPos > 200) {
            data->pos.z = effectPos + 400;
        }
    }

    renderTaskPtr->appendGfx = &snowflake_appendGfx;
    renderTaskPtr->appendGfxArg = effect;
    renderTaskPtr->dist = 0;
    renderTaskPtr->renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void snowflake_appendGfx(void* effect) {
    Matrix4f sp18, sp58, sp98, spD8, sp118;
    EffectInstance* effectTemp = effect;
    SnowflakeFXData* data = effectTemp->data.snowflake;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000900_331800);

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(spD8, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(spD8, sp18, sp118);
    guMtxF2L(sp118, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, 255);

    guRotateF(sp58, data->unk_18, 1.0f, 0.0f, 0.0f);
    guRotateF(sp98, data->unk_1C, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp98, sp118);
    guMtxF2L(sp118, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_090009E8_3318E8);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
