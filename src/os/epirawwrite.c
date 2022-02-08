#include "PR/piint.h"

s32 __osEPiRawWriteIo(OSPiHandle* pihandle, u32 devAddr, u32 data) {
    u32 stat;
    u32 domain;

    EPI_SYNC(pihandle, stat, domain);
    IO_WRITE(pihandle->baseAddress | devAddr, data);

    return 0;
}
