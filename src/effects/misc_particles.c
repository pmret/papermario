#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001580_3E03E0[];
extern Gfx D_09001670_3E04D0[];
extern Gfx D_09001768_3E05C8[];
extern Gfx D_09001818_3E0678[];
extern Gfx D_09001A20_3E0880[];
extern Gfx D_09001A40_3E08A0[];
extern Gfx D_09001A60_3E08C0[];
extern Gfx D_09001A80_3E08E0[];

Gfx* D_E00E4D90[] = {
    D_09001A20_3E0880, D_09001A40_3E08A0, D_09001A60_3E08C0,
    D_09001A60_3E08C0, D_09001A80_3E08E0, D_09001A80_3E08E0
};

Gfx* D_E00E4DA8[] = {
    D_09001580_3E03E0, D_09001670_3E04D0, D_09001768_3E05C8,
    D_09001768_3E05C8, D_09001818_3E0678, D_09001818_3E0678
};

u8 D_E00E4DC0[] = {
    0x02, 0x04, 0x08, 0x0D, 0x0F, 0x0D, 0x09, 0x06, 0x04, 0x03,
    0x02, 0x04, 0x08, 0x0D, 0x0F, 0x0D, 0x09, 0x06, 0x04, 0x03,
    0x02, 0x04, 0x08, 0x0D, 0x0F, 0x0D, 0x09, 0x06, 0x04, 0x03
};

u8 D_E00E4DE0[] = {
    0x28, 0x5A, 0x51, 0x48, 0x41, 0x3B, 0x35, 0x2F, 0x2B, 0x26,
    0x22, 0x1F, 0x1C, 0x19, 0x16, 0x14, 0x12, 0x10, 0x0F, 0x0D,
    0x0C, 0x0A, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x05, 0x04
};

u8 D_E00E4E00[] = {
    0xC8, 0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0xC8
};

void misc_particles_init(EffectInstance* effect);
void misc_particles_update(EffectInstance* effect);
void misc_particles_render(EffectInstance* effect);
void misc_particles_appendGfx(void* effect);

EffectInstance* misc_particles_main(
    s32 variation,
    f32 posX,
    f32 posY,
    f32 posZ,
    f32 scaleX,
    f32 scaleY,
    f32 arg6,
    s32 numParticles,
    s32 duration
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    MiscParticlesFXData* part;
    f32 interval;
    s32 i;

    numParticles++;

    bp.init = misc_particles_init;
    bp.update = misc_particles_update;
    bp.renderWorld = misc_particles_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_MISC_PARTICLES;

    effect = create_effect_instance(&bp);
    effect->numParts = numParticles;
    part = effect->data.miscParticles = general_heap_malloc(numParticles * sizeof(*part));
    ASSERT(effect->data.miscParticles != NULL);

    part->variation = variation;
    part->lifetime = 0;
    if (duration <= 0) {
        part->timeLeft = 1000;
    } else {
        part->timeLeft = duration;
    }
    part->innerColor.a = 255;
    part->pos.x = posX;
    part->pos.y = posY;
    part->pos.z = posZ;
    part->scale = arg6;
    part->scaleX = scaleX;
    part->scaleY = scaleY;
    part->innerColor.r = 255;
    part->innerColor.g = 255;
    part->innerColor.b = 255;

    switch (variation) {
        case 0:
            part->glowColor.r = 255;
            part->glowColor.g = 255;
            part->glowColor.b = 255;
            part->glowColor.a = 255;
            break;
        case 1:
            part->glowColor.r = 0;
            part->glowColor.g = 127;
            part->glowColor.b = 255;
            part->glowColor.a = 255;
            break;
        case 2:
        case 3:
            part->glowColor.r = 255;
            part->glowColor.g = 255;
            part->glowColor.b = 128;
            part->glowColor.a = 255;
            break;
        default:
            part->innerColor.r = rand_int(127) + 128;
            part->innerColor.g = rand_int(255 - part->innerColor.r) + 128;
            part->innerColor.b = rand_int(383 - part->innerColor.r - part->innerColor.g) + 128;
            part->glowColor.r = 127;
            part->glowColor.g = 127;
            part->glowColor.b = 127;
            part->glowColor.a = 127;
            break;
    }

    // determine delay for particles to appear
    if (part->timeLeft < 30) {
        interval = (f32) part->timeLeft / (numParticles - 1);
    } else {
        interval = 30.0f / (numParticles - 1);
    }

    // skip delay for first particle
    part++;

    // set initial delay for each particle after the first
    for (i = 1; i < numParticles; i++, part++) {
        part->animTime = (s32)(-1.0f * i * interval) - 1;
    }

    return effect;
}

void misc_particles_init(EffectInstance* effect) {
}

