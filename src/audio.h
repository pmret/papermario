#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "common.h"

struct UnkAlA9C;
struct UnkAl19E0;

typedef void (*UnkFuncAl)();

typedef union UnkField {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s32 s32;
} UnkField;

typedef union X16 {
    u8 u8[2];
    u16 u16;
} X16;

typedef struct UnkAl1 {
    /* 0x00 */ UnkField unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ UnkFuncAl unk_0C;
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

typedef struct UnkAl3 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ char unk_08[0x30];
    /* 0x38 */ u16 unk_38;
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ char unk_3C[0x2];
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ s8 unk_40;
    /* 0x41 */ s8 unk_41;
    /* 0x42 */ s8 unk_42;
    /* 0x43 */ s8 unk_43;
    /* 0x44 */ char unk_44[0x2];
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s8 unk_48;
    /* 0x49 */ s8 unk_49;
    /* 0x4A */ s8 unk_4A;
    /* 0x4B */ s8 unk_4B;
    /* 0x4C */ char unk_4C[0x9];
    /* 0x55 */ s8 unk_55;
    /* 0x56 */ s8 unk_56;
    /* 0x57 */ s8 unk_57;
    /* 0x58 */ char unk_58[0x3];
    /* 0x5B */ s8 unk_5B;
} UnkAl3;

typedef struct UnkLen18 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s8 unk_0C;
    /* 0x0D */ char unk_0D[0xB];
} UnkLen18;

typedef struct UnkAl7C {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ char unk_1C[0xC];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ char unk_38[0x4];
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ char unk_48[0x5];
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ char unk_50[0x4];
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ char unk_58[0x14];
    /* 0x6C */ s32 unk_6C;
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

typedef struct UnkAlA {
    /* 0x0 */ s16 unk_00;
    /* 0x2 */ s16 unk_02;
    /* 0x4 */ s16 unk_04;
    /* 0x6 */ s16 unk_06;
    /* 0x8 */ s8 unk_08;
} UnkAlA; // size = 0xA

typedef struct UnkAlAC {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x58];
    /* 0x5C */ u16 unk_5C;
    /* 0x5E */ char unk_5E[0x1A];
    /* 0x78 */ u8 unk_78;
    /* 0x79 */ u8 unk_79;
    /* 0x7A */ u8 unk_7A;
    /* 0x7B */ u8 unk_7B;
    /* 0x7C */ u8 unk_7C;
    /* 0x7D */ u8 unk_7D;
    /* 0x7E */ u8 unk_7E;
    /* 0x7F */ u8 unk_7F;
    /* 0x80 */ char unk_80[0xE];
    /* 0x8E */ u16 unk_8E;
    /* 0x90 */ u16 unk_90;
    /* 0x92 */ u16 unk_92;
    /* 0x94 */ u8 unk_94;
    /* 0x95 */ char unk_05[0x4];
    /* 0x99 */ u8 unk_99;
    /* 0x9A */ char unk_9A[0x1];
    /* 0x9B */ u8 unk_9B;
    /* 0x9C */ u8 unk_9C;
    /* 0x9D */ u8 unk_9D;
    /* 0x9E */ u8 unk_9E;
    /* 0x9F */ u8 unk_9F;
    /* 0xA0 */ char unk_A0[0xC];
} UnkAlAC; // size = 0xAC

typedef struct UnkAl6CC {
    /* 0x000 */ struct UnkAl19E0* unk_00;
    /* 0x004 */ char unk_04[0x2C];
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ s32 unk_34;
    /* 0x038 */ s32 unk_38;
    /* 0x03C */ s32 unk_3C;
    /* 0x040 */ UnkAl1 unk_40;
    /* 0x05C */ s32 unk_5C;
    /* 0x060 */ s32 unk_60;
    /* 0x064 */ s32* unk_64[8];
    /* 0x084 */ s8 unk_84[8];
    /* 0x08C */ u8 unk_8C;
    /* 0x08D */ s8 unk_8D;
    /* 0x08E */ char unk_8E[0x2];
    /* 0x090 */ s32 unk_90[4];
    /* 0x0A0 */ Vec3s unk_A0[4];
    /* 0x0B8 */ u16 unk_B8;
    /* 0x0BA */ s16 unk_BA;
    /* 0x0BC */ u8 unk_BC;
    /* 0x0BD */ u8 unk_BD;
    /* 0x0BE */ u8 unk_BE;
    /* 0x0BF */ char unk_BF[0x1];
    /* 0x0C0 */ s8 unk_C0;
    /* 0x0C1 */ char unk_C1[0x1];
    /* 0x0C2 */ UnkAlA unk_C2[16];
    /* 0x162 */ s8 unk_162;
    /* 0x163 */ s8 unk_163;
    /* 0x164 */ s8 unk_164;
    /* 0x165 */ s8 unk_165;
    /* 0x166 */ char unk_166[0x2];
    /* 0x168 */ s32 unk_168;
    /* 0x16C */ UnkAlAC unk_16C[8];
} UnkAl6CC;

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

