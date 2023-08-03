#include "common.h"
#include "ld_addrs.h"

extern IMG_BIN MsgCharImgTitle[];
extern IMG_BIN MsgCharImgSubtitle[];
extern IMG_BIN MsgCharImgNormal[];

u8 MsgCharWidthNormal[] = {
    [MSG_CHAR_NOTE]                  11,
    [MSG_CHAR_EXCLAMTION]             8,
    [MSG_CHAR_BACKSLASH]              8,
    [MSG_CHAR_HASH]                  10,
    [MSG_CHAR_DOLLAR]                 9,
    [MSG_CHAR_PERCENT]                9,
    [MSG_CHAR_AND]                    9,
    [MSG_CHAR_APOSTROPHE]             4,
    [MSG_CHAR_LPAREN]                 8,
    [MSG_CHAR_RPAREN]                 8,
    [MSG_CHAR_TIMES]                  9,
    [MSG_CHAR_PLUS]                   9,
    [MSG_CHAR_COMMA]                  5,
    [MSG_CHAR_MINUS]                  9,
    [MSG_CHAR_PERIOD]                 5,
    [MSG_CHAR_FORWARDSLASH]          10,
    [MSG_CHAR_DIGIT_0]                9,
    [MSG_CHAR_DIGIT_1]                7,
    [MSG_CHAR_DIGIT_2]                9,
    [MSG_CHAR_DIGIT_3]                9,
    [MSG_CHAR_DIGIT_4]                9,
    [MSG_CHAR_DIGIT_5]                9,
    [MSG_CHAR_DIGIT_6]                9,
    [MSG_CHAR_DIGIT_7]                9,
    [MSG_CHAR_DIGIT_8]                9,
    [MSG_CHAR_DIGIT_9]                9,
    [MSG_CHAR_COLON]                  5,
    [MSG_CHAR_SEMICOLON]              5,
    [MSG_CHAR_LESS_THAN]              8,
    [MSG_CHAR_EQUAL]                  9,
    [MSG_CHAR_GREATER_THAN]           8,
    [MSG_CHAR_QUESTION]               9,
    [MSG_CHAR_AT]                    10,
    [MSG_CHAR_UPPER_A]                9,
    [MSG_CHAR_UPPER_B]                9,
    [MSG_CHAR_UPPER_C]                9,
    [MSG_CHAR_UPPER_D]                9,
    [MSG_CHAR_UPPER_E]                9,
    [MSG_CHAR_UPPER_F]                9,
    [MSG_CHAR_UPPER_G]                9,
    [MSG_CHAR_UPPER_H]                9,
    [MSG_CHAR_UPPER_I]                7,
    [MSG_CHAR_UPPER_J]                9,
    [MSG_CHAR_UPPER_K]                9,
    [MSG_CHAR_UPPER_L]                9,
    [MSG_CHAR_UPPER_M]                9,
    [MSG_CHAR_UPPER_N]                9,
    [MSG_CHAR_UPPER_O]                9,
    [MSG_CHAR_UPPER_P]                9,
    [MSG_CHAR_UPPER_Q]                9,
    [MSG_CHAR_UPPER_R]                9,
    [MSG_CHAR_UPPER_S]                9,
    [MSG_CHAR_UPPER_T]                9,
    [MSG_CHAR_UPPER_U]                9,
    [MSG_CHAR_UPPER_V]                9,
    [MSG_CHAR_UPPER_W]                9,
    [MSG_CHAR_UPPER_X]                9,
    [MSG_CHAR_UPPER_Y]                9,
    [MSG_CHAR_UPPER_Z]                9,
    [MSG_CHAR_LBRACKET]               7,
    [MSG_CHAR_YEN]                    9,
    [MSG_CHAR_RBRACKET]               6,
    [MSG_CHAR_CARET]                  7,
    [MSG_CHAR_UNDERSCORE]             9,
    [MSG_CHAR_BACKTICK]               6,
    [MSG_CHAR_LOWER_A]                9,
    [MSG_CHAR_LOWER_B]                8,
    [MSG_CHAR_LOWER_C]                8,
    [MSG_CHAR_LOWER_D]                9,
    [MSG_CHAR_LOWER_E]                8,
    [MSG_CHAR_LOWER_F]                8,
    [MSG_CHAR_LOWER_G]                8,
    [MSG_CHAR_LOWER_H]                7,
    [MSG_CHAR_LOWER_I]                4,
    [MSG_CHAR_LOWER_J]                7,
    [MSG_CHAR_LOWER_K]                8,
    [MSG_CHAR_LOWER_L]                4,
    [MSG_CHAR_LOWER_M]                9,
    [MSG_CHAR_LOWER_N]                8,
    [MSG_CHAR_LOWER_O]                7,
    [MSG_CHAR_LOWER_P]                9,
    [MSG_CHAR_LOWER_Q]                8,
    [MSG_CHAR_LOWER_R]                8,
    [MSG_CHAR_LOWER_S]                8,
    [MSG_CHAR_LOWER_T]                8,
    [MSG_CHAR_LOWER_U]                8,
    [MSG_CHAR_LOWER_V]                8,
    [MSG_CHAR_LOWER_W]                9,
    [MSG_CHAR_LOWER_X]                8,
    [MSG_CHAR_LOWER_Y]                8,
    [MSG_CHAR_LOWER_Z]                8,
    [MSG_CHAR_LCURLY]                 7,
    [MSG_CHAR_PIPE]                   3,
    [MSG_CHAR_RCURLY]                 7,
    [MSG_CHAR_TILDA]                 10,
    [MSG_CHAR_DEGREE]                 7,
    [MSG_CHAR_UPPER_A_GRAVE]          9,
    [MSG_CHAR_UPPER_A_ACUTE]          9,
    [MSG_CHAR_UPPER_A_CIRCUMFLEX]     9,
    [MSG_CHAR_UPPER_A_UMLAUT]         9,
    [MSG_CHAR_UPPER_C_CEDILLA]        9,
    [MSG_CHAR_UPPER_E_GRAVE]          9,
    [MSG_CHAR_UPPER_E_ACUTE]          9,
    [MSG_CHAR_UPPER_E_CIRCUMFLEX]     9,
    [MSG_CHAR_UPPER_E_UMLAUT]         9,
    [MSG_CHAR_UPPER_I_GRAVE]          7,
    [MSG_CHAR_UPPER_I_ACUTE]          7,
    [MSG_CHAR_UPPER_I_CIRCUMFLEX]     7,
    [MSG_CHAR_UPPER_I_UMLAUT]         8,
    [MSG_CHAR_UPPER_N_TILDE]          9,
    [MSG_CHAR_UPPER_O_GRAVE]          9,
    [MSG_CHAR_UPPER_O_ACUTE]          9,
    [MSG_CHAR_UPPER_O_CIRCUMFLEX]     9,
    [MSG_CHAR_UPPER_O_UMLAUT]         9,
    [MSG_CHAR_UPPER_U_GRAVE]          9,
    [MSG_CHAR_UPPER_U_ACUTE]          9,
    [MSG_CHAR_UPPER_U_CIRCUMFLEX]     9,
    [MSG_CHAR_UPPER_U_UMLAUT]         9,
    [MSG_CHAR_SHARP_S]                9,
    [MSG_CHAR_LOWER_A_GRAVE]          9,
    [MSG_CHAR_LOWER_A_ACUTE]          9,
    [MSG_CHAR_LOWER_A_CIRCUMFLEX]     9,
    [MSG_CHAR_LOWER_A_UMLAUT]         9,
    [MSG_CHAR_LOWER_C_CEDILLA]        8,
    [MSG_CHAR_LOWER_E_GRAVE]          8,
    [MSG_CHAR_LOWER_E_ACUTE]          8,
    [MSG_CHAR_LOWER_E_CIRCUMFLEX]     8,
    [MSG_CHAR_LOWER_E_UMLAUT]         8,
    [MSG_CHAR_LOWER_I_GRAVE]          6,
    [MSG_CHAR_LOWER_I_ACUTE]          6,
    [MSG_CHAR_LOWER_I_CIRCUMFLEX]     6,
    [MSG_CHAR_LOWER_I_UMLAUT]         7,
    [MSG_CHAR_LOWER_N_TILDE]          9,
    [MSG_CHAR_LOWER_O_GRAVE]          7,
    [MSG_CHAR_LOWER_O_ACUTE]          7,
    [MSG_CHAR_LOWER_O_CIRCUMFLEX]     7,
    [MSG_CHAR_LOWER_O_UMLAUT]         8,
    [MSG_CHAR_LOWER_U_GRAVE]          8,
    [MSG_CHAR_LOWER_U_ACUTE]          8,
    [MSG_CHAR_LOWER_U_CIRCUMFLEX]     8,
    [MSG_CHAR_LOWER_U_UMLAUT]         8,
    [MSG_CHAR_INVERTED_EXCLAMTION]    6,
    [MSG_CHAR_INVERTED_QUESTION]      9,
    [MSG_CHAR_FEM_ORDINAL]            7,
    [MSG_CHAR_HEART]                 11,
    [MSG_CHAR_STAR]                  11,
    [MSG_CHAR_UP]                    11,
    [MSG_CHAR_DOWN]                  11,
    [MSG_CHAR_LEFT]                  12,
    [MSG_CHAR_RIGHT]                 12,
    [MSG_CHAR_CIRCLE]                11,
    [MSG_CHAR_CROSS]                 11,
    [MSG_CHAR_BUTTON_A]              13,
    [MSG_CHAR_BUTTON_B]              13,
    [MSG_CHAR_BUTTON_L]              14,
    [MSG_CHAR_BUTTON_R]              14,
    [MSG_CHAR_BUTTON_Z]              12,
    [MSG_CHAR_BUTTON_C_UP]           13,
    [MSG_CHAR_BUTTON_C_DOWN]         13,
    [MSG_CHAR_BUTTON_C_LEFT]         13,
    [MSG_CHAR_BUTTON_C_RIGHT]        13,
    [MSG_CHAR_BUTTON_START]          16,
    [MSG_CHAR_DOUBLE_QUOTE_OPEN]      9,
    [MSG_CHAR_DOUBLE_QUOTE_CLOSE]     9,
    [MSG_CHAR_SINGLE_QUOTE_OPEN]      5,
    [MSG_CHAR_SINGLE_QUOTE_CLOSE]     5,
};

