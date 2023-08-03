#include "common.h"
#include "Credits.h"

#if VERSION_PAL
#define CREDITS_MESSAGE_BUFFER_COUNT (24)
#else
#define CREDITS_MESSAGE_BUFFER_COUNT (23)
#endif

s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags);
void msg_get_glyph(s32 font, s32 variation, s32 charIndex, s32 palette, MesasgeFontGlyphData* out);
void dma_load_msg(u32 msgID, void* dest);

BSS CreditsData N(CreditsData);
BSS CreditsData* N(CreditsDataPtr);
#if !VERSION_IQUE
BSS s32 N(BSS_PAD_1)[2];
#endif
BSS u8 N(CreditsMessageBuffers)[CREDITS_MESSAGE_BUFFER_COUNT][256];
BSS Mtx N(CreditsProjMatrices)[2];

enum {
    CREDITS_LINE_FLAG_1          = 1,
    CREDITS_LINE_FLAG_2          = 2,
};

enum {
    CREDITS_LINE_APPEARING       = 0,
    CREDITS_LINE_HOLDING         = 1,
    CREDITS_LINE_VANISHING       = 2
};

CreditsPairOffset N(Font4Patterns)[] = {
    { .firstChar = 0x02, .secondChar = 0x07, .offset = 1 },
    { .firstChar = 0x02, .secondChar = 0x0A, .offset = 1 },
    { .firstChar = 0x03, .secondChar = 0x04, .offset = 1 },
    { .firstChar = 0x07, .secondChar = 0x0D, .offset = 1 },
    { .firstChar = 0x09, .secondChar = 0x04, .offset = 1 },
    { .firstChar = 0x0C, .secondChar = 0x04, .offset = 1 },
    { .firstChar = 0x0C, .secondChar = 0x0C, .offset = 1 },
    { .firstChar = 0x0C, .secondChar = 0x14, .offset = 1 },
    { .firstChar = 0x0D, .secondChar = 0x03, .offset = 1 },
    { .firstChar = 0x0D, .secondChar = 0x04, .offset = 1 },
    { .firstChar = 0x0D, .secondChar = 0x0A, .offset = 1 },
    { .firstChar = 0x0D, .secondChar = 0x14, .offset = 1 },
    { .firstChar = 0x0E, .secondChar = 0x0D, .offset = 1 },
    { .firstChar = 0x0E, .secondChar = 0x11, .offset = 1 },
    { .firstChar = 0x11, .secondChar = 0x04, .offset = 1 },
    { .firstChar = 0x11, .secondChar = 0x0F, .offset = 1 },
    { .firstChar = 0x14, .secondChar = 0x02, .offset = 1 },
    { .firstChar = 0x14, .secondChar = 0x0D, .offset = 1 },
    { .firstChar = 0x14, .secondChar = 0x0F, .offset = 1 },
    { .firstChar = 0x14, .secondChar = 0x12, .offset = 1 },
    { .firstChar = 0x12, .secondChar = 0x02, .offset = 1 },
    { .firstChar = 0x12, .secondChar = 0x07, .offset = 1 },
    { .firstChar = 0x12, .secondChar = 0x0F, .offset = 1 },
    { .firstChar = 0x15, .secondChar = 0x04, .offset = 1 },
    { .firstChar = 0x16, .secondChar = 0x11, .offset = 1 },
    {}
};

