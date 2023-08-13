#include "ultra64.h"
#include "PR/os_internal_flash.h"

extern u32 __osBbFlashAddress;
extern u32 __osBbFlashSize;

s32 osFlashSectorErase(u32 page_num) {
#ifdef BBPLAYER
    if (__osBbFlashSize != 0 && page_num * 0x80 < __osBbFlashSize) {
        int i;
        u32* p = (u32*)(__osBbFlashAddress + page_num * 0x80);

        for (i = 0; i < 0x80 / 4; i++) {
            p[i] = -1;
        }
        return FLASH_STATUS_ERASE_OK;
    }
    return FLASH_STATUS_ERASE_ERROR;
#else
    u32 status;
    OSTimer mytimer;
    OSMesgQueue timerMesgQueue;
    OSMesg dummy;

    // start sector erase operation
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_SECTOR_ERASE | page_num);
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_EXECUTE_ERASE);

    // wait for completion by polling erase-busy flag
    osCreateMesgQueue(&timerMesgQueue, &dummy, 1);

    do {
        osSetTimer(&mytimer, OS_USEC_TO_CYCLES(12500), 0, &timerMesgQueue, &dummy);
        osRecvMesg(&timerMesgQueue, &dummy, OS_MESG_BLOCK);
        osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    } while ((status & FLASH_STATUS_ERASE_BUSY) == FLASH_STATUS_ERASE_BUSY);

    // check erase operation status, clear status
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    osFlashClearStatus();

    if (((status & 0xFF) == 8) || ((status & 0xFF) == 0x48) || ((status & 8) == 8)) {
        return FLASH_STATUS_ERASE_OK;
    } else {
        return FLASH_STATUS_ERASE_ERROR;
    }
#endif
}