MessageCharData MsgCharDataNormal[] = {
    {
        .raster = MsgCharImgNormal,
        .charWidthTable = MsgCharWidthNormal,
        .monospaceWidth = 10,
        .baseHeightOffset = 0,
    },
    {
        .raster = MsgCharImgNormal,
        .charWidthTable = MsgCharWidthNormal,
        .monospaceWidth = 10,
        .baseHeightOffset = -2,
    },
    {
        .raster = MsgCharImgNormal,
        .charWidthTable = MsgCharWidthNormal,
        .monospaceWidth = 10,
        .baseHeightOffset = 0,
    },
    {
        .raster = MsgCharImgNormal,
        .charWidthTable = MsgCharWidthNormal,
        .monospaceWidth = 10,
        .baseHeightOffset = 0,
    },
    {}
};

MessageCharData MsgCharDataMenu[] = {
    {
        .raster = MsgCharImgNormal,
        .charWidthTable = MsgCharWidthNormal,
        .monospaceWidth = 9,
        .baseHeightOffset = -2,
    },
    {
        .raster = MsgCharImgNormal,
        .charWidthTable = MsgCharWidthNormal,
        .monospaceWidth = 9,
        .baseHeightOffset = 0,
    },
    {
        .raster = MsgCharImgNormal,
        .charWidthTable = MsgCharWidthNormal,
        .monospaceWidth = 9,
        .baseHeightOffset = 0,
    },
    {
        .raster = MsgCharImgNormal,
        .charWidthTable = MsgCharWidthNormal,
        .monospaceWidth = 9,
        .baseHeightOffset = 0,
    },
    {}
};

