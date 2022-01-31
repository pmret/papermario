#include "PR/viint.h"

void osViSwapBuffer(void* frameBufPtr) {
    u32 saveMask = __osDisableInt();

    __osViNext->framep = frameBufPtr;
    __osViNext->state |= VI_STATE_BUFFER_UPDATED;
    __osRestoreInt(saveMask);
}
