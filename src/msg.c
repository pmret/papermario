#include "common.h"
#include "ld_addrs.h"
#include "message_ids.h"
#include "sprite.h"

#if !VERSION_IQUE
// TODO: remove if assets are dumped in iQue release
#include "charset/postcard.png.h"
#include "charset/letter_content_1.png.h"
#endif

#if VERSION_IQUE
// TODO: remove if section is split in iQue release
extern Addr charset_ROM_START;
extern Addr charset_standard_OFFSET;
extern Addr charset_standard_pal_OFFSET;
extern Addr charset_title_OFFSET;
extern Addr charset_credits_pal_OFFSET;
extern Addr charset_subtitle_OFFSET;
#endif

enum RewindArrowStates {
    REWIND_ARROW_STATE_INIT = 0,
    REWIND_ARROW_STATE_GROW = 1,
    REWIND_ARROW_STATE_NEUTRAL = 2,
    REWIND_ARROW_STATE_CHANGE_COLOR = 3,
    REWIND_ARROW_STATE_CHANGE_COLOR_BACK = 4,
};

#ifdef SHIFT
#define MSG_ROM_START (s32)msg_ROM_START
#else
#define MSG_ROM_START 0x1B83000
#endif

typedef MessageImageData* MessageImageDataList[1];

s32 D_8014C280[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000 };

u8 MessagePlural[] = { MSG_CHAR_LOWER_S, MSG_CHAR_READ_END };

u8 MessageSingular[] = { MSG_CHAR_READ_ENDL, MSG_CHAR_READ_END };

s16 gNextMessageBuffer = 0;

//TODO Vtx
s32 gRewindArrowQuad[] = {
    0xFFF00009, 0x00000000, 0x00000000, 0xFFFFFFFF,
    0x00100009, 0x00000000, 0x04000000, 0xFFFFFFFF,
    0xFFF0FFF7, 0x00000000, 0x00000240, 0xFFFFFFFF,
    0x0010FFF7, 0x00000000, 0x04000240, 0xFFFFFFFF,
};

Gfx D_8014C2D8[] = {
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetRenderMode(IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | G_RM_PASS, IM_RD | CVG_DST_SAVE | ZMODE_XLU |
                      FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
    gsDPSetCombineMode(PM_CC_13, G_CC_PASS2),
    gsSPEndDisplayList(),
};

SHIFT_BSS s32 gMsgBGScrollAmtX;
SHIFT_BSS u16 gMsgGlobalWaveCounter;
SHIFT_BSS MessageImageDataList gMsgVarImages;
SHIFT_BSS s32 gMsgBGScrollAmtY;
SHIFT_BSS u8* D_8015131C;
SHIFT_BSS Gfx* D_80151338;
SHIFT_BSS char gMessageBuffers[2][1024];
SHIFT_BSS u8 gMessageMsgVars[3][32];
SHIFT_BSS s16 D_80155C98;
SHIFT_BSS Mtx gMessageWindowProjMatrix[2];
SHIFT_BSS MessageDrawState D_80155D20;
SHIFT_BSS MessageDrawState* msg_drawState;
SHIFT_BSS IMG_BIN D_80159B50[0x200];
SHIFT_BSS PAL_BIN D_8015C7E0[0x10];
SHIFT_BSS MessagePrintState gMessagePrinters[3];

extern s16 MsgStyleVerticalLineOffsets[];

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

extern IMG_BIN D_802ED550[];
extern PAL_BIN D_802ED670[];
extern IMG_BIN MsgCharImgTitle[];
extern IMG_BIN MsgCharImgNormal[];
extern MessageCharset* MsgCharsets[5];
extern IMG_BIN MsgCharImgSubtitle[];
extern PAL_BIN D_802F4560[80][8];

extern s32 gMessageBoxFrameParts[2][16];

extern IMG_BIN ui_point_right_png[];
extern PAL_BIN ui_point_right_pal[];

MessageNumber gMsgNumbers[] = {
    {
        .rasters = &MsgCharImgNormal[0x800],
        .texSize = 128,
        .texWidth = 16,
        .texHeight = 16,
        .digitWidth = {11, 8, 11, 11, 11, 11, 11, 11, 11, 11},
        .fixedWidth = 11
    }, {
        .rasters = &MsgCharImgNormal[0x800],
        .texSize = 128,
        .texWidth = 16,
        .texHeight = 16,
        .digitWidth = {9, 8, 9, 9, 9, 9, 9, 9, 9, 9},
        .fixedWidth = 9
    }
};

Gfx gMsgDlistInitDrawNumber[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

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

void clear_character_set(void) {
    D_80155C98 = -1;
}

void clear_printers(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMessagePrinters); i++) {
        initialize_printer(&gMessagePrinters[i], 0, 0);
    }

    gMsgBGScrollAmtX = 0;
    gMsgBGScrollAmtY = 0;

    for (i = 0; i < ARRAY_COUNT(gMessageMsgVars); i++) {
        gMessageMsgVars[i][0] = 0;
    }

    D_80151338 = NULL;
    gMsgGlobalWaveCounter = 0;
    load_font(0);
}

