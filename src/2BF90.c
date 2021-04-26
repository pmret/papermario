#include "audio.h"

INCLUDE_ASM(s32, "2BF90", func_80050B90);

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

INCLUDE_ASM(s32, "2BF90", func_80050C64);

INCLUDE_ASM(s32, "2BF90", func_80050CA0);

INCLUDE_ASM(void, "2BF90", func_80050D50, UnkAl1E4* arg0);

INCLUDE_ASM(s32, "2BF90", func_80050E18);

INCLUDE_ASM(s32, "2BF90", func_80050E84);

INCLUDE_ASM(s32, "2BF90", func_80050EF0);

INCLUDE_ASM(s32, "2BF90", func_80050F64);

INCLUDE_ASM(s32, "2BF90", func_80050FD0);

INCLUDE_ASM(s32, "2BF90", func_80051050);

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
