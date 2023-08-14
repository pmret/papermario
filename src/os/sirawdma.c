#include "PR/os_internal.h"
#include "PR/siint.h"

extern u32 __osBbIsBb;

void skKeepAlive(void);

s32 __osSiRawStartDma(s32 direction, void* dramAddr) {
    if (IO_READ(SI_STATUS_REG) & (SI_STATUS_DMA_BUSY | SI_STATUS_RD_BUSY)) {
        return -1;
    }

    if (direction == OS_WRITE) {
        osWritebackDCache(dramAddr, 64);
    }

    IO_WRITE(SI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));

    if (direction == OS_READ) {
#ifdef BBPLAYER
        if (__osBbIsBb) {
            register u32 mask = __osDisableInt();

            skKeepAlive();

            __osRestoreInt(mask);
        }
#endif
        IO_WRITE(SI_PIF_ADDR_RD64B_REG, PIF_RAM_START);
    } else {
        IO_WRITE(SI_PIF_ADDR_WR64B_REG, PIF_RAM_START);
    }

    if (direction == OS_READ) {
        osInvalDCache(dramAddr, 64);
    }

    return 0;
}