#if VERSION_IQUE
void load_font_data(Addr offset, u32 size, void* dest) {
#else
void load_font_data(Addr offset, u16 size, void* dest) {
#endif
    u8* base = charset_ROM_START + (s32) offset;

    dma_copy(base, base + size, dest);
}

void load_font(s32 font) {
    if (font != D_80155C98) {
        if (font == 0) {
            load_font_data(charset_standard_OFFSET, 0x5100, MsgCharImgNormal);
            load_font_data(charset_standard_pal_OFFSET, 0x500, D_802F4560);
        } else if (font == 1) {
            load_font_data(charset_title_OFFSET, 0xF60, MsgCharImgTitle);
            load_font_data(charset_subtitle_OFFSET, 0xB88, MsgCharImgSubtitle);
            load_font_data(charset_credits_pal_OFFSET, 0x80, D_802F4560);
        }
    }
}

void update_messages(void) {
    s32 i;

    gMsgGlobalWaveCounter++;
    if (gMsgGlobalWaveCounter >= 360) {
        gMsgGlobalWaveCounter = 0;
    }

    for (i = 0; i < ARRAY_COUNT(gMessagePrinters); i++) {
        if (gMessagePrinters[i].stateFlags & MSG_STATE_FLAG_2) {
            _update_message(&gMessagePrinters[i]);
        }
    }

    gMsgBGScrollAmtX += 12;
    gMsgBGScrollAmtY -= 12;
    if (gMsgBGScrollAmtX >= 2048) {
        gMsgBGScrollAmtX -= 2048;
    }
    if (gMsgBGScrollAmtY < 0) {
        gMsgBGScrollAmtY += 2048;
    }
}

s32 _update_message(MessagePrintState* printer) {
    f32 speechPan;
    u8 cond;
    s32 buttons;
    s16 endPosDist;
    s16 lineIncAmt;
    s32 charsToPrint;
    s32 i;

    printer->effectFrameCounter++;
    if (printer->effectFrameCounter >= 3600) {
        printer->effectFrameCounter = 0;
    }

    speechPan = (((f32)printer->initOpenPos.x - (SCREEN_WIDTH / 2.0)) / 3.8) + 64.0;
    if (speechPan < 5.0) {
        speechPan = 5.0f;
    } else if (speechPan > 122.0) {
        speechPan = 122.0f;
    }
    printer->speechPan = speechPan;

    cond = FALSE;
    if (!(printer->stateFlags & MSG_STATE_FLAG_40)) {
        if (!(printer->stateFlags & (MSG_STATE_FLAG_20 | MSG_STATE_FLAG_10))) {
            s32 buttons = BUTTON_A;

            switch (printer->windowState) {
                case MSG_WINDOW_STATE_WAITING:
                    if (printer->stateFlags & MSG_STATE_FLAG_80000) {
                        buttons = BUTTON_A | BUTTON_C_DOWN;
                    }
                    if ((buttons & gGameStatusPtr->pressedButtons[0]) || (gGameStatusPtr->curButtons[0] & BUTTON_B)) {
                        printer->windowState = MSG_WINDOW_STATE_PRINTING;
                        printer->curPrintDelay = 0;
                        printer->stateFlags |= MSG_STATE_FLAG_4;
                        if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_C_DOWN)) {
                            cond = TRUE;
                            sfx_play_sound_with_params(SOUND_MENU_NEXT, 0, 0, 0);
                        } else if (printer->srcBuffer[printer->srcBufferPos] != MSG_CHAR_READ_END) {
                            printer->stateFlags |= MSG_STATE_FLAG_PRINT_QUICKLY | MSG_STATE_FLAG_4;
                            if (printer->fontVariant != 0 || printer->srcBuffer[printer->srcBufferPos] != MSG_CHAR_UNK_C3) {
                                printer->stateFlags |= MSG_STATE_FLAG_PRINT_QUICKLY | MSG_STATE_FLAG_80 | MSG_STATE_FLAG_4;
                            }
                            sfx_play_sound_with_params(SOUND_CC, 0, 0, 0);
                        } else if (printer->style == MSG_STYLE_RIGHT ||
                                   printer->style == MSG_STYLE_LEFT ||
                                   printer->style == MSG_STYLE_CENTER ||
                                   printer->style == MSG_STYLE_TATTLE)
                        {
                            sfx_play_sound_with_params(SOUND_MENU_NEXT, 0, 0, 0);
                        }
                    } else if ((gGameStatusPtr->pressedButtons[0] & BUTTON_Z) &&
                               !(printer->stateFlags & MSG_STATE_FLAG_40000) &&
                               (printer->curLine != 0))
                    {
                        printer->windowState = MSG_WINDOW_STATE_B;
                        printer->unk_4CC = 0;
                        printer->unkArraySize = printer->curLine - 1;
                        printer->unk_4C8 = abs(printer->curLinePos - printer->lineEndPos[printer->unkArraySize]);
                        sfx_play_sound_with_params(SOUND_CD, 0, 0, 0);
                    }
                    break;
                case MSG_WINDOW_STATE_C:
                    if (gGameStatusPtr->pressedButtons[0] & BUTTON_B) {
                        printer->windowState = MSG_WINDOW_STATE_B;
                        printer->unk_4CC = 0;
                        printer->unkArraySize = printer->curLine;
                        printer->unk_4C8 = abs(printer->curLinePos - printer->lineEndPos[printer->unkArraySize]);
                        sfx_play_sound_with_params(SOUND_CC, 0, 0, 0);
                    } else if (gGameStatusPtr->pressedButtons[0] & BUTTON_Z) {
                        if (printer->unkArraySize > 0) {
                            printer->windowState = MSG_WINDOW_STATE_B;
                            printer->unk_4CC = 0;
                            printer->unkArraySize--;
                            printer->unk_4C8 = abs(printer->curLinePos - printer->lineEndPos[printer->unkArraySize]);
                            sfx_play_sound_with_params(SOUND_CD, 0, 0, 0);
                        }
                    } else {
                        if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                            printer->windowState = MSG_WINDOW_STATE_B;
                            printer->unk_4CC = 0;
                            printer->unkArraySize++;
                            printer->unk_4C8 = abs(printer->curLinePos - printer->lineEndPos[printer->unkArraySize]);
                            sfx_play_sound_with_params(SOUND_CE, 0, 0, 0);
                        }
                    }
                    break;
                case MSG_WINDOW_STATE_WAITING_FOR_CHOICE:
                    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                        printer->madeChoice = 1;
                        printer->windowState = MSG_WINDOW_STATE_PRINTING;
                        printer->scrollingTime = 0;
                        printer->stateFlags |= MSG_STATE_FLAG_20000;
                        sfx_play_sound_with_params(SOUND_MENU_NEXT, 0, 0, 0);
                    } else if (printer->cancelOption != 0xFF && (gGameStatusPtr->pressedButtons[0] & BUTTON_B)) {
                        if (printer->cancelOption >= printer->maxOption) {
                            printer->selectedOption = printer->curOption;
                        } else {
                            printer->selectedOption = printer->cancelOption;
                        }
                        printer->madeChoice = 1;
                        printer->windowState = MSG_WINDOW_STATE_PRINTING;
                        printer->scrollingTime = 0;
                        printer->curOption = printer->cancelOption;
                        printer->stateFlags |= MSG_STATE_FLAG_20000;
                        sfx_play_sound_with_params(SOUND_MENU_BACK, 0, 0, 0);
                    } else if (gGameStatusPtr->heldButtons[0] & BUTTON_STICK_DOWN) {
                        if (printer->curOption != printer->maxOption - 1) {
                            printer->targetOption = printer->curOption + 1;
                            printer->windowState = MSG_WINDOW_STATE_SCROLLING_BACK;
                            printer->scrollingTime = 1;
                            sfx_play_sound_with_params(SOUND_MENU_CHANGE_SELECTION, 0, 0, 0);
                        }
                    } else if (gGameStatusPtr->heldButtons[0] & BUTTON_STICK_UP) {
                        if (printer->curOption != 0) {
                            printer->targetOption = printer->curOption - 1;
                            printer->windowState = MSG_WINDOW_STATE_SCROLLING_BACK;
                            printer->scrollingTime = 1;
                            sfx_play_sound_with_params(SOUND_MENU_CHANGE_SELECTION, 0, 0, 0);
                        }
                    }

                    if (printer->windowState != MSG_WINDOW_STATE_SCROLLING_BACK) {
                        break;
                    }
                case MSG_WINDOW_STATE_SCROLLING_BACK:
                    printer->scrollingTime++;
                    if (printer->scrollingTime >= 5) {
                        printer->windowState = MSG_WINDOW_STATE_WAITING_FOR_CHOICE;
                        printer->curOption = printer->targetOption;
                        printer->selectedOption = printer->curOption;
                    }
                    break;
            }
        } else if (!(printer->stateFlags & MSG_STATE_FLAG_20) &&
                    printer->windowState == MSG_WINDOW_STATE_WAITING &&
                    (gGameStatusPtr->pressedButtons[0] & BUTTON_A))
        {
            printer->windowState = MSG_WINDOW_STATE_PRINTING;
            printer->curPrintDelay = 0;
            printer->stateFlags |= MSG_STATE_FLAG_4;
        }

        if (printer->stateFlags & MSG_STATE_FLAG_4 && !(gGameStatusPtr->curButtons[0] & BUTTON_A)) {
            printer->stateFlags &= ~MSG_STATE_FLAG_4;
        }

        for (i = 0; i < ARRAY_COUNT(printer->animTimers); i++) {
            if (printer->animTimers[i] > 0) {
                printer->animTimers[i]--;
            }
        }

        switch (printer->windowState) {
            case MSG_WINDOW_STATE_PRINTING:
                if ((gGameStatusPtr->pressedButtons[0] & BUTTON_A) | (gGameStatusPtr->curButtons[0] & BUTTON_B)) {
                    if (!(printer->stateFlags & (MSG_STATE_FLAG_20 | MSG_STATE_FLAG_10)) && !cond) {
                        printer->stateFlags |= MSG_STATE_FLAG_PRINT_QUICKLY;

                    }
                }
            // fallthrough
            case MSG_WINDOW_STATE_INIT:
                charsToPrint = printer->charsPerChunk;
                if (printer->windowState == MSG_WINDOW_STATE_INIT) {
                    printer->windowState = MSG_WINDOW_STATE_PRINTING;
                    printer->curPrintDelay = 0;
                } else if (printer->stateFlags & MSG_STATE_FLAG_PRINT_QUICKLY) {
                    charsToPrint = 12;
                    printer->curPrintDelay = 0;
                } else if (!(printer->stateFlags & MSG_STATE_FLAG_4)) {
                    if (!(printer->stateFlags & (MSG_STATE_FLAG_20 | MSG_STATE_FLAG_10)) &&
                        (gGameStatusPtr->curButtons[0] & BUTTON_A))
                    {
                        charsToPrint = 6;
                        printer->curPrintDelay = 0;
                    }
                }
                if ((printer->curPrintDelay == 0) || --printer->curPrintDelay == 0) {
                    msg_copy_to_print_buffer(printer, charsToPrint, 0);
                }
                break;
            case MSG_WINDOW_STATE_SCROLLING:
                if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
                    if (!(printer->stateFlags & (MSG_STATE_FLAG_20 | MSG_STATE_FLAG_10))) {
                        printer->stateFlags |= MSG_STATE_FLAG_PRINT_QUICKLY;
                    }
                }
                printer->curLinePos += printer->unk_464;
                if ((printer->stateFlags & MSG_STATE_FLAG_PRINT_QUICKLY) ||
                    (!(printer->stateFlags & (MSG_STATE_FLAG_10 | MSG_STATE_FLAG_4)) &&
                    (gGameStatusPtr->curButtons[0] & BUTTON_A)))
                {
                    printer->curLinePos += 6;
                }

                if (printer->curLinePos >= printer->nextLinePos) {
                    printer->windowState = MSG_WINDOW_STATE_PRINTING;
                    printer->curLinePos = printer->nextLinePos;
                    printer->stateFlags |= MSG_STATE_FLAG_4;

                    if (printer->style == MSG_STYLE_SIGN ||
                        printer->style == MSG_STYLE_LAMPPOST ||
                        printer->srcBuffer[printer->srcBufferPos] == MSG_CHAR_READ_WAIT)
                    {
                        printer->curPrintDelay = 0;
                    } else {
                        printer->curPrintDelay = 5;
                    }
                    printer->lineEndPos[printer->curLine] = printer->curLinePos;
                }
                break;
            case MSG_WINDOW_STATE_B:
                printer->unk_4CC += 1;
                endPosDist = abs(printer->curLinePos - printer->lineEndPos[printer->unkArraySize]);
                lineIncAmt = 2;

                if (printer->unk_4C8 <= 16) {
                    if (endPosDist >= 15) {
                        lineIncAmt = 4;
                    } else if (endPosDist >= 9) {
                        lineIncAmt = 3;
                    }
                } else if (endPosDist > 96) {
                    lineIncAmt = 10;
                } else if (endPosDist > 48) {
                    lineIncAmt = 9;
                } else if (endPosDist >= 24) {
                    lineIncAmt = 7;
                } else if (endPosDist >= 16) {
                    lineIncAmt = 5;
                } else if (endPosDist >= 8) {
                    lineIncAmt = 4;
                } else if (endPosDist > 4) {
                    lineIncAmt = 3;
                }

                printer->unk_4CA = lineIncAmt;

                if (printer->lineEndPos[printer->unkArraySize] < printer->curLinePos) {
                    printer->curLinePos -= printer->unk_4CA;
                    if (printer->lineEndPos[printer->unkArraySize] >= printer->curLinePos) {
                        printer->curLinePos = printer->lineEndPos[printer->unkArraySize];
                        printer->windowState = MSG_WINDOW_STATE_C;
                    }
                } else {
                    printer->curLinePos += printer->unk_4CA;
                    if (printer->curLinePos >= printer->lineEndPos[printer->unkArraySize]) {
                        printer->curLinePos = printer->lineEndPos[printer->unkArraySize];
                        printer->windowState = MSG_WINDOW_STATE_C;
                        if (printer->unkArraySize == printer->curLine) {
                            printer->windowState = MSG_WINDOW_STATE_WAITING;
                            printer->rewindArrowAnimState = REWIND_ARROW_STATE_INIT;
                            printer->rewindArrowCounter = 0;
                        }
                    }
                }
                break;
            case MSG_WINDOW_STATE_OPENING:
            case MSG_WINDOW_STATE_CLOSING:
            case MSG_WINDOW_STATE_WAITING:
            case MSG_WINDOW_STATE_WAITING_FOR_CHOICE:
            case MSG_WINDOW_STATE_SCROLLING_BACK:
            case MSG_WINDOW_STATE_VIEWING_PREV:
            case MSG_WINDOW_STATE_A:
            case MSG_WINDOW_STATE_C:
            case MSG_WINDOW_STATE_D:
            case MSG_WINDOW_STATE_E:
                break;
        }
    }

    if (printer->stateFlags & MSG_STATE_FLAG_1) {
        printer->windowState = MSG_WINDOW_STATE_DONE;
        printer->stateFlags = 0;
        if (printer->letterBackgroundImg != NULL) {
            general_heap_free(printer->letterBackgroundImg);
        }
        if (printer->letterBackgroundPal != NULL) {
            general_heap_free(printer->letterBackgroundPal);
        }
        if (printer->letterContentImg != NULL) {
            general_heap_free(printer->letterContentImg);
        }
        if (printer->letterContentPal != NULL) {
            general_heap_free(printer->letterContentPal);
        }
        if (printer->closedWritebackBool != NULL) {
            *printer->closedWritebackBool = TRUE;
            printer->closedWritebackBool = NULL;
        }
    }

    return printer->windowState;
}

