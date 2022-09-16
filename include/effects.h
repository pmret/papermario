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
    EFFECT_BULB_GLOW,
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
    EFFECT_MOTION_BLUR_FLAME,   // three orbs emanating from super block during upgrading animation
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

typedef struct Effect00FXData {
    /* 0x00 */ char todo[0];
} Effect00FXData; // size = unknown

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

typedef struct Effect02FXData {
    /* 0x00 */ char todo[0];
} Effect02FXData; // size = unknown

typedef struct Effect03FXData {
    /* 0x00 */ char todo[0];
} Effect03FXData; // size = unknown

typedef struct Effect04FXData {
    /* 0x00 */ char todo[0];
} Effect04FXData; // size = unknown

typedef struct Effect05FXData {
    /* 0x00 */ char todo[0];
} Effect05FXData; // size = unknown

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
    /* 0x00 */ s32 alive;
    /* 0x04 */ u16 triggeredByNpc;
    /* 0x06 */ s16 timeLeft;
    /* 0x08 */ u8 primAlpha;
    /* 0x09 */ s8 useAltColor;
    /* 0x0A */ char unk_0A[0x2];
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ Vec3f scale;
    /* 0x24 */ Vec3f rot;
    /* 0x30 */ Mtx transformMtx;
    /* 0x70 */ f32 velocityScaleA;
    /* 0x74 */ f32 velocityScaleB;
    /* 0x78 */ f32 visibilityAmt;   // when this is zero, the flower can vanish. may have once controlled alpha.
    /* 0x7C */ f32 unk_7C;
    /* 0x80 */ f32 integrator[4];
    /* 0x90 */ VecXZf velocity;
} FlowerFXData; // size = 0x98

typedef struct CloudPuffFXData {
    /* 0x00 */ s32 alive;
    /* 0x04 */ char unk_04[0x2];
    /* 0x06 */ s16 timeLeft;
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
    /* 0x00 */ Vec3f pos;
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

typedef struct SparklesFXData {
    /* 0x00 */ char todo[0];
} SparklesFXData; // size = unknown

enum SparkesFXTypes {
    FX_SPARKLES_0   = 0,
    FX_SPARKLES_1   = 1,
    FX_SPARKLES_2   = 2,
    FX_SPARKLES_3   = 3,
    FX_SPARKLES_4   = 4
};

typedef struct ShapeSpellFXData {
    /* 0x00 */ s32 isChild;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 timeLeft;
    /* 0x34 */ s32 unk_34;
} ShapeSpellFXData; // size = 0x38

typedef struct GatherEnergyPinkFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f posA;
    /* 0x10 */ Vec3f posB;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
} GatherEnergyPinkFXData; // size = 0x60

typedef struct DropLeavesFXData {
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
} DropLeavesFXData; // size = 0x30

typedef struct DustFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
} DustFXData; // size = 0x48

typedef struct ShatteringStonesFXData {
    /* 0x00 */ char todo[0];
} ShatteringStonesFXData; // size = unknown

typedef struct SmokeRingFXData {
    /* 0x00 */ char todo[0];
} SmokeRingFXData; // size = unknown

typedef struct DamageStarsFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x14 */ f32 unk_04;
    /* 0x18 */ f32 unk_08;
    /* 0x1C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
} DamageStarsFXData; // size = 0x30

typedef struct ExplosionFXData {
    /* 0x00 */ char todo[0];
} ExplosionFXData; // size = unknown

typedef struct LensFlareFXData {
    /* 0x00 */ char todo[0];
} LensFlareFXData; // size = unknown

typedef struct GotItemOutlineFXData {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk_18[0x18];
    /* 0x30 */ s32 unk_30;
} GotItemOutlineFXData; // size = ???

typedef struct SpikyWhiteAuraFXData {
    /* 0x00 */ char todo[0];
} SpikyWhiteAuraFXData; // size = unknown

typedef struct SmokeImpactFXData {
    /* 0x00 */ char todo[0];
} SmokeImpactFXData; // size = unknown

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

typedef struct PurpleRingFXData {
    /* 0x00 */ char todo[0];
} PurpleRingFXData; // size = unknown

typedef struct FlameFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} FlameFXData; // size = 0x34

