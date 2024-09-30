#include "ultra64.h"
#include "PR/os_internal_flash.h"

u32 __osFlashGetAddr(u32 page_num) {
    u32 devAddr;

    if (__osFlashVersion == OLD_FLASH) {
        // Account for hardware bug in old flash where the address bits are shifted 1-off where they should be
        devAddr = page_num * (FLASH_BLOCK_SIZE >> 1);
    } else {
        devAddr = page_num * FLASH_BLOCK_SIZE;
    }

    return devAddr;
}
