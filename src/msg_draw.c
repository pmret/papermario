#include "common.h"
#include "ld_addrs.h"
#include "message_ids.h"
#include "sprite.h"

#include "charset/postcard.png.h"
#include "charset/letter_content_1.png.h"

extern IMG_BIN ui_msg_bubble_left_png[];
extern IMG_BIN ui_msg_bubble_mid_png[];
extern IMG_BIN ui_msg_bubble_right_png[];
extern IMG_BIN ui_msg_arrow_png[];
extern unsigned char ui_msg_palettes[16][32];
extern IMG_BIN ui_msg_sign_corner_topleft_png[];
extern IMG_BIN ui_msg_sign_corner_topright_png[];
extern IMG_BIN ui_msg_sign_corner_bottomleft_png[];
extern IMG_BIN ui_msg_sign_corner_bottomright_png[];
extern IMG_BIN ui_msg_lamppost_corner_bottomright_png[];
extern IMG_BIN ui_msg_sign_side_top_png[];
extern IMG_BIN ui_msg_sign_side_left_png[];
extern IMG_BIN ui_msg_sign_side_right_png[];
extern IMG_BIN ui_msg_sign_side_bottom_png[];
extern IMG_BIN ui_msg_sign_fill_png[];
extern PAL_BIN ui_msg_sign_pal[];
extern PAL_BIN ui_msg_lamppost_pal[];
extern IMG_BIN ui_msg_background_png[];
extern IMG_BIN ui_msg_rewind_arrow_png[];
extern PAL_BIN ui_msg_rewind_arrow_pal[];
extern IMG_BIN ui_msg_star_png[];
extern IMG_BIN ui_msg_star_silhouette_png[];

// .bss
typedef MessageImageData* MessageImageDataList[1];

extern s32 gMsgBGScrollAmtX;
extern u16 gMsgGlobalWaveCounter;
extern MessageImageDataList gMsgVarImages;
extern s32 gMsgBGScrollAmtY;
extern u8* D_8015131C;
extern Gfx* D_80151338;
extern char gMessageBuffers[2][1024];
extern u8 gMessageMsgVars[3][32];
extern s16 D_80155C98;
extern Mtx gMessageWindowProjMatrix[2];
extern MessageDrawState D_80155D20;
extern MessageDrawState* msg_drawState;
extern IMG_BIN D_80159B50[0x200];
extern PAL_BIN D_8015C7E0[0x10];
extern MessagePrintState gMessagePrinters[3];
#if VERSION_IQUE
extern IMG_BIN D_801544A0[120][128];
#endif

extern s16 MsgStyleVerticalLineOffsets[];

extern IMG_BIN D_802ED550[];
extern PAL_BIN D_802ED670[];
extern IMG_BIN MsgCharImgTitle[];
extern IMG_BIN MsgCharImgNormal[];
extern MessageCharset* MsgCharsets[5];
extern IMG_BIN MsgCharImgSubtitle[];
extern PAL_BIN D_802F4560[80][8];
extern s32 gMessageBoxFrameParts[2][16];

Vtx gMsgSpeechBoxLQuad[4] = {
    { .v = { .ob = {1, 0, 0},           .tc = {0, 0},           .cn = {255, 255, 248, 255} } },
    { .v = { .ob = {0x20, 0, 0},        .tc = {0x400, 0},       .cn = {255, 255, 248, 255} } },
    { .v = { .ob = {0x1, 0xFFC0, 0},    .tc = {0, 0x800},       .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {0x20, 0xFFC0, 0},   .tc = {0x400, 0x800},   .cn = {191, 184, 176, 255} } },
};

Vtx gMsgSpeechBoxMQuad[] = {
    { .v = { .ob = {0x20, 0, 0},        .tc = {0, 0},            .cn = {255, 255, 248, 255} } },
    { .v = { .ob = {0xE1, 0, 0},        .tc = {0x100, 0},        .cn = {255, 255, 248, 255} } },
    { .v = { .ob = {0x20, 0xFFC0, 0},   .tc = {0, 0x800},        .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {0xE1, 0xFFC0, 0},   .tc = {0x100, 0x800},    .cn = {191, 184, 176, 255} } },
};

Vtx gMsgSpeechBoxRQuad[] = {
    { .v = { .ob = {0xE1, 0, 0},        .tc = {0, 0},             .cn = {255, 255, 248, 255} } },
    { .v = { .ob = {0x100, 0, 0},       .tc = {0x400, 0},         .cn = {255, 255, 248, 255} } },
    { .v = { .ob = {0xE1, 0xFFC0, 0},   .tc = {0, 0x800},         .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {0x100, 0xFFC0, 0},  .tc = {0x400, 0x800},     .cn = {191, 184, 176, 255} } },
};

Vtx gMsgArrowQuad1[] = {
    { .v = { .ob = {0xFFF1, 0x001E, 0}, .tc = {0, 0},             .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {0xF, 0x001E, 0},    .tc = {0x1E0, 0},         .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {0xFFFF, 0, 0},      .tc = {0, 0x1E0},         .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {1, 0, 0},           .tc = {0x1E0, 0x1E0},     .cn = {191, 184, 176, 255} } },
};

Vtx gMsgArrowQuad2[] = {
    { .v = { .ob = {0xFFF1, 0x001E, 0}, .tc = {0, 0},             .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {0xF, 0x001E, 0},    .tc = {0x1E0, 0},         .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {0xFFFF, 0, 0},      .tc = {0, 0x1E0},         .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {1, 0, 0},           .tc = {0x1E0, 0x1E0},     .cn = {191, 184, 176, 255} } },
};

Gfx D_8014C500[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_TEX_EDGE, G_RM_TEX_EDGE2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
    gsSPEndDisplayList(),
};

u8 D_8014C580[] = { 50, 80, 100, 105, 100, 0, 0, 0 };
u8 D_8014C588[] = { 105, 100, 77, 57, 40, 27, 16, 8, 3, 0, 0, 0};
#if VERSION_IQUE
u32 D_8014AD24 = 2;
#else
u8 D_8014C594[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif

s32 draw_image_with_clipping(IMG_PTR raster, s32 width, s32 height, s32 fmt, s32 bitDepth, s16 posX, s16 posY, u16 clipULx,
                             u16 clipULy, u16 clipLRx, u16 clipRLy);

s32 _update_message(MessagePrintState* printer);
void msg_copy_to_print_buffer(MessagePrintState* printer, s32 arg1, s32 arg2);
void initialize_printer(MessagePrintState* printer, s32 arg1, s32 arg2);
MessagePrintState* _msg_get_printer_for_msg(s32 msgID, s32* donePrintingWriteback, s32 arg2);
void msg_update_rewind_arrow(s32);
void msg_draw_rewind_arrow(s32);
void msg_draw_choice_pointer(MessagePrintState* printer);
void draw_message_window(MessagePrintState* printer);
void appendGfx_message(MessagePrintState*, s16, s16, u16, u16, u16, u8);
void appendGfx_msg_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 ulX, u16 ulY, u16 lrX, u16 lrY);
void msg_reset_gfx_state(void);
void msg_draw_char(MessagePrintState* printer, MessageDrawState* drawState, s32 charIndex, s32 palette, s32 posX,
                   s32 posY);
void msg_draw_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 posX, u16 posY, u16 sizeX, u16 sizeY);
void msg_draw_speech_arrow(MessagePrintState* printer);
void msg_draw_frame(s32 posX, s32 posY, s32 sizeX, s32 sizeY, s32 style, s32 palette, s32 fading, s32 bgAlpha, s32 frameAlpha);
void msg_draw_speech_bubble(MessagePrintState* printer, s16 posX, s16 posY, s16 straightWidth, s16 curveWidth,
                            s16 height, f32 scaleX, f32 scaleY, u8 opacity, s32 arg9);
s32 msg_get_draw_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u16 flags);

void drawbox_message_delegate(s32 data, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    MessagePrintState* printer = (MessagePrintState*)data;

    appendGfx_message(printer, 0, 0, 0, 0, 4, 0);
}

void draw_message_window(MessagePrintState* printer) {
    f32 scale = 1.0f;
    s32 rotZ = 0;

    switch (printer->windowState) {
        case MSG_WINDOW_STATE_D:
            scale = (f32)D_8014C580[printer->fadeInCounter] / 100.0;
            rotZ = (4 - printer->fadeInCounter) * 3;
            printer->fadeInCounter++;
            if (D_8014C580[printer->fadeInCounter] == 0) {
                printer->windowState = MSG_WINDOW_STATE_PRINTING;
            }
            break;
        case MSG_WINDOW_STATE_E:
            scale = (f32)D_8014C588[printer->fadeOutCounter] / 100.0;
            rotZ = -printer->fadeOutCounter;
            printer->fadeOutCounter++;
            if (D_8014C588[printer->fadeOutCounter] == 0) {
                printer->stateFlags |= MSG_STATE_FLAG_1;
            }
            break;
    }

    switch (printer->windowState) {
        case MSG_WINDOW_STATE_D:
        case MSG_WINDOW_STATE_E:
            printer->windowBasePos.x = 160 - (printer->windowSize.x / 2);
            printer->windowBasePos.y = 56;
            draw_box(DRAW_FLAG_ROTSCALE, WINDOW_STYLE_0, printer->windowBasePos.x, 56, 0, printer->windowSize.x, printer->windowSize.y, 255, 0,
                     scale, scale, 0.0f, 0.0f, rotZ, drawbox_message_delegate, printer, NULL, SCREEN_WIDTH,
                     SCREEN_HEIGHT, NULL);
            break;
        default:
            appendGfx_message(printer, printer->windowOffsetPos.x, printer->windowOffsetPos.y, printer->unk_46C,
                              printer->curLinePos, 4, 0);
            break;
    }
}

#if VERSION_JP
#define MSG_NORMAL_WIDTH        192
#define MSG_NORMAL_X            32
#define MSG_NORMAL_WIN_WIDTH    256
#define MSG_NORMAL_WIN_HEIGHT   64
#define MSG_NORMAL_TEXT_Y       8
#define MSG_NORMAL_ARROW_X      253
#define MSG_NORMAL_ARROW_Y      56
#define MSG_NORMAL_HEIGHT_CAP   64
#define MSG_NORMAL_PAGE_HT      16
#define MSG_INSPECT_TEXT_Y      5
#define MSG_SIGN_TEXT_Y         13
#define MSG_SIGN_WIDTH          240
#define MSG_SIGN_OFFSET_X       20
#define MSG_POPUP_TEXT_Y        8
#define MSG_EPILOGUE_TEXT_Y     0
#else
#define MSG_NORMAL_WIDTH        218
#define MSG_NORMAL_X            22
#define MSG_NORMAL_WIN_WIDTH    296
#define MSG_NORMAL_WIN_HEIGHT   68
#define MSG_NORMAL_TEXT_Y       6
#define MSG_NORMAL_ARROW_X      276
#define MSG_NORMAL_ARROW_Y      57
#define MSG_NORMAL_HEIGHT_CAP   68
#define MSG_NORMAL_PAGE_HT      14
#define MSG_INSPECT_TEXT_Y      3
#define MSG_SIGN_TEXT_Y         11
#define MSG_SIGN_WIDTH          280
#define MSG_SIGN_OFFSET_X       0
#define MSG_POPUP_TEXT_Y        4
#define MSG_EPILOGUE_TEXT_Y     -2
#endif

