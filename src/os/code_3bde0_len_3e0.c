#include "common.h"

INCLUDE_ASM_T(void, "os/code_3bde0_len_3e0", osCreatePiManager, OSPri prio, OSMesgQueue* queue, OSMesg* mesg, s32 unk);

INCLUDE_API_ASM("os/code_3bde0_len_3e0", osEPiRawStartDma);

INCLUDE_ASM_T(s32, "os/code_3bde0_len_3e0", osEPiWriteIo, OSPiHandle* handle, u32 unk1, u32 unk2);
