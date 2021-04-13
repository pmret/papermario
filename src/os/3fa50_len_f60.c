#include "common.h"

INCLUDE_ASM(void, "os/3fa50_len_f60", bcopy, const void* src, void* dst, int size);

INCLUDE_ASM(void, "os/3fa50_len_f60", bzero, void* buf, int size);

INCLUDE_ASM(s32, "os/3fa50_len_f60", strchr);

INCLUDE_ASM(s32, "os/3fa50_len_f60", strlen);

INCLUDE_ASM(s32, "os/3fa50_len_f60", memcpy);