void render_messages(void) {
    Mtx* matrix = &gMessageWindowProjMatrix[gCurrentDisplayContextIndex];
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMessagePrinters); i++) {
        if (gMessagePrinters[i].stateFlags & MSG_STATE_FLAG_2) {
            gSPViewport(gMainGfxPos++, D_8014C280);
            guOrtho(matrix, 0.0f, 319.0f, -240.0f, 0.0f, -500.0f, 500.0f, 1.0f);
            gSPMatrix(gMainGfxPos++, OS_K0_TO_PHYSICAL(matrix), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gDPPipeSync(gMainGfxPos++);
            gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
            gSPClearGeometryMode(gMainGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                 G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
            gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
            break;
        }
    }

    for (i = 0; i < ARRAY_COUNT(gMessagePrinters); i++) {
        if (gMessagePrinters[i].stateFlags & MSG_STATE_FLAG_2) {
            draw_message_window(&gMessagePrinters[i]);

            if (gMessagePrinters[i].windowState == MSG_WINDOW_STATE_WAITING) {
                if (!(gMessagePrinters[i].stateFlags & MSG_STATE_FLAG_8000) &&
                    !(gMessagePrinters[i].stateFlags & MSG_STATE_FLAG_40))
                {
                    msg_update_rewind_arrow(i);
                }
            } else if (gMessagePrinters[i].windowState == MSG_WINDOW_STATE_C) {
                msg_draw_rewind_arrow(i);
            } else if (gMessagePrinters[i].windowState == MSG_WINDOW_STATE_WAITING_FOR_CHOICE ||
                       gMessagePrinters[i].windowState == MSG_WINDOW_STATE_SCROLLING_BACK ||
                       gMessagePrinters[i].stateFlags & MSG_STATE_FLAG_10000 ||
                       gMessagePrinters[i].stateFlags & MSG_STATE_FLAG_20000)
            {
                msg_draw_choice_pointer(&gMessagePrinters[i]);
            }
        }
    }
}

void msg_play_speech_sound(MessagePrintState* printer, u8 character) {
    f32 volTemp;
    s16 volume;
    s32 pitchShift;
    s32 flag = 1;
    s32 baseShift = 100;

    if (printer->stateFlags & MSG_STATE_FLAG_800000 && !(printer->delayFlags & (MSG_DELAY_FLAG_2 | MSG_DELAY_FLAG_4)) && printer->volume != 0) {
        volTemp = (f32)printer->volume / 100.0;
        pitchShift = ((character % 20) * 10) + (printer->speechPitchShift - baseShift);
        volume = ((rand_int(15) + 78) * volTemp);

        if (volume > 255) {
            volume = 255;
        }

        if (character & flag) {
            sfx_play_sound_with_params(printer->speechSoundIDA, volume, printer->speechPan, pitchShift);
        } else {
            sfx_play_sound_with_params(printer->speechSoundIDB, volume, printer->speechPan, pitchShift);
        }
    }
}

extern s32 gItemIconRasterOffsets[];
extern s32 gItemIconPaletteOffsets[];
extern s32 MsgLetterRasterOffsets[];
extern s32 MsgLetterPaletteOffsets[];
extern MsgVoice MsgVoices[];

#if VERSION_IQUE
INCLUDE_ASM(s32, "msg", msg_copy_to_print_buffer);
#else
void msg_copy_to_print_buffer(MessagePrintState* printer, s32 arg1, s32 arg2) {
    u8 arg;
    u8 argQ;
    u8 argW;
    u8 argE;
    u8 sp10[4];
    s32 addr;
    s16 offset;
    s32 i;
    u8* romAddr;
    u8* romEnd;
    s32 temp;
    void* a2;
    s8 s8 = arg2 & 1;
    u8* printBuf = &printer->printBuffer[printer->printBufferPos];
    u8* srcBuf = &printer->srcBuffer[printer->srcBufferPos];

    do {
        u8 c = *srcBuf++; // a1
        u8 nextArg = *srcBuf; // a2
        switch (c) {
            case MSG_CHAR_READ_ENDL:
                *printBuf++ = MSG_CHAR_PRINT_ENDL;
                printer->lineCount += (u8)printer->sizeScale;
                break;
            case MSG_CHAR_READ_WAIT:
                printer->windowState = MSG_WINDOW_STATE_WAITING;
                printer->delayFlags |= MSG_DELAY_FLAG_1;
                printer->delayFlags &= ~2;
                printer->rewindArrowAnimState = REWIND_ARROW_STATE_INIT;
                printer->rewindArrowCounter = 0;
                printer->stateFlags &= ~MSG_STATE_FLAG_80;
                printer->stateFlags &= ~MSG_STATE_FLAG_PRINT_QUICKLY;
                if (printer->style != MSG_STYLE_F) {
                    sfx_play_sound_with_params(SOUND_CB, 0, 0, 0);
                }
                break;
            case MSG_CHAR_READ_PAUSE:
                printer->curPrintDelay = *srcBuf++;
                printer->delayFlags |= MSG_DELAY_FLAG_1;
                printer->stateFlags &= ~MSG_STATE_FLAG_80;
                break;
            case MSG_CHAR_READ_VARIANT0:
            case MSG_CHAR_READ_VARIANT1:
            case MSG_CHAR_READ_VARIANT2:
            case MSG_CHAR_READ_VARIANT3:
                *printBuf++ = MSG_CHAR_PRINT_VARIANT0 + (c - MSG_CHAR_READ_VARIANT0);
                printer->fontVariant = c + 13;
                break;
            case MSG_CHAR_READ_SPACE:
                *printBuf++ = MSG_CHAR_PRINT_SPACE;
                break;
            case MSG_CHAR_READ_FULL_SPACE:
                *printBuf++ = MSG_CHAR_PRINT_FULL_SPACE;
                break;
            case MSG_CHAR_READ_HALF_SPACE:
                *printBuf++ = MSG_CHAR_PRINT_HALF_SPACE;
                break;
            case MSG_CHAR_READ_UNK_CHAR_FA:
                *printBuf++ = MSG_CHAR_PRINT_UNK_CHAR_FA;
                arg1--;
                break;
            case MSG_CHAR_READ_NEXT:
                if (printer->lineCount != 0) {
                    printer->lineEndPos[printer->curLine] = printer->curLinePos;
                    printer->curLine++;
                    *printBuf++ = MSG_CHAR_PRINT_NEXT;
                    printer->nextLinePos = printer->curLinePos + (MsgCharsets[printer->font]->newLineY + MsgStyleVerticalLineOffsets[printer->style]) * printer->lineCount;
                    printer->windowState = MSG_WINDOW_STATE_SCROLLING;
                    printer->delayFlags |= MSG_DELAY_FLAG_1;
                }
                printer->lineCount = 0;
                break;
            case MSG_CHAR_READ_STYLE:
                *printBuf++ = MSG_CHAR_PRINT_STYLE;
                arg = *srcBuf++;
                printer->style = arg;
                *printBuf++ = arg;
                printer->fadeInCounter = 0;
                switch (arg) {
                    case MSG_STYLE_RIGHT:
                    case MSG_STYLE_LEFT:
                    case MSG_STYLE_CENTER:
                    case MSG_STYLE_TATTLE:
                        if (arg == MSG_STYLE_RIGHT || arg == MSG_STYLE_LEFT || arg == MSG_STYLE_CENTER) {
                            printer->maxLinesPerPage = 3;
                        }
                        printer->delayFlags |= MSG_DELAY_FLAG_1;
                        printer->stateFlags |= MSG_STATE_FLAG_800000 | MSG_STATE_FLAG_800;
                        if (nextArg != MSG_CHAR_UNK_C3) {
                            printer->stateFlags |= MSG_STATE_FLAG_80;
                        }
                        printer->speechSoundIDA = SOUND_MSG_VOICE_1A;
                        printer->speechSoundIDB = SOUND_MSG_VOICE_1B;
                        printer->windowState = MSG_WINDOW_STATE_OPENING;
                        break;
                    case MSG_STYLE_CHOICE:
                        do {
                            printer->windowBasePos.x = *srcBuf++;
                            printer->windowBasePos.y = *srcBuf++;
                            printer->windowSize.x = *srcBuf++;
                            printer->windowSize.y = *srcBuf++;
                            printer->windowState = MSG_WINDOW_STATE_OPENING;
                            printer->stateFlags |= MSG_STATE_FLAG_800;
                        } while (0);
                        break;
                    case MSG_STYLE_INSPECT:
                    case MSG_STYLE_NARRATE:
                    case MSG_STYLE_F:
                        if (!s8) {
                            printer->windowBasePos.x = 20;
                            printer->windowBasePos.y = 28;
                            printer->windowSize.y = 58;
                            printer->windowSize.x = 280;
                            printer->windowState = MSG_WINDOW_STATE_OPENING;
                            printer->stateFlags |= MSG_STATE_FLAG_800;
                            printer->delayFlags |= MSG_DELAY_FLAG_1;
                            if (arg == MSG_STYLE_INSPECT) {
                                sfx_play_sound_with_params(SOUND_21C, 0, 0, 0);
                            }
                        }
                        break;
                    case MSG_STYLE_UPGRADE:
                        printer->windowBasePos.x = *srcBuf++;
                        printer->windowBasePos.y = *srcBuf++;
                        printer->windowSize.x = *srcBuf++;
                        printer->windowSize.y = *srcBuf++;
                        sfx_play_sound_with_params(SOUND_21C, 0, 0, 0);
                        printer->windowState = MSG_WINDOW_STATE_OPENING;
                        printer->delayFlags |= MSG_DELAY_FLAG_1;
                        printer->stateFlags |= MSG_STATE_FLAG_800;
                        break;
                    case MSG_STYLE_LAMPPOST:
                        printer->windowSize.y = *srcBuf++;
                        // fallthrough
                    case MSG_STYLE_SIGN:
                        do {
                            if (!s8) {
                                printer->windowState = MSG_WINDOW_STATE_OPENING;
                                printer->stateFlags |= MSG_STATE_FLAG_800;
                                printer->delayFlags |= MSG_DELAY_FLAG_1;
                            }
                        } while (0);
                        break;
                    case MSG_STYLE_POSTCARD:
                        arg = *srcBuf++;
                        printer->windowState = MSG_WINDOW_STATE_OPENING;
                        printer->stateFlags |= MSG_STATE_FLAG_800;
                        printer->delayFlags |= MSG_DELAY_FLAG_1;
                        printer->letterBackgroundImg = heap_malloc(((charset_postcard_png_width * charset_postcard_png_height) / 2));
                        romAddr = charset_ROM_START + (s32)charset_postcard_OFFSET;
                        dma_copy(romAddr, romAddr + ((charset_postcard_png_width * charset_postcard_png_height) / 2), printer->letterBackgroundImg);
                        printer->letterBackgroundPal = heap_malloc(0x20);
                        romAddr = charset_ROM_START + ((s32)charset_postcard_pal_OFFSET + 5);
                        dma_copy(romAddr, romAddr + 0x20, printer->letterBackgroundPal);
                        printer->letterContentImg = heap_malloc(charset_letter_content_1_png_width * charset_letter_content_1_png_height);
                        romAddr = charset_ROM_START + MsgLetterRasterOffsets[arg];
                        dma_copy(romAddr, romAddr + (charset_letter_content_1_png_width * charset_letter_content_1_png_height), printer->letterContentImg);
                        printer->letterContentPal = heap_malloc(0x200);
                        romAddr = charset_ROM_START + MsgLetterPaletteOffsets[arg];
                        dma_copy(romAddr, romAddr + 0x200, printer->letterContentPal);
                        break;
                    case MSG_STYLE_POPUP:
                    case MSG_STYLE_B:
                        printer->windowSize.x = printer->msgWidth + 32;
                        printer->windowSize.y = 40;
                        printer->stateFlags |= MSG_STATE_FLAG_8000;
                        do {
                            if (!s8) {
                                printer->stateFlags |= MSG_STATE_FLAG_8000 | MSG_STATE_FLAG_800;
                                printer->windowState = MSG_WINDOW_STATE_D;
                                printer->delayFlags |= MSG_DELAY_FLAG_1;
                            }
                        } while (0);
                        break;
                    case MSG_STYLE_EPILOGUE:
                        printer->windowState = MSG_WINDOW_STATE_PRINTING;
                        break;
                }
                if ((printer->delayFlags & MSG_DELAY_FLAG_1) && (printer->delayFlags & (MSG_DELAY_FLAG_4 | MSG_DELAY_FLAG_2))) {
                    printer->delayFlags &= ~MSG_DELAY_FLAG_1;
                }
                break;
            case MSG_CHAR_READ_END:
                *printBuf++ = MSG_CHAR_PRINT_END;
                if (printer->stateFlags & MSG_STATE_FLAG_800) {
                    if (printer->stateFlags & MSG_STATE_FLAG_1000) {
                        if (printer->closedWritebackBool != NULL) {
                            *printer->closedWritebackBool = TRUE;
                        }
                    }
                    if (printer->style != MSG_STYLE_POPUP && printer->style != MSG_STYLE_B) {
                        printer->windowState = MSG_WINDOW_STATE_CLOSING;
                    } else {
                        printer->windowState = MSG_WINDOW_STATE_E;
                    }
                    printer->fadeOutCounter = 0;
                } else {
                    printer->stateFlags |= MSG_STATE_FLAG_1;
                }
                printer->delayFlags |= MSG_DELAY_FLAG_1;
                printer->delayFlags &= ~MSG_DELAY_FLAG_2;
                break;
            case MSG_CHAR_READ_FUNCTION:
                switch (*srcBuf++) {
                    case MSG_READ_FUNC_FONT:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_FONT;
                        *printBuf++ = printer->font = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_VARIANT:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_VARIANT;
                        *printBuf++ = printer->fontVariant = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_COLOR:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_COLOR;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_NO_SKIP:
                        printer->stateFlags |= MSG_STATE_FLAG_10;
                        break;
                    case MSG_READ_FUNC_INPUT_OFF:
                        printer->stateFlags |= MSG_STATE_FLAG_20;
                        printer->stateFlags &= ~MSG_STATE_FLAG_PRINT_QUICKLY;
                        break;
                    case MSG_READ_FUNC_INPUT_ON:
                        printer->stateFlags &= ~MSG_STATE_FLAG_20;
                        break;
                    case MSG_READ_FUNC_SPACING:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_SPACING;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_DELAY_OFF:
                        printer->delayFlags |= MSG_DELAY_FLAG_2;
                        break;
                    case MSG_READ_FUNC_DELAY_ON:
                        printer->delayFlags &= ~MSG_DELAY_FLAG_2;
                        printer->delayFlags |= MSG_DELAY_FLAG_1;
                        break;
                    case MSG_READ_FUNC_SCROLL:
                        printer->lineEndPos[printer->curLine] = printer->curLinePos;
                        printer->curLine++;
                        *printBuf++ = MSG_CHAR_PRINT_NEXT;
                        arg = *srcBuf++;
                        printer->nextLinePos = printer->curLinePos + (MsgCharsets[printer->font]->newLineY + MsgStyleVerticalLineOffsets[printer->style]) * arg;
                        printer->windowState = MSG_WINDOW_STATE_SCROLLING;
                        printer->delayFlags |= MSG_DELAY_FLAG_1;
                        printer->lineCount = 0;
                        break;
                    case MSG_READ_FUNC_SIZE:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_SIZE;
                        *printBuf++ = *srcBuf++;
                        *printBuf++ = arg = *srcBuf++;
                        printer->sizeScale = (arg >> 4) + (arg & 0xF) * 0.0625f;
                        break;
                    case MSG_READ_FUNC_SIZE_RESET:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_SIZE_RESET;
                        printer->sizeScale = 1.0f;
                        break;
                    case MSG_READ_FUNC_SPEED:
                        printer->printDelayTime = *srcBuf++;
                        printer->charsPerChunk = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_SET_X:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_SET_X;
                        *printBuf++ = *srcBuf++;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_SET_Y:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_SET_Y;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_RIGHT:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_RIGHT;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_DOWN:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_DOWN;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_UP:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_UP;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_INLINE_IMAGE:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_INLINE_IMAGE;
                        *printBuf++ = *srcBuf++;
                        arg1--;
                        printer->curPrintDelay = printer->printDelayTime;
                        if (arg1 <= 0) {
                            printer->delayFlags |= MSG_DELAY_FLAG_1;
                        }
                        if (printer->delayFlags & (MSG_DELAY_FLAG_4 | MSG_DELAY_FLAG_2)) {
                            printer->delayFlags &= ~MSG_DELAY_FLAG_1;
                        }
                        break;
                    case MSG_READ_FUNC_ANIM_SPRITE:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_ANIM_SPRITE;
                        *printBuf++ = *srcBuf++;
                        *printBuf++ = *srcBuf++;
                        *printBuf++ = *srcBuf++;
                        printer->curPrintDelay = printer->printDelayTime;
                        if (--arg1 <= 0) {
                            printer->delayFlags |= MSG_DELAY_FLAG_1;
                        }
                        if (printer->delayFlags & (MSG_DELAY_FLAG_4 | MSG_DELAY_FLAG_2)) {
                            printer->delayFlags &= ~MSG_DELAY_FLAG_1;
                        }
                        break;
                    case MSG_READ_FUNC_ITEM_ICON:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_ITEM_ICON;

                        arg = *srcBuf++;
                        argQ = *srcBuf++;

                        a2 = D_80159B50;
                        offset = arg << 8 | argQ;

                        D_8015131C = D_80159B50;
                        dma_copy(icon_ROM_START + gItemIconRasterOffsets[offset],
                                icon_ROM_START + gItemIconRasterOffsets[offset] + 0x200, a2);
                        romEnd = icon_ROM_START + gItemIconPaletteOffsets[offset] + 0x20;
                        dma_copy(icon_ROM_START + gItemIconPaletteOffsets[offset],
                                 romEnd, D_8015C7E0);
                        printer->curPrintDelay = printer->printDelayTime;
                        if (--arg1 <= 0) {
                            printer->delayFlags |= MSG_DELAY_FLAG_1;
                        }
                        if (printer->delayFlags & (MSG_DELAY_FLAG_4 | MSG_DELAY_FLAG_2)) {
                            printer->delayFlags &= ~MSG_DELAY_FLAG_1;
                        }
                        break;
                    case MSG_READ_FUNC_IMAGE:
                        printer->curImageIndex = *srcBuf++;
                        arg = *srcBuf++;
                        argQ = *srcBuf++;
                        printer->varImageScreenPos.x = arg << 8 | argQ;
                        printer->varImageScreenPos.y = *srcBuf++;
                        printer->varImgHasBorder = *srcBuf++;
                        printer->varImgFinalAlpha = *srcBuf++;
                        printer->varImgAlphaFadeStep = *srcBuf++;
                        printer->varImageDisplayState = 0;
                        printer->varImageFadeTimer = 0;
                        if (--arg1 <= 0) {
                            printer->delayFlags |= MSG_DELAY_FLAG_1;
                        }
                        if (printer->delayFlags & (MSG_DELAY_FLAG_4 | MSG_DELAY_FLAG_2)) {
                            printer->delayFlags &= ~MSG_DELAY_FLAG_1;
                        }
                        break;
                    case MSG_READ_FUNC_HIDE_IMAGE:
                        arg = *srcBuf++;
                        if (arg != 0) {
                            printer->varImageDisplayState = 2;
                            printer->varImgAlphaFadeStep = arg;
                            printer->varImageFadeTimer = 0;
                        } else {
                            printer->varImageScreenPos.x = 0;
                        }
                        break;
                    case MSG_READ_FUNC_ANIM_DELAY:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_ANIM_DELAY;
                        *printBuf++ = *srcBuf++;
                        *printBuf++ = *srcBuf++;
                        *printBuf++ = *srcBuf++;
                        printer->delayFlags |= MSG_DELAY_FLAG_4;
                        break;
                    case MSG_READ_FUNC_ANIM_LOOP:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_ANIM_LOOP;
                        *printBuf++ = *srcBuf++;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_ANIM_DONE:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_ANIM_DONE;
                        *printBuf++ = *srcBuf++;
                        printer->delayFlags &= ~MSG_DELAY_FLAG_4;
                        if (--arg1 <= 0) {
                            printer->delayFlags |= MSG_DELAY_FLAG_1;
                        }
                        break;
                    case MSG_READ_FUNC_SET_CURSOR:
                        arg = *srcBuf++;
                        argQ = *srcBuf++;
                        argW = *srcBuf++;
                        argE = *srcBuf++;
                        printer->cursorPosX[arg] = argQ << 8 | argW;
                        printer->cursorPosY[arg] = argE;
                        break;
                    case MSG_READ_FUNC_CURSOR:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_CURSOR;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_END_CHOICE:
                        sfx_play_sound_with_params(SOUND_MENU_SHOW_CHOICE, 0, 0, 0);
                        printer->maxOption = *srcBuf++;
                        printer->madeChoice = 0;
                        printer->curOption = 0;
                        printer->selectedOption = 0;
                        printer->windowState = MSG_WINDOW_STATE_WAITING_FOR_CHOICE;
                        printer->delayFlags |= MSG_DELAY_FLAG_1;
                        break;
                    case MSG_READ_FUNC_SET_CANCEL:
                        printer->cancelOption = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_OPTION:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_OPTION;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_RESET_GFX:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_RESET_GFX;
                        break;
                    case MSG_READ_FUNC_YIELD:
                        printer->stateFlags |= MSG_STATE_FLAG_100000 | MSG_STATE_FLAG_40;
                        printer->delayFlags |= MSG_DELAY_FLAG_1;
                        printer->stateFlags &= ~MSG_STATE_FLAG_80;
                        printer->stateFlags &= ~MSG_STATE_FLAG_PRINT_QUICKLY;
                        break;
                    case MSG_READ_FUNC_SAVE_POS:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_SAVE_POS;
                        break;
                    case MSG_READ_FUNC_RESTORE_POS:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_RESTORE_POS;
                        break;
                    case MSG_READ_FUNC_SAVE_COLOR:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_SAVE_COLOR;
                        break;
                    case MSG_READ_FUNC_RESTORE_COLOR:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_RESTORE_COLOR;
                        break;
                    case MSG_READ_FUNC_START_FX:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_START_FX;
                        arg = *srcBuf++;
                        switch (arg) {
                            case MSG_FX_SHAKE:
                            case MSG_FX_WAVE:
                            case MSG_FX_NOISE_OUTLINE:
                            case MSG_FX_RAINBOW:
                            case MSG_FX_GLOBAL_WAVE:
                            case MSG_FX_GLOBAL_RAINBOW:
                            case MSG_FX_RISE_PRINT:
                            case MSG_FX_GROW_PRINT:
                            case MSG_FX_SIZE_JITTER:
                            case MSG_FX_SIZE_WAVE:
                            case MSG_FX_DROP_SHADOW:
                                *printBuf++ = arg;
                                break;
                            case MSG_FX_STATIC:
                            case MSG_FX_BLUR:
                            case MSG_FX_DITHER_FADE:
                                *printBuf++ = arg;
                                *printBuf++ = *srcBuf++;
                                break;
                        }
                        break;
                    case MSG_READ_FUNC_END_FX:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_END_FX;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_VAR:
                        arg = *srcBuf++;
                        srcBuf -= 3;
                        if (printer->varBufferReadPos == 0) {
                            printer->unk_52A = printer->fontVariant;
                            *printBuf++ = MSG_CHAR_PRINT_VARIANT0;
                        }

                        do {
                            s32 a0 = 1;
                            argQ = gMessageMsgVars[arg][printer->varBufferReadPos++];
                            if (argQ >= MSG_CONTROL_CHAR) {
                                s32 tmp;

                                switch (argQ) {
                                    case MSG_CHAR_READ_ENDL:
                                        if (gMessageMsgVars[arg][printer->varBufferReadPos] != MSG_CHAR_READ_END) {
                                            sp10[0] = MSG_CHAR_PRINT_ENDL;
                                        } else {
                                            a0 = 0;
                                        }
                                        break;
                                    case MSG_CHAR_READ_VARIANT0:
                                    case MSG_CHAR_READ_VARIANT1:
                                    case MSG_CHAR_READ_VARIANT2:
                                    case MSG_CHAR_READ_VARIANT3:
                                        sp10[0] = (argQ - MSG_CHAR_READ_VARIANT0) + MSG_CHAR_PRINT_VARIANT0;
                                        temp = argQ - MSG_CHAR_READ_VARIANT0 + 0x200;
                                        printer->fontVariant = temp;
                                        break;
                                    case MSG_CHAR_READ_SPACE:
                                        sp10[0] = MSG_CHAR_PRINT_SPACE;
                                        break;
                                    case MSG_CHAR_READ_FUNCTION:
                                        sp10[0] = MSG_CHAR_PRINT_FUNCTION;
                                        switch (gMessageMsgVars[arg][printer->varBufferReadPos++]) {
                                            case MSG_READ_FUNC_COLOR:
                                                sp10[1] = MSG_PRINT_FUNC_COLOR;
                                                sp10[2] = gMessageMsgVars[arg][printer->varBufferReadPos++];
                                                a0 = 3;
                                                break;
                                            case MSG_READ_FUNC_SAVE_COLOR:
                                                sp10[1] = MSG_PRINT_FUNC_SAVE_COLOR;
                                                a0 = 2;
                                                break;
                                            case MSG_READ_FUNC_RESTORE_COLOR:
                                                sp10[1] = MSG_PRINT_FUNC_RESTORE_COLOR;
                                                a0 = 2;
                                                break;
                                        }
                                        break;
                                }
                            } else {
                                sp10[0] = argQ;
                            }
                            for (i = 0; i < a0; i++) {
                                arg1--;
                                *printBuf++ = sp10[i];
                            }

                            if (gMessageMsgVars[arg][printer->varBufferReadPos] == MSG_CHAR_READ_END) {
                                srcBuf += 3;
                                printer->varBufferReadPos = 0;
                                printer->fontVariant = printer->unk_52A;
                                *printBuf++ = MSG_CHAR_PRINT_VARIANT0 + printer->fontVariant;
                                break;
                            }
                        } while ((printer->delayFlags & (MSG_DELAY_FLAG_4 | MSG_DELAY_FLAG_2)) || arg1 > 0);

                        if (!(printer->delayFlags & (MSG_DELAY_FLAG_4 | MSG_DELAY_FLAG_2)) && arg1 <= 0) {
                            printer->delayFlags |= MSG_DELAY_FLAG_1;
                            printer->curPrintDelay = printer->printDelayTime;
                        }
                        msg_play_speech_sound(printer, argQ);
                        if (printer->stateFlags & MSG_STATE_FLAG_800000) {
                            printer->stateFlags |= MSG_STATE_FLAG_80;
                        }
                        break;
                    case MSG_READ_FUNC_VOICE:
                        arg = *srcBuf++;
                        printer->speechSoundType = arg;
                        printer->speechSoundIDA = MsgVoices[arg].voiceA;
                        printer->speechSoundIDB = MsgVoices[arg].voiceB;
                        printer->speechPitchShift = MsgVoices[arg].pitchShift;
                        break;
                    case MSG_READ_FUNC_VOLUME:
                        printer->volume = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_CUSTOM_VOICE:
                        arg = *srcBuf++;
                        argQ = *srcBuf++;
                        argW = *srcBuf++;
                        argE = *srcBuf++;
                        printer->speechSoundIDA = (arg << 0x18) + (argQ << 0x10) + (argW << 0x8) + (argE);
                        arg = *srcBuf++;
                        argQ = *srcBuf++;
                        argW = *srcBuf++;
                        argE = *srcBuf++;
                        printer->speechSoundIDB = (arg << 0x18) + (argQ << 0x10) + (argW << 0x8) + (argE);
                        break;
                    case MSG_READ_FUNC_CENTER_X:
                        *printBuf++ = MSG_CHAR_PRINT_FUNCTION;
                        *printBuf++ = MSG_PRINT_FUNC_CENTER_X;
                        *printBuf++ = *srcBuf++;
                        break;
                    case MSG_READ_FUNC_SET_REWIND:
                        if (*srcBuf++)  {
                            printer->stateFlags |= MSG_STATE_FLAG_40000;
                        } else {
                            printer->stateFlags &= ~MSG_STATE_FLAG_40000;
                        }
                        break;
                    case MSG_READ_FUNC_ENABLE_CDOWN_NEXT:
                        printer->stateFlags |= MSG_STATE_FLAG_80000;
                        break;
                }
                break;
            default:
                *printBuf++ = c;
                arg1--;
                if (printer->fontVariant == 0 && c == MSG_CHAR_UNK_C3) {
                    printer->stateFlags &= ~MSG_STATE_FLAG_80;
                } else {
                    msg_play_speech_sound(printer, c);
                    if (printer->stateFlags & MSG_STATE_FLAG_800000) {
                        printer->stateFlags |= MSG_STATE_FLAG_80;
                    }
                }
                break;
        }

        if (!(printer->delayFlags & (MSG_DELAY_FLAG_4 | MSG_DELAY_FLAG_2)) && arg1 <= 0) {
            printer->delayFlags |= MSG_DELAY_FLAG_1;
            printer->curPrintDelay = printer->printDelayTime;
        }
        if (!(printer->delayFlags & MSG_DELAY_FLAG_1)) {
            continue;
        }
        if (!s8) {
            break;
        }
        if (srcBuf[-1] == MSG_CHAR_READ_END) {
            break;
        }
        arg1 = 10000;
    } while (TRUE);

    printer->printBufferPos = printBuf - printer->printBuffer;
    printer->delayFlags = 0;
    printer->srcBufferPos = (u16)(s32)(srcBuf - (s32)printer->srcBuffer);
    *printBuf = MSG_CHAR_PRINT_END;
}
#endif

void initialize_printer(MessagePrintState* printer, s32 arg1, s32 arg2) {
    s32 i;

    printer->printBufferSize = ARRAY_COUNT(printer->printBuffer);
    printer->printBuffer[0] = MSG_CHAR_PRINT_END;
    printer->printDelayTime = 1;
    printer->charsPerChunk = 1;
    printer->unk_464 = 6;
    printer->srcBuffer = NULL;
    printer->msgID = 0;
    printer->curPrintDelay = 0;
    printer->windowOffsetPos.x = 0;
    printer->windowOffsetPos.y = 0;
    printer->windowBasePos.x = 0;
    printer->windowBasePos.y = 0;
    printer->rewindArrowAnimState = REWIND_ARROW_STATE_INIT;
    printer->rewindArrowCounter = 0;
    printer->rewindArrowPos.x = 0;
    printer->rewindArrowPos.y = 0;
    printer->curLine = 0;
    printer->unkArraySize = 0;
    printer->maxOption = 0;
    printer->madeChoice = 0;
    printer->curOption = 0;
    printer->selectedOption = 0;
    printer->cancelOption = -1;
    printer->windowState = MSG_WINDOW_STATE_DONE;
    printer->stateFlags = 0;
    printer->delayFlags = 0;
    printer->closedWritebackBool = NULL;
    printer->printBufferPos = 0;
    printer->srcBufferPos = 0;
    printer->font = 0;
    printer->fontVariant = 0;
    printer->effectFrameCounter = 0;
    printer->curLinePos = 0;
    printer->unk_46C = 0;
    printer->lineCount = 0;

    for (i = 0; i < ARRAY_COUNT(printer->animTimers); i++) {
        printer->curAnimFrame[i] = 0;
        printer->animTimers[i] = -1;
    }

    printer->initOpenPos.x = 160;
    printer->initOpenPos.y = 40;
    printer->speechSoundType = -1;
    printer->speechPan = 64;
    printer->volume = 75;
    printer->rewindArrowCounter = 0;
    printer->style = 0;
    printer->fadeInCounter = 0;
    printer->openStartPos.x = 0;
    printer->openStartPos.y = 0;
    printer->fadeOutCounter = 0;
    printer->windowSize.y = 0;
    printer->windowSize.x = 0;
    printer->speechPitchShift = 0;
    printer->speechSoundIDA = 0;
    printer->speechSoundIDB = 0;
    printer->varBufferReadPos = 0;
    printer->curImageIndex = 0;
    printer->varImageScreenPos.x = 0;
    printer->varImageScreenPos.y = 0;
    printer->varImgHasBorder = 0;
    printer->varImgFinalAlpha = 255;
    printer->varImageDisplayState = 0;
    printer->varImageFadeTimer = 0;
    printer->letterBackgroundImg = NULL;
    printer->letterBackgroundPal = NULL;
    printer->letterContentImg = NULL;
    printer->letterContentPal = NULL;
    printer->sizeScale = 1.0f;
}

void dma_load_msg(u32 msgID, void* dest) {
    u8* addr = (u8*) MSG_ROM_START + (msgID >> 14); // (msgID >> 16) * 4
    u8* offset[2]; // start, end

    dma_copy(addr, addr + 4, &offset[0]); // Load section offset

    addr = MSG_ROM_START + offset[0] + (msgID & 0xFFFF) * 4;
    dma_copy(addr, addr + 8, &offset); // Load message start and end offsets

    // Load the msg data
    dma_copy(MSG_ROM_START + offset[0], MSG_ROM_START + offset[1], dest);
}

s8* load_message_to_buffer(s32 msgID) {
    s8* prevBufferPos;

    dma_load_msg(msgID, &gMessageBuffers[gNextMessageBuffer]);
    prevBufferPos = gMessageBuffers[gNextMessageBuffer];

    gNextMessageBuffer++;
    if (gNextMessageBuffer >= ARRAY_COUNT(gMessageBuffers)) {
        gNextMessageBuffer = 0;
    }

    return prevBufferPos;
}

MessagePrintState* msg_get_printer_for_msg(s32 msgID, s32* donePrintingWriteback) {
    return _msg_get_printer_for_msg(msgID, donePrintingWriteback, 0);
}

MessagePrintState* _msg_get_printer_for_msg(s32 msgID, s32* donePrintingWriteback, s32 arg2) {
    MessagePrintState* printer;
    s8* srcBuffer;
    s32 height;
    s32 width;
    s32 maxLineChars;
    s32 numLines;
    s32 maxLinesPerPage;
    s32 i;

    if (msgID == MSG_NONE) {
        return NULL;
    }

    srcBuffer = (s8*) msgID;
    if (msgID >= 0) {
        srcBuffer = load_message_to_buffer((s32)srcBuffer);
    }

    for (i = 0; i < ARRAY_COUNT(gMessagePrinters); i++) {
        printer = &gMessagePrinters[i];

        if (!(printer->stateFlags & MSG_STATE_FLAG_2)) {
            initialize_printer(printer, 1, arg2);
            printer->windowState = MSG_WINDOW_STATE_INIT;
            printer->srcBuffer = srcBuffer;
            printer->msgID = msgID;
            printer->stateFlags |= MSG_STATE_FLAG_2;
            get_msg_properties(msgID, &height, &width, &maxLineChars, &numLines, &maxLinesPerPage, NULL, 0);
            printer->msgHeight = height;
            printer->msgWidth = width;
            printer->maxLineChars = maxLineChars;
            printer->numLines = numLines;
            printer->maxLinesPerPage = maxLinesPerPage;
            printer->closedWritebackBool = donePrintingWriteback;

            if (donePrintingWriteback != NULL) {
                *donePrintingWriteback = FALSE;
            }
            return printer;
        }
    }

    return NULL;
}

s32 msg_printer_load_msg(s32 msgID, MessagePrintState* printer) {
    s8* buffer;

    if (msgID >= 0) {
        buffer = load_message_to_buffer(msgID);
    } else {
        buffer = (s8*) msgID;
    }

    printer->srcBuffer = buffer;
    printer->srcBufferPos = 0;
    printer->stateFlags &= ~MSG_STATE_FLAG_40;
    return 1;
}

void msg_printer_set_origin_pos(MessagePrintState* msgPrintState, s32 x, s32 y) {
    msgPrintState->initOpenPos.x = x;
    msgPrintState->initOpenPos.y = y;

    if (msgPrintState->initOpenPos.x < 0) {
        msgPrintState->initOpenPos.x = 0;
    }
    if (msgPrintState->initOpenPos.x > SCREEN_WIDTH) {
        msgPrintState->initOpenPos.x = SCREEN_WIDTH;
    }
    if (msgPrintState->initOpenPos.y < 0) {
        msgPrintState->initOpenPos.y = 0;
    }
    if (msgPrintState->initOpenPos.y > 220) {
        msgPrintState->initOpenPos.y = 220;
    }
}

s32 cancel_message(MessagePrintState* msgPrintState) {
    if (!(msgPrintState->stateFlags & MSG_STATE_FLAG_2)) {
        return FALSE;
    }

    msgPrintState->stateFlags |= MSG_STATE_FLAG_1;
    return TRUE;
}

void set_message_images(MessageImageData* images) {
    *gMsgVarImages = images;
}

void set_message_msg(s32 msgID, s32 index) {
    u8* mallocSpace = NULL;
    s32 i;
    u8* msgVars;

    if (msgID >= 0) {
        mallocSpace = general_heap_malloc(0x400);
        dma_load_msg(msgID, mallocSpace);
        msgID = (s32)mallocSpace;
    }

    i = 0;
    msgVars = gMessageMsgVars[index];
    while (TRUE) {
        msgVars[i] = ((u8*)msgID)[i];
        if (((u8*)msgID)[i] == MSG_CHAR_READ_END) {
            break;
        }

        if (++i >= 32) {
            msgVars[i - 1] = MSG_CHAR_READ_END;
            break;
        }
    }

    if (mallocSpace != NULL) {
        general_heap_free(mallocSpace);
    }
}

void set_message_value(s32 value, s32 index) {
    s8 strBuffer[ARRAY_COUNT(gMessageMsgVars[index])];
    s8* bufferIt;
    s32 i;

    int_to_string(value, strBuffer, 10);

    for (i = 0, bufferIt = strBuffer; i < ARRAY_COUNT(gMessageMsgVars[index]) - 1; i++) {
        s8 thisChar = bufferIt[i];

        if (thisChar == 0) {
            break;
        }
        gMessageMsgVars[index][i] = thisChar - '0' + MSG_CHAR_DIGIT_0;
    }
    gMessageMsgVars[index][i] = MSG_CHAR_READ_END;
}

void close_message(MessagePrintState* msgPrintState) {
    msgPrintState->stateFlags &= ~MSG_STATE_FLAG_40;
}

s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags) {
    f32 charWidth;

    if (character >= MSG_CONTROL_CHAR
            && (character != MSG_CHAR_READ_SPACE
            && character != MSG_CHAR_READ_FULL_SPACE
            && character != MSG_CHAR_READ_HALF_SPACE)) {
        return 0;
    }

#if VERSION_IQUE
    if (character >= 0x5F && character<=0x8F) {
        charWidth = 16.0;
        return charWidth * msgScale;
    }
#endif

    if (overrideCharWidth != 0) {
        charWidth = overrideCharWidth;
    } else if (flags != 0) {
        u8* charWidthTable = MsgCharsets[charset]->rasters[variation].charWidthTable;

        if (charWidthTable != NULL
                && character != MSG_CHAR_READ_SPACE
                && character != MSG_CHAR_READ_FULL_SPACE
                && character != MSG_CHAR_READ_HALF_SPACE) {
            charWidth = charWidthTable[character];
        } else {
            charWidth = MsgCharsets[charset]->rasters[variation].monospaceWidth;
        }
    } else {
        charWidth = MsgCharsets[charset]->rasters[variation].monospaceWidth;
    }

    if (character == MSG_CHAR_READ_SPACE) {
        return charWidth * msgScale * 0.6;
    }
    if (character == MSG_CHAR_READ_FULL_SPACE) {
        f64 retWidth = charWidth * msgScale;
        return retWidth;
    }
    if (character == MSG_CHAR_READ_HALF_SPACE) {
        return charWidth * msgScale * 0.5;
    }
    if (character >= MSG_CONTROL_CHAR) {
        return 0;
    }
    return charWidth * msgScale;
}

