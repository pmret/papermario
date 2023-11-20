#include "common.h"
#include "hud_element.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

#define MAX_HUD_CACHE_ENTRIES 192

typedef struct HudElementSize {
    s16 width;
    s16 height;
    s16 size;
} HudElementSize;

u8* gHudElementAuxCache = NULL;
s32 gHudElementCacheCapacity = 0x11000;

HudScript HES_Empty = {
    hs_End
};

HudElementSize gHudElementSizes[] = {
    { 8, 8, 32 },
    { 16, 16, 128 },
    { 24, 24, 288 },
    { 32, 32, 512 },
    { 48, 48, 1152 },
    { 64, 64, 2048 },
    { 8, 16, 64 },
    { 16, 8, 64 },
    { 16, 24, 192 },
    { 16, 32, 256 },
    { 64, 32, 1024 },
    { 32, 16, 256 },
    { 12, 12, 72 },
    { 48, 24, 576 },
    { 32, 8, 128 },
    { 24, 8, 96 },
    { 64, 16, 512 },
    { 16, 64, 512 },
    { 192, 32, 3072 },
    { 40, 40, 800 },
    { 24, 16, 192 },
    { 32, 40, 640 },
    { 40, 16, 320 },
    { 40, 24, 480 },
    { 32, 24, 384 },
    { 20, 32, 0 }
};

s16 D_8014F068[] = { 34, 32, 0, 40, 40, 968, 0, 0 };
Gfx gHudElementsDLBackUI[] = {
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT),
    gsDPPipeSync(),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList()
};
Gfx gHudElementsDLFrontUI[] = {
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT),
    gsDPPipeSync(),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList()
};

Vtx D_8014F0C8[] = {
    {
        .v = {
            .ob = { -12, 0, 0},
            .flag = 0,
            .tc = { 0x800, 0x800 },
            .cn = { 0, 0, 0, 255}
        }
    },
    {
        .v = {
            .ob = { 51, 0, 0},
            .flag = 0,
            .tc = { 0, 0x800 },
            .cn = { 0, 0, 0, 255}
        }
    },
    {
        .v = {
            .ob = { 51, 63, 0},
            .flag = 0,
            .tc = { 0, 0 },
            .cn = { 0, 0, 0, 255}
        }
    },
    {
        .v = {
            .ob = { -12, 63, 0},
            .flag = 0,
            .tc = { 0x800, 0 },
            .cn = { 0, 0, 0, 255}
        }
    }
};

Lights1 HudElementLights = gdSPDefLights1(255, 255, 255, 0, 0, 0, 0, 0, 0);

SHIFT_BSS s32 gHudElementsNumber;
SHIFT_BSS s32 D_80159180;
SHIFT_BSS HudElementList* gHudElements;
SHIFT_BSS HudElementList gHudElementsWorld;
SHIFT_BSS HudElementList gHudElementsBattle;
SHIFT_BSS s32* gHudElementCacheSize;
SHIFT_BSS s32 gHudElementCacheSizeWorld;
SHIFT_BSS s32 gHudElementCacheSizeBattle;
SHIFT_BSS HudCacheEntry* gHudElementCacheTableRaster;
SHIFT_BSS HudCacheEntry* gHudElementCacheTablePalette;
SHIFT_BSS HudCacheEntry gHudElementCacheTableRasterWorld[192];
SHIFT_BSS HudCacheEntry gHudElementCacheTablePaletteWorld[192];
SHIFT_BSS HudCacheEntry gHudElementCacheTableRasterBattle[192];
SHIFT_BSS HudCacheEntry gHudElementCacheTablePaletteBattle[192];
SHIFT_BSS u8* gHudElementCacheBufferWorld;
SHIFT_BSS u8* gHudElementCacheBufferBattle;
SHIFT_BSS u8* gHudElementCacheBuffer;

void func_801413F8(void);

void hud_element_load_script(HudElement* hudElement, HudScript* anim) {
    s32* pos = (s32*)anim;
    s32 raster;
    s32 palette;
    s32 preset;
    Vec3s* size;
    HudCacheEntry* entry;
    s32 i;
    s32 capacity;

    if (pos == NULL) {
        return;
    }

    preset = 0;

    while (TRUE) {
        switch (*pos++) {
            case HUD_ELEMENT_OP_End:
                return;
            case HUD_ELEMENT_OP_SetCI:
                pos += 3;
                break;
            case HUD_ELEMENT_OP_SetTileSize:
                preset = *pos++;
                hudElement->drawSizePreset = hudElement->tileSizePreset = preset;
                break;
            case HUD_ELEMENT_OP_SetSizesAutoScale:
            case HUD_ELEMENT_OP_SetSizesFixedScale:
                preset = *pos;
                pos += 2;
                hudElement->drawSizePreset = hudElement->tileSizePreset = preset;
                break;
            case HUD_ELEMENT_OP_SetCustomSize:
                hudElement->customDrawSize.x = hudElement->customImageSize.x = *pos++;
                hudElement->customDrawSize.y = hudElement->customImageSize.y = *pos++;
                hudElement->flags |= HUD_ELEMENT_FLAG_CUSTOM_SIZE;
                break;
            case HUD_ELEMENT_OP_AddTexelOffsetX:
            case HUD_ELEMENT_OP_AddTexelOffsetY:
            case HUD_ELEMENT_OP_SetScale:
            case HUD_ELEMENT_OP_SetAlpha:
            case HUD_ELEMENT_OP_op_15:
            case HUD_ELEMENT_OP_RandomBranch:
            case HUD_ELEMENT_OP_SetFlags:
            case HUD_ELEMENT_OP_ClearFlags:
            case HUD_ELEMENT_OP_PlaySound:
                pos++;
                break;
            case HUD_ELEMENT_OP_SetRGBA:
            case HUD_ELEMENT_OP_SetTexelOffset:
            case HUD_ELEMENT_OP_RandomDelay:
            case HUD_ELEMENT_OP_RandomRestart:
            case HUD_ELEMENT_OP_SetPivot:
                pos += 2;
                break;
            case HUD_ELEMENT_OP_SetImage:
                pos++;
                raster = *pos++;
                palette = *pos++;

                i = 0;
                entry = gHudElementCacheTableRaster;
                while (TRUE) {
                    if (entry->id == -1) {
                        entry->id = raster;
                        entry->data = &gHudElementCacheBuffer[*gHudElementCacheSize];
                        if (!gGameStatusPtr->isBattle) {
                            capacity = gHudElementCacheCapacity;
                        } else {
                            capacity = gHudElementCacheCapacity / 2;
                        }
                        ASSERT(capacity > *gHudElementCacheSize + gHudElementSizes[preset].size);
                        nuPiReadRom((s32)icon_ROM_START + raster, entry->data, gHudElementSizes[preset].size);
                        *gHudElementCacheSize += gHudElementSizes[preset].size;
                        if (!gGameStatusPtr->isBattle) {
                            *pos = i;
                        } else {
                            *pos = (u16)(*pos) | (i << 16);
                        }
                        i++;
                        break;
                    } else if (entry->id == raster) {
                        if (!gGameStatusPtr->isBattle) {
                            *pos = i;
                        } else {
                            *pos = (u16)(*pos) | (i << 16);
                        }
                        break;
                    }
                    entry++;
                    i++;
                }

                pos++;
                ASSERT(i < MAX_HUD_CACHE_ENTRIES);

                entry = gHudElementCacheTablePalette;
                i = 0;
                while (TRUE) {
                    if (entry->id == -1) {
                        entry->id = palette;
                        entry->data = &gHudElementCacheBuffer[*gHudElementCacheSize];
                        if (!gGameStatusPtr->isBattle) {
                            capacity = gHudElementCacheCapacity;
                        } else {
                            capacity = gHudElementCacheCapacity / 2;
                        }
                        ASSERT(capacity > *gHudElementCacheSize + 32);
                        nuPiReadRom((s32)icon_ROM_START + palette, entry->data, 32);
                        *gHudElementCacheSize += 32;
                        if (!gGameStatusPtr->isBattle) {
                            *pos = i;
                        } else {
                            *pos = (u16)(*pos) | (i << 16);
                        }
                        i++;
                        break;
                    } else if (entry->id == palette) {
                        if (!gGameStatusPtr->isBattle) {
                            *pos = i;
                        } else {
                            *pos = (u16)(*pos) | (i << 16);
                        }
                        break;
                    }
                    entry++;
                    i++;
                }

                pos++;
                ASSERT(i < MAX_HUD_CACHE_ENTRIES);
                break;
        }
    }
}

