#include "common.h"

u8 hdwrBugFlag = 0; // Local Static to osAiSetNextBuffer.

INCLUDE_ASM(s32, "os/code_3ca80_len_a0", osAiSetNextBuffer, void* buf, u32 unk);
