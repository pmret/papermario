#include "common.h"

enum {
    CREDITS_LINE_FLAG_1          = 1,
    CREDITS_LINE_FLAG_2          = 2,
};

enum {
    CREDITS_LINE_APPEARING       = 0,
    CREDITS_LINE_HOLDING         = 1,
    CREDITS_LINE_VANISHING       = 2
};

// unused
void N(CharAnim_FadeIn_0)(CreditsLine* line, CreditsChar* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    f32 alpha;
    
    alpha = update_lerp(EASING_LINEAR, 0.0f, 255.0f, arg1->fadeInTime, line->appearTime);
    if (alpha > 255.0f) {
        alpha = 255.0;
    }
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    foldImg.raster  = glyphPtr->raster;
    foldImg.palette = glyphPtr->palette;
    foldImg.width   = glyphPtr->texSize.x;
    foldImg.height  = glyphPtr->texSize.y;
    foldImg.xOffset = -(glyphPtr->charWidth * 0.5);
    foldImg.yOffset = 0;
    foldImg.opacity = 255;
    fold_appendGfx_component(0, &foldImg, FOLD_STATE_FLAG_40000 | FOLD_STATE_FLAG_10000 | FOLD_STATE_FLAG_40, transformMtx);
    
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}


void N(CharAnim_FadeIn_1)(CreditsLine* line, CreditsChar* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    f32 alpha;
    
    alpha = update_lerp(0, 0.0f, 255.0f, arg1->fadeInTime, line->appearTime);
    if (alpha > 255.0f) {
        alpha = 255.0;
    }
    if (arg1->fadeInTime == (line->appearTime - 4)) {
        fold_update(0, FOLD_TYPE_A, 64, 64, 64, alpha, 0);
    } else if (arg1->fadeInTime == (line->appearTime - 3)) {
        fold_update(0, FOLD_TYPE_A, 96, 96, 96, alpha, 0);
    } else if (arg1->fadeInTime == (line->appearTime - 2)) {
        fold_update(0, FOLD_TYPE_A, 127, 127, 127, alpha, 0);
    } else if (arg1->fadeInTime == (line->appearTime - 1)) {
        fold_update(0, FOLD_TYPE_A, 80, 80, 80, alpha, 0);
    } else {
        fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    }
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    foldImg.raster  = glyphPtr->raster;
    foldImg.palette = glyphPtr->palette;
    foldImg.width   = glyphPtr->texSize.x;
    foldImg.height  = glyphPtr->texSize.y;
    foldImg.xOffset = -(glyphPtr->charWidth * 0.5);
    foldImg.yOffset = 0;
    foldImg.opacity = 255;
    fold_appendGfx_component(0, &foldImg, FOLD_STATE_FLAG_40000 | FOLD_STATE_FLAG_10000 | FOLD_STATE_FLAG_40, transformMtx);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeIn_2)(CreditsLine* line, CreditsChar* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    f32 scaleAmt;
    f32 alpha;
    
    alpha = update_lerp(EASING_COS_IN, 16.0f, 300.0f, arg1->fadeInTime, line->appearTime);
    if (alpha > 255.0f) {
        alpha = 255.0f;
    }
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    
    scaleAmt = update_lerp(EASING_LINEAR, 0.2f, 2.0f, arg1->fadeInTime, line->appearTime);
    if (scaleAmt > 1.0) {
        scaleAmt = 1.0;
    }
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    if (scaleAmt != 1.0) {
        guScaleF(tempMtx, scaleAmt, scaleAmt, 1.0f);
        guMtxCatF(tempMtx, transformMtx, transformMtx);
    }
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
   
    foldImg.raster  = glyphPtr->raster;
    foldImg.palette = glyphPtr->palette;
    foldImg.width   = glyphPtr->texSize.x;
    foldImg.height  = glyphPtr->texSize.y;
    foldImg.xOffset = -(glyphPtr->charWidth * 0.5);
    foldImg.yOffset = 0;
    foldImg.opacity = 255;
    fold_appendGfx_component(0, &foldImg, FOLD_STATE_FLAG_40, transformMtx);

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeIn_3)(CreditsLine* line, CreditsChar* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 rotAngle, alpha;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;

    alpha = update_lerp(EASING_COS_IN, 32.0f, 300.0f, arg1->fadeInTime, line->appearTime);
    if (alpha > 255.0f) {
        alpha = 255.0f;
    }
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    
    rotAngle = update_lerp(EASING_LINEAR, -75.0f, 30.0f, arg1->fadeInTime, line->appearTime);
    if (rotAngle >= 0.0f) {
        rotAngle = 0.0f;
    }
    
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    if (rotAngle != 0.0f) {
        guRotateF(tempMtx, rotAngle, 0.0f, 1.0f, 0.0f);
        guMtxCatF(tempMtx, transformMtx, transformMtx);
    }
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    foldImg.raster  = glyphPtr->raster;
    foldImg.palette = glyphPtr->palette;
    foldImg.width   = glyphPtr->texSize.x;
    foldImg.height  = glyphPtr->texSize.y;
    foldImg.xOffset = -(glyphPtr->charWidth * 0.5);
    foldImg.yOffset = 0;
    foldImg.opacity = 255;
    fold_appendGfx_component(0, &foldImg, FOLD_STATE_FLAG_10000 | FOLD_STATE_FLAG_40, transformMtx);
    
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeIn_4)(CreditsLine* line, CreditsChar* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 posX, posY, scaleAmt, rotAngle;
    f32 startX = (line->posX + line->msgWidth) - 16;
    f32 startY = line->posY + 60;
    u32 foldFlags = FOLD_STATE_FLAG_40;

    posX = update_lerp(EASING_COS_IN_OUT, startX, arg1->posX, arg1->fadeInTime, line->appearTime);
    posY = update_lerp(EASING_CUBIC_OUT, startY, arg1->posY, arg1->fadeInTime, line->appearTime);
    if (arg1->fadeInTime == line->appearTime) {
        rotAngle = 0.0f;
    } else {
        rotAngle = (line->appearTime - arg1->fadeInTime) * 10;
    }
    scaleAmt = update_lerp(EASING_QUADRATIC_OUT, 2.0f, 1.0f, arg1->fadeInTime, line->appearTime);

    if (arg1->fadeInTime == line->appearTime) {
        fold_update(0, FOLD_TYPE_NONE, 0, 0, 0, 0, 0);
        foldFlags |= FOLD_STATE_FLAG_10000;
    } else {
        f32 alpha = update_lerp(EASING_LINEAR, 16.0f, 300.0f, arg1->fadeInTime, line->appearTime);
        if (alpha > 255.0f) {
            alpha = 255.0f;
        }
        fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    }
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);
    
    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guRotateF(tempMtx, rotAngle, 0.0f, 1.0f, 0.2f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guScaleF (tempMtx, scaleAmt, scaleAmt, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    foldImg.raster  = glyphPtr->raster;
    foldImg.palette = glyphPtr->palette;
    foldImg.width   = glyphPtr->texSize.x;
    foldImg.height  = glyphPtr->texSize.y;
    foldImg.xOffset = -(glyphPtr->charWidth * 0.5);
    foldImg.yOffset = 0;
    foldImg.opacity = 255;
    fold_appendGfx_component(0, &foldImg, foldFlags, transformMtx);

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeIn_5)(CreditsLine* line, CreditsChar* arg1) {
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    f32 alpha;
    
    alpha = update_lerp(EASING_LINEAR, 0.0f, 255.0f, arg1->fadeInTime, line->appearTime);
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    draw_ci_image_with_clipping(glyphPtr->raster, glyphPtr->texSize.x, glyphPtr->texSize.y,
        G_IM_FMT_CI, G_IM_SIZ_4b, glyphPtr->palette, posX, posY,
        10, 20, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 40, alpha);
}

// unused
void N(CharAnim_HoldClearFold)(CreditsLine* line, CreditsChar* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;

    fold_update(0, FOLD_TYPE_NONE, 0, 0, 0, 0, 0);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);
    
    foldImg.raster  = glyphPtr->raster;
    foldImg.palette = glyphPtr->palette;
    foldImg.width   = glyphPtr->texSize.x;
    foldImg.height  = glyphPtr->texSize.y;
    foldImg.xOffset = -(glyphPtr->charWidth * 0.5);
    foldImg.yOffset = 0;
    foldImg.opacity = 255;
    fold_appendGfx_component(0, &foldImg, FOLD_STATE_FLAG_40000 | FOLD_STATE_FLAG_10000 | FOLD_STATE_FLAG_40, transformMtx);
    
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
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
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = chr->posX;
    f32 posY = chr->posY;
    f32 alpha;
    
    alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, chr->fadeInTime, line->vanishTime);
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);

    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    foldImg.raster  = glyphPtr->raster;
    foldImg.palette = glyphPtr->palette;
    foldImg.width   = glyphPtr->texSize.x;
    foldImg.height  = glyphPtr->texSize.y;
    foldImg.xOffset = -(glyphPtr->charWidth * 0.5);
    foldImg.yOffset = 0;
    foldImg.opacity = 255;
    fold_appendGfx_component(0, &foldImg, FOLD_STATE_FLAG_10000 | FOLD_STATE_FLAG_40, transformMtx);
    
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeOut_1)(CreditsLine* line, CreditsChar* chr) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 scaleAmt, alpha;
    f32 posX = chr->posX;
    f32 posY = chr->posY;
    
    alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, chr->fadeInTime, line->vanishTime);
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    
    scaleAmt = update_lerp(EASING_LINEAR, 1.0f, 0.2f, chr->fadeInTime, line->vanishTime);
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);
    
    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guScaleF(tempMtx, scaleAmt, scaleAmt, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    foldImg.raster  = glyphPtr->raster;
    foldImg.palette = glyphPtr->palette;
    foldImg.width   = glyphPtr->texSize.x;
    foldImg.height  = glyphPtr->texSize.y;
    foldImg.xOffset = -(glyphPtr->charWidth * 0.5);
    foldImg.yOffset = 0;
    foldImg.opacity = 255;
    fold_appendGfx_component(0, &foldImg, FOLD_STATE_FLAG_40, transformMtx);
    
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void N(CharAnim_FadeOut_2)(CreditsLine* line, CreditsChar* chr) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 rotAngle, alpha;
    f32 posX = chr->posX;
    f32 posY = chr->posY;
    
    alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, chr->fadeInTime, line->vanishTime);
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    
    rotAngle = update_lerp(EASING_LINEAR, 0.0f, 60.0f, chr->fadeInTime, line->vanishTime);
    msg_get_glyph(chr->font, chr->variation, chr->charIndex, chr->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guRotateF(tempMtx, rotAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    foldImg.raster  = glyphPtr->raster;
    foldImg.palette = glyphPtr->palette;
    foldImg.width   = glyphPtr->texSize.x;
    foldImg.height  = glyphPtr->texSize.y;
    foldImg.xOffset = -(glyphPtr->charWidth * 0.5);
    foldImg.yOffset = 0;
    foldImg.opacity = 255;
    fold_appendGfx_component(0, &foldImg, FOLD_STATE_FLAG_10000 | FOLD_STATE_FLAG_40, transformMtx);
    
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
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
