#ifndef _BATTLE_BATTLE_H_
#define _BATTLE_BATTLE_H_

#include "common.h"

typedef struct ActorDesc {
    /* 0x00 */ s32 flags;
    /* 0x04 */ char unk_04;
    /* 0x05 */ u8 type;
    /* 0x06 */ u8 level;
    /* 0x07 */ u8 maxHP;
    /* 0x08 */ s16 partCount;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ struct StaticActorPart** partsData;
    /* 0x10 */ Bytecode* script;
    /* 0x14 */ s32* statusTable;
    /* 0x18 */ u8 escapeChance;
    /* 0x19 */ u8 airLiftChance;
    /* 0x1A */ u8 spookChance;
    /* 0x1B */ u8 baseStatusChance;
    /* 0x1C */ u8 upAndAwayChance;
    /* 0x1D */ u8 spinSmashReq;
    /* 0x1E */ u8 powerBounceChance;
    /* 0x1F */ u8 coinReward;
    /* 0x20 */ Vec2b size;
    /* 0x22 */ Vec2b hpBarOffset;
    /* 0x24 */ Vec2b statusIconOffset;
    /* 0x26 */ Vec2b statusMessageOffset;
} ActorDesc; // size = 0x28

typedef struct Stage {
    /* 0x00 */ const char* texture;
    /* 0x04 */ const char* shape;
    /* 0x08 */ const char* hit;
    /* 0x0C */ Bytecode* preBattle;
    /* 0x10 */ Bytecode* postBattle;
    /* 0x14 */ const char* bg;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
} Stage; // size = 0x28

/// Zero-terminated.
typedef struct StageListRow {
    /* 0x00 */ const char* id; ///< Map ID.
    /* 0x04 */ Stage* stage;
} StageList[]; // size = 0x08 * n

typedef struct FormationRow {
    /* 0x00 */ ActorDesc* actor;
    /* 0x04 */ s32 position; ///< Home position. May also be a `Vector3*`.
    /* 0x08 */ s32 priority; ///< Actors with higher priority values take their turn first.
    /* 0x0C */ s32 var0;
    /* 0x10 */ s32 var1;
    /* 0x14 */ s32 var2;
    /* 0x18 */ s32 var3;
} Formation[]; // size = 0x1C * n

/// Zero-terminated.
typedef struct Battle {
    /* 0x00 */ const char* name; ///< Debug SJIS name.
    /* 0x04 */ s32 formationSize;
    /* 0x08 */ Formation* formation;
    /* 0x0C */ Stage* stage;
    /* 0x10 */ s32 unk_10;
} BattleList[]; // size = 0x14 * n

typedef struct {
    Element element;
    s32 defense;
} DefenseTableEntry;

typedef DefenseTableEntry DefenseTable[];

#define BATTLE(name, formation, stage) { name, ARRAY_COUNT(formation), formation, stage }

// TODO: enum for home position (0..3 are floor, 4..7 are air, etc.)

#endif
