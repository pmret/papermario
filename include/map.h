#ifndef _MAP_H_
#define _MAP_H_

#include "common_structs.h"
#include "enums.h"
#include "script_api/map.h"

// TODO: consider moving Npc here

#define ENTRY_COUNT(entryList) (sizeof(entryList) / sizeof(Vec4f))

typedef Vec4f EntryList[];

typedef struct MapConfig {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ Script* main;
    /* 0x14 */ EntryList* entryList;
    /* 0x18 */ s32 entryCount;
    /* 0x1C */ char unk_1C[0x1C];
    /* 0x38 */ BackgroundHeader* background;
    /* 0x3C */ union {
        MessageID msgID;
        UNK_FUN_PTR(get);
    } tattle;
} MapConfig; // size = 0x40

typedef struct NpcAISettings {
    /* 0x00 */ f32 moveSpeed;
    /* 0x04 */ s32 moveTime;
    /* 0x08 */ s32 waitTime;
    /* 0x0C */ f32 alertRadius;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 chaseSpeed;
    /* 0x1C */ s32 unk_1C; // chase turn step?
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 chaseRadius;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C; // bool
} NpcAISettings; // size = 0x30

typedef struct NpcSettings {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 height;
    /* 0x06 */ s16 radius;
    /* 0x08 */ UNK_PTR otherAI;
    /* 0x0C */ Script* onInteract;
    /* 0x10 */ Script* ai;
    /* 0x14 */ Script* onHit;
    /* 0x18 */ Script* aux;
    /* 0x1C */ Script* onDefeat;
    /* 0x20 */ s32 flags;
    /* 0x24 */ char unk_24[4];
    /* 0x28 */ s16 level;
    /* 0x2A */ s16 unk_2A;
} NpcSettings; // size = 0x2C

typedef struct ItemDrop {
    /* 0x00 */ ItemId item;
    /* 0x02 */ s16 weight;
    /* 0x04 */ s16 unk_08;
} ItemDrop; // size = 0x06

typedef struct StatDrop {
    // NOTE: these %s are F16
    /* 0x00 */ s16 hpCutoff; // % of max HP/FP
    /* 0x02 */ s16 generalChance; // %
    /* 0x04 */ s16 attempts;
    /* 0x06 */ s16 chancePerAttempt; // %
} StatDrop; // size = 0x08

#define NO_DROPS { F16(100), F16(0), 0, F16(0) }

#define STANDARD_HEART_DROPS(attempts) { \
    { F16(20), F16(70), attempts, F16(50) }, \
    { F16(30), F16(60), attempts, F16(50) }, \
    { F16(50), F16(50), attempts, F16(40) }, \
    { F16(80),  F16(40), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(30) }, \
}

#define GENEROUS_HEART_DROPS(attempts) { \
    { F16(20), F16(80), attempts, F16(50) } \
    { F16(30), F16(70), attempts, F16(50) } \
    { F16(50), F16(60), attempts, F16(40) } \
    { F16(80), F16(50), attempts, F16(40) } \
    { F16(100), F16(40), attempts, F16(30) }, \
}

#define GENEROUS_WHEN_LOW_HEART_DROPS(attempts) { \
    { F16(20), F16(80), attempts, F16(60) }, \
    { F16(30), F16(70), attempts, F16(50) }, \
    { F16(50), F16(60), attempts, F16(50) }, \
    { F16(80), F16(50), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(30) }, \
}

#define STANDARD_FLOWER_DROPS(attempts) { \
    { F16(20), F16(50), attempts, F16(40) }, \
    { F16(30), F16(40), attempts, F16(40) }, \
    { F16(50), F16(40), attempts, F16(40) }, \
    { F16(80), F16(40), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(40) }, \
}

#define GENEROUS_WHEN_LOW_FLOWER_DROPS(attempts) { \
    { F16(20), F16(70), attempts, F16(50) }, \
    { F16(30), F16(60), attempts, F16(50) }, \
    { F16(50), F16(50), attempts, F16(40) }, \
    { F16(80), F16(40), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(40) }, \
}

