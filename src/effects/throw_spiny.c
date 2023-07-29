#include "common.h"
#include "effects_internal.h"
#include "effects.h"

void throw_spiny_appendGfx(void* effect);

void throw_spiny_init(EffectInstance* effect);
void throw_spiny_update(EffectInstance* effect);
void throw_spiny_render(EffectInstance* effect);

extern Gfx D_09000800_3D02F0[];
extern Gfx D_090008D8_3D03C8[];
extern Gfx D_090009F0_3D04E0[];

Gfx* D_E00C8710[2] = { D_09000800_3D02F0, D_090008D8_3D03C8 };

u8 D_E00C8718[8] = { 110, 150, 130, 110, 100, 95, 100, 0 };
u8 D_E00C8720[8] = { 80, 60, 80, 100, 120, 110, 100, 0 };

//during spiny surge
EffectInstance* throw_spiny_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 time) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    ThrowSpinyFXData* spinyObject;
    s32 numParts = 1;
    f32 temp_f4, temp_f8, gravity;

    bp.init = throw_spiny_init;
    bp.update = throw_spiny_update;
    bp.renderWorld = throw_spiny_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_THROW_SPINY;

    effect = (EffectInstance*)create_effect_instance(bpPtr);
    effect->numParts = numParts;
    spinyObject = effect->data.throwSpiny = general_heap_malloc(numParts * sizeof(*spinyObject));
    ASSERT(effect->data.throwSpiny != NULL);
    spinyObject->unk_00 = arg0;
    spinyObject->lifeDuration = 0;

    if (time <= 0) {
        spinyObject->life = 1000;
    } else {
        spinyObject->life = time + 60;
    }

    temp_f8 = arg5 - arg2;
    temp_f4 = time;
    gravity = (temp_f8 / temp_f4) - (time * -0.10000000149011612); //TODO: fix this weird number
    spinyObject->timeUntilFall = time;
    spinyObject->rgba = 255;
    spinyObject->unk_10 = arg1;
    spinyObject->unk_14 = arg2;
    spinyObject->unk_18 = arg3;
    spinyObject->unk_1C = arg4;
    spinyObject->unk_20 = arg5;
    spinyObject->unk_24 = arg6;
    spinyObject->unk_44 = (arg4 - arg1) / temp_f4;
    spinyObject->unk_4C = (arg6 - arg3) / temp_f4;
    spinyObject->pos.x = arg1;
    spinyObject->pos.y = arg2;
    spinyObject->pos.z = arg3;
    spinyObject->gravity = gravity;

    if (temp_f8 < 0.0f) {
        spinyObject->unk_64 = 1;
    } else {
        spinyObject->unk_64 = 0;
    }

    spinyObject->unk_40 = arg7;
    spinyObject->unk_30 = 70;
    spinyObject->unk_34 = 180;
    spinyObject->unk_38 = 120;
    spinyObject->yaw = rand_int(360);
    spinyObject->rotSpeed = rand_int(10) + 5;
    spinyObject->state = -1;
    spinyObject->xScale = 1.0f;
    spinyObject->yScale = 1.0f;
    return effect;
}

void throw_spiny_init(EffectInstance* effect) {
}

void throw_spiny_update(EffectInstance* effectInstance) {
    ThrowSpinyFXData* spinyObject = effectInstance->data.throwSpiny;
    u32 state;
    f32 gravity;
    s32 lifeDuration;

    if (effectInstance->flags & FX_INSTANCE_FLAG_DISMISS) {
        effectInstance->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        spinyObject->life = 16;
    }

    if (spinyObject->life < 1000) {
        spinyObject->life--;
    }

    spinyObject->lifeDuration++;

    if (spinyObject->life < 0) {
        remove_effect(effectInstance);
        return;
    }

    lifeDuration = spinyObject->lifeDuration;
    state = spinyObject->state;

    if (state < 7) {
        spinyObject->xScale = D_E00C8718[state] * 0.01f;
        spinyObject->yScale = D_E00C8720[state] * 0.01f;
        spinyObject->state += 1;
        spinyObject->yaw -= 40.0f;
    } else {
        spinyObject->gravity += -0.2f;
        spinyObject->pos.x += spinyObject->unk_44;
        spinyObject->pos.y += spinyObject->gravity;
        spinyObject->pos.z += spinyObject->unk_4C;
        spinyObject->yaw += spinyObject->rotSpeed;
    }

    if ((lifeDuration - 1) == spinyObject->timeUntilFall) {
        spinyObject->state = 0;
        spinyObject->gravity = -spinyObject->gravity;
        spinyObject->unk_44 = spinyObject->unk_44;
        spinyObject->rotSpeed = -4.0f;
        return;
    }

    gravity = spinyObject->gravity;

    if ((gravity < 0.0f) && (spinyObject->pos.y < 100.0 / 7.0)) {
        spinyObject->pos.y = 100.0f / 7.0f;
        spinyObject->rotSpeed = -20.0f;
        spinyObject->gravity = gravity - gravity;
    }
}

void throw_spiny_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = throw_spiny_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00C844C(void) {
}

void throw_spiny_appendGfx(void* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    Camera* camera = &gCameras[gCurrentCameraID];
    ThrowSpinyFXData* data = ((EffectInstance*)effect)->data.throwSpiny;
    s32 temp_s5 = data->rgba;
    s32 temp_s6 = data->unk_00;
    f32 scale = data->unk_40 * SPRITE_WORLD_SCALE_D;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guScaleF(sp58, scale * data->xScale, scale * data->yScale, scale);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, data->yaw, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_30, data->unk_34, data->unk_38, temp_s5);
    gSPDisplayList(gMainGfxPos++, D_E00C8710[temp_s6]);
    gSPDisplayList(gMainGfxPos++, D_090009F0_3D04E0);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