CreditsPairOffset N(Font3Patterns)[] = {
    { .firstChar = 0x00, .secondChar = 0x02, .offset = 1 },
    { .firstChar = 0x00, .secondChar = 0x06, .offset = 1 },
    { .firstChar = 0x00, .secondChar = 0x0E, .offset = 1 },
    { .firstChar = 0x00, .secondChar = 0x03, .offset = 1 },
    { .firstChar = 0x00, .secondChar = 0x08, .offset = 1 },
    { .firstChar = 0x00, .secondChar = 0x0A, .offset = 1 },
    { .firstChar = 0x00, .secondChar = 0x0D, .offset = 1 },
    { .firstChar = 0x00, .secondChar = 0x13, .offset = 1 },
    { .firstChar = 0x00, .secondChar = 0x14, .offset = 1 },
    { .firstChar = 0x07, .secondChar = 0x00, .offset = 1 },
    { .firstChar = 0x07, .secondChar = 0x06, .offset = 1 },
    { .firstChar = 0x07, .secondChar = 0x08, .offset = 1 },
    { .firstChar = 0x08, .secondChar = 0x02, .offset = 1 },
    { .firstChar = 0x08, .secondChar = 0x04, .offset = 1 },
    { .firstChar = 0x08, .secondChar = 0x06, .offset = 1 },
    { .firstChar = 0x08, .secondChar = 0x0A, .offset = 1 },
    { .firstChar = 0x08, .secondChar = 0x0D, .offset = 1 },
    { .firstChar = 0x08, .secondChar = 0x0E, .offset = 1 },
    { .firstChar = 0x08, .secondChar = 0x13, .offset = 1 },
    { .firstChar = 0x08, .secondChar = 0x18, .offset = 1 },
    { .firstChar = 0x09, .secondChar = 0x08, .offset = 1 },
    { .firstChar = 0x0C, .secondChar = 0x0E, .offset = 1 },
    { .firstChar = 0x0C, .secondChar = 0x08, .offset = 1 },
    { .firstChar = 0x0D, .secondChar = 0x06, .offset = 1 },
    { .firstChar = 0x0D, .secondChar = 0x08, .offset = 1 },
    { .firstChar = 0x0D, .secondChar = 0x0E, .offset = 1 },
    { .firstChar = 0x0D, .secondChar = 0x13, .offset = 1 },
    { .firstChar = 0x12, .secondChar = 0x04, .offset = 1 },
    { .firstChar = 0x12, .secondChar = 0x08, .offset = 1 },
    { .firstChar = 0x13, .secondChar = 0x04, .offset = 1 },
    { .firstChar = 0x14, .secondChar = 0x02, .offset = 1 },
    { .firstChar = 0x14, .secondChar = 0x08, .offset = 1 },
    { .firstChar = 0x14, .secondChar = 0x0A, .offset = 1 },
    {}
};

Vp N(CreditsViewport) = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 }
    }
};

s32 N(CreditsBufferIndex) = 0;

// unused
void N(CharAnim_FadeIn_0)(CreditsLine* line, CreditsChar* chr) {
    ImgFXTexture ifxImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = chr->posX;
    f32 posY = chr->posY;
    f32 alpha;

    alpha = update_lerp(EASING_LINEAR, 0.0f, 255.0f, chr->fadeInTime, line->appearTime);
    if (alpha > 255.0f) {
        alpha = 255.0;
    }
    imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, alpha, 0);
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    ifxImg.raster  = glyphPtr->raster;
    ifxImg.palette = glyphPtr->palette;
    ifxImg.width   = glyphPtr->texSize.x;
    ifxImg.height  = glyphPtr->texSize.y;
    ifxImg.xOffset = -(glyphPtr->charWidth * 0.5);
    ifxImg.yOffset = 0;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_40000 | IMGFX_FLAG_NO_FILTERING | IMGFX_FLAG_40, transformMtx);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}


