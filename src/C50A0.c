#include "common.h"
#include "effects.h"
#include "hud_element.h"
#include "pause/pause_common.h"
#include "world/partners.h"
#include "sparkle_script.h"
#include "item_entity.h"
#include "message_ids.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "sprite/player.h"

#if VERSION_IQUE
// TODO: remove if section is split in iQue release
extern Addr icon_ROM_START;
#endif

#define MAX_ITEM_ENTITIES 256

extern SparkleScript SparkleScript_Coin;

extern Gfx D_8014B870[];
extern Gfx D_8014BBD8[];
extern Lights1 D_8014C6C8;

extern HudCacheEntry* gHudElementCacheTableRaster;
extern HudCacheEntry* gHudElementCacheTablePalette;

extern u8* gHudElementCacheBuffer;
extern s32* gHudElementCacheSize;

SHIFT_BSS s32 ItemEntitiesCreated;
SHIFT_BSS s32 D_80155D80;
SHIFT_BSS s32 ItemEntityAlternatingSpawn;
SHIFT_BSS s32 ItemEntityRenderGroup;
SHIFT_BSS s16 D_80155D8C;
SHIFT_BSS s16 D_80155D8E;
SHIFT_BSS s16 D_80155D90;
SHIFT_BSS ItemEntity* WorldItemEntities[MAX_ITEM_ENTITIES];
SHIFT_BSS ItemEntity* BattleItemEntities[MAX_ITEM_ENTITIES];
SHIFT_BSS ItemEntity** gCurrentItemEntities;
SHIFT_BSS s16 isPickingUpItem;
SHIFT_BSS s16 D_801565A6;
SHIFT_BSS s16 D_801565A8; // some hack relating to kooper item pickups
SHIFT_BSS PopupMenu D_801565B0;
SHIFT_BSS s32 ItemPickupIconID;
SHIFT_BSS s32 ItemPickupStateDelay;
SHIFT_BSS s32 D_801568E8;
SHIFT_BSS s32 D_801568EC;
SHIFT_BSS EffectInstance* ItemPickupGotOutline;
SHIFT_BSS MessagePrintState* GotItemTutorialPrinter;
SHIFT_BSS b32 GotItemTutorialClosed;

void item_entity_update(ItemEntity*);
void appendGfx_item_entity(void*);
void draw_item_entities(void);
void draw_ui_item_entities(void);
s32 test_item_player_collision(ItemEntity*);
void update_item_entity_collectable(ItemEntity*);
void draw_ui_item_entity_collectable(ItemEntity*);
void update_item_entity_stationary(ItemEntity*);
void draw_ui_item_entity_stationary(ItemEntity*);
void update_item_entity_no_pickup(ItemEntity*);
void draw_ui_item_entity_no_pickup(ItemEntity*);
void func_801363A0(ItemEntity*);
void update_item_entity_pickup(ItemEntity*);
s32 draw_image_with_clipping(IMG_PTR raster, u32 width, u32 height, s32 fmt, s32 bitDepth, s16 posX, s16 posY,
                             u16 clipX, u16 clipY, u16 clipWidth, u16 clipHeight);

void draw_content_pickup_item_header(ItemEntity* item, s32 posX, s32 posY);
void draw_content_cant_carry_more(ItemEntity* item, s32 posX, s32 posY);
void draw_content_pickup_item_desc(ItemEntity* item, s32 posX, s32 posY);

Vtx D_8014C5A0[4] = {
    {{{ -12,  0, 0 }, 0, { 0x2300, 0x2300 }, { 0, 0, 0, 255 }}},
    {{{  11,  0, 0 }, 0, { 0x2000, 0x2300 }, { 0, 0, 0, 255 }}},
    {{{  11, 23, 0 }, 0, { 0x2000, 0x2000 }, { 0, 0, 0, 255 }}},
    {{{ -12, 23, 0 }, 0, { 0x2300, 0x2000 }, { 0, 0, 0, 255 }}},
};

Vtx D_8014C5E0[4] = {
    {{{ -16,  0, 0 }, 0, { 0x2400, 0x2400 }, { 0, 0, 0, 255 }}},
    {{{  15,  0, 0 }, 0, { 0x2000, 0x2400 }, { 0, 0, 0, 255 }}},
    {{{  15, 31, 0 }, 0, { 0x2000, 0x2000 }, { 0, 0, 0, 255 }}},
    {{{ -16, 31, 0 }, 0, { 0x2400, 0x2000 }, { 0, 0, 0, 255 }}},
};

Gfx D_8014C620[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsSPEndDisplayList(),
};

