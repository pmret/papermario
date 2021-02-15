#include "common.h"

INCLUDE_ASM(s32, "os/code_3cd00_len_5f0", osContStartQuery, OSMesgQueue* queue);

INCLUDE_ASM(void, "os/code_3cd00_len_5f0", osContGetQuery, OSContStatus* status);

INCLUDE_ASM(s32, "os/code_3cd00_len_5f0", osContStartReadData, OSMesgQueue* queue);

INCLUDE_ASM(void, "os/code_3cd00_len_5f0", osContGetReadData, OSContPad* pad);

INCLUDE_ASM(s32, "os/code_3cd00_len_5f0", osPackReadData);
