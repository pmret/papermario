#ifndef _EFFECTS_H_
#define _EFFECTS_H_

#include "types.h"
#include "common_structs.h"

enum EffectID {
    EFFECT_00                       = 0x00,
    EFFECT_BIG_SMOKE_PUFF           = 0x01,
    EFFECT_02                       = 0x02, // unused
    EFFECT_03                       = 0x03, // unused
    EFFECT_04                       = 0x04, // unused
    EFFECT_05                       = 0x05, // unused
    EFFECT_LANDING_DUST             = 0x06,
    EFFECT_WALKING_DUST             = 0x07,
    EFFECT_FLOWER_SPLASH            = 0x08,
    EFFECT_FLOWER_TRAIL             = 0x09,
    EFFECT_CLOUD_PUFF               = 0x0A,
    EFFECT_CLOUD_TRAIL              = 0x0B,
    EFFECT_FOOTPRINT                = 0x0C,
    EFFECT_FLOATING_FLOWER          = 0x0D,
    EFFECT_SNOWFLAKE                = 0x0E,
    EFFECT_STAR                     = 0x0F,
    EFFECT_EMOTE                    = 0x10,
    EFFECT_SPARKLES                 = 0x11,
    EFFECT_SHAPE_SPELL              = 0x12,
    EFFECT_GATHER_ENERGY_PINK       = 0x13,
    EFFECT_DROP_LEAVES              = 0x14,
    EFFECT_DUST                     = 0x15,
    EFFECT_SHATTERING_STONES        = 0x16,
    EFFECT_SMOKE_RING               = 0x17,
    EFFECT_DAMAGE_STARS             = 0x18,
    EFFECT_EXPLOSION                = 0x19,
    EFFECT_LENS_FLARE               = 0x1A,
    EFFECT_GOT_ITEM_OUTLINE         = 0x1B,
    EFFECT_SPIKY_WHITE_AURA         = 0x1C,
    EFFECT_SMOKE_IMPACT             = 0x1D,
    EFFECT_DAMAGE_INDICATOR         = 0x1E,
    EFFECT_PURPLE_RING              = 0x1F,
    EFFECT_FLAME                    = 0x20,
    EFFECT_STARS_BURST              = 0x21,
    EFFECT_STARS_SHIMMER            = 0x22,
    EFFECT_RISING_BUBBLE            = 0x23,
    EFFECT_RING_BLAST               = 0x24,
    EFFECT_SHOCKWAVE                = 0x25,
    EFFECT_MUSIC_NOTE               = 0x26,
    EFFECT_SMOKE_BURST              = 0x27,
    EFFECT_SWEAT                    = 0x28,
    EFFECT_SLEEP_BUBBLE             = 0x29,
    EFFECT_2A                       = 0x2A, // unused
    EFFECT_WINDY_LEAVES             = 0x2B,
    EFFECT_FALLING_LEAVES           = 0x2C,
    EFFECT_STARS_SPREAD             = 0x2D,
    EFFECT_STEAM_BURST              = 0x2E,
    EFFECT_STARS_ORBITING           = 0x2F,
    EFFECT_BIG_SNOWFLAKES           = 0x30,
    EFFECT_DEBUFF                   = 0x31,
    EFFECT_GREEN_IMPACT             = 0x32,
    EFFECT_RADIAL_SHIMMER           = 0x33,
    EFFECT_ENDING_DECALS            = 0x34,
    EFFECT_LIGHT_RAYS               = 0x35,
    EFFECT_LIGHTNING                = 0x36,
    EFFECT_FIRE_BREATH              = 0x37,
    EFFECT_SHIMMER_BURST            = 0x38,
    EFFECT_ENERGY_SHOCKWAVE         = 0x39,
    EFFECT_SHIMMER_WAVE             = 0x3A,
    EFFECT_AURA                     = 0x3B,
    EFFECT_BULB_GLOW                = 0x3C,
    EFFECT_3D                       = 0x3D,
    EFFECT_BLAST                    = 0x3E,
    EFFECT_FIRE_FLOWER              = 0x3F,
    EFFECT_RECOVER                  = 0x40,
    EFFECT_DISABLE_X                = 0x41,
    EFFECT_BOMBETTE_BREAKING        = 0x42,
    EFFECT_FIREWORK                 = 0x43,
    EFFECT_CONFETTI                 = 0x44,
    EFFECT_SNOWFALL                 = 0x45,
    EFFECT_46                       = 0x46,
    EFFECT_GATHER_MAGIC             = 0x47,
    EFFECT_ATTACK_RESULT_TEXT       = 0x48,
    EFFECT_SMALL_GOLD_SPARKLE       = 0x49,
    EFFECT_FLASHING_BOX_SHOCKWAVE   = 0x4A,
    EFFECT_BALLOON                  = 0x4B,
    EFFECT_FLOATING_ROCK            = 0x4C,
    EFFECT_CHOMP_DROP               = 0x4D,
    EFFECT_QUIZMO_STAGE             = 0x4E,
    EFFECT_RADIATING_ENERGY_ORB     = 0x4F,
    EFFECT_QUIZMO_ANSWER            = 0x50, // unused
    EFFECT_MOTION_BLUR_FLAME        = 0x51, // three orbs emanating from super block during upgrading animation
    EFFECT_ENERGY_ORB_WAVE          = 0x52,
    EFFECT_MERLIN_HOUSE_STARS       = 0x53,
    EFFECT_QUIZMO_AUDIENCE          = 0x54, // unused
    EFFECT_BUTTERFLIES              = 0x55,
    EFFECT_STAT_CHANGE              = 0x56,
    EFFECT_SNAKING_STATIC           = 0x57,
    EFFECT_THUNDERBOLT_RING         = 0x58,
    EFFECT_SQUIRT                   = 0x59,
    EFFECT_WATER_BLOCK              = 0x5A,
    EFFECT_WATERFALL                = 0x5B,
    EFFECT_WATER_FOUNTAIN           = 0x5C,
    EFFECT_UNDERWATER               = 0x5D,
    EFFECT_LIGHTNING_BOLT           = 0x5E,
    EFFECT_WATER_SPLASH             = 0x5F,
    EFFECT_SNOWMAN_DOLL             = 0x60,
    EFFECT_FRIGHT_JAR               = 0x61,
    EFFECT_STOP_WATCH               = 0x62,
    EFFECT_63                       = 0x63,
    EFFECT_THROW_SPINY              = 0x64,
    EFFECT_65                       = 0x65,
    EFFECT_TUBBA_HEART_ATTACK       = 0x66,
    EFFECT_WHIRLWIND                = 0x67,
    EFFECT_RED_IMPACT               = 0x68,
    EFFECT_FLOATING_CLOUD_PUFF      = 0x69,
    EFFECT_6A                       = 0x6A, // unused
    EFFECT_ENERGY_IN_OUT            = 0x6B,
    EFFECT_TATTLE_WINDOW            = 0x6C,
    EFFECT_SHINY_FLARE              = 0x6D,
    EFFECT_HUFF_PUFF_BREATH         = 0x6E,
    EFFECT_COLD_BREATH              = 0x6F,
    EFFECT_EMBERS                   = 0x70,
    EFFECT_HIEROGLYPHS              = 0x71,
    EFFECT_MISC_PARTICLES           = 0x72,
    EFFECT_STATIC_STATUS            = 0x73,
    EFFECT_MOVING_CLOUD             = 0x74,
    EFFECT_75                       = 0x75,
    EFFECT_76                       = 0x76, // unused
    EFFECT_FIREWORK_ROCKET          = 0x77,
    EFFECT_PEACH_STAR_BEAM          = 0x78,
    EFFECT_CHAPTER_CHANGE           = 0x79,
    EFFECT_ICE_SHARD                = 0x7A,
    EFFECT_SPIRIT_CARD              = 0x7B,
    EFFECT_LIL_OINK                 = 0x7C,
    EFFECT_SOMETHING_ROTATING       = 0x7D,
    EFFECT_BREAKING_JUNK            = 0x7E,
    EFFECT_PARTNER_BUFF             = 0x7F,
    EFFECT_QUIZMO_ASSISTANT         = 0x80,
    EFFECT_ICE_PILLAR               = 0x81,
    EFFECT_SUN                      = 0x82,
    EFFECT_STAR_SPIRITS_ENERGY      = 0x83,
    EFFECT_PINK_SPARKLES            = 0x84,
    EFFECT_STAR_OUTLINE             = 0x85,
    EFFECT_86                       = 0x86,
};

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
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f vel;
    /* 0x1C */ f32 accelY;
    /* 0x20 */ f32 jerkY;
    /* 0x24 */ Vec2f rot;
    /* 0x2C */ Vec2f angularVel;
    /* 0x34 */ s32 timeLeft;
    /* 0x38 */ s32 lifetime;
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
    /* 0x3C */ Npc* unk_3C;
} EmoteFXData; // size = 0x40