Gfx D_8014C678[] = {
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(D_8014C5A0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_8014C6A0[] = {
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(D_8014C5E0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Lights1 D_8014C6C8 = gdSPDefLights1(255, 255, 255, 0, 0, 0, 0, 0, 0);

s16 PickupHeaderWindowHeight[] = { 32, 40 };
s16 PickupMessageWindowYOffsets[] = { 8, 4 };

s32 draw_ci_image_with_clipping(IMG_PTR raster, s32 width, s32 height, s32 fmt, s32 bitDepth, PAL_PTR palette, s16 posX,
                                s16 posY, u16 clipULx, u16 clipULy, u16 clipLRx, u16 clipRLy, u8 opacity) {
    s32 ret;

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);

    if (opacity == 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
        gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else if (opacity == 0) {
        return 1;
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gMainGfxPos++, PM_CC_02, PM_CC_02);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, opacity);
    }

    if (fmt == G_IM_FMT_CI) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        if (bitDepth == G_IM_SIZ_4b) {
            gDPLoadTLUT_pal16(gMainGfxPos++, 0, palette);
        } else {
            gDPLoadTLUT_pal256(gMainGfxPos++, palette);
        }
    } else {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    }
    ret = draw_image_with_clipping(raster, width, height, fmt, bitDepth, posX, posY, clipULx, clipULy, clipLRx, clipRLy);
    gDPPipeSync(gMainGfxPos++);
    return ret;
}

typedef struct Rect2b {
    /* 0x00 */ s16 ulx;
    /* 0x02 */ s16 uly;
    /* 0x04 */ s16 lrx;
    /* 0x06 */ s16 lry;
} Rect2b; // size = 0x08

s32 draw_image_with_clipping(IMG_PTR raster, u32 width, u32 height, s32 fmt, s32 bitDepth,
                     s16 posX, s16 posY,
                     u16 clipX, u16 clipY,
                     u16 clipWidth, u16 clipHeight) {
    Rect2b texRect;
    Rect2b drawRect;
    u8 stopDrawing;
    u8 stopDrawingLine;
    s8 zero = 0; // required to match

    u16 texOffsetX, texOffsetY;

    if (posX >= clipX + clipWidth || posY >= clipY + clipHeight) {
        return FALSE;
    }
    if (clipX >= (s16)(posX + width)) {
        return FALSE;
    }
    if (clipY >= (s16)(posY + height)) {
        return FALSE;
    }

    texRect.uly = 0;
    drawRect.uly = posY;
    stopDrawing = FALSE;

    while (TRUE) {
        texRect.lry = texRect.uly + 31;
        drawRect.lry = drawRect.uly + 32;
        texOffsetY = 0;
        if (drawRect.lry <= clipY) {
            do {
                texRect.uly += 32;
                drawRect.uly = drawRect.lry;
                drawRect.lry += 32;
            } while (drawRect.lry < clipY);
            texRect.lry = texRect.uly + 31;
        }

        if (drawRect.uly < clipY) {
            texOffsetY = abs(posY - clipY);
            drawRect.uly = clipY;
        }

        if (drawRect.lry >= clipY + clipHeight) {
            texRect.lry = clipY + clipHeight - posY - 1;
            stopDrawing = TRUE;
            drawRect.lry = clipY + clipHeight;
        }

        if (texRect.lry + 1 >= height) {
            texRect.lry = height - 1;
            drawRect.lry = texRect.lry + posY + 1;
            stopDrawing = TRUE;
        }

        texRect.ulx = zero;
        drawRect.ulx = posX;
        stopDrawingLine = FALSE;

        while (TRUE) {
            texRect.lrx = texRect.ulx + 63;
            drawRect.lrx = drawRect.ulx + 64;
            texOffsetX = 0;

            if (drawRect.lrx <= clipX) {
                do {
                    texRect.ulx += 64;
                    drawRect.ulx = drawRect.lrx;
                    drawRect.lrx += 64;
                } while (drawRect.lrx < clipX);
                texRect.lrx = texRect.ulx + 63;
            }

            if (drawRect.ulx < clipX) {
                texOffsetX = abs(posX - clipX);
                drawRect.ulx = clipX;
            }

            if (drawRect.lrx >= clipX + clipWidth) {
                texRect.lrx = clipX + clipWidth - posX - 1;
                stopDrawingLine = TRUE;
                drawRect.lrx = clipX + clipWidth;
            }

            if (texRect.lrx + 1 >= width) {
                texRect.lrx = width - 1;
                drawRect.lrx = texRect.lrx + posX + 1;
                stopDrawingLine = TRUE;
            }

            if (bitDepth == G_IM_SIZ_4b) {
                gDPLoadTextureTile_4b(gMainGfxPos++, raster, fmt, width, height,
                                texRect.ulx, texRect.uly, texRect.lrx, texRect.lry, 0,
                                G_TX_WRAP, G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
            } else if (bitDepth == G_IM_SIZ_16b) {
                gDPLoadTextureTile(gMainGfxPos++, raster, fmt, G_IM_SIZ_16b, width, height,
                                texRect.ulx, texRect.uly, texRect.lrx, texRect.lry, 0,
                                G_TX_WRAP, G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
            } else if (bitDepth == G_IM_SIZ_8b) {
                gDPLoadTextureTile(gMainGfxPos++, raster, fmt, G_IM_SIZ_8b, width, height,
                                texRect.ulx, texRect.uly, texRect.lrx, texRect.lry, 0,
                                G_TX_WRAP, G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
            }

            gSPTextureRectangle(gMainGfxPos++, drawRect.ulx * 4, drawRect.uly * 4, drawRect.lrx * 4, drawRect.lry * 4,
                                0, texOffsetX * 32, texOffsetY * 32, 1024, 1024);

            if (stopDrawingLine) {
                break;
            }
            texRect.ulx += 64;
            drawRect.ulx = drawRect.lrx;
        }

        if (stopDrawing) {
            break;
        }
        texRect.uly += 32;
        drawRect.uly = drawRect.lry;
    }

    return TRUE;
}

s32 draw_tiled_image(IMG_PTR raster, u32 width, u32 height, u8 fmt, u8 bitDepth,
                     s16 posX, s16 posY,
                     u16 clipX, u16 clipY, u16 clipWidth, u16 clipHeight,
                     f32 scaleX, f32 scaleY) {
    Rect texRect;
    Rect drawRect;
    s32 dsdx, dtdy;
    s32 texOffsetX, texOffsetY;
    u8 stopDrawing;
    u8 stopDrawingLine;

    if (scaleX < 0.01 || scaleY < 0.01) {
        return 0;
    }

    if (posX >= clipX + clipWidth  || posY >= clipY + clipHeight) {
        return 0;
    }

    if (clipX >= (s16)(posX + width * scaleX)) {
        return 0;
    }

    if (clipY >= (s16)(posY + height * scaleY)) {
        return 0;
    }

    stopDrawing = 0;
    texRect.uly = 0;
    drawRect.uly = posY;
    dsdx = 1.0f / scaleX * 1024.0f;
    dtdy = 1.0f / scaleY * 1024.0f;
    while (TRUE) {
        texRect.lry = texRect.uly + 31;
        drawRect.lry = drawRect.uly + (scaleY * 32.0 + 0.5);
        texOffsetY = 0;
        if (drawRect.lry <= clipY) {
            do {
                texRect.uly += 32;
                drawRect.uly = drawRect.lry;
                drawRect.lry += scaleY * 32.0f;
            } while (drawRect.lry < clipY);
            texRect.lry = texRect.uly + 31;
        }

        if (drawRect.uly < clipY) {
            drawRect.uly = clipY;
            texOffsetY = abs(posY - clipY) / scaleY * 32.0f;
        }

        if ((u32)(texRect.lry + 1) >= height) {
            texRect.lry = height - 1;
            stopDrawing = 1;
            drawRect.lry = posY + (s16)(texRect.lry * scaleY);
            drawRect.lry += scaleY;
        }

        if (drawRect.lry > clipY + clipHeight) {
            drawRect.lry = clipY + clipHeight;
            if (!stopDrawing) {
                drawRect.lry = clipY + clipHeight;
                stopDrawing = 1;
            }
        }

        stopDrawingLine = 0;
        texRect.ulx = 0;
        drawRect.ulx = posX;
        while (TRUE) {
            texRect.lrx = texRect.ulx + 63;
            drawRect.lrx = drawRect.ulx + (scaleX * 64.0 + 0.3);
            texOffsetX = 0;

            if (drawRect.lrx <= clipX) {
                do {
                    texRect.ulx += 64;
                    drawRect.ulx = drawRect.lrx;
                    drawRect.lrx += scaleX * 64.0f;
                } while (drawRect.lrx < clipX);
                texRect.lrx = texRect.ulx + 63;
            }

            if (drawRect.ulx < clipX) {
                drawRect.ulx = clipX;
                texOffsetX = abs(posX - clipX) / scaleX * 32.0f;
            }

            if ((u32)(texRect.lrx + 1) >= width) {
                texRect.lrx = width - 1;
                stopDrawingLine = TRUE;
                drawRect.lrx = posX + (s16)(texRect.lrx * scaleX);
                drawRect.lrx = drawRect.lrx + scaleX + 0.3;
            }

            if (drawRect.lrx > clipX + clipWidth) {
                drawRect.lrx = clipX + clipWidth;
                stopDrawingLine = TRUE;
            }

            if (bitDepth == G_IM_SIZ_16b) {
                gDPLoadTextureTile(gMainGfxPos++, raster, fmt, G_IM_SIZ_16b, width, height,
                                texRect.ulx, texRect.uly, texRect.lrx, texRect.lry, 0,
                                G_TX_WRAP, G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
            } else if (bitDepth == G_IM_SIZ_4b) {
                gDPLoadTextureTile_4b(gMainGfxPos++, raster, fmt, width, height,
                                texRect.ulx, texRect.uly, texRect.lrx, texRect.lry, 0,
                                G_TX_WRAP, G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
            }

            gSPTextureRectangle(gMainGfxPos++, drawRect.ulx * 4, drawRect.uly * 4, (drawRect.lrx - stopDrawingLine) * 4, drawRect.lry * 4,
                                0, texOffsetX, texOffsetY, dsdx, dtdy);

            if (stopDrawingLine) {
                break;
            }
            texRect.ulx += 64;
            drawRect.ulx = drawRect.lrx;
        };

        if (stopDrawing) {
            break;
        }
        texRect.uly += 32;
        drawRect.uly = drawRect.lry;
    };

    return 1;
}

s32 integer_log(s32 number, u32 base) {
    f32 fNumber = number;
    s32 ret = 1;

    while (TRUE) {
        fNumber /= base;
        if (fNumber <= 1.0) {
            return ret;
        }

        ret++;
    }
}

s32 draw_adjustable_tiled_image(IMG_PTR raster, u32 width, u32 height, u8 fmt, u8 bitDepth,
                     s16 posX, s16 posY,
                     u16 clipX, u16 clipY, u16 clipWidth, u16 clipHeight,
                     f32 scaleX, f32 scaleY) {
    Rect texRect;
    Rect drawRect;
    u16 overlap;
    s32 dsdx, dtdy;
    s32 texOffsetX, texOffsetY;
    u8 stopDrawing;

    u16 masks, maskt;

    u16 texelNum;
    u16 lineHeight;

    f32 temp;

    if (scaleX < 0.01 || scaleY < 0.01) {
        return 0;
    }

    if (posX >= clipX + clipWidth || posY >= clipY + clipHeight) {
        return 0;
    }

    if (clipX >= (s16)(posX + width * scaleX)) {
        return 0;
    }

    if (clipY >= (s16)(posY + height * scaleY)) {
        return 0;
    }
    if (bitDepth == G_IM_SIZ_4b) {
        if (fmt == G_IM_FMT_IA || fmt == G_IM_FMT_I) {
            texelNum = 0x2000;
        } else if (fmt == G_IM_FMT_CI) {
            texelNum = 0x1000;
        } else {
            return 0;
        }
    } else if (bitDepth == G_IM_SIZ_8b) {
        if (fmt == G_IM_FMT_IA || fmt == G_IM_FMT_I) {
            texelNum = 0x1000;
        } else if (fmt == G_IM_FMT_CI) {
            texelNum = 0x800;
        } else {
            return 0;
        }
    } else if (bitDepth == G_IM_SIZ_16b) {
        if (fmt == G_IM_FMT_RGBA) {
            texelNum = 0x800;
        } else if (fmt == G_IM_FMT_IA) {
            texelNum = 0x800;
        } else {
            return 0;
        }
    } else if (bitDepth == G_IM_SIZ_32b) {
        if (fmt == G_IM_FMT_RGBA) {
            texelNum = 0x400;
        } else {
            return 0;
        }
    } else {
        return 0;
    }

    dsdx = 1.0f / scaleX * 1024.0f;
    dtdy = 1.0f / scaleY * 1024.0f;
    lineHeight = texelNum / width;
    if (lineHeight > height) {
        lineHeight = height;
    } else if (lineHeight <= 1) {
        return 0;
    }
    if (scaleY <= 1.0) {
        overlap = 0;
    } else {
        overlap = scaleY;
    }

    masks = integer_log(width, 2);
    maskt = integer_log(height, 2);

    stopDrawing = 0;

    texRect.ulx = 0;
    texRect.uly = 0;
    drawRect.ulx = posX;
    drawRect.uly = posY;

    while (TRUE) {
        texRect.lrx = width - 1;
        texRect.lry = texRect.uly + lineHeight - 1;
        drawRect.lry = drawRect.uly + lineHeight * scaleY;
        drawRect.lrx = (s16)(drawRect.ulx + width * scaleX);


        texOffsetX = texOffsetY = 0;

        if (drawRect.lry <= clipY) {
            do {
                texRect.uly += lineHeight;
                drawRect.uly = drawRect.lry;
                drawRect.lry += lineHeight * scaleY;
            } while (drawRect.lry < clipY);
            texRect.lry = texRect.uly + lineHeight - 1;
        }

        if (drawRect.uly < clipY) {
            drawRect.uly = clipY;
            temp = abs(posY - clipY);
            temp /= scaleY;
            texOffsetY = temp * 32.0f;
        }
        if (texRect.lry + 1 == height){
            stopDrawing = 1;
        } else if (height < texRect.lry + 1) {
            s32 temp;
            texRect.lry = height - 1;
            temp = height * scaleY;
            stopDrawing = 1;
            drawRect.lry = drawRect.uly + temp;
        }

        if (drawRect.lry >= clipY + clipHeight) {
            if (!stopDrawing) {
                drawRect.lry = clipY + clipHeight;
                stopDrawing = 1;
            } else if (drawRect.lry > clipY + clipHeight) {
                drawRect.lry = clipY + clipHeight;
            }
        }
        if (drawRect.ulx < clipX) {
            drawRect.ulx = clipX;
            temp = abs(posX - clipX);
            temp /= scaleX;
            texOffsetX = temp * 32.0f;
        }
        if (drawRect.lrx >= clipX + clipWidth) {
            drawRect.lrx = clipX + clipWidth;
        }

        if (bitDepth == G_IM_SIZ_4b) {
            gDPLoadTextureTile_4b(gMainGfxPos++, raster, fmt, width, height,
                                  texRect.ulx, texRect.uly, texRect.lrx, texRect.lry, 0,
                                  G_TX_WRAP, G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        } else if (bitDepth == G_IM_SIZ_8b) {
            gDPLoadTextureTile(gMainGfxPos++, raster, fmt, G_IM_SIZ_8b, width, height,
                                  texRect.ulx, texRect.uly, texRect.lrx, texRect.lry, 0,
                                  G_TX_WRAP, G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        } else if (bitDepth == G_IM_SIZ_16b) {
            gDPLoadTextureTile(gMainGfxPos++, raster, fmt, G_IM_SIZ_16b, width, height,
                                  texRect.ulx, texRect.uly, texRect.lrx, texRect.lry, 0,
                                  G_TX_WRAP, G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        } else if (bitDepth == G_IM_SIZ_32b) {
            gDPLoadTextureTile(gMainGfxPos++, raster, fmt, G_IM_SIZ_32b, width, height,
                                  texRect.ulx, texRect.uly, texRect.lrx, texRect.lry, 0,
                                  G_TX_WRAP, G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        }
        gSPTextureRectangle(gMainGfxPos++, drawRect.ulx * 4, drawRect.uly * 4, drawRect.lrx * 4, drawRect.lry * 4,
                            0, texOffsetX, texOffsetY, dsdx, dtdy);

        if (stopDrawing) {
            break;
        }

        texRect.uly += lineHeight - overlap;
        drawRect.uly = drawRect.lry - overlap * scaleY;
    };

    return 1;
}

static const f32 rodata_padding[] = { 0.0f };

void sparkle_script_init(ItemEntity* item, SparkleScript* script) {
    item->sparkleReadPos = (s32*)script;
    item->sparkleNextUpdate = 1;
    item->sparkleSavedPos = (s32*)script;
}

s32 sparkle_script_step(ItemEntity* item) {
    s32* readPos = item->sparkleReadPos;

    switch (*readPos++) {
        case SPARKLE_OP_SetGfx:
            item->sparkleNextUpdate = *readPos++;
            item->sparkleUnk44 = *readPos++;
            item->sparkleReadPos = readPos;
            break;
        case SPARKLE_OP_Restart:
            item->sparkleReadPos = item->sparkleSavedPos;
            return TRUE;
        case SPARKLE_OP_Jump:
            item->sparkleSavedPos = readPos;
            item->sparkleReadPos = readPos;
            return TRUE;
        case SPARKLE_OP_SetCI:
            item->sparkleNextUpdate = *readPos++;
            item->sparkleRaster  = (IMG_PTR)*readPos++;
            item->sparklePalette = (PAL_PTR)*readPos++;
            item->sparkleWidth = *readPos++;
            item->sparkleHeight = *readPos++;
            item->sparkleReadPos = readPos;
            break;
        case SPARKLE_OP_Break:
            readPos++; // ignore arg
            item->sparkleReadPos = readPos;
        case SPARKLE_OP_End:
            return TRUE;
    }
    return FALSE;
}

void sparkle_script_update(ItemEntity* item) {
    item->sparkleNextUpdate--;
    if (item->sparkleNextUpdate <= 0) {
        while (sparkle_script_step(item)) {}
    }
}

void draw_coin_sparkles(ItemEntity* item) {
    f32 x, y, z;
    f32 angle;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;
    ImgFXTexture ifxImg;

    x = D_80155D8C;
    y = D_80155D8E;
    z = D_80155D90;
    angle = clamp_angle(180.0f - gCameras[gCurrentCamID].curYaw);

    guTranslateF(sp18, x, y, z);
    guTranslateF(sp58, item->pos.x, item->pos.y + 12.0f, item->pos.z);
    guRotateF(sp98, angle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp18, sp98, sp98);
    guMtxCatF(sp98, sp58, spD8);
    guMtxF2L(spD8, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    gSPSetLights1(gMainGfxPos++, D_8014C6C8);
    gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
    gDPSetTextureConvert(gMainGfxPos++, G_TC_FILT);
    gDPSetCombineKey(gMainGfxPos++, G_CK_NONE);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);

    ifxImg.raster = item->sparkleRaster;
    ifxImg.palette = item->sparklePalette;
    ifxImg.width = item->sparkleWidth;
    ifxImg.height = item->sparkleHeight;
    ifxImg.xOffset = -item->sparkleWidth / 2;
    ifxImg.yOffset = item->sparkleHeight / 2;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, 0, spD8);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}

ItemEntity* get_item_entity(s32 itemEntityIndex) {
    return gCurrentItemEntities[itemEntityIndex];
}

void hide_item_entity(ItemEntity* item) {
    Shadow* shadow;

    item->flags |= ITEM_ENTITY_FLAG_HIDDEN;
    if (item->shadowIndex >= 0) {
        shadow = get_shadow_by_index(item->shadowIndex);
        shadow->flags |= ENTITY_FLAG_HIDDEN;
    }
}

void reveal_item_entity(ItemEntity* item) {
    Shadow* shadow;

    item->flags &= ~ITEM_ENTITY_FLAG_HIDDEN;
    if (item->shadowIndex >= 0) {
        shadow = get_shadow_by_index(item->shadowIndex);
        shadow->flags &= ~ENTITY_FLAG_HIDDEN;
    }
}

void clear_item_entity_data(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentItemEntities = WorldItemEntities;
    } else {
        gCurrentItemEntities = BattleItemEntities;
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        gCurrentItemEntities[i] = NULL;
    }

    ItemEntitiesCreated = 0;
    D_80155D8C = 0;
    D_80155D8E = 0;
    D_80155D90 = 0;
    ItemEntityAlternatingSpawn = 0;

    if (!gGameStatusPtr->isBattle) {
        ItemEntityRenderGroup = 0;
    }

    create_worker_world(NULL, draw_item_entities);
    create_worker_frontUI(NULL, draw_ui_item_entities);
    isPickingUpItem = FALSE;
    D_801565A8 = FALSE;
}

void init_item_entity_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentItemEntities = WorldItemEntities;
    } else {
        gCurrentItemEntities = BattleItemEntities;
    }

    isPickingUpItem = FALSE;
    D_801565A8 = FALSE;
    ItemEntitiesCreated = 0;
    ItemEntityAlternatingSpawn = 0;
}

extern s32* gItemEntityScripts[];

void item_entity_load(ItemEntity* item) {
    s32* pos;
    HudCacheEntry* entry;
    s32 cond;
    s32 raster;
    s32 palette;
    s32 size;
    s32 i;

    item->savedReadPos = item->readPos = pos = gItemEntityScripts[item->itemID];

    while (TRUE) {
        switch (*pos++) {
            case ITEM_SCRIPT_OP_End:
                break;
            case ITEM_SCRIPT_OP_Restart:
            case ITEM_SCRIPT_OP_Loop:
            default:
                continue;
            case ITEM_SCRIPT_OP_RandomRestart:
                pos += 2;
                continue;
            case ITEM_SCRIPT_OP_SetImage:
                pos++;
                raster = *pos++;
                palette = *pos++;

                // 32x32 or 24x24 (divided by 2 because these are ci4 iamges)
                size = (item->flags & ITEM_ENTITY_FLAG_40000) ? (32 * 32 / 2) : (24 * 24 / 2);

                entry = gHudElementCacheTableRaster;
                i = 0;
                while (TRUE) {
                    if (entry->id == -1) {
                        entry->id = raster;
                        entry->data = &gHudElementCacheBuffer[*gHudElementCacheSize];

                        ASSERT(*gHudElementCacheSize + size < 0x11000);
                        nuPiReadRom((s32)icon_ROM_START + raster, entry->data, size);
                        *gHudElementCacheSize += size;
                        if (!gGameStatusPtr->isBattle) {
                            *pos = i;
                        } else {
                            *pos = (u16)(*pos) | (i << 16);
                        }
                        pos++;
                        break;
                    } else {
                        cond = entry->id == raster;  // TODO required to match
                        if (cond) {
                            if (!gGameStatusPtr->isBattle) {
                                *pos = i;
                            } else {
                                *pos = (u16)(*pos) | (i << 16);
                            }
                            pos++;
                            break;
                       }
                    }
                    entry++;
                    i++;
                }
                ASSERT(i < MAX_ITEM_ENTITIES);

                entry = gHudElementCacheTablePalette;
                i = 0;
                while (TRUE) {
                    if (entry->id == -1) {
                        entry->id = palette;
                        entry->data = &gHudElementCacheBuffer[*gHudElementCacheSize];
                        ASSERT(*gHudElementCacheSize + 0x20 < 0x11000);
                        nuPiReadRom((s32)icon_ROM_START + palette, entry->data, 0x20);
                        *gHudElementCacheSize += 0x20;
                        if (!gGameStatusPtr->isBattle) {
                            *pos = i;
                        } else {
                            *pos = (u16)(*pos) | (i << 16);
                        }
                        pos++;
                        break;
                    } else if (entry->id == palette) {
                        if (!gGameStatusPtr->isBattle) {
                            *pos = i;
                        } else {
                            *pos = (u16)(*pos) | (i << 16);
                        }
                        pos++;
                        break;
                    }
                    entry++;
                    i++;
                }
                continue;
        }
        break;
    }
    item_entity_update(item);
}

s32 make_item_entity(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 angle, s32 pickupFlagIndex) {
    s32 i;
    s32 id;
    ItemEntity* item;
    f32 hitDepth;
    Shadow* shadow;

    if (pickupFlagIndex <= EVT_GAME_FLAG_CUTOFF) {
        pickupFlagIndex = EVT_INDEX_OF_GAME_FLAG(pickupFlagIndex);
    }

    if (pickupFlagIndex > 0) {
        switch (itemSpawnMode) {
            case ITEM_SPAWN_MODE_KEY:
            case ITEM_SPAWN_MODE_TOSS_NEVER_VANISH:
            case ITEM_SPAWN_MODE_TOSS:
            case ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE:
            case ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE_NEVER_VANISH:
            case ITEM_SPAWN_MODE_ITEM_BLOCK_ITEM:
            case ITEM_SPAWN_MODE_ITEM_BLOCK_BADGE:
            case ITEM_SPAWN_MODE_FALL_NEVER_VANISH:
            case ITEM_SPAWN_MODE_FALL:
            case ITEM_SPAWN_MODE_FALL_SPAWN_ONCE:
            case ITEM_SPAWN_MODE_FIXED_NEVER_VANISH:
            case ITEM_SPAWN_MODE_FIXED:
            case ITEM_SPAWN_MODE_ITEM_BLOCK_COIN:
            case ITEM_SPAWN_MODE_TOSS_HIGHER_NEVER_VANISH:
                if (get_global_flag(pickupFlagIndex) != 0) {
                    return -1;
                }
                break;
        }
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        if (gCurrentItemEntities[i] == NULL) {
            break;
        }
    }

    ASSERT(i < MAX_ITEM_ENTITIES);

    id = i;
    gCurrentItemEntities[id] = item = heap_malloc(sizeof(*item));
    ItemEntitiesCreated++;
    ASSERT(item != NULL);

    item->renderGroup = (itemID & 0xF0000) >> 16;
    if (item->renderGroup == VIS_GROUP_5) {
        item->renderGroup = -1;
    }

    item->spawnType = itemSpawnMode;
    item->state = ITEM_PHYSICS_STATE_INIT;
    item->pos.x = x;
    item->pos.y = y;
    item->pos.z = z;

    itemID &= 0xFFFF;

    item->flags = ITEM_ENTITY_FLAG_80 | ITEM_ENTITY_FLAG_10 | ITEM_ENTITY_FLAG_CAM2 | ITEM_ENTITY_FLAG_CAM1 | ITEM_ENTITY_FLAG_CAM0;
    item->pickupMsgFlags = 0;
    item->boundVar = pickupFlagIndex;
    item->itemID = itemID;
    item->physicsData = NULL;
    item->pickupDelay = pickupDelay;
    item->scale = 1.0f;
    item->spawnAngle = angle;
    item->shadowIndex = -1;
    item->nextUpdate = 1;
    item->lastPos.x = -9999;
    item->lastPos.y = -9999;
    item->lastPos.z = -9999;
    D_801565A6 = 30;

    item->flags |= ITEM_ENTITY_RESIZABLE;
    if (gItemTable[itemID].typeFlags & ITEM_TYPE_FLAG_ENTITY_FULLSIZE) {
        item->flags |= ITEM_ENTITY_FLAG_40000;
        item->flags &= ~ITEM_ENTITY_RESIZABLE;
    }

    if (ItemEntityAlternatingSpawn != 0) {
        item->flags |= ITEM_ENTITY_FLAG_20000;
    }

    ItemEntityAlternatingSpawn = 1 - ItemEntityAlternatingSpawn;

    switch (item->spawnType) {
        case ITEM_SPAWN_MODE_KEY:
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_RECEIPT;
            break;
        case ITEM_SPAWN_MODE_DECORATION:
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            break;
        case ITEM_SPAWN_MODE_INVISIBLE:
            item->flags |= ITEM_ENTITY_FLAG_100000;
            break;
        case ITEM_SPAWN_MODE_BATTLE_REWARD:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_TOSS_LOWER;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_NEVER_VANISH:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_800;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE_NEVER_VANISH:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_800;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_NEVER_VANISH:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_ITEM_BLOCK_ITEM:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->flags |= ITEM_ENTITY_FLAG_ANGLE_RELATIVE_VELOCITY;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_ITEM_BLOCK_BADGE:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->flags |= ITEM_ENTITY_FLAG_ANGLE_RELATIVE_VELOCITY;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            break;
        case ITEM_SPAWN_MODE_FALL_NEVER_VANISH:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            item->spawnType = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FALL:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->spawnType = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FALL_SPAWN_ONCE:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_800;
            item->spawnType = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_NO_GRAVITY;
            item->flags |= ITEM_ENTITY_FLAG_NO_MOTION;
            break;
        case ITEM_SPAWN_MODE_FIXED_NEVER_VANISH:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_NO_GRAVITY;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            item->flags |= ITEM_ENTITY_FLAG_NO_MOTION;
            item->spawnType = ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FIXED:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_NO_GRAVITY;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->flags |= ITEM_ENTITY_FLAG_NO_MOTION;
            item->spawnType = ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS_NEVER_VANISH:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_NO_GRAVITY;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            item->flags |= ITEM_ENTITY_FLAG_NO_MOTION;
            item->spawnType = ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS;
            break;
        case ITEM_SPAWN_MODE_TOSS_FADE1:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_1000;
            item->scale = 0.8f;
            item->flags |= ITEM_ENTITY_RESIZABLE;
            break;
        case ITEM_SPAWN_MODE_TOSS_FADE2:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_1000;
            item->flags |= ITEM_ENTITY_FLAG_TOSS_LOWER;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_FADE1;
            item->scale = 0.8f;
            item->flags |= ITEM_ENTITY_RESIZABLE;
            break;
        case ITEM_SPAWN_MODE_TOSS_FADE3:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_1000;
            item->flags |= ITEM_ENTITY_FLAG_400000;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_FADE1;
            item->scale = 0.8f;
            item->flags |= ITEM_ENTITY_RESIZABLE;
            break;
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            item->scale = 0.8f;
            item->flags |= ITEM_ENTITY_RESIZABLE;
            break;
        case ITEM_SPAWN_MODE_UNKNOWN_1B:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_8000;
            item->spawnType = ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS;
            item->scale = 0.8f;
            item->flags |= ITEM_ENTITY_RESIZABLE;
            break;
        case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_8000;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            break;
        case ITEM_SPAWN_MODE_ITEM_BLOCK_COIN:
            item->spawnType = ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS;
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_8000;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            break;
        case ITEM_SPAWN_MODE_TOSS_HIGHER_NEVER_VANISH:
            item->spawnType = ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS;
            item->flags |= ITEM_ENTITY_FLAG_800000;
            item->flags |= ITEM_ENTITY_FLAG_SAVE_ON_TOUCH;
            item->flags |= ITEM_ENTITY_FLAG_NEVER_VANISH;
            item->flags |= ITEM_ENTITY_FLAG_TOSS_HIGHER;
            break;
    }

    switch (item->spawnType) {
        case ITEM_SPAWN_MODE_KEY:
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
            item->shadowIndex = create_shadow_type(0, item->pos.x, item->pos.y, item->pos.z);
            shadow = get_shadow_by_index(item->shadowIndex);

            if (item->spawnType == ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS) {
                shadow->flags |= ENTITY_FLAG_HIDDEN;
            }

            x = item->pos.x;
            y = item->pos.y + 12.0f;
            z = item->pos.z;
            hitDepth = 1000.0f;
            npc_raycast_down_sides(COLLISION_CHANNEL_20000, &x, &y, &z, &hitDepth);
            shadow->pos.x = x;
            shadow->pos.y = y;
            shadow->pos.z = z;
            shadow->rot.x = gGameStatusPtr->playerGroundTraceAngles.x;
            shadow->rot.y = 0.0f;
            shadow->rot.z = gGameStatusPtr->playerGroundTraceAngles.z;
            set_standard_shadow_scale(shadow, hitDepth * 0.5f);
            break;
    }

    if (item->pickupDelay != 0) {
        hide_item_entity(item);
    }

    item_entity_load(item);

    if (item->itemID == ITEM_COIN) {
        sparkle_script_init(item, &SparkleScript_Coin);
        sparkle_script_update(item);
    }

    if (item->itemID == ITEM_STAR_PIECE) {
        item->flags &= ~ITEM_ENTITY_FLAG_80;
    }

    return id;
}

s32 make_item_entity_nodelay(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupVar) {
    return make_item_entity(itemID, x, y, z, itemSpawnMode, 0, -1, pickupVar);
}

s32 make_item_entity_delayed(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 pickupVar) {
    return make_item_entity(itemID, x, y, z, itemSpawnMode, pickupDelay, -1, pickupVar);
}

s32 make_item_entity_at_player(s32 itemID, s32 category, s32 pickupMsgFlags) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    ItemEntity* item;
    Shadow* shadow;
    s32 i;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 depth;
    s32 id;

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        if (gCurrentItemEntities[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_ITEM_ENTITIES);
    id = i;

    gCurrentItemEntities[id] = item = heap_malloc(sizeof(*item));
    ItemEntitiesCreated++;
    ASSERT(item != NULL);

    itemID &= 0xFFFF;
    item->renderGroup = -1;
    item->flags = (ITEM_ENTITY_FLAG_CAM0 | ITEM_ENTITY_FLAG_CAM1 | ITEM_ENTITY_FLAG_CAM2 | ITEM_ENTITY_FLAG_10 | ITEM_ENTITY_FLAG_2000000);
    if (category != ITEM_TYPE_CONSUMABLE) {
        item->flags |= ITEM_ENTITY_FLAG_4000000;
    }
    item->pickupMsgFlags = pickupMsgFlags;
    item->spawnType = ITEM_SPAWN_AT_PLAYER;
    item->state = ITEM_PICKUP_STATE_INIT;
    item->boundVar = 0;
    item->pos.x = playerStatus->pos.x;
    item->pos.y = playerStatus->pos.y;
    item->pos.z = playerStatus->pos.z;

    item->shadowIndex = -1;
    item->nextUpdate = 1;
    item->lastPos.x = -9999;
    item->lastPos.y = -9999;
    item->lastPos.z = -9999;
    item->scale = 1.0f;
    item->itemID = itemID;
    item->physicsData = NULL;
    item->pickupDelay = 0;
    item->spawnAngle = 0;
    item->flags |= ITEM_ENTITY_RESIZABLE;

    if (gItemTable[itemID].typeFlags & ITEM_TYPE_FLAG_ENTITY_FULLSIZE) {
        item->flags = (item->flags | ITEM_ENTITY_FLAG_40000) & ~ITEM_ENTITY_RESIZABLE;
    }
    if (ItemEntityAlternatingSpawn != 0) {
        item->flags |= ITEM_ENTITY_FLAG_20000;
    }
    ItemEntityAlternatingSpawn = 1 - ItemEntityAlternatingSpawn;

    item->shadowIndex = create_shadow_type(0, item->pos.x, item->pos.y, item->pos.z);
    shadow = get_shadow_by_index(item->shadowIndex);
    shadow->flags |= ENTITY_FLAG_HIDDEN;

    posX = item->pos.x;
    posY = item->pos.y + 12.0f;
    posZ = item->pos.z;
    depth = 1000.0f;
    npc_raycast_down_sides(COLLISION_CHANNEL_20000, &posX, &posY, &posZ, &depth);
    shadow->pos.x = posX;
    shadow->pos.y = posY;
    shadow->pos.z = posZ;

    shadow->rot.x = gGameStatusPtr->playerGroundTraceAngles.x;
    shadow->rot.y = 0.0f;
    shadow->rot.z = gGameStatusPtr->playerGroundTraceAngles.z;
    set_standard_shadow_scale(shadow, depth * 0.5f);

    item_entity_load(item);
    if (item->itemID == ITEM_COIN) {
        sparkle_script_init(item, &SparkleScript_Coin);
        sparkle_script_update(item);
    }
    return id;
}

void item_entity_update(ItemEntity* entity) {
    s32* args;
    s32 max, threshold;

    entity->nextUpdate--;
    if (entity->nextUpdate != 0) {
        return;
    }

    do {
        args = entity->readPos;
        switch(*args++) {
            case ITEM_SCRIPT_OP_End:
                entity->nextUpdate = 60;
                return;
            case ITEM_SCRIPT_OP_SetImage:
                entity->nextUpdate = *args++;
                *args++;
                *args++;
                if (!gGameStatusPtr->isBattle) {
                    entity->lookupRasterIndex  = *args++;
                    entity->lookupPaletteIndex = *args++;
                } else {
                    entity->lookupRasterIndex  = *args++ >> 16;
                    entity->lookupPaletteIndex = *args++ >> 16;
                }
                entity->readPos = args;
                return;
            case ITEM_SCRIPT_OP_Restart:
                entity->readPos = entity->savedReadPos;
                break;
            case ITEM_SCRIPT_OP_Loop:
                entity->savedReadPos = args;
                entity->readPos = args;
                break;
            case ITEM_SCRIPT_OP_RandomRestart:
                max = *args++;
                threshold = *args++;
                if (rand_int(max) < threshold) {
                    entity->readPos = entity->savedReadPos;
                } else {
                    entity->readPos = args;
                }
                break;
        }
    } while (TRUE);
}

void update_item_entities(void) {
    ItemEntity* item;
    f32 x, y, z, hitDepth;
    s32 i;

    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_800))) {
        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            item = gCurrentItemEntities[i];

            if (item != NULL && item->flags != 0) {
                if (item->itemID == ITEM_COIN) {
                    if (rand_int(100) > 90) {
                        sparkle_script_init(item, &SparkleScript_Coin);
                        D_80155D8C = rand_int(16) - 8;
                        D_80155D8E = rand_int(16) - 8;
                        D_80155D90 = 5;
                    }
                    sparkle_script_update(item);
                }

                item_entity_update(item);

                switch (item->spawnType) {
                    case ITEM_SPAWN_MODE_KEY:
                        update_item_entity_stationary(item);
                        break;
                    case ITEM_SPAWN_MODE_DECORATION:
                    case ITEM_SPAWN_MODE_INVISIBLE:
                        update_item_entity_no_pickup(item);
                        break;
                    case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_TOSS_FADE1:
                        update_item_entity_collectable(item);
                        break;
                    case ITEM_SPAWN_AT_PLAYER:
                        update_item_entity_pickup(item);
                        break;
                }

                item = gCurrentItemEntities[i];
                if (item != NULL) {
                    s32 xs, ys, zs;

                    switch (item->spawnType) {
                        case ITEM_SPAWN_MODE_KEY:
                        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
                        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
                        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
                        case ITEM_SPAWN_AT_PLAYER:
                            xs = item->pos.x;
                            ys = item->pos.y;
                            zs = item->pos.z;

                            if (xs != item->lastPos.x || ys != item->lastPos.y || zs != item->lastPos.z) {
                                Shadow* shadow = get_shadow_by_index(item->shadowIndex);

                                x = item->pos.x;
                                y = item->pos.y + 12.0f;
                                z = item->pos.z;
                                hitDepth = 1000.0f;
                                npc_raycast_down_sides(COLLISION_CHANNEL_20000, &x, &y, &z, &hitDepth);

                                shadow->pos.x = x;
                                shadow->pos.y = y;
                                shadow->pos.z = z;
                                shadow->rot.x = gGameStatusPtr->playerGroundTraceAngles.x;
                                shadow->rot.y = 0.0f;
                                shadow->rot.z = gGameStatusPtr->playerGroundTraceAngles.z;
                                set_standard_shadow_scale(shadow, hitDepth * 0.5f);
                            }
                            break;
                    }
                    item->lastPos.x = item->pos.x;
                    item->lastPos.y = item->pos.y;
                    item->lastPos.z = item->pos.z;
                }
            }
            do {} while (0); // required to match
        }
    }
}

void appendGfx_item_entity(void* data) {
    ItemEntity* item = (ItemEntity*)data;
    Mtx mtxTransform;
    Matrix4f mtxTranslate, mtxRotY, mtxScale;
    s32 alpha = 255;
    s32 yOffset;
    f32 rot;

    if (item->flags & (ITEM_ENTITY_FLAG_HIDING | ITEM_ENTITY_FLAG_TRANSPARENT)) {
        if (item->flags & ITEM_ENTITY_FLAG_TRANSPARENT) {
            alpha = 255;
            alpha = (item->alpha * alpha) / 255;
        }
        if (item->flags & ITEM_ENTITY_FLAG_HIDING) {
            u8 r, g, b, a;

            get_background_color_blend(&r, &g, &b, &a);
            alpha = (alpha * (255 - a)) / 255;
        }
    }

    if (!(item->flags & ITEM_ENTITY_FLAG_40000)) {
        yOffset = -2;
    } else {
        yOffset = -3;
    }

    if (item->itemID == ITEM_COIN || item->itemID == ITEM_STAR_POINT || item->itemID == ITEM_HEART) {
        item->scale = 1.0f;
    }

    rot = clamp_angle(180.0f - gCameras[gCurrentCamID].curYaw);
    guTranslateF(mtxTranslate, item->pos.x, item->pos.y + yOffset, item->pos.z);
    guRotateF(mtxRotY, rot, 0.0f, 1.0f, 0.0f);
    if (item->flags & ITEM_ENTITY_RESIZABLE) {
        guScaleF(mtxScale, item->scale, item->scale, item->scale);
        guMtxCatF(mtxRotY, mtxScale, mtxRotY);
    }
    guMtxCatF(mtxRotY, mtxTranslate, mtxTranslate);
    guMtxF2L(mtxTranslate, &mtxTransform);

    gDisplayContext->matrixStack[gMatrixListPos] = mtxTransform;

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (gSpriteShadingProfile->flags != 0) {
        gSPDisplayList(gMainGfxPos++, D_8014BBD8);
    } else {
        gSPDisplayList(gMainGfxPos++, D_8014B870);
    }
    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH | G_LIGHTING);
    gSPDisplayList(gMainGfxPos++, D_8014C620);

    if (item->flags & (ITEM_ENTITY_FLAG_HIDING | ITEM_ENTITY_FLAG_TRANSPARENT)) {
        if (gSpriteShadingProfile->flags != 0) {
            gDPSetRenderMode(gMainGfxPos++, AA_EN | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | G_RM_PASS,
                             AA_EN | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL |
                             GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
        } else {
            gDPSetRenderMode(gMainGfxPos++, AA_EN | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL |
                             GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA),
                             AA_EN | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL |
                             GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
            gDPSetCombineLERP(gMainGfxPos++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, TEXEL0, 0, PRIMITIVE, 0);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, alpha);
        }
    }

    if (!(item->flags & ITEM_ENTITY_FLAG_40000)) {
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, gHudElementCacheTablePalette[item->lookupPaletteIndex].data);
        if (gSpriteShadingProfile->flags != 0) {
            gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 12, gHudElementCacheTableRaster[item->lookupRasterIndex].data);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR |
                       G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPLoadSync(gMainGfxPos++);
            gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x002E, 0x005C);
            gDPPipeSync(gMainGfxPos++);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8,
                       G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPSetTileSize(gMainGfxPos++, 1, 0x0400, 0x0400, 0x045C, 0x045C);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1,
                       G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0, G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 0x00FC, 0);

            if (item->flags & (ITEM_ENTITY_FLAG_HIDING | ITEM_ENTITY_FLAG_TRANSPARENT)) {
                func_801491E4(mtxTranslate, 0, 0, 24, 24, alpha);
            } else {
                func_801491E4(mtxTranslate, 0, 0, 24, 24, 255);
            }
        } else {
            gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 12, gHudElementCacheTableRaster[item->lookupRasterIndex].data);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_LOADTILE, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPLoadSync(gMainGfxPos++);
            gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x002E, 0x005C);
            gDPPipeSync(gMainGfxPos++);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0x0400, 0x0400, 0x045C, 0x045C);
        }
        gSPDisplayList(gMainGfxPos++, D_8014C678);
    } else {
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, gHudElementCacheTablePalette[item->lookupPaletteIndex].data);
        if (gSpriteShadingProfile->flags != 0) {
            gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 16, gHudElementCacheTableRaster[item->lookupRasterIndex].data);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_LOADTILE, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPLoadSync(gMainGfxPos++);
            gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x003E, 0x007C);
            gDPPipeSync(gMainGfxPos++);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                       8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPSetTileSize(gMainGfxPos++, 1, 0x0400, 0x0400, 0x047C, 0x047C);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1,
                       G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0, G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 0x00FC, 0);
            if (item->flags & (ITEM_ENTITY_FLAG_HIDING | ITEM_ENTITY_FLAG_TRANSPARENT)) {
                func_801491E4(mtxTranslate, 0, 0, 32, 32, alpha);
            } else {
                func_801491E4(mtxTranslate, 0, 0, 32, 32, 255);
            }
        } else {
            gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 16, gHudElementCacheTableRaster[item->lookupRasterIndex].data);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_LOADTILE, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPLoadSync(gMainGfxPos++);
            gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x003E, 0x007C);
            gDPPipeSync(gMainGfxPos++);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0x0400, 0x0400, 0x047C, 0x047C);
        }
        gSPDisplayList(gMainGfxPos++, D_8014C6A0);
    }
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);

    if (item->itemID == ITEM_COIN) {
        draw_coin_sparkles(item);
    }
}

