#include "common.h"

u32 __osSiAccessQueueEnabled = 0;

INCLUDE_ASM(s32, "os/41170_len_f0", osSiCreateAccessQueue);

INCLUDE_ASM(s32, "os/41170_len_f0", osSiGetAccess);

INCLUDE_ASM(s32, "os/41170_len_f0", osSiRelAccess);