typedef struct SparklesFXData {
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
} SparklesFXData; // size = 0x30

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
    /* 0x50 */ f32 unk_50;
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
    /* 0x00 */ f32 unk_00;
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
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
} ShatteringStonesFXData; // size = 0x40

typedef struct SmokeRingFXData {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
} SmokeRingFXData; // size = 0x44

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
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
} ExplosionFXData; // size = 0x3C

typedef struct LensFlareFXData {
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
    /* 0x30 */ s32 unk_30;
} LensFlareFXData; // size = 0x34

typedef struct GotItemOutlineFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
} GotItemOutlineFXData; // size = 0x20

typedef struct SpikyWhiteAuraFXData {
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
} SpikyWhiteAuraFXData; // size = 0x30

typedef struct SmokeImpactFXData {
    /* 0x00 */ u16 unk_00;
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
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
} SmokeImpactFXData; // size = 0x34

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
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ Matrix4f unk_1C;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ s32 unk_68;
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ u8 unk_74;
    /* 0x75 */ u8 unk_75;
    /* 0x76 */ u8 unk_76;
    /* 0x77 */ u8 unk_77;
    /* 0x78 */ u8 unk_78;
    /* 0x79 */ u8 unk_79;
    /* 0x7A */ char unk_7A[2];
} PurpleRingFXData; // size = 0x7C