typedef struct StarsBurstFXData {
    /* 0x00 */ char todo[0];
} StarsBurstFXData; // size = unknown

typedef struct StarsShimmerFXData {
    /* 0x00 */ char todo[0];
} StarsShimmerFXData; // size = unknown

typedef struct RisingBubbleFXData {
    /* 0x00 */ char unk_00[0x08];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk_0C[0x04];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
} RisingBubbleFXData; // size = unknown

typedef struct RingBlastFXData {
    /* 0x00 */ char todo[0];
} RingBlastFXData; // size = unknown

typedef struct ShockwaveFXData {
    /* 0x00 */ char todo[0];
} ShockwaveFXData; // size = unknown

typedef struct MusicNoteFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 timeLeft;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} MusicNoteFXData; // size = 0x34

typedef struct SmokeBurstFXData {
    /* 0x00 */ char todo[0];
} SmokeBurstFXData; // size = unknown

typedef struct SweatFXData {
    /* 0x00 */ char todo[0];
} SweatFXData; // size = unknown

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

typedef struct Unk2AFXData {
    /* 0x00 */ char todo[0];
} Unk2AFXData; // size = unknown

typedef struct WindyLeavesFXData {
    /* 0x00 */ char todo[0];
} WindyLeavesFXData; // size = unknown

typedef struct FallingLeavesFXData {
    /* 0x00 */ char todo[0];
} FallingLeavesFXData; // size = unknown

typedef struct StarsSpreadFXData {
    /* 0x00 */ char todo[0];
} StarsSpreadFXData; // size = unknown

typedef struct SteamBurstFXData {
    /* 0x00 */ char todo[0];
} SteamBurstFXData; // size = unknown

typedef struct StarsOrbitingFXData {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char unk_10[0x18];
    /* 0x28 */ s32 unk_28;
    /* 0x3C */ char todo[0];
} StarsOrbitingFXData; // size = unknown

typedef struct BigSnowflakesFXData {
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
} BigSnowflakesFXData; // size = 0x30

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

typedef struct GreenImpactFXData {
    /* 0x00 */ char todo[0];
} GreenImpactFXData; // size = unknown

typedef struct RadialShimmerFXData {
    /* 0x00 */ char todo[0];
} RadialShimmerFXData; // size = unknown

typedef struct EndingDecalsFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char todo[0];
} EndingDecalsFXData; // size = 0x??

typedef struct LightRaysFXData {
    /* 0x00 */ char todo[0];
} LightRaysFXData; // size = unknown

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
    /* 0x44 */ s32 lifeTime;
    /* 0x48 */ s32 timeLeft;
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

typedef struct ShimmerBurstFXData {
    /* 0x00 */ char todo[0];
} ShimmerBurstFXData; // size = unknown

typedef struct EnergyShockwaveFXData {
    /* 0x00 */ char todo[0];
} EnergyShockwaveFXData; // size = unknown

typedef struct ShimmerWaveFXData {
    /* 0x00 */ char todo[0];
} ShimmerWaveFXData; // size = unknown

typedef struct AuraFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f posA;
    /* 0x10 */ Vec3f posB;
    /* 0x1C */ Vec2f scale;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 primA;
    /* 0x2C */ s32 fadeTime;
    /* 0x30 */ s32 lifeTime;
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
    /* 0x64 */ f32 renderYaw;
    /* 0x68 */ u8 primR;
    /* 0x69 */ u8 primG;
    /* 0x6A */ u8 primB;
    /* 0x6B */ u8 envR;
    /* 0x6C */ u8 envG;
    /* 0x6D */ u8 engB;
    /* 0x6E */ u8 engA;
} AuraFXData; // size = 0x70

typedef struct BulbGlowFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} BulbGlowFXData; // size = 0x24

typedef struct Effect3DFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ Vec3f pos;
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
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ s32 unk_64;
} Effect3DFXData; // size = 0x68

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

typedef struct RecoverFXData {
    /* 0x00 */ char todo[0];
} RecoverFXData; // size = unknown

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

typedef struct BombetteBreakingFXData {
    /* 0x00 */ s16 type;
    /* 0x02 */ s16 treeIndex;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ Vec3f center;
    /* 0x14 */ Vec3f unk_14;
    /* 0x20 */ Vec3f unk_20;
    /* 0x2C */ Vec3f unk_2C;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ s32 timeLeft;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 alpha;
} BombetteBreakingFXData;

