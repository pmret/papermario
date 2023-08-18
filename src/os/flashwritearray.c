#include "ultra64.h"
#include "PR/os_internal_flash.h"

extern u32 __osBbFlashAddress;
extern u32 __osBbFlashSize;
extern u8 __osBbFlashBuffer[128];

s32 osFlashWriteArray(u32 page_num) {
#ifdef BBPLAYER
    if (__osBbFlashSize != 0 && __osBbFlashSize >= page_num * 0x80 + 0x80) {
        bcopy(__osBbFlashBuffer, (void*)(__osBbFlashAddress + page_num * 0x80), 0x80);
        return FLASH_STATUS_WRITE_OK;
    }
    return FLASH_STATUS_WRITE_ERROR;
#else
    u32 status;
    OSTimer mytimer;
    OSMesgQueue timerMesgQueue;
    OSMesg dummy;

    if ((u32)__osFlashVersion == NEW_FLASH) {
        osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_PAGE_PROGRAM);
    }

    // start program page operation
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_PROGRAM_PAGE | page_num);

    // wait for completion by polling write-busy flag
    osCreateMesgQueue(&timerMesgQueue, &dummy, 1);
    do {
        osSetTimer(&mytimer, OS_USEC_TO_CYCLES(200), 0, &timerMesgQueue, &dummy);
        osRecvMesg(&timerMesgQueue, &dummy, OS_MESG_BLOCK);
        osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    } while ((status & FLASH_STATUS_WRITE_BUSY) == FLASH_STATUS_WRITE_BUSY);

    // check program operation status, clear status
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    osFlashClearStatus();

    if (((status & 0xFF) == 4) || ((status & 0xFF) == 0x44) || ((status & 4) == 4)) {
        return FLASH_STATUS_WRITE_OK;
    } else {
        return FLASH_STATUS_WRITE_ERROR;
    }
#endif
}
