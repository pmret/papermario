#include "common.h"
#include "ld_addrs.h"
#include "sprite.h"

// todo consider symbol
#define MSG_ROM_START 0x1B83000

typedef struct UnkMsgStruct8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[0xE];
} UnkMsgStruct8; // size = 0x16

typedef struct UnkImage14 {
    /* 0x00 */ s32* raster;
    /* 0x04 */ s32* palette;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ s32 format;
    /* 0x10 */ s32 bitDepth;
} UnkImage14; // size = 0x14

typedef UnkImage14* UnkImage14List[1];

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
    },{
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

s32 D_8014C3C0[] = { 0x00010000, 0x00000000, 0x00000000, 0xFFFFF8FF, 0x00200000, 0x00000000, 0x04000000, 0xFFFFF8FF, 0x0001FFC0, 0x00000000, 0x00000800, 0xBFB8B0FF, 0x0020FFC0, 0x00000000, 0x04000800, 0xBFB8B0FF, };

s32 D_8014C400[] = { 0x00200000, 0x00000000, 0x00000000, 0xFFFFF8FF, 0x00E10000, 0x00000000, 0x01000000, 0xFFFFF8FF, 0x0020FFC0, 0x00000000, 0x00000800, 0xBFB8B0FF, 0x00E1FFC0, 0x00000000, 0x01000800, 0xBFB8B0FF, };

s32 D_8014C440[] = { 0x00E10000, 0x00000000, 0x00000000, 0xFFFFF8FF, 0x01000000, 0x00000000, 0x04000000, 0xFFFFF8FF, 0x00E1FFC0, 0x00000000, 0x00000800, 0xBFB8B0FF, 0x0100FFC0, 0x00000000, 0x04000800, 0xBFB8B0FF, };

s32 D_8014C480[] = { 0xFFF1001E, 0x00000000, 0x00000000, 0xBFB8B0FF, 0x000F001E, 0x00000000, 0x01E00000, 0xBFB8B0FF, 0xFFFF0000, 0x00000000, 0x000001E0, 0xBFB8B0FF, 0x00010000, 0x00000000, 0x01E001E0, 0xBFB8B0FF, };

s32 D_8014C4C0[] = { 0xFFF1001E, 0x00000000, 0x00000000, 0xBFB8B0FF, 0x000F001E, 0x00000000, 0x01E00000, 0xBFB8B0FF, 0xFFFF0000, 0x00000000, 0x000001E0, 0xBFB8B0FF, 0x00010000, 0x00000000, 0x01E001E0, 0xBFB8B0FF, };

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

// BSS
extern s32 gMsgBGScrollAmtX;
extern u16 gMsgGlobalWaveCounter;
extern UnkImage14List gMsgVarImages;
extern s32 gMsgBGScrollAmtY;
extern s32 D_80151338;
extern char gMessageBuffers[][1024];
extern u8 gMessageMsgVars[3][32];
extern s16 D_80155C98;
extern Matrix4s gMessageWindowProjMatrix[2];
extern MessageDrawState* msg_drawState;

// another file?
extern s32 D_802ED550;
extern s32 D_802ED670;
extern s32 D_802ED970;
extern s32 D_802EE8D0;
extern MessageCharset* gMsgCharsets[5];
extern s32 D_802F39D0;
extern UnkMsgStruct8 D_802F4560[];

void load_font(s32 font);
s32 _update_message(MessagePrintState*);
void appendGfx_message(MessagePrintState*, s16, s16, u16, u16, u16, u8);
void appendGfx_msg_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 ulX, u16 ulY, u16 lrX, u16 lrY);
void get_msg_properties(s32 msgID, s32* height, s32* width, s32* maxLineChars, s32* numLines,
                           s32* maxLinesPerPage, s32* arg6, s32 charset);
void msg_draw_char(MessagePrintState* printer, MessageDrawState* drawState, s32 charIndex, s32 palette, s32 posX, s32 posY);
void msg_draw_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 posX, u16 posY, u16 sizeX, u16 sizeY);
void msg_draw_frame(s32 posX, s32 posY, s32 sizeX, s32 sizeY, s32 style, s32 palette, s32 fading, u8 bgAlpha, u8 frameAlpha);


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

    D_80151338 = 0;
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
        if (gMessagePrinters[i].stateFlags & 2) {
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

#ifdef NON_MATCHING
s32 _update_message(MessagePrintState* printer) {
    GameStatus* temp_v0_5;
    f32 temp_f4;
    s32 temp_a1_3;
    s32 temp_v0_2;
    u8 temp_v1_2;
    s32 phi_a3;
    s32 phi_a0;
    u8 phi_v0;
    s32 phi_a0_2;
    MessagePrintState* phi_a0_4;
    s32 phi_a1_2;
    s32 phi_s1;
    u8 phi_a1_3;
    s16 phi_v1;
    s32 phi_a0_5;

    printer->effectFrameCounter++;
    if (printer->effectFrameCounter >= 3600) {
        printer->effectFrameCounter = 0;
    }
    temp_f4 = (f32) ((((f64) (f32) printer->initOpenPos.x - 160.0) / 3.8) + 64.0);
    if (temp_f4 < 5.0) {
        temp_f4 = 5.0f;
    } else if (temp_f4 > 122.0) {
        temp_f4 = 122.0f;
    }

    if (temp_f4 >= 2.1474836e9f) {
        printer->unk_51A = ((s8)(temp_f4 - 2.1474836e9f));
    } else {
        printer->unk_51A = temp_f4;
    }

    if (!(printer->stateFlags & 0x40)) {
        if (!(printer->stateFlags & 0x30)) {
            temp_v1_2 = printer->windowState;
            if (temp_v1_2 != 7) {
                if (temp_v1_2 < 8) {
                    if (temp_v1_2 != 5) {
                        phi_s1 = 0;
                    } else {
                        phi_a3 = 0x8000;
                        if (printer->stateFlags & 0x80000) {
                            phi_a3 = 0x8004;
                        }

                        if (((phi_a3 & gGameStatusPtr->pressedButtons)) || ((gGameStatusPtr->currentButtons & 0x4000) != 0)) {
                            printer->windowState = 4;
                            printer->currentPrintDelay = 0;
                            printer->stateFlags |= 0x4;
                            if ((gGameStatusPtr->pressedButtons & 0x8004) != 0) {
                                phi_s1 = 1;
                                sfx_play_sound_with_params(0xC9, 0, 0, 0);
                            } else {
                                if (printer->srcBuffer[printer->srcBufferPos] != 0xFD) {
                                    printer->stateFlags |= 0x104;
                                    if (printer->fontVariant == 0) {
                                        if (printer->srcBuffer[printer->srcBufferPos] == 0xC3) {
                                            phi_a0 = 0xCC;
                                        } else {
block_29:
                                            printer->stateFlags |= 0x184;
                                            phi_a0 = 0xCC;
                                        }
                                    } else {
                                        goto block_29;
                                    }
                                    sfx_play_sound_with_params(phi_a0, 0, 0, 0);
                                }
                                if ((printer->style - 1) < 4U) {
                                    sfx_play_sound_with_params(0xC9, 0, 0, 0);
                                }
                            }
                        } else {
                            if ((gGameStatusPtr->pressedButtons & 0x2000) != 0) {
                                if (!(printer->stateFlags & 0x40000)) {
                                    if (printer->currentLine != 0) {
                                        printer->windowState = 0xB;
                                        printer->unk_4CC = 0;
                                        phi_v0 = printer->currentLine - 1;
                                        phi_a0_2 = 0xCD;
block_44:
                                        printer->unkArraySize = phi_v0;
                                        temp_v0_2 = printer->curLinePos - printer->lineEndPos[phi_v0 & 0xFF];
                                        if (temp_v0_2 < 0) {
                                            temp_v0_2 = -temp_v0_2;
                                        }
                                        printer->unk_4C8 = temp_v0_2;
                                        sfx_play_sound_with_params(phi_a0_2, 0, 0, 0);
                                    }
                                }
                            }
                        }
                    }
                } else if (temp_v1_2 != 8) {
                    if (temp_v1_2 == 0xC) {
                        if (gGameStatusPtr->pressedButtons & 0x4000) {
                            printer->windowState = 0xB;
                            printer->unk_4CC = 0;
                            phi_v0 = printer->currentLine;
                            phi_a0_2 = 0xCC;
                            goto block_44;
                        }
                        if (gGameStatusPtr->pressedButtons & 0x2000) {
                            if (printer->unkArraySize != 0) {
                                printer->windowState = 0xB;
                                printer->unk_4CC = 0;
                                phi_v0 = printer->unkArraySize - 1;
                                phi_a0_2 = 0xCD;
                                goto block_44;
                            }
                        } else {
                            if (gGameStatusPtr->pressedButtons & 0x8000) {
                                printer->windowState = 0xB;
                                printer->unk_4CC = 0;
                                phi_v0 = printer->unkArraySize + 1;
                                phi_a0_2 = 0xCE;
                                goto block_44;
                            }
                        }
                    }
                } else {
block_65:
                    printer->unkCounter++;
                    if ((printer->unkCounter & 0xFF) >= 5U) {
                        printer->windowState = 7;
                        printer->currentOption = printer->targetOption;
                        printer->selectedOption = printer->targetOption;
                    }
                }
            } else {
                if (gGameStatusPtr->pressedButtons & 0x8000) {
                    printer->madeChoice = 1;
                    printer->windowState = 4;
                    printer->unkCounter = 0;
                    printer->stateFlags |= 0x20000;
                    sfx_play_sound_with_params(0xC9, 0, 0, 0);
                } else {
                    if ((printer->cancelOption != 0xFF) && (gGameStatusPtr->pressedButtons & 0x4000)) {
                        if (printer->cancelOption < printer->maxOption) {
                            printer->selectedOption = printer->cancelOption;
                        } else {
                            printer->selectedOption = printer->currentOption;
                        }
                        printer->madeChoice = 1;
                        printer->windowState = 4;
                        printer->unkCounter = 0;
                        printer->currentOption = printer->cancelOption;
                        printer->stateFlags |= 0x20000;
                        sfx_play_sound_with_params(0xCA, 0, 0, 0);
                    }
                    if (gGameStatusPtr->heldButtons & 0x20000) {
                        if (printer->currentOption != printer->maxOption - 1) {
                            printer->targetOption = printer->currentOption + 1;
                            printer->windowState = 8;
                            printer->unkCounter = 1;
                            sfx_play_sound_with_params(0xCA, 0, 0, 0);
                        }
                    } else if (gGameStatusPtr->heldButtons & 0x10000) {
                        if (printer->currentOption != 0) {
                            printer->targetOption = printer->currentOption - 1;
                            printer->windowState = 8;
                            printer->unkCounter = 1;
                            sfx_play_sound_with_params(0xCA, 0, 0, 0);
                        }
                    }
                }
                if (printer->windowState == 8) {
                    goto block_65;
                }
            }
        } else {
            if (!(printer->stateFlags & 0x20)) {
                if (printer->windowState == 5) {
                    if ((gGameStatusPtr->pressedButtons & 0x8000) != 0) {
                        printer->windowState = 4;
                        printer->currentPrintDelay = 0;
                        printer->stateFlags |= 4;
                    }
                }
            }
        }

        if (printer->stateFlags & 4) {
            phi_a1_2 = 0;
            if ((gGameStatusPtr->currentButtons & 0x8000) == 0) {
                printer->stateFlags &= ~0x4;
            }
        }

        do {
            temp_a1_3 = phi_a1_2 + 1;
            if (printer->animTimers[0] > 0) {
                printer->animTimers[0]--;
            }
            phi_a0_4 += 2;
            phi_a1_2 = temp_a1_3;
        } while ((temp_a1_3 < 4) != 0);


        switch (printer->windowState) {
            case 1:
    block_84:
    block_85:
                if (printer->windowState == 1) {
                    printer->windowState = 4;
                    phi_a1_3 = printer->charsPerChunk;
                    printer->currentPrintDelay = 0;
                } else {
                    if (printer->stateFlags & 0x100) {
                        phi_a1_3 = 0xC;
                        printer->currentPrintDelay = 0;
                    }
                    phi_a1_3 = printer->charsPerChunk;
                    if (!(printer->stateFlags & 0x4)) {
                        if (!(printer->stateFlags & 0x30)) {
                            if (gGameStatusPtr->currentButtons & 0x8000) {
                                phi_a1_3 = 6;
                                printer->currentPrintDelay = 0;
                            }
                        }
                    }
                }
                if ((printer->currentPrintDelay == 0) || (printer->currentPrintDelay--, (printer->currentPrintDelay == 0))) {
                    msg_copy_to_print_buffer(printer, phi_a1_3, 0);
                }
                goto block_135;
            case 4:
                temp_v0_5 = gGameStatusPtr;
                if ((temp_v0_5->pressedButtons & 0x8000) | (temp_v0_5->currentButtons & 0x4000)) {
                    if (!(printer->stateFlags & 0x30) && ((phi_s1 & 0xFF) == 0)) {
                        printer->stateFlags |= 0x100;
                        goto block_84;
                    }
                }
                goto block_85;
            case 6:
                if ((gGameStatusPtr->pressedButtons & 0xC000) != 0) {
                    if (!(printer->stateFlags & 0x30)) {
                        printer->stateFlags |= 0x100;
                    }
                }

                printer->curLinePos += printer->unk_464;
                if ((printer->stateFlags & 0x100) || ((!(printer->stateFlags & 0x14)) && ((gGameStatusPtr->currentButtons & 0x8000) != 0))) {
                    printer->curLinePos += 6;
                }

                if (printer->curLinePos >= printer->nextLinePos) {
                    printer->windowState = 4;
                    printer->curLinePos = printer->nextLinePos;
                    printer->stateFlags |= 4;
                    if (((printer->style - 7) < 2U) || (printer->srcBuffer[printer->srcBufferPos] == 0xF1)) {
                        printer->currentPrintDelay = 0;
                    } else {
                        printer->currentPrintDelay = 5;
                    }
                    printer->lineEndPos[printer->currentLine] = printer->unk_462;
                }
                goto block_135;
            case 11:
                printer->unk_4CC++;
                phi_v1 = printer->curLinePos - printer->lineEndPos[printer->unkArraySize];
                if (phi_v1 < 0) {
                    phi_v1 = -phi_v1;
                }
                if (printer->unk_4C8 < 0x11U) {
                    if (phi_v1 < 0xF) {
                        phi_a0_5 = 2;
                        if (!(phi_v1 < 9)) {
                            phi_a0_5 = 3;
                        }
                    } else {
                        phi_a0_5 = 4;
                    }
                } else if (phi_v1 > 96) {
                    phi_a0_5 = 10;
                } else if (phi_v1 > 48) {
                    phi_a0_5 = 9;
                } else if (phi_v1 >= 24) {
                    phi_a0_5 = 7;
                } else if (phi_v1 >= 16) {
                    phi_a0_5 = 5;
                } else {
                    if (phi_v1 >= 8) {
                        phi_a0_5 = 4;
                    }
                    phi_a0_5 = 2;
                    if (!(phi_v1 < 5)) {
                        phi_a0_5 = 3;
                    }
                }

                printer->unk_4CA = phi_a0_5;
                if (printer->lineEndPos[printer->unkArraySize] >= printer->curLinePos) {
                    printer->curLinePos += phi_a0_5;
                    if (printer->curLinePos >= printer->lineEndPos[printer->unkArraySize]) {
                        printer->curLinePos = printer->lineEndPos[printer->unkArraySize];
                        printer->windowState = 0xC;
                        if (printer->unkArraySize == printer->currentLine) {
                            printer->windowState = 5;
                            printer->rewindArrowAnimState = 0;
                            printer->rewindArrowBlinkCounter = 0;
                        }
                    }
                } else {
                    printer->curLinePos -= phi_a0_5;
                    if (printer->lineEndPos[printer->unkArraySize] >= printer->curLinePos) {
                        printer->curLinePos = printer->lineEndPos[printer->unkArraySize];
                        printer->windowState = 0xC;
                    }
                }
            default:
            block_135:
                if (printer->stateFlags & 1) {
                    printer->windowState = 0;
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
                        *printer->closedWritebackBool = 1;
                        printer->closedWritebackBool = NULL;
                    }
                }
        }
    }
    return printer->windowState;
}
#else
INCLUDE_ASM(s32, "msg", _update_message, MessagePrintState* msgPrintState);
#endif

