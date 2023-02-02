#ifndef _BATTLE_BATTLE_H_
#define _BATTLE_BATTLE_H_

#include "common.h"
#include "message_ids.h"

enum BattleAreaIDs {
    BTL_AREA_KMR_PART_1         = 0x00,
    BTL_AREA_KMR_PART_2         = 0x01,
    BTL_AREA_KMR_PART_3         = 0x02,
    BTL_AREA_MAC                = 0x03,
    BTL_AREA_HOS                = 0x04,
    BTL_AREA_NOK                = 0x05,
    BTL_AREA_TRD_PART_1         = 0x06,
    BTL_AREA_TRD_PART_2         = 0x07,
    BTL_AREA_TRD_PART_3         = 0x08,
    BTL_AREA_IWA                = 0x09,
    BTL_AREA_SBK                = 0x0A,
    BTL_AREA_ISK_PART_1         = 0x0B,
    BTL_AREA_ISK_PART_2         = 0x0C,
    BTL_AREA_MIM                = 0x0D,
    BTL_AREA_ARN                = 0x0E,
    BTL_AREA_DGB                = 0x0F,
    BTL_AREA_OMO                = 0x10,
    BTL_AREA_OMO2               = 0x11,
    BTL_AREA_OMO3               = 0x12,
    BTL_AREA_KGR                = 0x13,
    BTL_AREA_JAN                = 0x14,
    BTL_AREA_JAN2               = 0x15,
    BTL_AREA_KZN                = 0x16,
    BTL_AREA_KZN2               = 0x17,
    BTL_AREA_FLO                = 0x18,
    BTL_AREA_FLO2               = 0x19,
    BTL_AREA_TIK                = 0x1A,
    BTL_AREA_TIK2               = 0x1B,
    BTL_AREA_TIK3               = 0x1C,
    BTL_AREA_SAM                = 0x1D,
    BTL_AREA_SAM2               = 0x1E,
    BTL_AREA_PRA                = 0x1F,
    BTL_AREA_PRA2               = 0x20,
    BTL_AREA_PRA3               = 0x21,
    BTL_AREA_KPA                = 0x22,
    BTL_AREA_KPA2               = 0x23,
    BTL_AREA_KPA3               = 0x24,
    BTL_AREA_KPA4               = 0x25,
    BTL_AREA_KKJ                = 0x26,
    BTL_AREA_DIG                = 0x27,
    BTL_AREA_UNUSED_28          = 0x28,
    BTL_AREA_OMO2_1             = 0x29,
    BTL_AREA_OMO2_2             = 0x2A,
    BTL_AREA_OMO2_3             = 0x2B,
    BTL_AREA_OMO2_4             = 0x2C,
    BTL_AREA_OMO2_5             = 0x2D,
    BTL_AREA_OMO2_6             = 0x2E,
};

