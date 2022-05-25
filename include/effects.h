#ifndef _EFFECTS_H_
#define _EFFECTS_H_

#include "types.h"
#include "common_structs.h"

enum EffectID {
    EFFECT_00 = 0x00,
    EFFECT_BIG_SMOKE_PUFF,
    EFFECT_02, // unused
    EFFECT_03, // unused
    EFFECT_04, // unused
    EFFECT_05, // unused
    EFFECT_LANDING_DUST,
    EFFECT_WALKING_DUST,
    EFFECT_FLOWER_SPLASH,
    EFFECT_FLOWER_TRAIL,
    EFFECT_CLOUD_PUFF,
    EFFECT_CLOUD_TRAIL,
    EFFECT_FOOTPRINT,
    EFFECT_FLOATING_FLOWER,
    EFFECT_SNOWFLAKE,
    EFFECT_STAR,
    EFFECT_EMOTE,
    EFFECT_SPARKLES,
    EFFECT_SHAPE_SPELL,
    EFFECT_GATHER_ENERGY_PINK,
    EFFECT_DROP_LEAVES,
    EFFECT_DUST,
    EFFECT_SHATTERING_STONES,
    EFFECT_SMOKE_RING,
    EFFECT_DAMAGE_STARS,
    EFFECT_EXPLOSION,
    EFFECT_LENS_FLARE,
    EFFECT_GOT_ITEM_OUTLINE,
    EFFECT_SPIKY_WHITE_AURA,
    EFFECT_SMOKE_IMPACT,
    EFFECT_DAMAGE_INDICATOR,
    EFFECT_PURPLE_RING,
    EFFECT_FLAME,
    EFFECT_STARS_BURST,
    EFFECT_STARS_SHIMMER,
    EFFECT_RISING_BUBBLE,
    EFFECT_RING_BLAST,
    EFFECT_SHOCKWAVE,
    EFFECT_MUSIC_NOTE,
    EFFECT_SMOKE_BURST,
    EFFECT_SWEAT,
    EFFECT_SLEEP_BUBBLE,
    EFFECT_2A, // unused
    EFFECT_WINDY_LEAVES,
    EFFECT_FALLING_LEAVES,
    EFFECT_STARS_SPREAD,
    EFFECT_STEAM_BURST,
    EFFECT_STARS_ORBITING,
    EFFECT_BIG_SNOWFLAKES,
    EFFECT_DEBUFF,
    EFFECT_GREEN_IMPACT,
    EFFECT_RADIAL_SHIMMER,
    EFFECT_ENDING_DECALS,
    EFFECT_LIGHT_RAYS,
    EFFECT_LIGHTNING,
    EFFECT_FIRE_BREATH,
    EFFECT_SHIMMER_BURST,
    EFFECT_ENERGY_SHOCKWAVE,
    EFFECT_SHIMMER_WAVE,
    EFFECT_AURA,
    EFFECT_3C,
    EFFECT_3D,
    EFFECT_BLAST,
    EFFECT_FIRE_FLOWER,
    EFFECT_RECOVER,
    EFFECT_DISABLE_X,
    EFFECT_BOMBETTE_BREAKING,
    EFFECT_FIREWORK,
    EFFECT_CONFETTI,
    EFFECT_SNOWFALL,
    EFFECT_46,
    EFFECT_GATHER_MAGIC,
    EFFECT_ATTACK_RESULT_TEXT,
    EFFECT_SMALL_GOLD_SPARKLE,
    EFFECT_FLASHING_BOX_SHOCKWAVE,
    EFFECT_BALLOON,
    EFFECT_FLOATING_ROCK,
    EFFECT_CHOMP_DROP,
    EFFECT_QUIZMO_STAGE,
    EFFECT_RADIATING_ENERGY_ORB,
    EFFECT_QUIZMO_ANSWER, // unused
    EFFECT_MOTION_BLUR_FLAME,
    EFFECT_ENERGY_ORB_WAVE,
    EFFECT_MERLIN_HOUSE_STARS,
    EFFECT_QUIZMO_AUDIENCE, // unused
    EFFECT_BUTTERFLIES,
    EFFECT_STAT_CHANGE,
    EFFECT_SNAKING_STATIC,
    EFFECT_THUNDERBOLT_RING,
    EFFECT_SQUIRT,
    EFFECT_WATER_BLOCK,
    EFFECT_WATERFALL,
    EFFECT_WATER_FOUNTAIN,
    EFFECT_UNDERWATER,
    EFFECT_LIGHTNING_BOLT,
    EFFECT_WATER_SPLASH,
    EFFECT_SNOWMAN_DOLL,
    EFFECT_FRIGHT_JAR,
    EFFECT_STOP_WATCH,
    EFFECT_63,
    EFFECT_THROW_SPINY,
    EFFECT_65,
    EFFECT_TUBBA_HEART_ATTACK,
    EFFECT_WHIRLWIND,
    EFFECT_RED_IMPACT,
    EFFECT_FLOATING_CLOUD_PUFF,
    EFFECT_6A, // unused
    EFFECT_ENERGY_IN_OUT,
    EFFECT_TATTLE_WINDOW,
    EFFECT_SHINY_FLARE,
    EFFECT_HUFF_PUFF_BREATH,
    EFFECT_COLD_BREATH,
    EFFECT_EMBERS,
    EFFECT_HIEROGLYPHS,
    EFFECT_MISC_PARTICLES,
    EFFECT_STATIC_STATUS,
    EFFECT_MOVING_CLOUD,
    EFFECT_75,
    EFFECT_76, // unused
    EFFECT_FIREWORK_ROCKET,
    EFFECT_PEACH_STAR_BEAM,
    EFFECT_CHAPTER_CHANGE,
    EFFECT_ICE_SHARD,
    EFFECT_SPIRIT_CARD,
    EFFECT_LIL_OINK,
    EFFECT_SOMETHING_ROTATING,
    EFFECT_BREAKING_JUNK,
    EFFECT_PARTNER_BUFF,
    EFFECT_QUIZMO_ASSISTANT,
    EFFECT_ICE_PILLAR,
    EFFECT_SUN,
    EFFECT_STAR_SPIRITS_ENERGY,
    EFFECT_PINK_SPARKLES,
    EFFECT_STAR_OUTLINE,
    EFFECT_86,
};

