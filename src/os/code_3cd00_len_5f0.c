#include "common.h"

INCLUDE_ASM_T(s32, "os/code_3cd00_len_5f0", osContStartQuery, OSMesgQueue* queue);

INCLUDE_ASM_T(void, "os/code_3cd00_len_5f0", osContGetQuery, OSContStatus* status);

INCLUDE_ASM_T(s32, "os/code_3cd00_len_5f0", osContStartReadData, OSMesgQueue* queue);

INCLUDE_ASM_T(void, "os/code_3cd00_len_5f0", osContGetReadData, OSContPad* pad);

INCLUDE_API_ASM("os/code_3cd00_len_5f0", osPackReadData);

INCLUDE_ASM_T(s32, "os/code_3cd00_len_5f0", osContInit, OSMesgQueue* queue, u8* unk, OSContStatus* status);

INCLUDE_API_ASM("os/code_3cd00_len_5f0", osContGetInitData);

INCLUDE_API_ASM("os/code_3cd00_len_5f0", osPackRequestData);

INCLUDE_ASM_T(u32, "os/code_3cd00_len_5f0", osVirtualToPhysical, void* virt);
