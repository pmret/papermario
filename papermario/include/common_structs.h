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
    /* 0x084 */ char unk_84[0x8];
    /* 0x08C */ s16 mapID;
    /* 0x08E */ char unk_8E[0x1A];
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
    /* 0x00 */ s32 nameString;
    /* 0x04 */ s16 iconID;
    /* 0x06 */ s16 badgeSortPriority;
    /* 0x08 */ s32 targetFlags;
    /* 0x0C */ s16 sellValue;
    /* 0x10 */ s32 menuString;
    /* 0x14 */ s32 itemString;
    /* 0x18 */ s16 typeFlags;
    /* 0x1A */ s8 moveID;
    /* 0x1B */ s8 potencyA;
    /* 0x1C */ s8 potencyB;
    /* 0x1D */ char unk_1D[3];
} item_table_entry;

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
    /* 0x010 */ s8 starPoints;
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
    /* 0x2B4 */ u32 totalCoinsEarned;
    /* 0x2B8 */ s16 idleFrameCounter; /* frames with no inputs, overflows ever ~36 minutes of idling */
    /* 0x2BA */ char unk_2BA[0x2];
    /* 0x2BC */ s32 frameCounter; /* increases by 2 per frame */
    /* 0x2C0 */ s16 quizzesAnswered;
    /* 0x2C2 */ s16 quizzesCorrect;
    /* 0x2C4 */ s32 unk_2C4[12];
    /* 0x2F4 */ s32 unk_2F4[12];
    /* 0x2F8 */ char unk_324[4];
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
    /* 0x00 */ s32 hpIconIndexes[2]; /* hpIconIndex, heartIconIndex */
    /* 0x08 */ s32 fpIconIndexes[2]; /* fpIconIndex, flowerIconIndex */
    /* 0x10 */ s32 coinIconIndex;
    /* 0x14 */ s32 coinIconIndex2;
    /* 0x18 */ s32 starpointsIconIndex;
    /* 0x1C */ s32 starpointsIconIndex2;
    /* 0x20 */ s32 iconIndex8;
    /* 0x24 */ s32 iconIndex9;
    /* 0x28 */ s32 iconIndexA;
    /* 0x2C */ s32 iconIndexB;
    /* 0x30 */ s32 iconIndexC;
    /* 0x34 */ s16 drawPosX; /* overall x-offset for whole UI */
    /* 0x36 */ s16 drawPosY; /* modulated as it appears, goes away */
    /* 0x38 */ s16 showTimer;
    /* 0x3A */ s8 hidden;
    /* 0x3B */ s8 unk_3B;
    /* 0x3C */ s8 unk_3C;
    /* 0x3D */ s8 displayHP;
    /* 0x3E */ s8 displayFP;
    /* 0x3F */ char unk_3F;
    /* 0x40 */ s16 displayCoins;
    /* 0x42 */ s16 displayStarpoints;
    /* 0x44 */ s8 ignoreChanges; /* set != 0 to prevent automatic opening from HP/FP changes */
    /* 0x45 */ s8 unk_45;
    /* 0x46 */ s8 unk_46;
    /* 0x47 */ s8 disabled; /* set != 0 for menu to be disabled completely */
    /* 0x48 */ s16 displaySP;
    /* 0x4A */ s8 hpBlinking;
    /* 0x4B */ s8 hpBlinkCounter;
    /* 0x4C */ s8 hpBlinkTimer;
    /* 0x4D */ s8 fpBlinking;
    /* 0x4E */ s8 fpBlinkCounter;
    /* 0x4F */ s8 fpBlinkTimer;
    /* 0x50 */ s8 spBlinking;
    /* 0x51 */ s8 spBlinkCounter;
    /* 0x52 */ s8 starpointsBlinking;
    /* 0x53 */ s8 starpointsBlinkCounter;
    /* 0x54 */ s8 coinsBlinking;
    /* 0x55 */ s8 coinsBlinkCounter;
    /* 0x56 */ s8 coinsBlinkTimer;
    /* 0x57 */ s8 unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ s8 unk_59;
    /* 0x5A */ s8 spBarsToBlink; /* how many sp bars to blink */
    /* 0x5B */ char unk_5B;
    /* 0x5C */ s32 iconIndex10;
    /* 0x60 */ s32 iconIndex11;
    /* 0x64 */ s32 iconIndex12;
    /* 0x68 */ s32 iconIndex13;
    /* 0x6C */ s8 unk_6C;
    /* 0x6D */ s8 unk_6D;
    /* 0x6E */ s8 unk_6E;
    /* 0x6F */ char unk_6F;
} ui_status; // size = 0x70

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s16 height;
    /* 0x06 */ s16 radius;
    /* 0x08 */ void* otherAI; //?
    /* 0x0C */ s32* interactScript;
    /* 0x10 */ s32* aiScript;
    /* 0x14 */ s32* hitScript;
    /* 0x18 */ s32* auxScript;
    /* 0x1C */ s32* defeatScript;
    /* 0x20 */ s32 flags;
    /* 0x24 */ char unk_24[0x4];
    /* 0x28 */ s16 level;
    /* 0x2A */ s16 unkFlags;
} StaticNpcSettings; // size = 0x2C