typedef struct UnkAl48 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ char unk_11[0x3];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32* unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ char unk_38[0x1];
    /* 0x39 */ u8 unk_39;
    /* 0x3A */ u8 unk_3A;
    /* 0x3B */ u8 unk_3B;
    /* 0x3C */ u8 unk_3C;
    /* 0x3D */ u8 unk_3D;
    /* 0x3E */ u8 unk_3E;
    /* 0x3F */ u8 unk_3F;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ u8 unk_42;
    /* 0x43 */ u8 unk_43;
    /* 0x44 */ s8 unk_44;
    /* 0x45 */ u8 unk_45;
    /* 0x46 */ char unk_46[2];
} UnkAl48; // size = 0x48

typedef struct UnkTemp2 {
    /* 0x00 */ s32 unk_00;
    /* 0x08 */ s32 unk_04;
} UnkTemp2;

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
    /* 0x00 */ struct UnkAlA9C* unk_0;
    /* 0x04 */ s8 unk_4;
    /* 0x05 */ s8 unk_5;
} UnkAl19E0Sub3;

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
    /* 0x0098 */ s32* unk_98;
    /* 0x009C */ s32 unk_9C;
    /* 0x00A0 */ s32* unk_A0;
    /* 0x00A4 */ UnkFuncAl unk_A4[2];
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

typedef struct UnkAlA9C {
    /* 0x000 */ UnkAl19E0* unk_00;
    /* 0x004 */ UnkAl6CC* unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ s32 unk_14;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s32 unk_1C;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ char unk_24[0x8];
    /* 0x02C */ UnkAl1 unk_2C;
    /* 0x048 */ s32 unk_48;
    /* 0x04C */ u8 unk_4C[0x1]; // not sure how long this is
    /* 0x04D */ char unk_4D[0xB];
    /* 0x058 */ s16 unk_58;
    /* 0x05A */ s16 unk_5A;
    /* 0x05C */ s16 unk_5C;
    /* 0x05E */ char unk_5E[0x6];
    /* 0x064 */ s32 unk_64;
    /* 0x068 */ s16 unk_68;
    /* 0x06A */ char unk_6A[0x2];
    /* 0x06C */ s32 unk_6C;
    /* 0x070 */ s32 unk_70;
    /* 0x074 */ char unk_74[0x3C];
    /* 0x0B0 */ s32 unk_B0;
    /* 0x0B4 */ s32 unk_B4;
    /* 0x0B8 */ s32 unk_B8;
    /* 0x0BC */ s32 unk_BC;
    /* 0x0C0 */ s32 unk_C0;
    /* 0x0C4 */ s32 unk_C4;
    /* 0x0C8 */ s32 unk_C8;
    /* 0x0CC */ s32 unk_CC;
    /* 0x0D0 */ f32 unk_D0;
    /* 0x0D4 */ X16 unk_D4;
    /* 0x0D6 */ u8 unk_D6;
    /* 0x0D7 */ char unk_D7;
    /* 0x0D8 */ char unk_D8[0x90];
    /* 0x168 */ s32 unk_168;
    /* 0x16C */ char unk_16C[0x98];
    /* 0x204 */ s32 unk_204;
    /* 0x208 */ s16 unk_208;
    /* 0x20A */ s16 unk_20A;
    /* 0x20C */ s16 unk_20C;
    /* 0x20E */ s16 unk_20E;
    /* 0x210 */ char unk_210[0xA];
    /* 0x21A */ u8 unk_21A;
    /* 0x21B */ char unk_21B[0x5];
    /* 0x220 */ u8 unk_220;
    /* 0x221 */ u8 unk_221;
    /* 0x222 */ u8 unk_222;
    /* 0x223 */ u8 unk_223;
    /* 0x224 */ u8 unk_224[3];
    /* 0x227 */ char unk_227[0x3];
    /* 0x22A */ u8 unk_22A;
    /* 0x22B */ u8 unk_22B;
    /* 0x22C */ u8 unk_22C;
    /* 0x22D */ u8 unk_22D;
    /* 0x22E */ u8 unk_22E;
    /* 0x22F */ u8 unk_22F;
    /* 0x230 */ u8 unk_230;
    /* 0x231 */ u8 unk_231;
    /* 0x232 */ u8 unk_232;
    /* 0x233 */ char unk_233[0x1];
    /* 0x234 */ u8 unk_234;
    /* 0x235 */ u8 unk_235;
    /* 0x236 */ char unk_236[0x2];
    /* 0x238 */ s32 unk_238[8];
    /* 0x258 */ s8 unk_258;
    /* 0x259 */ s8 unk_259;
    /* 0x25A */ s8 unk_25A;
    /* 0x25B */ s8 unk_25B;
    /* 0x25C */ char unk_25C[0x840];
} UnkAlA9C; // size = 0xA9C

