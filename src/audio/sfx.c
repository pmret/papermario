#include "common.h"
#include "audio.h"

#define MAX_SOUND_INSTANCES 10

SHIFT_BSS u16 gCurrentDoorSounds;
SHIFT_BSS u16 gCurrentRoomDoorSounds;

#define SOUND_LOOP_IDX(soundID) (soundID & 0xFFFF)

// map logical looping soundIDs to raw ones
s32 LoopingSounds[] = {
    [SOUND_LOOP_IDX(SOUND_LOOP_BOMBETTE_FUSE)] SOUND_LRAW_BOMBETTE_FUSE,
    [SOUND_LOOP_IDX(SOUND_LOOP_BOBOMB_FUSE)] SOUND_LRAW_BOBOMB_FUSE,
    [SOUND_LOOP_IDX(SOUND_LOOP_ISK_FLIP_STAIRS)] SOUND_ISK_FLIP_STAIRS,
    [SOUND_LOOP_IDX(SOUND_LOOP_ISK_LOWER_STAIRS)] SOUND_LRAW_ISK_LOWER_STAIRS,
    [SOUND_LOOP_IDX(SOUND_LOOP_TRD_02_LOWER_STAIRS)] SOUND_LRAW_TRD_02_LOWER_STAIRS,
    [SOUND_LOOP_IDX(SOUND_LOOP_TRD_04_LOWER_STAIRS)] SOUND_LRAW_TRD_04_LOWER_STAIRS,
    [SOUND_LOOP_IDX(SOUND_LOOP_TRD_FLOWING_WATER)] SOUND_LRAW_TRD_FLOWING_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TRD_RAISE_STAIRS)] SOUND_LRAW_TRD_RAISE_STAIRS,
    [SOUND_LOOP_IDX(SOUND_LOOP_CHEERING)] SOUND_LRAW_CHEERING,
    [SOUND_LOOP_IDX(SOUND_LOOP_IWA10_FLOW1)] SOUND_LRAW_WATER_FLOWING_1,
    [SOUND_LOOP_IDX(SOUND_LOOP_IWA_UNUSED_FLOW3)] SOUND_LRAW_WATER_FLOWING_3,
    [SOUND_LOOP_IDX(SOUND_LOOP_IWA00_FLOW3)] SOUND_LRAW_WATER_FLOWING_3,
    [SOUND_LOOP_IDX(SOUND_LOOP_IWA00_FLOW2)] SOUND_LRAW_WATER_FLOWING_2,
    [SOUND_LOOP_IDX(SOUND_LOOP_IWA01_FLOW1)] SOUND_LRAW_WATER_FLOWING_1,
    [SOUND_LOOP_IDX(SOUND_LOOP_IWA01_FLOW2)] SOUND_LRAW_WATER_FLOWING_2,
    [SOUND_LOOP_IDX(SOUND_LOOP_OBK_LOWER_CHAIN)] SOUND_LRAW_OBK_LOWER_CHAIN,
    [SOUND_LOOP_IDX(SOUND_LOOP_MOVE_STATUE)] SOUND_LRAW_MOVE_STATUE,
    [SOUND_LOOP_IDX(SOUND_LOOP_SENTINEL_ALARM)] SOUND_LRAW_SENTINEL_ALARM,
    [SOUND_LOOP_IDX(SOUND_LOOP_QUIZ_TICKING)] SOUND_LRAW_QUIZ_TICKING,
    [SOUND_LOOP_IDX(SOUND_LOOP_AUDIENCE_MURMUR)] SOUND_LRAW_AUDIENCE_MURMUR,
    [SOUND_LOOP_IDX(SOUND_LOOP_TOYBOX_TRAIN_GEAR)] SOUND_LRAW_TOYBOX_TRAIN_GEAR,
    [SOUND_LOOP_IDX(SOUND_LOOP_OMO_SLOT_MACHINE)] SOUND_LRAW_OMO_SLOT_MACHINE,
    [SOUND_LOOP_IDX(SOUND_LOOP_OMO_ROTATING_WHEEL)] SOUND_LRAW_OMO_ROTATING_WHEEL,
    [SOUND_LOOP_IDX(SOUND_LOOP_JAN_BEACH_WAVES)] SOUND_LRAW_JAN_BEACH_WAVES,
    [SOUND_LOOP_IDX(SOUND_LOOP_MOVE_LARGE_STATUE)] SOUND_LRAW_MOVE_LARGE_STATUE,
    [SOUND_LOOP_IDX(SOUND_LOOP_ZIPLINE_RIDE)] SOUND_LRAW_ZIPLINE_RIDE,
    [SOUND_LOOP_IDX(SOUND_LOOP_ZIPLINE_RETURN)] SOUND_LRAW_ZIPLINE_RETURN,
    [SOUND_LOOP_IDX(SOUND_LOOP_TROMP_ROLL)] SOUND_LRAW_TROMP_ROLL,
    [SOUND_LOOP_IDX(SOUND_LOOP_JAN_SMALL_GEYSER)] SOUND_LRAW_JAN_SMALL_GEYSER,
    [SOUND_LOOP_IDX(SOUND_LOOP_JAN_LARGE_GEYSER)] SOUND_LRAW_JAN_LARGE_GEYSER,
    [SOUND_LOOP_IDX(SOUND_LOOP_JAN_CONSTRUCTION)] SOUND_LRAW_JAN_CONSTRUCTION,
    [SOUND_LOOP_IDX(SOUND_LOOP_NOTHING_1F)] SOUND_NONE,
    [SOUND_LOOP_IDX(SOUND_LOOP_NOTHING_20)] SOUND_NONE,
    [SOUND_LOOP_IDX(SOUND_LOOP_FLO_WATER_FLOW_1)] SOUND_LRAW_FLO_WATER_FLOW_1,
    [SOUND_LOOP_IDX(SOUND_LOOP_FLO_WATER_FLOW_2)] SOUND_LRAW_FLO_WATER_FLOW_2,
    [SOUND_LOOP_IDX(SOUND_LOOP_BUBBLE_DRIFT)] SOUND_LRAW_BUBBLE_DRIFT,
    [SOUND_LOOP_IDX(SOUND_LOOP_FLO_RELEASE_FOUNTAIN)] SOUND_LRAW_FLO_RELEASE_FOUNTAIN,
    [SOUND_LOOP_IDX(SOUND_LOOP_PUFF_PUFF_MACHINE)] SOUND_LRAW_PUFF_PUFF_MACHINE,
    [SOUND_LOOP_IDX(SOUND_LOOP_NOTHING_26)] SOUND_LRAW_NOTHING_26,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK01_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK02_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK02_FLOW2)] SOUND_LRAW_WATER_FLOWING_2,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK02_FLOW3)] SOUND_LRAW_WATER_FLOWING_3,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK03_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK03_FLOW1)] SOUND_LRAW_WATER_FLOWING_1,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK05_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK05_FLOW1)] SOUND_LRAW_WATER_FLOWING_1,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK06_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK06_FLOW2)] SOUND_LRAW_WATER_FLOWING_2,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK06_FLOW3)] SOUND_LRAW_WATER_FLOWING_3,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK06_FLOW4)] SOUND_LRAW_WATER_FLOWING_4,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK08_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK08_FLOW1)] SOUND_LRAW_WATER_FLOWING_1,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK09_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK09_FLOW2)] SOUND_LRAW_WATER_FLOWING_2,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK09_FLOW4)] SOUND_LRAW_WATER_FLOWING_4,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK09_FLOW3)] SOUND_LRAW_WATER_FLOWING_3,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK10_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK_UNUSED1_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK_UNUSED2_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK_UNUSED3_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK_UNUSED3_FLOW4)] SOUND_LRAW_WATER_FLOWING_4,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK_UNUSED3_FLOW3)] SOUND_LRAW_WATER_FLOWING_3,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK_UNUSED3_FLOW2)] SOUND_LRAW_WATER_FLOWING_2,
    [SOUND_LOOP_IDX(SOUND_LOOP_SAM_STAIRS_RISE)] SOUND_LRAW_SAM_STAIRS_RISE,
    [SOUND_LOOP_IDX(SOUND_LOOP_CHARGE_BAR)] SOUND_LRAW_CHARGE_BAR,
    [SOUND_LOOP_IDX(SOUND_LOOP_CRYSTAL_BALL_GLOW)] SOUND_LRAW_CRYSTAL_BALL_GLOW,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK18_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK19_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK19_FLOW3)] SOUND_LRAW_WATER_FLOWING_3,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK19_FLOW4)] SOUND_LRAW_WATER_FLOWING_4,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK20_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK23_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TIK24_WATER)] SOUND_LRAW_TIK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_WINDMILL_EXT)] SOUND_LRAW_WINDMILL_EXT,
    [SOUND_LOOP_IDX(SOUND_LOOP_WINDMILL_GEARS)] SOUND_LRAW_WINDMILL_GEARS,
    [SOUND_LOOP_IDX(SOUND_LOOP_SHY_GUY_CROWD_1)] SOUND_LRAW_SHY_GUY_CROWD_1,
    [SOUND_LOOP_IDX(SOUND_LOOP_SHY_GUY_CROWD_2)] SOUND_LRAW_SHY_GUY_CROWD_2,
    [SOUND_LOOP_IDX(SOUND_LOOP_FLIGHT)] SOUND_FLIGHT,
    [SOUND_LOOP_IDX(SOUND_LOOP_WHALE_GEYSER)] SOUND_LRAW_WHALE_GEYSER,
    [SOUND_LOOP_IDX(SOUND_LOOP_FLO_FILL_WATER_POOL)] SOUND_LRAW_FLO_FILL_WATER_POOL,
    [SOUND_LOOP_IDX(SOUND_LOOP_KPA_CHAIN_DRIVE)] SOUND_LRAW_KPA_CHAIN_DRIVE,
    [SOUND_LOOP_IDX(SOUND_LOOP_KPA_FILL_WATER)] SOUND_LRAW_KPA_FILL_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_KPA_DRAIN_WATER)] SOUND_LRAW_KPA_DRAIN_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_KPA_FLIP_BRIDGE_PANEL)] SOUND_KPA_FLIP_BRIDGE_PANEL,
    [SOUND_LOOP_IDX(SOUND_LOOP_JR_TROOPA_SWIM)] SOUND_LRAW_JR_TROOPA_SWIM,
    [SOUND_LOOP_IDX(SOUND_LOOP_KKJ_RUMBLING)] SOUND_LRAW_KKJ_RUMBLING,
    [SOUND_LOOP_IDX(SOUND_LOOP_OSR_RUMBLING)] SOUND_LRAW_OSR_RUMBLING,
    [SOUND_LOOP_IDX(SOUND_LOOP_MAC_HARBOR_WATER)] SOUND_LRAW_MAC_HARBOR_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_OSR_FOUNTAIN_INTACT)] SOUND_LRAW_OSR_FOUNTAIN_INTACT,
    [SOUND_LOOP_IDX(SOUND_LOOP_OSR_FOUNTAIN_BROKEN)] SOUND_LRAW_OSR_FOUNTAIN_BROKEN,
    [SOUND_LOOP_IDX(SOUND_LOOP_NOK_WATER)] SOUND_LRAW_NOK_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_TRD_WATER_EXT)] SOUND_LRAW_TRD_WATER_EXT,
    [SOUND_LOOP_IDX(SOUND_LOOP_DGB_COLLAPSE)] SOUND_LRAW_DGB_COLLAPSE,
    [SOUND_LOOP_IDX(SOUND_LOOP_SBK_RUINS_RISING)] SOUND_LRAW_SBK_RUINS_RISING,
    [SOUND_LOOP_IDX(SOUND_LOOP_SBK_RUINS_WHIRLWIND)] SOUND_LRAW_SBK_RUINS_WHIRLWIND,
    [SOUND_LOOP_IDX(SOUND_LOOP_SBK_RUINS_RISING_DISTANT)] SOUND_LRAW_SBK_RUINS_RISING_DISTANT,
    [SOUND_LOOP_IDX(SOUND_LOOP_SBK_OASIS_WATER)] SOUND_LRAW_SBK_OASIS_WATER,
    [SOUND_LOOP_IDX(SOUND_LOOP_62)] SOUND_NONE,
    [SOUND_LOOP_IDX(SOUND_LOOP_STAR_SANCTUARY_FAR)] SOUND_LRAW_STAR_SANCTUARY_FAR,
    [SOUND_LOOP_IDX(SOUND_LOOP_STAR_SANCTUARY_NEAR)] SOUND_LRAW_STAR_SANCTUARY_NEAR,
    [SOUND_LOOP_IDX(SOUND_LOOP_STAR_SANCTUARY_INSIDE)] SOUND_LRAW_STAR_SANCTUARY_INSIDE,
    [SOUND_LOOP_IDX(SOUND_LOOP_BOWSER_PROPELLER)] SOUND_LRAW_BOWSER_PROPELLER,
    [SOUND_LOOP_IDX(SOUND_LOOP_STAR_ORB_RISING)] SOUND_LRAW_STAR_ORB_RISING,
    [SOUND_LOOP_IDX(SOUND_LOOP_USE_STAR_BEAM)] SOUND_LRAW_USE_STAR_BEAM,
    [SOUND_LOOP_IDX(SOUND_LOOP_USE_PEACH_BEAM)] SOUND_LRAW_USE_PEACH_BEAM,
    [SOUND_LOOP_IDX(SOUND_LOOP_SPINNING_FLOWER)] SOUND_LRAW_SPINNING_FLOWER,
    [SOUND_LOOP_IDX(SOUND_LOOP_RUMBLE)] SOUND_LRAW_RUMBLE,
    [SOUND_LOOP_IDX(SOUND_LOOP_FIGHTING)] SOUND_LRAW_FIGHTING,
    [SOUND_LOOP_IDX(SOUND_LOOP_KPA_ARENA_TURN_ON)] SOUND_LRAW_KPA_ARENA_TURN_ON,
    [SOUND_LOOP_IDX(SOUND_LOOP_KPA_ARENA_ACTIVE)] SOUND_LRAW_KPA_ARENA_ACTIVE,
};