void hud_element_draw_rect(HudElement* hudElement, s16 texSizeX, s16 texSizeY, s16 drawSizeX, s16 drawSizeY,
                           s16 offsetX, s16 offsetY, s32 clamp, s32 dropShadow) {
    u32 isFmtCI4;
    u32 isFmtIA8;
    s32 flipX, flipY;
    s32 fmt;
    s32 widthScale, heightScale;
    s32 texStartX, texStartY;
    u32 isLastTileX, isLastTileY;
    s32 uls, ult, lrs, lrt;
    s32 uly, lry, ulx, lrx;
    s32 masks, maskt;
    s32 screenPosOffsetScaledX, screenPosOffsetScaledY;
    IMG_PTR imageAddr;
    PAL_PTR paletteAddr;
    s16 baseX, baseY;
    s32 tileMode;
    u32 flags1, flags2;
    u16 renderPosX, renderPosY;
    s16 tempX, tempY;

    imageAddr = hudElement->imageAddr;
    paletteAddr = (u16*) hudElement->paletteAddr;

    screenPosOffsetScaledX = hudElement->screenPosOffset.x * 1024;
    screenPosOffsetScaledY = hudElement->screenPosOffset.y * 1024;
    widthScale = hudElement->widthScale;
    screenPosOffsetScaledX /= widthScale;
    heightScale = hudElement->heightScale;
    screenPosOffsetScaledY /= heightScale;

    renderPosX = hudElement->worldPosOffset.x;
    renderPosY = hudElement->worldPosOffset.y;
    renderPosX += hudElement->renderPosX + screenPosOffsetScaledX;
    renderPosY += hudElement->renderPosY + screenPosOffsetScaledY;
    tempX = offsetX;
    tempY = offsetY;
    tempX += renderPosX;
    tempY += renderPosY;

    baseX = tempX;
    baseY = tempY;

    if (dropShadow) {
        baseX = tempX + 2;
        baseY = tempY + 2;
    }

    flags1 = (hudElement->flags & HUD_ELEMENT_FLAG_FMT_CI4);
    isFmtCI4 = flags1 != 0;
    flags1 = (hudElement->flags & HUD_ELEMENT_FLAG_FMT_IA8);
    isFmtIA8 = flags1 != 0;
    flags1 = (hudElement->flags & HUD_ELEMENT_FLAG_FLIPX);
    flipX = flags1 != 0;
    flags2 = (hudElement->flags & HUD_ELEMENT_FLAG_FLIPY);
    flipY = flags2 != 0;

    fmt = 0;
    if (isFmtCI4 == FALSE && isFmtIA8 == FALSE) {
        fmt = 0; // RGBA
    }
    if (isFmtCI4 == TRUE && isFmtIA8 == FALSE) {
        fmt = 1; // CI
    }
    if (isFmtCI4 == FALSE && isFmtIA8 == TRUE) {
        fmt = 2; // IA
    }
    if (isFmtCI4 == TRUE && isFmtIA8 == TRUE) {
        fmt = 2; // IA
    }

    masks = 6;
    maskt = 5;
    if (!(hudElement->flags & HUD_ELEMENT_FLAG_SCALED)) {
        switch (drawSizeX) {
            case 8:
                masks = 3;
                break;
            case 16:
                masks = 4;
                break;
            case 32:
                masks = 5;
                break;
        }

        switch (drawSizeY) {
            case 8:
                maskt = 3;
                break;
            case 16:
                maskt = 4;
                break;
            case 32:
                maskt = 5;
                break;
        }
    }

    switch (fmt) {
        case 0:
            gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
            break;
        case 1:
            if (!(hudElement->flags & HUD_ELEMENT_FLAG_TRANSPARENT)) {
                if (!(hudElement->flags & HUD_ELEMENT_FLAG_ANTIALIASING)) {
                    gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                } else {
                    gDPSetRenderMode(gMainGfxPos++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
                }
            } else {
                if (!(hudElement->flags & HUD_ELEMENT_FLAG_ANTIALIASING)) {
                    gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                } else {
                    gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF | AA_EN, G_RM_CLD_SURF2 | AA_EN);
                }
            }
            gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
            gDPLoadTLUT_pal16(gMainGfxPos++, 0, paletteAddr);
            break;
        case 2:
            gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
            break;
    }

    if (hudElement->flags & HUD_ELEMENT_FLAG_FILTER_TEX) {
        gDPSetTextureFilter(gMainGfxPos++, G_TF_AVERAGE);
    } else {
        gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    }

    ult = 0;
    isLastTileY = FALSE;
    uly = baseY;
    while (TRUE) {
        lry = uly + 1024.0 / heightScale * 32.0;
        lrt = ult + 31;
        if (flipY) {
            texStartY = texSizeY;
        } else {
            texStartY = 0;
        }

        if (lry < 0 || uly > SCREEN_HEIGHT) {
            break;
        }

        if (lry >= SCREEN_HEIGHT) {
            s32 temp = ult + SCREEN_HEIGHT + 31;
            temp -= baseY + lrt;
            lrt = temp - 1;

            lry = SCREEN_HEIGHT;
            isLastTileY = TRUE;
        }

        if (lrt + 1 >= texSizeY) {
            lrt = texSizeY - 1;
            if (texSizeY > 16) {
                lry = baseY + drawSizeY - 1;
            } else {
                lry = baseY + drawSizeY;
            }
            isLastTileY = TRUE;
        }

        isLastTileX = FALSE;
        uls = 0;
        ulx = baseX;
        while (TRUE) {
            lrx = ulx + 1024.0 / widthScale * 64.0;
            lrs = uls + 63;
            if (flipX) {
                texStartX = texSizeX;
            } else {
                texStartX = 0;
            }

            if (lrx < 0  || ulx > SCREEN_WIDTH) {
                break;
            }

            if (lrx >= SCREEN_WIDTH) {
                s32 temp = uls + SCREEN_WIDTH + 63;
                temp -= baseX + lrs;
                lrs = temp - 1;

                lrx = SCREEN_WIDTH;
                isLastTileX = TRUE;
            }

            if (lrs + 1 >= texSizeX) {
                lrs = texSizeX - 1;
                if (texSizeX > 16) {
                    lrx = baseX + drawSizeX - 1;
                } else {
                    lrx = baseX + drawSizeX;
                }
                isLastTileX = TRUE;
            }

            gDPPipeSync(gMainGfxPos++);

            if (isLastTileX ) {
                tileMode = !isLastTileY;
            }
            if (!isLastTileX && !isLastTileY) {
                tileMode = 0;
            }
            if (!isLastTileX && isLastTileY) {
                tileMode = 2;
            }
            if (isLastTileX && isLastTileY) {
                tileMode = 3;
            }

            switch (fmt) {
                case 0:
                    gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    if (!(hudElement->flags & HUD_ELEMENT_FLAG_TRANSPARENT)) {
                        gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    } else {
                        gDPSetCombineMode(gMainGfxPos++, PM_CC_01, PM_CC_02);
                    }

                    if (hudElement->flags & HUD_ELEMENT_FLAG_TRANSPARENT) {
                        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, hudElement->opacity);
                    }

                    if (!flipX && !flipY) {
                        gDPLoadTextureTile(gMainGfxPos++, imageAddr, G_IM_FMT_RGBA, G_IM_SIZ_32b, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                    } else {
                        gDPLoadTextureTile(gMainGfxPos++, imageAddr, G_IM_FMT_RGBA, G_IM_SIZ_32b, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                    }
                    break;
                case 1:
                    if (!dropShadow) {
                        if (hudElement->flags & HUD_ELEMENT_FLAG_TRANSPARENT) {
                            gDPSetCombineMode(gMainGfxPos++, PM_CC_2F, PM_CC_32);
                        } else {
                            gDPSetCombineMode(gMainGfxPos++, PM_CC_2F, PM_CC_32);
                        }

                        if (hudElement->flags & HUD_ELEMENT_FLAG_TRANSPARENT) {
                            gDPSetPrimColor(gMainGfxPos++, 0, 0, hudElement->tint.r, hudElement->tint.g, hudElement->tint.b, hudElement->opacity);
                        } else {
                            gDPSetPrimColor(gMainGfxPos++, 0, 0, hudElement->tint.r, hudElement->tint.g, hudElement->tint.b, 255);
                        }
                    } else {
                        gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                        gDPSetCombineMode(gMainGfxPos++, PM_CC_07, PM_CC_07);
                        gDPSetPrimColor(gMainGfxPos++, 0, 0, 40, 40, 40, 72);
                    }

                    if (!flipX && !flipY) {
                        if (!clamp) {
                            gDPLoadTextureTile_4b(gMainGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                        } else {
                            switch (tileMode) {
                                case 0:
                                    gDPLoadTextureTile_4b(gMainGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 1:
                                    gDPLoadTextureTile_4b(gMainGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 2:
                                    gDPLoadTextureTile_4b(gMainGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 3:
                                    gDPLoadTextureTile_4b(gMainGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                            }
                        }
                    } else {
                        gDPLoadTextureTile_4b(gMainGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                    }
                    break;
                case 2:
                    gDPSetCombineMode(gMainGfxPos++, PM_CC_47, PM_CC_47);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, hudElement->tint.r, hudElement->tint.g, hudElement->tint.b, hudElement->opacity);

                    if (!flipX && !flipY) {
                        if (!clamp) {
                            switch (tileMode) {
                                case 0:
                                    gDPLoadTextureTile(gMainGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 1:
                                    gDPLoadTextureTile(gMainGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 2:
                                    gDPLoadTextureTile(gMainGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 3:
                                    gDPLoadTextureTile(gMainGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                            }
                        } else {
                            gDPLoadTextureTile(gMainGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                        }
                    } else {
                        gDPLoadTextureTile(gMainGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, uls, ult, lrs, lrt, 0,
                                            G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                    }
                    break;
            }

            if (hudElement->flags & HUD_ELEMENT_FLAG_FILTER_TEX) {
                gSPScisTextureRectangle(gMainGfxPos++, ulx * 4, uly * 4, lrx * 4, lry * 4, 0, texStartX * 32 + 16, texStartY * 32 + 16, widthScale, heightScale);
            } else {
                gSPScisTextureRectangle(gMainGfxPos++, ulx * 4, uly * 4, lrx * 4, lry * 4, 0, texStartX * 32, texStartY * 32, widthScale, heightScale);
            }
            if (isLastTileX) {
                break;
            }
            ulx += 1024.0 / widthScale * 64.0;
            uls += 64;
        }

        if (isLastTileY) {
            break;
        }

        ult += 32;
        uly += 1024.0 / heightScale * 32.0;
    }

    gDPPipeSync(gMainGfxPos++);
}

void hud_element_clear_cache(void) {
    s32 i;
    HudCacheEntry* entryRaster;
    HudCacheEntry* entryPalette;

    if (!gGameStatusPtr->isBattle) {
        gHudElements = &gHudElementsWorld;
        gHudElementCacheSize = &gHudElementCacheSizeWorld;
        gHudElementCacheTableRaster = gHudElementCacheTableRasterWorld;
        gHudElementCacheTablePalette = gHudElementCacheTablePaletteWorld;
    } else {
        gHudElements = &gHudElementsBattle;
        gHudElementCacheSize = &gHudElementCacheSizeBattle;
        gHudElementCacheTableRaster = gHudElementCacheTableRasterBattle;
        gHudElementCacheTablePalette = gHudElementCacheTablePaletteBattle;
    }

    if (!gGameStatusPtr->isBattle) {
        gHudElementCacheBuffer = general_heap_malloc(gHudElementCacheCapacity);
        ASSERT(gHudElementCacheBuffer);
        gHudElementCacheBufferWorld = gHudElementCacheBuffer;
        *gHudElementCacheSize = 0;
        entryRaster = gHudElementCacheTableRaster;
        entryPalette = gHudElementCacheTablePalette;
        for (i = 0; i < MAX_HUD_CACHE_ENTRIES; i++) {
            entryRaster[i].id = -1;
            entryPalette[i].id = -1;
        }
    } else {
        if (gHudElementAuxCache == NULL) {
            gHudElementCacheBuffer = general_heap_malloc(gHudElementCacheCapacity / 2);
            ASSERT(gHudElementCacheBuffer);
        } else {
            gHudElementCacheBuffer = gHudElementAuxCache;
        }
        gHudElementCacheBufferBattle = gHudElementCacheBuffer;
        *gHudElementCacheSize = 0;
        entryRaster = gHudElementCacheTableRaster;
        entryPalette = gHudElementCacheTablePalette;
        for (i = 0; i < MAX_HUD_CACHE_ENTRIES; i++) {
            entryRaster[i].id = -1;
            entryPalette[i].id = -1;
        }
    }

    for (i = 0; i < ARRAY_COUNT(*gHudElements); i++) {
        (*gHudElements)[i] = NULL;
    }

    gHudElementsNumber = 0;
    D_80159180 = 0;
    func_801413F8();
}

#if VERSION_PAL
extern Addr D_80200000;
#endif

void init_hud_element_list(void) {
    if (!gGameStatusPtr->isBattle) {
        if (gHudElementCacheBufferBattle != NULL) {
#if VERSION_PAL
            if (gHudElementCacheBufferBattle != D_80200000) {
                general_heap_free(gHudElementCacheBufferBattle);
            }
#else
            general_heap_free(gHudElementCacheBufferBattle);
#endif
            gHudElementCacheBufferBattle = NULL;
        }

        gHudElements = &gHudElementsWorld;
        gHudElementCacheSize = &gHudElementCacheSizeWorld;
        gHudElementCacheTableRaster = gHudElementCacheTableRasterWorld;
        gHudElementCacheTablePalette = gHudElementCacheTablePaletteWorld;
        gHudElementCacheBuffer = gHudElementCacheBufferWorld;
    } else {
        gHudElements = &gHudElementsBattle;
        gHudElementCacheSize = &gHudElementCacheSizeBattle;
        gHudElementCacheTableRaster = gHudElementCacheTableRasterBattle;
        gHudElementCacheTablePalette = gHudElementCacheTablePaletteBattle;
        gHudElementCacheBuffer = gHudElementCacheBufferBattle;
    }

    gHudElementsNumber = 0;
    D_80159180 = 0;
}

void func_801413F8(void) {
    set_cam_viewport(CAM_3, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    gCameras[CAM_3].updateMode = CAM_UPDATE_MODE_2;
    gCameras[CAM_3].needsInit = TRUE;
    gCameras[CAM_3].lookAt_dist = 15551;
    gCameras[CAM_3].nearClip = CAM_NEAR_CLIP;
    gCameras[CAM_3].auxPitch = 0;
    gCameras[CAM_3].auxBoomLength = 0;
    gCameras[CAM_3].auxBoomPitch = 0;
    gCameras[CAM_3].lookAt_obj_target.z = 0;
    gCameras[CAM_3].farClip = 0x4000;
    gCameras[CAM_3].bgColor[0] = 0;
    gCameras[CAM_3].bgColor[1] = 0;
    gCameras[CAM_3].bgColor[2] = 0;
    gCameras[CAM_3].lookAt_obj_target.x = 160.0f;
    gCameras[CAM_3].lookAt_obj_target.y = -120.0f;
    gCameras[CAM_3].vfov = 1.0f;
    gCameras[CAM_3].flags &= ~(CAMERA_FLAG_DISABLED | CAMERA_FLAG_LEAD_PLAYER);
}

s32 hud_element_create(HudScript* anim) {
    HudElement* hudElement;
    s32 id;

    for (id = 0; id < ARRAY_COUNT(*gHudElements); id++) {
        if ((*gHudElements)[id] == NULL) {
            break;
        }
    }

    ASSERT(id < ARRAY_COUNT(*gHudElements));

    (*gHudElements)[id] = hudElement = heap_malloc(sizeof(*hudElement));
    gHudElementsNumber += 1;

    ASSERT(hudElement != NULL);

    hudElement->flags = HUD_ELEMENT_FLAG_INITIALIZED;
    hudElement->readPos = anim;
    if (anim == NULL) {
        hudElement->readPos = &HES_Empty;
    }
    hudElement->updateTimer = 1;
    hudElement->drawSizePreset = -1;
    hudElement->tileSizePreset = -1;
    hudElement->renderPosX = 0;
    hudElement->renderPosY = 0;
    hudElement->loopStartPos = anim;
    hudElement->widthScale = X10(1.0f);
    hudElement->heightScale = X10(1.0f);
    hudElement->anim = hudElement->readPos;
    hudElement->uniformScale = 1.0f;
    hudElement->screenPosOffset.x = 0;
    hudElement->screenPosOffset.y = 0;
    hudElement->worldPosOffset.x = 0;
    hudElement->worldPosOffset.y = 0;
    hudElement->worldPosOffset.z = 0;
    hudElement->opacity = 255;
    hudElement->tint.r = 255;
    hudElement->tint.g = 255;
    hudElement->tint.b = 255;

    if (gGameStatusPtr->isBattle) {
        hudElement->flags |= HUD_ELEMENT_FLAG_BATTLE;
        id |= HUD_ELEMENT_BATTLE_ID_MASK;
    }

    hud_element_load_script(hudElement, hudElement->readPos);
    while (hud_element_update(hudElement) != 0);

    return id;
}

// TODO not ideal match - should be able to put loop iterator in the loop def, but can't
void update_hud_elements(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gHudElements);) {
        HudElement* elem = (*gHudElements)[i];

        if (elem != NULL && elem->flags && !(elem->flags & HUD_ELEMENT_FLAG_DISABLED)) {
            if (elem->flags & HUD_ELEMENT_FLAG_DELETE) {
                hud_element_free(i);
                i++;
            } else if (elem->readPos != NULL) {
                elem->updateTimer--;
                if (elem->updateTimer == 0) {
                    while (hud_element_update(elem) != 0);
                }
                if (elem->flags & HUD_ELEMENT_FLAG_FIXEDSCALE) {
                    elem->unkImgScale[0] += elem->deltaSizeX;
                    elem->unkImgScale[1] += elem->deltaSizeY;
                }
                i++;
            } else {
                break;
            }
        } else {
            i++;
        }
    }
}

s32 hud_element_update(HudElement* hudElement) {
    HudCacheEntry* entryRaster;
    HudCacheEntry* entryPalette;
    s32 i;
    s32 drawSizePreset;
    s32 tileSizePreset;
    u8 sizePreset;
    f32 xScaled, yScaled;
    s32 imageWidth, imageHeight, drawWidth, drawHeight;
    u32 min, max;
    u32 flags;
    s32 raster, palette;
    s32 s1, s2;
    s32 arg1, arg2;
    f32 uniformScale;
    HudScript* newReadPos;

    HudTransform* hudTransform = hudElement->hudTransform;
    s32* nextPos = (s32*)hudElement->readPos;

    switch (*nextPos++) {
        case HUD_ELEMENT_OP_End:
            hudElement->updateTimer = 60;
            flags = hudElement->flags;
            hudElement->flags = flags | HUD_ELEMENT_FLAG_ANIMATION_FINISHED;
            break;
        case HUD_ELEMENT_OP_Delete:
            hudElement->updateTimer = 60;
            hudElement->flags |= HUD_ELEMENT_FLAG_DELETE;
            break;
        case HUD_ELEMENT_OP_UseIA8:
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->flags |= HUD_ELEMENT_FLAG_FMT_IA8;
            return TRUE;
        case HUD_ELEMENT_OP_SetVisible:
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->flags |= HUD_ELEMENT_FLAG_FMT_CI4;
            return TRUE;
        case HUD_ELEMENT_OP_SetHidden:
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->flags &= ~HUD_ELEMENT_FLAG_FMT_CI4;
            return TRUE;
        case HUD_ELEMENT_OP_SetFlags:
            s1 = *nextPos++;
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->flags |= s1;
            return TRUE;
        case HUD_ELEMENT_OP_ClearFlags:
            s1 = *nextPos++;
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->flags &= ~s1;
            return TRUE;
        case HUD_ELEMENT_OP_SetRGBA:
            hudElement->updateTimer = *nextPos++;
            hudElement->imageAddr = (u8*)*nextPos++;
            hudElement->readPos = (HudScript*)nextPos;

            if (hudElement->flags & HUD_ELEMENT_FLAG_MEMOFFSET) {
                hudElement->imageAddr += hudElement->memOffset;
            }

            if (hudElement->flags & HUD_ELEMENT_FLAG_FIXEDSCALE) {
                if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                    tileSizePreset = hudElement->tileSizePreset;
                    drawSizePreset = hudElement->drawSizePreset;
                    imageWidth = gHudElementSizes[tileSizePreset].width;
                    imageHeight = gHudElementSizes[tileSizePreset].height;
                    drawWidth = gHudElementSizes[drawSizePreset].width;
                    drawHeight = gHudElementSizes[drawSizePreset].height;
                } else {
                    imageWidth = hudElement->customImageSize.x;
                    imageHeight = hudElement->customImageSize.y;
                    drawWidth = hudElement->customDrawSize.x;
                    drawHeight = hudElement->customDrawSize.y;
                }

                if (!(hudElement->flags & HUD_ELEMENT_FLAG_200)) {
                    hudElement->flags |= HUD_ELEMENT_FLAG_200;
                    hudElement->unkImgScale[0] = imageWidth;
                    hudElement->unkImgScale[1] = imageHeight;
                    hudElement->deltaSizeX = ((f32)drawWidth - (f32)imageWidth) / (f32)hudElement->updateTimer;
                    hudElement->deltaSizeY = ((f32)drawHeight - (f32)imageHeight) / (f32)hudElement->updateTimer;
                } else {
                    hudElement->flags &= ~HUD_ELEMENT_FLAG_200;
                    hudElement->unkImgScale[0] = drawWidth;
                    hudElement->unkImgScale[1] = drawHeight;
                    hudElement->deltaSizeX = ((f32)imageWidth - (f32)drawWidth) / (f32)hudElement->updateTimer;
                    hudElement->deltaSizeY = ((f32)imageHeight - (f32)drawHeight) / (f32)hudElement->updateTimer;
                }
            }
            break;
        case HUD_ELEMENT_OP_SetCI:
            hudElement->updateTimer = *nextPos++;
            hudElement->imageAddr = (u8*)*nextPos++;
            hudElement->paletteAddr = (u8*)*nextPos++;
            hudElement->readPos = (HudScript*)nextPos;

            if (hudElement->flags & HUD_ELEMENT_FLAG_MEMOFFSET) {
                hudElement->imageAddr += hudElement->memOffset;
                hudElement->paletteAddr += hudElement->memOffset;
            }

            if (hudElement->flags & HUD_ELEMENT_FLAG_FIXEDSCALE) {
                if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                    tileSizePreset = hudElement->tileSizePreset;
                    drawSizePreset = hudElement->drawSizePreset;
                    imageWidth = gHudElementSizes[tileSizePreset].width;
                    imageHeight = gHudElementSizes[tileSizePreset].height;
                    drawWidth = gHudElementSizes[drawSizePreset].width;
                    drawHeight = gHudElementSizes[drawSizePreset].height;
                } else {
                    imageWidth = hudElement->customImageSize.x;
                    imageHeight = hudElement->customImageSize.y;
                    drawWidth = hudElement->customDrawSize.x;
                    drawHeight = hudElement->customDrawSize.y;
                }

                if (!(hudElement->flags & HUD_ELEMENT_FLAG_200)) {
                    hudElement->flags |= HUD_ELEMENT_FLAG_200;
                    hudElement->unkImgScale[0] = imageWidth;
                    hudElement->unkImgScale[1] = imageHeight;
                    hudElement->deltaSizeX = ((f32)drawWidth - (f32)imageWidth) / (f32)hudElement->updateTimer;
                    hudElement->deltaSizeY = ((f32)drawHeight - (f32)imageHeight) / (f32)hudElement->updateTimer;
                } else {
                    hudElement->flags &= ~HUD_ELEMENT_FLAG_200;
                    hudElement->unkImgScale[0] = drawWidth;
                    hudElement->unkImgScale[1] = drawHeight;
                    hudElement->deltaSizeX = ((f32)imageWidth - (f32)drawWidth) / (f32)hudElement->updateTimer;
                    hudElement->deltaSizeY = ((f32)imageHeight - (f32)drawHeight) / (f32)hudElement->updateTimer;
                }
            }
            break;
        case HUD_ELEMENT_OP_SetImage:
            hudElement->updateTimer = *nextPos++;

            if (!(hudElement->flags & HUD_ELEMENT_FLAG_BATTLE)) {
                entryRaster = gHudElementCacheTableRasterWorld;
                entryPalette = gHudElementCacheTablePaletteWorld;
            } else {
                entryRaster = gHudElementCacheTableRasterBattle;
                entryPalette = gHudElementCacheTablePaletteBattle;
            }

            i = 0;
            while (TRUE) {
                if (entryRaster[i].id == *nextPos) {
                    break;
                }
                ASSERT(++i < MAX_HUD_CACHE_ENTRIES);
            }

            nextPos++;
            hudElement->imageAddr = entryRaster[i].data;

            i = 0;
            while (TRUE) {
                if (entryPalette[i].id == *nextPos) {
                    break;
                }
                ASSERT(++i < MAX_HUD_CACHE_ENTRIES);
            }
            hudElement->paletteAddr = entryPalette[i].data;
            nextPos += 3;
            hudElement->readPos = (HudScript*)nextPos;

            if (hudElement->flags & HUD_ELEMENT_FLAG_FIXEDSCALE) {
                if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                    tileSizePreset = hudElement->tileSizePreset;
                    drawSizePreset = hudElement->drawSizePreset;
                    imageWidth = gHudElementSizes[tileSizePreset].width;
                    imageHeight = gHudElementSizes[tileSizePreset].height;
                    drawWidth = gHudElementSizes[drawSizePreset].width;
                    drawHeight = gHudElementSizes[drawSizePreset].height;
                } else {
                    imageWidth = hudElement->customImageSize.x;
                    imageHeight = hudElement->customImageSize.y;
                    drawWidth = hudElement->customDrawSize.x;
                    drawHeight = hudElement->customDrawSize.y;
                }

                if (!(hudElement->flags & HUD_ELEMENT_FLAG_200)) {
                    hudElement->flags |= HUD_ELEMENT_FLAG_200;
                    hudElement->unkImgScale[0] = imageWidth;
                    hudElement->unkImgScale[1] = imageHeight;
                    hudElement->deltaSizeX = ((f32)drawWidth - (f32)imageWidth) / (f32)hudElement->updateTimer;
                    hudElement->deltaSizeY = ((f32)drawHeight - (f32)imageHeight) / (f32)hudElement->updateTimer;
                } else {
                    hudElement->flags &= ~HUD_ELEMENT_FLAG_200;
                    hudElement->unkImgScale[0] = drawWidth;
                    hudElement->unkImgScale[1] = drawHeight;
                    hudElement->deltaSizeX = ((f32)imageWidth - (f32)drawWidth) / (f32)hudElement->updateTimer;
                    hudElement->deltaSizeY = ((f32)imageHeight - (f32)drawHeight) / (f32)hudElement->updateTimer;
                }
            }
            break;
        case HUD_ELEMENT_OP_Restart:
            hudElement->readPos = hudElement->loopStartPos;
            return TRUE;
        case HUD_ELEMENT_OP_Loop:
            hudElement->loopStartPos = (HudScript*)nextPos;
            hudElement->readPos = (HudScript*)nextPos;
            return TRUE;
        case HUD_ELEMENT_OP_RandomRestart:
            s1 = *nextPos++;
            s2 = *nextPos++;
            if (rand_int(s1) < s2) {
                hudElement->readPos = hudElement->loopStartPos;
            } else {
                hudElement->readPos = (HudScript*)nextPos;
            }
            return TRUE;
        case HUD_ELEMENT_OP_SetTileSize:
            sizePreset = *nextPos++;
            hudElement->widthScale = X10(1);
            hudElement->heightScale = X10(1);
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->drawSizePreset = sizePreset;
            hudElement->tileSizePreset = sizePreset;
            hudElement->flags &= ~HUD_ELEMENT_FLAG_FIXEDSCALE;
            hudElement->flags &= ~HUD_ELEMENT_FLAG_REPEATED;
            return TRUE;
        case HUD_ELEMENT_OP_SetSizesAutoScale:
            tileSizePreset = *nextPos++;
            arg2 = *nextPos++;

            hudElement->readPos = (HudScript*)nextPos;
            hudElement->tileSizePreset = tileSizePreset;
            hudElement->drawSizePreset = arg2;

            imageWidth = gHudElementSizes[tileSizePreset].width;
            imageHeight = gHudElementSizes[tileSizePreset].height;
            drawWidth = gHudElementSizes[arg2].width;
            drawHeight = gHudElementSizes[arg2].height;

            xScaled = (f32) drawWidth / (f32) imageWidth;
            yScaled = (f32) drawHeight / (f32) imageHeight;

            xScaled = 1.0f / xScaled;
            yScaled = 1.0f / yScaled;

            hudElement->widthScale = X10(xScaled);
            hudElement->heightScale = X10(yScaled);

            hudElement->flags &= ~HUD_ELEMENT_FLAG_FIXEDSCALE;
            hudElement->flags |= HUD_ELEMENT_FLAG_REPEATED;
            return TRUE;
        case HUD_ELEMENT_OP_SetSizesFixedScale:
            tileSizePreset = *nextPos++;
            drawSizePreset = *nextPos++;

            hudElement->widthScale = X10(1);
            hudElement->heightScale = X10(1);
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->tileSizePreset = tileSizePreset;
            hudElement->drawSizePreset = drawSizePreset;
            hudElement->flags |= HUD_ELEMENT_FLAG_FIXEDSCALE;
            hudElement->flags &= ~HUD_ELEMENT_FLAG_REPEATED;
            hudElement->flags &= ~HUD_ELEMENT_FLAG_200;
            return TRUE;
        case HUD_ELEMENT_OP_AddTexelOffsetX:
            s1 = *nextPos++;
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->screenPosOffset.x += s1;
            return TRUE;
        case HUD_ELEMENT_OP_AddTexelOffsetY:
            s2 = *nextPos++;
            if (!(hudElement->flags & HUD_ELEMENT_FLAG_FLIPY)) {
                hudElement->screenPosOffset.y += s2;
            } else {
                hudElement->screenPosOffset.y -= s2;
            }
            hudElement->readPos = (HudScript*)nextPos;
            return TRUE;
        case HUD_ELEMENT_OP_SetTexelOffset:
            s1 = *nextPos++;
            s2 = *nextPos++;
            hudElement->screenPosOffset.x = s1;
            if (!(hudElement->flags & HUD_ELEMENT_FLAG_FLIPY)) {
                hudElement->screenPosOffset.y = s2;
            } else {
                hudElement->screenPosOffset.y = -s2;
            }
            hudElement->readPos = (HudScript*)nextPos;
            return TRUE;
        case HUD_ELEMENT_OP_SetScale:
            uniformScale = (f32)*nextPos++;
            uniformScale /= 65536;
            hudElement->uniformScale = uniformScale;
            if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                imageWidth = gHudElementSizes[hudElement->tileSizePreset].width;
                imageHeight = gHudElementSizes[hudElement->tileSizePreset].height;
                drawWidth = gHudElementSizes[hudElement->drawSizePreset].width;
                drawHeight = gHudElementSizes[hudElement->drawSizePreset].height;
            } else {
                imageWidth = hudElement->customImageSize.x;
                imageHeight = hudElement->customImageSize.y;
                drawWidth = hudElement->customDrawSize.x;
                drawHeight = hudElement->customDrawSize.y;
            }

            hudElement->sizeX = drawWidth * uniformScale;
            hudElement->sizeY = drawHeight * uniformScale;

            xScaled = (f32) drawWidth / (f32) imageWidth * uniformScale;
            yScaled = (f32) drawHeight / (f32) imageHeight * uniformScale;

            xScaled = 1.0f / xScaled;
            yScaled = 1.0f / yScaled;

            hudElement->widthScale = X10(xScaled);
            hudElement->heightScale = X10(yScaled);

            hudElement->readPos = (HudScript*)nextPos;
            hudElement->flags &= ~HUD_ELEMENT_FLAG_FIXEDSCALE;
            hudElement->flags |= HUD_ELEMENT_FLAG_REPEATED | HUD_ELEMENT_FLAG_SCALED;
            return TRUE;
        case HUD_ELEMENT_OP_SetAlpha:
            s1 = *nextPos++;
            hudElement->opacity = s1;
            hudElement->flags |= HUD_ELEMENT_FLAG_TRANSPARENT;
            if (hudElement->opacity == 255) {
                hudElement->flags &= ~HUD_ELEMENT_FLAG_TRANSPARENT;
            }
            hudElement->readPos = (HudScript*)nextPos;
            return TRUE;
        case HUD_ELEMENT_OP_RandomDelay:
            s1 = *nextPos++;
            s2 = *nextPos++;
            hudElement->updateTimer = rand_int(s2 - s1) + s1;
            hudElement->readPos = (HudScript*)nextPos;
            break;
        case HUD_ELEMENT_OP_SetCustomSize:
            hudElement->customDrawSize.x = hudElement->customImageSize.x = *nextPos++;
            hudElement->customDrawSize.y = hudElement->customImageSize.y = *nextPos++;
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->widthScale = X10(1);
            hudElement->heightScale = X10(1);
            hudElement->drawSizePreset = 0;
            hudElement->tileSizePreset = 0;
            hudElement->flags &= ~HUD_ELEMENT_FLAG_FIXEDSCALE;
            hudElement->flags &= ~HUD_ELEMENT_FLAG_REPEATED;
            hudElement->flags |= HUD_ELEMENT_FLAG_CUSTOM_SIZE;
            return TRUE;
        case HUD_ELEMENT_OP_op_15:
            s1 = *nextPos++;
            hudElement->readPos = (HudScript*)nextPos;
            hudElement->flags &= ~(HUD_ELEMENT_FLAG_1000000 | HUD_ELEMENT_FLAG_2000000 | HUD_ELEMENT_FLAG_4000000 | HUD_ELEMENT_FLAG_8000000);
            hudElement->flags |= s1 << 24;
            return TRUE;
        case HUD_ELEMENT_OP_RandomBranch:
            s1 = *nextPos++;
            newReadPos = (HudScript*)nextPos[rand_int(s1 - 1)];
            hudElement->readPos = newReadPos;
            hud_element_load_script(hudElement, newReadPos);
            return TRUE;
        case HUD_ELEMENT_OP_PlaySound:
            arg2 = *nextPos++;
            sfx_play_sound(arg2);
            hudElement->readPos = (HudScript*)nextPos;
            return TRUE;
        case HUD_ELEMENT_OP_SetPivot:
            arg1 = *nextPos++;
            arg2 = *nextPos++;
            hudElement->readPos = (HudScript*)nextPos;
            if (hudElement->flags & HUD_ELEMENT_FLAG_TRANSFORM) {
                hudTransform->pivot.x = arg1;
                // TODO find better match
                do {
                    hudTransform->pivot.y = arg2;
                } while (0);
            }
            return TRUE;
        case HUD_ELEMENT_OP_op_16:
            break;
    }

    return FALSE;
}

void render_hud_elements_backUI(void) {
    s32 i, count, j;
    s32 sortedElements[ARRAY_COUNT(*gHudElements)];
    s32 el1, el2;
    s32 texSizeX, texSizeY;
    s32 drawSizeX, drawSizeY, offsetX, offsetY;
    HudElement* hudElement;

    D_80159180++;
    if (D_80159180 > 2) {
        D_80159180 = 0;
    }
    gSPDisplayList(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(gHudElementsDLBackUI));

    count = 0;
    for (i = 0; i < ARRAY_COUNT(*gHudElements); i++) {
        hudElement = (*gHudElements)[i];
        if (hudElement != NULL) {
            s32 flags = hudElement->flags;
            if (flags && !(flags & HUD_ELEMENT_FLAG_DISABLED)) {
                if (!(flags & (HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_TRANSFORM | HUD_ELEMENT_FLAG_200000 | HUD_ELEMENT_FLAG_10000000 | HUD_ELEMENT_FLAG_40000000))) {
                    if (!(flags & HUD_ELEMENT_FLAG_FRONTUI) && hudElement->drawSizePreset >= 0) {
                        sortedElements[count++] = i;
                    }
                }
            }
        }
    }

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            el1 = sortedElements[i];
            el2 = sortedElements[j];
            if ((*gHudElements)[el1]->worldPosOffset.z < (*gHudElements)[el2]->worldPosOffset.z) {
                sortedElements[i] = el2;
                sortedElements[j] = el1;
            }
        }
    }

    for (i = 0; i < count; i++) {
        hudElement = (*gHudElements)[sortedElements[i]];

        if (hudElement->readPos == NULL) {
            break;
        }

        if (!(hudElement->flags & HUD_ELEMENT_FLAG_FIXEDSCALE)) {
            if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                texSizeX = gHudElementSizes[hudElement->tileSizePreset].width;
                texSizeY = gHudElementSizes[hudElement->tileSizePreset].height;
            } else {
                texSizeX = hudElement->customImageSize.x;
                texSizeY = hudElement->customImageSize.y;
            }

            if (!(hudElement->flags & HUD_ELEMENT_FLAG_SCALED)) {
                if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                    drawSizeX = gHudElementSizes[hudElement->drawSizePreset].width;
                    drawSizeY = gHudElementSizes[hudElement->drawSizePreset].height;
                    offsetX = -drawSizeX / 2;
                    offsetY = -drawSizeY / 2;
                } else {
                    // TODO find better match
                    do {
                    drawSizeX = hudElement->customDrawSize.x;
                    drawSizeY = hudElement->customDrawSize.y;
                    offsetX = -drawSizeX / 2;
                    } while (0);
                    offsetY = -drawSizeY / 2;

                }
            } else {
                drawSizeX = hudElement->sizeX;
                drawSizeY = hudElement->sizeY;
                offsetX = -drawSizeX / 2;
                offsetY = -drawSizeY / 2;
            }

            if (!(hudElement->flags & HUD_ELEMENT_FLAG_REPEATED)) {
                if (hudElement->flags & HUD_ELEMENT_FLAG_DROP_SHADOW) {
                    hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, TRUE);
                }
                hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, FALSE);
            } else {
                if (hudElement->flags & HUD_ELEMENT_FLAG_DROP_SHADOW) {
                    hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
                }
                hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
            }
        } else {
            f32 xScaled, yScaled;

            if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                texSizeX = gHudElementSizes[hudElement->tileSizePreset].width;
                texSizeY = gHudElementSizes[hudElement->tileSizePreset].height;
            } else {
                texSizeX = hudElement->customImageSize.x;
                texSizeY = hudElement->customImageSize.y;
            }

            drawSizeX = hudElement->unkImgScale[0];
            drawSizeY = hudElement->unkImgScale[1];

            offsetX = -hudElement->unkImgScale[0] / 2;
            offsetY = -hudElement->unkImgScale[1] / 2;

            xScaled = (f32) drawSizeX / (f32) texSizeX;
            yScaled = (f32) drawSizeY / (f32) texSizeY;

            xScaled = 1.0f / xScaled;
            yScaled = 1.0f / yScaled;

            hudElement->widthScale = X10(xScaled);
            hudElement->heightScale = X10(yScaled);

            if (hudElement->flags & HUD_ELEMENT_FLAG_DROP_SHADOW) {
                hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
            }
            hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
        }
    }
}

