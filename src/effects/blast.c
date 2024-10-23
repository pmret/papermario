#include "common.h"
#include "effects_internal.h"

void blast_init(EffectInstance* effect);
void blast_update(EffectInstance* effect);
void blast_render(EffectInstance* effect);
void blast_appendGfx(void* effect);

extern Gfx D_09001300_37ECD0[];
extern Gfx D_09001378_37ED48[];
extern Gfx D_090013F0_37EDC0[];
extern Gfx D_09001468_37EE38[];
extern Gfx D_090014E0_37EEB0[];
extern Gfx D_09001558_37EF28[];
extern Gfx D_090015D0_37EFA0[];
extern Gfx D_09001648_37F018[];
extern Gfx D_090016C0_37F090[];
extern Gfx D_09001738_37F108[];
extern Gfx D_090017B0_37F180[];

Gfx* D_E007C510[] = {
    D_09001378_37ED48, D_090013F0_37EDC0, D_09001468_37EE38,
    D_090014E0_37EEB0, D_09001558_37EF28, D_090015D0_37EFA0,
    D_09001648_37F018, D_090016C0_37F090, D_09001738_37F108
};

void blast_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    BlastFXData* part;
    s32 numParts = 1;
    s32 randInt;

    bp.init = blast_init;
    bp.update = blast_update;
    bp.renderScene = blast_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_BLAST;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;

    part = effect->data.blast = general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.blast != NULL);

    mem_clear(part, numParts * sizeof(*part));

    part->timeLeft = arg5;
    part->unk_18 = 0;
    part->unk_1C = arg5;
    part->unk_20 = 0;
    part->unk_00 = arg0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->unk_10 = arg4;
    part->unk_24 = 0;

    part->unk_28 = arg0 == 0 ? 0 : 40.0;
}

void blast_init(EffectInstance* effect) {
}

void blast_update(EffectInstance* effect) {
    BlastFXData* part = effect->data.blast;

    part->unk_20 = part->unk_18++ * 9.0f / part->unk_1C;
    part->timeLeft--;

    if (part->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    part->unk_24 += part->unk_28;
}

void blast_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = blast_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void blast_appendGfx(void* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Gfx* dlist = D_090017B0_37F180;
    BlastFXData* data = ((EffectInstance*) effect)->data.blast;
    s32 unk_20 = data->unk_20;
    f32 t = 256.0f;
    s32 envAlpha = (data->unk_20 - unk_20) * t;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, D_09001300_37ECD0);
    gSPDisplayList(gMainGfxPos++, D_E007C510[unk_20]);

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);
    guScaleF(sp18, data->unk_10, data->unk_10, 1.0f);
    guMtxCatF(sp18, sp98, sp98);
    guRotateF(sp18, data->unk_24, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp18, sp98, sp98);
    guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (data->unk_20 > 4.0f) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, 127);
    } else {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 128, 127);
    }
    t = !(s32)t; // required to match
    gDPSetEnvColor(gMainGfxPos++, 255, 255, 139, envAlpha);

    gSPDisplayList(gMainGfxPos++, dlist);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