typedef enum ActorType {
    ACTOR_TYPE_RED_GOOMBA                  = 0x00,
    ACTOR_TYPE_RED_PARAGOOMBA              = 0x01,
    ACTOR_TYPE_GLOOMBA                     = 0x02,
    ACTOR_TYPE_PARAGLOOMBA                 = 0x03,
    ACTOR_TYPE_SPIKED_GLOOMBA              = 0x04,
    ACTOR_TYPE_DARK_KOOPA                  = 0x05,
    ACTOR_TYPE_DARK_PARATROOPA             = 0x06,
    ACTOR_TYPE_GOOMBA                      = 0x07,
    ACTOR_TYPE_PARAGOOMBA                  = 0x08,
    ACTOR_TYPE_SPIKED_GOOMBA               = 0x09,
    ACTOR_TYPE_FUZZY                       = 0x0A,
    ACTOR_TYPE_KOOPA_TROOPA                = 0x0B,
    ACTOR_TYPE_PARATROOPA                  = 0x0C,
    ACTOR_TYPE_BOB_OMB                     = 0x0D,
    ACTOR_TYPE_BOB_OMB_DUP                 = 0x0E,
    ACTOR_TYPE_BULLET_BILL                 = 0x0F,
    ACTOR_TYPE_BILL_BLASTER                = 0x10,
    ACTOR_TYPE_CLEFT                       = 0x11,
    ACTOR_TYPE_MONTY_MOLE                  = 0x12,
    ACTOR_TYPE_BANDIT                      = 0x13,
    ACTOR_TYPE_POKEY                       = 0x14,
    ACTOR_TYPE_POKEY_MUMMY                 = 0x15,
    ACTOR_TYPE_SWOOPER                     = 0x16,
    ACTOR_TYPE_BUZZY_BEETLE                = 0x17,
    ACTOR_TYPE_STONE_CHOMP                 = 0x18,
    ACTOR_TYPE_PIRANHA_PLANT               = 0x19,
    ACTOR_TYPE_FOREST_FUZZY                = 0x1A,
    ACTOR_TYPE_HYPER_GOOMBA                = 0x1B,
    ACTOR_TYPE_HYPER_PARAGOOMBA            = 0x1C,
    ACTOR_TYPE_HYPER_CLEFT                 = 0x1D,
    ACTOR_TYPE_CLUBBA                      = 0x1E,
    ACTOR_TYPE_SHY_GUY                     = 0x1F,
    ACTOR_TYPE_GROOVE_GUY                  = 0x20,
    ACTOR_TYPE_SKY_GUY                     = 0x21,
    ACTOR_TYPE_MEDI_GUY                    = 0x22,
    ACTOR_TYPE_PYRO_GUY                    = 0x23,
    ACTOR_TYPE_SPY_GUY                     = 0x24,
    ACTOR_TYPE_FUZZIPEDE                   = 0x25,
    ACTOR_TYPE_HURT_PLANT                  = 0x26,
    ACTOR_TYPE_M_BUSH                      = 0x27,
    ACTOR_TYPE_AQUA_FUZZY                  = 0x28,
    ACTOR_TYPE_JUNGLE_FUZZY                = 0x29,
    ACTOR_TYPE_SPEAR_GUY                   = 0x2A,
    ACTOR_TYPE_LAVA_BUBBLE                 = 0x2B,
    ACTOR_TYPE_SPIKE_TOP                   = 0x2C,
    ACTOR_TYPE_PUTRID_PIRANHA              = 0x2D,
    ACTOR_TYPE_LAKITU                      = 0x2E,
    ACTOR_TYPE_SPINY                       = 0x2F,
    ACTOR_TYPE_MONTY_MOLE_BOSS             = 0x30,
    ACTOR_TYPE_BZZAP                       = 0x31,
    ACTOR_TYPE_CRAZEE_DAYZEE               = 0x32,
    ACTOR_TYPE_AMAZY_DAYZEE                = 0x33,
    ACTOR_TYPE_RUFF_PUFF                   = 0x34,
    ACTOR_TYPE_SPIKE                       = 0x35,
    ACTOR_TYPE_GULPIT                      = 0x36,
    ACTOR_TYPE_GULPIT_ROCKS                = 0x37,
    ACTOR_TYPE_WHITE_CLUBBA                = 0x38,
    ACTOR_TYPE_FROST_PIRANHA               = 0x39,
    ACTOR_TYPE_SWOOPULA                    = 0x3A,
    ACTOR_TYPE_DUPLIGHOST                  = 0x3B,
    ACTOR_TYPE_GHOST_GOOMBARIO             = 0x3C,
    ACTOR_TYPE_GHOST_KOOPER                = 0x3D,
    ACTOR_TYPE_GHOST_BOMBETTE              = 0x3E,
    ACTOR_TYPE_GHOST_PARAKARRY             = 0x3F,
    ACTOR_TYPE_GHOST_BOW                   = 0x40,
    ACTOR_TYPE_GHOST_WATT                  = 0x41,
    ACTOR_TYPE_GHOST_SUSHIE                = 0x42,
    ACTOR_TYPE_GHOST_LAKILESTER            = 0x43,
    ACTOR_TYPE_ALBINO_DINO                 = 0x44,
    ACTOR_TYPE_EMBER                       = 0x45,
    ACTOR_TYPE_BONY_BEETLE                 = 0x46,
    ACTOR_TYPE_DRY_BONES                   = 0x47,
    ACTOR_TYPE_DRY_BONES2                  = 0x48,
    ACTOR_TYPE_BOMBSHELL_BLASTER           = 0x49,
    ACTOR_TYPE_BOMBSHELL_BILL              = 0x4A,
    ACTOR_TYPE_HAMMER_BROS                 = 0x4B,
    ACTOR_TYPE_KOOPATROL                   = 0x4C,
    ACTOR_TYPE_MAGIKOOPA                   = 0x4D,
    ACTOR_TYPE_FLYING_MAGIKOOPA            = 0x4E,
    ACTOR_TYPE_MAGICLONE                   = 0x4F,
    ACTOR_TYPE_FLYING_MAGICLONE            = 0x50,
    ACTOR_TYPE_RED_MAGIKOOPA               = 0x51,
    ACTOR_TYPE_FLYING_RED_MAGIKOOPA        = 0x52,
    ACTOR_TYPE_GREEN_MAGIKOOPA             = 0x53,
    ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA      = 0x54,
    ACTOR_TYPE_YELLOW_MAGIKOOPA            = 0x55,
    ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA     = 0x56,
    ACTOR_TYPE_GRAY_MAGIKOOPA              = 0x57,
    ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA       = 0x58,
    ACTOR_TYPE_WHITE_MAGIKOOPA             = 0x59,
    ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA      = 0x5A,

    ACTOR_TYPE_UNUSED_5B                   = 0x5B,
    ACTOR_TYPE_UNUSED_5C                   = 0x5C,
    ACTOR_TYPE_UNUSED_5D                   = 0x5D,
    ACTOR_TYPE_UNUSED_5E                   = 0x5E,
    ACTOR_TYPE_UNUSED_5F                   = 0x5F,
    ACTOR_TYPE_UNUSED_60                   = 0x60,
    ACTOR_TYPE_UNUSED_61                   = 0x61,
    ACTOR_TYPE_UNUSED_62                   = 0x62,
    ACTOR_TYPE_UNUSED_63                   = 0x63,
    ACTOR_TYPE_UNUSED_64                   = 0x64,
    ACTOR_TYPE_UNUSED_65                   = 0x65,
    ACTOR_TYPE_UNUSED_66                   = 0x66,
    ACTOR_TYPE_UNUSED_67                   = 0x67,
    ACTOR_TYPE_UNUSED_68                   = 0x68,
    ACTOR_TYPE_UNUSED_69                   = 0x69,
    ACTOR_TYPE_UNUSED_6A                   = 0x6A,

    ACTOR_TYPE_MONTY_HOLE                  = 0x6B,

    ACTOR_TYPE_UNUSED_6C                   = 0x6C,
    ACTOR_TYPE_UNUSED_6D                   = 0x6D,

    ACTOR_TYPE_PLAYER                      = 0x6E,
    ACTOR_TYPE_GOOMBARIO                   = 0x6F,
    ACTOR_TYPE_KOOPER                      = 0x70,
    ACTOR_TYPE_BOMBETTE                    = 0x71,
    ACTOR_TYPE_PARAKARRY                   = 0x72,
    ACTOR_TYPE_BOW                         = 0x73,
    ACTOR_TYPE_WATT                        = 0x74,
    ACTOR_TYPE_SUSHIE                      = 0x75,
    ACTOR_TYPE_LAKILESTER                  = 0x76,
    ACTOR_TYPE_TWINK                       = 0x77,

    ACTOR_TYPE_UNUSED_78                   = 0x78,
    ACTOR_TYPE_UNUSED_79                   = 0x79,

    ACTOR_TYPE_THE_MASTER_1                = 0x7A,
    ACTOR_TYPE_THE_MASTER_2                = 0x7B,
    ACTOR_TYPE_THE_MASTER_3                = 0x7C,
    ACTOR_TYPE_CHAN                        = 0x7D,
    ACTOR_TYPE_LEE                         = 0x7E,
    ACTOR_TYPE_LEE_GOOMBARIO               = 0x7F,
    ACTOR_TYPE_LEE_KOOPER                  = 0x80,
    ACTOR_TYPE_LEE_BOMBETTE                = 0x81,
    ACTOR_TYPE_LEE_PARAKARRY               = 0x82,
    ACTOR_TYPE_LEE_BOW                     = 0x83,
    ACTOR_TYPE_LEE_WATT                    = 0x84,
    ACTOR_TYPE_LEE_SUSHIE                  = 0x85,
    ACTOR_TYPE_LEE_LAKILESTER              = 0x86,
    ACTOR_TYPE_KAMMY_KOOPA                 = 0x87,
    ACTOR_TYPE_JR_TROOPA1                  = 0x88,
    ACTOR_TYPE_JR_TROOPA2                  = 0x89,
    ACTOR_TYPE_JR_TROOPA3                  = 0x8A,
    ACTOR_TYPE_JR_TROOPA4                  = 0x8B,
    ACTOR_TYPE_JR_TROOPA5                  = 0x8C,
    ACTOR_TYPE_JR_TROOPA6                  = 0x8D,
    ACTOR_TYPE_JR_TROOPA_DUP1              = 0x8E,
    ACTOR_TYPE_JR_TROOPA_DUP2              = 0x8F,
    ACTOR_TYPE_BLUE_GOOMBA_BOSS            = 0x90,
    ACTOR_TYPE_RED_GOOMBA_BOSS             = 0x91,
    ACTOR_TYPE_GOOMBA_KING                 = 0x92,
    ACTOR_TYPE_GOOMNUT_TREE                = 0x93,
    ACTOR_TYPE_GOOMBARIO_TUTOR1            = 0x94,
    ACTOR_TYPE_MAGIKOOPA_BOSS              = 0x95,
    ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS       = 0x96,
    ACTOR_TYPE_MAGIKOOPA_DUP1              = 0x97,
    ACTOR_TYPE_MAGIKOOPA_DUP2              = 0x98,
    ACTOR_TYPE_FAKE_BOWSER                 = 0x99,
    ACTOR_TYPE_KOOPA_BROS                  = 0x9A,
    ACTOR_TYPE_GREEN_NINJAKOOPA            = 0x9B,
    ACTOR_TYPE_RED_NINJAKOOPA              = 0x9C,
    ACTOR_TYPE_BLUE_NINJAKOOPA             = 0x9D,
    ACTOR_TYPE_YELLOW_NINJAKOOPA           = 0x9E,
    ACTOR_TYPE_ELDSTAR                     = 0x9F,
    ACTOR_TYPE_BUZZAR                      = 0xA0,
    ACTOR_TYPE_TUTANKOOPA                  = 0xA1,
    ACTOR_TYPE_CHOMP                       = 0xA2,
    ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE     = 0xA3,
    ACTOR_TYPE_TUBBA_BLUBBA                = 0xA4,
    ACTOR_TYPE_TUBBA_HEART                 = 0xA5,
    ACTOR_TYPE_STILT_GUY                   = 0xA6,
    ACTOR_TYPE_SHY_STACK                   = 0xA7,
    ACTOR_TYPE_SHY_SQUAD                   = 0xA8,
    ACTOR_TYPE_GENERAL_GUY                 = 0xA9,
    ACTOR_TYPE_TOY_TANK                    = 0xAA,
    ACTOR_TYPE_LIGHT_BULB                  = 0xAB,
    ACTOR_TYPE_SIGNAL_GUY                  = 0xAC,
    ACTOR_TYPE_SHY_SQUAD_DUP               = 0xAD,
    ACTOR_TYPE_SHY_GUY_DUP                 = 0xAE,
    ACTOR_TYPE_ANTI_GUY                    = 0xAF,
    ACTOR_TYPE_ANTI_GUY_DUP                = 0xB0,
    ACTOR_TYPE_BIG_LANTERN_GHOST           = 0xB1,
    ACTOR_TYPE_GOOMBA_KING_DUP             = 0xB2,
    ACTOR_TYPE_LAVA_PIRANHA_PHASE_1        = 0xB3,
    ACTOR_TYPE_LAVA_PIRANHA_PHASE_2        = 0xB4,
    ACTOR_TYPE_LAVA_BUD_PHASE_1            = 0xB5,
    ACTOR_TYPE_LAVA_BUD_PHASE_2            = 0xB6,
    ACTOR_TYPE_PETIT_PIRANHA               = 0xB7,
    ACTOR_TYPE_PETIT_PIRANHA_BOMB          = 0xB8,
    ACTOR_TYPE_KENT_C_KOOPA                = 0xB9,
    ACTOR_TYPE_HUFF_N_PUFF                 = 0xBA,
    ACTOR_TYPE_TUFF_PUFF                   = 0xBB,
    ACTOR_TYPE_MONSTAR                     = 0xBC,
    ACTOR_TYPE_CRYSTAL_KING                = 0xBD,
    ACTOR_TYPE_CRYSTAL_CLONE               = 0xBE,
    ACTOR_TYPE_CRYSTAL_BIT                 = 0xBF,
    ACTOR_TYPE_INTRO_BOWSER                = 0xC0,
    ACTOR_TYPE_BOWSER_PHASE_1              = 0xC1,
    ACTOR_TYPE_BOWSER_DUP1                 = 0xC2,
    ACTOR_TYPE_BOWSER_PHASE_2              = 0xC3,
    ACTOR_TYPE_BOWSER_DUP2                 = 0xC4,
    ACTOR_TYPE_BOWSER_PHASE_3              = 0xC5,
    ACTOR_TYPE_BOWSER_DUP3                 = 0xC6,
    ACTOR_TYPE_BLOOPER                     = 0xC7,
    ACTOR_TYPE_ELECTRO_BLOOPER1            = 0xC8,
    ACTOR_TYPE_ELECTRO_BLOOPER2            = 0xC9,
    ACTOR_TYPE_SUPER_BLOOPER1              = 0xCA,
    ACTOR_TYPE_SUPER_BLOOPER2              = 0xCB,
    ACTOR_TYPE_BLOOPER_BABY                = 0xCC,
    ACTOR_TYPE_LAKILESTER_DUP              = 0xCD,
    ACTOR_TYPE_SLOT_MACHINE_START          = 0xCE,
    ACTOR_TYPE_SLOT_MACHINE_STOP           = 0xCF,
    ACTOR_TYPE_WHACKA                      = 0xD0,
    ACTOR_TYPE_SLOT_MACHINE_START_DUP1     = 0xD1,
    ACTOR_TYPE_SLOT_MACHINE_START_DUP2     = 0xD2,
    ACTOR_TYPE_SLOT_MACHINE_START_DUP3     = 0xD3,
    ACTOR_TYPE_COUNT                       = 0xD4,
} ActorType;

