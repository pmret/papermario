#include "common.h"

INCLUDE_API_ASM("os/code_43200_len_7c0", osMotorAccess);

s32 INCLUDE_ASM("os/code_43200_len_7c0", osMotorInit, OSMesgQueue* queue, OSPfs* pfs, int unk);

s32 INCLUDE_ASM("os/code_43200_len_7c0", osPfsAllocateFile, OSPfs* pfs, u16 unk1, u32 unk2, u8* unk3, u8* unk4,
                int unk5, s32* unk6);

INCLUDE_API_ASM("os/code_43200_len_7c0", osPfsDeclearPage);
