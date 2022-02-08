#include "PR/rcp.h"

u32 __osSpGetStatus(void) {
    return IO_READ(SP_STATUS_REG);
}
