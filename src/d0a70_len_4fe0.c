#include "common.h"

s32 D_8014EE10[] = { 0x80156920, };

s32 D_8014EE14[] = { 0x00000000, };

s32 D_8014EE18[] = { 0x90909000, 0x90909000, 0xFFFFFF00, 0xFFFFFF00, 0x00007800, 0x00000000, 0xFFFFFF00, 0xFFFFFF00,
                     0x00008800, 0x00000000,
                   };

s32 D_8014EE40[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000, };

s32 D_8014EE50[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x02000000, };

s16 D_8014EE60 = 300;

// padding
s16 D_8014EE62[] = {0};

s32 D_8014EE68[] = { 0xD9FDF9FF, 0x00000000, 0xD9FFFFFF, 0x00200005, 0xD7000002, 0xFFFFFFFF, 0xE2001E01, 0x00000000,
                     0xE3000A11, 0x00082CF0, 0xDF000000, 0x00000000,
                   };

s32 D_8014EE98[] = { 0x00441208, 0x00111208, 0x00000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40,
                     0x01000000, 0x00404B40, 0x00104B40, 0x01000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40,
                     0x00104B40, 0x01000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40, 0x01000000,
                     0x00404B40, 0x00104B40, 0x01000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40,
                     0x01000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40, 0x01000000, 0x00441208,
                     0x00111208, 0x00000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40, 0x01000000,
                     0x00441208, 0x00111208, 0x00000000,
                   };

s32 D_8014EF64[] = { 0x00014358, 0x00018200, 0x0001A858, 0x0001E830, 0x00029458, 0x000314E0, 0x00033498, 0x00038988,
                     0x00039228, 0x0005B7A8, 0x0007CF10, 0x00086490, 0x00096258, 0x000A1820, 0x000ACDE8, 0x000BBF68,
                     0x000C0490, 0x000C49B8, 0x000C6150, 0x000CA380, 0x00000000, 0x00000000, 0x00000000,
                   };

typedef struct {
    /* 0x00 */ char unk_00[0x1];
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[0x01];
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ char unk_07[0x9];
    /* 0x10 */ s16 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk_18[0x1C];
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ char unk_38[0x44];
} UnkD0A70Struct ; // size = 0x7C

typedef UnkD0A70Struct UnkD0A70StructList[90];
extern UnkD0A70StructList* D_80156954;

void func_8013A370(s16 arg0) {
    D_8014EE60 = arg0;
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013A37C);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013A4D0);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013A610);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013A650);

void func_8013A6E8(void) {
    func_8013A650();
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013A704);

void func_8013A854(u32 idx) {
    if (idx < 90) {
        (*D_80156954)[idx].unk_14 = 0;
        (*D_80156954)[idx].unk_10 = -1;
    }
}

void func_8013A888(u32 idx) {
    if (idx < 90) {
        s32 temp_s0;

        do {
            temp_s0 = (*D_80156954)[idx].unk_10;
            func_8013A854(idx);
            idx = temp_s0;
        } while (temp_s0 != -1);
    }
}

s16 func_8013A8E0(s32 idx) {
    // TODO find better match
    if ((u32)idx >= 90) {
        return -1;
    }

    if (idx >= 90) {
        return 0xFF;
    } else {
        return (*D_80156954)[idx].unk_10;
    }
}

UnkD0A70Struct* func_8013A920(s32 idx) {
    return &(*D_80156954)[idx];
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013A93C);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013A9C8);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013A9E8);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013AA9C);

void func_8013AF20(s32 idx, u16 arg1, s32 arg2) {
    if ((*D_80156954)[idx].unk_14 & 1) {
        if (arg2 != 0) {
            (*D_80156954)[idx].unk_14 |= arg1;
        } else {
            (*D_80156954)[idx].unk_14 &= ~arg1;
        }
    }
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013AF70);

void func_8013B0EC(UnkD0A70Struct* arg0) {
    switch (arg0->unk_01) {
        case 3:
            if (arg0->unk_34 == 0) {
                arg0->unk_03 = 1;
                arg0->unk_04 = 16;
            } else {
                arg0->unk_03 = 1;
                arg0->unk_04 = 1;
            }
        case 1:
            func_8013C048(arg0);
            break;
        case 2:
            func_8013C3F0(arg0);
            break;
        case 0:
        case 4:
            func_8013BC88(arg0);
            break;
        default:
            return;
    }

    if (arg0->unk_05 == 4) {
        func_8013EE68(arg0);
    }

    switch (arg0->unk_06) {
        case 0xB:
        case 0xC:
            func_8013F1F8(arg0);
            break;
    }
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013B1B0);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013BC88);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013C048);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013C220);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013C3F0);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013CFA8);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013DAB4);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013E2F0);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013E904);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013EE48);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013EE68);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013F1F8);