void N(CharAnim_FadeIn_1)(CreditsLine* line, CreditsChar* chr) {
    ImgFXTexture ifxImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = chr->posX;
    f32 posY = chr->posY;
    f32 alpha;

    alpha = update_lerp(EASING_LINEAR, 0.0f, 255.0f, chr->fadeInTime, line->appearTime);
    if (alpha > 255.0f) {
        alpha = 255.0;
    }
    if (chr->fadeInTime == (line->appearTime - 4)) {
        imgfx_update(0, IMGFX_SET_CREDITS_FADE, 64, 64, 64, alpha, 0);
    } else if (chr->fadeInTime == (line->appearTime - 3)) {
        imgfx_update(0, IMGFX_SET_CREDITS_FADE, 96, 96, 96, alpha, 0);
    } else if (chr->fadeInTime == (line->appearTime - 2)) {
        imgfx_update(0, IMGFX_SET_CREDITS_FADE, 127, 127, 127, alpha, 0);
    } else if (chr->fadeInTime == (line->appearTime - 1)) {
        imgfx_update(0, IMGFX_SET_CREDITS_FADE, 80, 80, 80, alpha, 0);
    } else {
        imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, alpha, 0);
    }
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    ifxImg.raster  = glyphPtr->raster;
    ifxImg.palette = glyphPtr->palette;
    ifxImg.width   = glyphPtr->texSize.x;
    ifxImg.height  = glyphPtr->texSize.y;
    ifxImg.xOffset = -(glyphPtr->charWidth * 0.5);
    ifxImg.yOffset = 0;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_40000 | IMGFX_FLAG_NO_FILTERING | IMGFX_FLAG_40, transformMtx);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeIn_2)(CreditsLine* line, CreditsChar* chr) {
    ImgFXTexture ifxImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 posX = chr->posX;
    f32 posY = chr->posY;
    f32 scaleAmt;
    f32 alpha;

    alpha = update_lerp(EASING_COS_IN, 16.0f, 300.0f, chr->fadeInTime, line->appearTime);
    if (alpha > 255.0f) {
        alpha = 255.0f;
    }
    imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, alpha, 0);

    scaleAmt = update_lerp(EASING_LINEAR, 0.2f, 2.0f, chr->fadeInTime, line->appearTime);
    if (scaleAmt > 1.0) {
        scaleAmt = 1.0;
    }
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    if (scaleAmt != 1.0) {
        guScaleF(tempMtx, scaleAmt, scaleAmt, 1.0f);
        guMtxCatF(tempMtx, transformMtx, transformMtx);
    }
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    ifxImg.raster  = glyphPtr->raster;
    ifxImg.palette = glyphPtr->palette;
    ifxImg.width   = glyphPtr->texSize.x;
    ifxImg.height  = glyphPtr->texSize.y;
    ifxImg.xOffset = -(glyphPtr->charWidth * 0.5);
    ifxImg.yOffset = 0;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_40, transformMtx);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeIn_3)(CreditsLine* line, CreditsChar* chr) {
    ImgFXTexture ifxImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 rotAngle, alpha;
    f32 posX = chr->posX;
    f32 posY = chr->posY;

    alpha = update_lerp(EASING_COS_IN, 32.0f, 300.0f, chr->fadeInTime, line->appearTime);
    if (alpha > 255.0f) {
        alpha = 255.0f;
    }
    imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, alpha, 0);

    rotAngle = update_lerp(EASING_LINEAR, -75.0f, 30.0f, chr->fadeInTime, line->appearTime);
    if (rotAngle >= 0.0f) {
        rotAngle = 0.0f;
    }

    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    if (rotAngle != 0.0f) {
        guRotateF(tempMtx, rotAngle, 0.0f, 1.0f, 0.0f);
        guMtxCatF(tempMtx, transformMtx, transformMtx);
    }
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    ifxImg.raster  = glyphPtr->raster;
    ifxImg.palette = glyphPtr->palette;
    ifxImg.width   = glyphPtr->texSize.x;
    ifxImg.height  = glyphPtr->texSize.y;
    ifxImg.xOffset = -(glyphPtr->charWidth * 0.5);
    ifxImg.yOffset = 0;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_NO_FILTERING | IMGFX_FLAG_40, transformMtx);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeIn_4)(CreditsLine* line, CreditsChar* chr) {
    ImgFXTexture ifxImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 posX, posY, scaleAmt, rotAngle;
    f32 startX = (line->posX + line->msgWidth) - 16;
    f32 startY = line->posY + 60;
    u32 imgfxFlags = IMGFX_FLAG_40;

    posX = update_lerp(EASING_COS_IN_OUT, startX, chr->posX, chr->fadeInTime, line->appearTime);
    posY = update_lerp(EASING_CUBIC_OUT, startY, chr->posY, chr->fadeInTime, line->appearTime);
    if (chr->fadeInTime == line->appearTime) {
        rotAngle = 0.0f;
    } else {
        rotAngle = (line->appearTime - chr->fadeInTime) * 10;
    }
    scaleAmt = update_lerp(EASING_QUADRATIC_OUT, 2.0f, 1.0f, chr->fadeInTime, line->appearTime);

    if (chr->fadeInTime == line->appearTime) {
        imgfx_update(0, IMGFX_CLEAR, 0, 0, 0, 0, 0);
        imgfxFlags |= IMGFX_FLAG_NO_FILTERING;
    } else {
        f32 alpha = update_lerp(EASING_LINEAR, 16.0f, 300.0f, chr->fadeInTime, line->appearTime);
        if (alpha > 255.0f) {
            alpha = 255.0f;
        }
        imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, alpha, 0);
    }
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guRotateF(tempMtx, rotAngle, 0.0f, 1.0f, 0.2f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guScaleF (tempMtx, scaleAmt, scaleAmt, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    ifxImg.raster  = glyphPtr->raster;
    ifxImg.palette = glyphPtr->palette;
    ifxImg.width   = glyphPtr->texSize.x;
    ifxImg.height  = glyphPtr->texSize.y;
    ifxImg.xOffset = -(glyphPtr->charWidth * 0.5);
    ifxImg.yOffset = 0;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, imgfxFlags, transformMtx);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeIn_5)(CreditsLine* line, CreditsChar* chr) {
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    f32 posX = chr->posX;
    f32 posY = chr->posY;
    f32 alpha;

    alpha = update_lerp(EASING_LINEAR, 0.0f, 255.0f, chr->fadeInTime, line->appearTime);
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    draw_ci_image_with_clipping(glyphPtr->raster, glyphPtr->texSize.x, glyphPtr->texSize.y,
        G_IM_FMT_CI, G_IM_SIZ_4b, glyphPtr->palette, posX, posY,
        10, 20, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 40, alpha);
}