void render_hud_elements_frontUI(void) {
    s32 i, count, j;
    s32 sortedElements[ARRAY_COUNT(*gHudElements)];
    s32 el1, el2;
    s32 texSizeX, texSizeY;
    s32 drawSizeX, drawSizeY, offsetX, offsetY;
    HudElement* hudElement;

    gSPDisplayList(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(gHudElementsDLFrontUI));

    count = 0;
    for (i = 0; i < ARRAY_COUNT(*gHudElements); i++) {
        hudElement = (*gHudElements)[i];
        if (hudElement != NULL) {
            s32 flags = hudElement->flags;
            if (flags && !(flags & HUD_ELEMENT_FLAG_DISABLED)) {
                if (!(flags & (HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_TRANSFORM | HUD_ELEMENT_FLAG_200000 | HUD_ELEMENT_FLAG_10000000))) {
                    if ((flags & HUD_ELEMENT_FLAG_FRONTUI) && hudElement->drawSizePreset >= 0) {
                        sortedElements[count++] = i;
                    }
                }
            }
        }
    }

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            el1 = sortedElements[i];
            el2 = sortedElements[j];
            if ((*gHudElements)[el1]->worldPosOffset.z < (*gHudElements)[el2]->worldPosOffset.z) {
                sortedElements[i] = el2;
                sortedElements[j] = el1;
            }
        }
    }

    for (i = 0; i < count; i++) {
        hudElement = (*gHudElements)[sortedElements[i]];
        if (!(hudElement->flags & HUD_ELEMENT_FLAG_FIXEDSCALE)) {
            if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                texSizeX = gHudElementSizes[hudElement->tileSizePreset].width;
                texSizeY = gHudElementSizes[hudElement->tileSizePreset].height;
            } else {
                texSizeX = hudElement->customImageSize.x;
                texSizeY = hudElement->customImageSize.y;
            }

            if (!(hudElement->flags & HUD_ELEMENT_FLAG_SCALED)) {
                if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                    drawSizeX = gHudElementSizes[hudElement->drawSizePreset].width;
                    drawSizeY = gHudElementSizes[hudElement->drawSizePreset].height;
                    offsetX = -drawSizeX / 2;
                    offsetY = -drawSizeY / 2;
                } else {
                    // TODO find better match
                    do {
                    drawSizeX = hudElement->customDrawSize.x;
                    drawSizeY = hudElement->customDrawSize.y;
                    offsetX = -drawSizeX / 2;
                    } while (0);
                    offsetY = -drawSizeY / 2;

                }
            } else {
                drawSizeX = hudElement->sizeX;
                drawSizeY = hudElement->sizeY;
                offsetX = -drawSizeX / 2;
                offsetY = -drawSizeY / 2;
            }

            if (!(hudElement->flags & HUD_ELEMENT_FLAG_REPEATED)) {
                if (hudElement->flags & HUD_ELEMENT_FLAG_DROP_SHADOW) {
                    hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, TRUE);
                }
                hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, FALSE);
            } else {
                if (hudElement->flags & HUD_ELEMENT_FLAG_DROP_SHADOW) {
                    hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
                }
                hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
            }
        } else {
            f32 xScaled, yScaled;

            if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                texSizeX = gHudElementSizes[hudElement->drawSizePreset].width;
                texSizeY = gHudElementSizes[hudElement->drawSizePreset].height;
            } else {
                texSizeX = hudElement->customImageSize.x;
                texSizeY = hudElement->customImageSize.y;
            }

            drawSizeX = hudElement->unkImgScale[0];
            drawSizeY = hudElement->unkImgScale[1];

            offsetX = -hudElement->unkImgScale[0] / 2;
            offsetY = -hudElement->unkImgScale[1] / 2;

            xScaled = (f32) drawSizeX / (f32) texSizeX;
            yScaled = (f32) drawSizeY / (f32) texSizeY;

            xScaled = 1.0f / xScaled;
            yScaled = 1.0f / yScaled;

            hudElement->widthScale = X10(xScaled);
            hudElement->heightScale = X10(yScaled);

            if (hudElement->flags & HUD_ELEMENT_FLAG_DROP_SHADOW) {
                hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
            }
            hud_element_draw_rect(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
        }
    }
}

