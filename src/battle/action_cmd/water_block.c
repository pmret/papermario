#include "common.h"
#include "battle/action_cmd.h"
#include "include_asset.h"

//TODO action command
#define NAMESPACE action_command_water_block

extern s32 actionCmdTableWaterBlock[][2];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_FRAME          = 1,
    HIDX_LIGHT_1        = 2,
    HIDX_LIGHT_2        = 3,
    HIDX_LIGHT_3        = 4,
    HIDX_05             = 5,
    HIDX_RATING_1       = 6,
    HIDX_RATING_2       = 7,
    HIDX_RATING_3       = 8,
    HIDX_09             = 9,
    HIDX_DIGIT          = 10,
    HIDX_TICK_1         = 11,
    HIDX_TICK_2         = 12,
    HIDX_BUFF_ICON      = 13,
};

// states for water block
enum {
    WATER_BLOCK_STATE_INIT              = 0,  // create hud elements
    WATER_BLOCK_STATE_APPEAR            = 1,  // hud elements move into position
    WATER_BLOCK_STATE_START             = 10, // begin the input-checking phase
    WATER_BLOCK_STATE_PREFACE           = 11, // first two ticks light up
    WATER_BLOCK_STATE_FIRST_CHANCE      = 12, // first window to match timing
    WATER_BLOCK_STATE_SECOND_CHANCE     = 13, // second window to match timing
    WATER_BLOCK_STATE_THIRD_CHANCE      = 14, // third window to match timing
    WATER_BLOCK_STATE_WRAPUP            = 16, // tally overall success
    WATER_BLOCK_STATE_DISPOSE           = 17, // delay and disappear
};

INCLUDE_IMG("battle/action_cmd/water_block_1.png", battle_action_cmd_water_block_1_png);
INCLUDE_PAL("battle/action_cmd/water_block_1.pal", battle_action_cmd_water_block_1_pal);

INCLUDE_IMG("battle/action_cmd/water_block_2.png", battle_action_cmd_water_block_2_png);
INCLUDE_PAL("battle/action_cmd/water_block_2.pal", battle_action_cmd_water_block_2_pal);

INCLUDE_IMG("battle/action_cmd/water_block_3.png", battle_action_cmd_water_block_3_png);
INCLUDE_PAL("battle/action_cmd/water_block_3.pal", battle_action_cmd_water_block_3_pal);

INCLUDE_IMG("battle/action_cmd/water_block_0.png", battle_action_cmd_water_block_0_png);
INCLUDE_PAL("battle/action_cmd/water_block_0.pal", battle_action_cmd_water_block_0_pal);

INCLUDE_IMG("battle/action_cmd/water_block_block.png", battle_action_cmd_water_block_block_png);
INCLUDE_PAL("battle/action_cmd/water_block_block.pal", battle_action_cmd_water_block_block_pal);

INCLUDE_IMG("battle/action_cmd/water_block_circle.png", battle_action_cmd_water_block_circle_png);
INCLUDE_PAL("battle/action_cmd/water_block_circle.pal", battle_action_cmd_water_block_circle_pal);

INCLUDE_IMG("battle/action_cmd/water_block_cloud.png", battle_action_cmd_water_block_cloud_png);
INCLUDE_PAL("battle/action_cmd/water_block_cloud.pal", battle_action_cmd_water_block_cloud_pal);

INCLUDE_IMG("battle/action_cmd/water_block_4.png", battle_action_cmd_water_block_4_png);
INCLUDE_PAL("battle/action_cmd/water_block_4.pal", battle_action_cmd_water_block_4_pal);

HudScript HES_WaterBlock1 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_water_block_1, 24, 24);
HudScript HES_WaterBlock2 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_water_block_2, 24, 24);
HudScript HES_WaterBlock3 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_water_block_3, 24, 24);
HudScript HES_WaterBlock0 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_water_block_0, 24, 24);
HudScript HES_WaterBlock4 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_water_block_4, 24, 24);

HudScript HES_WaterBlockBlock = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_water_block_block, 32, 32);
HudScript HES_WaterBlockCircle = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_water_block_circle, 40, 40);
HudScript HES_WaterBlockCloud = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_water_block_cloud, 40, 40);

