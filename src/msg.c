#include "common.h"
#include "ld_addrs.h"
#include "message_ids.h"
#include "sprite.h"

#include "charset/postcard.png.h"
#include "charset/letter_content_1.png.h"

enum RewindArrowStates {
    REWIND_ARROW_STATE_INIT = 0,
    REWIND_ARROW_STATE_GROW = 1,
    REWIND_ARROW_STATE_NEUTRAL = 2,
    REWIND_ARROW_STATE_CHANGE_COLOR = 3,
    REWIND_ARROW_STATE_CHANGE_COLOR_BACK = 4,
};

#ifdef SHIFT
#define MSG_ROM_START (s32)msg_ROM_START
#elif VERSION_JP
#define MSG_ROM_START 0x1D40000
#else
#define MSG_ROM_START 0x1B83000
#endif

#if VERSION_PAL
#define CHOICE_POINTER_MOVE_RATE 5.0
#else
#define CHOICE_POINTER_MOVE_RATE 6.0
#endif

typedef MessageImageData* MessageImageDataList[1];

s32 D_8014C280[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000 };

#if !VERSION_JP
u8 MessagePlural[] = { MSG_CHAR_LOWER_S, MSG_CHAR_READ_END };

#if VERSION_PAL
u8 MessagePlural_de[] = { MSG_CHAR_LOWER_N, MSG_CHAR_READ_END };
#endif

u8 MessageSingular[] = { MSG_CHAR_READ_ENDL, MSG_CHAR_READ_END };
#endif

#if VERSION_PAL
s32 gCurrentLanguage = 0;

void* D_PAL_8014AE50[] = {
    [LANGUAGE_EN] = msg_pal_en_ROM_START,
    [LANGUAGE_DE] = msg_pal_de_ROM_START,
    [LANGUAGE_FR] = msg_pal_fr_ROM_START,
    [LANGUAGE_ES] = msg_pal_es_ROM_START,
};
#endif

s16 gNextMessageBuffer = 0;

