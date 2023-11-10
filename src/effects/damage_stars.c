#include "common.h"
#include "effects_internal.h"

extern Gfx D_090004C0_343500[];
extern Gfx D_090005E0_343620[];

u8 D_E0030E90[] = {
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
    254, 213, 172
};

f32 D_E0030EB4;

void damage_stars_init(EffectInstance* effect);
void damage_stars_update(EffectInstance* effect);
void damage_stars_render(EffectInstance* effect);
void damage_stars_appendGfx(void* effect);

void damage_stars_main(s32 type, f32 x, f32 y, f32 z, f32 rotAxisX, f32 rotAxisY, f32 rotAxisZ, s32 number) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    DamageStarsFXData* part;
    f32 norm;
    f32 var_f28;
    f32 var_f30;
    f32 rotateX;
    f32 rotateZ;
    f32 sp70;
    Matrix4f mtxRot;
    s32 i;

    if (number == 0) {
        return;
    }

    norm = SQ(rotAxisX) + SQ(rotAxisY) + SQ(rotAxisZ);
    if (norm == 0.0f) {
        return;
    }
    norm = -1.0f / sqrtf(norm);

    rotAxisX *= norm;
    rotAxisY *= norm;
    rotAxisZ *= norm;

    if (rotAxisX != 0.0f) {
        sp70 = 1.0f;
        var_f30 = -rotAxisY / rotAxisX;
        var_f28 = 0.0f;
    } else if (rotAxisY != 0.0f) {
        sp70 = -rotAxisX / rotAxisY;
        var_f30 = 1.0f;
        var_f28 = 0.0f;
    } else {
        sp70 = 0.0f;
        var_f30 = 1.0f;
        var_f28 = -rotAxisX / rotAxisZ;
    }

    norm = SQ(var_f30) + SQ(sp70) + SQ(var_f28);
    if (norm != 0) {
        norm = 1.0f / sqrtf(norm);

        var_f30 *= norm;
        sp70 *= norm;
        var_f28 *= norm;

        var_f30 *= 8.0f;
        sp70 *= 8.0f;
        var_f28 *= 8.0f;
        rotAxisX *= 8.0f;
        rotAxisY *= 8.0f;
        rotAxisZ *= 8.0f;

        bpPtr->unk_00 = 0;
        bpPtr->init = damage_stars_init;
        bpPtr->update = damage_stars_update;
        bpPtr->renderWorld = damage_stars_render;
        bpPtr->renderUI = NULL;
        bpPtr->effectID = EFFECT_DAMAGE_STARS;

        effect = create_effect_instance(bpPtr);
        effect->numParts = number;
        part = effect->data.damageStars = general_heap_malloc(number * sizeof(*part));
        ASSERT(effect->data.damageStars != NULL);

        for (i = 0; i < number; i++, part++) {
            part->type = type;
            part->pos.x = x;
            part->pos.y = y;
            part->pos.z = z;

            switch (type) {
                case FX_DAMAGE_STARS_0:
                case FX_DAMAGE_STARS_1:
                case FX_DAMAGE_STARS_2:
                    guRotateF(mtxRot, (i * 360) / (number - 1), rotAxisX, rotAxisY, rotAxisZ);
                    part->vel.x = rotAxisX + mtxRot[0][0] * var_f30 + mtxRot[1][0] * sp70 + mtxRot[2][0] * var_f28;
                    part->vel.y = rotAxisY + mtxRot[0][1] * var_f30 + mtxRot[1][1] * sp70 + mtxRot[2][1] * var_f28;
                    part->vel.z = rotAxisZ + mtxRot[0][2] * var_f30 + mtxRot[1][2] * sp70 + mtxRot[2][2] * var_f28;
                    break;
                case FX_DAMAGE_STARS_3:
                    rotateX = sin_deg(gCameras[gCurrentCameraID].curYaw);
                    rotateZ = -cos_deg(gCameras[gCurrentCameraID].curYaw);
                    guRotateF(mtxRot,
                        (number != 1) ? (i * 100) / (number - 1) - 50 : 0.0f,
                        rotateX, 0.0f, rotateZ);
                    part->vel.x = mtxRot[0][0] * rotAxisX + mtxRot[1][0] * rotAxisY + mtxRot[2][0] * rotAxisZ;
                    part->vel.y = mtxRot[0][1] * rotAxisX + mtxRot[1][1] * rotAxisY + mtxRot[2][1] * rotAxisZ;
                    part->vel.z = mtxRot[0][2] * rotAxisX + mtxRot[1][2] * rotAxisY + mtxRot[2][2] * rotAxisZ;
                    break;
                case FX_DAMAGE_STARS_4:
                    rotateX = sin_deg(gCameras[gCurrentCameraID].curYaw);
                    rotateZ = -cos_deg(gCameras[gCurrentCameraID].curYaw);
                    guRotateF(mtxRot, (i * 360.0f) / (number - 1), rotateX, 0.0f, rotateZ);
                    part->vel.x = mtxRot[0][0] * rotAxisX + mtxRot[1][0] * rotAxisY + mtxRot[2][0] * rotAxisZ;
                    part->vel.y = mtxRot[0][1] * rotAxisX + mtxRot[1][1] * rotAxisY + mtxRot[2][1] * rotAxisZ;
                    part->vel.z = mtxRot[0][2] * rotAxisX + mtxRot[1][2] * rotAxisY + mtxRot[2][2] * rotAxisZ;
                    break;
            }

            switch (type) {
                case FX_DAMAGE_STARS_0:
                    part->rollAngleVel = 0;
                    part->timeLeft = 24;
                    break;
                case FX_DAMAGE_STARS_1:
                    part->rollAngleVel = 20.0f;
                    part->timeLeft = 24;
                    break;
                case FX_DAMAGE_STARS_2:
                    part->rollAngleVel = 20.0f;
                    part->timeLeft = 40;
                    part->vel.x *= 0.5;
                    part->vel.y *= 0.5;
                    part->vel.z *= 0.5;
                    break;
                case FX_DAMAGE_STARS_3:
                case FX_DAMAGE_STARS_4:
                    part->rollAngleVel = 20.0f;
                    part->timeLeft = 24;
                    break;
            }

            part->rollAngle = 0;
            part->lifetime = 0;
            part->alpha = 255;
        }

        D_E0030EB4 += 15.0f;
        if (D_E0030EB4 > 360.0f) {
            D_E0030EB4 = 0.0f;
        }
    }
}

