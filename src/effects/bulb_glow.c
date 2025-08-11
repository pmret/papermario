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
    { 255, 255, 255 },
    { 255, 255, 128 },
    { 255, 128, 255 },
    { 128, 255, 255 },
    { 255, 128, 128 },
    { 128, 255, 128 },
    { 128, 128, 255 },
};

void bulb_glow_init(EffectInstance* effect);
void bulb_glow_update(EffectInstance* effect);
void bulb_glow_render(EffectInstance* effect);
void bulb_glow_appendGfx(void* effect);

void bulb_glow_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, EffectInstance** outEffect) {
    EffectBlueprint bp;
    EffectInstance* effect;
    BulbGlowFXData* data;
    s32 numParts = 1;

    bp.init = bulb_glow_init;
    bp.update = bulb_glow_update;
    bp.renderScene = bulb_glow_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_BULB_GLOW;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.bulbGlow = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.bulbGlow != nullptr);

    data->type = arg0 & 255;
    if (arg0 < 256) {
        data->timeLeft = 100;
    } else {
        data->timeLeft = 80;
    }
    data->lifetime = 0;
    data->brightness = 127;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->depthQueryID = D_E00789A8;

    D_E00789A8++;
    if (D_E00789A8 >= 16) {
        D_E00789A8 = 0;
    }

    data->unk_20 = rand_int(7);
    *outEffect = effect;
}

void bulb_glow_init(EffectInstance* effect) {
}

void bulb_glow_update(EffectInstance* effect) {
    BulbGlowFXData* data = effect->data.bulbGlow;
    s32 time;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->timeLeft = 10;
    }

    data->lifetime++;

    if (data->timeLeft < 100) {
        data->timeLeft--;
    }
    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = data->lifetime;
    if (data->type == 0) {
        if (time < 11) {
            data->brightness = (time * 6) + 4;
        } else {
            data->brightness = 64;
        }

        if (time & 1) {
            data->brightness *= 0.6;
        }

        if (time >= 15) {
            data->type = 4;
            data->brightness = 127;
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
    if (data->type == 5) {
        renderTask.dist = 0;
        renderTaskPtr->renderMode = RENDER_MODE_SURFACE_OPA;
    } else {
        renderTask.dist = -100;
        renderTaskPtr->renderMode = RENDER_MODE_CLOUD_NO_ZCMP;
    }

    retTask = queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E0078274(void) {
}

#define TMEM_ADDR(x) (x / sizeof(u64))

void bulb_glow_appendGfx(void* effect) {
    BulbGlowFXData* data = ((EffectInstance*)effect)->data.bulbGlow;
    f32 centerX;
    f32 centerY;
    s32 xMin;
    s32 numRects;
    s32 yMin;
    s32 type;
    s32 rectHeight;
    s32 glowExtent;
    s32 colorScale;
    s32 brightness;
    s32 yMax;
    s32 xStart;
    s32 xMax;
    s32 isPointVisible;
    s32 yStart;
    UnkBulbGlow* temp_s1;
    Color_RGB8* color;
    s32 i;
    s32 j;
    u8 r, g, b;

    brightness = data->brightness;
    type = data->type;
    if (brightness > 127) {
        brightness = 127;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    temp_s1 = &D_E0078918[type];
    glowExtent = temp_s1->unk_10;
    rectHeight = temp_s1->unk_14;

    isPointVisible = is_point_visible(data->pos.x, data->pos.y, data->pos.z, data->depthQueryID, &centerX, &centerY);

    if (type == 5) {
        isPointVisible = true;
    }

    if (!isPointVisible || centerX < 0.0f || centerY < 0.0f || centerX >= SCREEN_WIDTH || centerY >= SCREEN_HEIGHT) {
        return;
    }

    gSPDisplayList(gMainGfxPos++, D_E0078900[type]);
    color = &D_E00789AC[data->unk_20];
    colorScale = brightness * 2;
    r = color->r * colorScale / 255;
    g = color->g * colorScale / 255;
    b = color->b * colorScale / 255;

    gDPSetPrimColor(gMainGfxPos++, 0, 0, r, g, b, 127);

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

    for (i = yStart / rectHeight; i < numRects; i++) {
        s32 y = yMin + i * rectHeight;
        if (y + rectHeight >= SCREEN_HEIGHT) {
            break;
        }

        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE,
            (s32) (xMin * temp_s1->unk_08) * 4,
            (s32) (temp_s1->unk_04 * 20 - i * temp_s1->unk_14 * temp_s1->unk_0C) * 4,
            (s32) (xMin * temp_s1->unk_08 + temp_s1->unk_00) * 4,
            (s32) (temp_s1->unk_04 * 21 - i * temp_s1->unk_14 * temp_s1->unk_0C) * 4);

        for (j = 0; j < 1; j++) {
            gDPLoadMultiTile(gMainGfxPos++,
                VIRTUAL_TO_PHYSICAL(nuGfxCfb_ptr + y * SCREEN_WIDTH),
                TMEM_ADDR(TMEM_SIZE/2), G_TX_RENDERTILE + 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0,
                xMin + xStart, 0, xMax - 1, rectHeight - 1,
                0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 9, 8, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gMainGfxPos++,
                (xMin + xStart) * 4, y * 4,
                xMax * 4, (y + rectHeight) * 4,
                G_TX_RENDERTILE,
                ((xMin + xStart) & 0x1FF) << 5, 0,
                1 << 10, 1 << 10);
            gDPPipeSync(gMainGfxPos++);
        }
    }
}
