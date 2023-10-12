#include "common.h"

s32 draw_image_with_clipping(IMG_PTR raster, u32 width, u32 height, s32 fmt, s32 bitDepth, s16 posX, s16 posY,
                             u16 clipX, u16 clipY, u16 clipWidth, u16 clipHeight);

s32 draw_ci_image_with_clipping(IMG_PTR raster, s32 width, s32 height, s32 fmt, s32 bitDepth, PAL_PTR palette, s16 posX,
                                s16 posY, u16 clipULx, u16 clipULy, u16 clipLRx, u16 clipRLy, u8 opacity) {
    s32 ret = 1;

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);

    if (opacity == 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
        gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else if (opacity == 0) {
        return ret;
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
