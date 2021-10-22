#include "common.h"
#include "include_asm_libultra.h"

#ifndef MACOS
s32 osEPiLinkHandle(OSPiHandle* EPiHandle) {
    u32 saveMask = __osDisableInt();
    EPiHandle->next = __osPiTable;
    __osPiTable = EPiHandle;
    __osRestoreInt(saveMask);
    return 0;
}
#else
INCLUDE_ASM_LIBULTRA(osEPiLinkHandle, osEPiLinkHandle);
#endif
