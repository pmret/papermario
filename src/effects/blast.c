#include "common.h"
#include "effects_internal.h"

void blast_appendGfx(void* effect);
void blast_init(EffectInstance* effect);
void blast_update(EffectInstance* effect);
void blast_render(EffectInstance* effect);

extern Gfx D_09001300[];
extern Gfx D_09001378[];
extern Gfx D_090013F0[];
extern Gfx D_09001468[];
extern Gfx D_090014E0[];
extern Gfx D_09001558[];
extern Gfx D_090015D0[];
extern Gfx D_09001648[];
extern Gfx D_090016C0[];
extern Gfx D_09001738[];
extern Gfx D_090017B0[];

Gfx* D_E007C510[] = {
    D_09001378, D_090013F0, D_09001468, D_090014E0, D_09001558, D_090015D0, D_09001648, D_090016C0, D_09001738
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
    bp.renderWorld = blast_render;
    bp.unk_00 = 0;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_BLAST;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;

    part = effect->data = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

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
    BlastFXData* part = effect->data;

    part->unk_20 = part->unk_18++ * 9.0f / part->unk_1C;
    part->timeLeft--;

    if (part->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }

    part->unk_24 += part->unk_28;
}

void blast_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = blast_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

#ifdef NON_MATCHING
void blast_appendGfx(void* effect) {
    Matrix4f sp18, sp58, sp98;
    Gfx* dlist;
    Gfx* dlist2;
    BlastFXData* data = ((EffectInstance*)effect)->data;
    f32 temp_f2;
    s32 temp_f4;
    s32 alpha;

    dlist = D_090017B0;
    dlist2 = D_09001300;

    temp_f4 = data->unk_20;
    temp_f2 = temp_f4;
    alpha = (temp_f2 - temp_f4) * 256.0f;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, dlist2);
    gSPDisplayList(gMasterGfxPos++, D_E007C510[temp_f4]);

    shim_guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp98);
    shim_guScaleF(sp18, data->unk_10, data->unk_10, 1.0f);
    shim_guMtxCatF(sp18, sp98, sp98);
    shim_guRotateF(sp18, data->unk_24, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(sp18, sp98, sp98);
    shim_guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    if (data->unk_20 > 4.0f) {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 255, 127);
    } else {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 128, 127);
    }

    gDPSetEnvColor(gMasterGfxPos++, 255, 255, 139, alpha);

    gSPDisplayList(gMasterGfxPos++, dlist);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
#else
INCLUDE_ASM(s32, "effects/blast", blast_appendGfx);
#endif
