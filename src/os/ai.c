
#include "PR/os_internal.h"
#include "PR/rcp.h"

s32 __osAiDeviceBusy(void) {
    register s32 status = IO_READ(AI_STATUS_REG);

    if (status & AI_STATUS_FIFO_FULL) {
        return TRUE;
    }

    return FALSE;
}
