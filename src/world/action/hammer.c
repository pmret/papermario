#include "common.h"

INCLUDE_ASM(s32, "world/action/hammer", func_802B6000_E24ED0);
// s32 func_802B6000_E24ED0(s32 arg0) {
//     if (arg0 & 0x1000000) {
//         return TRUE;
//     }

//     switch (arg0 + ~0x6000F) {
//         case 1:
//         case 3:
//         case 5:
//         case 7:
//         case 9:
//         case 11:
//             return TRUE;
//     }
//     return FALSE;
// }

INCLUDE_ASM(s32, "world/action/hammer", func_802B6048_E24F18);

INCLUDE_ASM(s32, "world/action/hammer", func_802B62A4_E25174);

INCLUDE_ASM(void, "world/action/hammer", func_802B66A8_E25578, void);

INCLUDE_ASM(s32, "world/action/hammer", func_802B6820_E256F0);
