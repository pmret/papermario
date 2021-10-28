#include "common.h"

typedef struct {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ char unk_07[0x1];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ s32 unk_1C[2][4];
    /* 0x3C */ f32 unk_3C[2][4];
    /* 0x5C */ s32* unk_5C;
    /* 0x60 */ s16 unk_60;
    /* 0x62 */ char unk_62[0x2];
    /* 0x64 */ s32* unk_64;
    /* 0x68 */ s32* unk_68;
    /* 0x6C */ s32* unk_6C;
    /* 0x70 */ s32* unk_70;
    /* 0x74 */ s32* unk_74;
    /* 0x78 */ char unk_78[0x4];
} UnkD0A70Struct; // size = 0x7C

typedef struct Unk8Struct {
    /* 0x00 */ s32* unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x2];
} Unk8Struct; // size = 0x8

typedef UnkD0A70Struct UnkD0A70StructList[90];

s32 D_8014EE10[] = { 0x80156920, };

s16 D_8014EE14 = 0;

// padding
s16 D_8014EE16 = { 0x0000 };

s32 D_8014EE18[] = { 0x90909000, 0x90909000, 0xFFFFFF00, 0xFFFFFF00, 0x00007800, 0x00000000, 0xFFFFFF00, 0xFFFFFF00,
                     0x00008800, 0x00000000,
                   };

s32 D_8014EE40[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000, };

s32 D_8014EE50[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x02000000, };

u16 D_8014EE60 = 300;

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

extern s32* D_80156948[2];
extern s32* D_80156950;
extern UnkD0A70StructList* D_80156954;
extern s8 D_80156958[2];
extern s32 D_80156960[2];
extern s32 D_80156968[2];
extern s8 D_80156970;

extern Unk8Struct D_80156F20[8];

void func_8013A93C(UnkD0A70Struct*);
void func_8013A9C8(UnkD0A70Struct*);
void func_8013A9E8(UnkD0A70Struct*);
void func_8013BC88(UnkD0A70Struct*);
void func_8013C048(UnkD0A70Struct*);
void func_8013C220(UnkD0A70Struct*);
void func_8013C3F0(UnkD0A70Struct*);
void func_8013EE68(UnkD0A70Struct*);
void func_8013F1F8(UnkD0A70Struct*);

void func_8013A370(s16 arg0) {
    D_8014EE60 = arg0;
}

void func_8013A37C(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80156948); i++) {
        D_80156948[i] = _heap_malloc(&gSpriteHeapPtr, D_8014EE60 * 0x10);
    }

    D_80156954 = (UnkD0A70StructList*)_heap_malloc(&gSpriteHeapPtr, ARRAY_COUNT(*D_80156954) * sizeof((*D_80156954)[0]));

    for (i = 0; i < ARRAY_COUNT(*D_80156954); i++) {
        func_8013A9E8(&(*D_80156954)[i]);
        func_8013A9C8(&(*D_80156954)[i]);
    }

    for (i = 0; i < ARRAY_COUNT(D_80156958); i++) {
        D_80156958[i] = -1;
        D_80156960[i] = 0;
        D_80156968[i] = 0;
        D_80156970 = 0;
    }

    for (i = 0; i < ARRAY_COUNT(D_80156F20); i++) {
        D_80156F20[i].unk_00 = 0;
        D_80156F20[i].unk_04 = 0;
        D_80156F20[i].unk_05 = 0;
    }

    D_8014EE14 = 0;
    D_80156950 = D_80156948[gCurrentDisplayContextIndex];
}

void func_8013A4D0(void) {
    s32 i;

    D_80156950 = D_80156948[gCurrentDisplayContextIndex];
    D_8014EE14 = 0;
    func_8013A9E8(&(*D_80156954)[0]);

    (*D_80156954)[0].unk_14 |= 1;

    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if (((*D_80156954)[i].unk_14 & 1) && ((*D_80156954)[i].unk_05 != 5)) {
            func_8013A93C(&(*D_80156954)[i]);
        }
    }

    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if ((*D_80156954)[i].unk_14 & 1 && (*D_80156954)[i].unk_5C != NULL) {
            s32 temp = (*D_80156954)[i].unk_06; // TODO find a better way to match

            if (temp == 11 || (*D_80156954)[i].unk_06 == 12) {
                continue;
            }

            general_heap_free((*D_80156954)[i].unk_5C);
            (*D_80156954)[i].unk_5C = 0;
            (*D_80156954)[i].unk_60 = 0;
        }
    }
}