s32 msg_get_draw_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u16 flags) {
    f32 baseWidth;

    if (character >= MSG_CONTROL_CHAR
            && (character != MSG_CHAR_PRINT_SPACE
            && character != MSG_CHAR_PRINT_FULL_SPACE
            && character != MSG_CHAR_PRINT_HALF_SPACE)) {
        return 0;
    }

    if (overrideCharWidth != 0) {
        baseWidth = overrideCharWidth;
    } else if (flags & MSG_PRINT_FLAG_100) {
        u8* charWidthTable = MsgCharsets[charset]->rasters[variation].charWidthTable;

        if (charWidthTable != NULL
                && character != MSG_CHAR_PRINT_SPACE
                && character != MSG_CHAR_PRINT_FULL_SPACE
                && character != MSG_CHAR_PRINT_HALF_SPACE) {
            baseWidth = charWidthTable[character];
        } else {
            baseWidth = MsgCharsets[charset]->rasters[variation].monospaceWidth;
        }
    } else {
        baseWidth = MsgCharsets[charset]->rasters[variation].monospaceWidth;
    }

    if (character == MSG_CHAR_PRINT_SPACE) {
        return baseWidth * msgScale * 0.6;
    }
    if (character == MSG_CHAR_PRINT_FULL_SPACE) {
        f64 charWidth = baseWidth * msgScale;
        return charWidth;
    }
    if (character == MSG_CHAR_PRINT_HALF_SPACE) {
        return baseWidth * msgScale * 0.5;
    }
    if (character >= MSG_CONTROL_CHAR) {
        return 0;
    }
    return baseWidth * msgScale;
}

