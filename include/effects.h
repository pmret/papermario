#ifndef _EFFECTS_H_
#define _EFFECTS_H_

#include "types.h"
#include "common_structs.h"

enum EffectID {
    EFFECT_ID_00 = 0x00,
    EFFECT_ID_01,
    EFFECT_ID_06 = 0x06,
    EFFECT_ID_07,
    EFFECT_ID_08,
    EFFECT_ID_09,
    EFFECT_ID_0A,
    EFFECT_ID_0B,
    EFFECT_ID_0C,
    EFFECT_ID_0D,
    EFFECT_ID_0E,
    EFFECT_ID_0F,
    EFFECT_ID_10,
    EFFECT_ID_11,
    EFFECT_ID_12,
    EFFECT_ID_13,
    EFFECT_ID_14,
    EFFECT_ID_15,
    EFFECT_ID_16,
    EFFECT_ID_17,
    EFFECT_ID_18,
    EFFECT_ID_19,
    EFFECT_ID_1A,
    EFFECT_ID_1B,
    EFFECT_ID_1C,
    EFFECT_ID_1D,
    EFFECT_ID_1E,
    EFFECT_ID_1F,
    EFFECT_ID_20,
    EFFECT_ID_21,
    EFFECT_ID_22,
    EFFECT_ID_23,
    EFFECT_ID_24,
    EFFECT_ID_25,
    EFFECT_ID_26,
    EFFECT_ID_27,
    EFFECT_ID_28,
    EFFECT_ID_29,
    EFFECT_ID_2B = 0x2B,
    EFFECT_ID_2C,
    EFFECT_ID_2D,
    EFFECT_ID_2E,
    EFFECT_ID_2F,
    EFFECT_ID_30,
    EFFECT_ID_31,
    EFFECT_ID_32,
    EFFECT_ID_33,
    EFFECT_ID_34,
    EFFECT_ID_35,
    EFFECT_ID_36,
    EFFECT_ID_37,
    EFFECT_ID_38,
    EFFECT_ID_39,
    EFFECT_ID_3A,
    EFFECT_ID_3B,
    EFFECT_ID_3C,
    EFFECT_ID_3D,
    EFFECT_ID_3E,
    EFFECT_ID_3F,
    EFFECT_ID_40,
    EFFECT_ID_41,
    EFFECT_ID_42,
    EFFECT_ID_43,
    EFFECT_ID_44,
    EFFECT_ID_45,
    EFFECT_ID_46,
    EFFECT_ID_47,
    EFFECT_ID_48,
    EFFECT_ID_49,
    EFFECT_ID_4A,
    EFFECT_ID_4B,
    EFFECT_ID_4C,
    EFFECT_ID_4D,
    EFFECT_ID_4E,
    EFFECT_ID_4F,
    EFFECT_ID_51 = 0x51,
    EFFECT_ID_52,
    EFFECT_ID_53,
    EFFECT_ID_55 = 0x55,
    EFFECT_ID_56,
    EFFECT_ID_57,
    EFFECT_ID_58,
    EFFECT_ID_59,
    EFFECT_ID_5A,
    EFFECT_ID_5B,
    EFFECT_ID_5C,
    EFFECT_ID_5D,
    EFFECT_ID_5E,
    EFFECT_ID_5F,
    EFFECT_ID_60,
    EFFECT_ID_61,
    EFFECT_ID_62,
    EFFECT_ID_63,
    EFFECT_ID_64,
    EFFECT_ID_65,
    EFFECT_ID_66,
    EFFECT_ID_67,
    EFFECT_ID_68,
    EFFECT_ID_69,
    EFFECT_ID_6B = 0x6B,
    EFFECT_ID_6C,
    EFFECT_ID_6D,
    EFFECT_ID_6E,
    EFFECT_ID_6F,
    EFFECT_ID_70,
    EFFECT_ID_71,
    EFFECT_ID_72,
    EFFECT_ID_73,
    EFFECT_ID_74,
    EFFECT_ID_75,
    EFFECT_ID_77 = 0x77,
    EFFECT_ID_78,
    EFFECT_ID_79,
    EFFECT_ID_7A,
    EFFECT_ID_7B,
    EFFECT_ID_7C,
    EFFECT_ID_7D,
    EFFECT_ID_7E,
    EFFECT_ID_7F,
    EFFECT_ID_80,
    EFFECT_ID_81,
    EFFECT_ID_82,
    EFFECT_ID_83,
    EFFECT_ID_84,
    EFFECT_ID_85,
    EFFECT_ID_86,
};

typedef struct {
    char unk_00[0x38];
    f32 unk_38[4];
} EffectUnkStruct1;

