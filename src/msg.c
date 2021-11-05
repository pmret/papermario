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

// unsorted
extern s32 D_8015131C;
extern MessageDrawState D_80155D20;
extern s32 D_80159B50;
extern s32 D_8015C7E0;

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
void msg_draw_speech_bubble(MessagePrintState* printer, s16 posX, s16 posY, s16 straightWidth, s16 curveWidth,
                            s32 height, f32 scaleX, f32 scaleY, u8 opacity, s32 arg9);

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

INCLUDE_ASM(s32, "msg", _update_message, MessagePrintState* msgPrintState);

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
                printer->windowState = MSG_WINDOW_STATE_INIT;
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
                printer->windowState = MSG_WINDOW_STATE_PRINTING;
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

void appendGfx_message(MessagePrintState* printer, s16 posX, s16 posY, u16 additionalOffsetX, u16 additionalOffsetY,
                       u16 flag, u8 alpha) {
    SpriteRasterInfo sp50;
    u16 sp80bool;
    s16 sp8E;
    s16 sp96;
    s16 sp9E;
    s16 palette;
    s16 spAE;
    u16 spB6;
    u8 spB8;
    f32 spBC;
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
    f32 temp_f30;
    f32 temp_f8;
    f32 temp_f8_5;
    f64 temp_f0;
    f64 temp_f0_2;
    f64 temp_f2_2;
    f64 temp_f20_2;
    f64 temp_f22;
    f64 temp_f2;
    f64 temp_f2_3;
    f64 temp_f2_6;
    f64 temp_f2_7;
    f64 temp_f4;
    f64 temp_f4_4;
    f64 temp_f4_5;
    f64 temp_f6_2;
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
    u8 temp_v0_27;
    u8 temp_v0_28;
    UnkImage14* msgVarImage;
    UnkImage14* temp_t4;
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
    s16 t1;
    s16 t2;
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
    msg_drawState->printModeFlags |= 0x100 | 1;
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

    sp80bool = FALSE;
    msg_drawState->drawBufferPos = 0;

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
                        if (printer->windowState == MSG_WINDOW_STATE_OPENING && printer->fadeInCounter == 0) {
                            printer->openStartPos.x = printer->initOpenPos.x;
                            printer->openStartPos.y = printer->initOpenPos.y;
                        }
                        temp_s6 = printer->openStartPos.x;
                        temp_s5 = printer->openStartPos.y;
                        temp_s4 = printer->windowBasePos.x + (f32) printer->windowSize.x * 0.5;
                        temp_s3 = printer->windowBasePos.y + (f32) printer->windowSize.y * 0.5;
                        msg_drawState->textColor = 10;
                        msg_drawState->printModeFlags |= 0x10;

                        if (printer->style == 1 || printer->style == 2 || printer->style == 3) {
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
                            if (temp_a2 + printer->windowSize.x > 302) {
                                temp_a2 = 302 - printer->windowSize.x;
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

                        if (printer->windowState == 11 || printer->windowState == 12) {
                            msg_drawState->framePalette = 1;
                        }

                        if (printer->windowState == MSG_WINDOW_STATE_OPENING) {
                            spBC = update_lerp(0, 0.07f, 1.0f, printer->fadeInCounter, 7);
                            temp_f30 = update_lerp(0, 0.3f, 1.0f, printer->fadeInCounter, 7);
                            temp_f28 = update_lerp(0, 96.0f, 200.0f, printer->fadeInCounter, 7);
                            temp_f20 = update_lerp(11, temp_s5, temp_s3, printer->fadeInCounter, 7);
                            temp_f24 = update_lerp(11, temp_s6, temp_s4, printer->fadeInCounter, 7);
                            temp_f2_2 = (printer->windowSize.x * spBC) * 0.5;
                            temp_f0_2 = (printer->windowSize.y * temp_f30) * 0.5;
                            bubbleX = (temp_f24 - temp_f2_2) + 0.5;
                            bubbleY = (temp_f20 - temp_f0_2) + 0.5;
                            msg_draw_speech_bubble(printer, bubbleX, bubbleY, straightWidth, curveWidth, height, spBC, temp_f30, temp_f28, 1);
                            printer->fadeInCounter++;
                            if (printer->fadeInCounter == 7) {
                                printer->windowState = MSG_WINDOW_STATE_PRINTING;
                            }
                        } else if (printer->windowState == MSG_WINDOW_STATE_CLOSING) {
                            printer->fadeOutCounter++;
                            spBC = update_lerp(0, 1.0f, 0.6f, printer->fadeOutCounter, 5);
                            temp_f30 = update_lerp(0, 1.0f, 0.8f, printer->fadeOutCounter, 5);
                            temp_f2 = (printer->windowSize.x * spBC) * 0.5;
                            temp_f0 = (printer->windowSize.y * temp_f30) * 0.5;
                            temp_f24 = temp_s4;
                            temp_f20 = temp_s3;
                            bubbleX = (temp_f24 - temp_f2) + 0.5;
                            bubbleY = (temp_f20 - temp_f0) + 0.5;
                            temp_f22_2 = (temp_f24 + temp_f2) - 0.5;
                            temp_f20_3 = (temp_f20 + temp_f0) - 0.5;
                            temp_f28 = update_lerp(0, 255.0f, 64.0f, printer->fadeOutCounter, 5);
                            sp8E = temp_f28 * 0.35;
                            spAE = temp_f28;
                            msg_drawState->clipX[0] = bubbleX + msg_drawState->textStartPos[0];
                            msg_drawState->clipY[0] = bubbleY + msg_drawState->textStartPos[1];
                            msg_drawState->clipX[1] = temp_f22_2 - msg_drawState->textStartPos[0];
                            msg_drawState->clipY[1] = temp_f20_3 - msg_drawState->textStartPos[1];
                            msg_draw_speech_bubble(printer, bubbleX, bubbleY, straightWidth, curveWidth, height, spBC, temp_f30, temp_f28, 1);
                            if (printer->fadeOutCounter >= 5) {
                                printer->stateFlags |= 1;
                            }
                        } else {
                            bubbleX = posX + printer->windowBasePos.x;
                            bubbleY = posY + printer->windowBasePos.y;

                            msg_draw_speech_bubble(printer, bubbleX, bubbleY, straightWidth, curveWidth, height, 1.0f, 1.0f, 255, 1);
                            if (((u32) (printer->openStartPos.x - 20) <= 280) && (printer->openStartPos.y <= 220)) {
                                msg_draw_speech_arrow(printer);
                            }
                        }

                        if (printer->windowState != MSG_WINDOW_STATE_CLOSING) {
                            msg_drawState->clipX[0] = 20;
                            msg_drawState->clipY[0] = printer->windowOffsetPos.y + printer->windowBasePos.y +
                                                      msg_drawState->textStartPos[1];
                            msg_drawState->clipX[1] = 300;
                            msg_drawState->clipY[1] = msg_drawState->clipY[0] + printer->windowSize.y - 16;
                        }
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 5:
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

                            temp_f4 = windowSizeX * temp_f10;
                            temp_f6_2 = windowSizeY * temp_f10;
                            z1 = printer->windowBasePos.x + (windowSizeX / 2);
                            z2 = printer->windowBasePos.y + (windowSizeY / 2);
                            temp1 = z1 - (temp_f4 * 0.5);
                            temp2 = z2 - (temp_f6_2 * 0.5);
                            frameX = temp1 + 0.5;
                            frameY = temp2 + 0.5;
                            frameSizeX = temp_f4 + 0.5;
                            frameSizeY = temp_f6_2 + 0.5;

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
                                printer->stateFlags |= 1;
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
                        msg_draw_frame(frameX, frameY, frameSizeX, frameSizeY, 5, msg_drawState->framePalette, frameFading, frameAlpha, frameAlpha);
                        msg_reset_gfx_state();
                        spAE = frameAlpha & 0xFF;
                        msg_drawState->textColor = 10;
                        msg_drawState->drawBufferPos += 2;
                        msg_drawState->printModeFlags |= 0x10;
                        break;
                    case 6:
                    case 12:
                    case 13:
                    case 15:
                        fading = 0;
                        msg_drawState->textStartPos[0] = 16;
                        msg_drawState->textStartPos[1] = 3;
                        msg_drawState->clipX[0] = printer->windowBasePos.x + 5;
                        msg_drawState->clipY[0] = printer->windowBasePos.y + 4;
                        msg_drawState->clipX[1] = printer->windowBasePos.x + printer->windowSize.x - 8;
                        msg_drawState->clipY[1] = printer->windowBasePos.y + printer->windowSize.y - 5;
                        printer->rewindArrowPos.x = msg_drawState->clipX[1] - 17;
                        printer->rewindArrowPos.y = msg_drawState->clipY[1] - 17;
                        msg_drawState->textColor = 0;
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
                                printer->stateFlags |= 1;
                            }
                        }

                        msg_draw_frame(printer->windowBasePos.x, printer->windowBasePos.y, printer->windowSize.x, printer->windowSize.y, 6, msg_drawState->framePalette, fading, phi_s0_5, phi_s0_5);
                        msg_reset_gfx_state();
                        spAE = phi_s0_5 & 0xFF;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 7:
                    case 8:
                        msg_drawState->textStartPos[0] = 18;
                        msg_drawState->textStartPos[1] = 11;
                        printer->windowBasePos.x = 20;
                        printer->windowBasePos.y = 28;
                        printer->windowSize.x = 280;
                        msg_drawState->framePalette = 15;
                        temp_s1_5 = 0xFF;
                        if (printer->style == 7) {
                            spC0 = &D_802EC770;
                            printer->windowSize.y = 72;
                            msg_drawState->textColor = 24;
                            phi_s6 = &D_802ECD10;
                        } else {
                            spC0 = &D_802EC7F0;
                            msg_drawState->textColor = 28;
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
                                    printer->stateFlags |= 1;
                                }
                            }
                        }
                        spAE = (u8)temp_s1_5;
                        draw_ci_image_with_clipping(&D_802EC5F0, 16, 16, 2, 0, phi_s6, 20, 28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(&D_802EC670, 16, 16, 2, 0, phi_s6, 284, 28, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(&D_802EC6F0, 16, 16, 2, 0, phi_s6, 20, printer->windowSize.y + 12, 10, 10, 310, 230, temp_s1_5);
                        draw_ci_image_with_clipping(spC0, 16, 16, 2, 0, phi_s6, 284, printer->windowSize.y + 12, 10, 10, 310, 230, temp_s1_5);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802EC870, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0090, 0x0070, 0x0470, 0x00B0, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802EC970, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0050, 0x00B0, 0x0090, (printer->windowSize.y + 12) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802ECAB0, G_IM_FMT_CI, 16, 0, 0, 0, 15, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0470, 0x00B0, 0x04B0, (printer->windowSize.y + 12) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802ECBF0, G_IM_FMT_CI, 32, 0, 0, 0, 31, 15, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0090, (printer->windowSize.y + 12) * 4, 0x0470, (printer->windowSize.y + 28) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        gDPLoadTextureTile_4b(gMasterGfxPos++, D_802ECCF0, G_IM_FMT_CI, 8, 0, 0, 0, 7, 7, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 3, 3, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(gMasterGfxPos++, 0x0090, 0x00B0, 0x0470, (printer->windowSize.y + 12) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        msg_reset_gfx_state();
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 9:
                        phi_s2_4 = 0;
                        msg_drawState->textStartPos[0] = 0xC;
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
                        msg_drawState->textColor = 0;
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
                                printer->stateFlags |= 1;
                            }
                            phi_s2_4 = 1;
                        }
                        msg_draw_frame(40, 28, 240, 58, 6, msg_drawState->framePalette, phi_s2_4, phi_s3_2, phi_s3_2);
                        draw_ci_image_with_clipping(printer->letterBackgroundImg, 150, 105, 2, 0,
                                                    printer->letterBackgroundPal, 85, 97, 10, 10, 300, 220, phi_s3_2);
                        draw_ci_image_with_clipping(printer->letterContentImg, 70, 95, 2, 1, printer->letterContentPal,
                                                    160, 102, 10, 10, 300, 220, phi_s3_2);
                        msg_reset_gfx_state();
                        spAE = phi_s3_2 & 0xFF;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 10:
                    case 11:
                        msg_drawState->textStartPos[0] = 16;
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
                            draw_box(0, 0, printer->windowBasePos.x, 56, 0, printer->windowSize.x,
                                     printer->windowSize.y, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL,
                                     SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
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
                if (printer->windowState == 0xC) {
                    if (msg_drawState->nextCounter >= printer->unkArraySize) {
                        sp80bool = TRUE;
                    }
                } else if (printer->windowState == 0xB) {
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
            case 0xFB:
                sp80bool = TRUE;
                break;
            case 0xFF:
                msg_drawState->drawBufferPos++;
                switch (msg_drawState->printBuffer[msg_drawState->drawBufferPos]) {
                    case 0:
                        msg_drawState->font = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        msg_drawState->drawBufferPos += 2;
                        msg_drawState->printModeFlags |= 0x10;
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
                        msg_drawState->msgScale.x = (f32) (temp_v0_27 >> 4) + ((temp_v0_27 & 0xF) * 0.0625f);
                        temp_v0_28 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                        msg_drawState->msgScale.y = (f32) (temp_v0_28 >> 4) + ((temp_v0_28 & 0xF) * 0.0625f);
                        msg_drawState->drawBufferPos += 3;
                        if (msg_drawState->msgScale.x > 1.0 || msg_drawState->msgScale.y > 1.0) {
                            gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
                        } else if (msg_drawState->msgScale.x < 1.0 || msg_drawState->msgScale.y < 1.0) {
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
                        msg_drawState->nextPos[0] = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] * 256 + (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2]);
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
                        if (sp8E < 0xFF) {
                            phi_t5 = (s32) (sp8E * 0.7);
                        }
                        t1 = (s16) ((msg_drawState->nextPos[0] + (msg_drawState->textStartPos[0] + (printer->windowBasePos.x + posX))) - additionalOffsetX);
                        t2 = (s16) ((msg_drawState->nextPos[1] + (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY))) - additionalOffsetY);


                        draw_ci_image_with_clipping(temp_t4->raster, temp_t4->width, temp_t4->height, temp_t4->format, temp_t4->bitDepth, temp_t4->palette, t1, t2, (s32) msg_drawState->clipX[0], (s32) msg_drawState->clipY[0], msg_drawState->clipX[1] - msg_drawState->clipX[0], msg_drawState->clipY[1] - msg_drawState->clipY[0], phi_t5);
                        msg_drawState->printModeFlags |= 0x10 | 0x2;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 15:
                        phi_s0_6 = sp8E;
                        if (sp8E < 0xFF) {
                            phi_s0_6 = (s32) (sp8E * 0.7);
                        }

                        if (spr_get_npc_raster_info(&sp50, (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] << 8) | msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2], msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3]) != 0) {
                            t1 = (s16) ((msg_drawState->nextPos[0] + (msg_drawState->textStartPos[0] + (printer->windowBasePos.x + posX))) - additionalOffsetX);
                            t2 = (s16) ((msg_drawState->nextPos[1] + (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY))) - additionalOffsetY);

                            draw_ci_image_with_clipping(sp50.raster, sp50.width, sp50.height, 2, 0, sp50.defaultPal, t1, t2, msg_drawState->clipX[0], msg_drawState->clipY[0], msg_drawState->clipX[1] - msg_drawState->clipX[0], msg_drawState->clipY[1] - msg_drawState->clipY[0], phi_s0_6);
                            msg_drawState->printModeFlags |= 0x10;
                        }
                        msg_drawState->drawBufferPos += 4;
                        break;
                    case 16:
                        if (D_8015131C != 0) {
                            phi_t3 = sp8E;
                            if (sp8E < 0xFF) {
                                phi_t3 = (s32) (sp8E * 0.7);
                            }
                            t1 = (s16) ((msg_drawState->nextPos[0] + (msg_drawState->textStartPos[0] + (printer->windowBasePos.x + posX))) - additionalOffsetX);
                            t2 = (s16) ((msg_drawState->nextPos[1] + (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY))) - additionalOffsetY);

                            draw_ci_image_with_clipping(&D_80159B50, 32, 32, 2, 0, &D_8015C7E0, t1, t2, msg_drawState->clipX[0], msg_drawState->clipY[0], msg_drawState->clipX[1] - msg_drawState->clipX[0], msg_drawState->clipY[1] - msg_drawState->clipY[0], phi_t3);
                            msg_drawState->printModeFlags |= 0x10;
                        }
                        msg_drawState->drawBufferPos++;
                        break;
                    case 17:
                        animIdx = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                        if (printer->animTimers[animIdx] == -1) {
                            printer->animTimers[animIdx] = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3];
                        }
                        if (printer->animTimers[animIdx] == 0) {
                            printer->currentAnimFrame[animIdx]++;
                        }

                        dbPos = msg_drawState->drawBufferPos;
                        while (TRUE) {
                            if ((msg_drawState->printBuffer[dbPos - 1] == 0xFF) &&
                                (msg_drawState->printBuffer[dbPos] == 0x11) &&
                                (msg_drawState->printBuffer[dbPos + 1] == animIdx))
                            {
                                if (msg_drawState->printBuffer[dbPos + 2] != printer->currentAnimFrame[animIdx]) {
                                    dbPos += 4;
                                } else {
                                    break;
                                }
                            } else {
                                if ((msg_drawState->printBuffer[dbPos] == 0xFF) &&
                                    (msg_drawState->printBuffer[dbPos + 1] == 0x12) &&
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
                                    if (msg_drawState->printBuffer[dbPos] == 0xFF &&
                                        msg_drawState->printBuffer[dbPos + 1] == 0x13)
                                    {
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
                            case 0x11:
                                if (printer->animTimers[animIdx] == 0) {
                                    if (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] == 0) {
                                        printer->animTimers[animIdx] = -2;
                                    } else {
                                        printer->animTimers[animIdx] = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3];
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
                    case 19:
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 20:
                        printer->cursorPosX[msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]] = msg_drawState->textStartPos[0] + msg_drawState->nextPos[0] - additionalOffsetX - 6;
                        printer->cursorPosY[msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1]] = msg_drawState->textStartPos[1] + msg_drawState->nextPos[1] - additionalOffsetY - 1;
                        msg_drawState->drawBufferPos += 2;
                        break;
                    case 21:
                        if (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] == 0xFF) {
                            msg_drawState->printModeFlags &= ~0x20;
                        } else {
                            msg_drawState->unk_2D = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
                            msg_drawState->printModeFlags |= 0x20;
                            msg_drawState->nextPos[0] += 0xE;
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
                                gDPSetEnvColor(gMasterGfxPos++,
                                               msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                               msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                               msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2],
                                               0);
                                gDPSetCombineLERP(gMasterGfxPos++, NOISE, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0, 0, TEXEL0, NOISE, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0, 0, TEXEL0);
                                msg_drawState->drawBufferPos += 3;
                                break;
                            case 5:
                                msg_drawState->effectFlags |= 0x20;
                                spB8 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                                msg_drawState->drawBufferPos += 3;
                                break;
                            case 6:
                                msg_drawState->effectFlags |= 0x40;
                                msg_drawState->drawBufferPos += 2;
                                break;
                            case 7:
                                msg_drawState->effectFlags |= 0x80;
                                spB6 = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2];
                                msg_drawState->drawBufferPos += 3;
                                break;
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
                                msg_drawState->effectFlags &= ~0x400;
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
                        if (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] != 0) {
                            msg_drawState->centerPos = msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1];
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
                    msg_drawState->nextPos[0] += msg_drawState->centerPos - printer->msgWidth / 2;
                    msg_drawState->printModeFlags &= ~0x80;
                }
                if (msg_drawState->printModeFlags & 0x40) {
                    charPosX = (u16) msg_drawState->nextPos[0] + ((u16) printer->windowBasePos.x + (u16) posX);
                } else {
                    charPosX = (u16) msg_drawState->nextPos[0] + ((u16) msg_drawState->textStartPos[0] + ((u16) printer->windowBasePos.x + (u16) posX));
                }

                msgCharset = gMsgCharsets[msg_drawState->font];
                charPosY = (s8) msgCharset->rasters[msg_drawState->fontVariant].baseHeightOffset + (msg_drawState->nextPos[1] + (msg_drawState->textStartPos[1] + (printer->windowBasePos.y + posY)) - additionalOffsetY);

                if ((sp8E != 0) &&
                    (charPosX < msg_drawState->clipX[1]) &&
                    (charPosY < msg_drawState->clipY[1]) &&
                    (msg_drawState->clipX[0] < charPosX + (s32) (msg_drawState->msgScale.x * msgCharset->rasters[msg_drawState->fontVariant].monospaceWidth)) &&
                    (msg_drawState->clipY[0] < charPosY + (s32) (msg_drawState->msgScale.y * msgCharset->newLineY + D_802EB644[printer->style])))
                {
                    palette = msg_drawState->textColor;
                    phi_s2_5 = (s16) sp8E;
                    if (msg_drawState->effectFlags & 0x20) {
                        phi_s2_5 = (f32) phi_s2_5 * 0.35;
                    }
                    if ((printer->windowState == MSG_WINDOW_STATE_WAITING_FOR_CHOICE) && (msg_drawState->printModeFlags & 0x20)) {
                        if (msg_drawState->unk_2D == printer->currentOption) {
                            msg_drawState->effectFlags |= 0x8000 | 0x400 | 0x200;
                        } else {
                            msg_drawState->effectFlags &= ~0x400;
                            msg_drawState->effectFlags &= ~0x200;
                            msg_drawState->effectFlags &= ~0x8000;
                            palette = msg_drawState->textColor;
                            msg_drawState->printModeFlags |= 0x10;
                        }
                    }
                    if (msg_drawState->effectFlags & 1) {
                        charPosX += rand_int(10000) % 2;
                        charPosY += rand_int(10000) % 2;
                    }
                    if (msg_drawState->effectFlags & 2) {
                        temp_f2_3 = msg_drawState->msgScale.x - 1.0;
                        temp_s0_7 = (printer->effectFrameCounter * (s32) (20.0 - (temp_f2_3 * 5.0))) - (msg_drawState->visiblePrintedCount * (s32) (45.0 - (temp_f2_3 * 15.0)));
                        charPosX += cosine(temp_s0_7) * ((msg_drawState->msgScale.x - 1.0) + 1.6);
                        charPosY += cosine((temp_s0_7 + 180.0 + 90.0)) * (msg_drawState->msgScale.y - 1.0 + 1.6);
                    }
                    if (msg_drawState->effectFlags & 0x200) {
                        temp_s0_8 = (gMsgGlobalWaveCounter * (s32) (20.0 - ((msg_drawState->msgScale.x - 1.0) * 5.0))) - (msg_drawState->visiblePrintedCount * 45);
                        charPosX += cosine(temp_s0_8) * ((msg_drawState->msgScale.x - 1.0) + 1.6);
                        charPosY += cosine((temp_s0_8 + 180.0 + 90.0)) * ((msg_drawState->msgScale.y - 1.0) + 1.6);
                    }
                    if (msg_drawState->effectFlags & 0x40) {
                        palette = abs(msg_drawState->visiblePrintedCount - (u16)(printer->effectFrameCounter / 3)) % 10;
                    }
                    if (msg_drawState->effectFlags & 0x400) {
                        palette = abs(msg_drawState->visiblePrintedCount - (u16)(gGameStatusPtr->frameCounter / 3)) % 10;
                    }
                    if (msg_drawState->effectFlags & 0x80) {
                        gDPSetAlphaDither(gMasterGfxPos++, G_AD_NOISE);
                        gDPSetAlphaCompare(gMasterGfxPos++, G_AC_DITHER);
                        phi_s2_5 = spB6 * (phi_s2_5 / 255.0);
                    }
                    if ((msg_drawState->printModeFlags & 2) || (phi_s2_5 != sp96)) {
                        if ((sp96 < 0xFF) && (phi_s2_5 < 0xFF)) {
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, phi_s2_5);
                        } else if ((sp96 == 0xFF) && (phi_s2_5 < 0xFF)) {
                            gDPPipeSync(gMasterGfxPos++);
                            if (printer->stateFlags & 0x4000) {
                                gDPSetRenderMode(gMasterGfxPos++, IM_RD | CVG_DST_CLAMP | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_CLAMP | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));

                            } else {
                                gDPSetRenderMode(gMasterGfxPos++, IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));

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
                        if (msg_drawState->effectFlags & 0x800) {
                            if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] != 0xF0) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] != 0xF0) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] != 0xF0) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 4] != 0xF0))
                            {
                                if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] == 0xFB) &&
                                    (printer->windowState == MSG_WINDOW_STATE_PRINTING))
                                {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 1.7;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 1.7;
                                    temp_f8 = (msg_drawState->charScale.y / 1.7) * 6.0;
                                    charPosX -= temp_f8;
                                    charPosY -= temp_f8;
                                } else if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] == 0xFB) &&
                                           (printer->windowState == MSG_WINDOW_STATE_PRINTING))
                                {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 1.4;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 1.4;
                                    temp_f8 = (msg_drawState->charScale.y / 1.4) * 3.0;
                                    charPosX -= temp_f8;
                                    charPosY -= temp_f8;
                                } else if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] == 0xFB) &&
                                           (printer->windowState == MSG_WINDOW_STATE_PRINTING))
                                {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 1.2;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 1.2;
                                    temp_f8 = (msg_drawState->charScale.y / 1.2) * 2.0;
                                    charPosX -= temp_f8;
                                    charPosY -= temp_f8;
                                }
                            }
                        } else if (msg_drawState->effectFlags & 0x1000) {
                            if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] != 0xF0) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] != 0xF0) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] != 0xF0) &&
                                (msg_drawState->printBuffer[msg_drawState->drawBufferPos + 4] != 0xF0))
                            {
                                if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 1] == 0xFB) &&
                                    (printer->windowState == MSG_WINDOW_STATE_PRINTING))
                                {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 0.3;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 0.3;
                                    charPosX += 5;
                                    charPosY += 5;
                                } else if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 2] == 0xFB) &&
                                           (printer->windowState == MSG_WINDOW_STATE_PRINTING))
                                {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 0.5;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 0.5;
                                    charPosX += 3;
                                    charPosY += 3;
                                } else if ((msg_drawState->printBuffer[msg_drawState->drawBufferPos + 3] == 0xFB) &&
                                           (printer->windowState == MSG_WINDOW_STATE_PRINTING))
                                {
                                    msg_drawState->charScale.x = msg_drawState->msgScale.x * 0.75;
                                    msg_drawState->charScale.y = msg_drawState->msgScale.y * 0.75;
                                    charPosX += 2;
                                    charPosY += 2;
                                }
                            }
                        } else if (msg_drawState->effectFlags & 0x2000) {
                            temp_f8_5 = rand_int(10000) % 101;
                            temp_f8_5 /= 100.0;
                            temp_f8_5 = ((temp_f8_5 * 0.5) + 1.0) - 0.25;

                            if (temp_f8_5 > 1.0) {
                                msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_5;
                                msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_5;
                                temp_f4_4 = (temp_f8_5 * 8.0) - 8.5;
                                charPosX -= temp_f4_4;
                                charPosY -= temp_f4_4;
                            } else if (temp_f8_5 < 1.0) {
                                msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_5;
                                msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_5;
                                temp_f2_7 = 8.0 - (temp_f8_5 * 16.0) * 0.5;
                                charPosX += temp_f2_7;
                                charPosY += temp_f2_7;
                            }
                        } else if (msg_drawState->effectFlags & 0x4000) {
                            s32 mod360;

                            temp_a0_49 = printer->effectFrameCounter * 15;
                            temp_a0_49 -= msg_drawState->visiblePrintedCount * 15;
                            mod360 = temp_a0_49 % 360;
                            temp_f8_5 = (cosine(mod360) * 0.25) + 1.0;

                            if (temp_f8_5 > 1.0) {
                                msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_5;
                                msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_5;
                                temp_f4_5 = (temp_f8_5 * 8.0) - 8.5;
                                charPosX -= temp_f4_5;
                                charPosY -= temp_f4_5;
                            } else if (temp_f8_5 < 1.0) {
                                msg_drawState->charScale.x = msg_drawState->msgScale.x * temp_f8_5;
                                msg_drawState->charScale.y = msg_drawState->msgScale.y * temp_f8_5;
                                temp_f2_6 = 8.0 - (temp_f8_5 * 16.0) * 0.5;
                                charPosX += temp_f2_6;
                                charPosY += temp_f2_6;
                            }
                        }

                        if ((printer->windowState == 11 || printer->windowState == 12) &&
                            (printer->style == 1 || printer->style == 2 || printer->style == 3 || printer->style == 4))
                        {
                            switch (palette) {
                                case 0:
                                case 7:
                                case 16:
                                case 17:
                                case 18:
                                case 19:
                                case 20:
                                    break;
                                case 10:
                                    palette = 0x40;
                                    break;
                                case 32:
                                    palette = 0x41;
                                    break;
                                case 34:
                                    palette = 0x42;
                                    break;
                                case 35:
                                    palette = 0x43;
                                    break;
                                case 37:
                                    palette = 0x44;
                                    break;
                                default:
                                    palette = 0x40;
                                    break;
                            }
                        }
                        if (palette != sp9E) {
                            sp9E = palette;
                            msg_drawState->printModeFlags |= 0x10;
                        }
                        if ((msg_drawState->effectFlags & 0x8000) && (phi_s2_5 == 0xFF)) {
                            gDPPipeSync(gMasterGfxPos++);
                            gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                            gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 40, 40, 40, 72);
                            msg_draw_char(printer, msg_drawState, msg_drawState->printBuffer[msg_drawState->drawBufferPos], palette, charPosX + 2, charPosY + 2);
                            gDPPipeSync(gMasterGfxPos++);
                            gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                            gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                        }

                        if (msg_drawState->effectFlags & 0x20) {
                            for (i = 0; i < 5; i++) {
                                phi_s0_7 = charPosX;
                                phi_s1_8 = charPosY;
                                if (spB8 != 2) {
                                    phi_s0_7 += (rand_int(10000) % 3) - 1;
                                }
                                if (spB8 != 1) {
                                    phi_s1_8 += (rand_int(10000) % 3) - 1;
                                }
                                msg_draw_char(printer, msg_drawState, msg_drawState->printBuffer[msg_drawState->drawBufferPos], palette, phi_s0_7, phi_s1_8);
                            }
                        } else {
                            msg_draw_char(printer, msg_drawState, msg_drawState->printBuffer[msg_drawState->drawBufferPos], palette, charPosX, charPosY);
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
                        varImgFinalAlpha = (u8)(((f64) (f32) spAE / 255.0) * (f64) (f32) printer->varImgFinalAlpha);
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
                varImgFinalAlpha = (u8)(((f64) (f32) spAE / 255.0) * (f64) (f32) printer->varImgFinalAlpha);
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