typedef struct StarSpiritsEnergyFXData {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[0x20];
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ char unk_38[0x38];
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ s32 unk_74;
} StarSpiritsEnergyFXData; // size = ?

typedef struct SpiritCardFXData {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ s8 unk_34;
} SpiritCardFXData; // ?

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

typedef struct BigSnowflakeFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
} BigSnowflakeFXData; // size = 0x30

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

typedef struct FootprintFXData {
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
} FootprintFXData; // size = 0x98

typedef struct FloatingFlowerFXData {
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
} FloatingFlowerFXData; // size = 0x48

typedef struct SnowflakeFXData {
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
} SnowflakeFXData; // size = 0x2C

typedef struct StarFXData {
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
} StarFXData; // size = 0x250

typedef struct EmoteFXData {
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
} EmoteFXData; // size = 0x40

typedef struct AttackResultTextFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ char unk_2C[0x4];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
} AttackResultTextFXData; // size = 0x38

typedef struct SmallGoldSparkleFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 unk_20;
} SmallGoldSparkleFXData; // size = 0x24

typedef struct BalloonFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} BalloonFXData; // size = 0x24

typedef struct DebuffFXData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ u8 unk_38;
    /* 0x39 */ u8 unk_39;
    /* 0x3A */ u8 unk_3A;
    /* 0x3B */ u8 unk_3B;
    /* 0x3C */ u8 unk_3C;
    /* 0x3D */ u8 unk_3D;
    /* 0x3E */ char unk_3E[2];
} DebuffFXData; // size = 0x40

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

typedef struct SleepBubbleFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 timeLeft;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ Vec2f points[20];
    /* 0xC4 */ f32 unk_C4;
    /* 0xC8 */ f32 unk_C8;
} SleepBubbleFXData; // size = 0xCC

typedef struct WaterFountainFXData {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ char unk_24[0x4];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ char unk_34[0x4];
    /* 0x38 */ f32 unk_38;
} WaterFountainFXData; // size = ?

