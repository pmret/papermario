#include "common.h"
#include "effects_internal.h"

extern Gfx D_09004FE8_3EAF18[];
extern Gfx D_09005090_3EAFC0[];
extern Gfx D_090050F0_3EB020[];
extern Gfx D_09005168_3EB098[];
extern Gfx D_090051E0_3EB110[];
extern Gfx D_09005258_3EB188[];
extern Gfx D_090052D0_3EB200[];
extern Gfx D_09005348_3EB278[];
extern Gfx D_090053C0_3EB2F0[];
extern Gfx D_09005438_3EB368[];
extern Gfx D_090054B0_3EB3E0[];
extern Gfx D_09005570_3EB4A0[];
extern Gfx D_09005590_3EB4C0[];

Gfx* D_E010CA10[] = { D_090054B0_3EB3E0 };

Gfx* D_E010CA14[] = { D_09004FE8_3EAF18 };

Gfx* D_E010CA18[8] = {
    D_09005590_3EB4C0, D_09005570_3EB4A0, D_09005570_3EB4A0, D_09005570_3EB4A0,
    D_09005570_3EB4A0, D_09005570_3EB4A0, D_09005570_3EB4A0, D_09005570_3EB4A0
};

Gfx* D_E010CA38[8] = {
    D_090050F0_3EB020, D_09005168_3EB098, D_090051E0_3EB110, D_09005258_3EB188,
    D_090052D0_3EB200, D_09005348_3EB278, D_090053C0_3EB2F0, D_09005438_3EB368
};

void peach_star_beam_init(EffectInstance* effect);
void peach_star_beam_update(EffectInstance* effect);
void peach_star_beam_render(EffectInstance* effect);
void peach_star_beam_appendGfx(void* effect);

EffectInstance* peach_star_beam_main(s32 type, f32 x, f32 y, f32 z, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    PeachStarBeamFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = peach_star_beam_init;
    bp.update = peach_star_beam_update;
    bp.renderWorld = peach_star_beam_render;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_PEACH_STAR_BEAM;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.peachStarBeam = shim_general_heap_malloc(sizeof(*data));
    ASSERT(effect->data.peachStarBeam != NULL);

    data->type = type;
    data->lifetime = 0;
    if (arg5 <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = arg5;
    }
    data->alpha = 224;
    data->pos.x = x;
    data->pos.y = y;
    data->pos.z = z;
    data->unk_3C = 255;
    data->unk_38 = arg4;
    data->unk_48 = 80.0f;
    data->unk_58 = 50.0f;
    data->primR = 255;
    data->primG = 255;
    data->primB = 120;
    data->envR = 255;
    data->envG = 255;
    data->envB = 255;
    data->envA = 255;
    data->unk_40 = 5.0f;
    data->unk_44 = 0;
    data->unk_4C = x;
    data->unk_50 = y + 50.0f;
    data->unk_54 = z;

    for (i = 0; i < ARRAY_COUNT(data->parts); i++) {
        PeachStarBeamInner* part = &data->parts[i];

        if (type == 0 && i == 0) {
            part->flags = 0;
        } else {
            part->flags = 1;
        }
    }
    return effect;
}

void peach_star_beam_init(EffectInstance* effect) {
}

void peach_star_beam_update(EffectInstance* effect) {
    PeachStarBeamFXData* data = effect->data.peachStarBeam;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 angle;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->timeLeft = 16;
    }

    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifetime++;
    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }

    data->unk_44 += data->unk_40;
    unk_44 = data->unk_44;
    unk_48 = data->unk_48;
    unk_4C = data->unk_4C;
    unk_50 = data->unk_50;
    unk_54 = data->unk_54;

    for (i = 0; i < ARRAY_COUNT(data->parts); i++) {
        PeachStarBeamInner* part = &data->parts[i];

        if (i == 0) {
            part->unk_04.x = unk_4C;
            part->unk_04.y = unk_50 + data->unk_58;
            part->unk_04.z = unk_54;
        } else {
            angle = unk_44 + ((-360 + (360 * i)) / 7);
            part->unk_04.x = unk_4C + (unk_48 * shim_sin_deg(angle));
            part->unk_04.y = unk_50;
            part->unk_04.z = unk_54 + (unk_48 * shim_cos_deg(angle));
        }
        if (!(part->flags & 2)) {
            part->unk_10.x = part->unk_04.x;
            part->unk_10.y = part->unk_04.y;
            part->unk_10.z = part->unk_04.z;
        }
    }
}

void peach_star_beam_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = peach_star_beam_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void peach_star_beam_appendGfx(void* effect) {
    Matrix4f sp20, sp60;
    Camera* camera = &gCameras[gCurrentCameraID];
    PeachStarBeamFXData* data = ((EffectInstance*)effect)->data.peachStarBeam;
    PeachStarBeamInner* part;
    s32 alpha = data->alpha;
    f32 partX, partY, partZ;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x9, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMasterGfxPos++, D_09005090_3EAFC0);

    for (i = 0; i < ARRAY_COUNT(data->parts); i++) {
        part = &data->parts[i];
        if (part->flags & 1) {
            if (part->flags & 2) {
                partX = part->unk_10.x;
                partY = part->unk_10.y;
                partZ = part->unk_10.z;
            } else {
                partX = part->unk_04.x;
                partY = part->unk_04.y;
                partZ = part->unk_04.z;
            }

            if (!(data->pos.z < partZ)) {
                shim_guPositionF(sp20, 0.0f, 0.0f, 0.0f, SPRITE_WORLD_SCALE_F, partX, partY, partZ);
                shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

                gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                          G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPSetPrimColor(gMasterGfxPos++, 0, 0, 128, 128, 128, 255);
                gDPSetEnvColor(gMasterGfxPos++, 128, 128, 128, 127);
                gSPDisplayList(gMasterGfxPos++, D_E010CA38[i]);
                gSPDisplayList(gMasterGfxPos++, D_E010CA18[i]);
                gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            }
        }
    }

    shim_guTranslateF(sp20, data->pos.x, data->pos.y - (((f32) (255 - data->unk_3C) * 400.0) / 255.0), data->pos.z);
    shim_guScaleF(sp60, data->unk_38 * 0.4, data->unk_38 * 0.4, data->unk_38 * 0.4);
    shim_guMtxCatF(sp60, sp20, sp20);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->primR, data->primG, data->primB, alpha);
    gDPSetEnvColor(gMasterGfxPos++, data->envR, data->envG, data->envB, data->envA);
    gSPDisplayList(gMasterGfxPos++, D_E010CA14[0]);
    gSPDisplayList(gMasterGfxPos++, D_E010CA10[0]);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_09005090_3EAFC0);

    for (i = 0; i < ARRAY_COUNT(data->parts); i++) {
        part = &data->parts[i];

        if (part->flags & 1) {
            if (part->flags & 2) {
                partX = part->unk_10.x;
                partY = part->unk_10.y;
                partZ = part->unk_10.z;
            } else {
                partX = part->unk_04.x;
                partY = part->unk_04.y;
                partZ = part->unk_04.z;
            }

            if (!(partZ <= data->pos.z)) {
                shim_guPositionF(sp20, 0.0f, 0.0f, 0.0f, 0.67f, partX, partY, partZ);
                shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

                gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                          G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPSetPrimColor(gMasterGfxPos++, 0, 0, 128, 128, 128, 255);
                gDPSetEnvColor(gMasterGfxPos++, 128, 128, 128, 127);
                gSPDisplayList(gMasterGfxPos++, D_E010CA38[i]);
                gSPDisplayList(gMasterGfxPos++, D_E010CA18[i]);
                gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            }
        }
    }
}
