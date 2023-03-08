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

// wip
#ifdef WIP
void bulb_glow_appendGfx(void* effect) {
    BulbGlowFXData* data = ((EffectInstance*) effect)->data.bulbGlow; //s0
    f32 centerX;
    f32 centerY;
    s32 xMin;
    s32 numRects;
    s32 yMin;
    s32 temp_s2;
    s32 rectHeight;
    s32 glowExtent;
    s32 colorScale;
    s32 brightness;
    s32 xMax;
    s32 yMax;
    s32 xStart;
    s32 isPointVisible;
    s32 yStart;
    UnkBulbGlow* temp_s1;
    Color_RGB8* temp_v0;

    s32 i;
    s32 j;
    s32 r, g, b;

    brightness = data->unk_10;
    temp_s2 = data->unk_00;
    if (brightness > 0x7F) {
        brightness = 0x7F;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    temp_s1 = &D_E0078918[temp_s2];
    glowExtent = temp_s1->unk_10;
    rectHeight = temp_s1->unk_14;

    isPointVisible = shim_is_point_visible(data->pos.x, data->pos.y, data->pos.z, data->unk_1C, &centerX, &centerY);

    // There are 6 UnkStruct entries in the array at E0078918, so this refers to the last one
    if (temp_s2 == 5) {
        isPointVisible = TRUE;
    }

    if (!isPointVisible || centerX < 0.0f || centerY < 0.0f || centerX >= SCREEN_WIDTH || centerY >= SCREEN_HEIGHT) {
        return;
    }

    gSPDisplayList(gMainGfxPos++, D_E0078900[temp_s2]);
    temp_v0 = &D_E00789AC[data->unk_20];
    colorScale = (brightness * 2);
    r = temp_v0->r * colorScale / 255;
    g = temp_v0->g * colorScale / 255;
    b = temp_v0->b * colorScale / 255;

    gDPSetPrimColor(gMainGfxPos++, 0, 0, r, g, b, 0x7F);

    // temp_s1 = E0078948
    //   unk_00 = 64
    //   unk_04 = 64
    //   unk_08 = 1.0f
    //   unk_0C = 1.0f
    //   unk_10 = 64 (glow_extent)
    //   unk_14 = 8 (rect_height)

    // x_center = 247
    // y_center = 107
    // glow_extent = 64
    // x_min = 183
    // x_max = 311
    // y_min = 43
    // y_max = 171

    xMin = centerX - glowExtent;
    xMax = xMin + glowExtent * 2;
    yMin = centerY - glowExtent;
    yMax = yMin + glowExtent * 2;

    xStart = 0;
    if (xMin < 0) {
        xStart = -xMin;
    }
    yStart = 0;
    if (yMin < 0) {
        yStart = -yMin;
    }
    if (xMax > SCREEN_WIDTH) {
        xMax = SCREEN_WIDTH - 1;
    }
    if (yMax > SCREEN_HEIGHT) {
        yMax = SCREEN_HEIGHT - 1;
    }

    numRects = (yMax - yMin) / rectHeight;

    for (i = yStart / rectHeight; i < numRects && (i + 1) * rectHeight + yMin < SCREEN_HEIGHT; i++) {
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE,
            // uls = 183 << 2
            (s32) (xMin * temp_s1->unk_08) << 2,
            // This code is correct due to being masked to 12 bits
            // However, the wrapping may not be intended from the developer's perspective so it may be a bug
            // ult = (256 << 2, 248 << 2, 240 << 2, ...)
            (s32) (temp_s1->unk_04 * 20 - i * temp_s1->unk_14 * temp_s1->unk_0C) << 2,
            // lrs = 247 << 2
            (s32) (xMin * temp_s1->unk_08 + temp_s1->unk_00) << 2,
            // This code is correct as well, same as above
            // lrt = (320 << 2, 312 << 2, 304 << 2, ...)
            (s32) (temp_s1->unk_04 * 21 - i * temp_s1->unk_14 * temp_s1->unk_0C) << 2);

        for (j = 0; j < 1; j++) {
            gDPLoadMultiTile(gMainGfxPos++,
                // Offset the image to the rows being loaded
                VIRTUAL_TO_PHYSICAL(nuGfxCfb_ptr + (i * rectHeight + yMin) * (SCREEN_WIDTH * sizeof(u16))),
                TMEM_ADDR(TMEM_SIZE/2), G_TX_RENDERTILE + 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0,
                // uls = 183, ult = 0
                (xMin + xStart), 0,
                // lrs = 311 - 1, lrt = 8 - 1
                xMax - 1, rectHeight - 1,
                0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 9, 8, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gMainGfxPos++,
                // xl = 183 << 2, yl = (43 << 2, 51 << 2, 59 << 2, ...)
                (xMin + xStart) << 2, (i * rectHeight + yMin) << 2,
                // xr = 311 << 2, yh = (51 << 2, 59 << 2, 67 << 2, ...)
                xMax << 2, ((i + 1) * rectHeight + yMin) << 2,
                G_TX_RENDERTILE,
                // s = 183 << 5, t = 0
                ((xMin + xStart) & 0x1FF) << 5, 0,
                1 << 10, 1 << 10);
            gDPPipeSync(gMainGfxPos++);
        }
    }
}
#else
INCLUDE_ASM(s32, "effects/bulb_glow", bulb_glow_appendGfx);
#endif