// all sound IDs for alternating sounds
s32 FireBar0Sounds[] = { SOUND_FIRE_BAR_0_A, SOUND_FIRE_BAR_0_B };
s32 FireBar1Sounds[] = { SOUND_FIRE_BAR_1_A, SOUND_FIRE_BAR_1_B };
s32 FireBar2Sounds[] = { SOUND_FIRE_BAR_2_A, SOUND_FIRE_BAR_2_B };
s32 FireBar3Sounds[] = { SOUND_FIRE_BAR_3_A, SOUND_FIRE_BAR_3_B };
s32 FireBar4Sounds[] = { SOUND_FIRE_BAR_4_A, SOUND_FIRE_BAR_4_B };
s32 FireBar5Sounds[] = { SOUND_FIRE_BAR_5_A, SOUND_FIRE_BAR_5_B };
s32 FireBar6Sounds[] = { SOUND_FIRE_BAR_6_A, SOUND_FIRE_BAR_6_B };
s32 FireBar7Sounds[] = { SOUND_FIRE_BAR_7_A, SOUND_FIRE_BAR_7_B };
s32 FireBar8Sounds[] = { SOUND_FIRE_BAR_8_A, SOUND_FIRE_BAR_8_B };
s32 FireBar9Sounds[] = { SOUND_FIRE_BAR_9_A, SOUND_FIRE_BAR_9_B };
s32 FireBarDeadSounds[] = { SOUND_FIRE_BAR_DEAD, SOUND_FIRE_BAR_DEAD };
s32 AlertSounds[] = { SOUND_AI_ALERT_A, SOUND_AI_ALERT_B };
s32 SnoreInhaleSounds[] = { SOUND_SNORE_INHALE_A, SOUND_SNORE_INHALE_B };
s32 SnoreExhaleSounds[] = { SOUND_SNORE_EXHALE_A, SOUND_SNORE_EXHALE_B };
s32 SnapAwakeSounds[] = { SOUND_SNAP_AWAKE_A, SOUND_SNAP_AWAKE_B };
s32 BooVanishSounds[] = { SOUND_BOO_VANISH_A, SOUND_BOO_VANISH_B };
s32 BooAppearSounds[] = { SOUND_BOO_APPEAR_A, SOUND_BOO_APPEAR_B };
s32 WindowOpenSounds[] = { SOUND_WINDOW_OPEN_A, SOUND_WINDOW_OPEN_B };
s32 WindowCloseSounds[] = { SOUND_WINDOW_CLOSE_A, SOUND_WINDOW_CLOSE_B };
s32 RavenLeapSounds[] = { SOUND_RAVEN_LEAP_A, SOUND_RAVEN_LEAP_B };
s32 RavenFallSounds[] = { SOUND_RAVEN_FALL_A, SOUND_RAVEN_FALL_B, SOUND_RAVEN_FALL_C };
s32 ShootingStarFallSounds[] = { SOUND_SHOOTING_STAR_FALL_A, SOUND_SHOOTING_STAR_FALL_B };
s32 ShootingStarBounceSounds[] = { SOUND_STAR_BOUNCE_A, SOUND_STAR_BOUNCE_B };
s32 FuzzyHopSounds[] = { SOUND_FUZZY_HOP_A, SOUND_FUZZY_HOP_B, SOUND_FUZZY_HOP_C };
s32 BulletBillExplodeSounds[] = { SOUND_BULLET_BILL_EXPLODE_A, SOUND_BULLET_BILL_EXPLODE_B };
s32 LuigiStepSounds[] = { SOUND_LUIGI_STEP_A, SOUND_LUIGI_STEP_B };
s32 TrainChugSounds[] = { SOUND_TRAIN_CHUG_A, SOUND_TRAIN_CHUG_B };
s32 FinaleBridgeCollapseSounds[] = { SOUND_KPA_BRIDGE_COLLAPSE_A, SOUND_KPA_BRIDGE_COLLAPSE_B };
s32 FinaleExplosionSounds[] = { SOUND_KPA_EXPLOSION_A, SOUND_KPA_EXPLOSION_B };
s32 CardShuffleSounds[] = { SOUND_SHUFFLE_CARD_A, SOUND_SHUFFLE_CARD_B };
s32 StarSpiritAppearSounds[] = { SOUND_STAR_SPIRIT_APPEAR_A, SOUND_STAR_SPIRIT_APPEAR_B };
s32 StarSpiritCastSounds[] = { SOUND_STAR_SPIRIT_CAST_A, SOUND_STAR_SPIRIT_CAST_B };
s32 UnusedExplodeSounds[] = { SOUND_BULLET_BILL_EXPLODE_A, SOUND_BULLET_BILL_EXPLODE_B };
s32 ShyGuyStepSounds[] = { SOUND_SHY_GUY_STEP_A, SOUND_SHY_GUY_STEP_B };

