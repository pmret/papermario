#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "common.h"

typedef struct UnkAl1 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} UnkAl1; // size unknown (currently 0x1C)

typedef struct UnkAl2 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
} UnkAl2;

typedef struct UnkLen18 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s8 unk_0C;
    /* 0x0D */ char unk_0D[0xB];
} UnkLen18;

typedef struct UnkAl7C {
    /* 0x00 */ char unk_00[0x3C];
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk_40[0xD];
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ char unk_4E[0x6];
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ char unk_58[0x18];
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ char unk_74[0x4];
    /* 0x78 */ u8 unk_78;
    /* 0x79 */ char unk_79[0x3];
} UnkAl7C;

typedef struct UnkAl0 {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ ALHeap* unk_18;
    /* 0x1C */ UnkAl7C* unk_1C;
    /* 0x20 */ UnkLen18 unk_20[1]; // amt unknown
} UnkAl0;

typedef struct UnkAl6CC {
    /* 0x000 */ char unk_00[0x34];
    /* 0x034 */ s32 unk_34;
    /* 0x038 */ s32 unk_38;
    /* 0x03C */ s32 unk_3C;
    /* 0x040 */ u16 unk_40;
    /* 0x042 */ char unk_42[0x8];
    /* 0x04A */ s16 unk_4A;
    /* 0x04C */ char unk_4C[0x10];
    /* 0x05C */ s32 unk_5C;
    /* 0x060 */ char unk_60[0x5A];
    /* 0x0BA */ s16 unk_BA;
    /* 0x0BC */ char unk_BC[0x2];
    /* 0x0BE */ u8 unk_BE;
    /* 0x0BF */ char unk_BF[0x1];
    /* 0x0C0 */ s8 unk_C0;
    /* 0x0C1 */ char unk_C1[0xA2];
    /* 0x163 */ s8 unk_163;
    /* 0x164 */ s32 unk_164;
    /* 0x168 */ s32 unk_168;
    /* 0x16C */ char unk_16C[0x560];
} UnkAl6CC;

typedef struct UnkAlA9C {
    /* 0x000 */ char unk_00[0x4];
    /* 0x004 */ UnkAl6CC* unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ char unk_14[0x4];
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s32 unk_1C;
    /* 0x020 */ char unk_20[0xC];
    /* 0x02C */ UnkAl1 unk_2C;
    /* 0x048 */ char unk_48[0x14];
    /* 0x05C */ s16 unk_5C;
    /* 0x05E */ char unk_5E[0x1C3];
    /* 0x221 */ u8 unk_221;
    /* 0x222 */ char unk_222[0x87A];
} UnkAlA9C;

typedef struct UnkAl48 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ char unk_11[0x3];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ char unk_20[0x22];
    /* 0x42 */ u8 unk_42;
    /* 0x43 */ u8 unk_43;
    /* 0x44 */ s8 unk_44;
    /* 0x45 */ u8 unk_45;
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

typedef struct UnkAl30 {
    /* 0x00 */ s32* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32* unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s8 unk_24;
    /* 0x25 */ s8 unk_25;
    /* 0x26 */ s8 unk_26;
    /* 0x27 */ s8 unk_27;
    /* 0x28 */ s8 unk_28;
    /* 0x29 */ s8 unk_29;
    /* 0x2A */ s8 unk_2A;
    /* 0x2B */ s8 unk_2B;
    /* 0x2C */ s32* unk_2C;
} UnkAl30;

typedef struct UnkAl12 {
    /* 0x0 */ s16 unk_00;
    /* 0x2 */ s16 unk_02;
    /* 0x4 */ s8 unk_04;
    /* 0x5 */ s8 unk_05;
    /* 0x6 */ s8 unk_06;
    /* 0x7 */ s8 unk_07;
    /* 0x8 */ s8 unk_08;
    /* 0x9 */ s8 unk_09;
    /* 0xA */ s8 unk_0A;
} UnkAl12;

typedef struct UnkTemp2 {
    /* 0x00 */ s32 unk_00;
    /* 0x08 */ s32 unk_04;
} UnkTemp2;

typedef void (*UnkFuncAl)();

