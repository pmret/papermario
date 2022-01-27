#include "common.h"

s32 osEPiWriteIo(OSPiHandle* handle, u32 devAddr, u32 data) {
    register s32 ret;

    osPiGetAccess();
    ret = osEPiRawWriteIo(handle, devAddr, data);
    osPiRelAccess();

    return ret;
}
