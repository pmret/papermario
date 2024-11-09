#include "ultra64.h"
#include "PR/os_internal_flash.h"

void osFlashClearStatus(void) {
    // select status mode
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_STATUS);
    // clear status
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress, 0);
    return;
}