typedef struct FireworkFXData {
    /* 0x00 */ char todo[0];
} FireworkFXData; // size = unknown

typedef struct ConfettiFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} ConfettiFXData; // size = 0x34

typedef struct SnowfallFXData {
    /* 0x00 */ char todo[0];
} SnowfallFXData; // size = unknown

typedef struct Effect46FXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32* unk_04; // pointer to another struct?
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ s8 unk_44;
    /* 0x45 */ s8 unk_45;
    /* 0x46 */ s8 unk_46;
    /* 0x47 */ char unk_47;
} Effect46FXData; // size = 0x48

typedef struct GatherMagicFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0x4];
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
} GatherMagicFXData;

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

typedef struct FlashingBoxShockwaveFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char todo[0];
} FlashingBoxShockwaveFXData; // size = unknown

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

typedef struct FloatingRockFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ Vec3f unk_30;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
} FloatingRockFXData; // size = 0x50

typedef struct ChompDropFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
} ChompDropFXData; // size = 0x48

typedef struct QuizmoStageFXData {
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
} QuizmoStageFXData; // size ~ 0x50 (as allocated on heap)

typedef struct RadiatingEnergyOrbFXData {
    /* 0x00 */ char todo[0];
} RadiatingEnergyOrbFXData; // size = unknown

typedef struct QuizmoAnswerFXData {
    /* 0x00 */ char todo[0];
} QuizmoAnswerFXData; // size = unknown

typedef struct MotionBlurFlameFXData {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ Vec3f position;
    /* 0x1C */ char todo[0];
} MotionBlurFlameFXData; // size = unknown

typedef struct EnergyOrbWaveFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char unk_10[0x20];
    /* 0x30 */ f32 scale;
} EnergyOrbWaveFXData; // size = unknown

typedef struct MerlinHouseStarsFXData {
    /* 0x00 */ char todo[0];
} MerlinHouseStarsFXData; // size = unknown

typedef struct QuizmoAudienceFXData {
    /* 0x00 */ char todo[0];
} QuizmoAudienceFXData; // size = unknown

typedef struct ButterfliesFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
} ButterfliesFXData; // size = 0x48

typedef struct StatChangeFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 scale;
    /* 0x14 */ s32 timeLeft;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 arrowType;
    /* 0x20 */ s32 arrowValue;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 scaleX;
    /* 0x2C */ f32 scaleY;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
} StatChangeFXData;

typedef struct SnakingStaticFXData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char todo[0];
} SnakingStaticFXData; // size = unknown

typedef struct ThunderboltRingFXData {
    /* 0x00 */ char unk_00[0x30];
    /* 0x30 */ s32 unk_30;
} ThunderboltRingFXData; // size = ?

typedef struct SquirtFXData {
    /* 0x00 */ char todo[0];
} SquirtFXData; // size = unknown

typedef struct WaterBlockFXData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char todo[0];
} WaterBlockFXData; // size = unknown

typedef struct WaterfallFXData {
    /* 0x00 */ char todo[0];
} WaterfallFXData; // size = unknown

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

typedef struct UnderwaterFXData {
    /* 0x00 */ char todo[0];
} UnderwaterFXData; // size = unknown

typedef struct LightningBoltFXData {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char unk_10[0x20];
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ char unk_3C[0x4];
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
} LightningBoltFXData; // size = ?

typedef struct WaterSplashFXData {
    /* 0x00 */ char todo[0];
} WaterSplashFXData; // size = unknown

typedef struct SnowmanDollFXData {
    /* 0x00 */ char todo[0];
} SnowmanDollFXData; // size = unknown

typedef struct FrightJarFXData {
    /* 0x00 */ char todo[0];
} FrightJarFXData; // size = unknown

typedef struct StopWatchFXData {
    /* 0x00 */ char todo[0];
} StopWatchFXData; // size = unknown

typedef struct Effect63FXData {
    /* 0x00 */ char todo[0];
} Effect63FXData; // size = unknown

