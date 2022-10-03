#include "end_01.h"
#include "effects.h"
#include "../credits_common.h"

s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags);
void msg_get_glyph(s32 font, s32 variation, s32 charIndex, s32 palette, MesasgeFontGlyphData* out);
void dma_load_msg(u32 msgID, void* dest);

static CreditsData N(CreditsData);
static CreditsData* N(CreditsDataPtr);
static s32 N(BSS_PAD_1)[2];
static u8 N(CreditsMessageBuffers)[23][256];
static Mtx N(CreditsProjMatrices)[2];

CreditsUnkBeta N(Font3Patterns)[] = {
    { .unk_00 = 0x02, .unk_01 = 0x07, .size = 1 },
    { .unk_00 = 0x02, .unk_01 = 0x0A, .size = 1 },
    { .unk_00 = 0x03, .unk_01 = 0x04, .size = 1 },
    { .unk_00 = 0x07, .unk_01 = 0x0D, .size = 1 },
    { .unk_00 = 0x09, .unk_01 = 0x04, .size = 1 },
    { .unk_00 = 0x0C, .unk_01 = 0x04, .size = 1 },
    { .unk_00 = 0x0C, .unk_01 = 0x0C, .size = 1 },
    { .unk_00 = 0x0C, .unk_01 = 0x14, .size = 1 },
    { .unk_00 = 0x0D, .unk_01 = 0x03, .size = 1 },
    { .unk_00 = 0x0D, .unk_01 = 0x04, .size = 1 },
    { .unk_00 = 0x0D, .unk_01 = 0x0A, .size = 1 },
    { .unk_00 = 0x0D, .unk_01 = 0x14, .size = 1 },
    { .unk_00 = 0x0E, .unk_01 = 0x0D, .size = 1 },
    { .unk_00 = 0x0E, .unk_01 = 0x11, .size = 1 },
    { .unk_00 = 0x11, .unk_01 = 0x04, .size = 1 },
    { .unk_00 = 0x11, .unk_01 = 0x0F, .size = 1 },
    { .unk_00 = 0x14, .unk_01 = 0x02, .size = 1 },
    { .unk_00 = 0x14, .unk_01 = 0x0D, .size = 1 },
    { .unk_00 = 0x14, .unk_01 = 0x0F, .size = 1 },
    { .unk_00 = 0x14, .unk_01 = 0x12, .size = 1 },
    { .unk_00 = 0x12, .unk_01 = 0x02, .size = 1 },
    { .unk_00 = 0x12, .unk_01 = 0x07, .size = 1 },
    { .unk_00 = 0x12, .unk_01 = 0x0F, .size = 1 },
    { .unk_00 = 0x15, .unk_01 = 0x04, .size = 1 },
    { .unk_00 = 0x16, .unk_01 = 0x11, .size = 1 },
    {}
};

CreditsUnkBeta N(Font4Patterns)[] = {
    { .unk_00 = 0x00, .unk_01 = 0x02, .size = 1 },
    { .unk_00 = 0x00, .unk_01 = 0x06, .size = 1 },
    { .unk_00 = 0x00, .unk_01 = 0x0E, .size = 1 },
    { .unk_00 = 0x00, .unk_01 = 0x03, .size = 1 },
    { .unk_00 = 0x00, .unk_01 = 0x08, .size = 1 },
    { .unk_00 = 0x00, .unk_01 = 0x0A, .size = 1 },
    { .unk_00 = 0x00, .unk_01 = 0x0D, .size = 1 },
    { .unk_00 = 0x00, .unk_01 = 0x13, .size = 1 },
    { .unk_00 = 0x00, .unk_01 = 0x14, .size = 1 },
    { .unk_00 = 0x07, .unk_01 = 0x00, .size = 1 },
    { .unk_00 = 0x07, .unk_01 = 0x06, .size = 1 },
    { .unk_00 = 0x07, .unk_01 = 0x08, .size = 1 },
    { .unk_00 = 0x08, .unk_01 = 0x02, .size = 1 },
    { .unk_00 = 0x08, .unk_01 = 0x04, .size = 1 },
    { .unk_00 = 0x08, .unk_01 = 0x06, .size = 1 },
    { .unk_00 = 0x08, .unk_01 = 0x0A, .size = 1 },
    { .unk_00 = 0x08, .unk_01 = 0x0D, .size = 1 },
    { .unk_00 = 0x08, .unk_01 = 0x0E, .size = 1 },
    { .unk_00 = 0x08, .unk_01 = 0x13, .size = 1 },
    { .unk_00 = 0x08, .unk_01 = 0x18, .size = 1 },
    { .unk_00 = 0x09, .unk_01 = 0x08, .size = 1 },
    { .unk_00 = 0x0C, .unk_01 = 0x0E, .size = 1 },
    { .unk_00 = 0x0C, .unk_01 = 0x08, .size = 1 },
    { .unk_00 = 0x0D, .unk_01 = 0x06, .size = 1 },
    { .unk_00 = 0x0D, .unk_01 = 0x08, .size = 1 },
    { .unk_00 = 0x0D, .unk_01 = 0x0E, .size = 1 },
    { .unk_00 = 0x0D, .unk_01 = 0x13, .size = 1 },
    { .unk_00 = 0x12, .unk_01 = 0x04, .size = 1 },
    { .unk_00 = 0x12, .unk_01 = 0x08, .size = 1 },
    { .unk_00 = 0x13, .unk_01 = 0x04, .size = 1 },
    { .unk_00 = 0x14, .unk_01 = 0x02, .size = 1 },
    { .unk_00 = 0x14, .unk_01 = 0x08, .size = 1 },
    { .unk_00 = 0x14, .unk_01 = 0x0A, .size = 1 },
    {}
};

