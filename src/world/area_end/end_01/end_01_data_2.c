#include "end_01.h"
#include "effects.h"

#define STANDARD_POS_X              160
#define STANDARD_APPEAR_TIME        40
#define STANDARD_HOLD_TIME          174
#define STANDARD_VANISH_TIME        30
#define STANDARD_NEXT_TIME          230
#define STANDARD_TITLE_NEXT_TIME    270

enum {
    CREDITS_APPEAR_MODE_00      = 0,
    CREDITS_APPEAR_MODE_04      = 4,

    CREDITS_HOLD_MODE_00        = 0,

    CREDITS_VANISH_MODE_00      = 0,

    CREDITS_FLAG_1              = 1,
};

API_CALLABLE(N(InitCredits));
API_CALLABLE(N(ShowCreditList));
API_CALLABLE(N(func_802427E8_E07B48));
API_CALLABLE(N(func_80242840_E07BA0));
API_CALLABLE(N(func_80242690_E079F0));
API_CALLABLE(N(func_80242754_E07AB4));
API_CALLABLE(N(func_802427B4_E07B14));
API_CALLABLE(N(func_802428C0_E07C20));
API_CALLABLE(N(func_80242978_E07CD8));
API_CALLABLE(N(func_80242900_E07C60));
API_CALLABLE(N(func_80242A68_E07DC8));
API_CALLABLE(N(func_80242B68_E07EC8));
void N(func_80242C94_E07FF4)(void);
API_CALLABLE(N(func_80242C68_E07FC8));

extern EvtScript N(EVS_80246A60);
extern EvtScript N(EVS_80247620);
extern EvtScript N(EVS_80247D68);
extern EvtScript N(D_802481B0_E0D510);
extern EvtScript N(EVS_80248D1C);
extern EvtScript N(EVS_80249034);
extern EvtScript N(EVS_802492B0);
extern EvtScript N(D_80245820_E0AB80);
extern EvtScript N(D_80245BD0_E0AF30);
extern EvtScript N(D_80245FF0_E0B350);
extern EvtScript N(D_80245C74_E0AFD4);

CreditsUnkBeta N(Font3Patterns)[] = {
    { .unk_00 = 0x02, .unk_01 = 0x07, .size = 0x07, },
    { .unk_00 = 0x02, .unk_01 = 0x0A, .size = 0x0A, },
    { .unk_00 = 0x03, .unk_01 = 0x04, .size = 0x04, },
    { .unk_00 = 0x07, .unk_01 = 0x0D, .size = 0x0D, },
    { .unk_00 = 0x09, .unk_01 = 0x04, .size = 0x04, },
    { .unk_00 = 0x0C, .unk_01 = 0x04, .size = 0x04, },
    { .unk_00 = 0x0C, .unk_01 = 0x0C, .size = 0x0C, },
    { .unk_00 = 0x0C, .unk_01 = 0x14, .size = 0x14, },
    { .unk_00 = 0x0D, .unk_01 = 0x03, .size = 0x03, },
    { .unk_00 = 0x0D, .unk_01 = 0x04, .size = 0x04, },
    { .unk_00 = 0x0D, .unk_01 = 0x0A, .size = 0x0A, },
    { .unk_00 = 0x0D, .unk_01 = 0x14, .size = 0x14, },
    { .unk_00 = 0x0E, .unk_01 = 0x0D, .size = 0x0D, },
    { .unk_00 = 0x0E, .unk_01 = 0x11, .size = 0x11, },
    { .unk_00 = 0x11, .unk_01 = 0x04, .size = 0x04, },
    { .unk_00 = 0x11, .unk_01 = 0x0F, .size = 0x0F, },
    { .unk_00 = 0x14, .unk_01 = 0x02, .size = 0x02, },
    { .unk_00 = 0x14, .unk_01 = 0x0D, .size = 0x0D, },
    { .unk_00 = 0x14, .unk_01 = 0x0F, .size = 0x0F, },
    { .unk_00 = 0x14, .unk_01 = 0x12, .size = 0x12, },
    { .unk_00 = 0x12, .unk_01 = 0x02, .size = 0x02, },
    { .unk_00 = 0x12, .unk_01 = 0x07, .size = 0x07, },
    { .unk_00 = 0x12, .unk_01 = 0x0F, .size = 0x0F, },
    { .unk_00 = 0x15, .unk_01 = 0x04, .size = 0x04, },
    { .unk_00 = 0x16, .unk_01 = 0x11, .size = 0x11, },
    {}
};