void draw_item_entities(void) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    RenderTask* retTask;
    s32 i;

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        ItemEntity* item = gCurrentItemEntities[i];

        if (item != NULL
            && item->flags != 0
            && !(item->flags & ITEM_ENTITY_FLAG_HIDDEN)
            && (item->flags & (1 << gCurrentCamID))
            && !(item->flags & ITEM_ENTITY_FLAG_100000)
            && (item->renderGroup == -1 || ItemEntityRenderGroup == item->renderGroup))
        {
            if (!(item->flags & ITEM_ENTITY_FLAG_TRANSPARENT)) {
                rtPtr->renderMode = RENDER_MODE_ALPHATEST;
            } else {
                rtPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
            }

            rtPtr->appendGfxArg = item;
            rtPtr->appendGfx = appendGfx_item_entity;
            rtPtr->dist = 0;

            retTask = queue_render_task(rtPtr);
            retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
        }

        do {} while (0); // required to match
    }
}

void draw_ui_item_entities(void) {
    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_4000 | GLOBAL_OVERRIDES_8000))) {
        s32 i;

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* item = gCurrentItemEntities[i];

            if (item != NULL && item->flags != 0) {
                switch (item->spawnType) {
                    case ITEM_SPAWN_MODE_KEY:
                        draw_ui_item_entity_stationary(item);
                        break;
                    case ITEM_SPAWN_MODE_DECORATION:
                    case ITEM_SPAWN_MODE_INVISIBLE:
                        draw_ui_item_entity_no_pickup(item);
                        break;
                    case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_TOSS_FADE1:
                        draw_ui_item_entity_collectable(item);
                        break;
                }
            }

            do {} while (0); // required to match
        }
    }
}