#define SEQ_SOUND_ENTRY(soundID, sym) [soundID & 0xFFFF] { .sounds = sym, .soundCount = ARRAY_COUNT(sym) }

// map logical alternating soundIDs to lists of raw ones
AlternatingSoundSet AlternatingSounds[] = {
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_0, FireBar0Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_1, FireBar1Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_2, FireBar2Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_3, FireBar3Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_4, FireBar4Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_5, FireBar5Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_6, FireBar6Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_7, FireBar7Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_8, FireBar8Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_9, FireBar9Sounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FIRE_BAR_DEAD, FireBarDeadSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_AI_ALERT, AlertSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_SNORE_INHALE, SnoreInhaleSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_SNORE_EXHALE, SnoreExhaleSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_SNAP_AWAKE, SnapAwakeSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_BOO_VANISH, BooVanishSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_BOO_APPEAR, BooAppearSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_WINDOW_OPEN, WindowOpenSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_WINDOW_CLOSE, WindowCloseSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_RAVEN_LEAP, RavenLeapSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_RAVEN_FALL, RavenFallSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_SHOOTING_STAR_FALL, ShootingStarFallSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_SHOOTING_STAR_BOUNCE, ShootingStarBounceSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FUZZY_HOP, FuzzyHopSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_BULLET_BILL_EXPLODE, BulletBillExplodeSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_LUIGI_STEP, LuigiStepSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_TRAIN_CHUG, TrainChugSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FINALE_BRIDGE_COLLAPSE, FinaleBridgeCollapseSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_FINALE_EXPLOSION, FinaleExplosionSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_SHUFFLE_CARD, CardShuffleSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_STAR_SPIRIT_APPEAR, StarSpiritAppearSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_STAR_SPIRIT_CAST, StarSpiritCastSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_UNUSED_EXPLODE, UnusedExplodeSounds),
    SEQ_SOUND_ENTRY(SOUND_SEQ_SHY_GUY_STEP, ShyGuyStepSounds),
};