HudScript* WaterBlockDigitScripts[] = {
    &HES_WaterBlock0,
    &HES_WaterBlock1,
    &HES_WaterBlock2,
    &HES_WaterBlock3,
    &HES_WaterBlock4,
    &HES_WaterBlock4,
    &HES_WaterBlock4,
    &HES_WaterBlock4,
    &HES_WaterBlock4,
    &HES_WaterBlock4,
};

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hid;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = (s32*)actionCmdTableWaterBlock;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_WATER_BLOCK;
    acs->state = WATER_BLOCK_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->targetWeakness = evt_get_variable(script, *args++);
    battleStatus->actionQuality = 1;
    acs->hudPrepareTime = 30;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElements[HIDX_BUTTON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_TimingBar3Chances);
    acs->hudElements[HIDX_FRAME] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingWait);
    acs->hudElements[HIDX_LIGHT_1] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingWait);
    acs->hudElements[HIDX_LIGHT_2] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingWait);
    acs->hudElements[HIDX_LIGHT_3] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingOK);
    acs->hudElements[HIDX_RATING_1] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingOK);
    acs->hudElements[HIDX_RATING_2] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingOK);
    acs->hudElements[HIDX_RATING_3] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    acs->hudElements[HIDX_DIGIT] = hud_element_create(WaterBlockDigitScripts[1]);
    hud_element_set_render_pos(acs->hudElements[HIDX_DIGIT], acs->hudPosX, acs->hudPosY);

    acs->hudElements[HIDX_TICK_1] = hud_element_create(&HES_TimingCharge4c);
    hud_element_set_render_pos(acs->hudElements[HIDX_TICK_1], acs->hudPosX, acs->hudPosY);

    hid = hud_element_create(&HES_TimingCharge4b);
    acs->hudElements[HIDX_TICK_2] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);

    switch (acs->targetWeakness) {
        case TIMING_BUFF_WATER_BLOCK:
            acs->hudElements[HIDX_BUFF_ICON] = hud_element_create(&HES_WaterBlockBlock);
            hid = acs->hudElements[HIDX_BUFF_ICON];
            break;
        case TIMING_BUFF_TURBO_CHARGE:
            acs->hudElements[HIDX_BUFF_ICON] = hud_element_create(&HES_WaterBlockCircle);
            hid = acs->hudElements[HIDX_BUFF_ICON];
            break;
        case TIMING_BUFF_CLOUD_NINE:
            acs->hudElements[HIDX_BUFF_ICON] = hud_element_create(&HES_WaterBlockCloud);
            hid = acs->hudElements[HIDX_BUFF_ICON];
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
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    battleStatus->actionQuality = 1;
    battleStatus->actionSuccess = 0;
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
    s32 hid;

    switch (acs->state) {
        case WATER_BLOCK_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);
            hid = acs->hudElements[HIDX_BUTTON];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);
            hid = acs->hudElements[HIDX_FRAME];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElements[HIDX_LIGHT_1];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElements[HIDX_LIGHT_2];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElements[HIDX_LIGHT_3];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElements[HIDX_DIGIT];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElements[HIDX_TICK_1];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElements[HIDX_TICK_2];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElements[HIDX_BUFF_ICON];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            acs->state = WATER_BLOCK_STATE_APPEAR;
            break;
        case WATER_BLOCK_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->hudPrepareTime != 0) {
                acs->hudPrepareTime--;
                return;
            }
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElements[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[HIDX_FRAME], acs->hudPosX + 28, acs->hudPosY + 28);
            hud_element_set_render_pos(acs->hudElements[HIDX_LIGHT_1], acs->hudPosX + 21, acs->hudPosY + 24);
            hud_element_set_render_pos(acs->hudElements[HIDX_LIGHT_2], acs->hudPosX + 41, acs->hudPosY + 24);
            hud_element_set_render_pos(acs->hudElements[HIDX_LIGHT_3], acs->hudPosX + 61, acs->hudPosY + 24);

            hid = acs->hudElements[HIDX_DIGIT];
            switch (acs->targetWeakness) {
                case TIMING_BUFF_WATER_BLOCK:
                    hud_element_set_render_pos(hid, acs->hudPosX + 91, acs->hudPosY + 7);
                    break;
                case TIMING_BUFF_TURBO_CHARGE:
                    hud_element_set_render_pos(hid, acs->hudPosX + 91, acs->hudPosY + 13);
                    break;
                case TIMING_BUFF_CLOUD_NINE:
                    hud_element_set_render_pos(hid, acs->hudPosX + 91, acs->hudPosY + 13);
                    break;
            }

            hud_element_set_render_pos(acs->hudElements[HIDX_TICK_1], acs->hudPosX - 5, acs->hudPosY + 29);
            hud_element_set_render_pos(acs->hudElements[HIDX_TICK_2], acs->hudPosX + 7, acs->hudPosY + 29);
            hud_element_set_render_pos(acs->hudElements[HIDX_BUFF_ICON], acs->hudPosX + 92, acs->hudPosY + 23);
            break;
        case WATER_BLOCK_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }

            acs->frameCounter = acs->duration - 60;
            if (acs->frameCounter < 42) {
                acs->frameCounter = 42;
            }
            acs->state = WATER_BLOCK_STATE_PREFACE;

            // fallthrough
        case WATER_BLOCK_STATE_PREFACE:
            btl_set_popup_duration(POPUP_MSG_ON);
            // first two minor ticks
            if (acs->frameCounter == 42) {
                hud_element_set_script(acs->hudElements[HIDX_TICK_1], &HES_TimingCharge3);
                sfx_play_sound(SOUND_TIMING_BAR_TICK);
            }
            if (acs->frameCounter == 22) {
                hud_element_set_script(acs->hudElements[HIDX_TICK_2], &HES_TimingCharge2);
                sfx_play_sound(SOUND_TIMING_BAR_TICK);
            }
            // light up first orb
            if (acs->frameCounter == 2) {
                hud_element_set_script(acs->hudElements[HIDX_LIGHT_1], &HES_TimingReady);
                hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_AButtonDown);
                sfx_play_sound(SOUND_TIMING_BAR_GO);
            }
            acs->frameCounter--;
            // prepare to listen for input
            if (acs->frameCounter == 0) {
                acs->frameCounter = 20;
                acs->waterBlock.unk_5D = 0;
                acs->state = WATER_BLOCK_STATE_FIRST_CHANCE;
                acs->waterBlock.hadCorrectTiming = FALSE;
                acs->wrongButtonPressed = FALSE;
            }
            break;
        case WATER_BLOCK_STATE_FIRST_CHANCE:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (!acs->wrongButtonPressed
                && !acs->waterBlock.hadCorrectTiming
                && acs->waterBlock.unk_5D >= -5
            ) {
                s32 (*difficultyVec)[2] = (s32 (*)[2])battleStatus->actionCmdDifficultyTable;
                window = difficultyVec[acs->difficulty][0] + difficultyVec[acs->difficulty][1] + 5;
                pos = battleStatus->inputBufferPos;
                pos -= window;
                if (pos < 0) {
                    pos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }
                if (window == 0) {
                    window = 1;
                }

                for (i = 0; i < window; pos++, i++) {
                    if (pos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        pos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    if (i < 5 && (battleStatus->pushInputBuffer[pos] & BUTTON_A)) {
                        acs->wrongButtonPressed = TRUE;
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !acs->wrongButtonPressed) ||
                        acs->autoSucceed) {
                        acs->waterBlock.hadCorrectTiming = TRUE;
                        battleStatus->actionQuality++;
                        break;
                    }
                }
            }

            if ((acs->waterBlock.unk_5D >= -4) && (acs->wrongButtonPressed || acs->waterBlock.hadCorrectTiming)) {
                hid = acs->hudElements[HIDX_RATING_1];
                if (acs->waterBlock.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 28, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            if (acs->waterBlock.unk_5D == -5) {
                hid = acs->hudElements[HIDX_RATING_1];
                if (acs->waterBlock.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 28, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_AButton);
            }
            acs->waterBlock.unk_5D--;
            if (acs->frameCounter == 2) {
                hud_element_set_script(acs->hudElements[HIDX_LIGHT_2], &HES_TimingReady);
                hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_AButtonDown);
                sfx_play_sound(SOUND_TIMING_BAR_GO);
            }
            acs->frameCounter--;
            if (acs->frameCounter == 0) {
                acs->frameCounter = 20;
                acs->waterBlock.unk_5D = 0;
                acs->state = WATER_BLOCK_STATE_SECOND_CHANCE;
                acs->waterBlock.hadCorrectTiming = FALSE;
                acs->wrongButtonPressed = FALSE;
            }
            break;
        case WATER_BLOCK_STATE_SECOND_CHANCE:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (!acs->wrongButtonPressed && !acs->waterBlock.hadCorrectTiming && (acs->waterBlock.unk_5D >= -5)) {
                s32 (*difficultyVec)[2] = (s32 (*)[2])battleStatus->actionCmdDifficultyTable;
                window = difficultyVec[acs->difficulty][0] + difficultyVec[acs->difficulty][1] + 4;
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

                for (i = 0; i < window; pos++, i++) {
                    if (pos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        pos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    if (i < 5) {
                        if (battleStatus->pushInputBuffer[pos] & BUTTON_A) {
                            acs->wrongButtonPressed = TRUE;
                        }
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !acs->wrongButtonPressed) || acs->autoSucceed) {
                        acs->waterBlock.hadCorrectTiming = TRUE;
                        battleStatus->actionQuality++;
                        break;
                    }
                }
            }

            if ((acs->waterBlock.unk_5D >= -4) && (acs->wrongButtonPressed || acs->waterBlock.hadCorrectTiming)) {
                hid = acs->hudElements[HIDX_RATING_2];
                if (acs->waterBlock.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 48, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            if (acs->waterBlock.unk_5D == -5) {
                hid = acs->hudElements[HIDX_RATING_2];
                if (acs->waterBlock.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 48, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_AButton);
            }
            acs->waterBlock.unk_5D--;
            if (acs->frameCounter == 2) {
                hud_element_set_script(acs->hudElements[HIDX_LIGHT_3], &HES_TimingReady);
                hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_AButtonDown);
                sfx_play_sound(SOUND_TIMING_BAR_GO);
            }
            acs->frameCounter--;
            if (acs->frameCounter == 0) {
                acs->frameCounter = 20;
                acs->waterBlock.unk_5D = 0;
                acs->state = WATER_BLOCK_STATE_THIRD_CHANCE;
                acs->waterBlock.hadCorrectTiming = FALSE;
                acs->wrongButtonPressed = FALSE;
            }
            break;
        case WATER_BLOCK_STATE_THIRD_CHANCE:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (!acs->wrongButtonPressed && !acs->waterBlock.hadCorrectTiming && (acs->waterBlock.unk_5D >= -5)) {
                s32 (*difficultyVec)[2] = (s32 (*)[2])battleStatus->actionCmdDifficultyTable;
                window = difficultyVec[acs->difficulty][0] + difficultyVec[acs->difficulty][1] + 3;
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

                for (i = 0; i < window; pos++, i++) {
                    if (pos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        pos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    if (i < 5) {
                        if (battleStatus->pushInputBuffer[pos] & BUTTON_A) {
                            acs->wrongButtonPressed = TRUE;
                        }
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !acs->wrongButtonPressed) ||
                        acs->autoSucceed) {
                        acs->waterBlock.hadCorrectTiming = TRUE;
                        battleStatus->actionQuality++;
                        break;
                    }
                }
            }
            if (acs->waterBlock.unk_5D >= -4) {
                if (acs->wrongButtonPressed || acs->waterBlock.hadCorrectTiming) {
                    hid = acs->hudElements[HIDX_RATING_3];
                    if (acs->waterBlock.hadCorrectTiming) {
                        hud_element_set_script(hid, &HES_TimingOK);
                    } else {
                        hud_element_set_script(hid, &HES_TimingMiss);
                    }
                    hud_element_set_render_pos(hid, acs->hudPosX + 68, acs->hudPosY + 38);
                    hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                }
            }
            if (acs->waterBlock.unk_5D == -5) {
                hid = acs->hudElements[HIDX_RATING_3];
                if (acs->waterBlock.hadCorrectTiming) {
                    hud_element_set_script(hid, &HES_TimingOK);
                } else {
                    hud_element_set_script(hid, &HES_TimingMiss);
                }
                hud_element_set_render_pos(hid, acs->hudPosX + 68, acs->hudPosY + 38);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_AButton);
                acs->state = WATER_BLOCK_STATE_WRAPUP;
                return;
            }
            acs->waterBlock.unk_5D--;
            break;
        case WATER_BLOCK_STATE_WRAPUP:
            if (battleStatus->actionQuality == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = battleStatus->actionQuality;
            }
            battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            if (battleStatus->actionSuccess == 3) {
                increment_action_command_success_count();
            }
            btl_set_popup_duration(POPUP_MSG_OFF);
            acs->frameCounter = 5;
            acs->state = WATER_BLOCK_STATE_DISPOSE;
            break;
        case WATER_BLOCK_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;

    hud_element_draw_clipped(acs->hudElements[HIDX_BUTTON]);
    hud_element_draw_clipped(acs->hudElements[HIDX_FRAME]);
    hud_element_draw_clipped(acs->hudElements[HIDX_LIGHT_1]);
    hud_element_draw_clipped(acs->hudElements[HIDX_LIGHT_2]);
    hud_element_draw_clipped(acs->hudElements[HIDX_LIGHT_3]);
    hud_element_draw_clipped(acs->hudElements[HIDX_RATING_1]);
    hud_element_draw_clipped(acs->hudElements[HIDX_RATING_2]);
    hud_element_draw_clipped(acs->hudElements[HIDX_RATING_3]);
    hud_element_draw_clipped(acs->hudElements[HIDX_BUFF_ICON]);

    hid = acs->hudElements[HIDX_DIGIT];
    if (hud_element_get_script(hid) != WaterBlockDigitScripts[battleStatus->actionQuality]) {
        hud_element_set_script(hid, WaterBlockDigitScripts[battleStatus->actionQuality]);
    }

    hud_element_draw_clipped(hid);
    hud_element_draw_clipped(acs->hudElements[HIDX_TICK_1]);
    hud_element_draw_clipped(acs->hudElements[HIDX_TICK_2]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_FRAME]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_LIGHT_1]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_LIGHT_2]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_LIGHT_3]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_RATING_1]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_RATING_2]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_RATING_3]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_DIGIT]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_TICK_1]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_TICK_2]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_BUFF_ICON]);
}