void render_hud_element(HudElement* hudElement) {
    Matrix4f sp20;
    Matrix4f sp60;
    Matrix4f spA0;
    Matrix4f spE0;
    Matrix4f sp120;
    Matrix4f sp160;
    Matrix4f sp1A0;
    Matrix4f sp1E0;
    Matrix4f sp220;
    Matrix4f sp260;
    ImgFXTexture ifxImg;
    f32 xScaleFactor, yScaleFactor;
    s32 height, width;
    HudTransform* transform;
    s32 mode;
    u32 flags;
    IMG_PTR raster;
    PAL_PTR palette;
    u32 a0, v1;
    s32 ulx, uly, lrx, lry;
    Vtx* vtx;
    Vtx* vtx2;

    if (hudElement->flags & HUD_ELEMENT_FLAG_FILTER_TEX) {
        gDPSetTextureFilter(gMainGfxPos++, G_TF_AVERAGE);
    } else {
        gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    }

    if (!(hudElement->flags & HUD_ELEMENT_FLAG_FIXEDSCALE)) {
        xScaleFactor = 1.0f;
        yScaleFactor = 1.0f;
    } else {
        if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
            xScaleFactor = gHudElementSizes[hudElement->tileSizePreset].width;
            yScaleFactor = gHudElementSizes[hudElement->tileSizePreset].height;
        } else {
            xScaleFactor = hudElement->customImageSize.x;
            yScaleFactor = hudElement->customImageSize.y;
        }
        xScaleFactor /= hudElement->unkImgScale[0];
        xScaleFactor = 1.0f / xScaleFactor;
        yScaleFactor /= hudElement->unkImgScale[1];
        yScaleFactor = 1.0f / yScaleFactor;
    }

    if (!(hudElement->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
        width = gHudElementSizes[hudElement->tileSizePreset].width;
        height = gHudElementSizes[hudElement->tileSizePreset].height;
    } else {
        width = hudElement->customImageSize.x;
        height = hudElement->customImageSize.y;
    }

    transform = hudElement->hudTransform;

    guTranslateF(sp1E0, transform->pivot.x, -transform->pivot.y, 0.0f);
    guTranslateF(sp220, -transform->pivot.x, transform->pivot.y, 0.0f);
    guTranslateF(
        sp1A0,
        hudElement->renderPosX + hudElement->screenPosOffset.x + hudElement->worldPosOffset.x + transform->pos.x,
        -hudElement->renderPosY - hudElement->screenPosOffset.y + hudElement->worldPosOffset.y + transform->pos.y,
        - (hudElement->worldPosOffset.z / 10.0) + transform->pos.z
    );
    guScaleF(sp260, hudElement->uniformScale * xScaleFactor * transform->scale.x,
                    hudElement->uniformScale * yScaleFactor * transform->scale.y,
                    transform->scale.z);
    guRotateF(sp120, transform->rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(sp160, transform->rot.z, 0.0f, 0.0f, 1.0f);
    guRotateF(spE0, transform->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp160, spE0, sp20);
    guMtxCatF(sp20, sp120, spA0);
    guMtxCatF(sp260, sp1E0, sp20);
    guMtxCatF(sp20, spA0, sp60);
    guMtxCatF(sp60, sp220, sp20);
    guMtxCatF(sp20, sp1A0, sp60);
    guMtxF2L(sp60, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    mode = 0;
    a0 = mode;
    a0 = (hudElement->flags & HUD_ELEMENT_FLAG_FMT_CI4) > a0;
    v1 = mode < (hudElement->flags & HUD_ELEMENT_FLAG_FMT_IA8);

    if (a0 == TRUE) {
        mode = (v1 < 1);
    }
    if (a0 == FALSE) {
        if (v1 == TRUE) {
            mode = 2;
        }
    }

    if (a0 == TRUE) {
        if (v1 == a0) {
            mode = 2;
        }
    }

    switch (mode) {
        case 1:
            if (hudElement->flags & HUD_ELEMENT_FLAG_NO_FOLD) {
                if (hudElement->flags & HUD_ELEMENT_FLAG_TRANSPARENT) {
                    imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, hudElement->opacity, 0);
                } else {
                    imgfx_update(0, IMGFX_CLEAR, 0, 0, 0, 0, 0);
                }
            } else {
                if (hudElement->flags & HUD_ELEMENT_FLAG_TRANSPARENT) {
                    imgfx_update(transform->imgfxIdx, IMGFX_SET_ALPHA, 255, 255, 255, hudElement->opacity, 0);
                } else {
                    imgfx_update(transform->imgfxIdx, IMGFX_CLEAR, 0, 0, 0, 0, 0);
                }
            }

            ifxImg.raster = hudElement->imageAddr;
            palette = (u16*) hudElement->paletteAddr;
            ifxImg.width = width;
            ifxImg.height = height;
            ifxImg.xOffset = -width / 2;
            ifxImg.yOffset = height / 2;
            ifxImg.alpha = 255;
            ifxImg.palette = palette;

            if (hudElement->flags & HUD_ELEMENT_FLAG_NO_FOLD) {
                if (hudElement->flags & HUD_ELEMENT_FLAG_ANTIALIASING) {
                    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_40, sp60);
                } else {
                    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_40, sp60);
                }
            } else {
                imgfx_appendGfx_component(transform->imgfxIdx, &ifxImg, IMGFX_FLAG_40, sp60);
            }
            break;
        case 2:
            transform->unk_30[D_80159180].vtx[0] = D_8014F0C8[0];
            transform->unk_30[D_80159180].vtx[1] = D_8014F0C8[1];
            transform->unk_30[D_80159180].vtx[2] = D_8014F0C8[2];
            transform->unk_30[D_80159180].vtx[3] = D_8014F0C8[3];

            vtx2 = transform->unk_30[D_80159180].vtx;
            vtx = vtx2;

            vtx2->v.ob[0] = -width / 2;
            vtx2->v.ob[1] = -height / 2;
            vtx2->v.ob[2] = 0;
            vtx2->v.tc[0] = 0;
            vtx2->v.tc[1] = height * 32;
            vtx2 = vtx2 + 1;
            vtx2[0].v.ob[0] = (width / 2) - 1;
            vtx2[0].v.ob[1] = -height / 2;
            vtx2[0].v.ob[2] = 0;
            vtx2[0].v.tc[0] = width * 32;
            vtx2[0].v.tc[1] = height * 32;
            vtx[2].v.ob[0] = (width / 2) - 1;
            vtx[2].v.ob[1] = (height / 2) - 1;
            vtx[2].v.ob[2] = 0;
            vtx[2].v.tc[0] = width * 32;
            vtx[2].v.tc[1] = 0;
            vtx[3].v.ob[0] = -width / 2;
            vtx[3].v.ob[1] = (height / 2) - 1;
            vtx[3].v.ob[2] = 0;
            vtx[3].v.tc[0] = 0;
            vtx[3].v.tc[1] = 0;

            gDPPipeSync(gMainGfxPos++);
            gDPSetCombineMode(gMainGfxPos++, PM_CC_47, PM_CC_47);
            gDPSetPrimColor(gMainGfxPos++, 0, 0,
                            hudElement->tint.r, hudElement->tint.g, hudElement->tint.b, hudElement->opacity);

            if (!(hudElement->flags & HUD_ELEMENT_FLAG_TRANSPARENT)) {
                if (!(hudElement->flags & HUD_ELEMENT_FLAG_ANTIALIASING)) {
                    gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                } else {
                    gDPSetRenderMode(gMainGfxPos++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
                }
            } else {
                if (!(hudElement->flags & HUD_ELEMENT_FLAG_ANTIALIASING)) {
                    gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                } else {
                    gDPSetRenderMode(gMainGfxPos++, AA_EN | G_RM_CLD_SURF, AA_EN | G_RM_CLD_SURF2);
                }
            }

            gDPLoadTextureBlock(gMainGfxPos++, hudElement->imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
            gSPVertex(gMainGfxPos++, &transform->unk_30[D_80159180], 4, 0);
            gSP1Triangle(gMainGfxPos++, 0, 1, 2, 0);
            gSP1Triangle(gMainGfxPos++, 0, 2, 3, 0);
            break;
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}

void render_transformed_hud_elements(void) {
    s32 i, count, j;
    s32 sortedElements[ARRAY_COUNT(*gHudElements)];
    s32 el1, el2;
    HudElement* hudElement;
    s16 tempOffsetZ;
    s32 flags;
    s32 z1, z2;

    // TODO fix this terrible match
    do {
        do {
            count = 0;
            if (gCurrentCamID == CAM_3) {
                for (i = 0; i < ARRAY_COUNT(*gHudElements); i++) {
                    hudElement = (*gHudElements)[i];
                    if (hudElement == NULL) {
                        continue;
                    }

                    flags = hudElement->flags;
                    if (flags == 0 || flags & HUD_ELEMENT_FLAG_DISABLED) {
                        continue;
                    }

                    if (flags & (HUD_ELEMENT_FLAG_200000 | HUD_ELEMENT_FLAG_10000000)) {
                        continue;
                    }

                    if (!(flags & HUD_ELEMENT_FLAG_TRANSFORM)) {
                        continue;
                    }

                    if (flags & HUD_ELEMENT_FLAG_40000000) {
                        continue;
                    }

                    if (flags & HUD_ELEMENT_FLAG_FRONTUI || hudElement->drawSizePreset < 0 || flags & HUD_ELEMENT_FLAG_80) {
                        continue;
                    }

                    // add element to list
                    sortedElements[count++] = i;
                }

                if (count != 0) {
                    for (i = 0; i < count - 1; i++) {
                        for (j = i + 1; j < count; j++) {
                            el1 = sortedElements[i];
                            el2 = sortedElements[j];
                            tempOffsetZ = (*gHudElements)[el1]->worldPosOffset.z;
                            do {} while (0);
                            if (tempOffsetZ < (*gHudElements)[el2]->worldPosOffset.z) {
                                sortedElements[i] = el2;
                                sortedElements[j] = el1;
                            }
                        }
                    }

                    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 12, 20, 308, 220);
                    gDPPipeSync(gMainGfxPos++);
                    gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
                    gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
                    gSPSetLights1(gMainGfxPos++, HudElementLights);
                    gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
                    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
                    gSPSetOtherMode(gMainGfxPos++, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE);

                    for (i = 0; i < count; i++) {
                        render_hud_element((*gHudElements)[sortedElements[i]]);
                    }
                }
            }

            count = 0;
            if (gCurrentCamID == CAM_BATTLE) {
                for (i = 0; i < ARRAY_COUNT(*gHudElements); i++) {
                    hudElement = (*gHudElements)[i];
                    if (hudElement == NULL) {
                        continue;
                    }

                    flags = hudElement->flags;
                    if (flags == 0 || flags & HUD_ELEMENT_FLAG_DISABLED) {
                        continue;
                    }

                    if (flags & (HUD_ELEMENT_FLAG_200000 | HUD_ELEMENT_FLAG_10000000)) {
                        continue;
                    }

                    if (!(flags & HUD_ELEMENT_FLAG_TRANSFORM)) {
                        continue;
                    }

                    // different from CAM_3 pass
                    if (!(flags & HUD_ELEMENT_FLAG_40000000)) {
                        continue;
                    }

                    if (flags & HUD_ELEMENT_FLAG_FRONTUI || hudElement->drawSizePreset < 0 || flags & HUD_ELEMENT_FLAG_80) {
                        continue;
                    }

                    // add element to list
                    sortedElements[count++] = i;
                }

                if (count != 0) {
                    for (i = 0; i < count - 1; i++) {
                        for (j = i + 1; j < count; j++) {
                            el1 = sortedElements[i];
                            el2 = sortedElements[j];
                            tempOffsetZ = (*gHudElements)[el1]->worldPosOffset.z;
                            do {} while (0);
                            if ((*gHudElements)[el1]->worldPosOffset.z < (*gHudElements)[el2]->worldPosOffset.z) {
                                sortedElements[i] = el2;
                                sortedElements[j] = el1;
                            }
                        }
                    }

                    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 12, 20, 308, 220);
                    gDPPipeSync(gMainGfxPos++);
                    gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
                    gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
                    gSPSetLights1(gMainGfxPos++, HudElementLights);
                    gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
                    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
                    gSPSetOtherMode(gMainGfxPos++, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE);

                    for (i = 0; i < count; i++) {
                        render_hud_element((*gHudElements)[sortedElements[i]]);
                    }
                }
            }
        } while (0);
    } while (0);
}

