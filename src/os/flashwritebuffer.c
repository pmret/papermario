#include "ultra64.h"
#include "PR/os_internal_flash.h"

extern u32 __osBbFlashAddress;
extern u32 __osBbFlashSize;

#ifdef BBPLAYER
u8 __osBbFlashBuffer[0x80];
#endif

s32 osFlashWriteBuffer(OSIoMesg* mb, s32 priority, void* dramAddr, OSMesgQueue* mq) {
#ifdef BBPLAYER
    if (__osBbFlashSize != 0) {
        bcopy(dramAddr, __osBbFlashBuffer, 0x80);
        return osSendMesg(mq, NULL, NULL);
    }
    return -1;
#else
    s32 ret;

    // select page program mode
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_PAGE_PROGRAM);

    // DMA 128-byte page
    mb->hdr.pri = priority;
    mb->hdr.retQueue = mq;
    mb->dramAddr = dramAddr;
    mb->devAddr = 0;
    mb->size = FLASH_BLOCK_SIZE;

    ret = osEPiStartDma(&__osFlashHandler, mb, OS_WRITE);

    return ret;
#endif
}
