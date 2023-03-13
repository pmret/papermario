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
    bp.renderWorld = breaking_junk_render;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_BREAKING_JUNK;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;

    data = effect->data.breakingJunk = shim_general_heap_malloc(numParts * sizeof(*data));

    ASSERT(effect->data.breakingJunk != NULL);

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
        data->vel.x = (shim_rand_int(10) - 5) * 0.5;
        data->vel.y = (shim_rand_int(5) + 1) * 0.8;
        data->vel.z = (shim_rand_int(10) - 5) * 0.5;
        data->scale = scale;
        data->primR = data->envR = shim_rand_int(255);
        g = shim_rand_int(255 - data->envR);
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
        data->rot = shim_rand_int(359);
    }
    return effect;
}

void breaking_junk_init(EffectInstance* effect) {
}

void breaking_junk_update(EffectInstance* effect) {
    BreakingJunkFXData* data = effect->data.breakingJunk;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifeTime++;
    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
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
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void breaking_junk_appendGfx(void* effect) {
    Matrix4f sp20, sp60;
    BreakingJunkFXData* data = ((EffectInstance*)effect)->data.breakingJunk;
    s32 alpha = data->primA;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_E01187C0[0]);

    for (i = 0; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        shim_guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, data->scale * 0.5, data->pos.x, data->pos.y, data->pos.z);
        shim_guRotateF(sp60, data->rot, 0.0f, 0.0f, 1.0f);
        shim_guMtxCatF(sp60, sp20, sp20);
        shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primR, data->primG, data->primB, alpha);
        gDPSetEnvColor(gMainGfxPos++, data->envR, data->envG, data->envB, data->envA);
        gSPDisplayList(gMainGfxPos++, D_E01187B0[(u32)i % ARRAY_COUNT(D_E01187B0)]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMainGfxPos++);
}