#if VERSION_IQUE || VERSION_PAL
INCLUDE_ASM(s32, "msg_draw", appendGfx_message);
#else
void appendGfx_message(MessagePrintState* printer, s16 posX, s16 posY, u16 additionalOffsetX, u16 additionalOffsetY,
                       u16 flag, u8 alpha) {
    SpriteRasterInfo sprRasterInfo;
    u16 sp80bool;
    s16 sp8E;
    s16 sp96;
    s16 sp9E;
    s16 palette;
    s16 spAE;
    u16 spB6;
    u8 spB8;
    f32 windowScaleX;
    MessageCharset* msgCharset;
    f32 temp_f10;
    f32 temp_f20;
    f32 temp_f20_3;
    f32 temp_f22_2;
    f32 temp_f24;
    f32 bubbleX;
    f32 bubbleY;
    f32 temp_f28;
    f32 windowScaleY;
    f32 temp_f8;
    f32 temp_f8_5;
    f64 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2_2;
    f64 temp_f20_2;
    f64 temp_f22;
    f32 temp_f2;
    f64 temp_f2_3;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_a2;
    s32 temp_s1_5;
    s32 i;
    s16 temp_s3;
    s16 temp_s4;
    s32 windowSizeX;
    s32 windowSizeY;
    s16 temp_s5;
    s16 temp_s6;
    u32 temp_a0_49;
    s32 animIdx;
    u8 packedScaleX;
    u8 packedScaleY;
    MessageImageData* msgVarImage;
    MessageImageData* msgImageData;
    s32 phi_a0;
    s32 straightWidth;
    s32 curveWidth;
    s32 height;
    s32 frameX;
    s32 frameY;
    s32 frameSizeX;
    s32 frameSizeY;
    s32 frameFading;
    u8 frameAlpha;
    u16 fading;
    u8 phi_s0_5;
    IMG_PTR signRaster;
    PAL_PTR signPalette;
    s8 phi_s2_4;
    u8 phi_s3_2;
    s32 phi_v0_3;
    s32 phi_a0_4;
    s16 phi_t5;
    s16 phi_s0_6;
    s16 phi_t3;
    s32 dbPos;
    s16 charPosX;
    s16 charPosY;
    s16 phi_s2_5;
    s32 phi_s0_7;
    s32 phi_s1_8;
    s8 varImgHasBorder;
    s16 imgDrawPosX;
    s16 imgDrawPosY;
    f32 z1;
    f32 z2;
    f32 temp1;
    f32 temp2;
#if VERSION_JP
    u8 rasterOffsetY;
#else
    s8 rasterOffsetY;
#endif
    s16 baseOffsetY;

    msg_drawState = &D_80155D20;
    msg_drawState->printBuffer = printer->printBuffer;
    msg_drawState->printModeFlags = 0;
    if (gMainGfxPos != D_80151338) {
        msg_reset_gfx_state();
    }
    msg_drawState->printModeFlags |= (MSG_PRINT_FLAG_1 | MSG_PRINT_FLAG_100);
    sp8E = 255;
    if (flag & 1) {
        sp8E = alpha;
    }
    msg_drawState->textStartPos[0] = 0;
    msg_drawState->textStartPos[1] = 0;
    msg_drawState->clipX[0] = 0;
    msg_drawState->clipY[0] = 0;
    msg_drawState->clipX[1] = SCREEN_WIDTH - 1;
    msg_drawState->clipY[1] = SCREEN_HEIGHT - 1;
    msg_drawState->msgScale.x = 1.0f;
    msg_drawState->msgScale.y = 1.0f;
    msg_drawState->unk_29 = 0;
    msg_drawState->framePalette = 0;
    msg_drawState->unk_2C = 0;
    msg_drawState->visiblePrintedCount = 0;
    msg_drawState->centerPos = 0;
    msg_drawState->fontVariant = 0;
    msg_drawState->curPosX = 0;
    msg_drawState->nextPos[0] = 0;
    msg_drawState->nextPos[1] = 0;
    msg_drawState->font = 0;
    msg_drawState->effectFlags = 0;
    msg_drawState->nextCounter = 0;
    msg_drawState->textColor = MSG_PAL_WHITE;
    sp96 = 0xFF;
    spAE = 0xFF;
    spB6 = 0;
    spB8 = 0;
    sp9E = -1;

    if (flag & 2) {
        msg_drawState->font = 1;
    }

    if (flag & 4) {
        gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }

    sp80bool = FALSE;
    msg_drawState->drawBufferPos = 0;

    while (!sp80bool) {
        switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos]) {
            case MSG_CHAR_PRINT_ENDL:
                msg_drawState->nextPos[0] = 0;
                msg_drawState->nextPos[1] += (s32)((msg_drawState->msgScale.y * MsgCharsets[msg_drawState->font]->newLineY)
#if !VERSION_JP
                                                   + MsgStyleVerticalLineOffsets[printer->style]
#endif
                                                   );
                if (msg_drawState->printModeFlags & MSG_PRINT_FLAG_40) {
                    msg_drawState->printModeFlags |= MSG_PRINT_FLAG_80;
                }
                msg_drawState->drawBufferPos++;
                break;
            case MSG_CHAR_PRINT_UNK_CHAR_FA:
                msg_drawState->drawBufferPos++;
                break;
            case MSG_CHAR_PRINT_VARIANT0:
            case MSG_CHAR_PRINT_VARIANT1:
            case MSG_CHAR_PRINT_VARIANT2:
            case MSG_CHAR_PRINT_VARIANT3:
                msg_drawState->fontVariant = msg_drawState->printBuffer[msg_drawState->drawBufferPos] - MSG_CHAR_PRINT_VARIANT0;
                msg_drawState->drawBufferPos++;
                break;
            case MSG_CHAR_PRINT_SPACE:
            case MSG_CHAR_PRINT_FULL_SPACE:
            case MSG_CHAR_PRINT_HALF_SPACE:
                msg_drawState->nextPos[0] += msg_get_draw_char_width(msg_drawState->printBuffer[msg_drawState->drawBufferPos],
                                             msg_drawState->font, msg_drawState->fontVariant, msg_drawState->msgScale.x, msg_drawState->curPosX,
                                             msg_drawState->printModeFlags);
                msg_drawState->drawBufferPos++;
                break;
            case MSG_CHAR_PRINT_STYLE:
                switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]) {
                    case MSG_STYLE_RIGHT:
                    case MSG_STYLE_LEFT:
                    case MSG_STYLE_CENTER:
                    case MSG_STYLE_TATTLE:
                        if (printer->windowState == MSG_WINDOW_STATE_OPENING && printer->fadeInCounter == 0) {
                            printer->openStartPos.x = printer->initOpenPos.x;
                            printer->openStartPos.y = printer->initOpenPos.y;
                        }
                        temp_s6 = printer->openStartPos.x;
                        temp_s5 = printer->openStartPos.y;
                        temp_s4 = printer->windowBasePos.x + (f32) printer->windowSize.x * 0.5;
                        temp_s3 = printer->windowBasePos.y + (f32) printer->windowSize.y * 0.5;
                        msg_drawState->textColor = MSG_PAL_STANDARD;
                        msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;

                        if (printer->style == MSG_STYLE_RIGHT || printer->style == MSG_STYLE_LEFT || printer->style == MSG_STYLE_CENTER) {
                            straightWidth = MSG_NORMAL_WIDTH;
                            printer->windowBasePos.x = MSG_NORMAL_X;
                            printer->windowBasePos.y = 13;
                            printer->windowSize.x = MSG_NORMAL_WIN_WIDTH;
                            printer->windowSize.y = MSG_NORMAL_WIN_HEIGHT;
                            msg_drawState->textStartPos[0] = 26;
                            msg_drawState->textStartPos[1] = MSG_NORMAL_TEXT_Y;
                            printer->rewindArrowPos.x = MSG_NORMAL_ARROW_X;
                            printer->rewindArrowPos.y = MSG_NORMAL_ARROW_Y;
                            curveWidth = 32;
                            height = MSG_NORMAL_HEIGHT_CAP;
                        } else {
                            straightWidth = 218;

#if VERSION_JP
                            if (printer->maxLinesPerPage == 1) {
                                msg_drawState->textStartPos[0] = 18;
                                msg_drawState->textStartPos[1] = 10;
                                curveWidth = 24;
                            } else if (printer->maxLinesPerPage == 2) {
                                msg_drawState->textStartPos[0] = 22;
                                msg_drawState->textStartPos[1] = 8;
                                curveWidth = 28;
                            } else {
                                msg_drawState->textStartPos[0] = 26;
                                msg_drawState->textStartPos[1] = 8;
                                curveWidth = 32;
                            }
#else
                            switch (printer->maxLinesPerPage) {
                                case 1:
                                    msg_drawState->textStartPos[0] = 18;
                                    msg_drawState->textStartPos[1] = 10;
                                    curveWidth = 24;
                                    break;
                                case 2:
                                    msg_drawState->textStartPos[0] = 22;
                                    msg_drawState->textStartPos[1] = 6;
                                    curveWidth = 28;
                                    break;
                                case 3:
                                    msg_drawState->textStartPos[0] = 26;
                                    msg_drawState->textStartPos[1] = 8;
                                    curveWidth = 32;
                                    break;
                                default:
                                    msg_drawState->textStartPos[0] = 26;
                                    msg_drawState->textStartPos[1] = 6;
                                    curveWidth = 32;
                                    break;
                            }
#endif

                            straightWidth = printer->msgWidth;
                            if (straightWidth > 256) {
                                straightWidth = 256;
                            }
                            if (straightWidth < 70) {
                                straightWidth = 70;
                            }
                            straightWidth -= 12;

                            printer->windowSize.x = straightWidth + (curveWidth * 2);

                            height = (printer->maxLinesPerPage * MSG_NORMAL_PAGE_HT) + 16;
                            if (height > MSG_NORMAL_HEIGHT_CAP) {
                                height = MSG_NORMAL_HEIGHT_CAP;
                            }
                            if (height < 36) {
                                height = 36;
                            }
                            printer->windowSize.y = height;

                            temp_a2 = printer->openStartPos.x - printer->windowSize.x / 2;
                            if (temp_a2 < 18) {
                                temp_a2 = 18;
                            }
                            if (temp_a2 + printer->windowSize.x > SCREEN_WIDTH - 18) {
                                temp_a2 = SCREEN_WIDTH - 18 - printer->windowSize.x;
                            }
                            phi_a0 = printer->openStartPos.y - 38 - printer->windowSize.y;
                            if (phi_a0 < 20) {
                                phi_a0 = 20;
                            }
                            if (phi_a0 + printer->windowSize.y > 170) {
                                phi_a0 = 170 - printer->windowSize.y;
                            }
                            printer->windowBasePos.x = temp_a2;
                            printer->windowBasePos.y = phi_a0;
                            printer->rewindArrowPos.x = (printer->windowSize.x + temp_a2) - 30;
                            printer->rewindArrowPos.y = (printer->windowSize.y + phi_a0) - 18;
                        }

                        if (printer->windowState == MSG_WINDOW_STATE_B || printer->windowState == MSG_WINDOW_STATE_C) {
                            msg_drawState->framePalette = 1;
                        }

                        if (printer->windowState == MSG_WINDOW_STATE_OPENING) {
                            windowScaleX = update_lerp(EASING_LINEAR, 0.07f, 1.0f, printer->fadeInCounter, 7);
                            windowScaleY = update_lerp(EASING_LINEAR, 0.3f, 1.0f, printer->fadeInCounter, 7);
                            temp_f28 = update_lerp(EASING_LINEAR, 96.0f, 200.0f, printer->fadeInCounter, 7);
                            temp_f20 = update_lerp(EASING_SIN_OUT, temp_s5, temp_s3, printer->fadeInCounter, 7);
                            temp_f24 = update_lerp(EASING_SIN_OUT, temp_s6, temp_s4, printer->fadeInCounter, 7);
                            temp_f2_2 = printer->windowSize.x * windowScaleX;
                            temp_f0_2 = printer->windowSize.y * windowScaleY;
                            bubbleX = (temp_f24 - temp_f2_2 * 0.5) + 0.5;
                            bubbleY = (temp_f20 - temp_f0_2 * 0.5) + 0.5;
                            msg_draw_speech_bubble(printer, bubbleX, bubbleY, straightWidth, curveWidth, height, windowScaleX, windowScaleY, temp_f28, 1);
                            printer->fadeInCounter++;
                            if (printer->fadeInCounter == 7) {
                                printer->windowState = MSG_WINDOW_STATE_PRINTING;
                            }
                        } else if (printer->windowState == MSG_WINDOW_STATE_CLOSING) {
                            printer->fadeOutCounter++;
                            windowScaleX = update_lerp(EASING_LINEAR, 1.0f, 0.6f, printer->fadeOutCounter, 5);
                            windowScaleY = update_lerp(EASING_LINEAR, 1.0f, 0.8f, printer->fadeOutCounter, 5);
                            temp_f2 = (printer->windowSize.x * windowScaleX);
                            temp_f0 = (printer->windowSize.y * windowScaleY);
                            temp_f24 = temp_s4;
                            temp_f20 = temp_s3;
                            bubbleX = (temp_f24 - temp_f2 * 0.5) + 0.5;
                            bubbleY = (temp_f20 - temp_f0 * 0.5) + 0.5;
                            temp_f22_2 = (temp_f24 + temp_f2 * 0.5) - 0.5;
                            temp_f20_3 = (temp_f20 + temp_f0 * 0.5) - 0.5;
                            temp_f28 = update_lerp(EASING_LINEAR, 255.0f, 64.0f, printer->fadeOutCounter, 5);
                            sp8E = temp_f28 * 0.35;
                            spAE = temp_f28;
                            msg_drawState->clipX[0] = bubbleX + msg_drawState->textStartPos[0];
                            msg_drawState->clipY[0] = bubbleY + msg_drawState->textStartPos[1];
                            msg_drawState->clipX[1] = temp_f22_2 - msg_drawState->textStartPos[0];
                            msg_drawState->clipY[1] = temp_f20_3 - msg_drawState->textStartPos[1];
                            msg_draw_speech_bubble(printer, bubbleX, bubbleY, straightWidth, curveWidth, height, windowScaleX, windowScaleY, temp_f28, 1);
                            if (printer->fadeOutCounter >= 5) {
                                printer->stateFlags |= MSG_STATE_FLAG_1;
                            }
                        } else {
                            bubbleX = posX + printer->windowBasePos.x;
                            bubbleY = posY + printer->windowBasePos.y;

                            msg_draw_speech_bubble(printer, bubbleX, bubbleY, straightWidth, curveWidth, height, 1.0f, 1.0f, 255, 1);
                            if (((u32)(printer->openStartPos.x - 20) <= 280) && (printer->openStartPos.y <= 220)) {
                                msg_draw_speech_arrow(printer);
                            }
                        }

                        if (printer->windowState != MSG_WINDOW_STATE_CLOSING) {
                            msg_drawState->clipX[0] = 20;
                            msg_drawState->clipY[0] = printer->windowOffsetPos.y + printer->windowBasePos.y +
                                                      msg_drawState->textStartPos[1];
                            msg_drawState->clipX[1] = SCREEN_WIDTH - 20;
                            msg_drawState->clipY[1] = msg_drawState->clipY[0] + printer->windowSize.y - 16;
                        }
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_STYLE_CHOICE:
                        frameFading = 0;
                        windowSizeX = printer->windowSize.x;
                        windowSizeY = printer->windowSize.y;
                        frameSizeX = windowSizeX;
                        frameSizeY = windowSizeY;
                        msg_drawState->framePalette = 0;
                        msg_drawState->textStartPos[0] = 12;
                        msg_drawState->textStartPos[1] = 6;
                        frameAlpha = 255;
                        if (printer->windowState == MSG_WINDOW_STATE_OPENING) {

                            printer->fadeInCounter++;
                            if (printer->fadeInCounter == 6) {
                                printer->windowState = MSG_WINDOW_STATE_PRINTING;
                            }

                            temp_f10 = ((f32) printer->fadeInCounter * (2.0 / 15.0)) + 0.2;

                            z1 = printer->windowBasePos.x + (windowSizeX / 2);
                            z2 = printer->windowBasePos.y + (windowSizeY / 2);
                            temp1 = z1 - (windowSizeX * temp_f10 * 0.5);
                            temp2 = z2 - (windowSizeY * temp_f10 * 0.5);
                            frameX = temp1 + 0.5;
                            frameY = temp2 + 0.5;
                            frameSizeX = windowSizeX * temp_f10 + 0.5;
                            frameSizeY = windowSizeY * temp_f10 + 0.5;

                            if (frameSizeX < 24) {
                                frameSizeX = 24;
                            }
                            if (frameSizeY < 24) {
                                frameSizeY = 24;
                            }

                            sp8E = (u8)(temp_f10 * 255.0) * 0.6;
                        } else if (printer->windowState == MSG_WINDOW_STATE_CLOSING) {
                            printer->fadeOutCounter++;
                            if (printer->fadeOutCounter >= 5) {
                                printer->stateFlags |= MSG_STATE_FLAG_1;
                            }
                            frameAlpha = ~(printer->fadeOutCounter * 0x2E);
                            sp8E = ((u8)frameAlpha) * 0.6;
                            frameFading = 1;
                            if (sp8E >= 32) {
                                sp8E -= 32;
                            }
                            frameX = printer->windowBasePos.x;
                            frameY = printer->windowBasePos.y;
                        } else {
                            frameX = printer->windowBasePos.x;
                            frameY = printer->windowBasePos.y;
                            msg_draw_prim_rect(255, 32, 32, 0, frameX - 1, frameY - 1, windowSizeX + 2, windowSizeY + 2);
                        }
                        msg_drawState->clipX[0] = frameX + 2;
                        msg_drawState->clipY[0] = frameY + 2;
                        msg_drawState->clipX[1] = frameX + frameSizeX - 2;
                        msg_drawState->clipY[1] = frameY + frameSizeY - 2;
                        msg_draw_frame(frameX, frameY, frameSizeX, frameSizeY, MSG_STYLE_CHOICE, msg_drawState->framePalette, frameFading, frameAlpha,
                                       frameAlpha);
                        msg_reset_gfx_state();
                        spAE = frameAlpha & 0xFF;
                        msg_drawState->textColor = MSG_PAL_STANDARD;
                        msg_drawState->drawBufferPos += 2;
                        msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                        break;
                    case MSG_STYLE_INSPECT:
                    case MSG_STYLE_UPGRADE:
                    case MSG_STYLE_NARRATE:
                    case MSG_STYLE_F:
                        fading = 0;
                        msg_drawState->textStartPos[0] = 16;
                        msg_drawState->textStartPos[1] = MSG_INSPECT_TEXT_Y;
                        msg_drawState->clipX[0] = printer->windowBasePos.x + 5;
                        msg_drawState->clipY[0] = printer->windowBasePos.y + 4;
                        msg_drawState->clipX[1] = printer->windowBasePos.x + printer->windowSize.x - 8;
                        msg_drawState->clipY[1] = printer->windowBasePos.y + printer->windowSize.y - 5;
                        printer->rewindArrowPos.x = msg_drawState->clipX[1] - 17;
                        printer->rewindArrowPos.y = msg_drawState->clipY[1] - 17;
                        msg_drawState->textColor = MSG_PAL_WHITE;
                        phi_s0_5 = 0xFF;
                        msg_draw_prim_rect(255, 32, 32, 0, printer->windowBasePos.x + 3, printer->windowBasePos.y - 1,
                                           printer->windowSize.x - 6, 1);
                        msg_draw_prim_rect(32, 255, 32, 0, printer->windowBasePos.x + 3,
                                           printer->windowBasePos.y + printer->windowSize.y, printer->windowSize.x - 6,
                                           1);

                        if (printer->windowState == MSG_WINDOW_STATE_OPENING) {
                            phi_s0_5 = (printer->fadeInCounter * 0x30) + 0x50;
                            sp8E = (phi_s0_5 & 0xFF) - 0x30;
                            printer->fadeInCounter++;
                            fading = 1;
                            if ((s16)printer->fadeInCounter == 4) { // TODO why is this cast needed
                                printer->windowState = MSG_WINDOW_STATE_PRINTING;
                            }
                        } else if (printer->windowState == MSG_WINDOW_STATE_CLOSING) {
                            phi_s0_5 = -0x30 - (printer->fadeOutCounter * 40);
                            sp8E = (phi_s0_5 & 0xFF) - 0x30;
                            printer->fadeOutCounter++;
                            fading = 1;
                            if (printer->fadeOutCounter == 4) {
                                printer->stateFlags |= MSG_STATE_FLAG_1;
                            }
                        }

                        msg_draw_frame(printer->windowBasePos.x, printer->windowBasePos.y, printer->windowSize.x, printer->windowSize.y, MSG_STYLE_INSPECT,
                                       msg_drawState->framePalette, fading, phi_s0_5, phi_s0_5);
                        msg_reset_gfx_state();
                        spAE = phi_s0_5 & 0xFF;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_STYLE_SIGN:
                    case MSG_STYLE_LAMPPOST:
                        msg_drawState->textStartPos[0] = 18;
                        msg_drawState->textStartPos[1] = MSG_SIGN_TEXT_Y;
                        printer->windowBasePos.x = 20 + MSG_SIGN_OFFSET_X;
                        printer->windowBasePos.y = 28;
                        printer->windowSize.x = MSG_SIGN_WIDTH;
                        msg_drawState->framePalette = 15;
                        temp_s1_5 = 0xFF;
                        if (printer->style == MSG_STYLE_SIGN) {
                            signRaster = ui_msg_sign_corner_bottomright_png;
                            printer->windowSize.y = 72;
                            msg_drawState->textColor = MSG_PAL_18;
                            signPalette = ui_msg_sign_pal;
                        } else {
                            signRaster = ui_msg_lamppost_corner_bottomright_png;
                            msg_drawState->textColor = MSG_PAL_1C;
                            signPalette = ui_msg_lamppost_pal;
                        }
                        msg_drawState->clipX[0] = 20 + MSG_SIGN_OFFSET_X + 14;
                        msg_drawState->clipY[0] = 40;
                        msg_drawState->clipX[1] = 283 - MSG_SIGN_OFFSET_X;
                        msg_drawState->clipY[1] = printer->windowSize.y + 17;
                        printer->rewindArrowPos.x = msg_drawState->clipX[1] - 16;
                        printer->rewindArrowPos.y = msg_drawState->clipY[1] - 9;

                        if (printer->windowState == MSG_WINDOW_STATE_OPENING) {
                            temp_s1_5 = (printer->fadeInCounter << 6) + 0x50;
                            sp8E = (temp_s1_5 & 0xFF) - 0x30;
                            printer->fadeInCounter++;
                            if (printer->fadeInCounter == 3) {
                                printer->windowState = MSG_WINDOW_STATE_PRINTING;
                            }
                        } else {
                            if (printer->windowState == MSG_WINDOW_STATE_CLOSING) {
                                temp_s1_5 = -0x30 - (printer->fadeOutCounter * 0x30);
                                sp8E = (temp_s1_5 & 0xFF) - 0x30;
                                printer->fadeOutCounter++;
                                if (printer->fadeOutCounter == 3) {
                                    printer->stateFlags |= MSG_STATE_FLAG_1;
                                }
                            }
                        }
                        spAE = (u8)temp_s1_5;
                        draw_ci_image_with_clipping(ui_msg_sign_corner_topleft_png, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, signPalette, 20 + MSG_SIGN_OFFSET_X,
                                                    28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(ui_msg_sign_corner_topright_png, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, signPalette, 284 - MSG_SIGN_OFFSET_X,
                                                    28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(ui_msg_sign_corner_bottomleft_png, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, signPalette, 20 + MSG_SIGN_OFFSET_X, 
                                                    printer->windowSize.y + 12, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(signRaster, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, signPalette, 284 - MSG_SIGN_OFFSET_X, printer->windowSize.y + 12,
                                                    10, 10, 310, 230, temp_s1_5);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_side_top_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, (36 + MSG_SIGN_OFFSET_X) * 4, 28 * 4, (284 - MSG_SIGN_OFFSET_X) * 4, 44 * 4, G_TX_RENDERTILE, 0, 0,
                                            0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_side_left_png, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, (20 + MSG_SIGN_OFFSET_X) * 4, 44 * 4, (36 + MSG_SIGN_OFFSET_X) * 4, (printer->windowSize.y + 12) * 4,
                                            G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_side_right_png, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, (284 - MSG_SIGN_OFFSET_X) * 4, 44 * 4, (300 - MSG_SIGN_OFFSET_X) * 4, (printer->windowSize.y + 12) * 4,
                                            G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_side_bottom_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, (36 + MSG_SIGN_OFFSET_X) * 4, (printer->windowSize.y + 12) * 4, (284 - MSG_SIGN_OFFSET_X) * 4,
                                            (printer->windowSize.y + 28) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_fill_png, G_IM_FMT_CI, 8, 0, 0, 0, 7, 7, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 3, 3, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, (36 + MSG_SIGN_OFFSET_X) * 4, 44 * 4, (283 - MSG_SIGN_OFFSET_X + 1) * 4, (printer->windowSize.y + 12) * 4,
                                            G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_STYLE_POSTCARD:
                        phi_s2_4 = 0;
                        msg_drawState->textStartPos[0] = 12;
                        msg_drawState->textStartPos[1] = 5;
                        printer->windowBasePos.x = 40;
                        printer->windowBasePos.y = 28;
                        msg_drawState->clipX[0] = 45;
                        msg_drawState->clipY[0] = 32;
                        msg_drawState->clipX[1] = 272;
                        msg_drawState->clipY[1] = 81;
                        printer->rewindArrowPos.x = msg_drawState->clipX[1] - 21;
                        printer->rewindArrowPos.y = msg_drawState->clipY[1] - 20;
                        msg_drawState->framePalette = 0;
                        msg_drawState->textColor = MSG_PAL_WHITE;
                        msg_draw_prim_rect(255, 32, 32, 0, 43, 27, 234, 1);
                        msg_draw_prim_rect(32, 255, 32, 0, 43, 86, 234, 1);
                        phi_s3_2 = 0xFF;
                        if (printer->windowState == MSG_WINDOW_STATE_OPENING) {
                            phi_s3_2 = (printer->fadeInCounter * 64) + 80;
                            sp8E = (phi_s3_2 & 0xFF) - 0x30;
                            printer->fadeInCounter++;
                            if (printer->fadeInCounter == 3) {
                                printer->windowState = MSG_WINDOW_STATE_PRINTING;
                            }
                            phi_s2_4 = 1;
                        } else if (printer->windowState == MSG_WINDOW_STATE_CLOSING) {
                            phi_s3_2 = -0x30 - (printer->fadeOutCounter * 0x30);
                            sp8E = (phi_s3_2 & 0xFF) - 0x30;
                            printer->fadeOutCounter++;
                            if (printer->fadeOutCounter == 3) {
                                printer->stateFlags |= MSG_STATE_FLAG_1;
                            }
                            phi_s2_4 = 1;
                        }
                        msg_draw_frame(40, 28, 240, 58, MSG_STYLE_INSPECT, msg_drawState->framePalette, phi_s2_4, phi_s3_2, phi_s3_2);
                        draw_ci_image_with_clipping(printer->letterBackgroundImg, 150, 105, G_IM_FMT_CI, G_IM_SIZ_4b,
                                                    printer->letterBackgroundPal, 85, 97, 10, 10, 300, 220, phi_s3_2);
                        draw_ci_image_with_clipping(printer->letterContentImg, 70, 95, G_IM_FMT_CI, G_IM_SIZ_8b,
                                                    printer->letterContentPal, 160, 102, 10, 10, 300, 220, phi_s3_2);
                        msg_reset_gfx_state();
                        spAE = phi_s3_2 & 0xFF;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_STYLE_POPUP:
                    case MSG_STYLE_B:
                        msg_drawState->textStartPos[0] = 16;
                        msg_drawState->textStartPos[1] = MSG_POPUP_TEXT_Y;
                        msg_drawState->clipX[0] = 0;
                        msg_drawState->clipX[1] = SCREEN_WIDTH - 1;
                        msg_drawState->clipY[0] = 0;
                        msg_drawState->clipY[1] = SCREEN_HEIGHT - 1;
                        msg_drawState->textColor = MSG_PAL_WHITE;
                        msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                        if (printer->windowState == MSG_WINDOW_STATE_D || printer->windowState == MSG_WINDOW_STATE_E) {
                            printer->windowBasePos.x = 0;
                            printer->windowBasePos.y = 0;
                        } else {
                            printer->windowBasePos.x = 160 - printer->windowSize.x / 2;
                            printer->windowBasePos.y = 56;
                            draw_box(0, WINDOW_STYLE_0, printer->windowBasePos.x, 56, 0, printer->windowSize.x,
                                     printer->windowSize.y, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL,
                                     SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
                        }
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_STYLE_EPILOGUE:
                        printer->windowBasePos.x = 60;
                        printer->windowBasePos.y = 110;
                        printer->windowSize.x = 200;
                        printer->windowSize.y = 50;
                        msg_drawState->textStartPos[0] = 0;
                        msg_drawState->textStartPos[1] = MSG_EPILOGUE_TEXT_Y;
                        msg_drawState->clipX[0] = printer->windowBasePos.x;
                        msg_drawState->clipY[0] = printer->windowBasePos.y;
                        msg_drawState->clipX[1] = printer->windowBasePos.x + printer->windowSize.x;
                        msg_drawState->clipY[1] = printer->windowBasePos.y + printer->windowSize.y;
                        printer->rewindArrowPos.x = printer->windowBasePos.x + printer->windowSize.x - 10;
                        printer->rewindArrowPos.y = printer->windowBasePos.y + printer->windowSize.y - 10;
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos += 2;
                        break;
                }
                break;
            case MSG_CHAR_PRINT_NEXT:
                if (printer->windowState == MSG_WINDOW_STATE_C) {
                    if (msg_drawState->nextCounter >= printer->unkArraySize) {
                        sp80bool = TRUE;
                    }
                } else if (printer->windowState == MSG_WINDOW_STATE_B) {
                    if (printer->curLinePos < printer->lineEndPos[printer->unkArraySize]) {
                        if (msg_drawState->nextCounter >= printer->unkArraySize) {
                            sp80bool = TRUE;
                        }
                    } else {
                        if (printer->unkArraySize < msg_drawState->nextCounter) {
                            sp80bool = TRUE;
                        } else if (msg_drawState->nextCounter >= printer->unkArraySize) {
                            phi_a0_4 = 36;
                            if (printer->maxLinesPerPage >= 2) {
                                phi_v0_3 = 48;
                                if (printer->maxLinesPerPage == 2) {
                                    phi_v0_3 = 32;
                                }
                                if (printer->unk_4C8 < phi_v0_3) {
                                    if (printer->unk_4C8 <= 0x10) {
                                        phi_a0_4 = 56;
                                    }
                                    sp8E = 0xFF - (phi_a0_4 * printer->unk_4CC);
                                    if (sp8E < 0) {
                                        sp8E = 0;
                                    }
                                }
                            }
                        }
                    }
                }
                msg_drawState->nextCounter++;
                msg_drawState->drawBufferPos++;
                break;
            case MSG_CHAR_PRINT_END:
                sp80bool = TRUE;
                break;
            case MSG_CHAR_PRINT_FUNCTION:
                msg_drawState->drawBufferPos++;
                switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos]) {
                    case MSG_PRINT_FUNC_FONT:
                        msg_drawState->font = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                        break;
                    case MSG_PRINT_FUNC_VARIANT:
                        msg_drawState->fontVariant = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_COLOR:
                        msg_drawState->textColor = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_SPACING:
                        msg_drawState->curPosX = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_SIZE:
                        packedScaleX = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->msgScale.x = (f32)(packedScaleX >> 4) + ((packedScaleX & 0xF) * 0.0625f);
                        packedScaleY = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                        msg_drawState->msgScale.y = (f32)(packedScaleY >> 4) + ((packedScaleY & 0xF) * 0.0625f);
                        msg_drawState->drawBufferPos += 3;
                        if (msg_drawState->msgScale.x > 1.0 || msg_drawState->msgScale.y > 1.0) {
                            gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
                        } else if (msg_drawState->msgScale.x < 1.0 || msg_drawState->msgScale.y < 1.0) {
                            gDPSetTextureFilter(gMainGfxPos++, G_TF_AVERAGE);
                        }
                        break;
                    case MSG_PRINT_FUNC_SIZE_RESET:
                        msg_drawState->msgScale.x = 1.0f;
                        msg_drawState->msgScale.y = 1.0f;
                        msg_drawState->drawBufferPos++;
                        gDPSetTextureFilter(gMainGfxPos++, G_TF_AVERAGE);
                        break;
                    case MSG_PRINT_FUNC_SET_X:
                        msg_drawState->nextPos[0] = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] * 256 +
                                                    (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2]);
                        msg_drawState->drawBufferPos += 3;
                        break;
                    case MSG_PRINT_FUNC_SET_Y:
                        msg_drawState->nextPos[1] = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_RIGHT:
                        msg_drawState->nextPos[0] += msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_DOWN:
                        msg_drawState->nextPos[1] += msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_UP:
                        msg_drawState->nextPos[1] -=  msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_INLINE_IMAGE:
                        msgImageData = &(*gMsgVarImages)[msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]];
                        phi_t5 = sp8E;
                        if (sp8E < 0xFF) {
                            phi_t5 = (s32)(sp8E * 0.7);
                        }
                        imgDrawPosX = (s16)((msg_drawState->nextPos[0] + (msg_drawState->textStartPos[0] + (printer->windowBasePos.x + posX))) -
                                   additionalOffsetX);
                        imgDrawPosY = (s16)((msg_drawState->nextPos[1] + (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY))) -
                                   additionalOffsetY);

                        draw_ci_image_with_clipping(msgImageData->raster, msgImageData->width, msgImageData->height, msgImageData->format, msgImageData->bitDepth,
                                                    msgImageData->palette, imgDrawPosX, imgDrawPosY, (s32) msg_drawState->clipX[0], (s32) msg_drawState->clipY[0],
                                                    msg_drawState->clipX[1] - msg_drawState->clipX[0], msg_drawState->clipY[1] - msg_drawState->clipY[0], phi_t5);
                        msg_drawState->printModeFlags |= (MSG_PRINT_FLAG_2 | MSG_PRINT_FLAG_10);
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_ANIM_SPRITE:
                        phi_s0_6 = sp8E;
                        if (sp8E < 0xFF) {
                            phi_s0_6 = (s32)(sp8E * 0.7);
                        }

                        if (spr_get_npc_raster_info(&sprRasterInfo, (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] << 8) |
                                                    msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                                    msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3]) != 0) {
                            imgDrawPosX = (s16)((msg_drawState->nextPos[0] + (msg_drawState->textStartPos[0] + (printer->windowBasePos.x + posX))) -
                                       additionalOffsetX);
                            imgDrawPosY = (s16)((msg_drawState->nextPos[1] + (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY))) -
                                       additionalOffsetY);

                            draw_ci_image_with_clipping(sprRasterInfo.raster, sprRasterInfo.width, sprRasterInfo.height, G_IM_FMT_CI, G_IM_SIZ_4b, sprRasterInfo.defaultPal, imgDrawPosX, imgDrawPosY,
                                                        msg_drawState->clipX[0], msg_drawState->clipY[0], msg_drawState->clipX[1] - msg_drawState->clipX[0],
                                                        msg_drawState->clipY[1] - msg_drawState->clipY[0], phi_s0_6);
                            msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                        }
                        msg_drawState->drawBufferPos += 4;
                        break;
                    case MSG_PRINT_FUNC_ITEM_ICON:
                        if (D_8015131C != 0) {
                            phi_t3 = sp8E;
                            if (sp8E < 0xFF) {
                                phi_t3 = (s32)(sp8E * 0.7);
                            }
                            imgDrawPosX = (s16)((msg_drawState->nextPos[0] + (msg_drawState->textStartPos[0] + (printer->windowBasePos.x + posX))) -
                                       additionalOffsetX);
                            imgDrawPosY = (s16)((msg_drawState->nextPos[1] + (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY))) -
                                       additionalOffsetY);

                            draw_ci_image_with_clipping(D_80159B50, 32, 32, G_IM_FMT_CI, G_IM_SIZ_4b, D_8015C7E0, imgDrawPosX, imgDrawPosY, msg_drawState->clipX[0],
                                                        msg_drawState->clipY[0], msg_drawState->clipX[1] - msg_drawState->clipX[0],
                                                        msg_drawState->clipY[1] - msg_drawState->clipY[0], phi_t3);
                            msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                        }
                        msg_drawState->drawBufferPos++;
                        break;
                    case MSG_PRINT_FUNC_ANIM_DELAY:
                        animIdx = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        if (printer->animTimers[animIdx] == -1) {
                            printer->animTimers[animIdx] = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3];
                        }
                        if (printer->animTimers[animIdx] == 0) {
                            printer->curAnimFrame[animIdx]++;
                        }

                        dbPos = msg_drawState->drawBufferPos;
                        while (TRUE) {
                            if ((msg_drawState->printBuffer[dbPos - 1] == MSG_CHAR_PRINT_FUNCTION) &&
                                (msg_drawState->printBuffer[dbPos] == MSG_PRINT_FUNC_ANIM_DELAY) &&
                                (msg_drawState->printBuffer[dbPos + 1] == animIdx)) {
                                if (msg_drawState->printBuffer[dbPos + 2] != printer->curAnimFrame[animIdx]) {
                                    dbPos += 4;
                                } else {
                                    break;
                                }
                            } else {
                                if ((msg_drawState->printBuffer[dbPos] == MSG_CHAR_PRINT_FUNCTION) &&
                                    (msg_drawState->printBuffer[dbPos + 1] == MSG_PRINT_FUNC_ANIM_LOOP) &&
                                    (msg_drawState->printBuffer[dbPos + 2] == animIdx)) {

                                    if (printer->animTimers[animIdx] == 0) {
                                        printer->curAnimFrame[animIdx] = msg_drawState->printBuffer[dbPos + 3];
                                        dbPos = msg_drawState->drawBufferPos;
                                        continue;
                                    } else {
                                        dbPos++;
                                        break;
                                    }
                                } else {
                                    if (msg_drawState->printBuffer[dbPos] == MSG_CHAR_PRINT_FUNCTION &&
                                        msg_drawState->printBuffer[dbPos + 1] == MSG_PRINT_FUNC_ANIM_DONE) {
                                        if (msg_drawState->printBuffer[dbPos + 2] == animIdx) {
                                            dbPos++;
                                            break;
                                        }
                                    }
                                }
                            }
                            dbPos++;
                        }
                        msg_drawState->drawBufferPos = dbPos;

                        switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos]) {
                            case MSG_PRINT_FUNC_ANIM_DELAY:
                                if (printer->animTimers[animIdx] == 0) {
                                    if (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] == 0) {
                                        printer->animTimers[animIdx] = -2;
                                    } else {
                                        printer->animTimers[animIdx] = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3];
                                    }
                                }
                                msg_drawState->drawBufferPos += 4;
                                break;
                            case MSG_PRINT_FUNC_ANIM_LOOP:
                                msg_drawState->drawBufferPos += 3;
                                break;
                            case MSG_PRINT_FUNC_ANIM_DONE:
                                msg_drawState->drawBufferPos += 2;
                                break;
                        }
                        break;
                    case MSG_PRINT_FUNC_ANIM_LOOP:
                        msg_drawState->drawBufferPos += 3;
                        break;
                    case MSG_PRINT_FUNC_ANIM_DONE:
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_CURSOR:
                        printer->cursorPosX[msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]] = msg_drawState->textStartPos[0] +
                                msg_drawState->nextPos[0] - additionalOffsetX - 6;
                        printer->cursorPosY[msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]] = msg_drawState->textStartPos[1] +
                                msg_drawState->nextPos[1] - additionalOffsetY - 1;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_OPTION:
                        if (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] == 0xFF) {
                            msg_drawState->printModeFlags &= ~MSG_PRINT_FLAG_20;
                        } else {
                            msg_drawState->unk_2D = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                            msg_drawState->printModeFlags |= MSG_PRINT_FLAG_20;
                            msg_drawState->nextPos[0] += 14;
                        }
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_SET_FRAME_PALETTE:
                        msg_drawState->framePalette = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_RESET_GFX:
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos++;
                        break;
                    case MSG_PRINT_FUNC_SAVE_POS:
                        msg_drawState->savedPos[0] = msg_drawState->nextPos[0];
                        msg_drawState->savedPos[1] = msg_drawState->nextPos[1];
                        msg_drawState->drawBufferPos++;
                        break;
                    case MSG_PRINT_FUNC_RESTORE_POS:
                        msg_drawState->nextPos[0] = msg_drawState->savedPos[0];
                        msg_drawState->nextPos[1] = msg_drawState->savedPos[1];
                        msg_drawState->drawBufferPos++;
                        break;
                    case MSG_PRINT_FUNC_SAVE_COLOR:
                        msg_drawState->savedColor = msg_drawState->textColor;
                        msg_drawState->drawBufferPos++;
                        break;
                    case MSG_PRINT_FUNC_RESTORE_COLOR:
                        msg_drawState->textColor = msg_drawState->savedColor;
                        msg_drawState->drawBufferPos++;
                        break;
                    case MSG_PRINT_FUNC_START_FX:
                        switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]) {
                            case MSG_FX_SHAKE:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_SHAKE;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_WAVE:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_WAVE;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_NOISE_OUTLINE:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_NOISE_OUTLINE;
                                gDPSetCombineMode(gMainGfxPos++, PM_CC_MSG_NOISE_OUTLINE, PM_CC_MSG_NOISE_OUTLINE);
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_STATIC:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_STATIC;
                                gDPSetEnvColor(gMainGfxPos++,
                                               msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                               msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                               msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                               0);
                                gDPSetCombineMode(gMainGfxPos++, PM_CC_MSG_STATIC, PM_CC_MSG_STATIC);
                                msg_drawState->drawBufferPos += 3;
                                break;
                            case MSG_FX_BLUR:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_BLUR;
                                spB8 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                                msg_drawState->drawBufferPos += 3;
                                break;
                            case MSG_FX_RAINBOW:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_RAINBOW;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_DITHER_FADE:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_DITHER_FADE;
                                spB6 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                                msg_drawState->drawBufferPos += 3;
                                break;
                            case MSG_FX_GLOBAL_WAVE:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_GLOBAL_WAVE;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_GLOBAL_RAINBOW:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_GLOBAL_RAINBOW;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_RISE_PRINT:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_RISE_PRINT;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_GROW_PRINT:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_GROW_PRINT;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_SIZE_JITTER:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_SIZE_JITTER;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_SIZE_WAVE:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_SIZE_WAVE;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_DROP_SHADOW:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_DROP_SHADOW;
                                msg_drawState->drawBufferPos += 2;
                                break;
                        }
                        break;
                    case MSG_PRINT_FUNC_END_FX:
                        switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]) {
                            case MSG_FX_SHAKE:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_SHAKE;
                                break;
                            case MSG_FX_WAVE:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_WAVE;
                                break;
                            case MSG_FX_NOISE_OUTLINE:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_NOISE_OUTLINE;
                                break;
                            case MSG_FX_STATIC:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_STATIC;
                                break;
                            case MSG_FX_BLUR:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_BLUR;
                                break;
                            case MSG_FX_RAINBOW:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_RAINBOW;
                                msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                                break;
                            case MSG_FX_DITHER_FADE:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_DITHER_FADE;
                                break;
                            case MSG_FX_GLOBAL_WAVE:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_GLOBAL_WAVE;
                                break;
                            case MSG_FX_GLOBAL_RAINBOW:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_GLOBAL_RAINBOW;
                                msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                                break;
                            case MSG_FX_RISE_PRINT:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_RISE_PRINT;
                                break;
                            case MSG_FX_GROW_PRINT:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_GROW_PRINT;
                                break;
                            case MSG_FX_SIZE_JITTER:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_SIZE_JITTER;
                                break;
                            case MSG_FX_SIZE_WAVE:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_SIZE_WAVE;
                                break;
                            case MSG_FX_DROP_SHADOW:
                                msg_drawState->effectFlags &= ~MSG_FX_FLAG_DROP_SHADOW;
                                break;
                        }
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_CENTER_X:
                        if (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] != 0) {
                            msg_drawState->centerPos = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                            if (msg_drawState->centerPos == 0xFF) {
                                msg_drawState->centerPos = printer->windowSize.x / 2;
                            }
                            msg_drawState->printModeFlags |= (MSG_PRINT_FLAG_40 | MSG_PRINT_FLAG_80);
                        } else {
                            msg_drawState->nextPos[0] = 0;
                            msg_drawState->printModeFlags &= ~(MSG_PRINT_FLAG_40 | MSG_PRINT_FLAG_80);
                        }
                        msg_drawState->drawBufferPos += 2;
                        break;
                }
                break;
            default:
                if (msg_drawState->printModeFlags & MSG_PRINT_FLAG_2) {
                    sp96 = 0xFF;
                    gDPPipeSync(gMainGfxPos++);
                    gSPDisplayList(gMainGfxPos++, D_8014C500);
                }
                msg_drawState->charScale.x = msg_drawState->msgScale.x;
                msg_drawState->charScale.y = msg_drawState->msgScale.y;
                if (msg_drawState->printModeFlags & MSG_PRINT_FLAG_80) {
                    msg_drawState->nextPos[0] += msg_drawState->centerPos - printer->msgWidth / 2;
                    msg_drawState->printModeFlags &= ~MSG_PRINT_FLAG_80;
                }
                if (msg_drawState->printModeFlags & MSG_PRINT_FLAG_40) {
                    charPosX = msg_drawState->nextPos[0] + (printer->windowBasePos.x + posX);
                } else {
                    charPosX = msg_drawState->nextPos[0] + (msg_drawState->textStartPos[0] + (printer->windowBasePos.x +
                               posX));
                }

                baseOffsetY = msg_drawState->nextPos[1] + (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY));
                msgCharset = MsgCharsets[msg_drawState->font];
                rasterOffsetY = msgCharset->rasters[msg_drawState->fontVariant].baseHeightOffset;
                charPosY = rasterOffsetY + (baseOffsetY - additionalOffsetY);

                if ((sp8E != 0) &&
                    (charPosX < msg_drawState->clipX[1]) &&
                    (charPosY < msg_drawState->clipY[1]) &&
                    (msg_drawState->clipX[0] < charPosX + (s32)(msg_drawState->msgScale.x *
                            msgCharset->rasters[msg_drawState->fontVariant].monospaceWidth)) &&
                    (msg_drawState->clipY[0] < charPosY + (s32)(msg_drawState->msgScale.y * msgCharset->newLineY
#if !VERSION_JP
                            + MsgStyleVerticalLineOffsets[printer->style]
#endif
                            ))) {
                    palette = msg_drawState->textColor;
                    phi_s2_5 = sp8E;
                    if (msg_drawState->effectFlags & MSG_FX_FLAG_BLUR) {
                        phi_s2_5 = (f32) phi_s2_5 * 0.35;
                    }
                    if ((printer->windowState == MSG_WINDOW_STATE_WAITING_FOR_CHOICE) && (msg_drawState->printModeFlags & MSG_PRINT_FLAG_20)) {
                        if (msg_drawState->unk_2D == printer->curOption) {
                            msg_drawState->effectFlags |= MSG_FX_FLAG_DROP_SHADOW | MSG_FX_FLAG_GLOBAL_RAINBOW | MSG_FX_FLAG_GLOBAL_WAVE;
                        } else {
                            msg_drawState->effectFlags &= ~MSG_FX_FLAG_GLOBAL_RAINBOW;
                            msg_drawState->effectFlags &= ~MSG_FX_FLAG_GLOBAL_WAVE;
                            msg_drawState->effectFlags &= ~MSG_FX_FLAG_DROP_SHADOW;
                            palette = msg_drawState->textColor;
                            msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                        }
                    }
                    if (msg_drawState->effectFlags & MSG_FX_FLAG_SHAKE) {
                        charPosX += rand_int(10000) % 2;
                        charPosY += rand_int(10000) % 2;
                    }
                    if (msg_drawState->effectFlags & MSG_FX_FLAG_WAVE) {
                        temp_f2_3 = msg_drawState->msgScale.x - 1.0;
                        temp_s0_7 = (printer->effectFrameCounter * (s32)(20.0 - (temp_f2_3 * 5.0))) - (msg_drawState->visiblePrintedCount *
                                    (s32)(45.0 - (temp_f2_3 * 15.0)));
                        charPosX += cosine(temp_s0_7) * ((msg_drawState->msgScale.x - 1.0) + 1.6);
                        charPosY += cosine((temp_s0_7 + 180.0 + 90.0)) * (msg_drawState->msgScale.y - 1.0 + 1.6);
                    }
                    if (msg_drawState->effectFlags & MSG_FX_FLAG_GLOBAL_WAVE) {
                        temp_s0_8 = (gMsgGlobalWaveCounter * (s32)(20.0 - ((msg_drawState->msgScale.x - 1.0) * 5.0))) -
                                    (msg_drawState->visiblePrintedCount * 45);
                        charPosX += cosine(temp_s0_8) * ((msg_drawState->msgScale.x - 1.0) + 1.6);
                        charPosY += cosine((temp_s0_8 + 180.0 + 90.0)) * ((msg_drawState->msgScale.y - 1.0) + 1.6);
                    }
                    if (msg_drawState->effectFlags & MSG_FX_FLAG_RAINBOW) {
                        palette = abs(msg_drawState->visiblePrintedCount - (u16)(printer->effectFrameCounter / 3)) % 10;
                    }
                    if (msg_drawState->effectFlags & MSG_FX_FLAG_GLOBAL_RAINBOW) {
                        palette = abs(msg_drawState->visiblePrintedCount - (u16)(gGameStatusPtr->frameCounter / 3)) % 10;
                    }
                    if (msg_drawState->effectFlags & MSG_FX_FLAG_DITHER_FADE) {
                        gDPSetAlphaDither(gMainGfxPos++, G_AD_NOISE);
                        gDPSetAlphaCompare(gMainGfxPos++, G_AC_DITHER);
                        phi_s2_5 = spB6 * (phi_s2_5 / 255.0);
                    }
                    if ((msg_drawState->printModeFlags & MSG_PRINT_FLAG_2) || (phi_s2_5 != sp96)) {
                        if ((sp96 < 0xFF) && (phi_s2_5 < 0xFF)) {
                            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, phi_s2_5);
                        } else if ((sp96 == 0xFF) && (phi_s2_5 < 0xFF)) {
                            gDPPipeSync(gMainGfxPos++);
                            if (printer->stateFlags & MSG_STATE_FLAG_4000) {
                                gDPSetRenderMode(gMainGfxPos++, IM_RD | CVG_DST_CLAMP | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN,
                                                 G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_CLAMP | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM,
                                                         G_BL_1MA));

                            } else {
                                gDPSetRenderMode(gMainGfxPos++, IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN,
                                                 G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM,
                                                         G_BL_1MA));

                            }
                            gDPSetCombineMode(gMainGfxPos++, PM_CC_02, PM_CC_02);
                            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, phi_s2_5);
                        } else if ((sp96 < 0xFF) && (phi_s2_5 == 0xFF)) {
                            gDPPipeSync(gMainGfxPos++);
                            gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                            gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                        }
                        sp96 = phi_s2_5;
                    }
                    if (phi_s2_5 > 0) {
                        if (msg_drawState->effectFlags & MSG_FX_FLAG_RISE_PRINT) {
                            if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] != MSG_CHAR_PRINT_ENDL) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] != MSG_CHAR_PRINT_ENDL) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] != MSG_CHAR_PRINT_ENDL) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 4] != MSG_CHAR_PRINT_ENDL)) {
                                if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] == MSG_CHAR_PRINT_END) &&
                                    (printer->windowState == MSG_WINDOW_STATE_PRINTING)) {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 1.7;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 1.7;
                                    temp_f8 = (msg_drawState->charScale.y / 1.7) * 6.0;
                                    charPosX -= temp_f8;
                                    charPosY -= temp_f8;
                                } else if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] == MSG_CHAR_PRINT_END) &&
                                           (printer->windowState == MSG_WINDOW_STATE_PRINTING)) {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 1.4;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 1.4;
                                    temp_f8 = (msg_drawState->charScale.y / 1.4) * 3.0;
                                    charPosX -= temp_f8;
                                    charPosY -= temp_f8;
                                } else if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] == MSG_CHAR_PRINT_END) &&
                                           (printer->windowState == MSG_WINDOW_STATE_PRINTING)) {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 1.2;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 1.2;
                                    temp_f8 = (msg_drawState->charScale.y / 1.2) * 2.0;
                                    charPosX -= temp_f8;
                                    charPosY -= temp_f8;
                                }
                            }
                        } else if (msg_drawState->effectFlags & MSG_FX_FLAG_GROW_PRINT) {
                            if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] != MSG_CHAR_PRINT_ENDL) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] != MSG_CHAR_PRINT_ENDL) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] != MSG_CHAR_PRINT_ENDL) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 4] != MSG_CHAR_PRINT_ENDL)) {
                                if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] == MSG_CHAR_PRINT_END) &&
                                    (printer->windowState == MSG_WINDOW_STATE_PRINTING)) {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 0.3;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 0.3;
                                    charPosX += 5;
                                    charPosY += 5;
                                } else if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] == MSG_CHAR_PRINT_END) &&
                                           (printer->windowState == MSG_WINDOW_STATE_PRINTING)) {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 0.5;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 0.5;
                                    charPosX += 3;
                                    charPosY += 3;
                                } else if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] == MSG_CHAR_PRINT_END) &&
                                           (printer->windowState == MSG_WINDOW_STATE_PRINTING)) {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 0.75;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 0.75;
                                    charPosX += 2;
                                    charPosY += 2;
                                }
                            }
                        } else if (msg_drawState->effectFlags & MSG_FX_FLAG_SIZE_JITTER) {
                            temp_f8_5 = rand_int(10000) % 101;
                            temp_f8_5 /= 100.0;
                            temp_f8_5 = ((temp_f8_5 * 0.5) + 1.0) - 0.25;

                            if (temp_f8_5 > 1.0) {
                                msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_5;
                                msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_5;
                                charPosX -= (temp_f8_5 * 8.0) - 8.5;
                                charPosY -= (temp_f8_5 * 8.0) - 8.5;
                            } else if (temp_f8_5 < 1.0) {
                                msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_5;
                                msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_5;
                                charPosX += 8.0 - (temp_f8_5 * 16.0) * 0.5;
                                charPosY += 8.0 - (temp_f8_5 * 16.0) * 0.5;
                            }
                        } else if (msg_drawState->effectFlags & MSG_FX_FLAG_SIZE_WAVE) {
                            s32 mod360;

                            temp_a0_49 = printer->effectFrameCounter * 15;
                            temp_a0_49 -= msg_drawState->visiblePrintedCount * 15;
                            mod360 = temp_a0_49 % 360;
                            temp_f8_5 = (cosine(mod360) * 0.25) + 1.0;

                            if (temp_f8_5 > 1.0) {
                                msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_5;
                                msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_5;
                                charPosX -= (temp_f8_5 * 8.0) - 8.5;
                                charPosY -= (temp_f8_5 * 8.0) - 8.5;
                            } else if (temp_f8_5 < 1.0) {
                                msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_5;
                                msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_5;
                                charPosX += 8.0 - (temp_f8_5 * 16.0) * 0.5;
                                charPosY += 8.0 - (temp_f8_5 * 16.0) * 0.5;
                            }
                        }

                        if ((printer->windowState == MSG_WINDOW_STATE_B || printer->windowState == MSG_WINDOW_STATE_C) &&
                            (printer->style == MSG_STYLE_RIGHT ||
                             printer->style == MSG_STYLE_LEFT ||
                             printer->style == MSG_STYLE_CENTER ||
                             printer->style == MSG_STYLE_TATTLE))
                        {
                            switch (palette) {
                                case MSG_PAL_WHITE:
                                case MSG_PAL_RED:
                                case MSG_PAL_10:
                                case MSG_PAL_11:
                                case MSG_PAL_12:
                                case MSG_PAL_13:
                                case MSG_PAL_14:
                                    break;
                                case MSG_PAL_STANDARD:
                                    palette = MSG_PAL_40;
                                    break;
                                case MSG_PAL_20:
                                    palette = MSG_PAL_41;
                                    break;
                                case MSG_PAL_22:
                                    palette = MSG_PAL_42;
                                    break;
                                case MSG_PAL_23:
                                    palette = MSG_PAL_43;
                                    break;
                                case MSG_PAL_25:
                                    palette = MSG_PAL_44;
                                    break;
                                default:
                                    palette = MSG_PAL_40;
                                    break;
                            }
                        }
                        if (palette != sp9E) {
                            sp9E = palette;
                            msg_drawState->printModeFlags |= MSG_PRINT_FLAG_10;
                        }
                        if ((msg_drawState->effectFlags & MSG_FX_FLAG_DROP_SHADOW) && (phi_s2_5 == 0xFF)) {
                            gDPPipeSync(gMainGfxPos++);
                            gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                            gDPSetCombineMode(gMainGfxPos++, PM_CC_07, PM_CC_07);
                            gDPSetPrimColor(gMainGfxPos++, 0, 0, 40, 40, 40, 72);
                            msg_draw_char(printer, msg_drawState,
                                          msg_drawState->printBuffer[msg_drawState->drawBufferPos],
                                          palette, charPosX + 2, charPosY + 2);
                            gDPPipeSync(gMainGfxPos++);
                            gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                            gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                        }

                        if (msg_drawState->effectFlags & MSG_FX_FLAG_BLUR) {
                            for (i = 0; i < 5; i++) {
                                phi_s0_7 = charPosX;
                                phi_s1_8 = charPosY;
                                if (spB8 != 2) {
                                    phi_s0_7 += (rand_int(10000) % 3) - 1;
                                }
                                if (spB8 != 1) {
                                    phi_s1_8 += (rand_int(10000) % 3) - 1;
                                }
                                msg_draw_char(printer, msg_drawState,
                                              msg_drawState->printBuffer[msg_drawState->drawBufferPos], palette,
                                              phi_s0_7, phi_s1_8);
                            }
                        } else {
                            msg_draw_char(printer, msg_drawState,
                                          msg_drawState->printBuffer[msg_drawState->drawBufferPos], palette, charPosX,
                                          charPosY);
                        }
                    }
                }
                if (msg_drawState->printModeFlags & MSG_PRINT_FLAG_2) {
                    msg_drawState->printModeFlags &= ~MSG_PRINT_FLAG_2;
                }
                msg_drawState->visiblePrintedCount += 1;
                msg_drawState->nextPos[0] +=
                    msg_get_draw_char_width(msg_drawState->printBuffer[msg_drawState->drawBufferPos],
                                            msg_drawState->font, msg_drawState->fontVariant, msg_drawState->msgScale.x,
                                            msg_drawState->curPosX, msg_drawState->printModeFlags);
                msg_drawState->drawBufferPos++;
                break;
        }
    }

    varImgHasBorder = FALSE;
    if (printer->varImageScreenPos.x != 0) {
        s16 varImgFinalAlpha;

        varImgFinalAlpha = printer->varImgFinalAlpha;
        msgVarImage = &(*gMsgVarImages)[printer->curImageIndex];

        switch (printer->varImgHasBorder) {
            case 0:
            case 1:
                if (printer->varImgHasBorder) {
                    varImgHasBorder = TRUE;
                }
                switch (printer->varImageDisplayState) {
                    case 0:
                        printer->varImageFadeTimer++;
                        varImgFinalAlpha = printer->varImageFadeTimer * printer->varImgAlphaFadeStep;
                        if (printer->varImgFinalAlpha <= varImgFinalAlpha) {
                            varImgFinalAlpha = printer->varImgFinalAlpha;
                            printer->varImageFadeTimer = 0;
                            printer->varImageDisplayState = 1;
                        }
                        break;
                    case 1:
                        varImgFinalAlpha = (u8)(((f32) spAE / 255.0) * (f32) printer->varImgFinalAlpha);
                        break;
                    case 2:
                        printer->varImageFadeTimer++;
                        varImgFinalAlpha = printer->varImgFinalAlpha - printer->varImgAlphaFadeStep * printer->varImageFadeTimer;
                        if (varImgFinalAlpha < 1) {
                            printer->varImageScreenPos.x = 0;
                        }
                        break;
                }
                break;
            case 2:
                varImgFinalAlpha = (u8)(((f32) spAE / 255.0) * (f32) printer->varImgFinalAlpha);
                break;
        }

        if (varImgFinalAlpha > 0) {
            if (varImgHasBorder) {
                draw_box(0, WINDOW_STYLE_15, printer->varImageScreenPos.x - 7, printer->varImageScreenPos.y - 7, 0,
                         msgVarImage->width + 15, msgVarImage->height + 14, varImgFinalAlpha, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                         0.0f, NULL, 0, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
            }
            draw_ci_image_with_clipping(msgVarImage->raster, msgVarImage->width, msgVarImage->height,
                                        msgVarImage->format, msgVarImage->bitDepth, msgVarImage->palette,
                                        printer->varImageScreenPos.x, printer->varImageScreenPos.y, 0, 0,
                                        SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, varImgFinalAlpha);
        }

    }
    gDPPipeSync(gMainGfxPos++);
    D_80151338 = gMainGfxPos;
}
#endif

