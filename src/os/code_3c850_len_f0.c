#include "common.h"

u32 __osPiAccessQueueEnabled = 0;

INCLUDE_ASM(s32, "os/code_3c850_len_f0", __osPiCreateAccessQueue);

INCLUDE_ASM(s32, "os/code_3c850_len_f0", __osPiGetAccess);

INCLUDE_ASM(s32, "os/code_3c850_len_f0", __osPiRelAccess);