s32 OpenCloseSounds[][2] = {
    { SOUND_BASIC_DOOR_OPEN, SOUND_BASIC_DOOR_CLOSE },
    { SOUND_METAL_DOOR_OPEN, SOUND_METAL_DOOR_CLOSE },
    { SOUND_LARGE_DOOR_OPEN, SOUND_LARGE_DOOR_CLOSE },
    { SOUND_CREAKY_DOOR_OPEN, SOUND_CREAKY_DOOR_CLOSE },
    { SOUND_METAL_GATE_OPEN, SOUND_METAL_GATE_CLOSE },
    { SOUND_WINDOW_OPEN_A, SOUND_WINDOW_CLOSE_A },
    { SOUND_CREAKY_WINDOW_OPEN, SOUND_CREAKY_WINDOW_CLOSE },
};

SHIFT_BSS SoundInstance wEnvSounds[MAX_SOUND_INSTANCES];
SHIFT_BSS SoundInstance bEnvSounds[MAX_SOUND_INSTANCES];
SHIFT_BSS SoundInstance* gCurrentEnvSounds;
SHIFT_BSS s32 SfxReverbMode;

void sfx_compute_spatialized_sound_params_full(f32 x, f32 y, f32 z, s16* volume, s16* pan, s32 flags) {
    s32 screenX, screenY, screenZ;
    f32 volAmtOffsetX, volAmtDeltaY, volAmtDepth;
    f32 offsetX, offsetY, depth;
    f32 volTemp, panTemp;
    s32 phi_v0;

    get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);

    if (screenX > 5000 || screenX < -5000 || screenY > 5000 || screenY < -5000) {
        *volume = -1;
        *pan = 0;
        return;
    }

    if (flags & SOUND_PARAM_CLIP_OFFSCREEN_ANY) {
        if (screenX < -30 || screenX > SCREEN_WIDTH + 30 || screenY < -30 || screenY > SCREEN_HEIGHT + 30) {
            *volume = -1;
            *pan = 0;
            return;
        }
    } else if (flags & SOUND_PARAM_CLIP_OFFSCREEN_X) {
        if (screenX < -30 || screenX > SCREEN_WIDTH + 30) {
            *volume = -1;
            *pan = 0;
            return;
        }
    } else if (flags & SOUND_PARAM_CLIP_OFFSCREEN_Y) {
        if (screenY < -30 || screenY > SCREEN_HEIGHT + 30) {
            *volume = -1;
            *pan = 0;
            return;
        }
    }

    offsetX = abs((SCREEN_WIDTH / 2) - screenX) - 145;
    if (offsetX < 0.0) {
        offsetX = 0.0f;
    }

    volAmtOffsetX = update_lerp(EASING_LINEAR, 1.0f, 0.0f, offsetX, 200);
    if (volAmtOffsetX < 0.0) {
        volAmtOffsetX = 0.0f;
    }

    offsetY = abs((SCREEN_HEIGHT / 2) - screenY) - 105;
    if (offsetY < 0.0) {
        offsetY = 0.0f;
    }

    volAmtDeltaY = update_lerp(EASING_LINEAR, 1.0f, 0.0f, offsetY, 130);
    if (volAmtDeltaY < 0.0) {
        volAmtDeltaY = 0.0f;
    }

    depth = screenZ - 5550.0;
    if (depth < 0.0) {
        depth = 0.0f;
    }

    volAmtDepth = update_lerp(EASING_LINEAR, 1.0f, 0.0f, depth, 250);
    if (volAmtDepth < 0.0) {
        volAmtDepth = 0.0f;
    }

    volTemp = (volAmtOffsetX * volAmtDeltaY * volAmtDepth) * 127.0;
    if (volTemp < 15.0) {
        volTemp = 15.0f;
    } else if (volTemp > 127.0) {
        volTemp = 127.0f;
    }
    *volume = volTemp;

    panTemp = (((f32) screenX - (SCREEN_WIDTH / 2.0)) / 3.6) + 64.0;
    if (panTemp < 1.0) {
        panTemp = 1.0f;
    } else if (panTemp > 127.0) {
        panTemp = 127.0f;
    }
    *pan = panTemp;
}

