#include "common.h"
#include "battle/action_cmd.h"
#include "battle/action_cmd/whirlwind_bubble.png.h"
#include "include_asset.h"

//TODO action command
#define NAMESPACE action_command_whirlwind

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

s32 D_802AA844_4254B4[] = { 0, 25, 50, 75, 100, 100 };

s32 D_802AA85C_4254CC[] = { 50, 50, 50, 50, 75, 75, 75, 100, 100, 100, 100 };

HudScript* D_802AA888_4254F8[] = {
    &HES_Whirlwind7, &HES_Whirlwind6, &HES_Whirlwind5, &HES_Whirlwind4, &HES_Whirlwind3, &HES_Whirlwind2
};

HudScript* D_802AA8A0_425510[] = {
    &HES_Whirlwind1, &HES_Whirlwind1, &HES_Whirlwind2, &HES_Whirlwind3, &HES_Whirlwind3
};

s32 D_802AA8B4_425524[] = { 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

extern s32 actionCmdTableWhirlwind[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hid;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableWhirlwind;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->targetWeakness = evt_get_variable(script, *args++);
    acs->actionCommandID = ACTION_COMMAND_WHIRLWIND;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    if (acs->targetWeakness == 0) {
        battleStatus->actionQuality = 0;
    } else {
        battleStatus->actionQuality = 3;
    }
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElements[0] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_Whirlwind7);
    acs->hudElements[2] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX + 54, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_WhirlwindBubble);
    acs->hudElements[3] = hid;
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
    if (acs->targetWeakness == 0) {
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
    s32 temp;
    s32 amt;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[0];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElements[1];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[2];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[3];
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
            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);
            hud_element_set_render_pos(acs->hudElements[2], acs->hudPosX + 54, acs->hudPosY + 23);
            hud_element_set_render_pos(acs->hudElements[3], acs->hudPosX + 60, acs->hudPosY + 23);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }
            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            acs->barFillLevel = 0;
            acs->state = AC_STATE_ACTIVE;
            acs->frameCounter = acs->duration;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);
            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
            temp = acs->barFillLevel / cutoff;
            if (acs->targetWeakness == 0) {
                amt = D_802AA844_4254B4[temp / 20];
            } else {
                amt = D_802AA85C_4254CC[temp / 10];
            }
            acs->barFillLevel -= amt;

            if (acs->barFillLevel < 0) {
                acs->barFillLevel = 0;
            }

            if (!acs->berserkerEnabled) {
                if (battleStatus->curButtonsPressed & BUTTON_A) {
                    s32 amt;

                    if (acs->targetWeakness == 0) {
                        amt = SCALE_BY_PCT(500, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                    } else {
                        amt = SCALE_BY_PCT(600, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                    }
                    acs->barFillLevel += amt;
                }
            } else {
                acs->barFillLevel += SCALE_BY_PCT(25, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                acs->barFillLevel += rand_int(SCALE_BY_PCT(25, battleStatus->actionCmdDifficultyTable[acs->difficulty]));
            }

            if (acs->barFillLevel > cutoff * 100) {
                acs->barFillLevel = cutoff * 100;
            }
            if (acs->targetWeakness == 0) {
                battleStatus->actionQuality = acs->barFillLevel / 2000;
            } else {
                battleStatus->actionQuality = D_802AA8B4_425524[acs->barFillLevel / 1000];
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
        hud_element_draw_clipped(acs->hudElements[0]);
    }
    hid = acs->hudElements[1];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 1);
    hud_element_draw_clipped(acs->hudElements[3]);
    hid = acs->hudElements[2];
    if (acs->targetWeakness == 0) {
        if (D_802AA888_4254F8[battleStatus->actionQuality] != hud_element_get_script(hid)) {
            hud_element_set_script(hid, D_802AA888_4254F8[battleStatus->actionQuality]);
        }
    } else {
        if (D_802AA8A0_425510[battleStatus->actionQuality] != hud_element_get_script(hid)) {
            hud_element_set_script(hid, D_802AA8A0_425510[battleStatus->actionQuality]);
        }
    }
    hud_element_draw_clipped(hid);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
