#include "common.h"

u32 __osPiAccessQueueEnabled = 0;

INCLUDE_ASM(s32, "os/3c850_len_f0", osPiCreateAccessQueue);

INCLUDE_ASM(s32, "os/3c850_len_f0", osPiGetAccess);

INCLUDE_ASM(s32, "os/3c850_len_f0", osPiRelAccess);
