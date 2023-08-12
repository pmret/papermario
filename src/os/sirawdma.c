#include "ultra64.h"
#include "macros.h"
#include "PR/os_internal.h"
#include "PR/siint.h"

#if VERSION_IQUE
INCLUDE_ASM(s32, "os/sirawdma", __osSiRawStartDma, s32 direction, void *dramAddr);
#else
s32 __osSiRawStartDma(s32 direction, void *dramAddr)
{
    if (IO_READ(SI_STATUS_REG) & (SI_STATUS_DMA_BUSY | SI_STATUS_RD_BUSY))
        return -1;

    if (direction == OS_WRITE)
        osWritebackDCache(dramAddr, 64);

    IO_WRITE(SI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));

    if (direction == OS_READ)
        IO_WRITE(SI_PIF_ADDR_RD64B_REG, 0x1FC007C0);
    else
        IO_WRITE(SI_PIF_ADDR_WR64B_REG, 0x1FC007C0);

    if (direction == OS_READ)
        osInvalDCache(dramAddr, 64);

    return 0;
}
#endif
