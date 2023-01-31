#include "common.h"
#include "nu/nusys.h"
#include "effects_internal.h"

typedef struct UnkBulbGlow {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} UnkBulbGlow; // size = 0x18

extern Gfx D_09001400_37C1D0[];
extern Gfx D_090014B8_37C288[];
extern Gfx D_09001570_37C340[];
extern Gfx D_09001618_37C3E8[];
extern Gfx D_090016C0_37C490[];

Gfx* D_E0078900[] = {
    D_09001400_37C1D0, D_090014B8_37C288, D_09001570_37C340, D_09001618_37C3E8, D_090016C0_37C490, D_09001570_37C340
};

UnkBulbGlow D_E0078918[] = {
    { 0x00000080, 0x00000080, 0.5f, 0.5f, 0x00000040, 0x00000004 },
    { 0x00000040, 0x00000040, 2.0f, 2.0f, 0x00000020, 0x00000010 },
    { 0x00000040, 0x00000040, 1.0f, 1.0f, 0x00000040, 0x00000008 },
    { 0x00000040, 0x00000040, 2.0f, 2.0f, 0x00000010, 0x00000010 },
    { 0x00000040, 0x00000040, 1.0f, 1.0f, 0x00000020, 0x00000010 },
    { 0x00000040, 0x00000040, 1.0f, 1.0f, 0x00000040, 0x00000008 },
};

s32 D_E00789A8 = 0;

u8 D_E00789AC[] = {
    255, 255, 255,
    255, 255, 128,
    255, 128, 255,
    128, 255, 255,
    255, 128, 128,
    128, 255, 128,
    128, 128, 255,
};

void bulb_glow_init(EffectInstance* effect);
void bulb_glow_update(EffectInstance* effect);
void bulb_glow_render(EffectInstance* effect);
void bulb_glow_appendGfx(void* effect);

void bulb_glow_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, EffectInstance** outEffect) {
    EffectBlueprint bp;
    EffectInstance* effect;
    BulbGlowFXData* data;
    s32 numParts = 1;

    bp.init = bulb_glow_init;
    bp.update = bulb_glow_update;
    bp.renderWorld = bulb_glow_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_BULB_GLOW;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.bulbGlow = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.bulbGlow != NULL);

    data->unk_00 = arg0 & 255;
    if (arg0 < 256) {
        data->unk_14 = 100;
    } else {
        data->unk_14 = 80;
    }
    data->unk_18 = 0;
    data->unk_10 = 127;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->unk_1C = D_E00789A8;

    D_E00789A8++;
    if (D_E00789A8 >= 16) {
        D_E00789A8 = 0;
    }

    data->unk_20 = shim_rand_int(7);
    *outEffect = effect;
}

void bulb_glow_init(EffectInstance* effect) {
}

void bulb_glow_update(EffectInstance* effect) {
    BulbGlowFXData* data = effect->data.bulbGlow;
    s32 unk18;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_14 = 10;
    }

    data->unk_18++;

    if (data->unk_14 < 100) {
        data->unk_14--;
    }
    if (data->unk_14 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk18 = data->unk_18;
    if (data->unk_00 == 0) {
        if (unk18 < 11) {
            data->unk_10 = (unk18 * 6) + 4;
        } else {
            data->unk_10 = 64;
        }

        if (unk18 & 1) {
            data->unk_10 *= 0.6;
        }

        if (unk18 >= 15) {
            data->unk_00 = 4;
            data->unk_10 = 127;
        }
    }
}