typedef enum {
    Hammer=4,
    Jump=2,
    Normal=1,
    Partner=6,
    Spin=3,
} eEncounterTrigger;

typedef struct {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s8 encounterIndex;
    /* 0x05 */ s8 encountered; // eEncounterTrigger
    /* 0x06 */ s8 scriptGroup; /* scripts launched for this npc controller will be assigned this group */
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ s16 npcID;
    /* 0x0A */ s16 spawnPos[3];
    /* 0x10 */ s16 unk_10[3];
    /* 0x16 */ char unk_16[0x2];
    /* 0x18 */ struct StaticNpcSettings* npcSettings;
    /* 0x1C */ s32* initBytecode;
    /* 0x20 */ s32* interactBytecode;
    /* 0x24 */ s32* aiBytecode;
    /* 0x28 */ s32* hitBytecode;
    /* 0x2C */ s32* auxBytecode;
    /* 0x30 */ s32* defeatBytecode;
    /* 0x34 */ struct script_context* initScript;
    /* 0x38 */ struct script_context* interactScript;
    /* 0x3C */ struct script_context* aiScript;
    /* 0x40 */ struct script_context* hitScript;
    /* 0x44 */ struct script_context* auxScript;
    /* 0x48 */ struct script_context* defeatScript;
    /* 0x4C */ s32 initScriptID;
    /* 0x50 */ s32 interactScriptID;
    /* 0x54 */ s32 aiScriptID;
    /* 0x58 */ s32 hitScriptID;
    /* 0x5C */ s32 auxScriptID;
    /* 0x60 */ s32 defeatScriptID;
    /* 0x64 */ void* unk_64;
    /* 0x68 */ char unk_68[0x4];
    /* 0x6C */ s32 varTable[16];
    /* 0xAC */ s8 unk_AC;
    /* 0xAD */ char unk_AD[0x3];
    /* 0xB0 */ s32* unk_B0; /* might be flags of some sort */
    /* 0xB4 */ s8 unk_B4;
    /* 0xB5 */ s8 unk_B5;
    /* 0xB6 */ char unk_B6[0x2];
    /* 0xB8 */ s32 unkSettings24;
    /* 0xBC */ s32 unk_BC;
    /* 0xC0 */ s32 unk_C0;
    /* 0xC4 */ s32 unk_C4;
    /* 0xC8 */ char unk_C8[0x4];
    /* 0xCC */ s32* animList;
    /* 0xD0 */ s32* territoryData;
    /* 0xD4 */ s32* dropTables;
    /* 0xD8 */ u32 tattleString;
    /* 0xDC */ s32 unk_DC;
    /* 0xE0 */ s16 unk_E0;
    /* 0xE2 */ char unk_E2[0xE];
} enemy; // size = 0xF0

typedef struct {
    /* 0x000 */ s8 state;
    /* 0x001 */ s8 currentArgc;
    /* 0x002 */ s8 currentOpcode;
    /* 0x003 */ s8 priority;
    /* 0x004 */ s8 groupFlags;
    /* 0x005 */ s8 blocked; /* 1 = blocking */
    /* 0x006 */ s8 loopDepth; /* how many nested loops we are in, >= 8 hangs forever */
    /* 0x007 */ s8 switchDepth; /* how many nested switches we are in, max = 8 */
    /* 0x008 */ s32* ptrNextLine;
    /* 0x00C */ s32* ptrReadPos;
    /* 0x010 */ s8 labelIndices[16];
    /* 0x020 */ s32* labelPositions[16];
    /* 0x060 */ s32 deleted; /* set to zero in KillScript when malloc'd */
    /* 0x064 */ struct script_context* blockingParent; /* parent? */
    /* 0x068 */ struct script_context* childScript;
    /* 0x06C */ struct script_context* parentScript; /* brother? */
    /* 0x070 */ s32 functionTemp[4];
    /* 0x080 */ void* callFunction;
    /* 0x084 */ u32 varTable[16];
    /* 0x0C4 */ s32 varFlags[3];
    /* 0x0D0 */ s32 loopStartTable[8];
    /* 0x0F0 */ s32 loopCounterTable[8];
    /* 0x110 */ s8 switchBlockState[8];
    /* 0x118 */ s32 switchBlockValue[8];
    /* 0x138 */ void* buffer;
    /* 0x13C */ void* array;
    /* 0x140 */ void* flagArray;
    /* 0x144 */ s32 uniqueID;
    /* 0x148 */ enemy* ownerActorID; /* controller*, battle ID, trigger* */
    /* 0x14C */ u32 ownerID; /* can be an npcID, a triggerID, a trigger ptr */
    /* 0x150 */ f32 timeScale;
    /* 0x154 */ f32 frameCounter;
    /* 0x158 */ s32 unk_158;
    /* 0x15C */ s32* ptrFirstLine;
    /* 0x160 */ s32* ptrSavedPosition;
    /* 0x164 */ s32* ptrCurrentLine;
} script_context; // size = 0x168;

#endif
