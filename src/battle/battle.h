#ifndef _BATTLE_BATTLE_H_
#define _BATTLE_BATTLE_H_

#include "common.h"
#include "message_ids.h"

// Terminates foreground model lists
#define STAGE_MODEL_LIST_END 0

enum BattleAreaIDs {
    BTL_AREA_KMR_1         = 0x00,
    BTL_AREA_KMR_2         = 0x01,
    BTL_AREA_KMR_3         = 0x02,
    BTL_AREA_MAC           = 0x03,
    BTL_AREA_HOS           = 0x04,
    BTL_AREA_NOK           = 0x05,
    BTL_AREA_TRD_1         = 0x06,
    BTL_AREA_TRD_2         = 0x07,
    BTL_AREA_TRD_3         = 0x08,
    BTL_AREA_IWA           = 0x09,
    BTL_AREA_SBK           = 0x0A,
    BTL_AREA_ISK_1         = 0x0B,
    BTL_AREA_ISK_2         = 0x0C,
    BTL_AREA_MIM           = 0x0D,
    BTL_AREA_ARN           = 0x0E,
    BTL_AREA_DGB           = 0x0F,
    BTL_AREA_OMO           = 0x10,
    BTL_AREA_OMO2          = 0x11,
    BTL_AREA_OMO3          = 0x12,
    BTL_AREA_KGR           = 0x13,
    BTL_AREA_JAN           = 0x14,
    BTL_AREA_JAN2          = 0x15,
    BTL_AREA_KZN           = 0x16,
    BTL_AREA_KZN2          = 0x17,
    BTL_AREA_FLO           = 0x18,
    BTL_AREA_FLO2          = 0x19,
    BTL_AREA_TIK           = 0x1A,
    BTL_AREA_TIK2          = 0x1B,
    BTL_AREA_TIK3          = 0x1C,
    BTL_AREA_SAM           = 0x1D,
    BTL_AREA_SAM2          = 0x1E,
    BTL_AREA_PRA           = 0x1F,
    BTL_AREA_PRA2          = 0x20,
    BTL_AREA_PRA3          = 0x21,
    BTL_AREA_KPA           = 0x22,
    BTL_AREA_KPA2          = 0x23,
    BTL_AREA_KPA3          = 0x24,
    BTL_AREA_KPA4          = 0x25,
    BTL_AREA_KKJ           = 0x26,
    BTL_AREA_DIG           = 0x27,
    BTL_AREA_UNUSED_28     = 0x28,
    BTL_AREA_OMO2_1        = 0x29,
    BTL_AREA_OMO2_2        = 0x2A,
    BTL_AREA_OMO2_3        = 0x2B,
    BTL_AREA_OMO2_4        = 0x2C,
    BTL_AREA_OMO2_5        = 0x2D,
    BTL_AREA_OMO2_6        = 0x2E,
};

enum BattlePositions {
    BTL_POS_GROUND_A  = 0,
    BTL_POS_GROUND_B  = 1,
    BTL_POS_GROUND_C  = 2,
    BTL_POS_GROUND_D  = 3,
    BTL_POS_AIR_A     = 4,
    BTL_POS_AIR_B     = 5,
    BTL_POS_AIR_C     = 6,
    BTL_POS_AIR_D     = 7,
    BTL_POS_HIGH_A    = 8,
    BTL_POS_HIGH_B    = 9,
    BTL_POS_HIGH_C    = 10,
    BTL_POS_HIGH_D    = 11,
    BTL_POS_TOP_A     = 12,
    BTL_POS_TOP_B     = 13,
    BTL_POS_TOP_C     = 14,
    BTL_POS_TOP_D     = 15,
    BTL_POS_CENTER    = 16,
};

