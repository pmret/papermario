#include "ultra64.h"
#include "PR/os_internal_flash.h"

void osFlashReadId(u32* flash_type, u32* flash_maker) {
    u8 tmp;

    // why read status ?
    osFlashReadStatus(&tmp);

    // select silicon id read mode
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_ID);

    // read silicon id using DMA
    __osFlashMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    __osFlashMsg.hdr.retQueue = &__osFlashMessageQ;
    __osFlashMsg.dramAddr = __osFlashID;
    __osFlashMsg.devAddr = 0;
    __osFlashMsg.size = 2 * sizeof(u32);

    osInvalDCache(__osFlashID, sizeof(__osFlashID));
    osEPiStartDma(&__osFlashHandler, &__osFlashMsg, OS_READ);
    osRecvMesg(&__osFlashMessageQ, NULL, OS_MESG_BLOCK);

    *flash_type = __osFlashID[0];
    *flash_maker = __osFlashID[1];
    return;
}