typedef struct EffectStruct {
    char unk_00[0x4];
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    char unk_14[0x4];
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    X32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 unk_34;
    s32 unk_38;
    char unk_3C[0xC];
    EffectUnkStruct1* unk_48;
    char unk_4C[0x24];
    s32 unk_70;
    s32 unk_74;
} EffectStruct;

typedef struct StarSpiritEffectUnkStruct {
    char unk_00[0xC];
    EffectStruct* unk_0C;
} StarSpiritEffectUnkStruct;

typedef struct StarSpiritEffect {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40; // a shadowID
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ struct StarSpiritEffectUnkStruct* unk_50;
    /* 0x54 */ struct StarSpiritEffectUnkStruct* unk_54;
} StarSpiritEffect; // size = 0x58

typedef struct BigSmokePuffFXData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 y;
    /* 0x14 */ f32 z;
    /* 0x18 */ f32 partX;
    /* 0x1C */ f32 partY;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0x4];
} BigSmokePuffFXData; // size = 0x2C

typedef struct LandingDustFXData {
    /* 0x00 */ u16 type;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
} LandingDustFXData; // size = 0x44

typedef struct WalkingDustFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[0x44];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ s32 unk_74;
} WalkingDustFXData; // size = 0x78

// Used by both flower_splash and flower_trail
typedef struct FlowerFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 primAlpha;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ char unk_0A[0x2];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ Mtx unk_30;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ f32 unk_78;
    /* 0x7C */ f32 unk_7C;
    /* 0x80 */ f32 unk_80;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ f32 unk_8C;
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
} FlowerFXData; // size = 0x98

typedef struct CloudPuffFXData {
    /* 0x00 */ s32 alive;
    /* 0x04 */ char unk_04[0x2];
    /* 0x06 */ s16 lifetime;
    /* 0x08 */ u8 alpha;
    /* 0x09 */ char unk_09[0x3];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
} CloudPuffFXData; // size = 0x4C

typedef struct CloudTrailFXData {
    /* 0x00 */ s32 alive;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 lifetime;
    /* 0x08 */ u8 alpha;
    /* 0x09 */ char unk_09[0x3];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ char unk_34[0x4];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ char unk_48[0x8];
} CloudTrailFXData; // size = 0x50

typedef struct Effect12 {
    /* 0x00 */ s32 alive;
    /* 0x04 */ char unk_04[0x2];
    /* 0x06 */ s16 lifetime;
    /* 0x08 */ u8 alpha;
    /* 0x09 */ char unk_09[0x3];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ Mtx mtx;
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ char unk_74[0x8];
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ char unk_88[0x8];
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
} Effect12; // size = 0x98

typedef struct Effect13 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
} Effect13; // size = 0x48

typedef struct Effect14 {
    /* 0x00 */ f32 xPos;
    /* 0x04 */ f32 yPos;
    /* 0x08 */ f32 zPos;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
} Effect14; // size = 0x2C

typedef struct Effect15 {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ f32 unk_08;
    /* 0x00C */ f32 unk_0C;
    /* 0x010 */ f32 unk_10;
    /* 0x014 */ f32 unk_14;
    /* 0x018 */ f32 unk_18;
    /* 0x01C */ f32 unk_1C;
    /* 0x020 */ f32 unk_20;
    /* 0x024 */ f32 unk_24;
    /* 0x028 */ s32 unk_28;
    /* 0x02C */ f32 unk_2C;
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ f32 unk_34;
    /* 0x038 */ s32 unk_38;
    /* 0x03C */ s32 unk_3C;
    /* 0x040 */ Mtx unk_40[8];
    /* 0x240 */ f32 unk_240;
    /* 0x244 */ s32 unk_244;
    /* 0x248 */ s32 unk_248;
    /* 0x24C */ s32 unk_24C;
} Effect15; // size = 0x250

typedef struct Effect16 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
} Effect16; // size = 0x40

typedef struct Effect73 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 unk_20;
} Effect73; // size = 0x24

typedef struct Effect75 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} Effect75; // size = 0x24

typedef struct Effect134 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
} Effect134; // size = 0x38

// TODO figure out what this actually is
// playFX_4E invokes gEffectTable[78]'s entryPoint function
// playFX_6F invokes gEffectTable[111]'s entryPoint function
// playFX_83 invokes gEffectTable[131]'s entryPoint function
// These functions are currently typed to return void
// Assume they return an Effect*, and this struct is accessed at unk_0C,
// but this struct differs from EffectInstanceData
// Search for "struct N(temp)" for examples
typedef struct EffectInstanceDataThing {
    char unk_00[0x4];
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    char unk_14[0x4];
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    X32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    char unk_3C[0xC];
    EffectUnkStruct1* unk_48;
    char unk_4C[0x24];
    s32 unk_70;
    s32 unk_74;
} EffectInstanceDataThing;

