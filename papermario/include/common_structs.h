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
    /* 0x0 */ s8 enabled;
    /* 0x1 */ s8 level;
    /* 0x2 */ s16 unk_2;
    /* 0x4 */ s16 unk_4;
    /* 0x6 */ s16 unk_6;
} partner_data; // size = 0x8

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
    /* 0x00B */ char unk_0B;
    /* 0x00C */ s16 coins;
    /* 0x00E */ s8 fortressKeyCount;
    /* 0x00F */ u8 starPieces;
    /* 0x010 */ u8 starPoints;
    /* 0x011 */ char unk_11;
    /* 0x012 */ s8 currentPartner;
    /* 0x013 */ char unk_13;
    /* 0x014 */ partner_data partners[12];
    /* 0x074 */ s16 keyItems[32];
    /* 0x0B4 */ s16 badges[128];
    /* 0x1B4 */ s16 invItems[10];
    /* 0x1C8 */ s16 storedItems[32];
    /* 0x208 */ s16 equippedBadges[64];
    /* 0x288 */ s8 unk_288;
    /* 0x289 */ s8 merleeSpellType;
    /* 0x28A */ s8 merleeCastsLeft;
    /* 0x28B */ char unk_28B;
    /* 0x28C */ s16 merleeTurnCount;
    /* 0x28E */ s8 maxStarPower;
    /* 0x28F */ char unk_28F;
    /* 0x290 */ s16 specialBarsFilled;
    /* 0x292 */ s8 unk_292;
    /* 0x293 */ char unk_293;
    /* 0x294 */ s16 otherHitsTaken;
    /* 0x296 */ s16 unk_296;
    /* 0x298 */ s16 hitsTaken;
    /* 0x29A */ s16 hitsBlocked;
    /* 0x29C */ s16 playerFirstStrikes;
    /* 0x29E */ s16 enemyFirstStrikes;
    /* 0x2A0 */ s16 powerBounces;
    /* 0x2A2 */ s16 battlesCount;
    /* 0x2A4 */ s16 unk_2A4;
    /* 0x2A6 */ s16 unk_2A6;
    /* 0x2A8 */ s16 unk_2A8;
    /* 0x2AA */ s16 unk_2AA;
    /* 0x2AC */ s32 unk_2AC;
    /* 0x2B0 */ s32 unk_2B0;
    /* 0x2B4 */ s32 totalCoinsEarned;
    /* 0x2B8 */ s16 idleFrameCounter; /* frames with no inputs, overflows ever ~36 minutes of idling */
    /* 0x2BA */ char unk_2BA[0x2];
    /* 0x2BC */ s32 frameCounter; /* increases by 2 per frame */
    /* 0x2C0 */ s16 quizzesAnswered;
    /* 0x2C2 */ s16 quizzesCorrect;
    /* 0x2C4 */ s32 unk_2C4;
    /* 0x2C8 */ s32 unk_2C8[12];
    /* 0x2F8 */ char unk_2F8[0x30];
    /* 0x328 */ s32 unk_328;
    /* 0x32C */ s16 starPiecesCollected;
    /* 0x32E */ s16 jumpGamePlays;
    /* 0x330 */ s32 jumpGameTotal;
    /* 0x334 */ s16 jumpGameRecord;
    /* 0x336 */ s16 smashGamePlays;
    /* 0x338 */ s32 smashGameTotal;
    /* 0x33C */ s16 smashGameRecord;
    /* 0x33E */ char unk_33E[0x2];
} player_data; // size = 0x340

typedef struct {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ s32* ptrReadPos;
} ScriptContext;

#endif