typedef struct FlameFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} FlameFXData; // size = 0x34

typedef struct StarsBurstFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ char unk_1C[8];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
} StarsBurstFXData; // size = 0x38

typedef struct StarsShimmerFXData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 state;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 lifeTime;
    /* 0x24 */ s32 timeLeft;
    /* 0x28 */ s32 unk_28;
} StarsShimmerFXData; // size = 0x2C

typedef struct RisingBubbleFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 timeLeft;
    /* 0x1C */ s32 lifeTime;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
} RisingBubbleFXData; // size = 0x28

typedef struct RingBlastFXData {
    /* 0x00 */ u16 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 timeLeft;
    /* 0x18 */ s32 lifeTime;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
} RingBlastFXData; // size = 0x2C

// Likely to be the same as GreenImpactFXData and RedImpactFXData
typedef struct ShockwaveFXData {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[2]; // likely padding
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 alpha;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ Color_RGB8 prim;
    /* 0x53 */ Color_RGB8 env;
    /* 0x56 */ char unk_56[2]; // likely padding
} ShockwaveFXData; // size = 0x58

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
    /* 0x00 */ u16 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 timeLeft;
    /* 0x18 */ s32 lifeTime;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ Color_RGBA8 rgba;
} SmokeBurstFXData; // size = 0x28

typedef struct SweatFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[0x04];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 timeLeft;
} SweatFXData; // size = 0x28

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

typedef struct WindyLeavesFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 alpha;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
} WindyLeavesFXData; // size = 0x3C

typedef struct FallingLeavesFXData {
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
    /* 0x30 */ char unk_30[4];
} FallingLeavesFXData; // size = 0x34

typedef struct StarsSpreadFXData {
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
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
} StarsSpreadFXData; // size = 0x34

typedef struct SteamBurstFXData {
    /* 0x00 */ u16 unk_00;
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
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
} SteamBurstFXData; // size = 0x34

typedef struct StarsOrbitingFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 orbitRadius;
    /* 0x14 */ f32 targetRadius;
    /* 0x18 */ f32 roll;
    /* 0x1C */ f32 rollSpinRate;
    /* 0x20 */ f32 pitch;
    /* 0x24 */ s32 yaw;
    /* 0x28 */ s32 enabled;
} StarsOrbitingFXData; // size = 0x2C

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
    /* 0x00 */ s16 type;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 scaleY;
    /* 0x20 */ f32 scaleX;
    /* 0x24 */ s32 timeLeft;
    /* 0x28 */ s32 lifetime;
    /* 0x2C */ f32 rotZ;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ s32 alpha;
    /* 0x38 */ Color_RGB8 primCol;
    /* 0x38 */ Color_RGB8 envCol;
    /* 0x3E */ char unk_3E[2];
} DebuffFXData; // size = 0x40

// Likely to be the same as RedImpactFXData and ShockwaveFXData
typedef struct GreenImpactFXData {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[2]; // likely padding
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ Color_RGB8 unk_50;
    /* 0x53 */ Color_RGB8 unk_53;
    /* 0x56 */ char unk_56[2]; // likely padding
} GreenImpactFXData; // size = 0x58

typedef struct RadialShimmerFXData {
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
    /* 0x28 */ s32 timeLeft;
    /* 0x2C */ s32 lifeTime;
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
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ u8 unk_68;
    /* 0x69 */ u8 unk_69;
    /* 0x6A */ u8 unk_6A;
    /* 0x6B */ u8 unk_6B;
    /* 0x6C */ u8 unk_6C;
    /* 0x6D */ u8 unk_6D;
    /* 0x6E */ char unk_6E[2];
} RadialShimmerFXData; // size = 0x70

typedef struct EndingDecalsFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 scale;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 haloAlpha;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ u8 unk_26;
    /* 0x27 */ u8 unk_27;
    /* 0x28 */ u8 unk_28;
    /* 0x29 */ u8 unk_29;
    /* 0x2A */ char unk_2A[2];
} EndingDecalsFXData; // size = 0x2C

