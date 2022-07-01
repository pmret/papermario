#include "common.h"
#include "ld_addrs.h"
#include "sprite.h"

// todo consider symbol
#define MSG_ROM_START 0x1B83000

typedef struct UnkMsgStruct8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[0xE];
} UnkMsgStruct8; // size = 0x16

typedef MessageImageData* MessageImageDataList[1];

extern s32 D_802EF0D0;

s32 D_8014C280[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000, };

s32 MessagePlural = 0x53FD0000;

s16 MessageSingular = 0xF0FD;

s16 gNextMessageBuffer = 0;

s32 D_8014C298[] = { 0xFFF00009, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00100009, 0x00000000, 0x04000000, 0xFFFFFFFF, 0xFFF0FFF7, 0x00000000, 0x00000240, 0xFFFFFFFF, 0x0010FFF7, 0x00000000, 0x04000240, 0xFFFFFFFF, };

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
    gsDPSetCombineLERP(TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};

MessageNumber gMsgNumbers[] = {
    {
        .rasters = &D_802EF0D0,
        .texSize = 128,
        .texWidth = 16,
        .texHeight = 16,
        .digitWidth = {11, 8, 11, 11, 11, 11, 11, 11, 11, 11},
        .fixedWidth = 11
    }, {
        .rasters = &D_802EF0D0,
        .texSize = 128,
        .texWidth = 16,
        .texHeight = 16,
        .digitWidth = {9, 8, 9, 9, 9, 9, 9, 9, 9, 9},
        .fixedWidth = 9
    }
};

