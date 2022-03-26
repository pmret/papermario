#include "PR/rcp.h"

u32 osAiGetLength(void) {
    return IO_READ(AI_LEN_REG);
}