void render_messages(void) {
    Matrix4s* matrix = &gMessageWindowProjMatrix[gCurrentDisplayContextIndex];
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMessagePrinters); i++) {
        if (gMessagePrinters[i].stateFlags & 0x2) {
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
        if (gMessagePrinters[i].stateFlags & 0x2) {
            draw_message_window(&gMessagePrinters[i]);

            if (gMessagePrinters[i].windowState == 5) {
                if (!(gMessagePrinters[i].stateFlags & 0x8000) && !(gMessagePrinters[i].stateFlags & 0x40)) {
                    msg_update_rewind_arrow(i);
                }
            } else if (gMessagePrinters[i].windowState == 0xC) {
                msg_draw_rewind_arrow(i);
            } else if (gMessagePrinters[i].windowState == 7 || gMessagePrinters[i].windowState == 8 ||
                       gMessagePrinters[i].stateFlags & 0x10000 || gMessagePrinters[i].stateFlags & 0x20000) {
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
    s32 hundred = 100;

    if (printer->stateFlags & 0x800000 && !(printer->delayFlags & 6) && printer->volume != 0) {
        volTemp = (f32)printer->volume / 100.0;
        pitchShift = ((character % 20) * 10) + (printer->speechVolumePitch - hundred);
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
    printer->printBuffer[0] = 0xFB; // next (TODO: make enum for this)
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
    printer->windowState = 0;
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

s32* load_message_to_buffer(s32 msgID) {
    s32* prevBufferPos;

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

#ifdef NON_MATCHING
MessagePrintState* _msg_get_printer_for_msg(s32 msgID, s32* donePrintingWriteback, s32 arg2) {
    if (msgID != 0) {
        s8* srcBuffer = (s8*) msgID;
        s32 i;

        if (msgID >= 0) {
            srcBuffer = load_message_to_buffer(srcBuffer);
        }

        for (i = 0; i < ARRAY_COUNT(gMessagePrinters); i++) {
            MessagePrintState* printer = &gMessagePrinters[i];

            if (!(printer->stateFlags & 2)) {
                s32 height;
                s32 width;
                s32 maxLineChars;
                s32 numLines;
                s32 maxLinesPerPage;

                initialize_printer(printer, 1, arg2);
                printer->windowState = 1;
                printer->srcBuffer = srcBuffer;
                printer->msgID = msgID;
                printer->stateFlags |= 2;
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
    }
    return NULL;
}
#else
INCLUDE_ASM(MessagePrintState*, "msg", _msg_get_printer_for_msg, s32 msgID, s32* donePrintingWriteback, s32 arg2);
#endif

s32 msg_printer_load_msg(s32 msgID, MessagePrintState* printer) {
    s32* buffer;

    if (msgID >= 0) {
        buffer = load_message_to_buffer(msgID);
    } else {
        buffer = (s32*) msgID;
    }

    printer->srcBuffer = buffer;
    printer->srcBufferPos = 0;
    printer->stateFlags &= ~0x40;
    return 1;
}

void msg_printer_set_origin_pos(MessagePrintState* msgPrintState, s16 x, s16 y) {
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
    if ((msgPrintState->stateFlags & 2) == 0) {
        return 0;
    }

    msgPrintState->stateFlags |= 1;
    return 1;
}

void set_message_images(UnkImage14List images) {
    *gMsgVarImages = images;
}

// loop crap
#ifdef NON_MATCHING
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

    int_to_string(value, &strBuffer, 10);

    for (i = 0, bufferIt = strBuffer; i < ARRAY_COUNT(gMessageMsgVars[index]) - 1; i++) {
        s8 thisChar = bufferIt[i];

        if (thisChar == 0) {
            break;
        }
        gMessageMsgVars[index][i] = thisChar - 0x20;
    }
    gMessageMsgVars[index][i] = 0xFD;
}

void close_message(MessagePrintState* msgPrintState) {
    msgPrintState->stateFlags &= ~0x40;
}

// so close, just some dumb control flow thing at the beginning
s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags);
#ifdef NON_MATCHING
s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags) {
    u8* charWidthTable;
    f32 baseWidth;
    f64 charWidth;
    f64 modifier;

    if (character < 0xF0 || (character == 0xF7 || character == 0xF8 || character == 0xF9)) {
        if (overrideCharWidth != 0) {
            baseWidth = overrideCharWidth;
        } else if (flags != 0 && gMsgCharsets[charset]->rasters[variation].charWidthTable != NULL &&
                    character != 0xF7 && character != 0xF8 && character != 0xF9) {
            baseWidth = gMsgCharsets[charset]->rasters[variation].charWidthTable[character];
        } else {
            baseWidth = gMsgCharsets[charset]->rasters[variation].monospaceWidth;
        }

        if (character == 0xF7) {
            charWidth = baseWidth * msgScale;
            modifier = 0.6;
            return charWidth * modifier;
        }
        if (character == 0xF8) {
            charWidth = baseWidth * msgScale;
            return charWidth;
        }
        if (character == 0xF9) {
            charWidth = baseWidth * msgScale;
            modifier = 0.5;
            return charWidth * modifier;
        }
        if (character < 0xF0) {
            return baseWidth * msgScale;
        }
    }
    return 0;
}
#else
INCLUDE_ASM(s32, "msg", msg_get_print_char_width, s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags);
#endif

s32 msg_get_draw_char_width(s32 character, s32 charset, s32 varaition, f32 msgScale, s32 overrideCharWidth, s32 flags);
INCLUDE_ASM(s32, "msg", msg_get_draw_char_width, s32 character, s32 charset, s32 varaition, f32 msgScale, s32 overrideCharWidth, s32 flags);

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

// some weird stacky msgIDy stuff
#ifdef NON_MATCHING
void draw_msg(s32 msgID, s32 posX, s32 posY, s32 opacity, s32 palette, u8 style) {
    s32 width;
    MessagePrintState stackPrinter;
    MessagePrintState* printer;
    u16 bufferPos;
    s32* mallocSpace;
    s32 charset;
    s32 flags;

    flags = 0;
    bufferPos = 0;
    mallocSpace = NULL;
    charset = 0;

    if (msgID != 0) {
        if (style & 1) {
            flags = 2;
            charset = 1;
        }

        if (opacity < 0xFF) {
            flags |= 1;
        }

        printer = &stackPrinter;
        initialize_printer(printer, 1, 0);

        if (msgID < 0) {
            printer = (MessagePrintState*)msgID;
        } else {
            mallocSpace = general_heap_malloc(0x400);
            dma_load_msg(msgID, mallocSpace);
            printer->srcBuffer = mallocSpace;
            get_msg_properties(msgID, 0, &width, 0, 0, 0, 0, charset);
            printer->msgWidth = width;
        }

        if (palette >= 0) {
            printer->printBuffer[bufferPos++] = 0xFF;
            printer->printBuffer[bufferPos++] = 4;
            printer->printBuffer[bufferPos++] = palette;
            printer->printBufferPos += 3;
        }

        if (style & 2) {
            printer->printBuffer[bufferPos++] = 0xFF;
            printer->printBuffer[bufferPos++] = 0x1C;
            printer->printBuffer[bufferPos++] = 8;
            printer->printBufferPos += 3;
        }

        if (style & 4) {
            printer->printBuffer[bufferPos++] = 0xFF;
            printer->printBuffer[bufferPos++] = 0x1C;
            printer->printBuffer[bufferPos++] = 9;
            printer->printBufferPos += 3;
        }

        if (style & 8) {
            printer->printBuffer[bufferPos++] = 0xFF;
            printer->printBuffer[bufferPos++] = 0x1C;
            printer->printBuffer[bufferPos++] = 0xE;
            printer->printBufferPos += 3;
        }

        msg_copy_to_print_buffer(printer, 10000, 1);
        appendGfx_message(printer, posX, posY, 0, 0, flags, opacity);

        if (mallocSpace != NULL) {
            general_heap_free(mallocSpace);
        }
    }
}
#else
INCLUDE_ASM(void, "msg", draw_msg, s32 msgID, s32 posX, s32 posY, s32 opacity, s32 palette, s32 style);
#endif

INCLUDE_ASM(s32, "msg", msg_update_rewind_arrow);

void msg_draw_rewind_arrow(s32 printerIndex) {
    MessagePrintState* printer = &gMessagePrinters[printerIndex];

    if (printer->rewindArrowBlinkCounter < 6) {
        draw_ci_image_with_clipping(&D_802ED550, 0x18, 0x18, 2, 0, &D_802ED670, printer->rewindArrowPos.x,
                                    printer->rewindArrowPos.y, 10, 10, 300, 220, 255);
    }

    printer->rewindArrowBlinkCounter++;
    if (printer->rewindArrowBlinkCounter >= 12) {
        printer->rewindArrowBlinkCounter = 0;
    }
}

INCLUDE_ASM(s32, "msg", msg_draw_choice_pointer);

INCLUDE_ASM(s32, "msg", draw_digit);

INCLUDE_ASM(void, "msg", draw_number, s32 value, s32 x, s32 y, s32 arg3, s32 palette, s32 opacity, s32 style);

void drawbox_message_delegate(MessagePrintState* printer) {
    appendGfx_message(printer, 0, 0, 0, 0, 4, 0);
}

void draw_message_window(MessagePrintState* printer) {
    f32 scale = 1.0f;
    s32 rotZ = 0;

    switch (printer->windowState) {
        case 0xD:
            scale = (f32)D_8014C580[printer->fadeInCounter] / 100.0;
            rotZ = (4 - printer->fadeInCounter) * 3;
            printer->fadeInCounter++;
            if (D_8014C580[printer->fadeInCounter] == 0) {
                printer->windowState = 4;
            }
            break;
        case 0xE:
            scale = (f32)D_8014C588[printer->fadeOutCounter] / 100.0;
            rotZ = -printer->fadeOutCounter;
            printer->fadeOutCounter++;
            if (D_8014C588[printer->fadeOutCounter] == 0) {
                printer->stateFlags |= 1;
            }
            break;
    }

    switch (printer->windowState) {
        case 0xD:
        case 0xE:
            printer->windowBasePos.x = 160 - (printer->windowSize.x / 2);
            printer->windowBasePos.y = 56;
            draw_box(1, 0, printer->windowBasePos.x, 56, 0, printer->windowSize.x, printer->windowSize.y, 255, 0,
                     scale, scale, 0.0f, 0.0f, rotZ, drawbox_message_delegate, printer, NULL, SCREEN_WIDTH,
                     SCREEN_HEIGHT, NULL);
            break;
        default:
            appendGfx_message(printer, printer->windowOffsetPos.x, printer->windowOffsetPos.y, printer->unk_46C,
                              printer->curLinePos, 4, 0);
            break;
    }
}

extern s32 D_8015131C;
extern MessageDrawState D_80155D20;
extern s32 D_80159B50;
extern s32 D_8015C7E0;
extern s16 D_802EB644[22];
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

#ifdef NON_MATCHING
void msg_draw_speech_bubble(MessagePrintState* printer, s32 posX, s32 posY, s32 straightWidth, s32 curveWidth,
                            s32 height, f32 scaleX, f32 scaleY, u8 opacity);

void appendGfx_message(MessagePrintState* printer, s16 posX, s16 posY, u16 additionalOffsetX, u16 additionalOffsetY, u16 flag, u8 alpha) {
    SpriteRasterInfo sp50;
    s16 sp66;
    s16 sp6E;
    u16 sp76;
    u16 sp7E;
    u16 sp80bool;
    u16 sp8E;
    u16 sp96;
    s16 sp9E;
    s16 spA6;
    s16 spAE;
    u16 spB6;
    u8 spB8;
    f32 spBC;
    s32 *spC0;
    MessageCharData *temp_a3_4;
    MessageCharset *temp_t0_2;
    f32 temp_f10;
    f32 temp_f20;
    f32 temp_f20_3;
    f32 temp_f22_2;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f2_2;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f4_3;
    f32 temp_f6_3;
    f32 temp_f6_4;
    f32 temp_f8;
    f32 temp_f8_2;
    f32 temp_f8_3;
    f32 temp_f8_4;
    f32 temp_f8_5;
    f64 temp_f0;
    u32 temp_f0_2;
    f64 temp_f0_4;
    f64 temp_f0_5;
    f64 temp_f20_2;
    f64 temp_f22;
    f64 temp_f2;
    f64 temp_f2_3;
    f64 temp_f2_4;
    f64 temp_f2_5;
    f64 temp_f2_6;
    f64 temp_f4;
    f64 temp_f4_2;
    f64 temp_f4_4;
    f64 temp_f4_5;
    f64 temp_f6;
    f64 temp_f6_2;
    s16 temp_a1_20;
    s16 temp_lo;
    s16 temp_s0_2;
    s16 temp_s0_3;
    s16 temp_s0_7;
    s16 temp_s0_8;
    s16 temp_s1_2;
    s16 temp_s1_6;
    s32 temp_a0_32;
    s32 temp_a0_44;
    s32 temp_a0_45;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a2;
    s32 temp_f12_2;
    s32 temp_f12_4;
    s32 temp_f12_6;
    s32 temp_f12_7;
    s32 temp_f12_8;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s1;
    s32 temp_s1_3;
    s32 temp_s1_4;
    s32 temp_s1_5;
    s32 temp_s1_7;
    s32 temp_s1_8;
    s32 i;
    s16 temp_s3;
    s32 temp_s3_3;
    s32 temp_s3_4;
    s16 temp_s4;
    s32 temp_s4_2;
    s32 temp_v0_65;
    s32 temp_v0_68;
    s32 temp_v0_69;
    s8 *temp_a1_11;
    u8 *temp_a2_2;
    s8 *temp_v1_27;
    s8 *temp_v1_30;
    s8 *temp_v1_33;
    s8 *temp_v1_34;
    s8 *temp_v1_35;
    s8 *temp_v1_57;
    s8 *temp_v1_58;
    u16 temp_s2;
    u16 temp_s3_2;
    s16 temp_s5;
    s16 temp_s6;
    u16 temp_v0_25;
    u16 temp_v1_20;
    u32 temp_a0_49;
    u8 temp_a0_10;
    u8 temp_a0_15;
    u8 temp_a0_16;
    u8 envColor;
    u8 temp_a0_51;
    u8 temp_a1_25;
    u8 temp_a1_26;
    u8 temp_a1_6;
    u8 temp_a3_3;
    u8 temp_s0_9;
    u8 temp_v0_16;
    u8 temp_v0_18;
    u8 temp_v0_22;
    u8 temp_v0_23;
    u8 temp_v0_27;
    u8 temp_v0_28;
    u8 temp_v0_33;
    u8 temp_v0_58;
    s16 temp_v0_70;
    u8 temp_v1_15;
    u8 temp_v1_18;
    u8 temp_v1_19;
    u8 temp_v1_69;
    UnkImage14 *msgVarImage;
    UnkImage14 *temp_t4;
    s32 phi_s0;
    s32 phi_a2;
    s32 phi_a0;
    s16 phi_a2_2;
    s16 phi_a0_2;
    s16 phi_s0_3;
    s32 phi_v1_2;
    s32 phi_s2_2;
    s32 phi_s1_3;
    s16 phi_a0_3;
    s16 phi_s0_4;
    u16 phi_s2_3;
    u16 phi_s3;
    s32 phi_s5;
    s32 phi_s4;
    s32 fading;
    s32 phi_s0_5;
    u16 phi_t8;
    s32 *phi_s6;
    s32 phi_s1_5;
    s32 phi_s2_4;
    s32 phi_s3_2;
    s32 phi_v0_3;
    s32 phi_a0_4;
    u16 phi_t5;
    u16 phi_s0_6;
    u16 phi_t3;
    s32 phi_a0_6;
    s32 phi_a0_7;
    s16 phi_s1_6;
    s32 phi_a0_14;
    s16 phi_s2_5;
    f64 phi_f2;
    f32 phi_f8;
    s16 charPosX;
    s16 charPosY;
    s32 phi_s0_7;
    s32 phi_s1_8;
    s16 phi_v0_16;
    s32 varImgHasBorderCond;
    u8 phi_s0_8;
    s16 phi_s1_9;
    s32 phi_a0_17;
    s16 phi_s2_7;
    s16 phi_s1_10;
    f32 phi_f2_2;
    s16 phi_s3_4;
    f32 phi_f0;
    u8 phi_s0_10;
    s32 varImgHasBorder;

    sp66 = posX;
    sp6E = posY;
    sp76 = additionalOffsetX;
    sp7E = additionalOffsetY;
    msg_drawState = &D_80155D20;
    msg_drawState->printBuffer = printer->printBuffer;
    msg_drawState->printModeFlags = 0;
    if (gMasterGfxPos != D_80151338) {
        msg_reset_gfx_state();
    }
    msg_drawState->printModeFlags |= (0x100 | 1);
    sp8E = 0xFF;
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
    msg_drawState->nextCounter = 0;
    msg_drawState->nextPos[0] = 0;
    msg_drawState->nextPos[1] = 0;
    msg_drawState->font = 0;
    msg_drawState->effectFlags = 0;
    msg_drawState->textColor = 0;
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

    msg_drawState->drawBufferPos = 0;
    sp80bool = FALSE;

    do {
        switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos]) {
            case 0xF0:
                msg_drawState->nextPos[0] = 0;
                msg_drawState->nextPos[1] += (s32) ((msg_drawState->msgScale.y * gMsgCharsets[msg_drawState->font]->newLineY) + D_802EB644[printer->style]);
                if (msg_drawState->printModeFlags & 0x40) {
                    msg_drawState->printModeFlags |= 0x80;
                }
                msg_drawState->drawBufferPos++;
                break;
            case 0xF9:
                msg_drawState->drawBufferPos++;
                break;
            case 0xF1:
            case 0xF2:
            case 0xF3:
            case 0xF4:
                msg_drawState->fontVariant = msg_drawState->printBuffer[msg_drawState->drawBufferPos] - 0xF1;
                msg_drawState->drawBufferPos++;
                break;
            case 0xF5:
            case 0xF6:
            case 0xF7:
                msg_drawState->nextPos[0] += msg_get_draw_char_width(msg_drawState->printBuffer[msg_drawState->drawBufferPos], msg_drawState->font, msg_drawState->fontVariant, msg_drawState->msgScale.x, msg_drawState->currentPosX, msg_drawState->printModeFlags);
                msg_drawState->drawBufferPos++;
                break;
            case 0xF8:
                switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]) {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        if (printer->windowState == 2 && printer->fadeInCounter == 0) {
                            printer->openStartPos.x = printer->initOpenPos.x;
                            printer->openStartPos.y = printer->initOpenPos.y;
                        }
                        temp_s6 = printer->openStartPos.x;
                        temp_s5 = printer->openStartPos.y;
                        temp_s4 = printer->windowBasePos.x + ((f32) printer->windowSize.x * 0.5);
                        temp_s3 = printer->windowBasePos.y + ((f32) printer->windowSize.y * 0.5);
                        msg_drawState->textColor = 10;
                        msg_drawState->printModeFlags |= 0x10;
                        phi_s0_3 = 0xDA;

                        if (printer->style == 1 || printer->style == 2 || printer->style == 3) {
                            printer->windowBasePos.x = 22;
                            printer->windowBasePos.y = 13;
                            printer->windowSize.x = 296;
                            printer->windowSize.y = 68;
                            msg_drawState->textStartPos[0] = 26;
                            msg_drawState->textStartPos[1] = 6;
                            printer->rewindArrowPos.x = 276;
                            printer->rewindArrowPos.y = 57;
                            phi_s2_2 = 32;
                            phi_s1_3 = 68;
                        } else {
                            switch (printer->maxLinesPerPage) {
                                case 1:
                                    msg_drawState->textStartPos[0] = 18;
                                    msg_drawState->textStartPos[1] = 10;
                                    phi_s2_2 = 24;
                                    break;
                                case 2:
                                    msg_drawState->textStartPos[0] = 22;
                                    msg_drawState->textStartPos[1] = 6;
                                    phi_s2_2 = 28;
                                    break;
                                case 3:
                                    msg_drawState->textStartPos[0] = 26;
                                    msg_drawState->textStartPos[1] = 8;
                                    phi_s2_2 = 32;
                                    break;
                                default:
                                    msg_drawState->textStartPos[0] = 26;
                                    msg_drawState->textStartPos[1] = 6;
                                    phi_s2_2 = 32;
                                    break;
                            }

                            phi_s0 = printer->msgWidth;
                            if (phi_s0 > 256) {
                                phi_s0 = 256;
                            }
                            if (phi_s0 < 70) {
                                phi_s0 = 70;
                            }
                            temp_s0_2 = phi_s0 - 12;
                            printer->windowSize.x = temp_s0_2 + (phi_s2_2 * 2);
                            temp_s1 = (printer->maxLinesPerPage * 14) + 16;
                            phi_s0_3 = temp_s0_2;
                            if (temp_s1 > 68) {
                                temp_s1 = 68;
                            }
                            if (temp_s1 < 36) {
                                temp_s1 = 36;
                            }
                            temp_a2 = (u16) printer->openStartPos.x - printer->windowSize.x / 2;
                            printer->windowSize.y = temp_s1;
                            phi_a2 = temp_a2;
                            phi_s1_3 = (s32) temp_s1;
                            if (temp_a2 < 18) {
                                phi_a2 = 18;
                            }
                            phi_a2_2 = (s16) phi_a2;
                            if ((phi_a2 + printer->windowSize.x) > 302) {
                                phi_a2_2 = 302 - printer->windowSize.x;
                            }
                            temp_a0_5 = (u16) printer->openStartPos.y - (printer->windowSize.y + 38);
                            phi_a0 = temp_a0_5;
                            if (temp_a0_5 < 20) {
                                phi_a0 = 20;
                            }
                            phi_a0_2 = phi_a0;
                            if ((phi_a0 + printer->windowSize.y) > 170) {
                                phi_a0_2 = 170 - printer->windowSize.y;
                            }
                            printer->windowBasePos.x = phi_a2_2;
                            printer->windowBasePos.y = phi_a0_2;
                            printer->rewindArrowPos.x = (printer->windowSize.x + phi_a2_2) - 30;
                            printer->rewindArrowPos.y = (printer->windowSize.y + phi_a0_2) - 18;
                        }

                        if (printer->windowState == 11 || printer->windowState == 12) {
                            msg_drawState->framePalette = 1;
                        }

                        if (printer->windowState == 2) {
                            s32 blah;
                            spBC = update_lerp(0, 0.07f, 1.0f, printer->fadeInCounter, 7);
                            temp_f30 = update_lerp(0, 0.3f, 1.0f, printer->fadeInCounter, 7);
                            temp_f28 = update_lerp(0, 96.0f, 200.0f, printer->fadeInCounter, 7);
                            temp_f20 = update_lerp(11, temp_s5, temp_s3, printer->fadeInCounter, 7);
                            blah = update_lerp(11, temp_s6, temp_s4, printer->fadeInCounter, 7);

                            msg_draw_speech_bubble(printer, (s16) (s32) (f32) (((f64) blah - ((f64) ((f32) printer->windowSize.x * spBC) * 0.5)) + 0.5), (s16) (s32) (f32) (((f64) temp_f20 - ((f64) ((f32) printer->windowSize.y * temp_f30) * 0.5)) + 0.5), phi_s0_3, 0, 0, 1.0f, 1.0f, temp_f28);
                            printer->fadeInCounter++;
                            if (printer->fadeInCounter == 7) {
                                printer->windowState = 4;
                            }
                        } else if (printer->windowState == 3) {
                            printer->fadeOutCounter++;
                            spBC = update_lerp(0, 1.0f, 0.6f, printer->fadeOutCounter & 0xFF, 5);
                            temp_f2 = (f64) ((f32) printer->windowSize.x * spBC) * 0.5;
                            temp_f30_2 = update_lerp(0, 1.0f, 0.8f, printer->fadeOutCounter, 5);
                            temp_f0 = (f64) ((f32) printer->windowSize.y * temp_f30_2) * 0.5;
                            temp_f22 = (f64) (f32) (s16) temp_s4;
                            temp_f20_2 = (f64) (f32) (s16) temp_s3;
                            temp_f24 = (f32) ((temp_f22 - temp_f2) + 0.5);
                            temp_f22_2 = (f32) ((temp_f22 + temp_f2) - 0.5);
                            temp_f26 = (f32) ((temp_f20_2 - temp_f0) + 0.5);
                            temp_f20_3 = (f32) ((temp_f20_2 + temp_f0) - 0.5);
                            temp_f28_2 = update_lerp(0, 255.0f, 64.0f, printer->fadeOutCounter, 5);
                            temp_f6 = (f64) temp_f28_2 * 0.35;
                            temp_a0_6 = (s32) temp_f28_2;
                            spAE = (u16) temp_a0_6;
                            msg_drawState->clipX[0] = (s32) (temp_f24 + (f32) msg_drawState->textStartPos[0]);
                            msg_drawState->clipY[0] = (s32) (temp_f26 + (f32) msg_drawState->textStartPos[1]);
                            msg_drawState->clipX[1] = (s32) (temp_f22_2 - (f32) msg_drawState->textStartPos[0]);
                            msg_drawState->clipY[1] = (s32) (temp_f20_3 - (f32) msg_drawState->textStartPos[1]);
                            sp8E = (u16) (s32) temp_f6;

                            msg_draw_speech_bubble(printer, (s16) (s32) temp_f24, (s16) temp_f26, phi_s0_3, 0, 0, 1.0f, 1.0f, temp_f28_2);
                            if (printer->fadeOutCounter >= 5) {
                                printer->stateFlags |= 1;
                            }
                        } else {
                            msg_draw_speech_bubble(printer, (s16) (s32) (f32) (sp66 + printer->windowBasePos.x), (s16) (s32) (f32) (sp6E + printer->windowBasePos.y), phi_s0_3, phi_s2_2, phi_s1_3, 1.0f, 1.0f, 0xFF);
                            if (((u32) ((u16) printer->openStartPos.x - 20) <= 280) && ((u32) printer->openStartPos.y <= 220)) {
                                msg_draw_speech_arrow(printer);
                            }
                        }

                        if (printer->windowState != 3) {
                            msg_drawState->clipX[0] = 20;
                            msg_drawState->clipX[1] = 300;
                            msg_drawState->clipY[0] = printer->windowOffsetPos.y + printer->windowBasePos.y + msg_drawState->textStartPos[1];
                            msg_drawState->clipY[1] = (msg_drawState->clipY[0] + printer->windowSize.y) - 16;
                        }
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 19:
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 5:
                        temp_s2 = printer->windowSize.x;
                        temp_s3_2 = printer->windowSize.y;
                        msg_drawState->framePalette = 0;
                        msg_drawState->textStartPos[0] = 12;
                        msg_drawState->textStartPos[1] = 6;
                        phi_s2_3 = temp_s2;
                        phi_s3 = temp_s3_2;
                        phi_s5 = 0;
                        phi_s4 = 0xFF;
                        phi_s2_3 = temp_s2;
                        phi_s3 = temp_s3_2;
                        if (printer->windowState == 2) {
                            printer->fadeInCounter++;
                            if (printer->fadeInCounter == 6) {
                                printer->windowState = 4;
                            }
                            temp_f10 = (f32) (((f32) printer->fadeInCounter * (4.0 / 3.0)) + 0.2);
                            temp_f4 = (f64) ((f32) temp_s2 * temp_f10);
                            temp_f6_2 = (f64) ((f32) temp_s3_2 * temp_f10);
                            temp_f12_6 = (s32) (temp_f4 + 0.5);
                            temp_f12_7 = (s32) (temp_f6_2 + 0.5);
                            phi_s1_9 = (s16) (s32) ((f64) (f32) ((f64) (f32) (printer->windowBasePos.x + ((s32) (temp_s2 + ((u32) temp_s2 >> 0x1F)) >> 1)) - (temp_f4 * 0.5)) + 0.5);
                            phi_s0_4 = (s16) (s32) ((f64) (f32) ((f64) (f32) (printer->windowBasePos.y + ((s32) temp_s3_2 / 2)) - (temp_f6_2 * 0.5)) + 0.5);
                            phi_s2_3 = (u16) temp_f12_6;
                            phi_s3 = (u16) temp_f12_7;
                            if (temp_f12_6 < 0x18) {
                                phi_s2_3 = 0x18;
                            }
                            if (temp_f12_7 < 0x18) {
                                phi_s3 = 0x18;
                            }
                            temp_f0_2 = temp_f10 * 255.0;

                            sp8E = (u16) (s32) ((f64) temp_f0_2 * 0.6);
                            goto block_88;
                        }
                        if (printer->windowState == 3) {
                            printer->fadeOutCounter++;
                            if (printer->fadeOutCounter >= 5) {
                                printer->stateFlags |= 1;
                            }
                            temp_s4_2 = ~(printer->fadeOutCounter * 0x2E);
                            temp_f12_8 = (s32) ((f64) (temp_s4_2 & 0xFF) * 0.6);
                            sp8E = (u16) temp_f12_8;
                            phi_s5 = 1;
                            phi_s4 = temp_s4_2;
                            if ((s32) (s16) temp_f12_8 >= 32) {
                                sp8E = temp_f12_8 - 32;
                            }
                            phi_a0_3 = printer->windowBasePos.x;
                            phi_s0_4 = printer->windowBasePos.y;
                        } else {
                            temp_s1_2 = printer->windowBasePos.x;
                            temp_s0_3 = printer->windowBasePos.y;
                            msg_draw_prim_rect(255, 32, 32, 0, temp_s1_2 - 1, temp_s0_3 - 1, temp_s2 + 2, temp_s3_2 + 2);
                            phi_s1_9 = temp_s1_2;
                            phi_s0_4 = temp_s0_3;
        block_88:
                            phi_a0_3 = phi_s1_9;
                        }
                        msg_drawState->clipX[0] = phi_a0_3 + 2;
                        msg_drawState->clipY[0] = phi_s0_4 + 2;
                        msg_drawState->clipX[1] = (phi_a0_3 + phi_s2_3) - 2;
                        msg_drawState->clipY[1] = (phi_s0_4 + phi_s3) - 2;
                        msg_draw_frame(phi_a0_3, phi_s0_4, phi_s2_3, phi_s3, 5, (s32) (u8) msg_drawState->framePalette, phi_s5, phi_s4, phi_s4);
                        msg_reset_gfx_state();
                        spAE = phi_s4 & 0xFF;
                        msg_drawState->textColor = 0xA;
                        msg_drawState->drawBufferPos += 2;
                        msg_drawState->printModeFlags |= 0x10;
                        break;
                    case 6:
                    case 12:
                    case 13:
                    case 15:
                        msg_drawState->textStartPos[0] = 16;
                        msg_drawState->textStartPos[1] = 3;
                        msg_drawState->clipX[0] = printer->windowBasePos.x + 5;
                        msg_drawState->clipY[0] = printer->windowBasePos.y + 4;
                        msg_drawState->clipX[1] = printer->windowBasePos.x + printer->windowSize.x - 8;
                        msg_drawState->clipY[1] = printer->windowBasePos.y + printer->windowSize.y - 5;
                        printer->rewindArrowPos.x = msg_drawState->clipX[1] - 17;
                        printer->rewindArrowPos.y = msg_drawState->clipY[1] - 17;
                        msg_drawState->textColor = 0;
                        msg_draw_prim_rect(255, 32, 32, 0, printer->windowBasePos.x + 3, printer->windowBasePos.y - 1,printer->windowSize.x - 6, 1);
                        msg_draw_prim_rect(32, 255, 32, 0, printer->windowBasePos.x + 3, printer->windowBasePos.y + printer->windowSize.y, printer->windowSize.x - 6, 1);
                        temp_v0_16 = printer->windowState;
                        fading = 0;
                        phi_s0_5 = 0xFF;
                        if (temp_v0_16 == 2) {
                            temp_s0_4 = (printer->fadeInCounter * 0x30) + 0x50;
                            sp8E = (temp_s0_4 & 0xFF) - 0x30;
                            printer->fadeInCounter++;
                            fading = 1;
                            phi_s0_5 = temp_s0_4;
                            if (printer->fadeInCounter == 4) {
                                printer->windowState = printer->fadeInCounter;
                                fading = 1;
                            }
                        } else if (temp_v0_16 == 3) {
                            temp_s0_5 = -0x30 - ((printer->fadeOutCounter * 5) << 3);
                            sp8E = (temp_s0_5 & 0xFF) - 0x30;
                            printer->fadeOutCounter++;
                            fading = 1;
                            phi_s0_5 = temp_s0_5;
                            if (printer->fadeOutCounter == 4) {
                                printer->stateFlags |= 1;
                                fading = 1;
                            }
                        }

                        msg_draw_frame(printer->windowBasePos.x, printer->windowBasePos.y, printer->windowSize.x, printer->windowSize.y, 6, msg_drawState->framePalette, fading, phi_s0_5, phi_s0_5);
                        msg_reset_gfx_state();
                        spAE = phi_s0_5 & 0xFF;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 7:
                    case 8:
                        msg_drawState->textStartPos[0] = 0x12;
                        msg_drawState->textStartPos[1] = 0xB;
                        printer->windowBasePos.x = 20;
                        printer->windowBasePos.y = 28;
                        printer->windowSize.x = 280;
                        msg_drawState->framePalette = 0xF;
                        phi_s1_5 = 0xFF;
                        if (printer->style == 7) {
                            spC0 = &D_802EC770;
                            printer->windowSize.y = 72;
                            msg_drawState->textColor = 0x18;
                            phi_s6 = &D_802ECD10;
                        } else {
                            spC0 = &D_802EC7F0;
                            msg_drawState->textColor = 0x1C;
                            phi_s6 = &D_802ECD30;
                        }
                        msg_drawState->clipX[0] = 34;
                        msg_drawState->clipY[0] = 40;
                        msg_drawState->clipX[1] = 283;
                        msg_drawState->clipY[1] = printer->windowSize.y + 17;
                        printer->rewindArrowPos.x = msg_drawState->clipX[1] - 16;
                        printer->rewindArrowPos.y = msg_drawState->clipY[1] - 9;
                        temp_v1_15 = printer->windowState;
                        if (temp_v1_15 == 2) {
                            temp_v0_18 = printer->fadeInCounter;
                            temp_s1_3 = (temp_v0_18 << 6) + 0x50;
                            sp8E = (temp_s1_3 & 0xFF) - 0x30;
                            printer->fadeInCounter++;
                            phi_t8 = temp_s1_3 & 0xFF;
                            phi_s1_5 = temp_s1_3;
                            if (printer->fadeInCounter == 3) {
                                printer->windowState = 4;
                            }
                        } else {
                            phi_t8 = temp_s1_3 & 0xFF;
                            if (temp_v1_15 == 3) {
                                temp_s1_4 = -0x30 - (printer->fadeOutCounter * 0x30);
                                sp8E = (temp_s1_4 & 0xFF) - 0x30;
                                printer->fadeOutCounter++;
                                phi_t8 = temp_s1_4 & 0xFF;
                                phi_s1_5 = temp_s1_4;
                                if (printer->fadeOutCounter == 3) {
                                    printer->stateFlags |= 1;
                                }
                            }
                        }
                        spAE = phi_t8;
                        temp_s1_5 = phi_s1_5 & 0xFF;
                        draw_ci_image_with_clipping(&D_802EC5F0, 16, 16, 2, 0, phi_s6, 20, 28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(&D_802EC670, 16, 16, 2, 0, phi_s6, 284, 28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(&D_802EC6F0, 16, 16, 2, 0, phi_s6, 20, (s32) ((printer->windowSize.y + 12) << 0x10U) >> 0x10U, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(spC0, 16, 16, 2, 0, phi_s6, 284, (s32) ((printer->windowSize.y + 0xC) << 0x10U) >> 0x10U, 10, 10, 310, 230, temp_s1_5);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802EC870, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0090, 0x0070, 0x0470, 0x00B0, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802EC970, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0050, 0x00B0, 0x0090, printer->windowSize.y + 12, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802ECAB0, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0470, 0x00B0, 0x04B0, printer->windowSize.y + 12, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802ECBF0, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0090, printer->windowSize.y + 12, 0x0470, printer->windowSize.y + 12, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802ECCF0, G_IM_FMT_CI, 8, 0, 0, 0, 7, 7, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 3, 3, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0090, 0x00B0, 0x0470, printer->windowSize.y + 12, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        msg_reset_gfx_state();
                    case 9:
                        msg_drawState->textStartPos[0] = 0xC;
                        msg_drawState->textStartPos[1] = 5;
                        printer->windowBasePos.x = 40;
                        printer->windowBasePos.y = 28;
                        msg_drawState->clipX[0] = 45;
                        msg_drawState->clipY[0] = 32;
                        msg_drawState->clipX[1] = 272;
                        msg_drawState->clipY[1] = 81;
                        printer->rewindArrowPos.x = msg_drawState->clipX[1] - 0x15;
                        printer->rewindArrowPos.y = msg_drawState->clipY[1] - 0x14;
                        msg_drawState->framePalette = 0;
                        msg_drawState->textColor = 0;
                        msg_draw_prim_rect(255, 32, 32, 0, 43, 27, 234, 1);
                        msg_draw_prim_rect(32, 255, 32, 0, 43, 86, 234, 1);
                        temp_v0_22 = printer->windowState;
                        phi_s2_4 = 0;
                        phi_s3_2 = 0xFF;
                        if (temp_v0_22 == 2) {
                            temp_v0_23 = printer->fadeInCounter;
                            temp_s3_3 = (temp_v0_23 << 6) + 0x50;
                            sp8E = (temp_s3_3 & 0xFF) - 0x30;
                            printer->fadeInCounter++;
                            phi_s3_2 = temp_s3_3;
                            if (printer->fadeInCounter == 3) {
                                printer->windowState = 4;
                            }
                            goto block_113;
                        }
                        if (temp_v0_22 == 3) {
                            temp_a0_15 = printer->fadeOutCounter;
                            temp_s3_4 = -0x30 - (temp_a0_15 * 0x30);
                            temp_a0_16 = temp_a0_15 + 1;
                            sp8E = (temp_s3_4 & 0xFF) - 0x30;
                            printer->fadeOutCounter = temp_a0_16;
                            phi_s3_2 = temp_s3_4;
                            if ((temp_a0_16 & 0xFF) == 3) {
                                printer->stateFlags |= 1;
                            }
        block_113:
                            phi_s2_4 = 1;
                        }
                        // todo fix temp_s0_6 = phi_s3_2 & 0xFF;
                        msg_draw_frame(0x28, 0x1C, 0xF0U, 0x3AU, 6, (s32) (u8) msg_drawState->framePalette, phi_s2_4, phi_s3_2, phi_s3_2);
                        draw_ci_image_with_clipping(printer->letterBackgroundImg, 150, 105, 2, 0, printer->letterBackgroundPal, 85, 97, 10, 10, 300, 220, temp_s0_6);
                        draw_ci_image_with_clipping(printer->letterContentImg, 70, 95, 2, 1, printer->letterContentPal, 160, 102, 10, 10, 300, 220, temp_s0_6);
                        msg_reset_gfx_state();
                        spAE = phi_s3_2 & 0xFF;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 10:
                    case 11:
                        msg_drawState->textStartPos[0] = 0x10;
                        msg_drawState->textStartPos[1] = 4;
                        msg_drawState->clipX[0] = 0;
                        msg_drawState->clipX[1] = SCREEN_WIDTH - 1;
                        msg_drawState->clipY[0] = 0;
                        msg_drawState->clipY[1] = SCREEN_HEIGHT - 1;
                        msg_drawState->textColor = 0;
                        msg_drawState->printModeFlags |= 0x10;
                        if (printer->windowState == 13 || printer->windowState == 14) {
                            printer->windowBasePos.x = 0;
                            printer->windowBasePos.y = 0;
                        } else {
                            printer->windowBasePos.x = 160 - printer->windowSize.x / 2;
                            printer->windowBasePos.y = 56;
                            draw_box(0, 0, printer->windowBasePos.x, 56, 0, printer->windowSize.x, printer->windowSize.y, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
                        }
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 14:
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
            case 0xFA:
                temp_v1_18 = printer->windowState;
                if (temp_v1_18 == 0xC) {
                    if (msg_drawState->nextCounter >= printer->unkArraySize) {
                        sp80bool = TRUE;
                    }
                } else if (temp_v1_18 == 0xB) {
                    if (printer->curLinePos < (u16) printer->lineEndPos[printer->unkArraySize]) {
                        if (msg_drawState->nextCounter >= printer->unkArraySize) {
                            sp80bool = TRUE;
                        }
                    } else {
                        if (printer->unkArraySize < msg_drawState->nextCounter) {
                            sp80bool = TRUE;
                        } else if (msg_drawState->nextCounter >= printer->unkArraySize) {
                            temp_v1_19 = (u8) printer->maxLinesPerPage;
                            phi_a0_4 = 0x24;
                            if (temp_v1_19 >= 2) {
                                phi_v0_3 = 0x30;
                                if (temp_v1_19 == 2) {
                                    phi_v0_3 = 0x20;
                                }
                                temp_v1_20 = (u16) printer->unk_4C8;
                                if ((s32) temp_v1_20 < phi_v0_3) {
                                    if ((u32) temp_v1_20 < 0x11U) {
                                        phi_a0_4 = 0x38;
                                    }
                                    temp_v0_25 = 0xFF - (phi_a0_4 * (u16) printer->unk_4CC);
                                    sp8E = temp_v0_25;
                                    if (temp_v0_25 & 0x8000) {
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
            case 0xFB:
                sp80bool = TRUE;
                break;
            case 0xFF:
                msg_drawState->drawBufferPos++;
                switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos]) {
                    case 0:
                        temp_a1_6 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        msg_drawState->printModeFlags |= 0x10;
                        msg_drawState->font = (s16) temp_a1_6;
                        break;
                    case 1:
                        msg_drawState->fontVariant = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 4:
                        msg_drawState->textColor = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->printModeFlags |= 0x10;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 5:
                        msg_drawState->currentPosX = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 6:
                        temp_v0_27 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->msgScale.x = (f32) ((u32) temp_v0_27 >> 4) + ((f32) (temp_v0_27 & 0xF) * 0.0625f);
                        temp_v0_28 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                        temp_f2_2 = (f32) ((u32) temp_v0_28 >> 4) + ((f32) (temp_v0_28 & 0xF) * 0.0625f);
                        temp_f4_2 = (f64) msg_drawState->msgScale.x;
                        msg_drawState->drawBufferPos += 3;
                        msg_drawState->msgScale.y = temp_f2_2;
                        if (temp_f4_2 > 1.0 || temp_f2_2 > 1.0) {
                            gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
                        } else if (temp_f4_2 < 1.0 || temp_f2_2 < 1.0) {
                            gDPSetTextureFilter(gMasterGfxPos++, G_TF_AVERAGE);
                        }
                        break;
                    case 7:
                        msg_drawState->msgScale.x = 1.0f;
                        msg_drawState->msgScale.y = 1.0f;
                        msg_drawState->drawBufferPos++;
                        gDPSetTextureFilter(gMasterGfxPos++, G_TF_AVERAGE);
                        break;
                    case 8:
                        temp_v1_27 = &msg_drawState->printBuffer[msg_drawState->drawBufferPos];
                        msg_drawState->nextPos[0] = temp_v1_27[2] + (temp_v1_27[1] << 8);
                        msg_drawState->drawBufferPos += 3;
                        break;
                    case 9:
                        msg_drawState->nextPos[1] = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 10:
                        msg_drawState->nextPos[0] += msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 11:
                        msg_drawState->nextPos[1] += msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 12:
                        msg_drawState->nextPos[1] -=  msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 14:
                        temp_t4 = &(*gMsgVarImages)[msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]];
                        phi_t5 = sp8E;
                        if ((s32) (s16) sp8E < 0xFF) {
                            phi_t5 = (u16) (s32) ((f64) (s16) sp8E * 0.7);
                        }
                        draw_ci_image_with_clipping(temp_t4->raster, temp_t4->width, temp_t4->height, temp_t4->format, temp_t4->bitDepth, temp_t4->palette, (s32) (s16) (((u16) msg_drawState->nextPos[0] + ((u16) msg_drawState->textStartPos[0] + ((u16) printer->windowBasePos.x + (u16) sp66))) - sp76), (s32) (s16) (((u16) msg_drawState->nextPos[1] + ((u16) msg_drawState->textStartPos[1] + ((u16) printer->windowBasePos.y + (u16) sp6E))) - sp7E), (s32) msg_drawState->clipX[0], (s32) msg_drawState->clipY[1], (msg_drawState->clipX[1] - msg_drawState->clipX[0]) & 0xFFFF, (msg_drawState->clipY[1] - msg_drawState->clipY[0]) & 0xFFFF, phi_t5 & 0xFF);
                        msg_drawState->printModeFlags |= 0x10 | 0x2;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 15:
                        phi_s0_6 = sp8E;
                        if ((s32) (s16) sp8E < 0xFF) {
                            phi_s0_6 = (u16) (s32) ((f64) (s16) sp8E * 0.7);
                        }
                        temp_v1_30 = &msg_drawState->printBuffer[msg_drawState->drawBufferPos];
                        if (spr_get_npc_raster_info(&sp50, (temp_v1_30[1] << 8) | temp_v1_30[2], temp_v1_30[3]) != 0) {
                            draw_ci_image_with_clipping(sp50.raster, sp50.width, sp50.height, 2, 0, sp50.defaultPal, (s32) (s16) (((u16) msg_drawState->nextPos[0] + ((u16) msg_drawState->textStartPos[0] + ((u16) printer->windowBasePos.x + (u16) sp66))) - sp76), (s32) (s16) (((u16) msg_drawState->nextPos[1] + ((u16) msg_drawState->textStartPos[1] + ((u16) printer->windowBasePos.y + (u16) sp6E))) - sp7E), (s32) msg_drawState->clipX[0], (s32) msg_drawState->clipY[0], (msg_drawState->clipX[1] - msg_drawState->clipX[0]) & 0xFFFF, (msg_drawState->clipY[1] - msg_drawState->clipY[0]) & 0xFFFF, phi_s0_6 & 0xFF);
                            msg_drawState->printModeFlags |= 0x10;
                        }
                        msg_drawState->drawBufferPos += 4;
                        break;
                    case 16:
                        if (D_8015131C != 0) {
                            phi_t3 = sp8E;
                            if ((s32) (s16) sp8E < 0xFF) {
                                phi_t3 = (u16) (s32) ((f64) (s16) sp8E * 0.7);
                            }
                            draw_ci_image_with_clipping(&D_80159B50, 0x20U, 0x20U, 2, 0, &D_8015C7E0, (s32) (s16) (((u16) msg_drawState->nextPos[0] + ((u16) msg_drawState->textStartPos[0] + ((u16) printer->windowBasePos.x + (u16) sp66))) - sp76), (s32) (s16) (((u16) msg_drawState->nextPos[1] + ((u16) msg_drawState->textStartPos[1] + ((u16) printer->windowBasePos.y + (u16) sp6E))) - sp7E), (s32) msg_drawState->clipX[0], (s32) msg_drawState->clipY[0], (msg_drawState->clipX[1] - msg_drawState->clipX[0]) & 0xFFFF, (msg_drawState->clipY[1] - msg_drawState->clipY[0]) & 0xFFFF, phi_t3 & 0xFF);
                            msg_drawState->printModeFlags |= 0x10;
                        }
                        msg_drawState->drawBufferPos++;
                        break;
                    case 17:
                        temp_a1_11 = &msg_drawState->printBuffer[msg_drawState->drawBufferPos];
                        temp_a3_3 = temp_a1_11[1];
                        if (printer->animTimers[temp_a3_3] == -1) {
                            printer->animTimers[temp_a3_3] = (s16) temp_a1_11[3];
                        }
                        if (printer->animTimers[temp_a3_3] == 0) {
                            printer->currentAnimFrame[temp_a3_3] = (u8) printer->currentAnimFrame[temp_a3_3] + 1;
                        }
        loop_175:
                        phi_a0_6 = msg_drawState->drawBufferPos;
        loop_176:
                        temp_v1_33 = &msg_drawState->printBuffer[phi_a0_6];
                        phi_a0_7 = phi_a0_6;
                        if ((temp_v1_33[-1] == 0xFF) && ((u8) temp_v1_33[0] == 0x11) && (temp_v1_33[1] == temp_a3_3)) {
                            if (temp_v1_33[2] != (u8) printer->currentAnimFrame[temp_a3_3]) {
                                phi_a0_17 = phi_a0_6 + 4;
                                phi_a0_6 = phi_a0_17 + 1;
                                goto loop_176;
                            }
                        } else {
                            temp_v1_34 = &msg_drawState->printBuffer[phi_a0_6];
                            if ((u8) temp_v1_34[0] != 0xFF) {
                                phi_a0_6 += 1;
                                goto loop_176;
                            }
                            if ((temp_v1_34[1] == 0x12) && (temp_v1_34[2] == temp_a3_3)) {
                                phi_a0_7 = phi_a0_6 + 1;
                                if (printer->animTimers[temp_a3_3] == 0) {
                                    printer->currentAnimFrame[temp_a3_3] = (s8) temp_v1_34[3];
                                    goto loop_175;
                                }
                            } else {
                                temp_v1_35 = &msg_drawState->printBuffer[phi_a0_6];
                                if ((u8) temp_v1_35[0] != 0xFF) {
                                    phi_a0_6 += 1;
                                    goto loop_176;
                                }
                                if (temp_v1_35[1] != 0x13) {
                                    phi_a0_6 += 1;
                                    goto loop_176;
                                }
                                temp_a0_32 = phi_a0_6 + 1;
                                phi_a0_7 = temp_a0_32;
                                phi_a0_17 = temp_a0_32;
                                if (temp_v1_35[2] != temp_a3_3) {
                                    phi_a0_6 = phi_a0_17 + 1;
                                    goto loop_176;
                                }
                            }
                        }
                        msg_drawState->drawBufferPos = phi_a0_7;
                        temp_a2_2 = &msg_drawState->printBuffer[msg_drawState->drawBufferPos];

                        switch (temp_a2_2[0]) {
                            case 0x11:
                                if (printer->animTimers[temp_a3_3] == 0) {
                                    if (temp_a2_2[3] == 0) {
                                        printer->animTimers[temp_a3_3] = -2;
                                    } else {
                                        printer->animTimers[temp_a3_3] = temp_a2_2[3];
                                    }
                                }
                                msg_drawState->drawBufferPos += 4;
                                break;
                            case 0x12:
                                msg_drawState->drawBufferPos += 3;
                                break;
                            case 0x13:
                                msg_drawState->drawBufferPos += 2;
                                break;
                        }
                        break;
                    case 18:
                        msg_drawState->drawBufferPos += 3;
                        break;
                    case 20:
                        printer->cursorPosX[msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]] = (((u16) msg_drawState->textStartPos[0] + (u16) msg_drawState->nextPos[0]) - sp76) - 6;
                        printer->cursorPosY[msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]] = (((u16) msg_drawState->textStartPos[1] + (u16) msg_drawState->nextPos[1]) - sp7E) - 1;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 21:
                        temp_v0_33 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        if (temp_v0_33 != 0xFF) {
                            msg_drawState->unk_2D = (s8) temp_v0_33;
                            msg_drawState->printModeFlags |= 0x20;
                            msg_drawState->nextPos[0] += 0xE;
                        } else {
                            msg_drawState->printModeFlags &= ~0x20;
                        }
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 22:
                        msg_drawState->framePalette = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 23:
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos++;
                        break;
                    case 24:
                        msg_drawState->savedPos[0] = msg_drawState->nextPos[0];
                        msg_drawState->savedPos[1] = msg_drawState->nextPos[1];
                        msg_drawState->drawBufferPos++;
                        break;
                    case 25:
                        msg_drawState->nextPos[0] = msg_drawState->savedPos[0];
                        msg_drawState->nextPos[1] = msg_drawState->savedPos[1];
                        msg_drawState->drawBufferPos++;
                        break;
                    case 26:
                        msg_drawState->savedColor = msg_drawState->textColor;
                        msg_drawState->drawBufferPos++;
                        break;
                    case 27:
                        msg_drawState->textColor = msg_drawState->savedColor;
                        msg_drawState->drawBufferPos++;
                        break;
                    case 28:
                        switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]) {
                            case 0:
                                msg_drawState->effectFlags |= 1;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 1:
                                msg_drawState->effectFlags |= 2;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 2:
                                msg_drawState->effectFlags |= 4;
                                gDPSetCombineLERP(gMasterGfxPos++, NOISE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, NOISE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0);
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 3:
                                msg_drawState->effectFlags |= 0x10000;
                                envColor = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                                gDPSetEnvColor(gMasterGfxPos++, envColor, envColor, envColor, 0);
                                gDPSetCombineLERP(gMasterGfxPos++, NOISE, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0, 0, TEXEL0, NOISE, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0, 0, TEXEL0);
                                msg_drawState->drawBufferPos += 3;
                                break;
                            case 5:
                                msg_drawState->effectFlags |= 0x20;
                                spB8 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                                msg_drawState->drawBufferPos += 3;
                            case 6:
                                msg_drawState->effectFlags |= 0x40;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 7:
                                msg_drawState->effectFlags |= 0x80;
                                spB6 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                                msg_drawState->drawBufferPos += 3;
                            case 8:
                                msg_drawState->effectFlags |= 0x200;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 9:
                                msg_drawState->effectFlags |= 0x400;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 10:
                                msg_drawState->effectFlags |= 0x800;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 11:
                                msg_drawState->effectFlags |= 0x1000;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 12:
                                msg_drawState->effectFlags |= 0x2000;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 13:
                                msg_drawState->effectFlags |= 0x4000;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 14:
                                msg_drawState->effectFlags |= 0x8000;
                                msg_drawState->drawBufferPos += 2;
                                break;
                        }
                        break;
                    case 29:
                        switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]) {
                            case 0:
                                msg_drawState->effectFlags &= ~0x1;
                                break;
                            case 1:
                                msg_drawState->effectFlags &= ~0x2;
                                break;
                            case 2:
                                msg_drawState->effectFlags &= ~0x4;
                                break;
                            case 3:
                                msg_drawState->effectFlags &= ~0x10000;
                                break;
                            case 5:
                                msg_drawState->effectFlags &= ~0x20;
                                break;
                            case 6:
                                msg_drawState->effectFlags &= ~0x40;
                                msg_drawState->printModeFlags |= 0x10;
                                break;
                            case 7:
                                msg_drawState->effectFlags &= ~0x80;
                                break;
                            case 8:
                                msg_drawState->effectFlags &= ~0x200;
                                break;
                            case 9:
                                msg_drawState->effectFlags &= ~0x200;
                                msg_drawState->printModeFlags |= 0x10;
                                break;
                            case 10:
                                msg_drawState->effectFlags &= ~0x800;
                                break;
                            case 11:
                                msg_drawState->effectFlags &= ~0x1000;
                                break;
                            case 12:
                                msg_drawState->effectFlags &= ~0x2000;
                                break;
                            case 13:
                                msg_drawState->effectFlags &= ~0x4000;
                                break;
                            case 14:
                                msg_drawState->effectFlags &= ~0x8000;
                                break;
                        }
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 30:
                        temp_v0_58 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        if (temp_v0_58 != 0) {
                            msg_drawState->centerPos = temp_v0_58;
                            if (msg_drawState->centerPos == 0xFF) {
                                msg_drawState->centerPos = printer->windowSize.x / 2;
                            }
                            msg_drawState->printModeFlags |= 0xC0;
                        } else {
                            msg_drawState->nextPos[0] = 0;
                            msg_drawState->printModeFlags &= ~0xC0;
                        }
                        msg_drawState->drawBufferPos += 2;
                        break;
                }
                break;
            default:
                if (msg_drawState->printModeFlags & 2) {
                    sp96 = 0xFF;
                    gDPPipeSync(gMasterGfxPos++);
                    gSPDisplayList(gMasterGfxPos++, D_8014C500);
                }
                msg_drawState->charScale.x = msg_drawState->msgScale.x;
                msg_drawState->charScale.y = msg_drawState->msgScale.y;
                if (msg_drawState->printModeFlags & 0x80) {
                    msg_drawState->printModeFlags &= ~0x80;
                    msg_drawState->nextPos[0] += msg_drawState->centerPos - printer->msgWidth / 2;
                }
                if (msg_drawState->printModeFlags & 0x40) {
                    phi_s1_6 = (u16) msg_drawState->nextPos[0] + ((u16) printer->windowBasePos.x + (u16) sp66);
                } else {
                    phi_s1_6 = (u16) msg_drawState->nextPos[0] + ((u16) msg_drawState->textStartPos[0] + ((u16) printer->windowBasePos.x + (u16) sp66));
                }
                temp_t0_2 = gMsgCharsets[msg_drawState->font];
                temp_a3_4 = &temp_t0_2->rasters[msg_drawState->fontVariant];
                temp_a1_20 = (s8) temp_a3_4->baseHeightOffset + (((u16) msg_drawState->nextPos[1] + ((u16) msg_drawState->textStartPos[1] + ((u16) printer->windowBasePos.y + (u16) sp6E))) - sp7E);
                if (((s16) sp8E != 0) && ((s32) phi_s1_6 < msg_drawState->clipX[1]) && ((s32) temp_a1_20 < msg_drawState->clipY[1]) && (msg_drawState->clipX[0] < (phi_s1_6 + (s32) (msg_drawState->msgScale.x * (f32) temp_a3_4->monospaceWidth))) && (msg_drawState->clipY[0] < (temp_a1_20 + (s32) ((msg_drawState->msgScale.y * (f32) (u8) temp_t0_2->newLineY) + D_802EB644[printer->style])))) {
                    spA6 = msg_drawState->textColor;
                    phi_s2_7 = (s16) sp8E;
                    if (msg_drawState->effectFlags & 0x20) {
                        phi_s2_7 = (s16) (s32) ((f64) (f32) (s16) sp8E * 0.35);
                    }
                    phi_s2_5 = phi_s2_7;
                    if ((printer->windowState == 7) && (((u16) msg_drawState->printModeFlags & 0x20) != 0)) {
                        if (msg_drawState->unk_2D == printer->currentOption) {
                            msg_drawState->effectFlags |= 0x8600;
                        } else {
                            spA6 = msg_drawState->textColor;
                            msg_drawState->effectFlags &= ~0x400;
                            msg_drawState->effectFlags &= ~0x200;
                            msg_drawState->effectFlags &= ~0x8000;
                            msg_drawState->printModeFlags = (u16) msg_drawState->printModeFlags | 0x10;
                        }
                    }
                    if (msg_drawState->effectFlags & 1) {
                        phi_s1_6 += rand_int(10000) % 2;
                        temp_a1_20 += rand_int(10000) % 2;
                    }
                    if (msg_drawState->effectFlags & 2) {
                        temp_f2_3 = (f64) msg_drawState->msgScale.x - 1.0;
                        temp_s0_7 = (printer->effectFrameCounter * (s32) (20.0 - (temp_f2_3 * 5.0))) - (msg_drawState->visiblePrintedCount * (s32) (45.0 - (temp_f2_3 * 15.0)));
                        temp_s1_7 = (s32) ((f64) phi_s1_6 + ((f64) cosine(temp_s0_7) * (((f64) msg_drawState->msgScale.x - 1.0) + 1.6)));
                        phi_s1_6 = (s16) temp_s1_7;
                        temp_a1_20 = (s16) (s32) ((f64) temp_a1_20 + ((f64) cosine((s16) (s32) ((f64) temp_s0_7 + 180.0 + 90.0)) * (((f64) msg_drawState->msgScale.y - 1.0) + 1.6)));
                    }
                    phi_s1_10 = phi_s1_6;
                    phi_s3_4 = temp_a1_20;
                    if (msg_drawState->effectFlags & 0x200) {
                        temp_s0_8 = (gMsgGlobalWaveCounter * (s32) (20.0 - (((f64) msg_drawState->msgScale.x - 1.0) * 5.0))) - (msg_drawState->visiblePrintedCount * 0x2D);
                        temp_s1_8 = (s32) ((f64) phi_s1_6 + ((f64) cosine(temp_s0_8) * (((f64) msg_drawState->msgScale.x - 1.0) + 1.6)));
                        phi_s1_10 = (s16) temp_s1_8;
                        phi_s3_4 = (s16) (s32) ((f64) temp_a1_20 + ((f64) cosine((s16) (s32) ((f64) temp_s0_8 + 180.0 + 90.0)) * (((f64) msg_drawState->msgScale.y - 1.0) + 1.6)));
                    }
                    charPosX = phi_s1_10;
                    charPosY = phi_s3_4;
                    if (msg_drawState->effectFlags & 0x40) {
                        temp_a0_44 = msg_drawState->visiblePrintedCount - ((printer->effectFrameCounter / 3) & 0xFFFF);
                        temp_a0_44 = abs(temp_a0_44);
                        spA6 = temp_a0_44 - (((temp_a0_44 / 10) - (temp_a0_44 >> 0x1F)) * 0xA);
                    }
                    if (msg_drawState->effectFlags & 0x400) {
                        temp_a0_45 = msg_drawState->visiblePrintedCount - ((gGameStatusPtr->frameCounter / 3) & 0xFFFF);
                        phi_a0_14 = temp_a0_45;
                        if (temp_a0_45 < 0) {
                            phi_a0_14 = -temp_a0_45;
                        }
                        spA6 = phi_a0_14 - (((phi_a0_14 / 10) - (phi_a0_14 >> 0x1F)) * 0xA);
                    }
                    if (msg_drawState->effectFlags & 0x80) {
                        gDPSetAlphaDither(gMasterGfxPos++, G_AD_NOISE);
                        gDPSetAlphaCompare(gMasterGfxPos++, G_AC_DITHER);
                        phi_s2_5 = (s16) (s32) ((f64) spB6 * ((f64) phi_s2_7 / 255.0));
                    }
                    if ((((u16) msg_drawState->printModeFlags & 2)) || (((phi_s2_5 << 0x10) != (sp96 << 0x10)))) {
                        if (((s32) (s16) sp96 < 0xFF) && ((s32) phi_s2_5 < 0xFF)) {
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, phi_s2_5);
                        }
                        if (((s16) sp96 == 0xFF) && ((s32) phi_s2_5 < 0xFF)) {
                            gDPPipeSync(gMasterGfxPos++);
                            if (printer->stateFlags & 0x4000) {
                                gDPSetRenderMode(gMasterGfxPos++, IM_RD | CVG_DST_CLAMP | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_CLAMP | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
                                gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                            } else {
                                gDPSetRenderMode(gMasterGfxPos++, IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
                                gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                            }
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, phi_s2_5);
                        } else if (((s32) (s16) sp96 < 0xFF) && (phi_s2_5 == 0xFF)) {
                            gDPPipeSync(gMasterGfxPos++);
                            gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                            gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                        }
                        sp96 = (u16) phi_s2_5;
                    }
                    if (phi_s2_5 > 0) {
                        if (msg_drawState->effectFlags & 0x800) {
                            temp_v1_57 = &msg_drawState->printBuffer[msg_drawState->drawBufferPos];
                            temp_a1_25 = temp_v1_57[1];
                            if ((temp_a1_25 != 0xF0) && (temp_v1_57[2] != 0xF0) && (temp_v1_57[3] != 0xF0) && (temp_v1_57[4] != 0xF0)) {
                                if ((temp_a1_25 == 0xFB) && (printer->windowState == 4)) {
                                    temp_f6_3 = (f32) ((f64) msg_drawState->msgScale.y * 1.7);
                                    msg_drawState->charScale.x = (f32) ((f64) msg_drawState->msgScale.x * 1.7);
                                    temp_f8 = (f32) (((f64) temp_f6_3 / 1.7) * 6.0);
                                    msg_drawState->charScale.y = temp_f6_3;
                                    phi_f2_2 = (f32) phi_s1_10 - temp_f8;
                                    phi_f0 = (f32) phi_s3_4 - temp_f8;
                                    charPosX = (s16) (s32) phi_f2_2;
                                    charPosY = (s16) (s32) phi_f0;
                                }
                                if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] == 0xFB) && (printer->windowState == 4)) {
                                    temp_f6_4 = (f32) ((f64) msg_drawState->msgScale.y * 1.4);
                                    msg_drawState->charScale.x = (f32) ((f64) msg_drawState->msgScale.x * 1.4);
                                    temp_f8_2 = (f32) (((f64) temp_f6_4 / 1.4) * 3.0);
                                    msg_drawState->charScale.y = temp_f6_4;
                                    phi_f2_2 = (f32) phi_s1_10 - temp_f8_2;
                                    phi_f0 = (f32) phi_s3_4 - temp_f8_2;
                                    charPosX = (s16) (s32) phi_f2_2;
                                    charPosY = (s16) (s32) phi_f0;
                                }
                                if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] == 0xFB) && (printer->windowState == 4)) {
                                    temp_f4_3 = (f32) ((f64) msg_drawState->msgScale.y * 1.2);
                                    msg_drawState->charScale.x = (f32) ((f64) msg_drawState->msgScale.x * 1.2);
                                    temp_f8_3 = (f32) (2.0 * ((f64) temp_f4_3 / 1.2));
                                    msg_drawState->charScale.y = temp_f4_3;
                                    phi_f2_2 = (f32) phi_s1_10 - temp_f8_3;
                                    phi_f0 = (f32) phi_s3_4 - temp_f8_3;
                                    charPosX = (s16) (s32) phi_f2_2;
                                    charPosY = (s16) (s32) phi_f0;
                                }
                            }
                        } else if (msg_drawState->effectFlags & 0x1000) {
                            temp_v1_58 = &msg_drawState->printBuffer[msg_drawState->drawBufferPos];
                            temp_a1_26 = temp_v1_58[1];
                            if ((temp_a1_26 != 0xF0) && (temp_v1_58[2] != 0xF0) && (temp_v1_58[3] != 0xF0) && (temp_v1_58[3] != 0xF0)) {
                                if ((temp_a1_26 == 0xFB) && (printer->windowState == 4)) {
                                    msg_drawState->charScale.x = (f32) ((f64) msg_drawState->msgScale.x * 0.3);
                                    msg_drawState->charScale.y = (f32) ((f64) msg_drawState->msgScale.y * 0.3);
                                    charPosX = phi_s1_10 + 5;
                                    charPosY = phi_s3_4 + 5;
                                } else {
                                    if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] == 0xFB) && (printer->windowState == 4)) {
                                        msg_drawState->charScale.x = (f32) ((f64) msg_drawState->msgScale.x * 0.5);
                                        msg_drawState->charScale.y = (f32) ((f64) msg_drawState->msgScale.y * 0.5);
                                        charPosX = phi_s1_10 + 3;
                                        charPosY = phi_s3_4 + 3;
                                    } else if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] == 0xFB) && (printer->windowState == 4)) {
                                        msg_drawState->charScale.x = (f32) ((f64) msg_drawState->msgScale.x * 0.75);
                                        msg_drawState->charScale.y = (f32) ((f64) msg_drawState->msgScale.y * 0.75);
                                        charPosX = phi_s1_10 + 2;
                                        charPosY = phi_s3_4 + 2;
                                    }
                                }
                            }
                        } else {
                            if (msg_drawState->effectFlags & 0x2000) {
                                temp_v0_65 = rand_int(10000);
                                temp_f8_4 = (f32) ((((f64) (f32) ((f64) (f32) (temp_v0_65 - (((temp_v0_65 / 101) - (temp_v0_65 >> 0x1F)) * 0x65)) / 100.0) * 0.5) + 1.0) - 0.25);
                                temp_f2_4 = (f64) temp_f8_4;
                                phi_f2 = temp_f2_4;
                                phi_f8 = temp_f8_4;
                                if (temp_f2_4 > 1.0) {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_4;
                                    temp_f4_4 = (temp_f2_4 * 8.0) - 8.5;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_4;
                                    charPosX = (s16) (s32) ((f64) phi_s1_10 - temp_f4_4);
                                    charPosY = (f64) phi_s3_4 - temp_f4_4;
                                }
                                goto block_355;
                            }
                            if (msg_drawState->effectFlags & 0x4000) {
                                temp_a0_49 = (printer->effectFrameCounter * 0xF) - (msg_drawState->visiblePrintedCount * 0xF);
                                temp_f8_5 = (f32) (((f64) cosine((s16) (temp_a0_49 - ((((temp_a0_49 >> 3) / 45)) * 360))) * 0.25) + 1.0);
                                temp_f2_5 = (f64) temp_f8_5;
                                phi_f2 = temp_f2_5;
                                phi_f8 = temp_f8_5;
                                if (temp_f2_5 > 1.0) {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_5;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_5;
                                    temp_f4_5 = (temp_f2_5 * 8.0) - 8.5;
                                    charPosX = (s16) (s32) ((f64) phi_s1_10 - temp_f4_5);
                                    charPosY = (f64) phi_s3_4 - temp_f4_5;
                                }
    block_355:
                                if (phi_f2 < 0.0) {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * phi_f8;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * phi_f8;
                                    temp_f2_6 = 8.0 - (phi_f2 * 16.0 * 0.5);
                                    charPosX = (s16) (s32) ((f64) phi_s1_10 + temp_f2_6);
                                    charPosY = (f64) phi_s3_4 + temp_f2_6;
                                }
                            }
                        }
                        if ((printer->windowState == 11 || printer->windowState == 12) &&
                            (printer->style == 1 || printer->style == 2 || printer->style == 3 || printer->style == 4))
                        {
                            switch (spA6) {       /* switch 6 */
                                case 10:                    /* switch 6 */
                                    spA6 = 0x40;
                                    break;
                                case 32:                    /* switch 6 */
                                    spA6 = 0x41;
                                    break;
                                case 34:                    /* switch 6 */
                                    spA6 = 0x42;
                                    break;
                                case 35:                    /* switch 6 */
                                    spA6 = 0x43;
                                    break;
                                case 37:                    /* switch 6 */
                                    spA6 = 0x44;
                                    break;
                                default:                    /* switch 6 */
                                    spA6 = 0x40;
                                    break;
                            }
                        }
                        if (spA6 != sp9E) {
                            sp9E = spA6;
                            msg_drawState->printModeFlags |= 0x10;
                        }
                        if ((msg_drawState->effectFlags & 0x8000) && (phi_s2_5 == 0xFF)) {
                            gDPPipeSync(gMasterGfxPos++);
                            gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                            gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 40, 40, 40, 72);
                            msg_draw_char(printer, msg_drawState, (u8) msg_drawState->printBuffer[msg_drawState->drawBufferPos], spA6, charPosX + 2, charPosY + 2);
                            gDPPipeSync(gMasterGfxPos++);
                            gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                            gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                        }



                        if (msg_drawState->effectFlags & 0x20) {
                            for (i = 0; i < 5; i++) {
                                phi_s0_7 = charPosX;
                                phi_s1_8 = (s32) charPosY;
                                if (spB8 != 2) {
                                    temp_v0_68 = rand_int(10000);
                                    phi_s0_7 = charPosX - 1 + (temp_v0_68 - (((temp_v0_68 / 3) - (temp_v0_68 >> 0x1F)) * 3));
                                }
                                if (spB8 != 1) {
                                    temp_v0_69 = rand_int(10000);
                                    phi_s1_8 = charPosY - 1 + (temp_v0_69 - (((temp_v0_69 / 3) - (temp_v0_69 >> 0x1F)) * 3));
                                }
                                msg_draw_char(printer, msg_drawState, (u8) msg_drawState->printBuffer[msg_drawState->drawBufferPos], spA6, phi_s0_7, phi_s1_8);
                            }
                        } else {
                            msg_draw_char(printer, msg_drawState, *(msg_drawState->printBuffer + msg_drawState->drawBufferPos), spA6, charPosX, charPosY);
                        }
                    }
                }
                if (msg_drawState->printModeFlags & 0x2) {
                    msg_drawState->printModeFlags &= ~0x2;
                }
                msg_drawState->visiblePrintedCount += 1;
                msg_drawState->nextPos[0] += msg_get_draw_char_width(msg_drawState->printBuffer[msg_drawState->drawBufferPos], msg_drawState->font, msg_drawState->fontVariant, msg_drawState->msgScale.x, msg_drawState->currentPosX, msg_drawState->printModeFlags);
                msg_drawState->drawBufferPos++;
                break;
        }
    } while (!sp80bool);

    varImgHasBorder = FALSE;
    varImgHasBorderCond = FALSE;
    if (printer->varImageScreenPos.x != 0) {
        temp_s0_9 = printer->varImgFinalAlpha;
        temp_a0_51 = printer->varImgHasBorder;
        msgVarImage = &(*gMsgVarImages)[printer->currentImageIndex];
        phi_s0_10 = temp_s0_9;
        phi_s0_8 = temp_s0_9;
        if ((s32) temp_a0_51 >= 0) {
            if ((s32) temp_a0_51 >= 2) {
                phi_v0_16 = temp_s0_9 << 0x10;
                if (temp_a0_51 != 2) {

                } else {
                    temp_f0_4 = ((f64) (f32) (s16) spAE / 255.0) * (f64) (f32) printer->varImgFinalAlpha;
                    temp_f0_4 = fabs(temp_f0_4);
                    goto block_411;
                }
                goto block_414;
            }
            if (temp_a0_51 != 0) {
                varImgHasBorder = TRUE;
            }
            temp_v1_69 = printer->varImageDisplayState;
            varImgHasBorderCond = varImgHasBorder;
            if (temp_v1_69 != 1) {
                if ((s32) temp_v1_69 < 2) {
                    phi_v0_16 = temp_s0_9 << 0x10;
                    if (temp_v1_69 != 0) {

                    } else {
                        temp_lo = ++printer->varImageFadeTimer * (u8) printer->varImgAlphaFadeStep;
                        phi_v0_16 = temp_lo << 0x10;
                        phi_s0_8 = (u8) temp_lo;
                        if ((s32) temp_lo >= (s32) printer->varImgFinalAlpha) {
                            printer->varImageFadeTimer = 0;
                            printer->varImageDisplayState = 1;
                            phi_s0_10 = printer->varImgFinalAlpha;
                            goto block_413;
                        }
                    }
                    goto block_414;
                }
                phi_v0_16 = temp_s0_9 << 0x10;
                if (temp_v1_69 != 2) {
                    goto block_414;
                }
                temp_v0_70 = printer->varImgFinalAlpha - (printer->varImgAlphaFadeStep * ++printer->varImageFadeTimer);

                phi_s0_8 = temp_v0_70;
                if (temp_v0_70 <= 0) {
                    printer->varImageScreenPos.x = 0;
                    phi_s0_10 = temp_v0_70;
                    goto block_413;
                }
                goto block_415;
            }
            temp_f0_5 = ((f64) (f32) (s16) spAE / 255.0) * (f32) printer->varImgFinalAlpha;
            phi_s0_10 = temp_f0_5;
block_412:
block_411:
            goto block_413;
        }
block_413:
        phi_v0_16 = phi_s0_10 << 0x10;
        phi_s0_8 = phi_s0_10;
block_414:
        if (phi_v0_16 > 0) {
block_415:
            if (varImgHasBorderCond) {
                draw_box(0, 0xF, (u16) printer->varImageScreenPos.x - 7, (u16) printer->varImageScreenPos.y - 7, 0,
                        msgVarImage->width + 0xF, msgVarImage->height + 0xE, phi_s0_8 & 0xFF, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
            }
            draw_ci_image_with_clipping(msgVarImage->raster, msgVarImage->width, msgVarImage->height,
                                        msgVarImage->format, msgVarImage->bitDepth, msgVarImage->palette,
                                        printer->varImageScreenPos.x, printer->varImageScreenPos.y, 0, 0,
                                        SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, phi_s0_8);
        }
    }
    gDPPipeSync(gMasterGfxPos++);
    D_80151338 = gMasterGfxPos;
}
#else
INCLUDE_ASM(void, "msg", appendGfx_message, MessagePrintState* printer, s16 arg1, s16 arg2, u16 arg3, u16 arg4, u16 arg5, u8 arg6);
#endif

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

INCLUDE_ASM(s32, "msg", msg_draw_speech_bubble);

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
