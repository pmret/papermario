#include "PR/viint.h"

void *osViGetCurrentFramebuffer(void) {
    register u32 saveMask = __osDisableInt();
    void *framep = __osViCurr->framep;

    __osRestoreInt(saveMask);
    return framep;
}
