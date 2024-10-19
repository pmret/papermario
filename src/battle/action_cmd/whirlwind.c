#include "common.h"
#include "battle/action_cmd.h"
#include "battle/action_cmd/whirlwind_bubble.png.h"
#include "include_asset.h"

#define NAMESPACE action_command_whirlwind

extern s32 actionCmdTableWhirlwind[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
    HIDX_DIGIT          = 2,
    HIDX_BUBBLE         = 3,
};

// how much to add to the meter per input
#define HUFF_FILL_TICK 500
#define BUZZAR_FILL_TICK 600

INCLUDE_IMG("battle/action_cmd/whirlwind_1.png", battle_action_cmd_whirlwind_1_png);
INCLUDE_PAL("battle/action_cmd/whirlwind_1.pal", battle_action_cmd_whirlwind_1_pal);

INCLUDE_IMG("battle/action_cmd/whirlwind_2.png", battle_action_cmd_whirlwind_2_png);
INCLUDE_PAL("battle/action_cmd/whirlwind_2.pal", battle_action_cmd_whirlwind_2_pal);

INCLUDE_IMG("battle/action_cmd/whirlwind_3.png", battle_action_cmd_whirlwind_3_png);
INCLUDE_PAL("battle/action_cmd/whirlwind_3.pal", battle_action_cmd_whirlwind_3_pal);

INCLUDE_IMG("battle/action_cmd/whirlwind_4.png", battle_action_cmd_whirlwind_4_png);
INCLUDE_PAL("battle/action_cmd/whirlwind_4.pal", battle_action_cmd_whirlwind_4_pal);

INCLUDE_IMG("battle/action_cmd/whirlwind_5.png", battle_action_cmd_whirlwind_5_png);
INCLUDE_PAL("battle/action_cmd/whirlwind_5.pal", battle_action_cmd_whirlwind_5_pal);

INCLUDE_IMG("battle/action_cmd/whirlwind_6.png", battle_action_cmd_whirlwind_6_png);
INCLUDE_PAL("battle/action_cmd/whirlwind_6.pal", battle_action_cmd_whirlwind_6_pal);

INCLUDE_IMG("battle/action_cmd/whirlwind_7.png", battle_action_cmd_whirlwind_7_png);
INCLUDE_PAL("battle/action_cmd/whirlwind_7.pal", battle_action_cmd_whirlwind_7_pal);

INCLUDE_IMG("battle/action_cmd/whirlwind_bubble.png", battle_action_cmd_whirlwind_bubble_png);
INCLUDE_PAL("battle/action_cmd/whirlwind_bubble.pal", battle_action_cmd_whirlwind_bubble_pal);

HudScript HES_Whirlwind1 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_whirlwind_1, 24, 24);
HudScript HES_Whirlwind2 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_whirlwind_2, 24, 24);
HudScript HES_Whirlwind3 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_whirlwind_3, 24, 24);
HudScript HES_Whirlwind4 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_whirlwind_4, 24, 24);
HudScript HES_Whirlwind5 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_whirlwind_5, 24, 24);
HudScript HES_Whirlwind6 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_whirlwind_6, 24, 24);
HudScript HES_Whirlwind7 = HES_TEMPLATE_CI_ENUM_SIZE(battle_action_cmd_whirlwind_7, 24, 24);

HudScript HES_WhirlwindBubble = HES_TEMPLATE_CI_CUSTOM_SIZE(battle_action_cmd_whirlwind_bubble,
    battle_action_cmd_whirlwind_bubble_png_width, battle_action_cmd_whirlwind_bubble_png_height);

s32 N(DrainRateTable0)[] = { 0, 25, 50, 75, 100, 100 };
s32 N(DrainRateTable1)[] = { 50, 50, 50, 50, 75, 75, 75, 100, 100, 100, 100 };

// bug: the final entry is not accessible due to the way idx is calculated in these macros
#define GET_DRAIN_RATE_HUFF(pct)    (N(DrainRateTable0)[((pct) / (ONE_PCT_MASH / 5))])
#define GET_DRAIN_RATE_BUZZAR(pct)  (N(DrainRateTable1)[((pct) / (ONE_PCT_MASH / 10))])

HudScript* N(HuffDigits)[] = {
    &HES_Whirlwind7, &HES_Whirlwind6, &HES_Whirlwind5, &HES_Whirlwind4, &HES_Whirlwind3, &HES_Whirlwind2
};

HudScript* N(BuzzarDigits)[] = {
    &HES_Whirlwind1, &HES_Whirlwind1, &HES_Whirlwind2, &HES_Whirlwind3, &HES_Whirlwind3
};

