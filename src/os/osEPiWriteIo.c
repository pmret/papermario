#define MOVE_ADDU

#include "common.h"

s32 osEPiWriteIo(OSPiHandle* handle, u32 devAddr, u32 data) {
    register s32 ret;

    __osPiGetAccess();
    ret = osEPiRawWriteIo(handle, devAddr, data);
    __osPiRelAccess();

    return ret;
}
