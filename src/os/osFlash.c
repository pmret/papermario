#include "include_asm.h"
#include "ultra64.h"

void func_8006EF60(void) {
}

INCLUDE_ASM(s32, "os/osFlash", osFlashInit);

// void osFlashReadId(s32*, s32*); // extern
// extern OSMesgQueue D_800B0C58;
// extern OSPiHandle D_800B0C70;
// extern s8 D_800B0C74;
// extern s8 D_800B0C75;
// extern s8 D_800B0C76;
// extern s8 D_800B0C77;
// extern s8 D_800B0C78;
// extern s8 D_800B0C79;
// extern s32 D_800B0C7C;
// extern s32 D_800B0C80;
// extern void* D_800B0CE4;
// extern s32 D_800B0CE8;

// OSPiHandle* osFlashInit(void) {
//     s32 sp1C;
//     s32 sp18;

//     osCreateMesgQueue(&D_800B0C58, &D_800B0CE4, 1);
//     if (D_800B0C7C == 0xA8000000) {
//         return &D_800B0C70;
//     }
//     D_800B0C74 = 8;
//     D_800B0C7C = 0xA8000000;
//     D_800B0C75 = 5;
//     D_800B0C78 = 0xC;
//     D_800B0C76 = 0xF;
//     D_800B0C77 = 2;
//     D_800B0C79 = 1;
//     D_800B0C80 = 0;
//     bzero(&D_800B0C70 + 0x14, 0x60);
//     osEPiLinkHandle(&D_800B0C70);
//     osFlashReadId(&sp1C, &sp18);
//     if ((sp18 == 0xC2001E) || (sp18 == 0xC20001) || (sp18 == 0xC20000)) {
//         D_800B0CE8 = 0;
//     } else {
//         D_800B0CE8 = 1;
//     }
//     return &D_800B0C70;
// }

INCLUDE_ASM(s32, "os/osFlash", osFlashReadStatus);

INCLUDE_ASM(s32, "os/osFlash", osFlashReadId);

INCLUDE_ASM(s32, "os/osFlash", osFlashClearStatus);

INCLUDE_ASM(s32, "os/osFlash", osFlashAllErase);

INCLUDE_ASM(s32, "os/osFlash", osFlashSectorErase);

INCLUDE_ASM(s32, "os/osFlash", osFlashWriteBuffer);

INCLUDE_ASM(s32, "os/osFlash", osFlashWriteArray);

INCLUDE_ASM(s32, "os/osFlash", osFlashReadArray);
