#include "PR/os_internal.h"
#include "PR/rcp.h"

void __osSpSetStatus(u32 data) {
    IO_WRITE(SP_STATUS_REG, data);
}
