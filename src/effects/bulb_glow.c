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

Color_RGB8 D_E00789AC[] = {
    {255, 255, 255},
    {255, 255, 128},
    {255, 128, 255},
    {128, 255, 255},
    {255, 128, 128},
    {128, 255, 128},
    {128, 128, 255},
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

#define TMEM_ADDR(x) (x / sizeof(u64))

void bulb_glow_appendGfx(void* effect) {
    f32 x_center;
    f32 y_center;
    s32 x_min;
    s32 num_rects;
    s32 y_min;
    s32 temp_s2;
    s32 rect_height;
    s32 glow_extent;
    s32 color_scale;
    s32 brightness;
    s32 y_max;
    s32 x_start;
    s32 x_max;
    s32 var_v1;
    s32 y_start;
    UnkBulbGlow* temp_s1;
    Color_RGB8* temp_v0;

    BulbGlowFXData* data = ((EffectInstance*)effect)->data.bulbGlow;
    s32 i;
    s32 j;
    u8 r, g, b;

    brightness = data->unk_10;
    temp_s2 = data->unk_00;
    if (brightness > 127) {
        brightness = 127;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    temp_s1 = &D_E0078918[temp_s2];
    glow_extent = temp_s1->unk_10;
    rect_height = temp_s1->unk_14;

    var_v1 = shim_is_point_visible(data->pos.x, data->pos.y, data->pos.z, data->unk_1C, &x_center, &y_center);

    if (temp_s2 == 5) {
        var_v1 = TRUE;
    }

    if (!var_v1 || x_center < 0.0f || y_center < 0.0f || x_center >= SCREEN_WIDTH || y_center >= SCREEN_HEIGHT) {
        return;
    }

    gSPDisplayList(gMainGfxPos++, D_E0078900[temp_s2]);
    temp_v0 = &D_E00789AC[data->unk_20];
    color_scale = brightness * 2;
    r = temp_v0->r * color_scale / 255;
    g = temp_v0->g * color_scale / 255;
    b = temp_v0->b * color_scale / 255;

    gDPSetPrimColor(gMainGfxPos++, 0, 0, r, g, b, 127);

    x_min = x_center - glow_extent;
    x_max = x_min + glow_extent * 2;
    y_min = y_center - glow_extent;
    y_max = y_min + glow_extent * 2;

    x_start = 0;
    if (x_min < 0) {
        x_start = -x_min;
    }
    y_start = 0;
    if (y_min < 0) {
        y_start = -y_min;
    }
    if (x_max > SCREEN_WIDTH) {
        x_max = SCREEN_WIDTH - 1;
    }
    if (y_max > SCREEN_HEIGHT) {
        y_max = SCREEN_HEIGHT - 1;
    }

    num_rects = (y_max - y_min) / rect_height;

    for (i = y_start / rect_height; i < num_rects; i++) {
        s32 y = y_min + i * rect_height;
        if (y + rect_height >= SCREEN_HEIGHT) {
            break;
        }

        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE,
            (s32) (x_min * temp_s1->unk_08) << 2,
            (s32) (temp_s1->unk_04 * 20 - i * temp_s1->unk_14 * temp_s1->unk_0C) << 2,
            (s32) (x_min * temp_s1->unk_08 + temp_s1->unk_00) << 2,
            (s32) (temp_s1->unk_04 * 21 - i * temp_s1->unk_14 * temp_s1->unk_0C) << 2);

        for (j = 0; j < 1; j++) {
            gDPLoadMultiTile(gMainGfxPos++,
                VIRTUAL_TO_PHYSICAL(nuGfxCfb_ptr + y * SCREEN_WIDTH),
                TMEM_ADDR(TMEM_SIZE/2), G_TX_RENDERTILE + 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0,
                x_min + x_start, 0, x_max - 1, rect_height - 1,
                0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 9, 8, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gMainGfxPos++,
                (x_min + x_start) << 2, y << 2,
                x_max << 2, (y + rect_height) << 2,
                G_TX_RENDERTILE,
                ((x_min + x_start) & 0x1FF) << 5, 0,
                1 << 10, 1 << 10);
            gDPPipeSync(gMainGfxPos++);
        }
    }
}