typedef struct LightRaysFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ char unk_04[0xC];
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 alpha;
    /* 0x28 */ s32 timeLeft;
    /* 0x2C */ s32 lifetime;
    /* 0x30 */ char unk_30[4];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ Vec3f rotation;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ Vec3f initialRot;
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ f32 unk_80;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ f32 unk_8C;
    /* 0x90 */ s32 unk_90;
} LightRaysFXData; // size = 0x94

typedef struct LightningFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ struct EffectInstance* unk_44;
    /* 0x48 */ struct EffectInstance* unk_48;
} LightningFXData; // size = 0x4C

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
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
} ShimmerBurstFXData; // size = 0x6C

typedef struct EnergyShockwaveFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char unk_10[0xC];
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u8 unk_50;
    /* 0x51 */ u8 unk_51;
    /* 0x52 */ s8 unk_52;
    /* 0x53 */ char unk_53[1];
} EnergyShockwaveFXData; // size = 0x54

typedef struct ShimmerWaveFXData {
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
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
} ShimmerWaveFXData; // size = 0x6C

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
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ Vec3i unk_40;
} FireFlowerFXData; // size = 0x4C

typedef struct RecoverFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
} RecoverFXData; // size = 0x48

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
    /* 0x3C */ s32 koDuration;
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
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk_18[4];
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ u8 unk_3C;
    /* 0x3D */ u8 unk_3D;
    /* 0x3E */ u8 unk_3E;
    /* 0x3F */ u8 unk_3F;
    /* 0x40 */ u8 unk_40;
    /* 0x41 */ u8 unk_41;
    /* 0x42 */ char unk_42[2];
} FireworkFXData; // size = 0x44

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
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 timeLeft;
    /* 0x24 */ s32 lifeTime;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} SnowfallFXData; // size = 0x34

typedef struct Effect46FXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ PlayerStatus* unk_04;
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
    /* 0x44 */ u8 unk_44;
    /* 0x45 */ u8 unk_45;
    /* 0x46 */ u8 unk_46;
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
    /* 0x28 */ f32 unk_28;
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
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
} FlashingBoxShockwaveFXData; // size = 0x48

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
   /* 0x00 */ s32 unk_00;
   /* 0x04 */ s32 vanishTimer;
   /* 0x08 */ s32 lifetime;
   /* 0x0C */ Vec3f origin;
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
   /* 0x40 */ char unk_40[0x04];
} QuizmoStageFXData; // size 0x44

typedef struct RadiatingEnergyOrbFXData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ char unk_24[4];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} RadiatingEnergyOrbFXData; // size = 0x34

typedef struct MotionBlurFlameFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ f32 unk_1C[4];
    /* 0x2C */ f32 unk_2C[4];
    /* 0x3C */ f32 unk_3C[4];
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ char unk_58[4];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ s32 unk_64;
} MotionBlurFlameFXData; // size = 0x68

typedef struct EnergyOrbWaveFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 scale;
    /* 0x34 */ f32 unk_34;
} EnergyOrbWaveFXData; // size = 0x38

typedef struct MerlinHouseStarsFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
} MerlinHouseStarsFXData; // size = 0x3C

#define MAX_QUIZMO_AUDIENCE 10

typedef struct QuizmoAudienceFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 timeLeft;
    /* 0x08 */ s32 lifeTime;
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ s32 primColor;
    /* 0x1C */ s32 compState[MAX_QUIZMO_AUDIENCE];
    /* 0x44 */ s32 compType[MAX_QUIZMO_AUDIENCE];
    /* 0x6C */ s32 compPosIdx[MAX_QUIZMO_AUDIENCE];
    /* 0x94 */ f32 compMoveMagnitude[MAX_QUIZMO_AUDIENCE];
    /* 0xBC */ f32 compX[MAX_QUIZMO_AUDIENCE];
    /* 0xE4 */ f32 compY[MAX_QUIZMO_AUDIENCE];
} QuizmoAudienceFXData; // size = 0x10C

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
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
} StatChangeFXData;

typedef struct SnakingStaticFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifeTime;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 unk_40;
} SnakingStaticFXData; // size = 0x44

typedef struct ThunderboltRingFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifeTime;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk_30;
} ThunderboltRingFXData; // size = 0x34

typedef struct SquirtFXData {
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
    /* 0x02C */ s32 unk_2C;
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ s32 unk_34;
    /* 0x038 */ s32 unk_38;
    /* 0x03C */ s32 unk_3C;
    /* 0x040 */ s32 unk_40;
    /* 0x044 */ s32 unk_44;
    /* 0x048 */ s32 unk_48;
    /* 0x04C */ s32 unk_4C;
    /* 0x050 */ f32 unk_50;
    /* 0x054 */ s32 unk_54;
    /* 0x058 */ f32 unk_58[12];
    /* 0x088 */ f32 unk_88[12];
    /* 0x0B8 */ s32 unk_B8[12];
    /* 0x0E8 */ f32 unk_E8[12];
    /* 0x118 */ f32 unk_118[12];
    /* 0x148 */ f32 unk_148[12];
    /* 0x178 */ s32 unk_178[12];
    /* 0x1A8 */ s32 unk_1A8[12];
    /* 0x1D8 */ u8 unk_1D8[12];
} SquirtFXData; // size = 0x1E4