typedef struct ThrowSpinyFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 life;
    /* 0x2C */ s32 lifeDuration;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 rgba;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 gravity;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 yaw;
    /* 0x54 */ f32 rotationSpeed;
    /* 0x58 */ f32 xScale;
    /* 0x5C */ f32 yScale;
    /* 0x60 */ u32 state;
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ s32 timeUntilFall; //how long until spiny falls to ground?
} ThrowSpinyFXData; //sizeof 0x6C

typedef struct Effect65FXData {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ Vec3f pos;
    /* 0x44 */ char todo[0];
} Effect65FXData; // size = unknown

typedef struct TubbaHeartAttackFXData {
    /* 0x00 */ char todo[0];
} TubbaHeartAttackFXData; // size = unknown

typedef struct WhirlwindFXData {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char todo[0];
} WhirlwindFXData; // size = unknown

typedef struct RedImpactFXData {
    /* 0x00 */ char todo[0];
} RedImpactFXData; // size = unknown

typedef struct FloatingCloudPuffFXData {
    /* 0x00 */ char todo[0];
} FloatingCloudPuffFXData; // size = unknown

typedef struct Effect6AFXData {
    /* 0x00 */ char todo[0];
} Effect6AFXData; // size = unknown

typedef struct EnergyInOutFXData {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char unk_10[0x24];
    /* 0x34 */ f32 scale;
    /* 0x38 */ char unk_38[0xC];
    /* 0x44 */ f32 unk_44;
    /* 0x38 */ char todo[0];
} EnergyInOutFXData; // size = unknown

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

typedef struct TattleWindowFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ u8 unk_34;
    /* 0x35 */ u8 unk_35;
} TattleWindowFXData; // size = 0x38

typedef struct ShinyFlareFXData {
    /* 0x00 */ char todo[0];
} ShinyFlareFXData; // size = unknown

typedef struct HuffPuffBreathFXData {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ char unk_24[0x4];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} HuffPuffBreathFXData; // size = ?

typedef struct ColdBreathFXData {
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
    /* 0x28 */ s32 unk_28;  // TODO:  Vec3i color?
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
} ColdBreathFXData; // size = 0x44

typedef struct EmbersFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
} EmbersFXData; // size = 0x70

typedef struct HieroglyphsFXData {
    /* 0x00 */ char todo[0];
} HieroglyphsFXData; // size = unknown

typedef struct MiscParticlesFXData {
    char unk_00[0x4];
    Vec3f pos;
    f32 scaleX;
    f32 scaleY;
    char unk_18[0x20];
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    char unk_44[0x4];
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
} MiscParticlesFXData; // size = ?

typedef struct StaticStatusFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ char unk_2C[0x0C];
} StaticStatusFXData; // size = 0x38

typedef struct MovingCloudFXData {
    /* 0x00 */ char todo[0];
} MovingCloudFXData; // size = unknown

typedef struct Effect75FXData {
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
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
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
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ f32 unk_78;
    /* 0x7C */ f32 unk_7C;
} Effect75FXData; // size = 0x80

typedef struct Effect76FXData {
    /* 0x00 */ char todo[0];
} Effect76FXData; // size = unknown

typedef struct FireworkRocketFXData {
    /* 0x00 */ char todo[0];
} FireworkRocketFXData; // size = unknown

typedef struct PeachStarBeamInner {
    /* 0x00 */ s32 flags;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ Vec3f unk_10;
} PeachStarBeamInner; // size = 0x1C

typedef struct PeachStarBeamFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifetime;
    /* 0x18 */ s32 primR;
    /* 0x1C */ s32 primG;
    /* 0x20 */ s32 primB;
    /* 0x24 */ s32 alpha;
    /* 0x28 */ s32 envR;
    /* 0x2C */ s32 envG;
    /* 0x30 */ s32 envB;
    /* 0x34 */ s32 envA;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ PeachStarBeamInner parts[8];
} PeachStarBeamFXData; // size = 0x13C

typedef struct ChapterChangeFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ s32 unk_54;
} ChapterChangeFXData; // size = 0x58

typedef struct IceShardFXData {
    /* 0x00 */ char unk_00[0x4C];
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
} IceShardFXData; // size = ?

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

#define MAX_LIL_OINKS 11