MessageCharset MsgCharsetNormal = {
    .texSize = { 16, 16 },
    .unk_02 = 14,
    .newLineY = 16,
    .charRasterSize = 128,
    .rasters = MsgCharDataNormal
};

MessageCharset MsgCharsetMenu = {
    .texSize = { 16, 16 },
    .unk_02 = 14,
    .newLineY = 16,
    .charRasterSize = 128,
    .rasters = MsgCharDataMenu
};

u8 MsgCharWidthTitle[] = {
    8, 8, 8, 9, 8, 8, 8, 8,
    5, 8, 9, 8,10, 8, 8, 9,
    8, 9, 8, 8, 8, 8,10, 9,
    9, 8, 4, 3, 4, 9, 9, 9,
    9, 9, 9, 9, 9, 9, 9,10,
    10
};

u8 MsgCharWidthSubtitle[] = {
    9, 9, 8, 8, 7, 7, 8, 7,
    3, 7, 7, 7, 8, 7, 8, 8,
    8, 7, 7, 8, 7, 7, 8, 8,
    8, 7, 4, 3, 4, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8
};

MessageCharData MsgCharDataTitle[] = {
    {
        .raster = MsgCharImgTitle,
        .charWidthTable = MsgCharWidthTitle,
        .monospaceWidth = 14,
        .baseHeightOffset = 0,
    },
    {}
};