enum BattleVars {
    BTL_VAR_DuplighostCopyFlags         = 0, // used by duplighost
    BTL_VAL_Duplighost_HasCopied        = 0x4,
    BTL_VAR_HyperSync                   = 1,
    BTL_VAL_HyperSync_None              = 0,
    BTL_VAL_HyperSync_Done              = 1,
    BTL_VAL_HyperSync_Active            = 2,
    // index of the last enemy boosted by a magikoopa
    // intended to prevent multiple boosts for the same actor in the same turn
    // selected enemies go from left to right and are reset if none are found
    BTL_VAR_Magikoopa_LastIndexBoosted  = 2,
    BTL_VAR_LastCopiedPartner           = 3, // used by duplighost
    BTL_VAR_KoopatrolSummonCount_0      = 4, // count summons from Koopatrol and 'children' originally from column 0
    BTL_VAR_KoopatrolSummonCount_1      = 5, // count summons from Koopatrol and 'children' originally from column 1
    BTL_VAR_KoopatrolSummonCount_2      = 6, // count summons from Koopatrol and 'children' originally from column 2
    BTL_VAR_KoopatrolSummonCount_3      = 7, // count summons from Koopatrol and 'children' originally from column 3
};

// document special actor vars referenced from other actors
enum CommonActorVars {
    AVAR_DryBones_Collapsed             = 8,
    AVAR_SpearGuy_Generation            = 1,
    AVAR_JungleFuzzy_Generation         = 0,
};

extern s32 bActorNames[];

typedef struct BattleMoveEntry {
    /* 0x00 */ u8* romStart;
    /* 0x04 */ u8* romEnd;
    /* 0x08 */ u8* vramStart;
    /* 0x0C */ EvtScript* mainScript;
} BattleMoveEntry; // size = 0x10

#define BTL_MOVE(name, script) \
{ \
    .romStart   = battle_move_##name##_ROM_START, \
    .romEnd     = battle_move_##name##_ROM_END, \
    .vramStart  = battle_move_##name##_VRAM, \
    .mainScript = &battle_move_##name##_##script \
}

#define BTL_ITEM(name) \
{ \
    .romStart   = name##_ROM_START, \
    .romEnd     = name##_ROM_END, \
    .vramStart  = name##_VRAM, \
    .mainScript = &battle_item_##name##_##EVS_UseItem \
}

typedef struct ActorBlueprint {
    /* 0x00 */ s32 flags;
    /* 0x04 */ char unk_04;
    /* 0x05 */ u8 type;
    /* 0x06 */ u8 level;
    /* 0x07 */ u8 maxHP;
    /* 0x08 */ s16 partCount;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ struct ActorPartBlueprint* partsData;
    /* 0x10 */ EvtScript* initScript;
    /* 0x14 */ s32* statusTable;
    /* 0x18 */ u8 escapeChance;
    /* 0x19 */ u8 airLiftChance;
    /* 0x1A */ u8 hurricaneChance;
    /* 0x1B */ u8 spookChance;
    /* 0x1C */ u8 upAndAwayChance;
    /* 0x1D */ u8 spinSmashReq;
    /* 0x1E */ u8 powerBounceChance;
    /* 0x1F */ u8 coinReward;
    /* 0x20 */ Vec2b size;
    /* 0x22 */ Vec2b healthBarOffset;
    /* 0x24 */ Vec2b statusIconOffset;
    /* 0x26 */ Vec2b statusTextOffset;
} ActorBlueprint; // size = 0x28

typedef struct FormationRow {
    /* 0x00 */ ActorBlueprint* actor;
    /* 0x04 */ union {
                   s32    index;
                   Vec3i* vec;
               } home;
    /* 0x08 */ s32 priority; ///< Actors with higher priority values take their turn first.
    /* 0x0C */ s32 var0;
    /* 0x10 */ s32 var1;
    /* 0x14 */ s32 var2;
    /* 0x18 */ s32 var3;
} FormationRow; // size = 0x1C * n

typedef FormationRow Formation[];

typedef struct StaticFormationActor {
    /* 0x00 */ char unk_00[0x4];
} StaticFormationActor; // size = ??

typedef struct StaticFormationEntry {
    /* 0x00 */ char* sjisName;
    /* 0x04 */ s32 numActors;
    /* 0x08 */ StaticFormationActor* actors;
    /* 0x0C */ char* stageName;
    /* 0x10 */ char unk_10[0x4];
} StaticFormationEntry; // size = 0x20

