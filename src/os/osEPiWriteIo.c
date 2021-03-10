#include "common.h"

#ifdef MOVE_ISSUE
s32 osEPiWriteIo(OSPiHandle* handle, u32 devAddr, u32 data) {
    register s32 ret;

    __osPiGetAccess();
    ret = osEPiRawWriteIo(handle, devAddr, data);
    __osPiRelAccess();

    return ret;
}
#else
INCLUDE_ASM(s32, "os/osEPiWriteIo", osEPiWriteIo, OSPiHandle* handle, u32 devAddr, u32 data);
#endif