CreditsUnkBeta N(Font4Patterns)[] = {
    { .unk_00 = 0x00, .unk_01 = 0x02, .size = 0x02, },
    { .unk_00 = 0x00, .unk_01 = 0x06, .size = 0x06, },
    { .unk_00 = 0x00, .unk_01 = 0x0E, .size = 0x0E, },
    { .unk_00 = 0x00, .unk_01 = 0x03, .size = 0x03, },
    { .unk_00 = 0x00, .unk_01 = 0x08, .size = 0x08, },
    { .unk_00 = 0x00, .unk_01 = 0x0A, .size = 0x0A, },
    { .unk_00 = 0x00, .unk_01 = 0x0D, .size = 0x0D, },
    { .unk_00 = 0x00, .unk_01 = 0x13, .size = 0x13, },
    { .unk_00 = 0x00, .unk_01 = 0x14, .size = 0x14, },
    { .unk_00 = 0x07, .unk_01 = 0x00, .size = 0x00, },
    { .unk_00 = 0x07, .unk_01 = 0x06, .size = 0x06, },
    { .unk_00 = 0x07, .unk_01 = 0x08, .size = 0x08, },
    { .unk_00 = 0x08, .unk_01 = 0x02, .size = 0x02, },
    { .unk_00 = 0x08, .unk_01 = 0x04, .size = 0x04, },
    { .unk_00 = 0x08, .unk_01 = 0x06, .size = 0x06, },
    { .unk_00 = 0x08, .unk_01 = 0x0A, .size = 0x0A, },
    { .unk_00 = 0x08, .unk_01 = 0x0D, .size = 0x0D, },
    { .unk_00 = 0x08, .unk_01 = 0x0E, .size = 0x0E, },
    { .unk_00 = 0x08, .unk_01 = 0x13, .size = 0x13, },
    { .unk_00 = 0x08, .unk_01 = 0x18, .size = 0x18, },
    { .unk_00 = 0x09, .unk_01 = 0x08, .size = 0x08, },
    { .unk_00 = 0x0C, .unk_01 = 0x0E, .size = 0x0E, },
    { .unk_00 = 0x0C, .unk_01 = 0x08, .size = 0x08, },
    { .unk_00 = 0x0D, .unk_01 = 0x06, .size = 0x06, },
    { .unk_00 = 0x0D, .unk_01 = 0x08, .size = 0x08, },
    { .unk_00 = 0x0D, .unk_01 = 0x0E, .size = 0x0E, },
    { .unk_00 = 0x0D, .unk_01 = 0x13, .size = 0x13, },
    { .unk_00 = 0x12, .unk_01 = 0x04, .size = 0x04, },
    { .unk_00 = 0x12, .unk_01 = 0x08, .size = 0x08, },
    { .unk_00 = 0x13, .unk_01 = 0x04, .size = 0x04, },
    { .unk_00 = 0x14, .unk_01 = 0x02, .size = 0x02, },
    { .unk_00 = 0x14, .unk_01 = 0x08, .size = 0x08, },
    { .unk_00 = 0x14, .unk_01 = 0x0A, .size = 0x01, },
    {}
};

Vp N(CreditsViewport) = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 }
    }
};

s32 N(CreditsBufferIndex) = 0;

CreditsEntry N(D_80243214_E08574)[] = {
    {
        .msgID = MSG_Credits_0019,
        .posX = STANDARD_POS_X,
        .posY = 166,
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 2,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 2270,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = 2340,
        .flags = CREDITS_FLAG_1,
    },
    {
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = 0,
        .perCharDelayIn = 0,
        .next = 60,
    },
    {
        .msgID = MSG_Credits_001A,
        .posX = STANDARD_POS_X,
        .posY = 170,
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 2,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 200,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = 270,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_001B,
        .posX = STANDARD_POS_X,
        .posY = 170,
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 2,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 430,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = 500,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_001D,
        .posX = STANDARD_POS_X,
        .posY = 170,
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 2,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 200,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = 270,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_001C,
        .posX = STANDARD_POS_X,
        .posY = 170,
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 2,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 430,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = 500,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_001E,
        .posX = STANDARD_POS_X,
        .posY = 170,
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 2,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 200,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = 270,
        .flags = CREDITS_FLAG_1,
    },
    {
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = 0,
        .perCharDelayIn = 0,
        .next = 60,
    },
    {
        .msgID = MSG_Credits_0007,
        .posX = 131,
        .posY = 182,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = 60,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 50,
        .perCharDelayOut = 0,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0008,
        .posX = 189,
        .posY = 182,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = 60,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 50,
        .perCharDelayOut = 0,
        .next = 270,
        .flags = CREDITS_FLAG_1,
    },
    {
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = 0,
        .perCharDelayIn = 0,
        .next = 30,
    },
    {
        .msgID = MSG_Credits_0005,
        .posX = STANDARD_POS_X,
        .posY = 172,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = 60,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 50,
        .perCharDelayOut = 0,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0006,
        .posX = STANDARD_POS_X,
        .posY = 188,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = 60,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 50,
        .perCharDelayOut = 0,
        .next = 270,
        .flags = CREDITS_FLAG_1,
    },
    {
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = 0,
        .perCharDelayIn = 0,
        .next = -1,
    },
};

