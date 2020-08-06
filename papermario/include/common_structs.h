#ifndef _COMMON_STRUCTS_H_
#define _COMMON_STRUCTS_H_

#include "ultra64.h"

typedef struct {
    /* 0x000 */ s16 unk_00;
    /* 0x002 */ s16 unk_02;
    /* 0x004 */ char unk_04[0x44];
    /* 0x048 */ u16 unk_48[4];
    /* 0x050 */ u16 unk_50[4];
    /* 0x058 */ char unk_58[0x10];
    /* 0x068 */ u16 demoButtonInput;
    /* 0x06A */ s8 demoStickX;
    /* 0x06B */ s8 demoStickY;
    /* 0x06C */ char unk_6C[0x4];
    /* 0x070 */ s8 unk_70;
    /* 0x071 */ s8 demoState;
    /* 0x072 */ char unk_72[3];
    /* 0x075 */ s8 unk_75;
    /* 0x076 */ char unk_76[3];
    /* 0x079 */ s8 unk_79;
    /* 0x07A */ s8 musicEnabled;
    /* 0x07B */ char unk_7B;
    /* 0x07C */ s8 unk_7C;
    /* 0x07D */ char unk_7D[4];
    /* 0x081 */ s8 unk_81;
    /* 0x082 */ s8 unk_82;
    /* 0x083 */ s8 unk_83;
    /* 0x084 */ char unk_84[0x24];
    /* 0x0A8 */ s8 unk_A8;
    /* 0x0A9 */ char unk_A9;
    /* 0x0AA */ s8 unk_AA;
    /* 0x0AB */ char unk_AB[0x91];
    /* 0x13C */ s16 unk_13C;
    /* 0x13E */ char unk_13E[0xA];
    /* 0x148 */ s16 unk_148;
    /* 0x14A */ char unk_14A[0x1E];
    /* 0x168 */ s32 unk_168;
} game_status;

typedef struct {
    /* 0x000 */ s8 bootsLevel;
    /* 0x001 */ s8 hammerLevel;
    /* 0x002 */ s8 curHP;
    /* 0x003 */ s8 curMaxHP;
    /* 0x004 */ s8 hardMaxHP;
    /* 0x005 */ s8 curFP;
    /* 0x006 */ s8 curMaxFP;
    /* 0x007 */ s8 hardMaxFP;
    /* 0x008 */ s8 maxBP;
    /* 0x009 */ s8 level;
    /* 0x00A */ s8 hasActionCommands;
    /* 0x00B */ char unk_0B[0x1];
    /* 0x00C */ s16 coins;
    /* 0x00E */ s8 fortressKeyCount;
    /* 0x00F */ s8 starPieces;
    /* 0x010 */ s8 starPoints;
    /* 0x011 */ char unk_11[0x1];
    /* 0x012 */ s8 currentPartner;
} player_data;

typedef struct {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ s32* ptrReadPos;
} ScriptContext;

#endif
