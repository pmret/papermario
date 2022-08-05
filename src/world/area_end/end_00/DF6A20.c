#include "end_00.h"

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern ParadeNpcInfo D_80244D74_DFB774[];

extern CreditsUnkBeta N(Font4Patterns)[16];
extern CreditsUnkBeta N(Font3Patterns)[16];
s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags);

enum {
    DRAW_CREDIT_FLAG_CENTER     = 1,
    DRAW_CREDIT_FLAG_2          = 2,
};

// unused
void N(CharAnim_FadeIn_0)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    f32 alpha;
    
    alpha = update_lerp(EASING_LINEAR, 0.0f, 255.0f, arg1->fadeInTime, unk->fadeInTime);
    if (alpha > 255.0f) {
        alpha = 255.0;
    }
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
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

void N(CharAnim_FadeIn_1)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    f32 alpha;
    
    alpha = update_lerp(0, 0.0f, 255.0f, arg1->fadeInTime, unk->fadeInTime);
    if (alpha > 255.0f) {
        alpha = 255.0;
    }
    if (arg1->fadeInTime == (unk->fadeInTime - 4)) {
        fold_update(0, FOLD_TYPE_A, 64, 64, 64, alpha, 0);
    } else if (arg1->fadeInTime == (unk->fadeInTime - 3)) {
        fold_update(0, FOLD_TYPE_A, 96, 96, 96, alpha, 0);
    } else if (arg1->fadeInTime == (unk->fadeInTime - 2)) {
        fold_update(0, FOLD_TYPE_A, 127, 127, 127, alpha, 0);
    } else if (arg1->fadeInTime == (unk->fadeInTime - 1)) {
        fold_update(0, FOLD_TYPE_A, 80, 80, 80, alpha, 0);
    } else {
        fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    }
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
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

void N(CharAnim_FadeIn_2)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    f32 scaleAmt;
    f32 alpha;
    
    alpha = update_lerp(EASING_COS_IN, 16.0f, 300.0f, arg1->fadeInTime, unk->fadeInTime);
    if (alpha > 255.0f) {
        alpha = 255.0f;
    }
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    
    scaleAmt = update_lerp(EASING_LINEAR, 0.2f, 2.0f, arg1->fadeInTime, unk->fadeInTime);
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
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
   
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

void N(CharAnim_FadeIn_3)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 rotAngle, alpha;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;

    alpha = update_lerp(EASING_COS_IN, 32.0f, 300.0f, arg1->fadeInTime, unk->fadeInTime);
    if (alpha > 255.0f) {
        alpha = 255.0f;
    }
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    
    rotAngle = update_lerp(EASING_LINEAR, -75.0f, 30.0f, arg1->fadeInTime, unk->fadeInTime);
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
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
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

void N(CharAnim_FadeIn_4)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 posX, posY, scaleAmt, rotAngle;
    f32 startX = (unk->posX + unk->msgWidth) - 16;
    f32 startY = unk->posY + 60;
    u32 foldFlags = FOLD_STATE_FLAG_40;

    posX = update_lerp(EASING_COS_IN_OUT, startX, arg1->posX, arg1->fadeInTime, unk->fadeInTime);
    posY = update_lerp(EASING_CUBIC_OUT, startY, arg1->posY, arg1->fadeInTime, unk->fadeInTime);
    if (arg1->fadeInTime == unk->fadeInTime) {
        rotAngle = 0.0f;
    } else {
        rotAngle = (unk->fadeInTime - arg1->fadeInTime) * 10;
    }
    scaleAmt = update_lerp(EASING_QUADRATIC_OUT, 2.0f, 1.0f, arg1->fadeInTime, unk->fadeInTime);

    if (arg1->fadeInTime == unk->fadeInTime) {
        fold_update(0, FOLD_TYPE_NONE, 0, 0, 0, 0, 0);
        foldFlags |= FOLD_STATE_FLAG_10000;
    } else {
        f32 alpha = update_lerp(EASING_LINEAR, 16.0f, 300.0f, arg1->fadeInTime, unk->fadeInTime);
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
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
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

void N(CharAnim_FadeIn_5)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    f32 alpha;
    
    alpha = update_lerp(EASING_LINEAR, 0.0f, 255.0f, arg1->fadeInTime, unk->fadeInTime);
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    draw_ci_image_with_clipping(glyphPtr->raster, glyphPtr->texSize.x, glyphPtr->texSize.y,
        G_IM_FMT_CI, G_IM_SIZ_4b, glyphPtr->palette, posX, posY,
        10, 20, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 40, alpha);
}

// unused
void N(CharAnim_HoldClearFold)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;

    fold_update(0, FOLD_TYPE_NONE, 0, 0, 0, 0, 0);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
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