CreditsEntry N(D_80243524_E08884)[] = {
    {
        .next = 40,
    },
    {
        .msgID = MSG_Credits_0071,
        .posX = STANDARD_POS_X,
        .posY = 186,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0072,
        .posX = STANDARD_POS_X,
        .posY = 203,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0066,
        .posX = STANDARD_POS_X,
        .posY = 186,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0065,
        .posX = STANDARD_POS_X,
        .posY = 203,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0075,
        .posX = STANDARD_POS_X,
        .posY = 186,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0073,
        .posX = STANDARD_POS_X,
        .posY = 203,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0055,
        .posX = STANDARD_POS_X,
        .posY = 186,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0051,
        .posX = STANDARD_POS_X,
        .posY = 203,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0059,
        .posX = STANDARD_POS_X,
        .posY = 186,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_005A,
        .posX = STANDARD_POS_X,
        .posY = 203,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0053,
        .posX = STANDARD_POS_X,
        .posY = 182,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_005B,
        .posX = STANDARD_POS_X,
        .posY = 195,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_005C,
        .posX = STANDARD_POS_X,
        .posY = 208,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_005D,
        .posX = STANDARD_POS_X,
        .posY = 186,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_005E,
        .posX = STANDARD_POS_X,
        .posY = 203,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_005F,
        .posX = STANDARD_POS_X,
        .posY = 182,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0060,
        .posX = STANDARD_POS_X,
        .posY = 195,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0061,
        .posX = STANDARD_POS_X,
        .posY = 208,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0068,
        .posX = STANDARD_POS_X,
        .posY = 191,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0085,
        .posX = STANDARD_POS_X,
        .posY = 182,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0086,
        .posX = STANDARD_POS_X,
        .posY = 195,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = 0,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0087,
        .posX = STANDARD_POS_X,
        .posY = 208,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = 0,
        .perCharDelayIn = 0,
        .next = 60,
    },
    {
        .next = 40,
    },
    {
        .msgID = MSG_Credits_0052,
        .posX = STANDARD_POS_X,
        .posY = 191,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .next = 40,
    },
    {
        .msgID = MSG_Credits_006A,
        .posX = STANDARD_POS_X,
        .posY = 191,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_0054,
        .posX = STANDARD_POS_X,
        .posY = 191,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .next = 40,
    },
    {
        .msgID = MSG_Credits_006D,
        .posX = STANDARD_POS_X,
        .posY = 191,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .next = 40,
    },
    {
        .msgID = MSG_Credits_006C,
        .posX = STANDARD_POS_X,
        .posY = 191,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = STANDARD_HOLD_TIME,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 1,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .msgID = MSG_Credits_006B,
        .posX = STANDARD_POS_X,
        .posY = 191,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 1,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .next = 40,
    },
    {
        .msgID = MSG_Credits_006E,
        .posX = STANDARD_POS_X,
        .posY = 191,
        .palette = 1,
        .appearMode = CREDITS_APPEAR_MODE_00,
        .appearTime = STANDARD_APPEAR_TIME,
        .perCharDelayIn = 0,
        .holdMode = CREDITS_HOLD_MODE_00,
        .holdTime = 160,
        .vanishMode = CREDITS_VANISH_MODE_00,
        .vanishTime = 30,
        .perCharDelayOut = 0,
        .next = STANDARD_NEXT_TIME,
        .flags = CREDITS_FLAG_1,
    },
    {
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = 0,
        .perCharDelayIn = 0,
        .next = 60,
    },
    {
        .appearMode = CREDITS_APPEAR_MODE_04,
        .appearTime = 0,
        .perCharDelayIn = 0,
        .next = -1,
    },
};

