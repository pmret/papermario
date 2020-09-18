#include "common.h"

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A370);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A37C);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A4D0);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A610);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A650);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A6E8);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A704);

// INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A854);
s32 func_8013A854(u32 a0) {
    //UnkSructFromfunc8013A854* unkStruct = D_80156954;
    u32 v0;
    u32 v1;
    u32 s0;
    u32 s1;
    u32 sp;
    // TODO sonicspiral - what is the real RA
    u32 returnAddress = 0x80000000;
    
    v0 = a0 << 5;
    if ((a0 < 0x5AU) == 0) {
        // L8013A880
        sp = sp - 0x20;
        return returnAddress;        
    } else { 
        v0 = v0 - a0;
        v1 = 0x8015A854;
        v0 = v0 << 2;
        v0 = v0 + v1;
        // TODO what is being set here?
        // v0 = (a0 * 0x7C) + func_8013A854(a0);
        // unkStruct->unk14 = 0U;
        // unkStruct->unk10 = -1U;
        v1 = -1;
    }

    sp = sp - 0x20;
    if (a0 < 0x5a) {
        
    } else {
        while (s0 == s1) {
            // /* 0D0F9C 8013A89C AFB00010 */   sw    $s0, 0x10($sp)
            // s1 = -1;
            s1 = 0xFFFE;
            // L8013A8A4
            v0 = a0 << 5;
            v0 = v0 - a0;
            v0 = v0 << 2;
            v0 = v0 + v1;
            a0 = s0;
            func_8013A854(a0);
        }    
        // L8013A8CC
        sp = sp + 0x20;
        return returnAddress;   
        // L8013A8F4
        v0 = a0 < 0x5A;
        if (v0 != 0) {
            return returnAddress; 
            v0 = a0 << 5;
            if (v0 == 0) {
                // L8013A918
                v0 = 0xFF;
                return returnAddress;
                v1 = a0 << 5;
                v1 = v1 - a0;
                v1 = v1 << 2;
                v0 = v0 + v1;
                return returnAddress; 
            }
        }
    }

    return v0;
}

// s32 func_8013A854(u32 arg0) {
//     UnkSructFromfunc8013A854* temp_v0 = D_80156954;
//     s32 phi_return;
//     phi_return = arg0 << 5;
//     if (arg0 < 0x5AU) {
//         temp_v0 = (arg0 * 0x7C) + func_8013A854(arg0);
//         temp_v0->unk14 = 0;
//         temp_v0->unk10 = (u16)-1;
//         phi_return = temp_v0;
//     }
//     return phi_return;
// }

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A93C);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A9C8);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013A9E8);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013AA9C);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013AF70);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013B0EC);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013B1B0);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013BC88);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013C048);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013C220);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013C3F0);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013CFA8);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013DAB4);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013E2F0);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013E904);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013EE48);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013EE68);

INCLUDE_ASM("code_d0a70_len_4fe0", func_8013F1F8);
