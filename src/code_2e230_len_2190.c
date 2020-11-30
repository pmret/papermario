#include "code_2e230_len_2190.h"

#undef alHeapAlloc

typedef struct UnkAl0 {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ ALHeap* unk_18;
} UnkAl0;

typedef struct UnkAl6CC {
    /* 0x00 */ char unk_00[0x6CC];
} UnkAl6CC;

typedef struct UnkAlA9C {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ UnkAl6CC* unk_04;
    /* 0x08 */ char unk_08[0xA94];
} UnkAlA9C;

typedef struct UnkAl48 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
    /* 0x10 */ s8 unk_10;
    /* 0x11 */ char unk_11[0x31];
    /* 0x42 */ s8 unk_42;
    /* 0x43 */ s8 unk_43;
    /* 0x44 */ s8 unk_44;
    /* 0x45 */ s8 unk_45;
    /* 0x46 */ char unk_46[2];
} UnkAl48; // size = 0x48

typedef struct UnkAl19E0Sub {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
    /* 0x4 */ u16 unk_4;
} UnkAl19E0Sub;

typedef struct UnkAl19E0Sub2 {
    /* 0x0 */ u8 unk_00;
    /* 0x1 */ u8 unk_01;
    /* 0x2 */ char unk_02[2];
} UnkAl19E0Sub2;

typedef struct UnkAl19E0Sub3 {
    /* 0x00 */ UnkAlA9C* unk_0;
    /* 0x04 */ s8 unk_4;
    /* 0x05 */ s8 unk_5;
} UnkAl19E0Sub3;

typedef struct UnkAl19E0 {
    /* 0x0000 */ f32 unk_00;
    /* 0x0004 */ s32* unk_04;
    /* 0x0008 */ s32* unk_08;
    /* 0x000C */ char unk_0C[0x8];
    /* 0x0014 */ alUnk2* unk_14;
    /* 0x0018 */ char unk_18[0x24];
    /* 0x003C */ UnkAl19E0Sub* unk_3C;
    /* 0x0040 */ UnkAl19E0Sub2 unk_40[4];
    /* 0x0050 */ s8 unk_50;
    /* 0x0051 */ s8 unk_51;
    /* 0x0052 */ s8 unk_52;
    /* 0x0053 */ s8 unk_53;
    /* 0x0054 */ s32* unk_54;
    /* 0x0058 */ s32* unk_58;
    /* 0x005C */ s32* unk_5C;
    /* 0x0060 */ s32* unk_60;
    /* 0x0064 */ s32* unk_64;
    /* 0x0068 */ s32* unk_68;
    /* 0x006C */ UnkAl19E0Sub3 unk_6C[1];
    /* 0x0074 */ char unk_74[0x20];
    /* 0x0094 */ s32* unk_94;
    /* 0x0098 */ char unk_98[0x8];
    /* 0x00A0 */ s32* unk_A0;
    /* 0x00A4 */ s32 unk_A4;
    /* 0x00A8 */ s32 unk_A8;
    /* 0x00AC */ s32* unk_AC;
    /* 0x00B0 */ char unk_B0[0x3C];
    /* 0x00EC */ s32* unk_EC;
    /* 0x00F0 */ char unk_F0[0x3FC];
    /* 0x04EC */ s32* unk_4EC;
    /* 0x04F0 */ char unk_4F0[0xFC];
    /* 0x05EC */ s32* unk_5EC;
    /* 0x05F0 */ char unk_5F0[0x3FC];
    /* 0x09EC */ s32* unk_9EC;
    /* 0x09F0 */ char unk_9F0[0x3FC];
    /* 0x0DEC */ s32* unk_DEC;
    /* 0x0DF0 */ char unk_DF0[0x3FC];
    /* 0x11EC */ s32* unk_11EC;
    /* 0x11F0 */ char unk_11F0[0xFC];
    /* 0x12EC */ s32* unk_12EC;
    /* 0x12F0 */ s32* unk_12F0;
    /* 0x12F4 */ s32* unk_12F4;
    /* 0x12F8 */ s32* unk_12F8;
    /* 0x12FC */ s32* unk_12FC;
    /* 0x1300 */ s32* unk_1300;
    /* 0x1304 */ s32* unk_1304;
    /* 0x1308 */ s32* unk_1308;
    /* 0x130C */ char unk_130C[0x4];
    /* 0x1310 */ s32* unk_1310[3];
    /* 0x131C */ char unk_131C[4];
    /* 0x1320 */ UnkAl48 unk_1320[24];
} UnkAl19E0; // size = 0x19E0

typedef struct UnkAl834 {
    /* 0x00 */ UnkAl19E0* unk_00;
    /* 0x04 */ char unk_04[0x830];
} UnkAl834;