#define NUM_WATER_BLOCK_COMPONENTS 4

typedef struct WaterBlockFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38[NUM_WATER_BLOCK_COMPONENTS];
    /* 0x48 */ f32 unk_48[NUM_WATER_BLOCK_COMPONENTS];
    /* 0x58 */ f32 unk_58[NUM_WATER_BLOCK_COMPONENTS];
    /* 0x68 */ f32 unk_68[NUM_WATER_BLOCK_COMPONENTS];
    /* 0x78 */ f32 unk_78[NUM_WATER_BLOCK_COMPONENTS];
    /* 0x88 */ s32 unk_88[NUM_WATER_BLOCK_COMPONENTS];
} WaterBlockFXData; // size = 0x98

typedef struct WaterfallFXData {
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
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C[12];
    /* 0x5C */ f32 unk_5C[12];
} WaterfallFXData; // size = 0x8C

typedef struct WaterFountainFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifeTime;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
} WaterFountainFXData; // size = 0x44

typedef struct UnderwaterFXData {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ f32 unk_08;
    /* 0x00C */ f32 unk_0C;
    /* 0x010 */ s32 timeLeft;
    /* 0x014 */ s32 lifeTime;
    /* 0x018 */ f32 unk_18;
    /* 0x01C */ Color_RGBA8 waterColor;
    /* 0x020 */ Color_RGB8 unk_20;
    /* 0x023 */ s8 unk_23[19][13];
    /* 0x11A */ s16 unk_11A[19][13];
} UnderwaterFXData; // size = 0x308

typedef struct LightningBoltFXData {
    /* 0x000 */ s32 type;
    /* 0x004 */ Vec3f tipPos;
    /* 0x010 */ Vec3f startPos;
    /* 0x01C */ Vec3f endPos;
    /* 0x028 */ s32 timeLeft;
    /* 0x02C */ s32 lifetime;
    /* 0x030 */ Color4i outerColor;
    /* 0x040 */ Color3i innerColor;
    /* 0x04C */ f32 widthScale;
    /* 0x050 */ f32 boltVertexPosX[12];
    /* 0x080 */ f32 boltVertexPosY[12];
    /* 0x0B0 */ f32 boltVertexPosZ[12];
    /* 0x0E0 */ f32 edgeLength[12];
    /* 0x110 */ s32 unk_110;
    /* 0x114 */ f32 unk_114;
} LightningBoltFXData; // size = 0x118

typedef struct WaterSplashFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
} WaterSplashFXData; // size = 0x38

typedef struct SnowmanDollFXData {
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
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
} SnowmanDollFXData; // size = 0x60

typedef struct FrightJarFXData {
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
    /* 0x28 */ f32 unk_28;
} FrightJarFXData; // size = 0x2C

typedef struct StopWatchFXData {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ f32 unk_08;
    /* 0x00C */ f32 unk_0C;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ s32 unk_14;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s32 unk_1C;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ s32 unk_24;
    /* 0x028 */ f32 unk_28;
    /* 0x02C */ s32 unk_2C;
    /* 0x030 */ f32 unk_30;
    /* 0x034 */ f32 unk_34[10];
    /* 0x05C */ f32 unk_5C[10];
    /* 0x084 */ f32 unk_84[10];
    /* 0x0AC */ f32 unk_AC[10];
    /* 0x0D4 */ f32 unk_D4[10];
    /* 0x0FC */ f32 unk_FC[10];
    /* 0x124 */ s32 unk_124[10];
    /* 0x14C */ s32 unk_14C[10];
} StopWatchFXData; // size = 0x174

typedef struct Effect63FXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
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
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ char unk_5C[4];
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ f32 unk_78;
} Effect63FXData; // size = 0x7C

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
    /* 0x000 */ s32 variation;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ f32 unk_08;
    /* 0x00C */ f32 unk_0C;
    /* 0x010 */ s32 timeLeft;
    /* 0x014 */ s32 lifeTime;
    /* 0x018 */ s32 primR;
    /* 0x01C */ s32 primG;
    /* 0x020 */ s32 primB;
    /* 0x024 */ s32 alpha;
    /* 0x028 */ s32 envR;
    /* 0x02C */ s32 envG;
    /* 0x030 */ s32 envB;
    /* 0x034 */ f32 scale;
    /* 0x038 */ Vec3f pos;
    /* 0x044 */ f32 pathJitterX;
    /* 0x048 */ f32 pathJitterY;
    /* 0x04C */ f32 pathJitterZ;
    /* 0x050 */ f32 pathX[30];
    /* 0x0C8 */ f32 pathY[30];
    /* 0x140 */ f32 pathZ[30];
    /* 0x1B8 */ s32 pathTimestamp[30];
    /* 0x230 */ s32 pathPointEnabled[30]; // a bool
    /* 0x2A8 */ s32 lastPointIndex;
    /* 0x2AC */ f32 pathLength[30];
} Effect65FXData; // size = 0x324