#define REDUCED_FLOWER_DROPS(attempts) { \
    { F16(20), F16(40), attempts, F16(40) }, \
    { F16(30), F16(40), attempts, F16(40) }, \
    { F16(50), F16(40), attempts, F16(40) }, \
    { F16(80), F16(40), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(40) }, \
}

#define ANIMATION(sprite, palette, anim) (sprite << 16) + (palette << 8) + anim

typedef struct StaticNPC {
    /* 0x000 */ NpcId id;
    /* 0x004 */ NpcSettings* settings;
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 flags;
    /* 0x018 */ Bytecode* init;
    /* 0x01C */ char unk_1C[8];
    /* 0x024 */ s32 yaw;
    /* 0x028 */ s8 dropFlags;
    /* 0x029 */ s8 itemDropChance; // %
    /* 0x02A */ ItemDrop itemDrops[8];
    /* 0x05A */ StatDrop heartDrops[8];
    /* 0x09A */ StatDrop flowerDrops[8];
    /* 0x0DA */ s16 minCoinBonus;
    /* 0x0DC */ s16 maxCoinBonus;
    /* 0x0DE */ char unk_DE[2];
    /* 0x0E0 */ s32 movement[48];
    /* 0x1A0 */ s32 animations[16];
    /* 0x1E0 */ char unk_1E0[8];
    /* 0x1E8 */ UNK_PTR extraAnimations;
    /* 0x1EC */ MessageID tattle;
} StaticNpc; // size = 0x1F0

typedef struct Enemy {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 encounterIndex;
    /* 0x05 */ s8 encountered;
    /* 0x06 */ u8 scriptGroup; /* scripts launched for this npc controller will be assigned this group */
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ s16 npcID;
    /* 0x0A */ s16 spawnPos[3];
    /* 0x10 */ Vec3s unk_10;
    /* 0x16 */ char unk_16[2];
    /* 0x18 */ struct NpcSettings* npcSettings;
    /* 0x1C */ Bytecode* initBytecode;
    /* 0x20 */ Bytecode* interactBytecode;
    /* 0x24 */ Bytecode* aiBytecode;
    /* 0x28 */ Bytecode* hitBytecode;
    /* 0x2C */ Bytecode* auxBytecode;
    /* 0x30 */ Bytecode* defeatBytecode;
    /* 0x34 */ struct ScriptInstance* initScript;
    /* 0x38 */ struct ScriptInstance* interactScript;
    /* 0x3C */ struct ScriptInstance* aiScript;
    /* 0x40 */ struct ScriptInstance* hitScript;
    /* 0x44 */ struct ScriptInstance* auxScript;
    /* 0x48 */ struct ScriptInstance* defeatScript;
    /* 0x4C */ ScriptID initScriptID;
    /* 0x50 */ ScriptID interactScriptID;
    /* 0x54 */ ScriptID aiScriptID;
    /* 0x58 */ ScriptID hitScriptID;
    /* 0x5C */ ScriptID auxScriptID;
    /* 0x60 */ ScriptID defeatScriptID;
    /* 0x64 */ char unk_64[8];
    /* 0x6C */ s32 varTable[16];
    /* 0xAC */ char unk_AC[9];
    /* 0xB5 */ s8 unk_B5;
    /* 0xB6 */ char unk_B6[2];
    /* 0xB8 */ s32 unkSettings24;
    /* 0xBC */ char unk_BC[8];
    /* 0xC4 */ s32 unk_C4;
    /* 0xC8 */ s32 unk_C8;
    /* 0xCC */ s32* animList;
    /* 0xD0 */ UNK_PTR territoryData;
    /* 0xD4 */ s16* dropTables;
    /* 0xD8 */ u32 tattleString;
    /* 0xDC */ char unk_DC[20];
} Enemy; // size = 0xF0

typedef struct {
    /* 0x00 */ s32 npcCount;
    /* 0x04 */ StaticNpc* npcs;
    /* 0x08 */ s32 battleID;
} NpcGroupList[]; // size = 0x0C

#define NPC_GROUP(npcs, battleID) { sizeof(npcs) / sizeof(StaticNpc), &npcs, battleID }
#define NPC_GROUP_LIST_END() { 0, 0, 0 }

Enemy* get_enemy(NpcId npcId);

#endif