EvtScript N(D_80243D74_E090D4) = {
    EVT_CALL(N(InitCredits))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243D90_E090F0) = {
    EVT_CALL(N(ShowCreditList), EVT_PTR(N(D_80243214_E08574)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243DB0_E09110) = {
    EVT_CALL(N(ShowCreditList), EVT_PTR(N(D_80243524_E08884)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243DD0_E09130) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -3135, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -3135, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243E44_E091A4) = {
    EVT_CALL(SetPanTarget, CAM_DEFAULT, EVT_FLOAT(-3135.0), 0, 0)
    EVT_SETF(LVar1, EVT_FLOAT(0.0))
    EVT_LOOP(0)
        EVT_CALL(N(func_802427E8_E07B48))
        EVT_CALL(TranslateGroup, MODEL_bg, LVar1, 0, 0)
        EVT_ADDF(LVar1, EVT_FLOAT(0.6669922))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243ED8_E09238) = {
    EVT_CALL(EnableTexPanning, MODEL_o145, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o146, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o152, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o153, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o154, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o166, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o157, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o159, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o160, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o161, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o162, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o195, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o196, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o197, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o198, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o260, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o201, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o202, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o203, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o204, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o275, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o276, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o277, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o278, TRUE)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 150)
            EVT_IF_GT(LVar0, 0x20000)
                EVT_ADD(LVar0, -0x20000)
            EVT_END_IF
            EVT_CALL(SetTexPanOffset, 1, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80244180) = {
    EVT_CALL(N(func_80242840_E07BA0), LVar0)
    EVT_RETURN
    EVT_END
};

AnimID N(D_802441A0_E09500)[] = {
    ANIM_BattleEldstar_Idle,
    -1
};

AnimID N(D_802441A8_E09508)[] = {
    ANIM_BattleMamar_Idle,
    -1
};

AnimID N(D_802441B0_E09510)[] = {
    ANIM_BattleSkolar_Idle,
    -1
};

AnimID N(D_802441B8_E09518)[] = {
    ANIM_BattleMuskular_Idle,
    -1
};

AnimID N(D_802441C0_E09520)[] = {
    ANIM_BattleMisstar_Still,
    -1
};

AnimID N(D_802441C8_E09528)[] = {
    ANIM_BattleKlevar_Idle,
    -1
};

AnimID N(D_802441D0_E09530)[] = {
    ANIM_BattleKalmar_Idle,
    -1
};

AnimID N(D_802441D8_E09538)[] = {
    ANIM_PyroGuy_Anim03,
    -1
};

AnimID N(D_802441E0_E09540)[] = {
    ANIM_ShyGuy_Red_Anim04,
    ANIM_ShyGuy_Red_Anim10,
    ANIM_ShyGuy_Red_Anim01,
    -1
};

ParadeNpcInfo N(ParadeNpcsTable)[] = {
    [NPC_00] {
        .initialAnim = ANIM_BattleEldstar_Idle,
        .animList = N(D_802441A0_E09500),
        .pos = { -3135.0f, 210.0f, -120.0f },
        .yaw = 270.0f
    },
    [NPC_01] {
        .initialAnim = ANIM_BattleMamar_Idle,
        .animList = N(D_802441A8_E09508),
        .pos = { -3195.0f, 200.0f, -120.0f },
        .yaw = 270.0f
    },
    [NPC_02] {
        .initialAnim = ANIM_BattleSkolar_Idle,
        .animList = N(D_802441B0_E09510),
        .pos = { -3075.0f, 195.0f, -120.0f },
        .yaw = 270.0f
    },
    [NPC_03] {
        .initialAnim = ANIM_BattleMuskular_Idle,
        .animList = N(D_802441B8_E09518),
        .pos = { -3045.0f, 148.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_04] {
        .initialAnim = ANIM_BattleMisstar_Still,
        .animList = N(D_802441C0_E09520),
        .pos = { -3105.0f, 158.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_05] {
        .initialAnim = ANIM_BattleKlevar_Idle,
        .animList = N(D_802441C8_E09528),
        .pos = { -3165.0f, 158.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_06] {
        .initialAnim = ANIM_BattleKalmar_Idle,
        .animList = N(D_802441D0_E09530),
        .pos = { -3225.0f, 148.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_07] {
        .initialAnim = ANIM_ParadeIceShow_Violin_SkateStill,
        .pos = { -2700.0f, 0.0f, -37.0f },
        .yaw = 270.0f
    },
    [NPC_08] {
        .initialAnim = ANIM_ParadeIceShow_Violin_SkateStill,
        .pos = { -2700.0f, 0.0f, 37.0f },
        .yaw = 270.0f
    },
    [NPC_09] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ShadeMayorWalk,
        .pos = { -2650.0f, 0.0f, -77.0f },
        .yaw = 270.0f
    },
    [NPC_0A] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ShadeMayorWifeWalk,
        .pos = { -2610.0f, 0.0f, -77.0f },
        .yaw = 270.0f
    },
    [NPC_0B] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ViolinPlay,
        .pos = { -2555.0f, 5.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_0C] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ViolinPlayUpright,
        .pos = { -2527.0f, 5.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_0D] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ViolinPlay,
        .pos = { -2495.0f, 5.0f, 30.0f },
        .yaw = 90.0f
    },
    [NPC_0E] {
        .initialAnim = ANIM_Musician_Poet_Dark_ConductSlow,
        .pos = { -2624.0f, 20.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_0F] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ShadeDivaIdle,
        .pos = { -2529.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_10] {
        .initialAnim = ANIM_Dayzee_Amazy_Anim02,
        .pos = { -2210.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_11] {
        .initialAnim = ANIM_Dayzee_Amazy_Anim02,
        .pos = { -2210.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_12] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerleGather,
        .pos = { -2025.0f, 20.0f, 28.0f },
        .yaw = 270.0f
    },
    [NPC_13] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerleeGather,
        .pos = { -1995.0f, 20.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_14] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerlonGather,
        .pos = { -2055.0f, 20.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_15] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerluvleeGather,
        .pos = { -2085.0f, 20.0f, 28.0f },
        .yaw = 270.0f
    },
    [NPC_16] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerlowGather,
        .pos = { -2110.0f, 20.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_17] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerlarGather,
        .pos = { -1980.0f, 60.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_18] {
        .initialAnim = ANIM_Sun_TalkSad,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_19] {
        .initialAnim = ANIM_Sun_FireTalkSad,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_1A] {
        .initialAnim = ANIM_Bubulb_Pink_DarkWalk,
        .pos = { -1850.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_1B] {
        .initialAnim = ANIM_Bubulb_Pink_DarkWalk,
        .pos = { -1850.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_1C] {
        .initialAnim = ANIM_ParadeShyGuy_MarshallWalk,
        .pos = { -1548.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_1D] {
        .initialAnim = ANIM_ParadeShyGuy_GeneralPoint,
        .pos = { -1448.0f, 57.0f, -25.0f },
        .yaw = 270.0f
    },
    [NPC_1E] {
        .initialAnim = ANIM_ParadeShyGuy_StackHold,
        .pos = { -1483.0f, 24.0f, -40.0f },
        .yaw = 90.0f
    },
    [NPC_1F] {
        .initialAnim = ANIM_ParadeShyGuy_StackHold,
        .pos = { -1413.0f, 24.0f, -40.0f },
        .yaw = 270.0f
    },
    [NPC_20] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1468.0f, 24.0f, -5.0f },
        .yaw = 270.0f
    },
    [NPC_21] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1458.0f, 24.0f, -5.0f },
        .yaw = 270.0f
    },
    [NPC_22] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1438.0f, 24.0f, -5.0f },
        .yaw = 90.0f
    },
    [NPC_23] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1428.0f, 24.0f, -5.0f },
        .yaw = 90.0f
    },
    [NPC_24] {
        .initialAnim = ANIM_PyroGuy_Anim03,
        .animList = N(D_802441D8_E09538),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_25] {
        .initialAnim = ANIM_PyroGuy_Anim03,
        .animList = N(D_802441D8_E09538),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_26] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1048.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_27] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1048.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_28] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1048.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_29] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1018.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_2A] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1018.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_2B] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1018.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_2C] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -988.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_2D] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -988.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_2E] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -988.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_2F] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -958.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_30] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -958.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_31] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -958.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_32] {
        .initialAnim = ANIM_ShyGuy_Red_Anim04,
        .animList = N(D_802441E0_E09540),
        .pos = { -788.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_33] {
        .initialAnim = ANIM_ParadeHorn_Walk,
        .pos = { -689.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_34] {
        .initialAnim = ANIM_ParadeHorn_Walk,
        .pos = { -689.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_35] {
        .initialAnim = ANIM_ParadeDrummer_Walk,
        .pos = { -639.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_36] {
        .initialAnim = ANIM_ParadeDrummer_Walk,
        .pos = { -639.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_37] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { -589.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_38] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { -589.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_39] {
        .initialAnim = ANIM_ParadeMario_Wave,
        .pos = { -329.0f, 37.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3A] {
        .initialAnim = ANIM_ParadePeach_ShadeWaveSlow,
        .pos = { -289.0f, 37.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3B] {
        .initialAnim = ANIM_ParadeTwink_Idle,
        .pos = { -389.0f, 120.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_3C] {
        .initialAnim = ANIM_ParadeTwirler_Walk,
        .pos = { -109.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3D] {
        .initialAnim = ANIM_ParadeTwirler_Walk,
        .pos = { -69.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3E] {
        .initialAnim = ANIM_ParadeTwirler_Walk,
        .pos = { -29.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3F] {
        .initialAnim = ANIM_ParadeTwirler_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_40] {
        .initialAnim = ANIM_ParadeTwirler_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_41] {
        .initialAnim = ANIM_ParadeTwirler_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_42] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { 41.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_43] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { 41.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
};

EvtScript N(D_80244850_E09BB0) = {
    EVT_CALL(N(func_80242690_E079F0), NPC_00)
    EVT_CALL(N(func_80242690_E079F0), NPC_01)
    EVT_CALL(N(func_80242690_E079F0), NPC_02)
    EVT_CALL(N(func_80242690_E079F0), NPC_03)
    EVT_CALL(N(func_80242690_E079F0), NPC_04)
    EVT_CALL(N(func_80242690_E079F0), NPC_05)
    EVT_CALL(N(func_80242690_E079F0), NPC_06)
    EVT_CALL(N(func_80242690_E079F0), NPC_09)
    EVT_CALL(N(func_80242690_E079F0), NPC_0A)
    EVT_CALL(N(func_80242690_E079F0), NPC_07)
    EVT_CALL(N(func_80242690_E079F0), NPC_08)
    EVT_CALL(N(func_80242690_E079F0), NPC_0B)
    EVT_CALL(N(func_80242690_E079F0), NPC_0C)
    EVT_CALL(N(func_80242690_E079F0), NPC_0D)
    EVT_CALL(N(func_80242690_E079F0), NPC_0E)
    EVT_CALL(N(func_80242690_E079F0), NPC_0F)
    EVT_CALL(N(func_80242754_E07AB4), 0x13400, LVar0)
    EVT_CALL(N(func_80242690_E079F0), NPC_10)
    EVT_CALL(N(func_80242690_E079F0), NPC_11)
    EVT_CALL(N(func_802427B4_E07B14), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2350)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_00)
    EVT_CALL(DeleteNpc, NPC_01)
    EVT_CALL(DeleteNpc, NPC_02)
    EVT_CALL(DeleteNpc, NPC_03)
    EVT_CALL(DeleteNpc, NPC_04)
    EVT_CALL(DeleteNpc, NPC_05)
    EVT_CALL(DeleteNpc, NPC_06)
    EVT_CALL(DeleteNpc, NPC_09)
    EVT_CALL(DeleteNpc, NPC_0A)
    EVT_CALL(DeleteNpc, NPC_07)
    EVT_CALL(DeleteNpc, NPC_08)
    EVT_CALL(DeleteNpc, NPC_0B)
    EVT_CALL(DeleteNpc, NPC_0C)
    EVT_CALL(DeleteNpc, NPC_0D)
    EVT_CALL(DeleteNpc, NPC_0E)
    EVT_CALL(DeleteNpc, NPC_0F)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242690_E079F0), NPC_12)
    EVT_CALL(N(func_80242690_E079F0), NPC_13)
    EVT_CALL(N(func_80242690_E079F0), NPC_14)
    EVT_CALL(N(func_80242690_E079F0), NPC_15)
    EVT_CALL(N(func_80242690_E079F0), NPC_16)
    EVT_CALL(N(func_80242690_E079F0), NPC_17)
    EVT_CALL(N(func_80242690_E079F0), NPC_18)
    EVT_CALL(N(func_80242690_E079F0), NPC_19)
    EVT_CALL(N(func_80242690_E079F0), NPC_1A)
    EVT_CALL(N(func_80242690_E079F0), NPC_1B)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -1778)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_10)
    EVT_CALL(DeleteNpc, NPC_11)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242754_E07AB4), 0x4700, LVar0)
    EVT_CALL(N(func_80242690_E079F0), NPC_24)
    EVT_CALL(N(func_80242690_E079F0), NPC_25)
    EVT_CALL(N(func_80242690_E079F0), NPC_32)
    EVT_CALL(N(func_80242690_E079F0), NPC_1C)
    EVT_CALL(N(func_80242690_E079F0), NPC_1D)
    EVT_CALL(N(func_80242690_E079F0), NPC_1E)
    EVT_CALL(N(func_80242690_E079F0), NPC_1F)
    EVT_CALL(N(func_80242690_E079F0), NPC_20)
    EVT_CALL(N(func_80242690_E079F0), NPC_21)
    EVT_CALL(N(func_80242690_E079F0), NPC_22)
    EVT_CALL(N(func_80242690_E079F0), NPC_23)
    EVT_CALL(N(func_80242690_E079F0), NPC_26)
    EVT_CALL(N(func_80242690_E079F0), NPC_27)
    EVT_CALL(N(func_80242690_E079F0), NPC_28)
    EVT_CALL(N(func_80242690_E079F0), NPC_29)
    EVT_CALL(N(func_80242690_E079F0), NPC_2A)
    EVT_CALL(N(func_80242690_E079F0), NPC_2B)
    EVT_CALL(N(func_80242690_E079F0), NPC_2C)
    EVT_CALL(N(func_80242690_E079F0), NPC_2D)
    EVT_CALL(N(func_80242690_E079F0), NPC_2E)
    EVT_CALL(N(func_80242690_E079F0), NPC_2F)
    EVT_CALL(N(func_80242690_E079F0), NPC_30)
    EVT_CALL(N(func_80242690_E079F0), NPC_31)
    EVT_CALL(N(func_802427B4_E07B14), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -889)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_12)
    EVT_CALL(DeleteNpc, NPC_13)
    EVT_CALL(DeleteNpc, NPC_14)
    EVT_CALL(DeleteNpc, NPC_15)
    EVT_CALL(DeleteNpc, NPC_16)
    EVT_CALL(DeleteNpc, NPC_17)
    EVT_CALL(DeleteNpc, NPC_18)
    EVT_CALL(DeleteNpc, NPC_19)
    EVT_CALL(DeleteNpc, NPC_1A)
    EVT_CALL(DeleteNpc, NPC_1B)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242690_E079F0), NPC_33)
    EVT_CALL(N(func_80242690_E079F0), NPC_34)
    EVT_CALL(N(func_80242690_E079F0), NPC_35)
    EVT_CALL(N(func_80242690_E079F0), NPC_36)
    EVT_CALL(N(func_80242690_E079F0), NPC_37)
    EVT_CALL(N(func_80242690_E079F0), NPC_38)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -689)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_24)
    EVT_CALL(DeleteNpc, NPC_25)
    EVT_CALL(DeleteNpc, NPC_32)
    EVT_CALL(DeleteNpc, NPC_1C)
    EVT_CALL(DeleteNpc, NPC_1D)
    EVT_CALL(DeleteNpc, NPC_1E)
    EVT_CALL(DeleteNpc, NPC_1F)
    EVT_CALL(DeleteNpc, NPC_20)
    EVT_CALL(DeleteNpc, NPC_21)
    EVT_CALL(DeleteNpc, NPC_22)
    EVT_CALL(DeleteNpc, NPC_23)
    EVT_CALL(DeleteNpc, NPC_26)
    EVT_CALL(DeleteNpc, NPC_27)
    EVT_CALL(DeleteNpc, NPC_28)
    EVT_CALL(DeleteNpc, NPC_29)
    EVT_CALL(DeleteNpc, NPC_2A)
    EVT_CALL(DeleteNpc, NPC_2B)
    EVT_CALL(DeleteNpc, NPC_2C)
    EVT_CALL(DeleteNpc, NPC_2D)
    EVT_CALL(DeleteNpc, NPC_2E)
    EVT_CALL(DeleteNpc, NPC_2F)
    EVT_CALL(DeleteNpc, NPC_30)
    EVT_CALL(DeleteNpc, NPC_31)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242690_E079F0), NPC_39)
    EVT_CALL(N(func_80242690_E079F0), NPC_3A)
    EVT_CALL(N(func_80242690_E079F0), NPC_3B)
    EVT_CALL(N(func_80242690_E079F0), NPC_3C)
    EVT_CALL(N(func_80242690_E079F0), NPC_3D)
    EVT_CALL(N(func_80242690_E079F0), NPC_3E)
    EVT_CALL(N(func_80242690_E079F0), NPC_3F)
    EVT_CALL(N(func_80242690_E079F0), NPC_40)
    EVT_CALL(N(func_80242690_E079F0), NPC_41)
    EVT_CALL(N(func_80242690_E079F0), NPC_42)
    EVT_CALL(N(func_80242690_E079F0), NPC_43)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802451B8_E0A518) = {
    EVT_WAIT(60)
    EVT_EXEC(N(D_80243D74_E090D4))
    EVT_EXEC(N(D_80243D90_E090F0))
    EVT_EXEC(N(D_80243DB0_E09110))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802451F8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_PARADE_NIGHT, 0, 8)
    EVT_EXEC(N(D_80243DD0_E09130))
    EVT_EXEC(N(D_80244850_E09BB0))
    EVT_EXEC_GET_TID(N(D_80245820_E0AB80), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVarA, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_802451B8_E0A518))
    EVT_EXEC_GET_TID(N(D_80243E44_E091A4), LVarA)
    EVT_EXEC_GET_TID(N(D_80243ED8_E09238), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -3000)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_80245BD0_E0AF30))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2950)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_80245C74_E0AFD4))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2945)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_80245FF0_E0B350))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2450)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80246A60))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -1778)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80247620))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -1248)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80247D68))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -889)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_802481B0_E0D510))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -689)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_GET_TID(N(EVS_80248D1C), LVarC)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -330)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVarC, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80249034))
    EVT_WAIT(150)
    EVT_EXEC(N(EVS_802492B0))
    EVT_WAIT(200)
    EVT_CALL(GotoMap, EVT_PTR("kmr_30"), kmr_30_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245740_E0AAA0) = {
    EVT_CALL(SetNpcFlagBits, NPC_07, NPC_FLAG_40000, TRUE)
    EVT_CALL(GetNpcPos, LVarA, LVar2, LVar3, LVar4)
    EVT_SUB(LVar3, 120)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, 15)
    EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LVar2, LVar5, LVar4, 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetNpcPos, LVarA, LVar2, LVar3, LVar4)
    EVT_CALL(N(func_80242978_E07CD8))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245820_E0AB80) = {
    EVT_CALL(N(func_802428C0_E07C20))
    EVT_WAIT(20)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(2)
    EVT_SET(LVarA, 1)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(2)
    EVT_SET(LVarA, 2)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(3)
    EVT_SET(LVarA, 4)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(5)
    EVT_SET(LVarA, 5)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(3)
    EVT_SET(LVarA, 3)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(7)
    EVT_SET(LVarA, 6)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(30)
    EVT_CALL(N(func_80242900_E07C60))
    EVT_WAIT(60)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245978_E0ACD8) = {
    EVT_CALL(SetNpcFlagBits, NPC_07, NPC_FLAG_40000, TRUE)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(SetNpcAnimation, NPC_07, ANIM_ParadeIceShow_Violin_SkateKickLeft)
            EVT_WAIT(30)
            EVT_CALL(SetNpcAnimation, NPC_07, ANIM_ParadeIceShow_Violin_SkateKickRight)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetNpcPos, NPC_07, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_07, LVar0, LVar2, 120)
    EVT_CALL(N(func_80242A68_E07DC8), 7)
    EVT_CALL(GetNpcPos, NPC_07, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_07, LVar0, LVar2, 120)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245AA4_E0AE04) = {
    EVT_CALL(SetNpcFlagBits, NPC_08, NPC_FLAG_40000, TRUE)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(SetNpcAnimation, NPC_08, ANIM_ParadeIceShow_Violin_SkateKickLeft)
            EVT_WAIT(30)
            EVT_CALL(SetNpcAnimation, NPC_08, ANIM_ParadeIceShow_Violin_SkateKickRight)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetNpcPos, NPC_08, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -210)
    EVT_CALL(NpcMoveTo, NPC_08, LVar0, LVar2, 140)
    EVT_CALL(N(func_80242B68_E07EC8), 8)
    EVT_CALL(GetNpcPos, NPC_08, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_08, LVar0, LVar2, 120)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245BD0_E0AF30) = {
    EVT_EXEC_GET_TID(N(D_80245978_E0ACD8), LVarA)
    EVT_EXEC_GET_TID(N(D_80245AA4_E0AE04), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2800)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245C74_E0AFD4) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_09, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -300)
        EVT_CALL(NpcMoveTo, NPC_09, LVar0, LVar2, 500)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_0A, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -300)
        EVT_CALL(NpcMoveTo, NPC_0A, LVar0, LVar2, 500)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