typedef struct UnkAl834 {
    /* 0x000 */ UnkAl19E0* unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ char unk_10[0x10];
    /* 0x020 */ u8 unk_20;
    /* 0x021 */ char unk_21[0x813];
} UnkAl834;

extern s32 D_80078E50;
extern UnkAl0* D_80078E54;
extern s8* D_80078181;
extern s32* D_80078190;
extern s32* D_800781D0;
extern s32* D_80078290;
extern s32* D_800782F8;
extern s32* D_80078348;
extern s32* D_80078320;
extern s32* D_80078544;
extern s32* D_800785A0;
extern s32 D_80078DB0;
extern u16 D_80078DB6;

extern s8 D_80078E58;
extern s16 D_80078E5A;
extern s8 D_80078E5C;
extern s32 D_8007F1F8;

extern UnkAl19E0* D_8009A5C0;
extern UnkAlA9C* D_8009A5CC;
extern UnkAlA9C* D_8009A5FC;
extern UnkFuncAl D_8009A5E8;
extern UnkAl834* D_8009A628;
extern UnkAl6CC* D_8009A640;
extern UnkAlA9C* D_8009A664;

extern s32* D_800A3FE0;
extern s32* D_800A3FE4;
extern s32 D_800A3FE8;
extern s8 D_800A3FEC;
extern s16 D_800A3FEE;
extern s32 D_800A3FF0;

void al_LoadBKHeaders(UnkAl19E0* arg0, ALHeap* arg1);

void func_8004B440(UnkAl6CC*, u8, u8, UnkAl19E0*, u8);
void func_8004B62C(UnkAl6CC*);
void func_8004B698(UnkAl6CC*);
void func_8004B6D8(UnkAl6CC*, s32, s16, s16, u8);
void func_8004B748(UnkAl6CC*);
s32 func_8004B9E4(UnkAl6CC*, s32);
void func_8004BA54(UnkAl6CC*, s32);
s16 func_8004C444(UnkAl6CC*);