typedef struct TubbaHeartAttackFXData {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ f32 unk_08;
    /* 0x00C */ f32 unk_0C;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ s32 unk_14;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s32 unk_1C;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ s32 unk_24;
    /* 0x028 */ f32 unk_28;
    /* 0x02C */ f32 unk_2C[25];
    /* 0x090 */ f32 unk_90[25];
    /* 0x0F4 */ f32 unk_F4[25];
    /* 0x158 */ f32 unk_158[25];
    /* 0x1BC */ f32 unk_1BC[25];
    /* 0x220 */ f32 unk_220[25];
    /* 0x284 */ f32 unk_284[25];
    /* 0x2E8 */ f32 unk_2E8[25];
    /* 0x34C */ f32 unk_34C[25];
    /* 0x3B0 */ f32 unk_3B0[25];
    /* 0x414 */ f32 unk_414[25];
    /* 0x478 */ f32 unk_478[25];
    /* 0x4DC */ f32 unk_4DC[25];
    /* 0x540 */ f32 unk_540[25];
    /* 0x5A4 */ f32 unk_5A4[25];
    /* 0x608 */ f32 unk_608[25];
    /* 0x66C */ s32 unk_66C[25];
    /* 0x6D0 */ s32 unk_6D0[25];
    /* 0x734 */ s32 unk_734[25];
} TubbaHeartAttackFXData; // size = 0x798

#define MAX_WHIRLWIND_SEGMENTS 8

typedef struct WhirlwindFXData {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ Vec3f pos;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ s32 unk_14;
    /* 0x018 */ s32 primR;
    /* 0x01C */ s32 primG;
    /* 0x020 */ s32 primB;
    /* 0x024 */ s32 primAlpha;
    /* 0x028 */ s32 envR;
    /* 0x02C */ s32 envG;
    /* 0x030 */ s32 envB;
    /* 0x034 */ f32 unk_34;
    /* 0x038 */ f32 unk_38[MAX_WHIRLWIND_SEGMENTS];
    /* 0x058 */ f32 unk_58[MAX_WHIRLWIND_SEGMENTS];
    /* 0x078 */ f32 unk_78[MAX_WHIRLWIND_SEGMENTS];
    /* 0x098 */ f32 unk_98[MAX_WHIRLWIND_SEGMENTS];
    /* 0x0B8 */ f32 unk_B8[MAX_WHIRLWIND_SEGMENTS];
    /* 0x0D8 */ f32 unk_D8[MAX_WHIRLWIND_SEGMENTS];
    /* 0x0F8 */ f32 unk_F8[MAX_WHIRLWIND_SEGMENTS];
    /* 0x118 */ f32 unk_118[MAX_WHIRLWIND_SEGMENTS];
    /* 0x138 */ f32 unk_138;
    /* 0x13C */ f32 unk_13C;
    /* 0x140 */ f32 unk_140;
} WhirlwindFXData; // size = 0x144

// Likely to be the same as GreenImpactFXData and ShockwaveFXData
typedef struct RedImpactFXData {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[2]; // likely padding
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ Color_RGB8 unk_50;
    /* 0x53 */ Color_RGB8 unk_53;
    /* 0x56 */ char unk_56[2]; // likely padding
} RedImpactFXData; // size = 0x58

typedef struct FloatingCloudPuffFXData {
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
    /* 0x38 */ f32 unk_38;
} FloatingCloudPuffFXData; // size = 0x3C

typedef struct EnergyInOutFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 scale;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
} EnergyInOutFXData; // size = 0x48

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
    /* 0x1C */ f32 scale;
    /* 0x20 */ Vec3f rot;
    /* 0x2C */ Vec2f offset;
    /* 0x34 */ u8 unk_34;
    /* 0x35 */ u8 unk_35;
} TattleWindowFXData; // size = 0x38

typedef struct ShinyFlareFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifeTime;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
} ShinyFlareFXData; // size = 0x30

