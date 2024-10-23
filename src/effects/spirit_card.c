#include "common.h"
#include "effects_internal.h"

extern Gfx D_09003F98_3FE448[];
extern Gfx D_09004010_3FE4C0[];
extern Gfx D_09004088_3FE538[];
extern Gfx D_09004100_3FE5B0[];
extern Gfx D_09004178_3FE628[];
extern Gfx D_090041F0_3FE6A0[];
extern Gfx D_09004268_3FE718[];
extern Gfx D_090042E0_3FE790[];
extern Gfx D_09004360_3FE810[];
extern Gfx D_09004458_3FE908[];
extern Gfx D_09004508_3FE9B8[];
extern Gfx D_09004600_3FEAB0[];

Gfx* D_E0112630[] = { D_09004458_3FE908, D_09004600_3FEAB0 };
Gfx* D_E0112638[] = { D_09004360_3FE810, D_09004508_3FE9B8 };
Gfx* D_E0112640[] = {
    D_09003F98_3FE448, D_09004010_3FE4C0, D_09004088_3FE538, D_09004100_3FE5B0,
    D_09004178_3FE628, D_090041F0_3FE6A0, D_09004268_3FE718
};

void spirit_card_init(EffectInstance* effect);
void spirit_card_update(EffectInstance* effect);
void spirit_card_render(EffectInstance* effect);
void spirit_card_appendGfx(void* effect);

EFFECT_DEF_RING_BLAST(ring_blast_main);
EFFECT_DEF_MISC_PARTICLES(misc_particles_main);

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
    bp.renderScene = spirit_card_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_SPIRIT_CARD;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.spiritCard = general_heap_malloc(numParts * sizeof(*data));
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
        load_effect(EFFECT_RING_BLAST);
        ring_blast_main(1, data->pos.x, data->pos.y, data->pos.z, 3.0f, 30);
    }

    if (arg0 < 2) {
        load_effect(EFFECT_MISC_PARTICLES);
        data->child = misc_particles_main(3, arg1, arg2 - arg4 * 30.0f, arg3, arg4 * 30.0f, arg4 * 50.0f, 1.0f, 16, 0);
    } else {
        data->child = NULL;
    }

    return effect;
}

void spirit_card_init(EffectInstance* effect) {
}

void spirit_card_update(EffectInstance* effect) {
    SpiritCardFXData* data = effect->data.spiritCard;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 16;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        remove_effect(effect);
        if (data->child != NULL) {
            data->child->flags |= FX_INSTANCE_FLAG_DISMISS;
        }
    } else if (data->unk_10 >= 16 && data->child != NULL) {
        data->child->data.miscParticles->scaleX = data->unk_18 * 30.0f;
        data->child->data.miscParticles->scaleY = data->unk_18 * 50.0f;
        data->child->data.miscParticles->pos.x = data->pos.x;
        data->child->data.miscParticles->pos.y = data->pos.y - data->unk_18 * 30.0f;
        data->child->data.miscParticles->pos.z = data->pos.z;
    }
}

void spirit_card_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = spirit_card_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E0112330(s32 arg0, SpiritCardFXData* data) {
    f32 temp;
    Matrix4f sp20;
    Matrix4f sp60;

    if (arg0 == 0) {
        temp = gCameras[gCurrentCameraID].curYaw;
    } else {
        temp = 0.0f;
    }

    guPositionF(sp20, 0.0f, data->yaw - temp, 0.0f, data->unk_18, data->pos.x + 2.0f, data->pos.y, data->pos.z + 2.0f);
    guRotateF(sp60, data->unk_20, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guTranslateF(sp60, 0.0f, 0.0f, -2.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void spirit_card_appendGfx(void* effect) {
    SpiritCardFXData* data = ((EffectInstance*)effect)->data.spiritCard;
    s32 unk_00 = data->unk_00;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, D_090042E0_3FE790);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, 255);

    if (unk_00 < 2) {
        func_E0112330(0, data);

        gSPDisplayList(gMainGfxPos++, D_E0112638[0]);
        gSPDisplayList(gMainGfxPos++, D_E0112640[data->chapter]);
        gSPDisplayList(gMainGfxPos++, D_E0112630[0]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMainGfxPos++);
}