void sfx_reset_door_sounds(void) {
    gCurrentDoorSounds = DOOR_SOUNDS_BASIC;
    gCurrentRoomDoorSounds = DOOR_SOUNDS_BASIC;
}

void sfx_clear_sounds(void) {
    bzero(&wEnvSounds, sizeof(wEnvSounds));
    bzero(&bEnvSounds, sizeof(bEnvSounds));
    gCurrentEnvSounds = wEnvSounds;
    sfx_set_reverb_mode(0);
    sfx_reset_door_sounds();
}

// name might be incorrect?
void sfx_clear_env_sounds(s16 playSounds) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentEnvSounds = wEnvSounds;
    } else {
        gCurrentEnvSounds = bEnvSounds;
    }

    if (playSounds) {
        SoundInstance* sound = gCurrentEnvSounds;
        s32 i;

        for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
            if (sound->flags & SOUND_INSTANCE_FLAG_ACTIVE) {
                snd_start_sound_with_shift(sound->soundID, sound->volume, sound->pan, sound->pitchShift);
            }
        }
    } else {
        bzero(gCurrentEnvSounds, MAX_SOUND_INSTANCES * sizeof(SoundInstance));
    }
}

void sfx_update_env_sound_params(void) {
    SoundInstance* sound = gCurrentEnvSounds;
    u16 volume;
    u16 pan;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (sound->flags & SOUND_INSTANCE_FLAG_ACTIVE) {
            if (sound->flags & SOUND_INSTANCE_FLAG_POSITION_CHANGED) {
                sfx_get_spatialized_sound_params(sound->pos.x, sound->pos.y, sound->pos.z, &volume, &pan, sound->sourceFlags);
                sound->volume = volume;
                sound->pan = pan;
            }
            snd_adjust_sound_with_shift(sound->soundID, sound->volume, sound->pan, sound->pitchShift);
        }
    }
}