void get_msg_properties(s32 msgID, s32* height, s32* width, s32* maxLineChars, s32* numLines, s32* maxLinesPerPage, s32* numSpaces, u16 charset) {
    u8* message;
    s32 i;
    u16 pageCount;
    s32 linesOnPage;
    u8 stop;
    s32 lineWidth;
    s32 charCount;
    u16 lineIndex;
    s32 msgStyle;
    s32 functionCode;
    u8 packedScaleY;
    f32 scale;
    s32 temp;

    u16 lineWidths[32];
    u16 lineCharNumbers[32];
    u16 linesPerPage[32];
    s32 lineCount;
    u16 varIndex;
    u16 font;
    u8* buffer;
    u16 maxLineWidth;
    u16 maxCharsPerLine;
    u16 maxLinesOnPage;
    u16 spaceCount;
    u16 endl;

    u8 c;
    u8 prevChar;

    scale = 1.0f;
    c = 0;
    lineIndex = 0;
    pageCount = 0;
    varIndex = 0;
    font = 0;
    buffer = NULL;
    maxLineWidth = 0;
    maxCharsPerLine = 0;
    maxLinesOnPage = 0;
    spaceCount = 0;

    if (msgID == MSG_NONE) {
        return;
    }

    if (msgID >= 0) {
        buffer = general_heap_malloc(0x400);
        dma_load_msg(msgID, buffer);
        message = buffer;
    } else {
        message = (u8*)msgID;
    }

    if (charset & 1) {
        font = 1;
    }

    i = 0;
    stop = FALSE;
    lineWidth = 0;
    linesOnPage = 0;
    charCount = 0;
    endl = TRUE;
    lineCount = 0;

    do {
        prevChar = c;
        c = message[i++];
        switch (c) {
            case MSG_CHAR_READ_VARIANT0:
            case MSG_CHAR_READ_VARIANT1:
            case MSG_CHAR_READ_VARIANT2:
            case MSG_CHAR_READ_VARIANT3:
                varIndex = c - MSG_CHAR_READ_VARIANT0;
                break;
            case MSG_CHAR_READ_PAUSE:
                i++;
                break;
            case MSG_CHAR_READ_WAIT:
            case MSG_CHAR_READ_NEXT:
                if (linesOnPage != 0) {
                    linesPerPage[pageCount] = linesOnPage;
                    pageCount++;
                    if (pageCount >= 32) {
                        stop = 1;
                    }
                    linesOnPage = 0;
                }
                break;
            case MSG_CHAR_READ_ENDL:
                lineWidths[lineIndex] = lineWidth;
                lineCharNumbers[lineIndex] = charCount;
                lineIndex++;
                if (lineIndex >= 32) {
                    stop = 1;
                }
                lineWidth = 0;
                charCount = 0;
                endl = TRUE;
                break;
            case MSG_CHAR_READ_STYLE:
                msgStyle = message[i++];
                switch (msgStyle) {
                    case MSG_STYLE_CHOICE:
                        i += 4;
                        break;
                    case MSG_STYLE_POSTCARD:
                        i++;
                        break;
                    case MSG_STYLE_RIGHT:
                    case MSG_STYLE_LEFT:
                    case MSG_STYLE_CENTER:
                    case MSG_STYLE_TATTLE:
                    case MSG_STYLE_INSPECT:
                    case MSG_STYLE_SIGN:
                    case MSG_STYLE_LAMPPOST:
                    case MSG_STYLE_POPUP:
                    case MSG_STYLE_B:
                        break;
                }
                break;
            case MSG_CHAR_READ_END:
                lineWidths[lineIndex] = lineWidth;
                lineCharNumbers[lineIndex] = charCount;
                lineIndex++;
                stop = TRUE;
                break;
            case MSG_CHAR_READ_FUNCTION:
                functionCode = message[i++];
                switch (functionCode) {
                    case MSG_READ_FUNC_FONT:
                        font = message[i++];
                        break;
                    case MSG_READ_FUNC_RESET_GFX:
                    case MSG_READ_FUNC_NO_SKIP:
                    case MSG_READ_FUNC_INPUT_OFF:
                    case MSG_READ_FUNC_INPUT_ON:
                    case MSG_READ_FUNC_DELAY_OFF:
                    case MSG_READ_FUNC_DELAY_ON:
                    case MSG_READ_FUNC_SAVE_POS:
                    case MSG_READ_FUNC_RESTORE_POS:
                    case MSG_READ_FUNC_SAVE_COLOR:
                    case MSG_READ_FUNC_RESTORE_COLOR:
                    case MSG_READ_FUNC_ENABLE_CDOWN_NEXT:
                        break;
                    default:
                        stop = TRUE;
                        break;
                    case MSG_READ_FUNC_CUSTOM_VOICE:
                        i++;
                        // fallthrough
                    temp = 4;
                    case MSG_READ_FUNC_IMAGE:
                        i += temp;
                        // fallthrough
                    case MSG_READ_FUNC_ANIM_SPRITE:
                    case MSG_READ_FUNC_ANIM_DELAY:
                        i++;
                        // fallthrough
                    case MSG_READ_FUNC_SPEED:
                    case MSG_READ_FUNC_SET_X:
                    case MSG_READ_FUNC_ANIM_LOOP:
                        i++;
                        // fallthrough
                    case MSG_READ_FUNC_COLOR:
                    case MSG_READ_FUNC_SPACING:
                    case MSG_READ_FUNC_SCROLL:
                    case MSG_READ_FUNC_SET_Y:
                    case MSG_READ_FUNC_RIGHT:
                    case MSG_READ_FUNC_DOWN:
                    case MSG_READ_FUNC_UP:
                    case MSG_READ_FUNC_INLINE_IMAGE:
                    case MSG_READ_FUNC_ITEM_ICON:
                    case MSG_READ_FUNC_HIDE_IMAGE:
                    case MSG_READ_FUNC_ANIM_DONE:
                    case MSG_READ_FUNC_CURSOR:
                    case MSG_READ_FUNC_END_CHOICE:
                    case MSG_READ_FUNC_SET_CANCEL:
                    case MSG_READ_FUNC_OPTION:
                    case MSG_READ_FUNC_END_FX:
                    case MSG_READ_FUNC_SET_REWIND:
                    case MSG_READ_FUNC_VOICE:
                        i++;
                        break;
                    case MSG_READ_FUNC_CENTER_X:
                        if (message[i] == 0) {
                            stop = TRUE;
                        }
                        i++;
                        break;
                    case MSG_READ_FUNC_YIELD:
                        if (message[i] == MSG_CHAR_READ_END) {
                            stop = TRUE;
                        }
                        break;
                    case MSG_READ_FUNC_SIZE:
                        packedScaleY = message[i + 1];
                        i += 2;
                        scale = (f32)(packedScaleY >> 4) + ((packedScaleY & 0xF) * 0.0625f);
                        break;
                    case MSG_READ_FUNC_SIZE_RESET:
                        scale = 1.0f;
                        break;
                    case MSG_READ_FUNC_START_FX:
                        switch (message[i++]) {
                            case MSG_FX_STATIC:
                            case MSG_FX_BLUR:
                            case MSG_FX_DITHER_FADE:
                                i++;
                                break;
                            case MSG_FX_SHAKE:
                            case MSG_FX_WAVE:
                            case MSG_FX_NOISE_OUTLINE:
                            case MSG_FX_RAINBOW:
                            case MSG_FX_GLOBAL_WAVE:
                            case MSG_FX_GLOBAL_RAINBOW:
                            case MSG_FX_RISE_PRINT:
                            case MSG_FX_GROW_PRINT:
                            case MSG_FX_SIZE_JITTER:
                            case MSG_FX_SIZE_WAVE:
                            case MSG_FX_DROP_SHADOW:
                                break;
                        }
                        break;
                    case MSG_READ_FUNC_VAR:
                        lineWidth += get_msg_width((s32)gMessageMsgVars[message[i++]], 0);
                        break;
                }
                break;
            case MSG_CHAR_READ_UNK_CHAR_FA:
                break;
            case MSG_CHAR_READ_SPACE:
            case MSG_CHAR_READ_FULL_SPACE:
            case MSG_CHAR_READ_HALF_SPACE:
                spaceCount++;
                // fallthrough
            default:
                if (endl) {
                    lineCount++;
                    linesOnPage++;
                    endl = FALSE;
                }

#if VERSION_IQUE
                if (prevChar >= 0x5f && prevChar <= 0x8F) {
                    break;
                }
#endif

                lineWidth += msg_get_print_char_width(c, font, varIndex, scale, 0, 1);
                charCount++;
                break;
        }
    } while (!stop);

    if (buffer != NULL) {
        general_heap_free(buffer);
    }

    for (i = 0; i < lineIndex; i++) {
        if (maxLineWidth < lineWidths[i]) {
            maxLineWidth = lineWidths[i];
        }
        if (maxCharsPerLine < lineCharNumbers[i]) {
            maxCharsPerLine = lineCharNumbers[i];
        }
    }

    if (pageCount == 0) {
        maxLinesOnPage = linesOnPage;
    } else {
        for (i = 0; i < pageCount; i++) {
            if (maxLinesOnPage < linesPerPage[i]) {
                maxLinesOnPage = linesPerPage[i];
            }
        }
    }

    if (width != NULL) {
        *width = maxLineWidth;
    }
    if (height != NULL) {
        *height = lineCount * MsgCharsets[font]->newLineY;
    }
    if (maxLineChars != NULL) {
        *maxLineChars = maxCharsPerLine;
    }
    if (numLines != NULL) {
        *numLines = lineCount;
    }
    if (maxLinesPerPage != NULL) {
        *maxLinesPerPage = maxLinesOnPage;
    }
    if (numSpaces != NULL) {
        *numSpaces = spaceCount;
    }
}