void bulb_glow_render(EffectInstance* effect) {
    BulbGlowFXData* data = effect->data.bulbGlow;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = bulb_glow_appendGfx;
    if (data->unk_00 == 5) {
        renderTask.distance = 0;
        renderTaskPtr->renderMode = RENDER_MODE_SURFACE_OPA;
    } else {
        renderTask.distance = -100;
        renderTaskPtr->renderMode = RENDER_MODE_2D;
    }

    retTask = shim_queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E0078274(void) {
}

// wip
#ifdef WIP
void bulb_glow_appendGfx(void* effect) {
    f32 sp18;
    f32 sp1C;
    s32 sp20;
    s32 sp28;
    s32 sp30;
    BulbGlowFXData* data = ((EffectInstance*) effect)->data.bulbGlow;
    s32 unk_10;
    s32 unk_00;
    UnkBulbGlow* temp_s1;
    s32 temp_s3;
    s32 temp_s6;
    s32 i;
    s32 j;

    f32 temp_f0;
    f32 temp_f4;
    s32 temp_a0_2;
    s32 temp_f6;
    s32 temp_lo;
    s32 temp_s0_2;
    s32 temp_s2_2;
    s32 temp_t0;
    s32 temp_t5;
    s32 var_t2;
    s32 var_t4;
    s32 var_t5;
    s32 var_t7;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_t6;
    u8* temp_v0;


    unk_10 = data->unk_10;
    unk_00 = data->unk_00;
    if (unk_10 > 127) {
        unk_10 = 127;
    }

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    temp_s1 = &D_E0078918[unk_00];
    temp_s6 = temp_s1->unk_10;
    temp_s3 = temp_s1->unk_14;

    var_v1 = shim_func_8011CFBC(data->pos.x, data->pos.y, data->pos.z, data->unk_1C, &sp18, &sp1C);
    if (unk_00 == 5) {
        var_v1 = 1;
    }
    if ((var_v1 != 0) && !(sp18 < 0.0f) && !(sp1C < 0.0f) && !(sp18 >= 320.0f) && !(sp1C >= 240.0f)) {
        u8 r, g, b;

        gSPDisplayList(gMasterGfxPos++, D_E0078900[unk_00]);

        temp_v0 = &D_E00789AC[data->unk_20 * 3];
        temp_t0 = unk_10 * 2;

        r = temp_v0[0] * temp_t0 / 255;
        g = temp_v0[1] * temp_t0 / 255;
        b = temp_v0[2] * temp_t0 / 255;

        gDPSetPrimColor(gMasterGfxPos++, 0, 0, r, g, b, 127);

        sp20 = sp18 - temp_s6;
        var_t7 = sp20 + temp_s6 * 2;
        temp_f6 = sp1C - temp_s6;
        var_t4 = temp_f6 + temp_s6 * 2;

        var_t5 = 0;
        if (sp20 < 0) {
            var_t5 = -sp20;
        }
        var_v1_2 = 0;
        if (temp_f6 < 0) {
            var_v1_2 = -temp_f6;
        }
        if (var_t7 > 320) {
            var_t7 = 319;
        }
        if (var_t4 > 240) {
            var_t4 = 239;
        }
        temp_lo = (s32) (var_t4 - temp_f6) / temp_s3;

        for (i = var_v1_2 / temp_s3; i < temp_lo; i++) {
            if ((i + 1) * temp_s3 + temp_f6 >= 240) {
                break;
            }

            gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE,
                (s32) (sp20 * temp_s1->unk_08) * 4,
                (s32) (temp_s1->unk_04 * 0x14 - i * temp_s1->unk_14 * temp_s1->unk_0C) * 4,
                (s32) (sp20 * temp_s1->unk_08 + temp_s1->unk_00) * 4,
                (s32) (temp_s1->unk_04 * 0x15 - i * temp_s1->unk_14 * temp_s1->unk_0C) * 4);

            for (j = 0; j < 1; j++) {
                gDPLoadMultiTile(gMasterGfxPos++, VIRTUAL_TO_PHYSICAL(nuGfxCfb_ptr + (i * temp_s3 + temp_f6) * 0x280),
                    0x0100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0, sp20 + var_t5, 0, var_t7 - 1, temp_s3 - 1,
                    0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 9, 8, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gMasterGfxPos++, (sp20 + var_t5) * 4, (i * temp_s3 + temp_f6) * 4, var_t7 * 4, ((i + 1) * temp_s3 + temp_f6) * 4, G_TX_RENDERTILE, sp20 + var_t5, 0, 0x0400, 0x0400);
                gDPPipeSync(gMasterGfxPos++);
            }
        }
    }
}

#else
INCLUDE_ASM(s32, "effects/bulb_glow", bulb_glow_appendGfx);
#endif