typedef struct EffectInstanceData {
    /* 0x00 */ EffectInstanceDataThing* unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f rotation;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ char unk_40[0x24];
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ char unk_68[0x18];
} EffectInstanceData; // size = 0x80

typedef struct EffectInstance {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 effectIndex;
    /* 0x08 */ s32 numParts;
    /* 0x0C */ void* data; // often but not always EffectInstanceData
    /* 0x10 */ struct EffectGraphics* graphics;
} EffectInstance; // size = 0x14

typedef struct EffectBlueprint {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 effectID;
    /* 0x08 */ void (*init)(EffectInstance* effectInst);
    /* 0x0C */ void (*update)(EffectInstance* effectInst);
    /* 0x10 */ void (*renderWorld)(EffectInstance* effectInst);
    /* 0x14 */ void (*unk_14)(EffectInstance* effectInst);
} EffectBlueprint; // size = 0x18

typedef struct EffectGraphics {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 effectIndex;
    /* 0x08 */ s32 instanceCounter;
    /* 0x0C */ s32 freeDelay;
    /* 0x10 */ void (*update)(EffectInstance* effectInst);
    /* 0x14 */ void (*renderWorld)(EffectInstance* effectInst);
    /* 0x18 */ void (*renderUI)(EffectInstance* effectInst);
    /* 0x1C */ s32* data;
} EffectGraphics; // size = 0x20

typedef struct EffectTableEntry {
    /* 0x00 */ void (*entryPoint);
    /* 0x04 */ void* dmaStart;
    /* 0x08 */ void* dmaEnd;
    /* 0x0C */ void* dmaDest;
    /* 0x10 */ void* graphicsDmaStart;
    /* 0x14 */ void* graphicsDmaEnd;
} EffectTableEntry; // size = 0x18

typedef struct EffectWhirlwind {
    /* 0x00 */ char unk_00[40];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} EffectWhirlwind;

typedef struct Effect6BData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char unk_10[12];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ char unk_24[8];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 scale;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ char unk_40[0x4];
} Effect6BData; // size = 0x44

typedef struct Effect6BInstance {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[8];
    /* 0x0C */ Effect6BData* data;
} Effect6BInstance;

typedef struct Effect6FData {
    /* 0x00 */ EffectInstanceDataThing* unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3i rotation;
    /* 0x1C */ Vec3i scale;
    /* 0x28 */ Vec3i color;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ char unk_40[0x4];
} Effect6FData; // size = 0x44

typedef struct Effect6FInstance {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 effectIndex;
    /* 0x08 */ s32 numParts;
    /* 0x0C */ Effect6FData* data;
    /* 0x10 */ struct EffectGraphics* effect;
} Effect6FInstance;

EffectInstance* create_effect_instance(EffectBlueprint* effectBp);
void remove_effect(EffectInstance*);
s32 load_effect(s32 effectIndex);

