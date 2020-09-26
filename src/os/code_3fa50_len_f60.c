#include "common.h"

INCLUDE_ASM(void, "os/code_3fa50_len_f60", bcopy, const void* src, void* dst, int size);

INCLUDE_ASM(void, "os/code_3fa50_len_f60", bzero, void* buf, int size);

INCLUDE_ASM(s32, "os/code_3fa50_len_f60", strchr);

INCLUDE_ASM(s32, "os/code_3fa50_len_f60", strlen);

INCLUDE_ASM(s32, "os/code_3fa50_len_f60", memcpy);

INCLUDE_ASM(s32, "os/code_3fa50_len_f60", _Printf);

INCLUDE_ASM(s32, "os/code_3fa50_len_f60", _Putfld);

INCLUDE_ASM(int, "os/code_3fa50_len_f60", sprintf, char* s, const char* fmt, ...);

INCLUDE_ASM(s32, "os/code_3fa50_len_f60", proutSprintf);

INCLUDE_ASM(void, "os/code_3fa50_len_f60", osCreateMesgQueue, OSMesgQueue* queue, OSMesg* mesg, s32 unk);
