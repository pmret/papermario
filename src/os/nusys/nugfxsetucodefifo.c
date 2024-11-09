#include "common.h"
#include "nu/nusys.h"

void nuGfxSetUcodeFifo(void* fifoBufPtr, s32 size) {
    nuGfxUcodeFifoPtr = (u64*)fifoBufPtr;
    nuGfxUcodeFifoSize = size;
}