typedef struct HuffPuffBreathFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifeTime;
    /* 0x18 */ s32 primR;
    /* 0x1C */ s32 primG;
    /* 0x20 */ s32 primB;
    /* 0x24 */ s32 primA;
    /* 0x28 */ s32 envR;
    /* 0x2C */ s32 envG;
    /* 0x30 */ s32 envB;
    /* 0x34 */ s32 envA;
    /* 0x38 */ f32 texOffsetX;
    /* 0x3C */ f32 speedX;
    /* 0x40 */ f32 texOffsetY;
    /* 0x44 */ f32 speedY;
    /* 0x48 */ f32 angle;
    /* 0x4C */ f32 scale;
} HuffPuffBreathFXData; // size = 0x50

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
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifeTime;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ f32 unk_38;
} HieroglyphsFXData; // size = 0x3C

typedef struct MiscParticlesFXData {
    /* 0x00 */ s32 variation;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 scaleX;
    /* 0x14 */ f32 scaleY;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ char unk_20[4];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 animTime;
    /* 0x30 */ s32 timeLeft;
    /* 0x34 */ s32 lifetime;
    /* 0x38 */ Color4i innerColor;
    /* 0x48 */ Color4i glowColor;
    /* 0x58 */ f32 scale;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
} MiscParticlesFXData; // size = 0x64

typedef struct StaticStatusFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 frame; // not visible when negative
    /* 0x24 */ f32 rotation;
    /* 0x28 */ s32 timeLeft;
    /* 0x2C */ s32 lifetime;
    /* 0x30 */ s32 alpha;
    /* 0x34 */ f32 scale;
} StaticStatusFXData; // size = 0x38

typedef struct MovingCloudFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
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
    /* 0x44 */ f32 unk_44;
} MovingCloudFXData; // size = 0x48

typedef struct Effect75FXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ Color3i primCol;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ Color3i envCol;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 masterAlpha;
    /* 0x3C */ f32 scale;
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

typedef struct FireworkRocketFXData {
    /* 0x00 */ s32 variation;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f velocity;
    /* 0x1C */ s32 timeLeft;
    /* 0x20 */ s32 lifeTime;
    /* 0x24 */ s32 r;
    /* 0x28 */ s32 g;
    /* 0x2C */ s32 b;
    /* 0x30 */ s32 minBlurAlpha;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ f32 radius;
    /* 0x48 */ f32 maxRadius;
    /* 0x4C */ s32 isExploded;
    /* 0x50 */ f32 rocketX[4];
    /* 0x60 */ f32 rocketY[4];
    /* 0x70 */ f32 rocketZ[4];
    /* 0x80 */ f32 rocketVelocityX[4];
    /* 0x90 */ f32 rocketVelocityY[4];
    /* 0xA0 */ f32 rocketVelocityZ[4];
} FireworkRocketFXData; // size = 0xB0

typedef struct PeachStarBeamSpirit {
    /* 0x00 */ s32 flags;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f lockedPos;
} PeachStarBeamSpirit; // size = 0x1C

typedef struct PeachStarBeamFXData {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifetime;
    /* 0x18 */ s32 primR;
    /* 0x1C */ s32 primG;
    /* 0x20 */ s32 primB;
    /* 0x24 */ s32 beamAlpha;
    /* 0x28 */ s32 envR;
    /* 0x2C */ s32 envG;
    /* 0x30 */ s32 envB;
    /* 0x34 */ s32 envA;
    /* 0x38 */ f32 beamScale;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ f32 rotationSpeed;
    /* 0x44 */ f32 rotationAngle;
    /* 0x48 */ f32 circleRadius;
    /* 0x4C */ Vec3f circleCenter;
    /* 0x58 */ f32 twinkYOffset;
    /* 0x5C */ PeachStarBeamSpirit spirits[8];
} PeachStarBeamFXData; // size = 0x13C

typedef struct ChapterChangeFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec2f chapterPos;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ Vec2f endOfPos;
    /* 0x18 */ s32 timeLeft;
    /* 0x1C */ s32 lifetime;
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
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifetime;
    /* 0x18 */ Color4i primCol;
    /* 0x28 */ Color4i envCol;
    /* 0x38 */ f32 scale;
    /* 0x3C */ f32 rotation;
    /* 0x40 */ f32 angularVel;
    /* 0x44 */ f32 animFrame;
    /* 0x48 */ f32 animRate;
    /* 0x4C */ Vec3f vel;
    /* 0x58 */ f32 gravAccel;
} IceShardFXData; // size = 0x5C

typedef struct SpiritCardFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ struct EffectInstance* unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 yaw;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ u8 chapter;
    /* 0x35 */ char unk_35[3];
} SpiritCardFXData; // size = 0x38

#define MAX_LIL_OINKS 11

enum LilOinkFlags {
    LIL_OINK_FLAG_VISIBLE = 1,
    LIL_OINK_FLAG_ANIM_CHANGED = 2,
};