void damage_stars_init(EffectInstance* effect) {
}

void damage_stars_update(EffectInstance* effect) {
    DamageStarsFXData* part = effect->data.damageStars;
    s32 time;
    s32 unk_2C;
    s32 i;

    part->timeLeft--;
    part->lifetime++;

    if (part->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = part->timeLeft;
    unk_2C = part->lifetime;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->type == FX_DAMAGE_STARS_2) {
            part->vel.y = cos_deg(unk_2C * 6) * 4.0f;
            part->vel.x *= 0.94;
            part->vel.z *= 0.94;
            if (part->vel.y < 0.0f) {
                part->rollAngleVel *= 0.8;
                part->alpha *= 0.6;
            }
        } else {
            if (time >= 6) {
                part->vel.x *= 0.8;
                part->vel.y *= 0.8;
                part->vel.z *= 0.8;
            }
            if (time >= 6 && time <= 19) {
                if (part->type == FX_DAMAGE_STARS_0) {
                    part->rollAngleVel += 1.0f;
                }
            } else if (time < 5) {
                part->rollAngleVel *= 0.8;
                part->alpha *= 0.6;
                part->vel.x *= 0.7;
                part->vel.y *= 0.7;
                part->vel.z *= 0.7;
            }
        }

        part->pos.x += part->vel.x;
        part->pos.y += part->vel.y;
        part->pos.z += part->vel.z;
        part->rollAngle += part->rollAngleVel;
    }
}

void damage_stars_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = damage_stars_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void damage_stars_appendGfx(void* effect) {
    DamageStarsFXData* part = ((EffectInstance*)effect)->data.damageStars;
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    s32 baseIdx;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_090004C0_343500);

    baseIdx = (part->lifetime - 1) * 3;
    baseIdx %= 36;

    for (i = 0; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        s32 rIdx = baseIdx + i * 3;
        s32 gIdx = baseIdx + 1 + i * 3;
        s32 bIdx = baseIdx + 2 + i * 3;

        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0030E90[rIdx % 36], D_E0030E90[gIdx % 36], D_E0030E90[bIdx % 36], part->alpha);
        guTranslateF(mtxTransform, part->pos.x, part->pos.y, part->pos.z);
        guRotateF(mtxTemp, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        guRotateF(mtxTransform, part->rollAngle, 0.0f, 0.0f, 1.0f);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_090005E0_343620);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}