typedef struct UnkAl19E0 {
    /* 0x0000 */ f32 unk_00;
    /* 0x0004 */ UnkAl30* unk_04;
    /* 0x0008 */ UnkAl12* unk_08;
    /* 0x000C */ char unk_0C[0x8];
    /* 0x0014 */ UnkAl2* unk_14;
    /* 0x0018 */ char unk_18[0x4];
    /* 0x001C */ s32 unk_1C;
    /* 0x0020 */ UnkTemp2* unk_20;
    /* 0x0024 */ s32 unk_24;
    /* 0x0028 */ char unk_28[0xC];
    /* 0x0034 */ s32 unk_34;
    /* 0x0038 */ s32 unk_38;
    /* 0x003C */ UnkAl19E0Sub* unk_3C;
    /* 0x0040 */ UnkAl19E0Sub2 unk_40[4];
    /* 0x0050 */ u8 unk_50;
    /* 0x0051 */ u8 unk_51;
    /* 0x0052 */ u8 unk_52;
    /* 0x0053 */ u8 unk_53;
    /* 0x0054 */ s32* unk_54;
    /* 0x0058 */ s32* unk_58;
    /* 0x005C */ s32* unk_5C;
    /* 0x0060 */ s32* unk_60;
    /* 0x0064 */ s32* unk_64;
    /* 0x0068 */ s32* unk_68;
    /* 0x006C */ UnkAl19E0Sub3 unk_6C[1];
    /* 0x0074 */ char unk_74[0xC];
    /* 0x0080 */ s32 unk_80;
    /* 0x0084 */ char unk_84[0x10];
    /* 0x0094 */ s32* unk_94;
    /* 0x0098 */ char unk_98[0x4];
    /* 0x009C */ s32 unk_9C;
    /* 0x00A0 */ s32* unk_A0;
    /* 0x00A4 */ UnkFuncAl unk_A4;
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
    /* 0x130C */ u8 unk_130C;
    /* 0x130D */ char unk_130D[3];
    /* 0x1310 */ s32* unk_1310[3];
    /* 0x131C */ char unk_131C[4];
    /* 0x1320 */ UnkAl48 unk_1320[24];
} UnkAl19E0; // size = 0x19E0

typedef struct UnkAl834 {
    /* 0x000 */ UnkAl19E0* unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ char unk_10[0x10];
    /* 0x020 */ u8 unk_20;
    /* 0x021 */ char unk_21[0x813];
} UnkAl834;

extern UnkAl0* D_80078E54;
extern s8* D_80078181;
extern s32* D_80078190;
extern s32* D_800781D0;
extern s32* D_80078544;
extern s32* D_80078DB0;
extern u16 D_80078DB6;

extern s8 D_80078E58;
extern s16 D_80078E5A;
extern s8 D_80078E5C;

extern UnkAl19E0* D_8009A5C0;
extern UnkAlA9C* D_8009A5CC;
extern UnkAlA9C* D_8009A5FC;
extern UnkFuncAl D_8009A5E8;
extern UnkAl834* D_8009A628;
extern UnkAl6CC* D_8009A640;
extern UnkAlA9C* D_8009A664;

extern s32 D_800A3FE8;
extern s8 D_800A3FEC;
extern s16 D_800A3FEE;
extern s32 D_800A3FF0;

void al_LoadBKHeaders(UnkAl19E0* arg0, ALHeap* arg1);

void func_8004B6D8(UnkAl6CC*, s32, s16, s16, u8);
void func_8004B748(UnkAl6CC*);
void func_8004BA54(UnkAl6CC*, s32);
void func_8004D510(UnkAlA9C*);
void func_8004DAA8(UnkAlA9C*);
s32 func_80050C30(u32);
void func_800532F4(UnkAl30*);
void func_80053370(UnkAl12*);
void func_800533A8(UnkAl2*);
void func_80053654(UnkAl19E0*);
void func_80053A18(UnkAl1*);
void func_80053A28(s32);
void func_80053A98(u8, u16, s32);
void func_80053BA8(UnkAl1*);
void func_80054CE0(s32, s32);
void func_8005610C(void);
s16 func_80056D50(void);
void func_80056D78(u8, u16);
void func_80056DCC(u8, u8);
void func_80056EE8(u8);
void func_800576EC(u8, s32, s32);
void func_80057DC8(s32);
void func_80057E08(u8);
void func_80057548(u8, u8, u8);
void func_80057E5C(u8);
void func_80057EB0(void);

void al_LoadINIT(UnkAl19E0*, s32, ALHeap*);
s32 al_CopyFileTableEntry(u16, s32, s32*);
void al_LoadPER(UnkAl19E0*, s32*);
void al_LoadPRG(UnkAl19E0*, s32*);
void al_DmaCopy(s32, s32*, s32);

#undef alHeapAlloc
void* alHeapAlloc(ALHeap *heap, s32 arg1, s32 size);

#endif
