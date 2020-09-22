#include "common.h"

INCLUDE_ASM_T(s32, "os/code_48020_len_a00", osPfsChecker, OSPfs* pfs);

INCLUDE_ASM("os/code_48020_len_a00", corrupted_init);

INCLUDE_API_ASM("os/code_48020_len_a00", corrupted);

INCLUDE_ASM_T(s32, "os/code_48020_len_a00", osPfsIsPlug, OSMesgQueue* queue, u8* unk);

INCLUDE_API_ASM("os/code_48020_len_a00", osPfsRequestData);

INCLUDE_API_ASM("os/code_48020_len_a00", osPfsGetInitData);