extern s32 bActorNames[];

#define BTL_AREA(id) \
    .dmaStart = battle_##id##_ROM_START, \
    .dmaEnd = battle_##id##_ROM_END, \
    .dmaDest = battle_##id##_VRAM

typedef struct ActorBlueprint {
    /* 0x00 */ s32 flags;
    /* 0x04 */ char unk_04;
    /* 0x05 */ u8 type;
    /* 0x06 */ u8 level;
    /* 0x07 */ u8 maxHP;
    /* 0x08 */ s16 partCount;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ struct ActorPartBlueprint* partsData;
    /* 0x10 */ EvtScript* takeTurnScript;
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
    /* 0x22 */ Vec2b hpBarOffset;
    /* 0x24 */ Vec2b statusIconOffset;
    /* 0x26 */ Vec2b statusMessageOffset;
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
    /* 0x24 */ s32 stageEnemyChance;        // chance for stageFormation enemies to spawn: N = 0 means always, N > 0 is 1/N chance
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
    /* 0x00 */ const char* id; ///< Map ID.
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

#define BATTLE(name, formation, stage) { name, ARRAY_COUNT(formation), (Formation*) formation, stage }
#define BATTLE_WITH_SCRIPT(name, formation, stage, script) { name, ARRAY_COUNT(formation), (Formation*) formation, stage, script }

// TODO: enum for home position (0..3 are floor, 4..7 are air, etc.)

typedef struct ActorSounds {
    /* 0x00 */ s32 walk[2];
    /* 0x08 */ s32 fly[2];
    /* 0x10 */ s32 jump;
    /* 0x14 */ s32 hurt;
    /* 0x18 */ s16 delay[2]; ///< Number of frames to wait between walk/fly sounds. Negative values are in distance.
} ActorSounds; // size = 0x1C

extern ActorSounds bActorSoundTable[ACTOR_TYPE_COUNT];

typedef struct ActorOffsets {
    /* 0x00 */ Vec3b tattleCam;
    /* 0x03 */ s8 shadow;
} ActorOffsets; // size = 0x04

extern Battle* gCurrentBattlePtr;

extern ActorOffsets bActorOffsets[ACTOR_TYPE_COUNT];

void func_80072BCC(s32 arg0);
void load_demo_battle(u32 index);
Actor* create_actor(Formation formation);

#ifdef SHIFT
#define AUX_DATA_ADDR_0 world_model_anim_kzn_01_VRAM // (picked the first overlay among those with this address)
#define AUX_DATA_ADDR_1 battle_area_omo2_1_VRAM // (picked the first overlay among those with this address)
#define AUX_DATA_ADDR_2 0x8022E000 // TODO shiftability
#define AUX_DATA_ADDR_3 0x8022C000 // TODO shiftability
#else
#define AUX_DATA_ADDR_0 0x80234000
#define AUX_DATA_ADDR_1 0x80231000
#define AUX_DATA_ADDR_2 0x8022E000
#define AUX_DATA_ADDR_3 0x8022C000
#endif

#endif
