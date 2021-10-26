#include "common.h"
#include "ld_addrs.h"

// todo consider symbol
#define MSG_ROM_START 0x1B83000

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
extern s32 gMsgVarImages; // message images?
extern s32 gMsgBGScrollAmtY;
extern s32 D_80151338;
extern char gMessageBuffers[][1024];
extern u8 gMessageMsgVars[3][32];
extern s16 D_80155C98;
extern Matrix4s gMessageWindowProjMatrix[2];
extern MessageDrawState* gMessageDrawStatePtr;

// another file?
extern s32 D_802ED550;
extern s32 D_802ED670;
extern s32 D_802ED970;
extern s32 D_802EE8D0;
extern MessageCharset* gMsgCharsets[5];
extern s32 D_802F39D0;
extern s16 D_802F4560[];

void load_font(s32 font);
s32 _update_message(MessagePrintState*);
void appendGfx_message(MessagePrintState*, s16, s16, u16, u16, u16, u8);
void appendGfx_msg_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 ulX, u16 ulY, u16 lrX, u16 lrY);
void get_msg_properties(s32 msgID, s32* height, s32* width, s32* maxLineChars, s32* numLines,
                           s32* maxLinesPerPage, s32* arg6, s32 charset);


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

void set_message_images(s32* images) {
    gMsgVarImages = images;
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
                                    printer->rewindArrowPos.y, 0xA, 0xA, 0x12C, 0xDC, 0xFF);
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

INCLUDE_ASM(void, "msg", appendGfx_message, MessagePrintState* printer, s16 arg1, s16 arg2, u16 arg3, u16 arg4, u16 arg5, u8 arg6);

void msg_reset_gfx_state(void) {
    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, D_8014C500);
}

INCLUDE_ASM(s32, "msg", msg_draw_char);

void msg_draw_prim_rect(u8 r, u8 g, u8 b, u8 a, s32 posX, s32 posY, s32 sizeX, s32 sizeY) {
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

    switch (gMessageDrawStatePtr->unk_29) {
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
    out->palette = &D_802F4560[palette * 8];
    out->texSize.x = gMsgCharsets[font]->texSize.x;
    out->texSize.y = gMsgCharsets[font]->texSize.y;
    out->charWidth = msg_get_draw_char_width(charIndex, font, variation, 1.0f, 0, 0);
    out->charHeight = out->texSize.y;
}