typedef struct Stage {
    /* 0x00 */ char* texture;
    /* 0x04 */ const char* shape;
    /* 0x08 */ const char* hit;
    /* 0x0C */ EvtScript* preBattle;        // sets BattleStatus::controlScript on battle start
    /* 0x10 */ EvtScript* postBattle;       // sets BattleStatus::controlScript on battle end
    /* 0x14 */ char* bg;
    /* 0x18 */ s32* foregroundModelList;
    /* 0x1C */ s32 stageEnemyCount;         // number of enemies in the stageFormation
    /* 0x20 */ Formation* stageFormation;   // extra enemies native to this stage
    /* 0x24 */ s32 stageEnemyChance;        // 1/(N+1) chance for stageFormation enemies to spawn
} Stage; // size = 0x28

/// Zero-terminated.
typedef struct Battle {
    /* 0x00 */ const char* name; ///< Debug SJIS name.
    /* 0x04 */ s32 formationSize;
    /* 0x08 */ Formation* formation;
    /* 0x0C */ Stage* stage;
    /* 0x10 */ EvtScript* onBattleStart;    // sets BattleStatus::controlScript on battle start, overrides Stage::preBattle
} Battle; // size = 0x14

typedef Battle BattleList[];

/// Zero-terminated.
typedef struct StageListRow {
    /* 0x00 */ const char* name; ///< Map ID.
    /* 0x04 */ Stage* stage;
} StageListRow; // size = 0x08

typedef StageListRow StageList[];

typedef struct BattleArea {
    /* 0x00 */ char* name; ///< JP debug name.
    /* 0x04 */ void* dmaStart;
    /* 0x08 */ void* dmaEnd;
    /* 0x0C */ void* dmaDest;
    /* 0x10 */ BattleList* battles;
    /* 0x14 */ StageList* stages;
    /* 0x18 */ s32 unused_18;
    /* 0x1C */ DmaTable* dmaTable;
} BattleArea; // size = 0x20

extern BattleArea gBattleAreas[0x30];

#define BATTLE(formation, stage, name) { name, ARRAY_COUNT(formation), (Formation*) formation, &stage }
#define BATTLE_WITH_SCRIPT(formation, stage, script, name) { name, ARRAY_COUNT(formation), (Formation*) formation, &stage, &script }

#define ACTOR_BY_IDX(_name, _idx, _priority, args...) { .actor = &_name, .home = { .index = _idx }, .priority = _priority, args }
#define ACTOR_BY_POS(_name, _pos, _priority, args...) { .actor = &_name, .home = { .vec = &_pos }, .priority = _priority, args }

#define STAGE(_name, _stage) { .name = _name, .stage = &_stage }

typedef struct ActorSounds {
    /* 0x00 */ s32 walk[2];
    /* 0x08 */ s32 fly[2];
    /* 0x10 */ s32 jump;
    /* 0x14 */ s32 hurt;
    /* 0x18 */ s16 delay[2]; ///< Number of frames to wait between walk/fly sounds. Negative values are in distance.
} ActorSounds; // size = 0x1C

extern ActorSounds bActorSoundTable[];

typedef struct ActorOffsets {
    /* 0x00 */ Vec3b tattleCam;
    /* 0x03 */ s8 shadow;
} ActorOffsets; // size = 0x04

// TODO look into making options here better. it's really an array of 5 substructs, each having an [8][2] array
typedef struct PlayerCelebrationAnimOptions {
    /* 0x00 */ s16 randomChance;
    /* 0x02 */ s16 hpBasedChance;
    /* 0x04 */ s32 options[80];
} PlayerCelebrationAnimOptions; // size = 0x8

extern Battle* gCurrentBattlePtr;

extern ActorOffsets bActorOffsets[];

void func_80072BCC(s32 arg0);
void load_demo_battle(u32 index);
Actor* create_actor(Formation formation);

#define EXEC_DEATH_NO_SPINNING -12345
#define ACTOR_API_SKIP_ARG -12345678

#define DANGER_THRESHOLD  5
#define PERIL_THRESHOLD   1

#endif