void N(CharAnim_Hold)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;

    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);
    draw_ci_image_with_clipping(glyphPtr->raster, glyphPtr->texSize.x, glyphPtr->texSize.y,
        G_IM_FMT_CI, G_IM_SIZ_4b, glyphPtr->palette, posX, posY,
        10, 20, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 40, 255);
}

// unused
void N(CharAnim_FadeOut_0)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    f32 alpha;
    
    alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, arg1->fadeInTime, unk->fadeOutTime);
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);

    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
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

void N(CharAnim_FadeOut_1)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 scaleAmt, alpha;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    
    alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, arg1->fadeInTime, unk->fadeOutTime);
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    
    scaleAmt = update_lerp(EASING_LINEAR, 1.0f, 0.2f, arg1->fadeInTime, unk->fadeOutTime);
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);
    
    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guScaleF(tempMtx, scaleAmt, scaleAmt, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
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

void N(CharAnim_FadeOut_2)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    FoldImageRecPart foldImg;
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    Matrix4f transformMtx, tempMtx;
    f32 rotAngle, alpha;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY;
    
    alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, arg1->fadeInTime, unk->fadeOutTime);
    fold_update(0, FOLD_TYPE_7, 255, 255, 255, alpha, 0);
    
    rotAngle = update_lerp(EASING_LINEAR, 0.0f, 60.0f, arg1->fadeInTime, unk->fadeOutTime);
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);

    posX += (glyphPtr->charWidth * 0.5);
    guTranslateF(transformMtx, posX, -posY, 0.0f);
    guRotateF(tempMtx, rotAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L (transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
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

void N(CharAnim_FadeOut_3)(CreditsUnkAlpha* unk, CreditsGlyphInfo* arg1) {
    MesasgeFontGlyphData glyph;
    MesasgeFontGlyphData* glyphPtr = &glyph;
    f32 posX = arg1->posX;
    f32 posY = arg1->posY; 
    f32 alpha = update_lerp(EASING_SIN_OUT, 255.0f, 0.0f, arg1->fadeInTime, unk->fadeOutTime);
    
    msg_get_glyph(arg1->font, arg1->variation, arg1->charIndex, arg1->palette, glyphPtr);
    draw_ci_image_with_clipping(glyphPtr->raster, glyphPtr->texSize.x, glyphPtr->texSize.y,
        G_IM_FMT_CI, G_IM_SIZ_4b, glyphPtr->palette, posX, posY,
        10, 20, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 40, alpha);
}

void N(CharAnim_Main)(CreditsUnkAlpha* arg0) {
    CreditsGlyphInfo glyph;
    CreditsGlyphInfo* glyphPtr = &glyph;
    CreditsUnkBeta* curPattern;
    s32 msgHeight, msgWidth, msgMaxLineChars;
    s32 bufEnd2;
    s32 readPos;
    u8 thisChar;
    u16 nextChar1, nextChar2;
    u16 doneCalcLoop, doneDrawLoop;
    s32 drawCount;
    s32 posX;
    s32 i;

    bufEnd2 = FALSE;
    if (arg0->flags & DRAW_CREDIT_FLAG_2) {
        arg0->flags &= ~DRAW_CREDIT_FLAG_2;
        arg0->time = 0;
        arg0->unk_0C = 0;
    }
    
    get_msg_properties(arg0->message, &msgHeight, &msgWidth, &msgMaxLineChars, NULL, NULL, NULL, 0);
    
    glyphPtr->font = 0;
    glyphPtr->variation = 0;

    // calculate message width
    msgWidth = 1;
    readPos = 0;
    do {
        thisChar = arg0->message[readPos++];
        nextChar1 = arg0->message[readPos];
        doneCalcLoop = FALSE;
        
        switch (thisChar) {
            case MSG_CHAR_READ_VARIANT0:
            case MSG_CHAR_READ_VARIANT1:
            case MSG_CHAR_READ_VARIANT2:
                glyphPtr->variation = thisChar - MSG_CHAR_READ_VARIANT0;
                break;
            case MSG_CHAR_READ_ENDL:
            case MSG_CHAR_READ_END:
                doneCalcLoop = TRUE;
                break;
            case MSG_CHAR_READ_FUNCTION:
                // only support function for selecting font
                if (arg0->message[readPos++] == MSG_READ_FUNC_FONT) {
                    glyphPtr->font = arg0->message[readPos++];
                }
                break;
            default:
                msgWidth += msg_get_print_char_width(thisChar, glyphPtr->font, glyphPtr->variation, 1.0f, 0, 1) - 1;
                if (glyphPtr->font == MSG_FONT_TITLE || glyphPtr->font == MSG_FONT_SUBTITLE) {
                    curPattern = N(Font3Patterns);
                    if (glyphPtr->font == MSG_FONT_SUBTITLE) {
                        curPattern = N(Font4Patterns);
                    }
    
                    i = 0;
    
                    if (glyphPtr->font == MSG_FONT_SUBTITLE) {
                        if (thisChar == MSG_CHAR_LPAREN || nextChar1 == MSG_CHAR_LPAREN) {
                            msgWidth++;
                        }
                    }
                    
                    do {
                        if (thisChar == curPattern[i].unk_00 && nextChar1 == curPattern[i].unk_01) {
                            msgWidth += curPattern[i].unk_02;
                        }
                        i++;
                    } while (curPattern[i].unk_02 != 0);
                }
                break;
        }
    } while (!doneCalcLoop);

    arg0->msgWidth = msgWidth;
    if (arg0->flags & DRAW_CREDIT_FLAG_CENTER) {
        posX = arg0->posX - (((f32) msgWidth * 0.5) + 0.0);
    } else {
        posX = arg0->posX;
    }

    glyphPtr->font = 0;
    glyphPtr->variation = 0;
    glyphPtr->palette = arg0->highlight;
    
    drawCount = 0;
    readPos = 0;
    do {
        thisChar = arg0->message[readPos++];
        nextChar2 = arg0->message[readPos];
        doneDrawLoop = FALSE;
        
        switch (thisChar) {
            case MSG_CHAR_READ_VARIANT0:
            case MSG_CHAR_READ_VARIANT1:
            case MSG_CHAR_READ_VARIANT2:
                glyphPtr->variation = thisChar - MSG_CHAR_READ_VARIANT0;
                break;
            case MSG_CHAR_READ_ENDL:
            case MSG_CHAR_READ_END:
                doneDrawLoop = TRUE;
                break;
            case MSG_CHAR_READ_FUNCTION:
                if (arg0->message[readPos++] == 0) {
                    glyphPtr->font = arg0->message[readPos++];
                }
                break;
            default:
                if (thisChar < MSG_CHAR_READ_ENDL) {
                    glyphPtr->charIndex = thisChar;
                    glyphPtr->posX = posX;
                    glyphPtr->posY = arg0->posY;
                    
                    switch (arg0->unk_0C) {
                        case 0:
                            glyphPtr->fadeInTime = arg0->time - (arg0->perCharDelay * drawCount);
                            if (glyphPtr->fadeInTime >= 0) {
                                if (arg0->fadeInTime < glyphPtr->fadeInTime) {
                                    glyphPtr->fadeInTime = arg0->fadeInTime;
                                }
                                if ((nextChar2 == MSG_CHAR_READ_END) && (glyphPtr->fadeInTime == arg0->fadeInTime)) {
                                    bufEnd2 = TRUE;
                                }
                                switch (arg0->unk_18) {
                                    case 0:
                                        N(CharAnim_FadeIn_5)(arg0, glyphPtr);
                                        break;
                                    case 1:
                                        N(CharAnim_FadeIn_1)(arg0, glyphPtr);
                                        break;
                                    case 2:
                                        N(CharAnim_FadeIn_2)(arg0, glyphPtr);
                                        break;
                                    case 3:
                                        N(CharAnim_FadeIn_3)(arg0, glyphPtr);
                                        break;
                                    case 4:
                                        N(CharAnim_FadeIn_4)(arg0, glyphPtr);
                                        break;
                                    case 5:
                                        N(CharAnim_FadeIn_5)(arg0, glyphPtr);
                                        break;
                                }
                            }
                            break;
                        
                        case 1:
                            if (nextChar2 == MSG_CHAR_READ_END) {
                                if (arg0->time == arg0->holdTime) {
                                    bufEnd2 = TRUE;
                                }
                            }
                            N(CharAnim_Hold)(arg0, glyphPtr);
                            break;

                        case 2:
                            glyphPtr->fadeInTime = arg0->time - (arg0->unk_54 * drawCount);
                            if (glyphPtr->fadeInTime < 0) {
                                glyphPtr->fadeInTime = 0;
                            }
                            if (glyphPtr->fadeInTime > arg0->fadeOutTime) {
                                glyphPtr->fadeInTime = arg0->fadeOutTime;
                            }
                            if (nextChar2 == MSG_CHAR_READ_END && glyphPtr->fadeInTime == arg0->fadeOutTime) {
                                bufEnd2 = TRUE;
                            }

                            switch (arg0->unk_4C) {
                                case 0:
                                    N(CharAnim_FadeOut_3)(arg0, glyphPtr);
                                    break;
                                case 1:
                                    N(CharAnim_FadeOut_1)(arg0, glyphPtr);
                                    break;
                                case 2:
                                    N(CharAnim_FadeOut_2)(arg0, glyphPtr);
                                    break;
                                case 3:
                                    N(CharAnim_FadeOut_3)(arg0, glyphPtr);
                                    break;
                            }
                            break;
                    }
                    drawCount++;
                }

                posX += msg_get_print_char_width(thisChar, glyphPtr->font, glyphPtr->variation, 1.0f, 0, 1) - 1;
                if (glyphPtr->font == MSG_FONT_TITLE || glyphPtr->font == MSG_FONT_SUBTITLE) {
                    curPattern = N(Font3Patterns);
                    if (glyphPtr->font == MSG_FONT_SUBTITLE) {
                        curPattern = N(Font4Patterns);
                    }

                    i = 0;

                    if (glyphPtr->font == MSG_FONT_SUBTITLE) {
                        if (thisChar == MSG_CHAR_LPAREN || nextChar2 == MSG_CHAR_LPAREN) {
                            posX++;
                        }
                    }
                    do {
                        if (thisChar == curPattern[i].unk_00 && nextChar2 == curPattern[i].unk_01) {
                            posX += curPattern[i].unk_02;
                        }
                        i++;
                    } while (curPattern[i].unk_02 != 0);
                }
                break;
        }
    } while (!doneDrawLoop);
    
    if ((arg0->unk_0C == 0) && bufEnd2) {
        s32 temp = 0;
        get_msg_properties(arg0->message, NULL, NULL, &temp, NULL, NULL, NULL, 0);
        arg0->time = 0;
        arg0->unk_0C++;
        if (arg0->holdTime <= 0) {
            arg0->unk_0C++;
        }
    } else if ((arg0->unk_0C == 1) && bufEnd2) {
        arg0->time = 0;
        arg0->unk_0C++;
    } else if ((arg0->unk_0C == 2) && bufEnd2) {
        arg0->flags &= ~DRAW_CREDIT_FLAG_CENTER;
    }
    arg0->time++;
}

static char* N(exit_str_0) = "end_01";

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_802421D8_DF8BD8);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242358_DF8D58);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242500_DF8F00);