void fx_big_dust_puff(s32, f32, f32, f32, s32);
void fx_big_smoke_puff(f32, f32, f32);
void fx_landing_dust(s32, f32, f32, f32, f32);
void fx_walking_dust(s32, f32, f32, f32, f32, f32);
void fx_flower_splash(f32, f32, f32, f32);
void fx_flower_trail(s32, f32, f32, f32, f32, f32);
EffectInstance* fx_cloud_puff(f32, f32, f32, f32);
EffectInstance* fx_cloud_trail(s32, f32, f32, f32);
EffectInstance* playFX_0C(f32, f32, f32, f32, f32);
EffectInstance* playFX_0D(s32, f32, f32, f32, s32);
EffectInstance* playFX_0E(f32, f32, f32, s32);
void playFX_0F(s32, f32, f32, f32, f32, f32, f32, f32);
void fx_emote(s32, Npc*, f32, f32, f32, f32, f32, s32, s32*);
void playFX_11(s32, f32, f32, f32, f32);
EffectInstance* playFX_12(s32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* playFX_13(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_14(s32, f32, f32, f32, s32);
EffectInstance* playFX_15(s32, f32, f32, f32, s32);
EffectInstance* playFX_16(s32, f32, f32, f32, f32);
void playFX_17(s32, f32, f32, f32);
void playFX_18(s32, f32, f32, f32, f32, f32, f32, s32);
void playFX_19(s32, f32, f32, f32);
EffectInstance* playFX_1A(s32, f32, f32, f32, s32);
EffectInstance* playFX_1B(s32, f32, f32, f32, f32, s32*);
EffectInstance* playFX_1C(s32, f32, f32, f32, s32);
void playFX_1D(s32, f32, f32, f32, f32, s32, f32, s32);
EffectInstance* playFX_1E(s32, f32, f32, f32, f32, f32, s32, s32*);
EffectInstance* playFX_1F(s32, f32, f32, f32, f32, f32, f32, f32);
EffectInstance* playFX_20(s32, f32, f32, f32, f32, EffectInstance**);
EffectInstance* playFX_21(s32, f32, f32, f32, f32, f32, s32);
void playFX_22(s32, f32, f32, f32, f32, f32, s32, s32);
EffectInstance* playFX_23(u32, f32, f32, f32, f32);
EffectInstance* playFX_24(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_25(s32, f32, f32, f32);
void playFX_26(s32, f32, f32, f32);
EffectInstance* playFX_27(s32, f32, f32, f32, f32, s32);
void fx_sweat(s32, f32 x, f32 y, f32 z, f32, f32, s32);
void fx_sleep_bubble(s32, f32, f32, f32, f32, f32, s32*);
EffectInstance* playFX_2A(s32, f32, f32, f32);
EffectInstance* playFX_2B(s32, f32, f32, f32);
EffectInstance* playFX_2C(s32, f32, f32, f32);
void playFX_2D(s32, f32, f32, f32, s32, s32);
void playFX_2E(s32, f32, f32, f32, f32, s32);
void playFX_2F(s32, f32, f32, f32, f32, s32, s32*);
void playFX_30(s32, f32, f32, f32);
void playFX_31(s32, f32, f32, f32);
void playFX_32(s32, f32, f32, f32, f32);
EffectInstance* playFX_33(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_34(s32, f32, f32, f32, f32, s32*);
EffectInstance* playFX_35(s32, f32, f32, f32, f32, s32*);
EffectInstance* playFX_36(s32, f32, f32, f32, f32, f32);
EffectInstance* playFX_37(s32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
EffectInstance* playFX_38(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_39(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_3A(s32, f32, f32, f32, f32, f32, s32, s32);
void playFX_3B(s32, f32, f32, f32, f32, s32*);
EffectInstance* playFX_3C(s32, f32, f32, f32, f32, s32*);
void playFX_3D(s32, f32, f32, f32, f32, f32, f32, s32, s32*);
EffectInstance* playFX_3E(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_3F(s32, f32, f32, f32, s32);
EffectInstance* playFX_40(s32, f32, f32, f32, s32);
EffectInstance* playFX_41(s32, f32, f32, f32, s32);
EffectInstance* playFX_42(s32, s32, s32, f32, s32, s32);
EffectInstance* playFX_43(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_44(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_45(s32, s32);
EffectInstance* playFX_46_whirlwind(s32, EffectWhirlwind*, f32, s32);
EffectInstance* playFX_47(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_48(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_49(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_4A(s32, f32, f32, f32, f32, f32);
EffectInstance* playFX_4B(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_4C(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* playFX_4D(s32, f32, f32, f32, f32, s32, f32, s32, f32, s32);
EffectInstance* playFX_4E(s32, f32, f32, f32);
EffectInstance* playFX_4F(s32, f32, f32, f32, f32, s32);
void playFX_50(s32, f32, f32, f32);
EffectInstance* playFX_51(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_52(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_53(s32, f32, f32, f32);
EffectInstance* playFX_54(s32, f32, f32, f32);
EffectInstance* playFX_55(s32, f32, f32, f32);
EffectInstance* playFX_56(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_57(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_58(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_59(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* playFX_5A(s32, f32 x, f32 y, f32 z, f32 scale /* maybe */, s32);
EffectInstance* playFX_5B(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_5C(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_5D(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_5E(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* playFX_5F(s32, f32 x, f32 y, f32 z, f32 scale /* maybe */, s32);
EffectInstance* playFX_60(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_61(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_62(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_63(s32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
EffectInstance* playFX_64(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* playFX_65(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_66(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_67(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_68(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_69(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_6A(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_6B(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_6C(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_6D(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_6E(s32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* playFX_6F(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_70(s32, f32, f32, f32, f32, f32, f32, s32, s32, f32, f32);
EffectInstance* playFX_71(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_72(s32, f32, f32, f32, f32, f32, f32, s32, s32);
EffectInstance* playFX_73(s32, f32, f32, f32, f32, s32, s32); //returns ptr to struct unk_802BE310* in watt.c
EffectInstance* playFX_74(s32, f32, f32, f32, f32, f32, f32, f32, f32);
EffectInstance* playFX_75(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_76(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_77(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* playFX_78(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_79(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_7A(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_7B(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_7C(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_7D(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_7E(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_7F(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_80(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_81(s32, f32 x, f32 y, f32 z, f32, s32);
EffectInstance* playFX_82(s32, f32, f32, f32, f32, s32 time);
EffectInstance* playFX_83(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_84(s32, f32, f32, f32, f32, f32);
EffectInstance* playFX_85(s32, f32, f32, f32, f32, s32);
EffectInstance* playFX_86(s32, f32, f32, f32, f32, s32);

#endif