void render_item_entities(void) {
    s32 i;
    s32 offsetY;
    f32 rotX;
    Mtx sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;
    u8 r1, g1, b1, a1;
    s32 alpha;

    // needed to move 'i++' to the bottom
    for (i = 0; i < MAX_ITEM_ENTITIES;) {
        ItemEntity* item = gCurrentItemEntities[i];
        if (item != NULL) {
            if ((item->flags != 0)) {
                if (!(item->flags & ITEM_ENTITY_FLAG_HIDDEN)) {
                    if ((item->flags & ITEM_ENTITY_FLAG_100000)) {
                        if (!(item->flags & ITEM_ENTITY_FLAG_40000)) {
                            offsetY = -4;
                        } else {
                            offsetY = 0;
                        }

                        if (item->itemID == ITEM_COIN || item->itemID == ITEM_STAR_POINT || item->itemID == ITEM_HEART) {
                            offsetY = 0;
                            item->scale = 1.0f;
                        }

                        rotX = clamp_angle(180.0f - gCameras[gCurrentCamID].curYaw);
                        guTranslateF(sp58, item->pos.x, -item->pos.y - offsetY, item->pos.z);
                        guRotateF(sp98, rotX, 0.0f, 1.0f, 0.0f);
                        if (item->flags & ITEM_ENTITY_RESIZABLE) {
                            guScaleF(spD8, item->scale, item->scale, item->scale);
                            guMtxCatF(sp98, spD8, sp98);
                        }
                        guMtxCatF(sp98, sp58, sp58);
                        guMtxF2L(sp58, &sp18);
                        gDisplayContext->matrixStack[gMatrixListPos] = sp18;
                        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

                        if (gSpriteShadingProfile->flags != 0) {
                            gSPDisplayList(gMainGfxPos++, D_8014BBD8);
                        } else {
                            gSPDisplayList(gMainGfxPos++, D_8014B870);
                        }
                        gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                        gSPDisplayList(gMainGfxPos++, D_8014C620);

                        alpha = 255;
                        if (item->flags & (ITEM_ENTITY_FLAG_TRANSPARENT | ITEM_ENTITY_FLAG_HIDING)) {
                            if (item->flags & ITEM_ENTITY_FLAG_TRANSPARENT) {
                                alpha = item->alpha * alpha / 255;
                            }
                            if (item->flags & ITEM_ENTITY_FLAG_HIDING) {
                                get_background_color_blend(&r1, &g1, &b1, &a1);
                                alpha = alpha * (255 - a1) / 255;
                            }
                            if (item->flags & (ITEM_ENTITY_FLAG_TRANSPARENT | ITEM_ENTITY_FLAG_HIDING)) {
                                if (gSpriteShadingProfile->flags) {
                                    gDPSetRenderMode(gMainGfxPos++, AA_EN | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | G_RM_PASS,
                                        AA_EN | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
                                } else {
                                    gDPSetRenderMode(gMainGfxPos++, AA_EN | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA),
                                                                    AA_EN | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
                                    gDPSetCombineLERP(gMainGfxPos++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, TEXEL0, 0, PRIMITIVE, 0);
                                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, alpha);
                                }
                            }
                        }

                        if (!(item->flags & ITEM_ENTITY_FLAG_40000)) {
                            gDPLoadTLUT_pal16(gMainGfxPos++, 0, gHudElementCacheTablePalette[item->lookupPaletteIndex].data);
                            if (gSpriteShadingProfile->flags) {
                                gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 12, gHudElementCacheTableRaster[item->lookupRasterIndex].data);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPLoadSync(gMainGfxPos++);
                                gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x002E, 0x005C);
                                gDPPipeSync(gMainGfxPos++);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPSetTileSize(gMainGfxPos++, 1, 0x0400, 0x0400, 0x045C, 0x045C);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                                gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 0x00FC, 0);
                                if (item->flags & (ITEM_ENTITY_FLAG_TRANSPARENT | ITEM_ENTITY_FLAG_HIDING)) {
                                    func_801491E4(sp58, 0, 0, 24, 24, alpha);
                                } else {
                                    func_801491E4(sp58, 0, 0, 24, 24, 255);
                                }
                            } else {
                                gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 12, gHudElementCacheTableRaster[item->lookupRasterIndex].data);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPLoadSync(gMainGfxPos++);
                                gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x002E, 0x005C);
                                gDPPipeSync(gMainGfxPos++);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0x0400, 0x0400, 0x045C, 0x045C);
                            }
                            gSPDisplayList(gMainGfxPos++, D_8014C678);
                        } else {
                            gDPLoadTLUT_pal16(gMainGfxPos++, 0, gHudElementCacheTablePalette[item->lookupPaletteIndex].data);
                            if (gSpriteShadingProfile->flags) {
                                gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 16, gHudElementCacheTableRaster[item->lookupRasterIndex].data);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPLoadSync(gMainGfxPos++);
                                gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x003E, 0x007C);
                                gDPPipeSync(gMainGfxPos++);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPSetTileSize(gMainGfxPos++, 1, 0x0400, 0x0400, 0x047C, 0x047C);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                                gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 0x00FC, 0);
                                if (item->flags & (ITEM_ENTITY_FLAG_TRANSPARENT | ITEM_ENTITY_FLAG_HIDING)) {
                                    func_801491E4(sp58, 0, 0, 32, 32, alpha);
                                } else {
                                    func_801491E4(sp58, 0, 0, 32, 32, 255);
                                }
                            } else {
                                gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 16, gHudElementCacheTableRaster[item->lookupRasterIndex].data);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPLoadSync(gMainGfxPos++);
                                gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x003E, 0x007C);
                                gDPPipeSync(gMainGfxPos++);
                                gDPSetTile(gMainGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
                                gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0x0400, 0x0400, 0x047C, 0x047C);
                            }
                            gSPDisplayList(gMainGfxPos++, D_8014C6A0);
                        }
                        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
                        gDPPipeSync(gMainGfxPos++);
                    }
                }
            }
        }
        i++;
    }
}

