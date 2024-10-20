#include "common.h"
#include "battle/action_cmd.h"
#include "include_asset.h"

#define NAMESPACE action_command_three_chances

extern s32 actionCmdTableWaterBlock[][2];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_FRAME          = 1,
    HIDX_LIGHT_1        = 2,
    HIDX_LIGHT_2        = 3,
    HIDX_LIGHT_3        = 4,
    HIDX_05             = 5, // unused 4th light
    HIDX_RATING_1       = 6,
    HIDX_RATING_2       = 7,
    HIDX_RATING_3       = 8,
    HIDX_09             = 9, // unused rating for 4th light
    HIDX_DIGIT          = 10,
    HIDX_TICK_1         = 11,
    HIDX_TICK_2         = 12,
    HIDX_BUFF_ICON      = 13,
};

// states for this action command
enum {
    THREE_CHANCES_STATE_INIT            = 0,  // create hud elements
    THREE_CHANCES_STATE_APPEAR          = 1,  // hud elements move into position
    THREE_CHANCES_STATE_START           = 10, // begin the input-checking phase
    THREE_CHANCES_STATE_PREFACE         = 11, // first two ticks light up
    THREE_CHANCES_STATE_FIRST_CHANCE    = 12, // first window to match timing
    THREE_CHANCES_STATE_SECOND_CHANCE   = 13, // second window to match timing
    THREE_CHANCES_STATE_THIRD_CHANCE    = 14, // third window to match timing
    THREE_CHANCES_STATE_UNUSED_CHANCE   = 15, // unimplemented fourth chance to match timing
    THREE_CHANCES_STATE_WRAPUP          = 16, // tally overall success
    THREE_CHANCES_STATE_DISPOSE         = 17, // delay and disappear
};

// input window before the light appears where A inputs cause timing test to fail
#define ANTI_MASH_TIME 5

INCLUDE_IMG("battle/action_cmd/three_chances_1.png", battle_action_cmd_three_chances_1_png);
INCLUDE_PAL("battle/action_cmd/three_chances_1.pal", battle_action_cmd_three_chances_1_pal);

INCLUDE_IMG("battle/action_cmd/three_chances_2.png", battle_action_cmd_three_chances_2_png);
INCLUDE_PAL("battle/action_cmd/three_chances_2.pal", battle_action_cmd_three_chances_2_pal);

INCLUDE_IMG("battle/action_cmd/three_chances_3.png", battle_action_cmd_three_chances_3_png);
INCLUDE_PAL("battle/action_cmd/three_chances_3.pal", battle_action_cmd_three_chances_3_pal);

INCLUDE_IMG("battle/action_cmd/three_chances_0.png", battle_action_cmd_three_chances_0_png);
INCLUDE_PAL("battle/action_cmd/three_chances_0.pal", battle_action_cmd_three_chances_0_pal);

INCLUDE_IMG("battle/action_cmd/three_chances_block.png", battle_action_cmd_three_chances_block_png);
INCLUDE_PAL("battle/action_cmd/three_chances_block.pal", battle_action_cmd_three_chances_block_pal);

INCLUDE_IMG("battle/action_cmd/three_chances_circle.png", battle_action_cmd_three_chances_circle_png);
INCLUDE_PAL("battle/action_cmd/three_chances_circle.pal", battle_action_cmd_three_chances_circle_pal);

INCLUDE_IMG("battle/action_cmd/three_chances_cloud.png", battle_action_cmd_three_chances_cloud_png);
INCLUDE_PAL("battle/action_cmd/three_chances_cloud.pal", battle_action_cmd_three_chances_cloud_pal);

INCLUDE_IMG("battle/action_cmd/three_chances_4.png", battle_action_cmd_three_chances_4_png);
INCLUDE_PAL("battle/action_cmd/three_chances_4.pal", battle_action_cmd_three_chances_4_pal);

