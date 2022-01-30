#include "PR/osint.h"
#include "PR/rcp.h"

s32 osAiSetNextBuffer(void *bufPtr, u32 size) {
    static u8 hdwrBugFlag = FALSE;
    char *bptr;

    if (__osAiDeviceBusy()) {
        return -1;
    }

    bptr = bufPtr;

    if (hdwrBugFlag) {
        bptr -= 0x2000;
    }

    if ((((u32)bufPtr + size) & 0x1fff) == 0) {
        hdwrBugFlag = TRUE;
    } else {
        hdwrBugFlag = FALSE;
    }

    IO_WRITE(AI_DRAM_ADDR_REG, osVirtualToPhysical(bptr));
    IO_WRITE(AI_LEN_REG, size);
    return 0;
}