typedef struct AuraFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 primA;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
               union {
                   s32 s;
                   f32 f;
               } unk_64;
    /* 0x68 */ u8 primR;
    /* 0x69 */ u8 primG;
    /* 0x6A */ u8 primB;
    /* 0x6B */ u8 envR;
    /* 0x6C */ u8 envG;
    /* 0x6D */ u8 engB;
    /* 0x6E */ u8 engA;
} AuraFXData; // size = 0x70

typedef struct BlastFXData {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 timeLeft;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
} BlastFXData; // size = 0x2C

typedef struct FireFlowerFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ Vec3i unk_40;
} FireFlowerFXData; // size = 0x4C

typedef struct DisableXFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 alpha;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 scale;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ s32 unk_44;
} DisableXFXData; // size = 0x48

typedef struct FireBreathFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ s32 numChildren;
    /* 0x08 */ s32 spawnDelay;
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ Vec3f initPos;
    /* 0x24 */ Vec3f endPos;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 scale;
    /* 0x3C */ f32 scaleChangeFactor;
    /* 0x40 */ s32 alpha;
    /* 0x44 */ s32 maxLifetime;
    /* 0x48 */ s32 lifetime;
    /* 0x4C */ s32 spawnTimer;
    /* 0x50 */ Vec3f unk_50;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ s32 primR;
    /* 0x68 */ s32 primG;
    /* 0x6C */ s32 primB;
    /* 0x70 */ s32 envR;
    /* 0x74 */ s32 envG;
    /* 0x78 */ s32 envB;
} FireBreathFXData; // size = 0x7C

typedef struct DamageIndicatorFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ Vec3f unk_1C;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 alpha;
    /* 0x30 */ s32 effectDurationTimer;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 numParts;
} DamageIndicatorFXData; // size = 0x40

// seems to actually be PlayerStatus, but it's too large seemingly given the bss padding in UnkWhirlwindEffectFunc.inc.c
typedef struct EffectWhirlwindUnk {
    /* 0x00 */ char unk_00[0x28];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} EffectWhirlwindUnk;

typedef struct Effect6BFXData {
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
} Effect6BFXData; // size = 0x44

typedef struct ColdBreathFXData {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ char unk_24[0x4];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} ColdBreathFXData; // size = ?

typedef struct LightningFXData {
    /* 0x00 */ char unk_00[0x30];
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ char unk_3C[0x4];
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
} LightningFXData; // size = ?

typedef struct Effect6FFXData {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3i rotation;
    /* 0x1C */ Vec3i scale;
    /* 0x28 */ Vec3i color;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ char unk_40[0x4];
} Effect6FFXData; // size = 0x44

typedef struct MiscParticlesFXData {
    char unk_00[0x38];
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    char unk_44[0x4];
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
} MiscParticlesFXData;

typedef struct Effect46FXData {
    /* 0x00 */ char unk_00[0x24];
    /* 0x04 */ s32 unk_24;
} Effect46FXData; // size = 0x44

typedef struct ThunderboltRingFXData {
    /* 0x00 */ char unk_00[0x30];
    /* 0x30 */ s32 unk_30;
} ThunderboltRingFXData; // size = ?

// fx_quizmo_stage
typedef struct EffectDataQuizStage {
   /* 0x00 */ char unk_00[0x4];
   /* 0x04 */ s32 vanishTimer;
   /* 0x08 */ s32 lifetime;
   /* 0x10 */ Vec3f origin;
   /* 0x18 */ s32 microphoneRaiseAmt;
   /* 0x1C */ s32 rearWallRaiseAmt;
   /* 0x20 */ s32 leftWallRaiseAmt;
   /* 0x24 */ s32 rightWallRaiseAmt;
   /* 0x28 */ s32 podiumRaiseAmt;
   /* 0x2C */ s32 lightScrollAmt;
   /* 0x30 */ s32 lightScrollIncrement;
   /* 0x34 */ s32 lightScrollDelay;
   /* 0x38 */ s32 unkEffectMode;
   /* 0x3C */ s32 unk_3C; // stage hidden when == 0xFF
   /* 0x3C */ char unk_40[0x10];
} EffectDataQuizStage; // size ~ 0x50 (as allocated on heap)