typedef struct LilOinkFXData {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ s32 flags[MAX_LIL_OINKS];
    /* 0x034 */ f32 x[MAX_LIL_OINKS];
    /* 0x060 */ f32 y[MAX_LIL_OINKS];
    /* 0x08C */ f32 z[MAX_LIL_OINKS];
    /* 0x0B8 */ f32 rot[MAX_LIL_OINKS];
    /* 0x0E4 */ u8 type[MAX_LIL_OINKS];
    /* 0x0EF */ s8 unk_EF[MAX_LIL_OINKS];
    /* 0x0FA */ u8 unk_FA[MAX_LIL_OINKS];
    /* 0x105 */ u8 unk_105[MAX_LIL_OINKS];
    /* 0x110 */ f32 jumpOffset[MAX_LIL_OINKS];
    /* 0x13C */ s8 unk_13C[MAX_LIL_OINKS];
} LilOinkFXData; // size = 0x148

typedef struct SomethingRotatingFXData {
    /* 0x00 */ char todo[0];
} SomethingRotatingFXData; // size = unknown

typedef struct BreakingJunkFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f vel;
    /* 0x1C */ s32 timeLeft;
    /* 0x20 */ s32 lifeTime;
    /* 0x24 */ f32 scale;
    /* 0x28 */ f32 rot;
    /* 0x2C */ s16 primR;
    /* 0x2E */ s16 primG;
    /* 0x30 */ s16 primB;
    /* 0x32 */ s16 primA;
    /* 0x34 */ s16 envR;
    /* 0x36 */ s16 envG;
    /* 0x38 */ s16 envB;
    /* 0x3A */ s16 envA;
} BreakingJunkFXData; // size = unknown

enum {
    FX_BUFF_DATA_WATER_BLOCK    = 0,
    FX_BUFF_DATA_CLOUD_NINE     = 1,
    FX_BUFF_DATA_TURBO_CHARGE   = 2
};

typedef struct BuffData {
    /* 0x00 */ s16 alpha;
    /* 0x02 */ s16 turnsDisplay;
    /* 0x04 */ s16 turnsLeft;
    /* 0x06 */ s16 state;
    /* 0x08 */ s16 stateTimer;
} BuffData;

typedef struct PartnerBuffFXData {
    /* 0x00 */ s16 useRandomValues;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 timeLeft;
    /* 0x08 */ s32 lifeTime;
    /* 0x0C */ BuffData unk_0C[3];
} PartnerBuffFXData; // size = 0x2C

typedef struct QuizmoAssistantFXData {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ Vec3f position;
    /* 0x10 */ s32 vanishTimer;
    /* 0x14 */ s32 lifetime;
    /* 0x18 */ s32 fadeInAmt; // 0 = all-black, FF = fully-visible
    /* 0x1C */ s32 anim;
} QuizmoAssistantFXData; // size = 0x20

typedef struct IcePillarFXData {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ char todo[0];
} IcePillarFXData; // size = unknown

typedef struct SunFXData {
    /* 0x00 */ s32 shineFromRight;
    /* 0x04 */ Vec3f pos; // does nothing
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifeTime;
    /* 0x18 */ Color_RGB8 primColor;
    /* 0x1B */ Color_RGBA8 envColor;
    /* 0x1F */ char unk_1F[0x1];
    /* 0x20 */ f32 texScrollAmt[5];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 alpha;
    /* 0x3C */ s32 targetAlpha;
} SunFXData; // size = 0x40

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

typedef struct PinkSparklesFXData {
    /* 0x00 */ char todo[0];
} PinkSparklesFXData; // size = unknown

typedef struct StarOutlineFXData {
    /* 0x00 */ char todo[0];
} StarOutlineFXData; // size = unknown

typedef struct Effect86FXData {
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
} Effect86FXData; // size = 0x38

