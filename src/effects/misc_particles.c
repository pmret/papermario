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
    0x02, 0x04, 0x08, 0x0D, 0x0F, 0x0D, 0x09, 0x06, 0x04, 0x03, 0x02, 0x04, 0x08, 0x0D, 0x0F, 0x0D, 0x09, 0x06, 0x04, 0x03, 0x02, 0x04, 0x08, 0x0D, 0x0F, 0x0D, 0x09, 0x06, 0x04, 0x03, 0x00, 0x00
};

u8 D_E00E4DE0[] = {
    0x28, 0x5A, 0x51, 0x48, 0x41, 0x3B, 0x35, 0x2F, 0x2B, 0x26, 0x22, 0x1F, 0x1C, 0x19, 0x16, 0x14, 0x12, 0x10, 0x0F, 0x0D, 0x0C, 0x0A, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x05, 0x04, 0x00, 0x00
};

u8 D_E00E4E00[] = {
    0xC8, 0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0xC8, 0x00, 0x00
};

void misc_particles_init(EffectInstance* effect);
void misc_particles_update(EffectInstance* effect);
void misc_particles_render(EffectInstance* effect);
void misc_particles_appendGfx(void* effect);

EffectInstance* misc_particles_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    f32 arg6,
    s32 arg7,
    s32 arg8
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    MiscParticlesFXData* part;
    f32 temp;
    s32 i;

    arg7++;

    bp.init = misc_particles_init;
    bp.update = misc_particles_update;
    bp.renderWorld = misc_particles_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_MISC_PARTICLES;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = arg7;
    part = effect->data.miscParticles = shim_general_heap_malloc(arg7 * sizeof(*part));
    ASSERT(effect->data.miscParticles != NULL);

    part->unk_00 = arg0;
    part->unk_34 = 0;
    if (arg8 <= 0) {
        part->unk_30 = 1000;
    } else {
        part->unk_30 = arg8;
    }
    part->unk_44 = 255;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->unk_58 = arg6;
    part->scaleX = arg4;
    part->scaleY = arg5;
    part->unk_38 = 255;
    part->unk_3C = 255;
    part->unk_40 = 255;

    switch (arg0) {
        case 0:
            part->unk_48 = 255;
            part->unk_4C = 255;
            part->unk_50 = 255;
            part->unk_54 = 255;
            break;
        case 1:
            part->unk_48 = 0;
            part->unk_4C = 127;
            part->unk_50 = 255;
            part->unk_54 = 255;
            break;
        case 2:
        case 3:
            part->unk_48 = 255;
            part->unk_4C = 255;
            part->unk_50 = 128;
            part->unk_54 = 255;
            break;
        default:
            part->unk_38 = shim_rand_int(127) + 128;
            part->unk_3C = shim_rand_int(255 - part->unk_38) + 128;
            part->unk_40 = shim_rand_int(383 - part->unk_38 - part->unk_3C) + 128;
            part->unk_48 = 127;
            part->unk_4C = 127;
            part->unk_50 = 127;
            part->unk_54 = 127;
            break;
    }

    if (part->unk_30 < 30) {
        temp = (f32) part->unk_30 / (arg7 - 1);
    } else {
        temp = 30.0f / (arg7 - 1);
    }

    part++;
    for (i = 1; i < arg7; i++, part++) {
        s32 temp_f0 = -(f32) i * temp;
        part->unk_2C = temp_f0 - 1;
    }

    return effect;
}

void misc_particles_init(EffectInstance* effect) {
}