s32 N(BuzzarQuality)[] = { 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hid;

    battleStatus->maxActionSuccess = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableWhirlwind;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->variation = evt_get_variable(script, *args++);
    acs->actionCommandID = ACTION_COMMAND_WHIRLWIND;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    if (acs->variation == ACV_WHIRLWIND_HUFF) {
        battleStatus->actionQuality = 0;
    } else {
        battleStatus->actionQuality = 3;
    }
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElements[HIDX_BUTTON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElements[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_Whirlwind7);
    acs->hudElements[HIDX_DIGIT] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX + 54, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_WhirlwindBubble);
    acs->hudElements[HIDX_BUBBLE] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX + 60, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

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
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    if (acs->variation == ACV_WHIRLWIND_HUFF) {
        battleStatus->actionQuality = 0;
    } else {
        battleStatus->actionQuality = 3;
    }
    acs->state = AC_STATE_START;
    gBattleStatus.flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;
    s32 cutoff;
    s32 fillPct;
    s32 amt;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[HIDX_BUTTON];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElements[HIDX_METER];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[HIDX_DIGIT];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[HIDX_BUBBLE];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElements[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            hud_element_set_render_pos(acs->hudElements[HIDX_DIGIT], acs->hudPosX + 54, acs->hudPosY + 23);
            hud_element_set_render_pos(acs->hudElements[HIDX_BUBBLE], acs->hudPosX + 60, acs->hudPosY + 23);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }
            hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_MashAButton);
            acs->barFillLevel = 0;
            acs->state = AC_STATE_ACTIVE;
            acs->frameCounter = acs->duration;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // apply bar draining every frame
            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
            fillPct = acs->barFillLevel / cutoff;
            if (acs->variation == ACV_WHIRLWIND_HUFF) {
                amt = GET_DRAIN_RATE_HUFF(fillPct);
            } else {
                amt = GET_DRAIN_RATE_BUZZAR(fillPct);
            }
            acs->barFillLevel -= amt;

            if (acs->barFillLevel < 0) {
                acs->barFillLevel = 0;
            }

            // check for bar-filling input
            if (!acs->berserkerEnabled) {
                if (battleStatus->curButtonsPressed & BUTTON_A) {
                    if (acs->variation == ACV_WHIRLWIND_HUFF) {
                        amt = SCALE_BY_PCT(HUFF_FILL_TICK, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                    } else {
                        amt = SCALE_BY_PCT(BUZZAR_FILL_TICK, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                    }
                    acs->barFillLevel += amt;
                }
            } else {
                acs->barFillLevel += SCALE_BY_PCT(25, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                acs->barFillLevel += rand_int(SCALE_BY_PCT(25, battleStatus->actionCmdDifficultyTable[acs->difficulty]));
            }

            // cap bar to maximum fill level
            if (acs->barFillLevel > cutoff * 100) {
                acs->barFillLevel = cutoff * 100;
            }

            if (acs->variation == ACV_WHIRLWIND_HUFF) {
                battleStatus->actionQuality = (acs->barFillLevel / ONE_PCT_MASH) / 20;
            } else {
                battleStatus->actionQuality = N(BuzzarQuality)[(acs->barFillLevel / ONE_PCT_MASH) / 10];
            }

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }
            battleStatus->actionResult = ACTION_RESULT_NONE;
            battleStatus->actionSuccess = battleStatus->actionQuality;
            btl_set_popup_duration(POPUP_MSG_OFF);
            acs->frameCounter = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
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
    s32 hudX, hudY;
    s32 hid;

    if (!acs->berserkerEnabled) {
        hud_element_draw_clipped(acs->hudElements[HIDX_BUTTON]);
    }
    hid = acs->hudElements[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 1);
    hud_element_draw_clipped(acs->hudElements[HIDX_BUBBLE]);

    hid = acs->hudElements[HIDX_DIGIT];
    if (acs->variation == ACV_WHIRLWIND_HUFF) {
        if (N(HuffDigits)[battleStatus->actionQuality] != hud_element_get_script(hid)) {
            hud_element_set_script(hid, N(HuffDigits)[battleStatus->actionQuality]);
        }
    } else {
        if (N(BuzzarDigits)[battleStatus->actionQuality] != hud_element_get_script(hid)) {
            hud_element_set_script(hid, N(BuzzarDigits)[battleStatus->actionQuality]);
        }
    }
    hud_element_draw_clipped(hid);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_METER]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_DIGIT]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_BUBBLE]);
}