// unused
void N(CharAnim_HoldClearImgFX)(CreditsLine* line, CreditsChar* chr) {
    ImgFXTexture ifxImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = chr->posX;
    f32 posY = chr->posY;

    imgfx_update(0, IMGFX_CLEAR, 0, 0, 0, 0, 0);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    ifxImg.raster  = glyphPtr->raster;
    ifxImg.palette = glyphPtr->palette;
    ifxImg.width   = glyphPtr->texSize.x;
    ifxImg.height  = glyphPtr->texSize.y;
    ifxImg.xOffset = -(glyphPtr->charWidth * 0.5);
    ifxImg.yOffset = 0;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_40000 | IMGFX_FLAG_NO_FILTERING | IMGFX_FLAG_40, transformMtx);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_Hold)(CreditsLine* line, CreditsChar* chr) {
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    f32 posX = chr->posX;
    f32 posY = chr->posY;

    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);
    draw_ci_image_with_clipping(glyphPtr->raster, glyphPtr->texSize.x, glyphPtr->texSize.y,
        G_IM_FMT_CI, G_IM_SIZ_4b, glyphPtr->palette, posX, posY,
        10, 20, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 40, 255);
}

// unused
void N(CharAnim_FadeOut_0)(CreditsLine* line, CreditsChar* chr) {
    ImgFXTexture ifxImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = chr->posX;
    f32 posY = chr->posY;
    f32 alpha;

    alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, chr->fadeInTime, line->vanishTime);
    imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, alpha, 0);

    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    ifxImg.raster  = glyphPtr->raster;
    ifxImg.palette = glyphPtr->palette;
    ifxImg.width   = glyphPtr->texSize.x;
    ifxImg.height  = glyphPtr->texSize.y;
    ifxImg.xOffset = -(glyphPtr->charWidth * 0.5);
    ifxImg.yOffset = 0;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_NO_FILTERING | IMGFX_FLAG_40, transformMtx);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeOut_1)(CreditsLine* line, CreditsChar* chr) {
    ImgFXTexture ifxImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 scaleAmt, alpha;
    f32 posX = chr->posX;
    f32 posY = chr->posY;

    alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, chr->fadeInTime, line->vanishTime);
    imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, alpha, 0);

    scaleAmt = update_lerp(EASING_LINEAR, 1.0f, 0.2f, chr->fadeInTime, line->vanishTime);
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guScaleF(tempMtx, scaleAmt, scaleAmt, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    ifxImg.raster  = glyphPtr->raster;
    ifxImg.palette = glyphPtr->palette;
    ifxImg.width   = glyphPtr->texSize.x;
    ifxImg.height  = glyphPtr->texSize.y;
    ifxImg.xOffset = -(glyphPtr->charWidth * 0.5);
    ifxImg.yOffset = 0;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_40, transformMtx);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeOut_2)(CreditsLine* line, CreditsChar* chr) {
    ImgFXTexture ifxImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 rotAngle, alpha;
    f32 posX = chr->posX;
    f32 posY = chr->posY;

    alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, chr->fadeInTime, line->vanishTime);
    imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, alpha, 0);

    rotAngle = update_lerp(EASING_LINEAR, 0.0f, 60.0f, chr->fadeInTime, line->vanishTime);
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guRotateF(tempMtx, rotAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    ifxImg.raster  = glyphPtr->raster;
    ifxImg.palette = glyphPtr->palette;
    ifxImg.width   = glyphPtr->texSize.x;
    ifxImg.height  = glyphPtr->texSize.y;
    ifxImg.xOffset = -(glyphPtr->charWidth * 0.5);
    ifxImg.yOffset = 0;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_NO_FILTERING | IMGFX_FLAG_40, transformMtx);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeOut_3)(CreditsLine* line, CreditsChar* chr) {
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    f32 posX = chr->posX;
    f32 posY = chr->posY;
    f32 alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, chr->fadeInTime, line->vanishTime);

    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);
    draw_ci_image_with_clipping(glyphPtr->raster, glyphPtr->texSize.x, glyphPtr->texSize.y,
        G_IM_FMT_CI, G_IM_SIZ_4b, glyphPtr->palette, posX, posY,
        10, 20, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 40, alpha);
}