HudScript HES_Digit1 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_three_chances_1, 24, 24);
HudScript HES_Digit2 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_three_chances_2, 24, 24);
HudScript HES_Digit3 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_three_chances_3, 24, 24);
HudScript HES_Digit0 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_three_chances_0, 24, 24);
HudScript HES_Digit4 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_three_chances_4, 24, 24);

HudScript HES_WaterBlock = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_three_chances_block, 32, 32);
HudScript HES_TurboCharge = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_three_chances_circle, 40, 40);
HudScript HES_CloudNine = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_three_chances_cloud, 40, 40);

HudScript* DigitScripts[] = {
    &HES_Digit0,
    &HES_Digit1,
    &HES_Digit2,
    &HES_Digit3,
    &HES_Digit4,
    &HES_Digit4,
    &HES_Digit4,
    &HES_Digit4,
    &HES_Digit4,
    &HES_Digit4,
};

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    HudElemID hid;

    battleStatus->maxActionQuality = 5;
    battleStatus->actionCmdDifficultyTable = (s32*)actionCmdTableWaterBlock;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_THREE_CHANCES;
    acs->state = THREE_CHANCES_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    acs->variation = evt_get_variable(script, *args++);
    battleStatus->actionProgress = 1;
    acs->hudPrepareTime = 30;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElemIDs[HIDX_BUTTON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_TimingBar3Chances);
    acs->hudElemIDs[HIDX_FRAME] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingWait);
    acs->hudElemIDs[HIDX_LIGHT_1] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingWait);
    acs->hudElemIDs[HIDX_LIGHT_2] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingWait);
    acs->hudElemIDs[HIDX_LIGHT_3] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingOK);
    acs->hudElemIDs[HIDX_RATING_1] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingOK);
    acs->hudElemIDs[HIDX_RATING_2] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingOK);
    acs->hudElemIDs[HIDX_RATING_3] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    acs->hudElemIDs[HIDX_DIGIT] = hud_element_create(DigitScripts[1]);
    hud_element_set_render_pos(acs->hudElemIDs[HIDX_DIGIT], acs->hudPosX, acs->hudPosY);

    acs->hudElemIDs[HIDX_TICK_1] = hud_element_create(&HES_TimingCharge4c);
    hud_element_set_render_pos(acs->hudElemIDs[HIDX_TICK_1], acs->hudPosX, acs->hudPosY);

    hid = hud_element_create(&HES_TimingCharge4b);
    acs->hudElemIDs[HIDX_TICK_2] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);

    switch (acs->variation) {
        case ACV_THREE_CHANCES_WATER_BLOCK:
            acs->hudElemIDs[HIDX_BUFF_ICON] = hud_element_create(&HES_WaterBlock);
            hid = acs->hudElemIDs[HIDX_BUFF_ICON];
            break;
        case ACV_THREE_CHANCES_TURBO_CHARGE:
            acs->hudElemIDs[HIDX_BUFF_ICON] = hud_element_create(&HES_TurboCharge);
            hid = acs->hudElemIDs[HIDX_BUFF_ICON];
            break;
        case ACV_THREE_CHANCES_CLOUD_NINE:
            acs->hudElemIDs[HIDX_BUFF_ICON] = hud_element_create(&HES_CloudNine);
            hid = acs->hudElemIDs[HIDX_BUFF_ICON];
            break;
    }

    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

    acs->wrongButtonPressed = FALSE;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    battleStatus->actionProgress = 1;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    acs->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 pos;
    s32 i;
    s32 window;
    HudElemID hid;

    switch (acs->state) {
        case THREE_CHANCES_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);
            hid = acs->hudElemIDs[HIDX_BUTTON];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);
            hid = acs->hudElemIDs[HIDX_FRAME];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElemIDs[HIDX_LIGHT_1];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElemIDs[HIDX_LIGHT_2];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElemIDs[HIDX_LIGHT_3];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElemIDs[HIDX_DIGIT];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElemIDs[HIDX_TICK_1];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElemIDs[HIDX_TICK_2];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElemIDs[HIDX_BUFF_ICON];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            acs->state = THREE_CHANCES_STATE_APPEAR;
            break;
        case THREE_CHANCES_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->hudPrepareTime != 0) {
                acs->hudPrepareTime--;
                return;
            }
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_FRAME], acs->hudPosX + 28, acs->hudPosY + 28);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_LIGHT_1], acs->hudPosX + 21, acs->hudPosY + 24);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_LIGHT_2], acs->hudPosX + 41, acs->hudPosY + 24);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_LIGHT_3], acs->hudPosX + 61, acs->hudPosY + 24);

            hid = acs->hudElemIDs[HIDX_DIGIT];
            switch (acs->variation) {
                case ACV_THREE_CHANCES_WATER_BLOCK:
                    hud_element_set_render_pos(hid, acs->hudPosX + 91, acs->hudPosY + 7);
                    break;
                case ACV_THREE_CHANCES_TURBO_CHARGE:
                    hud_element_set_render_pos(hid, acs->hudPosX + 91, acs->hudPosY + 13);
                    break;
                case ACV_THREE_CHANCES_CLOUD_NINE:
                    hud_element_set_render_pos(hid, acs->hudPosX + 91, acs->hudPosY + 13);
                    break;
            }

            hud_element_set_render_pos(acs->hudElemIDs[HIDX_TICK_1], acs->hudPosX - 5, acs->hudPosY + 29);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_TICK_2], acs->hudPosX + 7, acs->hudPosY + 29);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_BUFF_ICON], acs->hudPosX + 92, acs->hudPosY + 23);
            break;
        case THREE_CHANCES_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }

            acs->stateTimer = acs->duration - 60;
            if (acs->stateTimer < 42) {
                acs->stateTimer = 42;
            }
            acs->state = THREE_CHANCES_STATE_PREFACE;

            // fallthrough
        case THREE_CHANCES_STATE_PREFACE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // first two minor ticks
            if (acs->stateTimer == 42) {
                hud_element_set_script(acs->hudElemIDs[HIDX_TICK_1], &HES_TimingCharge3);
                sfx_play_sound(SOUND_TIMING_BAR_TICK);
            }
            if (acs->stateTimer == 22) {
                hud_element_set_script(acs->hudElemIDs[HIDX_TICK_2], &HES_TimingCharge2);
                sfx_play_sound(SOUND_TIMING_BAR_TICK);
            }

            // activate the first light
            if (acs->stateTimer == 2) {
                hud_element_set_script(acs->hudElemIDs[HIDX_LIGHT_1], &HES_TimingReady);
                hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_AButtonDown);
                sfx_play_sound(SOUND_TIMING_BAR_GO);
            }

            acs->stateTimer--;

            // prepare to listen for input
            if (acs->stateTimer == 0) {
                acs->stateTimer = 20;
                acs->threeChances.time = 0;
                acs->state = THREE_CHANCES_STATE_FIRST_CHANCE;
                acs->threeChances.hadCorrectTiming = FALSE;
                acs->wrongButtonPressed = FALSE;
            }
            break;
        case THREE_CHANCES_STATE_FIRST_CHANCE:
            btl_set_popup_duration(POPUP_MSG_ON);
            // in this state, test for input during the first six frames (threeChances.time >= -5), then display
            // a verdict and wait until the full 20 frame state lifetime is complete before beginning the next one.

            // first six frames, if no input has been received
            if (!(acs->wrongButtonPressed || acs->threeChances.hadCorrectTiming)
                && acs->threeChances.time >= -5
            ) {
                s32 (*difficultyVec)[2] = (s32 (*)[2])battleStatus->actionCmdDifficultyTable;
                window = difficultyVec[acs->difficulty][0] + difficultyVec[acs->difficulty][1] + ANTI_MASH_TIME;
                pos = battleStatus->inputBufferPos;
                pos -= window;
                if (pos < 0) {
                    pos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }
                if (window == 0) {
                    window = 1;
                }
                // iterate through last N inputs looking for button presses
                for (i = 0; i < window; pos++, i++) {
                    if (pos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        pos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    if (i < ANTI_MASH_TIME && (battleStatus->pushInputBuffer[pos] & BUTTON_A)) {
                        acs->wrongButtonPressed = TRUE;
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !acs->wrongButtonPressed) || acs->autoSucceed) {
                        acs->threeChances.hadCorrectTiming = TRUE;
                        battleStatus->actionProgress++;
                        break;
                    }
                }
            }

            // if an input is received, show an early verdict
            if ((acs->threeChances.time > -5)
                && (acs->wrongButtonPressed || acs->threeChances.hadCorrectTiming)
            ) {
                hid = acs->hudElemIDs[HIDX_RATING_1];
                if (acs->threeChances.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 28, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            // after six frames, show the verdict
            if (acs->threeChances.time == -5) {
                hid = acs->hudElemIDs[HIDX_RATING_1];
                if (acs->threeChances.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 28, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_AButton);
            }

            acs->threeChances.time--;

            // activate the second light just before the next state begins
            if (acs->stateTimer == 2) {
                hud_element_set_script(acs->hudElemIDs[HIDX_LIGHT_2], &HES_TimingReady);
                hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_AButtonDown);
                sfx_play_sound(SOUND_TIMING_BAR_GO);
            }

            acs->stateTimer--;

            if (acs->stateTimer == 0) {
                acs->stateTimer = 20;
                acs->threeChances.time = 0;
                acs->state = THREE_CHANCES_STATE_SECOND_CHANCE;
                acs->threeChances.hadCorrectTiming = FALSE;
                acs->wrongButtonPressed = FALSE;
            }
            break;
        case THREE_CHANCES_STATE_SECOND_CHANCE:
            btl_set_popup_duration(POPUP_MSG_ON);
            // in this state, test for input during the first six frames (threeChances.time >= -5), then display
            // a verdict and wait until the full 20 frame state lifetime is complete before beginning the next one.

            // first six frames, if no input has been received
            if (!(acs->wrongButtonPressed || acs->threeChances.hadCorrectTiming)
                && acs->threeChances.time >= -5
            ) {
                s32 (*difficultyVec)[2] = (s32 (*)[2])battleStatus->actionCmdDifficultyTable;
                window = difficultyVec[acs->difficulty][0] + difficultyVec[acs->difficulty][1] + ANTI_MASH_TIME - 1;
                if (window < 6) {
                    window = 6;
                }
                pos = battleStatus->inputBufferPos;
                pos -= window;
                if (pos < 0) {
                    pos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }
                if (window == 0) {
                    window = 1;
                }
                // iterate through last N inputs looking for button presses
                for (i = 0; i < window; pos++, i++) {
                    if (pos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        pos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    if (i < ANTI_MASH_TIME) {
                        if (battleStatus->pushInputBuffer[pos] & BUTTON_A) {
                            acs->wrongButtonPressed = TRUE;
                        }
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !acs->wrongButtonPressed) || acs->autoSucceed) {
                        acs->threeChances.hadCorrectTiming = TRUE;
                        battleStatus->actionProgress++;
                        break;
                    }
                }
            }

            // if an input is received, show an early verdict
            if ((acs->threeChances.time > -5)
                && (acs->wrongButtonPressed || acs->threeChances.hadCorrectTiming)
            ) {
                hid = acs->hudElemIDs[HIDX_RATING_2];
                if (acs->threeChances.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 48, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            // after six frames, show the verdict
            if (acs->threeChances.time == -5) {
                hid = acs->hudElemIDs[HIDX_RATING_2];
                if (acs->threeChances.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 48, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_AButton);
            }

            acs->threeChances.time--;

            // activate the third light just before the next state begins
            if (acs->stateTimer == 2) {
                hud_element_set_script(acs->hudElemIDs[HIDX_LIGHT_3], &HES_TimingReady);
                hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_AButtonDown);
                sfx_play_sound(SOUND_TIMING_BAR_GO);
            }

            acs->stateTimer--;

            if (acs->stateTimer == 0) {
                acs->stateTimer = 20;
                acs->threeChances.time = 0;
                acs->state = THREE_CHANCES_STATE_THIRD_CHANCE;
                acs->threeChances.hadCorrectTiming = FALSE;
                acs->wrongButtonPressed = FALSE;
            }
            break;
        case THREE_CHANCES_STATE_THIRD_CHANCE:
            btl_set_popup_duration(POPUP_MSG_ON);
            // in this state, test for input during the first six frames (threeChances.time >= -5), then display
            // a verdict and begin wrapping up the action command.

            // first six frames, if no input has been received
            if (!(acs->wrongButtonPressed || acs->threeChances.hadCorrectTiming)
                && acs->threeChances.time >= -5
            ) {
                s32 (*difficultyVec)[2] = (s32 (*)[2])battleStatus->actionCmdDifficultyTable;
                window = difficultyVec[acs->difficulty][0] + difficultyVec[acs->difficulty][1] + ANTI_MASH_TIME - 2;
                if (window < 6) {
                    window = 6;
                }
                pos = battleStatus->inputBufferPos;
                pos -= window;
                if (pos < 0) {
                    pos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }
                if (window == 0) {
                    window = 1;
                }
                // iterate through last N inputs looking for button presses
                for (i = 0; i < window; pos++, i++) {
                    if (pos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        pos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    if (i < ANTI_MASH_TIME) {
                        if (battleStatus->pushInputBuffer[pos] & BUTTON_A) {
                            acs->wrongButtonPressed = TRUE;
                        }
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !acs->wrongButtonPressed) ||
                        acs->autoSucceed) {
                        acs->threeChances.hadCorrectTiming = TRUE;
                        battleStatus->actionProgress++;
                        break;
                    }
                }
            }

            // if an input is received, show an early verdict
            if ((acs->threeChances.time > -5)
                && (acs->wrongButtonPressed || acs->threeChances.hadCorrectTiming)
            ) {
                hid = acs->hudElemIDs[HIDX_RATING_3];
                if (acs->threeChances.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 68, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            // after six frames, show the verdict
            if (acs->threeChances.time == -5) {
                hid = acs->hudElemIDs[HIDX_RATING_3];
                if (acs->threeChances.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 68, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_AButton);
                acs->state = THREE_CHANCES_STATE_WRAPUP;
                return;
            }

            acs->threeChances.time--;
            break;
        case THREE_CHANCES_STATE_WRAPUP:
            if (battleStatus->actionProgress == 0) {
                battleStatus->actionQuality = AC_QUALITY_FAILED;
            } else {
                battleStatus->actionQuality = battleStatus->actionProgress;
            }
            battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            if (battleStatus->actionQuality == 3) {
                increment_action_command_success_count();
            }
            btl_set_popup_duration(POPUP_MSG_OFF);
            acs->stateTimer = 5;
            acs->state = THREE_CHANCES_STATE_DISPOSE;
            break;
        case THREE_CHANCES_STATE_DISPOSE:
            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;

    hud_element_draw_clipped(acs->hudElemIDs[HIDX_BUTTON]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_FRAME]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_LIGHT_1]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_LIGHT_2]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_LIGHT_3]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_RATING_1]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_RATING_2]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_RATING_3]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_BUFF_ICON]);

    hid = acs->hudElemIDs[HIDX_DIGIT];
    if (hud_element_get_script(hid) != DigitScripts[battleStatus->actionProgress]) {
        hud_element_set_script(hid, DigitScripts[battleStatus->actionProgress]);
    }

    hud_element_draw_clipped(hid);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_TICK_1]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_TICK_2]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_FRAME]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_LIGHT_1]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_LIGHT_2]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_LIGHT_3]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_RATING_1]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_RATING_2]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_RATING_3]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_DIGIT]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_TICK_1]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_TICK_2]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_BUFF_ICON]);
}