void msg_reset_gfx_state(void) {
    gDPPipeSync(gMainGfxPos++);
    gSPDisplayList(gMainGfxPos++, D_8014C500);
}

void msg_draw_char(MessagePrintState* printer, MessageDrawState* drawState, s32 charIndex, s32 palette, s32 posX, s32 posY) {
    MessageCharset* messageCharset;
    s32 fontVariant;

    s32 clipUly;
    s32 clipLry;
    s32 clipUlx;
    s32 clipLrx;

    s32 rightPosX;
    s32 rightPosY;

    f32 clipOffset;
    s32 ulx, texOffsetX;
    s32 uly, texOffsetY;
    s32 lrx, lry;
    s32 dsdx, dtdy;
    s32 posX2, posY2;

#if VERSION_IQUE
    if (charIndex == MSG_CHAR_ZH_RANK) {
        load_font_data(((u8 (*)[128])charset_standard_OFFSET)[charIndex], sizeof(D_801544A0[0]), D_801544A0[0]);
    } else if (charIndex == MSG_CHAR_ZH_CHAPTER) {
        load_font_data(((u8 (*)[128])charset_standard_OFFSET)[charIndex], sizeof(D_801544A0[0]), D_801544A0[1]);
    } else if (charIndex >= MSG_CHAR_ZH_START) {
        load_font_data(((u8 (*)[128])charset_standard_OFFSET)[charIndex], sizeof(D_801544A0[0]), D_801544A0[D_8014AD24]);
    }
#endif

    messageCharset = MsgCharsets[drawState->font];
    fontVariant = drawState->fontVariant;

    clipUly = drawState->clipY[0];
    clipLry = drawState->clipY[1];
    clipUlx = drawState->clipX[0];
    clipLrx = drawState->clipX[1];

    posX2 = posX;
    posY2 = posY;

    rightPosX = posX2 + (s32)(drawState->charScale.x * messageCharset->texSize.x);
    rightPosY = posY2 + (s32)(drawState->charScale.y * messageCharset->texSize.y);

    if (posX2 >= clipLrx || posY2 >= clipLry || rightPosX <= clipUlx || rightPosY <= clipUly) {
        return;
    }

    if (posX2 < clipUlx) {
        clipOffset = abs(posX2 - clipUlx) / drawState->charScale.x;
        texOffsetX = (f32)((clipOffset + 0.5) * 32.0);
        ulx = clipUlx;
    } else {
        texOffsetX = 0;
        ulx = posX2;
    }

    if (posY2 < clipUly) {
        if (!(printer->stateFlags & MSG_STATE_FLAG_400) || posY2 < 0) {
            clipOffset = abs(posY2 - clipUly) / drawState->charScale.y;
            texOffsetY = clipOffset * 32.0f;
            uly = clipUly;
        } else {
            texOffsetY = 0;
            uly = posY2;
        }
    } else {
        texOffsetY = 0;
        uly = posY2;
    }

    lrx = rightPosX;
    if (lrx >= clipLrx) {
        lrx = clipLrx;
    }

    lry = rightPosY;
    if (lry >= clipLry) {
        lry = clipLry;
    }

    dsdx = 1.0f / drawState->charScale.x * 1024.0f;
    dtdy = 1.0f / drawState->charScale.y * 1024.0f;

    if (drawState->printModeFlags & (MSG_PRINT_FLAG_10 | MSG_PRINT_FLAG_1)) {
        drawState->printModeFlags &= ~(MSG_PRINT_FLAG_10 | MSG_PRINT_FLAG_1);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, D_802F4560[palette]);
    }

    if (messageCharset->texSize.x >= 16 && messageCharset->texSize.x % 16 == 0) {
#if VERSION_IQUE
        if (charIndex == MSG_CHAR_ZH_RANK || charIndex == MSG_CHAR_ZH_CHAPTER) {
            gDPLoadTextureBlock_4b(gMainGfxPos++, D_801544A0[charIndex - MSG_CHAR_ZH_RANK], G_IM_FMT_CI,
                                   messageCharset->texSize.x, messageCharset->texSize.y, 0,
                                   G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (charIndex >= MSG_CHAR_ZH_START) {
            gDPLoadTextureBlock_4b(gMainGfxPos++, D_801544A0[D_8014AD24], G_IM_FMT_CI,
                                   messageCharset->texSize.x, messageCharset->texSize.y, 0,
                                   G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else {
#endif
            gDPLoadTextureBlock_4b(gMainGfxPos++, messageCharset->rasters[fontVariant].raster + messageCharset->charRasterSize * charIndex, G_IM_FMT_CI,
                                   messageCharset->texSize.x, messageCharset->texSize.y, 0,
                                   G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
#if VERSION_IQUE
        }
#endif
    } else {
#if VERSION_IQUE
        if (charIndex == MSG_CHAR_ZH_RANK || charIndex == MSG_CHAR_ZH_CHAPTER) {
            gDPLoadTextureTile_4b(gMainGfxPos++,  D_801544A0[charIndex - MSG_CHAR_ZH_RANK], G_IM_FMT_CI,
                                  messageCharset->texSize.x, messageCharset->texSize.y,
                                  0, 0, messageCharset->texSize.x - 1, messageCharset->texSize.y - 1, 0,
                                  G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (charIndex >= MSG_CHAR_ZH_START) {
            gDPLoadTextureTile_4b(gMainGfxPos++,  D_801544A0[D_8014AD24], G_IM_FMT_CI,
                                  messageCharset->texSize.x, messageCharset->texSize.y,
                                  0, 0, messageCharset->texSize.x - 1, messageCharset->texSize.y - 1, 0,
                                  G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else {
#endif
            gDPLoadTextureTile_4b(gMainGfxPos++, messageCharset->rasters[fontVariant].raster + messageCharset->charRasterSize * charIndex, G_IM_FMT_CI,
                                  messageCharset->texSize.x, messageCharset->texSize.y,
                                  0, 0, messageCharset->texSize.x - 1, messageCharset->texSize.y - 1, 0,
                                  G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
#if VERSION_IQUE
        }
#endif
    }
    gSPTextureRectangle(gMainGfxPos++, ulx * 4, uly * 4, lrx * 4, lry * 4, G_TX_RENDERTILE, texOffsetX, texOffsetY,
                        dsdx, dtdy);

#if VERSION_IQUE
    if (charIndex >= MSG_CHAR_ZH_START) {
        D_8014AD24 = (D_8014AD24 + 1) % 120;
        if (D_8014AD24 == 0) {
            D_8014AD24 = 2;
        }
    }
#endif
}

void msg_draw_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 posX, u16 posY, u16 sizeX, u16 sizeY) {
    u16 lrX = posX + sizeX;
    u16 lrY = posY + sizeY;

    appendGfx_msg_prim_rect(r, g, b, a, posX, posY, lrX, lrY);
}

void appendGfx_msg_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 ulX, u16 ulY, u16 lrX, u16 lrY) {
    gDPPipeSync(gMainGfxPos++);

    if (a == 255) {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_PRIM_FULL_ALPHA, PM_CC_PRIM_FULL_ALPHA);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, r, g, b, a);
    gDPFillRectangle(gMainGfxPos++, ulX, ulY, lrX, lrY);
    gDPPipeSync(gMainGfxPos++);
    gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

    switch (msg_drawState->unk_29) {
        case 0:
            gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            break;
        case 1:
            gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
            break;
        default:
            gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            break;
    }
}

void msg_draw_speech_bubble(
    MessagePrintState* printer,
    s16 posX, s16 posY, s16 straightWidth, s16 curveWidth, s16 height, f32 scaleX, f32 scaleY, u8 opacity, s32 arg9)
{
    Matrix4f sp20, sp60;
    s16 temp_v0;
    s16 temp_v0_2;
    s32 negHeight;

    if (opacity == 255 && scaleX == 1.0 && scaleY == 1.0) {
        msg_draw_prim_rect(32, 128, 240, 0, posX - 1, posY + 1, curveWidth + (straightWidth + curveWidth) + 2, height - 2);
    }

    negHeight = -height;

    gMsgSpeechBoxLQuad[0].v.ob[0] = 1;
    gMsgSpeechBoxLQuad[2].v.ob[0] = 1;
    gMsgSpeechBoxLQuad[1].v.ob[0] = curveWidth;
    gMsgSpeechBoxLQuad[3].v.ob[0] = curveWidth;
    gMsgSpeechBoxLQuad[2].v.ob[1] = negHeight;
    gMsgSpeechBoxLQuad[3].v.ob[1] = negHeight;

    temp_v0 = curveWidth + straightWidth;

    gMsgSpeechBoxMQuad[0].v.ob[0] = curveWidth;
    gMsgSpeechBoxMQuad[2].v.ob[0] = curveWidth;
    gMsgSpeechBoxMQuad[1].v.ob[0] = temp_v0;
    gMsgSpeechBoxMQuad[3].v.ob[0] = temp_v0;
    gMsgSpeechBoxMQuad[2].v.ob[1] = negHeight;
    gMsgSpeechBoxMQuad[3].v.ob[1] = negHeight;

    temp_v0_2 = curveWidth + temp_v0;

    gMsgSpeechBoxRQuad[0].v.ob[0] = temp_v0;
    gMsgSpeechBoxRQuad[2].v.ob[0] = temp_v0;
    gMsgSpeechBoxRQuad[1].v.ob[0] = temp_v0_2;
    gMsgSpeechBoxRQuad[3].v.ob[0] = temp_v0_2;
    gMsgSpeechBoxRQuad[2].v.ob[1] = negHeight;
    gMsgSpeechBoxRQuad[3].v.ob[1] = negHeight;

    guTranslateF(sp20, posX, -posY, 0.0f);

    if (scaleX != 1.0 || scaleY != 1.0) {
        guScaleF(sp60, scaleX, scaleY, 1.0f);
        guMtxCatF(sp60, sp20, sp20);
    }

    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);

    if (printer->maxLinesPerPage == 3) {
        gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    } else {
        gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
    }

    if (opacity >= 255) {
        gDPSetRenderMode(gMainGfxPos++, AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                         GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM),
                         AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                         GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
        gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else {
        gDPSetRenderMode(gMainGfxPos++, IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL |
                         GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA),
                         IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL |
                         GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
        gDPSetCombineMode(gMainGfxPos++, PM_CC_02, PM_CC_02);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 32, 32, 32, opacity);
    }

    gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
    gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1,
                       ui_msg_palettes[msg_drawState->framePalette]);
    gDPTileSync(gMainGfxPos++);
    gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMainGfxPos++);
    gDPLoadTLUTCmd(gMainGfxPos++, G_TX_LOADTILE, 15);
    gDPPipeSync(gMainGfxPos++);
    gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_bubble_left_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 63, 0,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gMainGfxPos++, gMsgSpeechBoxLQuad, 4, 0);
    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
    gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_bubble_mid_png, G_IM_FMT_CI, 8, 0, 0, 0, 7, 63, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 3, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gMainGfxPos++, gMsgSpeechBoxMQuad, 4, 0);
    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
    gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_bubble_right_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 63, 0,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gMainGfxPos++, gMsgSpeechBoxRQuad, 4, 0);
    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
    gDPPipeSync(gMainGfxPos++);
}