typedef union {
    s32* any;
    struct Effect00FXData*              unk_00;
    struct BigSmokePuffFXData*          bigSmokePuff;
    struct Effect02FXData*              unk_02;
    struct Effect03FXData*              unk_03;
    struct Effect04FXData*              unk_04;
    struct Effect05FXData*              unk_05;
    struct LandingDustFXData*           landingDust;
    struct WalkingDustFXData*           walkingDust;
    struct FlowerFXData*                flowerSplash; // note: shared
    struct FlowerFXData*                flowerTrail;  // note: shared
    struct CloudPuffFXData*             cloudPuff;
    struct CloudTrailFXData*            cloudTrail;
    struct FootprintFXData*             footprint;
    struct FloatingFlowerFXData*        floatingFlower;
    struct SnowflakeFXData*             snowflake;
    struct StarFXData*                  star;
    struct EmoteFXData*                 emote;
    struct SparklesFXData*              sparkles;
    struct ShapeSpellFXData*            shapeSpell;
    struct GatherEnergyPinkFXData*      gatherEnergyPink;
    struct DropLeavesFXData*            dropLeaves;
    struct DustFXData*                  dust;
    struct ShatteringStonesFXData*      shatteringStones;
    struct SmokeRingFXData*             smokeRing;
    struct DamageStarsFXData*           damageStars;
    struct ExplosionFXData*             explosion;
    struct LensFlareFXData*             lensFlare;
    struct GotItemOutlineFXData*        gotItemOutline;
    struct SpikyWhiteAuraFXData*        spikyWhiteAura;
    struct SmokeImpactFXData*           smokeImpact;
    struct DamageIndicatorFXData*       damageIndicator;
    struct PurpleRingFXData*            purpleRing;
    struct FlameFXData*                 flame;
    struct StarsBurstFXData*            starsBurst;
    struct StarsShimmerFXData*          starsShimmer;
    struct RisingBubbleFXData*          risingBubble;
    struct RingBlastFXData*             ringBlast;
    struct ShockwaveFXData*             shockwave;
    struct MusicNoteFXData*             musicNote;
    struct SmokeBurstFXData*            smokeBurst;
    struct SweatFXData*                 sweat;
    struct SleepBubbleFXData*           sleepBubble;
    struct Unk2AFXData*                 unk_2A;
    struct WindyLeavesFXData*           windyLeaves;
    struct FallingLeavesFXData*         fallingLeaves;
    struct StarsSpreadFXData*           starsSpread;
    struct SteamBurstFXData*            steamBurst;
    struct StarsOrbitingFXData*         starsOrbiting;
    struct BigSnowflakesFXData*         bigSnowflakes;
    struct DebuffFXData*                debuff;
    struct GreenImpactFXData*           greenImpact;
    struct RadialShimmerFXData*         radialShimmer;
    struct EndingDecalsFXData*          endingDecals;
    struct LightRaysFXData*             lightRays;
    struct LightningFXData*             lightning;
    struct FireBreathFXData*            fireBreath;
    struct ShimmerBurstFXData*          shimmerBurst;
    struct EnergyShockwaveFXData*       energyShockwave;
    struct ShimmerWaveFXData*           shimmerWave;
    struct AuraFXData*                  aura;
    struct BulbGlowFXData*              bulbGlow;
    struct Effect3DFXData*              unk_3D;
    struct BlastFXData*                 blast;
    struct FireFlowerFXData*            fireFlower;
    struct RecoverFXData*               recover;
    struct DisableXFXData*              disableX;
    struct BombetteBreakingFXData*      bombetteBreaking;
    struct FireworkFXData*              firework;
    struct ConfettiFXData*              confetti;
    struct SnowfallFXData*              snowfall;
    struct Effect46FXData*              unk_46;
    struct GatherMagicFXData*           gatherMagic;
    struct AttackResultTextFXData*      attackResultText;
    struct SmallGoldSparkleFXData*      smallGoldSparkle;
    struct FlashingBoxShockwaveFXData*  flashingBoxShockwave;
    struct BalloonFXData*               balloon;
    struct FloatingRockFXData*          floatingRock;
    struct ChompDropFXData*             chompDrop;
    struct QuizmoStageFXData*           quizmoStage;
    struct RadiatingEnergyOrbFXData*    radiatingEnergyOrb;
    struct QuizmoAnswerFXData*          quizmoAnswer;
    struct MotionBlurFlameFXData*       motionBlurFlame;
    struct EnergyOrbWaveFXData*         energyOrbWave;
    struct MerlinHouseStarsFXData*      merlinHouseStars;
    struct QuizmoAudienceFXData*        quizmoAudience;
    struct ButterfliesFXData*           butterflies;
    struct StatChangeFXData*            statChange;
    struct SnakingStaticFXData*         snakingStatic;
    struct ThunderboltRingFXData*       thunderboltRing;
    struct SquirtFXData*                squirt;
    struct WaterBlockFXData*            waterBlock;
    struct WaterfallFXData*             waterfall;
    struct WaterFountainFXData*         waterFountain;
    struct UnderwaterFXData*            underwater;
    struct LightningBoltFXData*         lightningBolt;
    struct WaterSplashFXData*           waterSplash;
    struct SnowmanDollFXData*           snowmanDoll;
    struct FrightJarFXData*             frightJar;
    struct StopWatchFXData*             stopWatch;
    struct Effect63FXData*              unk_63;
    struct ThrowSpinyFXData*            throwSpiny;
    struct Effect65FXData*              unk_65;
    struct TubbaHeartAttackFXData*      tubbaHeartAttack;
    struct WhirlwindFXData*             whirlwind;
    struct RedImpactFXData*             redImpact;
    struct FloatingCloudPuffFXData*     floatingCloudPuff;
    struct Effect6AFXData*              unk_6A;
    struct EnergyInOutFXData*           energyInOut;
    struct TattleWindowFXData*          tattleWindow;
    struct ShinyFlareFXData*            shinyFlare;
    struct HuffPuffBreathFXData*        huffPuffBreath;
    struct ColdBreathFXData*            coldBreath;
    struct EmbersFXData*                embers;
    struct HieroglyphsFXData*           hieroglyphs;
    struct MiscParticlesFXData*         miscParticles;
    struct StaticStatusFXData*          staticStatus;
    struct MovingCloudFXData*           movingCloud;
    struct Effect75FXData*              unk_75;
    struct Effect76FXData*              unk_76;
    struct FireworkRocketFXData*        fireworkRocket;
    struct PeachStarBeamFXData*         peachStarBeam;
    struct ChapterChangeFXData*         chapterChange;
    struct IceShardFXData*              iceShard;
    struct SpiritCardFXData*            spiritCard;
    struct LilOinkFXData*               lilOink;
    struct SomethingRotatingFXData*     somethingRotating;
    struct BreakingJunkFXData*          breakingJunk;
    struct PartnerBuffFXData*           partnerBuff;
    struct QuizmoAssistantFXData*       quizmoAssistant;
    struct IcePillarFXData*             icePillar;
    struct SunFXData*                   sun;
    struct StarSpiritsEnergyFXData*     starSpiritsEnergy;
    struct PinkSparklesFXData*          pinkSparkles;
    struct StarOutlineFXData*           starOutline;
    struct Effect86FXData*              unk_86;
} EffectData;

