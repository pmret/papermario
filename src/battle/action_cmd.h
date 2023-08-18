#ifndef _BATTLE_ACTION_CMD_H_
#define _BATTLE_ACTION_CMD_H_

#include "common.h"
#include "hud_element.h"
#include "battle/action_cmd/jump.h"
#include "battle/action_cmd/hammer.h"
#include "battle/action_cmd/flee.h"
#include "battle/action_cmd/break_free.h"
#include "battle/action_cmd/whirlwind.h"
#include "battle/action_cmd/stop_leech.h"
#include "battle/action_cmd/07.h"
#include "battle/action_cmd/dizzy_shell.h"
#include "battle/action_cmd/fire_shell.h"
#include "battle/action_cmd/0A.h"
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
#include "battle/action_cmd/water_block.h"
#include "battle/action_cmd/tidal_wave.h"

enum MashMeterColorModes {
    MASH_METER_MODE_BLINK       = -1,
    MASH_METER_MODE_MULTI_COLOR = 0,
    MASH_METER_MODE_ONE_COLOR   = 1,
};

enum ActionCommandModes {
    ACTION_COMMAND_MODE_TUTORIAL_BLOCK      = -1,
    ACTION_COMMAND_MODE_NOT_LEARNED         = 0,
    ACTION_COMMAND_MODE_LEARNED             = 1,
    ACTION_COMMAND_MODE_TUTORIAL            = 2,
    ACTION_COMMAND_MODE_TUTORIAL_WAIT_INPUT = 3,
};

typedef struct ActionCommandStatus {
    /* 0x00 */ s32 workerID;
    /* 0x04 */ s32 hudElements[16];
    /* 0x44 */ s16 barFillLevel; // full = 10000
    /* 0x46 */ s16 thresholdLevel;
    /* 0x48 */ s16 barFillWidth; // X100
    /* 0x4A */ s16 actionCommandID;
    /* 0x4C */ s16 state;
    /* 0x4E */ s16 prepareTime;
    /* 0x50 */ s16 difficulty; // values from 0 to 7
    /* 0x52 */ s16 duration;
    /* 0x54 */ s16 frameCounter;
    /* 0x56 */ s16 hudPosX;
    /* 0x58 */ s16 hudPosY;
    /* 0x5A */ s16 unk_5A;
    /* 0x5C */ s8 unk_5C;
    /* 0x5D */ s8 unk_5D;
    /* 0x5E */ s8 autoSucceed;
    /* 0x5F */ s8 hammerMissedStart;
    /* 0x60 */ s8 wrongButtonPressed;
    /* 0x61 */ s8 showHud;
    /* 0x62 */ s8 playHammerSounds;
    /* 0x63 */ s8 unk_63;
    /* 0x64 */ s16 targetWeakness; // chance of applying special status, the more the easier it is to fill the bar
    /* 0x66 */ s16 thresholdMoveDir;
    /* 0x68 */ s16 isBarFilled;
    /* 0x6A */ s16 berserkerEnabled;
    /* 0x6C */ s16 hudPrepareTime;
    /* 0x6E */ s16 hitsTakenIsMax;
    /* 0x70 */ s16 lookBackCounter;
    /* 0x72 */ s16 wrongInputFrameCounter;
    /* 0x74 */ s16 mashMeterCutoffs[6]; // upper bounds for each interval
    /* 0x80 */ s8 mashMeterIntervals;
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
void func_80268E88(void);
void func_80269118(void);
void func_80269160(void);

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
API_CALLABLE(GetActionSuccess);
API_CALLABLE(SetActionSuccess);
API_CALLABLE(SetActionCommandMode);
API_CALLABLE(GetActionCommandMode);
API_CALLABLE(SetActionHudPrepareTime);
API_CALLABLE(GetCommandAutoSuccess);
API_CALLABLE(SetCommandAutoSuccess);
API_CALLABLE(func_802693F0);
API_CALLABLE(CloseActionCommandInfo);
API_CALLABLE(func_80269470);
API_CALLABLE(ShowActionHud);
API_CALLABLE(GetActionSuccessCopy);
API_CALLABLE(GetActionResult);
API_CALLABLE(SetActionResult);
API_CALLABLE(GetBlockResult);
API_CALLABLE(GetActionQuality);
API_CALLABLE(SetActionQuality);
API_CALLABLE(func_80269600);
API_CALLABLE(func_8026962C);

#endif