void func_8013A610(s32* arg0, s8 arg1) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80156F20); i++) {
        if (D_80156F20[i].unk_00 == NULL) {
            D_80156F20[i].unk_00 = arg0;
            D_80156F20[i].unk_04 = 4;
            D_80156F20[i].unk_05 = arg1;
            return;
        }
    }
}

void func_8013A650(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80156F20); i++) {
        if (D_80156F20[i].unk_00 != 0) {
            D_80156F20[i].unk_04--;

            if (D_80156F20[i].unk_04 == 0) {
                if (D_80156F20[i].unk_05 != 0) {
                    heap_free(D_80156F20[i].unk_00);
                    D_80156F20[i].unk_00 = NULL;
                } else {
                    general_heap_free(D_80156F20[i].unk_00);
                    D_80156F20[i].unk_00 = NULL;
                }

                D_80156F20[i].unk_04 = 0;
                D_80156F20[i].unk_05 = 0;
            }
        }
    }
}

void func_8013A6E8(void) {
    func_8013A650();
}

s32 func_8013A704(s32 arg0) {
    s32 count;
    s32 cond;
    s32 iPrev;
    s32 ret;
    s32 i;

    count = 0;
    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if (!((*D_80156954)[i].unk_14 & 1)) {
            count++;
        }
    }

    if (count < arg0) {
        return -1;
    }

    ret = 0;
    cond = FALSE;
    count = 0;
    iPrev = -1;
    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if (!((*D_80156954)[i].unk_14 & 1)) {
            if (!cond) {
                ret = i;
                cond = TRUE;
            } else {
                (*D_80156954)[iPrev].unk_10 = i;
            }

            (*D_80156954)[i].unk_00 = i;
            func_8013A9E8(&(*D_80156954)[i]);
            count++;
            (*D_80156954)[i].unk_14 |= 1;
            iPrev = i;
            if (count == arg0) {
                (*D_80156954)[i].unk_10 = -1;
                break;
            }
        }
    }

    return ret;
}

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

void func_8013A93C(UnkD0A70Struct* arg0) {
    if (arg0->unk_64 != 0) {
        arg0->unk_64 = 0;
    }
    if (arg0->unk_68 != 0) {
        func_8013A610(arg0->unk_68, 1);
        arg0->unk_68 = 0;
    }
    if (arg0->unk_6C != 0) {
        func_8013A610(arg0->unk_6C, 1);
        arg0->unk_6C = 0;
    }
    if (arg0->unk_70 != 0) {
        func_8013A610(arg0->unk_70, 1);
        arg0->unk_70 = 0;
    }
    if (arg0->unk_74 != 0) {
        func_8013A610(arg0->unk_74, 1);
        arg0->unk_74 = 0;
    }
}

void func_8013A9C8(UnkD0A70Struct* arg0) {
    arg0->unk_64 = 0;
    arg0->unk_68 = 0;
    arg0->unk_6C = 0;
    arg0->unk_70 = 0;
    arg0->unk_74 = 0;
    arg0->unk_5C = 0;
    arg0->unk_60 = 0;
}

void func_8013A9E8(UnkD0A70Struct* arg0) {
    s32 i;
    s32 j;

    arg0->unk_10 = -1;
    arg0->unk_05 = 0;
    arg0->unk_06 = 0;
    arg0->unk_14 = 0;
    arg0->unk_01 = 0;
    arg0->unk_02 = 0;
    arg0->unk_08 = 0;
    arg0->unk_0A = 0;
    arg0->unk_0C = 0;
    arg0->unk_0E = 0;
    arg0->unk_1C[0][3] = 255;
    arg0->unk_1C[1][3] = 255;
    arg0->unk_03 = 0;
    arg0->unk_04 = 0;
    arg0->unk_08 = 0;
    arg0->unk_0A = 0;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_1C); i++) {
        for (j = 0; j < ARRAY_COUNT(arg0->unk_1C[0]); j++) {
            arg0->unk_1C[i][j] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(arg0->unk_3C); i++) {
        for (j = 0; j < ARRAY_COUNT(arg0->unk_3C[0]); j++) {
            arg0->unk_3C[i][j] = 0;
        }
    }
}

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
            if (arg0->unk_1C[1][2] == 0) {
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
        case 11:
        case 12:
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

void func_8013EE48(UnkD0A70Struct* arg0) {
    arg0->unk_3C[0][0] = 0.0f;
    arg0->unk_3C[0][1] = 50.0f;
    arg0->unk_3C[0][2] = 30.0f;
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013EE68);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013F1F8);
