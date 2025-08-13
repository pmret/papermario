#include "common.h"
#include "effects_internal.h"

s32 D_E001A610 = 0;

extern Gfx D_090002F0_330750[];

void floating_flower_init(EffectInstance* effect);
void floating_flower_update(EffectInstance* effect);
void floating_flower_render(EffectInstance* effect);
void floating_flower_appendGfx(void* effect);

void floating_flower_main(s32 type, f32 posX, f32 posY, f32 posZ, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FloatingFlowerFXData* part;
    s32 numParts = 1;
    f32 phi_f6;

    bp.unk_00 = 0;
    bp.init = floating_flower_init;
    bp.update = floating_flower_update;
    bp.renderScene = floating_flower_render;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_FLOATING_FLOWER;

    effect = create_effect_instance(&bp);
    effect->numParts = 1;
    part = effect->data.floatingFlower = general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.floatingFlower != nullptr);

    part->type = type;
    part->pos.x = posX;
    part->pos.y = posY + 10.0f;
    part->pos.z = posZ;
    part->vel.x = 0.0f;
    part->vel.y = 0.0f;
    part->vel.z = 0.0f;

    if (type == 0) {
        part->vel.z = 0;
        part->rot.x = 0.0f;
        part->rot.y = 0.0f;
        part->accelY = 0.12f;
        part->jerkY = -0.0152f;
        part->angularVel.x = 3.0f;
        if (D_E001A610 != 0) {
            phi_f6 = -10.0f;
        } else {
            phi_f6 = 10.0f;
        }
        part->angularVel.y = phi_f6;
        part->timeLeft = duration;
    } else {
        part->accelY = 0.12f;
        part->jerkY = -0.0152f;
        part->rot.x = (rand_int(1) * 30) - 15;
        part->rot.y = rand_int(360);
        part->angularVel.x = 0;
        part->angularVel.y = (rand_int(1) * 8) - 4;
        part->timeLeft = duration;
        part->lifetime = 0;
        part->unk_44 = rand_int(10);
        part->unk_40 = rand_int(20);
        part->unk_3C = (rand_int(1) * 2) - 1;
    }

    D_E001A610++;
    if (D_E001A610 > 1) {
        D_E001A610 = 0;
    }
}

void floating_flower_init(EffectInstance* effect) {
}

void floating_flower_update(EffectInstance* effect) {
    FloatingFlowerFXData* data = effect->data.floatingFlower;
    s32 type = data->type;

    if (data->timeLeft < 150) {
        data->vel.x -= 0.001;
        data->pos.x += data->vel.x;
        data->pos.z += data->vel.z;
        data->rot.x += data->angularVel.x;
        if (type == 0) {
            if (data->rot.x < 10.0f) {
                data->rot.x = 10.0f;
                data->angularVel.x = -data->angularVel.x;
            }
            if (data->rot.x > 45.0f) {
                data->rot.x = 45.0f;
                data->angularVel.x = -data->angularVel.x;
            }
        }
        data->rot.y += data->angularVel.y;
        if (type == 0) {
            data->vel.y = 1.4f;
        } else {
            data->vel.y = 1.0f;
        }
    } else {
        data->jerkY += 0.0007;
        data->accelY += data->jerkY;
        data->vel.y += data->accelY;
        if (data->vel.y > 1.0f) {
            data->vel.y = 1.0f;
        }
    }

    if (type == 1) {
        data->unk_40 += data->unk_3C;
        if (data->unk_40 >= 20) {
            data->unk_40 = 20;
            data->unk_3C = -1;
        } else if (data->unk_40 <= 0) {
            data->unk_40 = 0;
            data->unk_3C = type;
        }
    }
    data->pos.y += data->vel.y;
    data->timeLeft--;
    data->lifetime++;
    if (data->timeLeft < 0) {
        remove_effect(effect);
    }
}

void floating_flower_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = floating_flower_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void floating_flower_appendGfx(void* effect) {
    Matrix4f mtxTransform, mtxUnused;
    EffectInstance* effectTemp = effect;
    FloatingFlowerFXData* part = effectTemp->data.floatingFlower;
    u32 alpha;
    u8 rgb, a;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->shared->graphics));

    guPositionF(mtxTransform, part->rot.x, part->rot.y, 0.0f, 1.0f, part->pos.x, part->pos.y, part->pos.z);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

    a = alpha = 255;

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (*gBackgroundTintModePtr == ENV_TINT_SHROUD) {
        mdl_get_shroud_tint_params(&rgb, &rgb, &rgb, &a);
        alpha -= a;
    }

    if (alpha != 0) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);
        gSPDisplayList(gMainGfxPos++, D_090002F0_330750);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}