static const f32 padding = 0.0f;

s32 get_msg_width(s32 msgID, u16 charset) {
    s32 width;

    get_msg_properties(msgID, NULL, &width, NULL, NULL, NULL, NULL, charset);
    return width;
}

s32 get_msg_lines(s32 msgID) {
    s32 numLines;

    get_msg_properties(msgID, NULL, NULL, NULL, &numLines, NULL, NULL, 0);
    return numLines;
}

void draw_msg(s32 msgID, s32 posX, s32 posY, s32 opacity, s32 palette, u8 style) {
    MessagePrintState stackPrinter;
    MessagePrintState* printer;
    u16 bufferPos;
    s8* mallocSpace;
    s32 charset;
    u16 flags;
    s32 width;

    flags = 0;
    bufferPos = 0;
    mallocSpace = NULL;
    charset = 0;

    if (msgID != 0) {
        if (style & DRAW_MSG_STYLE_MENU) {
            flags = 2;
            charset = 1;
        }

        if (opacity < 0xFF) {
            flags |= 1;
        }

        printer = &stackPrinter;
        initialize_printer(printer, 1, 0);

        if (msgID < 0) {
            printer->srcBuffer = (u8*)msgID;
        } else {
            mallocSpace = general_heap_malloc(0x400);
            dma_load_msg(msgID, mallocSpace);
            printer->srcBuffer = mallocSpace;
            get_msg_properties((s32) printer->srcBuffer, 0, &width, 0, 0, 0, 0, charset);
            printer->msgWidth = width;
        }

        if (palette >= 0) {
            printer->printBuffer[bufferPos++] = MSG_CHAR_PRINT_FUNCTION;
            printer->printBuffer[bufferPos++] = MSG_PRINT_FUNC_COLOR;
            printer->printBuffer[bufferPos++] = palette;
            printer->printBufferPos += 3;
        }

        if (style & DRAW_MSG_STYLE_WAVY) {
            printer->printBuffer[bufferPos++] = MSG_CHAR_PRINT_FUNCTION;
            printer->printBuffer[bufferPos++] = MSG_PRINT_FUNC_START_FX;
            printer->printBuffer[bufferPos++] = MSG_FX_GLOBAL_WAVE;
            printer->printBufferPos += 3;
        }

        if (style & DRAW_MSG_STYLE_RAINBOW) {
            printer->printBuffer[bufferPos++] = MSG_CHAR_PRINT_FUNCTION;
            printer->printBuffer[bufferPos++] = MSG_PRINT_FUNC_START_FX;
            printer->printBuffer[bufferPos++] = MSG_FX_GLOBAL_RAINBOW;
            printer->printBufferPos += 3;
        }

        if (style & DRAW_MSG_STYLE_DROP_SHADOW) {
            printer->printBuffer[bufferPos++] = MSG_CHAR_PRINT_FUNCTION;
            printer->printBuffer[bufferPos++] = MSG_PRINT_FUNC_START_FX;
            printer->printBuffer[bufferPos++] = MSG_FX_DROP_SHADOW;
            printer->printBufferPos += 3;
        }

        msg_copy_to_print_buffer(printer, 10000, 1);
        appendGfx_message(printer, (s16)posX, (s16)posY, 0, 0, flags, opacity & 0xFF);

        if (mallocSpace != NULL) {
            general_heap_free(mallocSpace);
        }
    }
}

