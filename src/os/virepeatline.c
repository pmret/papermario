#include "PR/viint.h"

void osViRepeatLine(u8 active) {
    register u32 saveMask = __osDisableInt();

    if (active) {
        __osViNext->state |= VI_STATE_REPEATLINE;
    } else {
        __osViNext->state &= ~VI_STATE_REPEATLINE;
    }

    __osRestoreInt(saveMask);
}