Vp N(CreditsViewport) = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 }
    }
};

s32 N(CreditsBufferIndex) = 0;

#include "world/common/atomic/Credits_1.inc.c"

// same as end_00_credits_update_line, but Font3Patterns and Font4Patterns are swapped...
// might be able to fix this when data for this map is done?
void N(credits_update_line)(CreditsLine* line) {
    CreditsChar creditsChar;
    CreditsChar* curChar = &creditsChar;
    CreditsUnkBeta* curPattern;
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
                    curPattern = N(Font4Patterns);
                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        curPattern = N(Font3Patterns);
                    }
    
                    i = 0;
    
                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        if (curMsgChar == MSG_CHAR_LPAREN || nextMsgChar1 == MSG_CHAR_LPAREN) {
                            msgWidth++;
                        }
                    }
                    
                    do {
                        if (curMsgChar == curPattern[i].unk_00 && nextMsgChar1 == curPattern[i].unk_01) {
                            msgWidth += curPattern[i].size;
                        }
                        i++;
                    } while (curPattern[i].size != 0);
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
                                    case CREDITS_APPEAR_MODE_00:
                                        N(CharAnim_FadeIn_5)(line, curChar);
                                        break;
                                    case CREDITS_APPEAR_MODE_01:
                                        N(CharAnim_FadeIn_1)(line, curChar);
                                        break;
                                    case CREDITS_APPEAR_MODE_02:
                                        N(CharAnim_FadeIn_2)(line, curChar);
                                        break;
                                    case CREDITS_APPEAR_MODE_03:
                                        N(CharAnim_FadeIn_3)(line, curChar);
                                        break;
                                    case CREDITS_APPEAR_MODE_04:
                                        N(CharAnim_FadeIn_4)(line, curChar);
                                        break;
                                    case CREDITS_APPEAR_MODE_05:
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
                                case CREDITS_VANISH_MODE_00:
                                    N(CharAnim_FadeOut_3)(line, curChar);
                                    break;
                                case CREDITS_VANISH_MODE_01:
                                    N(CharAnim_FadeOut_1)(line, curChar);
                                    break;
                                case CREDITS_VANISH_MODE_02:
                                    N(CharAnim_FadeOut_2)(line, curChar);
                                    break;
                                case CREDITS_VANISH_MODE_03:
                                    N(CharAnim_FadeOut_3)(line, curChar);
                                    break;
                            }
                            break;
                    }
                    drawCount++;
                }

                posX += msg_get_print_char_width(curMsgChar, curChar->font, curChar->variation, 1.0f, 0, 1) - 1;
                if (curChar->font == MSG_FONT_TITLE || curChar->font == MSG_FONT_SUBTITLE) {
                    curPattern = N(Font4Patterns);
                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        curPattern = N(Font3Patterns);
                    }

                    i = 0;

                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        if (curMsgChar == MSG_CHAR_LPAREN || nextMsgChar2 == MSG_CHAR_LPAREN) {
                            posX++;
                        }
                    }
                    do {
                        if (curMsgChar == curPattern[i].unk_00 && nextMsgChar2 == curPattern[i].unk_01) {
                            posX += curPattern[i].size;
                        }
                        i++;
                    } while (curPattern[i].size != 0);
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

#include "world/common/atomic/Credits_2.inc.c"

#include "credits_jobs.inc.c"
#include "credits_names.inc.c"

EvtScript N(EVS_InitCredits) = {
    EVT_CALL(N(InitCredits))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowCredits_Jobs) = {
    EVT_CALL(N(ShowCreditList), EVT_PTR(N(Credits_Jobs)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowCredits_Names) = {
    EVT_CALL(N(ShowCreditList), EVT_PTR(N(Credits_Names)))
    EVT_RETURN
    EVT_END
};
