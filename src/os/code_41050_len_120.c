#include "common.h"

INCLUDE_ASM(void, "os/code_41050_len_120", osSpTaskYield, void);

INCLUDE_ASM(OSYieldResult, "os/code_41050_len_120", osSpTaskYielded, OSTask* tp);

INCLUDE_API_ASM("os/code_41050_len_120", osSiRawStartDma);