void msg_update_rewind_arrow(s32 printerIndex) {
    MessagePrintState* printer = &gMessagePrinters[printerIndex];
    f32 angle = 0.0f;
    f32 scale = 1.0f;
    f32 colorG = 255.0f;
    f32 colorR = 255.0f;
    f32 colorB = 255.0f;
    Matrix4f sp18;
    Matrix4f sp58;
    f32 temp;

    gDPPipeSync(gMainGfxPos++);
    gSPDisplayList(gMainGfxPos++, D_8014C2D8);

    switch (printer->rewindArrowAnimState) {
        case REWIND_ARROW_STATE_INIT:
            printer->rewindArrowCounter = 0;
            printer->rewindArrowSwingPhase = 0;
            printer->rewindArrowAnimState = REWIND_ARROW_STATE_GROW;
            // fallthrough
        case REWIND_ARROW_STATE_GROW:
            temp = printer->rewindArrowCounter;
            scale = temp * 0.2 + 0.5;
            if (++printer->rewindArrowCounter >= 4) {
                printer->rewindArrowCounter = 0;
                printer->rewindArrowAnimState = REWIND_ARROW_STATE_NEUTRAL;
            }
            break;
        case REWIND_ARROW_STATE_NEUTRAL:
            if (++printer->rewindArrowCounter >= 25) {
                printer->rewindArrowCounter = 0;
                printer->rewindArrowAnimState = REWIND_ARROW_STATE_CHANGE_COLOR;
            }
            break;
        case REWIND_ARROW_STATE_CHANGE_COLOR:
            colorR = update_lerp(EASING_LINEAR, 255.0f, 224.0f, printer->rewindArrowCounter, 15);
            colorG = update_lerp(EASING_LINEAR, 255.0f, 224.0f, printer->rewindArrowCounter, 15);
            colorB = update_lerp(EASING_LINEAR, 255.0f, 208.0f, printer->rewindArrowCounter, 15);
            if (++printer->rewindArrowCounter >= 15) {
                printer->rewindArrowCounter = 0;
                printer->rewindArrowAnimState = REWIND_ARROW_STATE_CHANGE_COLOR_BACK;
            }
            break;
        case REWIND_ARROW_STATE_CHANGE_COLOR_BACK:
            colorR = update_lerp(EASING_LINEAR, 224.0f, 255.0f, printer->rewindArrowCounter, 15);
            colorG = update_lerp(EASING_LINEAR, 224.0f, 255.0f, printer->rewindArrowCounter, 15);
            colorB = update_lerp(EASING_LINEAR, 208.0f, 255.0f, printer->rewindArrowCounter, 15);
            if (++printer->rewindArrowCounter >= 15) {
                printer->rewindArrowCounter = 0;
                printer->rewindArrowAnimState = REWIND_ARROW_STATE_NEUTRAL;
            }
            break;
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, colorR, colorG, colorB, 255);

    if (printer->rewindArrowAnimState == REWIND_ARROW_STATE_NEUTRAL ||
        printer->rewindArrowAnimState == REWIND_ARROW_STATE_CHANGE_COLOR ||
        printer->rewindArrowAnimState == REWIND_ARROW_STATE_CHANGE_COLOR_BACK) {
        angle = cosine(printer->rewindArrowSwingPhase) * 30.0f;
        printer->rewindArrowSwingPhase += 15;
        if (printer->rewindArrowSwingPhase >= 360) {
            printer->rewindArrowSwingPhase -= 360;
        }
    }

    guTranslateF(sp18, printer->rewindArrowPos.x + 12, -(printer->rewindArrowPos.y + 12), 0);
    if (angle != 0.0) {
        guRotateF(sp58, angle, 0, 0, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
    }
    if (scale != 1.0) {
        guScaleF(sp58, scale, scale, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
    }

    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPLoadTextureTile(gMainGfxPos++, ui_msg_star_png, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, 15, 17, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiTile_4b(gMainGfxPos++, ui_msg_star_silhouette_png, 0x0100, 1, G_IM_FMT_I, 16, 0, 0, 0, 15, 18, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gMainGfxPos++, gRewindArrowQuad, 4, 0);
    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
}

void msg_draw_rewind_arrow(s32 printerIndex) {
    MessagePrintState* printer = &gMessagePrinters[printerIndex];

    if (printer->rewindArrowCounter < 6) {
        draw_ci_image_with_clipping(ui_msg_rewind_arrow_png, 24, 24, G_IM_FMT_CI, G_IM_SIZ_4b, ui_msg_rewind_arrow_pal, printer->rewindArrowPos.x,
                                    printer->rewindArrowPos.y, 10, 10, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, 255);
    }

    printer->rewindArrowCounter++;
    if (printer->rewindArrowCounter >= 12) {
        printer->rewindArrowCounter = 0;
    }
}

void msg_draw_choice_pointer(MessagePrintState* printer) {
    s32 pointerAlpha = 255;
    s32 shadowAlpha = 72;
    s32 posInterpPhase = gGameStatusPtr->frameCounter % 360;
    s32 posX, posY;

    if (printer->windowState == MSG_WINDOW_STATE_WAITING_FOR_CHOICE || (printer->stateFlags & MSG_STATE_FLAG_20000)) {
        posX = printer->windowOffsetPos.x + printer->windowBasePos.x + printer->cursorPosX[printer->selectedOption];
        posY = printer->windowOffsetPos.y + printer->windowBasePos.y + printer->cursorPosY[printer->selectedOption];
    } else {
        s32 baseX, baseY, targetX, targetY;
        f32 moveToTargetAlpha = (f32)(printer->scrollingTime + 1.0) / 6.0;

        baseX = printer->windowOffsetPos.x + printer->windowBasePos.x + printer->cursorPosX[printer->selectedOption];
        targetX = printer->windowOffsetPos.x + printer->windowBasePos.x + printer->cursorPosX[printer->targetOption];
        posX = baseX + (targetX - baseX) * moveToTargetAlpha;

        baseY = printer->windowOffsetPos.y + printer->windowBasePos.y + printer->cursorPosY[printer->selectedOption];
        targetY = printer->windowOffsetPos.y + printer->windowBasePos.y + printer->cursorPosY[printer->targetOption];
        posY = baseY + (targetY - baseY) * moveToTargetAlpha;
    }

    posY += 1;
    posX += (cosine(posInterpPhase * 38 + 270) + 1.0) * 0.5 * 3.2;
    posX -= 2;

    if (printer->stateFlags & MSG_STATE_FLAG_20000) {
        u32 opacity;
        opacity = 255.0 - printer->fadeOutCounter * 46.0;
        pointerAlpha = opacity;
        opacity = 72.0 - printer->fadeOutCounter * 14.4;
        shadowAlpha = opacity;
    }

    gDPPipeSync(gMainGfxPos++);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gMainGfxPos++, 0, ui_point_right_pal);
    gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_07, PM_CC_07);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 40, 40, 40, shadowAlpha);
    draw_image_with_clipping(ui_point_right_png, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, posX + 2, posY + 2, 10, 10, 300, 220);
    draw_ci_image_with_clipping(ui_point_right_png, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, ui_point_right_pal, posX, posY, 20, 20, 300, 200, pointerAlpha);
}