void msg_draw_speech_arrow(MessagePrintState* printer) {
    s16 targetX, targetY;
    f32 windowXpart;
    s32 arrowLength;
    Vtx* quad;
    s32 angle;
    f32 cosAngle, sinAngle;
    Matrix4f sp10;
    s16 x1, x2, x3, x4;
    s32 y1, y2;
    u8 pointRightSide = FALSE;
    s16 windowX = printer->windowOffsetPos.x + printer->windowBasePos.x;
    s16 windowY = printer->windowOffsetPos.y + printer->windowBasePos.y;

    if (printer->openStartPos.x == 0) {
        return;
    }

    if (printer->style == MSG_STYLE_RIGHT ||
        printer->style == MSG_STYLE_LEFT ||
        printer->style == MSG_STYLE_CENTER ||
        printer->maxLinesPerPage == 3) {
        targetY = windowY + printer->windowSize.y - 4;
    } else {
        targetY = windowY + printer->windowSize.y - 3;
    }

    if (printer->style == MSG_STYLE_LEFT) {
        pointRightSide = FALSE;
    } else if (printer->style == MSG_STYLE_CENTER || printer->openStartPos.x >= 160) {
        pointRightSide = TRUE;
    }

    if (pointRightSide) {
        targetX = windowX + (f32)printer->windowSize.x * 0.7;
        if (printer->openStartPos.x < targetX) {
            for (windowXpart = 0.7f; windowXpart >= 0.67; windowXpart -= 0.005) {
                targetX = windowX + printer->windowSize.x * windowXpart;
                angle = atan2(printer->openStartPos.x, printer->openStartPos.y, targetX, targetY);
                if (abs(angle) < 45) {
                    break;
                }
            }
        }
    } else {
        targetX = windowX + (f32)printer->windowSize.x * 0.3;
        if (printer->openStartPos.x > targetX) {
            for (windowXpart = 0.3f; windowXpart <= 0.38; windowXpart += 0.005) {
                targetX = windowX + printer->windowSize.x * windowXpart;
                angle = atan2(printer->openStartPos.x, printer->openStartPos.y, targetX, targetY);
                if (abs(angle) < 45) {
                    break;
                }
            }
        }
    }

    x1 = targetX - 9;
    x2 = targetX + 9;
    x3 = targetX;

    arrowLength = dist2D(printer->initOpenPos.x, printer->initOpenPos.y, targetX, targetY);
    if (arrowLength < 10) {
        return;
    }

    if (arrowLength > 25) {
        arrowLength = 25;
    }

    // alternate quads between frames
    if (gCurrentDisplayContextIndex != 0) {
        quad = gMsgArrowQuad1;
    } else {
        quad = gMsgArrowQuad2;
    }

    angle = atan2(targetX, targetY, printer->initOpenPos.x, printer->initOpenPos.y);
    angle -= 180;
    if (abs(angle) >= 75) {
        return;
    }

    cosAngle = cosine(angle);
    sinAngle = cosine(angle + 90);

    x3 = x3 - arrowLength * cosAngle;
    x4 = x3 + 1;

    y1 = -targetY;
    y2 = -(s16)(targetY + arrowLength * sinAngle);

    quad[0].v.ob[0] = x1;
    quad[0].v.ob[1] = y1;
    quad[1].v.ob[0] = x2;
    quad[1].v.ob[1] = y1;

    quad[2].v.ob[0] = x3;
    quad[2].v.ob[1] = y2;
    quad[3].v.ob[0] = x4;
    quad[3].v.ob[1] = y2;

    gDPPipeSync(gMainGfxPos++);
    gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_0F, PM_CC_0F);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 32, 32, 32, 255);
    gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_arrow_png, G_IM_FMT_CI, 16, 0, 0, 0, 15, 15, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    guTranslateF(sp10, 0.0f, 0.0f, 0.0f);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gMainGfxPos++, quad, 4, 0);
    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
}