typedef struct EffectInstance {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 effectIndex;
    /* 0x08 */ s32 numParts;
    /* 0x0C */ EffectData data;
    /* 0x10 */ struct EffectGraphics* graphics;
} EffectInstance; // size = 0x14

// composite struct for watt effects -- NOT the same as StaticStatusFXData
typedef struct WattEffectData {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 angle;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ EffectInstance* effect1;
    /* 0x18 */ EffectInstance* effect2;
    /* 0x1C */ s32 debuff;
} WattEffectData;

// seems to actually be PlayerStatus, but it's too large seemingly given the bss padding in UnkWhirlwindEffectFunc.inc.c
typedef struct EffectWhirlwindUnk {
    /* 0x00 */ char unk_00[0x28];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} EffectWhirlwindUnk;

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
EffectInstance* fx_got_item_outline(s32, f32, f32, f32, f32, EffectInstance**);
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
void fx_sweat(s32, f32 x, f32 y, f32 z, f32 radius, f32 pitch, s32 duration);
void fx_sleep_bubble(s32, f32, f32, f32, f32, f32, EffectInstance**);
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
EffectInstance* fx_ending_decals(s32, f32, f32, f32, f32, EffectInstance**);
EffectInstance* fx_light_rays(s32, f32, f32, f32, f32, s32*);
EffectInstance* fx_lightning(s32, f32, f32, f32, f32, f32);
EffectInstance* fx_fire_breath(s32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
EffectInstance* fx_shimmer_burst(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_energy_shockwave(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_shimmer_wave(s32, f32, f32, f32, f32, f32, s32, s32);
void fx_aura(s32, f32, f32, f32, f32, EffectInstance**);
EffectInstance* fx_bulb_glow(s32, f32, f32, f32, f32, EffectInstance**);
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