void draw_digit(IMG_PTR img, s32 charset, s32 posX, s32 posY) {
    MessageNumber* num = &gMsgNumbers[charset];

    gDPLoadTextureTile_4b(gMainGfxPos++,
        img, G_IM_FMT_CI,
        num->texWidth , num->texHeight,
        0, 0,
        num->texWidth - 1, num->texHeight - 1,
        0,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
        G_TX_NOMASK, G_TX_NOMASK,
        G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gMainGfxPos++,
        4 * posX, 4 * posY,
        4 * (posX + num->texWidth), 4 * (posY + num->texHeight),
        G_TX_RENDERTILE,
        0, 0,
        1 << 10, 1 << 10);
}

void draw_number(s32 value, s32 x, s32 y, s32 charset, s32 palette, s32 opacity, u16 style) {
    u8 valueStr[24];
    u8 digits[24];
    s32 digitPosX[24];
    s32 i;
    s32 count;
    s32 posX;
    IMG_PTR raster = gMsgNumbers[charset].rasters;
    s32 texSize = gMsgNumbers[charset].texSize;

    y -= 2;
    if (y < 0 || y > 240) {
        return;
    }

    int_to_string(value, valueStr, 10);

    for (i = 0; i < 10; i++) {
        u8 digit;
        if (valueStr[i] == '\0') {
            break;
        }

        digit = valueStr[i] - '0';
        if (digit < 10){
            digits[i] = digit;
        }
    }
    posX = x;
    count = i;

    gSPDisplayList(gMainGfxPos++, gMsgDlistInitDrawNumber);

    if (style & DRAW_NUMBER_STYLE_ALIGN_RIGHT) {
        for (i = count - 1; i >= 0; i--) {
            if (style & DRAW_NUMBER_STYLE_MONOSPACE) {
                posX -= gMsgNumbers[charset].fixedWidth;
            } else {
                posX -= gMsgNumbers[charset].digitWidth[digits[i]];
            }
            digitPosX[i] = posX;
        }
    } else {
        for (i = 0; i < count; i++) {
            digitPosX[i] = posX;
            if (style & DRAW_NUMBER_STYLE_MONOSPACE) {
                posX += gMsgNumbers[charset].fixedWidth;
            } else {
                posX += gMsgNumbers[charset].digitWidth[digits[i]];
            }
        }
    }

    if (style & DRAW_NUMBER_STYLE_DROP_SHADOW) {
        for (i = 0; i < count; i++) {
            gDPPipeSync(gMainGfxPos++);
            gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetCombineMode(gMainGfxPos++, PM_CC_07, PM_CC_07);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 40, 40, 40, 72);
            draw_digit(raster + digits[i] * texSize, charset, digitPosX[i] + 2, y + 2);
            gDPPipeSync(gMainGfxPos++);
        }
    }

    if (opacity == 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
        gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gMainGfxPos++, PM_CC_01, PM_CC_01);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, opacity);
    }

    gDPLoadTLUT_pal16(gMainGfxPos++, 0, D_802F4560[palette]);
    for (i = 0; i < count; i++) {
        posX = digitPosX[i];
        if (posX > 0 && posX < 320) {
            draw_digit(raster + digits[i] * texSize, charset, posX, y);
        }
    }
    gDPPipeSync(gMainGfxPos++);
}

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

#if VERSION_IQUE
INCLUDE_ASM(s32, "msg", appendGfx_message);
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
                msg_drawState->nextPos[1] += (s32)((msg_drawState->msgScale.y * MsgCharsets[msg_drawState->font]->newLineY) +
                                                   MsgStyleVerticalLineOffsets[printer->style]);
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
                            straightWidth = 218;
                            printer->windowBasePos.x = 22;
                            printer->windowBasePos.y = 13;
                            printer->windowSize.x = 296;
                            printer->windowSize.y = 68;
                            msg_drawState->textStartPos[0] = 26;
                            msg_drawState->textStartPos[1] = 6;
                            printer->rewindArrowPos.x = 276;
                            printer->rewindArrowPos.y = 57;
                            curveWidth = 32;
                            height = 68;
                        } else {
                            straightWidth = 218;

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

                            straightWidth = printer->msgWidth;
                            if (straightWidth > 256) {
                                straightWidth = 256;
                            }
                            if (straightWidth < 70) {
                                straightWidth = 70;
                            }
                            straightWidth -= 12;

                            printer->windowSize.x = straightWidth + (curveWidth * 2);

                            height = (printer->maxLinesPerPage * 14) + 16;
                            if (height > 68) {
                                height = 68;
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
                        msg_drawState->textStartPos[1] = 3;
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
                        msg_drawState->textStartPos[1] = 11;
                        printer->windowBasePos.x = 20;
                        printer->windowBasePos.y = 28;
                        printer->windowSize.x = 280;
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
                        msg_drawState->clipX[0] = 34;
                        msg_drawState->clipY[0] = 40;
                        msg_drawState->clipX[1] = 283;
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
                        draw_ci_image_with_clipping(ui_msg_sign_corner_topleft_png, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, signPalette, 20, 28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(ui_msg_sign_corner_topright_png, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, signPalette, 284, 28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(ui_msg_sign_corner_bottomleft_png, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, signPalette, 20, printer->windowSize.y + 12, 10, 10, 310, 230,
                                                    temp_s1_5);
                        draw_ci_image_with_clipping(signRaster, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, signPalette, 284, printer->windowSize.y + 12, 10, 10, 310, 230, temp_s1_5);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_side_top_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, 0x0090, 0x0070, 0x0470, 0x00B0, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_side_left_png, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, 0x0050, 0x00B0, 0x0090, (printer->windowSize.y + 12) * 4, G_TX_RENDERTILE, 0, 0,
                                            0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_side_right_png, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, 0x0470, 0x00B0, 0x04B0, (printer->windowSize.y + 12) * 4, G_TX_RENDERTILE, 0, 0,
                                            0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_side_bottom_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, 0x0090, (printer->windowSize.y + 12) * 4, 0x0470, (printer->windowSize.y + 28) * 4,
                                            G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMainGfxPos++, ui_msg_sign_fill_png, G_IM_FMT_CI, 8, 0, 0, 0, 7, 7, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 3, 3, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMainGfxPos++, 0x0090, 0x00B0, 0x0470, (printer->windowSize.y + 12) * 4, G_TX_RENDERTILE, 0, 0,
                                            0x0400, 0x0400);
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
                        msg_drawState->textStartPos[1] = 4;
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
                        msg_drawState->textStartPos[1] = -2;
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
                    charPosX = (u16) msg_drawState->nextPos[0] + ((u16) printer->windowBasePos.x + (u16) posX);
                } else {
                    charPosX = (u16) msg_drawState->nextPos[0] + ((u16) msg_drawState->textStartPos[0] + ((u16) printer->windowBasePos.x +
                               (u16) posX));
                }

                msgCharset = MsgCharsets[msg_drawState->font];
                charPosY = (s8) msgCharset->rasters[msg_drawState->fontVariant].baseHeightOffset + (msg_drawState->nextPos[1] +
                           (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY)) - additionalOffsetY);

                if ((sp8E != 0) &&
                    (charPosX < msg_drawState->clipX[1]) &&
                    (charPosY < msg_drawState->clipY[1]) &&
                    (msg_drawState->clipX[0] < charPosX + (s32)(msg_drawState->msgScale.x *
                            msgCharset->rasters[msg_drawState->fontVariant].monospaceWidth)) &&
                    (msg_drawState->clipY[0] < charPosY + (s32)(msg_drawState->msgScale.y * msgCharset->newLineY +
                            MsgStyleVerticalLineOffsets[printer->style]))) {
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

#if VERSION_IQUE
INCLUDE_ASM(s32, "msg", msg_draw_char);
#else
void msg_draw_char(MessagePrintState* printer, MessageDrawState* drawState, s32 charIndex, s32 palette, s32 posX, s32 posY) {
    MessageCharset* messageCharset = MsgCharsets[drawState->font];
    s32 fontVariant = drawState->fontVariant;

    s32 clipUly = drawState->clipY[0];
    s32 clipLry = drawState->clipY[1];
    s32 clipUlx = drawState->clipX[0];
    s32 clipLrx = drawState->clipX[1];

    s32 rightPosX = posX + (s32)(drawState->charScale.x * messageCharset->texSize.x);
    s32 rightPosY = posY + (s32)(drawState->charScale.y * messageCharset->texSize.y);

    f32 clipOffset;
    s32 texOffsetX;
    s32 texOffsetY;
    s32 ulx, uly, lrx, lry;
    s32 dsdx, dtdy;

    if (posX >= clipLrx || posY >= clipLry || rightPosX <= clipUlx || rightPosY <= clipUly) {
        return;
    }

    if (posX < clipUlx) {
        clipOffset = abs(posX - clipUlx) / drawState->charScale.x;
        texOffsetX = (f32)((clipOffset + 0.5) * 32.0);
        ulx = clipUlx;
    } else {
        texOffsetX = 0;
        ulx = posX;
    }

    if (posY < clipUly) {
        if (!(printer->stateFlags & MSG_STATE_FLAG_400) || posY < 0) {
            clipOffset = abs(posY - clipUly) / drawState->charScale.y;
            texOffsetY = clipOffset * 32.0f;
            uly = clipUly;
        } else {
            texOffsetY = 0;
            uly = posY;
        }
    } else {
        texOffsetY = 0;
        uly = posY;
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
        gDPLoadTextureBlock_4b(gMainGfxPos++, messageCharset->rasters[fontVariant].raster + messageCharset->charRasterSize * charIndex, G_IM_FMT_CI,
                               messageCharset->texSize.x, messageCharset->texSize.y, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    } else {
        gDPLoadTextureTile_4b(gMainGfxPos++, messageCharset->rasters[fontVariant].raster + messageCharset->charRasterSize * charIndex, G_IM_FMT_CI,
                              messageCharset->texSize.x, messageCharset->texSize.y,
                              0, 0, messageCharset->texSize.x - 1, messageCharset->texSize.y - 1, 0,
                              G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    }
    gSPTextureRectangle(gMainGfxPos++, ulx * 4, uly * 4, lrx * 4, lry * 4, G_TX_RENDERTILE, texOffsetX, texOffsetY,
                        dsdx, dtdy);
}
#endif

void msg_draw_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 posX, u16 posY, u16 sizeX, u16 sizeY) {
    u16 lrX = posX + sizeX;
    u16 lrY = posY + sizeY;

    appendGfx_msg_prim_rect(r, g, b, a, posX, posY, lrX, lrY);
}

void appendGfx_msg_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 ulX, u16 ulY, u16 lrX, u16 lrY) {
    gDPPipeSync(gMainGfxPos++);

    if (a == 255) {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_08, PM_CC_08);
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
    s32 r, g, b;
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
                r = ((((u16*)(ui_msg_palettes[0]))[4] >> 11) & 0x1F) * 8;
                g = ((((u16*)(ui_msg_palettes[0]))[4] >> 6) & 0x1F) * 8;
                b = ((((u16*)(ui_msg_palettes[0]))[4] >> 1) & 0x1F) * 8;
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