MessageCharData MsgCharDataSubtitle[] = {
    {
        .raster = MsgCharImgSubtitle,
        .charWidthTable = MsgCharWidthSubtitle,
        .monospaceWidth = 10,
        .baseHeightOffset = 0,
    },
    {}
};

MessageCharset MsgCharsetTitle = {
    .texSize = { 12, 15 },
    .unk_02 = 14,
    .newLineY = 16,
    .charRasterSize = 96,
    .rasters = MsgCharDataTitle
};

MessageCharset MsgCharsetSubtitle = {
    .texSize = { 12, 12 },
    .unk_02 = 10,
    .newLineY = 10,
    .charRasterSize = 72,
    .rasters = MsgCharDataSubtitle
};

MessageCharset* MsgCharsets[] = {
    [MSG_FONT_NORMAL]   &MsgCharsetNormal,
    [MSG_FONT_MENU]     &MsgCharsetMenu,
    [MSG_FONT_2]        &MsgCharsetMenu,
    [MSG_FONT_TITLE]    &MsgCharsetTitle,
    [MSG_FONT_SUBTITLE] &MsgCharsetSubtitle,
    NULL
};

s32 MsgLetterRasterOffsets[] = {
    0x0000D178, 0x0000ED78, 0x00010978, 0x00012578,
    0x00014178, 0x00015D78, 0x00017978, 0x00019578,
    0x0001B178, 0x0001CD78, 0x0001E978, 0x00020578,
};

s32 MsgLetterPaletteOffsets[] = {
    0x0000EB78, 0x00010778, 0x00012378, 0x00013F78,
    0x00015B78, 0x00017778, 0x00019378, 0x0001AF78,
    0x0001CB78, 0x0001E778, 0x00020378, 0x00021F78,
};

MsgVoice MsgVoices[] = {
    [MSG_VOICE_NORMAL] {
        .voiceA = SOUND_MSG_VOICE_1A,
        .voiceB = SOUND_MSG_VOICE_1B,
        .pitchShift = 0
    },
    [MSG_VOICE_BOWSER] {
        .voiceA = SOUND_MSG_VOICE_4A,
        .voiceB = SOUND_MSG_VOICE_4B,
        .pitchShift = -50
    },
    [MSG_VOICE_STAR] {
        .voiceA = SOUND_MSG_VOICE_STAR,
        .voiceB = SOUND_MSG_VOICE_STAR,
        .pitchShift = 0
    },
};

s16 MsgStyleVerticalLineOffsets[] = {
    [MSG_STYLE_NONE]       0,
    [MSG_STYLE_RIGHT]     -4,
    [MSG_STYLE_LEFT]      -4,
    [MSG_STYLE_CENTER]    -4,
    [MSG_STYLE_TATTLE]    -4,
    [MSG_STYLE_CHOICE]     0,
    [MSG_STYLE_INSPECT]   -4,
    [MSG_STYLE_SIGN]      -4,
    [MSG_STYLE_LAMPPOST]  -4,
    [MSG_STYLE_POSTCARD]   0,
    [MSG_STYLE_POPUP]      0,
    [MSG_STYLE_B]          0,
    [MSG_STYLE_UPGRADE]    0,
    [MSG_STYLE_NARRATE]   -4,
    [MSG_STYLE_EPILOGUE]  -4,
    [MSG_STYLE_F]          0,
};
