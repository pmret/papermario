#include "audio.h"

extern s32 D_80078520;

void func_80050B90(UnkAl834* arg0, s8 arg1, s8 arg2, SndGlobals* arg3) {
    UnkAl1E4* temp_v0;
    s32 i;
    
    snd_memset(arg0, sizeof(*arg0), 0);

    for (i = 0; i < ARRAY_COUNT(arg0->unk_24); i++) {
        temp_v0 = &arg0->unk_24[i];
        temp_v0->unk_14 = i;
        temp_v0->unk_18 = 1;
        temp_v0->unk_38 = 0x7F000000;
    }

    arg0->unk_00 = arg3;
    arg0->unk_04 = 1;
    arg0->unk_0C = 2;
    arg0->unk_08 = 2;
    arg0->unk_22 = arg1;
    arg0->unk_23 = arg2;
}


s32 func_80050C30(u32 arg0) {
    if (D_8009A628->unk_20 <= arg0) {
        return 3;
    } else {
        return 0;
    }
}

void func_80050C54(s32 arg0, s8 arg1) {
    D_8009A628->unk_21 = arg1;
}

void func_80050C64(s32 arg0, s32 arg1) {
    UnkAl834* A = D_8009A628;
    UnkAl1E4* B = &A->unk_24[arg0];
    
    if (arg1 == 0) {
        B->unk_25 = 0;
    } else {
        B->unk_25 = 2;
    }
}

s32 func_80050CA0(s32 arg0, s32 arg1) {
    UnkAl834* temp_a0 = D_8009A628;
    UnkAl1E4* temp_s0 = &temp_a0->unk_24[arg0];
    s32* temp_a1 = temp_a0->unk_10[arg0];
    s32 retVal = 0;
    
    if (temp_a1 != NULL) {
        if (temp_s0->unk_20 == 0) {
            func_800510A4(temp_a0, temp_a1, arg0);
            if (arg1 != 0) {
                temp_s0->unk_28 = arg1;
                temp_s0->unk_2A = 0;
                temp_s0->unk_2B = 0x7F;
                temp_s0->unk_26 = 0;
                func_80050D50(temp_s0);
            }
        } else {
            retVal = 1;
        }
    } else {
        retVal = 2;
    }
    return retVal;
}

void func_80050D50(UnkAl1E4* arg0) {
    u16 temp_a1 = arg0->unk_28;
    
    if (arg0->unk_2A == 0xFF) {
        arg0->unk_2A = arg0->unk_38 >> 0x18;
    }

    if (temp_a1 >= 250 && temp_a1 <= 10000) {
        arg0->unk_38 = arg0->unk_2A << 0x18;
        arg0->unk_42 = arg0->unk_2B;
        arg0->unk_40 = (u32)(temp_a1 * 10) / 115;
        arg0->unk_3C = ((arg0->unk_2B - arg0->unk_2A) << 0x18) / (arg0->unk_40 & 0xFFFF);
    }
    
    arg0->unk_28 = 0;
    arg0->unk_2A = 0;
    arg0->unk_2B = 0;
}

//CLOVER document
void func_80050E18(s32 arg0, s32 arg1) {
    UnkAl1E4* temp_v1 = &D_8009A628->unk_24[arg0];
    
    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != NULL)) {
        if (arg1 != 0) {
            temp_v1->unk_2A = 0xFF;
            temp_v1->unk_28 = arg1;
            temp_v1->unk_2B = 0;
            temp_v1->unk_26 = 2;
            return;
        }
        temp_v1->unk_24 = 3;
    }
}

//CLOVER document
void func_80050E84(s32 arg0, s32 arg1) {
    UnkAl1E4* temp_v1 = &D_8009A628->unk_24[arg0];
    
    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != NULL)) {
        temp_v1->unk_24 = 1;
        if (arg1 != 0) {
            temp_v1->unk_28 = arg1;
        } else {
            temp_v1->unk_28 = 0xFA;
        }
        temp_v1->unk_2A = 0;
        temp_v1->unk_2B = 0x7F;
        temp_v1->unk_26 = 0;
    }
}