extern UnkAl0* D_80078E54;
extern UnkAl19E0* D_8009A5C0;
extern UnkAlA9C* D_8009A5CC;
extern UnkAlA9C* D_8009A5FC;
extern UnkAl834* D_8009A628;
extern UnkAl6CC* D_8009A640;
extern UnkAlA9C* D_8009A664;

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80052E30);

void func_800532F4(s32);
void func_80053370(s32);
void func_800533A8(alUnk2*);
void al_LoadINIT(UnkAl19E0*, s32, ALHeap*);
s32 al_CopyFileTableEntry(u16 arg0, s32 arg1, s32* arg2);
void al_LoadPER(UnkAl19E0*, s32*);
void al_LoadPRG(UnkAl19E0*, s32*);
void al_DmaCopy(s32*, s32*, s32);
s32* alHeapAlloc(ALHeap*, s32, s32);

//INCLUDE_ASM(s32, "code_2e230_len_2190", func_80052E5C);
void func_80052E5C(s32 arg0) {
    UnkAl19E0** temp_s4 = &D_8009A5C0;
    UnkAl19E0* temp4;
    s32* temp_v0_2;
    ALHeap* alHeap;
    u32 i;
    s32* subroutine_arg6;
    s32* subroutine_arg7;
    s32* subroutine_arg8;
    UnkAlA9C** temp1 = &D_8009A664;
    UnkAlA9C** temp1_1;
    UnkAl6CC** temp2 = &D_8009A640;
    UnkAl6CC** temp2_1;
    UnkAlA9C** temp3;
    UnkAl48* temp5;
    u8 temp6[4];
    u8* temp7;
    s32** temp8;

    alHeap = D_80078E54->unk_18;
    *temp_s4 = alHeapAlloc(alHeap, 1, 0x19E0);

    (*temp1) = alHeapAlloc(alHeap, 1, 0xA9C);
    D_8009A5FC = alHeapAlloc(alHeap, 1, 0xA9C);
    D_8009A5CC = alHeapAlloc(alHeap, 1, 0xA9C);
    (*temp2) = alHeapAlloc(alHeap, 1, 0x6CC);
    D_8009A628 = alHeapAlloc(alHeap, 1, 0x834);
    (*temp1)->unk_04 = (*temp2);
    D_8009A628->unk_00 = *(temp_s4);


    temp4 = *temp_s4;
    temp_v0_2 = alHeapAlloc(alHeap, 1, 0x8000);
    temp4->unk_5C = &temp_v0_2[0];
    temp4->unk_60 = &temp_v0_2[0x1400];
    temp4->unk_64 = &temp_v0_2[0x1C00];
    temp4->unk_68 = &temp_v0_2[0x1400];

    for (i = 0; i < 1; i++) {
        temp4->unk_6C[i].unk_0 = alHeapAlloc(alHeap, 1, 0xA9C);
    }

    temp4->unk_A0 = alHeapAlloc(alHeap, 1, 0x5200);
    temp4->unk_04 = alHeapAlloc(alHeap, 1, 0x30);
    temp4->unk_54 = alHeapAlloc(alHeap, 1, 0x360);
    temp4->unk_58 = alHeapAlloc(alHeap, 1, 0x200);
    temp4->unk_94 = alHeapAlloc(alHeap, 1, 0x40);
    temp4->unk_00 = arg0;
    func_800532F4(temp4->unk_04);
    func_80053370(&temp4->unk_08);
    func_800533A8(&temp4->unk_14);
    func_8005610C();
    temp4->unk_A4 = 0;
    temp4->unk_A8 = 0;

    for (i = 0; i < 1; i++) {
        temp4->unk_6C[i].unk_4 = 0;
        temp4->unk_6C[i].unk_5 = 0;
    }

    for (i = 0; i < 4; i++) {
        temp4->unk_40[i].unk_00 = 0;
        temp4->unk_40[i].unk_01 = 0;
    }

    for (i = 0; i < 24; i++) {
        func_80056EC0((u8)i, 0);
        func_80057224((u8)i, temp4->unk_04);
        temp5 = &temp4->unk_1320[i];
        temp5->unk_00 = 0;
        temp5->unk_04 = 0;
        temp5->unk_0C = -1;
        temp5->unk_0E = 0xFF;
        temp5->unk_0F = 0xFF;
        temp5->unk_10 = 0;
        temp5->unk_42 = 0;
        temp5->unk_43 = 0;
        temp5->unk_44 = 0;
        temp5->unk_45 = 0;
    }

    al_LoadINIT(temp4, 0xF00000, alHeap);

    for (i = 0; i < 3; i++) {
        temp4->unk_1310[i] = alHeapAlloc(alHeap, 1, 0x840);
    }

    temp2_1 = &D_8009A640;
    temp3 = &D_8009A5FC;
    temp1_1 = &D_8009A664;
    func_8004E158((*temp1_1), 1, 0, temp4);
    temp6[0] = 0;
    temp6[1] = 3;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    temp7 = &temp6[0];
    func_8004E344((*temp1_1), temp7);
    func_8004E158((*temp3), 2, 2, temp4);
    temp6[0] = 2;
    temp6[1] = 0xff;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    func_8004E344((*temp3), temp7);
    func_8004B440((*temp2_1), 4, 1, temp4, 0x10);
    func_80050B90(D_8009A628, 6, 1, temp4);
    func_80052614(temp4);
    al_LoadBKHeaders(temp4, alHeap);
    if (al_CopyFileTableEntry(temp4->unk_3C->unk_0, 0x20, &subroutine_arg7) == 0) {
        al_DmaCopy(&subroutine_arg6, temp4->unk_A0, ((s32)&subroutine_arg8 & 0xFFFFFF));
    }
    func_8004B62C((*temp2_1));
    if (al_CopyFileTableEntry(temp4->unk_3C->unk_2, 0x40, &subroutine_arg6) == 0) {
        al_LoadPER(temp4, subroutine_arg6);
    }
    if (al_CopyFileTableEntry(temp4->unk_3C->unk_4, 0x40, &subroutine_arg6) == 0) {
        al_LoadPRG(temp4, subroutine_arg6);
    }

    temp4->unk_12EC = &temp4->unk_4EC;
    temp4->unk_12F0 = &temp4->unk_5EC;
    temp4->unk_12F4 = &temp4->unk_AC;
    temp4->unk_12F8 = &temp4->unk_EC;
    temp4->unk_12FC = &temp4->unk_9EC;
    temp4->unk_1300 = &temp4->unk_DEC;
    temp4->unk_1304 = &temp4->unk_11EC;
    temp4->unk_1308 = &temp4->unk_4EC;
    temp4->unk_53 = 0;
    temp4->unk_52 = 0;
    temp4->unk_51 = 0;
    temp4->unk_50 = 0;

    func_80057ED0(0);
    func_80055050(alHeap);
}