enum LilOinkTypes {
    LIL_OINK_TYPE_BLACK     = 0,
    LIL_OINK_TYPE_WHITE     = 1,
    LIL_OINK_TYPE_PINK      = 2,
    LIL_OINK_TYPE_PIKACHU   = 3,
    LIL_OINK_TYPE_SHROOM    = 4,
    LIL_OINK_TYPE_FLOWER    = 5,
    LIL_OINK_TYPE_STAR      = 6,
    LIL_OINK_TYPE_QUESTION  = 7,
    LIL_OINK_TYPE_SILVER    = 8,
    LIL_OINK_TYPE_GOLD      = 9,
};

enum LilOinkAnims {
    LIL_OINK_ANIM_0 = 0,
    LIL_OINK_ANIM_1 = 1,
    LIL_OINK_ANIM_2 = 2,
    LIL_OINK_ANIM_3 = 3,
    LIL_OINK_ANIM_4 = 4,
    LIL_OINK_ANIM_5 = 5,
};

typedef struct LilOinkFXData {
    /* 0x000 */ s32 timeLeft;
    /* 0x004 */ s32 lifetime;
    /* 0x008 */ s32 flags[MAX_LIL_OINKS];
    /* 0x034 */ f32 x[MAX_LIL_OINKS];
    /* 0x060 */ f32 y[MAX_LIL_OINKS];
    /* 0x08C */ f32 z[MAX_LIL_OINKS];
    /* 0x0B8 */ f32 rot[MAX_LIL_OINKS];
    /* 0x0E4 */ u8 type[MAX_LIL_OINKS];
    /* 0x0EF */ s8 nextAnim[MAX_LIL_OINKS];
    /* 0x0FA */ u8 anim[MAX_LIL_OINKS];
    /* 0x105 */ u8 gfxFrame[MAX_LIL_OINKS];
    /* 0x110 */ f32 jumpOffset[MAX_LIL_OINKS];
    /* 0x13C */ s8 animTime[MAX_LIL_OINKS];
} LilOinkFXData; // size = 0x148

typedef struct SomethingRotatingFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ u8 primAlpha;
    /* 0x25 */ s8 unk_25;
    /* 0x26 */ Color_RGB8 env;
    /* 0x29 */ u8 state;
    /* 0x2A */ char unk_2A[2];
    /* 0x2C */ f32 unk_2C;
} SomethingRotatingFXData; // size = 0x30

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
} BuffData; // size = 0xA

typedef struct PartnerBuffFXData {
    /* 0x00 */ s16 useRandomValues;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 timeLeft;
    /* 0x08 */ s32 lifeTime;
    /* 0x0C */ BuffData unk_0C[3];
} PartnerBuffFXData; // size = 0x2C

typedef struct QuizmoAssistantFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f position;
    /* 0x10 */ s32 vanishTimer;
    /* 0x14 */ s32 lifetime;
    /* 0x18 */ s32 fadeInAmt; // 0 = all-black, FF = fully-visible
    /* 0x1C */ s32 anim;
} QuizmoAssistantFXData; // size = 0x20

typedef struct IcePillarFXData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifeTime;
    /* 0x18 */ Color_RGBA8 prim;
    /* 0x1C */ Color_RGBA8 env;
    /* 0x20 */ f32 scale;
    /* 0x24 */ s8 unk_24;
    /* 0x25 */ s8 unk_25;
    /* 0x26 */ char unk_26[0x2];
    /* 0x28 */ struct EffectInstance* miscParticles;
} IcePillarFXData; // size = 0x2C

// sun shine directions
enum {
    FX_SUN_FROM_LEFT    = 0,
    FX_SUN_FROM_RIGHT   = 1,
};

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
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40[4];
    /* 0x50 */ s32 unk_50[4];
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ s32 unk_68;
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ s32 unk_74;
} StarSpiritsEnergyFXData; // size = 0x78

typedef struct PinkSparklesFXData {
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
    /* 0x28 */ s32 unk_28;
} PinkSparklesFXData; // size = 0x2C

typedef struct StarOutlineFXData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ s32 timeLeft;
    /* 0x14 */ s32 lifeTime;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ Vec3f unk_3C;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
} StarOutlineFXData; // size = 0x58

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
    void*                               quizmoAnswer;
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
void fx_shattering_stones(s32, f32, f32, f32, f32);
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
EffectInstance* fx_46(s32, PlayerStatus*, f32, s32);
EffectInstance* fx_gather_magic(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_attack_result_text(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_small_gold_sparkle(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_flashing_box_shockwave(s32, f32, f32, f32, f32, f32);
EffectInstance* fx_balloon(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_floating_rock(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* fx_chomp_drop(s32, f32, f32, f32, f32, s32, f32, s32, f32, s32);
EffectInstance* fx_quizmo_stage(s32, f32, f32, f32);
EffectInstance* fx_radiating_energy_orb(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_quizmo_answer(s32, f32, f32, f32);
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

void fx_sun_undeclared(s32, s32, s32, s32, s32, s32);

#endif
