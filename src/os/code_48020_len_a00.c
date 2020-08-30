#include "common.h"

s32 INCLUDE_ASM("os/code_48020_len_a00", osPfsChecker, OSPfs* pfs);

INCLUDE_ASM("os/code_48020_len_a00", corrupted_init);

INCLUDE_API_ASM("os/code_48020_len_a00", corrupted);

s32 INCLUDE_ASM("os/code_48020_len_a00", osPfsIsPlug, OSMesgQueue* queue, u8* unk);

INCLUDE_API_ASM("os/code_48020_len_a00", osPfsRequestData);

INCLUDE_API_ASM("os/code_48020_len_a00", osPfsGetInitData);