void sfx_set_reverb_mode(s32 mode) {
    func_800561E4(mode);
    SfxReverbMode = mode;
}

s32 sfx_get_reverb_mode(void) {
    return SfxReverbMode;
}

void sfx_stop_env_sounds(void) {
    SoundInstance* sound;
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentEnvSounds = wEnvSounds;
    } else {
        gCurrentEnvSounds = bEnvSounds;
    }

    sound = gCurrentEnvSounds;
    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (sound->flags & SOUND_INSTANCE_FLAG_ACTIVE) {
            snd_stop_sound(sound->soundID);
        }
    }
}

SoundInstance* sfx_get_env_sound_instance(s32 soundID) {
    SoundInstance* sound = gCurrentEnvSounds;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (sound->flags & SOUND_INSTANCE_FLAG_ACTIVE && sound->soundID == soundID) {
            return sound;
        }
    }

    return NULL;
}

void sfx_play_sound_looping(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundInstance* sound = gCurrentEnvSounds;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (!(sound->flags & SOUND_INSTANCE_FLAG_ACTIVE)) {
            break;
        }
    }

    sound->pan = pan;
    sound->soundID = soundID;
    sound->volume = volume;
    sound->pitchShift = pitchShift;
    sound->flags |= SOUND_INSTANCE_FLAG_ACTIVE;

    snd_start_sound_with_shift(soundID, volume, pan, pitchShift);
}

