#ifndef _BATTLE_ACTION_CMD_H_
#define _BATTLE_ACTION_CMD_H_

#include "common.h"
#include "hud_element.h"
#include "battle.h"
#include "battle/action_cmd/jump.h"
#include "battle/action_cmd/hammer.h"
#include "battle/action_cmd/flee.h"
#include "battle/action_cmd/break_free.h"
#include "battle/action_cmd/whirlwind.h"
#include "battle/action_cmd/stop_leech.h"
#include "battle/action_cmd/unused_flee.h"
#include "battle/action_cmd/dizzy_shell.h"
#include "battle/action_cmd/fire_shell.h"
#include "battle/action_cmd/unused_mash_a.h"
#include "battle/action_cmd/bomb.h"
#include "battle/action_cmd/body_slam.h"
#include "battle/action_cmd/air_lift.h"
#include "battle/action_cmd/air_raid.h"
#include "battle/action_cmd/squirt.h"
#include "battle/action_cmd/power_shock.h"
#include "battle/action_cmd/mega_shock.h"
#include "battle/action_cmd/smack.h"
#include "battle/action_cmd/spiny_surge.h"
#include "battle/action_cmd/hurricane.h"
#include "battle/action_cmd/spook.h"
#include "battle/action_cmd/three_chances.h"
#include "battle/action_cmd/tidal_wave.h"

// standard states for action commands
// used by every command except three_chances and tidal_wave
enum {
    AC_STATE_INIT                   = 0,  // create hud elements
    AC_STATE_APPEAR                 = 1,  // hud elements move into position
    AC_STATE_START                  = 10, // begin listening for input
    AC_STATE_ACTIVE                 = 11, // responding to player input
    AC_STATE_DISPOSE                = 12, // delay and disappear
};

enum ActionCommandDifficulty {
    AC_DIFFICULTY_0                 = 0, // easiest
    AC_DIFFICULTY_1                 = 1, // very easy
    AC_DIFFICULTY_2                 = 2, // easy
    AC_DIFFICULTY_3                 = 3, // standard
    AC_DIFFICULTY_4                 = 4, // harder
    AC_DIFFICULTY_5                 = 5, // hard
    AC_DIFFICULTY_6                 = 6, // very hard
    AC_DIFFICULTY_7                 = 7, // hardest
};

enum MashMeterColorModes {
    MASH_METER_MODE_BLINK           = -1,
    MASH_METER_MODE_MULTI_COLOR     = 0,
    MASH_METER_MODE_ONE_COLOR       = 1,
};

enum ActionCommandModes {
    AC_MODE_TUTORIAL_BLOCK          = -1,
    AC_MODE_NOT_LEARNED             = 0,
    AC_MODE_LEARNED                 = 1,
    AC_MODE_TUTORIAL                = 2,
    AC_MODE_TUTORIAL_WAIT_INPUT     = 3,
};

#define AC_QUALITY_FAILED -1

// mash meter has 100 units for each 1%
#define ONE_PCT_MASH    100

// mash meter goes up to 100%
#define MAX_MASH_PCT    100

// total number of units in the mash meter
#define MAX_MASH_UNITS  (MAX_MASH_PCT * ONE_PCT_MASH)

#define SCALE_BY_PCT(x, pct)            ((x) * (pct) / 100)
#define PCT_TO_TABLE_IDX(table, pct)    ((pct) / (ONE_PCT_MASH / ARRAY_COUNT(table)))
#define PCT_TO_TABLE_RATE(table, pct)   (table[PCT_TO_TABLE_IDX(table, pct)])

