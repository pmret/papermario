#include "common.h"
#include "effects_internal.h"

extern Gfx D_090042E0[];
extern Gfx* D_E0112630[];
extern Gfx* D_E0112638[];
extern Gfx* D_E0112640[];

void spirit_card_init(EffectInstance* effect);
void spirit_card_update(EffectInstance* effect);
void spirit_card_render(EffectInstance* effect);
void spirit_card_appendGfx(void* effect);

EffectInstance* spirit_card_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5)
{
    EffectBlueprint bp;
    EffectInstance* effect;
    SpiritCardFXData* data;
    s32 numParts = 1;

    bp.init = spirit_card_init;
    bp.update = spirit_card_update;
    bp.renderWorld = spirit_card_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_SPIRIT_CARD;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.spiritCard = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.spiritCard != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->unk_18 = arg4;
    data->yaw = 0;
    data->chapter = 0;
    data->unk_20 = 30.0f;

    if (arg0 == 0) {
        shim_load_effect(EFFECT_RING_BLAST);
        ring_blast_main(1, data->pos.x, data->pos.y, data->pos.z, 3.0f, 30);
    }

    if (arg0 < 2) {
        shim_load_effect(EFFECT_MISC_PARTICLES);
        data->unk_1C = misc_particles_main(3, arg1, arg2 - arg4 * 30.0f, arg3, arg4 * 30.0f, arg4 * 50.0f, 1.0f, 16, 0);
    } else {
        data->unk_1C = NULL;
    }

    return effect;
}

void spirit_card_init(EffectInstance* effect) {
}

void spirit_card_update(EffectInstance* effect) {
    SpiritCardFXData* data = effect->data.spiritCard;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_10 = 16;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        shim_remove_effect(effect);
        if (data->unk_1C != NULL) {
            data->unk_1C->flags |= 0x10;
        }
    } else if (data->unk_10 >= 16 && data->unk_1C != NULL) {
        data->unk_1C->data.miscParticles->scaleX = data->unk_18 * 30.0f;
        data->unk_1C->data.miscParticles->scaleY = data->unk_18 * 50.0f;
        data->unk_1C->data.miscParticles->pos.x = data->pos.x;
        data->unk_1C->data.miscParticles->pos.y = data->pos.y - data->unk_18 * 30.0f;
        data->unk_1C->data.miscParticles->pos.z = data->pos.z;
    }
}

void spirit_card_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = spirit_card_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E0112330(s32 arg0, SpiritCardFXData* data) {
    f32 temp;
    Matrix4f sp20;
    Matrix4f sp60;

    if (arg0 == 0) {
        temp = gCameras[gCurrentCameraID].currentYaw;
    } else {
        temp = 0.0f;
    }

    shim_guPositionF(sp20, 0.0f, data->yaw - temp, 0.0f, data->unk_18, data->pos.x + 2.0f, data->pos.y, data->pos.z + 2.0f);
    shim_guRotateF(sp60, data->unk_20, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guTranslateF(sp60, 0.0f, 0.0f, -2.0f);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void spirit_card_appendGfx(void* effect) {
    SpiritCardFXData* data = ((EffectInstance*)effect)->data.spiritCard;
    s32 unk_00 = data->unk_00;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, D_090042E0);
    gDPSetEnvColor(gMasterGfxPos++, 0, 0, 0, 255);

    if (unk_00 < 2) {
        func_E0112330(0, data);

        gSPDisplayList(gMasterGfxPos++, D_E0112638[0]);
        gSPDisplayList(gMasterGfxPos++, D_E0112640[data->chapter]);
        gSPDisplayList(gMasterGfxPos++, D_E0112630[0]);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMasterGfxPos++);
}
