#include "common.h"

s32 INCLUDE_ASM("os/code_43200_len_7c0", __osMotorAccess, OSPfs* pfs, s32 unk);

s32 INCLUDE_ASM("os/code_43200_len_7c0", osMotorInit, OSMesgQueue* queue, OSPfs* pfs, int unk);

s32 INCLUDE_ASM("os/code_43200_len_7c0", osPfsAllocateFile, OSPfs* pfs, u16 unk1, u32 unk2, u8* unk3, u8* unk4,
                int unk5, s32* unk6);

INCLUDE_API_ASM("os/code_43200_len_7c0", osPfsDeclearPage);
