#include "common.h"
#include "effects_internal.h"

void music_note_appendGfx(void* effect);
void music_note_init(EffectInstance* effect);
void music_note_update(EffectInstance* effect);
void music_note_render(EffectInstance* effect);

extern Gfx D_09000FC0_35B5A0[];
extern Gfx D_09001038_35B618[];
extern Gfx D_090010C0_35B6A0[];
extern Gfx D_09001148_35B728[];
extern Gfx D_090011D0_35B7B0[];
extern Gfx D_09001258_35B838[];
extern Gfx D_090012E0_35B8C0[];
extern Gfx D_09001368_35B948[];

Gfx* D_E004C660[] = { D_09001038_35B618, D_090010C0_35B6A0, D_09001148_35B728, D_090011D0_35B7B0,
                      D_09001258_35B838, D_090012E0_35B8C0, D_09001368_35B948 };

s8 D_E004C67C[] = {
    254, 172, 172,
    254, 172, 213,
    254, 180, 154,
    213, 180, 254,
    180, 180, 254,
    180, 221, 254,
    180, 254, 254,
    180, 254, 213,
    180, 254, 180,
    213, 254, 180,
    254, 254, 180,
    254, 213, 172,
};

void music_note_main(s32 type, f32 posX, f32 posY, f32 posZ) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    MusicNoteFXData* part;
    s32 numParts = 1;
    s32 randInt;

    bp.unk_00 = 0;
    bp.init = music_note_init;
    bp.update = music_note_update;
    bp.renderWorld = music_note_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_MUSIC_NOTE;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;

    part = effect->data.musicNote = general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.musicNote != NULL);

    part->type = type;
    part->pos.x = posX;
    part->pos.y = posY;
    part->pos.z = posZ;
    part->scale = 0;
    part->timeLeft = 64;
    part->alpha = 0;
    part->lifetime = 0;
    part->noteType = rand_int(6);
    switch (type) {
        case 0:
            part->velX = 0.0f;
            part->velY = 1.0f;
            part->finalVelX = 0.0f;
            part->finalVelY = 1.0f;
            break;
        case 1:
            randInt = rand_int(10);
            part->velX = (randInt * 0.1) + -5.0;
            part->velY = (rand_int(10) * 0.1) + 0.5;
            part->finalVelX = 0.0f;
            part->finalVelY = 0.0f;
            break;
        default:
            randInt = rand_int(10);
            part->velX = 5.0 - (randInt * 0.1);
            part->velY = (rand_int(10) * 0.1) + 1.0;
            part->finalVelX = 0.0f;
            part->finalVelY = 0.0f;
            break;
    }
}

void music_note_init(EffectInstance* effect) {
}

void music_note_update(EffectInstance* effect) {
    MusicNoteFXData* part = effect->data.musicNote;
    s32 timeLeft;

    part->timeLeft--;
    part->lifetime++;
    timeLeft = part->timeLeft;
    if (timeLeft < 0) {
        remove_effect(effect);
        return;
    }
    if (timeLeft >= 6) {
        part->alpha += (255 - part->alpha) * 0.3;
        part->scale += (1.0f - part->scale) * 0.3;
    }
    if (timeLeft < 10) {
        part->alpha = timeLeft * 25;
    }
    part->pos.x += part->velX;
    part->pos.y += part->velY;
    part->velX += (part->finalVelX - part->velX) * 0.04;
    part->velY += (part->finalVelY - part->velY) * 0.04;
}

void music_note_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = music_note_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void music_note_appendGfx(void* data) {
    EffectInstance* effect = data;
    MusicNoteFXData* fxData = effect->data.musicNote;
    Matrix4f mtxTransform, mtxTemp;
    s32 colorIdx = fxData->lifetime;
    s32 dlistIdx = fxData->noteType;
    s32 rgbOffset;

    // TODO required to match - need to initialize define twice for some reason
    rgbOffset = (colorIdx * 3) % ARRAY_COUNT(D_E004C67C);
    rgbOffset = (colorIdx * 3) % ARRAY_COUNT(D_E004C67C);

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000FC0_35B5A0);
    gDPSetPrimColor(gMainGfxPos++, 0, 0,
        D_E004C67C[rgbOffset], D_E004C67C[rgbOffset + 1], D_E004C67C[rgbOffset + 2], fxData->alpha
    );
    guTranslateF(mtxTransform, fxData->pos.x, fxData->pos.y, fxData->pos.z);
    guRotateF(mtxTemp, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guScaleF(mtxTemp, fxData->scale, fxData->scale, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_E004C660[dlistIdx]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