void N(credits_update_line)(CreditsLine* line) {
    CreditsChar creditsChar;
    CreditsChar* curChar = &creditsChar;
    CreditsPairOffset* curPattern;
    s32 msgHeight, msgWidth, msgMaxLineChars;
    s32 doneCurrentState;
    s32 readPos;
    u8 curMsgChar;
    u16 nextMsgChar1, nextMsgChar2;
    u16 doneCalcLoop, doneDrawLoop;
    s32 drawCount;
    s32 posX;
    s32 i;

    doneCurrentState = FALSE;
    if (line->flags & CREDITS_LINE_FLAG_2) {
        line->flags &= ~CREDITS_LINE_FLAG_2;
        line->time = 0;
        line->state = 0;
    }

    get_msg_properties((s32) line->message, &msgHeight, &msgWidth, &msgMaxLineChars, NULL, NULL, NULL, 0);

    curChar->font = 0;
    curChar->variation = 0;

    // calculate message width
    msgWidth = 1;
    readPos = 0;
    do {
        curMsgChar = line->message[readPos++];
        nextMsgChar1 = line->message[readPos];
        doneCalcLoop = FALSE;

        switch (curMsgChar) {
            case MSG_CHAR_READ_VARIANT0:
            case MSG_CHAR_READ_VARIANT1:
            case MSG_CHAR_READ_VARIANT2:
                curChar->variation = curMsgChar - MSG_CHAR_READ_VARIANT0;
                break;
            case MSG_CHAR_READ_ENDL:
            case MSG_CHAR_READ_END:
                doneCalcLoop = TRUE;
                break;
            case MSG_CHAR_READ_FUNCTION:
                // only support function for selecting font
                if (line->message[readPos++] == MSG_READ_FUNC_FONT) {
                    curChar->font = line->message[readPos++];
                }
                break;
            default:
                msgWidth += msg_get_print_char_width(curMsgChar, curChar->font, curChar->variation, 1.0f, 0, 1) - 1;
                if (curChar->font == MSG_FONT_TITLE || curChar->font == MSG_FONT_SUBTITLE) {
                    curPattern = N(Font3Patterns);
                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        curPattern = N(Font4Patterns);
                    }

                    i = 0;

                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        if (curMsgChar == MSG_CHAR_LPAREN || nextMsgChar1 == MSG_CHAR_LPAREN) {
                            msgWidth++;
                        }
                    }

                    do {
                        if (curMsgChar == curPattern[i].firstChar && nextMsgChar1 == curPattern[i].secondChar) {
                            msgWidth += curPattern[i].offset;
                        }
                        i++;
                    } while (curPattern[i].offset != 0);
                }
                break;
        }
    } while (!doneCalcLoop);

    line->msgWidth = msgWidth;
    if (line->flags & CREDITS_LINE_FLAG_1) {
        posX = line->posX - (((f32) msgWidth * 0.5) + 0.0);
    } else {
        posX = line->posX;
    }

    curChar->font = 0;
    curChar->variation = 0;
    curChar->palette = line->palette;

    drawCount = 0;
    readPos = 0;
    do {
        curMsgChar = line->message[readPos++];
        nextMsgChar2 = line->message[readPos];
        doneDrawLoop = FALSE;

        switch (curMsgChar) {
            case MSG_CHAR_READ_VARIANT0:
            case MSG_CHAR_READ_VARIANT1:
            case MSG_CHAR_READ_VARIANT2:
                curChar->variation = curMsgChar - MSG_CHAR_READ_VARIANT0;
                break;
            case MSG_CHAR_READ_ENDL:
            case MSG_CHAR_READ_END:
                doneDrawLoop = TRUE;
                break;
            case MSG_CHAR_READ_FUNCTION:
                if (line->message[readPos++] == 0) {
                    curChar->font = line->message[readPos++];
                }
                break;
            default:
                if (curMsgChar < MSG_CHAR_READ_ENDL) {
                    curChar->charIndex = curMsgChar;
                    curChar->posX = posX;
                    curChar->posY = line->posY;

                    switch (line->state) {
                        case CREDITS_LINE_APPEARING:
                            curChar->fadeInTime = line->time - (line->perCharDelayIn * drawCount);
                            if (curChar->fadeInTime >= 0) {
                                if (line->appearTime < curChar->fadeInTime) {
                                    curChar->fadeInTime = line->appearTime;
                                }
                                if ((nextMsgChar2 == MSG_CHAR_READ_END) && (curChar->fadeInTime == line->appearTime)) {
                                    doneCurrentState = TRUE;
                                }
                                switch (line->appearMode) {
                                    case 0:
                                        N(CharAnim_FadeIn_5)(line, curChar);
                                        break;
                                    case 1:
                                        N(CharAnim_FadeIn_1)(line, curChar);
                                        break;
                                    case 2:
                                        N(CharAnim_FadeIn_2)(line, curChar);
                                        break;
                                    case 3:
                                        N(CharAnim_FadeIn_3)(line, curChar);
                                        break;
                                    case 4:
                                        N(CharAnim_FadeIn_4)(line, curChar);
                                        break;
                                    case 5:
                                        N(CharAnim_FadeIn_5)(line, curChar);
                                        break;
                                }
                            }
                            break;

                        case CREDITS_LINE_HOLDING:
                            if (nextMsgChar2 == MSG_CHAR_READ_END) {
                                if (line->time == line->holdTime) {
                                    doneCurrentState = TRUE;
                                }
                            }
                            N(CharAnim_Hold)(line, curChar);
                            break;

                        case CREDITS_LINE_VANISHING:
                            curChar->fadeInTime = line->time - (line->perCharDelayOut * drawCount);
                            if (curChar->fadeInTime < 0) {
                                curChar->fadeInTime = 0;
                            }
                            if (curChar->fadeInTime > line->vanishTime) {
                                curChar->fadeInTime = line->vanishTime;
                            }
                            if (nextMsgChar2 == MSG_CHAR_READ_END && curChar->fadeInTime == line->vanishTime) {
                                doneCurrentState = TRUE;
                            }

                            switch (line->vanishMode) {
                                case 0:
                                    N(CharAnim_FadeOut_3)(line, curChar);
                                    break;
                                case 1:
                                    N(CharAnim_FadeOut_1)(line, curChar);
                                    break;
                                case 2:
                                    N(CharAnim_FadeOut_2)(line, curChar);
                                    break;
                                case 3:
                                    N(CharAnim_FadeOut_3)(line, curChar);
                                    break;
                            }
                            break;
                    }
                    drawCount++;
                }

                posX += msg_get_print_char_width(curMsgChar, curChar->font, curChar->variation, 1.0f, 0, 1) - 1;
                if (curChar->font == MSG_FONT_TITLE || curChar->font == MSG_FONT_SUBTITLE) {
                    curPattern = N(Font3Patterns);
                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        curPattern = N(Font4Patterns);
                    }

                    i = 0;

                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        if (curMsgChar == MSG_CHAR_LPAREN || nextMsgChar2 == MSG_CHAR_LPAREN) {
                            posX++;
                        }
                    }
                    do {
                        if (curMsgChar == curPattern[i].firstChar && nextMsgChar2 == curPattern[i].secondChar) {
                            posX += curPattern[i].offset;
                        }
                        i++;
                    } while (curPattern[i].offset != 0);
                }
                break;
        }
    } while (!doneDrawLoop);

    if ((line->state == CREDITS_LINE_APPEARING) && doneCurrentState) {
        s32 temp = 0;
        get_msg_properties((s32) line->message, NULL, NULL, &temp, NULL, NULL, NULL, 0);
        line->time = 0;
        line->state++;
        if (line->holdTime <= 0) {
            line->state++;
        }
    } else if ((line->state == CREDITS_LINE_HOLDING) && doneCurrentState) {
        line->time = 0;
        line->state++;
    } else if ((line->state == CREDITS_LINE_VANISHING) && doneCurrentState) {
        line->flags &= ~CREDITS_LINE_FLAG_1;
    }
    line->time++;
}