// fx_quizmo_assistant
typedef struct EffectDataQuizVannaT {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ Vec3f position;
    /* 0x10 */ s32 vanishTimer;
    /* 0x14 */ s32 lifetime;
    /* 0x18 */ s32 fadeInAmt; // 0 = all-black, FF = fully-visible
    /* 0x1C */ s32 anim;
} EffectDataQuizVannaT; // size = 0x20

typedef struct EffectInstanceData {
    /* 0x00 */ s32 unk_00;
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
    /* 0x0C */ void* data;
    /* 0x10 */ struct EffectGraphics* graphics;
} EffectInstance; // size = 0x14

typedef struct StarSpiritData {
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
    /* 0x50 */ EffectInstance* unk_50;
    /* 0x54 */ EffectInstance* unk_54;
} StarSpiritData; // size = 0x58

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

enum FireBreathType {
    FIRE_BREATH_LARGE = 0,
    FIRE_BREATH_SMALL = 1,
    FIRE_BREATH_TINY  = 2,
};

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
EffectInstance* fx_footprint(f32, f32, f32, f32, f32);
EffectInstance* fx_floating_flower(s32, f32, f32, f32, s32);
EffectInstance* fx_snowflake(f32, f32, f32, s32);
void fx_star(s32, f32, f32, f32, f32, f32, f32, f32);
void fx_emote(s32, Npc*, f32, f32, f32, f32, f32, s32, s32*);
void fx_sparkles(s32, f32, f32, f32, f32);
EffectInstance* fx_shape_spell(s32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* fx_gather_energy_pink(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_drop_leaves(s32, f32, f32, f32, s32);
EffectInstance* fx_dust(s32, f32, f32, f32, s32);
EffectInstance* fx_shattering_stones(s32, f32, f32, f32, f32);
void fx_smoke_ring(s32, f32, f32, f32);
void fx_damage_stars(s32, f32, f32, f32, f32, f32, f32, s32);
void fx_explosion(s32, f32, f32, f32);
EffectInstance* fx_lens_flare(s32, f32, f32, f32, s32);
EffectInstance* fx_got_item_outline(s32, f32, f32, f32, f32, s32*);
EffectInstance* fx_spiky_white_aura(s32, f32, f32, f32, s32);
void fx_smoke_impact(s32, f32, f32, f32, f32, s32, f32, s32);
EffectInstance* fx_damage_indicator(s32, f32, f32, f32, f32, f32, s32, EffectInstance**);
EffectInstance* fx_purple_ring(s32, f32, f32, f32, f32, f32, f32, f32);
EffectInstance* fx_flame(s32, f32, f32, f32, f32, EffectInstance**);
EffectInstance* fx_stars_burst(s32, f32, f32, f32, f32, f32, s32);
void fx_stars_shimmer(s32, f32, f32, f32, f32, f32, s32, s32);
EffectInstance* fx_rising_bubble(u32, f32, f32, f32, f32);
EffectInstance* fx_ring_blast(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_shockwave(s32, f32, f32, f32);
void fx_music_note(s32, f32, f32, f32);
EffectInstance* fx_smoke_burst(s32, f32, f32, f32, f32, s32);
void fx_sweat(s32, f32 x, f32 y, f32 z, f32, f32, s32);
void fx_sleep_bubble(s32, f32, f32, f32, f32, f32, s32*);
EffectInstance* fx_2A(s32, f32, f32, f32);
EffectInstance* fx_windy_leaves(s32, f32, f32, f32);
EffectInstance* fx_falling_leaves(s32, f32, f32, f32);
void fx_stars_spread(s32, f32, f32, f32, s32, s32);
void fx_steam_burst(s32, f32, f32, f32, f32, s32);
void fx_stars_orbiting(s32, f32, f32, f32, f32, s32, EffectInstance**);
void fx_big_snowflakes(s32, f32, f32, f32);
EffectInstance* fx_debuff(s32, f32, f32, f32);
void fx_green_impact(s32, f32, f32, f32, f32);
EffectInstance* fx_radial_shimmer(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_ending_decals(s32, f32, f32, f32, f32, s32*);
EffectInstance* fx_light_rays(s32, f32, f32, f32, f32, s32*);
EffectInstance* fx_lightning(s32, f32, f32, f32, f32, f32);
EffectInstance* fx_fire_breath(s32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
EffectInstance* fx_shimmer_burst(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_energy_shockwave(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_shimmer_wave(s32, f32, f32, f32, f32, f32, s32, s32);
void fx_aura(s32, f32, f32, f32, f32, EffectInstance**);
EffectInstance* fx_3C(s32, f32, f32, f32, f32, s32*);
void fx_3D(s32, f32, f32, f32, f32, f32, f32, s32, s32*);
EffectInstance* fx_blast(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_fire_flower(s32, f32, f32, f32, s32);
EffectInstance* fx_recover(s32, f32, f32, f32, s32);
EffectInstance* fx_disable_x(s32, f32, f32, f32, s32);
EffectInstance* fx_bombette_breaking(s32, s32, s32, f32, s32, s32);
EffectInstance* fx_firework(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_confetti(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_snowfall(s32, s32);
EffectInstance* fx_46(s32, EffectWhirlwindUnk*, f32, s32);
EffectInstance* fx_gather_magic(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_attack_result_text(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_small_gold_sparkle(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_flashing_box_shockwave(s32, f32, f32, f32, f32, f32);
EffectInstance* fx_balloon(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_floating_rock(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* fx_chomp_drop(s32, f32, f32, f32, f32, s32, f32, s32, f32, s32);
EffectInstance* fx_quizmo_stage(s32, f32, f32, f32);
EffectInstance* fx_radiating_energy_orb(s32, f32, f32, f32, f32, s32);
void fx_quizmo_answer(s32, f32, f32, f32);
EffectInstance* fx_motion_blur_flame(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_energy_orb_wave(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_merlin_house_stars(s32, f32, f32, f32);
EffectInstance* fx_quizmo_audience(s32, f32, f32, f32);
EffectInstance* fx_butterflies(s32, f32, f32, f32);
EffectInstance* fx_stat_change(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_snaking_static(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_thunderbolt_ring(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_squirt(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* fx_water_block(s32, f32 x, f32 y, f32 z, f32 scale /* maybe */, s32);
EffectInstance* fx_waterfall(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_water_fountain(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_underwater(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_lightning_bolt(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* fx_water_splash(s32, f32 x, f32 y, f32 z, f32 scale /* maybe */, s32);
EffectInstance* fx_snowman_doll(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_fright_jar(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_stop_watch(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_63(s32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
EffectInstance* fx_throw_spiny(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* fx_65(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_tubba_heart_attack(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_whirlwind(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_red_impact(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_floating_cloud_puff(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_6A(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_energy_in_out(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_tattle_window(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_shiny_flare(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_huff_puff_breath(s32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* fx_cold_breath(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_embers(s32, f32, f32, f32, f32, f32, f32, s32, s32, f32, f32);
EffectInstance* fx_hieroglyphs(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_misc_particles(s32, f32, f32, f32, f32, f32, f32, s32, s32);
EffectInstance* fx_static_status(s32, f32, f32, f32, f32, s32, s32); //returns ptr to struct unk_802BE310* in watt.c
EffectInstance* fx_moving_cloud(s32, f32, f32, f32, f32, f32, f32, f32, f32);
EffectInstance* fx_75(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_76(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_firework_rocket(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* fx_peach_star_beam(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_chapter_change(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_ice_shard(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_spirit_card(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_lil_oink(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_something_rotating(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_breaking_junk(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_partner_buff(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_quizmo_assistant(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_ice_pillar(s32, f32 x, f32 y, f32 z, f32, s32);
EffectInstance* fx_sun(s32, f32, f32, f32, f32, s32 time);
EffectInstance* fx_star_spirits_energy(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_pink_sparkles(s32, f32, f32, f32, f32, f32);
EffectInstance* fx_star_outline(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_86(s32, f32, f32, f32, f32, s32);

#endif
