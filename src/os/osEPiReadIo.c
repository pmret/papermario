#include "common.h"

#ifdef MACOS
#define MOVE_ADDU
#endif

s32 osEPiReadIo(OSPiHandle* pihandle, u32 devAddr, u32* data) {
    s32 ret;

    osPiGetAccess();
    ret = osEPiRawReadIo(pihandle, devAddr, data);
    osPiRelAccess();
    return ret;
}
