#ifndef _CREDITS_H_
#define _CREDITS_H_

#include "common.h"
#include "message_ids.h"

#define STANDARD_POS_X              160

#if VERSION_PAL
#define STANDARD_APPEAR_TIME        33
#define STANDARD_HOLD_TIME          116
#define STANDARD_VANISH_TIME        25
#else
#define STANDARD_APPEAR_TIME        40
#define STANDARD_HOLD_TIME          174
#define STANDARD_VANISH_TIME        30
#endif

#define STANDARD_NEXT_TIME          230
#define STANDARD_TITLE_NEXT_TIME    270

enum {
    CREDITS_APPEAR_MODE_00      = 0,
    CREDITS_APPEAR_MODE_01      = 1,
    CREDITS_APPEAR_MODE_02      = 2,
    CREDITS_APPEAR_MODE_03      = 3,
    CREDITS_APPEAR_MODE_04      = 4,
    CREDITS_APPEAR_MODE_05      = 5,
};

enum {
    CREDITS_HOLD_MODE_00        = 0,
};

enum {
    CREDITS_VANISH_MODE_00      = 0,
    CREDITS_VANISH_MODE_01      = 1,
    CREDITS_VANISH_MODE_02      = 2,
    CREDITS_VANISH_MODE_03      = 3,
};

enum {
    CREDITS_FLAG_1              = 1,
};

#endif
