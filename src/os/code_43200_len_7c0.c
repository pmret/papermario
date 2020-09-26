#include "common.h"

INCLUDE_ASM(s32, "os/code_43200_len_7c0", osMotorAccess);

INCLUDE_ASM(s32, "os/code_43200_len_7c0", osMotorInit, OSMesgQueue* queue, OSPfs* pfs, int unk);

INCLUDE_ASM(s32, "os/code_43200_len_7c0", osPfsAllocateFile, OSPfs* pfs, u16 unk1, u32 unk2, u8* unk3, u8* unk4,
              int unk5, s32* unk6);

INCLUDE_ASM(s32, "os/code_43200_len_7c0", osPfsDeclearPage);