void misc_particles_update(EffectInstance* effect) {
    MiscParticlesFXData* part = ((EffectInstance*)effect)->data.miscParticles;
    s32 unk_00 = part->unk_00;
    f32 scaleX;
    f32 scaleY;
    f32 posX;
    f32 posY;
    f32 posZ;
    s32 unk_30;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    f32 temp_sin;
    f32 temp_cos;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        part->unk_30 = 16;
    }

    if (part->unk_30 < 1000) {
        part->unk_30--;
    }

    part->unk_34++;

    if (part->unk_30 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_30 = part->unk_30;

    if (unk_30 < 8) {
        part->unk_44 = unk_30 * 32;
    }

    scaleX = part->scaleX;
    scaleY = part->scaleY;
    posX = part->pos.x;
    posY = part->pos.y;
    posZ = part->pos.z;
    temp_cos = shim_cos_deg(gCameras[gCurrentCameraID].currentYaw);
    temp_sin = shim_sin_deg(gCameras[gCurrentCameraID].currentYaw);
    unk_38 = part->unk_38;
    unk_3C = part->unk_3C;
    unk_40 = part->unk_40;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_2C++;
        if (part->unk_2C >= 30) {
            if (unk_30 < 30) {
                part->unk_2C = 20;
            } else {
                part->unk_2C = 0;
            }
        }

        if (part->unk_2C >= 0) {
            if (part->unk_2C == 0) {
                f32 temp_f20 = shim_rand_int(scaleX) - scaleX * 0.5;
                part->pos.x = posX + temp_f20 * temp_cos - temp_sin;
                part->pos.y = posY + shim_rand_int(scaleY);
                part->pos.z = posZ + temp_f20 * temp_sin + temp_cos;
                part->unk_38 = unk_38;
                part->unk_3C = unk_3C;
                part->unk_40 = unk_40;
            }

            switch (unk_00) {
                case 0:
                case 1:
                    if (part->unk_2C == 0) {
                        part->unk_18 = 0.0f;
                        part->unk_1C = 0.0f;
                        part->unk_24 = 0.0f;
                        part->unk_28 = (f32) (-shim_rand_int(10) - 2) * 0.05;
                        part->unk_5C = 0.0f;
                        part->unk_60 = 0.0f;
                        part->unk_58 = (f32) shim_rand_int(10) * 0.05 + 0.5;
                    }
                    part->unk_44 = D_E00E4E00[part->unk_2C];
                    part->pos.x += part->unk_18;
                    part->pos.y += part->unk_1C;
                    part->unk_5C += 0.2;
                    part->unk_60 += 0.6;
                    part->unk_18 += (part->unk_24 - part->unk_18) * 0.04;
                    part->unk_1C += (part->unk_28 - part->unk_1C) * 0.04;
                    break;
                case 2:
                case 3:
                    if (part->unk_2C == 0) {
                        if (unk_00 == 2) {
                            part->unk_18 = (f32) (shim_rand_int(20) - 10) * 0.05;
                            part->unk_1C = (f32) (shim_rand_int(20) - 10) * 0.05;
                        } else {
                            part->unk_18 = 0.0f;
                            part->unk_1C = 0.0f;
                        }
                        part->unk_24 = 0.0f;
                        part->unk_28 = 0.0f;
                        part->unk_5C = shim_rand_int(15);
                        part->unk_60 = shim_rand_int(15);
                        part->unk_44 = 255;
                    }
                    part->unk_58 = (f32) D_E00E4DC0[part->unk_2C] * 0.1;
                    part->pos.x += part->unk_18;
                    part->pos.y += part->unk_1C;
                    part->unk_5C += 0.2;
                    part->unk_60 += 0.6;
                    part->unk_18 += (part->unk_24 - part->unk_18) * 0.04;
                    part->unk_1C += (part->unk_28 - part->unk_1C) * 0.04;
                    break;
                default:
                    if (part->unk_2C == 0) {
                        part->unk_5C = 0.0f;
                        part->unk_60 = 0.0f;
                        part->unk_44 = 255;
                        part->unk_58 = 1.0f;
                        part->unk_38 = shim_rand_int(127) + 128;
                        part->unk_3C = shim_rand_int(255 - part->unk_38) + 128;
                        part->unk_40 = shim_rand_int(383 - part->unk_38 - part->unk_3C) + 128;
                    }
                    if (unk_00 == 4) {
                        part->unk_58 = (f32) D_E00E4DE0[part->unk_2C] * 0.01;
                    } else {
                        part->unk_58 = (f32) D_E00E4DC0[part->unk_2C] * 0.01;
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
    renderTask.distance = 7;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00E4954(void) {
}

void misc_particles_appendGfx(void* effect) {
    MiscParticlesFXData* part = ((EffectInstance*)effect)->data.miscParticles;
    s32 unk_00 = part->unk_00;
    f32 temp_f20 = (part->unk_44 / 255.0f) * part->unk_58;
    Matrix4f sp20;
    Matrix4f unused;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gDPSetEnvColor(gMasterGfxPos++, part->unk_48, part->unk_4C, part->unk_50, part->unk_54);
    gSPDisplayList(gMasterGfxPos++, D_E00E4DA8[unk_00]);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_2C >= 0) {
            shim_guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, part->unk_58 * temp_f20, part->pos.x, part->pos.y, part->pos.z);
            shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMasterGfxPos++, 0, 80 - part->unk_2C, part->unk_38, part->unk_3C, part->unk_40, temp_f20 * part->unk_44);
            gDPSetTileSize(gMasterGfxPos++, 1,
                (s32) part->unk_5C * 4,
                (s32) part->unk_60 * 4,
                ((s32) part->unk_5C + 15) * 4,
                ((s32) part->unk_60 + 15) * 4);

            if (unk_00 == 2) {
                gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE,
                    ((i & 0x1F) * 32     ) * 4, 31 * 4,
                    ((i & 0x1F) * 32 + 31) * 4, 31 * 4);
            }

            gSPDisplayList(gMasterGfxPos++, D_E00E4D90[unk_00]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }
}