void func_80143C48(s32 elemID, s32 arg1, s32 camID) {
    Camera* camera = &gCameras[camID];

    if (arg1 > 0) {
        if (camera->flags == 0 || (camera->flags & CAMERA_FLAG_DISABLED)) {
            return;
        }

        gCurrentCamID = camID;

        gSPViewport(gMainGfxPos++, &camera->vp);
        gSPClearGeometryMode(gMainGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPTexture(gMainGfxPos++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPPipelineMode(gMainGfxPos++, G_PM_NPRIMITIVE);
        gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
        gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
        gDPSetCombineMode(gMainGfxPos++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gSPClipRatio(gMainGfxPos++, FRUSTRATIO_2);
        gDPPipeSync(gMainGfxPos++);
        //clear Z buffer inside camera viewport
        gDPSetCycleType(gMainGfxPos++, G_CYC_FILL);
        gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxZBuffer));
        gDPSetFillColor(gMainGfxPos++, GPACK_ZDZ(G_MAXFBZ, 0)<<16 | GPACK_ZDZ(G_MAXFBZ, 0));
        gDPFillRectangle(gMainGfxPos++, camera->viewportStartX, camera->viewportStartY,
                         camera->viewportStartX + camera->viewportW - 1,
                         camera->viewportStartY + camera->viewportH - 1);
        gDPPipeSync(gMainGfxPos++);

        gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
        gDPPipeSync(gMainGfxPos++);

        guOrthoF(camera->perspectiveMatrix, 0.0f, 320.0f, -240.0f, 0.0f, -1000.0f, 1000.0f, 1.0f);
        guMtxF2L(camera->perspectiveMatrix, &gDisplayContext->camPerspMatrix[gCurrentCamID]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCamID], G_MTX_NOPUSH | G_MTX_LOAD |
                                                                                    G_MTX_PROJECTION);
        gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 12, 20, 308, 220);
        gDPPipeSync(gMainGfxPos++);
        gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                                G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
        gSPSetLights1(gMainGfxPos++, HudElementLights);
        gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
        gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
        gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
        gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
        gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
        gDPSetTextureConvert(gMainGfxPos++, G_TC_FILT);
        gDPSetCombineKey(gMainGfxPos++, G_CK_NONE);
        gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
    }

    if (elemID >= 0) {
        HudElement* elem;

        elemID &= ~HUD_ELEMENT_BATTLE_ID_MASK;
        elem = (*gHudElements)[elemID];

        if (elem == NULL) {
            return;
        }

        if (elem->flags == 0 || elem->flags & HUD_ELEMENT_FLAG_DISABLED) {
            return;
        }

        if (elem->flags & (HUD_ELEMENT_FLAG_200000 | HUD_ELEMENT_FLAG_10000000)) {
            return;
        }

        if (!(elem->flags & HUD_ELEMENT_FLAG_TRANSFORM)) {
            return;
        }

        if (elem->flags & HUD_ELEMENT_FLAG_FRONTUI || elem->drawSizePreset < 0 || !(elem->flags & HUD_ELEMENT_FLAG_80)) {
            return;
        }

        render_hud_element(elem);
    }
}