Gfx D_8014C368[] = {
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

Vtx gMsgUnkArrowQuad[] = {
    { .v = { .ob = {0xFFF1, 0x001E, 0}, .tc = {0, 0},             .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {0xF, 0x001E, 0},    .tc = {0x1E0, 0},         .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {0xFFFF, 0, 0},      .tc = {0, 0x1E0},         .cn = {191, 184, 176, 255} } },
    { .v = { .ob = {1, 0, 0},           .tc = {0x1E0, 0x1E0},     .cn = {191, 184, 176, 255} } },
};

Vtx gMsgUnkQuad[] = {
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
u8 D_8014C588[] = { 105, 100, 77, 57, 40, 27, 16, 8, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// unsorted
extern s32 D_8015131C;
extern MessageDrawState D_80155D20;
extern s32 D_80159B50;
extern s32 D_8015C7E0;

// BSS
extern s32 gMsgBGScrollAmtX;
extern u16 gMsgGlobalWaveCounter;
extern MessageImageDataList gMsgVarImages;
extern s32 gMsgBGScrollAmtY;
extern Gfx* D_80151338;
extern char gMessageBuffers[][1024];
extern u8 gMessageMsgVars[3][32];
extern s16 D_80155C98;
extern Mtx gMessageWindowProjMatrix[2];
extern MessageDrawState* msg_drawState;

// another file?
extern s16 D_802EB644[22];
extern s32 D_802EB670;
extern s32 D_802EBA70;
extern s32 D_802EBB70;
extern s32 D_802EC3F0;
extern s32 D_802EC5F0;
extern s32 D_802EC670;
extern s32 D_802EC6F0;
extern s32 D_802EC770;
extern s32 D_802EC7F0;
extern s32 D_802EC870[];
extern s32 D_802EC970[];
extern s32 D_802ECAB0[];
extern s32 D_802ECBF0[];
extern s32 D_802ECCF0[];
extern s32 D_802ECD10;
extern s32 D_802ECD30;

extern s32 D_802ED550;
extern s32 D_802ED670;
extern s32 D_802ED970;
extern s32 D_802EE8D0;
extern MessageCharset* gMsgCharsets[5];
extern s32 D_802F39D0;
extern UnkMsgStruct8 D_802F4560[];

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
void msg_draw_frame(s32 posX, s32 posY, s32 sizeX, s32 sizeY, s32 style, s32 palette, s32 fading, u8 bgAlpha,
                    u8 frameAlpha);
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

void load_font_data(Addr offset, u16 size, void* dest) {
    u8* base = charset_ROM_START + (s32) offset;

    dma_copy(base, base + size, dest);
}

void load_font(s32 font) {
    if (font != D_80155C98) {
        if (font == 0) {
            load_font_data(charset_standard_OFFSET, 0x5100, &D_802EE8D0);
            load_font_data(charset_standard_pal_OFFSET, 0x500, &D_802F4560);
        } else if (font == 1) {
            load_font_data(charset_title_OFFSET, 0xF60, &D_802ED970);
            load_font_data(charset_subtitle_OFFSET, 0xB88, &D_802F39D0);
            load_font_data(charset_credits_pal_OFFSET, 0x80, &D_802F4560);
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
    s32 phi_a1_3;
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
                    if ((buttons & gGameStatusPtr->pressedButtons[0]) || (gGameStatusPtr->currentButtons[0] & BUTTON_B)) {
                        printer->windowState = MSG_WINDOW_STATE_PRINTING;
                        printer->currentPrintDelay = 0;
                        printer->stateFlags |= 4;
                        if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_C_DOWN)) {
                            cond = TRUE;
                            sfx_play_sound_with_params(SOUND_MENU_NEXT, 0, 0, 0);
                        } else if (printer->srcBuffer[printer->srcBufferPos] != 0xFD) {
                            printer->stateFlags |= MSG_STATE_FLAG_100 | MSG_STATE_FLAG_4;
                            if (printer->fontVariant != 0 || printer->srcBuffer[printer->srcBufferPos] != 0xC3) {
                                printer->stateFlags |= MSG_STATE_FLAG_100 | MSG_STATE_FLAG_80 | MSG_STATE_FLAG_4;
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
                               (printer->currentLine != 0))
                    {
                        printer->windowState = MSG_WINDOW_STATE_B;
                        printer->unk_4CC = 0;
                        printer->unkArraySize = printer->currentLine - 1;
                        printer->unk_4C8 = abs(printer->curLinePos - printer->lineEndPos[printer->unkArraySize]);
                        sfx_play_sound_with_params(SOUND_CD, 0, 0, 0);
                    }
                    break;
                case MSG_WINDOW_STATE_C:
                    if (gGameStatusPtr->pressedButtons[0] & BUTTON_B) {
                        printer->windowState = MSG_WINDOW_STATE_B;
                        printer->unk_4CC = 0;
                        printer->unkArraySize = printer->currentLine;
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
                        printer->unkCounter = 0;
                        printer->stateFlags |= MSG_STATE_FLAG_20000;
                        sfx_play_sound_with_params(SOUND_MENU_NEXT, 0, 0, 0);
                    } else if (printer->cancelOption != 0xFF && (gGameStatusPtr->pressedButtons[0] & BUTTON_B)) {
                        if (printer->cancelOption >= printer->maxOption) {
                            printer->selectedOption = printer->currentOption;
                        } else {
                            printer->selectedOption = printer->cancelOption;
                        }
                        printer->madeChoice = 1;
                        printer->windowState = MSG_WINDOW_STATE_PRINTING;
                        printer->unkCounter = 0;
                        printer->currentOption = printer->cancelOption;
                        printer->stateFlags |= MSG_STATE_FLAG_20000;
                        sfx_play_sound_with_params(SOUND_MENU_BACK, 0, 0, 0);
                    } else if (gGameStatusPtr->heldButtons[0] & BUTTON_STICK_DOWN) {
                        if (printer->currentOption != printer->maxOption - 1) {
                            printer->targetOption = printer->currentOption + 1;
                            printer->windowState = MSG_WINDOW_STATE_SCROLLING_BACK;
                            printer->unkCounter = 1;
                            sfx_play_sound_with_params(SOUND_MENU_CHANGE_SELECTION, 0, 0, 0);
                        }
                    } else if (gGameStatusPtr->heldButtons[0] & BUTTON_STICK_UP) {
                        if (printer->currentOption != 0) {
                            printer->targetOption = printer->currentOption - 1;
                            printer->windowState = MSG_WINDOW_STATE_SCROLLING_BACK;
                            printer->unkCounter = 1;
                            sfx_play_sound_with_params(SOUND_MENU_CHANGE_SELECTION, 0, 0, 0);
                        }
                    }

                    if (printer->windowState != MSG_WINDOW_STATE_SCROLLING_BACK) {
                        break;
                    }
                case MSG_WINDOW_STATE_SCROLLING_BACK:
                    printer->unkCounter++;
                    if (printer->unkCounter >= 5) {
                        printer->windowState = 7;
                        printer->currentOption = printer->targetOption;
                        printer->selectedOption = printer->currentOption;
                    }
                    break;
            }
        } else if (!(printer->stateFlags & MSG_STATE_FLAG_20) &&
                    printer->windowState == 5 &&
                    (gGameStatusPtr->pressedButtons[0] & BUTTON_A))
        {
            printer->windowState = MSG_WINDOW_STATE_PRINTING;
            printer->currentPrintDelay = 0;
            printer->stateFlags |= MSG_STATE_FLAG_4;
        }

        if (printer->stateFlags & MSG_STATE_FLAG_4 && !(gGameStatusPtr->currentButtons[0] & BUTTON_A)) {
            printer->stateFlags &= ~MSG_STATE_FLAG_4;
        }

        for (i = 0; i < ARRAY_COUNT(printer->animTimers); i++) {
            if (printer->animTimers[i] > 0) {
                printer->animTimers[i]--;
            }
        }

        switch (printer->windowState) {
            case MSG_WINDOW_STATE_PRINTING:
                if ((gGameStatusPtr->pressedButtons[0] & BUTTON_A) | (gGameStatusPtr->currentButtons[0] & BUTTON_B)) {
                    if (!(printer->stateFlags & (MSG_STATE_FLAG_20 | MSG_STATE_FLAG_10)) && !cond) {
                        printer->stateFlags |= MSG_STATE_FLAG_100;

                    }
                }
            // fallthrough
            case MSG_WINDOW_STATE_INIT:
                phi_a1_3 = printer->charsPerChunk;
                if (printer->windowState == MSG_WINDOW_STATE_INIT) {
                    printer->windowState = MSG_WINDOW_STATE_PRINTING;
                    printer->currentPrintDelay = 0;
                } else if (printer->stateFlags & MSG_STATE_FLAG_100) {
                    phi_a1_3 = 12;
                    printer->currentPrintDelay = 0;
                } else if (!(printer->stateFlags & MSG_STATE_FLAG_4)) {
                    if (!(printer->stateFlags & (MSG_STATE_FLAG_20 | MSG_STATE_FLAG_10)) &&
                        (gGameStatusPtr->currentButtons[0] & BUTTON_A))
                    {
                        phi_a1_3 = 6;
                        printer->currentPrintDelay = 0;
                    }
                }
                if ((printer->currentPrintDelay == 0) || --printer->currentPrintDelay == 0) {
                    msg_copy_to_print_buffer(printer, phi_a1_3, 0);
                }
                break;
            case MSG_WINDOW_STATE_SCROLLING:
                if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
                    if (!(printer->stateFlags & (MSG_STATE_FLAG_20 | MSG_STATE_FLAG_10))) {
                        printer->stateFlags |= MSG_STATE_FLAG_100;
                    }
                }
                printer->curLinePos += printer->unk_464;
                if ((printer->stateFlags & MSG_STATE_FLAG_100) ||
                    (!(printer->stateFlags & (MSG_STATE_FLAG_10 | MSG_STATE_FLAG_4)) &&
                    (gGameStatusPtr->currentButtons[0] & BUTTON_A)))
                {
                    printer->curLinePos += 6;
                }

                if (printer->curLinePos >= printer->nextLinePos) {
                    printer->windowState = MSG_WINDOW_STATE_PRINTING;
                    printer->curLinePos = printer->nextLinePos;
                    printer->stateFlags |= MSG_STATE_FLAG_4;

                    if (printer->style == MSG_STYLE_SIGN ||
                        printer->style == MSG_STYLE_LAMPPOST ||
                        printer->srcBuffer[printer->srcBufferPos] == 0xF1)
                    {
                        printer->currentPrintDelay = 0;
                    } else {
                        printer->currentPrintDelay = 5;
                    }
                    printer->lineEndPos[printer->currentLine] = printer->curLinePos;
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
                        if (printer->unkArraySize == printer->currentLine) {
                            printer->windowState = MSG_WINDOW_STATE_WAITING;
                            printer->rewindArrowAnimState = 0;
                            printer->rewindArrowBlinkCounter = 0;
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
            gSPViewport(gMasterGfxPos++, D_8014C280);
            guOrtho(matrix, 0.0f, 319.0f, -240.0f, 0.0f, -500.0f, 500.0f, 1.0f);
            gSPMatrix(gMasterGfxPos++, OS_K0_TO_PHYSICAL(matrix), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gDPPipeSync(gMasterGfxPos++);
            gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
            gSPClearGeometryMode(gMasterGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                 G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
            gSPSetGeometryMode(gMasterGfxPos++, G_SHADE | G_SHADING_SMOOTH);
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
        pitchShift = ((character % 20) * 10) + (printer->speechVolumePitch - baseShift);
        volume = ((rand_int(15) + 78) * volTemp);

        if (volume > 255) {
            volume = 255;
        }

        if (character & flag) {
            sfx_play_sound_with_params(printer->speedSoundIDA, volume, printer->speechPan, pitchShift);
        } else {
            sfx_play_sound_with_params(printer->speedSoundIDB, volume, printer->speechPan, pitchShift);
        }
    }
}


INCLUDE_ASM(s32, "msg", msg_copy_to_print_buffer);

void initialize_printer(MessagePrintState* printer, s32 arg1, s32 arg2) {
    s32 i;

    printer->printBufferSize = ARRAY_COUNT(printer->printBuffer);
    printer->printBuffer[0] = MSG_CHAR_PRINT_END;
    printer->printDelayTime = 1;
    printer->charsPerChunk = 1;
    printer->unk_464 = 6;
    printer->srcBuffer = NULL;
    printer->msgID = 0;
    printer->currentPrintDelay = 0;
    printer->windowOffsetPos.x = 0;
    printer->windowOffsetPos.y = 0;
    printer->windowBasePos.x = 0;
    printer->windowBasePos.y = 0;
    printer->rewindArrowAnimState = 0;
    printer->rewindArrowBlinkCounter = 0;
    printer->rewindArrowPos.x = 0;
    printer->rewindArrowPos.y = 0;
    printer->currentLine = 0;
    printer->unkArraySize = 0;
    printer->maxOption = 0;
    printer->madeChoice = 0;
    printer->currentOption = 0;
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
        printer->currentAnimFrame[i] = 0;
        printer->animTimers[i] = -1;
    }

    printer->initOpenPos.x = 160;
    printer->initOpenPos.y = 40;
    printer->speechSoundType = -1;
    printer->speechPan = 64;
    printer->volume = 75;
    printer->rewindArrowBlinkCounter = 0;
    printer->style = 0;
    printer->fadeInCounter = 0;
    printer->openStartPos.x = 0;
    printer->openStartPos.y = 0;
    printer->fadeOutCounter = 0;
    printer->windowSize.y = 0;
    printer->windowSize.x = 0;
    printer->speechVolumePitch = 0;
    printer->speedSoundIDA = 0;
    printer->speedSoundIDB = 0;
    printer->varBufferReadPos = 0;
    printer->currentImageIndex = 0;
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
    if (gNextMessageBuffer >= 2) {
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

    if (msgID == 0) {
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

// loop crap
#ifdef NON_EQUIVALENT
void set_message_msg(s32 msgID, s32 index) {
    u8* buffer = msgID;
    u8* mallocSpace = NULL;
    u8* it;
    s32 i;
    s32 new_var;

    if (msgID >= 0) {
        buffer = general_heap_malloc(0x400);
        dma_load_msg(msgID, buffer);
        mallocSpace = buffer;
    }

    for (i = 0; i < ARRAY_COUNT(gMessageMsgVars[index]); i++) {
        gMessageMsgVars[index][i] = buffer[i];
        if (buffer[i] == 0xFD) {
            break;
        }
    }

    if (mallocSpace != NULL) {
        general_heap_free(mallocSpace);
    }
}
#else
INCLUDE_ASM(s32, "msg", set_message_msg);
#endif

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
        gMessageMsgVars[index][i] = thisChar - 0x20;
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

    if (overrideCharWidth != 0) {
        charWidth = overrideCharWidth;
    } else if (flags != 0) {
        u8* charWidthTable = gMsgCharsets[charset]->rasters[variation].charWidthTable;

        if (charWidthTable != NULL
                && character != MSG_CHAR_READ_SPACE
                && character != MSG_CHAR_READ_FULL_SPACE
                && character != MSG_CHAR_READ_HALF_SPACE) {
            charWidth = charWidthTable[character];
        } else {
            charWidth = gMsgCharsets[charset]->rasters[variation].monospaceWidth;
        }
    } else {
        charWidth = gMsgCharsets[charset]->rasters[variation].monospaceWidth;
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
        u8* charWidthTable = gMsgCharsets[charset]->rasters[variation].charWidthTable;

        if (charWidthTable != NULL
                && character != MSG_CHAR_PRINT_SPACE
                && character != MSG_CHAR_PRINT_FULL_SPACE
                && character != MSG_CHAR_PRINT_HALF_SPACE) {
            baseWidth = charWidthTable[character];
        } else {
            baseWidth = gMsgCharsets[charset]->rasters[variation].monospaceWidth;
        }
    } else {
        baseWidth = gMsgCharsets[charset]->rasters[variation].monospaceWidth;
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

INCLUDE_ASM(void, "msg", get_msg_properties, s32 msgID, s32* height, s32* width, s32* maxLineChars, s32* numLines,
            s32* maxLinesPerPage, s32* arg6, s32 charset);

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
            get_msg_properties((s32)printer->srcBuffer, 0, &width, 0, 0, 0, 0, charset);
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

INCLUDE_ASM(s32, "msg", msg_update_rewind_arrow);

void msg_draw_rewind_arrow(s32 printerIndex) {
    MessagePrintState* printer = &gMessagePrinters[printerIndex];

    if (printer->rewindArrowBlinkCounter < 6) {
        draw_ci_image_with_clipping(&D_802ED550, 24, 24, G_IM_FMT_CI, G_IM_SIZ_4b, &D_802ED670, printer->rewindArrowPos.x,
                                    printer->rewindArrowPos.y, 10, 10, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, 255);
    }

    printer->rewindArrowBlinkCounter++;
    if (printer->rewindArrowBlinkCounter >= 12) {
        printer->rewindArrowBlinkCounter = 0;
    }
}

INCLUDE_ASM(s32, "msg", msg_draw_choice_pointer);

void draw_digit(u32 img, s32 charset, s32 posX, s32 posY) {
    MessageNumber* num = &gMsgNumbers[charset];

    gDPLoadTextureTile_4b(gMasterGfxPos++,
        img, G_IM_FMT_CI,
        num->texWidth , num->texHeight,
        0, 0,
        num->texWidth - 1, num->texHeight - 1,
        0,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
        G_TX_NOMASK, G_TX_NOMASK,
        G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gMasterGfxPos++,
        4 * posX, 4 * posY,
        4 * (posX + num->texWidth), 4 * (posY + num->texHeight),
        G_TX_RENDERTILE,
        0, 0,
        1 << 10, 1 << 10);
}

INCLUDE_ASM(void, "msg", draw_number, s32 value, s32 x, s32 y, s32 arg3, s32 palette, s32 opacity, s32 style);

void drawbox_message_delegate(void* data) {
    MessagePrintState* printer = data;

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
            draw_box(DRAW_FLAGS_ROTSCALE, 0, printer->windowBasePos.x, 56, 0, printer->windowSize.x, printer->windowSize.y, 255, 0,
                     scale, scale, 0.0f, 0.0f, rotZ, drawbox_message_delegate, printer, NULL, SCREEN_WIDTH,
                     SCREEN_HEIGHT, NULL);
            break;
        default:
            appendGfx_message(printer, printer->windowOffsetPos.x, printer->windowOffsetPos.y, printer->unk_46C,
                              printer->curLinePos, 4, 0);
            break;
    }
}

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
    s32* spC0;
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
    s32 frameAlpha;
    u16 fading;
    s32 phi_s0_5;
    s32* phi_s6;
    s8 phi_s2_4;
    s32 phi_s3_2;
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
    if (gMasterGfxPos != D_80151338) {
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
    msg_drawState->currentPosX = 0;
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
        gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }

    sp80bool = FALSE;
    msg_drawState->drawBufferPos = 0;

    while (!sp80bool) {
        switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos]) {
            case MSG_CHAR_PRINT_ENDL:
                msg_drawState->nextPos[0] = 0;
                msg_drawState->nextPos[1] += (s32)((msg_drawState->msgScale.y * gMsgCharsets[msg_drawState->font]->newLineY) +
                                                   D_802EB644[printer->style]);
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
                                             msg_drawState->font, msg_drawState->fontVariant, msg_drawState->msgScale.x, msg_drawState->currentPosX,
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
                        msg_draw_frame(frameX, frameY, frameSizeX, frameSizeY, 5, msg_drawState->framePalette, frameFading, frameAlpha,
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

                        msg_draw_frame(printer->windowBasePos.x, printer->windowBasePos.y, printer->windowSize.x, printer->windowSize.y, 6,
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
                            spC0 = &D_802EC770;
                            printer->windowSize.y = 72;
                            msg_drawState->textColor = MSG_PAL_18;
                            phi_s6 = &D_802ECD10;
                        } else {
                            spC0 = &D_802EC7F0;
                            msg_drawState->textColor = MSG_PAL_1C;
                            phi_s6 = &D_802ECD30;
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
                        draw_ci_image_with_clipping(&D_802EC5F0, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, phi_s6, 20, 28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(&D_802EC670, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, phi_s6, 284, 28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(&D_802EC6F0, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, phi_s6, 20, printer->windowSize.y + 12, 10, 10, 310, 230,
                                                    temp_s1_5);
                        draw_ci_image_with_clipping(spC0, 16, 16, G_IM_FMT_CI, G_IM_SIZ_4b, phi_s6, 284, printer->windowSize.y + 12, 10, 10, 310, 230, temp_s1_5);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802EC870, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0090, 0x0070, 0x0470, 0x00B0, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802EC970, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0050, 0x00B0, 0x0090, (printer->windowSize.y + 12) * 4, G_TX_RENDERTILE, 0, 0,
                                            0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802ECAB0, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0470, 0x00B0, 0x04B0, (printer->windowSize.y + 12) * 4, G_TX_RENDERTILE, 0, 0,
                                            0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802ECBF0, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0090, (printer->windowSize.y + 12) * 4, 0x0470, (printer->windowSize.y + 28) * 4,
                                            G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802ECCF0, G_IM_FMT_CI, 8, 0, 0, 0, 7, 7, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                              G_TX_NOMIRROR | G_TX_WRAP, 3, 3, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0090, 0x00B0, 0x0470, (printer->windowSize.y + 12) * 4, G_TX_RENDERTILE, 0, 0,
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
                        msg_draw_frame(40, 28, 240, 58, 6, msg_drawState->framePalette, phi_s2_4, phi_s3_2, phi_s3_2);
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
                            draw_box(0, 0, printer->windowBasePos.x, 56, 0, printer->windowSize.x,
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
                        msg_drawState->currentPosX = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case MSG_PRINT_FUNC_SIZE:
                        packedScaleX = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->msgScale.x = (f32)(packedScaleX >> 4) + ((packedScaleX & 0xF) * 0.0625f);
                        packedScaleY = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                        msg_drawState->msgScale.y = (f32)(packedScaleY >> 4) + ((packedScaleY & 0xF) * 0.0625f);
                        msg_drawState->drawBufferPos += 3;
                        if (msg_drawState->msgScale.x > 1.0 || msg_drawState->msgScale.y > 1.0) {
                            gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
                        } else if (msg_drawState->msgScale.x < 1.0 || msg_drawState->msgScale.y < 1.0) {
                            gDPSetTextureFilter(gMasterGfxPos++, G_TF_AVERAGE);
                        }
                        break;
                    case MSG_PRINT_FUNC_SIZE_RESET:
                        msg_drawState->msgScale.x = 1.0f;
                        msg_drawState->msgScale.y = 1.0f;
                        msg_drawState->drawBufferPos++;
                        gDPSetTextureFilter(gMasterGfxPos++, G_TF_AVERAGE);
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

                            draw_ci_image_with_clipping(&D_80159B50, 32, 32, G_IM_FMT_CI, G_IM_SIZ_4b, &D_8015C7E0, imgDrawPosX, imgDrawPosY, msg_drawState->clipX[0],
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
                            printer->currentAnimFrame[animIdx]++;
                        }

                        dbPos = msg_drawState->drawBufferPos;
                        while (TRUE) {
                            if ((msg_drawState->printBuffer[dbPos - 1] == MSG_CHAR_PRINT_FUNCTION) &&
                                (msg_drawState->printBuffer[dbPos] == MSG_PRINT_FUNC_ANIM_DELAY) &&
                                (msg_drawState->printBuffer[dbPos + 1] == animIdx)) {
                                if (msg_drawState->printBuffer[dbPos + 2] != printer->currentAnimFrame[animIdx]) {
                                    dbPos += 4;
                                } else {
                                    break;
                                }
                            } else {
                                if ((msg_drawState->printBuffer[dbPos] == MSG_CHAR_PRINT_FUNCTION) &&
                                    (msg_drawState->printBuffer[dbPos + 1] == MSG_PRINT_FUNC_ANIM_LOOP) &&
                                    (msg_drawState->printBuffer[dbPos + 2] == animIdx)) {

                                    if (printer->animTimers[animIdx] == 0) {
                                        printer->currentAnimFrame[animIdx] = msg_drawState->printBuffer[dbPos + 3];
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
                                gDPSetCombineLERP(gMasterGfxPos++, NOISE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, NOISE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0);
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case MSG_FX_STATIC:
                                msg_drawState->effectFlags |= MSG_FX_FLAG_STATIC;
                                gDPSetEnvColor(gMasterGfxPos++,
                                               msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                               msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                               msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                               0);
                                gDPSetCombineLERP(gMasterGfxPos++, NOISE, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0, 0, TEXEL0, NOISE, TEXEL0, ENVIRONMENT,
                                                  TEXEL0, 0, 0, 0, TEXEL0);
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
                    gDPPipeSync(gMasterGfxPos++);
                    gSPDisplayList(gMasterGfxPos++, D_8014C500);
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

                msgCharset = gMsgCharsets[msg_drawState->font];
                charPosY = (s8) msgCharset->rasters[msg_drawState->fontVariant].baseHeightOffset + (msg_drawState->nextPos[1] +
                           (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY)) - additionalOffsetY);

                if ((sp8E != 0) &&
                    (charPosX < msg_drawState->clipX[1]) &&
                    (charPosY < msg_drawState->clipY[1]) &&
                    (msg_drawState->clipX[0] < charPosX + (s32)(msg_drawState->msgScale.x *
                            msgCharset->rasters[msg_drawState->fontVariant].monospaceWidth)) &&
                    (msg_drawState->clipY[0] < charPosY + (s32)(msg_drawState->msgScale.y * msgCharset->newLineY +
                            D_802EB644[printer->style]))) {
                    palette = msg_drawState->textColor;
                    phi_s2_5 = sp8E;
                    if (msg_drawState->effectFlags & MSG_FX_FLAG_BLUR) {
                        phi_s2_5 = (f32) phi_s2_5 * 0.35;
                    }
                    if ((printer->windowState == MSG_WINDOW_STATE_WAITING_FOR_CHOICE) && (msg_drawState->printModeFlags & MSG_PRINT_FLAG_20)) {
                        if (msg_drawState->unk_2D == printer->currentOption) {
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
                        gDPSetAlphaDither(gMasterGfxPos++, G_AD_NOISE);
                        gDPSetAlphaCompare(gMasterGfxPos++, G_AC_DITHER);
                        phi_s2_5 = spB6 * (phi_s2_5 / 255.0);
                    }
                    if ((msg_drawState->printModeFlags & MSG_PRINT_FLAG_2) || (phi_s2_5 != sp96)) {
                        if ((sp96 < 0xFF) && (phi_s2_5 < 0xFF)) {
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, phi_s2_5);
                        } else if ((sp96 == 0xFF) && (phi_s2_5 < 0xFF)) {
                            gDPPipeSync(gMasterGfxPos++);
                            if (printer->stateFlags & MSG_STATE_FLAG_4000) {
                                gDPSetRenderMode(gMasterGfxPos++, IM_RD | CVG_DST_CLAMP | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN,
                                                 G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_CLAMP | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM,
                                                         G_BL_1MA));

                            } else {
                                gDPSetRenderMode(gMasterGfxPos++, IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN,
                                                 G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM,
                                                         G_BL_1MA));

                            }
                            gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, phi_s2_5);
                        } else if ((sp96 < 0xFF) && (phi_s2_5 == 0xFF)) {
                            gDPPipeSync(gMasterGfxPos++);
                            gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                            gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
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
                            gDPPipeSync(gMasterGfxPos++);
                            gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                            gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                                              PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 40, 40, 40, 72);
                            msg_draw_char(printer, msg_drawState,
                                          msg_drawState->printBuffer[msg_drawState->drawBufferPos],
                                          palette, charPosX + 2, charPosY + 2);
                            gDPPipeSync(gMasterGfxPos++);
                            gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                            gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
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
                                            msg_drawState->currentPosX, msg_drawState->printModeFlags);
                msg_drawState->drawBufferPos++;
                break;
        }
    }

    varImgHasBorder = FALSE;
    if (printer->varImageScreenPos.x != 0) {
        s16 varImgFinalAlpha;

        varImgFinalAlpha = printer->varImgFinalAlpha;
        msgVarImage = &(*gMsgVarImages)[printer->currentImageIndex];

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
                draw_box(0, 15, printer->varImageScreenPos.x - 7, printer->varImageScreenPos.y - 7, 0,
                         msgVarImage->width + 15, msgVarImage->height + 14, varImgFinalAlpha, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                         0.0f, NULL, 0, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
            }
            draw_ci_image_with_clipping(msgVarImage->raster, msgVarImage->width, msgVarImage->height,
                                        msgVarImage->format, msgVarImage->bitDepth, msgVarImage->palette,
                                        printer->varImageScreenPos.x, printer->varImageScreenPos.y, 0, 0,
                                        SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, varImgFinalAlpha);
        }

    }
    gDPPipeSync(gMasterGfxPos++);
    D_80151338 = gMasterGfxPos;
}

void msg_reset_gfx_state(void) {
    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, D_8014C500);
}

INCLUDE_ASM(s32, "msg", msg_draw_char);

void msg_draw_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 posX, u16 posY, u16 sizeX, u16 sizeY) {
    u16 lrX = posX + sizeX;
    u16 lrY = posY + sizeY;

    appendGfx_msg_prim_rect(r, g, b, a, posX, posY, lrX, lrY);
}

void appendGfx_msg_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 ulX, u16 ulY, u16 lrX, u16 lrY) {
    gDPPipeSync(gMasterGfxPos++);

    if (a == 255) {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1);
    } else {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gMasterGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    }

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, r, g, b, a);
    gDPFillRectangle(gMasterGfxPos++, ulX, ulY, lrX, lrY);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

    switch (msg_drawState->unk_29) {
        case 0:
            gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            break;
        case 1:
            gDPSetCombineMode(gMasterGfxPos++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
            break;
        default:
            gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
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

    gSPMatrix(gMasterGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMasterGfxPos++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(gMasterGfxPos++, G_SHADE | G_SHADING_SMOOTH);
    gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
    gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);

    if (printer->maxLinesPerPage == 3) {
        gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
    } else {
        gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
    }

    if (opacity >= 255) {
        gDPSetRenderMode(gMasterGfxPos++, AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                         GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM),
                         AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                         GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
        gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else {
        gDPSetRenderMode(gMasterGfxPos++, IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL |
                         GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA),
                         IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL |
                         GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                          TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 32, 32, 32, opacity);
    }

    gDPSetTextureLUT(gMasterGfxPos++, G_TT_RGBA16);
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1,
                       (msg_drawState->framePalette << 5) + (s8*)&D_802EC3F0); // TODO fix (array?)
    gDPTileSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTLUTCmd(gMasterGfxPos++, G_TX_LOADTILE, 15);
    gDPPipeSync(gMasterGfxPos++);
    gDPLoadTextureTile_4b(gMasterGfxPos++, &D_802EB670, G_IM_FMT_CI, 32, 0, 0, 0, 31, 63, 0,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gMasterGfxPos++, gMsgSpeechBoxLQuad, 4, 0);
    gSP2Triangles(gMasterGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
    gDPLoadTextureTile_4b(gMasterGfxPos++, &D_802EBA70, G_IM_FMT_CI, 8, 0, 0, 0, 7, 63, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 3, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gMasterGfxPos++, gMsgSpeechBoxMQuad, 4, 0);
    gSP2Triangles(gMasterGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
    gDPLoadTextureTile_4b(gMasterGfxPos++, &D_802EBB70, G_IM_FMT_CI, 32, 0, 0, 0, 31, 63, 0,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gMasterGfxPos++, gMsgSpeechBoxRQuad, 4, 0);
    gSP2Triangles(gMasterGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
    gDPPipeSync(gMasterGfxPos++);
}

INCLUDE_ASM(s32, "msg", msg_draw_speech_arrow);

INCLUDE_ASM(s32, "msg", msg_draw_frame);

void msg_get_glyph(s32 font, s32 variation, s32 charIndex, s32 palette, MesasgeFontGlyphData* out) {
    out->raster = &gMsgCharsets[font]->rasters[variation].raster[(u16)gMsgCharsets[font]->charRasterSize * charIndex];
    out->palette = &D_802F4560[palette].unk_00;
    out->texSize.x = gMsgCharsets[font]->texSize.x;
    out->texSize.y = gMsgCharsets[font]->texSize.y;
    out->charWidth = msg_get_draw_char_width(charIndex, font, variation, 1.0f, 0, 0);
    out->charHeight = out->texSize.y;
}