s32 N(D_80245D34_E0B094) = 0;

EvtScript N(D_80245D38_E0B098) = {
    EVT_CALL(EnableTexPanning, MODEL_kino3, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_kino5, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_kino6, TRUE)
    EVT_SET(LVar1, LVar0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x2000)
        EVT_CALL(SetTexPanOffset, 14, 0, LVar0, 0)
        EVT_WAIT(LVar1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245DF0_E0B150) = {
    EVT_CALL(EnableTexPanning, MODEL_kino4, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x2000)
        EVT_CALL(SetTexPanOffset, 12, 0, LVar0, 0)
        EVT_WAIT(16)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245E70_E0B1D0) = {
    EVT_CALL(EnableModel, MODEL_kino7, TRUE)
    EVT_CALL(EnableModel, MODEL_kino8, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_kino8, TRUE)
    EVT_CALL(SetModelCustomGfx, MODEL_kino7, 1, -1)
    EVT_CALL(SetCustomGfxBuilders, 1, EVT_PTR(N(func_80242C94_E07FF4)), 0)
    EVT_CHILD_THREAD
        EVT_CALL(MakeLerp, 0, 255, 90, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(func_80242C68_E07FC8), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x1000)
        EVT_ADD(LVar1, 0x400)
        EVT_CALL(SetTexPanOffset, 15, 0, LVar0, LVar1)
        EVT_WAIT(4)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245FF0_E0B350) = {
    EVT_CALL(EnableModel, MODEL_kino7, FALSE)
    EVT_CALL(EnableModel, MODEL_kino8, FALSE)
    EVT_SET(LVar0, 8)
    EVT_EXEC_GET_TID(N(D_80245D38_E0B098), LVarA)
    EVT_EXEC_GET_TID(N(D_80245DF0_E0B150), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2610)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 1)
    EVT_EXEC_GET_TID(N(D_80245D38_E0B098), LVarA)
    EVT_EXEC_GET_TID(N(D_80245E70_E0B1D0), LVarC)
    EVT_CALL(SetNpcFlagBits, NPC_0F, NPC_FLAG_ENABLE_HIT_SCRIPT, TRUE)
    EVT_CALL(MakeLerp, 0, 55, 90, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_kino1, 0, LVar0, 0)
        EVT_ADD(LVar0, -19)
        EVT_CALL(SetNpcPos, NPC_0F, -2529, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 8)
    EVT_EXEC_GET_TID(N(D_80245D38_E0B098), LVarA)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_0F, ANIM_ParadeIceShow_Violin_ShadeDivaSing)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2345)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_RETURN
    EVT_END
};
