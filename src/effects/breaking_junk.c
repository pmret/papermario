#include "common.h"
#include "effects_internal.h"

void breaking_junk_init(EffectInstance* effect);
void breaking_junk_update(EffectInstance* effect);
void breaking_junk_render(EffectInstance* effect);
void breaking_junk_appendGfx(void* effect);

extern Gfx D_09000400_403FF0[];
extern Gfx D_090005A8_404198[];
extern Gfx D_090005C8_4041B8[];
extern Gfx D_090005E8_4041D8[];
extern Gfx D_09000608_4041F8[];

Gfx* D_E01187B0[] = { D_090005A8_404198, D_090005C8_4041B8, D_090005E8_4041D8, D_09000608_4041F8 };

Gfx* D_E01187C0[] = { D_09000400_403FF0 };

EffectInstance* breaking_junk_main(s32 arg0, f32 x, f32 y, f32 z, f32 scale, s32 time) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    BreakingJunkFXData* data;
    s32 numParts = 6;
    u32 g;
    s32 i;

    bp.unk_00 = 0;
    bp.init = breaking_junk_init;
    bp.update = breaking_junk_update;
    bp.renderScene = breaking_junk_render;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_BREAKING_JUNK;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;

    data = effect->data.breakingJunk = general_heap_malloc(numParts * sizeof(*data));

    ASSERT(effect->data.breakingJunk != nullptr);

    data->unk_00 = arg0;
    data->lifeTime = 0;
    if (time <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = time;
    }
    data->primA = 255;

    for (i = 0; i < effect->numParts; i++, data++) {
        data->pos.x = x;
        data->pos.y = y;
        data->pos.z = z;
        data->vel.x = (rand_int(10) - 5) * 0.5;
        data->vel.y = (rand_int(5) + 1) * 0.8;
        data->vel.z = (rand_int(10) - 5) * 0.5;
        data->scale = scale;
        data->primR = data->envR = rand_int(255);
        g = rand_int(255 - data->envR);
        data->primG = data->envG = g;
        data->primB = data->envB = (255 - g) - data->envR;
        data->primR += 168;
        data->primG += 168;
        data->primB += 168;
        if (data->primR > 255) {
            data->primR = 255;
        }
        if (data->primG > 255) {
            data->primG = 255;
        }
        if (data->primB > 255) {
            data->primB = 255;
        }
        data->envR = data->envR * 0.6;
        data->envG = data->envG * 0.6;
        data->envB = data->envB * 0.6;
        data->rot = rand_int(359);
    }
    return effect;
}

void breaking_junk_init(EffectInstance* effect) {
}

void breaking_junk_update(EffectInstance* effect) {
    BreakingJunkFXData* data = effect->data.breakingJunk;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifeTime++;
    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    if (data->timeLeft < 8) {
        data->primA = data->timeLeft * 32;
    }

    for (i = 0; i < effect->numParts; i++, data++) {
        data->vel.y -= 0.5;
        data->pos.x += data->vel.x;
        data->pos.y += data->vel.y;
        data->pos.z += data->vel.z;
        if (data->pos.y < 0.0f && data->vel.y < 0.0f) {
            data->pos.y = 0.0f;
            data->vel.y *= -0.7;
        }
        data->rot += (((i & 1) * 2) - 1) * 14;
    }
}

void breaking_junk_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = breaking_junk_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void breaking_junk_appendGfx(void* effect) {
    Matrix4f sp20, sp60;
    BreakingJunkFXData* data = ((EffectInstance*)effect)->data.breakingJunk;
    s32 alpha = data->primA;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, D_E01187C0[0]);

    for (i = 0; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, data->scale * 0.5, data->pos.x, data->pos.y, data->pos.z);
        guRotateF(sp60, data->rot, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp60, sp20, sp20);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primR, data->primG, data->primB, alpha);
        gDPSetEnvColor(gMainGfxPos++, data->envR, data->envG, data->envB, data->envA);
        gSPDisplayList(gMainGfxPos++, D_E01187B0[(u32)i % ARRAY_COUNT(D_E01187B0)]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMainGfxPos++);
}