void sfx_register_looping_sound_at_position(s32 soundID, s32 flags, f32 x, f32 y, f32 z) {
    SoundInstance* sound = gCurrentEnvSounds;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (!(sound->flags & SOUND_INSTANCE_FLAG_ACTIVE)) {
            break;
        }
    }

    sound->sourceFlags = flags;
    sound->pos.x = x;
    sound->pos.y = y;
    sound->pos.z = z;
    sound->soundID = soundID;
    sound->flags |= SOUND_INSTANCE_FLAG_ACTIVE | SOUND_INSTANCE_FLAG_POSITION_CHANGED;

    sfx_play_sound_at_position(soundID, flags, x, y, z);
}

s32 sfx_adjust_env_sound_pos(s32 soundID, s32 sourceFlags, f32 x, f32 y, f32 z) {
    SoundInstance* sound = sfx_get_env_sound_instance(soundID);

    if (sound == NULL) {
        return FALSE;
    }

    sound->sourceFlags = sourceFlags;
    sound->pos.x = x;
    sound->pos.y = y;
    sound->pos.z = z;
    sound->soundID = soundID;
    sound->flags |= SOUND_INSTANCE_FLAG_ACTIVE | SOUND_INSTANCE_FLAG_POSITION_CHANGED;
    return TRUE;
}

void snd_stop_tracking_env_sound_pos(s32 soundID, s32 keepPlaying) {
    SoundInstance* sound = sfx_get_env_sound_instance(soundID);

    if (sound != NULL) {
        sound->flags &= ~(SOUND_INSTANCE_FLAG_ACTIVE | SOUND_INSTANCE_FLAG_POSITION_CHANGED);
        if (!keepPlaying) {
            snd_stop_sound(sound->soundID);
        }
    }
}

void sfx_play_sound_with_params(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    AlternatingSoundSet* alternatingSet;

    if (gGameStatusPtr->demoState) {
        return;
    }

    if (soundID & SOUND_TYPE_SPECIAL) {
        s32 soundIndex = soundID & 0xFF;
        s32 soundType = (soundID & 0x70000000) >> 0x1C;
        switch (soundType) {
            case SOUND_TYPE_LOOPING:
                // 0x8xxxxxxx
                sfx_play_sound_looping(LoopingSounds[soundIndex], volume, pan, pitchShift);
                return;
            case SOUND_TYPE_EXIT_DOOR:
                soundID = OpenCloseSounds[gCurrentDoorSounds][soundIndex];
                break;
            case SOUND_TYPE_ROOM_DOOR:
                soundID = OpenCloseSounds[gCurrentRoomDoorSounds][soundIndex];
                break;
            case SOUND_TYPE_ALTERNATING:
                // 0xBxxxxxxx
                alternatingSet = &AlternatingSounds[soundIndex];
                if (alternatingSet->curIndex >= alternatingSet->soundCount) {
                    alternatingSet->curIndex = 0;
                }
                soundID = alternatingSet->sounds[alternatingSet->curIndex++];
                break;
        }
    }
    snd_start_sound_with_shift(soundID, volume, pan, pitchShift);
}

void sfx_adjust_env_sound_params(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundInstance* sound;

    if (soundID & SOUND_TYPE_SPECIAL) {
        sound = sfx_get_env_sound_instance(LoopingSounds[soundID & 0xFFFF]);
        if (sound != NULL) {
            sound->volume = volume;
            sound->pan = pan;
            sound->pitchShift = pitchShift;
        }
    } else {
        snd_adjust_sound_with_shift(soundID, volume, pan, pitchShift);
    }
}

void sfx_stop_sound(s32 soundID) {
    s32 sound = soundID;

    if (sound & SOUND_TYPE_SPECIAL) {
        snd_stop_tracking_env_sound_pos(LoopingSounds[sound & 0xFFFF], FALSE);
    } else {
        snd_stop_sound(sound);
    }
}

void sfx_play_sound(s32 soundID) {
    sfx_play_sound_with_params(soundID, 0, 0, 0);
}

void sfx_play_sound_at_player(s32 soundID, s32 flags) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    sfx_play_sound_at_position(soundID, flags, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z);
}

