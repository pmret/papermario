#ifndef _MAP_H_
#define _MAP_H_

#include "common_structs.h"
#include "enums.h"
#include "script_api/map.h"

// TODO: consider moving Npc here

#define ENTRY_COUNT(entryList) (sizeof(entryList) / sizeof(Vec4f))

typedef Vec4f EntryList[0];

/// Fields other than main, entryList, entryCount, background, and tattle are initialised when the map loads.
typedef struct MapConfig {
    /* 0x00 */ ModelNode* modelTreeRoot;
    /* 0x04 */ UNK_PTR collision;
    /* 0x08 */ char unk_08[8];
    /* 0x10 */ Script* main;
    /* 0x14 */ EntryList* entryList;
    /* 0x18 */ s32 entryCount;
    /* 0x1C */ char unk_1C[12];
    /* 0x28 */ char** modelNameList;
    /* 0x2C */ char** colliderNameList;
    /* 0x30 */ char** zoneNameList;
    /* 0x34 */ char unk_34[4];
    /* 0x38 */ BackgroundHeader* background;
    /* 0x3C */ union {
        MessageID msgID;
        UNK_FUN_PTR(get);
    } tattle;
} MapConfig; // size = 0x40

typedef s32(*MapInit)(void);

#define MAP_ID_MAX_LEN 7 ///< "xxx_yyy" excluding null terminator.
typedef struct Map {
    /* 0x00 */ char* id; ///< @see MAP_ID_MAX_LEN
    /* 0x04 */ MapConfig* config;
    /* 0x08 */ void* dmaStart;
    /* 0x0C */ void* dmaEnd;
    /* 0x10 */ void* dmaDest;
    /* 0x14 */ char* bgName;
    /* 0x18 */ MapInit init; ///< Return TRUE to skip normal asset (shape/hit/bg/tex) loading.
    /* 0x1C */ s16 unk_1C; // Unused?
    /* 0x1E */ s8 songVariation; ///< 0 or 1. @see bgm_get_map_default_variation
    /* 0x1F */ s8 flags;
} Map; // size = 0x20

typedef struct Area {
    /* 0x00 */ s32 mapCount;
    /* 0x04 */ Map* maps;
    /* 0x08 */ char* id; ///< "area_xxx"
    /* 0x0C */ char* name; ///< JP debug name.
} Area; // size = 0x10

typedef struct NpcBlueprint {
    /* 0x00 */ s32 flags;
    /* 0x04 */ NpcAnimID initialAnim;
    /* 0x08 */ UNK_FUN_PTR(onUpdate);
    /* 0x0C */ UNK_FUN_PTR(onRender);
} NpcBlueprint; // size = 0x10

typedef struct NpcAISettings {
    /* 0x00 */ f32 moveSpeed;
    /* 0x04 */ s32 moveTime;
    /* 0x08 */ s32 waitTime;
    /* 0x0C */ f32 alertRadius;
    /* 0x10 */ X32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 chaseSpeed;
    /* 0x1C */ s32 unk_1C; // chase turn step?
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 chaseRadius;
    /* 0x28 */ X32 unk_28;
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

/// @brief Describes heart/flower drop chances after defeating an Npc in the overworld.
///
/// The algorithm for calculating the number of hearts/flowers from a StatDrop is:
/// - If current HP/FP > cutoff, drop 0.
/// - Roll generalChance. If it fails, drop 0.
/// - Roll chancePerAttempt attempts times. For each success, drop a heart/flower.
///
/// StaticNpc holds a table of StatDrops for each stat (hearts, flowers). All are checked together
/// and the number of hearts/flowers to drop is the total number of successful attempts for each stat.
///
/// Each heart/flower is worth 1 HP and 1 FP respectively, if picked up.
///
/// cutoff, generalChance, and chancePerAttempt are short fixed-point percentage values.
/// That is, `F16(0)` is a 0% chance and `F16(100)` is a 100% chance.
typedef struct StatDrop {
    /* 0x00 */ s16 cutoff;           ///< % of max HP/FP. If current HP/FP > cutoff, no hearts/flowers can be dropped.
    /* 0x02 */ s16 generalChance;    ///< % chance for any hearts/flowers to be dropped at all from this StatDrop.
    /* 0x04 */ s16 attempts;         ///< Maximum number of hearts/flowers that can be dropped from this StatDrop.
    /* 0x06 */ s16 chancePerAttempt; ///< % chance for a single heart/flower to be dropped from each attempt.
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

#define OVERRIDE_MOVEMENT_SPEED(speed) (speed * 32767)
#define NO_OVERRIDE_MOVEMENT_SPEED OVERRIDE_MOVEMENT_SPEED(-1)

typedef struct StaticNpc {
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
    /* 0x0E0 */ s32 movement[48]; // TODO: type
    /* 0x1A0 */ NpcAnimID animations[16];
    /* 0x1E0 */ char unk_1E0[8];
    /* 0x1E8 */ NpcAnimID* extraAnimations;
    /* 0x1EC */ MessageID tattle;
} StaticNpc; // size = 0x1F0

typedef struct EnemyTerritoryThing {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 shape;
    /* 0x08 */ s32 pointX;
    /* 0x0C */ s32 pointZ;
    /* 0x10 */ s32 sizeX;
    /* 0x14 */ s32 sizeZ;
    /* 0x18 */ f32 unk_34;
    /* 0x1C */ s16 unk_1C;
} EnemyTerritoryThing; // size = 0x20

typedef struct EnemyTerritory {
    /* 0x00 */ Vec3i unk_00;
    /* 0x0C */ char unk_0C[0x8];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 pointX;
    /* 0x20 */ s32 pointY;
    /* 0x24 */ s32 pointZ;
    /* 0x28 */ s32 sizeX;
    /* 0x2C */ s32 sizeZ;
    /* 0x30 */ s32 shape;
    /* 0x34 */ s32 unk_34;
} EnemyTerritory; // size = ???

typedef struct Enemy {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s8 encounterIndex;
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
    /* 0xAC */ char unk_AC[4];
    /* 0xB0 */ s32 unk_B0;
    /* 0xB4 */ s8 unk_B4;
    /* 0xB5 */ s8 unk_B5;
    /* 0xB6 */ char unk_B6[2];
    /* 0xB8 */ s32 unkSettings24;
    /* 0xBC */ char unk_BC[8];
    /* 0xC4 */ s32 unk_C4;
    /* 0xC8 */ s32 unk_C8;
    /* 0xCC */ s32* animList;
    /* 0xD0 */ EnemyTerritory* territory;
    /* 0xD4 */ s16* dropTables;
    /* 0xD8 */ u32 tattleString;
    /* 0xDC */ char unk_DC[20];
} Enemy; // size = 0xF0

/// Zero-terminated.
typedef struct {
    /* 0x00 */ s32 npcCount;
    /* 0x04 */ StaticNpc* npcs;
    /* 0x08 */ BattleID battle;
} NpcGroupList[]; // size = 0x0C

#define NPC_GROUP(npcs, battle) { sizeof(npcs) / sizeof(StaticNpc), &npcs, battle }

Enemy* get_enemy(NpcId npcId);
MapConfig* get_current_map_header(void);

s32 func_800490B4(EnemyTerritoryThing* arg0, Enemy* arg1, f32 arg2, s32 arg3, s32 arg4);

/// Zero-terminated.
Area gAreas[29];

/// Lists the songs that are forced to use the variation determined by `map.songVariation & 1`.
/// @see bgm_get_map_default_variation
extern SongID gSongsUsingVariationFlag[6];
extern s16 D_8014F738;

#endif