void misc_particles_update(EffectInstance* effect) {
    MiscParticlesFXData* particle = effect->data.miscParticles;
    s32 variation = particle->variation;
    f32 scaleX;
    f32 scaleY;
    f32 posX;
    f32 posY;
    f32 posZ;
    s32 timeLeft;
    s32 innerColorR;
    s32 innerColorG;
    s32 innerColorB;
    f32 temp_sin;
    f32 temp_cos;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        particle->timeLeft = 16;
    }

    if (particle->timeLeft < 1000) {
        particle->timeLeft--;
    }

    particle->lifetime++;

    if (particle->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    timeLeft = particle->timeLeft;

    if (particle->timeLeft < 8) {
        particle->innerColor.a = particle->timeLeft * 32;
    }

    scaleX = particle->scaleX;
    scaleY = particle->scaleY;
    posX = particle->pos.x;
    posY = particle->pos.y;
    posZ = particle->pos.z;
    temp_cos = cos_deg(gCameras[gCurrentCameraID].curYaw);
    temp_sin = sin_deg(gCameras[gCurrentCameraID].curYaw);
    innerColorR = particle->innerColor.r;
    innerColorG = particle->innerColor.g;
    innerColorB = particle->innerColor.b;

    particle++;
    for (i = 1; i < effect->numParts; i++, particle++) {
        particle->animTime++;
        if (particle->animTime >= 30) {
            if (timeLeft < 30) {
                // perform final fadeout
                particle->animTime = 20;
            } else {
                // recycle the particle
                particle->animTime = 0;
            }
        }

        if (particle->animTime >= 0) {
            if (particle->animTime == 0) {
                f32 randMag = rand_int(scaleX) - scaleX * 0.5;
                particle->pos.x = posX + randMag * temp_cos - temp_sin;
                particle->pos.y = posY + rand_int(scaleY);
                particle->pos.z = posZ + randMag * temp_sin + temp_cos;
                particle->innerColor.r = innerColorR;
                particle->innerColor.g = innerColorG;
                particle->innerColor.b = innerColorB;
            }

            switch (variation) {
                case 0:
                case 1:
                    if (particle->animTime == 0) {
                        particle->unk_18 = 0.0f;
                        particle->unk_1C = 0.0f;
                        particle->unk_24 = 0.0f;
                        particle->unk_28 = (f32) (-rand_int(10) - 2) * 0.05;
                        particle->unk_5C = 0.0f;
                        particle->unk_60 = 0.0f;
                        particle->scale = (f32) rand_int(10) * 0.05 + 0.5;
                    }
                    particle->innerColor.a = D_E00E4E00[particle->animTime];
                    particle->pos.x += particle->unk_18;
                    particle->pos.y += particle->unk_1C;
                    particle->unk_5C += 0.2;
                    particle->unk_60 += 0.6;
                    particle->unk_18 += (particle->unk_24 - particle->unk_18) * 0.04;
                    particle->unk_1C += (particle->unk_28 - particle->unk_1C) * 0.04;
                    break;
                case 2:
                case 3:
                    if (particle->animTime == 0) {
                        if (variation == 2) {
                            particle->unk_18 = (f32) (rand_int(20) - 10) * 0.05;
                            particle->unk_1C = (f32) (rand_int(20) - 10) * 0.05;
                        } else {
                            particle->unk_18 = 0.0f;
                            particle->unk_1C = 0.0f;
                        }
                        particle->unk_24 = 0.0f;
                        particle->unk_28 = 0.0f;
                        particle->unk_5C = rand_int(15);
                        particle->unk_60 = rand_int(15);
                        particle->innerColor.a = 255;
                    }
                    particle->scale = (f32) D_E00E4DC0[particle->animTime] * 0.1;
                    particle->pos.x += particle->unk_18;
                    particle->pos.y += particle->unk_1C;
                    particle->unk_5C += 0.2;
                    particle->unk_60 += 0.6;
                    particle->unk_18 += (particle->unk_24 - particle->unk_18) * 0.04;
                    particle->unk_1C += (particle->unk_28 - particle->unk_1C) * 0.04;
                    break;
                default:
                    if (particle->animTime == 0) {
                        particle->unk_5C = 0.0f;
                        particle->unk_60 = 0.0f;
                        particle->innerColor.a = 255;
                        particle->scale = 1.0f;
                        particle->innerColor.r = rand_int(127) + 128;
                        particle->innerColor.g = rand_int(255 - particle->innerColor.r) + 128;
                        particle->innerColor.b = rand_int(383 - particle->innerColor.r - particle->innerColor.g) + 128;
                    }
                    if (variation == 4) {
                        particle->scale = (f32) D_E00E4DE0[particle->animTime] * 0.01;
                    } else {
                        particle->scale = (f32) D_E00E4DC0[particle->animTime] * 0.01;
                    }
                    break;
            }
        }
    }
}

void misc_particles_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = misc_particles_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 7;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00E4954(void) {
}

void misc_particles_appendGfx(void* effect) {
    MiscParticlesFXData* particle = ((EffectInstance*)effect)->data.miscParticles;
    s32 variation = particle->variation;
    f32 alphaScale = (particle->innerColor.a / 255.0f) * particle->scale;
    Matrix4f mtxTransform;
    Matrix4f unused;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gDPSetEnvColor(gMainGfxPos++, particle->glowColor.r, particle->glowColor.g, particle->glowColor.b, particle->glowColor.a);
    gSPDisplayList(gMainGfxPos++, D_E00E4DA8[variation]);

    particle++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, particle++) {
        if (particle->animTime >= 0) {
            guPositionF(mtxTransform, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, particle->scale * alphaScale, particle->pos.x, particle->pos.y, particle->pos.z);
            guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 80 - particle->animTime, particle->innerColor.r, particle->innerColor.g, particle->innerColor.b, alphaScale * particle->innerColor.a);
            gDPSetTileSize(gMainGfxPos++, 1,
                (s32) particle->unk_5C * 4,
                (s32) particle->unk_60 * 4,
                ((s32) particle->unk_5C + 15) * 4,
                ((s32) particle->unk_60 + 15) * 4);

            if (variation == 2) {
                gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE,
                    ((i & 0x1F) * 32     ) * 4, 31 * 4,
                    ((i & 0x1F) * 32 + 31) * 4, 31 * 4);
            }

            gSPDisplayList(gMainGfxPos++, D_E00E4D90[variation]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
}
