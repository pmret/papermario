#include "PR/rcp.h"

u32 osAiGetStatus(void) {
    return IO_READ(AI_STATUS_REG);
}
