#include "ultra64.h"
#include "PR/os_internal_flash.h"

void osFlashReadStatus(u8* flash_status) {
    u32 status;

    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_STATUS);
    // read status
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);

    // why twice ?
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_STATUS);
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);

    *flash_status = status & 0xFF;
    return;
}