void func_80144218(s32 id) {
    func_80143C48(id, 1, CAM_3);
}

void func_80144238(s32 id) {
    func_80143C48(id, 0, CAM_3);
}

void func_80144258(s32 id) {
    func_80143C48(id, 1, CAM_BATTLE);
}

void func_80144278(s32 id) {
    func_80143C48(id, 0, CAM_BATTLE);
}

void draw_hud_element_internal(s32 id, s32 clipMode) {
    HudElement* elem = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
    s32 texSizeX, texSizeY;
    s32 drawSizeX, drawSizeY;
    s32 offsetX, offsetY;
    s32 preset;

    if (elem->flags && !(elem->flags & HUD_ELEMENT_FLAG_DISABLED)) {
        if (!(elem->flags & (HUD_ELEMENT_FLAG_200000 | HUD_ELEMENT_FLAG_10000000)) && (elem->drawSizePreset >= 0)) {
            if (clipMode != HUD_ELEMENT_DRAW_NEXT) {
                if (clipMode == HUD_ELEMENT_DRAW_FIRST_WITH_CLIPPING) {
                    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 12, 20, SCREEN_WIDTH - 12, SCREEN_HEIGHT - 20);
                }
                gDPPipeSync(gMainGfxPos++);
                gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
                gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
                gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
                gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
                gDPSetTextureConvert(gMainGfxPos++, G_TC_FILT);
                gDPSetCombineKey(gMainGfxPos++, G_CK_NONE);
                gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
                gDPNoOp(gMainGfxPos++);
                gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
                gDPSetAlphaDither(gMainGfxPos++, G_AD_DISABLE);
                gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
            }

            if (!(elem->flags & HUD_ELEMENT_FLAG_FIXEDSCALE)) {
                if (!(elem->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                    preset = elem->tileSizePreset;
                    texSizeX = gHudElementSizes[preset].width;
                    texSizeY = gHudElementSizes[preset].height;
                } else {
                    texSizeX = elem->customImageSize.x;
                    texSizeY = elem->customImageSize.y;
                }

                if (!(elem->flags & HUD_ELEMENT_FLAG_SCALED)) {
                    if (!(elem->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                        drawSizeX = gHudElementSizes[elem->drawSizePreset].width;
                        drawSizeY = gHudElementSizes[elem->drawSizePreset].height;
                    } else {
                        drawSizeX = elem->customDrawSize.x;
                        drawSizeY = elem->customDrawSize.y;
                    }
                } else {
                    drawSizeX = elem->sizeX;
                    drawSizeY = elem->sizeY;
                }

                do {
                    offsetX = -drawSizeX / 2;
                    offsetY = -drawSizeY / 2;
                } while (0); // required to match

                if (!(elem->flags & HUD_ELEMENT_FLAG_REPEATED)) {
                    if (elem->flags & HUD_ELEMENT_FLAG_DROP_SHADOW) {
                        hud_element_draw_rect(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, TRUE);
                    }
                    hud_element_draw_rect(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, FALSE);
                } else {
                    if (elem->flags & HUD_ELEMENT_FLAG_DROP_SHADOW) {
                        hud_element_draw_rect(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
                    }
                    hud_element_draw_rect(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
                }
            } else {
                f32 xScaled, yScaled;

                if (!(elem->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
                    preset = elem->tileSizePreset;
                    texSizeX = gHudElementSizes[preset].width;
                    texSizeY = gHudElementSizes[preset].height;
                } else {
                    texSizeX = elem->customImageSize.x;
                    texSizeY = elem->customImageSize.y;
                }

                drawSizeX = elem->unkImgScale[0];
                drawSizeY = elem->unkImgScale[1];

                offsetX = -elem->unkImgScale[0] / 2;
                offsetY = -elem->unkImgScale[1] / 2;

                xScaled = (f32) drawSizeX / (f32) texSizeX;
                yScaled = (f32) drawSizeY / (f32) texSizeY;

                xScaled = 1.0f / xScaled;
                yScaled = 1.0f / yScaled;

                elem->widthScale = X10(xScaled);
                elem->heightScale = X10(yScaled);

                if (elem->flags & HUD_ELEMENT_FLAG_DROP_SHADOW) {
                    hud_element_draw_rect(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
                }
                hud_element_draw_rect(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
            }
        }
    }
}

void hud_element_draw_clipped(s32 id) {
    draw_hud_element_internal(id, HUD_ELEMENT_DRAW_FIRST_WITH_CLIPPING);
}

void hud_element_draw_next(s32 id) {
    draw_hud_element_internal(id, HUD_ELEMENT_DRAW_NEXT);
}

void hud_element_draw_without_clipping(s32 id) {
    draw_hud_element_internal(id, HUD_ELEMENT_DRAW_FIRST_WITHOUT_CLIPPING);
}

void hud_element_set_script(s32 id, HudScript* anim) {
    HudElement* hudElement = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];

    if (anim == NULL) {
        anim = &HES_Empty;
    }

    hudElement->updateTimer = 1;
    hudElement->widthScale = X10(1.0f);
    hudElement->heightScale = X10(1.0f);
    hudElement->readPos = anim;
    hudElement->anim = anim;
    hudElement->loopStartPos = anim;
    hudElement->screenPosOffset.x = 0;
    hudElement->screenPosOffset.y = 0;
    hudElement->worldPosOffset.x = 0;
    hudElement->worldPosOffset.y = 0;
    hudElement->flags &= ~HUD_ELEMENT_FLAG_ANIMATION_FINISHED;
    hudElement->uniformScale = 1.0f;
    hudElement->flags &= ~(HUD_ELEMENT_FLAG_SCALED | HUD_ELEMENT_FLAG_TRANSPARENT | HUD_ELEMENT_FLAG_FIXEDSCALE | HUD_ELEMENT_FLAG_REPEATED);
    hud_element_load_script(hudElement, anim);

    while (hud_element_update(hudElement) != 0) {}
}

HudScript* hud_element_get_script(s32 id) {
    return (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK]->anim;
}

HudElement* get_hud_element(s32 id) {
    return (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
}

void hud_element_free(s32 id) {
    if ((*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK]->flags & HUD_ELEMENT_FLAG_TRANSFORM) {
        hud_element_free_transform(id & ~HUD_ELEMENT_BATTLE_ID_MASK);
    }

    heap_free((*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK]);
    (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK] = NULL;
    gHudElementsNumber--;
}

void hud_element_set_render_pos(s32 id, s32 x, s32 y) {
    HudElement* hudElement = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];

    hudElement->renderPosX = x;
    hudElement->renderPosY = y;
}

void hud_element_get_render_pos(s32 id, s32* x, s32* y) {
    HudElement* hudElement = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];

    *x = hudElement->renderPosX;
    *y = hudElement->renderPosY;
}

void hud_element_set_render_depth(s32 id, s32 z) {
    (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK]->worldPosOffset.z = z;
}

void hud_element_set_flags(s32 id, s32 flags) {
    (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK]->flags |= flags;
}

void hud_element_clear_flags(s32 id, s32 flags) {
    (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK]->flags &= ~flags;
}

void ALT_clear_hud_element_cache(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        heap_free(gHudElementCacheBuffer);
        gHudElementCacheBuffer = heap_malloc(gHudElementCacheCapacity);
        ASSERT(gHudElementCacheBuffer);
        gHudElementCacheBufferWorld = gHudElementCacheBuffer;
        *gHudElementCacheSize = 0;
        gHudElementCacheSize = &gHudElementCacheSizeWorld;
        gHudElementCacheTableRaster = gHudElementCacheTableRasterWorld;
        gHudElementCacheTablePalette = gHudElementCacheTablePaletteWorld;
        gHudElementCacheBuffer = gHudElementCacheBufferWorld;

        for (i = 0; i < MAX_HUD_CACHE_ENTRIES; i++) {
            gHudElementCacheTableRasterWorld[i].id = -1;
            gHudElementCacheTablePaletteWorld[i].id = -1;
        }
    } else {
        if (gHudElementAuxCache == NULL) {
            heap_free(gHudElementCacheBuffer);
            gHudElementCacheBuffer = heap_malloc(gHudElementCacheCapacity / 2);
            ASSERT(gHudElementCacheBuffer);
        } else {
            gHudElementCacheBuffer = gHudElementAuxCache;
        }
        gHudElementCacheBufferBattle = gHudElementCacheBuffer;
        *gHudElementCacheSize = 0;
        gHudElementCacheSize = &gHudElementCacheSizeBattle;
        gHudElementCacheTableRaster = gHudElementCacheTableRasterBattle;
        gHudElementCacheTablePalette = gHudElementCacheTablePaletteBattle;
        gHudElementCacheBuffer = gHudElementCacheBufferBattle;

        for (i = 0; i < MAX_HUD_CACHE_ENTRIES; i++) {
            gHudElementCacheTableRasterBattle[i].id = -1;
            gHudElementCacheTablePaletteBattle[i].id = -1;
        }
    }
}

void hud_element_set_scale(s32 index, f32 scale) {
    HudElement* elem = (*gHudElements)[index & ~HUD_ELEMENT_BATTLE_ID_MASK];
    s32 drawSizeX;
    s32 drawSizeY;
    s32 imgSizeX;
    s32 imgSizeY;
    f32 xScaled, yScaled;

    elem->uniformScale = scale;
    if (!(elem->flags & HUD_ELEMENT_FLAG_CUSTOM_SIZE)) {
        imgSizeX = gHudElementSizes[elem->tileSizePreset].width;
        imgSizeY = gHudElementSizes[elem->tileSizePreset].height;
        drawSizeX = gHudElementSizes[elem->drawSizePreset].width;
        drawSizeY = gHudElementSizes[elem->drawSizePreset].height;
    } else {
        imgSizeX = elem->customImageSize.x;
        imgSizeY = elem->customImageSize.y;
        drawSizeX = elem->customDrawSize.x;
        drawSizeY = elem->customDrawSize.y;
    }
    elem->sizeX = drawSizeX * scale;
    elem->sizeY = drawSizeY * scale;
    elem->flags &= ~HUD_ELEMENT_FLAG_FIXEDSCALE;
    elem->flags |= HUD_ELEMENT_FLAG_REPEATED | HUD_ELEMENT_FLAG_SCALED;

    xScaled = ((f32) drawSizeX / (f32) imgSizeX) * scale;
    yScaled = ((f32) drawSizeY / (f32) imgSizeY) * scale;

    xScaled = 1.0f / xScaled;
    yScaled = 1.0f / yScaled;

    elem->widthScale = X10(xScaled);
    elem->heightScale = X10(yScaled);
}

void hud_element_use_preset_size(s32 id, s8 sizePreset) {
    HudElement* hudElement = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];

    hudElement->widthScale = X10(1.0f);
    hudElement->heightScale = X10(1.0f);
    hudElement->tileSizePreset = sizePreset;
    hudElement->drawSizePreset = sizePreset;
    hudElement->uniformScale = 1.0f;
    hudElement->flags &= ~HUD_ELEMENT_FLAG_FIXEDSCALE;
    hudElement->flags &= ~(HUD_ELEMENT_FLAG_SCALED | HUD_ELEMENT_FLAG_REPEATED);
}

s32 func_80144E4C(s32 id) {
    return ((*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK]->flags >> 24) & 0xF;
}

void func_80144E74(s32 id, s32 arg1) {
    HudElement* hudElement = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];

    hudElement->flags &= ~(HUD_ELEMENT_FLAG_1000000 | HUD_ELEMENT_FLAG_2000000 | HUD_ELEMENT_FLAG_4000000 | HUD_ELEMENT_FLAG_8000000);
    hudElement->flags |= arg1 << 24;
}

void hud_element_set_alpha(s32 id, s32 opacity) {
    HudElement* hudElement = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];

    hudElement->flags |= HUD_ELEMENT_FLAG_TRANSPARENT;
    hudElement->opacity = opacity;

    if (opacity == 255) {
        hudElement->flags &= ~HUD_ELEMENT_FLAG_TRANSPARENT;
    }
}