typedef struct ActionCommandStatus {
    /* 0x00 */ s32 workerID;
    /* 0x04 */ HudElemID hudElemIDs[16];
    /* 0x44 */ s16 meterFillLevel; // 0 to MAX_MASH_UNITS
    /* 0x46 */ s16 escapeThreshold;
    /* 0x48 */ s16 meterFillWidth; // X100
    /* 0x4A */ s16 actionCommandID;
    /* 0x4C */ s16 state;
    /* 0x4E */ s16 prepareTime;
    /* 0x50 */ s16 difficulty; // see enum: ActionCommandDifficulty
    /* 0x52 */ s16 duration;
    /* 0x54 */ s16 stateTimer;
    /* 0x56 */ s16 hudPosX;
    /* 0x58 */ s16 hudPosY;
    /* 0x5A */ s16 escapeChance; // used by air_lift (via AirLiftChance), break_free (30), and flee (random 0-1).
    /* 0x5C */ union {
                    struct {
                        s8 unk_5C;
                        s8 unk_5D;
                    } any;
                    struct {
                        b8 holdingLeft;
                    } airRaid;
                    struct {
                        s8 dir;
                    } breakFree;
                    struct {
                        b8 holdingLeft;
                    } fireShell;
                    struct {
                        s8 dir;
                        s8 drainDelay; // only found in unused variant
                    } flee;
                    struct {
                        b8 holdingLeft;
                    } smack;
                    struct {
                        s8 tossState;
                    } spinySurge;
                    struct {
                        b8 holdingLeft;
                    } spook;
                    struct {
                        b8 draining;
                    } squirt;
                    struct {
                        b8 hadCorrectTiming;
                        s8 time;
                    } threeChances;
                    struct {
                        s8 prevButton;
                        s8 inputCount;
                    } tidalWave;
                };
    /* 0x5E */ s8 autoSucceed;
    /* 0x5F */ b8 hammerMissedStart;
    /* 0x60 */ b8 wrongButtonPressed;
    /* 0x61 */ b8 showHud;
    /* 0x62 */ b8 playHammerSounds;
    /* 0x63 */ char pad_63[1];
    /* 0x64 */ union {
                    s16 variation; // used to select different variants of an action command
                    s16 statusChance; // chance of applying special status; higher values make mashing easier
               };
    /* 0x66 */ s16 thresholdMoveDir;
    /* 0x68 */ b16 isMeterFilled;
    /* 0x6A */ b16 berserkerEnabled;
    /* 0x6C */ s16 hudPrepareTime;
    /* 0x6E */ b16 hitsTakenIsMax;
    /* 0x70 */ s16 lookBackCounter;
    /* 0x72 */ s16 wrongInputFrameCounter;
    /* 0x74 */ s16 mashMeterCutoffs[6]; // upper bounds for each interval
    /* 0x80 */ s8 mashMeterNumIntervals;
} ActionCommandStatus;

extern ActionCommandStatus gActionCommandStatus;

extern HudScript HES_100pct;
extern HudScript HES_AButton;
extern HudScript HES_AButtonDown;
extern HudScript HES_BButton;
extern HudScript HES_BButtonHeld;
extern HudScript HES_BlueMeter;
extern HudScript HES_CDownButtonHeld;
extern HudScript HES_FillGaugeResult;
extern HudScript HES_MashAButton;
extern HudScript HES_MashBButton1;
extern HudScript HES_PressAButton;
extern HudScript HES_PressBButton;
extern HudScript HES_PressCDownButton;
extern HudScript HES_RightOn;
extern HudScript HES_RunningAway;
extern HudScript HES_RunAwayOK;
extern HudScript HES_StickHoldLeft;
extern HudScript HES_StickMashLeft;
extern HudScript HES_StickNeutral;
extern HudScript HES_StickTapNeutral;
extern HudScript HES_TimingBar1Chance;
extern HudScript HES_TimingBar3Chances;
extern HudScript HES_TimingCharge1;
extern HudScript HES_TimingCharge2;
extern HudScript HES_TimingCharge3;
extern HudScript HES_TimingCharge4a;
extern HudScript HES_TimingCharge4b;
extern HudScript HES_TimingCharge4c;
extern HudScript HES_TimingOK;
extern HudScript HES_TimingMiss;
extern HudScript HES_TimingReady;
extern HudScript HES_TimingWait;

void action_command_init_status(void);
void action_command_free(void);
void create_action_command_ui_worker(void);
void increment_action_command_attempt_count(void);
void increment_action_command_success_count(void);

void draw_mash_meter_multicolor_with_divisor(s32 posX, s32 posY, s32 fillValue, s32 divisor);
void draw_mash_meter_blink(s32 posX, s32 posY, s32 fillValue);
void draw_mash_meter_multicolor(s32 posX, s32 posY, s32 fillValue);
void draw_mash_meter_mode_with_divisor(s32 posX, s32 posY, s32 fillValue, s32 divisor, s32 colorMode);
void draw_mash_meter_blink_with_divisor(s32 posX, s32 posY, s32 fillValue, s32 divisor);
s32 adjust_action_command_difficulty(s32 arg0);
s32 check_block_input(s32 buttonMask);

API_CALLABLE(LoadActionCommand);
API_CALLABLE(SetActionDifficultyTable);
API_CALLABLE(SetupMashMeter);
API_CALLABLE(GetSmashActionQuality);
API_CALLABLE(SetActionSuccess);
API_CALLABLE(SetActionCommandMode);
API_CALLABLE(GetActionCommandMode);
API_CALLABLE(SetActionHudPrepareTime);
API_CALLABLE(GetCommandAutoSuccess);
API_CALLABLE(SetCommandAutoSuccess);
API_CALLABLE(func_802693F0);
API_CALLABLE(InterruptActionCommand);
API_CALLABLE(InterruptLeechActionCommand);
API_CALLABLE(ShowActionHud);
API_CALLABLE(GetMashActionQuality);
API_CALLABLE(GetJumpActionQuality);
API_CALLABLE(SetActionResult);
API_CALLABLE(GetBlockResult);
API_CALLABLE(GetActionProgress);
API_CALLABLE(SetActionProgress);
API_CALLABLE(GetActionResultTier);
API_CALLABLE(SetActionResultTier);

#endif