void remove_item_entity_by_reference(ItemEntity* entity) {
    s32 index;

    for (index = 0; index < MAX_ITEM_ENTITIES; index++) {
        if (gCurrentItemEntities[index] == entity) {
            break;
        }
    }

    if (index < MAX_ITEM_ENTITIES) {
        if (entity->physicsData != NULL) {
            heap_free(entity->physicsData);
        }

        switch (entity->spawnType) {
            case ITEM_SPAWN_MODE_KEY:
            case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
            case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
            case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
            case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
            case ITEM_SPAWN_AT_PLAYER:
                delete_shadow(entity->shadowIndex);
                break;
        }

        heap_free(gCurrentItemEntities[index]);
        isPickingUpItem = FALSE;
        gCurrentItemEntities[index] = NULL;
    }
}

void remove_item_entity_by_index(s32 index) {
    ItemEntity* item = gCurrentItemEntities[index];

    switch (item->spawnType) {
        case ITEM_SPAWN_MODE_KEY:
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
        case ITEM_SPAWN_AT_PLAYER:
            delete_shadow(item->shadowIndex);
            break;
    }

    heap_free(gCurrentItemEntities[index]);
    gCurrentItemEntities[index] = NULL;
    isPickingUpItem = FALSE;
}

void func_80133A94(s32 idx, s32 itemID) {
    ItemEntity* item = gCurrentItemEntities[idx];

    item->itemID = itemID;

    item->flags |= ITEM_ENTITY_RESIZABLE;
    item->flags &= ~ITEM_ENTITY_FLAG_40000;

    if (gItemTable[itemID].typeFlags & ITEM_TYPE_FLAG_ENTITY_FULLSIZE) {
        item->flags |= ITEM_ENTITY_FLAG_40000;
        item->flags &= ~ITEM_ENTITY_RESIZABLE;
    }

    item_entity_load(item);
}

b32 test_item_player_collision(ItemEntity* item) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 actionState = playerStatus->actionState;
    f32 distThreshold;
    f32 itemX, itemY, itemZ;
    f32 tmpX, tmpZ;
    f32 playerX, playerY, playerZ;
    f32 colliderHeightHalf;
    f32 colliderDiameterQuart;
    f32 spriteFacingAngle;
    f32 playerY2;
    f32 xDiff, zDiff;
    f32 dist;
    f32 angle;
    b32 cond;
    // below weird temps required to match
    f32 fourteen;
    f32 yTopThreshold;
    f32 yBottomThreshold;
    f32 tmpFourteen;
    f32 tmpYTopThreshold;

    if (item->flags & ITEM_ENTITY_FLAG_AUTO_COLLECT) {
        item->flags &= ~ITEM_ENTITY_FLAG_AUTO_COLLECT;
        return TRUE;
    }

    if (gEncounterState != ENCOUNTER_STATE_NEUTRAL && gEncounterState != ENCOUNTER_STATE_NONE) {
        return FALSE;
    }

    if (encounterStatus->hitType == ENCOUNTER_TRIGGER_CONVERSATION) {
        return FALSE;
    }

    if (item->flags & ITEM_ENTITY_FLAG_CANT_COLLECT) {
        return FALSE;
    }

    tmpFourteen = 14.0f;
    if (isPickingUpItem) {
        return FALSE;
    }

    fourteen = tmpFourteen;
    tmpYTopThreshold = 18.0f;
    yBottomThreshold = 27.0f;

    cond = item->flags; // required to match
    if (item->flags & ITEM_ENTITY_FLAG_HIDDEN) {
        return FALSE;
    }

    yTopThreshold = tmpYTopThreshold;
    if (get_time_freeze_mode() != TIME_FREEZE_NORMAL) {
        return FALSE;
    }

    if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE && partnerStatus->actingPartner == PARTNER_BOW) {
        return FALSE;
    }

    if (
        (actionState == ACTION_STATE_USE_SPINNING_FLOWER
         || actionState == ACTION_STATE_USE_MUNCHLESIA
         || actionState == ACTION_STATE_USE_TWEESTER)
        && item->itemID != ITEM_COIN)
    {
        return FALSE;
    }

    if (gOverrideFlags & GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS) {
        return FALSE;
    }

    cond = FALSE;
    colliderHeightHalf = playerStatus->colliderHeight / 2;
    playerX = playerStatus->pos.x;
    playerY = playerStatus->pos.y;
    playerZ = playerStatus->pos.z;

    colliderDiameterQuart = playerStatus->colliderDiameter / 4;
    spriteFacingAngle = playerStatus->spriteFacingAngle;
    if (spriteFacingAngle < 180.0f) {
        spriteFacingAngle = clamp_angle(camera->curYaw - 90.0f);
    } else {
        spriteFacingAngle = clamp_angle(camera->curYaw + 90.0f);
    }

    tmpX = playerX;
    playerY2 = playerY;
    tmpZ = playerZ;
    if (get_clamped_angle_diff(camera->curYaw, spriteFacingAngle) < 0.0f) {
        angle = clamp_angle(camera->curYaw - 90.0f);
        if (playerStatus->trueAnimation & 0x01000000) {
            angle = clamp_angle(angle + 30.0f);
        }
    } else {
        angle = clamp_angle(camera->curYaw + 90.0f);
        if (playerStatus->trueAnimation & 0x01000000) {
            angle = clamp_angle(angle - 30.0f);
        }
    }

    add_vec2D_polar(&tmpX, &tmpZ, 24.0f, angle);

    itemX = item->pos.x;
    itemY = item->pos.y;
    itemZ = item->pos.z;

    do {
        do {
            distThreshold = 13.5f;
        } while (0); // required to match

        xDiff = itemX - playerX;
        zDiff = itemZ - playerZ;

        dist = sqrtf(SQ(xDiff) + SQ(zDiff));
        if (!(colliderDiameterQuart + distThreshold <= dist) &&
            !(itemY + yBottomThreshold < playerY) &&
            !(playerY + colliderHeightHalf < itemY))
        {
            cond = TRUE;
        }
    } while (0); // required to match

    if (playerStatus->actionState == ACTION_STATE_HAMMER && (playerStatus->flags & PS_FLAG_HAMMER_CHECK)) {
        xDiff = itemX - tmpX;
        zDiff = itemZ - tmpZ;
        dist = sqrtf(SQ(xDiff) + SQ(zDiff));
        if (!(fourteen + distThreshold <= dist)
            && !(itemY + yBottomThreshold < playerY2)
            && !(playerY2 + yTopThreshold < itemY))
        {
            cond = TRUE;
        }
    }

    if (cond) {
        if (item->flags & ITEM_ENTITY_FLAG_80) {
            if (D_801565A6 != 0) {
                D_801565A6--;
                return FALSE;
            } else {
                item->flags &= ~ITEM_ENTITY_FLAG_80;
            }
        }
        return TRUE;
    }

    if (item->flags & ITEM_ENTITY_FLAG_80) {
        item->flags &= ~ITEM_ENTITY_FLAG_80;
    }
    return FALSE;
}