void msg_draw_frame(s32 posX, s32 posY, s32 sizeX, s32 sizeY, s32 style, s32 palette, s32 fading, s32 bgAlpha, s32 frameAlpha) {
    s32 i;
    s32 frameType;
    s32 textures[16];
    u8 r, g, b;
    Rect quads[16];

    if (sizeX < 16 || sizeY < 16) {
        return;
    }

    if (fading != 0 && bgAlpha == 0 && frameAlpha == 0) {
        return;
    }

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
    gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_DISABLE);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);

    if (fading == 0 || bgAlpha != 0) {
        do {} while (0);
        switch (style) {
            case MSG_STYLE_CHOICE:
                r = UNPACK_PAL_R(((u16*)ui_msg_palettes)[4]) * 8;
                g = UNPACK_PAL_G(((u16*)ui_msg_palettes)[4]) * 8;
                b = UNPACK_PAL_B(((u16*)ui_msg_palettes)[4]) * 8;
                gDPPipeSync(gMainGfxPos++);
                if (fading != 0 && bgAlpha < 255) {
                    gDPSetRenderMode(gMainGfxPos++, IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
                } else {
                    gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
                }
                gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, r, g, b, bgAlpha);
                if (posX + sizeX - 8 > 0) {
                    gDPScisFillRectangle(gMainGfxPos++, posX + 8, posY + 8, posX + sizeX - 8, posY + sizeY - 8);
                }
                break;
            case MSG_STYLE_INSPECT:
                gDPPipeSync(gMainGfxPos++);
                gDPSetTextureFilter(gMainGfxPos++, G_TF_AVERAGE);
                gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                gDPSetCombineMode(gMainGfxPos++, PM_CC_10, PM_CC_10);
                if (fading == 0 || bgAlpha == 255) {
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, 216);
                } else {
                    if (bgAlpha > 216) {
                        bgAlpha = 216;
                    }
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, bgAlpha);
                }

                gDPLoadTextureBlock_4b(gMainGfxPos++, ui_msg_background_png, G_IM_FMT_I, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
                if (style == MSG_STYLE_INSPECT) {
                    gSPScisTextureRectangle(gMainGfxPos++, (posX + 3) * 4, (posY + 3) * 4, (posX + sizeX - 3) * 4, (posY + sizeY - 3) * 4,
                                            G_TX_RENDERTILE, gMsgBGScrollAmtX, gMsgBGScrollAmtY, 0x400, 0x400);
                } else {
                    gSPScisTextureRectangle(gMainGfxPos++, (posX + 5) * 4, (posY + 5) * 4, (posX + sizeX - 5) * 4, (posY + sizeY - 5) * 4,
                                            G_TX_RENDERTILE, gMsgBGScrollAmtX, gMsgBGScrollAmtY, 0x400, 0x400);
                }
                break;
        }
    }

    if (sizeX >= 32) {
        quads[2].ulx = (posX + 16) * 4;
        quads[2].uly = posY * 4;
        quads[2].lrx = (posX + sizeX - 16) * 4;
        quads[2].lry = (posY + 8) * 4;

        quads[13].ulx = (posX + 16) * 4;
        quads[13].uly = (posY + sizeY - 8) * 4;
        quads[13].lrx = (posX + sizeX - 16) * 4;
        quads[13].lry = (posY + sizeY) * 4;
    } else if (sizeX > 16 && sizeX < 24) {
        quads[2].ulx = (posX + 8) * 4;
        quads[2].uly = posY * 4;
        quads[2].lrx = (posX + sizeX - 8) * 4;
        quads[2].lry = (posY + 8) * 4;

        quads[13].ulx = (posX + 8) * 4;
        quads[13].uly = (posY + sizeY - 8) * 4;
        quads[13].lrx = (posX + sizeX - 8) * 4;
        quads[13].lry = (posY + sizeY) * 4;
    } else {
        quads[2].ulx = 10000;
        quads[13].ulx = 10000;
    }

    if (sizeY >= 32) {
        quads[7].ulx = posX * 4;
        quads[7].uly = (posY + 16) * 4;
        quads[7].lrx = (posX + 8) * 4;
        quads[7].lry = (posY + sizeY - 16) * 4;

        quads[8].ulx = (posX + sizeX - 8) * 4;
        quads[8].uly = (posY + 16) * 4;
        quads[8].lrx = (posX + sizeX) * 4;
        quads[8].lry = (posY + sizeY - 16) * 4;
    } else if (sizeY > 16 && sizeY < 24) {
        quads[7].ulx = posX * 4;
        quads[7].uly = (posY + 8) * 4;
        quads[7].lrx = (posX + 8) * 4;
        quads[7].lry = (posY + sizeY - 8) * 4;

        quads[8].ulx = (posX + sizeX - 8) * 4;
        quads[8].uly = (posY + 8) * 4;
        quads[8].lrx = (posX + sizeX) * 4;
        quads[8].lry = (posY + sizeY - 8) * 4;
    } else {
        quads[7].ulx = 10000;
        quads[8].ulx = 10000;
    }

    if (sizeX >= 24) {
        quads[1].ulx = (posX + 8) * 4;
        quads[1].uly = posY * 4;
        quads[1].lrx = (posX + 16) * 4;
        quads[1].lry = (posY + 8) * 4;

        quads[3].ulx = (posX + sizeX - 16) * 4;
        quads[3].uly = posY * 4;
        quads[3].lrx = (posX + sizeX - 8) * 4;
        quads[3].lry = (posY + 8) * 4;

        quads[12].ulx = (posX + 8) * 4;
        quads[12].uly = (posY + sizeY - 8) * 4;
        quads[12].lrx = (posX + 16) * 4;
        quads[12].lry = (posY + sizeY) * 4;

        quads[14].ulx = (posX + sizeX - 16) * 4;
        quads[14].uly = (posY + sizeY - 8) * 4;
        quads[14].lrx = (posX + sizeX - 8) * 4;
        quads[14].lry = (posY + sizeY) * 4;
    } else {
        quads[1].ulx = 10000;
        quads[3].ulx = 10000;
        quads[12].ulx = 10000;
        quads[14].ulx = 10000;
    }

    if (sizeY >= 24) {
        quads[5].ulx = posX * 4;
        quads[5].uly = (posY + 8) * 4;
        quads[5].lrx = (posX + 8) * 4;
        quads[5].lry = (posY + 16) * 4;

        quads[6].ulx = (posX + sizeX - 8) * 4;
        quads[6].uly = (posY + 8) * 4;
        quads[6].lrx = (posX + sizeX) * 4;
        quads[6].lry = (posY + 16) * 4;

        quads[9].ulx = posX * 4;
        quads[9].uly = (posY + sizeY - 16) * 4;
        quads[9].lrx = (posX + 8) * 4;
        quads[9].lry = (posY + sizeY - 8) * 4;

        quads[10].ulx = (posX + sizeX - 8) * 4;
        quads[10].uly = (posY + sizeY - 16) * 4;
        quads[10].lrx = (posX + sizeX) * 4;
        quads[10].lry = (posY + sizeY - 8) * 4;
    } else {
        quads[5].ulx = 10000;
        quads[6].ulx = 10000;
        quads[9].ulx = 10000;
        quads[10].ulx = 10000;
    }

    quads[0].ulx = posX * 4;
    quads[0].uly = posY * 4;
    quads[0].lrx = (posX + 8) * 4;
    quads[0].lry = (posY + 8) * 4;

    quads[4].ulx = (posX + sizeX - 8) * 4;
    quads[4].uly = posY * 4;
    quads[4].lrx = (posX + sizeX) * 4;
    quads[4].lry = (posY + 8) * 4;

    quads[11].ulx = posX * 4;
    quads[11].uly = (posY + sizeY - 8) * 4;
    quads[11].lrx = (posX + 8) * 4;
    quads[11].lry = (posY + sizeY) * 4;

    quads[15].ulx = (posX + sizeX - 8) * 4;
    quads[15].uly = (posY + sizeY - 8) * 4;
    quads[15].lrx = (posX + sizeX) * 4;
    quads[15].lry = (posY + sizeY) * 4;

    switch (style) {
        case MSG_STYLE_CHOICE:
            frameType = 0;
            break;
        case MSG_STYLE_INSPECT:
            frameType = 1;
            break;
        default:
            frameType = 0;
            break;
    }

    for (i = 0; i < ARRAY_COUNT(textures); i++) {
        textures[i] = gMessageBoxFrameParts[frameType][i];
    }

    if (fading == 0) {
        frameAlpha = 255;
    }

    gDPPipeSync(gMainGfxPos++);
    gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_02, PM_CC_02);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, frameAlpha);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gMainGfxPos++, 0, ui_msg_palettes[palette]);

    for (i = 0; i < ARRAY_COUNT(textures); i++) {
        if (textures[i] != NULL && quads[i].ulx < 10000) {
            gDPLoadTextureTile_4b(gMainGfxPos++, textures[i], G_IM_FMT_CI, 8, 8, 0, 0, 7, 7, 0, G_TX_WRAP, G_TX_WRAP, 3, 3, G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(gMainGfxPos++, quads[i].ulx, quads[i].uly, quads[i].lrx, quads[i].lry,
                                    G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
        }
    }

    gDPPipeSync(gMainGfxPos++);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
}

void msg_get_glyph(s32 font, s32 variation, s32 charIndex, s32 palette, MesasgeFontGlyphData* out) {
    out->raster = &MsgCharsets[font]->rasters[variation].raster[(u16)MsgCharsets[font]->charRasterSize * charIndex];
    out->palette = D_802F4560[palette];
    out->texSize.x = MsgCharsets[font]->texSize.x;
    out->texSize.y = MsgCharsets[font]->texSize.y;
    out->charWidth = msg_get_draw_char_width(charIndex, font, variation, 1.0f, 0, 0);
    out->charHeight = out->texSize.y;
}
