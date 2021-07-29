#define MOVE_ADDU

#include "common.h"

s32 osEPiReadIo(OSPiHandle* pihandle, u32 devAddr, u32* data) {
    s32 ret;

    osPiGetAccess();
    ret = osEPiRawReadIo(pihandle, devAddr, data);
    osPiRelAccess();
    return ret;
}