//CLOVER document
void func_80050EF0(s32 arg0) {
    UnkAl1E4* temp_v1 = &D_8009A628->unk_24[arg0];
    
    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != NULL)) {
        if (temp_v1->unk_24 != 0) {
            temp_v1->unk_08 = NULL;
            temp_v1->unk_20 = 0;
            temp_v1->unk_24 = 0U;
            return;
        }
        temp_v1->unk_08 = &D_80078520;
        temp_v1->unk_18 = 1;
    }
}

//CLOVER document
void func_80050F64(s32 arg0, s32 arg1) {
    UnkAl1E4* temp_v1 = &D_8009A628->unk_24[arg0];
    
    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != 0)) {
        if (arg1 != 0) {
            temp_v1->unk_28 = arg1;
        } else {
            temp_v1->unk_28 = 250;
        }
        temp_v1->unk_2A = -1;
        temp_v1->unk_2B = 0;
        temp_v1->unk_26 = 1;
    }
}

//CLOVER document
void func_80050FD0(s32 arg0, s32 arg1, s32 arg2) {
    UnkAl1E4* temp_v1 = &D_8009A628->unk_24[arg0];
    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != 0)) {
        if (arg2 <= 0) {
            arg2 = 1;
        } else if (arg2 >= 0x80) {
            arg2 = 0x7F;
        }
        if (arg1 != 0) {
            temp_v1->unk_28 = arg1;
        } else {
            temp_v1->unk_28 = 250;
        }
        temp_v1->unk_2A = -1;
        temp_v1->unk_2B = arg2;
        temp_v1->unk_26 = 0;
    }
}

//CLOVER document
s32 func_80051050(s32 arg0) {
    UnkAl1E4* temp_v1 = &D_8009A628->unk_24[arg0];
    s32 var_a0 = 0;
    
    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != 0)) {
        var_a0 = 1;
        if (temp_v1->unk_24 != 0) {
            var_a0 = 2;
        }
    }
    return var_a0;
}

INCLUDE_ASM(s32, "2BF90", func_800510A4);

void func_800511BC(UnkAl834* arg0) {
    u32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_7B4); i++) {
        UnkAl8* temp = &arg0->unk_7B4[i];

        if ((temp->unk_00.u8[3] == 1) && (arg0->unk_00->unk_1320[i].unk_45 != arg0->unk_22)) {
            temp->unk_00.s32 = 0;
        }
    }

    for (j = 0; j < ARRAY_COUNT(arg0->unk_24); j++) {
        UnkAl1E4* temp = &arg0->unk_24[j];
        s32 var;

        if (temp->unk_08 != 0) {
            if (arg0->unk_21 != 0) {
                func_80051334(arg0, temp);
            }

            var = temp->unk_24;
            if (var != 0) {
                if (var == 3) {
                    temp->unk_24 = 2;
                    func_800522A8(arg0, temp);
                    func_800521E8(arg0, temp);
                } else if (temp->unk_24 == 1) {
                    temp->unk_24 = 0;
                    if (temp->unk_28 != 0) {
                        func_80050D50(temp);
                    }
                    func_8005232C(arg0, temp);
                }
            } else {
                if (temp->unk_28 != 0) {
                    func_80050D50(temp);
                }
                if (temp->unk_25 == 2) {
                    func_800521E8(arg0, temp);
                    temp->unk_25 = 1;
                }
                func_80051434(arg0, temp);
            }
        }
    }

    arg0->unk_21 = 0;
}

INCLUDE_ASM(void, "2BF90", func_80051334, UnkAl834* arg0, UnkAl1E4* arg1);

INCLUDE_ASM(void, "2BF90", func_80051434, UnkAl834* arg0, UnkAl1E4* arg1);

INCLUDE_ASM(s32, "2BF90", func_800521D0);

INCLUDE_ASM(void, "2BF90", func_800521E8, UnkAl834* arg0, UnkAl1E4* arg1);

INCLUDE_ASM(void, "2BF90", func_800522A8, UnkAl834* arg0, UnkAl1E4* arg1);

INCLUDE_ASM(void, "2BF90", func_8005232C, UnkAl834* arg0, UnkAl1E4* arg1);
