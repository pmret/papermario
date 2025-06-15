#include "common.h"
#include "effects_internal.h"

extern Gfx D_090003A0_38ED30[];
extern Gfx D_09000420_38EDB0[];

// perhaps additional, unused colors? 36 bytes would give 12 RGB colors
s32 D_E008CAF0[] = {
    0xFEACACFE, 0xACD5FEB4, 0x9AD5B4FE,
    0xB4B4FEB4, 0xDDFEB4FE, 0xFEB4FED5,
    0xB4FEB4D5, 0xFEB4FEFE, 0xB4FED5AC
};

u8 ColorsR[] = { 255, 255,  64 };
u8 ColorsG[] = { 255,  64,  64 };
u8 ColorsB[] = { 255,  64, 255 };

void effect_46_init(EffectInstance* effect);
void effect_46_update(EffectInstance* effect);
void effect_46_render(EffectInstance* effect);
void effect_46_appendGfx(void* effect);

EffectInstance* effect_46_main(s32 type, PlayerStatus* player, f32 scale, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SpinFXData* part;
    s32 numParts = 5;
    s32 colorIdx;
    s32 i;

    bp.init = effect_46_init;
    bp.update = effect_46_update;
    bp.renderScene = effect_46_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_46;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.spin = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.spin != nullptr);

    part->type = type;
    part->player = player;
    part->scale = scale * 1.2;
    part->initialScale = scale * 1.2;
    part->duration = duration;
    part->timeLeft = duration;
    part->alpha = 0;
    part->lifetime = 0;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        switch (type) {
            case 0:
            case 2:
            case 4:
            case 6:
                part->pos.x = 0.0f;
                part->pos.y = i * 7 + 4;
                part->pos.z = 0.0f;
                part->rotVel.x = 0.0f;
                part->rotVel.y = 60.0f;
                part->rotVel.z = 0.0f;
                part->rot.x = 0.0f;
                part->rot.y = i * 120;
                part->rot.z = 0.0f;
                part->scale = 1.0f;
                break;
            case 1:
            case 3:
            case 5:
            case 7:
                part->pos.x = 0.0f;
                part->pos.y = i * 7 + 4;
                part->pos.z = 0.0f;
                part->rotVel.x = 0.0f;
                part->rotVel.y = -60.0f;
                part->rotVel.z = 0.0f;
                part->rot.x = 0.0f;
                part->rot.y = i * 120;
                part->rot.z = 0.0f;
                part->scale = 1.0f;
                part->color.b = 255;
                part->color.g = 255;
                part->color.r = 255;
                break;
            default:
                part->pos.x = 0;
                part->pos.y = player->colliderHeight * 0.5;
                part->pos.z = 0;
                part->rotVel.x = effect_rand_int(1) * 8 - 4;
                part->rotVel.y = 0;
                part->rotVel.z = effect_rand_int(1) * 8 - 4;
                part->rot.x = i * 25;
                part->rot.y = (i - 1) * 360 / (numParts - 1);
                part->rot.z = 360 - i * 38;
                part->scale = (f32) (i - 1) / (numParts - 1) * 0.5 + 0.5;
                break;
        }

        switch (type) {
            case 2:
            case 3:
                colorIdx = 1;
                break;
            case 4:
            case 5:
                colorIdx = 2;
                break;
            case 6:
            case 7:
                colorIdx = (i & 1) + 1;
                break;
            default:
                colorIdx = 0;
                break;
        }

        part->color.r = ColorsR[colorIdx];
        part->color.g = ColorsG[colorIdx];
        part->color.b = ColorsB[colorIdx];
    }

    return effect;
}

void effect_46_init(EffectInstance* effect) {
}

void effect_46_update(EffectInstance* effect) {
    SpinFXData* part = effect->data.spin;
    s32 type;
    s32 time;
    s32 i;

    part->timeLeft--;
    part->lifetime++;

    if (part->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    type = part->type;
    time = part->timeLeft;

    if (type == 8) {
        if (time >= 6) {
            part->alpha += (255 - part->alpha) * 0.05;
        }
        part->scale = (part->initialScale * time) / part->duration;
        if (time < 10) {
            part->alpha = time * 25;
        }
    } else {
        if (time >= 6) {
            part->alpha += (100 - part->alpha) * 0.3;
        }
        if (time < 10) {
            part->alpha *= 0.8;
            part->scale += (2.0f * part->initialScale - part->scale) * 0.1;
        }
    }

    part->pos.x = part->player->pos.x;
    part->pos.y = part->player->pos.y;
    part->pos.z = part->player->pos.z;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        if (type == 8) {
            if (i % 2) {
                part->rotVel.y += (40.0f - part->rotVel.y) * 0.2;
            } else {
                part->rotVel.y += (-40.0f - part->rotVel.y) * 0.2;
            }
            part->rot.x += part->rotVel.x;
            part->rot.y += part->rotVel.y;
            part->rot.z += part->rotVel.z;
        } else if (time < 10) {
            part->rot.y += (part->rotVel.y * time) / 10.0f;
        } else {
            part->rot.y += part->rotVel.y;
        }
    }
}

void effect_46_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = effect_46_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void effect_46_appendGfx(void* effect) {
    SpinFXData* part = ((EffectInstance*)effect)->data.spin;
    s32 type;
    s32 alpha = part->alpha;
    f32 curScale = part->scale;
    f32 initialScale = part->initialScale;
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    s32 i;

    type = part->type;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, D_09000420_38EDB0);

    guTranslateF(mtxTransform, part->pos.x, part->pos.y, part->pos.z);
    guRotateF(mtxTemp, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        guPositionF(mtxTransform, part->rot.x, 0.0f, part->rot.z, curScale * part->scale, part->pos.x, part->pos.y, part->pos.z);
        guRotateF(mtxTemp, part->rot.y, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);

        if (type < 8) {
            guTranslateF(mtxTemp, 3.0f - (curScale - initialScale) * 3.0f / initialScale, 0.0f, 0.0f);
            guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        } else {
            guTranslateF(mtxTemp, 2.0f, 0.0f, 0.0f);
            guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        }

        gDPSetPrimColor(gMainGfxPos++, 0, 0, part->color.r, part->color.g, part->color.b, alpha);

        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_090003A0_38ED30);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