INCLUDE_ASM(void, "code_2e230_len_2190", func_800532F4, s32 arg0);

INCLUDE_ASM(void, "code_2e230_len_2190", func_80053370, s32 arg0);

//INCLUDE_ASM(s32, "code_2e230_len_2190", func_800533A8);
void func_800533A8(alUnk2* arg0) {
    arg0->unk_00 = 8208;
    arg0->unk_02 = ~128;
    arg0->unk_03 = 64;
    arg0->unk_04 = 0;
    arg0->unk_05 = 0;
    arg0->unk_06 = 0;
}

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800533D0);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800535C0);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053654);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053888);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800538C4);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800538F8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053974);

void func_80053A18(UnkStructFor80053A18* arg0) {
    arg0->unk_0A = 0;
    arg0->unk_04 = 0;
    arg0->unk_0C = 0;
}

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053A28);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053A98);

void func_80053AC8(alUnk1* arg0) {
    if (arg0->unk_0A == 0) {
        arg0->unk_0A = 1;
        arg0->unk_04 = 0;
        arg0->unk_08 = arg0->unk_00;
    }
}

void func_80053AEC(alUnk1* arg0, s16 arg1) {
    arg0->unk_10 = arg1 << 16;
    arg0->unk_18 = arg1;
    arg0->unk_1A = 0;
    arg0->unk_14 = 0;
}

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053B04);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053BA8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053BE8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053C58);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053CB4);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053CF8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053E58);

UnkAlA9C* func_80053F64(s32 arg0) {
    if (arg0 == 0) {
        return D_8009A5C0->unk_6C[0].unk_0; // 0x6C
    }
    return 0;
}

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80053F80);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054248);

INCLUDE_ASM(void, "code_2e230_len_2190", al_LoadINIT, UnkAl19E0* arg0, s32 arg1, ALHeap* arg2);

INCLUDE_ASM(s32, "code_2e230_len_2190", al_CopyFileTableEntry, u16 arg0, s32 arg1, s32* arg2);

INCLUDE_ASM(void, "code_2e230_len_2190", al_LoadPER, UnkAl19E0* arg0, s32* arg1);

INCLUDE_ASM(void, "code_2e230_len_2190", al_LoadPRG, UnkAl19E0* arg0, s32* arg1);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_8005465C);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054744);

INCLUDE_ASM(s32, "code_2e230_len_2190", al_LoadBank);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_800549F8);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054AA0);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054C4C);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054C84);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054CE0);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054D74);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054DA8);

INCLUDE_ASM(void, "code_2e230_len_2190", al_DmaCopy, s32* arg0, s32* arg1, s32 arg2);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054E90);

INCLUDE_ASM(s32, "code_2e230_len_2190", func_80054F48);

INCLUDE_ASM(s32, "code_2e230_len_2190", al_CopyWords);