ApiStatus func_80242558_DF8F58(Evt* script, s32 isInitialCall) {
    func_80242500_DF8F00();
    load_font(1);
    return ApiStatus_DONE2;
}

ApiStatus N(ShowCreditList)(Evt* script, s32 isInitialCall) {
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
                    func_80242358_DF8D58(&creditList[script->varTable[2]]);
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
            // fall through
        case 1:
            script->varTable[1]--;
            if (script->varTable[1] <= 0) {
                script->varTable[0] = 0;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80242680_DF9080(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    ParadeNpcInfo* npcInfo = &D_80244D74_DFB774[npcID];
    NpcBlueprint bp;
    Npc* npc;

    bp.flags = NPC_FLAG_100;
    bp.initialAnim = npcInfo->initialAnim;
    bp.onUpdate = NULL;
    bp.onRender = NULL;

    spr_allocateBtlComponentsOnWorldHeap = TRUE;

    npc = get_npc_by_index(_create_npc_standard(&bp, npcInfo->animList));
    npc->npcID = npcID;
    npc->flags &= ~NPC_FLAG_PARTICLE;
    npc->pos.x = npcInfo->pos.x;
    npc->pos.y = npcInfo->pos.y;
    npc->pos.z = npcInfo->pos.z;
    set_npc_yaw(npc, npcInfo->yaw);
    return ApiStatus_DONE2;
}

ApiStatus func_80242744_DF9144(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 heapSize = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    evt_set_variable(script, outVar, _heap_malloc(&gSpriteHeapPtr, heapSize));
    return ApiStatus_DONE2;
}

ApiStatus func_802427A4_DF91A4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 pointer = *args++;

    _heap_free(&gSpriteHeapPtr, evt_get_variable(script, pointer));
    return ApiStatus_DONE2;
}

ApiStatus func_802427D8_DF91D8(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    camera->unk_506 = 1;
    camera->movePos.x += 0.6666667f;
    return ApiStatus_DONE2;
}

ApiStatus N(SetNpcShadowScale)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 newShadowScale = evt_get_float_variable(script, *args++);

    resolve_npc(script, npcID)->shadowScale = newShadowScale;
    return ApiStatus_DONE2;
}

ApiStatus func_80242898_DF9298(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc** npc = (Npc**)&script->functionTempPtr[1];

    if (isInitialCall) {
        *npc = get_npc_unsafe(evt_get_variable(script, *args++));
    }

    (*npc)->pos.x += 0.6666667f;

    return ApiStatus_BLOCK;
}