void hud_element_set_tint(s32 id, s32 r, s32 g, s32 b) {
    HudElement* hudElement = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];

    hudElement->tint.r = r;
    hudElement->tint.g = g;
    hudElement->tint.b = b;
}

void hud_element_create_transform_A(s32 id) {
    HudElement* element = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
    HudTransform* transform = general_heap_malloc(sizeof(*transform));

    element->hudTransform = transform;
    ASSERT(transform != NULL);
    element->flags |= HUD_ELEMENT_FLAG_TRANSFORM;
    transform->imgfxIdx = imgfx_get_free_instances(1);
    transform->pos.x = 0.0f;
    transform->pos.y = 0.0f;
    transform->pos.z = 0.0f;
    transform->rot.x = 0.0f;
    transform->rot.y = 0.0f;
    transform->rot.z = 0.0f;
    transform->scale.x = 1.0f;
    transform->scale.y = 1.0f;
    transform->scale.z = 1.0f;
    transform->pivot.x = 0;
    transform->pivot.y = 0;
    func_801413F8();
}

void hud_element_create_transform_B(s32 id) {
    HudElement* element = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
    HudTransform* transform = general_heap_malloc(sizeof(*transform));

    element->hudTransform = transform;
    ASSERT(transform != NULL);
    element->flags |= HUD_ELEMENT_FLAG_TRANSFORM | HUD_ELEMENT_FLAG_NO_FOLD;
    transform->imgfxIdx = 0;
    transform->pos.x = 0.0f;
    transform->pos.y = 0.0f;
    transform->pos.z = 0.0f;
    transform->rot.x = 0.0f;
    transform->rot.y = 0.0f;
    transform->rot.z = 0.0f;
    transform->scale.x = 1.0f;
    transform->scale.y = 1.0f;
    transform->scale.z = 1.0f;
    func_801413F8();
}