void N(credits_worker_render)(void) {
    Mtx* projMtx = &N(CreditsProjMatrices)[gCurrentDisplayContextIndex];
    CreditsData* data = N(CreditsDataPtr);
    s32 i;

    gSPViewport(gMainGfxPos++, &N(CreditsViewport));
    guOrtho(projMtx, 0.0f, 320.0f, -240.0f, 0.0f, -100.0f, 100.0f, 1.0f);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(projMtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPPipeSync(gMainGfxPos++);
    gSPClearGeometryMode(gMainGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);

    for (i = 0; i < ARRAY_COUNT(data->lines); i++) {
        if (data->lines[i].flags & CREDITS_LINE_FLAG_1) {
            N(credits_update_line)(&data->lines[i]);
        }
    }
}

void N(credits_load_message)(CreditsEntry* entry) {
    CreditsLine* line;
    s32 maxLineChars;
    s32 numSpaces;
    s32 i = 0;

    while (TRUE) {
        if (!(N(CreditsDataPtr)->lines[i].flags & CREDITS_LINE_FLAG_1)) {
            break;
        }
        if (++i == ARRAY_COUNT(N(CreditsDataPtr)->lines)) {
            return;
        }
    }

    line = &N(CreditsDataPtr)->lines[i];
    if (entry->msgID != NULL) {
        if (entry->msgID >= 0) {
            dma_load_msg(entry->msgID, N(CreditsMessageBuffers)[N(CreditsBufferIndex)]);
            line->message = N(CreditsMessageBuffers)[N(CreditsBufferIndex)];
            N(CreditsBufferIndex)++;
            if (N(CreditsBufferIndex) >= ARRAY_COUNT(N(CreditsMessageBuffers))) {
                N(CreditsBufferIndex) = 0;
            }
        } else {
            line->message = (u8*) entry->msgID;
        }
        get_msg_properties((s32) line->message, NULL, NULL, &maxLineChars, NULL, NULL, &numSpaces, 0);
        line->posX            = entry->posX;
        line->posY            = entry->posY;
        line->palette         = entry->palette;
        line->appearMode      = entry->appearMode;
        line->appearTime      = entry->appearTime;
        line->holdMode        = entry->holdMode;
        line->holdTime        = entry->holdTime;
        if (entry->perCharDelayIn != 0) {
            line->holdTime = entry->holdTime - ((maxLineChars - 1) - numSpaces) * entry->perCharDelayIn;
            if (line->holdTime < 0) {
                line->holdTime = 0;
            }
        }
        line->vanishMode      = entry->vanishMode;
        line->vanishTime      = entry->vanishTime;
        line->perCharDelayIn  = entry->perCharDelayIn;
        line->perCharDelayOut = entry->perCharDelayOut;
        line->flags           = entry->flags | CREDITS_LINE_FLAG_1 | CREDITS_LINE_FLAG_2;
    }
}

void N(init_credits)(void) {
    s32 i;

    N(CreditsDataPtr) = &N(CreditsData);
    N(CreditsData).workerID = create_worker_frontUI(NULL, N(credits_worker_render));

    for (i = 0; i < ARRAY_COUNT(N(CreditsData).lines); i++) {
        N(CreditsData).lines[i].flags = 0;
    }
}

API_CALLABLE(N(InitCredits)) {
    N(init_credits)();
    load_font(1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ShowCreditList)) {
    CreditsEntry* creditList = (CreditsEntry*) evt_get_variable(script, *script->ptrReadPos);

    if (isInitialCall) {
        script->varTable[0] = 0;
        script->varTable[1] = -1;
        script->varTable[2] = 0;
    }

    switch (script->varTable[0]) {
        case 0:
            while (TRUE) {
                if (creditList[script->varTable[2]].msgID != 0) {
                    N(credits_load_message)(&creditList[script->varTable[2]]);
                }
                script->varTable[1] = creditList[script->varTable[2]].next;
                script->varTable[2]++;
                if (script->varTable[1] > 0) {
                    break;
                }
                if (script->varTable[1] == -1) {
                    return ApiStatus_DONE2;
                }
            }
            script->varTable[0] = 1;
            // fallthrough
        case 1:
            script->varTable[1]--;
            if (script->varTable[1] <= 0) {
                script->varTable[0] = 0;
            }
            break;
    }

    return ApiStatus_BLOCK;
}
