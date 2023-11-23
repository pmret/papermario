#ifndef _ENUMS_H_
#define _ENUMS_H_

#include "ultra64.h"
#include "types.h"
#include "saved_byte_names.h"
#include "saved_flag_names.h"

enum StoryProgress {
    STORY_INTRO                                 = -128,
    STORY_CH0_WAKE_UP                           = -127,
    STORY_CH0_MET_INNKEEPER                     = -126,
    STORY_UNUSED_FFFFFF83                       = -125,
    STORY_CH0_MET_GOOMPA                        = -124,
    STORY_CH0_GATE_CRUSHED                      = -123,
    STORY_CH0_FELL_OFF_CLIFF                    = -122,
    STORY_CH0_GOOMPA_JOINED_PARTY               = -121,
    STORY_CH0_LOOKING_FOR_HAMMER                = -120,
    STORY_CH0_FOUND_HAMMER                      = -119,
    STORY_CH0_DEFEATED_JR_TROOPA                = -118,
    STORY_CH0_LEFT_THE_PLAYGROUND               = -117,
    STORY_UNUSED_FFFFFF8C                       = -116,
    STORY_CH0_GOOMBARIO_JOINED_PARTY            = -115,
    STORY_CH0_SMASHED_GATE_BLOCK                = -114,
    STORY_CH0_DEFEATED_GOOMBA_BROS              = -113,
    STORY_CH0_DEFEATED_GOOMBA_KING              = -112,
    STORY_CH0_FOUND_GATEHOUSE_SWITCH            = -111,
    STORY_CH0_HIT_GATEHOUSE_SWITCH              = -110,
    STORY_CH0_OPENED_BRIDGE_TO_TOAD_TOWN        = -109,
    STORY_CH0_KAMMY_RETURNED_TO_BOWSER          = -108,
    STORY_CH0_ARRIVED_AT_TOAD_TOWN              = -107,
    STORY_CH0_MET_STAR_SPIRITS                  = -106,
    STORY_CH0_BEGAN_PEACH_MISSION               = -105,
    STORY_CH0_TWINK_GAVE_LUCKY_STAR             = -104,
    STORY_CH0_RETURNED_TO_TOAD_TOWN             = -103,
    STORY_CH1_SPOKE_WITH_MERLIN                 = -102,
    STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS      = -101,
    STORY_CH1_MERLIN_REVEALED_KOOPA_BROS        = -100,
    STORY_CH1_KNOCKED_SWITCH_FROM_TREE          = -99,
    STORY_CH1_MADE_FIRST_BRIDGE                 = -98,
    STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE          = -97,
    STORY_CH1_PROMISED_TO_HELP_KOOPER           = -96,
    STORY_CH1_FUZZY_THIEF_LEFT_TOWN             = -95,
    STORY_CH1_FUZZY_THIEF_RAN_AWAY              = -94,
    STORY_CH1_FUZZY_THIEF_HID_IN_TREE           = -93,
    STORY_CH1_KOOPER_JOINED_PARTY               = -92,
    STORY_CH1_MADE_SECOND_BRIDGE                = -91,
    STORY_CH1_ARRIVED_AT_KOOPA_FORTRESS         = -90,
    STORY_CH1_SPOTTED_BY_KOOPA_BROS             = -89,
    STORY_CH1_KOOPA_BROS_HID_KEY                = -88,
    STORY_CH1_DEFEATED_BASEMENT_GUARD           = -87,
    STORY_CH1_LOWERED_FIRST_STAIRS              = -86,
    STORY_CH1_KOOPA_BROS_SET_TRAP               = -85,
    STORY_CH1_MARIO_ACTIVATED_TRAP              = -84,
    STORY_CH1_BOMBETTE_JOINED_PARTY             = -83,
    STORY_CH1_DEFEATED_DUNGEON_GUARDS           = -82,
    STORY_CH1_LOWERED_SECOND_STAIRS             = -81,
    STORY_CH1_RAISED_SUBMERGED_STAIRS           = -80,
    STORY_CH1_KOOPA_BROS_FIRING_BLASTERS        = -79,
    STORY_CH1_DEFEATED_KOOPA_BROS               = -78,
    STORY_CH1_STAR_SPIRIT_RESCUED               = -77,
    STORY_CH1_BEGAN_PEACH_MISSION               = -76,
    STORY_CH1_STAR_SPRIT_DEPARTED               = -75,
    STORY_CH1_DEFEATED_JR_TROOPA                = -74,
    STORY_CH1_RETURNED_TO_TOAD_TOWN             = -73,
    STORY_CH2_ARRIVED_AT_MT_RUGGED              = -72,
    STORY_CH2_SPOKE_WITH_PARAKARRY              = -71,
    STORY_CH2_PARAKARRY_JOINED_PARTY            = -70,
    STORY_CH2_ARRIVED_AT_DRY_DRY_DESERT         = -69,
    STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST        = -68,
    STORY_CH2_SHADY_MOUSE_LEFT_SHOP             = -67,
    STORY_CH2_SPOKE_WITH_SHEEK                  = -66,
    STORY_CH2_SHADY_MOUSE_ENTERED_SHOP          = -65,
    STORY_CH2_BOUGHT_SECRET_ITEMS               = -64,
    STORY_CH2_GOT_PULSE_STONE                   = -63,
    STORY_CH2_UNCOVERED_DRY_DRY_RUINS           = -62,
    STORY_CH2_DRAINED_FIRST_SAND_ROOM           = -61,
    STORY_CH2_DRAINED_SECOND_SAND_ROOM          = -60,
    STORY_CH2_GOT_SUPER_HAMMER                  = -59,
    STORY_CH2_DRAINED_THIRD_SAND_ROOM           = -58,
    STORY_CH2_SOLVED_ARTIFACT_PUZZLE            = -57,
    STORY_CH2_DEFEATED_TUTANKOOPA               = -56,
    STORY_CH2_STAR_SPIRIT_RESCUED               = -55,
    STORY_CH2_BEGAN_PEACH_MISSION               = -54,
    STORY_CH2_STAR_SPRIT_DEPARTED               = -53,
    STORY_UNUSED_FFFFFFCC                       = -52,
    STORY_CH3_SAW_BOO_ENTER_FOREST              = -51,
    STORY_CH3_INVITED_TO_BOOS_MANSION           = -50,
    STORY_CH3_ALLOWED_INTO_FOREVER_FOREST       = -49,
    STORY_CH3_ARRIVED_AT_BOOS_MANSION           = -48,
    STORY_CH3_OPENED_BOOS_MANSION_GATE          = -47,
    STORY_CH3_ENTERED_BOOS_MANSION              = -46,
    STORY_CH3_TRIGGERED_DOOR_JUMP_SCARE         = -45,
    STORY_CH3_GOT_RECORD                        = -44,
    STORY_CH3_PLAYED_THE_RECORD                 = -43,
    STORY_CH3_GOT_WEIGHT                        = -42,
    STORY_CH3_WEIGHED_DOWN_CHANDELIER           = -41,
    STORY_CH3_GOT_SUPER_BOOTS                   = -40,
    STORY_CH3_HIT_HUGE_BLUE_SWITCH              = -39,
    STORY_CH3_GOT_BOO_PORTRAIT                  = -38,
    STORY_CH3_RESTORED_BOO_PORTRAIT             = -37,
    STORY_CH3_BOW_JOINED_PARTY                  = -36,
    STORY_CH3_UNLOCKED_GUSTY_GULCH              = -35,
    STORY_CH3_ARRIVED_AT_GHOST_TOWN             = -34,
    STORY_CH3_SAW_TUBBA_EAT_BOO                 = -33,
    STORY_CH3_ARRIVED_AT_TUBBAS_MANOR           = -32,
    STORY_UNUSED_FFFFFFE1                       = -31,
    STORY_CH3_TUBBA_BEGAN_NAPPING               = -30,
    STORY_CH3_TUBBA_WOKE_UP                     = -29,
    STORY_CH3_TUBBA_SMASHED_THE_BRIDGES         = -28,
    STORY_CH3_TUBBA_CHASED_MARIO_IN_HALL        = -27,
    STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER       = -26,
    STORY_CH3_ESCAPED_TUBBAS_MANOR              = -25,
    STORY_CH3_UNLOCKED_WINDY_MILL               = -24,
    STORY_CH3_WENT_DOWN_THE_WELL                = -23,
    STORY_CH3_HEART_FLED_FIRST_TUNNEL           = -22,
    STORY_UNUSED_FFFFFFEB                       = -21,
    STORY_UNUSED_FFFFFFEC                       = -20,
    STORY_CH3_HEART_FLED_SECOND_TUNNEL          = -19,
    STORY_CH3_HEART_ESCAPED_WELL                = -18,
    STORY_CH3_HEART_ESCAPED_WINDY_MILL          = -17,
    STORY_CH3_DEFEATED_TUBBA_BLUBBA             = -16,
    STORY_CH3_STAR_SPIRIT_RESCUED               = -15,
    STORY_CH3_BEGAN_PEACH_MISSION               = -14,
    STORY_CH3_STAR_SPRIT_DEPARTED               = -13,
    STORY_CH4_FRYING_PAN_STOLEN                 = -12,
    STORY_CH4_MET_WITH_TWINK                    = -11,
    STORY_CH4_FOUND_HIDDEN_DOOR                 = -10,
    STORY_CH4_ENTERED_THE_TOY_BOX               = -9,
    STORY_CH4_GOT_STOREROOM_KEY                 = -8,
    STORY_CH4_RETURNED_STOREROOM_KEY            = -7,
    STORY_CH4_GOT_TOY_TRAIN                     = -6,
    STORY_CH4_RETURNED_TOY_TRAIN                = -5,
    STORY_CH4_GOT_FRYING_PAN                    = -4,
    STORY_CH4_GOT_TAYCE_TS_CAKE                 = -3,
    STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY          = -2,
    STORY_CH4_PULLED_SWITCH_SWITCH              = -1,
    STORY_CH4_SOLVED_COLOR_PUZZLE               = 0,
    STORY_CH4_DEFEATED_LANTERN_GHOST            = 1,
    STORY_CH4_WATT_JOINED_PARTY                 = 2,
    STORY_CH4_OPENED_GENERAL_GUY_ROOM           = 3,
    STORY_CH4_DEFEATED_GENERAL_GUY              = 4,
    STORY_CH4_STAR_SPIRIT_RESCUED               = 5,
    STORY_CH4_BEGAN_PEACH_MISSION               = 6,
    STORY_CH4_STAR_SPRIT_DEPARTED               = 7,
    STORY_CH5_WHALE_MOUTH_OPEN                  = 8,
    STORY_CH5_ENTERED_WHALE                     = 9,
    STORY_CH5_DEFEATED_FUZZIPEDE                = 10,
    STORY_CH5_REACHED_LAVA_LAVA_ISLAND          = 11,
    STORY_CH5_KOLORADO_ESCAPED_FUZZIES          = 12,
    STORY_CH5_KOLORADO_ESCAPED_SPEAR_GUYS       = 13,
    STORY_CH5_YOSHI_CHILDREN_ARE_MISSING        = 14,
    STORY_CH5_SUSHIE_JOINED_PARTY               = 15,
    STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED        = 16,
    STORY_CH5_GOT_JADE_RAVEN                    = 17,
    STORY_CH5_MOVED_RAVEN_STATUE                = 18,
    STORY_CH5_DEFEATED_PIRANHAS_MINIBOSS        = 19,
    STORY_CH5_REACHED_RAPHAELS_TREE             = 20,
    STORY_CH5_RAPHAEL_LEFT_NEST                 = 21,
    STORY_CH5_RAPHAEL_MOVED_ROOT                = 22,
    STORY_CH5_RAPHAEL_WAITING_FOR_MARIO         = 23,
    STORY_CH5_ZIP_LINE_READY                    = 24,
    STORY_CH5_ENTERED_MT_LAVA_LAVA              = 25,
    STORY_CH5_KOLORADO_FELL_IN_LAVA             = 26,
    STORY_CH5_LAVA_STREAM_BLOCKED               = 27,
    STORY_CH5_GOT_ULTRA_HAMMER                  = 28,
    STORY_CH5_SMASHED_ULTRA_BLOCK               = 29,
    STORY_CH5_KOLORADO_FELL_IN_PIT              = 30,
    STORY_CH5_KOLORADO_AT_DEAD_END              = 31,
    STORY_CH5_HIDDEN_PASSAGE_OPEN               = 32,
    STORY_CH5_KOLORADO_RAN_AHEAD                = 33,
    STORY_CH5_KOLORADO_IN_TREASURE_ROOM         = 34,
    STORY_CH5_DEFEATED_LAVA_PIRANHA             = 35,
    STORY_CH5_MT_LAVA_LAVA_ERUPTING             = 36,
    STORY_CH5_OPENED_ESCAPE_ROUTE               = 37,
    STORY_CH5_BEGAN_PEACH_MISSION               = 38,
    STORY_CH5_STAR_SPRIT_DEPARTED               = 39,
    STORY_CH5_TRADED_VASE_FOR_SEED              = 40,
    STORY_CH5_RETURNED_TO_TOAD_TOWN             = 41,
    STORY_CH6_FLOWER_GATE_OPEN                  = 42,
    STORY_CH6_ARRIVED_AT_FLOWER_FIELDS          = 43,
    STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES       = 44,
    STORY_CH6_GOT_MAGICAL_BEAN                  = 45,
    STORY_CH6_GOT_FERTILE_SOIL                  = 46,
    STORY_CH6_GOT_CRYSTAL_BERRY                 = 47,
    STORY_CH6_GOT_WATER_STONE                   = 48,
    STORY_CH6_FILLED_SPRING_WITH_WATER          = 49,
    STORY_CH6_SPOKE_WITH_THE_SUN                = 50,
    STORY_CH6_LAKILESTER_JOINED_PARTY           = 51,
    STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS         = 52,
    STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE       = 53,
    STORY_CH6_WISTERWOOD_GAVE_HINT              = 54,
    STORY_CH6_GREW_MAGIC_BEANSTALK              = 55,
    STORY_CH6_DEFEATED_HUFF_N_PUFF              = 56,
    STORY_CH6_STAR_SPIRIT_RESCUED               = 57,
    STORY_CH6_BEGAN_PEACH_MISSION               = 58,
    STORY_CH6_STAR_SPRIT_DEPARTED               = 59,
    STORY_CH6_RETURNED_TO_TOAD_TOWN             = 60,
    STORY_CH7_INVITED_TO_STARBORN_VALLEY        = 61,
    STORY_CH7_ARRIVED_AT_SHIVER_CITY            = 62,
    STORY_CH7_MAYOR_MURDER_MYSTERY              = 63,
    STORY_CH7_SHATTERED_FROZEN_POND             = 64,
    STORY_CH7_SPOKE_WITH_HERRINGWAY             = 65,
    STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE        = 66,
    STORY_CH7_MAYOR_MURDER_SOLVED               = 67,
    STORY_CH7_DEFEATED_JR_TROOPA                = 68,
    STORY_CH7_DEFEATED_MONSTAR                  = 69,
    STORY_CH7_ARRIVED_AT_STARBORN_VALLEY        = 70,
    STORY_CH7_MERLE_APOLOGIZED                  = 71,
    STORY_CH7_GOT_SNOWMAN_SCARF                 = 72,
    STORY_CH7_GOT_SNOWMAN_BUCKET                = 73,
    STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN          = 74,
    STORY_CH7_DEFEATED_FIRST_DUPLIGHOST         = 75,
    STORY_CH7_GOT_STAR_STONE                    = 76,
    STORY_CH7_RAISED_FROZEN_STAIRS              = 77,
    STORY_CH7_ARRIVED_AT_CRYSTAL_PALACE         = 78,
    STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS       = 79,
    STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS     = 80,
    STORY_CH7_DEFEATED_CLUBBAS                  = 81,
    STORY_CH7_DEFEATED_KOOPER_DUPLIGHOSTS       = 82,
    STORY_CH7_EXTENDED_PALACE_BRIDGE            = 83,
    STORY_CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE    = 84,
    STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE         = 85,
    STORY_CH7_DEFEATED_CRYSTAL_KING             = 86,
    STORY_CH7_STAR_SPIRIT_RESCUED               = 87,
    STORY_CH7_BEGAN_PEACH_MISSION               = 88,
    STORY_CH7_STAR_SPRIT_DEPARTED               = 89,
    STORY_CH8_OPENED_PATH_TO_STAR_WAY           = 90,
    STORY_CH8_REACHED_STAR_HAVEN                = 91,
    STORY_CH8_STAR_SHIP_ACTIVATED               = 92,
    STORY_UNUSED_0000005D                       = 93,
    STORY_CH8_REACHED_BOWSERS_CASTLE            = 94,
    STORY_CH8_REACHED_PEACHS_CASTLE             = 95,
    STORY_EPILOGUE                              = 96,
    STORY_NEVER                                 = 97,
};

enum KoopaKootFavors {
    KOOT_FAVOR_CH1_1        = 0,
    KOOT_FAVOR_CH1_2        = 1,
    KOOT_FAVOR_CH2_1        = 2,
    KOOT_FAVOR_CH2_2        = 3,
    KOOT_FAVOR_CH2_3        = 4,
    KOOT_FAVOR_CH3_1        = 5,
    KOOT_FAVOR_CH3_2        = 6,
    KOOT_FAVOR_CH3_3        = 7,
    KOOT_FAVOR_CH4_1        = 8,
    KOOT_FAVOR_CH4_2        = 9,
    KOOT_FAVOR_CH4_3        = 10,
    KOOT_FAVOR_CH5_1        = 11,
    KOOT_FAVOR_CH5_2        = 12,
    KOOT_FAVOR_CH5_3        = 13,
    KOOT_FAVOR_CH6_1        = 14,
    KOOT_FAVOR_CH6_2        = 15,
    KOOT_FAVOR_CH6_3        = 16,
    KOOT_FAVOR_CH7_1        = 17,
    KOOT_FAVOR_CH7_2        = 18,
    KOOT_FAVOR_CH7_3        = 19,
};

enum KoopaKootFavorStates {
    KOOT_FAVOR_STATE_0      = 0,
    KOOT_FAVOR_STATE_1      = 1,
    KOOT_FAVOR_STATE_2      = 2,
};

enum EncounterTriggers {
    ENCOUNTER_TRIGGER_NONE                            = 1,
    ENCOUNTER_TRIGGER_JUMP                            = 2,
    ENCOUNTER_TRIGGER_SPIN                            = 3,
    ENCOUNTER_TRIGGER_HAMMER                          = 4,
    ENCOUNTER_TRIGGER_CONVERSATION                    = 5,
    ENCOUNTER_TRIGGER_PARTNER                         = 6,
};

enum SoundOutputMode {
    SOUND_OUT_MONO                                    = 0,
    SOUND_OUT_STEREO                                  = 1,
};

enum SongIDs {
    SONG_TOAD_TOWN                  = 0x00000000,
    //SONG_GOOMBA_VILLAGE_COPY      = 0x00000001,
    SONG_NORMAL_BATTLE              = 0x00000002,
    SONG_SPECIAL_BATTLE             = 0x00000003,
    SONG_JR_TROOPA_BATTLE           = 0x00000004,
    SONG_FINAL_BOWSER_BATTLE        = 0x00000005,
    //SONG_GOOMBA_VILLAGE_COPY      = 0x00000006,
    SONG_GOOMBA_KING_BATTLE         = 0x00000007,
    SONG_KOOPA_BROS_BATTLE          = 0x00000008,
    SONG_FAKE_BOWSER_BATTLE         = 0x00000009,
    SONG_TUTANKOOPA_BATTLE          = 0x0000000A,
    SONG_TUBBA_BLUBBA_BATTLE        = 0x0000000B,
    SONG_GENERAL_GUY_BATTLE         = 0x0000000C,
    SONG_LAVA_PIRANHA_BATTLE        = 0x0000000D,
    SONG_HUFF_N_PUFF_BATTLE         = 0x0000000E,
    SONG_CRYSTAL_KING_BATTLE        = 0x0000000F,
    SONG_GOOMBA_VILLAGE             = 0x00000010,
    SONG_PLEASANT_PATH              = 0x00000011,
    SONG_FUZZY_ATTACK               = 0x00000012,
    SONG_KOOPA_VILLAGE              = 0x00000013,
    SONG_KOOPA_FORTRESS             = 0x00000014,
    SONG_DRY_DRY_OUTPOST            = 0x00000015,
    SONG_MT_RUGGED                  = 0x00000016,
    SONG_DRY_DRY_DESERT             = 0x00000017,
    SONG_DRY_DRY_RUINS              = 0x00000018,
    SONG_RUINS_BASEMENT             = 0x00000019,
    SONG_FOREVER_FOREST             = 0x0000001A,
    SONG_BOOS_MANSION               = 0x0000001B,
    SONG_CHEERFUL_BOOS_MANSION      = 0x0000001C,
    SONG_GUSTY_GULCH                = 0x0000001D,
    SONG_TUBBAS_MANOR               = 0x0000001E,
    SONG_TUBBA_ESCAPE               = 0x0000001F,
    SONG_SHY_GUY_TOYBOX             = 0x00000020,
    SONG_TOYBOX_TRAIN               = 0x00000021,
    SONG_CREEPY_TOYBOX              = 0x00000022,
    //SONG_GOOMBA_VILLAGE_COPY      = 0x00000023,
    SONG_JADE_JUNGLE                = 0x00000024,
    SONG_DEEP_JUNGLE                = 0x00000025,
    SONG_YOSHIS_VILLAGE             = 0x00000026,
    SONG_YOSHIS_PANIC               = 0x00000027,
    SONG_RAPHAEL_RAVEN              = 0x00000028,
    SONG_MT_LAVALAVA                = 0x00000029,
    SONG_VOLCANO_ESCAPE             = 0x0000002A,
    SONG_STAR_WAY_OPENS             = 0x0000002B,
    SONG_MASTER_BATTLE              = 0x0000002C,
    SONG_RADIO_ISLAND_SOUNDS        = 0x0000002D,
    SONG_RADIO_HOT_HITS             = 0x0000002E,
    SONG_RADIO_GOLDEN_OLDIES        = 0x0000002F,
    SONG_FLOWER_FIELDS_CLOUDY       = 0x00000030,
    SONG_FLOWER_FIELDS_SUNNY        = 0x00000031,
    SONG_CLOUDY_CLIMB               = 0x00000032,
    SONG_PUFF_PUFF_MACHINE          = 0x00000033,
    SONG_SUN_TOWER_CLOUDY           = 0x00000034,
    SONG_SUN_TOWER_SUNNY            = 0x00000035,
    //SONG_GOOMBA_VILLAGE_COPY      = 0x00000036,
    SONG_CRYSTAL_PALACE             = 0x00000037,
    SONG_SHIVER_CITY                = 0x00000038,
    SONG_PENGUIN_MYSTERY            = 0x00000039,
    SONG_SHIVER_SNOWFIELD           = 0x0000003A,
    SONG_SHIVER_MOUNTAIN            = 0x0000003B,
    SONG_STARBORN_VALLEY            = 0x0000003C,
    SONG_MERLAR_THEME               = 0x0000003D,
    SONG_MAIL_CALL                  = 0x0000003E,
    SONG_PEACHS_CASTLE_PARTY        = 0x0000003F,
    SONG_CHAPTER_END                = 0x00000040,
    SONG_CHAPTER_START              = 0x00000041,
    SONG_ITEM_UPGRADE               = 0x00000042,
    //SONG_GOOMBA_VILLAGE_COPY      = 0x00000043,
    SONG_PHONOGRAPH_MUSIC           = 0x00000044,
    SONG_TUTANKOOPA_THEME           = 0x00000045,
    SONG_KAMMY_KOOPA_THEME          = 0x00000046,
    SONG_JR_TROOPA_THEME            = 0x00000047,
    SONG_BULLET_BILL_ASSAULT        = 0x00000048,
    SONG_MONTY_MOLE_ASSAULT         = 0x00000049,
    SONG_SHY_GUY_INVASION           = 0x0000004A,
    SONG_TOAD_TOWN_TUNNELS          = 0x0000004B,
    SONG_WHALE_THEME                = 0x0000004C,
    SONG_FOREVER_FOREST_WARNING     = 0x0000004D,
    SONG_YOSHI_KIDS_FOUND           = 0x0000004E,
    SONG_UNUSED_FANFARE             = 0x0000004F,
    SONG_GOOMBA_KING_THEME          = 0x00000050,
    SONG_KOOPA_BROS_INTERLUDE       = 0x00000051,
    SONG_KOOPA_BROS_THEME           = 0x00000052,
    SONG_TUTANKOOPA_WARNING         = 0x00000053,
    SONG_TUTANKOOPA_REVEALED        = 0x00000054,
    SONG_TUBBA_BLUBBA_THEME         = 0x00000055,
    SONG_GENERAL_GUY_THEME          = 0x00000056,
    SONG_LAVA_PIRANHA_THEME         = 0x00000057,
    SONG_HUFF_N_PUFF_THEME          = 0x00000058,
    SONG_CRYSTAL_KING_THEME         = 0x00000059,
    SONG_BLOOPER_THEME              = 0x0000005A,
    SONG_MINIBOSS_BATTLE            = 0x0000005B,
    SONG_MONSTAR_THEME              = 0x0000005C,
    SONG_CLUB64                     = 0x0000005D,
    SONG_UNUSED_OPENING             = 0x0000005E,
    SONG_BOWSERS_CASTLE_FALLS       = 0x0000005F,
    SONG_STAR_HAVEN                 = 0x00000060,
    SONG_SHOOTING_STAR_SUMMIT       = 0x00000061,
    SONG_STARSHIP_THEME             = 0x00000062,
    SONG_STAR_SANCTUARY             = 0x00000063,
    SONG_BOWSERS_CASTLE             = 0x00000064,
    SONG_BOWSERS_CASTLE_CAVES       = 0x00000065,
    SONG_BOWSER_THEME               = 0x00000066,
    SONG_BOWSER_BATTLE              = 0x00000067,
    SONG_PEACH_WISHES               = 0x00000068,
    SONG_FILE_SELECT                = 0x00000069,
    SONG_MAIN_THEME                 = 0x0000006A,
    SONG_BOWSER_ATTACKS             = 0x0000006B,
    SONG_MARIO_FALLS                = 0x0000006C,
    SONG_PEACH_APPEARS              = 0x0000006D,
    SONG_THE_END                    = 0x0000006E,
    SONG_RECOVERED_STAR_ROD         = 0x0000006F,
    SONG_TWINK_THEME                = 0x00000070,
    SONG_STIRRING_CAKE              = 0x00000071,
    SONG_GOURMET_GUY_FREAKOUT       = 0x00000072,
    SONG_PRISONER_PEACH_THEME       = 0x00000073,
    SONG_PEACH_MISSION              = 0x00000074,
    SONG_PEACH_SNEAKING             = 0x00000075,
    SONG_PEACH_CAUGHT               = 0x00000076,
    SONG_PEACH_QUIZ_INTRO           = 0x00000077,
    SONG_STAR_SPIRIT_THEME          = 0x00000078,
    SONG_PENGUIN_WHODUNIT           = 0x00000079,
    SONG_PENGUIN_WAKES_UP           = 0x0000007A,
    SONG_MAGIC_BEANSTALK            = 0x0000007B,
    SONG_MERLEE_SPELL               = 0x0000007C,
    SONG_LAKILESTER_THEME           = 0x0000007D,
    SONG_GOOMBA_BROS_RETREAT        = 0x0000007E,
    SONG_SUNSHINE_RETURNS           = 0x0000007F,
    SONG_RIDING_THE_RAILS           = 0x00000080,
    SONG_RIDING_THE_WHALE           = 0x00000081,
    SONG_NEW_PARTNER                = 0x00000082,
    SONG_DRY_DRY_RUINS_APPEAR       = 0x00000083,
    SONG_CANDY_CANES                = 0x00000084,
    SONG_PLAYROOM                   = 0x00000085,
    SONG_MOUSTAFA_THEME             = 0x00000086,
    SONG_GAME_OVER                  = 0x00000087,
    SONG_TAKING_REST                = 0x00000088,
    SONG_FLOWER_NPC_THEME           = 0x00000089,
    SONG_FLOWER_GATE_APPEARS        = 0x0000008A,
    SONG_BATTLE_END                 = 0x0000008B,
    SONG_POP_DIVA_SONG              = 0x0000008C,
    SONG_BOO_MINIGAME               = 0x0000008D,
    SONG_LEVEL_UP                   = 0x0000008E,
    //SONG_GOOMBA_VILLAGE_COPY      = 0x0000008F,
    SONG_PARADE_DAY                 = 0x00000090,
    SONG_PARADE_NIGHT               = 0x00000091,
    //SONG_GOOMBA_VILLAGE_COPY      = 0x00000092,
    //SONG_GOOMBA_VILLAGE_COPY      = 0x00000093,
    SONG_MARIO_BROS_HOUSE           = 0x00000094,
    SONG_INTRO_STORY                = 0x00000095,
    SONG_NEW_PARTNER_JP             = 0x00000096,
};

enum Abilities {
    ABILITY_DODGE_MASTER            = 0x00000000,
    ABILITY_UNUSED                  = 0x00000001,
    ABILITY_SPIKE_SHIELD            = 0x00000002,
    ABILITY_FIRST_ATTACK            = 0x00000003,
    ABILITY_HP_PLUS                 = 0x00000004,
    ABILITY_DOUBLE_DIP              = 0x00000005,
    ABILITY_MYSTERY_SCROLL          = 0x00000006,
    ABILITY_FIRE_SHIELD             = 0x00000007,
    ABILITY_PRETTY_LUCKY            = 0x00000008,
    ABILITY_HP_DRAIN                = 0x00000009,
    ABILITY_ALL_OR_NOTHING          = 0x0000000A,
    ABILITY_SLOW_GO                 = 0x0000000B,
    ABILITY_FP_PLUS                 = 0x0000000C,
    ABILITY_ICE_POWER               = 0x0000000D,
    ABILITY_FEELING_FINE            = 0x0000000E,
    ABILITY_ATTACK_FX               = 0x0000000F,
    ABILITY_MONEY_MONEY             = 0x00000010,
    ABILITY_CHILL_OUT               = 0x00000011,
    ABILITY_HAPPY_HEART             = 0x00000012,
    ABILITY_ZAP_TAP                 = 0x00000013,
    ABILITY_MEGA_RUSH               = 0x00000014,
    ABILITY_BERSERKER               = 0x00000015,
    ABILITY_RIGHT_ON                = 0x00000016,
    ABILITY_RUNAWAY_PAY             = 0x00000017,
    ABILITY_FLOWER_SAVER            = 0x00000018,
    ABILITY_PAY_OFF                 = 0x00000019,
    ABILITY_QUICK_CHANGE            = 0x0000001A,
    ABILITY_DEFEND_PLUS             = 0x0000001B,
    ABILITY_POWER_PLUS              = 0x0000001C,
    ABILITY_REFUND                  = 0x0000001D,
    ABILITY_POWER_RUSH              = 0x0000001E,
    ABILITY_CRAZY_HEART             = 0x0000001F,
    ABILITY_LAST_STAND              = 0x00000020,
    ABILITY_CLOSE_CALL              = 0x00000021,
    ABILITY_P_UP_D_DOWN             = 0x00000022,
    ABILITY_LUCKY_DAY               = 0x00000023,
    ABILITY_MEGA_HP_DRAIN           = 0x00000024,
    ABILITY_P_DOWN_D_UP             = 0x00000025,
    ABILITY_FLOWER_FANATIC          = 0x00000026,
    ABILITY_SPEEDY_SPIN             = 0x00000027,
    ABILITY_SPIN_ATTACK             = 0x00000028,
    ABILITY_I_SPY                   = 0x00000029,
    ABILITY_BUMP_ATTACK             = 0x0000002A,
    ABILITY_HEART_FINDER            = 0x0000002B,
    ABILITY_FLOWER_FINDER           = 0x0000002C,
    ABILITY_DIZZY_ATTACK            = 0x0000002D,
    ABILITY_FINAL_GOOMPA            = 0x0000002E,
    ABILITY_FINAL_BOBOMB            = 0x0000002F,
    ABILITY_DEEP_FOCUS              = 0x00000030,
    ABILITY_SUPER_FOCUS             = 0x00000031,
    ABILITY_KAIDEN                  = 0x00000032,
    ABILITY_DAMAGE_DODGE            = 0x00000033,
    ABILITY_HAPPY_FLOWER            = 0x00000034,
    ABILITY_GROUP_FOCUS             = 0x00000035,
    ABILITY_PEEKABOO                = 0x00000036,
    ABILITY_HEALTHY_HEALTHY         = 0x00000037,
};

enum Emotes {
    EMOTE_EXCLAMATION        = 0,
    EMOTE_SHOCK              = 1,
    EMOTE_QUESTION           = 2,
    EMOTE_FRUSTRATION        = 3,
    EMOTE_ELLIPSIS           = 4,
    EMOTE_INVALID            = 5,
};

enum Emoters {
    EMOTER_PLAYER   = 0,
    EMOTER_NPC      = 1,
    EMOTER_POS      = 2,
};

enum EasingType {
    EASING_LINEAR                   = 0,
    EASING_QUADRATIC_IN             = 1,
    EASING_CUBIC_IN                 = 2,
    EASING_QUARTIC_IN               = 3,
    EASING_QUADRATIC_OUT            = 4,
    EASING_CUBIC_OUT                = 5,
    EASING_QUARTIC_OUT              = 6,
    EASING_COS_SLOW_OVERSHOOT       = 7,
    EASING_COS_FAST_OVERSHOOT       = 8,
    EASING_COS_BOUNCE               = 9,
    EASING_COS_IN_OUT               = 10,
    EASING_SIN_OUT                  = 11,
    EASING_COS_IN                   = 12,
};

enum SoundIDBits {
    SOUND_ID_STOP                   = 0x00008000,
    SOUND_ID_LOWER                  = 0x000023FF,
    SOUND_ID_UNK                    = 0x00002000, // sounds belonging to special large section
    SOUND_ID_ADJUST                 = 0x00001000,
    SOUND_ID_TRIGGER_MASK           = 0x00000C00,
    SOUND_ID_TRIGGER_CHANGE_VOLUME  = 0x00000800,
    SOUND_ID_TRIGGER_CHANGE_SOUND   = 0x00000400,
    SOUND_ID_SECTION_MASK           = 0x00000300, // corresponds to sections 0-3 for indices < 0xC0 and 4-7 for those above
    SOUND_ID_INDEX_MASK             = 0x000000FF,
    SOUND_ID_UNK_INDEX_MASK         = 0x000001FF, // indices for the special large section
};

enum SoundType {
    SOUND_TYPE_SPECIAL              = 0x80000000,
    SOUND_TYPE_LOOPING              = 0, // 0x80000000 (with SOUND_TYPE_SPECIAL)
    SOUND_TYPE_EXIT_DOOR            = 1, // 0x90000000 (with SOUND_TYPE_SPECIAL)
    SOUND_TYPE_ROOM_DOOR            = 2, // 0xA0000000 (with SOUND_TYPE_SPECIAL)
    SOUND_TYPE_ALTERNATING          = 3, // 0xB0000000 (with SOUND_TYPE_SPECIAL)
};

enum SoundIDs {
    SOUND_NONE                                  = 0x00000000,
    SOUND_OPEN_POPUP_1                          = 0x00000001,
    SOUND_OPEN_POPUP_2                          = 0x00000002,
    SOUND_LOWER_STATUS_BAR                      = 0x00000003,
    SOUND_RAISE_STATUS_BAR                      = 0x00000004,
    SOUND_MENU_BADGE_EQUIP                      = 0x00000005,
    SOUND_MENU_BADGE_UNEQUIP                    = 0x00000006,
    SOUND_MENU_SHOW_CHOICE                      = 0x00000009,
    SOUND_CHIME_BEGIN_AMBUSH                    = 0x0000000A,
    SOUND_CHIME_SOLVED_PUZZLE                   = 0x0000000B,
    SOUND_ACTIVATE_COMPUTER                     = 0x0000000C, // unused
    SOUND_PARTNER_PUT_AWAY                      = 0x0000000D,
    SOUND_PARTNER_GET_OUT                       = 0x0000000E,
    SOUND_PARTNER_SWAP_BATTLE_POS               = 0x0000000F,
    SOUND_SAVE_CONFIRM                          = 0x00000010,
    SOUND_MSG_VOICE_1A                          = 0x00000011,
    SOUND_MSG_VOICE_1B                          = 0x00000012,
    SOUND_MSG_VOICE_2A                          = 0x00000013,
    SOUND_MSG_VOICE_2B                          = 0x00000014,
    SOUND_MSG_VOICE_3A                          = 0x00000015,
    SOUND_MSG_VOICE_3B                          = 0x00000016,
    SOUND_MSG_VOICE_4A                          = 0x00000017,
    SOUND_MSG_VOICE_4B                          = 0x00000018,
    SOUND_MSG_VOICE_5A                          = 0x00000019,
    SOUND_MSG_VOICE_5B                          = 0x0000001A,
    SOUND_MSG_VOICE_STAR                        = 0x0000001B,
    SOUND_LRAW_TRD_FLOWING_WATER                = 0x00000021,
    SOUND_LRAW_TRD_RAISE_STAIRS                 = 0x00000022,
    SOUND_TRD_WATER_SPLASH                      = 0x00000023,
    SOUND_LRAW_TRD_02_LOWER_STAIRS              = 0x00000024,
    SOUND_TRD_02_STAIRS_LOWERED                 = 0x00000025,
    SOUND_TRD_PUZZLE_PLATFORM_THUD              = 0x00000026,
    SOUND_LRAW_TRD_04_LOWER_STAIRS              = 0x00000027,
    SOUND_TRD_04_STAIRS_LOWERED                 = 0x00000028,
    SOUND_TRD_POUNDING_HIGH                     = 0x00000029,
    SOUND_TRD_POUNDING_LOW                      = 0x0000002A,
    SOUND_TRD_MAGIC_DOOR_JUMP                   = 0x0000002B,
    SOUND_TRD_MAGIC_DOOR_LAND                   = 0x0000002C,
    SOUND_PRA_PUSH_STATUE                       = 0x0000002D,
    SOUND_PRA_FLIP_WALL                         = 0x0000002E,
    SOUND_PRA_EXTEND_HIDDEN_BRIDGE              = 0x0000002F,
    SOUND_PRA_UNFOLD_EXIT                       = 0x00000030,
    SOUND_LRAW_KKJ_RUMBLING                     = 0x00000033,
    SOUND_LRAW_OSR_RUMBLING                     = 0x00000034, // doesn't loop?
    SOUND_OSR_GROUND_CRACKING                   = 0x00000035,
    SOUND_OSR_SMOKE_RISING_1                    = 0x00000036,
    SOUND_OSR_SMOKE_RISING_2                    = 0x00000037,
    SOUND_OSR_SMOKE_RISING_3                    = 0x00000038,
    SOUND_LRAW_MAC_HARBOR_WATER                 = 0x00000039, // #looping
    SOUND_PRA_SHIFT_FLOORS_RUMBLE               = 0x0000003F, // #looping
    SOUND_PRA_SHIFT_FLOORS_THUD                 = 0x00000040,
    SOUND_WHALE_JIGGLE                          = 0x00000041,
    SOUND_WHALE_FILL                            = 0x00000042,
    SOUND_LRAW_WHALE_GEYSER                     = 0x00000043, // #looping
    SOUND_WHALE_EJECT                           = 0x00000044,
    SOUND_JR_TROOPA_SPLASH                      = 0x00000045,
    SOUND_LRAW_JR_TROOPA_SWIM                   = 0x00000046,
    SOUND_BOO_SPOOK                             = 0x00000047,
    SOUND_OBJECT_LAND                           = 0x00000048,
    SOUND_UNUSED_WATER_RUNNING                  = 0x00000049, // #looping
    SOUND_LRAW_JAN_BEACH_WAVES                  = 0x0000004A,
    SOUND_LRAW_OSR_FOUNTAIN_INTACT              = 0x0000004C,
    SOUND_LRAW_OSR_FOUNTAIN_BROKEN              = 0x0000004D,
    SOUND_LRAW_JAN_SMALL_GEYSER                 = 0x0000004E,
    SOUND_LRAW_JAN_LARGE_GEYSER                 = 0x0000004F,
    SOUND_LRAW_WINDMILL_EXT                     = 0x00000050,
    SOUND_OMO_FLIP_TRACK_THUD                   = 0x00000051,
    SOUND_LRAW_TROMP_ROLL                       = 0x00000052,
    SOUND_ISK_DRAINING_SAND                     = 0x00000053, // #looping
    SOUND_ISK_FLIP_STAIRS                       = 0x00000054,
    SOUND_LARGE_LENS_FLARE                      = 0x00000055,
    SOUND_LRAW_ISK_LOWER_STAIRS                 = 0x00000056,
    SOUND_ISK_STAIR_DROP_THUD                   = 0x00000057,
    SOUND_ISK_STAIRS_EMERGE_RUMBLE              = 0x00000058,
    SOUND_ISK_STAIRS_EMERGE_THUD                = 0x00000059,
    SOUND_KKJ_ARENA_LENS_FLARE                  = 0x0000005A,
    SOUND_LRAW_SBK_RUINS_WHIRLWIND              = 0x0000005B,
    SOUND_SBK_RUINS_FINISH_RISING               = 0x0000005C,
    SOUND_LRAW_SBK_RUINS_RISING                 = 0x0000005D,
    SOUND_SBK_RUINS_STEPS_UNFOLD                = 0x0000005E,
    SOUND_SBK_RUINS_PEDESTAL_SINK               = 0x0000005F,
    SOUND_LRAW_SBK_RUINS_RISING_DISTANT         = 0x00000060,
    SOUND_GOOMPA_ATTACKED                       = 0x00000061,
    SOUND_TWINK_DEPART                          = 0x00000062,
    SOUND_UNUSED_STAR_SPIRIT_APPEARS            = 0x00000063,
    SOUND_MULTIPLE_STAR_SPIRITS_APPEAR          = 0x00000064,
    SOUND_NOK_BRIDGE_XYLOPHONE_1                = 0x00000067,
    SOUND_NOK_BRIDGE_XYLOPHONE_2                = 0x00000068,
    SOUND_NOK_BRIDGE_XYLOPHONE_3                = 0x00000069,
    SOUND_NOK_BRIDGE_XYLOPHONE_4                = 0x0000006A,
    SOUND_NOK_BRIDGE_XYLOPHONE_5                = 0x0000006B,
    SOUND_NOK_BRIDGE_XYLOPHONE_6                = 0x0000006C,
    SOUND_NOK_BRIDGE_XYLOPHONE_7                = 0x0000006D,
    SOUND_LRAW_WINDMILL_GEARS                   = 0x00000070,
    SOUND_NOK_BRIDGE_THUD_1                     = 0x00000071,
    SOUND_NOK_BRIDGE_THUD_2                     = 0x00000072,
    SOUND_NOK_BRIDGE_THUD_3                     = 0x00000073,
    SOUND_JR_TROOPA_SCAMPER                     = 0x00000074,
    SOUND_NOK_HOUSE_CONFLICT                    = 0x00000077,
    SOUND_PULSE_STONE                           = 0x0000007D,
    SOUND_TRAIN_DEPARTURE                       = 0x00000082,
    SOUND_LRAW_TOYBOX_TRAIN_GEAR                = 0x00000083,
    SOUND_OMO_TOY_TRAIN_WHISTLE_B               = 0x00000084,
    SOUND_OMO_PLATFORM_ASCEND                   = 0x00000085,
    SOUND_OMO_PLATFORM_DESCEND                  = 0x00000087,
    SOUND_LRAW_AUDIENCE_MURMUR                  = 0x00000089,
    SOUND_AUDIENCE_CHEER                        = 0x0000008A,
    SOUND_AUDIENCE_BOO                          = 0x0000008B,
    SOUND_QUIZ_NEXT_QUESTION                    = 0x0000008C,
    SOUND_QUIZ_BUZZER                           = 0x0000008D,
    SOUND_LRAW_QUIZ_TICKING                     = 0x0000008E,
    SOUND_QUIZMO_VANISH                         = 0x0000008F,
    SOUND_LRAW_PUFF_PUFF_MACHINE                = 0x00000091,
    SOUND_KKJ_USE_SNEAKY_PARASOL                = 0x00000092,
    SOUND_KKJ_ROTATING_WALL                     = 0x00000093, // #looping
    SOUND_LRAW_DGB_COLLAPSE                     = 0x00000094,
    SOUND_DGB_COLLAPSE_1                        = 0x00000095,
    SOUND_DGB_COLLAPSE_2                        = 0x00000096,
    SOUND_DGB_COLLAPSE_4                        = 0x00000097,
    SOUND_DGB_COLLAPSE_3                        = 0x00000098,
    SOUND_LRAW_OBK_LOWER_CHAIN                  = 0x00000099,
    SOUND_OBK_CAGE_SLAM                         = 0x0000009B,
    SOUND_OBK_CHANDELIER_SWING                  = 0x0000009D,
    SOUND_LRAW_MOVE_STATUE                      = 0x0000009E,
    SOUND_LRAW_MOVE_LARGE_STATUE                = 0x0000009F,
    SOUND_LRAW_OMO_ROTATING_WHEEL               = 0x000000A0,
    SOUND_OMO_TOYBOX_TRAIN_DROP                 = 0x000000A1,
    SOUND_LRAW_STAR_ORB_RISING                  = 0x000000A2,
    SOUND_STARSHIP_APPEARS                      = 0x000000A3,
    SOUND_KPA_LIGHT_RAYS                        = 0x000000A4,
    SOUND_KMR_TOWER_COLLAPSE_RUMBLE_LOOP        = 0x000000A5,
    SOUND_KMR_TOWER_COLLAPSE_THUD               = 0x000000A6,
    SOUND_KMR_TOWER_COLLAPSE_UNFOLD             = 0x000000A7,
    SOUND_DGB_SMALL_THUD                        = 0x000000A8,
    SOUND_ROWF_OPEN_SHOP                        = 0x000000A9,
    SOUND_ROWF_PULL_RUG_OUT                     = 0x000000AA,
    SOUND_ROWF_CLOSE_SHOP                       = 0x000000AB,
    SOUND_ROWF_PUSH_RUG_IN                      = 0x000000AC,
    SOUND_LRAW_STAR_SANCTUARY_FAR               = 0x000000AD,
    SOUND_LRAW_STAR_SANCTUARY_NEAR              = 0x000000AE,
    SOUND_LRAW_STAR_SANCTUARY_INSIDE            = 0x000000AF,
    SOUND_INTRO_NEXT_PAGE                       = 0x000000B0,
    SOUND_MERLAR_APPEARS                        = 0x000000B1,
    SOUND_STAR_ORB_BURST                        = 0x000000B2,
    SOUND_TUBBA_POUNDING                        = 0x000000B4,
    SOUND_BOO_VANISH_A                          = 0x000000C1,
    SOUND_BOO_VANISH_B                          = 0x000000C2,
    SOUND_BOO_APPEAR_A                          = 0x000000C3,
    SOUND_BOO_APPEAR_B                          = 0x000000C4,
    SOUND_MENU_OPEN                             = 0x000000C5,
    SOUND_MENU_CLOSE                            = 0x000000C6,
    SOUND_MENU_CHANGE_SELECTION                 = 0x000000C7,
    SOUND_MENU_CHANGE_TAB                       = 0x000000C8,
    SOUND_MENU_NEXT                             = 0x000000C9,
    SOUND_MENU_BACK                             = 0x000000CA,
    SOUND_MSG_WAIT                              = 0x000000CB,
    SOUND_MSG_SKIP                              = 0x000000CC,
    SOUND_MSG_REWIND                            = 0x000000CD,
    SOUND_MSG_UNREWIND                          = 0x000000CE,
    SOUND_JINGLE_GOT_ITEM                       = 0x000000D1,
    SOUND_JINGLE_GOT_KEY                        = 0x000000D2,
    SOUND_JINGLE_GOT_BADGE                      = 0x000000D3,
    SOUND_JINGLE_WON_BATTLE                     = 0x000000D4,
    SOUND_FILE_MENU_IN                          = 0x000000D5,
    SOUND_FILE_MENU_OUT                         = 0x000000D6,
    SOUND_TRANSPORTER_IN                        = 0x000000D9,
    SOUND_TRANSPORTER_OUT                       = 0x000000DA,
    SOUND_SLIDE_WHISTLE_IN                      = 0x000000DB, // unused
    SOUND_SLIDE_WHISTLE_OUT                     = 0x000000DC,
    SOUND_HEAVY_OBJECT_DROP                     = 0x000000DD,
    SOUND_CHECK_LAUGHING_FLOWERS                = 0x000000DF,
    SOUNC_CHECK_MAILBOX                         = 0x000000E0,
    SOUND_HIT_PLAYER_NORMAL                     = 0x000000E1,
    SOUND_HIT_PLAYER_FIRE                       = 0x000000E2,
    SOUND_HIT_PLAYER_ICE                        = 0x000000E3,
    SOUND_FROZEN_SHATTER                        = 0x000000E7,
    SOUND_TOUCH_LAVA                            = 0x000000E8,
    SOUND_HIT_NORMAL                            = 0x000000E9,
    SOUND_HIT_FIRE                              = 0x000000EA,
    SOUND_HIT_ICE                               = 0x000000EB,
    SOUND_PLANTS_BELL                           = 0x000000F1,
    SOUND_PLANTS_CYMBAL_CRASH                   = 0x000000F2,
    SOUND_PLANTS_TRUMPET                        = 0x000000F3,
    SOUND_PLANTS_LIGHT_UP                       = 0x000000F4,
    SOUND_FIREPLACE_BURST                       = 0x000000F5,
    SOUND_OBK_CHECK_CABINET                     = 0x000000F6,
    SOUND_OBK_CABINET_CRASH                     = 0x000000F7,
    SOUND_FLIP_PAGE                             = 0x000000F8,
    SOUND_KKJ_REVEAL_BUTTON                     = 0x000000F9,
    SOUND_KKJ_PRESS_BUTTON                      = 0x000000FA,
    SOUND_KKJ_DROP_INTO_ASHES                   = 0x000000FB,
    SOUND_KKJ_EXTINGUISH_FIRE                   = 0x000000FC,
    SOUND_SNEAKY_PARASOL_COPY                   = 0x000000FD,
    SOUND_SNEAKY_PARASOL_TRANSFORM              = 0x000000FE,
    SOUND_START_OVEN_TIMER                      = 0x000000FF,
    SOUND_KOOPER_STEP                           = 0x00000100,
    SOUND_HIT_SPIKE                             = 0x00000108,
    SOUND_HAMMER_WINDUP                         = 0x0000010B,
    SOUND_IMMUNE                                = 0x0000010C,
    SOUND_HIT_BONES                             = 0x0000010D,
    SOUND_HIT_SILENT                            = 0x0000010E, // nothing is audible
    SOUND_ACTOR_HURT                            = 0x0000010F,
    SOUND_HIT_RATTLE                            = 0x00000110,
    SOUND_HEART_BLOCK                           = 0x00000131,
    SOUND_UNUSED_HEAL_BLOCK                     = 0x00000133, // #unused
    SOUND_ASCENDING_CHIMES                      = 0x00000134, // #unused
    SOUND_DESCENDING_CHIMES                     = 0x00000135, // #unused
    SOUND_STAR_CARD_APPEARS                     = 0x00000137,
    SOUND_RESCUE_STAR_SPIRIT                    = 0x00000138,
    SOUND_RECEIVE_STAR_POWER                    = 0x00000139,
    SOUND_MONSTAR_BREAKS_APART                  = 0x0000013D,
    SOUND_STAR_KID_FLYING                       = 0x0000013E,
    SOUND_STEP_NORMAL1                          = 0x00000141,
    SOUND_STEP_NORMAL2                          = 0x00000142,
    SOUND_STEP_CRUNCHY1                         = 0x00000143,
    SOUND_STEP_CRUNCHY2                         = 0x00000144,
    SOUND_SPIN_JUMP                             = 0x00000146,
    SOUND_TORNADO_JUMP                          = 0x00000147,
    SOUND_LAND_SOFTLY                           = 0x00000148,
    SOUND_LAND_SPIN_JUMP                        = 0x00000149,
    SOUND_LAND_TORANDO_JUMP                     = 0x0000014A,
    SOUND_HIT_BLOCK                             = 0x0000014E,
    SOUND_SMASH_HAMER_BLOCK_1                   = 0x0000014F,
    SOUND_SMASH_HAMER_BLOCK_2                   = 0x00000150,
    SOUND_SMASH_HAMER_BLOCK_3                   = 0x00000151,
    SOUND_ACTIVATE_SWITCH                       = 0x00000152,
    SOUND_SEARCH_BUSH                           = 0x00000153,
    SOUND_PLAYER_CHARGE                         = 0x00000156,
    SOUND_BLOCK_SHATTER                         = 0x00000158,
    SOUND_SMALL_BOING                           = 0x00000159, // #spring #boing #unused
    SOUND_ACTOR_JUMPED_1                        = 0x0000015A, // #unused
    SOUND_ACTOR_JUMPED_2                        = 0x0000015B, // #unused
    SOUND_ACTOR_JUMPED_3                        = 0x0000015C, // #unused
    SOUND_PLAYER_RUN_IN_PLACE                   = 0x0000015D,
    SOUND_PLAYER_RUN_AWAY                       = 0x0000015E,
    SOUND_LONG_PLAYER_JUMP                      = 0x00000160,
    SOUND_PLAYER_LONG_FALL                      = 0x00000161,
    SOUND_TRIP                                  = 0x00000162,
    SOUND_ENTER_PIPE                            = 0x00000163,
    SOUND_LRAW_NOTHING_26                       = 0x00000164, // #unused #nodata
    SOUND_SMACK_TREE                            = 0x00000165,
    SOUND_SHAKE_TREE_LEAVES                     = 0x00000166,
    SOUND_SLIDE                                 = 0x00000167, // #looping
    SOUND_LRAW_ZIPLINE_RIDE                     = 0x00000168,
    SOUND_DUST_OFF                              = 0x00000172,
    SOUND_RUN_AWAY_BUILDUP                      = 0x00000173,
    SOUND_RUN_AWAY                              = 0x00000174,
    SOUND_PAPER_GLIDE_1                         = 0x00000175,
    SOUND_PAPER_GLIDE_2                         = 0x00000176,
    SOUND_LUIGI_STEP_A                          = 0x00000179,
    SOUND_LUIGI_STEP_B                          = 0x0000017A,
    SOUND_ISPY                                  = 0x0000017B,
    SOUND_STARSHIP_ENGINE_LOOP                  = 0x0000017C, // #looping
    SOUND_STARSHIP_TAKEOFF_LONG                 = 0x0000017D,
    SOUND_STARSHIP_TAKEOFF_SHORT                = 0x0000017E,
    SOUND_STARSHIP_ARRIVE                       = 0x0000017F,
    SOUND_STARSHIP_NEAR_FLYBY                   = 0x00000180,
    SOUND_STARSHIP_ASCEND                       = 0x00000181,
    SOUND_STARSHIP_FLY_AWAY                     = 0x00000182,
    SOUND_STARSHIP_FLY_TOWARD                   = 0x00000183,
    SOUND_SPRINKLE_MAGIC                        = 0x00000184, // #unused
    SOUND_LRAW_ZIPLINE_RETURN                   = 0x00000185,
    SOUND_JAN_BASKET_ELEVATOR                   = 0x00000186,
    SOUND_FLO_STAIRS_LOWERING                   = 0x00000187, // #rocky #scrape #rumble
    SOUND_GET_STAR_POWER_WAVE                   = 0x00000188,
    SOUND_LRAW_JAN_CONSTRUCTION                 = 0x00000189,
    SOUND_JAN_RAPHAEL_POUND                     = 0x0000018A, // #heavy #impact #thud
    SOUND_JAN_ROOT_WOBBLE_1                     = 0x0000018C,
    SOUND_JAN_ROOT_WOBBLE_2                     = 0x0000018D,
    SOUND_JAN_ROOT_WOBBLE_3                     = 0x0000018E,
    SOUND_FLO_PUFF_PUFF_SMOKE_BURST             = 0x00000190, // #explode
    SOUND_JAN_BOULDER_TREMBLE                   = 0x00000191, // #rocky #knock #short #impact
    SOUND_FLO_BLOW_BUBBLE                       = 0x00000193,
    SOUND_LRAW_BUBBLE_DRIFT                     = 0x00000194, // #looping
    SOUND_LRAW_FLO_FILL_WATER_POOL              = 0x00000197, // #looping
    SOUND_LRAW_FLO_WATER_FLOW_1                 = 0x00000198, // #looping #gentle
    SOUND_LRAW_FLO_WATER_FLOW_2                 = 0x00000199, // #looping #fountain
    SOUND_LRAW_FLO_RELEASE_FOUNTAIN             = 0x0000019A, // #looping #fountain
    SOUND_FLO_BEANSTALK_START_GROWING           = 0x0000019B,
    SOUND_FLO_RIDE_BEANSTALK_UP_LOOP            = 0x0000019C, // #looping
    SOUND_FLO_RIDE_BEANSTALK_DOWN_LOOP          = 0x0000019D, // #looping
    SOUND_FLO_MAGIKOOPA_FLY_AWAY                = 0x0000019E,
    SOUND_FLO_LAKITU_FLY_AWAY                   = 0x0000019F,
    SOUND_FLO_PUFF_PUFF_EXPLODE                 = 0x000001A0, // #explode
    SOUND_OMO_BOX_GLOW_1                        = 0x000001A1,
    SOUND_OMO_BOX_GLOW_2                        = 0x000001A2,
    SOUND_OMO_BOX_GLOW_3                        = 0x000001A3,
    SOUND_OMO_BOX_GLOW_4                        = 0x000001A4,
    SOUND_OMO_BOX_CHIME_1                       = 0x000001A5,
    SOUND_OMO_BOX_CHIME_2                       = 0x000001A6,
    SOUND_OMO_BOX_CHIME_3                       = 0x000001A7,
    SOUND_OMO_BOX_CHIME_4                       = 0x000001A8,
    SOUND_OMO_BOX_DONE                          = 0x000001A9,
    SOUND_OMO_TOYBOX_LID                        = 0x000001AA,
    SOUND_OMO_SECRET_DOOR_OPEN                  = 0x000001AB,
    SOUND_OMO_SECRET_DOOR_CLOSE                 = 0x000001AC,
    SOUND_FLYING_PYROCLAST_1                    = 0x000001AD,
    SOUND_FLYING_PYROCLAST_2                    = 0x000001AE,
    SOUND_JAN_CHEST_IMPACT                      = 0x000001AF,
    SOUND_LRAW_NOK_WATER                        = 0x000001B1,
    SOUND_LRAW_TRD_WATER_EXT                    = 0x000001B2,
    SOUND_LRAW_SBK_OASIS_WATER                  = 0x000001B3,
    SOUND_BASIC_DOOR_OPEN                       = 0x000001C1,
    SOUND_BASIC_DOOR_CLOSE                      = 0x000001C2,
    SOUND_METAL_DOOR_OPEN                       = 0x000001C3,
    SOUND_METAL_DOOR_CLOSE                      = 0x000001C4,
    SOUND_LARGE_DOOR_OPEN                       = 0x000001C5,
    SOUND_LARGE_DOOR_CLOSE                      = 0x000001C6,
    SOUND_CREAKY_DOOR_OPEN                      = 0x000001C7,
    SOUND_CREAKY_DOOR_CLOSE                     = 0x000001C8,
    SOUND_METAL_GATE_OPEN                       = 0x000001C9,
    SOUND_METAL_GATE_CLOSE                      = 0x000001CA,
    SOUND_WINDOW_OPEN_A                         = 0x000001CB,
    SOUND_WINDOW_CLOSE_A                        = 0x000001CC,
    SOUND_WINDOW_OPEN_B                         = 0x000001CD,
    SOUND_WINDOW_CLOSE_B                        = 0x000001CE,
    SOUND_WOODEN_DOOR_OPEN                      = 0x000001CF,
    SOUND_WOODEN_DOOR_CLOSE                     = 0x000001D0,
    SOUND_SARCOPHAGUS_OPEN                      = 0x000001D1,
    SOUND_GOOMBA_GATE_OPEN                      = 0x000001D2,
    SOUND_OPEN_CHEST                            = 0x000001D3,
    SOUND_FOREST_GATE_OPEN                      = 0x000001D4,
    SOUND_FOREST_GATE_CLOSE                     = 0x000001D5,
    SOUND_CREAKY_ROCKING                        = 0x000001D6,
    SOUND_KKJ_WINDOW_TAP                        = 0x000001D8,
    SOUND_OMO_DOOR_FLIP                         = 0x000001D9,
    SOUND_PUSH_BLOCK_FALL                       = 0x000001DA,
    SOUND_FLO_LOG_OPEN                          = 0x000001DB,
    SOUND_FLO_LOG_CLOSE                         = 0x000001DC,
    SOUND_SAM_RAISE_BARRIER                     = 0x000001DD,
    SOUND_SAM_LOWER_BARRIER                     = 0x000001DE,
    SOUND_AIRSHIP_DOCK_DOOR_OPEN                = 0x000001DF,
    SOUND_AIRSHIP_DOCK_DOOR_CLOSE               = 0x000001E0,
    SOUND_KMR_TOWER_RUMBLE                      = 0x000001E1,
    SOUND_DISTANT_THUD                          = 0x000001E2,
    SOUND_TROMP_DROP                            = 0x000001E3,
    SOUND_TROMP_CRASH                           = 0x000001E4,
    SOUND_PUFF_PUFF_SMASH                       = 0x000001E5,
    SOUND_PUFF_PUFF_PART_BREAKS                 = 0x000001E6,
    SOUND_PUFF_PUFF_PANEL_BREAKS                = 0x000001E7,
    SOUND_BOING                                 = 0x000001E8,
    SOUND_SAM_DROP_STAIR                        = 0x000001E9,
    SOUND_SAM_BARRIER_THUD                      = 0x000001EA,
    SOUND_SAM_PLACE_STAR_STONE                  = 0x000001EB,
    SOUND_SAM_ICE_STEP_THUD                     = 0x000001EC,
    SOUND_PRA_ROTATE_ALBINO_DINO                = 0x000001ED,
    SOUND_PRA_UNFOLD_STEP                       = 0x000001EE,
    SOUND_KPA_DROP_WALL                         = 0x000001EF,
    SOUND_YOSHI_KID_CRY                         = 0x000001F0,
    SOUND_OMO_TRAIN_TRACK_LEVER                 = 0x000001F1,
    SOUND_OMO_FLIP_TRAIN_TRACK                  = 0x000001F2,
    SOUND_OMO_COLORED_PANEL_DROP                = 0x000001F3,
    SOUND_OMO_BARRICADE_DROP                    = 0x000001F4,
    SOUND_OMO_LANTERN_BREAK                     = 0x000001F5,
    SOUND_OMO_TRAIN_SWITCH_RATTLE               = 0x000001F9,
    SOUND_OMO_TRAIN_SWITCH_SELECT               = 0x000001FA,
    SOUND_TRAIN_CHUG_A                          = 0x000001FB,
    SOUND_TRAIN_CHUG_B                          = 0x000001FC,
    SOUND_TRAIN_RELEASE_STEAM                   = 0x000001FD,
    SOUND_OMO_TOY_TRAIN_CLICK                   = 0x000001FE,
    SOUND_OMO_TOY_TRAIN_WHISTLE_A               = 0x000001FF,
    SOUND_MERLEE_TWIRL                          = 0x00000201,
    SOUND_MERLEE_GATHER_ENERGY                  = 0x00000202,
    SOUND_MERLEE_SHOW_CARD                      = 0x00000203,
    SOUND_MERLEE_GATHER_CARDS                   = 0x00000204,
    SOUND_MERLEE_RELEASE_PLAYER                 = 0x00000205,
    SOUND_MERLEE_COMPLETE_SPELL                 = 0x00000206,
    SOUND_LRAW_CRYSTAL_BALL_GLOW                = 0x00000207,
    SOUND_CRYSTAL_BALL_WAVE                     = 0x00000208,
    SOUND_MERLON_GATHER                         = 0x00000209,
    SOUND_MERLON_STRIKE                         = 0x0000020A,
    SOUND_LOWER_PITCH_MAGIC                     = 0x0000020B, // #unused
    SOUND_RAVEN_FALL_A                          = 0x0000020C,
    SOUND_RAVEN_FALL_B                          = 0x0000020D,
    SOUND_RAVEN_FALL_C                          = 0x0000020E,
    SOUND_COIN_PICKUP                           = 0x00000211,
    SOUND_COIN_BOUNCE                           = 0x00000212,
    SOUND_HEART_PICKUP                          = 0x00000213,
    SOUND_HEART_BOUNCE                          = 0x00000214,
    SOUND_STAR_POINT_PICKUP                     = 0x00000215,
    SOUND_FLOWER_PICKUP                         = 0x00000217,
    SOUND_FLOWER_BOUNCE                         = 0x00000218,
    SOUND_STAR_PIECE_BOUNCE                     = 0x00000219,
    SOUND_ITEM_BOUNCE                           = 0x0000021A,
    SOUND_BADGE_BOUNCE                          = 0x0000021B,
    SOUND_APPROVE                               = 0x0000021C,
    SOUND_MENU_ERROR                            = 0x0000021D,
    SOUND_LRAW_KPA_CHAIN_DRIVE                  = 0x00000221,
    SOUND_KPA_DUMP_LAVA                         = 0x00000222,
    SOUND_KPA_BOWSER_POWER_UP                   = 0x00000223,
    SOUND_KPA_BOWSER_POWER_DOWN                 = 0x00000224, // #unused
    SOUND_KPA_QUIZ_DOORS_OPEN                   = 0x00000225, // #stony #scraping
    SOUND_KPA_QUIZ_DOORS_CLOSE                  = 0x00000226, // #stony #scraping
    SOUND_KPA_RAISE_STONE_PLATFORM              = 0x00000227, // #stony #scraping #rumble
    SOUND_KPA_LOWER_STONE_PLATFORM              = 0x00000228, // #stony #scraping #rumble
    SOUND_KPA_PULL_CHAIN                        = 0x00000229, // #metallic #rattle
    SOUND_LRAW_KPA_FILL_WATER                   = 0x0000022A, // #looping #flush #flowing #water
    SOUND_LRAW_KPA_DRAIN_WATER                  = 0x0000022B, // #looping #flush #flowing #water
    SOUND_LRAW_KPA_ARENA_TURN_ON                = 0x0000022C, // #electric #humming #machine
    SOUND_LRAW_KPA_ARENA_ACTIVE                 = 0x0000022D, // #electric #humming #machine
    SOUND_KPA_EXPLOSION_A                       = 0x0000022E, // #explosion
    SOUND_KPA_EXPLOSION_B                       = 0x0000022F, // #explosion
    SOUND_KPA_EXPLOSION_CLUSTER                 = 0x00000230, // #explosion
    SOUND_DAMAGE_STARS                          = 0x00000231, // also used when blocking
    SOUND_COLLECT_1UP                           = 0x00000232, // #unused
    SOUND_TIMING_BAR_TICK                       = 0x00000233,
    SOUND_TIMING_BAR_GO                         = 0x00000234,
    SOUND_JUMP_COMBO_1                          = 0x00000235,
    SOUND_JUMP_COMBO_2                          = 0x00000236,
    SOUND_JUMP_COMBO_3                          = 0x00000237,
    SOUND_JUMP_COMBO_4                          = 0x00000238,
    SOUND_JUMP_COMBO_5                          = 0x00000239, // #unused
    SOUND_JUMP_COMBO_6                          = 0x0000023A, // #unused
    SOUND_JUMP_COMBO_7                          = 0x0000023B, // #unused rings a bit longer than the others
    SOUND_JUMP_COMBO_8                          = 0x0000023C, // #unused
    SOUND_LRAW_BOWSER_PROPELLER                 = 0x0000023D,
    SOUND_BEGIN_WISH                            = 0x00000241,
    SOUND_REFRESH                               = 0x00000242,
    SOUND_CHILL_OUT                             = 0x00000244,
    SOUND_SMOOCH                                = 0x00000245,
    SOUND_TIME_OUT                              = 0x00000246,
    SOUND_UP_AND_AWAY_CAST                      = 0x00000247,
    SOUND_LRAW_USE_STAR_BEAM                    = 0x00000248,
    SOUND_LRAW_USE_PEACH_BEAM                   = 0x00000249,
    SOUND_STAR_BEAM_FIRE                        = 0x0000024A,
    SOUND_MERLEE_APPEAR                         = 0x0000024B,
    SOUND_SHOOTING_STAR_FALL_A                  = 0x00000259,
    SOUND_SHOOTING_STAR_FALL_B                  = 0x0000025A,
    SOUND_STAR_BOUNCE_A                         = 0x0000025C,
    SOUND_STAR_BOUNCE_B                         = 0x0000025D,
    SOUND_ISK_PLACE_IN_SOCKET                   = 0x00000261, // #stony #thud
    SOUND_EMOTE_IDEA                            = 0x00000262,
    SOUND_EMOTE_QUESTION                        = 0x00000263,
    SOUND_ISK_DOOR_OPEN                         = 0x00000265,
    SOUND_ISK_DOOR_CLOSE                        = 0x00000266,
    SOUND_ISK_DOOR_SLAM                         = 0x00000267, // #stony #thud #heavy
    SOUND_USE_KEY                               = 0x00000269, // #metallic #rattle
    SOUND_LOCK_DROP                             = 0x0000026A, // #metallic #hollow #thud
    SOUND_LARGE_GATE_OPEN                       = 0x0000026B, // #metallic #blowing
    SOUND_LARGE_GATE_CLOSE                      = 0x0000026C, // #metallic #thud
    SOUND_METAL_CRASH                           = 0x00000270, // #unused #metallic #thud
    SOUND_LRAW_TIK_WATER                        = 0x00000271, // #water
    SOUND_LRAW_WATER_FLOWING_1                  = 0x00000273, // #water #flowing
    SOUND_LRAW_WATER_FLOWING_2                  = 0x00000274, // #water #flowing
    SOUND_LRAW_WATER_FLOWING_3                  = 0x00000275, // #water #flowing
    SOUND_LRAW_WATER_FLOWING_4                  = 0x00000276, // #water #flowing
    SOUND_GOOMBARIO_HEADBONK                    = 0x00000281, // #descending #falling
    SOUND_TATTLE_WINDOW_OPEN                    = 0x00000282,
    SOUND_KOOPER_SHELL_KICK                     = 0x00000283,
    SOUND_KOOPER_SHELL_SWIRL                    = 0x00000284,
    SOUND_KOOPER_PICKUP                         = 0x00000286,
    SOUND_LRAW_BOMBETTE_FUSE                    = 0x00000287,
    SOUND_LAKILESTER_HURRICANE_WIND             = 0x00000288,
    SOUND_WATT_CHARGE                           = 0x00000289,
    SOUND_WATT_POWER_SHOCK                      = 0x0000028A,
    SOUND_WATT_TURBO_CHARGE                     = 0x0000028B,
    SOUND_WATT_MEGA_DISCHARGE                   = 0x0000028C,
    SOUND_WATT_WHOOSH_SHOCK                     = 0x0000028D, // #unused
    SOUND_ROARING_FIRE                          = 0x0000028E,
    SOUND_FIRE_SHELL_LAUNCH                     = 0x0000028F,
    SOUND_DIZZY_SHELL_LAUNCH                    = 0x00000290,
    SOUND_BOW_SPOOK                             = 0x00000291,
    SOUND_BOOTLER_SPOOK                         = 0x00000292,
    SOUND_BOOTLER_HIDE                          = 0x00000293,
    SOUND_SUSHIE_DIVE                           = 0x00000294,
    SOUND_FLIGHT                                = 0x00000295,
    SOUND_SUSHIE_SQUIRT                         = 0x00000297,
    SOUND_SUSHIE_FOUNTAIN                       = 0x00000298,
    SOUND_DESTROY_WATER_BLOCK                   = 0x00000299,
    SOUND_SUSHIE_STEP                           = 0x0000029A,
    SOUND_TIDAL_WAVE_LEAP_A                     = 0x0000029B,
    SOUND_TIDAL_WAVE_LEAP_B                     = 0x0000029C,
    SOUND_TIDAL_WAVE_WATER                      = 0x0000029D,
    SOUND_SUSHIE_FLOP                           = 0x000002A0,
    SOUND_PLANT_FLOWERS                         = 0x000002A1,
    SOUND_FLOWER_GATE                           = 0x000002A2,
    SOUND_WOODEN_DOOR_SPINNING                  = 0x000002A3,
    SOUND_WOODEN_DOOR_WAVES                     = 0x000002A4,
    SOUND_RAVEN_LEAP_A                          = 0x000002A6,
    SOUND_RAVEN_LEAP_B                          = 0x000002A7,
    SOUND_LRAW_BOBOMB_FUSE                      = 0x000002A8,
    SOUND_TWINK_FLY_B                           = 0x000002AA,
    SOUND_PARAGOOMBA_DIVE                       = 0x000002C1,
    SOUND_HURT_PLANT_BITE                       = 0x000002C4,
    SOUND_SPIKE_SUMMON_SPINY                    = 0x000002C5,
    SOUND_SPIKE_THROW_SPINY                     = 0x000002C6,
    SOUND_SPINY_SPIN_UP                         = 0x000002C7,
    SOUND_BULLET_BILL_FIRE                      = 0x000002C8,
    SOUND_BULLET_BILL_MOTION                    = 0x000002C9,
    SOUND_DUPLIGHOST_STEP                       = 0x000002CA,
    SOUND_DUPLIGHOST_LEAP                       = 0x000002CB,
    SOUND_DUPLIGHOST_POWER_DOWN                 = 0x000002CC, // unused
    SOUND_SMOKE_BURST                           = 0x000002CD,
    SOUND_POKEY_THROW                           = 0x000002CE,
    SOUND_EMBER_JUMP                            = 0x000002CF,
    SOUND_EMBER_SPIT                            = 0x000002D0,
    SOUND_DRY_BONES_THROW                       = 0x000002D1,
    SOUND_DRY_BONES_COLLAPSE                    = 0x000002D2,
    SOUND_DRY_BONES_ARISE                       = 0x000002D3,
    SOUND_DRY_BONES_RATTLE                      = 0x000002D4,
    SOUND_DAYZEE_JUMP                           = 0x000002D5,
    SOUND_DAYZEE_STEP                           = 0x000002D6,
    SOUND_DAYZEE_SONG                           = 0x000002D7,
    SOUND_POWER_UP                              = 0x000002D8,
    SOUND_HYPER_CLEFT_LAND                      = 0x000002D9,
    SOUND_HYPER_CLEFT_CHARGE                    = 0x000002DA,
    SOUND_MAGIKOOPA_VANISH                      = 0x000002DB,
    SOUND_MAGIKOOPA_WAND_STRIKE                 = 0x000002DC,
    SOUND_MAGIKOOPA_POWER_UP                    = 0x000002DD,
    SOUND_SUMMON_CRYSTAL_BITS                   = 0x000002DE, // #windy #chimes
    SOUND_SUMMON_CRYSTAL_CLONES                 = 0x000002DF,
    SOUND_CRYSTAL_KING_ICE_BOLT                 = 0x000002E0,
    SOUND_SKY_GUY_BALLOON_POP                   = 0x000002E1,
    SOUND_GROOVE_GUY_TWIRL                      = 0x000002E2,
    SOUND_GROOVE_GUY_LEAP                       = 0x000002E3,
    SOUND_GROOVE_GUY_SPIN_DOWN                  = 0x000002E4,
    SOUND_CALL_FOR_BACKUP                       = 0x000002E5,
    SOUND_GROOVE_GUY_SUMMON                     = 0x000002E6,
    SOUND_SLINGSHOT_DRAW                        = 0x000002E7,
    SOUND_SLINGSHOT_FIRE                        = 0x000002E8,
    SOUND_HAMMER_BROS_THROW                     = 0x000002E9,
    SOUND_MONSTAR_CAST_SPELL                    = 0x000002EA,
    SOUND_LANTERN_GHOST_LIGHT                   = 0x000002EB,
    SOUND_POKEY_STEP                            = 0x000002EC,
    SOUND_POKEY_SMASH                           = 0x000002ED,
    SOUND_POKEY_REACH_DOWN                      = 0x000002EE,
    SOUND_ACTOR_HOP                             = 0x000002EF,
    SOUND_MAGIKOOPA_ELECTRIFY                   = 0x000002F0,
    SOUND_SNAP_AWAKE_A                          = 0x000002F1,
    SOUND_SNAP_AWAKE_B                          = 0x000002F2,
    SOUND_BUBBLE_BURST                          = 0x000002F3,
    SOUND_AI_ALERT_A                            = 0x000002F4,
    SOUND_AI_ALERT_B                            = 0x000002F5,
    SOUND_TWEESTER_LAUNCH                       = 0x000002F6,
    SOUND_SENTINEL_PICKUP                       = 0x000002F7,
    SOUND_GATHER_SMALL                          = 0x000002F8,
    SOUND_TOSS                                  = 0x000002F9,
    SOUND_SPEAR_GUY_DANCE_1                     = 0x000002FA,
    SOUND_SPEAR_GUY_DANCE_2                     = 0x000002FB,
    SOUND_SPEAR_GUY_RIP_SKIRT                   = 0x000002FC,
    SOUND_ALBINO_DINO_STEP_B                    = 0x000002FD,
    SOUND_CLOSE_SHELL                           = 0x000002FF,
    SOUND_JR_TROOPA_NEW_POWER                   = 0x00000300,
    SOUND_FALL_QUICK                            = 0x00000301,
    SOUND_FALL_LONG                             = 0x00000302,
    SOUND_LARGE_FALL_QUICK                      = 0x00000303,
    SOUND_LARGE_FALL_LONG                       = 0x00000304, // unused
    SOUND_LONG_FLUTTER_FALL_A                   = 0x00000305,
    SOUND_LONG_FLUTTER_FALL_B                   = 0x00000306,
    SOUND_SPEAR_STAB                            = 0x00000309,
    SOUND_SPEAR_THROW                           = 0x0000030A, // #whoosh
    SOUND_ALBINO_DINO_STEP_A                    = 0x0000030B,
    SOUND_SHY_GUY_SCREAMS1                      = 0x0000030C,
    SOUND_SHY_GUY_SCREAMS2                      = 0x0000030D,
    SOUND_SHY_GUY_SCREAMS3                      = 0x0000030E,
    SOUND_TOY_TANK_MOVE1                        = 0x0000030F,
    SOUND_TOY_TANK_MOVE2                        = 0x00000310,
    SOUND_AIM_SHELL_SHOT                        = 0x00000311, // #looping
    SOUND_AIM_SPINY_FLIP                        = 0x00000312, // #looping
    SOUND_TUBBA_GULP                            = 0x00000315,
    SOUND_FIRE_BAR_0_B                          = 0x00000316,
    SOUND_FIRE_BAR_1_B                          = 0x00000317,
    SOUND_FIRE_BAR_2_B                          = 0x00000318,
    SOUND_FIRE_BAR_3_B                          = 0x00000319,
    SOUND_FIRE_BAR_4_B                          = 0x0000031A,
    SOUND_FIRE_BAR_5_B                          = 0x0000031B,
    SOUND_FIRE_BAR_6_B                          = 0x0000031C,
    SOUND_FIRE_BAR_7_B                          = 0x0000031D,
    SOUND_FIRE_BAR_8_B                          = 0x0000031E,
    SOUND_FIRE_BAR_9_B                          = 0x0000031F,
    SOUND_BURROW_SURFACE                        = 0x00000321,
    SOUND_BURROW_DIG                            = 0x00000322,
    SOUND_MOLE_POP                              = 0x00000323,
    SOUND_MALLET_SWING                          = 0x00000327,
    SOUND_BLASTER_FIRE                          = 0x00000328,
    SOUND_CREEPY_LAUGH                          = 0x00000329, // #unused
    SOUND_SKID                                  = 0x0000032B,
    SOUND_NPC_JUMP                              = 0x0000032C,
    SOUND_LOWER_NPC_JUMP                        = 0x0000032D,
    SOUND_LRAW_SENTINEL_ALARM                   = 0x0000032E,
    SOUND_SNORE_INHALE_A                        = 0x0000032F,
    SOUND_SNORE_INHALE_B                        = 0x00000330,
    SOUND_FUZZY_HOP_A                           = 0x00000331,
    SOUND_FUZZY_HOP_B                           = 0x00000332,
    SOUND_FUZZY_HOP_C                           = 0x00000333,
    SOUND_SNORE_EXHALE_A                        = 0x00000334,
    SOUND_SNORE_EXHALE_B                        = 0x00000335,
    SOUND_FIRE_BAR_0_A                          = 0x00000336,
    SOUND_FIRE_BAR_1_A                          = 0x00000337,
    SOUND_FIRE_BAR_2_A                          = 0x00000338,
    SOUND_FIRE_BAR_3_A                          = 0x00000339,
    SOUND_FIRE_BAR_4_A                          = 0x0000033A,
    SOUND_FIRE_BAR_5_A                          = 0x0000033B,
    SOUND_FIRE_BAR_6_A                          = 0x0000033C,
    SOUND_FIRE_BAR_7_A                          = 0x0000033D,
    SOUND_FIRE_BAR_8_A                          = 0x0000033E,
    SOUND_FIRE_BAR_9_A                          = 0x0000033F,
    SOUND_FIRE_BAR_DEAD                         = 0x00000340,
    SOUND_LRAW_CHARGE_BAR                       = 0x00000341,
    SOUND_POKEY_SWAY                            = 0x00000342, // same as SOUND_POKEY_LEAN_BACK?
    SOUND_POKEY_WALK                            = 0x00000343,
    SOUND_POKEY_LEAN_FORWARD                    = 0x00000344,
    SOUND_POKEY_LEAN_BACK                       = 0x00000345,
    SOUND_POKEY_EMERGE_FROM_GROUND              = 0x00000346,
    SOUND_LRAW_CHEERING                         = 0x00000349,
    SOUND_SHORT_CLAP                            = 0x0000034A,
    SOUND_MULTI_CLAP                            = 0x0000034B, // #unused
    SOUND_TOY_TANK_EXPLODE                      = 0x0000034E, // #explosion
    SOUND_SLOT_REELS                            = 0x00000350, // #unused
    SOUND_ACTOR_FLIGHT                          = 0x00000351,
    SOUND_KOOPA_BROS_SPINUP                     = 0x00000353,
    SOUND_KOOPA_BROS_TOWER_SPIN_1               = 0x00000354,
    SOUND_KOOPA_BROS_TOWER_SPIN_2               = 0x00000355,
    SOUND_KOOPA_BROS_TOWER_SPIN_3               = 0x00000356,
    SOUND_BZZAP_BUZZ                            = 0x00000357, // #looping
    SOUND_MINI_BZZAP_BUZZ                       = 0x00000358,
    SOUND_EMBER_FLY                             = 0x00000359, // #looping
    SOUND_HUFF_N_PUFF_FIRE_LIGHTNING            = 0x0000035B, // #electric #boom #echoing
    SOUND_CHARGE_LIGHTNING                      = 0x0000035C, // #electric #ascending
    SOUND_HEAVY_WIND_LOOP                       = 0x0000035D, // #looping #windy
    SOUND_HEAVY_NPC_SWIPE                       = 0x0000035E,
    SOUND_BABY_BLOOPER_MOVE                     = 0x0000035F,
    SOUND_PUT_ON_CAP                            = 0x00000361,
    SOUND_BECOME_STONE                          = 0x00000362,
    SOUND_WINTERY_JINGLE                        = 0x00000363,
    SOUND_SHEEP_STAMPEDE                        = 0x00000364,
    SOUND_THUNDER_BOLT                          = 0x00000365,
    SOUND_LIGHTNING_STRIKE                      = 0x00000366,
    SOUND_FRIGHT_JAR                            = 0x00000367,
    SOUND_MYSTERY_REEL                          = 0x00000368,
    SOUND_HUSTLE_WHISTLE                        = 0x00000369,
    SOUND_SMALL_GLASS_BREAK                     = 0x00000369, // #unused
    SOUND_CRYSTAL_KING_DISAPPEAR                = 0x0000036B,
    SOUND_LRAW_SHY_GUY_CROWD_1                  = 0x0000036C,
    SOUND_LRAW_SHY_GUY_CROWD_2                  = 0x0000036D,
    SOUND_MONSTAR_STAR_STORM                    = 0x0000036E,
    SOUND_TOY_TANK_FALL_APART                   = 0x0000036F,
    SOUND_KENT_C_SHELL_TOSS_LOOP                = 0x00000370, // #looping
    SOUND_PLAYER_SPINNING                       = 0x00000371,
    SOUND_LIFE_SHROOM_CHIME                     = 0x00000372,
    SOUND_REVIVAL_MAGIC                         = 0x00000373, // #magic #chimes
    SOUND_PLAYER_REVIVE                         = 0x00000374,
    SOUND_REPEL_GEL_APPLY                       = 0x00000375,
    SOUND_REPEL_GEL_VANISH                      = 0x00000376,
    SOUND_PLANT_FIRE_FLOWER                     = 0x00000377,
    SOUND_RECOVERY_SHMMER                       = 0x00000378,
    SOUND_VOLT_SHROOM_APPLY                     = 0x00000379,
    SOUND_HIT_PLAYER_SHOCK                      = 0x0000037A,
    SOUND_HIT_SHOCK                             = 0x0000037B,
    SOUND_KOOPA_LAUNCH_SHELL                    = 0x0000037C,
    SOUND_LANTERN_GHOST_STEP                    = 0x0000037D,
    SOUND_TOY_TANK_STEP                         = 0x0000037E,
    SOUND_SHY_GUY_FLY                           = 0x00000380,
    SOUND_GOURMET_GUY_SHOCK_1                   = 0x00000381,
    SOUND_GOURMET_GUY_SHOCK_2                   = 0x00000382,
    SOUND_GOURMET_GUY_SHOCK_3                   = 0x00000383,
    SOUND_GOURMET_GUY_RUN                       = 0x00000384,
    SOUND_GOURMET_GUY_LAUNCH                    = 0x00000385,
    SOUND_BIG_DRUM_A                            = 0x00000386,
    SOUND_BIG_DRUM_B                            = 0x00000387,
    SOUND_LRAW_OMO_SLOT_MACHINE                 = 0x00000388,
    SOUND_SAM_POND_CRACK_1                      = 0x00000389,
    SOUND_SAM_POND_CRACK_2                      = 0x0000038A,
    SOUND_SAM_POND_SHATTER                      = 0x0000038B,
    SOUND_SAM_SNOWMAN_JUMP                      = 0x0000038C,
    SOUND_SAM_SNOWMEN_RAISE_WALL                = 0x0000038D,
    SOUND_SAM_SNOWMEN_OPEN_PASSAGE              = 0x0000038E,
    SOUND_TOSS_PLAYER                           = 0x00000390,
    SOUND_LRAW_SPINNING_FLOWER                  = 0x00000391,
    SOUND_MUNCHLESIA_CHEW                       = 0x00000392,
    SOUND_MUNCHLESIA_SPIT                       = 0x00000393,
    SOUND_OVEN_TIMER_TICKING                    = 0x00000394, // #looping
    SOUND_GENERAL_WHISTLE                       = 0x00000395,
    SOUND_ICE_SHATTER                           = 0x00000396,
    SOUND_PENGUIN_WHISTLE                       = 0x00000397, // identical to SOUND_GENERAL_WHISTLE
    SOUND_DRAG_PLAYER                           = 0x00000398, // #looping #windy #scraping
    SOUND_SAM07_RAISE_FLOOR                     = 0x00000399, // #ascending
    SOUND_SAM07_LOWER_FLOOR                     = 0x0000039A, // #descending
    SOUND_SAM08_RAISE_FLOOR                     = 0x0000039B, // #ascending
    SOUND_SAM_STAIRS_ACTIVATE                   = 0x0000039C,
    SOUND_SAM_STAIRS_LOUD_THUD                  = 0x0000039D,
    SOUND_LRAW_SAM_STAIRS_RISE                  = 0x0000039E,
    SOUND_SAM_STAIRS_FINAL_THUD                 = 0x0000039F,
    SOUND_MIM_MUSHROOM_GLOW                     = 0x000003A0,
    SOUND_UNUSED_TAPPING_LOOP                   = 0x000003A1, // #looping
    SOUND_SHY_GUY_FLEE_LOOP                     = 0x000003A2, // #looping
    SOUND_LANTERN_GHOST_REVEAL_MORE_1           = 0x000003A3,
    SOUND_LANTERN_GHOST_REVEAL_MORE_2           = 0x000003A4,
    SOUND_LANTERN_GHOST_REVEAL_MORE_3           = 0x000003A5,
    SOUND_LANTERN_GHOST_REVEAL_MORE_4           = 0x000003A6,
    SOUND_LANTERN_GHOST_DARKEN_1                = 0x000003A7,
    SOUND_LANTERN_GHOST_DARKEN_2                = 0x000003A8,
    SOUND_LANTERN_GHOST_DARKEN_3                = 0x000003A9,
    SOUND_LANTERN_GHOST_DARKEN_4                = 0x000003AA,
    SOUND_PIRANHA_BREATH                        = 0x000003AB,
    SOUND_GOOMBA_BROS_STEP                      = 0x000003AC,
    SOUND_LRAW_FIGHTING                         = 0x000003AD,
    SOUND_TANK_BULB_SHATTER                     = 0x000003AE,
    SOUND_CRYSTAL_KING_INHALE                   = 0x000003AF,
    SOUND_HUFF_N_PUFF_INHALE                    = 0x000003B0, // #looping
    SOUND_PIRANHA_SPIN                          = 0x000003B1,
    SOUND_PIRANHA_CHOMP                         = 0x000003B2,
    SOUND_HUFF_N_PUFF_REAR_UP                   = 0x000003B3,
    SOUND_ACTOR_STEP_B                          = 0x000003B4,
    SOUND_FAKE_BOWSER_BLAST                     = 0x000003B5, // large blasting sound when the fake bowser robot is destroyed
    SOUND_SHY_GUY_STEP_A                        = 0x000003B6,
    SOUND_SHY_GUY_STEP_B                        = 0x000003B7,
    SOUND_MASTER_LEAP                           = 0x000003B9,
    SOUND_BUBBLE_DOWN                           = 0x000003BA, // #unused #descending
    SOUND_LAVA_PIRANHA_RECOVER                  = 0x000003BB,
    SOUND_LRAW_RUMBLE                           = 0x000003BC,
    SOUND_BOWSER_FIRE_BREATH_LOOP               = 0x000003BD, // #looping #wind #rumble
    SOUND_FAKE_BOWSER_LONG_WALK                 = 0x000003BE, // #rattle
    SOUND_HUFF_N_PUFF_EMERGE                    = 0x000003C0,
    SOUND_LAVA_PIRANHA_INHALE                   = 0x000003C1,
    SOUND_LAVA_PIRANHA_SHRIVEL                  = 0x000003C2, // #unused
    SOUND_LAVA_PIRANHA_SPIT_FIRE                = 0x000003C3,
    SOUND_LAVA_PIRANHA_FIRE_BREATH              = 0x000003C4,
    SOUND_LAVA_PIRANHA_EMERGE                   = 0x000003C5,
    SOUND_LAVA_PIRANHA_DEFEAT                   = 0x000003C6,
    SOUND_LAVA_BUD_WITHER                       = 0x000003C7,
    SOUND_LAVA_PIRANHA_WITHER                   = 0x000003C8,
    SOUND_LAVA_BUD_SPIT_PETIT                   = 0x000003C9,
    SOUND_PETIT_PIRANHA_ASCEND                  = 0x000003CA,
    SOUND_PETIT_PIRANHA_DIVE                    = 0x000003CB,
    SOUND_LAVA_PIRANHA_WRITHE                   = 0x000003CC,
    SOUND_LAVA_PIRANHA_COLLAPSE                 = 0x000003CD,
    SOUND_PIRANHA_STEP                          = 0x000003CE,
    SOUND_LANTERN_GHOST_INHALE                  = 0x000003CF,
    SOUND_LANTERN_GHOST_BLOW                    = 0x000003D0,
    SOUND_HUFF_N_PUFF_FLY                       = 0x000003D1,
    SOUND_ELECTRIC_BUZZ                         = 0x000003D2,
    SOUND_HUFF_N_PUFF_LIGHTNING_BLAST           = 0x000003D3,
    SOUND_OPEN_SHELL                            = 0x000003D4,
    SOUND_RUFF_PUFF_FLY_A                       = 0x000003D5,
    SOUND_RUFF_PUFF_FLY_B                       = 0x000003D6,
    SOUND_LIGHT_THROW                           = 0x000003D9,
    SOUND_SQUEEZE                               = 0x000003DB,
    SOUND_BLOOPER_MOVE                          = 0x000003DC,
    SOUND_BLOOPER_FALL                          = 0x000003DD,
    SOUND_BLOOPER_SQUIRT                        = 0x000003DE,
    SOUND_LEECH                                 = 0x000003E0,
    SOUND_AI_FOUND_PLAYER_JUMP                  = 0x000003E1,
    SOUND_ACTOR_JUMP                            = 0x000003E2,
    SOUND_ACTOR_TRIP                            = 0x000003E3,
    SOUND_ACTOR_TWITCH                          = 0x000003E4,
    SOUND_ACTOR_DEATH                           = 0x000003E5,
    SOUND_BIG_POWER_UP                          = 0x000003E6,
    SOUND_LARGE_ACTOR_JUMP                      = 0x000003E7,
    SOUND_MOLE_THROW                            = 0x000003E8,
    SOUND_KOOPA_BROS_LAND                       = 0x000003E9,
    SOUND_FAKE_BOWSER_STEP                      = 0x000003EA,
    SOUND_SMALL_CROWD_WALK                      = 0x000003EB,
    SOUND_LARGE_CROWD_WALK                      = 0x000003EC,
    SOUND_MASTER_SMACK                          = 0x000003ED, // #electric #impact
    SOUND_MASTER_PUNCH                          = 0x000003EE,
    SOUND_BOWSER_CHARGE_LIGHTNING               = 0x000003EF,
    SOUND_DANGER                                = 0x000003F1,
    SOUND_PERIL                                 = 0x000003F2,
    SOUND_DING                                  = 0x000003F3,
    SOUND_LULLABY                               = 0x000003F4,
    SOUND_BUBBLES_RISING                        = 0x000003F5, // unused
    SOUND_DRIP                                  = 0x000003F6,
    STONE_STONE_CHOMP_STEP                      = 0x000003F9,
    SOUND_THROW                                 = 0x000003FA,
    SOUND_PLAYER_COLLAPSE                       = 0x000003FB,
    SOUND_LUCKY                                 = 0x000003FC,
    SOUND_GOOMBARIO_GATHERING                   = SOUND_ID_UNK | 0x00000003,
    SOUND_PARAKARRY_PREDIVE                     = SOUND_ID_UNK | 0x00000004,
    SOUND_PARAKARRY_DIVE                        = SOUND_ID_UNK | 0x00000005,
    SOUND_PARAKARRY_SHELL_SHOT                  = SOUND_ID_UNK | 0x00000006,
    SOUND_PARAKARRY_FLAP                        = SOUND_ID_UNK | 0x00000009,
    SOUND_PARAKARRY_AIR_RAID_1                  = SOUND_ID_UNK | 0x0000000A, // #whoosh
    SOUND_PARAKARRY_AIR_RAID_2                  = SOUND_ID_UNK | 0x0000000B, // #whoosh #echoing
    SOUND_KOOPER_SHELL_SPINUP                   = SOUND_ID_UNK | 0x0000000C,
    SOUND_GOOMBARIO_JUMP                        = SOUND_ID_UNK | 0x0000000D,
    SOUND_BOW_VANISH                            = SOUND_ID_UNK | 0x0000000E,
    SOUND_BOW_APPEAR                            = SOUND_ID_UNK | 0x0000000F,
    SOUND_EGG_MISSILE_BLAST                     = SOUND_ID_UNK | 0x00000010,
    SOUND_WATT_REPEL_DARKNESS                   = SOUND_ID_UNK | 0x00000011,
    SOUND_WATT_RESUME_DARKNESS                  = SOUND_ID_UNK | 0x00000012,
    SOUND_SUSHIE_EMBARK                         = SOUND_ID_UNK | 0x00000013,
    SOUND_SUSHIE_RIDE_IDLE                      = SOUND_ID_UNK | 0x00000014,
    SOUND_SUSHIE_RIDE_MOVING                    = SOUND_ID_UNK | 0x00000015,
    SOUND_BOMBETTE_BLAST_LV1                    = SOUND_ID_UNK | 0x00000016,
    SOUND_BOMBETTE_BLAST_LV2                    = SOUND_ID_UNK | 0x00000017,
    SOUND_BOMBETTE_BLAST_LV3                    = SOUND_ID_UNK | 0x00000018,
    SOUND_BOW_SMACK                             = SOUND_ID_UNK | 0x00000019,
    SOUND_BOW_FAN_SMACK                         = SOUND_ID_UNK | 0x0000001A,
    SOUND_LAKILESTER_THROW_SPINY_A              = SOUND_ID_UNK | 0x0000001B,
    SOUND_LAKILESTER_THROW_SPINY_B              = SOUND_ID_UNK | 0x0000001C,
    SOUND_LAKILESTER_MAKE_CLOUD_NINE            = SOUND_ID_UNK | 0x0000001D,
    SOUND_LAKILESTER_HURRICANE_INHALE           = SOUND_ID_UNK | 0x0000001E,
    SOUND_LAKILESTER_HURRICANE_EXHALE           = SOUND_ID_UNK | 0x0000001F,
    SOUND_BOMBETTE_BODY_SLAM                    = SOUND_ID_UNK | 0x00000020,
    SOUND_SHELL_SPIN                            = SOUND_ID_UNK | 0x00000021,
    SOUND_FAN_SMACK_HIT                         = SOUND_ID_UNK | 0x00000022, // #windy
    SOUND_FAN_SMACK_END                         = SOUND_ID_UNK | 0x00000023, // #windy
    SOUND_WATT_MEGA_CHARGE_WAVE                 = SOUND_ID_UNK | 0x00000024,
    SOUND_DIZZY_SHELL                           = SOUND_ID_UNK | 0x00000026,
    SOUND_SHUFFLE_CARD_A                        = SOUND_ID_UNK | 0x0000002A,
    SOUND_SHUFFLE_CARD_B                        = SOUND_ID_UNK | 0x0000002B,
    SOUND_FIRE_FLOWER_A                         = SOUND_ID_UNK | 0x0000002C,
    SOUND_FIRE_FLOWER_B                         = SOUND_ID_UNK | 0x0000002D,
    SOUND_SNOWMAN_DOLL_JUMP                     = SOUND_ID_UNK | 0x0000002E,
    SOUND_NOISE_RUSH                            = SOUND_ID_UNK | 0x0000002F, // unused
    SOUND_POW_BLOCK                             = SOUND_ID_UNK | 0x00000030,
    SOUND_INFLICT_SLEEP                         = SOUND_ID_UNK | 0x00000031,
    SOUND_INFLICT_STATUS                        = SOUND_ID_UNK | 0x00000032,
    SOUND_DIZZY_DIAL                            = SOUND_ID_UNK | 0x00000033,
    SOUND_SUSHIE_BELLY_FLOP                     = SOUND_ID_UNK | 0x00000034,
    SOUND_CREATE_WATER_BLOCK                    = SOUND_ID_UNK | 0x00000035,
    SOUND_WHALE_OPEN_MOUTH                      = SOUND_ID_UNK | 0x00000036,
    SOUND_WHALE_CLOSE_MOUTH                     = SOUND_ID_UNK | 0x00000037,
    SOUND_TUBBA_SNORE_INHALE                    = SOUND_ID_UNK | 0x00000038,
    SOUND_TUBBA_SNORE_EXHALE                    = SOUND_ID_UNK | 0x00000039,
    SOUND_KPA_BRIDGE_COLLAPSE_A                 = SOUND_ID_UNK | 0x0000003A,
    SOUND_KPA_BRIDGE_COLLAPSE_B                 = SOUND_ID_UNK | 0x0000003B,
    SOUND_KPA_ARENA_EXPLODING                   = SOUND_ID_UNK | 0x0000003C,
    SOUND_OBK_STAIRS_DROP                       = SOUND_ID_UNK | 0x0000003D,
    SOUND_SHY_GUY_OUCH                          = SOUND_ID_UNK | 0x0000003E,
    SOUND_SHY_GUY_RUN_AWAY                      = SOUND_ID_UNK | 0x0000003F,
    SOUND_KPA_FLIP_BRIDGE_PANEL                 = SOUND_ID_UNK | 0x00000040,
    SOUND_STAR_SPIRIT_APPEAR_A                  = SOUND_ID_UNK | 0x00000041,
    SOUND_STAR_SPIRIT_APPEAR_B                  = SOUND_ID_UNK | 0x00000042,
    SOUND_STAR_SPIRIT_CAST_A                    = SOUND_ID_UNK | 0x00000043,
    SOUND_STAR_SPIRIT_CAST_B                    = SOUND_ID_UNK | 0x00000044,
    SOUND_STAR_SPIRIT_DEPART_1                  = SOUND_ID_UNK | 0x00000045,
    SOUND_STAR_SPIRIT_DEPART_2                  = SOUND_ID_UNK | 0x00000046,
    SOUND_STAR_SPIRIT_DEPART_3                  = SOUND_ID_UNK | 0x00000047,
    SOUND_DARK_TOAD_DISPEL                      = SOUND_ID_UNK | 0x00000049,
    SOUND_OPEN_MAGIC_CHEST                      = SOUND_ID_UNK | 0x0000004A,
    SOUND_CLOSE_MAGIC_CHEST                     = SOUND_ID_UNK | 0x0000004B,
    SOUND_QUICK_HINGE                           = SOUND_ID_UNK | 0x0000004C, // unused
    SOUND_FLO_MOVE_PILLAR                       = SOUND_ID_UNK | 0x0000004D,
    SOUND_WISH_ASCENDING                        = SOUND_ID_UNK | 0x00000051,
    SOUND_UP_AND_AWAY_SEND_AWAY                 = SOUND_ID_UNK | 0x00000052,
    SOUND_STAR_POWER_RECOVERY                   = SOUND_ID_UNK | 0x00000053,
    SOUND_START_RECOVERY                        = SOUND_ID_UNK | 0x00000055,
    SOUND_RECOVER                               = SOUND_ID_UNK | 0x00000056,
    SOUND_FLOWERS_LIGHT_GIGGLE                  = SOUND_ID_UNK | 0x00000059,
    SOUND_FLOWERS_SAD_GIGGLE                    = SOUND_ID_UNK | 0x0000005A,
    SOUND_FLOWERS_LAUGH                         = SOUND_ID_UNK | 0x0000005B,
    SOUND_FLOWERS_WITHER                        = SOUND_ID_UNK | 0x0000005C,
    SOUND_FLOWERS_GROW                          = SOUND_ID_UNK | 0x0000005D,
    SOUND_ROCK_LAUGHTER                         = SOUND_ID_UNK | 0x0000005E,
    SOUND_TREE_LAUGHTER                         = SOUND_ID_UNK | 0x0000005F,
    SOUND_IMPISH_LAUGH                          = SOUND_ID_UNK | 0x00000060,
    SOUND_CHAIN_CHOMP_BITE                      = SOUND_ID_UNK | 0x00000061,
    SOUND_CHAIN_CHOMP_THUD                      = SOUND_ID_UNK | 0x00000062,
    SOUND_CHAIN_RATTLE                          = SOUND_ID_UNK | 0x00000063,
    SOUND_SHY_STACK_SQUISH                      = SOUND_ID_UNK | 0x00000064,
    SOUND_STILT_GUY_UNFOLD                      = SOUND_ID_UNK | 0x00000065,
    SOUND_STILT_GUY_STEP                        = SOUND_ID_UNK | 0x00000066,
    SOUND_STILTS_FALL                           = SOUND_ID_UNK | 0x00000067, // #woody
    SOUND_TANK_BULB_FIRE                        = SOUND_ID_UNK | 0x00000069, // #electric
    SOUND_TOY_TANK_OPEN_HATCH                   = SOUND_ID_UNK | 0x0000006A,
    SOUND_TOY_TANK_CLOSE_HATCH                  = SOUND_ID_UNK | 0x0000006B,
    SOUND_WOODEN_BLOCK                          = SOUND_ID_UNK | 0x0000006C, // #unused
    SOUND_RECOVER_HEART                         = SOUND_ID_UNK | 0x0000006D, // #magic
    SOUND_FUZZY_RUMBLE                          = SOUND_ID_UNK | 0x0000006E,
    SOUND_FUZZY_SHAKE                           = SOUND_ID_UNK | 0x0000006F,
    SOUND_FUZZY_DIVIDE                          = SOUND_ID_UNK | 0x00000070,
    SOUND_UP_AND_AWAY_CAPTURE                   = SOUND_ID_UNK | 0x00000071,
    SOUND_YOSHI                                 = SOUND_ID_UNK | 0x00000072,
    SOUND_HIT_WHACKA                            = SOUND_ID_UNK | 0x00000073,
    SOUND_MAGIC_ASCENDING                       = SOUND_ID_UNK | 0x00000074, // #magic #ascending
    SOUND_MAGIC_DESCENDING                      = SOUND_ID_UNK | 0x00000075, // #magic #descending
    SOUND_BOMB_BLAST                            = SOUND_ID_UNK | 0x00000076,
    SOUND_BULLET_BILL_EXPLODE_A                 = SOUND_ID_UNK | 0x00000078,
    SOUND_BULLET_BILL_EXPLODE_B                 = SOUND_ID_UNK | 0x00000079,
    SOUND_KAMMY_SUMMON_MAGIC                    = SOUND_ID_UNK | 0x0000007A,
    SOUND_KAMMY_SUMMON_BLOCK                    = SOUND_ID_UNK | 0x0000007B,
    SOUND_KAMMY_RAISE_OBJECT                    = SOUND_ID_UNK | 0x0000007C,
    SOUND_KAMMY_LOWER_OBJECT                    = SOUND_ID_UNK | 0x0000007D,
    SOUND_TWINK_ATTACK                          = SOUND_ID_UNK | 0x0000007E,
    SOUND_TWINK_FLY_A                           = SOUND_ID_UNK | 0x0000007F,
    SOUND_QUICK_PLAYER_JUMP                     = SOUND_ID_UNK | 0x00000081,
    SOUND_JUMP_8BIT_MARIO                       = SOUND_ID_UNK | 0x00000082,
    SOUND_STAR_BOX_LAUNCHER                     = SOUND_ID_UNK | 0x00000085,
    SOUND_SPRING                                = SOUND_ID_UNK | 0x00000086,
    SOUND_ZIPLINE_FINISH                        = SOUND_ID_UNK | 0x00000087,
    SOUND_PUSH_BLOCK                            = SOUND_ID_UNK | 0x00000088,
    SOUND_PULL_VINE                             = SOUND_ID_UNK | 0x00000089,
    SOUND_FLOOR_SWITCH_DEPRESS                  = SOUND_ID_UNK | 0x0000008A,
    SOUND_FLOOR_SWITCH_ACTIVATE                 = SOUND_ID_UNK | 0x0000008B,
    SOUND_NO_DAMGE                              = SOUND_ID_UNK | 0x0000008C,
    SOUND_USE_ITEM                              = SOUND_ID_UNK | 0x0000008D,
    SOUND_GROW                                  = SOUND_ID_UNK | 0x0000008E,
    SOUND_CHARGE_UP                             = SOUND_ID_UNK | 0x0000008F,
    SOUND_OPEN_TRAPDOOR                         = SOUND_ID_UNK | 0x00000091,
    SOUND_BREAK_FLOOR                           = SOUND_ID_UNK | 0x00000092,
    SOUND_SPIKES_EXTEND                         = SOUND_ID_UNK | 0x00000093,
    SOUND_JUMP_SCARE                            = SOUND_ID_UNK | 0x00000094,
    SOUND_EAT_OR_DRINK                          = SOUND_ID_UNK | 0x00000095,
    SOUND_SPIT_OUT                              = SOUND_ID_UNK | 0x00000096,
    SOUND_GLASS_SHATTER                         = SOUND_ID_UNK | 0x00000097,
    SOUND_VANISH_IN_SMOKE                       = SOUND_ID_UNK | 0x00000098,
    SOUND_HEART_PLANT                           = SOUND_ID_UNK | 0x00000099,
    SOUND_HURT_PLANT_SHRIEK                     = SOUND_ID_UNK | 0x0000009A,
    SOUND_MUNCHLESIA_SUCTION                    = SOUND_ID_UNK | 0x0000009B,
    SOUND_JAN_LOG_LAND                          = SOUND_ID_UNK | 0x0000009D,
    SOUND_JAN_LOG_SPLIT                         = SOUND_ID_UNK | 0x0000009E,
    SOUND_SEPARATE_BUSHES                       = SOUND_ID_UNK | 0x0000009F,
    SOUND_LARGE_NPC_IMPACT                      = SOUND_ID_UNK | 0x000000A0,
    SOUND_STARSHIP_BOOST                        = SOUND_ID_UNK | 0x000000A1,
    SOUND_IWA_SLIDE_GATE                        = SOUND_ID_UNK | 0x000000A2,
    SOUND_CREAKY_WINDOW_OPEN                    = SOUND_ID_UNK | 0x000000A3,
    SOUND_CREAKY_WINDOW_CLOSE                   = SOUND_ID_UNK | 0x000000A4,
    SOUND_TRAIN_DOOR_OPEN                       = SOUND_ID_UNK | 0x000000A5,
    SOUND_TRAIN_DOOR_CLOSE                      = SOUND_ID_UNK | 0x000000A6,
    SOUND_TURN_MECHANISM                        = SOUND_ID_UNK | 0x000000A7,
    SOUND_CAPSULE_OPEN                          = SOUND_ID_UNK | 0x000000A8,
    SOUND_FLIP_PANEL                            = SOUND_ID_UNK | 0x000000AB,
    SOUND_CLOSE_PANEL                           = SOUND_ID_UNK | 0x000000AC,
    SOUND_WATER_SPLASH                          = SOUND_ID_UNK | 0x000000AD,
    SOUND_BREAK_CRATE                           = SOUND_ID_UNK | 0x000000AE, // #boing
    SOUND_HOLLOW_RISING                         = SOUND_ID_UNK | 0x000000AF, // #unused
    SOUND_HOLLOW_FALLING                        = SOUND_ID_UNK | 0x000000B0, // #unused
    SOUND_PIRANHA_SPIN_1                        = SOUND_ID_UNK | 0x000000B1,
    SOUND_PIRANHA_SPIN_2                        = SOUND_ID_UNK | 0x000000B2,
    SOUND_PIRANHA_TENSE                         = SOUND_ID_UNK | 0x000000B3,
    SOUND_HEAVY_NPC_STEP_B                      = SOUND_ID_UNK | 0x000000B4,
    SOUND_HUFF_N_PUFF_JIGGLE                    = SOUND_ID_UNK | 0x000000B6,
    SOUND_HUFF_N_PUFF_WOBBLE                    = SOUND_ID_UNK | 0x000000B7,
    SOUND_GHOST_TRANSFORM                       = SOUND_ID_UNK | 0x000000B8,
    SOUND_JR_TROOPA_TRANSFORM                   = SOUND_ID_UNK | 0x000000B9,
    SOUND_ACTOR_STEP_A                          = SOUND_ID_UNK | 0x000000BA,
    SOUND_MASTER_FLUTTER                        = SOUND_ID_UNK | 0x000000BB,
    SOUND_MASTER_KICK                           = SOUND_ID_UNK | 0x000000BC,
    SOUND_MASTER_STANCE_CHANGE                  = SOUND_ID_UNK | 0x000000BD,
    SOUND_MASTER_FLIP                           = SOUND_ID_UNK | 0x000000BE,
    SOUND_LAVA_BUD_RECOVER                      = SOUND_ID_UNK | 0x000000BF,
    SOUND_SMALL_NPC_STEP                        = SOUND_ID_UNK | 0x000000C1,
    SOUND_BANDIT_STEAL                          = SOUND_ID_UNK | 0x000000C2,
    SOUND_DISAPPOINTED                          = SOUND_ID_UNK | 0x000000C3,
    SOUND_CLUBBA_STEP                           = SOUND_ID_UNK | 0x000000C4,
    SOUND_CLUBBA_SWING                          = SOUND_ID_UNK | 0x000000C5,
    SOUND_MBUSH_STEP                            = SOUND_ID_UNK | 0x000000C6,
    SOUND_TUBBA_HEART_JUMP                      = SOUND_ID_UNK | 0x000000C8,
    SOUND_MBUSH_LEAP                            = SOUND_ID_UNK | 0x000000C9,
    SOUND_BZZAP_STING                           = SOUND_ID_UNK | 0x000000CA,
    SOUND_MINI_BZZAP_STING                      = SOUND_ID_UNK | 0x000000CB,
    SOUND_BZZAP_CALL_SWARM                      = SOUND_ID_UNK | 0x000000CC,
    SOUND_BONY_BEETLE_STEP                      = SOUND_ID_UNK | 0x000000CD,
    SOUND_BONY_BEETLE_EXTEND_SPIKES             = SOUND_ID_UNK | 0x000000CE,
    SOUND_BONY_BEETLE_RETRACT_SPIKES            = SOUND_ID_UNK | 0x000000CF,
    SOUND_CLEFT_STEP                            = SOUND_ID_UNK | 0x000000D0,
    SOUND_CLEFT_TACKLE                          = SOUND_ID_UNK | 0x000000D1,
    SOUND_LAKITU_THROW_SPINY                    = SOUND_ID_UNK | 0x000000D2,
    SOUND_SHELL_TOSS                            = SOUND_ID_UNK | 0x000000D3,
    SOUND_SPELL_CAST1                           = SOUND_ID_UNK | 0x000000D4,
    SOUND_SPELL_CAST2                           = SOUND_ID_UNK | 0x000000D5,
    SOUND_SPELL_CAST3                           = SOUND_ID_UNK | 0x000000D6,
    SOUND_SPELL_CAST4                           = SOUND_ID_UNK | 0x000000D7,
    SOUND_SPELL_CAST5                           = SOUND_ID_UNK | 0x000000D8, // unused
    SOUND_FUZZIPEDE_MOTION                      = SOUND_ID_UNK | 0x000000D9,
    SOUND_FUZZIPEDE_LEAP                        = SOUND_ID_UNK | 0x000000DA, // #boing #spring #bounce
    SOUND_FUZZIPEDE_STRIKE                      = SOUND_ID_UNK | 0x000000DB, // #boing #spring
    SOUND_COMMAND_LOSS                          = SOUND_ID_UNK | 0x000000DC,
    SOUND_GOOMBA_STEP                           = SOUND_ID_UNK | 0x000000DD,
    SOUND_PIRANHA_BITE                          = SOUND_ID_UNK | 0x000000DE,
    SOUND_PARAGOOMBA_FLY                        = SOUND_ID_UNK | 0x000000DF,
    SOUND_PARAGOOMBA_PREDIVE                    = SOUND_ID_UNK | 0x000000E0,
    SOUND_TUTANKOOPA_MAGIC                      = SOUND_ID_UNK | 0x000000E1,
    SOUND_JR_TOOPA_JUMP                         = SOUND_ID_UNK | 0x000000E2,
    SOUND_ACTOR_WITHER                          = SOUND_ID_UNK | 0x000000E3,
    SOUND_ACTOR_COLLAPSE                        = SOUND_ID_UNK | 0x000000E4,
    SOUND_KNOCKOUT_CHIRPING                     = SOUND_ID_UNK | 0x000000E5, // #bird #chirping
    SOUND_TUTANKOOPA_LEVITATE                   = SOUND_ID_UNK | 0x000000E6,
    SOUND_SPOOKY_LEVITATE                       = SOUND_ID_UNK | 0x000000E7,
    SOUND_ILLUSION_DISSOLVE                     = SOUND_ID_UNK | 0x000000E8,
    SOUND_HEAVY_NPC_FALLING                     = SOUND_ID_UNK | 0x000000E9, // #falling
    SOUND_HEAVY_NPC_LANDING                     = SOUND_ID_UNK | 0x000000EA, // #echoing #thud #impact
    SOUND_TUTANKOOPA_DEBRIS_FALL                = SOUND_ID_UNK | 0x000000EB, // #falling
    SOUND_HEAVY_NPC_STEP_A                      = SOUND_ID_UNK | 0x000000EC,
    SOUND_GOOMBA_KING_SPIN                      = SOUND_ID_UNK | 0x000000ED,
    SOUND_GULPIT_LICK                           = SOUND_ID_UNK | 0x000000EE,
    SOUND_BUZZAR_FLAP                           = SOUND_ID_UNK | 0x000000EF,
    SOUND_BUZZAR_WHIRLWIND                      = SOUND_ID_UNK | 0x000000F0, // #windy
    SOUND_BUZZAR_WINDUP                         = SOUND_ID_UNK | 0x000000F1,
    SOUND_BUZZAR_DIVE                           = SOUND_ID_UNK | 0x000000F2,
    SOUND_SMALL_LENS_FLARE                      = SOUND_ID_UNK | 0x000000F3,
    SOUND_BUZZAR_THROW                          = SOUND_ID_UNK | 0x000000F4,
    SOUND_BUZZAR_GRAB                           = SOUND_ID_UNK | 0x000000F5,
    SOUND_HEAVY_NPC_STEP_C                      = SOUND_ID_UNK | 0x000000F6,
    SOUND_TUBBAS_HEART_CHARGE                   = SOUND_ID_UNK | 0x000000F7,
    SOUND_TUBBAS_HEART_SWARM_ATTACK             = SOUND_ID_UNK | 0x000000F9,
    SOUND_TUBBAS_HEART_SWARM_DISPERSE           = SOUND_ID_UNK | 0x000000FB,
    SOUND_TUBBAS_HEART_SWARM_VANISH             = SOUND_ID_UNK | 0x000000FC,
    SOUND_FAKE_BOWSER_SWING                     = SOUND_ID_UNK | 0x000000FD,
    SOUND_FAKE_BOWSER_STRIKE                    = SOUND_ID_UNK | 0x000000FE,
    SOUND_FILE_MENU_MOVE_CURSOR                 = SOUND_ID_UNK | 0x00000101,
    SOUND_CREATE_FILE_MOVE_CURSOR               = SOUND_ID_UNK | 0x00000102,
    SOUND_CREATE_FILE_SET_CHARACTER             = SOUND_ID_UNK | 0x00000103,
    SOUND_CREATE_FILE_BACKSPACE                 = SOUND_ID_UNK | 0x00000104,
    SOUND_CREATE_FILE_CHANGE_CHARSET            = SOUND_ID_UNK | 0x00000105,
    SOUND_INFLICT_CHILL_OUT                     = SOUND_ID_UNK | 0x00000106,
    SOUND_INFLICT_KO                            = SOUND_ID_UNK | 0x00000107,
    SOUND_SPAWN_BLOCK                           = SOUND_ID_UNK | 0x00000108,
    SOUND_D_DOWN_HIT_1                          = SOUND_ID_UNK | 0x0000010A,
    SOUND_D_DOWN_HIT_2                          = SOUND_ID_UNK | 0x0000010B,
    SOUND_D_DOWN_HIT_3                          = SOUND_ID_UNK | 0x0000010C,
    SOUND_SPIN                                  = SOUND_ID_UNK | 0x00000111,
    SOUND_SPEEDY_SPIN                           = SOUND_ID_UNK | 0x00000112,
    SOUND_SPIN_ATTACK                           = SOUND_ID_UNK | 0x00000113,
    SOUND_SPEEDY_SPIN_ATTACK                    = SOUND_ID_UNK | 0x00000114,
    SOUND_HAMMER_SWING_1                        = SOUND_ID_UNK | 0x00000115,
    SOUND_HAMMER_SWING_2                        = SOUND_ID_UNK | 0x00000116,
    SOUND_HAMMER_SWING_3                        = SOUND_ID_UNK | 0x00000117,
    SOUND_HAMMER_STRIKE_1                       = SOUND_ID_UNK | 0x00000118,
    SOUND_HAMMER_STRIKE_2                       = SOUND_ID_UNK | 0x00000119,
    SOUND_HAMMER_STRIKE_3                       = SOUND_ID_UNK | 0x0000011A,
    SOUND_HAMMER_QUAKE_1                        = SOUND_ID_UNK | 0x0000011B,
    SOUND_HAMMER_QUAKE_2                        = SOUND_ID_UNK | 0x0000011C,
    SOUND_HAMMER_QUAKE_3                        = SOUND_ID_UNK | 0x0000011D,
    SOUND_SPIN_SMASH_1                          = SOUND_ID_UNK | 0x0000011E,
    SOUND_SPIN_SMASH_2                          = SOUND_ID_UNK | 0x0000011F,
    SOUND_SPIN_SMASH_3                          = SOUND_ID_UNK | 0x00000120,
    SOUND_BOWSER_STAR_ROD_USE                   = SOUND_ID_UNK | 0x00000121,
    SOUND_BOWSER_STAR_ROD_DRAIN_WAVE            = SOUND_ID_UNK | 0x00000122,
    SOUND_BOWSER_STAR_ROD_GATHER                = SOUND_ID_UNK | 0x00000123,
    SOUND_BOWSER_STAR_ROD_SHOCKWAVE             = SOUND_ID_UNK | 0x00000124,
    SOUND_BOWSER_STAR_ROD_ENCHANT               = SOUND_ID_UNK | 0x00000125,
    SOUND_BOWSER_CAST_RECOVER                   = SOUND_ID_UNK | 0x00000126,
    SOUND_BOWSER_LIGHTNING                      = SOUND_ID_UNK | 0x00000127,
    SOUND_BOWSER_POWER_DOWN                     = SOUND_ID_UNK | 0x00000128,
    SOUND_BOWSER_COLLAPSE                       = SOUND_ID_UNK | 0x00000129,
    SOUND_OBK_CHANDELIER_RELEASE                = SOUND_ID_UNK | 0x0000012A,
    SOUND_OBK_CHANDELIER_STOP                   = SOUND_ID_UNK | 0x0000012B,
    SOUND_OBK_CHANDELIER_RETRACT                = SOUND_ID_UNK | 0x0000012C,
    SOUND_RELEASE_ENERGY                        = SOUND_ID_UNK | 0x0000012D,
    SOUND_GATHER_ENERGY                         = SOUND_ID_UNK | 0x0000012E,
    // looping sounds
    SOUND_LOOP_BOMBETTE_FUSE                    = 0x80000000,
    SOUND_LOOP_BOBOMB_FUSE                      = 0x80000001,
    SOUND_LOOP_ISK_FLIP_STAIRS                  = 0x80000002,
    SOUND_LOOP_ISK_LOWER_STAIRS                 = 0x80000003,
    SOUND_LOOP_TRD_02_LOWER_STAIRS              = 0x80000004,
    SOUND_LOOP_TRD_04_LOWER_STAIRS              = 0x80000005,
    SOUND_LOOP_TRD_FLOWING_WATER                = 0x80000006,
    SOUND_LOOP_TRD_RAISE_STAIRS                 = 0x80000007,
    SOUND_LOOP_CHEERING                         = 0x80000008,
    SOUND_LOOP_IWA10_FLOW1                      = 0x80000009,
    SOUND_LOOP_IWA_UNUSED_FLOW3                 = 0x8000000A, // #unused
    SOUND_LOOP_IWA00_FLOW3                      = 0x8000000B,
    SOUND_LOOP_IWA00_FLOW2                      = 0x8000000C,
    SOUND_LOOP_IWA01_FLOW1                      = 0x8000000D,
    SOUND_LOOP_IWA01_FLOW2                      = 0x8000000E,
    SOUND_LOOP_OBK_LOWER_CHAIN                  = 0x8000000F,
    SOUND_LOOP_MOVE_STATUE                      = 0x80000010,
    SOUND_LOOP_SENTINEL_ALARM                   = 0x80000011,
    SOUND_LOOP_QUIZ_TICKING                     = 0x80000012, // #unused
    SOUND_LOOP_AUDIENCE_MURMUR                  = 0x80000013, // #unused
    SOUND_LOOP_TOYBOX_TRAIN_GEAR                = 0x80000014, // #unused
    SOUND_LOOP_OMO_SLOT_MACHINE                 = 0x80000015,
    SOUND_LOOP_OMO_ROTATING_WHEEL               = 0x80000016,
    SOUND_LOOP_JAN_BEACH_WAVES                  = 0x80000017,
    SOUND_LOOP_MOVE_LARGE_STATUE                = 0x80000018,
    SOUND_LOOP_ZIPLINE_RIDE                     = 0x80000019,
    SOUND_LOOP_ZIPLINE_RETURN                   = 0x8000001A,
    SOUND_LOOP_TROMP_ROLL                       = 0x8000001B,
    SOUND_LOOP_JAN_SMALL_GEYSER                 = 0x8000001C,
    SOUND_LOOP_JAN_LARGE_GEYSER                 = 0x8000001D,
    SOUND_LOOP_JAN_CONSTRUCTION                 = 0x8000001E,
    SOUND_LOOP_NOTHING_1F                       = 0x8000001F, // #unused #nodata
    SOUND_LOOP_NOTHING_20                       = 0x80000020, // #unused #nodata
    SOUND_LOOP_FLO_WATER_FLOW_1                 = 0x80000021,
    SOUND_LOOP_FLO_WATER_FLOW_2                 = 0x80000022,
    SOUND_LOOP_BUBBLE_DRIFT                     = 0x80000023,
    SOUND_LOOP_FLO_RELEASE_FOUNTAIN             = 0x80000024,
    SOUND_LOOP_PUFF_PUFF_MACHINE                = 0x80000025,
    SOUND_LOOP_NOTHING_26                       = 0x80000026, // #unused #nodata
    SOUND_LOOP_TIK01_WATER                      = 0x80000027,
    SOUND_LOOP_TIK02_WATER                      = 0x80000028,
    SOUND_LOOP_TIK02_FLOW2                      = 0x80000029,
    SOUND_LOOP_TIK02_FLOW3                      = 0x8000002A,
    SOUND_LOOP_TIK03_WATER                      = 0x8000002B,
    SOUND_LOOP_TIK03_FLOW1                      = 0x8000002C,
    SOUND_LOOP_TIK05_WATER                      = 0x8000002D,
    SOUND_LOOP_TIK05_FLOW1                      = 0x8000002E,
    SOUND_LOOP_TIK06_WATER                      = 0x8000002F,
    SOUND_LOOP_TIK06_FLOW2                      = 0x80000030,
    SOUND_LOOP_TIK06_FLOW3                      = 0x80000031,
    SOUND_LOOP_TIK06_FLOW4                      = 0x80000032,
    SOUND_LOOP_TIK08_WATER                      = 0x80000033,
    SOUND_LOOP_TIK08_FLOW1                      = 0x80000034,
    SOUND_LOOP_TIK09_WATER                      = 0x80000035,
    SOUND_LOOP_TIK09_FLOW2                      = 0x80000036,
    SOUND_LOOP_TIK09_FLOW4                      = 0x80000037,
    SOUND_LOOP_TIK09_FLOW3                      = 0x80000038,
    SOUND_LOOP_TIK10_WATER                      = 0x80000039,
    SOUND_LOOP_TIK_UNUSED1_WATER                = 0x8000003A, // #unused
    SOUND_LOOP_TIK_UNUSED2_WATER                = 0x8000003B, // #unused
    SOUND_LOOP_TIK_UNUSED3_WATER                = 0x8000003C, // #unused
    SOUND_LOOP_TIK_UNUSED3_FLOW4                = 0x8000003D, // #unused
    SOUND_LOOP_TIK_UNUSED3_FLOW3                = 0x8000003E, // #unused
    SOUND_LOOP_TIK_UNUSED3_FLOW2                = 0x8000003F, // #unused
    SOUND_LOOP_SAM_STAIRS_RISE                  = 0x80000040,
    SOUND_LOOP_CHARGE_BAR                       = 0x80000041,
    SOUND_LOOP_CRYSTAL_BALL_GLOW                = 0x80000042,
    SOUND_LOOP_TIK18_WATER                      = 0x80000043,
    SOUND_LOOP_TIK19_WATER                      = 0x80000044,
    SOUND_LOOP_TIK19_FLOW3                      = 0x80000045,
    SOUND_LOOP_TIK19_FLOW4                      = 0x80000046,
    SOUND_LOOP_TIK20_WATER                      = 0x80000047,
    SOUND_LOOP_TIK23_WATER                      = 0x80000048,
    SOUND_LOOP_TIK24_WATER                      = 0x80000049,
    SOUND_LOOP_WINDMILL_EXT                     = 0x8000004A,
    SOUND_LOOP_WINDMILL_GEARS                   = 0x8000004B,
    SOUND_LOOP_SHY_GUY_CROWD_1                  = 0x8000004C,
    SOUND_LOOP_SHY_GUY_CROWD_2                  = 0x8000004D,
    SOUND_LOOP_FLIGHT                           = 0x8000004E, // #unused
    SOUND_LOOP_WHALE_GEYSER                     = 0x8000004F,
    SOUND_LOOP_FLO_FILL_WATER_POOL              = 0x80000050,
    SOUND_LOOP_KPA_CHAIN_DRIVE                  = 0x80000051,
    SOUND_LOOP_KPA_FILL_WATER                   = 0x80000052,
    SOUND_LOOP_KPA_DRAIN_WATER                  = 0x80000053,
    SOUND_LOOP_KPA_FLIP_BRIDGE_PANEL            = 0x80000054, // #unused
    SOUND_LOOP_JR_TROOPA_SWIM                   = 0x80000055,
    SOUND_LOOP_KKJ_RUMBLING                     = 0x80000056,
    SOUND_LOOP_OSR_RUMBLING                     = 0x80000057,
    SOUND_LOOP_MAC_HARBOR_WATER                 = 0x80000058,
    SOUND_LOOP_OSR_FOUNTAIN_INTACT              = 0x80000059,
    SOUND_LOOP_OSR_FOUNTAIN_BROKEN              = 0x8000005A,
    SOUND_LOOP_NOK_WATER                        = 0x8000005B,
    SOUND_LOOP_TRD_WATER_EXT                    = 0x8000005C,
    SOUND_LOOP_DGB_COLLAPSE                     = 0x8000005D,
    SOUND_LOOP_SBK_RUINS_RISING                 = 0x8000005E,
    SOUND_LOOP_SBK_RUINS_WHIRLWIND              = 0x8000005F,
    SOUND_LOOP_SBK_RUINS_RISING_DISTANT         = 0x80000060,
    SOUND_LOOP_SBK_OASIS_WATER                  = 0x80000061,
    SOUND_LOOP_62                               = 0x80000062, // unused, no data
    SOUND_LOOP_STAR_SANCTUARY_FAR               = 0x80000063,
    SOUND_LOOP_STAR_SANCTUARY_NEAR              = 0x80000064,
    SOUND_LOOP_STAR_SANCTUARY_INSIDE            = 0x80000065,
    SOUND_LOOP_BOWSER_PROPELLER                 = 0x80000066,
    SOUND_LOOP_STAR_ORB_RISING                  = 0x80000067,
    SOUND_LOOP_USE_STAR_BEAM                    = 0x80000068,
    SOUND_LOOP_USE_PEACH_BEAM                   = 0x80000069,
    SOUND_LOOP_SPINNING_FLOWER                  = 0x8000006A, // doesn't loop
    SOUND_LOOP_RUMBLE                           = 0x8000006B,
    SOUND_LOOP_FIGHTING                         = 0x8000006C,
    SOUND_LOOP_KPA_ARENA_TURN_ON                = 0x8000006D, // unused
    SOUND_LOOP_KPA_ARENA_ACTIVE                 = 0x8000006E, // unused
    // exit doors
    SOUND_DOOR_OPEN                             = 0x90000000,
    SOUND_DOOR_CLOSE                            = 0x90000001,
    // room doors
    SOUND_ROOM_DOOR_OPEN                        = 0xA0000000,
    SOUND_ROOM_DOOR_CLOSE                       = 0xA0000001,
    // alternating sounds
    SOUND_SEQ_FIRE_BAR_0                        = 0xB0000000,
    SOUND_SEQ_FIRE_BAR_1                        = 0xB0000001,
    SOUND_SEQ_FIRE_BAR_2                        = 0xB0000002,
    SOUND_SEQ_FIRE_BAR_3                        = 0xB0000003,
    SOUND_SEQ_FIRE_BAR_4                        = 0xB0000004,
    SOUND_SEQ_FIRE_BAR_5                        = 0xB0000005,
    SOUND_SEQ_FIRE_BAR_6                        = 0xB0000006,
    SOUND_SEQ_FIRE_BAR_7                        = 0xB0000007,
    SOUND_SEQ_FIRE_BAR_8                        = 0xB0000008,
    SOUND_SEQ_FIRE_BAR_9                        = 0xB0000009,
    SOUND_SEQ_FIRE_BAR_DEAD                     = 0xB000000A,
    SOUND_SEQ_AI_ALERT                          = 0xB000000B,
    SOUND_SEQ_SNORE_INHALE                      = 0xB000000C,
    SOUND_SEQ_SNORE_EXHALE                      = 0xB000000D,
    SOUND_SEQ_SNAP_AWAKE                        = 0xB000000E,
    SOUND_SEQ_BOO_VANISH                        = 0xB000000F,
    SOUND_SEQ_BOO_APPEAR                        = 0xB0000010,
    SOUND_SEQ_WINDOW_OPEN                       = 0xB0000011,
    SOUND_SEQ_WINDOW_CLOSE                      = 0xB0000012,
    SOUND_SEQ_RAVEN_LEAP                        = 0xB0000013,
    SOUND_SEQ_RAVEN_FALL                        = 0xB0000014,
    SOUND_SEQ_SHOOTING_STAR_FALL                = 0xB0000015,
    SOUND_SEQ_SHOOTING_STAR_BOUNCE              = 0xB0000016,
    SOUND_SEQ_FUZZY_HOP                         = 0xB0000017,
    SOUND_SEQ_BULLET_BILL_EXPLODE               = 0xB0000018,
    SOUND_SEQ_LUIGI_STEP                        = 0xB0000019,
    SOUND_SEQ_TRAIN_CHUG                        = 0xB000001A,
    SOUND_SEQ_FINALE_BRIDGE_COLLAPSE            = 0xB000001B,
    SOUND_SEQ_FINALE_EXPLOSION                  = 0xB000001C,
    SOUND_SEQ_SHUFFLE_CARD                      = 0xB000001D,
    SOUND_SEQ_STAR_SPIRIT_APPEAR                = 0xB000001E,
    SOUND_SEQ_STAR_SPIRIT_CAST                  = 0xB000001F,
    SOUND_SEQ_UNUSED_EXPLODE                    = 0xB0000020,
    SOUND_SEQ_SHY_GUY_STEP                      = 0xB0000021,
};

enum SoundSpatializationFlags {
    SOUND_SPACE_MODE_MASK           = 0x0000FFFF,
    SOUND_SPACE_DEFAULT             = 0x00000000,
    SOUND_SPACE_WITH_DEPTH          = 0x00000001,
    SOUND_SPACE_FULL                = 0x00000002,
    SOUND_SPACE_PARAMS_MASK         = 0xFFFF0000,
    SOUND_PARAM_MUTE                = 0x00010000,
    SOUND_PARAM_CLIP_OFFSCREEN_ANY  = 0x00020000,
    SOUND_PARAM_CLIP_OFFSCREEN_X    = 0x00040000,
    SOUND_PARAM_CLIP_OFFSCREEN_Y    = 0x00080000,
    SOUND_PARAM_MOST_QUIET          = 0x00100000,
    SOUND_PARAM_MORE_QUIET          = 0x00200000,
    SOUND_PARAM_QUIET               = 0x00400000,
};

enum SoundTriggers {
    SOUND_TRIGGER_CHANGE_SOUND  = 1,
    SOUND_TRIGGER_CHANGE_VOLUME = 2,
};

typedef enum AuResult {
    AU_RESULT_OK                        = 0,
    AU_ERROR_1                          = 1,
    AU_AMBIENCE_ERROR_1                 = 1,
    AU_ERROR_SONG_NOT_PLAYING           = 2, // player not found for songName
    AU_AMBIENCE_ERROR_2                 = 2,
    AU_ERROR_NULL_SONG_NAME             = 3, // songName is NULL
    AU_AMBIENCE_ERROR_3                 = 3,
    AU_ERROR_INVALID_SONG_DURATION      = 4, // duration out of bounds: (250,10000)
    AU_ERROR_6                          = 6,
    AU_ERROR_7                          = 7,
    AU_ERROR_11                         = 11,
    AU_ERROR_SBN_INDEX_OUT_OF_RANGE     = 101,
    AU_ERROR_SBN_FORMAT_MISMATCH        = 102,
    AU_ERROR_151                        = 151,
    AU_ERROR_201                        = 201
} AuResult;

typedef enum AuFileFormat {
    AU_FMT_BGM              = 0x10,
    AU_FMT_SEF              = 0x20,
    AU_FMT_BK               = 0x30,
    AU_FMT_PER              = 0x40,
    AU_FMT_PRG              = 0x40,
    AU_FMT_MSEQ             = 0x40
} AuFileFormat;

enum {
    MUSIC_PROXIMITY_FAR,
    MUSIC_PROXIMITY_NEAR,
    MUSIC_PROXIMITY_FULL
};

typedef enum MusicTrackVols {
    TRACK_VOLS_0            = 0,
    TRACK_VOLS_1            = 1,
    TRACK_VOLS_2            = 2,
    TRACK_VOLS_3            = 3,
    TRACK_VOLS_KPA_OUTSIDE  = 4,
    TRACK_VOLS_KPA_1        = 5,
    TRACK_VOLS_KPA_2        = 6,
    TRACK_VOLS_KPA_3        = 7
} MusicTrackVols;

enum Cams {
    CAM_DEFAULT      = 0,
    CAM_BATTLE       = 1,
    CAM_TATTLE       = 2,
    CAM_3            = 3,
};

enum CamShakeModes {
    CAM_SHAKE_CONSTANT_VERTICAL     = 0,
    CAM_SHAKE_ANGULAR_HORIZONTAL    = 1,
    CAM_SHAKE_DECAYING_VERTICAL     = 2
};

// for use with SetBattleCamParam
enum AuxCameraParams {
    AUX_CAM_PARAM_1             = 1,
    AUX_CAM_BOOM_LENGTH         = 2,
    AUX_CAM_PARAM_3             = 3,
    AUX_CAM_BOOM_PITCH          = 4,
    AUX_CAM_BOOM_YAW            = 5,
    AUX_CAM_BOOM_ZOFFSET        = 6,
    AUX_CAM_PARAM_7             = 7,
    AUX_CAM_ZOOM_PERCENT        = 8
};

#include "item_enum.h"

// used for chest and give item events
enum GotItemType {
    ITEM_TYPE_CONSUMABLE    = 0,
    ITEM_TYPE_KEY           = 1,
    ITEM_TYPE_BADGE         = 2,
    ITEM_TYPE_STAR_PIECE    = 3,
};

enum ItemTypeFlags {
    ITEM_TYPE_FLAG_WORLD_USABLE         = 0x0001,
    ITEM_TYPE_FLAG_BATTLE_USABLE        = 0x0002,
    ITEM_TYPE_FLAG_CONSUMABLE           = 0x0004,
    ITEM_TYPE_FLAG_KEY                  = 0x0008,
    ITEM_TYPE_FLAG_GEAR                 = 0x0020,
    ITEM_TYPE_FLAG_BADGE                = 0x0040,
    ITEM_TYPE_FLAG_FOOD_OR_DRINK        = 0x0080,
    ITEM_TYPE_FLAG_USE_DRINK_ANIMATION  = 0x0100,
    ITEM_TYPE_FLAG_ENTITY_COLLECTABLE   = 0x0200,
    ITEM_TYPE_FLAG_ENTITY_FULLSIZE      = 0x1000,
};

// both items and moves use these flags to determine what type of targets are eligible
// they are used during the construction of target lists and during the select target battle state
enum TargetFlags {
    TARGET_FLAG_SELECT_ONE              = 0x00000001, // player selects a single target
    TARGET_FLAG_2                       = 0x00000002,
    TARGET_FLAG_GROUND                  = 0x00000004, // only allow targets on the ground (row = 0)
    TARGET_FLAG_PLAYER                  = 0x00000008, // allow the player as a target, prevents enemies from being targets
    TARGET_FLAG_NOT_HIGH                = 0x00000010, // only allow targets in the first two rows (no moves use this)
    TARGET_FLAG_NOT_FLYING              = 0x00000020, // reject targets which have ACTOR_FLAG_FLYING
    TARGET_FLAG_NOT_GROUND              = 0x00000040, // reject targets on the ground (row = 0)
    TARGET_FLAG_80                      = 0x00000080, // jump, headbonk, belly flop (not read)
    TARGET_FLAG_PARTNER                 = 0x00000100, // allow the partner as a target, prevents enemies from being targets
    TARGET_FLAG_AIRLIFT                 = 0x00000400, // special case for air lift, only rejects targets on the ceiling
    TARGET_FLAG_JUMP_LIKE               = 0x00000800, // jump, headbonk, belly flop, ... and jump charge
    TARGET_FLAG_SMASH_LIKE              = 0x00001000, // smash moves
    TARGET_FLAG_NOT_BEHIND              = 0x00002000, // hammer, bombette body slam, kooper shell toss
    TARGET_FLAG_NOT_BELOW               = 0x00004000, // reject all targets below other targets
    TARGET_FLAG_PRIMARY_ONLY            = 0x00008000, // rejects all targets without ACTOR_PART_FLAG_PRIMARY_TARGET
    TARGET_FLAG_ALLOW_TARGET_ONLY       = 0x00010000, // allow targets which have ACTOR_FLAG_TARGET_ONLY
    TARGET_FLAG_TATTLE                  = 0x00020000, // special case for tattle, only rejects targets with ACTOR_FLAG_NO_TATTLE
    TARGET_FLAG_NO_CEILING              = 0x00040000, // rejects targets on the ceiling (those with ACTOR_FLAG_UPSIDE_DOWN)
    TARGET_FLAG_DIR_RIGHT               = 0x00100000, // directional filter used with CountTargets (bugged, unused)
    TARGET_FLAG_DIR_LEFT                = 0x00200000, // directional filter used with CountTargets (bugged, unused)
    TARGET_FLAG_DIR_BELOW               = 0x00400000, // directional filter used with CountTargets (bugged, unused)
    TARGET_FLAG_DIR_ABOVE               = 0x00800000, // directional filter used with CountTargets (bugged, unused)
    TARGET_FLAG_OVERRIDE                = 0x80000000, // skip choosing a target
};

enum ActorPartTargetFlags {
    ACTOR_PART_TARGET_NO_JUMP           = 0x01, // prevent any jump attacks from targeting
    ACTOR_PART_TARGET_NO_SMASH          = 0x02, // prevent any smash attacks from targeting
    ACTOR_PART_TARGET_NO_DAMAGE         = 0x04, // exempts from damage or status infliction
};

enum AmbientSounds {
    AMBIENT_SPOOKY          = 0,
    AMBIENT_WIND            = 1,
    AMBIENT_BEACH           = 2,
    AMBIENT_JUNGLE          = 3,
    AMBIENT_LAVA_1          = 4,
    AMBIENT_LAVA_2          = 5,
    AMBIENT_SILENCE         = 6,
    AMBIENT_LAVA_3          = 7,
    AMBIENT_LAVA_4          = 8,
    AMBIENT_LAVA_5          = 9,
    AMBIENT_LAVA_6          = 10,
    AMBIENT_LAVA_7          = 11,
    AMBIENT_BIRDS           = 12,
    AMBIENT_SEA             = 13,
    AMBIENT_RADIO           = 16, // radio songs for nok
    // the following 4 IDs are reserved for additional radio songs,
    // and no more are expected to follow after that
    // see: au_ambient_load
};

enum EncounterOutcomes {
    OUTCOME_PLAYER_WON          = 0,
    OUTCOME_PLAYER_LOST         = 1,
    OUTCOME_PLAYER_FLED         = 2,
    OUTCOME_ENEMY_FLED          = 3,
    OUTCOME_4                   = 4,
};

enum MerleeSpellType {
    MERLEE_SPELL_NONE           = 0,
    MERLEE_SPELL_ATK_BOOST      = 1,
    MERLEE_SPELL_DEF_BOOST      = 2,
    MERLEE_SPELL_EXP_BOOST      = 3,
    MERLEE_SPELL_COIN_BOOST     = 4,
};

enum NpcDecorationIDs {
    NPC_DECORATION_NONE                          = 0x00000000,
    NPC_DECORATION_BOWSER_AURA                   = 0x00000001,
    NPC_DECORATION_SWEAT                         = 0x00000002,
    NPC_DECORATION_SEEING_STARS                  = 0x00000003,
    NPC_DECORATION_WHITE_GLOW_FRONT              = 0x00000004,
    NPC_DECORATION_WHITE_GLOW_BEHIND             = 0x00000005,
    NPC_DECORATION_CHARGED                       = 0x00000006,
};

enum NpcPaletteAdjustments {
    NPC_PAL_ADJUST_NONE                             = 0,
    NPC_PAL_ADJUST_WATT_IDLE                        = 1,
    NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS = 2,
    NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS = 3,
    NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES            = 4,
};

enum SpeechFlags {
    SPEECH_FLAG_10              = 0x010,
    SPEECH_FLAG_HAS_OFFSET      = 0x100,
    SPEECH_FLAG_200             = 0x200,
    // different facing orientations for speaker and listener
    SPEECH_ORIENTATION_MASK     = 0xF,
    SPEECH_FACE_SPEAKER_ONLY    = 4,
    SPEECH_FACE_AWAY_FROM       = 3,
    SPEECH_FACE_LIKE_SPEAKER    = 2,
    SPEECH_FACE_LIKE_LISTENER   = 1,
    SPEECH_FACE_EACH_OTHER      = 0,
};

typedef enum HitResult {
    HIT_RESULT_BACKFIRE             = -1,
    HIT_RESULT_HIT                  = 0,
    HIT_RESULT_NICE                 = 1,
    HIT_RESULT_NO_DAMAGE            = 2,
    HIT_RESULT_NICE_NO_DAMAGE       = 3,
    HIT_RESULT_LANDED_ON_SPIKE      = 4,
    HIT_RESULT_LUCKY                = 5,
    HIT_RESULT_MISS                 = 6,
    HIT_RESULT_HIT_STATIC           = 7,
    HIT_RESULT_IMMUNE               = 8,
    HIT_RESULT_10                   = 10,
} HitResult;

typedef enum ActionResult {
    ACTION_RESULT_NONE      = 127,
    ACTION_RESULT_MINUS_4   = -4,
    ACTION_RESULT_MINUS_2   = -2,
    ACTION_RESULT_EARLY     = -1,
    ACTION_RESULT_FAIL      = 0,
    ACTION_RESULT_SUCCESS   = 1,
} ActionResult;

typedef enum BlockResult {
    BLOCK_RESULT_NONE       = 127,
    BLOCK_RESULT_EARLY      = -1,
    BLOCK_RESULT_FAIL       = 0,
    BLOCK_RESULT_SUCCESS    = 1,
} BlockResult;

enum ActionRatings {
    ACTION_RATING_NICE              = 0, ///< sets nice hits = 1
    ACTION_RATING_MISS              = 1, ///< clears nice hits
    ACTION_RATING_LUCKY             = 2, ///< clears nice hits
    ACTION_RATING_SUPER             = 3, ///< sets nice hits = 2
    ACTION_RATING_NICE_NO_COMBO     = 4, ///< clears nice hits
    ACTION_RATING_NICE_SUPER_COMBO  = 5  ///< 'Nice' but becomes 'Super' if nice hits > 2
};

enum DamageSources {
    DMG_SRC_DEFAULT                 = 0,
    DMG_SRC_LEECH                   = 1,    // used by Baby Blooper, but not Fuzzy
    DMG_SRC_SPIN_SMASH              = 2,
    DMG_SRC_D_DOWN_POUND            = 3,
    DMG_SRC_D_DOWN_JUMP             = 4,
    DMG_SRC_TUTORIAL_GOOMBARIO      = 5,
    DMG_SRC_SHELL_TOSS              = 6,
    DMG_SRC_POWER_SHELL             = 7,
    DMG_SRC_DIZZY_SHELL             = 8,
    DMG_SRC_FIRE_SHELL              = 9,
    DMG_SRC_NEXT_SLAP_LEFT          = 10,
    DMG_SRC_NEXT_SLAP_RIGHT         = 11,
    DMG_SRC_LAST_SLAP_LEFT          = 12,
    DMG_SRC_LAST_SLAP_RIGHT         = 13,
    DMG_SRC_NEXT_FAN_SMACK_LEFT     = 14,
    DMG_SRC_NEXT_FAN_SMACK_RIGHT    = 15,
    DMG_SRC_LAST_FAN_SMACK_LEFT     = 16,
    DMG_SRC_LAST_FAN_SMACK_RIGHT    = 17,
    DMG_SRC_SPOOK                   = 18,
    DMG_SRC_ELECTRO_DASH            = 19,
    DMG_SRC_HURRICANE               = 20,
    DMG_SRC_FRIGHT_JAR              = 21,
    DMG_SRC_POW_BLOCK               = 22,
    DMG_SRC_TUBBA_SMASH             = 23,
    DMG_SRC_CRUSH                   = 24,
    DMG_SRC_CRUSH_PARTNER           = 25,
    DMG_SRC_INK_BLAST               = 26,
};

enum PartnerRank {
    PARTNER_RANK_NORMAL = 0,
    PARTNER_RANK_SUPER  = 1,
    PARTNER_RANK_ULTRA  = 2,
};

enum Iters {
    ITER_FIRST       = -1,
    ITER_NEXT        = 0,
    ITER_PREV        = 1,
    ITER_LAST        = 10,
    // return values
    ITER_HAS_MORE    = 0,
    ITER_NO_MORE     = -1,
};

enum ActorSoundIDs {
    ACTOR_SOUND_WALK                      = 0x00000000,
    ACTOR_SOUND_FLY                       = 0x00000001,
    ACTOR_SOUND_JUMP                      = 0x00000002,
    ACTOR_SOUND_HURT                      = 0x00000003,
    ACTOR_SOUND_WALK_INCREMENT            = 0x00000004,
    ACTOR_SOUND_FLY_INCREMENT             = 0x00000005,
};

enum ActorDecorationIDs {
    ACTOR_DECORATION_NONE                   = 0x00000000,
    ACTOR_DECORATION_GOLDEN_FLAMES          = 0x00000001,
    ACTOR_DECORATION_SWEAT                  = 0x00000002,
    ACTOR_DECORATION_SEEING_STARS           = 0x00000003,
    ACTOR_DECORATION_RED_FLAMES             = 0x00000004,
    ACTOR_DECORATION_GREY_SMOKE_TRAIL       = 0x00000005,
    ACTOR_DECORATION_FIRE_SMOKE_TRAIL       = 0x00000006,
    ACTOR_DECORATION_WHIRLWIND              = 0x00000007,
    ACTOR_DECORATION_STEAM_EMITTER          = 0x00000008,
    ACTOR_DECORATION_SPARKLES               = 0x00000009,
    ACTOR_DECORATION_BOWSER_AURA            = 0x0000000A,
    ACTOR_DECORATION_RADIAL_STAR_EMITTER    = 0x0000000B,
};

enum Phases {
    PHASE_EXECUTE_ACTION            = 0,
    PHASE_FIRST_STRIKE              = 1,
    PHASE_RUN_AWAY_START            = 3,
    PHASE_DEATH                     = 4,
    PHASE_CELEBRATE                 = 5,
    PHASE_USE_DEFEND                = 6,
    PHASE_RUN_AWAY_FAIL             = 7,
    PHASE_USE_LIFE_SHROOM           = 8,
    PHASE_PLAYER_BEGIN              = 10,
    PHASE_ENEMY_END                 = 11,
    PHASE_ENEMY_BEGIN               = 12,
    PHASE_PLAYER_END                = 13,
    PHASE_MERLEE_ATTACK_BONUS       = 20,
    PHASE_MERLEE_DEFENSE_BONUS      = 21,
    PHASE_MERLEE_EXP_BONUS          = 22,
    PHASE_PLAYER_HAPPY              = 30,
};

enum ActorClasses {
    ACTOR_CLASS_PLAYER      = 0x000,
    ACTOR_CLASS_PARTNER     = 0x100,
    ACTOR_CLASS_ENEMY       = 0x200,
    ACTOR_CLASS_MASK        = 0x700,
};

enum ActorIDs {
    ACTOR_SELF           = 0xFFFFFF81,
    ACTOR_PLAYER         = 0x00000000,
    ACTOR_PARTNER        = 0x00000100,
    ACTOR_ENEMY0         = 0x00000200,
    ACTOR_ENEMY1         = 0x00000201,
    ACTOR_ENEMY2         = 0x00000202,
    ACTOR_ENEMY3         = 0x00000203,
    ACTOR_ENEMY4         = 0x00000204,
    ACTOR_ENEMY5         = 0x00000205,
    ACTOR_ENEMY6         = 0x00000206,
    ACTOR_ENEMY7         = 0x00000207,
    ACTOR_ENEMY8         = 0x00000208,
    ACTOR_ENEMY9         = 0x00000209,
    ACTOR_ENEMY10        = 0x0000020A,
    ACTOR_ENEMY11        = 0x0000020B,
    ACTOR_ENEMY12        = 0x0000020C,
    ACTOR_ENEMY13        = 0x0000020D,
    ACTOR_ENEMY14        = 0x0000020E,
    ACTOR_ENEMY15        = 0x0000020F,
    ACTOR_ENEMY16        = 0x00000210,
    ACTOR_ENEMY17        = 0x00000211,
    ACTOR_ENEMY18        = 0x00000212,
    ACTOR_ENEMY19        = 0x00000213,
    ACTOR_ENEMY20        = 0x00000214,
    ACTOR_ENEMY21        = 0x00000215,
    ACTOR_ENEMY22        = 0x00000216,
    ACTOR_ENEMY23        = 0x00000217,
};

enum Elements {
    ELEMENT_END              = 0x00000000,
    ELEMENT_NORMAL           = 0x00000001,
    ELEMENT_FIRE             = 0x00000002,
    ELEMENT_WATER            = 0x00000003,
    ELEMENT_ICE              = 0x00000004,
    ELEMENT_MYSTERY          = 0x00000005,
    ELEMENT_MAGIC            = 0x00000007,
    ELEMENT_SMASH            = 0x00000008,
    ELEMENT_JUMP             = 0x00000009,
    ELEMENT_COSMIC           = 0x0000000A,
    ELEMENT_BLAST            = 0x0000000B,
    ELEMENT_SHOCK            = 0x0000000C,
    ELEMENT_QUAKE            = 0x0000000D,
    ELEMENT_THROW            = 0x0000000F,
};

enum Events {
    EVENT_HIT_COMBO                   = 0x00000009,
    EVENT_HIT                         = 0x0000000A,
    EVENT_SPIN_SMASH_HIT              = 0x0000000B,
    EVENT_FALL_TRIGGER                = 0x0000000C,
    EVENT_FLIP_TRIGGER                = 0x0000000D,
    EVENT_BURN_HIT                    = 0x0000000E,
    EVENT_15                          = 0x0000000F, // FLAME_HIT?
    EVENT_SPIN_SMASH_LAUNCH_HIT       = 0x00000011,
    EVENT_SHELL_CRACK_HIT             = 0x00000012,
    EVENT_STAR_BEAM                   = 0x00000013,
    EVENT_PEACH_BEAM                  = 0x00000014,
    EVENT_POWER_BOUNCE_HIT            = 0x00000015,
    EVENT_BLOW_AWAY                   = 0x00000016,
    EVENT_ZERO_DAMAGE                 = 0x00000017,
    EVENT_18                          = 0x00000018,
    EVENT_IMMUNE                      = 0x00000019,
    EVENT_BLOCK                       = 0x0000001A,
    EVENT_SPIKE_TAUNT                 = 0x0000001B,
    EVENT_BURN_TAUNT                  = 0x0000001C,
    EVENT_INVUNERABLE_TAUNT           = 0x0000001D,
    EVENT_1E                          = 0x0000001E,
    EVENT_AIR_LIFT_FAILED             = 0x0000001F,
    EVENT_DEATH                       = 0x00000020,
    EVENT_SPIN_SMASH_DEATH            = 0x00000021,
    EVENT_EXPLODE_TRIGGER             = 0x00000022,
    EVENT_23                          = 0x00000023,
    EVENT_BURN_DEATH                  = 0x00000024,
    EVENT_SPIN_SMASH_LAUNCH_DEATH     = 0x00000025,
    EVENT_SHOCK_DEATH                 = 0x00000026,
    EVENT_SPIKE_DEATH                 = 0x00000027,
    EVENT_POWER_BOUNCE_DEATH          = 0x00000028,
    EVENT_FIRE_DEATH                  = 0x00000029, // burn death copy?
    EVENT_SPIKE_CONTACT               = 0x0000002A,
    EVENT_BURN_CONTACT                = 0x0000002C,
    EVENT_SHOCK_HIT                   = 0x0000002F,
    EVENT_30                          = 0x00000030,
    EVENT_RECOVER_STATUS              = 0x00000031,
    EVENT_32                          = 0x00000032,
    EVENT_33                          = 0x00000033,
    EVENT_RECOVER_FROM_KO             = 0x00000034,
    EVENT_END_FIRST_STRIKE            = 0x00000035,
    EVENT_LUCKY                       = 0x00000037,
    EVENT_BEGIN_FIRST_STRIKE          = 0x00000038,
    EVENT_SCARE_AWAY                  = 0x00000039,
    EVENT_BEGIN_AIR_LIFT              = 0x0000003A,
    EVENT_UP_AND_AWAY                 = 0x0000003D,
    EVENT_PUT_PARTNER_AWAY            = 0x0000003E,
    EVENT_RECEIVE_BUFF                = 0x0000003F,
    EVENT_LIFE_SHROOM_PROC            = 0x00000040,
    EVENT_REVIVE                      = 0x00000041,
    EVENT_66                          = 0x00000042,
};

enum HitSounds {
    HIT_SOUND_MISS             = 0,
    HIT_SOUND_BONES            = 1,
    HIT_SOUND_NORMAL           = 2,
    HIT_SOUND_FIRE             = 3,
    HIT_SOUND_ICE              = 4,
    HIT_SOUND_SHOCK            = 5,
};

// Player.debuff
// Partner.debuff
enum StatusKeys {
    STATUS_END                      = 0x00000000,
    STATUS_KEY_NORMAL               = 0x00000001,
    STATUS_KEY_DEFAULT              = 0x00000002,
    STATUS_KEY_FEAR                 = 0x00000003,
    STATUS_KEY_DIZZY                = 0x00000004,
    STATUS_KEY_PARALYZE             = 0x00000005,
    STATUS_KEY_SLEEP                = 0x00000006,
    STATUS_KEY_FROZEN               = 0x00000007,
    STATUS_KEY_STOP                 = 0x00000008,
    STATUS_KEY_POISON               = 0x00000009,
    STATUS_KEY_SHRINK               = 0x0000000A,
    STATUS_KEY_STATIC               = 0x0000000B,
    STATUS_KEY_STONE                = 0x0000000C,
    STATUS_KEY_DAZE                 = 0x0000000D,
    STATUS_KEY_TRANSPARENT          = 0x0000000E,
    STATUS_KEY_KO                   = 0x0000000F,
    STATUS_KEY_BERSERK              = 0x00000010,
    STATUS_KEY_11                   = 0x00000011,
    STATUS_KEY_INACTIVE             = 0x00000012,
    STATUS_KEY_INACTIVE_BERSERK     = 0x00000013,
    STATUS_KEY_14                   = 0x00000014, // probably STATUS_KEY_INACTIVE_FROZEN
    STATUS_KEY_INACTIVE_SLEEP       = 0x00000015,
    STATUS_KEY_INACTIVE_WEARY       = 0x00000016,
    STATUS_KEY_17                   = 0x00000017,
    STATUS_KEY_INACTIVE_DIZZY       = 0x00000018,
    STATUS_KEY_HUSTLE               = 0x00000019,
    STATUS_KEY_DANGER               = 0x0000001A,
    STATUS_KEY_1B                   = 0x0000001B,
    STATUS_KEY_THINKING             = 0x0000001C,
    STATUS_KEY_WEARY                = 0x0000001D,
    STATUS_KEY_1E                   = 0x0000001E,
    STATUS_TURN_MOD_DEFAULT         = 0x0000001F,
    STATUS_TURN_MOD_SLEEP           = 0x00000020,
    STATUS_TURN_MOD_STATIC          = 0x00000021,
    STATUS_TURN_MOD_FROZEN          = 0x00000022,
    STATUS_TURN_MOD_FEAR            = 0x00000023,
    STATUS_TURN_MOD_DIZZY           = 0x00000024,
    STATUS_TURN_MOD_POISON          = 0x00000025,
    STATUS_TURN_MOD_PARALYZE        = 0x00000026,
    STATUS_TURN_MOD_SHRINK          = 0x00000027,
    STATUS_TURN_MOD_STONE           = 0x00000028,
    STATUS_TURN_MOD_STOP            = 0x00000029,
};

enum ActorPaletteAdjustments {
    ACTOR_PAL_ADJUST_NONE             = 0,
    ACTOR_PAL_ADJUST_SLEEP            = 3,
    ACTOR_PAL_ADJUST_STATIC           = 4,
    ACTOR_PAL_ADJUST_FEAR             = 5,  // darker
    ACTOR_PAL_ADJUST_POISON           = 6,
    ACTOR_PAL_ADJUST_PARALYZE         = 7,
    ACTOR_PAL_ADJUST_BERSERK          = 8,
    ACTOR_PAL_ADJUST_WATT_IDLE        = 9,
    ACTOR_PAL_ADJUST_WATT_ATTACK      = 10,
    ACTOR_PAL_ADJUST_PLAYER_DEBUFF    = 12,
    ACTOR_PAL_ADJUST_PLAYER_POISON    = 13,
    ACTOR_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS = 14,
    ACTOR_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS = 15,
    ACTOR_PAL_ADJUST_BLEND_PALSETS    = 16,
};

enum GlowPaletteModes {
    GLOW_PAL_OFF    = 0,
    GLOW_PAL_ON     = 11,
};

enum ActorPartFlashState {
    FLASH_MODE_LIGHT    = 0,
    FLASH_MODE_MEDIUM    = 1,
    FLASH_MODE_HEAVY    = 2,
    FLASH_MODE_DISPOSE    = 3,
};

enum FlashPaletteModes {
    FLASH_PAL_OFF    = 0,
    FLASH_PAL_ON     = -1,
};

enum DoorSwing {
    DOOR_SWING_IN           = -1,
    DOOR_SWING_OUT          = 1,
};

enum VisibilityGroup {
    VIS_GROUP_0             = 0,
    VIS_GROUP_1             = 1,
    VIS_GROUP_2             = 2,
    VIS_GROUP_3             = 3,
    VIS_GROUP_4             = 4,
    VIS_GROUP_5             = 5,
    VIS_GROUP_6             = 6,
    VIS_GROUP_7             = 7,
};

enum ItemSpawnModes {
    ITEM_SPAWN_MODE_KEY                                          = 0x00000000,
    ITEM_SPAWN_MODE_DECORATION                                   = 0x00000001,
    ITEM_SPAWN_MODE_INVISIBLE                                    = 0x00000002,
    ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS                            = 0x00000003,
    ITEM_SPAWN_MODE_BATTLE_REWARD                                = 0x00000004,
    ITEM_SPAWN_MODE_TOSS_NEVER_VANISH                            = 0x00000005,
    ITEM_SPAWN_MODE_TOSS                                         = 0x00000006,
    ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE                              = 0x00000007,
    ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE_NEVER_VANISH                 = 0x00000008,
    ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_NEVER_VANISH               = 0x00000009,
    ITEM_SPAWN_MODE_ITEM_BLOCK_ITEM                              = 0x0000000A,
    ITEM_SPAWN_MODE_ITEM_BLOCK_BADGE                             = 0x0000000B,
    ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS                            = 0x0000000C,
    ITEM_SPAWN_MODE_FALL_NEVER_VANISH                            = 0x0000000D,
    ITEM_SPAWN_MODE_FALL                                         = 0x0000000E,
    ITEM_SPAWN_MODE_FALL_SPAWN_ONCE                              = 0x0000000F,
    ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS                           = 0x00000010,
    ITEM_SPAWN_MODE_FIXED_NEVER_VANISH                           = 0x00000011,
    ITEM_SPAWN_MODE_FIXED                                        = 0x00000012,
    ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS_NEVER_VANISH              = 0x00000013,
    ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS                      = 0x00000014,
    ITEM_SPAWN_MODE_ITEM_BLOCK_COIN                              = 0x00000015,
    ITEM_SPAWN_MODE_TOSS_HIGHER_NEVER_VANISH                     = 0x00000016,
    ITEM_SPAWN_MODE_TOSS_FADE1                                   = 0x00000017,
    ITEM_SPAWN_MODE_TOSS_FADE2                                   = 0x00000018,
    ITEM_SPAWN_MODE_TOSS_FADE3                                   = 0x00000019,
    ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL                      = 0x0000001A,
    ITEM_SPAWN_MODE_UNKNOWN_1B                                   = 0x0000001B,
    ITEM_SPAWN_AT_PLAYER                                         = 0x0000001C,
};

enum Locations {
    LOCATION_TOAD_TOWN                  = 0x01,
    LOCATION_TOAD_TOWN_TUNNELS          = 0x02,
    LOCATION_KOOPA_BROS_FORTRESS        = 0x07,
    LOCATION_MT_RUGGED                  = 0x08,
    LOCATION_DRY_DRY_OUTPOST            = 0x09,
    LOCATION_DRY_DRY_DESERT             = 0x0A,
    LOCATION_DRY_DRY_RUINS              = 0x0B,
    LOCATION_FOREVER_FOREST             = 0x0C,
    LOCATION_BOOS_MANSION               = 0x0D,
    LOCATION_TUBBAS_MANOR               = 0x0F,
    LOCATION_SHY_GUYS_TOYBOX            = 0x10,
    LOCATION_MT_LAVALAVA                = 0x12,
    LOCATION_CRYSTAL_PALACE             = 0x15,
    LOCATION_BOWSERS_CASTLE             = 0x16,
    LOCATION_TESTING                    = 0x17,
    LOCATION_NONE                       = 0x18,
    LOCATION_PEACH_CASTLE_GROUNDS       = 0x19,
    LOCATION_PEACHS_CASTLE              = 0x1A,
    LOCATION_SHOOTING_STAR_SUMMIT       = 0x1B,
    LOCATION_STAR_WAY                   = 0x1C,
    LOCATION_STAR_HAVEN                 = 0x1D,
    LOCATION_GOOMBA_VILLAGE             = 0x1E,
    LOCATION_GOOMBA_ROAD                = 0x1F,
    LOCATION_PLEASANT_PATH              = 0x20,
    LOCATION_KOOPA_VILLAGE              = 0x21,
    LOCATION_GUSTY_GULCH                = 0x22,
    LOCATION_WINDY_MILL                 = 0x23,
    LOCATION_JADE_JUNGLE                = 0x24,
    LOCATION_YOSHIS_VILLAGE             = 0x25,
    LOCATION_FLOWER_FIELDS              = 0x26,
    LOCATION_CLOUDY_CLIMB               = 0x27,
    LOCATION_SHIVER_CITY                = 0x28,
    LOCATION_SHIVER_SNOWFIELD           = 0x29,
    LOCATION_STARBORN_VALLEY            = 0x2A,
    LOCATION_SHIVER_MOUNTAIN            = 0x2B,
    LOCATION_MARIOS_HOUSE               = 0x2C,
};

typedef enum ScreenTransition {
    TRANSITION_STANDARD                 = 0,    // fade to/from black
    TRANSITION_TOY_TRAIN                = 1,    // similar to TRANSITION_TOY_TRAIN, but fade applies to whole screen
    TRANSITION_END_DEMO_SCENE_BLACK     = 2,    // rapidly fade to black
    TRANSITION_END_DEMO_SCENE_WHITE     = 3,    // slow fade to white -> rapid fade in from white
    TRANSITION_BEGIN_OR_END_GAME        = 4,    // slow fade to/from black
    TRANSITION_OUTRO_END_SCENE          = 5,    // slow fade to/from black
    TRANSITION_BEGIN_OR_END_CHAPTER     = 6,    // white fade in/out; standard transition for entering kmr_22 (Begin Chapter) or leaving kmr_23 (End of Chapter)
    TRANSITION_SLOW_FADE_TO_WHITE       = 7,    // slow fade to/from white
    TRANSITION_ENTER_WORLD              = 8,    // black Mario stencil in/out
    TRANSITION_MARIO_WHITE              = 9,    // white Mario stencil -> white fade in; used in post ch5 scene, fading to Save and Continue? screen
    TRANSITION_MARIO_BLACK              = 10,   // black Mario stencil -> black fade in; used after Goombaria finds Mario and he wakes up in the inn
    TRANSITION_AFTER_SAVE_PROMPT        = 11,   // white fade out -> white star stencil
    TRANSITION_END_PEACH_INTERLUDE      = 12,   // white star stencil -> white Mario stencil
    TRANSITION_PEACH_CAPTURED           = 13,   // black star stencil -> black fade in
    TRANSITION_GET_STAR_CARD            = 14,   // used for entering kmr_23 (Get Star Card / End Chapter)
    TRANSITION_END_CHAPTER_INTERRUPTED  = 15,   // white fade out -> white Mario stencil; used in kzn_19 for Ch5
    TRANSITION_SLOW_BLUR_MOTION         = 16,   // unused?
} ScreenTransition;

enum ScreenLayer {
    SCREEN_LAYER_FRONT              = 0,
    SCREEN_LAYER_BACK               = 1,
};

typedef enum ScreenOverlayType {
    OVERLAY_NONE                    = -1,
    OVERLAY_SCREEN_COLOR            = 0,
    OVERLAY_VIEWPORT_COLOR          = 1,
    OVERLAY_TYPE_2                  = 2,
    OVERLAY_VIEWPORT_SPOTLIGHT      = 3,
    OVERLAY_VIEWPORT_MARIO          = 4,
    OVERLAY_VIEWPORT_STAR           = 5,
    OVERLAY_SCREEN_SPOTLIGHT        = 6,
    OVERLAY_SCREEN_MARIO            = 7,
    OVERLAY_SCREEN_STAR             = 8,
    OVERLAY_TYPE_9                  = 9,
    OVERLAY_START_BATTLE            = 10,
    OVERLAY_WORLD_DARKNESS          = 11,
    OVERLAY_BLUR                    = 12,
    OVERLAY_BATTLE_DARKNESS         = 13,
    OVERLAY_INTRO_1                 = 14,
    OVERLAY_INTRO_2                 = 15,
} ScreenOverlayType;

enum DoorSounds {
    DOOR_SOUNDS_BASIC               = 0,
    DOOR_SOUNDS_METAL               = 1,
    DOOR_SOUNDS_LARGE               = 2,
    DOOR_SOUNDS_CREAKY              = 3,
    DOOR_SOUNDS_GATE                = 4,
    DOOR_SOUNDS_DOOR                = 5,
    DOOR_SOUNDS_UNUSED              = 6,
};

#if VERSION_US || VERSION_PAL || VERSION_IQUE
#include "sprite/sprite_shading_profiles.h"
#endif

enum LightSourceFlags {
    LIGHT_SOURCE_DISABLED           = 0,
    LIGHT_SOURCE_ENABLED            = 1,
    LIGHT_SOURCE_LINEAR_FALLOFF     = 4,
    LIGHT_SOURCE_QUADRATIC_FALLOFF  = 8,
};

enum ActionStates {
    ACTION_STATE_IDLE                           = 0x00000000,
    ACTION_STATE_WALK                           = 0x00000001,
    ACTION_STATE_RUN                            = 0x00000002,
    // all states above are considered locomotion states
    ACTION_STATE_JUMP                           = 0x00000003,
    ACTION_STATE_BOUNCE                         = 0x00000004,  ///< Used with Kooper
    ACTION_STATE_HOP                            = 0x00000005,  ///< Released A before apex of jump
    ACTION_STATE_LAUNCH                         = 0x00000006,  ///< Shy Guy Toybox jack-in-the-boxes
    ACTION_STATE_LANDING_ON_SWITCH              = 0x00000007,  ///< Small red/blue ! switches
    ACTION_STATE_FALLING                        = 0x00000008,
    ACTION_STATE_STEP_DOWN                      = 0x00000009,
    ACTION_STATE_LAND                           = 0x0000000A,
    ACTION_STATE_STEP_DOWN_LAND                 = 0x0000000B,
    // Following action states prohibit movement (see set_action_state())
    ACTION_STATE_TALK                           = 0x0000000C,  ///< Reading signs doesn't count
    ACTION_STATE_SPIN_JUMP                      = 0x0000000D,
    ACTION_STATE_SPIN_POUND                     = 0x0000000E,
    ACTION_STATE_TORNADO_JUMP                   = 0x0000000F,
    ACTION_STATE_TORNADO_POUND                  = 0x00000010,
    ACTION_STATE_SLIDING                        = 0x00000011,
    ACTION_STATE_HAMMER                         = 0x00000012,
    ACTION_STATE_13                             = 0x00000013,
    ACTION_STATE_PUSHING_BLOCK                  = 0x00000014,
    ACTION_STATE_HIT_FIRE                       = 0x00000015,  ///< Causes Mario to fly up and take damage. Used for fire bars.
    ACTION_STATE_KNOCKBACK                      = 0x00000016,  // some kind of knockback, does no damage
    ACTION_STATE_HIT_LAVA                       = 0x00000017,
    ACTION_STATE_STEP_UP_PEACH                  = 0x00000018,
    ACTION_STATE_USE_SNEAKY_PARASOL             = 0x00000019,
    ACTION_STATE_SPIN                           = 0x0000001A,
    ACTION_STATE_ENEMY_FIRST_STRIKE             = 0x0000001B,
    ACTION_STATE_RAISE_ARMS                     = 0x0000001C,
    ACTION_STATE_USE_SPINNING_FLOWER            = 0x0000001D,
    ACTION_STATE_USE_MUNCHLESIA                 = 0x0000001E,  ///< Set by the jan_09 squishy flower entity; throws the player in the air.
    ACTION_STATE_USE_TWEESTER                   = 0x0000001F,
    ACTION_STATE_BOUNCE_OFF_SWITCH              = 0x00000020,  ///< Small red/blue ! switches
    ACTION_STATE_RIDE                           = 0x00000021,
    ACTION_STATE_STEP_UP                        = 0x00000022,
    ACTION_STATE_23                             = 0x00000023,
    ACTION_STATE_24                             = 0x00000024,
    ACTION_STATE_INVALID_25                     = 0x00000025,
    ACTION_STATE_USE_SPRING                     = 0x00000026,
};

enum JumpSubstate {
    JUMP_SUBSTATE_0                 = 0,
    JUMP_SUBSTATE_1                 = 1,
};

enum TweesterPartnerStates {
    TWEESTER_PARTNER_INIT       = 0,
    TWEESTER_PARTNER_ATTRACT    = 1,
    TWEESTER_PARTNER_HOLD       = 2,
    TWEESTER_PARTNER_RELEASE    = 3,
};

enum LandOnSwitchSubstate {
    LANDING_ON_SWITCH_SUBSTATE_0    = 0,
    LANDING_ON_SWITCH_SUBSTATE_1    = 1,
    LANDING_ON_SWITCH_SUBSTATE_2    = 2,
};

enum PeachFlags {
    PEACH_FLAG_IS_PEACH             = 0x01,
    PEACH_FLAG_DISGUISED            = 0x02,
    PEACH_FLAG_HAS_PARASOL          = 0x04,
    PEACH_FLAG_BLOCK_NEXT_DISGUISE  = 0x08, // next attempt to copy an NPC with parasol will fail
    PEACH_FLAG_DEPRESSED            = 0x10
};

enum PeachBakingItems {
    PEACH_BAKING_NONE                   = 0,
    PEACH_BAKING_CREAM                  = 1,
    PEACH_BAKING_STRAWBERRY             = 2,
    PEACH_BAKING_BUTTER                 = 3,
    PEACH_BAKING_CLEANSER               = 4,
    PEACH_BAKING_WATER                  = 5,
    PEACH_BAKING_MILK                   = 6,
    PEACH_BAKING_FLOUR                  = 7,
    PEACH_BAKING_EGG                    = 8,
    PEACH_BAKING_COMPLETE_CAKE          = 9,
    PEACH_BAKING_CAKE_BOWL              = 10,
    PEACH_BAKING_CAKE_MIXED             = 11,
    PEACH_BAKING_CAKE_PAN               = 12,
    PEACH_BAKING_CAKE_BATTER            = 13,
    PEACH_BAKING_CAKE_BARE              = 14,
    PEACH_BAKING_SALT                   = 15,
    PEACH_BAKING_SUGAR                  = 16,
    PEACH_BAKING_CAKE_WITH_ICING        = 17,
    PEACH_BAKING_CAKE_WITH_BERRIES      = 18,
};

enum PeachDisguises {
    PEACH_DISGUISE_NONE                 = 0,
    PEACH_DISGUISE_KOOPATROL            = 1,
    PEACH_DISGUISE_HAMMER_BROS          = 2,
    PEACH_DISGUISE_CLUBBA               = 3,
};

// Requires decimals
enum NpcIDs {
    NPC_SELF            = -1,
    NPC_PLAYER          = -2,
    NPC_PARTNER         = -4,
    NPC_BTL_MERLEE      = -10,
    NPC_BTL_COMPANION   = 0, // used for Peach in intro Bowser fight and Kolorado in Lava Piranha fight
    NPC_BTL_SPIRIT      = 100,
};

enum ShadowType {
    SHADOW_VARYING_CIRCLE       = 0,
    SHADOW_VARYING_SQUARE       = 1,
    SHADOW_FIXED_CIRCLE         = 2,
    SHADOW_FIXED_SQUARE         = 3,
    SHADOW_VARYING_ALT_CIRCLE   = 4, // unused?
    SHADOW_FIXED_ALT_CIRCLE     = 5, // unused?
};

enum EntityTypes {
    ENTITY_TYPE_SHADOW                  =   0x01,
    ENTITY_TYPE_2                       =   0x02,
    ENTITY_TYPE_PADLOCK                 =   0x03,
    ENTITY_TYPE_PADLOCK_RED_FRAME       =   0x04,
    ENTITY_TYPE_PADLOCK_RED_FACE        =   0x05,
    ENTITY_TYPE_PADLOCK_BLUE_FACE       =   0x06,
    ENTITY_TYPE_BLUE_SWITCH             =   0x07,
    ENTITY_TYPE_RED_SWITCH              =   0x08,
    ENTITY_TYPE_HUGE_BLUE_SWITCH        =   0x09,
    ENTITY_TYPE_GREEN_STOMP_SWITCH      =   0x0A,
    ENTITY_TYPE_MULTI_TRIGGER_BLOCK     =   0x0B,
    ENTITY_TYPE_PUSH_BLOCK              =   0x0C,
    ENTITY_TYPE_BRICK_BLOCK             =   0x0D,
    ENTITY_TYPE_MULTI_COIN_BRICK        =   0x0E,
    ENTITY_TYPE_YELLOW_BLOCK            =   0x0F,
    ENTITY_TYPE_SINGLE_TRIGGER_BLOCK    =   0x10,
    ENTITY_TYPE_HIDDEN_YELLOW_BLOCK     =   0x11,
    ENTITY_TYPE_HIDDEN_RED_BLOCK        =   0x12,
    ENTITY_TYPE_INACTIVE_BLOCK          =   0x13,
    ENTITY_TYPE_RED_BLOCK               =   0x14,
    ENTITY_TYPE_HAMMER1_BLOCK           =   0x15,
    ENTITY_TYPE_HAMMER2_BLOCK           =   0x16,
    ENTITY_TYPE_HAMMER3_BLOCK           =   0x17,
    ENTITY_TYPE_HAMMER1_BLOCK_TINY      =   0x18,
    ENTITY_TYPE_HAMMER2_BLOCK_TINY      =   0x19,
    ENTITY_TYPE_HAMMER3_BLOCK_TINY      =   0x1A,
    ENTITY_TYPE_HEALING_BLOCK           =   0x1B,
    ENTITY_TYPE_1C                      =   0x1C,
    ENTITY_TYPE_1D                      =   0x1D,
    ENTITY_TYPE_1E                      =   0x1E,
    ENTITY_TYPE_HEALING_BLOCK_FRAME     =   0x1F,
    ENTITY_TYPE_SAVE_POINT              =   0x20,
    ENTITY_TYPE_POW_BLOCK               =   0x21,
    ENTITY_TYPE_SUPER_BLOCK             =   0x22,
    ENTITY_TYPE_ULTRA_BLOCK             =   0x23,
    ENTITY_TYPE_WOODEN_CRATE            =   0x24,
    ENTITY_TYPE_BOARDED_FLOOR           =   0x25,
    ENTITY_TYPE_BOMBABLE_ROCK           =   0x26,
    ENTITY_TYPE_BLUE_WARP_PIPE          =   0x2B,
    ENTITY_TYPE_SIMPLE_SPRING           =   0x2E,
    ENTITY_TYPE_SCRIPT_SPRING           =   0x2F,
    ENTITY_TYPE_HIDDEN_PANEL            =   0x30,
    ENTITY_TYPE_STAR_BOX_LAUNCHER       =   0x31,
    ENTITY_TYPE_CHEST                   =   0x32,
    ENTITY_TYPE_SIGNPOST                =   0x33,
    ENTITY_TYPE_RED_ARROW_SIGNS         =   0x34,
    ENTITY_TYPE_BELLBELL_PLANT          =   0x35,
    ENTITY_TYPE_TRUMPET_PLANT           =   0x36,
    ENTITY_TYPE_MUNCHLESIA              =   0x37,
    ENTITY_TYPE_CYMBAL_PLANT            =   0x38,
    ENTITY_TYPE_PINK_FLOWER             =   0x39,
    ENTITY_TYPE_SPINNING_FLOWER         =   0x3A,
    ENTITY_TYPE_3B                      =   0x3B,
    ENTITY_TYPE_TWEESTER                =   0x3C,
    ENTITY_TYPE_HEALING_BLOCK_CONTENT   =   0x3F,
    ENTITY_TYPE_SUPER_BLOCK_HIT_EFFECT  =   0x41,
    ENTITY_TYPE_ULTRA_BLOCK_HIT_EFFECT  =   0x42,
    ENTITY_TYPE_RESET_MUNCHLESIA        =   0x43,
    ENTITY_TYPE_MUNCHLESIA_GRAB         =   0x44,
    ENTITY_TYPE_MUNCHLESIA_ENVELOP      =   0x45,
    ENTITY_TYPE_MUNCHLESIA_BEGIN_CHEW   =   0x46,
    ENTITY_TYPE_MUNCHLESIA_CHEWING      =   0x47,
    ENTITY_TYPE_MUNCHLESIA_SPIT_OUT     =   0x48,
    ENTITY_TYPE_MUNCHLESIA_RESET1       =   0x49,
    ENTITY_TYPE_MUNCHLESIA_RESET2       =   0x4A
};

// Entity
enum EntityFlags {
    ENTITY_FLAG_HIDDEN                                      = 0x00000001,
    ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE1                    = 0x00000002,
    ENTITY_FLAG_HAS_DYNAMIC_SHADOW                          = 0x00000004,
    ENTITY_FLAG_HAS_ANIMATED_MODEL                          = 0x00000008,
    ENTITY_FLAG_SKIP_UPDATE_TRANSFORM_MATRIX                = 0x00000010,
    ENTITY_FLAG_DISABLE_COLLISION                           = 0x00000020,
    ENTITY_FLAG_CONTINUOUS_COLLISION                        = 0x00000040,
    ENTITY_FLAG_80                                          = 0x00000080,
    ENTITY_FLAG_HAS_SHADOW                                  = 0x00000100,
    ENTITY_FLAG_FIXED_SHADOW_SIZE                           = 0x00000200,
    ENTITY_FLAG_400                                         = 0x00000400,
    ENTITY_FLAG_CIRCULAR_SHADOW                             = 0x00000800,
    ENTITY_FLAG_SHOWS_INSPECT_PROMPT                        = 0x00001000,
    ENTITY_FLAG_ALWAYS_FACE_CAMERA                          = 0x00002000,
    ENTITY_FLAG_4000                                        = 0x00004000,
    ENTITY_FLAG_8000                                        = 0x00008000,
    ENTITY_FLAG_DETECTED_COLLISION                          = 0x00010000,
    ENTITY_FLAG_PARTNER_COLLISION                           = 0x00020000,
    ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE2                    = 0x00040000,
    ENTITY_FLAG_IGNORE_DISTANCE_CULLING                     = 0x00080000,
    ENTITY_FLAG_100000                                      = 0x00100000,
    ENTITY_FLAG_200000                                      = 0x00200000,
    ENTITY_FLAG_SHADOW_POS_DIRTY                            = 0x00400000,
    ENTITY_FLAG_DARK_SHADOW                                 = 0x00800000,
    ENTITY_FLAG_BOUND_SCRIPT_DIRTY                          = 0x01000000,
    ENTITY_FLAG_2000000                                     = 0x02000000,
    ENTITY_FLAG_PENDING_FULL_DELETE                         = 0x04000000,
    ENTITY_FLAG_8000000                                     = 0x08000000,
    ENTITY_FLAG_FADING_AWAY                                 = 0x10000000,
    ENTITY_FLAG_PENDING_INSTANCE_DELETE                     = 0x20000000,
    ENTITY_FLAG_SKIP_UPDATE                                 = 0x40000000,
    ENTITY_FLAG_CREATED                                     = 0x80000000,
};

enum EntityCollisionFlags {
    ENTITY_COLLISION_PLAYER_TOUCH_FLOOR                     = 0x00000001,
    ENTITY_COLLISION_FLAG_02                                = 0x00000002,
    ENTITY_COLLISION_PLAYER_TOUCH_CEILING                   = 0x00000004,
    ENTITY_COLLISION_PLAYER_TOUCH_WALL                      = 0x00000008,
    ENTITY_COLLISION_PLAYER_PUSHING_AGAINST                 = 0x00000010,
    ENTITY_COLLISION_FLAG_20                                = 0x00000020,
    ENTITY_COLLISION_PLAYER_HAMMER                          = 0x00000040,
    ENTITY_COLLISION_PARTNER                                = 0x00000080,
    ENTITY_COLLISION_PLAYER_LAST_FLOOR                      = 0x00000100
};

enum EntityHideMode {
    ENTITY_HIDE_MODE_0      = 0,
    ENTITY_HIDE_MODE_1      = 1,
    ENTITY_HIDE_MODE_2      = 2,
};

typedef enum PushGridOccupant {
    PUSH_GRID_EMPTY         = 0,
    PUSH_GRID_BLOCK         = 1,
    PUSH_GRID_OBSTRUCTION   = 2,
    PUSH_GRID_OUT_OF_BOUNDS = 3
} PushGridOccupant;

enum TriggerFlags {
    TRIGGER_ACTIVE              = 0x00000001,
    TRIGGER_ACTIVATED           = 0x00000002,
    TRIGGER_FORCE_ACTIVATE      = 0x00000010,
    TRIGGER_WALL_PUSH           = 0x00000040,
    TRIGGER_FLOOR_TOUCH         = 0x00000080,
    TRIGGER_WALL_PRESS_A        = 0x00000100,
    TRIGGER_FLOOR_JUMP          = 0x00000200,
    TRIGGER_WALL_TOUCH          = 0x00000400,
    TRIGGER_FLOOR_PRESS_A       = 0x00000800,
    TRIGGER_WALL_HAMMER         = 0x00001000,
    TRIGGER_FLAG_2000           = 0x00002000,
    TRIGGER_FLAG_4000           = 0x00004000,
    TRIGGER_FLAG_8000           = 0x00008000,
    TRIGGER_GAME_FLAG_SET       = 0x00010000,
    TRIGGER_AREA_FLAG_SET       = 0x00020000,
    TRIGGER_CEILING_TOUCH       = 0x00040000,
    TRIGGER_FLOOR_ABOVE         = 0x00080000,
    TRIGGER_POINT_BOMB          = 0x00100000,
    TRIGGER_SCRIPT_BOUND        = 0x01000000
};

enum ItemEntityFlags {
    ITEM_ENTITY_FLAG_CAM0                       = 0x00000001,
    ITEM_ENTITY_FLAG_CAM1                       = 0x00000002,
    ITEM_ENTITY_FLAG_CAM2                       = 0x00000004,
    ITEM_ENTITY_FLAG_CAM3                       = 0x00000008,
    ITEM_ENTITY_FLAG_10                         = 0x00000010,
    ITEM_ENTITY_FLAG_HIDDEN                     = 0x00000040, // do not render; player cant pickup
    ITEM_ENTITY_FLAG_JUST_SPAWNED               = 0x00000080,
    ITEM_ENTITY_FLAG_AUTO_COLLECT               = 0x00000100,
    ITEM_ENTITY_FLAG_NEVER_VANISH               = 0x00000200,
    ITEM_ENTITY_FLAG_SAVE_ON_TOUCH              = 0x00000400, // sets bound game flag when the item is touched
    ITEM_ENTITY_FLAG_SAVE_ON_INIT               = 0x00000800,
    ITEM_ENTITY_FLAG_1000                       = 0x00001000,
    ITEM_ENTITY_FLAG_NO_GRAVITY                 = 0x00002000,
    ITEM_ENTITY_RESIZABLE                       = 0x00004000,
    ITEM_ENTITY_FLAG_8000                       = 0x00008000,
    ITEM_ENTITY_FLAG_TOSS_LOWER                 = 0x00010000,
    ITEM_ENTITY_FLAG_ODD_SPAWN_PARITY           = 0x00020000, // every other item entity spawned will have this set
    ITEM_ENTITY_FLAG_FULLSIZE                   = 0x00040000,
    ITEM_ENTITY_FLAG_TRANSPARENT                = 0x00080000,
    ITEM_ENTITY_FLAG_INVISIBLE                  = 0x00100000, // spawned with ITEM_SPAWN_MODE_INVISIBLE
    ITEM_ENTITY_FLAG_CANT_COLLECT               = 0x00200000,
    ITEM_ENTITY_FLAG_400000                     = 0x00400000,
    ITEM_ENTITY_FLAG_800000                     = 0x00800000,
    ITEM_ENTITY_FLAG_TOSS_HIGHER                = 0x01000000,
    ITEM_ENTITY_FLAG_2000000                    = 0x02000000,
    ITEM_ENTITY_FLAG_4000000                    = 0x04000000,
    ITEM_ENTITY_FLAG_HIDING                     = 0x08000000,
    ITEM_ENTITY_FLAG_NO_MOTION                  = 0x10000000,
    ITEM_ENTITY_FLAG_DONE_FALLING               = 0x20000000,
    ITEM_ENTITY_FLAG_ANGLE_RELATIVE_VELOCITY    = 0x40000000,
    ITEM_ENTITY_FLAG_SAVE_ON_RECEIPT            = 0x80000000, // sets bound game flag only when the item is placed in player inventory
};

// governs item behavior after spawning until being picked up
enum ItemPhysicsStates {
    ITEM_PHYSICS_STATE_INIT      = 0x0,
    ITEM_PHYSICS_STATE_ALIVE     = 0x1, //
    ITEM_PHYSICS_STATE_DEAD      = 0x2, // item is vanished or fallen out of the world
    ITEM_PHYSICS_STATE_TOUCH     = 0x3, // player has touched the item
    ITEM_PHYSICS_STATE_04        = 0x4,
    ITEM_PHYSICS_STATE_PICKUP    = 0xA, // item will begin pickup, physics state is invalid after this
};

// governs the process of picking up an item
enum ItemPickupStates {
    // these states comprise the typical progression for item pickup
    ITEM_PICKUP_STATE_INIT                  = 0x0,
    ITEM_PICKUP_STATE_AWAIT_VALID_STATE     = 0x1,
    ITEM_PICKUP_STATE_SHOW_GOT_ITEM         = 0x2,
    ITEM_PICKUP_STATE_HIDE_GOT_ITEM         = 0x3, // wait for window closing animations to finish
    ITEM_PICKUP_STATE_DONE                  = 0x9,
    // next three states are used for tutorials which trigger on item pickup
    ITEM_PICKUP_STATE_CHECK_TUTORIALS       = 0x4,
    ITEM_PICKUP_STATE_SHOW_TUTORIAL         = 0x5,
    ITEM_PICKUP_STATE_AWAIT_TUTORIAL        = 0x6,
    // remaining states occur when inventory is full and an item needs to be throw away
    ITEM_PICKUP_STATE_SHOW_TOO_MANY         = 0xA, // show 'cant carry more items'; open throw away popup on state exit
    ITEM_PICKUP_STATE_HIDE_TOO_MANY         = 0xB, // wait for window closing animations to finish
    ITEM_PICKUP_STATE_AWAIT_THROW_AWAY      = 0xC, // choosing
    ITEM_PICKUP_STATE_SHOW_THREW_AWAY       = 0xD, // you threw away X window
    ITEM_PICKUP_STATE_HIDE_THREW_AWAY       = 0xE, // wait for window closing animations to finish
    ITEM_PICKUP_STATE_THROW_AWAY_DONE       = 0xF,
};

enum ItemPickupFlags {
    ITEM_PICKUP_FLAG_NO_SOUND           = 0x01,
    ITEM_PICKUP_FLAG_NO_ANIMS           = 0x02,
    ITEM_PICKUP_FLAG_UNKNOWN            = 0x04,
    ITEM_PICKUP_FLAG_1_COIN             = 0x10,
    ITEM_PICKUP_FLAG_3_STAR_PIECES      = 0x20,
    ITEM_PICKUP_FLAG_UNIQUE             = 0x40,
};

// Worker
enum WorkerFlags {
    WORKER_FLAG_1                       = 0x00000001,
    WORKER_FLAG_SKIP_DRAW_UNTIL_UPDATE  = 0x00000002,
    WORKER_FLAG_FRONT_UI                = 0x00000004,
    WORKER_FLAG_BACK_UI                 = 0x00000008,
};

enum Buttons {
    BUTTON_C_RIGHT      = 0x00000001,
    BUTTON_C_LEFT       = 0x00000002,
    BUTTON_C_DOWN       = 0x00000004,
    BUTTON_C_UP         = 0x00000008,
    BUTTON_R            = 0x00000010,
    BUTTON_L            = 0x00000020,
    BUTTON_D_RIGHT      = 0x00000100,
    BUTTON_D_LEFT       = 0x00000200,
    BUTTON_D_DOWN       = 0x00000400,
    BUTTON_D_UP         = 0x00000800,
    BUTTON_START        = 0x00001000,
    BUTTON_Z            = 0x00002000,
    BUTTON_B            = 0x00004000,
    BUTTON_A            = 0x00008000,
    BUTTON_STICK_UP     = 0x00010000,
    BUTTON_STICK_DOWN   = 0x00020000,
    BUTTON_STICK_LEFT   = 0x00040000,
    BUTTON_STICK_RIGHT  = 0x00080000,
};

enum PlayerBuffs {
    PLAYER_BUFF_ALL             = 0xFFFFFFFF,
    PLAYER_BUFF_JUMP_CHARGE     = 0x00000001,
    PLAYER_BUFF_HAMMER_CHARGE   = 0x00000002,
    PLAYER_BUFF_STONE           = 0x00000008,
    PLAYER_BUFF_HUSTLE          = 0x00000010,
    PLAYER_BUFF_STATIC          = 0x00000020,
    PLAYER_BUFF_TRANSPARENT     = 0x00000040,
    PLAYER_BUFF_CLOUD_NINE      = 0x00000080,
    PLAYER_BUFF_TURBO_CHARGE    = 0x00000100,
    PLAYER_BUFF_WATER_BLOCK     = 0x00000200,
    PLAYER_BUFF_PARTNER_GLOWING = 0x00010000,
};

enum StatusFlags {
    STATUS_FLAG_SLEEP           = 0x00001000,
    STATUS_FLAG_STATIC          = 0x00002000,
    STATUS_FLAG_FROZEN          = 0x00004000,
    STATUS_FLAG_FEAR            = 0x00008000,
    STATUS_FLAG_PARALYZE        = 0x00010000,
    STATUS_FLAG_POISON          = 0x00020000,
    STATUS_FLAG_DIZZY           = 0x00040000,
    STATUS_FLAG_SHRINK          = 0x00080000,
    STATUS_FLAG_STONE           = 0x00100000,
    STATUS_FLAG_STOP            = 0x00200000,
    STATUS_FLAG_400000          = 0x00400000,
    STATUS_FLAG_KO              = 0x01000000,
    STATUS_FLAG_GLOWING         = 0x02000000,
    STATUS_FLAG_TRANSPARENT     = 0x04000000,
    STATUS_FLAG_ATTACK_BOOST    = 0x08000000,
    STATUS_FLAG_DEFENSE_BOOST   = 0x10000000,
    STATUS_FLAG_CHILL_OUT       = 0x20000000,
    STATUS_FLAG_RIGHT_ON        = 0x40000000,
    STATUS_FLAG_80000000        = 0x80000000,
};

// general combination of flags for checking if an enemy is immobilized
#define STATUS_FLAGS_IMMOBILIZED \
     (STATUS_FLAG_SLEEP \
    | STATUS_FLAG_FROZEN \
    | STATUS_FLAG_FEAR \
    | STATUS_FLAG_PARALYZE \
    | STATUS_FLAG_DIZZY \
    | STATUS_FLAG_STONE \
    | STATUS_FLAG_STOP)

// common set of flags used in checks throughout Dojo fights
#define STATUS_FLAGS_DOJO \
     (STATUS_FLAG_SLEEP \
    | STATUS_FLAG_PARALYZE \
    | STATUS_FLAG_DIZZY \
    | STATUS_FLAG_STONE \
    | STATUS_FLAG_STOP)

enum DamageTypes {
    DAMAGE_TYPE_FIRE                       = 0x00000002,
    DAMAGE_TYPE_WATER                      = 0x00000004,
    DAMAGE_TYPE_ICE                        = 0x00000008,
    DAMAGE_TYPE_MAGIC                      = 0x00000010,
    DAMAGE_TYPE_SHOCK                      = 0x00000020,
    DAMAGE_TYPE_SMASH                      = 0x00000040,
    DAMAGE_TYPE_JUMP                       = 0x00000080,
    DAMAGE_TYPE_COSMIC                     = 0x00000100,
    DAMAGE_TYPE_BLAST                      = 0x00000200,
    DAMAGE_TYPE_POW                        = 0x00000400,
    DAMAGE_TYPE_QUAKE                      = 0x00000800,
    DAMAGE_TYPE_FEAR                       = 0x00001000,
    DAMAGE_TYPE_DEATH                      = 0x00002000,
    DAMAGE_TYPE_4000                       = 0x00004000,
    DAMAGE_TYPE_AIR_LIFT                   = 0x00008000,
    DAMAGE_TYPE_SPINY_SURGE                = 0x00010000,
    DAMAGE_TYPE_SHELL_CRACK                = 0x00020000,
    DAMAGE_TYPE_THROW                      = 0x00040000,
    DAMAGE_TYPE_POWER_BOUNCE               = 0x00100000,
    DAMAGE_TYPE_QUAKE_HAMMER               = 0x00200000,
    DAMAGE_TYPE_REMOVE_BUFFS               = 0x00400000,
    DAMAGE_TYPE_PEACH_BEAM                 = 0x00800000,
    DAMAGE_TYPE_MULTI_BOUNCE               = 0x01000000,
    DAMAGE_TYPE_UNBLOCKABLE                = 0x02000000,
    DAMAGE_TYPE_SPIN_SMASH                 = 0x04000000,
    DAMAGE_TYPE_IGNORE_DEFENSE             = 0x08000000,
    DAMAGE_TYPE_NO_CONTACT                 = 0x10000000,
    DAMAGE_TYPE_MULTIPLE_POPUPS            = 0x20000000, // part of an attack that hits multiple opponents
    DAMAGE_TYPE_STATUS_ALWAYS_HITS         = 0x40000000,
    DAMAGE_TYPE_TRIGGER_LUCKY              = 0x80000000,
};

enum PartnerIDs {
    PARTNER_NONE                = 0x00000000,
    PARTNER_GOOMBARIO           = 0x00000001,
    PARTNER_KOOPER              = 0x00000002,
    PARTNER_BOMBETTE            = 0x00000003,
    PARTNER_PARAKARRY           = 0x00000004,
    PARTNER_GOOMPA              = 0x00000005,
    PARTNER_WATT                = 0x00000006,
    PARTNER_SUSHIE              = 0x00000007,
    PARTNER_LAKILESTER          = 0x00000008,
    PARTNER_BOW                 = 0x00000009,
    PARTNER_GOOMBARIA           = 0x0000000A,
    PARTNER_TWINK               = 0x0000000B,
};

enum EventSupressFlags {
    SUPPRESS_EVENT_SPIKY_TOP        = 0x1,
    SUPPRESS_EVENT_EXPLODE_CONTACT  = 0x2,
    SUPPRESS_EVENT_SPIKY_FRONT      = 0x4,
    SUPPRESS_EVENT_SHOCK_CONTACT    = 0x8,
    SUPPRESS_EVENT_BURN_CONTACT     = 0x10,
    SUPPRESS_EVENT_ALT_SPIKY        = 0x80,
    SUPPRESS_EVENT_FLAG_200         = 0x200,    // unused?
    SUPPRESS_EVENT_ALL              = 0xFFFF,
    SUPPRESS_EVENT_FLAG_10000       = 0x10000,  // usage is a bug?
};

// combination used for hammer-based attacks
#define SUPPRESS_EVENTS_HAMMER \
      SUPPRESS_EVENT_SPIKY_TOP \
    | SUPPRESS_EVENT_SHOCK_CONTACT \
    | SUPPRESS_EVENT_BURN_CONTACT

// combination used for mostly for kooper's attacks
#define SUPPRESS_EVENTS_KOOPER_TEST \
      SUPPRESS_EVENT_SPIKY_FRONT \
    | SUPPRESS_EVENT_BURN_CONTACT

// combination used for mostly for kooper's attacks
#define SUPPRESS_EVENTS_KOOPER_DAMAGE \
      SUPPRESS_EVENT_SPIKY_TOP \
    | SUPPRESS_EVENT_EXPLODE_CONTACT \
    | SUPPRESS_EVENT_SPIKY_FRONT \
    | SUPPRESS_EVENT_SHOCK_CONTACT \
    | SUPPRESS_EVENT_BURN_CONTACT \
    | SUPPRESS_EVENT_ALT_SPIKY

enum PartnerActions {
    PARTNER_ACTION_NONE             = 0, // generic state
    PARTNER_ACTION_USE              = 1, // generic state
    PARTNER_ACTION_KOOPER_GATHER    = 1,
    PARTNER_ACTION_KOOPER_TOSS      = 2,
    PARTNER_ACTION_BOMBETTE_1       = 1,
    PARTNER_ACTION_BOMBETTE_2       = 2,
    PARTNER_ACTION_BOMBETTE_3       = 3,
    PARTNER_ACTION_PARAKARRY_HOVER  = 1,
    PARTNER_ACTION_WATT_SHINE       = 1,
    PARTNER_ACTION_LAKILESTER_1     = 1,
};

enum PartnerStates {
    PARTNER_CMD_NONE                = 0,
    PARTNER_CMD_INIT                = 1,
    PARTNER_CMD_INSTA_SWITCH        = 2, // skips put away / take out scripts. assumes valid current partner.
    PARTNER_CMD_SWITCH              = 3, // assumes valid current partner.
    PARTNER_CMD_PUT_AWAY            = 4, // switches to null partner.
    PARTNER_CMD_INSTA_PUT_AWAY      = 5,
    PARTNER_CMD_TAKE_OUT            = 6, // assumes no current partner.
    PARTNER_CMD_INSTA_TAKE_OUT      = 7,
    PARTNER_CMD_USE_ABILITY         = 8,
    PARTNER_CMD_RESET               = 9,
    PARTNER_CMD_ABORT               = 10,
};

/// @see gAreas
enum Areas {
    AREA_KMR,
    AREA_MAC,
    AREA_TIK,
    AREA_KGR,
    AREA_KKJ,
    AREA_HOS,
    AREA_NOK,
    AREA_TRD,
    AREA_IWA,
    AREA_DRO,
    AREA_SBK,
    AREA_ISK,
    AREA_MIM,
    AREA_OBK,
    AREA_ARN,
    AREA_DGB,
    AREA_OMO,
    AREA_JAN,
    AREA_KZN,
    AREA_FLO,
    AREA_SAM,
    AREA_PRA,
    AREA_KPA,
    AREA_OSR,
    AREA_END,
    AREA_MGM,
    AREA_GV,
    AREA_TST,
};

enum NpcPalSwapState {
    NPC_PALSWAP_HOLDING_A           = 0,
    NPC_PALSWAP_FROM_A_TO_B         = 1,
    NPC_PALSWAP_HOLDING_B           = 2,
    NPC_PALSWAP_FROM_B_TO_A         = 3
};

enum NpcFlags {
    NPC_FLAG_ENABLED                        = 0x00000001, // Does nothing aside from making npc->flags !=
    NPC_FLAG_INVISIBLE                      = 0x00000002, // NPC will not be drawn or cause surface effects while moving
    NPC_FLAG_INACTIVE                       = 0x00000004, // NPC will not render, move, or have collisions with other NPCs. They may still be interacted with.
    NPC_FLAG_FLYING                         = 0x00000008,
    NPC_FLAG_HAS_SHADOW                     = 0x00000010, // Set by default and by enable_npc_shadow
    NPC_FLAG_NO_SHADOW_RAYCAST              = 0x00000020, // Shadows are tied to NPC position instead of raycasting below the NPC
    NPC_FLAG_IGNORE_WORLD_COLLISION         = 0x00000040,
    NPC_FLAG_UPSIDE_DOWN                    = 0x00000080, // Render NPCs upside-down
    NPC_FLAG_IGNORE_PLAYER_COLLISION        = 0x00000100,
    NPC_FLAG_GRAVITY                        = 0x00000200, // Enables gravity. Does nothing if NPC_FLAG_JUMPING is set.
    NPC_FLAG_DONT_UPDATE_SHADOW_Y           = 0x00000400, // When shadow raycasting is off, only X and Z update as NPC moves
    NPC_FLAG_JUMPING                        = 0x00000800,
    NPC_FLAG_GROUNDED                       = 0x00001000, // Touching the ground
    NPC_FLAG_COLLDING_WITH_WORLD            = 0x00002000, // Colliding with world in front or to the sides of the NPC
    NPC_FLAG_COLLDING_FORWARD_WITH_WORLD    = 0x00004000, // Colliding with world directly in front of NPC
    NPC_FLAG_IGNORE_ENTITY_COLLISION        = 0x00008000,
    NPC_FLAG_DIRTY_SHADOW                   = 0x00010000, // Set if shadow is dirty (needs to be repositioned etc.)
    NPC_FLAG_REFLECT_WALL                   = 0x00020000, // Mirror rendering across z=0
    NPC_FLAG_IGNORE_CAMERA_FOR_YAW          = 0x00040000, // Do not adjust renderYaw to face the camera
    NPC_FLAG_REFLECT_FLOOR                  = 0x00080000, // Mirror rendering across y=0
    NPC_FLAG_MOTION_BLUR                    = 0x00100000, // Gives motion blur effect as NPC moves. Set by enable_npc_blur
    NPC_FLAG_200000                         = 0x00200000,
    NPC_FLAG_TOUCHES_GROUND                 = 0x00400000, // Can cause effects to play when touching special surface types
    NPC_FLAG_HIDING                         = 0x00800000,
    NPC_FLAG_HAS_NO_SPRITE                  = 0x01000000,
    NPC_FLAG_COLLIDING_WITH_NPC             = 0x02000000,
    NPC_FLAG_PARTNER                        = 0x04000000,
    NPC_FLAG_WORLD_COLLISION_DIRTY          = 0x08000000,
    NPC_FLAG_10000000                       = 0x10000000,
    NPC_FLAG_20000000                       = 0x20000000,
    NPC_FLAG_NO_ANIMS_LOADED                = 0x40000000, // Npc has no animations loaded
    NPC_FLAG_SUSPENDED                      = 0x80000000,
};

enum PlayerStatusFlags {
    PS_FLAG_AIRBORNE                         = 0x0000000E,
    PS_FLAG_HAS_REFLECTION                   = 0x00000001,
    PS_FLAG_JUMPING                          = 0x00000002,
    PS_FLAG_FALLING                          = 0x00000004,
    PS_FLAG_FLYING                           = 0x00000008,
    PS_FLAG_SLIDING                          = 0x00000010,
    /* Paused either via the start menu, or through another menu that causes a pause (like the item menu) */
    PS_FLAG_PAUSED                           = 0x00000020,
    PS_FLAG_NO_CHANGE_PARTNER                = 0x00000040,
    PS_FLAG_NO_PARTNER_USAGE                 = 0x00000080,
    /* Prevents opening menus that would require a game-time pause (start menu, item menu, etc) */
    PS_FLAG_PAUSE_DISABLED                   = 0x00000100,
    /* Doing either a spin jump or a tornado jump */
    PS_FLAG_SPECIAL_JUMP                     = 0x00000200,
    /* Landing from either a spin jump or a tornado jump */
    PS_FLAG_SPECIAL_LAND                     = 0x00000400,
    /* Burning from touching a fire hazard of some kind */
    PS_FLAG_HIT_FIRE                         = 0x00000800,
    PS_FLAG_NO_STATIC_COLLISION              = 0x00001000,
    PS_FLAG_INPUT_DISABLED                   = 0x00002000,
    /* Indicates that Mario's lateral movement is currently commandeered by a cutscene or script */
    PS_FLAG_CUTSCENE_MOVEMENT                = 0x00004000,
    /* Either outta sight with Bow, or temporarily damage boosted - makes Mario ignore fire bars */
    PS_FLAG_HAZARD_INVINCIBILITY             = 0x00008000,
    /* Spinning either through pressing Z or the tornado jump - causes a ghost trail to render */
    PS_FLAG_SPINNING                         = 0x00020000,
    /* Slows Mario's physics and animations to half speed - responsible for the dramatic slowdown when starting an encounter by jumping on an enemy.
       Also stops Mario from successfully completing a hammer. */
    PS_FLAG_ENTERING_BATTLE                  = 0x00040000,
    /* Occurs after hitting a heart block - temporarily prevents encounters from starting */
    PS_FLAG_ARMS_RAISED                      = 0x00080000,
    /* Stops Mario's sprite yaw from being adjusted, usually so a cutscene can do it instead. */
    PS_FLAG_ROTATION_LOCKED                  = 0x00100000,
    /* Forces Mario's sprite to either face exactly left or right, without transitioning. */
    PS_FLAG_NO_FLIPPING                      = 0x00200000,
    /* Prevents Mario from moving laterally */
    PS_FLAG_MOVEMENT_LOCKED                  = 0x00400000, //TODO misnamed
    /* Stops Mario from air steering or using a special jump during a scripted fall */
    PS_FLAG_SCRIPTED_FALL                    = 0x00800000,
    /* Not fully sure about this one, but appears to mark the frame that the check for what to hammer occurs */
    PS_FLAG_HAMMER_CHECK                     = 0x01000000,
    PS_FLAG_HAS_CONVERSATION_NPC             = 0x02000000,
    PS_FLAG_CAMERA_DOESNT_FOLLOW             = 0x04000000,
    /* Mario just interacted with something (usually cleared on the same frame) */
    PS_FLAG_INTERACTED                       = 0x08000000,
    /* Makes Mario face forwards, used when talking to NPCs, or when on Lakilester */
    PS_FLAG_FACE_FORWARD                     = 0x10000000,
    /* Freezes physics and animations - is usually reset at the start of a frame so often does nothing */
    PS_FLAG_TIME_STOPPED                     = 0x20000000,
    /* Indicates that Mario needs his sprite redrawn */
    PS_FLAG_SPRITE_REDRAW                    = 0x40000000,
    PS_FLAG_ACTION_STATE_CHANGED             = 0x80000000,
};

/// @see PlayerStatus::animFlags
enum PlayerStatusAnimFlags {
    /* Whether Mario is in the process of using Watt (but isn't necessarily holding them yet) */
    PA_FLAG_USING_WATT                       = 0x00000001,
    /* Whether Watt is actually in Mario's hands at the moment */
    PA_FLAG_WATT_IN_HANDS                    = 0x00000002,
    PA_FLAG_INTERRUPT_USE_PARTNER            = 0x00000004, ///< forces actions with bow, parakarry, watt, and lakilester to end (sushie not tested)
    PA_FLAG_FORCE_USE_PARTNER                = 0x00000008, ///< triggers partner use when set
    PA_FLAG_INTERACT_PROMPT_AVAILABLE        = 0x00000010, ///< ! prompt
    PA_FLAG_SPEECH_PROMPT_AVAILABLE          = 0x00000020, ///< (...) prompt
    PA_FLAG_PULSE_STONE_VISIBLE              = 0x00000040, ///< The pulse stone icon is being shown
    PA_FLAG_USING_PULSE_STONE                = 0x00000080,
    PA_FLAG_ISPY_VISIBLE                     = 0x00000100, ///< The I Spy icon is being shown
    PA_FLAG_RAISED_ARMS                      = 0x00000200, ///< Sets action state to ACTION_STATE_RAISE_ARMS on idle
    PA_FLAG_SHIVERING                        = 0x00000400,
    PA_FLAG_OPENED_HIDDEN_PANEL              = 0x00000800,
    PA_FLAG_USING_PEACH_PHYSICS              = 0x00001000,
    PA_FLAG_INVISIBLE                        = 0x00002000,
    PA_FLAG_8BIT_MARIO                       = 0x00004000,
    PA_FLAG_NPC_COLLIDED                     = 0x00008000,
    PA_FLAG_SPINNING                         = 0x00010000,
    /* Began an encounter by spinning into an enemy with the Dizzy Attack badge on */
    PA_FLAG_DIZZY_ATTACK_ENCOUNTER           = 0x00020000,
    PA_FLAG_INTERRUPT_SPIN                   = 0x00040000,
    /* When Mario is in a transition to a new map, either through a loading zone or pipe */
    PA_FLAG_CHANGING_MAP                     = 0x00100000,
    /* Occurs after PA_FLAG_FORCE_USE_PARTNER. Some partners - namely Bow and Lakilester, unset this immediately.
       Not sure why - seems like it might contribute to being unable to *stop* using your partner during a cutscene. */
    PA_FLAG_PARTNER_USAGE_FORCED             = 0x00200000,
    PA_FLAG_RIDING_PARTNER                   = 0x00400000,
    PA_FLAG_ABORT_PUSHING_BLOCK              = 0x00800000,
    /* Changes how Mario is rendered. Seems to be intended to make Mario's depth render properly when using Bow behind a switch (two translucent objects on top of eachother), but it doesn't actually work. */
    PA_FLAG_MAP_HAS_SWITCH                   = 0x01000000,
    /* Usually, if Mario falls for too long, he eventually gets reset to his last safe position. This prevents that. Used by some scripts. */
    PA_FLAG_NO_OOB_RESPAWN                   = 0x10000000,
    /* This allows dismounting from Lakilester, even if in a precarious situation (like over spikes, lava, or water). */
    PA_FLAG_DISMOUNTING_ALLOWED              = 0x20000000,
    /* This flag is set when partner usage was interrupted by a script, and it prevents menu sounds (like the error sound) from playing for script-initiated player actions */
    PA_FLAG_FORCED_PARTNER_ABILITY_END       = 0x40000000,
    /* This one's really weird. Seems to have something to do with the direction Mario is facing, but I'm not sure what it's actually supposed to be achieving. */
    PA_FLAG_80000000                         = 0x80000000,
};

enum PopupType {
    POPUP_MENU_USE_ITEM             = 0x0,
    POPUP_MENU_SWITCH_PARTNER       = 0x1,
    POPUP_MENU_THROW_AWAY_ITEM      = 0x2,
    POPUP_MENU_TRADE_FOR_BADGE      = 0x3,
    POPUP_MENU_UPGRADE_PARTNER      = 0x4,
    POPUP_MENU_SELL_ITEM            = 0x5,
    POPUP_MENU_CHECK_ITEM           = 0x6,
    POPUP_MENU_CLAIM_ITEM           = 0x7,
    POPUP_MENU_READ_LETTER          = 0x8,
    POPUP_MENU_TAKE_FROM_CHEST      = 0x9,
    POPUP_MENU_READ_DIARY_PAGE      = 0xA,
    POPUP_MENU_READ_POSTCARD        = 0xB,
    POPUP_MENU_USEKEY               = 0xC,
    POPUP_MENU_POST_OFFICE          = 0xD,
    POPUP_MENU_DOUBLE_DIP           = 100,
    POPUP_MENU_TRIPLE_DIP           = 200,
};

enum PopupState {
    POPUP_STATE_INIT                        = 0,
    POPUP_STATE_CHOOSING                    = 1,
    POPUP_STATE_10                          = 10,
    POPUP_STATE_11                          = 11,
    POPUP_STATE_20                          = 20,
    POPUP_STATE_ALREADY_HAVE_PARTNER_BEGIN  = 30,
    POPUP_STATE_ALREADY_HAVE_PARTNER_SHOW   = 31,
    POPUP_STATE_ALREADY_HAVE_PARTNER_AWAIT  = 32,
    POPUP_STATE_CANCEL_DIP                  = 100,
    POPUP_STATE_CANCEL_DIP_AWAIT_CHOICE     = 101,
    POPUP_STATE_CANCEL_DIP_ACCEPT           = 102,
    POPUP_STATE_CANCEL_DIP_DECLINE          = 103,
    POPUP_STATE_104                         = 104,
    POPUP_STATE_105                         = 105,
    POPUP_STATE_CHOSE_WORLD                 = -1,
    POPUP_STATE_CHOSE_BATTLE                = -2,
    POPUP_STATE_MINUS_3                     = -3,
    POPUP_STATE_MINUS_4                     = -4,
    POPUP_STATE_MINUS_5                     = -5,
    POPUP_STATE_CHOSE_SWAP                  = -6,
    POPUP_STATE_MINUS_7                     = -7,
    POPUP_STATE_MINUS_8                     = -8,
};

enum PopupResult {
    POPUP_RESULT_INVALID    = -1,
    POPUP_RESULT_SWAP_MENU  = -2,
    POPUP_RESULT_CHOOSING   = 0,
    POPUP_RESULT_CANCEL     = 255,
};

enum WindowPriority {
    WINDOW_PRIORITY_0               = 0,
    WINDOW_PRIORITY_1               = 1,
    WINDOW_PRIORITY_10              = 10,
    WINDOW_PRIORITY_19              = 19,
    WINDOW_PRIORITY_20              = 20,
    WINDOW_PRIORITY_21              = 21,
    WINDOW_PRIORITY_64              = 64,
};

enum RenderModeIndex {
    // RM1 modes
    RENDER_MODE_IDX_00 = 0x00,
    RENDER_MODE_IDX_01 = 0x01,
    RENDER_MODE_IDX_02 = 0x02,
    RENDER_MODE_IDX_03 = 0x03,
    RENDER_MODE_IDX_04 = 0x04,
    RENDER_MODE_IDX_05 = 0x05,
    RENDER_MODE_IDX_06 = 0x06,
    RENDER_MODE_IDX_07 = 0x07,
    RENDER_MODE_IDX_08 = 0x08,
    RENDER_MODE_IDX_09 = 0x09,
    RENDER_MODE_IDX_0A = 0x0A,
    RENDER_MODE_IDX_0B = 0x0B,
    RENDER_MODE_IDX_0C = 0x0C,
    RENDER_MODE_IDX_0D = 0x0D,
    RENDER_MODE_IDX_0E = 0x0E,
    RENDER_MODE_IDX_0F = 0x0F,
    // RM2 modes
    RENDER_MODE_IDX_10 = 0x10,
    RENDER_MODE_IDX_11 = 0x11,
    RENDER_MODE_IDX_12 = 0x12,
    RENDER_MODE_IDX_13 = 0x13,
    RENDER_MODE_IDX_14 = 0x14,
    RENDER_MODE_IDX_15 = 0x15,
    RENDER_MODE_IDX_16 = 0x16,
    RENDER_MODE_IDX_17 = 0x17,
    RENDER_MODE_IDX_18 = 0x18,
    RENDER_MODE_IDX_19 = 0x19,
    RENDER_MODE_IDX_1A = 0x1A,
    RENDER_MODE_IDX_1B = 0x1B,
    RENDER_MODE_IDX_1C = 0x1C,
    RENDER_MODE_IDX_1D = 0x1D,
    RENDER_MODE_IDX_1E = 0x1E,
    // RM3 modes
    RENDER_MODE_IDX_1F = 0x1F,
    RENDER_MODE_IDX_20 = 0x20,
    RENDER_MODE_IDX_21 = 0x21,
    RENDER_MODE_IDX_22 = 0x22,
    RENDER_MODE_IDX_23 = 0x23,
    RENDER_MODE_IDX_24 = 0x24,
    RENDER_MODE_IDX_25 = 0x25,
    RENDER_MODE_IDX_26 = 0x26,
    RENDER_MODE_IDX_27 = 0x27,
    RENDER_MODE_IDX_28 = 0x28,
    RENDER_MODE_IDX_29 = 0x29,
    RENDER_MODE_IDX_2A = 0x2A,
    RENDER_MODE_IDX_2B = 0x2B,
    RENDER_MODE_IDX_2C = 0x2C,
    RENDER_MODE_IDX_2D = 0x2D,
    RENDER_MODE_IDX_2E = 0x2E,
    RENDER_MODE_IDX_2F = 0x2F,
    RENDER_MODE_IDX_30 = 0x30,
    RENDER_MODE_IDX_31 = 0x31,
    RENDER_MODE_IDX_32 = 0x32,
    RENDER_MODE_IDX_33 = 0x33,
    RENDER_MODE_IDX_34 = 0x34,
    RENDER_MODE_IDX_35 = 0x35,
    RENDER_MODE_IDX_36 = 0x36,
    // cloud render modes
    RENDER_MODE_IDX_37 = 0x37,
    RENDER_MODE_IDX_38 = 0x38,
    RENDER_MODE_IDX_39 = 0x39,
    RENDER_MODE_IDX_3A = 0x3A,
    RENDER_MODE_IDX_3B = 0x3B,
    RENDER_MODE_IDX_3C = 0x3C,
};

// predefined configurations for RDP geometry and render modes
// though these are called "render modes", they do not strictly correspond to the RDP render modes (as supplied to gDPSetRenderMode)
enum RenderMode {
    // opaque render modes
    RENDER_MODE_SURF_SOLID_AA_ZB_LAYER0          = 0x00,
    RENDER_MODE_SURFACE_OPA                      = 0x01,
    RENDER_MODE_02_UNUSED                        = 0x02,
    RENDER_MODE_SURFACE_OPA_NO_AA                = 0x03,
    RENDER_MODE_SURFACE_OPA_NO_ZB                = 0x04,
    RENDER_MODE_DECAL_OPA                        = 0x05,
    RENDER_MODE_06_UNUSED                        = 0x06,
    RENDER_MODE_DECAL_OPA_NO_AA                  = 0x07,
    RENDER_MODE_08_UNUSED                        = 0x08,
    RENDER_MODE_INTERSECTING_OPA                 = 0x09,
    RENDER_MODE_0A_UNUSED                        = 0x0A,
    RENDER_MODE_0B_UNUSED                        = 0x0B,
    RENDER_MODE_0C_UNUSED                        = 0x0C,
    RENDER_MODE_ALPHATEST                        = 0x0D,
    RENDER_MODE_0E_UNUSED                        = 0x0E,
    RENDER_MODE_ALPHATEST_ONESIDED               = 0x0F,
    RENDER_MODE_ALPHATEST_NO_ZB                  = 0x10,
    RENDER_MODES_LAST_OPAQUE                     = RENDER_MODE_ALPHATEST_NO_ZB,
    // translucent render modes
    RENDER_MODE_SURFACE_XLU_LAYER1               = 0x11,
    RENDER_MODE_12_UNUSED                        = 0x12,
    RENDER_MODE_SURFACE_XLU_NO_AA                = 0x13,
    RENDER_MODE_SURFACE_XLU_NO_ZB                = 0x14,
    RENDER_MODE_SURFACE_XLU_ZB_ZUPD              = 0x15,
    RENDER_MODE_SURFACE_XLU_LAYER2               = 0x16,
    RENDER_MODE_17_UNUSED                        = 0x17,
    RENDER_MODE_18_UNUSED                        = 0x18,
    RENDER_MODE_19_UNUSED                        = 0x19,
    RENDER_MODE_DECAL_XLU                        = 0x1A,
    RENDER_MODE_1B_UNUSED                        = 0x1B,
    RENDER_MODE_DECAL_XLU_NO_AA                  = 0x1C,
    RENDER_MODE_1D_UNUSED                        = 0x1D,
    RENDER_MODE_DECAL_XLU_AHEAD                  = 0x1E, // special case RENDER_MODE_DECAL_XLU for rendering in front of others
    RENDER_MODE_1F_UNUSED                        = 0x1F,
    RENDER_MODE_SHADOW                           = 0x20,
    RENDER_MODE_21_UNUSED                        = 0x21,
    RENDER_MODE_SURFACE_XLU_LAYER3               = 0x22,
    RENDER_MODE_23_UNUSED                        = 0x23,
    RENDER_MODE_24_UNUSED                        = 0x24,
    RENDER_MODE_25_UNUSED                        = 0x25,
    RENDER_MODE_INTERSECTING_XLU                 = 0x26,
    RENDER_MODE_27_UNUSED                        = 0x27,
    // unusual render modes
    RENDER_MODE_PASS_THROUGH                     = 0x28, // no render mode is set, only geometry modes are initialized
    RENDER_MODE_SURFACE_XLU_AA_ZB_ZUPD           = 0x29,
    RENDER_MODE_SURFACE_OPA_NO_ZB_BEHIND         = 0x2A,
    RENDER_MODE_ALPHATEST_NO_ZB_BEHIND           = 0x2B,
    RENDER_MODE_SURFACE_XLU_NO_ZB_BEHIND         = 0x2C,
    RENDER_MODE_CLOUD_NO_ZCMP                    = 0x2D,
    RENDER_MODE_CLOUD                            = 0x2E,
    RENDER_MODE_CLOUD_NO_ZB                      = 0x2F,
};

enum RenderTaskFlags {
    RENDER_TASK_FLAG_ENABLED        = 0x01,
    RENDER_TASK_FLAG_REFLECT_FLOOR  = 0x02,
    RENDER_TASK_FLAG_20             = 0x20,
};

// same as ActorPartFlags, kept separate for clarity
enum ActorFlags {
    ACTOR_FLAG_INVISIBLE                    = 0x00000001, ///< Actor is not rendered.
    ACTOR_FLAG_NO_SHADOW                    = 0x00000004, ///< Hide shadow.
    ACTOR_FLAG_LOW_PRIORITY_TARGET          = 0x00000010, // only usable with ACTOR_FLAG_TARGET_ONLY, treats the target's sort position as off-stage to the right
    ACTOR_FLAG_MINOR_TARGET                 = 0x00000040, // ignored by moves using TARGET_FLAG_PRIMARY_ONLY (unused)
    ACTOR_FLAG_NO_TATTLE                    = 0x00000080,
    ACTOR_FLAG_FLYING                       = 0x00000200, ///< Quake Hammer can't hit.
    ACTOR_FLAG_FLIPPED                      = 0x00000400, ///< Actor has been flipped over.
    ACTOR_FLAG_UPSIDE_DOWN                  = 0x00000800, ///< HP bar offset below actor (e.g. Swooper when upside-down).
    ACTOR_FLAG_TYPE_CHANGED                 = 0x00001000, ///< Indicates actors type has changed, triggers recheck for if HP bar should be shown based on tattle status.
    ACTOR_FLAG_DAMAGE_IMMUNE                = 0x00002000, // prevents hits from items, chill out, and up & away
    ACTOR_FLAG_TARGET_ONLY                  = 0x00004000, ///< Battle ends even if undefeated. No turn.
    ACTOR_FLAG_HALF_HEIGHT                  = 0x00008000,
    ACTOR_FLAG_SKIP_TURN                    = 0x00010000,
    ACTOR_FLAG_NO_HEALTH_BAR                = 0x00040000, // Health bar is not shown for this actor type
    ACTOR_FLAG_HEALTH_BAR_HIDDEN            = 0x00080000, // Health bar is temporarily hidden
    ACTOR_FLAG_NO_ATTACK                    = 0x00200000, ///< Skip attack turn.
    ACTOR_FLAG_NO_DMG_APPLY                 = 0x00400000, ///< Damage is not applied to actor HP.
    ACTOR_FLAG_NO_DMG_POPUP                 = 0x02000000, ///< Hide damage popup.
    ACTOR_FLAG_USING_IDLE_ANIM              = 0x04000000,
    ACTOR_FLAG_SHOW_STATUS_ICONS            = 0x08000000,
    ACTOR_FLAG_BLUR_ENABLED                 = 0x10000000,
    ACTOR_FLAG_NO_INACTIVE_ANIM             = 0x20000000, // only used for player Actor
};

// same as ActorFlags, kept separate for clarity
enum ActorPartFlags {
    ACTOR_PART_FLAG_INVISIBLE               = 0x00000001,
    ACTOR_PART_FLAG_NO_DECORATIONS          = 0x00000002,
    ACTOR_PART_FLAG_NO_SHADOW               = 0x00000004,
    ACTOR_PART_FLAG_DEFAULT_TARGET          = 0x00000008, // Part will be the default selected target for player.
    ACTOR_PART_FLAG_IGNORE_BELOW_CHECK      = 0x00000020, // ignore below check while targeting
    ACTOR_PART_FLAG_MINOR_TARGET            = 0x00000040, // ignored by moves using TARGET_FLAG_PRIMARY_ONLY (unused)
    ACTOR_PART_FLAG_NO_TATTLE               = 0x00000080,
    ACTOR_PART_FLAG_TRANSPARENT             = 0x00000100,
    ACTOR_PART_FLAG_DAMAGE_IMMUNE           = 0x00002000, ///< electrified Plays extra hurt SFX?
    ACTOR_PART_FLAG_TARGET_ONLY             = 0x00004000, // Has no effect on ActorPart. Use the ACTOR_FLAG on Actor instead.
    ACTOR_PART_FLAG_NO_TARGET               = 0x00020000, ///< Cannot be targeted.
    ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION   = 0x00100000,
    ACTOR_PART_FLAG_PRIMARY_TARGET          = 0x00800000, // Multi-target attacks will target this part of an Actor with multiple parts.
    ACTOR_PART_FLAG_HAS_PAL_EFFECT          = 0x01000000,
    ACTOR_PART_FLAG_NO_STATUS_ANIMS         = 0x20000000, // Do not update idle animation based on Actor status
    ACTOR_PART_FLAG_SKIP_SHOCK_EFFECT       = 0x40000000, // Do not apply a shock effect to this ActorPart when its Actor is shocked
    ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC     = 0x80000000, // Do not allocate ActorPartMovement for this ActorPart
};

enum ActorEventFlags {
    ACTOR_EVENT_FLAGS_NONE                  = 0x00000000,
    ACTOR_EVENT_FLAG_FIREY                  = 0x00000002, ///< Player takes burn damage upon contact.
    ACTOR_EVENT_FLAG_ICY                    = 0x00000008, ///< No known effect, but is used.
    ACTOR_EVENT_FLAG_SPIKY_TOP              = 0x00000010, ///< Player takes spike damage from jump attacks.
    ACTOR_EVENT_FLAG_ILLUSORY               = 0x00000020, ///< Player attacks pass through and miss.
    ACTOR_EVENT_FLAG_ELECTRIFIED            = 0x00000080, ///< Player takes shock damage upon contact.
    ACTOR_EVENT_FLAG_MONSTAR                = 0x00000100, ///< Set by Monstar, but has no effect
    ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION    = 0x00000200, ///< Blast and fire attacks trigger an explosion.
    ACTOR_EVENT_FLAG_FIRE_EXPLODE           = 0x00000400, ///< Fire attacks trigger an explosion, used only by bullet/bombshell bills.
    ACTOR_EVENT_FLAG_BURIED                 = 0x00000800, ///< Actor can only by hit by quake-element attacks.
    ACTOR_EVENT_FLAG_FLIPABLE               = 0x00001000, ///< Actor can be flipped; triggered by jump and quake attacks.
    ACTOR_EVENT_FLAG_EXTREME_DEFENSE        = 0x00002000, ///< Actor has 127 extra defense during damage calculation, unaffected by IGNORE_DEFENSE.
    ACTOR_EVENT_FLAG_GROUNDABLE             = 0x00004000, ///< Actor can be knocked down from flight; triggered by jump attacks.
    ACTOR_EVENT_FLAG_EXPLODE_ON_CONTACT     = 0x00008000, ///< Attacks that contact will trigger an explosion.
    ACTOR_EVENT_FLAG_SPIKY_FRONT            = 0x00010000, ///< Player takes spike damage from hammer attacks.
    ACTOR_EVENT_FLAG_ENCHANTED              = 0x00040000, ///< Actor glows and listens for the Star Beam event.
    ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED     = 0x00080000, ///< Actor glows and listens for Star Beam and Peach Beam events.
    ACTOR_EVENT_FLAG_POWER_BOUNCE           = 0x00100000, ///< Actor listens for Power Bounce events.
    ACTOR_EVENT_FLAG_ALT_SPIKY              = 0x00200000, ///< Additional spiky quality associated with Pokeys and Spinies
    ACTOR_EVENT_FLAG_ATTACK_CHARGED         = 0x00400000, ///< Actor has charged an attack that can be removed with Star Beam.
    ACTOR_EVENT_FLAG_RIDING_BROOMSTICK      = 0x00800000, ///< Actor is on Magikoopa Broomstick, effect seems to be redundant.
};

enum PartnerWishAnims {
    PARTNER_WISH_ANIM_WALK          = 0,
    PARTNER_WISH_ANIM_PRAY          = 1,
    PARTNER_WISH_ANIM_UNUSED        = 2,
    PARTNER_WISH_ANIM_RETURN        = 3,
    PARTNER_WISH_ANIM_IDLE          = 4,
};

enum PartnerAnimIndices {
    PARTNER_ANIM_INDEX_STILL      = 0x0,
    PARTNER_ANIM_INDEX_WALK       = 0x1,
    PARTNER_ANIM_INDEX_JUMP       = 0x2,
    PARTNER_ANIM_INDEX_FALL       = 0x3,
    PARTNER_ANIM_INDEX_FLY        = 0x4,
    PARTNER_ANIM_INDEX_IDLE       = 0x5,
    PARTNER_ANIM_INDEX_RUN        = 0x6,
    PARTNER_ANIM_INDEX_TALK       = 0x7,
    PARTNER_ANIM_INDEX_HURT       = 0x8,
};

enum AnyPartnerAnims {
    PARTNER_ANIM_STILL      = 0x101,
    PARTNER_ANIM_WALK       = 0x102,
    PARTNER_ANIM_JUMP       = 0x103,
    PARTNER_ANIM_FALL       = 0x104,
    PARTNER_ANIM_FLY        = 0x105,
    PARTNER_ANIM_IDLE       = 0x106,
    PARTNER_ANIM_RUN        = 0x107,
    PARTNER_ANIM_TALK       = 0x108,
    PARTNER_ANIM_HURT       = 0x109,
};

enum EnemyAnimIndices {
    ENEMY_ANIM_INDEX_IDLE         = 0,
    ENEMY_ANIM_INDEX_WALK         = 1,
    ENEMY_ANIM_INDEX_RUN          = 2,
    ENEMY_ANIM_INDEX_CHASE        = 3,
    ENEMY_ANIM_INDEX_JUMP         = 4,
    ENEMY_ANIM_INDEX_05           = 5,
    ENEMY_ANIM_INDEX_DEATH        = 6,
    ENEMY_ANIM_INDEX_HIT          = 7,
    ENEMY_ANIM_INDEX_MELEE_PRE    = 8,
    ENEMY_ANIM_INDEX_MELEE_HIT    = 9,
};

enum AnyEnemyAnims {
    ENEMY_ANIM_IDLE         = 0x201,
    ENEMY_ANIM_WALK         = 0x202,
    ENEMY_ANIM_RUN          = 0x203,
    ENEMY_ANIM_CHASE        = 0x204,
    ENEMY_ANIM_JUMP         = 0x205,
    ENEMY_ANIM_5            = 0x206,
    ENEMY_ANIM_DEATH        = 0x207,
    ENEMY_ANIM_HIT          = 0x208,
    ENEMY_ANIM_8            = 0x209,
    ENEMY_ANIM_9            = 0x20A,
    ENEMY_ANIM_A            = 0x20B,
    ENEMY_ANIM_B            = 0x20C,
    ENEMY_ANIM_C            = 0x20D,
    ENEMY_ANIM_D            = 0x20E,
    ENEMY_ANIM_E            = 0x20F,
    ENEMY_ANIM_F            = 0x210,
};

enum FirstStrikes {
    FIRST_STRIKE_NONE           = 0,
    FIRST_STRIKE_PLAYER         = 1,
    FIRST_STRIKE_ENEMY          = 2,
};

enum TimeFreezeMode {
    TIME_FREEZE_NORMAL          = 0,
    TIME_FREEZE_PARTIAL         = 1,
    TIME_FREEZE_FULL            = 2,
    TIME_FREEZE_POPUP_MENU      = 3,
    TIME_FREEZE_EXIT            = 4,
};

enum ActionCommand {
    ACTION_COMMAND_NONE                      = 0x00000000,
    ACTION_COMMAND_JUMP                      = 0x00000001,
    ACTION_COMMAND_SMASH                     = 0x00000002,
    ACTION_COMMAND_FLEE                      = 0x00000003,
    ACTION_COMMAND_BREAK_FREE                = 0x00000004,
    ACTION_COMMAND_WHIRLWIND                 = 0x00000005,
    ACTION_COMMAND_STOP_LEECH                = 0x00000006,
    ACTION_COMMAND_07                        = 0x00000007,
    ACTION_COMMAND_DIZZY_SHELL               = 0x00000008,
    ACTION_COMMAND_FIRE_SHELL                = 0x00000009,
    ACTION_COMMAND_0A                        = 0x0000000A,
    ACTION_COMMAND_BOMB                      = 0x0000000B,
    ACTION_COMMAND_BODY_SLAM                 = 0x0000000C,
    ACTION_COMMAND_AIR_LIFT                  = 0x0000000D,
    ACTION_COMMAND_AIR_RAID                  = 0x0000000E,
    ACTION_COMMAND_SQUIRT                    = 0x0000000F,
    ACTION_COMMAND_POWER_SHOCK               = 0x00000010,
    ACTION_COMMAND_MEGA_SHOCK                = 0x00000011,
    ACTION_COMMAND_SMACK                     = 0x00000012,
    ACTION_COMMAND_SPINY_SURGE               = 0x00000013,
    ACTION_COMMAND_HURRICANE                 = 0x00000014,
    ACTION_COMMAND_SPOOK                     = 0x00000015,
    ACTION_COMMAND_WATER_BLOCK               = 0x00000016,
    ACTION_COMMAND_TIDAL_WAVE                = 0x00000017,
};

enum HazardType {
    HAZARD_TYPE_NONE        = 0,
    HAZARD_TYPE_LAVA        = 1,
    HAZARD_TYPE_SPIKES      = 2,
    HAZARD_TYPE_FIRE_BAR    = 3,
};

enum DamageIntensityRange {
    DAMAGE_INTENSITY_LIGHT      = 0,    // 0-3
    DAMAGE_INTENSITY_MEDIUM     = 1,    // 4-6
    DAMAGE_INTENSITY_HEAVY      = 2,    // 7-9
    DAMAGE_INTENSITY_EXTREME    = 3,    // 10+
    DAMAGE_INTENSITY_UNUSED     = 4,    // unused
};

enum EffectInstanceFlags {
    FX_INSTANCE_FLAG_ENABLED            = 0x00000001,
    FX_INSTANCE_FLAG_BATTLE             = 0x00000004, // effect was created during battle
    FX_INSTANCE_FLAG_HAS_UPDATED        = 0x00000008, // has run update at least once
    FX_INSTANCE_FLAG_DISMISS            = 0x00000010, // effect should perform cleanup and self-delete
};

enum EffectGfxDataFlags {
    FX_GRAPHICS_DISABLED                = 0x00000000,
    FX_GRAPHICS_LOADED                  = 0x00000001,
    FX_GRAPHICS_CAN_FREE                = 0x00000002,
};

#include "move_enum.h"

enum DemoState {
    DEMO_STATE_NONE         = 0,
    DEMO_STATE_ACTIVE       = 1,
    DEMO_STATE_CHANGE_MAP   = 2,
    DEMO_STATE_4            = 4,
    DEMO_STATE_DONE         = 5,
};

enum DemoFlags {
    DEMO_BTL_FLAG_ENABLED           = 0x01,
    DEMO_BTL_FLAG_PARTNER_ACTING    = 0x02,
    DEMO_BTL_FLAG_ENEMY_ACTING      = 0x04,
    DEMO_BTL_FLAG_10                = 0x10,
    DEMO_BTL_FLAG_20                = 0x20,
    DEMO_BTL_FLAG_40                = 0x40,
};

enum IntroParts {
    INTRO_PART_0            = 0,
    INTRO_PART_1            = 1,
    INTRO_PART_5            = 5,
    INTRO_PART_100          = 100,
    INTRO_PART_NONE         = -1,
};

enum MapLoadType {
    LOAD_FROM_MAP           = 0,
    LOAD_FROM_FILE_SELECT   = 1,
};

enum BattleStatusFlags1 {
    BS_FLAGS1_ACTORS_VISIBLE                = 0x00000001,
    BS_FLAGS1_MENU_OPEN                     = 0x00000002,
    BS_FLAGS1_TATTLE_OPEN                   = 0x00000004,
    BS_FLAGS1_SHOW_PLAYER_DECORATIONS       = 0x00000008, // enables effects for Frozen, Water Block, and Cloud Nine to appear and follow the player
    // Enables attack bonuses like Power Plus and Merlee ATK boost.
    // Almost always used with TestTarget functions when not called with DAMAGE_TYPE_TRIGGER_LUCKY.
    BS_FLAGS1_INCLUDE_POWER_UPS             = 0x00000010,
    // Current hit may trigger special events on the target (other than hit/death/immune)
    // These include FLIP_TRIGGER, FALL_TRIGGER, BURN_HIT, SPIN_SMASH_HIT, etc.
    // This has no bearing on contact hazard events which affect the attacker like SPIKE_CONTACT or BURN_CONTACT.
    BS_FLAGS1_TRIGGER_EVENTS                = 0x00000020,
    BS_FLAGS1_NICE_HIT                      = 0x00000040,
    BS_FLAGS1_NO_RATING                     = 0x00000080, // prevents 'Nice!' or 'Super!' messages from appearing
    BS_FLAGS1_EXECUTING_MOVE                = 0x00000100,
    BS_FLAGS1_SUPER_HIT                     = 0x00000200, // only works for partners and items, NOT player hits
    BS_FLAGS1_FORCE_IMMUNE_HIT              = 0x00000800,
    BS_FLAGS1_AUTO_SUCCEED_ACTION           = 0x00001000,
    BS_FLAGS1_2000                          = 0x00002000,
    BS_FLAGS1_4000                          = 0x00004000,
    BS_FLAGS1_FREE_ACTION_COMMAND           = 0x00008000,
    BS_FLAGS1_10000                         = 0x00010000,
    BS_FLAGS1_DISABLE_CELEBRATION           = 0x00020000,
    BS_FLAGS1_BATTLE_FLED                   = 0x00040000, // used both when the player flees sucessfully or an enemy flees
    BS_FLAGS1_PARTNER_ACTING                = 0x00080000,
    BS_FLAGS1_PLAYER_IN_BACK                = 0x00100000,
    BS_FLAGS1_YIELD_TURN                    = 0x00200000, // moves end either when their script is finished or this flag is set by calling YieldTurn
    BS_FLAGS1_PLAYER_DEFENDING              = 0x00400000,
    BS_FLAGS1_NO_GAME_OVER                  = 0x00800000, // don’t game over on loss
    BS_FLAGS1_STAR_POINTS_DROPPED           = 0x01000000,
    BS_FLAGS1_TUTORIAL_BATTLE               = 0x02000000, // prevent player from swapping to/from partner
    BS_FLAGS1_HUSTLED                       = 0x04000000,
    BS_FLAGS1_SORT_ENEMIES_BY_POSX          = 0x08000000, // enemy turn order ignores priority; sorts bases on x position instead
    BS_FLAGS1_HAMMER_CHARGED                = 0x10000000,
    BS_FLAGS1_JUMP_CHARGED                  = 0x20000000,
    BS_FLAGS1_GOOMBARIO_CHARGED             = 0x40000000,
    BS_FLAGS1_ATK_BLOCKED                   = 0x80000000,
};

enum BattleStatusFlags2 {
    BS_FLAGS2_AWARDING_STAR_POINTS          = 0x00000001, // star points move to the center of the screen
    BS_FLAGS2_PLAYER_TURN_USED              = 0x00000002, // set after player has used their action for this turn
    BS_FLAGS2_PARTNER_TURN_USED             = 0x00000004, // set after partner has used their action for this turn
    BS_FLAGS2_OVERRIDE_INACTIVE_PLAYER      = 0x00000008, // override inactive player animations and effects
    BS_FLAGS2_OVERRIDE_INACTIVE_PARTNER     = 0x00000010, // override inactive partner animations and effects
    BS_FLAGS2_CANT_FLEE                     = 0x00000020,
    BS_FLAGS2_PEACH_BATTLE                  = 0x00000040,
    BS_FLAGS2_STORED_TURBO_CHARGE_TURN      = 0x00000100, // prevents turbo charge turns from decrementing on begin player turn
    BS_FLAGS2_DOING_JUMP_TUTORIAL           = 0x00000200,
    BS_FLAGS2_FINAL_BOWSER_PART_1           = 0x00000400, // no other use for this flag, purpose unknown
    BS_FLAGS2_NO_TARGET_AVAILABLE           = 0x00001000,
    BS_FLAGS2_IGNORE_DARKNESS               = 0x00004000,
    BS_FLAGS2_HIDE_BUFF_COUNTERS            = 0x00010000, // hide turn counters for partner buffs (Cloud Nine, Water Block, etc)
    BS_FLAGS2_NO_PLAYER_PAL_ADJUST          = 0x00100000,
    BS_FLAGS2_IS_FIRST_STRIKE               = 0x01000000,
    BS_FLAGS2_DONT_STOP_MUSIC               = 0x02000000, // don't stop playing the current song when the battle ends
    BS_FLAGS2_HAS_DRAINED_HP                = 0x04000000,
    BS_FLAGS2_HAS_RUSH                      = 0x08000000,
    BS_FLAGS2_DROP_WHACKA_BUMP              = 0x10000000,
};

enum BattleStatusReflectionFlags {
    BS_REFLECT_FLOOR    = 1,
};

enum BattleStates {
    BATTLE_STATE_NEGATIVE_1                 = -1,
    BATTLE_STATE_0                          = 0,
    BATTLE_STATE_NORMAL_START               = 1,
    BATTLE_STATE_FIRST_STRIKE               = 2,
    BATTLE_STATE_PARTNER_FIRST_STRIKE       = 3,
    BATTLE_STATE_ENEMY_FIRST_STRIKE         = 4,
    BATTLE_STATE_BEGIN_TURN                 = 5,
    BATTLE_STATE_END_TURN                   = 6,
    BATTLE_STATE_BEGIN_PLAYER_TURN          = 7,
    BATTLE_STATE_BEGIN_PARTNER_TURN         = 8,
    BATTLE_STATE_9                          = 9,    // can be reached from BATTLE_STATE_PARTNER_MOVE if partner == NULL
    BATTLE_STATE_SWITCH_TO_PLAYER           = 10,
    BATTLE_STATE_SWITCH_TO_PARTNER          = 11,
    BATTLE_STATE_PREPARE_MENU               = 12,
    BATTLE_STATE_PLAYER_MENU                = 13,
    BATTLE_STATE_PARTNER_MENU               = 14,
    BATTLE_STATE_PEACH_MENU                 = 15,
    BATTLE_STATE_TWINK_MENU                 = 16,
    BATTLE_STATE_SELECT_TARGET              = 17,
    BATTLE_STATE_PLAYER_MOVE                = 18,
    BATTLE_STATE_PARTNER_MOVE               = 19,
    BATTLE_STATE_NEXT_ENEMY                 = 20,
    BATTLE_STATE_ENEMY_MOVE                 = 21,
    BATTLE_STATE_END_PLAYER_TURN            = 22,
    BATTLE_STATE_END_PARTNER_TURN           = 23,
    BATTLE_STATE_RUN_AWAY                   = 24,
    BATTLE_STATE_DEFEND                     = 25,
    BATTLE_STATE_VICTORY                    = 26,
    BATTLE_STATE_DEFEAT                     = 27,
    BATTLE_STATE_28                         = 28,
    BATTLE_STATE_CHANGE_PARTNER             = 29,
    BATTLE_STATE_END_TRAINING_BATTLE        = 30,
    BATTLE_STATE_31                         = 31,
    BATTLE_STATE_END_BATTLE                 = 32,
    BATTLE_STATE_CELEBRATION                = 33,
    BATTLE_STATE_34                         = 34,
    BATTLE_STATE_END_DEMO_BATTLE            = 35,
};

enum BattleSubStates {
    // shared
    BTL_SUBSTATE_INIT                                       = 0,

    // BATTLE_STATE_NORMAL_START
    BTL_SUBSTATE_NORMAL_START_INIT                          = 0, // loads assets, initializes state, and runs OnBattleInit script
    BTL_SUBSTATE_NORMAL_START_CREATE_ENEMIES                = 1,
    BTL_SUBSTATE_NORMAL_START_CHECK_FIRST_STRIKE            = 4, // wait for actor scripts to finish
    BTL_SUBSTATE_NORMAL_START_FADE_IN                       = 7,
    BTL_SUBSTATE_NORMAL_START_DONE                          = 8,

    // BATTLE_STATE_FIRST_STRIKE
    BTL_SUBSTATE_FIRST_STRIKE_INIT                          = 0,
    BTL_SUBSTATE_FIRST_STRIKE_AWAIT_ENEMY_READY             = 1,
    BTL_SUBSTATE_FIRST_STRIKE_AWAIT_SCRIPTS                 = 2,
    BTL_SUBSTATE_FIRST_STRIKE_AWAIT_ENEMY_DONE              = 3,

    // BATTLE_STATE_PARTNER_FIRST_STRIKE
    BTL_SUBSTATE_PARTNER_FIRST_STRIKE_INIT                  = 0,
    BTL_SUBSTATE_PARTNER_FIRST_STRIKE_AWAIT_ENEMY_READY     = 1,
    BTL_SUBSTATE_PARTNER_FIRST_STRIKE_AWAIT_SCRIPTS         = 2,
    BTL_SUBSTATE_PARTNER_FIRST_STRIKE_AWAIT_ENEMY_DONE      = 3,

    // BATTLE_STATE_ENEMY_FIRST_STRIKE
    BTL_SUBSTATE_ENEMY_FIRST_STRIKE_INIT                    = 0,
    BTL_SUBSTATE_ENEMY_FIRST_STRIKE_AWAIT_SCRIPTS           = 2,

    // BATTLE_STATE_BEGIN_TURN
    BTL_SUBSTATE_BEGIN_TURN_INIT                            = 0,
    BTL_SUBSTATE_BEGIN_TURN_AWAIT_ENEMY_SCRIPTS             = 5,
    BTL_SUBSTATE_BEGIN_TURN_AWAIT_ENEMY_DEATH               = 10,

    // BATTLE_STATE_END_TURN
    BTL_SUBSTATE_END_TURN_INIT                              = 0,
    BTL_SUBSTATE_END_TURN_CHECK_FOR_SWAP                    = 1,
    BTL_SUBSTATE_END_TURN_AWAIT_SCRIPTS                     = 2,
    BTL_SUBSTATE_END_TURN_BEGIN_NEXT                        = 3,
    BTL_SUBSTATE_END_TURN_UNUSED_4                          = 4,
    BTL_SUBSTATE_END_TURN_PERFORM_SWAP                      = 11,
    BTL_SUBSTATE_END_TURN_START_SCRIPTS                     = 12,

    // BATTLE_STATE_BEGIN_PLAYER_TURN
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_INIT                     = 0,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_TRY_COMMAND_RECOVER      = 1,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_AWAIT_WATER_BLOCK        = 2,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_CHECK_WATER_BLOCK        = 10,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_CHECK_CLOUD_NINE         = 11,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_AWAIT_CLOUD_NINE         = 12,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_CHECK_TURBO_CHARGE       = 15,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_AWAIT_TURBO_CHARGE       = 16,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_AWAIT_OUTTA_SIGHT        = 20,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_TRY_STATUS_DAMAGE        = 21,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_TRY_STATUS_RECOVER       = 22,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_END_DELAY                = 30,
    BTL_SUBSTATE_BEGIN_PLAYER_TURN_RESET_STATE              = 100,

    // BATTLE_STATE_BEGIN_PARTNER_TURN
    BTL_SUBSTATE_BEGIN_PARTNER_TURN_INIT                    = 0,
    BTL_SUBSTATE_BEGIN_PARTNER_TURN_AWAIT_RECOVER_DONE      = 1,
    BTL_SUBSTATE_BEGIN_PARTNER_TURN_EXEC_TURN_SCRIPT        = 8,
    BTL_SUBSTATE_BEGIN_PARTNER_TURN_AWAIT_TURN_SCRIPT       = 9,
    BTL_SUBSTATE_BEGIN_PARTNER_TURN_END_DELAY               = 10,
    BTL_SUBSTATE_BEGIN_PARTNER_TURN_RESET_STATE             = 100,

    // BATTLE_STATE_9
    BTL_SUBSTATE_9_INIT                                     = 0,
    BTL_SUBSTATE_9_1                                        = 1,
    BTL_SUBSTATE_9_2                                        = 2,
    BTL_SUBSTATE_9_3                                        = 3,
    BTL_SUBSTATE_9_4                                        = 4,
    BTL_SUBSTATE_9_5                                        = 5,
    BTL_SUBSTATE_9_6                                        = 6,
    BTL_SUBSTATE_9_7                                        = 7,

    // BATTLE_STATE_SWITCH_TO_PLAYER
    // BATTLE_STATE_SWITCH_TO_PARTNER

    // BATTLE_STATE_PREPARE_MENU
    BATTLE_SUBSTATE_PREPARE_MENU_DIPPING                    = 70,

    // BATTLE_STATE_PLAYER_MENU
    // BATTLE_STATE_PARTNER_MENU

    // BATTLE_STATE_PEACH_MENU
    BTL_SUBSTATE_PEACH_MENU_INIT                            = 0,
    BTL_SUBSTATE_PEACH_MENU_CHOOSE_CATEGORY                 = 1,
    BTL_SUBSTATE_PEACH_MENU_CHOOSE_TARGET                   = 2,
    BTL_SUBSTATE_PEACH_MENU_UNUSED_3                        = 3,
    BTL_SUBSTATE_PEACH_MENU_TARGET_CANCEL                   = 4,
    BTL_SUBSTATE_PEACH_MENU_TARGET_CHOSEN                   = 5,
    BTL_SUBSTATE_PEACH_MENU_UNUSED_6                        = 6,
    BTL_SUBSTATE_PEACH_MENU_UNUSED_7                        = 7,
    BTL_SUBSTATE_PEACH_MENU_SHOW_CANT_SWITCH                = 8,
    BTL_SUBSTATE_PEACH_MENU_AWAIT_CANT_SWITCH_POPUP         = 9,
    BTL_SUBSTATE_PEACH_MENU_PERFORM_SWAP                    = 10,
    BTL_SUBSTATE_PEACH_CREATE_MAIN_MENU                     = 11,

    // BATTLE_STATE_TWINK_MENU
    BTL_SUBSTATE_TWINK_MENU_INIT                            = 0,
    BTL_SUBSTATE_TWINK_MENU_CHOOSE_CATEGORY                 = 1,
    BTL_SUBSTATE_TWINK_MENU_CHOOSE_TARGET                   = 2,
    BTL_SUBSTATE_TWINK_MENU_UNUSED_3                        = 3,
    BTL_SUBSTATE_TWINK_MENU_TARGET_CANCEL                   = 4,
    BTL_SUBSTATE_TWINK_MENU_TARGET_CHOSEN                   = 5,
    BTL_SUBSTATE_TWINK_MENU_UNUSED_6                        = 6,
    BTL_SUBSTATE_TWINK_MENU_UNUSED_7                        = 7,
    BTL_SUBSTATE_TWINK_MENU_SHOW_CANT_SWITCH                = 8,
    BTL_SUBSTATE_TWINK_MENU_AWAIT_CANT_SWITCH_POPUP         = 9,
    BTL_SUBSTATE_TWINK_MENU_PERFORM_SWAP                    = 10,
    BTL_SUBSTATE_TWINK_MENU_CREATE_MAIN_MENU                = 11,

    // BATTLE_STATE_SELECT_TARGET
    BTL_SUBSTATE_SELECT_TARGET_INIT                         = 0,
    BTL_SUBSTATE_SELECT_TARGET_CHOOSE                       = 1,
    BTL_SUBSTATE_SELECT_TARGET_DONE                         = 2,
    BTL_SUBSTATE_SELECT_TARGET_CANCEL                       = 10,

    // BATTLE_STATE_PLAYER_MOVE
    BTL_SUBSTATE_PLAYER_MOVE_INIT                           = 0,
    BTL_SUBSTATE_PLAYER_MOVE_BEGIN_SHOW_TIP                 = 1,
    BTL_SUBSTATE_PLAYER_MOVE_SHOW_TIP_DELAY                 = 2,
    BTL_SUBSTATE_PLAYER_MOVE_EXECUTE_MOVE                   = 3,
    BTL_SUBSTATE_PLAYER_MOVE_HANDLE_RESULTS                 = 4,
    BTL_SUBSTATE_PLAYER_MOVE_AWAIT_ENEMY_STATUS_POPUP       = 11,
    BTL_SUBSTATE_PLAYER_MOVE_POST_ENEMY_STATUS_POPUP        = 12,
    BTL_SUBSTATE_PLAYER_MOVE_CHECK_PLAYER_STATUS            = 20,
    BTL_SUBSTATE_PLAYER_MOVE_AWAIT_PLAYER_STATUS_POPUP      = 21,
    BTL_SUBSTATE_PLAYER_MOVE_POST_PLAYER_STATUS_POPUP       = 22,
    BTL_SUBSTATE_PLAYER_MOVE_AWAIT_DONE                     = 30,

    // BATTLE_STATE_PARTNER_MOVE
    BTL_SUBSTATE_PARTNER_MOVE_INIT                          = 0,
    BTL_SUBSTATE_PARTNER_MOVE_EXECUTE_MOVE                  = 2,
    BTL_SUBSTATE_PARTNER_MOVE_HANDLE_RESULTS                = 3,
    BTL_SUBSTATE_PARTNER_MOVE_AWAIT_PARTNER_STATUS_POPUP    = 11,
    BTL_SUBSTATE_PARTNER_MOVE_POST_PARTNER_STATUS_POPUP     = 12,
    BTL_SUBSTATE_PARTNER_MOVE_CHECK_ENEMY_STATUS            = 20,
    BTL_SUBSTATE_PARTNER_MOVE_AWAIT_ENEMY_STATUS_POPUP      = 21,
    BTL_SUBSTATE_PARTNER_MOVE_POST_ENEMY_STATUS_POPUP       = 22,
    BTL_SUBSTATE_PARTNER_MOVE_DONE                          = 30,

    // BATTLE_STATE_NEXT_ENEMY
    BTL_SUBSTATE_NEXT_ENEMY_INIT                            = 0,
    BTL_SUBSTATE_NEXT_ENEMY_UNUSED_1                        = 1,
    BTL_SUBSTATE_NEXT_ENEMY_DONE                            = 2, // enemy has been found

    // BATTLE_STATE_ENEMY_MOVE
    BTL_SUBSTATE_ENEMY_MOVE_EXECUTE                         = 0,
    BTL_SUBSTATE_ENEMY_MOVE_UNUSED_1                        = 1,
    BTL_SUBSTATE_ENEMY_MOVE_AWAIT_SCRIPTS                   = 2,
    BTL_SUBSTATE_ENEMY_MOVE_AWAIT_PLAYER_POPUP_DONE         = 11, // wait for popups regarding player status to finish
    BTL_SUBSTATE_ENEMY_MOVE_POST_PLAYER_POPUP_DELAY         = 12, // a brief delay after the popup vanishes
    BTL_SUBSTATE_ENEMY_MOVE_CHECK_PARTNER                   = 20,
    BTL_SUBSTATE_ENEMY_MOVE_AWAIT_PARTNER_POPUP_DONE        = 21, // wait for popups regarding partner status to finish
    BTL_SUBSTATE_ENEMY_MOVE_POST_PARTNER_POPUP_DELAY        = 22, // a brief delay after the popup vanishes
    BTL_SUBSTATE_ENEMY_MOVE_DONE                            = 30,

    // BATTLE_STATE_END_PLAYER_TURN
    BTL_SUBSTATE_END_PLAYER_TURN_CHECK_HAPPY                = 0,
    BTL_SUBSTATE_END_PLAYER_TURN_AWAIT_HAPPY                = 5,
    BTL_SUBSTATE_END_PLAYER_TURN_AWAIT_SWAP                 = 6,
    BTL_SUBSTATE_END_PLAYER_TURN_DONE                       = 10,

    // BATTLE_STATE_END_PARTNER_TURN

    // BATTLE_STATE_RUN_AWAY
    BTL_SUBSTATE_RUN_AWAY_EXEC_SCRIPT                       = 0,
    BTL_SUBSTATE_RUN_AWAY_AWAIT_SCRIPT                      = 2,
    BTL_SUBSTATE_RUN_AWAY_EXEC_POST_FAILURE                 = 3,
    BTL_SUBSTATE_RUN_AWAY_AWAIT_POST_FAILURE                = 4,
    BTL_SUBSTATE_RUN_AWAY_GIVE_STAR_POINTS                  = 10,
    BTL_SUBSTATE_RUN_AWAY_DONE                              = 11,

    // BATTLE_STATE_DEFEND
    BTL_SUBSTATE_DEFEND_INIT                                = 0,
    BTL_SUBSTATE_DEFEND_AWAIT_SCRIPT                        = 1,

    // BATTLE_STATE_VICTORY
    BTL_SUBSTATE_VICTORY_CHECK_OUTTA_SIGHT                  = 0,
    BTL_SUBSTATE_VICTORY_AWAIT_OUTTA_SIGHT                  = 1,
    BTL_SUBSTATE_VICTORY_CHECK_MERLEE                       = 2,
    BTL_SUBSTATE_VICTORY_AWAIT_MERLEE                       = 3,
    BTL_SUBSTATE_VICTORY_DONE                               = 4,
    BTL_SUBSTATE_VICTORY_RECOVER_STATUS                     = 5,
    BTL_SUBSTATE_VICTORY_AWAIT_RECOVER_KO                   = 10,
    BTL_SUBSTATE_VICTORY_CHECK_SWAP                         = 11,
    BTL_SUBSTATE_VICTORY_AWAIT_SWAP                         = 12,

    // BATTLE_STATE_DEFEAT
    BTL_SUBSTATE_DEFEAT_INIT                                = 0,
    BTL_SUBSTATE_DEFEAT_CHECK_LIFE_SHROOM                   = 1,
    BTL_SUBSTATE_DEFEAT_AWAIT_LIFE_SHROOM                   = 2,
    BTL_SUBSTATE_DEFEAT_DONE                                = 10,

    // BATTLE_STATE_28

    // BATTLE_STATE_CHANGE_PARTNER
    BTL_SUBSTATE_CHANGE_PARTNER_INIT                        = 0,
    BTL_SUBSTATE_CHANGE_PARTNER_EXEC_PUT_AWAY               = 2,
    BTL_SUBSTATE_CHANGE_PARTNER_LOAD_NEW_PARTNER            = 3,
    BTL_SUBSTATE_CHANGE_PARTNER_EXEC_BRING_OUT              = 4,
    BTL_SUBSTATE_CHANGE_PARTNER_EXEC_PHASE                  = 5,
    BTL_SUBSTATE_CHANGE_PARTNER_AWAIT_PHASE                 = 6,
    BTL_SUBSTATE_CHANGE_PARTNER_DONE                        = 7,

    // BATTLE_STATE_END_TRAINING_BATTLE
    BTL_SUBSTATE_END_TRAINING_INIT                          = 0,
    BTL_SUBSTATE_END_TRAINING_AWAIT_RECOVERING              = 10,
    BTL_SUBSTATE_END_TRAINING_CHECK_OUTTA_SIGHT             = 11,
    BTL_SUBSTATE_END_TRAINING_AWAIT_OUTTA_SIGHT             = 12,
    BTL_SUBSTATE_END_TRAINING_RESET_CAM                     = 13,
    BTL_SUBSTATE_END_TRAINING_DONE                          = 14,

    // BATTLE_STATE_31

    // BATTLE_STATE_END_BATTLE
    BTL_SUBSTATE_END_BATTLE_INIT                            = 0,
    BTL_SUBSTATE_END_BATTLE_FADE_OUT                        = 1,
    BTL_SUBSTATE_END_BATTLE_EXEC_STAGE_SCRIPT               = 2,
    BTL_SUBSTATE_END_BATTLE_AWAIT_STAGE_SCRIPT              = 3,
    BTL_SUBSTATE_END_BATTLE_CLEANUP                         = 4,

    // BATTLE_STATE_CELEBRATION
    BTL_SUBSTATE_CELEBRATE_INIT                             = 0,
    BTL_SUBSTATE_CELEBRATE_LOAD_STAR_POINTS                 = 1,
    BTL_SUBSTATE_CELEBRATE_TALLY_STAR_POINTS                = 2,
    BTL_SUBSTATE_CELEBRATE_POST_STAR_POINTS                 = 3,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_LOAD                    = 4,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_BEGIN                   = 5,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CREATE_HUD              = 6,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_SHOW_HUD                = 7,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_CHOOSE                  = 8,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_UPGRADE                 = 9,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_FADE_OUT                = 10,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_DESTROY_HUD             = 11,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID                 = 15,
    BTL_SUBSTATE_CELEBRATE_LEVEL_UP_INVALID_DELAY           = 16,
    BTL_SUBSTATE_CELEBRATE_SKIPPABLE_END_DELAY              = 20,
    BTL_SUBSTATE_CELEBRATE_WALK_AWAY                        = 21,
    BTL_SUBSTATE_CELEBRATE_DONE                             = 22,

    // BATTLE_STATE_34

    // BATTLE_STATE_END_DEMO_BATTLE
    BTL_SUBSTATE_END_DEMO_BATTLE_INIT                       = 0,
    BTL_SUBSTATE_END_DEMO_BATTLE_FADE_OUT                   = 1,
    BTL_SUBSTATE_END_DEMO_BATTLE_EXEC_STAGE_SCRIPT          = 2,
    BTL_SUBSTATE_END_DEMO_BATTLE_AWAIT_STAGE_SCRIPT         = 3,
    BTL_SUBSTATE_END_DEMO_BATTLE_CLEANUP                    = 4,
};

// used with BATTLE_STATE_PLAYER_MENU
enum BattlePlayerMenuSubstates {
    BTL_SUBSTATE_PLAYER_MENU_INIT                           = 0,
    // Main menu
    BTL_SUBSTATE_PLAYER_MENU_CHOOSE_CATEGORY                = 1,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_MENU_2                    = 2,
    BTL_SUBSTATE_PLAYER_MENU_MOVE_CHOOSE_TARGET             = 3,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_MENU_4                    = 4,
    BTL_SUBSTATE_PLAYER_MENU_MOVE_TARGET_CANCEL             = 5,
    BTL_SUBSTATE_PLAYER_MENU_MOVE_TARGET_CHOSEN             = 6,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_MENU_7                    = 7,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_SHOW_CANT_SWAP            = 8,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_AWAIT_CANT_SWAP           = 9,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_MENU_10                   = 10,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_MENU_11                   = 11,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_MENU_12                   = 12,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_MENU_13                   = 13,
    BTL_SUBSTATE_PLAYER_MENU_MAIN_MENU_14                   = 14,
    // Unknown
    BTL_SUBSTATE_PLAYER_MENU_UNKNOWN_1                      = 20,
    BTL_SUBSTATE_PLAYER_MENU_DIPPING_CHOOSE_TARGET          = 21,
    BTL_SUBSTATE_PLAYER_MENU_UNKNOWN_3                      = 22,
    BTL_SUBSTATE_PLAYER_MENU_UNKNOWN_4                      = 23,
    BTL_SUBSTATE_PLAYER_MENU_DIPPING_TARGET_CANCEL          = 24,
    BTL_SUBSTATE_PLAYER_MENU_DIPPING_TARGET_CHOSEN          = 25,
    // Change Member
    BTL_SUBSTATE_PLAYER_MENU_CHANGE_MEMBER_1                = 30,
    BTL_SUBSTATE_PLAYER_MENU_CHANGE_MEMBER_2                = 31,
    BTL_SUBSTATE_PLAYER_MENU_CHANGE_MEMBER_3                = 32,
    BTL_SUBSTATE_PLAYER_MENU_CHANGE_MEMBER_4                = 33,
    BTL_SUBSTATE_PLAYER_MENU_CHANGE_MEMBER_5                = 34,
    BTL_SUBSTATE_PLAYER_MENU_CHANGE_MEMBER_6                = 35,
    BTL_SUBSTATE_PLAYER_MENU_CHANGE_MEMBER_7                = 36,
    // Items
    BTL_SUBSTATE_PLAYER_MENU_ITEMS_1                        = 40,
    BTL_SUBSTATE_PLAYER_MENU_ITEMS_2                        = 41,
    BTL_SUBSTATE_PLAYER_MENU_ITEMS_3                        = 42,
    BTL_SUBSTATE_PLAYER_MENU_ITEMS_4                        = 43,
    BTL_SUBSTATE_PLAYER_MENU_ITEMS_5                        = 44,
    BTL_SUBSTATE_PLAYER_MENU_ITEMS_6                        = 45,
    // Star Spirits
    BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_1                 = 60,
    BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_2                 = 61,
    BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_3                 = 62,
    BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_4                 = 63,
    BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_5                 = 64,
    BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_6                 = 65,
    BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_7                 = 66,
    // additional item use from Double/Triple dip
    BTL_SUBSTATE_PLAYER_MENU_DIPPING_1                      = 70,
    BTL_SUBSTATE_PLAYER_MENU_DIPPING_2                      = 71,
    BTL_SUBSTATE_PLAYER_MENU_DIPPING_3                      = 72,
    BTL_SUBSTATE_PLAYER_MENU_DIPPING_4                      = 73,
    BTL_SUBSTATE_PLAYER_MENU_DIPPING_5                      = 74,
    BTL_SUBSTATE_PLAYER_MENU_DIPPING_6                      = 75,
    // Berserker
    BTL_SUBSTATE_PLAYER_MENU_BERSERKER_CHOOSE               = 100,
    // Strategies
    BTL_SUBSTATE_PLAYER_MENU_BUILD_STRATEGIES               = 200,
    BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_2                   = 201,
    BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_3                   = 202,
    BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_4                   = 203,
    BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_5                   = 204,
    BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_6                   = 205,
    BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_8                   = 207,
    // initialize
    BTL_SUBSTATE_PLAYER_MENU_PERFORM_SWAP                   = 300,
    BTL_SUBSTATE_PLAYER_MENU_CREATE_MAIN_MENU               = 302,
};

enum BattlePartnerMenuSubstates {
    BTL_SUBSTATE_PARTNER_MENU_NONE                            = 0,
    // Main menu
    BTL_SUBSTATE_PARTNER_MENU_MAIN_MENU_1                     = 2,
    BTL_SUBSTATE_PARTNER_MENU_MAIN_MENU_2                     = 3,
    BTL_SUBSTATE_PARTNER_MENU_MAIN_MENU_3                     = 4,
    BTL_SUBSTATE_PARTNER_MENU_MAIN_MENU_4                     = 5,
    BTL_SUBSTATE_PARTNER_MENU_MAIN_MENU_5                     = 6,
    BTL_SUBSTATE_PARTNER_MENU_MAIN_MENU_6                     = 7,
    BTL_SUBSTATE_PARTNER_MENU_MAIN_SHOW_CANT_SWAP             = 8,
    BTL_SUBSTATE_PARTNER_MENU_MAIN_AWAIT_CANT_SWAP            = 9,
    // Abilities
    BTL_SUBSTATE_PARTNER_MENU_ABILITIES_1                     = 10,
    BTL_SUBSTATE_PARTNER_MENU_ABILITIES_2                     = 11,
    BTL_SUBSTATE_PARTNER_MENU_ABILITIES_3                     = 12,
    BTL_SUBSTATE_PARTNER_MENU_ABILITIES_4                     = 13,
    BTL_SUBSTATE_PARTNER_MENU_ABILITIES_5                     = 14,
    BTL_SUBSTATE_PARTNER_MENU_ABILITIES_6                     = 15,
    BTL_SUBSTATE_PARTNER_MENU_ABILITIES_7                     = 16,
    // Unknown, referenced only in btl_state_draw_partner_menu
    BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_1                       = 20,
    BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_2                       = 21,
    BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_3                       = 22,
    BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_4                       = 23,
    BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_5                       = 24,
    // Change Partner
    BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_1                = 30,
    BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_2                = 31,
    BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_3                = 32,
    BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_4                = 33,
    BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_5                = 34,
    BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_6                = 35,
    BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_7                = 36,
    // Items
    BTL_SUBSTATE_PARTNER_MENU_ITEMS_1                         = 40,
    BTL_SUBSTATE_PARTNER_MENU_ITEMS_2                         = 41,
    BTL_SUBSTATE_PARTNER_MENU_ITEMS_3                         = 42,
    BTL_SUBSTATE_PARTNER_MENU_ITEMS_4                         = 43,
    BTL_SUBSTATE_PARTNER_MENU_ITEMS_5                         = 44,
    BTL_SUBSTATE_PARTNER_MENU_ITEMS_6                         = 45,
    // Switch partner (unused)
    BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_1         = 50,
    BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_2         = 51,
    BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_3         = 52,
    BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_4         = 53,
    BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_5         = 54,
    BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_6         = 55,
    BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_7         = 56,
    // Focus
    BTL_SUBSTATE_PARTNER_MENU_FOCUS_1                         = 60,
    BTL_SUBSTATE_PARTNER_MENU_FOCUS_2                         = 61,
    BTL_SUBSTATE_PARTNER_MENU_FOCUS_3                         = 62,
    BTL_SUBSTATE_PARTNER_MENU_FOCUS_4                         = 63,
    BTL_SUBSTATE_PARTNER_MENU_FOCUS_5                         = 64,
    BTL_SUBSTATE_PARTNER_MENU_FOCUS_6                         = 65,
    // Strategies
    BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_1                    = 200,
    BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_2                    = 201,
    BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_3                    = 202,
    BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_4                    = 203,
    BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_5                    = 204,
    BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_6                    = 205,
    // initialize
    BTL_SUBSTATE_PARTNER_MENU_12D                             = 301,
    BTL_SUBSTATE_PARTNER_MENU_INIT_MENU                       = 302,
};

enum BattleMessages {
    BTL_MSG_MERLEE_ATK_UP                           = 0x00,
    BTL_MSG_MERLEE_DEF_UP                           = 0x01,
    BTL_MSG_MERLEE_EXP_UP                           = 0x02,
    BTL_MSG_MERLEE_DONE                             = 0x03,
    BTL_MSG_CHARGE_HAMMER                           = 0x04,
    BTL_MSG_CHARGE_HAMMER_MORE                      = 0x05,
    BTL_MSG_CHARGE_JUMP                             = 0x06,
    BTL_MSG_CHARGE_JUMP_MORE                        = 0x07,
    BTL_MSG_CANT_CHARGE                             = 0x08,
    BTL_MSG_ENEMY_MISSED                            = 0x09,
    BTL_MSG_PLAYER_DAZED                            = 0x0A,
    BTL_MSG_PLAYER_ASLEEP                           = 0x0B,
    BTL_MSG_PLAYER_FROZEN                           = 0x0C,
    BTL_MSG_PLAYER_POISONED                         = 0x0D,
    BTL_MSG_PLAYER_SHRUNK                           = 0x0E,
    BTL_MSG_PLAYER_PARALYZED                        = 0x0F,
    BTL_MSG_PLAYER_CHARGED                          = 0x10,
    BTL_MSG_PLAYER_TRANSPARENT                      = 0x11,
    BTL_MSG_ENEMY_DAZED                             = 0x12,
    BTL_MSG_ENEMY_ASLEEP                            = 0x13,
    BTL_MSG_ENEMY_FROZEN                            = 0x14,
    BTL_MSG_ENEMY_POISONED                          = 0x15,
    BTL_MSG_ENEMY_SHRUNK                            = 0x16,
    BTL_MSG_ENEMY_PARALYZED                         = 0x17,
    BTL_MSG_ENEMY_ELECTRIFIED                       = 0x18,
    BTL_MSG_ENEMY_CANT_MOVE                         = 0x19,
    BTL_MSG_STAR_POWER_RECHARGED                    = 0x1A,
    BTL_MSG_STAR_POWER_MAXED                        = 0x1B,
    BTL_MSG_STAR_POWER_FILLED                       = 0x1C,
    BTL_MSG_ATTACK_UP                               = 0x1D,
    BTL_MSG_DEFENCE_UP                              = 0x1E,
    BTL_MSG_HEAL_ONE                                = 0x1F,
    BTL_MSG_HEAL_ALL                                = 0x20,
    BTL_MSG_ENEMY_TRANSPARENT                       = 0x21,
    BTL_MSG_ENEMY_CHARGED                           = 0x22,
    BTL_MSG_PARTNER_INJURED                         = 0x23,
    BTL_MSG_CHARGE_GOOMBARIO                        = 0x24,
    BTL_MSG_CHARGE_GOOMBARIO_MORE                   = 0x25,
    BTL_MSG_WATER_BLOCK_BEGIN                       = 0x26,
    BTL_MSG_WATER_BLOCK_END                         = 0x27,
    BTL_MSG_CLOUD_NINE_BEGIN                        = 0x28,
    BTL_MSG_CLOUD_NINE_END                          = 0x29,
    BTL_MSG_TURBO_CHARGE_BEGIN                      = 0x2A,
    BTL_MSG_TURBO_CHARGE_END                        = 0x2B,
    BTL_MSG_CHILL_OUT_BEGIN                         = 0x2C,
    BTL_MSG_UNUSED_CLOUD_NINE                       = 0x2D,
    BTL_MSG_FIRST_ACTION_TIP                        = 0x2E,
    BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING         = 0x2E, // jump moves, Sky Dive
    BTL_MSG_ACTION_TIP_HOLD_LEFT_TIMED              = 0x2F, // hammer moves, Belly Flop, Shell Toss
    BTL_MSG_ACTION_TIP_PRESS_BEFORE_STRIKE          = 0x30, // Headbonk and Multibonk
    BTL_MSG_ACTION_TIP_MASH_BUTTON                  = 0x31, // Dizzy Shell, Power Shock, Air Lift, Bombette's moves
    BTL_MSG_ACTION_TIP_MASH_LEFT                    = 0x32, // Fire Shell, Air Raid, Spiny Surge, Bow's moves
    BTL_MSG_ACTION_TIP_HOLD_LEFT_AIM                = 0x33, // Shell Shot
    BTL_MSG_ACTION_TIP_UNUSED_1                     = 0x34, // unused
    BTL_MSG_ACTION_TIP_UNUSED_2                     = 0x35, // unused
    BTL_MSG_ACTION_TIP_PRESS_BUTTONS_SHOWN          = 0x36, // Tidal Wave
    BTL_MSG_ACTION_TIP_NOT_USED_1                   = 0x37, // unused, special message
    BTL_MSG_ACTION_TIP_PRESS_WITH_TIMING            = 0x38, // Turbo Charge, Water Block, Cloud Nine
    BTL_MSG_ACTION_TIP_NOT_USED_2                   = 0x39, // unused, special message
    BTL_MSG_ACTION_TIP_MASH_BOTH                    = 0x3A, // Mega Shock and Hurricane
    BTL_MSG_ACTION_TIP_UNUSED_3                     = 0x3B, // unused
    BTL_MSG_ACTION_TIP_HOLD_THEN_TAP                = 0x3C, // Squirt
    BTL_MSG_ACTION_TIP_HOLD_THEN_RELEASE            = 0x3D, // Body Slam and Electro Dash
    BTL_MSG_ACTION_TIP_MOVE_TO_AIM                  = 0x3E, // Spiny Flip
    BTL_MSG_ACTION_TIP_UNUSED_4                     = 0x3F, // unused
    BTL_MSG_ACTION_TIP_BREAK_FREE                   = 0x40, // unused
    BTL_MSG_ACTION_TIP_REDUCE_DAMAGE                = 0x41, // unused
    BTL_MSG_ACTION_TIP_NOT_USED_3                   = 0x42, // Earthquake Jump
    BTL_MSG_LAST_ACTION_TIP                         = 0x42,
    BTL_MSG_NO_JUMP_TARGET                          = 0x43,
    BTL_MSG_NO_HAMMER_TARGET                        = 0x44,
    BTL_MSG_NO_ITEM_TARGET                          = 0x45,
    BTL_MSG_46                                      = 0x46,
    BTL_MSG_47                                      = 0x47,
    BTL_MSG_CANT_SELECT_NOW                         = 0x48,
    BTL_MSG_HAMMER_DISABLED_1                       = 0x49,
    BTL_MSG_HAMMER_DISABLED_2                       = 0x4A,
    BTL_MSG_HAMMER_DISABLED_3                       = 0x4B,
    BTL_MSG_JUMP_DISABLED_1                         = 0x4C,
    BTL_MSG_JUMP_DISABLED_2                         = 0x4D,
    BTL_MSG_JUMP_DISABLED_3                         = 0x4E,
    BTL_MSG_ITEMS_DISABLED                          = 0x4F,
    BTL_MSG_CANT_SWITCH                             = 0x50,
    BTL_MSG_CANT_MOVE                               = 0x51,
    BTL_MSG_CANT_SWITCH_UNUSED                      = 0x52,
    BTL_MSG_CANT_MOVE_UNUSED                        = 0x53,
    BTL_MSG_CANT_SELECT_NOW_ALT                     = 0x54,
};

// states after INIT are different for each type of battle message
enum BattleMessageStates {
    // generic INIT state shared by all message types
    BTL_MSG_STATE_INIT                  = 0,
    // states for popup messages like BTL_MSG_MERLEE_ATK_UP or BTL_MSG_ENEMY_ASLEEP
    BTL_MSG_STATE_POPUP_PRE_DELAY       = 1,
    BTL_MSG_STATE_POPUP_DELAY           = 2,
    BTL_MSG_STATE_POPUP_POST_DELAY      = 3,
    BTL_MSG_STATE_POPUP_DISPOSE         = 4,
    // states for action tip messages
    BTL_MSG_STATE_ACTION_TIP_DELAY      = 1,
    BTL_MSG_STATE_ACTION_TIP_DISPOSE    = 2,
    // states for error messages like BTL_MSG_NO_JUMP_TARGET or BTL_MSG_CANT_SELECT_NOW
    BTL_MSG_STATE_ERROR_PRE_DELAY       = 1,
    BTL_MSG_STATE_ERROR_DELAY           = 2,
    BTL_MSG_STATE_ERROR_POST_DELAY      = 3,
    BTL_MSG_STATE_ERROR_DISPOSE         = 4,
    // states for command disable notifications like BTL_MSG_ITEMS_DISABLED
    BTL_MSG_STATE_DISABLED_DELAY        = 1,
};

// BattleMenuState
enum BattleMenuStates {
    BTL_MENU_STATE_OPENED_SUBMENU       = -1,
    BTL_MENU_STATE_CREATE               = 0,
    BTL_MENU_STATE_UNK_1                = 1,
    BTL_MENU_STATE_ACCEPT_INPUT         = 2,
    BTL_MENU_STATE_UNK_A                = 10,
    BTL_MENU_STATE_UNK_B                = 11,
    BTL_MENU_STATE_UNK_14               = 20,
    BTL_MENU_STATE_UNK_1E               = 30,
    BTL_MENU_STATE_SHOW_DISABLED_POPUP  = 100,
    BTL_MENU_STATE_AWAIT_DISABLED_POPUP = 101,
};

enum BattleMoveSubmenuStates {
    BTL_SUBMENU_MOVES_STATE_UNK_NEGATIVE_TWO     = -2, // go back
    BTL_SUBMENU_MOVES_STATE_UNK_NEGATIVE_ONE     = -1,
    BTL_SUBMENU_MOVES_STATE_UNK_0                = 0,
    BTL_SUBMENU_MOVES_STATE_UNK_1                = 1,
    BTL_SUBMENU_MOVES_STATE_UNK_A                = 10,
    BTL_SUBMENU_MOVES_STATE_UNK_B                = 11,
    BTL_SUBMENU_MOVES_STATE_UNK_14               = 20,
    BTL_SUBMENU_MOVES_STATE_UNK_1E               = 30,
    BTL_SUBMENU_MOVES_STATE_UNK_28               = 40,
    BTL_SUBMENU_MOVES_STATE_UNK_29               = 41,
    BTL_SUBMENU_MOVES_STATE_UNK_2A               = 42,
};


enum BattleStratsSubmenuStates {
    BTL_SUBMENU_STRATS_STATE_CANCEL               = -2, // go back
    BTL_SUBMENU_STRATS_STATE_SELECT               = -1, // approve choice
    BTL_SUBMENU_STRATS_STATE_INIT                 = 0,
    BTL_SUBMENU_STRATS_STATE_CHOOSE               = 1,
    BTL_SUBMENU_STRATS_STATE_UNK_10               = 10,
    BTL_SUBMENU_STRATS_STATE_UNK_11               = 11,
    BTL_SUBMENU_STRATS_STATE_UNK_20               = 20,
    BTL_SUBMENU_STRATS_STATE_UNK_30               = 30,
    BTL_SUBMENU_STRATS_STATE_ERROR_INIT           = 40,
    BTL_SUBMENU_STRATS_STATE_ERROR_SHOW           = 41,
    BTL_SUBMENU_STRATS_STATE_ERROR_DONE           = 42,
};

enum BattleMenuIndex {
    BTL_MENU_IDX_MAIN               = 0,
    BTL_MENU_IDX_JUMP               = 1,
    BTL_MENU_IDX_SMASH              = 2,
    BTL_MENU_IDX_ITEMS              = 3,
    BTL_MENU_IDX_DIP                = 4,
    BTL_MENU_IDX_PARTNER            = 5,
    BTL_MENU_IDX_STAR_POWER         = 6,
    BTL_MENU_IDX_STRATEGY           = 7,
    // partners only
    BTL_MENU_IDX_ABILITY            = 1,
    BTL_MENU_IDX_PARTNER_ITEM       = 4,
};

enum BattleMenuTypes {
    BTL_MENU_TYPE_INVALID           = -1,
    BTL_MENU_TYPE_JUMP              = 0,
    BTL_MENU_TYPE_SMASH             = 1,
    BTL_MENU_TYPE_ITEMS             = 2,
    BTL_MENU_TYPE_RUN_AWAY          = 3,
    BTL_MENU_TYPE_DEFEND            = 4,
    BTL_MENU_TYPE_CHANGE_PARTNER    = 5,
    BTL_MENU_TYPE_ABILITY           = 6,
    BTL_MENU_TYPE_STRATEGIES        = 7,
    BTL_MENU_TYPE_STAR_POWERS       = 8,
    BTL_MENU_TYPE_DO_NOTHING        = 9,
    BTL_MENU_TYPE_ACT_LATER         = 10,
    BTL_MENU_TYPE_PARTNER_FOCUS     = 11,
};

enum BattleMenuDisableFlags {
    BTL_MENU_ENABLED_JUMP           = 1 << BTL_MENU_TYPE_JUMP,
    BTL_MENU_ENABLED_SMASH          = 1 << BTL_MENU_TYPE_SMASH,
    BTL_MENU_ENABLED_ITEMS          = 1 << BTL_MENU_TYPE_ITEMS,
    BTL_MENU_ENABLED_ABILITIES      = 1 << BTL_MENU_TYPE_ABILITY,
    BTL_MENU_ENABLED_STRATEGIES     = 1 << BTL_MENU_TYPE_STRATEGIES,
    BTL_MENU_ENABLED_STAR_POWERS    = 1 << BTL_MENU_TYPE_STAR_POWERS,
    BTL_MENU_ENABLED_PARTNER_FOCUS  = 1 << BTL_MENU_TYPE_PARTNER_FOCUS,
};

enum BattleRumbleModes {
    BTL_RUMBLE_STOP                 = 0,
    BTL_RUMBLE_LONG                 = 1,
    BTL_RUMBLE_HIT_MIN              = 2,
    BTL_RUMBLE_HIT_LIGHT            = 3,
    BTL_RUMBLE_HIT_HEAVY            = 4,
    BTL_RUMBLE_HIT_EXTREME          = 5,
    BTL_RUMBLE_HIT_MAX              = 6,
    BTL_RUMBLE_PLAYER_MIN           = 7,
    BTL_RUMBLE_PLAYER_LIGHT         = 8,
    BTL_RUMBLE_PLAYER_HEAVY         = 9,
    BTL_RUMBLE_PLAYER_EXTREME       = 10,
    BTL_RUMBLE_PLAYER_MAX           = 11,
};

enum DebugEnemyContactModes {
    DEBUG_CONTACT_NONE              = 0, // contact with enemies behaves normally
    DEBUG_CONTACT_CANT_TOUCH        = 1, // enemies pass through the player and cannot start battles
    DEBUG_CONTACT_DIE_ON_TOUCH      = 2, // enemies die on contact in the overworld
    DEBUG_CONTACT_DIE_IN_BATTLE     = 3, // all enemies wll die during BATTLE_STATE_BEGIN_TURN
    DEBUG_CONTACT_AUTO_FLEE         = 4, // the player flees during BATTLE_STATE_BEGIN_TURN
};

enum DebugScriptstModes {
    DEBUG_SCRIPTS_NONE              = 0,
    DEBUG_SCRIPTS_NO_UPDATE         = 1,
    DEBUG_SCRIPTS_BLOCK_FUNC_DONE   = 2,
};

enum DebuffTypes {
    DEBUFF_TYPE_SLEEP               = 0x00001000,
    DEBUFF_TYPE_STATIC              = 0x00002000,
    DEBUFF_TYPE_FROZEN              = 0x00004000,
    DEBUFF_TYPE_PARALYZED           = 0x00010000,
    DEBUFF_TYPE_POISON              = 0x00020000,
    DEBUFF_TYPE_DIZZY               = 0x00040000,
    DEBUFF_TYPE_SHRINK              = 0x00080000,
    DEBUFF_TYPE_STONE               = 0x00100000,
    DEBUFF_TYPE_STOP                = 0x00200000,
    DEBUFF_TYPE_DAZE                = 0x01000000,
    DEBUFF_TYPE_INVISIBLE           = 0x04000000,
};

enum GlobalOverrides {
    GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD           = 0x00000002,
    GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME             = 0x00000008,
    GLOBAL_OVERRIDES_MESSAGES_OVER_FRONTUI          = 0x00000010,
    GLOBAL_OVERRIDES_SOFT_RESET                     = 0x00000020, // unused but functional
    GLOBAL_OVERRIDES_40                             = 0x00000040,
    GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION        = 0x00000080,
    GLOBAL_OVERRIDES_DISABLE_BATTLES                = 0x00000100,
    GLOBAL_OVERRIDES_200                            = 0x00000200,
    GLOBAL_OVERRIDES_400                            = 0x00000400,
    GLOBAL_OVERRIDES_800                            = 0x00000800,
    GLOBAL_OVERRIDES_PREV_DISABLE_BATTLES           = 0x00001000,
    GLOBAL_OVERRIDES_PREV_200                       = 0x00002000,
    GLOBAL_OVERRIDES_PREV_400                       = 0x00004000,
    GLOBAL_OVERRIDES_PREV_800                       = 0x00008000,
    GLOBAL_OVERRIDES_WINDOWS_OVER_CURTAINS          = 0x00010000,
    GLOBAL_OVERRIDES_DONT_RESUME_SONG_AFTER_BATTLE  = 0x00020000,
    GLOBAL_OVERRIDES_DISABLE_MENUS                  = 0x00040000,
    GLOBAL_OVERRIDES_MESSAGES_OVER_CURTAINS         = 0x00100000,
    GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS             = 0x00200000,
};

#define MODEL_FLAGS_MASK_FFF0  (\
      MODEL_FLAG_USES_CUSTOM_GFX \
    | MODEL_FLAG_20 \
    | MODEL_FLAG_IGNORE_FOG \
    | MODEL_FLAG_HAS_LOCAL_VERTEX_COPY \
    | MODEL_FLAG_USE_CAMERA_UNK_MATRIX \
    | MODEL_FLAG_DO_BOUNDS_CULLING \
    | MODEL_FLAG_HAS_TRANSFORM \
    | MODEL_FLAG_HAS_TEX_PANNER \
    | MODEL_FLAG_MATRIX_DIRTY \
    | MODEL_FLAG_IGNORE_MATRIX \
    | MODEL_FLAG_UNUSED_4000 \
    | MODEL_FLAG_UNUSED_8000)

enum ModelFlags {
    MODEL_FLAG_VALID                    = 0x0001,
    MODEL_FLAG_HIDDEN                   = 0x0002,
    MODEL_FLAG_INACTIVE                 = 0x0004,
    MODEL_FLAG_TRANSFORM_GROUP_MEMBER   = 0x0008,
    MODEL_FLAG_USES_CUSTOM_GFX          = 0x0010,
    MODEL_FLAG_20                       = 0x0020,
    MODEL_FLAG_IGNORE_FOG               = 0x0040,
    MODEL_FLAG_HAS_LOCAL_VERTEX_COPY    = 0x0080,
    MODEL_FLAG_USE_CAMERA_UNK_MATRIX    = 0x0100,
    MODEL_FLAG_DO_BOUNDS_CULLING        = 0x0200,
    MODEL_FLAG_HAS_TRANSFORM            = 0x0400,
    MODEL_FLAG_HAS_TEX_PANNER           = 0x0800,
    MODEL_FLAG_MATRIX_DIRTY             = 0x1000, // transform matrix changed and combined matrix needs to be recalculated
    MODEL_FLAG_IGNORE_MATRIX            = 0x2000, // set until dirty combined matrix has been recalculated
    MODEL_FLAG_UNUSED_4000              = 0x4000,
    MODEL_FLAG_UNUSED_8000              = 0x8000,
};

enum ModelGroupVisibility {
    MODEL_GROUP_HIDDEN          = 0,
    MODEL_GROUP_VISIBLE         = 1,
    MODEL_GROUP_OTHERS_HIDDEN   = 2,
    MODEL_GROUP_OTHERS_VISIBLE  = 3,
};

enum TintMode {
    ENV_TINT_UNCHANGED  = -1,
    // no additional tint is applied (model is still be affected by world fog)
    ENV_TINT_NONE       = 0,
    // additional fog which 'shrouds' the world during certain scenes
    ENV_TINT_SHROUD     = 1,
    // adds depth-based tint using fog, overriding the world fog for affected models
    ENV_TINT_DEPTH      = 2,
    // this mode remaps each color channel range from [0, 255] -> [min, max],
    // setting a new white point and black point for the scene.
    // the new max values are stored in PRIMITIVE and the new min values in ENV
    ENV_TINT_REMAP      = 3,
};

enum TexPanner {
    //select pan unit
    TEX_PANNER_0    = 0x0,
    TEX_PANNER_1    = 0x1,
    TEX_PANNER_2    = 0x2,
    TEX_PANNER_3    = 0x3,
    TEX_PANNER_4    = 0x4,
    TEX_PANNER_5    = 0x5,
    TEX_PANNER_6    = 0x6,
    TEX_PANNER_7    = 0x7,
    TEX_PANNER_8    = 0x8,
    TEX_PANNER_9    = 0x9,
    TEX_PANNER_A    = 0xA,
    TEX_PANNER_B    = 0xB,
    TEX_PANNER_C    = 0xC,
    TEX_PANNER_D    = 0xD,
    TEX_PANNER_E    = 0xE,
    TEX_PANNER_F    = 0xF,
    // select texture component
    TEX_PANNER_MAIN = 0,
    TEX_PANNER_AUX  = 1,
};

enum CustomGfxUnit {
    CUSTOM_GFX_NONE = -1,
    CUSTOM_GFX_0    = 0x00,
    CUSTOM_GFX_1    = 0x01,
    CUSTOM_GFX_2    = 0x02,
    CUSTOM_GFX_3    = 0x03,
    CUSTOM_GFX_4    = 0x04,
    CUSTOM_GFX_5    = 0x05,
    CUSTOM_GFX_6    = 0x06,
    CUSTOM_GFX_7    = 0x07,
    CUSTOM_GFX_8    = 0x08,
    CUSTOM_GFX_9    = 0x09,
    CUSTOM_GFX_A    = 0x0A,
    CUSTOM_GFX_B    = 0x0B,
    CUSTOM_GFX_C    = 0x0C,
    CUSTOM_GFX_D    = 0x0D,
    CUSTOM_GFX_E    = 0x0E,
    CUSTOM_GFX_F    = 0x0F,
};

enum CopiedVtxUnit {
    VTX_COPY_0      = 0x0,
    VTX_COPY_1      = 0x1,
    VTX_COPY_2      = 0x2,
    VTX_COPY_3      = 0x3,
    VTX_COPY_4      = 0x4,
    VTX_COPY_5      = 0x5,
    VTX_COPY_6      = 0x6,
    VTX_COPY_7      = 0x7,
    VTX_COPY_8      = 0x8,
    VTX_COPY_9      = 0x9,
    VTX_COPY_A      = 0xA,
    VTX_COPY_B      = 0xB,
    VTX_COPY_C      = 0xC,
    VTX_COPY_D      = 0xD,
    VTX_COPY_E      = 0xE,
    VTX_COPY_F      = 0xF,
};

enum ModelAnimUnit {
    MDL_ANIMATOR_0  = 0x0,
    MDL_ANIMATOR_1  = 0x1,
    MDL_ANIMATOR_2  = 0x2,
    MDL_ANIMATOR_3  = 0x3,
    MDL_ANIMATOR_4  = 0x4,
    MDL_ANIMATOR_5  = 0x5,
    MDL_ANIMATOR_6  = 0x6,
    MDL_ANIMATOR_7  = 0x7,
    MDL_ANIMATOR_8  = 0x8,
    MDL_ANIMATOR_9  = 0x9,
    MDL_ANIMATOR_A  = 0xA,
    MDL_ANIMATOR_B  = 0xB,
    MDL_ANIMATOR_C  = 0xC,
    MDL_ANIMATOR_D  = 0xD,
    MDL_ANIMATOR_E  = 0xE,
    MDL_ANIMATOR_F  = 0xF,
};

enum MapRoomFlags {
    ROOM_FLAGS_VISGROUP_MASK                = 0xF000,
    ROOM_FLAGS_MASK                         = 0x0F00,
    ROOM_FLAGS_DOOR_TYPE_MASK               = 0x00FF,
    ROOM_DOOR_RIGHT_HINGE_OPENS_OUT         = 0, // left --> center (hinge on right)
    ROOM_DOOR_RIGHT_HINGE_OPENS_IN          = 1, // center --> left
    ROOM_DOOR_LEFT_HINGE_OPENS_OUT          = 2, // right --> center (hinge on left)
    ROOM_DOOR_LEFT_HINGE_OPENS_IN           = 3, // center --> right
    ROOM_DOOR_STRAIGHT_THROUGH              = 4, // center --> center
    ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT   = 5, // deep left  --> center     (hinge on right)
    ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_IN    = 6, // center     --> deep left
    ROOM_LARGE_DOOR_LEFT_HINGE_OPENS_OUT    = 7, // deep right --> center     (hinge on left)
    ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR         = 0x100,
    ROOM_FLAG_CUSTOM_ANIM_WALL_ROT          = 0x200,
    ROOM_FLAG_CUSTOM_ANIM_DROP_DOOR         = 0x400,
    ROOM_FLAG_EXIT_DOOR_DROPS               = 0x800, // for internal use
};

enum MapRoomNotifications {
    // dispatched to listener script during interactions with the room door
    ROOM_UPDATE_ENTER_BEGIN     = 0,
    ROOM_UPDATE_ENTER_DONE      = 1,
    ROOM_UPDATE_EXIT_BEGIN      = 2,
    ROOM_UPDATE_EXIT_END        = 3,
    // when handling ROOM_UPDATE_ENTER_BEGIN, listener may return this to cancel the door opening. useful for locked doors.
    ROOM_UPDATE_REQUEST_CANCEL  = -1,
    // anim move door updates
    ROOM_MOVE_DOOR_ENTER_OPEN   = 0,
    ROOM_MOVE_DOOR_ENTER_CLOSE  = 1,
    ROOM_MOVE_DOOR_EXIT_OPEN    = 2,
    ROOM_MOVE_DOOR_EXIT_CLOSE   = 3,
    // anim move walls update
    ROOM_MOVE_WALL_OPEN         = 0,
    ROOM_MOVE_WALL_1            = 1, // unused
    ROOM_MOVE_WALL_2            = 2, // unused
    ROOM_MOVE_WALL_CLOSE        = 3,
    // anim drop droor updates
    ROOM_DROP_DOOR_ENTER        = 0,
    ROOM_DROP_DOOR_1            = 1, // unused
    ROOM_DROP_DOOR_2            = 2, // unused
    ROOM_DROP_DOOR_EXIT         = 3,
};

enum EnemyFlags {
    ENEMY_FLAG_PASSIVE                  = 0x00000001, // Not hostile; collision does not trigger battle
    ENEMY_FLAG_2                        = 0x00000002, // Unused
    ENEMY_FLAG_4                        = 0x00000004,
    ENEMY_FLAG_ENABLE_HIT_SCRIPT        = 0x00000008,
    ENEMY_FLAG_FLED                     = 0x00000010,
    ENEMY_FLAG_DISABLE_AI               = 0x00000020, // Disable movement AI and collision (idle animation plays)
    ENEMY_FLAG_PROJECTILE               = 0x00000040,
    ENEMY_FLAG_DONT_UPDATE_SHADOW_Y     = 0x00000080,
    ENEMY_FLAG_IGNORE_WORLD_COLLISION   = 0x00000100,
    ENEMY_FLAG_IGNORE_PLAYER_COLLISION  = 0x00000200,
    ENEMY_FLAG_IGNORE_ENTITY_COLLISION  = 0x00000400,
    ENEMY_FLAG_FLYING                   = 0x00000800, // Corresponds with NPC_FLAG_FLYING, name seems incorrect?
    ENEMY_FLAG_GRAVITY                  = 0x00001000,
    ENEMY_FLAG_NO_SHADOW_RAYCAST        = 0x00002000,
    ENEMY_FLAG_HAS_NO_SPRITE            = 0x00004000,
    ENEMY_FLAG_8000                     = 0x00008000, // Corresponds with NPC_FLAG_10000000
    ENEMY_FLAG_10000                    = 0x00010000, // Corresponds with NPC_FLAG_20000000
    ENEMY_FLAG_USE_PLAYER_SPRITE        = 0x00020000, // Used for Peach NPCs
    ENEMY_FLAG_40000                    = 0x00040000,
    ENEMY_FLAG_80000                    = 0x00080000,
    ENEMY_FLAG_100000                   = 0x00100000,
    ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN   = 0x00200000,
    ENEMY_FLAG_400000                   = 0x00400000,
    ENEMY_FLAG_NO_DROPS                 = 0x00800000, // Do not drop hearts, flowers, or coins on defeat
    ENEMY_FLAG_IGNORE_TOUCH             = 0x01000000,
    ENEMY_FLAG_IGNORE_JUMP              = 0x02000000,
    ENEMY_FLAG_IGNORE_HAMMER            = 0x04000000,
    ENEMY_FLAG_CANT_INTERACT            = 0x08000000, // Makes passive NPCs non-interactable. Hostile NPCs are always non-interactible.
    ENEMY_FLAG_IGNORE_PARTNER           = 0x10000000,
    ENEMY_FLAG_IGNORE_SPIN              = 0x20000000,
    ENEMY_FLAG_BEGIN_WITH_CHASING       = 0x40000000, // Starts in state AI_STATE_CHASE_INIT instead of AI_STATE_WANDER_INIT on spawn or AI resume
    ENEMY_FLAG_SUSPENDED                = 0x80000000,
};

#define COMMON_PASSIVE_FLAGS \
      ENEMY_FLAG_PASSIVE \
    | ENEMY_FLAG_ENABLE_HIT_SCRIPT \
    | ENEMY_FLAG_IGNORE_WORLD_COLLISION \
    | ENEMY_FLAG_IGNORE_ENTITY_COLLISION \
    | ENEMY_FLAG_FLYING

// used with enemy->aiFlags
enum EnemyAIFlags {
    ENEMY_AI_FLAG_1              = 0x00000001,
    ENEMY_AI_FLAG_2              = 0x00000002, // do not move; do not sense player
    ENEMY_AI_FLAG_SUSPEND        = 0x00000004,
    ENEMY_AI_FLAG_8              = 0x00000008,
    ENEMY_AI_FLAG_10             = 0x00000010,
    ENEMY_AI_FLAG_20             = 0x00000020,
    ENEMY_AI_FLAG_40             = 0x00000040,
    ENEMY_AI_FLAG_80             = 0x00000080,
};

enum EnemyAIStates {
    // basic states
    AI_STATE_WANDER_INIT            = 0,
    AI_STATE_WANDER                 = 1,
    AI_STATE_PATROL_INIT            = 0,
    AI_STATE_PATROL                 = 1,
    AI_STATE_HOP_INIT               = 0,
    AI_STATE_HOP                    = 1,
    AI_STATE_LOITER_INIT            = 2,
    AI_STATE_LOITER                 = 3,
    AI_STATE_LOITER_POST            = 4,
    AI_STATE_ALERT_INIT             = 10,
    AI_STATE_ALERT                  = 11,
    AI_STATE_CHASE_INIT             = 12,
    AI_STATE_CHASE                  = 13,
    AI_STATE_LOSE_PLAYER            = 14,
    AI_STATE_PATROL_15              = 15,
    AI_RETURN_HOME_INIT             = 40,
    AI_RETURN_HOME                  = 41,
    AI_STATE_SUSPEND                = 99,
    // melee hitboxes
    AI_STATE_MELEE_HITBOX_INIT      = 30,
    AI_STATE_MELEE_HITBOX_PRE       = 31,
    AI_STATE_MELEE_HITBOX_ACTIVE    = 32,
    AI_STATE_MELEE_HITBOX_MISS      = 33,
    // projectile hitboxes
    AI_STATE_PROJECTILE_HITBOX_30   = 30,
    AI_STATE_PROJECTILE_HITBOX_31   = 31,
    AI_STATE_PROJECTILE_HITBOX_32   = 32,
    AI_STATE_PROJECTILE_HITBOX_33   = 33,
};

enum EnemyActionFlags {
    AI_ACTION_JUMP_WHEN_SEE_PLAYER          = 0x01,
    AI_ACTION_02                            = 0x02,
    AI_ACTION_04                            = 0x04,
    AI_ACTION_08                            = 0x08,
    AI_ACTION_LOOK_AROUND_DURING_LOITER     = 0x10,
    AI_ACTION_20                            = 0x20
};

enum EnemyDetectFlags {
    AI_DETECT_SIGHT                 = 0x01,
    AI_DETECT_SENSITIVE_MOTION      = 0x02,
    AI_DETECT_FLAG_8                = 0x08,
};

enum EnemyTerritoryFlags {
    AI_TERRITORY_IGNORE_HIDING      = 0x01, // bow and sushi dont prevent enemy detection
    AI_TERRITORY_IGNORE_ELEVATION   = 0x02, // vertical size of detection volume is ignored
};

enum PiranhaPlantStates {
    AI_STATE_PIRANHA_PLANT_00       = 0,
    AI_STATE_PIRANHA_PLANT_01       = 1,
    AI_STATE_PIRANHA_PLANT_10       = 10,
    AI_STATE_PIRANHA_PLANT_11       = 11,
    AI_STATE_PIRANHA_PLANT_12       = 12,
    AI_STATE_PIRANHA_PLANT_13       = 13,
    AI_STATE_PIRANHA_PLANT_14       = 14,
    AI_STATE_PIRANHA_PLANT_SUSPEND  = 99
};

enum MeleeHitboxAttackStates {
    MELEE_HITBOX_STATE_NONE         = 0,
    MELEE_HITBOX_STATE_INIT         = 1,
    MELEE_HITBOX_STATE_PRE          = 2,
    MELEE_HITBOX_STATE_ACTIVE       = 3,  // hitbox is active
    MELEE_HITBOX_STATE_POST         = 4
};

enum ProjectileHitboxAttackStates {
    PROJECTILE_HITBOX_STATE_NONE        = 0,
    PROJECTILE_HITBOX_STATE_INIT        = 1,
    PROJECTILE_HITBOX_STATE_PRE         = 2,
    PROJECTILE_HITBOX_STATE_ACTIVE      = 3,  // hitbox is active
    PROJECTILE_HITBOX_STATE_POST        = 4,
    PROJECTILE_HITBOX_STATE_DONE        = 100
};

enum MusicSettingsFlags {
    MUSIC_SETTINGS_FLAG_1                 = 0x00000001,
    MUSIC_SETTINGS_FLAG_ENABLE_PROXIMITY_MIX   = 0x00000002,
    MUSIC_SETTINGS_FLAG_4                 = 0x00000004,
    MUSIC_SETTINGS_FLAG_8                 = 0x00000008,
    MUSIC_SETTINGS_FLAG_10                = 0x00000010,
    MUSIC_SETTINGS_FLAG_20                = 0x00000020,
};

// the lower byte of ColliderFlags
enum SurfaceType {
    SURFACE_TYPE_DEFAULT            = 0,
    SURFACE_TYPE_WATER              = 1,
    SURFACE_TYPE_SPIKES             = 2,
    SURFACE_TYPE_LAVA               = 3,
    SURFACE_TYPE_DOCK_WALL          = 4,
    SURFACE_TYPE_SLIDE              = 5,
    SURFACE_TYPE_FLOWERS            = 6,
    SURFACE_TYPE_CLOUD              = 7, ///< used with clouds in flo_19 and flo_21
    SURFACE_TYPE_SNOW               = 8,
    SURFACE_TYPE_HEDGES             = 9, ///< used within hedge maze in flo_11
    SURFACE_TYPE_INVALID            = -1,
};

typedef enum SurfaceInteractMode {
    SURFACE_INTERACT_WALK       = 0,
    SURFACE_INTERACT_RUN        = 1,
    SURFACE_INTERACT_LAND       = 2,
} SurfaceInteractMode;

// flags that can be set on colliders
// passed into collision queries to selectively ignore certain types of objects or colliders
enum ColliderFlags {
    COLLIDER_FLAGS_UPPER_MASK           = 0x7FFFFE00, // map data dumper needs this to be first
    COLLIDER_FLAGS_SURFACE_TYPE_MASK    = 0x000000FF,
    COLLIDER_FLAG_SAFE_FLOOR            = 0x00000100,
    COLLIDER_FLAG_IGNORE_SHELL          = 0x00008000, // colliders marked with this flag are not solid for shells
    COLLIDER_FLAG_IGNORE_PLAYER         = 0x00010000, // colliders marked with this flag are not solid for player or partners
    COLLIDER_FLAG_IGNORE_NPC            = 0x00020000, // colliders marked with this flag are not solid for npcs or item entities
    COLLISION_IGNORE_ENTITIES           = 0x00040000, // used for collision queries, not set for colliders
    COLLIDER_FLAG_DOCK_WALL             = 0x00080000,
    COLLISION_ONLY_ENTITIES             = 0x00100000, // used for collision queries, not set for colliders
    COLLIDER_FLAG_HAS_MODEL_PARENT      = 0x80000000
};

enum ColliderFlagsModifyMode {
    MODIFY_COLLIDER_FLAGS_SET_BITS       = 0,
    MODIFY_COLLIDER_FLAGS_CLEAR_BITS     = 1,
    MODIFY_COLLIDER_FLAGS_SET_VALUE      = 2,
    MODIFY_COLLIDER_FLAGS_SET_SURFACE    = 3,
};

enum PlayerCollisionTests {
    PLAYER_COLLISION_0          = 0,
    PLAYER_COLLISION_1          = 1,
    PLAYER_COLLISION_2          = 2,
    PLAYER_COLLISION_3          = 3,
    PLAYER_COLLISION_4          = 4,
};

enum CameraFlags {
    CAMERA_FLAG_INITIALIZED         = 0x00000001,
    CAMERA_FLAG_DISABLED            = 0x00000002,
    CAMERA_FLAG_LEAD_PLAYER         = 0x00000004,
    CAMERA_FLAG_SHAKING             = 0x00000008,
    CAMERA_FLAG_ORTHO               = 0x00000010,
    CAMERA_FLAG_NO_DRAW             = 0x00000080,
    CAMERA_FLAG_RENDER_ENTITIES     = 0x00000200,
    CAMERA_FLAG_RENDER_MODELS       = 0x00000400,
    CAMERA_FLAG_SUPRESS_LEADING     = 0x00001000,
};

enum CameraMoveFlags {
    CAMERA_MOVE_IGNORE_PLAYER_Y     = 0x00000001,
    CAMERA_MOVE_NO_INTERP_Y         = 0x00000002,
    CAMERA_MOVE_ACCEL_INTERP_Y      = 0x00000004,
};

enum CameraUpdateType {
    CAM_UPDATE_MODE_INIT            = 0,
    CAM_UPDATE_UNUSED_1             = 1,
    CAM_UPDATE_MODE_2               = 2,
    CAM_UPDATE_FROM_ZONE            = 3,
    CAM_UPDATE_UNUSED_4             = 4,
    CAM_UPDATE_UNUSED_5             = 5,
    CAM_UPDATE_MODE_6               = 6,
};

enum CameraControlType {
    // Camera follows the player, using a fixed yaw position.
    // Uses: A/B as 2D points
    // Yaw is defined by the line segment AB
    // flag 0 = free forward movement (follow player)
    // flag 1 = lock forward movement (must intersect B)
    CAM_CONTROL_FIXED_ORIENTATION   = 0,

    // Camera faces toward or away from a point with the player in the center of the frame.
    // Use a negative boom length to look away from a point.
    // flag 1 = Constrain to Fixed Radius
    CAM_CONTROL_LOOK_AT_POINT       = 1,

    // Camera is contrained to a point along the line segment BC.
    // Use these near exits to stop camera movement.
    // Uses: A/B/C as 2D points
    // The target position is found by projecting player position onto BC along a line orthogonal to AB.
    // If posA == posB, AB is ignored and the projection axis will be along a line orthogonal to BC with
    // the resulting position being the closest point on BC to the player.
    // flag 1 = Freeze Camera Position
    CAM_CONTROL_CONSTRAIN_TO_LINE   = 2,

    // Follows the player using whatever yaw value the camera initially possessed.
    CAM_CONTROL_FOLLOW_PLAYER       = 3,

    // Both position and yaw are fixed.
    CAM_CONTROL_FIXED_POS_AND_ORIENTATION       = 4,

    // Look Toward Point, Constrain to Line
    // flag 1 = Freeze Target at Point
    CAM_CONTROL_LOOK_AT_POINT_CONSTAIN_TO_LINE  = 5,

    // Camera position is contrained to a line segment, with yaw perpendicular to the line segment.
    // flag 1 = Disable Forward Motion
    CAM_CONTROL_CONSTAIN_BETWEEN_POINTS         = 6,
};

enum BtlCameraPreset {
    BTL_CAM_PRESET_00               = 0,    // unused?
    BTL_CAM_PRESET_01               = 1,    // STOP
    BTL_CAM_DEFAULT                 = 2,
    BTL_CAM_PRESET_03               = 3,
    BTL_CAM_PRESET_04               = 4,
    BTL_CAM_PRESET_05               = 5,
    BTL_CAM_PRESET_06               = 6,   // unused?
    BTL_CAM_PRESET_07               = 7,
    BTL_CAM_PRESET_08               = 8,
    BTL_CAM_PRESET_09               = 9,    // unused?
    BTL_CAM_PRESET_10               = 10,
    BTL_CAM_PRESET_11               = 11,
    BTL_CAM_PRESET_12               = 12,   // unused?
    BTL_CAM_PRESET_13               = 13,
    BTL_CAM_PRESET_14               = 14,  // FOCUS_ON_TARGET?
    BTL_CAM_PRESET_15               = 15,
    BTL_CAM_PRESET_16               = 16,   // unused?
    BTL_CAM_PRESET_17               = 17,   // unused?
    BTL_CAM_PRESET_18               = 18,   // unused?
    BTL_CAM_PRESET_19               = 19,
    BTL_CAM_PRESET_20               = 20,   // unused?
    BTL_CAM_PRESET_21               = 21,   // unused?
    BTL_CAM_PLAYER_ENTRY            = 22,
    BTL_CAM_VICTORY                 = 23,   // closeup on party while star points are tallied
    BTL_CAM_PRESET_24               = 24,
    BTL_CAM_PRESET_25               = 25,   // closeup on player used when running away or being defeated
    BTL_CAM_PLAYER_ATTACK_APPROACH  = 26,
    BTL_CAM_PRESET_27               = 27,
    BTL_CAM_PRESET_28               = 28,
    BTL_CAM_PRESET_29               = 29,
    BTL_CAM_PLAYER_HIT_SPIKE        = 30,   // player hurt via spike contact
    BTL_CAM_PLAYER_HIT_HAZARD       = 31,   // player hurt via burn or shock contact
    BTL_CAM_PLAYER_CHARGE_UP        = 32,
    BTL_CAM_PLAYER_STATUS_AFFLICTED = 33,
    BTL_CAM_PRESET_34               = 34,
    BTL_CAM_PRESET_35               = 35,
    BTL_CAM_PRESET_36               = 36,   // unused?
    BTL_CAM_PRESET_37               = 37,
    BTL_CAM_PRESET_38               = 38,
    BTL_CAM_PRESET_39               = 39,
    BTL_CAM_PRESET_40               = 40,
    BTL_CAM_PRESET_41               = 41,   // unused?
    BTL_CAM_PRESET_42               = 42,   // unused?
    BTL_CAM_PLAYER_AIM_HAMMER       = 43,
    BTL_CAM_PLAYER_HAMMER_STRIKE    = 44,
    BTL_CAM_PRESET_45               = 45,   // unused?
    BTL_CAM_PRESET_46               = 46,
    BTL_CAM_PARTNER_APPROACH        = 47,   // used by Goombario and Watt (power shock only)
    BTL_CAM_PRESET_48               = 48,
    BTL_CAM_PRESET_49               = 49,   // unused?
    BTL_CAM_PRESET_50               = 50,
    BTL_CAM_PRESET_51               = 51,
    BTL_CAM_PRESET_52               = 52,
    BTL_CAM_PRESET_53               = 53,
    BTL_CAM_PARTNER_INJURED         = 54,   // closeup on partner after being injured
    BTL_CAM_PRESET_55               = 55,
    BTL_CAM_PRESET_56               = 56,   // unused?
    BTL_CAM_PRESET_57               = 57,   // unused?
    BTL_CAM_PRESET_58               = 58,   // unused?
    BTL_CAM_PRESET_59               = 59,
    BTL_CAM_PRESET_60               = 60,   // unused?
    BTL_CAM_PRESET_61               = 61,
    BTL_CAM_PRESET_62               = 62,
    BTL_CAM_ENEMY_APPROACH          = 63,   // (very common)
    BTL_CAM_PRESET_64               = 64,   // unused?
    BTL_CAM_PRESET_65               = 65,   // unused?
    BTL_CAM_PRESET_66               = 66,
    BTL_CAM_PRESET_67               = 67,   // unused?
    BTL_CAM_PRESET_68               = 68,   // unused?
    BTL_CAM_PRESET_69               = 69,
    BTL_CAM_PRESET_70               = 70,   // unused?
    BTL_CAM_PRESET_71               = 71,   // unused?
    BTL_CAM_PRESET_72               = 72,   // unused?
    BTL_CAM_PRESET_73               = 73,
};

enum BattleCamXModes {
    BTL_CAM_MODEX_0         = 0,
    BTL_CAM_MODEX_1         = 1,
};

enum BattleCamYModes {
    BTL_CAM_MODEY_MINUS_2   = -2,
    BTL_CAM_MODEY_MINUS_1   = -1,
    BTL_CAM_MODEY_0         = 0,
    BTL_CAM_MODEY_1         = 1,
};

enum ModelAnimatorFlags {
    MODEL_ANIMATOR_FLAG_CAM_0             = 0x00000001,
    MODEL_ANIMATOR_FLAG_CAM_1             = 0x00000002,
    MODEL_ANIMATOR_FLAG_CAM_2             = 0x00000004,
    MODEL_ANIMATOR_FLAG_CAM_3             = 0x00000008,
    MODEL_ANIMATOR_FLAG_ENABLED           = 0x00000010,
    MODEL_ANIMATOR_FLAG_20                = 0x00000020,
    MODEL_ANIMATOR_FLAG_UPDATE_PENDING    = 0x00000040,
    MODEL_ANIMATOR_FLAG_HIDDEN            = 0x00000080,
    MODEL_ANIMATOR_FLAG_FLIP_Z            = 0x00000100,
    MODEL_ANIMATOR_FLAG_FLIP_Y            = 0x00000200,
    MODEL_ANIMATOR_FLAG_FLIP_X            = 0x00000400,
    MODEL_ANIMATOR_FLAG_800               = 0x00000800,
    MODEL_ANIMATOR_FLAG_HAS_MODEL         = 0x00001000,
    MODEL_ANIMATOR_FLAG_2000              = 0x00002000,
    MODEL_ANIMATOR_FLAG_4000              = 0x00004000,
    MODEL_ANIMATOR_FLAG_MESH              = 0x00008000,
    MODEL_ANIMATOR_FLAG_CULL_BACK         = 0x00010000,
    MODEL_ANIMATOR_FLAG_NO_FLIP           = 0x00020000,
    MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION  = 0x00040000,
    MODEL_ANIMATOR_FLAG_80000             = 0x00080000,
    MODEL_ANIMATOR_FLAG_100000            = 0x00100000,
    MODEL_ANIMATOR_FLAG_200000            = 0x00200000,
    MODEL_ANIMATOR_FLAG_400000            = 0x00400000,
    MODEL_ANIMATOR_FLAG_800000            = 0x00800000,
    MODEL_ANIMATOR_FLAG_1000000           = 0x01000000,
    MODEL_ANIMATOR_FLAG_2000000           = 0x02000000,
    MODEL_ANIMATOR_FLAG_4000000           = 0x04000000,
    MODEL_ANIMATOR_FLAG_8000000           = 0x08000000,
    MODEL_ANIMATOR_FLAG_10000000          = 0x10000000,
    MODEL_ANIMATOR_FLAG_20000000          = 0x20000000,
    MODEL_ANIMATOR_FLAG_40000000          = 0x40000000,
    MODEL_ANIMATOR_FLAG_80000000          = 0x80000000,
};

enum ShopFlags {
    SHOP_FLAG_SHOWING_ITEM_INFO         = 0x1,
    SHOP_FLAG_INTERACT_SCRIPT_RUNNING   = 0x8,
};

enum {
    SHOP_MSG_BUY_CONFIRM        = 0x00,
    SHOP_MSG_NOT_ENOUGH_COINS   = 0x01,
    SHOP_MSG_NOT_ENOUGH_ROOM    = 0x02,
    SHOP_MSG_BUY_THANK_YOU      = 0x03,
    SHOP_MSG_GREETING           = 0x04,
    SHOP_MSG_INSTRUCTIONS       = 0x05,
    SHOP_MSG_NOTHING_TO_SELL    = 0x06,
    SHOP_MSG_SELL_WHICH         = 0x07,
    SHOP_MSG_SELL_CONFIRM       = 0x08,
    SHOP_MSG_SELL_CANCEL        = 0x09,
    SHOP_MSG_SELL_MORE          = 0x0A,
    SHOP_MSG_SELL_THANKS        = 0x0B,
    SHOP_MSG_NOTHING_TO_CHECK   = 0x0C,
    SHOP_MSG_NO_CHECK_ROOM      = 0x0D,
    SHOP_MSG_CHECK_WHICH        = 0x0E,
    SHOP_MSG_CHECK_ACCEPTED     = 0x0F,
    SHOP_MSG_CHECK_MORE         = 0x10,
    SHOP_MSG_NOTHING_TO_CLAIM   = 0x11,
    SHOP_MSG_NO_CLAIM_ROOM      = 0x12,
    SHOP_MSG_CLAIM_WHICH        = 0x13,
    SHOP_MSG_CLAIM_ACCEPTED     = 0x14,
    SHOP_MSG_CLAIM_MORE         = 0x15,
    SHOP_MSG_FAREWELL           = 0x16,
};

enum {
    SHOP_BUY_RESULT_NOT_ENOUGH_COINS    = 0,
    SHOP_BUY_RESULT_OK                  = 1,
    SHOP_BUY_RESULT_2                   = 2,
    SHOP_BUY_RESULT_CANCEL              = 3,
    SHOP_BUY_RESULT_4                   = 4,
    SHOP_BUY_RESULT_NOT_ENOUGH_ROOM     = 5,
};

enum EncounterStatusFlags {
    ENCOUNTER_STATUS_FLAG_0                 = 0x00000000,
    ENCOUNTER_STATUS_FLAG_1                 = 0x00000001,
    ENCOUNTER_STATUS_FLAG_2                 = 0x00000002,
    ENCOUNTER_STATUS_FLAG_4                 = 0x00000004,
    ENCOUNTER_STATUS_FLAG_8                 = 0x00000008,
    ENCOUNTER_STATUS_FLAG_10                = 0x00000010,
    ENCOUNTER_STATUS_FLAG_20                = 0x00000020,
    ENCOUNTER_STATUS_FLAG_40                = 0x00000040,
    ENCOUNTER_STATUS_FLAG_80                = 0x00000080,
    ENCOUNTER_STATUS_FLAG_100               = 0x00000100,
    ENCOUNTER_STATUS_FLAG_200               = 0x00000200,
    ENCOUNTER_STATUS_FLAG_400               = 0x00000400,
    ENCOUNTER_STATUS_FLAG_800               = 0x00000800,
    ENCOUNTER_STATUS_FLAG_1000              = 0x00001000,
    ENCOUNTER_STATUS_FLAG_2000              = 0x00002000,
    ENCOUNTER_STATUS_FLAG_4000              = 0x00004000,
    ENCOUNTER_STATUS_FLAG_8000              = 0x00008000,
    ENCOUNTER_STATUS_FLAG_10000             = 0x00010000,
    ENCOUNTER_STATUS_FLAG_20000             = 0x00020000,
    ENCOUNTER_STATUS_FLAG_40000             = 0x00040000,
    ENCOUNTER_STATUS_FLAG_80000             = 0x00080000,
    ENCOUNTER_STATUS_FLAG_100000            = 0x00100000,
    ENCOUNTER_STATUS_FLAG_200000            = 0x00200000,
    ENCOUNTER_STATUS_FLAG_400000            = 0x00400000,
    ENCOUNTER_STATUS_FLAG_800000            = 0x00800000,
    ENCOUNTER_STATUS_FLAG_1000000           = 0x01000000,
    ENCOUNTER_STATUS_FLAG_2000000           = 0x02000000,
    ENCOUNTER_STATUS_FLAG_4000000           = 0x04000000,
    ENCOUNTER_STATUS_FLAG_8000000           = 0x08000000,
    ENCOUNTER_STATUS_FLAG_10000000          = 0x10000000,
    ENCOUNTER_STATUS_FLAG_20000000          = 0x20000000,
    ENCOUNTER_STATUS_FLAG_40000000          = 0x40000000,
    ENCOUNTER_STATUS_FLAG_80000000          = 0x80000000,
};

enum WindowFlags {
    WINDOW_FLAG_INITIALIZED       = 0x00000001,
    WINDOW_FLAG_FPUPDATE_CHANGED  = 0x00000002,
    WINDOW_FLAG_HIDDEN            = 0x00000004, ///< Updated but not rendered
    WINDOW_FLAG_INITIAL_ANIMATION = 0x00000008,
    WINDOW_FLAG_HAS_CHILDREN      = 0x00000010,
    WINDOW_FLAG_DISABLED          = 0x00000020, ///< Not updated or rendered
    WINDOW_FLAG_40                = 0x00000040,
};

enum DrawFlags {
    DRAW_FLAG_ROTSCALE                  = 0x00000001,
    DRAW_FLAG_ANIMATED_BACKGROUND       = 0x00000002,
    DRAW_FLAG_NO_CLIP                   = 0x00000004,
    DRAW_FLAG_CULL_BACK                 = 0x00000008,
};

enum EntityModelFlags {
    ENTITY_MODEL_FLAG_CAM0              = 0x00000001,
    ENTITY_MODEL_FLAG_CAM1              = 0x00000002,
    ENTITY_MODEL_FLAG_CAM2              = 0x00000004,
    ENTITY_MODEL_FLAG_CAM3              = 0x00000008,
    ENTITY_MODEL_FLAG_ENABLED           = 0x00000010,
    ENTITY_MODEL_FLAG_HIDDEN            = 0x00000020,
    ENTITY_MODEL_FLAG_40                = 0x00000040,
    ENTITY_MODEL_FLAG_80                = 0x00000080,
    ENTITY_MODEL_FLAG_100               = 0x00000100,
    ENTITY_MODEL_FLAG_REFLECT           = 0x00000200,
    ENTITY_MODEL_FLAG_USE_IMAGE         = 0x00000400,
    ENTITY_MODEL_FLAG_FOG_DISABLED      = 0x00000800,
    ENTITY_MODEL_FLAG_1000              = 0x00001000,
    ENTITY_MODEL_FLAG_2000              = 0x00002000,
    ENTITY_MODEL_FLAG_4000              = 0x00004000,
    ENTITY_MODEL_FLAG_8000              = 0x00008000,
    ENTITY_MODEL_FLAG_10000             = 0x00010000,
    ENTITY_MODEL_FLAG_DISABLE_SCRIPT    = 0x00020000,
    ENTITY_MODEL_FLAG_40000             = 0x00040000,
    ENTITY_MODEL_FLAG_80000             = 0x00080000,
    ENTITY_MODEL_FLAG_100000            = 0x00100000,
    ENTITY_MODEL_FLAG_200000            = 0x00200000,
    ENTITY_MODEL_FLAG_400000            = 0x00400000,
    ENTITY_MODEL_FLAG_800000            = 0x00800000,
    ENTITY_MODEL_FLAG_1000000           = 0x01000000,
    ENTITY_MODEL_FLAG_2000000           = 0x02000000,
    ENTITY_MODEL_FLAG_4000000           = 0x04000000,
    ENTITY_MODEL_FLAG_8000000           = 0x08000000,
    ENTITY_MODEL_FLAG_10000000          = 0x10000000,
    ENTITY_MODEL_FLAG_20000000          = 0x20000000,
    ENTITY_MODEL_FLAG_40000000          = 0x40000000,
    ENTITY_MODEL_FLAG_80000000          = 0x80000000,
};

enum TempSetZoneEnabledFlags {
    TEMP_SET_ZONE_ENABLED_FLAG_1                 = 0x00000001,
    TEMP_SET_ZONE_ENABLED_FLAG_2                 = 0x00000002,
    TEMP_SET_ZONE_ENABLED_FLAG_4                 = 0x00000004,
    TEMP_SET_ZONE_ENABLED_FLAG_8                 = 0x00000008,
    TEMP_SET_ZONE_ENABLED_FLAG_10                = 0x00000010,
    TEMP_SET_ZONE_ENABLED_FLAG_20                = 0x00000020,
    TEMP_SET_ZONE_ENABLED_FLAG_40                = 0x00000040,
    TEMP_SET_ZONE_ENABLED_FLAG_80                = 0x00000080,
    TEMP_SET_ZONE_ENABLED_FLAG_100               = 0x00000100,
    TEMP_SET_ZONE_ENABLED_FLAG_200               = 0x00000200,
    TEMP_SET_ZONE_ENABLED_FLAG_400               = 0x00000400,
    TEMP_SET_ZONE_ENABLED_FLAG_800               = 0x00000800,
    TEMP_SET_ZONE_ENABLED_FLAG_1000              = 0x00001000,
    TEMP_SET_ZONE_ENABLED_FLAG_2000              = 0x00002000,
    TEMP_SET_ZONE_ENABLED_FLAG_4000              = 0x00004000,
    TEMP_SET_ZONE_ENABLED_FLAG_8000              = 0x00008000,
    TEMP_SET_ZONE_ENABLED_FLAG_10000             = 0x00010000,
    TEMP_SET_ZONE_ENABLED_FLAG_20000             = 0x00020000,
    TEMP_SET_ZONE_ENABLED_FLAG_40000             = 0x00040000,
    TEMP_SET_ZONE_ENABLED_FLAG_80000             = 0x00080000,
    TEMP_SET_ZONE_ENABLED_FLAG_100000            = 0x00100000,
    TEMP_SET_ZONE_ENABLED_FLAG_200000            = 0x00200000,
    TEMP_SET_ZONE_ENABLED_FLAG_400000            = 0x00400000,
    TEMP_SET_ZONE_ENABLED_FLAG_800000            = 0x00800000,
    TEMP_SET_ZONE_ENABLED_FLAG_1000000           = 0x01000000,
    TEMP_SET_ZONE_ENABLED_FLAG_2000000           = 0x02000000,
    TEMP_SET_ZONE_ENABLED_FLAG_4000000           = 0x04000000,
    TEMP_SET_ZONE_ENABLED_FLAG_8000000           = 0x08000000,
    TEMP_SET_ZONE_ENABLED_FLAG_10000000          = 0x10000000,
    TEMP_SET_ZONE_ENABLED_FLAG_20000000          = 0x20000000,
    TEMP_SET_ZONE_ENABLED_FLAG_40000000          = 0x40000000,
    TEMP_SET_ZONE_ENABLED_FLAG_80000000          = 0x80000000,
};

enum ModelTransformGroupFlags {
    TRANSFORM_GROUP_FLAG_VALID                  = 0x00000001,
    TRANSFORM_GROUP_FLAG_HIDDEN                 = 0x00000002, // update, but do not render
    TRANSFORM_GROUP_FLAG_INACTIVE               = 0x00000004,
    TRANSFORM_GROUP_FLAG_HAS_TRANSFORM          = 0x00000400,
    TRANSFORM_GROUP_FLAG_MATRIX_DIRTY           = 0x00001000,
    TRANSFORM_GROUP_FLAG_IGNORE_MATRIX          = 0x00002000, // set until dirty matrix has been recalculated
};

enum NpcDropFlags {
    NPC_DROP_FLAG_1                 = 0x01,
    NPC_DROP_FLAG_2                 = 0x02,
    NPC_DROP_FLAG_4                 = 0x04,
    NPC_DROP_FLAG_8                 = 0x08,
    NPC_DROP_FLAG_10                = 0x10,
    NPC_DROP_FLAG_20                = 0x20,
    NPC_DROP_FLAG_40                = 0x40,
    NPC_DROP_FLAG_80                = 0x80,
};

enum ImgFXStateFlags {
    IMGFX_FLAG_VALID                = 0x00000001,
    IMGFX_FLAG_G_CULL_BACK          = 0x00000002,
    IMGFX_FLAG_G_CULL_FRONT         = 0x00000004,
    IMGFX_FLAG_8                    = 0x00000008,
    IMGFX_FLAG_SKIP_GFX_SETUP       = 0x00000010,
    IMGFX_FLAG_SKIP_TEX_SETUP       = 0x00000020,
    IMGFX_FLAG_40                   = 0x00000040,
    IMGFX_FLAG_LOOP_ANIM            = 0x00000080,
    IMGFX_FLAG_REVERSE_ANIM         = 0x00000100, // fold animation plays backwards (from end to start)
    IMGFX_FLAG_200                  = 0x00000200,
    IMGFX_FLAG_400                  = 0x00000400,
    IMGFX_FLAG_800                  = 0x00000800,
    IMGFX_FLAG_ANIM_DONE            = 0x00001000,
    IMGFX_FLAG_2000                 = 0x00002000,
    IMGFX_FLAG_4000                 = 0x00004000,
    IMGFX_FLAG_8000                 = 0x00008000,
    IMGFX_FLAG_NO_FILTERING         = 0x00010000,
    IMGFX_FLAG_20000                = 0x00020000,
    IMGFX_FLAG_40000                = 0x00040000,
    IMGFX_FLAG_80000                = 0x00080000,
    IMGFX_FLAG_100000               = 0x00100000,
};

typedef enum ImgFXType {
    IMGFX_CLEAR                     = 0x0,
    IMGFX_UNK_1                     = 0x1,    // unused?
    IMGFX_UNK_2                     = 0x2,    // unused?
    IMGFX_RESET                     = 0x3,    // after goomba 'sticker' ambush in kmr_09 unfurls. might be to force-terminate ANIM.
    IMGFX_SET_WAVY                  = 0x4,    // Kolorado when injured and Sushie when underwater (* note: Sushie fold rendering is bugged and only occurs *before* going underwater)
    IMGFX_SET_ANIM                  = 0x5,
    IMGFX_SET_COLOR                 = 0x6,    // modulate color (args: R, G, B)
    IMGFX_SET_ALPHA                 = 0x7,    // modulate alpha (args: A)
    IMGFX_SET_TINT                  = 0x8,    // modulate color+alpha (args: R, G, B, A)
    IMGFX_SET_WHITE_FADE            = 0x9,
    IMGFX_SET_CREDITS_FADE          = 0xA,
    IMGFX_COLOR_BUF_SET_MULTIPLY    = 0xB,
    IMGFX_COLOR_BUF_SET_MODULATE    = 0xC,    // used for color cycling on Monstar's outline
    IMGFX_HOLOGRAM                  = 0xD,    // ghostly star spirits and merlar (args: ???, staticAmt, ???, alphaAmt)
    IMGFX_FILL_COLOR                = 0xE,    // used to create boss silhouettes in chapter introduction sceens
    IMGFX_OVERLAY                   = 0xF,
    IMGFX_OVERLAY_XLU               = 0x10,   // unused?
    IMGFX_ALLOC_COLOR_BUF           = 0x11,   // (args: count) creates buffer to set color of 'count' vertices
} ImgFXType;

typedef enum ImgFXAnim {
    IMGFX_ANIM_SHOCK                   = 0x00, // used for Goombaria and Goompapa when Kammy drops the hammer block
    IMGFX_ANIM_SHIVER                  = 0x01, // used when Goombaria gives Mario a kiss
    IMGFX_ANIM_VERTICAL_PIPE_CURL      = 0x02, // vertical pipe curl
    IMGFX_ANIM_HORIZONTAL_PIPE_CURL    = 0x03, // horizontal pipe curl
    IMGFX_ANIM_STARTLE                 = 0x04, // used when Koopa Bros are surprised by Mario
    IMGFX_ANIM_FLUTTER_DOWN            = 0x05, // player falling like paper
    IMGFX_ANIM_UNFURL                  = 0x06, // used by Goomba 'stickers' that ambush Mario in area_kmr
    IMGFX_ANIM_GET_IN_BED              = 0x07, // Mario gets into bed
    IMGFX_ANIM_SPIRIT_CAPTURE          = 0x08, // Eldstar being captured
    IMGFX_ANIM_UNUSED_1                = 0x09, // unused
    IMGFX_ANIM_UNUSED_2                = 0x0A, // unused
    IMGFX_ANIM_UNUSED_3                = 0x0B, // unused
    IMGFX_ANIM_TUTANKOOPA_GATHER       = 0x0C, // tutankoopa 3
    IMGFX_ANIM_TUTANKOOPA_SWIRL_2      = 0x0D, // tutankoopa 2
    IMGFX_ANIM_TUTANKOOPA_SWIRL_1      = 0x0E, // tutankoopa 1
    IMGFX_ANIM_SHUFFLE_CARDS           = 0x0F, // merlee spell-casting card shuffle
    IMGFX_ANIM_FLIP_CARD_1             = 0x10, // merlee spell-casting card flip 1
    IMGFX_ANIM_FLIP_CARD_2             = 0x11, // merlee spell-casting card flip 2
    IMGFX_ANIM_FLIP_CARD_3             = 0x12, // merlee spell-casting card flip 3
    IMGFX_ANIM_CYMBAL_CRUSH            = 0x13, // used when Mario is crushed in a Cymbal Plant
} ImgFXAnim;

typedef enum ImgFXRenderType {
    IMGFX_RENDER_DEFAULT               = 0x00,
    IMGFX_RENDER_MULTIPLY_RGB          = 0x01,
    IMGFX_RENDER_MULTIPLY_ALPHA        = 0x02,
    IMGFX_RENDER_MULTIPLY_RGBA         = 0x03,
    IMGFX_RENDER_MODULATE_PRIM_RGB     = 0x04,
    IMGFX_RENDER_MODULATE_PRIM_RGBA    = 0x05,
    IMGFX_RENDER_MULTIPLY_SHADE_RGB    = 0x06,
    IMGFX_RENDER_MULTIPLY_SHADE_ALPHA  = 0x07,
    IMGFX_RENDER_MULTIPLY_SHADE_RGBA   = 0x08,
    IMGFX_RENDER_MODULATE_SHADE_RGB    = 0x09,
    IMGFX_RENDER_MODULATE_SHADE_RGBA   = 0x0A,
    IMGFX_RENDER_ANIM                  = 0x0B,
    IMGFX_RENDER_HOLOGRAM              = 0x0C,
    IMGFX_RENDER_COLOR_FILL            = 0x0D,
    IMGFX_RENDER_OVERLAY_RGB           = 0x0E,
    IMGFX_RENDER_OVERLAY_RGBA          = 0x0F,
    IMGFX_RENDER_UNUSED                = 0x10,
} ImgFXRenderType;

enum ImgFXRenderModeFlags {
    IMGFX_RENDER_NO_OVERRIDE      = 1,
};

typedef enum ImgFXMeshType {
    IMGFX_MESH_DEFAULT                 = 0x0,
    IMGFX_MESH_GRID_WAVY               = 0x1,
    IMGFX_MESH_ANIMATED                = 0x2,
    IMGFX_MESH_GRID_UNUSED             = 0x3,
    IMGFX_MESH_STRIP                   = 0x4,
} ImgFXMeshType;

enum ImgFXHologramTypes {
    IMGFX_HOLOGRAM_NOISE               = 0,
    IMGFX_HOLOGRAM_DITHER              = 1,
    IMGFX_HOLOGRAM_THRESHOLD           = 2,
};

enum SpriteCompImgFXFlags {
    SPR_IMGFX_FLAG_10000000             = 0x10000000,
    SPR_IMGFX_FLAG_20000000             = 0x20000000,
    SPR_IMGFX_FLAG_40000000             = 0x40000000,
    SPR_IMGFX_FLAG_80000000             = 0x80000000,
    SPR_IMGFX_FLAG_ALL                  = 0xF0000000,
};

enum MoveType {
    MOVE_TYPE_NONE          = 0,
    MOVE_TYPE_HAMMER        = 1,
    MOVE_TYPE_JUMP          = 2,
    MOVE_TYPE_3             = 3,
    MOVE_TYPE_ITEMS         = 4,
    MOVE_TYPE_SWITCH        = 5,
    MOVE_TYPE_6             = 6,
    MOVE_TYPE_ATTACK_UP     = 7,
    MOVE_TYPE_DEFENSE_UP    = 8,
    MOVE_TYPE_9             = 9,
    MOVE_TYPE_STAR_POWER    = 10,
    MOVE_TYPE_PARTNER       = 11
};

enum BattleMenuStatus {
    BATTLE_SUBMENU_STATUS_ENABLED           = 1,
    BATTLE_SUBMENU_STATUS_NOT_ENOUGH_FP     = 0,
    BATTLE_SUBMENU_STATUS_NO_TARGETS        = -1,
    BATTLE_SUBMENU_STATUS_NO_TARGETS_2      = -2, // TODO: determine difference, probably uses a different error message
};

enum DictionaryIndex {
    DICTIONARY_KEY   = 0,
    DICTIONARY_VALUE = 1,
    DICTIONARY_SIZE,
};

enum WindowId {
    WINDOW_ID_NONE                              = -1,
    WINDOW_ID_0                                 = 0,
    WINDOW_ID_1                                 = 1,
    WINDOW_ID_2                                 = 2,
    WINDOW_ID_3                                 = 3,
    WINDOW_ID_4                                 = 4,
    WINDOW_ID_5                                 = 5,
    WINDOW_ID_6                                 = 6,
    WINDOW_ID_7                                 = 7,
    WINDOW_ID_8                                 = 8, // battle main?
    WINDOW_ID_BATTLE_POPUP                      = 9,
    WINDOW_ID_ITEM_INFO_NAME                    = 10,
    WINDOW_ID_ITEM_INFO_DESC                    = 11,
    WINDOW_ID_12                                = 12,
    WINDOW_ID_13                                = 13,
    WINDOW_ID_14                                = 14,
    WINDOW_ID_15                                = 15,
    WINDOW_ID_16                                = 16,
    WINDOW_ID_17                                = 17, // brown box used for "Throw away an item" and certain popup titles
    WINDOW_ID_18                                = 18,
    WINDOW_ID_19                                = 19,
    WINDOW_ID_CURRENCY_COUNTER                  = 20,
    WINDOW_ID_21                                = 21,
    WINDOW_ID_PAUSE_MAIN                        = 22,
    WINDOW_ID_PAUSE_DECRIPTION                  = 23,
    WINDOW_ID_FILEMENU_CURSOR                   = 23, // same as previous
    WINDOW_ID_PAUSE_TUTORIAL                    = 24,
    WINDOW_ID_FILEMENU_COPYARROW                = 24, // same as previous
    WINDOW_ID_PAUSE_TAB_STATS                   = 25,
    WINDOW_ID_PAUSE_TAB_BADGES                  = 26,
    WINDOW_ID_PAUSE_TAB_ITEMS                   = 27,
    WINDOW_ID_PAUSE_TAB_PARTY                   = 28,
    WINDOW_ID_PAUSE_TAB_SPIRITS                 = 29,
    WINDOW_ID_PAUSE_TAB_MAP                     = 30,
    WINDOW_ID_PAUSE_STATS                       = 31,
    WINDOW_ID_PAUSE_BADGES                      = 32,
    WINDOW_ID_PAUSE_ITEMS                       = 33,
    WINDOW_ID_PAUSE_PARTNERS                    = 34,
    WINDOW_ID_PAUSE_PARTNERS_TITLE              = 35,
    WINDOW_ID_PAUSE_PARTNERS_MOVELIST           = 36,
    WINDOW_ID_PAUSE_PARTNERS_MOVELIST_TITLE     = 37,
    WINDOW_ID_PAUSE_PARTNERS_MOVELIST_FLOWER    = 38,
    WINDOW_ID_PAUSE_SPIRITS                     = 39,
    WINDOW_ID_PAUSE_SPIRITS_TITLE               = 40,
    WINDOW_ID_PAUSE_MAP                         = 41,
    WINDOW_ID_PAUSE_MAP_TITLE                   = 42,
    WINDOW_ID_PAUSE_TAB_INVIS                   = 43,
    WINDOW_ID_PAUSE_CURSOR                      = 44,
    WINDOW_ID_FILEMENU_MAIN                     = 44, // same as previous
    WINDOW_ID_FILEMENU_TITLE                    = 45,
    WINDOW_ID_FILEMENU_YESNO_PROMPT             = 46,
    WINDOW_ID_FILEMENU_INFO                     = 47,
    WINDOW_ID_FILEMENU_CREATEFILE_HEADER        = 48,
    WINDOW_ID_FILEMENU_KEYBOARD                 = 49,
    WINDOW_ID_FILEMENU_YESNO_OPTIONS            = 50,
    WINDOW_ID_FILEMENU_STEREO                   = 51,
    WINDOW_ID_FILEMENU_MONO                     = 52,
    WINDOW_ID_FILEMENU_OPTION_LEFT              = 53,
    WINDOW_ID_FILEMENU_OPTION_CENTER            = 54,
    WINDOW_ID_FILEMENU_OPTION_RIGHT             = 55,
    WINDOW_ID_FILEMENU_FILE0_INFO               = 56,
    WINDOW_ID_FILEMENU_FILE1_INFO               = 57,
    WINDOW_ID_FILEMENU_FILE2_INFO               = 58,
    WINDOW_ID_FILEMENU_FILE3_INFO               = 59,
    WINDOW_ID_FILEMENU_FILE0_TITLE              = 60,
    WINDOW_ID_FILEMENU_FILE1_TITLE              = 61,
    WINDOW_ID_FILEMENU_FILE2_TITLE              = 62,
    WINDOW_ID_FILEMENU_FILE3_TITLE              = 63,
};

enum SimpleWindowUpdateId {
    WINDOW_UPDATE_SHOW              = 1,
    WINDOW_UPDATE_HIDE              = 2,
    WINDOW_UPDATE_HIER_UPDATE       = 3,
    WINDOW_UPDATE_DARKENED          = 4,
    WINDOW_UPDATE_TRANSPARENT       = 5,
    WINDOW_UPDATE_OPAQUE            = 6,
    WINDOW_UPDATE_SHOW_TRANSPARENT  = 7,
    WINDOW_UPDATE_SHOW_DARKENED     = 8,
    WINDOW_UPDATE_9                 = 9,
};

enum WindowGroupId {
    WINDOW_GROUP_ALL = 0,
    WINDOW_GROUP_1 = 1,
    WINDOW_GROUP_PAUSE_MENU = 2,
    WINDOW_GROUP_FILE_MENU = 3,
};

enum RushFlags {
    RUSH_FLAG_NONE  = 0,
    RUSH_FLAG_MEGA  = 1,
    RUSH_FLAG_POWER = 2,
};

enum FileMenuMessages {
    /*  0 */ FILE_MESSAGE_NONE,
    /*  1 */ FILE_MESSAGE_SELECT_FILE_TO_START,        // Select file to start:[End]
    /*  2 */ FILE_MESSAGE_SELECT_FILE_TO_DELETE,       // Select file to delete:[End]
#if !VERSION_PAL
    /*  3 */ FILE_MESSAGE_SELECT_FILE_TO_SAVE,         // Select file to save[End]
#endif
    /*  4 */ FILE_MESSAGE_COPY_WHICH_FILE,             // Copy which file?[End]
    /*  5 */ FILE_MESSAGE_COPY_TO_WHICH_FILE,          // Copy to which file?[End]
    /*  6 */ FILE_MESSAGE_NEW,                         // NEW[End]
    /*  7 */ FILE_MESSAGE_LEVEL,                       // Level[End]
    /*  8 */ FILE_MESSAGE_PLAY_TIME,                   // Play Time[End]
    /*  9 */ FILE_MESSAGE_DELETE_FILE,                 // Delete File[End]
    /* 10 */ FILE_MESSAGE_CANCEL,                      // Cancel[End]
    /* 11 */ FILE_MESSAGE_COPY_FILE,                   // Copy File[End]
    /* 12 */ FILE_MESSAGE_FIRST_PLAY,                  // First Play[End]
    /* 13 */ FILE_MESSAGE_PERIOD_13,                   // .[End]
    /* 14 */ FILE_MESSAGE_YES,                         // Yes[End]
    /* 15 */ FILE_MESSAGE_NO,                          // No[End]
    /* 16 */ FILE_MESSAGE_DELETE,                      // Delete[End]
    /* 17 */ FILE_MESSAGE_OVERRIDE_TO_NEW_DATA,        // Override to New Data[End]
    /* 18 */ FILE_MESSAGE_SAVE_OK,                     // Save OK?[End]
    /* 19 */ FILE_MESSAGE_FILE_NAME_IS,                // File name is :[End]
    /* 20 */ FILE_MESSAGE_PERIOD_20,                   // .[End]
    /* 21 */ FILE_MESSAGE_OK,                          // OK?[End]
    /* 22 */ FILE_MESSAGE_FILE_22,                     // File[End]
    /* 23 */ FILE_MESSAGE_WILL_BE_DELETED,             // will be deleted.[End]
    /* 24 */ FILE_MESSAGE_OK_TO_COPY_TO_THIS_FILE,     // OK to copy to this file?[End]
    /* 25 */ FILE_MESSAGE_START_GAME_WITH,             // Start game with[End]
    /* 26 */ FILE_MESSAGE_FILE_26,                     // File[End]
    /* 27 */ FILE_MESSAGE_HAS_BEEN_DELETED,            // has been deleted.[End]
    /* 28 */ FILE_MESSAGE_28,                          // [End]
    /* 29 */ FILE_MESSAGE_COPY_FROM,                   // Copy from[End]
    /* 30 */ FILE_MESSAGE_TO,                          // to[End]
    /* 31 */ FILE_MESSAGE_HAS_BEEN_CREATED,            // has been created.[End]
#if VERSION_PAL
    // TODO: determine where these new entries should be placed
    UNK1,
    UNK2,
#endif
    /* 32 */ FILE_MESSAGE_ENTER_A_FILE_NAME,           // Enter a file name![End]
    /* 33 */ FILE_MESSAGE_QUESTION,                    // ?[End]
    /* 34 */ FILE_MESSAGE_PERIOD_34,                   // .[End]
#if VERSION_PAL
    FILE_MESSAGE_BASE_UNK,
#endif
};

// specifically used with draw_msg, not to be confused with MsgStyles
enum DrawMsgStyleFlags {
    DRAW_MSG_STYLE_MENU             = 1, // slightly higher baseline with smaller fullspace widths
    DRAW_MSG_STYLE_WAVY             = 2,
    DRAW_MSG_STYLE_RAINBOW          = 4,
    DRAW_MSG_STYLE_DROP_SHADOW      = 8,
};

// used with draw_number
enum DrawNumberStyleFlags {
    DRAW_NUMBER_STYLE_ALIGN_RIGHT       = 1, ///< drawn to the left of posX
    DRAW_NUMBER_STYLE_MONOSPACE         = 2,
    DRAW_NUMBER_STYLE_MONOSPACE_RIGHT   = 3, // combination of MONOSPACE and ALIGN_RIGHT
    DRAW_NUMBER_STYLE_DROP_SHADOW       = 4,
};

enum DrawNumberCharsets {
    DRAW_NUMBER_CHARSET_NORMAL = 0,
    DRAW_NUMBER_CHARSET_THIN   = 1,
};

enum MsgPalettes {
    MSG_PAL_WHITE                   = 0x00,
    MSG_PAL_TEAL                    = 0x01,
    MSG_PAL_BLUE                    = 0x02,
    MSG_PAL_GREEN                   = 0x03,
    MSG_PAL_LIME                    = 0x04,
    MSG_PAL_YELLOW                  = 0x05,
    MSG_PAL_ORANGE                  = 0x06,
    MSG_PAL_RED                     = 0x07,
    MSG_PAL_PURPLE                  = 0x08,
    MSG_PAL_PINK                    = 0x09,
    MSG_PAL_STANDARD                = 0x0A,
    MSG_PAL_0B                      = 0x0B,
    MSG_PAL_0C                      = 0x0C,
    MSG_PAL_0D                      = 0x0D,
    MSG_PAL_0E                      = 0x0E,
    MSG_PAL_0F                      = 0x0F,
    MSG_PAL_10                      = 0x10,
    MSG_PAL_11                      = 0x11,
    MSG_PAL_12                      = 0x12,
    MSG_PAL_13                      = 0x13,
    MSG_PAL_14                      = 0x14,
    MSG_PAL_15                      = 0x15,
    MSG_PAL_16                      = 0x16,
    MSG_PAL_17                      = 0x17,
    MSG_PAL_18                      = 0x18,
    MSG_PAL_19                      = 0x19,
    MSG_PAL_1A                      = 0x1A,
    MSG_PAL_1B                      = 0x1B,
    MSG_PAL_1C                      = 0x1C,
    MSG_PAL_1D                      = 0x1D,
    MSG_PAL_1E                      = 0x1E,
    MSG_PAL_1F                      = 0x1F,
    MSG_PAL_20                      = 0x20,
    MSG_PAL_21                      = 0x21,
    MSG_PAL_22                      = 0x22,
    MSG_PAL_23                      = 0x23,
    MSG_PAL_24                      = 0x24,
    MSG_PAL_25                      = 0x25,
    MSG_PAL_26                      = 0x26,
    MSG_PAL_27                      = 0x27,
    MSG_PAL_28                      = 0x28,
    MSG_PAL_29                      = 0x29,
    MSG_PAL_2A                      = 0x2A,
    MSG_PAL_2B                      = 0x2B,
    MSG_PAL_2C                      = 0x2C,
    MSG_PAL_2D                      = 0x2D,
    MSG_PAL_2E                      = 0x2E,
    MSG_PAL_2F                      = 0x2F,
    MSG_PAL_30                      = 0x30,
    MSG_PAL_31                      = 0x31,
    MSG_PAL_32                      = 0x32,
    MSG_PAL_33                      = 0x33,
    MSG_PAL_34                      = 0x34,
    MSG_PAL_35                      = 0x35,
    MSG_PAL_36                      = 0x36,
    MSG_PAL_37                      = 0x37,
    MSG_PAL_38                      = 0x38,
    MSG_PAL_39                      = 0x39,
    MSG_PAL_3A                      = 0x3A,
    MSG_PAL_3B                      = 0x3B,
    MSG_PAL_3C                      = 0x3C,
    MSG_PAL_3D                      = 0x3D,
    MSG_PAL_3E                      = 0x3E,
    MSG_PAL_3F                      = 0x3F,
    MSG_PAL_40                      = 0x40,
    MSG_PAL_41                      = 0x41,
    MSG_PAL_42                      = 0x42,
    MSG_PAL_43                      = 0x43,
    MSG_PAL_44                      = 0x44,
    MSG_PAL_45                      = 0x45,
    MSG_PAL_46                      = 0x46,
    MSG_PAL_47                      = 0x47,
    MSG_PAL_48                      = 0x48,
    MSG_PAL_49                      = 0x49,
    MSG_PAL_4A                      = 0x4A,
    MSG_PAL_4B                      = 0x4B,
    MSG_PAL_4C                      = 0x4C,
    MSG_PAL_4D                      = 0x4D,
    MSG_PAL_4E                      = 0x4E,
    MSG_PAL_4F                      = 0x4F,
    MSG_PAL_50                      = 0x50
};

enum MsgChars {
    MSG_CHAR_NOTE                   = 0x00,
    MSG_CHAR_EXCLAMTION             = 0x01,
    MSG_CHAR_BACKSLASH              = 0x02,
    MSG_CHAR_HASH                   = 0x03,
    MSG_CHAR_DOLLAR                 = 0x04,
    MSG_CHAR_PERCENT                = 0x05,
    MSG_CHAR_AND                    = 0x06,
    MSG_CHAR_APOSTROPHE             = 0x07,
    MSG_CHAR_LPAREN                 = 0x08,
    MSG_CHAR_RPAREN                 = 0x09,
    MSG_CHAR_TIMES                  = 0x0A,
    MSG_CHAR_PLUS                   = 0x0B,
    MSG_CHAR_COMMA                  = 0x0C,
    MSG_CHAR_MINUS                  = 0x0D,
    MSG_CHAR_PERIOD                 = 0x0E,
    MSG_CHAR_FORWARDSLASH           = 0x0F,
    MSG_CHAR_DIGIT_0                = 0x10,
    MSG_CHAR_DIGIT_1                = 0x11,
    MSG_CHAR_DIGIT_2                = 0x12,
    MSG_CHAR_DIGIT_3                = 0x13,
    MSG_CHAR_DIGIT_4                = 0x14,
    MSG_CHAR_DIGIT_5                = 0x15,
    MSG_CHAR_DIGIT_6                = 0x16,
    MSG_CHAR_DIGIT_7                = 0x17,
    MSG_CHAR_DIGIT_8                = 0x18,
    MSG_CHAR_DIGIT_9                = 0x19,
    MSG_CHAR_COLON                  = 0x1A,
    MSG_CHAR_SEMICOLON              = 0x1B,
    MSG_CHAR_LESS_THAN              = 0x1C,
    MSG_CHAR_EQUAL                  = 0x1D,
    MSG_CHAR_GREATER_THAN           = 0x1E,
    MSG_CHAR_QUESTION               = 0x1F,
    MSG_CHAR_AT                     = 0x20,
    MSG_CHAR_UPPER_A                = 0x21,
    MSG_CHAR_UPPER_B                = 0x22,
    MSG_CHAR_UPPER_C                = 0x23,
    MSG_CHAR_UPPER_D                = 0x24,
    MSG_CHAR_UPPER_E                = 0x25,
    MSG_CHAR_UPPER_F                = 0x26,
    MSG_CHAR_UPPER_G                = 0x27,
    MSG_CHAR_UPPER_H                = 0x28,
    MSG_CHAR_UPPER_I                = 0x29,
    MSG_CHAR_UPPER_J                = 0x2A,
    MSG_CHAR_UPPER_K                = 0x2B,
    MSG_CHAR_UPPER_L                = 0x2C,
    MSG_CHAR_UPPER_M                = 0x2D,
    MSG_CHAR_UPPER_N                = 0x2E,
    MSG_CHAR_UPPER_O                = 0x2F,
    MSG_CHAR_UPPER_P                = 0x30,
    MSG_CHAR_UPPER_Q                = 0x31,
    MSG_CHAR_UPPER_R                = 0x32,
    MSG_CHAR_UPPER_S                = 0x33,
    MSG_CHAR_UPPER_T                = 0x34,
    MSG_CHAR_UPPER_U                = 0x35,
    MSG_CHAR_UPPER_V                = 0x36,
    MSG_CHAR_UPPER_W                = 0x37,
    MSG_CHAR_UPPER_X                = 0x38,
    MSG_CHAR_UPPER_Y                = 0x39,
    MSG_CHAR_UPPER_Z                = 0x3A,
    MSG_CHAR_LBRACKET               = 0x3B,
    MSG_CHAR_YEN                    = 0x3C,
    MSG_CHAR_RBRACKET               = 0x3D,
    MSG_CHAR_CARET                  = 0x3E,
    MSG_CHAR_UNDERSCORE             = 0x3F,
    MSG_CHAR_BACKTICK               = 0x40,
    MSG_CHAR_LOWER_A                = 0x41,
    MSG_CHAR_LOWER_B                = 0x42,
    MSG_CHAR_LOWER_C                = 0x43,
    MSG_CHAR_LOWER_D                = 0x44,
    MSG_CHAR_LOWER_E                = 0x45,
    MSG_CHAR_LOWER_F                = 0x46,
    MSG_CHAR_LOWER_G                = 0x47,
    MSG_CHAR_LOWER_H                = 0x48,
    MSG_CHAR_LOWER_I                = 0x49,
    MSG_CHAR_LOWER_J                = 0x4A,
    MSG_CHAR_LOWER_K                = 0x4B,
    MSG_CHAR_LOWER_L                = 0x4C,
    MSG_CHAR_LOWER_M                = 0x4D,
    MSG_CHAR_LOWER_N                = 0x4E,
    MSG_CHAR_LOWER_O                = 0x4F,
    MSG_CHAR_LOWER_P                = 0x50,
    MSG_CHAR_LOWER_Q                = 0x51,
    MSG_CHAR_LOWER_R                = 0x52,
    MSG_CHAR_LOWER_S                = 0x53,
    MSG_CHAR_LOWER_T                = 0x54,
    MSG_CHAR_LOWER_U                = 0x55,
    MSG_CHAR_LOWER_V                = 0x56,
    MSG_CHAR_LOWER_W                = 0x57,
    MSG_CHAR_LOWER_X                = 0x58,
    MSG_CHAR_LOWER_Y                = 0x59,
    MSG_CHAR_LOWER_Z                = 0x5A,
    MSG_CHAR_LCURLY                 = 0x5B,
    MSG_CHAR_PIPE                   = 0x5C,
    MSG_CHAR_RCURLY                 = 0x5D,
    MSG_CHAR_TILDA                  = 0x5E,
    MSG_CHAR_DEGREE                 = 0x5F,
    MSG_CHAR_UPPER_A_GRAVE          = 0x60,
    MSG_CHAR_UPPER_A_ACUTE          = 0x61,
    MSG_CHAR_UPPER_A_CIRCUMFLEX     = 0x62,
    MSG_CHAR_UPPER_A_UMLAUT         = 0x63,
    MSG_CHAR_UPPER_C_CEDILLA        = 0x64,
    MSG_CHAR_UPPER_E_GRAVE          = 0x65,
    MSG_CHAR_UPPER_E_ACUTE          = 0x66,
    MSG_CHAR_UPPER_E_CIRCUMFLEX     = 0x67,
    MSG_CHAR_UPPER_E_UMLAUT         = 0x68,
    MSG_CHAR_UPPER_I_GRAVE          = 0x69,
    MSG_CHAR_UPPER_I_ACUTE          = 0x6A,
    MSG_CHAR_UPPER_I_CIRCUMFLEX     = 0x6B,
    MSG_CHAR_UPPER_I_UMLAUT         = 0x6C,
    MSG_CHAR_UPPER_N_TILDE          = 0x6D,
    MSG_CHAR_UPPER_O_GRAVE          = 0x6E,
    MSG_CHAR_UPPER_O_ACUTE          = 0x6F,
    MSG_CHAR_UPPER_O_CIRCUMFLEX     = 0x70,
    MSG_CHAR_UPPER_O_UMLAUT         = 0x71,
    MSG_CHAR_UPPER_U_GRAVE          = 0x72,
    MSG_CHAR_UPPER_U_ACUTE          = 0x73,
    MSG_CHAR_UPPER_U_CIRCUMFLEX     = 0x74,
    MSG_CHAR_UPPER_U_UMLAUT         = 0x75,
    MSG_CHAR_SHARP_S                = 0x76,
    MSG_CHAR_LOWER_A_GRAVE          = 0x77,
    MSG_CHAR_LOWER_A_ACUTE          = 0x78,
    MSG_CHAR_LOWER_A_CIRCUMFLEX     = 0x79,
    MSG_CHAR_LOWER_A_UMLAUT         = 0x7A,
    MSG_CHAR_LOWER_C_CEDILLA        = 0x7B,
    MSG_CHAR_LOWER_E_GRAVE          = 0x7C,
    MSG_CHAR_LOWER_E_ACUTE          = 0x7D,
    MSG_CHAR_LOWER_E_CIRCUMFLEX     = 0x7E,
    MSG_CHAR_LOWER_E_UMLAUT         = 0x7F,
    MSG_CHAR_LOWER_I_GRAVE          = 0x80,
    MSG_CHAR_LOWER_I_ACUTE          = 0x81,
    MSG_CHAR_LOWER_I_CIRCUMFLEX     = 0x82,
    MSG_CHAR_LOWER_I_UMLAUT         = 0x83,
    MSG_CHAR_LOWER_N_TILDE          = 0x84,
    MSG_CHAR_LOWER_O_GRAVE          = 0x85,
    MSG_CHAR_LOWER_O_ACUTE          = 0x86,
    MSG_CHAR_LOWER_O_CIRCUMFLEX     = 0x87,
    MSG_CHAR_LOWER_O_UMLAUT         = 0x88,
    MSG_CHAR_LOWER_U_GRAVE          = 0x89,
    MSG_CHAR_LOWER_U_ACUTE          = 0x8A,
    MSG_CHAR_LOWER_U_CIRCUMFLEX     = 0x8B,
    MSG_CHAR_LOWER_U_UMLAUT         = 0x8C,
    MSG_CHAR_INVERTED_EXCLAMTION    = 0x8D,
    MSG_CHAR_INVERTED_QUESTION      = 0x8E,
    MSG_CHAR_FEM_ORDINAL            = 0x8F,
    MSG_CHAR_HEART                  = 0x90,
    MSG_CHAR_STAR                   = 0x91,
    MSG_CHAR_UP                     = 0x92,
    MSG_CHAR_DOWN                   = 0x93,
    MSG_CHAR_LEFT                   = 0x94,
    MSG_CHAR_RIGHT                  = 0x95,
    MSG_CHAR_CIRCLE                 = 0x96,
    MSG_CHAR_CROSS                  = 0x97,
    MSG_CHAR_BUTTON_A               = 0x98,
    MSG_CHAR_BUTTON_B               = 0x99,
    MSG_CHAR_BUTTON_L               = 0x9A,
    MSG_CHAR_BUTTON_R               = 0x9B,
    MSG_CHAR_BUTTON_Z               = 0x9C,
    MSG_CHAR_BUTTON_C_UP            = 0x9D,
    MSG_CHAR_BUTTON_C_DOWN          = 0x9E,
    MSG_CHAR_BUTTON_C_LEFT          = 0x9F,
    MSG_CHAR_BUTTON_C_RIGHT         = 0xA0,
    MSG_CHAR_BUTTON_START           = 0xA1,
    MSG_CHAR_DOUBLE_QUOTE_OPEN      = 0xA2,
    MSG_CHAR_DOUBLE_QUOTE_CLOSE     = 0xA3,
    MSG_CHAR_SINGLE_QUOTE_OPEN      = 0xA4,
    MSG_CHAR_SINGLE_QUOTE_CLOSE     = 0xA5,
    // 0xA6 to 0xEF are unused

#if VERSION_IQUE
    // All US characters are in the rom, but their range is used for multibyte characters
    MSG_CHAR_MULTIBYTE_FIRST        = 0x5F,
    MSG_CHAR_MULTIBYTE_LAST         = 0x8F,
    MSG_CHAR_ZH_START               = 0xA6,
    MSG_CHAR_ZH_RANK                = 0x33F, // 勋
    MSG_CHAR_ZH_CHAPTER             = 0x340, // 章
#endif

    MSG_CHAR_UNK_C3                 = 0xC3,

    // special character codes used when reading from the source buffer
    MSG_CHAR_READ_ENDL              = 0xF0,
    MSG_CHAR_READ_WAIT              = 0xF1,
    MSG_CHAR_READ_PAUSE             = 0xF2,
    MSG_CHAR_READ_VARIANT0          = 0xF3,
    MSG_CHAR_READ_VARIANT1          = 0xF4,
    MSG_CHAR_READ_VARIANT2          = 0xF5,
    MSG_CHAR_READ_VARIANT3          = 0xF6,
    MSG_CHAR_READ_SPACE             = 0xF7,
    MSG_CHAR_READ_FULL_SPACE        = 0xF8,
    MSG_CHAR_READ_HALF_SPACE        = 0xF9,
    MSG_CHAR_READ_UNK_CHAR_FA       = 0xFA,
    MSG_CHAR_READ_NEXT              = 0xFB,
    MSG_CHAR_READ_STYLE             = 0xFC,
    MSG_CHAR_READ_END               = 0xFD,
    // 0xFE unused
    MSG_CHAR_READ_FUNCTION          = 0xFF,

    // special character codes used when writing to the print buffer
    MSG_CONTROL_CHAR                = 0xF0,
    MSG_CHAR_PRINT_ENDL             = 0xF0,
    MSG_CHAR_PRINT_VARIANT0         = 0xF1,
    MSG_CHAR_PRINT_VARIANT1         = 0xF2,
    MSG_CHAR_PRINT_VARIANT2         = 0xF3,
    MSG_CHAR_PRINT_VARIANT3         = 0xF4,
    MSG_CHAR_PRINT_SPACE            = 0xF5,
    MSG_CHAR_PRINT_FULL_SPACE       = 0xF6,
    MSG_CHAR_PRINT_HALF_SPACE       = 0xF7,
    MSG_CHAR_PRINT_STYLE            = 0xF8,
    MSG_CHAR_PRINT_UNK_CHAR_FA      = 0xF9,
    MSG_CHAR_PRINT_NEXT             = 0xFA,
    MSG_CHAR_PRINT_END              = 0xFB,
    // FC unused
    // FD unused
    // FE unused
    MSG_CHAR_PRINT_FUNCTION         = 0xFF
};

enum MsgFunctionCodes {
    // function codes used when reading from the source buffer
    MSG_READ_FUNC_FONT                   = 0x00,
    MSG_READ_FUNC_VARIANT                = 0x01,
    MSG_READ_FUNC_SET_FRAME_PALETTE      = 0x02,
    MSG_READ_FUNC_RESET_GFX              = 0x03,
    MSG_READ_FUNC_YIELD                  = 0x04,
    MSG_READ_FUNC_COLOR                  = 0x05,
    MSG_READ_FUNC_NO_SKIP                = 0x06,
    MSG_READ_FUNC_INPUT_OFF              = 0x07,
    MSG_READ_FUNC_INPUT_ON               = 0x08,
    MSG_READ_FUNC_DELAY_OFF              = 0x09,
    MSG_READ_FUNC_DELAY_ON               = 0x0A,
    MSG_READ_FUNC_SPACING                = 0x0B,
    MSG_READ_FUNC_SCROLL                 = 0x0C,
    MSG_READ_FUNC_SIZE                   = 0x0D,
    MSG_READ_FUNC_SIZE_RESET             = 0x0E,
    MSG_READ_FUNC_SPEED                  = 0x0F,
    MSG_READ_FUNC_SET_X                  = 0x10,
    MSG_READ_FUNC_SET_Y                  = 0x11,
    MSG_READ_FUNC_RIGHT                  = 0x12,
    MSG_READ_FUNC_DOWN                   = 0x13,
    MSG_READ_FUNC_UP                     = 0x14,
    MSG_READ_FUNC_INLINE_IMAGE           = 0x15,
    MSG_READ_FUNC_ANIM_SPRITE            = 0x16,
    MSG_READ_FUNC_ITEM_ICON              = 0x17,
    MSG_READ_FUNC_IMAGE                  = 0x18,
    MSG_READ_FUNC_HIDE_IMAGE             = 0x19,
    MSG_READ_FUNC_ANIM_DELAY             = 0x1A,
    MSG_READ_FUNC_ANIM_LOOP              = 0x1B,
    MSG_READ_FUNC_ANIM_DONE              = 0x1C,
    MSG_READ_FUNC_SET_CURSOR             = 0x1D,
    MSG_READ_FUNC_CURSOR                 = 0x1E,
    MSG_READ_FUNC_END_CHOICE             = 0x1F,
    MSG_READ_FUNC_SET_CANCEL             = 0x20,
    MSG_READ_FUNC_OPTION                 = 0x21,
    MSG_READ_FUNC_SAVE_POS               = 0x22,
    MSG_READ_FUNC_RESTORE_POS            = 0x23,
    MSG_READ_FUNC_SAVE_COLOR             = 0x24,
    MSG_READ_FUNC_RESTORE_COLOR          = 0x25,
    MSG_READ_FUNC_START_FX               = 0x26,
    MSG_READ_FUNC_END_FX                 = 0x27,
    MSG_READ_FUNC_VAR                    = 0x28,
    MSG_READ_FUNC_CENTER_X               = 0x29,
    MSG_READ_FUNC_SET_REWIND             = 0x2A,
    MSG_READ_FUNC_ENABLE_CDOWN_NEXT      = 0x2B,
    MSG_READ_FUNC_CUSTOM_VOICE           = 0x2C,
    MSG_READ_FUNC_VOLUME                 = 0x2E,
    MSG_READ_FUNC_VOICE                  = 0x2F,
    // function codes used when writing to the print buffer
    MSG_PRINT_FUNC_FONT                  = 0x00,
    MSG_PRINT_FUNC_VARIANT               = 0x01,
    MSG_PRINT_FUNC_SET_FRAME_PALETTE     = 0x16,
    MSG_PRINT_RESET_GFX                  = 0x17,
    MSG_PRINT_FUNC_COLOR                 = 0x04,
    MSG_PRINT_FUNC_SPACING               = 0x05,
    MSG_PRINT_FUNC_SCROLL                = 0xFA,
    MSG_PRINT_FUNC_SIZE                  = 0x06,
    MSG_PRINT_FUNC_SIZE_RESET            = 0x07,
    MSG_PRINT_FUNC_SET_X                 = 0x08,
    MSG_PRINT_FUNC_SET_Y                 = 0x09,
    MSG_PRINT_FUNC_RIGHT                 = 0x0A,
    MSG_PRINT_FUNC_DOWN                  = 0x0B,
    MSG_PRINT_FUNC_UP                    = 0x0C,
    MSG_PRINT_FUNC_INLINE_IMAGE          = 0x0E,
    MSG_PRINT_FUNC_ANIM_SPRITE           = 0x0F,
    MSG_PRINT_FUNC_ITEM_ICON             = 0x10,
    MSG_PRINT_FUNC_ANIM_DELAY            = 0x11,
    MSG_PRINT_FUNC_ANIM_LOOP             = 0x12,
    MSG_PRINT_FUNC_ANIM_DONE             = 0x13,
    MSG_PRINT_FUNC_CURSOR                = 0x14,
    MSG_PRINT_FUNC_OPTION                = 0x15,
    MSG_PRINT_FUNC_SAVE_POS              = 0x18,
    MSG_PRINT_FUNC_RESTORE_POS           = 0x19,
    MSG_PRINT_FUNC_SAVE_COLOR            = 0x1A,
    MSG_PRINT_FUNC_RESTORE_COLOR         = 0x1B,
    MSG_PRINT_FUNC_START_FX              = 0x1C,
    MSG_PRINT_FUNC_END_FX                = 0x1D,
    MSG_PRINT_FUNC_CENTER_X              = 0x1E
};

enum MsgEffectCodes {
    MSG_FX_SHAKE                    = 0x00,
    MSG_FX_WAVE                     = 0x01,
    MSG_FX_NOISE_OUTLINE            = 0x02,
    MSG_FX_STATIC                   = 0x03,
    MSG_FX_BLUR                     = 0x05,
    MSG_FX_RAINBOW                  = 0x06,
    MSG_FX_DITHER_FADE              = 0x07,
    MSG_FX_GLOBAL_WAVE              = 0x08,
    MSG_FX_GLOBAL_RAINBOW           = 0x09,
    MSG_FX_RISE_PRINT               = 0x0A,
    MSG_FX_GROW_PRINT               = 0x0B,
    MSG_FX_SIZE_JITTER              = 0x0C,
    MSG_FX_SIZE_WAVE                = 0x0D,
    MSG_FX_DROP_SHADOW              = 0x0E
};

enum MsgEffectFlags {
    MSG_FX_FLAG_SHAKE               = 0x00001,
    MSG_FX_FLAG_WAVE                = 0x00002,
    MSG_FX_FLAG_NOISE_OUTLINE       = 0x00004,
    MSG_FX_FLAG_BLUR                = 0x00020,
    MSG_FX_FLAG_RAINBOW             = 0x00040,
    MSG_FX_FLAG_DITHER_FADE         = 0x00080,
    MSG_FX_FLAG_GLOBAL_WAVE         = 0x00200,
    MSG_FX_FLAG_GLOBAL_RAINBOW      = 0x00400,
    MSG_FX_FLAG_RISE_PRINT          = 0x00800,
    MSG_FX_FLAG_GROW_PRINT          = 0x01000,
    MSG_FX_FLAG_SIZE_JITTER         = 0x02000,
    MSG_FX_FLAG_SIZE_WAVE           = 0x04000,
    MSG_FX_FLAG_DROP_SHADOW         = 0x08000,
    MSG_FX_FLAG_STATIC              = 0x10000
};

enum MsgStyles {
    MSG_STYLE_NONE                  = 0x0,
    MSG_STYLE_RIGHT                 = 0x1,
    MSG_STYLE_LEFT                  = 0x2,
    MSG_STYLE_CENTER                = 0x3,
    MSG_STYLE_TATTLE                = 0x4,
    MSG_STYLE_CHOICE                = 0x5,
    MSG_STYLE_INSPECT               = 0x6,
    MSG_STYLE_SIGN                  = 0x7,
    MSG_STYLE_LAMPPOST              = 0x8,
    MSG_STYLE_POSTCARD              = 0x9,
    MSG_STYLE_POPUP                 = 0xA,
    MSG_STYLE_B                     = 0xB,
    MSG_STYLE_UPGRADE               = 0xC,
    MSG_STYLE_NARRATE               = 0xD,
    MSG_STYLE_EPILOGUE              = 0xE,
    MSG_STYLE_F                     = 0xF
};

enum MsgFonts {
    MSG_FONT_NORMAL                 = 0,
    MSG_FONT_MENU                   = 1,
    MSG_FONT_2                      = 2,
    MSG_FONT_TITLE                  = 3,
    MSG_FONT_SUBTITLE               = 4,
};

enum MsgVoices {
    MSG_VOICE_NORMAL                = 0,
    MSG_VOICE_BOWSER                = 1,
    MSG_VOICE_STAR                  = 2
};

enum MsgPrintModeFlags {
    MSG_PRINT_FLAG_1                = 0x001,
    MSG_PRINT_FLAG_2                = 0x002,
    MSG_PRINT_FLAG_10               = 0x010,
    MSG_PRINT_FLAG_20               = 0x020,
    MSG_PRINT_FLAG_40               = 0x040,
    MSG_PRINT_FLAG_80               = 0x080,
    MSG_PRINT_FLAG_100              = 0x100,
};

enum MsgStateFlags {
    MSG_STATE_FLAG_1                = 0x000001,
    MSG_STATE_FLAG_2                = 0x000002,
    MSG_STATE_FLAG_4                = 0x000004,
    MSG_STATE_FLAG_10               = 0x000010,
    MSG_STATE_FLAG_20               = 0x000020,
    MSG_STATE_FLAG_40               = 0x000040,
    MSG_STATE_FLAG_SPEAKING         = 0x000080, // determines animation of speaker (talk vs idle)
    MSG_STATE_FLAG_PRINT_QUICKLY    = 0x000100,
    MSG_STATE_FLAG_400              = 0x000400,
    MSG_STATE_FLAG_800              = 0x000800,
    MSG_STATE_FLAG_1000             = 0x001000,
    MSG_STATE_FLAG_4000             = 0x004000,
    MSG_STATE_FLAG_8000             = 0x008000,
    MSG_STATE_FLAG_10000            = 0x010000,
    MSG_STATE_FLAG_20000            = 0x020000,
    MSG_STATE_FLAG_40000            = 0x040000,
    MSG_STATE_FLAG_80000            = 0x080000,
    MSG_STATE_FLAG_100000           = 0x100000,
    MSG_STATE_FLAG_800000           = 0x800000,
};

enum MsgDelayFlags {
    MSG_DELAY_FLAG_1                = 0x000001,
    MSG_DELAY_FLAG_2                = 0x000002,
    MSG_DELAY_FLAG_4                = 0x000004,
};

enum MsgWindowStates {
    MSG_WINDOW_STATE_DONE               = 0x0,
    MSG_WINDOW_STATE_INIT               = 0x1,
    MSG_WINDOW_STATE_OPENING            = 0x2,
    MSG_WINDOW_STATE_CLOSING            = 0x3,
    MSG_WINDOW_STATE_PRINTING           = 0x4,
    MSG_WINDOW_STATE_WAITING            = 0x5,
    MSG_WINDOW_STATE_SCROLLING          = 0x6,
    MSG_WINDOW_STATE_WAITING_FOR_CHOICE = 0x7,
    MSG_WINDOW_STATE_SCROLLING_BACK     = 0x8,
    MSG_WINDOW_STATE_VIEWING_PREV       = 0x9,
    MSG_WINDOW_STATE_A                  = 0xA,
    MSG_WINDOW_STATE_B                  = 0xB,
    MSG_WINDOW_STATE_C                  = 0xC,
    MSG_WINDOW_STATE_D                  = 0xD,
    MSG_WINDOW_STATE_E                  = 0xE,
};

enum BackgroundFlags {
    BACKGROUND_FLAG_TEXTURE                 = 0x01,
    BACKGROUND_FLAG_FOG                     = 0x02,
    BACKGROUND_RENDER_STATE_BEGIN_PAUSED    = 0x10,
    BACKGROUND_RENDER_STATE_FILTER_PAUSED   = 0x20,
    BACKGROUND_RENDER_STATE_SHOW_PAUSED     = 0x30,
    BACKGROUND_RENDER_STATE_MASK            = 0xF0,
};

enum EncounterStates {
    ENCOUNTER_STATE_NONE            = 0,
    ENCOUNTER_STATE_CREATE          = 1,
    ENCOUNTER_STATE_NEUTRAL         = 2,
    ENCOUNTER_STATE_PRE_BATTLE      = 3,
    ENCOUNTER_STATE_CONVERSATION    = 4,
    ENCOUNTER_STATE_POST_BATTLE     = 5,
};

enum EncounterCreateSubStates {
    ENCOUNTER_SUBSTATE_CREATE_INIT = 0,
    ENCOUNTER_SUBSTATE_CREATE_RUN_INIT_SCRIPT = 1,
    ENCOUNTER_SUBSTATE_CREATE_RUN_AI = 2,
};

enum EncounterNeutralSubStates {
    ENCOUNTER_SUBSTATE_NEUTRAL = 0,
};

enum EncounterPreBattleSubStates {
    ENCOUNTER_SUBSTATE_PRE_BATTLE_INIT = 0,
    ENCOUNTER_SUBSTATE_PRE_BATTLE_LOAD_BATTLE = 1,
    ENCOUNTER_SUBSTATE_PRE_BATTLE_AUTO_WIN = 2,
    ENCOUNTER_SUBSTATE_PRE_BATTLE_3 = 3,
};

enum EncounterConversationSubStates {
    ENCOUNTER_SUBSTATE_CONVERSATION_INIT = 0,
    ENCOUNTER_SUBSTATE_CONVERSATION_END = 1,
};

enum EncounterPostBattleSubStates {
    ENCOUNTER_SUBSTATE_POST_BATTLE_INIT = 0,
    ENCOUNTER_SUBSTATE_POST_BATTLE_WON_WAIT = 2,
    ENCOUNTER_SUBSTATE_POST_BATTLE_WON_KILL = 3,
    ENCOUNTER_SUBSTATE_POST_BATTLE_WON_TO_NEUTRAL = 4,
    ENCOUNTER_SUBSTATE_POST_BATTLE_WON_CHECK_MERLEE_BONUS = 10,
    ENCOUNTER_SUBSTATE_POST_BATTLE_PLAY_NPC_DEFEAT = 11,
    ENCOUNTER_SUBSTATE_POST_BATTLE_FLED_INIT = 100,
    ENCOUNTER_SUBSTATE_POST_BATTLE_FLED_WAIT = 101,
    ENCOUNTER_SUBSTATE_POST_BATTLE_102 = 102,
    ENCOUNTER_SUBSTATE_POST_BATTLE_103 = 103,
    ENCOUNTER_SUBSTATE_POST_BATTLE_LOST_INIT = 200,
    ENCOUNTER_SUBSTATE_POST_BATTLE_LOST_WAIT = 201,
    ENCOUNTER_SUBSTATE_POST_BATTLE_202 = 202,
    ENCOUNTER_SUBSTATE_POST_BATTLE_LOST_TO_NEUTRAL = 203,
    ENCOUNTER_SUBSTATE_POST_BATTLE_300 = 300,
    ENCOUNTER_SUBSTATE_POST_BATTLE_ENEMY_FLED_INIT = 400,
    ENCOUNTER_SUBSTATE_POST_BATTLE_ENEMY_FLED_WAIT = 401,
    ENCOUNTER_SUBSTATE_POST_BATTLE_ENEMY_FLED_TO_NEUTRAL = 402,
};

enum PlayerSpriteSets {
    PLAYER_SPRITES_MARIO_WORLD          = 0,
    PLAYER_SPRITES_MARIO_REFLECT_FLOOR  = 1,
    PLAYER_SPRITES_COMBINED_EPILOGUE    = 2,
    PLAYER_SPRITES_MARIO_PARADE         = 3,
    PLAYER_SPRITES_PEACH_WORLD          = 4,
    PLAYER_SPRITES_MARIO_BATTLE         = 5,
    PLAYER_SPRITES_PEACH_BATTLE         = 6,
};

enum BattleDarknessMode {
    BTL_DARKNESS_MODE_0     = 0,
    BTL_DARKNESS_MODE_1     = 1,
    BTL_DARKNESS_MODE_2     = 2,
    BTL_DARKNESS_MODE_3     = 3,
};

enum BattleDarknessState {
    BTL_DARKNESS_STATE_LOCKED       = -2,
    BTL_DARKNESS_STATE_DARK         = -1,
    BTL_DARKNESS_STATE_NONE         = 0,
    BTL_DARKNESS_STATE_WATT_BASED   = 1,
};

enum WindowStyles {
    WINDOW_STYLE_0      = 0,
    WINDOW_STYLE_1      = 1,
    WINDOW_STYLE_2      = 2,
    WINDOW_STYLE_3      = 3,
    WINDOW_STYLE_4      = 4,
    WINDOW_STYLE_5      = 5,
    WINDOW_STYLE_6      = 6,
    WINDOW_STYLE_7      = 7,
    WINDOW_STYLE_8      = 8,
    WINDOW_STYLE_9      = 9,
    WINDOW_STYLE_10     = 10,
    WINDOW_STYLE_11     = 11,
    WINDOW_STYLE_12     = 12,
    WINDOW_STYLE_13     = 13,
    WINDOW_STYLE_14     = 14,
    WINDOW_STYLE_15     = 15,
    WINDOW_STYLE_16     = 16,
    WINDOW_STYLE_17     = 17,
    WINDOW_STYLE_18     = 18,
    WINDOW_STYLE_19     = 19,
    WINDOW_STYLE_20     = 20,
    WINDOW_STYLE_21     = 21,
    WINDOW_STYLE_22     = 22,
    WINDOW_STYLE_MAX    = 22,
};

// LANGUAGE_DEFAULT as 0 will be the first index into several arrays containing data based on the current language.
// For non-PAL versions, this will be the first and only index.
#define LANGUAGE_DEFAULT 0
enum Language {
    LANGUAGE_EN = 0,
    LANGUAGE_DE = 1,
    LANGUAGE_FR = 2,
    LANGUAGE_ES = 3,
};

enum IdleScriptState {
    IDLE_SCRIPT_DISABLE = 0,
    IDLE_SCRIPT_ENABLE  = 1,
    IDLE_SCRIPT_RESTART = -1,
};

enum BlurState {
    ACTOR_BLUR_DISABLE  = 0,
    ACTOR_BLUR_ENABLE   = 1,
    ACTOR_BLUR_RESET    = -1,
};

#endif