void hud_element_create_transform_C(s32 id) {
    HudElement* element = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
    HudTransform* transform = general_heap_malloc(sizeof(*transform));

    element->hudTransform = transform;
    ASSERT(transform != NULL);
    element->flags |= HUD_ELEMENT_FLAG_40000000 | HUD_ELEMENT_FLAG_NO_FOLD | HUD_ELEMENT_FLAG_TRANSFORM;
    transform->imgfxIdx = 0;
    transform->pos.x = 0.0f;
    transform->pos.y = 0.0f;
    transform->pos.z = 0.0f;
    transform->rot.x = 0.0f;
    transform->rot.y = 0.0f;
    transform->rot.z = 0.0f;
    transform->scale.x = 1.0f;
    transform->scale.y = 1.0f;
    transform->scale.z = 1.0f;
    func_801413F8();
}

void hud_element_free_transform(s32 id) {
    HudElement* hudElement = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
    HudTransform* hudTransform = hudElement->hudTransform;

    if (!(hudElement->flags & HUD_ELEMENT_FLAG_NO_FOLD)) {
        imgfx_release_instance(hudTransform->imgfxIdx);
    }

    heap_free(hudElement->hudTransform);
    hudElement->hudTransform = NULL;
    hudElement->flags &= ~(HUD_ELEMENT_FLAG_40000000 | HUD_ELEMENT_FLAG_NO_FOLD | HUD_ELEMENT_FLAG_TRANSFORM);
}

void hud_element_set_transform_pos(s32 id, f32 x, f32 y, f32 z) {
    HudElement* element = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
    HudTransform* transform = element->hudTransform;

    if (element->flags & HUD_ELEMENT_FLAG_TRANSFORM) {
        transform->pos.x = x;
        transform->pos.y = y;
        transform->pos.z = z;
    }
}

void hud_element_set_transform_scale(s32 id, f32 x, f32 y, f32 z) {
    HudElement* element = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
    HudTransform* transform = element->hudTransform;

    if (element->flags & HUD_ELEMENT_FLAG_TRANSFORM) {
        transform->scale.x = x;
        transform->scale.y = y;
        transform->scale.z = z;
    }
}

void hud_element_set_transform_rotation(s32 id, f32 x, f32 y, f32 z) {
    HudElement* element = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
    HudTransform* transform = element->hudTransform;

    if (element->flags & HUD_ELEMENT_FLAG_TRANSFORM) {
        transform->rot.x = x;
        transform->rot.y = y;
        transform->rot.z = z;
    }
}

void hud_element_set_transform_rotation_pivot(s32 id, s32 dx, s32 dy) {
    HudElement* element = (*gHudElements)[id & ~HUD_ELEMENT_BATTLE_ID_MASK];
    HudTransform* transform = element->hudTransform;

    if (element->flags & HUD_ELEMENT_FLAG_TRANSFORM) {
        transform->pivot.x = dx;
        transform->pivot.y = dy;
    }
}

void copy_world_hud_element_ref_to_battle(s32 worldID, s32 battleID) {
    gHudElementsBattle[battleID & ~HUD_ELEMENT_BATTLE_ID_MASK] = gHudElementsWorld[worldID & ~HUD_ELEMENT_BATTLE_ID_MASK];
}

void hud_element_set_aux_cache(void* base, s32 size) {
    gHudElementAuxCache = (u8*)base;
    if (base == NULL) {
        gHudElementCacheCapacity = 0x11000;
    } else {
        gHudElementCacheCapacity = size;
    }
}