s32 test_item_entity_position(f32 x, f32 y, f32 z, f32 dist) {
    ItemEntity* item;
    f32 dx, dy, dz;
    s32 i;

    if (is_starting_conversation() || isPickingUpItem || get_time_freeze_mode() != 0 ||
        gOverrideFlags & GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    {
        return -1;
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++){
        item = gCurrentItemEntities[i];

        if (item == NULL) {
            continue;
        }

        if (item->flags == 0) {
            continue;
        }

        if (item->spawnType == ITEM_SPAWN_MODE_DECORATION) {
            continue;
        }

        if (item->spawnType == ITEM_SPAWN_MODE_INVISIBLE) {
            continue;
        }

        if (item->flags & ITEM_ENTITY_FLAG_HIDDEN) {
            continue;
        }

        if (item->flags & ITEM_ENTITY_FLAG_CANT_COLLECT) {
            continue;
        }

        dx = item->pos.x - x;
        dz = item->pos.y - y;
        dy = item->pos.z - z;
        if (sqrtf(SQ(dx) + SQ(dz) + SQ(dy)) < dist) {
            return i;
        }
    }
    return -1;
}

void set_item_entity_flags(s32 index, s32 flags) {
    ItemEntity* item = gCurrentItemEntities[index];

    item->flags |= flags;
    if (item->flags & ITEM_ENTITY_FLAG_CANT_COLLECT) {
        D_801565A8 = TRUE;
    }
}

void clear_item_entity_flags(s32 index, s32 flags) {
    ItemEntity* item = gCurrentItemEntities[index];

    item->flags &= ~flags;
}

void auto_collect_item_entity(s32 index) {
    ItemEntity* item = gCurrentItemEntities[index];
    gOverrideFlags |= GLOBAL_OVERRIDES_40;
    item->flags |= ITEM_ENTITY_FLAG_AUTO_COLLECT;
}

/// @returns TRUE when "you got X" popup is on-screen
b32 is_picking_up_item(void) {
    b32 ret = D_801565A8 != FALSE;

    if (isPickingUpItem) {
        ret = TRUE;
    }
    return ret;
}

void set_item_entity_position(s32 itemEntityIndex, f32 x, f32 y, f32 z) {
    ItemEntity* item = gCurrentItemEntities[itemEntityIndex];

    item->pos.x = x;
    item->pos.y = y;
    item->pos.z = z;
}

void set_current_item_entity_render_group(s32 group) {
    ItemEntityRenderGroup = group;
}

s32 get_current_item_entity_render_group(void) {
    return ItemEntityRenderGroup;
}

void update_item_entity_collectable(ItemEntity* item) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    ItemEntityPhysicsData* physData;
    s32 camID;
    s32 hit;
    f32 outX, outY, outZ, outDepth;
    f32 theta, sinAngle, cosAngle;
    f32 temp;

    if (isPickingUpItem) {
        return;
    }

    if (item->pickupDelay != 0) {
        item->pickupDelay--;
        return;
    }

    if (item->spawnType == ITEM_SPAWN_MODE_TOSS_FADE1) {
        camID = CAM_BATTLE;
    } else {
        camID = CAM_DEFAULT;
    }

    switch (item->state) {
        case ITEM_PHYSICS_STATE_INIT:
            reveal_item_entity(item);
            physData = heap_malloc(sizeof(*physData));
            item->physicsData = physData;
            ASSERT(physData != NULL);

            if (item->flags & ITEM_ENTITY_FLAG_TOSS_HIGHER) {
                physData->verticalVel = 16.0f;
                physData->gravity = 2.0f;
            } else if (!(item->flags & ITEM_ENTITY_FLAG_TOSS_LOWER)) {
                physData->verticalVel = 12.0f;
                physData->gravity = 2.0f;
            } else {
                physData->verticalVel = 14.0f;
                physData->gravity = 2.0f;
            }

            physData->collisionRadius = 24.0f;
            physData->constVel = 24.0f;
            if (item->spawnAngle < 0) {
                if (IS_ITEM(item->itemID)) {
                    if (rand_int(10000) < 5000) {
                        physData->moveAngle = clamp_angle(gCameras[camID].curYaw + 105.0f + rand_int(30) - 15.0f);
                    } else {
                        physData->moveAngle = clamp_angle(gCameras[camID].curYaw - 105.0f + rand_int(30) - 15.0f);
                    }
                    physData->verticalVel += 4.0f;
                } else {
                    switch (item->itemID) {
                        case ITEM_HEART:
                            physData->moveAngle = clamp_angle(gCameras[camID].curYaw + 90.0f + rand_int(120) - 60.0f);
                            break;
                        case ITEM_FLOWER_POINT:
                            physData->moveAngle = clamp_angle(gCameras[camID].curYaw - 90.0f + rand_int(120) + 60.0f);
                            break;
                        case ITEM_COIN:
                            if (rand_int(10000) < 5000) {
                                physData->moveAngle = clamp_angle(gCameras[camID].curYaw + 90.0f + rand_int(120) - 60.0f);
                            } else {
                                physData->moveAngle = clamp_angle(gCameras[camID].curYaw - 90.0f + rand_int(120) - 60.0f);
                            }
                            break;
                        case ITEM_KOOPA_FORTRESS_KEY:
                            if (rand_int(10000) >= 5000) {
                                physData->moveAngle = clamp_angle(gCameras[camID].curYaw - 90.0f + rand_int(120) - 60.0f);
                            } else {
                                physData->moveAngle = clamp_angle(gCameras[camID].curYaw + 90.0f + rand_int(120) - 60.0f);
                            }
                            break;
                        case ITEM_STAR_POINT:
                            if (item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1) {
                                physData->moveAngle = clamp_angle(gCameras[camID].curYaw - 90.0f + rand_int(120) - 60.0f);
                                break;
                            }
                            if (rand_int(10000) < 5000) {
                                physData->moveAngle = clamp_angle(gCameras[camID].curYaw + 90.0f + rand_int(60) - 30.0f);
                            } else {
                                physData->moveAngle = clamp_angle(gCameras[camID].curYaw - 90.0f + rand_int(60) - 30.0f);
                            }
                            break;
                        case ITEM_HEART_POINT:
                            physData->moveAngle = clamp_angle(gCameras[camID].curYaw + 90.0f + rand_int(120) - 60.0f);
                            break;
                        case ITEM_STAR_PIECE:
                            if (rand_int(10000) < 5000) {
                                physData->moveAngle = clamp_angle(gCameras[camID].curYaw + 90.0f + rand_int(60) - 30.0f);
                            } else {
                                physData->moveAngle = clamp_angle(gCameras[camID].curYaw - 90.0f + rand_int(60) - 30.0f);
                            }
                            break;
                        case ITEM_HEART_PIECE:
                            physData->moveAngle = clamp_angle(gCameras[camID].curYaw + 90.0f + rand_int(120) - 60.0f);
                            break;
                        default:
                            physData->moveAngle = 0.0f;
                            break;
                    }
                }

                if (!(item->flags & ITEM_ENTITY_FLAG_TOSS_HIGHER)) {
                    temp = rand_int(2000);
                    temp = (temp / 1000.0f) + 1.5;
                    theta = DEG_TO_RAD(physData->moveAngle);
                    sinAngle = sin_rad(theta);
                    cosAngle = cos_rad(theta);
                    physData->velX = temp * sinAngle;
                    physData->velZ = -temp * cosAngle;
                } else {
                    temp = rand_int(2000);
                    temp = (temp / 1000.0f) + 2.0;
                    theta = DEG_TO_RAD(physData->moveAngle);
                    sinAngle = sin_rad(theta);
                    cosAngle = cos_rad(theta);
                    physData->velX = temp * sinAngle;
                    physData->velZ = -temp * cosAngle;
                }
            } else {
                physData->moveAngle = clamp_angle(item->spawnAngle);
                if (!(item->flags & ITEM_ENTITY_FLAG_ANGLE_RELATIVE_VELOCITY)) {
                    temp = 1.5f + (0.6 * (item->spawnAngle / 360));
                } else {
                    temp = 2.1f;
                }
                theta = DEG_TO_RAD(physData->moveAngle);
                sinAngle = sin_rad(theta);
                cosAngle = cos_rad(theta);
                physData->velX = temp * sinAngle;
                physData->velZ = -temp * cosAngle;
            }

            if (item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1) {
                physData->timeLeft = 180;
                physData->useSimplePhysics = FALSE;
            } else {
                if (!(item->flags & ITEM_ENTITY_FLAG_400000)) {
                    physData->timeLeft = 17;
                } else {
                    physData->timeLeft = 20;
                }
                physData->useSimplePhysics = FALSE;
                physData->verticalVel = 15.0f;
                physData->gravity = 1.6f;
            }

            if (item->spawnType == ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS) {
                physData->timeLeft = 60;
                physData->useSimplePhysics = FALSE;
                physData->velX = 0.0f;
                physData->velZ = 0.0f;
            }

            if (item->spawnType == ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS) {
                physData->verticalVel = 0.0f;
                physData->velX = 0.0f;
                physData->velZ = 0.0f;
                physData->useSimplePhysics = TRUE;
            }

            if (item->spawnType == ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS) {
                physData->verticalVel = 0.0f;
                physData->velX = 0.0f;
                physData->velZ = 0.0f;
                physData->useSimplePhysics = TRUE;
            }

            if (item->flags & ITEM_ENTITY_FLAG_800) {
                set_global_flag(item->boundVar);
            }
            item->state = ITEM_PHYSICS_STATE_ALIVE;
            break;

        case ITEM_PHYSICS_STATE_ALIVE:
            physData = item->physicsData;

            // test for pickup
            if (item->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS
                && item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1
                && physData->useSimplePhysics
                && test_item_player_collision(item)
            ) {
                item->state = ITEM_PHYSICS_STATE_TOUCH;
                break;
            }

            // check for expiration
            if (!(item->flags & ITEM_ENTITY_FLAG_NEVER_VANISH)
                && !(gOverrideFlags & (GLOBAL_OVERRIDES_200 | GLOBAL_OVERRIDES_DISABLE_BATTLES))
                && !(item->flags & ITEM_ENTITY_FLAG_CANT_COLLECT)
            ) {
                physData->timeLeft--;
                if (physData->timeLeft < 0) {
                    item->state = ITEM_PHYSICS_STATE_DEAD;
                    break;
                }
            }

            // apply gravity
            if (!(item->flags & ITEM_ENTITY_FLAG_NO_GRAVITY)) {
                if (!(item->flags & ITEM_ENTITY_FLAG_CANT_COLLECT)) {
                    physData->verticalVel -= physData->gravity;
                    if (physData->verticalVel < -16.0) {
                        physData->verticalVel = -16.0f;
                    }
                    item->pos.y += physData->verticalVel;
                    item->pos.x += physData->velX;
                    item->pos.z += physData->velZ;
                }
            }

            // handle auto-collection from multi-coin bricks
            if (item->spawnType == ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS
                && physData->verticalVel <= 0.0f
            ) {
                item->state = ITEM_PHYSICS_STATE_TOUCH;
                break;
            }

            // if the item has upward velocity, try moving it up
            if (!(item->flags & (ITEM_ENTITY_FLAG_DONE_FALLING | ITEM_ENTITY_FLAG_NO_MOTION))
                && item->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS
                && item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1
                && physData->verticalVel > 0.0f
            ) {
                temp = physData->constVel;
                outX = item->pos.x;
                outY = item->pos.y;
                outZ = item->pos.z;
                outDepth = temp + physData->verticalVel;

                if (!physData->useSimplePhysics) {
                    hit = npc_raycast_up(COLLISION_CHANNEL_20000, &outX, &outY, &outZ, &outDepth);
                } else {
                    hit = npc_raycast_up(COLLISION_CHANNEL_20000, &outX, &outY, &outZ, &outDepth);
                }

                if (hit && outDepth < temp) {
                    item->pos.y = outY - temp;
                    physData->verticalVel = 0.0f;
                }
            }

            // if the item has non-zero lateral velocity, try moving it laterally
            if (!(item->flags & (ITEM_ENTITY_FLAG_DONE_FALLING | ITEM_ENTITY_FLAG_NO_MOTION))
                && item->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS
                && item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1
                && (physData->velX != 0.0f || physData->velZ != 0.0f)
            ) {
                outX = item->pos.x;
                outY = item->pos.y;
                outZ = item->pos.z;

                if (!physData->useSimplePhysics) {
                    hit = npc_test_move_complex_with_slipping(COLLISION_CHANNEL_20000, &outX, &outY, &outZ, 0.0f, physData->moveAngle, physData->constVel, physData->collisionRadius);
                } else {
                    hit = npc_test_move_simple_with_slipping(COLLISION_CHANNEL_20000, &outX, &outY, &outZ, 0.0f, physData->moveAngle, physData->constVel, physData->collisionRadius);
                }

                if (hit) {
                    // if a wall is hit, bounce back
                    item->pos.x = outX;
                    item->pos.y = outY;
                    item->pos.z = outZ;
                    physData->moveAngle = clamp_angle(physData->moveAngle + 180.0f);
                    theta = DEG_TO_RAD(physData->moveAngle);
                    sinAngle = sin_rad(theta);
                    cosAngle = cos_rad(theta);
                    physData->velX = sinAngle * 2.0;
                    physData->velZ = cosAngle * -2.0;
                }
            }

            // if the item has downward velocity, try moving it down
            if (!(item->flags & ITEM_ENTITY_FLAG_NO_MOTION)
                && item->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS
                && physData->verticalVel <= 0.0
            ) {
                physData->useSimplePhysics = TRUE;
                if (item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1) {
                    outX = item->pos.x;
                    outY = (item->pos.y - physData->verticalVel) + 12.0f;
                    outZ = item->pos.z;
                    outDepth = -physData->verticalVel + 12.0f;
                    if (!physData->useSimplePhysics) {
                        hit = npc_raycast_down_sides(COLLISION_CHANNEL_20000, &outX, &outY, &outZ, &outDepth);
                    } else {
                        hit = npc_raycast_down_around(COLLISION_CHANNEL_20000, &outX, &outY, &outZ, &outDepth, 180.0f, 20.0f);
                    }
                } else {
                    outX = item->pos.x;
                    outY = (item->pos.y - physData->verticalVel) + 12.0f;
                    outZ = item->pos.z;
                    outDepth = -physData->verticalVel + 12.0f;
                    if (outY < outDepth + 0.0f) {
                        outY = 0.0f;
                        hit = TRUE;
                    } else {
                        hit = FALSE;
                    }
                }

                // handle bounce
                if (hit) {
                    item->pos.y = outY;
                    physData->verticalVel = -physData->verticalVel / 1.25;
                    if (physData->verticalVel < 3.0) {
                        physData->verticalVel = 0.0f;
                        physData->velX = 0.0f;
                        physData->velZ = 0.0f;
                        item->flags |= ITEM_ENTITY_FLAG_DONE_FALLING;
                    } else {
                        if (IS_BADGE(item->itemID)) {
                            sfx_play_sound_at_position(SOUND_21B, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                        } else if (IS_ITEM(item->itemID)) {
                            sfx_play_sound_at_position(SOUND_21A, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                        } else {
                            switch (item->itemID) {
                                case ITEM_HEART:
                                    sfx_play_sound_at_position(SOUND_214, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                                    break;
                                case ITEM_COIN:
                                    sfx_play_sound_at_position(SOUND_212, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                                    break;
                                case ITEM_KOOPA_FORTRESS_KEY:
                                    sfx_play_sound_at_position(SOUND_212, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                                    break;
                                case ITEM_HEART_PIECE:
                                    sfx_play_sound_at_position(SOUND_214, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                                    break;
                                case ITEM_STAR_POINT:
                                    sfx_play_sound_at_position(SOUND_212, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                                    break;
                                case ITEM_HEART_POINT:
                                    sfx_play_sound_at_position(SOUND_214, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                                    break;
                                case ITEM_STAR_PIECE:
                                    sfx_play_sound_at_position(SOUND_219, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                                    break;
                                case ITEM_FLOWER_POINT:
                                    sfx_play_sound_at_position(SOUND_218, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                                    break;
                            }
                        }
                    }
                }
            }

            if (item->pos.y < -2000.0f) {
                item->state = ITEM_PHYSICS_STATE_DEAD;
            }
            break;
    }

    if (item->state == ITEM_PHYSICS_STATE_DEAD) {
        remove_item_entity_by_reference(item);
    }

    if (item->state == ITEM_PHYSICS_STATE_TOUCH) {
        if (item->flags & ITEM_ENTITY_FLAG_SAVE_ON_TOUCH) {
            set_global_flag(item->boundVar);
        }

        fx_small_gold_sparkle(0, item->pos.x, item->pos.y + 16.0f, item->pos.z, 1.0f, 0);

        if (IS_ITEM(item->itemID)) {
            item->state = ITEM_PHYSICS_STATE_PICKUP;
        } else if (IS_BADGE(item->itemID)) {
            item->state = ITEM_PHYSICS_STATE_PICKUP;
        } else if (item->itemID == ITEM_STAR_PIECE) {
            playerData->starPiecesCollected++;
            item->state = ITEM_PHYSICS_STATE_PICKUP;
        } else {
            if (item->spawnType == ITEM_SPAWN_MODE_TOSS_FADE1) {
                item->itemID = -1;
            }

            switch (item->itemID) {
                case ITEM_HEART:
                    if (playerData->curHP < playerData->curMaxHP) {
                        fx_recover(0, playerStatus->pos.x, playerStatus->pos.y + playerStatus->colliderHeight, playerStatus->pos.z, 1);
                        sfx_play_sound_at_position(SOUND_2056, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                    }
                    playerData->curHP++;
                    if (playerData->curHP > playerData->curMaxHP) {
                        playerData->curHP = playerData->curMaxHP;
                    }
                    sfx_play_sound_at_position(SOUND_213, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                    fx_sparkles(4, playerStatus->pos.x, playerStatus->pos.y + playerStatus->colliderHeight, playerStatus->pos.z, 30.0f);
                    break;
                case ITEM_FLOWER_POINT:
                    if (playerData->curFP < playerData->curMaxFP) {
                        fx_recover(1, playerStatus->pos.x, playerStatus->pos.y + playerStatus->colliderHeight, playerStatus->pos.z, 1);
                        sfx_play_sound_at_position(SOUND_2056, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                    }
                    playerData->curFP++;
                    if (playerData->curFP > playerData->curMaxFP) {
                        playerData->curFP = playerData->curMaxFP;
                    }
                    sfx_play_sound_at_position(SOUND_217, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                    fx_sparkles(4, playerStatus->pos.x, playerStatus->pos.y + playerStatus->colliderHeight, playerStatus->pos.z, 30.0f);
                    break;
                case ITEM_COIN:
                    playerData->coins++;
                    if (playerData->coins > 999) {
                        playerData->coins = 999;
                    }
                    sfx_play_sound_at_position(SOUND_211, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                    playerData->totalCoinsEarned++;
                    if (playerData->totalCoinsEarned > 99999) {
                        playerData->totalCoinsEarned = 99999;
                    }
                    break;
                case ITEM_KOOPA_FORTRESS_KEY:
                    playerData->fortressKeyCount = playerData->fortressKeyCount + 1;
                    sfx_play_sound_at_position(SOUND_211, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                    break;
                case ITEM_STAR_POINT:
                    playerData->starPoints++;
                    if (playerData->starPoints > 100) {
                        playerData->starPoints = 100;
                    }
                    sfx_play_sound_at_position(SOUND_211, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                    break;
                case ITEM_HEART_POINT:
                    playerData->curHP = playerData->curMaxHP;
                    playerData->curFP = playerData->curMaxFP;
                    sfx_play_sound_at_position(SOUND_213, SOUND_SPACE_MODE_0, item->pos.x, item->pos.y, item->pos.z);
                    break;
            }
            D_801565A8 = FALSE;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            remove_item_entity_by_reference(item);
        }
    }

    // items in this unused state are managed by a script
    // when the script is done executing, destroy these items
    if (item->state == ITEM_PHYSICS_STATE_04) {
        if (!does_script_exist(D_80155D80)) {
            D_801565A8 = FALSE;
            remove_item_entity_by_reference(item);
            resume_all_group(EVT_GROUP_02);
        }
    }

    if (item->state == ITEM_PHYSICS_STATE_PICKUP) {
        isPickingUpItem = TRUE;
        item->spawnType = ITEM_SPAWN_AT_PLAYER;
        item->state = ITEM_PICKUP_STATE_INIT;
        D_801565A8 = FALSE;
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
    }
}

void draw_ui_item_entity_collectable(ItemEntity* item) {
    if (item->state == ITEM_PHYSICS_STATE_ALIVE) {
        ItemEntityPhysicsData* physicsData = item->physicsData;
        s32 flag = (item->flags & ITEM_ENTITY_FLAG_20000) > 0;

        if (item->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS) {
            if (item->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1) {
                if (physicsData->timeLeft < 60) {
                    if ((item->flags & ITEM_ENTITY_FLAG_CANT_COLLECT) || ((gGameStatusPtr->frameCounter + flag) & 1)) {
                        item->flags &= ~ITEM_ENTITY_FLAG_HIDDEN;
                    } else {
                        item->flags |= ITEM_ENTITY_FLAG_HIDDEN;
                    }
                }
            } else {
                if (physicsData->timeLeft < 10) {
                    item->alpha = physicsData->timeLeft * 28;
                    item->flags |= ITEM_ENTITY_FLAG_TRANSPARENT;
                }
            }
        }
    }
}

void update_item_entity_stationary(ItemEntity* item) {
    if (item->state == ITEM_PHYSICS_STATE_INIT) {
        if (test_item_player_collision(item)) {
            // change spawn type to initiate pickup
            isPickingUpItem = TRUE;
            item->spawnType = ITEM_SPAWN_AT_PLAYER;
            item->state = ITEM_PICKUP_STATE_INIT;
            D_801565A8 = FALSE;
            gOverrideFlags |= GLOBAL_OVERRIDES_40;
        }
    }
}

void draw_ui_item_entity_stationary(ItemEntity* item) {
}

void update_item_entity_no_pickup(ItemEntity* item) {
}

void draw_ui_item_entity_no_pickup(ItemEntity* item) {
}

void update_item_entity_pickup(ItemEntity* item) {
    PlayerData* playerData = &gPlayerData;
    PlayerStatus* playerStatus = &gPlayerStatus;
    PopupMenu* menu = &D_801565B0;
    ItemData* itemData;
    s32 numEntries;
    s32 msgID;
    s32 i;

    if (item->state == ITEM_PICKUP_STATE_INIT) {
        isPickingUpItem = TRUE;
        if (!(item->flags & ITEM_ENTITY_FLAG_2000000)) {
            disable_player_input();
            partner_disable_input();
            gOverrideFlags |= GLOBAL_OVERRIDES_40;
            set_time_freeze_mode(TIME_FREEZE_FULL);
        }
        hide_item_entity(item);
        item->state = ITEM_PICKUP_STATE_AWAIT_VALID_STATE;
    }

    switch (item->state) {
        case ITEM_PICKUP_STATE_AWAIT_VALID_STATE:
            if (!(item->flags & ITEM_ENTITY_FLAG_2000000)) {
                // list of action state conditions which allow item pickup
                // remain in this state (via break) until one of these is TRUE
                s32 actionState = playerStatus->actionState;
                if (!(
                    playerStatus->animFlags & PA_FLAG_NO_OOB_RESPAWN
                    || ((playerStatus->timeInAir != 0 || actionState == ACTION_STATE_JUMP || actionState == ACTION_STATE_FALLING)
                        && playerStatus->enableCollisionOverlapsCheck
                        && playerStatus->inputDisabledCount != 0)
                    || actionState == ACTION_STATE_LAUNCH
                    || actionState == ACTION_STATE_RIDE
                    || actionState == ACTION_STATE_IDLE
                    || (actionState == ACTION_STATE_USE_SPINNING_FLOWER && playerStatus->actionSubstate == 1)
                )) {
                    break;
                }
            }

            if (!(item->pickupMsgFlags & ITEM_PICKUP_FLAG_NO_SOUND)) {
                if (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_BADGE) {
                    sfx_play_sound(SOUND_D3);
                } else if (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_KEY) {
                    sfx_play_sound(SOUND_D2);
                } else if (item->itemID == ITEM_COIN) {
                    sfx_play_sound_at_position(SOUND_211, 0, item->pos.x, item->pos.y, item->pos.z);
                } else {
                    sfx_play_sound(SOUND_D1);
                }
            }

            ItemPickupIconID = hud_element_create(gItemHudScripts[gItemTable[item->itemID].hudElemID].enabled);
            hud_element_set_flags(ItemPickupIconID, HUD_ELEMENT_FLAG_80);
            hud_element_set_render_pos(ItemPickupIconID, -100, -100);
            item->state = ITEM_PICKUP_STATE_SHOW_GOT_ITEM;

            if (!(item->flags & ITEM_ENTITY_FLAG_2000000)) {
                if (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_CONSUMABLE) {
                    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
                        if (playerData->invItems[i] == ITEM_NONE) {
                            break;
                        }
                    }

                    if (i < ARRAY_COUNT(playerData->invItems)) {
                        playerData->invItems[i] = item->itemID;
                    } else {
                        item->state = ITEM_PICKUP_STATE_SHOW_TOO_MANY;
                        goto block_47; // TODO required to match
                    }
                }

                if (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_KEY) {
                    for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
                        if (playerData->keyItems[i] == ITEM_NONE) {
                            break;
                        }
                    }

                    if (i < ARRAY_COUNT(playerData->keyItems)) {
                        playerData->keyItems[i] = item->itemID;
                    } else {
                        item->state = ITEM_PICKUP_STATE_SHOW_TOO_MANY;
                        goto block_47; // TODO required to match
                    }
                }

                if (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_BADGE) {
                    for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
                        if (playerData->badges[i] == ITEM_NONE) {
                            break;
                        }
                    }

                    if (i < ARRAY_COUNT(playerData->badges)) {
                        playerData->badges[i] = item->itemID;
                    } else {
                        item->state = ITEM_PICKUP_STATE_SHOW_TOO_MANY;
                        goto block_47; // TODO required to match
                    }
                }

                if (item->itemID == ITEM_STAR_PIECE) {
                    playerData->starPieces++;
                    if (playerData->starPieces > MAX_STAR_PIECES) {
                        playerData->starPieces = MAX_STAR_PIECES;
                    }
                }

                if (item->itemID == ITEM_LUCKY_STAR) {
                    playerData->hasActionCommands = TRUE;
                }

                if (item->itemID >= ITEM_HAMMER && item->itemID <= ITEM_ULTRA_HAMMER) {
                    playerData->hammerLevel = item->itemID - ITEM_HAMMER;
                }

                if (item->itemID >= ITEM_BOOTS && item->itemID <= ITEM_ULTRA_BOOTS) {
                    playerData->bootsLevel = item->itemID - ITEM_BOOTS;
                }
            }

block_47: // TODO required to match
            if (item->flags & ITEM_ENTITY_FLAG_SAVE_ON_RECEIPT) {
                set_global_flag(item->boundVar);
            }
            if (item->state == ITEM_PICKUP_STATE_SHOW_TOO_MANY) {
                func_801363A0(item);
                set_window_update(WINDOW_ID_12, (s32) basic_window_update);
                set_window_update(WINDOW_ID_17, (s32) basic_window_update);
                set_window_update(WINDOW_ID_19, (s32) basic_window_update);
            }
            increment_status_bar_disabled();
            ItemPickupStateDelay = 10;
            break;

        case ITEM_PICKUP_STATE_SHOW_GOT_ITEM:
            if (ItemPickupStateDelay == 9) {
                if (   (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_BADGE)
                    || (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_KEY)
                    || (item->itemID == ITEM_STAR_PIECE)
                    || (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR)
                    || (item->flags & ITEM_ENTITY_FLAG_4000000)
                    || (item->pickupMsgFlags & ITEM_PICKUP_FLAG_NO_ANIMS)
                ) {
                    item->pos.x = playerStatus->pos.x;
                    item->pos.y = playerStatus->pos.y + playerStatus->colliderHeight;
                    item->pos.z = playerStatus->pos.z;
                    suggest_player_anim_always_forward(ANIM_MarioW1_Lift);
                }

                if (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR) {
                    fx_got_item_outline(
                        1,
                        item->pos.x,
                        item->pos.y + 8.0f,
                        item->pos.z,
                        1.0f,
                        &ItemPickupGotOutline
                    );
                }
            }

            if (ItemPickupStateDelay < 9) {
                if (   (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_BADGE)
                    || (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_KEY)
                    || (item->itemID == ITEM_STAR_PIECE)
                    || (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR)
                    || (item->flags & ITEM_ENTITY_FLAG_4000000)
                    || (item->pickupMsgFlags & ITEM_PICKUP_FLAG_NO_ANIMS)
                ) {
                    suggest_player_anim_always_forward(ANIM_MarioW1_Lift);
                }
            }

            if (ItemPickupStateDelay == 7) {
                if (   (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_BADGE)
                    || (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_KEY)
                    || (item->itemID == ITEM_STAR_PIECE)
                    || (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR)
                    || (item->flags & ITEM_ENTITY_FLAG_4000000)
                    || (item->pickupMsgFlags & ITEM_PICKUP_FLAG_NO_ANIMS)
                ) {
                    item->flags &= ~ITEM_ENTITY_FLAG_HIDDEN;
                }
            }

            if (ItemPickupStateDelay == 6) {
                func_801363A0(item);
                set_window_update(WINDOW_ID_12, (s32) basic_window_update);
                if (item->itemID != ITEM_STAR_PIECE && item->itemID != ITEM_COIN) {
                    set_window_update(WINDOW_ID_19, (s32) basic_window_update);
                }
            }

            if (ItemPickupStateDelay != 0) {
                ItemPickupStateDelay--;
                break;
            }

            // wait for input
            if (gGameStatusPtr->pressedButtons[0] &
                (BUTTON_STICK_RIGHT | BUTTON_STICK_LEFT | BUTTON_STICK_DOWN | BUTTON_STICK_UP | BUTTON_A | BUTTON_B))
            {
                hide_item_entity(item);
                if (is_player_dismounted()
                    && playerStatus->actionState != ACTION_STATE_USE_SPINNING_FLOWER
                    && !(playerStatus->animFlags & PA_FLAG_NO_OOB_RESPAWN)
                ) {
                    set_action_state(ACTION_STATE_IDLE);
                }

                if (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR) {
                    ItemPickupGotOutline->data.gotItemOutline->timeLeft = 10;
                }
                set_window_update(WINDOW_ID_12, (s32) basic_hidden_window_update);
                set_window_update(WINDOW_ID_19, (s32) basic_hidden_window_update);
                item->state = ITEM_PICKUP_STATE_HIDE_GOT_ITEM;
            }
            break;
        case ITEM_PICKUP_STATE_HIDE_GOT_ITEM:
            if (!(gWindows[WINDOW_ID_12].flags & WINDOW_FLAG_INITIAL_ANIMATION) &&
                !(gWindows[WINDOW_ID_19].flags & WINDOW_FLAG_INITIAL_ANIMATION))
            {
                item->state = ITEM_PICKUP_STATE_CHECK_TUTORIALS;
            }
            break;
        case ITEM_PICKUP_STATE_CHECK_TUTORIALS:
            if ((gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_CONSUMABLE) &&
                !evt_get_variable(NULL, GF_Tutorial_GotItem))
            {
                evt_set_variable(NULL, GF_Tutorial_GotItem, TRUE);
                item->state = ITEM_PICKUP_STATE_SHOW_TUTORIAL;
                break;
            }

            if (item->itemID == ITEM_STAR_PIECE && !evt_get_variable(NULL, GF_Tutorial_GotStarPiece)) {
                evt_set_variable(NULL, GF_Tutorial_GotStarPiece, TRUE);
                item->state = ITEM_PICKUP_STATE_SHOW_TUTORIAL;
                break;
            }
            item->state = ITEM_PICKUP_STATE_DONE;
            break;
        case ITEM_PICKUP_STATE_SHOW_TUTORIAL:
            msgID = MSG_NONE;
            if (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_CONSUMABLE) {
                msgID = MSG_Menus_Tutorial_GotItem;
            }
            if (item->itemID == ITEM_STAR_PIECE) {
                msgID = MSG_Menus_Tutorial_GotStarPiece;
            }
            GotItemTutorialPrinter = msg_get_printer_for_msg(msgID, &GotItemTutorialClosed);
            msg_printer_set_origin_pos(GotItemTutorialPrinter, 0, 0);
            item->state = ITEM_PICKUP_STATE_AWAIT_TUTORIAL;
            break;
        case ITEM_PICKUP_STATE_AWAIT_TUTORIAL:
            if (GotItemTutorialClosed == TRUE) {
                isPickingUpItem = FALSE;
            } else {
                break;
            }
        case ITEM_PICKUP_STATE_DONE:
            if (!(item->flags & ITEM_ENTITY_FLAG_2000000)) {
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                enable_player_input();
                partner_enable_input();
                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            }
            hud_element_free(ItemPickupIconID);
            remove_item_entity_by_reference(item);
            sort_items();
            decrement_status_bar_disabled();
            isPickingUpItem = FALSE;
            break;
        case ITEM_PICKUP_STATE_SHOW_TOO_MANY:
            numEntries = 0;
            if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                // add new item to menu
                itemData = &gItemTable[item->itemID];
                menu->ptrIcon[numEntries] = gItemHudScripts[itemData->hudElemID].enabled;
                menu->userIndex[numEntries] = item->itemID;
                menu->enabled[numEntries] = TRUE;
                menu->nameMsg[numEntries] = itemData->nameMsg;
                menu->descMsg[numEntries] = itemData->shortDescMsg;
                numEntries++;
                // add player inventory to menu
                for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
                    if (playerData->invItems[i] != 0) {
                        itemData = &gItemTable[playerData->invItems[i]];
                        menu->ptrIcon[numEntries] = gItemHudScripts[itemData->hudElemID].enabled;
                        menu->userIndex[numEntries] = playerData->invItems[i];
                        menu->enabled[numEntries] = TRUE;
                        menu->nameMsg[numEntries] = itemData->nameMsg;
                        menu->descMsg[numEntries] = itemData->shortDescMsg;
                        numEntries++;
                    }
                }
                menu->popupType = POPUP_MENU_THROW_AWAY_ITEM;
                menu->numEntries = numEntries;
                menu->initialPos = 0;
                create_standard_popup_menu(menu);
                set_window_update(WINDOW_ID_12, (s32) basic_hidden_window_update);
                set_window_update(WINDOW_ID_17, (s32) basic_hidden_window_update);
                ItemPickupStateDelay = 0;
                item->state = ITEM_PICKUP_STATE_HIDE_TOO_MANY;
            }
            break;
        case ITEM_PICKUP_STATE_HIDE_TOO_MANY:
            if (!(gWindows[WINDOW_ID_12].flags & WINDOW_FLAG_INITIAL_ANIMATION) &&
                !(gWindows[WINDOW_ID_17].flags & WINDOW_FLAG_INITIAL_ANIMATION) &&
                !(gWindows[WINDOW_ID_19].flags & WINDOW_FLAG_INITIAL_ANIMATION))
            {
                item->state = ITEM_PICKUP_STATE_AWAIT_THROW_AWAY;
            }
            break;
        case ITEM_PICKUP_STATE_AWAIT_THROW_AWAY:
            if (ItemPickupStateDelay == 0) {
                D_801568E8 = menu->result;
                if (D_801568E8 == 0) {
                    break;
                }
                hide_popup_menu();
            }
            ItemPickupStateDelay++;
            if (ItemPickupStateDelay >= 15) {
                destroy_popup_menu();
                if (D_801568E8 == 255) {
                    D_801568E8 = 1;
                }
                D_801568EC = menu->userIndex[D_801568E8 - 1];
                hud_element_set_script(ItemPickupIconID, menu->ptrIcon[D_801568E8 - 1]);

                get_item_entity(
                    make_item_entity_delayed(
                        D_801568EC,
                        playerStatus->pos.x,
                        playerStatus->pos.y + playerStatus->colliderHeight,
                        playerStatus->pos.z, 3, 0, 0
                    )
                )->renderGroup = -1;

                if (D_801568E8 >= 2) {
                    playerData->invItems[D_801568E8 - 2] = 0;
                    sort_items();
                    add_item(item->itemID);
                }
                suggest_player_anim_always_forward(ANIM_MarioW1_Lift);
                func_801363A0(item);
                set_window_update(WINDOW_ID_12, (s32) basic_window_update);
                ItemPickupStateDelay = 50;
                item->state = ITEM_PICKUP_STATE_SHOW_THREW_AWAY;
            }
            break;
        case ITEM_PICKUP_STATE_SHOW_THREW_AWAY:
            if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                set_window_update(WINDOW_ID_12, (s32) basic_hidden_window_update);
                item->state = ITEM_PICKUP_STATE_HIDE_THREW_AWAY;
            }
            break;
        case ITEM_PICKUP_STATE_HIDE_THREW_AWAY:
            if (!(gWindows[WINDOW_ID_12].flags & WINDOW_FLAG_INITIAL_ANIMATION) &&
                !(gWindows[WINDOW_ID_17].flags & WINDOW_FLAG_INITIAL_ANIMATION) &&
                !(gWindows[WINDOW_ID_19].flags & WINDOW_FLAG_INITIAL_ANIMATION))
            {
                item->state = ITEM_PICKUP_STATE_THROW_AWAY_DONE;
            }
            break;
        case ITEM_PICKUP_STATE_THROW_AWAY_DONE:
            suggest_player_anim_always_forward(ANIM_Mario1_Idle);
            set_time_freeze_mode(TIME_FREEZE_NORMAL);
            enable_player_input();
            partner_enable_input();
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            hud_element_free(ItemPickupIconID);
            remove_item_entity_by_reference(item);
            sort_items();
            decrement_status_bar_disabled();
            isPickingUpItem = FALSE;
            break;
    }
}

void func_801363A0(ItemEntity* item) {
    ItemData* itemData = &gItemTable[item->itemID];
    s32 itemMsg;
    s32 width;
    s32 posX;
    s32 offsetY;
    s32 posY;
    s32 height;
    s32 v1;

    switch (item->state) {
        case ITEM_PICKUP_STATE_SHOW_GOT_ITEM:
        case ITEM_PICKUP_STATE_SHOW_TOO_MANY:
            if (!(itemData->typeFlags & ITEM_TYPE_FLAG_BADGE)) {
                if (!(item->flags & ITEM_ENTITY_FLAG_4000000) || (item->pickupMsgFlags & ITEM_PICKUP_FLAG_UNKNOWN)) {
                    itemMsg = MSG_Menus_0058;
                } else {
                    itemMsg = MSG_Menus_005A;
                }

                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_1_COIN) {
                    itemMsg = MSG_Menus_005D;
                }
                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_3_STAR_PIECES) {
                    itemMsg = MSG_Menus_005E;
                }
                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_UNIQUE) {
                    itemMsg = MSG_Menus_005C;
                }

                set_message_msg(itemData->nameMsg, 0);

                if (!(gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_KEY) &&
                    item->itemID != ITEM_STAR_PIECE &&
                    !(gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR) &&
                    !(item->pickupMsgFlags & (ITEM_PICKUP_FLAG_1_COIN | ITEM_PICKUP_FLAG_3_STAR_PIECES))) {
                    width = get_msg_width(itemMsg, 0) + 54;
                } else {
                    width = get_msg_width(itemMsg, 0) + 30;
                }
                posX = 160 - width / 2;
                posY = 76;
            } else {
                if (!(item->flags & ITEM_ENTITY_FLAG_4000000) || (item->pickupMsgFlags & ITEM_PICKUP_FLAG_UNKNOWN)) {
                    itemMsg = MSG_Menus_0059;
                } else {
                    itemMsg = MSG_Menus_005B;
                }

                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_1_COIN) {
                    itemMsg = MSG_Menus_005D;
                }
                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_3_STAR_PIECES) {
                    itemMsg = MSG_Menus_005E;
                }
                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_UNIQUE) {
                    itemMsg = MSG_Menus_005C;
                }

                set_message_msg(itemData->nameMsg, 0);
                width = get_msg_width(itemMsg, 0) + 30;
                posX = 160 - width / 2;
                posY = 76;
            }
            height = PickupHeaderWindowHeight[get_msg_lines(itemMsg) - 1];
            if (item->state != ITEM_PICKUP_STATE_SHOW_GOT_ITEM) {
                offsetY = 28;
            } else {
                offsetY = 0;
            }
            if (   !(gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_KEY)
                && !(gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR)
                && !(item->pickupMsgFlags & (ITEM_PICKUP_FLAG_1_COIN | ITEM_PICKUP_FLAG_3_STAR_PIECES)
                && item->itemID != ITEM_STAR_PIECE)
            ) {
                set_window_properties(WINDOW_ID_12, posX, posY - 24 + offsetY, width,
                                    height, WINDOW_PRIORITY_0, draw_content_pickup_item_header, item, -1);
            } else if (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_WORLD_USABLE){
                set_window_properties(WINDOW_ID_12, posX, posY - 24 + offsetY, width,
                                    height, WINDOW_PRIORITY_0, draw_content_pickup_item_header, item, -1);
            } else {
                set_window_properties(WINDOW_ID_12, posX, posY - 24 + offsetY, width,
                                    height, WINDOW_PRIORITY_0, draw_content_pickup_item_header, item, -1);
            }
            if (item->itemID != ITEM_STAR_PIECE && item->itemID != ITEM_COIN) {
                set_window_properties(WINDOW_ID_19, 20, 186, 280, 32, WINDOW_PRIORITY_0, draw_content_pickup_item_desc, item, -1);
            }
            if (item->state != ITEM_PICKUP_STATE_SHOW_GOT_ITEM) {
                width = get_msg_width(MSG_Menus_0060, 0) + 24;
                posX = 160 - width / 2;
                set_window_properties(WINDOW_ID_17, 160 - width / 2, 36, width, 40, WINDOW_PRIORITY_0, draw_content_cant_carry_more, item, -1);
            }
            break;
        case ITEM_PICKUP_STATE_AWAIT_THROW_AWAY:
            set_message_msg(itemData->nameMsg, 0);
            width = get_msg_width(MSG_Menus_005F, 0) + 54;
            posX = 160 - width / 2;
            set_window_properties(WINDOW_ID_12, 160 - width / 2, 76, width, 40, WINDOW_PRIORITY_0, draw_content_pickup_item_header, item, -1);
            break;
    }
}

void draw_content_pickup_item_header(ItemEntity* item, s32 posX, s32 posY) {
    ItemData* itemData = &gItemTable[item->itemID];
    s32 itemMsg;
    s32 offsetY;

    switch (item->state) {
        case ITEM_PICKUP_STATE_SHOW_GOT_ITEM:
        case ITEM_PICKUP_STATE_HIDE_GOT_ITEM:
        case ITEM_PICKUP_STATE_SHOW_TOO_MANY:
        case ITEM_PICKUP_STATE_HIDE_TOO_MANY:
            if (!(itemData->typeFlags & ITEM_TYPE_FLAG_BADGE)) {
                if (!(item->flags & ITEM_ENTITY_FLAG_4000000) || (item->pickupMsgFlags & ITEM_PICKUP_FLAG_UNKNOWN)) {
                    itemMsg = MSG_Menus_0058;
                } else {
                    itemMsg = MSG_Menus_005A;
                }
                set_message_msg(itemData->nameMsg, 0);

                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_1_COIN) {
                    itemMsg = MSG_Menus_005D;
                }
                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_3_STAR_PIECES) {
                    itemMsg = MSG_Menus_005E;
                }
                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_UNIQUE) {
                    itemMsg = MSG_Menus_005C;
                }
            } else {
                if (!(item->flags & ITEM_ENTITY_FLAG_4000000) || (item->pickupMsgFlags & ITEM_PICKUP_FLAG_UNKNOWN)) {
                    itemMsg = MSG_Menus_0059;
                } else {
                    itemMsg = MSG_Menus_005B;
                }

                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_1_COIN) {
                    itemMsg = MSG_Menus_005D;
                }
                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_3_STAR_PIECES) {
                    itemMsg = MSG_Menus_005E;
                }
                if (item->pickupMsgFlags & ITEM_PICKUP_FLAG_UNIQUE) {
                    itemMsg = MSG_Menus_005C;
                }

                set_message_msg(itemData->nameMsg, 0);
            }

            offsetY = PickupMessageWindowYOffsets[get_msg_lines(itemMsg) - 1];

            if ((gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_BADGE)
                || (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_KEY)
                || item->itemID == ITEM_STAR_PIECE
                || (gItemTable[item->itemID].typeFlags & ITEM_TYPE_FLAG_GEAR)
                || (item->pickupMsgFlags & (ITEM_PICKUP_FLAG_1_COIN | ITEM_PICKUP_FLAG_3_STAR_PIECES))
            ) {
                draw_msg(itemMsg, posX + 15, posY + offsetY, 255, MSG_PAL_2F, 0);
            } else {
                draw_msg(itemMsg, posX + 40, posY + offsetY, 255, MSG_PAL_2F, 0);
                if (!(item->pickupMsgFlags & (ITEM_PICKUP_FLAG_1_COIN | ITEM_PICKUP_FLAG_3_STAR_PIECES))) {
                    hud_element_set_render_pos(ItemPickupIconID, posX + 20, posY + 20);
                    hud_element_draw_next(ItemPickupIconID);
                }
            }
            break;
        case ITEM_PICKUP_STATE_SHOW_THREW_AWAY:
        case ITEM_PICKUP_STATE_HIDE_THREW_AWAY:
            set_message_msg(gItemTable[D_801568EC].nameMsg, 0);
            draw_msg(MSG_Menus_005F, posX + 40, posY + 4, 255, MSG_PAL_2F, 0);
            hud_element_set_render_pos(ItemPickupIconID, posX + 20, posY + 20);
            hud_element_draw_next(ItemPickupIconID);
            break;
    }
}

void draw_content_cant_carry_more(ItemEntity* item, s32 x, s32 y) {
    draw_msg(MSG_Menus_0060, x + 12, y + 4, 255, MSG_PAL_34, 0);
}

void draw_content_pickup_item_desc(ItemEntity* item, s32 posX, s32 posY) {
    ItemData* itemData = &gItemTable[item->itemID];
    s32 itemMsg;

    switch (item->state) {
        case ITEM_PICKUP_STATE_SHOW_GOT_ITEM:
        case ITEM_PICKUP_STATE_HIDE_GOT_ITEM:
        case ITEM_PICKUP_STATE_SHOW_TOO_MANY:
        case ITEM_PICKUP_STATE_HIDE_TOO_MANY:
            itemMsg = itemData->shortDescMsg;
            draw_msg(itemMsg, posX + 8, posY, 255, MSG_PAL_STANDARD, 0);
            break;
    }
}