void func_8004D510(UnkAlA9C*);
UnkAlA9C* func_8004D794(s32);
s32 func_8004DA0C(UNK_TYPE);
void func_8004DAA8(UnkAlA9C*);
void func_8004DFD4(UnkAl19E0*);
void func_8004E158(UnkAlA9C*, s32, s32, UnkAl19E0*);
void func_8004E3A4(UnkAlA9C*);
void func_8004E444(UnkAlA9C*);
s16 func_8004E4B8(UnkAlA9C*);
void func_8004FBBC(UnkAlA9C*, UnkAl3*);
s32 func_8004FC08(UnkAlA9C*, u32);
void func_8004FCB4(UnkAlA9C*, UnkAl3*);
void func_8004FCE4(UnkAlA9C*, UnkAl3*);
void func_8004FD04(UnkAlA9C*, UnkAl3*);
void func_8004FD38(UnkAlA9C*, UnkAl3*);
void func_8004FD94(UnkAlA9C*, UnkAl3*);
void func_8004FE10(UnkAlA9C*, UnkAl3*);
void func_8004FE6C(UnkAlA9C*, UnkAl3*);
void func_8004FEB0(UnkAlA9C*, UnkAl3*);
void func_8004FED0(UnkAlA9C*, UnkAl3*);
void func_8004FF3C(UnkAlA9C*, UnkAl3*);
void func_8004FF58(UnkAlA9C*, UnkAl3*);
void func_8004FF70(UnkAlA9C*, UnkAl3*);
void func_8004FF88(UnkAlA9C*, UnkAl3*);
void func_8004FFA8(UnkAlA9C*, UnkAl3*);
void func_8004FFB4(UnkAlA9C*, UnkAl3*);
void func_8004FFC8(UnkAlA9C*, UnkAl3*);
void func_8004FFE4(UnkAlA9C*, UnkAl3*);
void func_8004FFF0(UnkAlA9C*, UnkAl3*);
void func_8004FFFC(UnkAlA9C*, UnkAl3*);
void func_80050004(UnkAlA9C*, UnkAl3*);
void func_80050020(UnkAlA9C*, UnkAl3*);
void func_80050128(UnkAlA9C*, UnkAl3*);
void func_8005015C(UnkAlA9C*, UnkAl3*);
void func_80050184(UnkAlA9C*, UnkAl3*);
void func_800501A8(UnkAlA9C*, UnkAl3*);
void func_800502F0(UnkAlA9C*, UnkAl3*);
void func_80050560(UnkAlA9C*, UnkAl3*);
s32 func_80056068(s32, u8);
s32 func_800506C8(s32, s32);
s32 func_80050C30(u32);
void func_800511BC(UnkAl834*);

void func_800525A0(UnkAl19E0*);
void func_80052614(UnkAl19E0*);
void func_80052660(UnkAl19E0*);
void func_80052B44(UnkAl48*);
void func_80052BF8(UnkAl48*, s32*);

void func_800532F4(UnkAl30*);
void func_80053370(UnkAl12*);
void func_800533A8(UnkAl2*);
void func_80053654(UnkAl19E0*);
void func_80053974(UnkAl1*, s32, s32, s16);
void func_80053A18(UnkAl1*);
void func_80053A28(UnkAl1*);
void func_80053A98(u8, u16, s32);
void func_80053AEC(UnkAl1*, s16);
void func_80053BA8(UnkAl1*);
void func_80054CE0(s32, s32);
void func_8005610C(void);

void func_80055110(UnkAlA9C*);
s32 func_80055FF0(s32, s32);
s32 func_8005600C(s32, s32);
s32 func_80056028(s32, u8);
s32 func_80056044(s32, u8);
s32 func_80056068(s32, u8);
void func_8005608C(s32*, s32*);
void func_800560A8(void);
void func_8005610C(void);
void func_80056144(UnkFuncAl, s32);
void func_8005615C(void);
void func_80056180(void);
void func_800561A4(s32);
void func_800561C4(s32);
void func_800561E4(s32);
void func_80056204(void);
void func_80056228(void);

s16 func_80056D50(void);
void func_80056D78(u8, u16);
void func_80056DCC(u8, u8);
void func_80056EC0(u8, s8);
void func_80056EE8(u8);
void func_80056FA4(u8, u8, s32, f32, s16, u8, u8, s32);
void func_80057224(u8, UnkAl30*);
void func_80057344(u8, f32);
void func_8005736C(u8, s16, s32, u8, u8);
void func_80057548(u8, u8, u8);
void func_800576EC(u8, s32, s32);
void func_80057DC8(s32);
void func_80057E08(u8);
void func_80057E5C(u8);
void func_80057EB0(void);
void func_80057ED0(s16);

void al_LoadINIT(UnkAl19E0*, s32, ALHeap*);
s32 al_CopyFileTableEntry(u16, s32, s32*);
void al_LoadPER(UnkAl19E0*, s32*);
void al_LoadPRG(UnkAl19E0*, s32*);
void al_DmaCopy(s32, s32*, s32);

#undef alHeapAlloc
void* alHeapAlloc(ALHeap *heap, s32 arg1, s32 size);

#endif
