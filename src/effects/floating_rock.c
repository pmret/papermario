#include "common.h"
#include "effects_internal.h"

extern Gfx D_090003A0_396490[];
extern Gfx D_090003E0_3964D0[];
extern Gfx D_09000410_396500[];
extern Gfx D_09000450_396540[];

Gfx* D_E0098510[] = {
    D_090003A0_396490, D_090003E0_3964D0, D_09000410_396500,
    D_090003A0_396490, D_090003E0_3964D0, D_09000410_396500
};

void floating_rock_init(EffectInstance* effect);
void floating_rock_update(EffectInstance* effect);
void floating_rock_render(EffectInstance* effect);
void floating_rock_appendGfx(void* effect);

EffectInstance* floating_rock_main(s32 type, f32 posX, f32 posY, f32 posZ, f32 floorY, f32 fallVelocity, f32 fallAccel, f32 scale, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FloatingRockFXData* data;
    s32 numParts = 1;

    bp.init = floating_rock_init;
    bp.update = floating_rock_update;
    bp.renderWorld = floating_rock_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_FLOATING_ROCK;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.floatingRock = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.floatingRock != NULL);

    data->type = type;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->floorY = floorY;
    data->vel.y = fallVelocity;
    data->fallAccel = fallAccel;
    data->timeLeft = duration;
    data->lifetime = 0;
    data->vel.x = 0;
    data->vel.z = 0;
    data->rot.x = 0;
    data->rot.y = rand_int(360);
    data->rot.z = rand_int(360);
    data->rotVel.x = 0.0f;
    data->rotVel.z = 20.0f;
    data->rotVel.y = -20.0f;

    data->scale = 2.0f * scale;
    data->alpha = 255;
    data->unk_40 = 0;

    return effect;
}

void floating_rock_init(EffectInstance* effect) {
}

EFFECT_DEF_DUST(dust_main);

void floating_rock_update(EffectInstance* effect) {
    FloatingRockFXData* data = effect->data.floatingRock;
    s32 time;

    data->timeLeft--;
    data->lifetime++;
    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = data->timeLeft;
    if (data->pos.y != data->floorY) {
        data->vel.y += data->fallAccel;
        data->pos.y += data->vel.y;
        data->rot.x += data->rotVel.x;
        data->rot.z += data->rotVel.z;
        data->rot.y += data->rotVel.y;
        if (data->pos.y <= data->floorY) {
            data->pos.y = data->floorY;
            load_effect(EFFECT_DUST);
            dust_main(2, data->pos.x, data->pos.y, data->pos.z, 20);
            data->timeLeft = 30;
        }
    }

    if (time < 10) {
        data->alpha *= 0.8;
    }
}

void floating_rock_render(EffectInstance *effect) {
    FloatingRockFXData* effect76 = effect->data.floatingRock;
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = floating_rock_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = effect76->pos.z;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void floating_rock_appendGfx(void* effect) {
    FloatingRockFXData* data = ((EffectInstance*)effect)->data.floatingRock;
    s32 alpha = data->alpha;
    Matrix4f mtxTransform;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guPositionF(mtxTransform, data->rot.x, data->rot.z, data->rot.y, data->scale, data->pos.x, data->pos.y, data->pos.z);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 215, 215, 110, alpha);

    if (alpha != 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    }

    gSPDisplayList(gMainGfxPos++, D_09000450_396540);
    gSPDisplayList(gMainGfxPos++, D_E0098510[data->type]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