void sfx_play_sound_at_npc(s32 soundID, s32 flags, s32 npcID) {
    Npc* npc = get_npc_safe(npcID);

    if (npc != NULL) {
        sfx_play_sound_at_position(soundID, flags, npc->pos.x, npc->pos.y, npc->pos.z);
    }
}

void sfx_play_sound_at_position(s32 soundID, s32 flags, f32 posX, f32 posY, f32 posZ) {
    if ((soundID & 0xF0000000) == SOUND_TYPE_SPECIAL) {
        s32 id = LoopingSounds[soundID & 0xFFFF];

        sfx_register_looping_sound_at_position(id, flags, posX, posY, posZ);
    } else {
        s16 volume;
        s16 pan;

        sfx_get_spatialized_sound_params(posX, posY, posZ, &volume, &pan, flags);
        if (volume >= 0) {
            sfx_play_sound_with_params(soundID, volume, pan, 0);
        }
    }
}

void sfx_get_spatialized_sound_params(f32 x, f32 y, f32 z, s16* volume, s16* pan, s32 flags) {
    u32 paramFlags;
    u32 spaceMode;

    paramFlags = flags & SOUND_SPACE_PARAMS_MASK;

    do {
        spaceMode = flags & SOUND_SPACE_MODE_MASK;
    } while (0); // required to match

    switch (spaceMode) {
        case SOUND_SPACE_DEFAULT:
            sfx_compute_spatialized_sound_params_ignore_depth(x, y, z, volume, pan);
            break;
        case SOUND_SPACE_WITH_DEPTH:
            sfx_compute_spatialized_sound_params_with_depth(x, y, z, volume, pan);
            break;
        case SOUND_SPACE_FULL:
            sfx_compute_spatialized_sound_params_full(x, y, z, volume, pan, paramFlags);
            break;
    }

    if (paramFlags & SOUND_PARAM_MUTE) {
        *volume = 0;
    } else if (paramFlags & SOUND_PARAM_QUIET) {
        if (*volume < 80) {
            *volume = 80;
        }
    } else if (paramFlags & SOUND_PARAM_MORE_QUIET) {
        if (*volume < 60) {
            *volume = 60;
        }
    } else if (paramFlags & SOUND_PARAM_MOST_QUIET) {
        if (*volume < 40) {
            *volume = 40;
        }
    }

    if (*pan < 1) {
        *pan = 1;
    }
    if (*pan > 127) {
        *pan = 127;
    }
}

void sfx_compute_spatialized_sound_params_ignore_depth(f32 x, f32 y, f32 z, s16* volume, s16* pan) {
    s32 screenX, screenY, screenZ;

    get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);

    if (screenX > 3000 || screenX < -3000 || screenY > 3000 || screenY < -3000) {
        *volume = 1;
        *pan = 0;
        return;
    }

    *volume = 127;
    if (screenX < 0) {
        *volume = (screenX * 0.3f) + 127.0f;
        screenX = 0;
    }
    if (screenX > SCREEN_WIDTH) {
        *volume = 127.0f - ((screenX - SCREEN_WIDTH) * 0.3f);
        screenX = SCREEN_WIDTH;
    }

    if (*volume < 1) {
        *volume = 1;
    }

    if (!gGameStatusPtr->isBattle) {
        // 25/75 at screen edge
        *pan = (screenX * 0.2f) + 32.0f;
    } else {
        f32 temp_f20 = ((screenX * 127.0) / SCREEN_WIDTH) - 64.0;
        *pan = (s32) (temp_f20 * sin_rad(DEG_TO_RAD(fabs(temp_f20) * 90.0 / 64.0))) + 64;
    }
}

void sfx_compute_spatialized_sound_params_with_depth(f32 x, f32 y, f32 z, s16* volume, s16* pan) {
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 screenX, screenY, screenZ;
    f32 depth;

    get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);

    if (screenX > 3000 || screenX < -3000 || screenY > 3000 || screenY < -3000) {
        *volume = 1;
        *pan = 0;
        return;
    }

    *volume = 127;
    if (screenX < 0) {
        *volume = (screenX * 0.3f) + 127.0f;
        screenX = 0;
    }
    if (camera->viewportW < screenX) {
        *volume = 127.0f - ((screenX - camera->viewportW) * 0.3f);
        screenX = camera->viewportW;
    }

    depth = fabsf(5000 - screenZ);
    if (depth > 1000.0f) {
        depth = 1000.0f;
    }

    *volume = *volume * (1500.0f - depth) * 0.001f;
    if (*volume > 127) {
        *volume = 127;
    }
    if (*volume < 1) {
        *volume = 1;
    }

    *pan = ((screenX * 64.0f) / camera->viewportW) + 32.0f;
}