//TODO Vtx
ALIGNED(8) s32 gRewindArrowQuad[] = {
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
    gsDPSetCombineMode(PM_CC_MSG_UP_ARROW, G_CC_PASS2),
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
#if VERSION_IQUE
SHIFT_BSS IMG_BIN D_801544A0[120][128];
#endif

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

#if VERSION_JP
extern IMG_BIN MsgCharImgKana[];
extern IMG_BIN MsgCharImgLatin[];
extern IMG_BIN MsgCharImgMenuKana[];
extern IMG_BIN MsgCharImgMenuLatin[];
#endif

extern s32 gMessageBoxFrameParts[2][16];

extern IMG_BIN ui_point_right_png[];
extern PAL_BIN ui_point_right_pal[];

MessageNumber gMsgNumbers[] = {
#if VERSION_JP
    {
        .rasters = &MsgCharImgKana[0x4910],
        .texSize = 112,
        .texWidth = 16,
        .texHeight = 14,
        .digitWidth = {11, 8, 11, 11, 11, 11, 11, 11, 11, 11},
        .fixedWidth = 11
    }, {
        .rasters = &MsgCharImgMenuKana[0x2EF8],
        .texSize = 72,
        .texWidth = 12,
        .texHeight = 12,
        .digitWidth = {9, 8, 9, 9, 9, 9, 9, 9, 9, 9},
        .fixedWidth = 9
    }
#else
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
#endif
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
#if VERSION_JP
            load_font_data(charset_kana_OFFSET, 0x5710, MsgCharImgKana);
            load_font_data(charset_latin_OFFSET, 0xBD0, MsgCharImgLatin);
            load_font_data(charset_kanji_OFFSET, 0x34F0, MsgCharImgTitle); // huh
            load_font_data(charset_buttons_OFFSET, 0x460, MsgCharImgSubtitle); // what
            load_font_data(charset_menu_kana_OFFSET, 0x37F8, MsgCharImgMenuKana);
            load_font_data(charset_menu_latin_OFFSET, 0x798, MsgCharImgMenuLatin);
#else
            load_font_data(charset_standard_OFFSET, 0x5100, MsgCharImgNormal);
#endif
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
                                printer->stateFlags |= MSG_STATE_FLAG_PRINT_QUICKLY | MSG_STATE_FLAG_SPEAKING | MSG_STATE_FLAG_4;
                            }
                            sfx_play_sound_with_params(SOUND_MSG_SKIP, 0, 0, 0);
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
                        sfx_play_sound_with_params(SOUND_MSG_REWIND, 0, 0, 0);
                    }
                    break;
                case MSG_WINDOW_STATE_C:
                    if (gGameStatusPtr->pressedButtons[0] & BUTTON_B) {
                        printer->windowState = MSG_WINDOW_STATE_B;
                        printer->unk_4CC = 0;
                        printer->unkArraySize = printer->curLine;
                        printer->unk_4C8 = abs(printer->curLinePos - printer->lineEndPos[printer->unkArraySize]);
                        sfx_play_sound_with_params(SOUND_MSG_SKIP, 0, 0, 0);
                    } else if (gGameStatusPtr->pressedButtons[0] & BUTTON_Z) {
                        if (printer->unkArraySize > 0) {
                            printer->windowState = MSG_WINDOW_STATE_B;
                            printer->unk_4CC = 0;
                            printer->unkArraySize--;
                            printer->unk_4C8 = abs(printer->curLinePos - printer->lineEndPos[printer->unkArraySize]);
                            sfx_play_sound_with_params(SOUND_MSG_REWIND, 0, 0, 0);
                        }
                    } else {
                        if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                            printer->windowState = MSG_WINDOW_STATE_B;
                            printer->unk_4CC = 0;
                            printer->unkArraySize++;
                            printer->unk_4C8 = abs(printer->curLinePos - printer->lineEndPos[printer->unkArraySize]);
                            sfx_play_sound_with_params(SOUND_MSG_UNREWIND, 0, 0, 0);
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
                    if (printer->scrollingTime >= (s32)(5 * DT)) {
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
                printer->curLinePos += printer->windowScrollRate;
                if ((printer->stateFlags & MSG_STATE_FLAG_PRINT_QUICKLY) ||
                    (!(printer->stateFlags & (MSG_STATE_FLAG_10 | MSG_STATE_FLAG_4)) &&
                    (gGameStatusPtr->curButtons[0] & BUTTON_A)))
                {
                    printer->curLinePos += (s32)(6 / DT);
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

#if VERSION_PAL
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
                printer->delayFlags &= ~MSG_DELAY_FLAG_2;
                printer->rewindArrowAnimState = REWIND_ARROW_STATE_INIT;
                printer->rewindArrowCounter = 0;
                printer->stateFlags &= ~MSG_STATE_FLAG_SPEAKING;
                printer->stateFlags &= ~MSG_STATE_FLAG_PRINT_QUICKLY;
                if (printer->style != MSG_STYLE_F) {
                    sfx_play_sound_with_params(SOUND_MSG_WAIT, 0, 0, 0);
                }
                break;
            case MSG_CHAR_READ_PAUSE:
                printer->curPrintDelay = *srcBuf++;
                printer->delayFlags |= MSG_DELAY_FLAG_1;
                printer->stateFlags &= ~MSG_STATE_FLAG_SPEAKING;
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
                    printer->nextLinePos = printer->curLinePos + (MsgCharsets[printer->font]->newLineY
#if !VERSION_JP
                        + MsgStyleVerticalLineOffsets[printer->style]
#endif
                        ) * printer->lineCount;
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
                            printer->stateFlags |= MSG_STATE_FLAG_SPEAKING;
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
#if VERSION_JP
                            printer->windowBasePos.x = 40;
#else
                            printer->windowBasePos.x = 20;
#endif
                            printer->windowBasePos.y = 28;
                            printer->windowSize.y = 58;
#if VERSION_JP
                            printer->windowSize.x = 240;
#else
                            printer->windowSize.x = 280;
#endif
                            printer->windowState = MSG_WINDOW_STATE_OPENING;
                            printer->stateFlags |= MSG_STATE_FLAG_800;
                            printer->delayFlags |= MSG_DELAY_FLAG_1;
                            if (arg == MSG_STYLE_INSPECT) {
                                sfx_play_sound_with_params(SOUND_APPROVE, 0, 0, 0);
                            }
                        }
                        break;
                    case MSG_STYLE_UPGRADE:
                        printer->windowBasePos.x = *srcBuf++;
                        printer->windowBasePos.y = *srcBuf++;
                        printer->windowSize.x = *srcBuf++;
                        printer->windowSize.y = *srcBuf++;
                        sfx_play_sound_with_params(SOUND_APPROVE, 0, 0, 0);
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
#if VERSION_JP
                        printer->windowSize.y = 32;
#else
                        printer->windowSize.y = 40;
#endif
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
                        printer->nextLinePos = printer->curLinePos + (MsgCharsets[printer->font]->newLineY
#if !VERSION_JP
                            + MsgStyleVerticalLineOffsets[printer->style]
#endif
                            ) * arg;
                        printer->windowState = MSG_WINDOW_STATE_SCROLLING;
                        printer->delayFlags |= MSG_DELAY_FLAG_1;
                        printer->lineCount = 0;
                        break;
#if !VERSION_IQUE
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
#endif
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
                        printer->stateFlags &= ~MSG_STATE_FLAG_SPEAKING;
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
                                        printer->fontVariant = sp10[0] + 0x10F;
                                        break;
#if !VERSION_JP
                                    case MSG_CHAR_READ_SPACE:
                                        sp10[0] = MSG_CHAR_PRINT_SPACE;
                                        break;
#endif
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
                            printer->stateFlags |= MSG_STATE_FLAG_SPEAKING;
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
#if VERSION_IQUE
                if (c >= MSG_CHAR_MULTIBYTE_FIRST && c <= MSG_CHAR_MULTIBYTE_LAST) {
                    *printBuf++ = nextArg;
                    srcBuf++;
                    arg1--;
                }
#endif
                if (printer->fontVariant == 0 && c == MSG_CHAR_UNK_C3) {
                    printer->stateFlags &= ~MSG_STATE_FLAG_SPEAKING;
                } else {
                    msg_play_speech_sound(printer, c);
                    if (printer->stateFlags & MSG_STATE_FLAG_800000) {
                        printer->stateFlags |= MSG_STATE_FLAG_SPEAKING;
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
    printer->windowScrollRate = (s32)(6 / DT);
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

#if VERSION_PAL
void dma_load_msg(u32 msgID, void* dest);
INCLUDE_ASM(s32, "msg", dma_load_msg);
#else
void dma_load_msg(u32 msgID, void* dest) {
    u8* addr = (u8*) MSG_ROM_START + (msgID >> 14); // (msgID >> 16) * 4
    u8* offset[2]; // start, end

    dma_copy(addr, addr + 4, &offset[0]); // Load section offset

    addr = MSG_ROM_START + offset[0] + (msgID & 0xFFFF) * 4;
    dma_copy(addr, addr + 8, &offset); // Load message start and end offsets

    // Load the msg data
    dma_copy(MSG_ROM_START + offset[0], MSG_ROM_START + offset[1], dest);
}
#endif

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

void set_message_text_var(s32 msgID, s32 index) {
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

void set_message_int_var(s32 value, s32 index) {
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

#if VERSION_JP
#define CHAR_SPACE_MULTIPLIER 0.7
#else
#define CHAR_SPACE_MULTIPLIER 0.6
#endif

s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags) {
    f32 charWidth;

    if (character >= MSG_CONTROL_CHAR
            && (character != MSG_CHAR_READ_SPACE
            && character != MSG_CHAR_READ_FULL_SPACE
            && character != MSG_CHAR_READ_HALF_SPACE)) {
        return 0;
    }

#if VERSION_IQUE
    if (character >= MSG_CHAR_MULTIBYTE_FIRST && character <= MSG_CHAR_MULTIBYTE_LAST) {
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
        return charWidth * msgScale * CHAR_SPACE_MULTIPLIER;
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
        return baseWidth * msgScale * CHAR_SPACE_MULTIPLIER;
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
                if (prevChar >= MSG_CHAR_MULTIBYTE_FIRST && prevChar <= MSG_CHAR_MULTIBYTE_LAST) {
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

#if !VERSION_JP
static const f32 padding = 0.0f;
#endif

s32 get_msg_width(s32 msgID, u16 charset) {
    s32 width;

    get_msg_properties(msgID, NULL, &width, NULL, NULL, NULL, NULL, charset);
    return width;
}

#if !VERSION_JP
s32 get_msg_lines(s32 msgID) {
    s32 numLines;

    get_msg_properties(msgID, NULL, NULL, NULL, &numLines, NULL, NULL, 0);
    return numLines;
}
#endif

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
        f32 moveToTargetAlpha = (f32)(printer->scrollingTime + 1.0) / CHOICE_POINTER_MOVE_RATE;

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

#if !VERSION_JP
    y -= 2;
#endif
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
