#include "common.h"
#include "battle/action_cmd.h"
#include "battle/action_cmd/whirlwind_bubble.png.h"

#define NAMESPACE action_command_whirlwind

#include "battle/action_cmd/whirlwind_1.png.inc.c"
#include "battle/action_cmd/whirlwind_1.pal.inc.c"

#include "battle/action_cmd/whirlwind_2.png.inc.c"
#include "battle/action_cmd/whirlwind_2.pal.inc.c"

#include "battle/action_cmd/whirlwind_3.png.inc.c"
#include "battle/action_cmd/whirlwind_3.pal.inc.c"

#include "battle/action_cmd/whirlwind_4.png.inc.c"
#include "battle/action_cmd/whirlwind_4.pal.inc.c"

#include "battle/action_cmd/whirlwind_5.png.inc.c"
#include "battle/action_cmd/whirlwind_5.pal.inc.c"

#include "battle/action_cmd/whirlwind_6.png.inc.c"
#include "battle/action_cmd/whirlwind_6.pal.inc.c"

#include "battle/action_cmd/whirlwind_7.png.inc.c"
#include "battle/action_cmd/whirlwind_7.pal.inc.c"

#include "battle/action_cmd/whirlwind_bubble.png.inc.c"
#include "battle/action_cmd/whirlwind_bubble.pal.inc.c"

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
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s16 temp_v0;
    s32 id;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableWhirlwind;
    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->targetWeakness = evt_get_variable(script, *args++);
    actionCommandStatus->actionCommandID = ACTION_COMMAND_WHIRLWIND;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    if (actionCommandStatus->targetWeakness == 0) {
        battleStatus->actionResult = 0;
    } else {
        battleStatus->actionResult = 3;
    }
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_Whirlwind7);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 54, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_WhirlwindBubble);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 60, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    if (actionCommandStatus->targetWeakness == 0) {
        battleStatus->actionResult = 0;
    } else {
        battleStatus->actionResult = 3;
    }
    actionCommandStatus->state = 10;
    gBattleStatus.flags1 &= ~BS_FLAGS1_8000;
    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 cutoff;
    s32 temp;
    s32 amt;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[2];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[3];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudPosX + 54, actionCommandStatus->hudPosY + 23);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudPosX + 60, actionCommandStatus->hudPosY + 23);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                return;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->state = 11;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
        case 11:
            btl_set_popup_duration(99);
            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
            temp = actionCommandStatus->barFillLevel / cutoff;
            if (actionCommandStatus->targetWeakness == 0) {
                amt = D_802AA844_4254B4[temp / 20];
            } else {
                amt = D_802AA85C_4254CC[temp / 10];
            }
            actionCommandStatus->barFillLevel -= amt;

            if (actionCommandStatus->barFillLevel < 0) {
                actionCommandStatus->barFillLevel = 0;
            }

            if (!actionCommandStatus->berserkerEnabled) {
                if (battleStatus->curButtonsPressed & BUTTON_A) {
                    s32 amt;

                    if (actionCommandStatus->targetWeakness == 0) {
                        amt = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 5;
                    } else {
                        amt = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 6;
                    }
                    actionCommandStatus->barFillLevel += amt;
                }
            } else {
                actionCommandStatus->barFillLevel += battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] / 4;
                actionCommandStatus->barFillLevel += rand_int(battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] / 4);
            }

            if (actionCommandStatus->barFillLevel > cutoff * 100) {
                actionCommandStatus->barFillLevel = cutoff * 100;
            }
            if (!actionCommandStatus->targetWeakness) {
                battleStatus->actionResult = actionCommandStatus->barFillLevel / 2000;
            } else {
                battleStatus->actionResult = D_802AA8B4_425524[actionCommandStatus->barFillLevel / 1000];
            }

            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }
            battleStatus->unk_86 = 127;
            battleStatus->actionSuccess = battleStatus->actionResult;
            btl_set_popup_duration(0);
            actionCommandStatus->frameCounter = 5;
            actionCommandStatus->state = 12;
            break;
        case 12:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 x, y;
    s32 id;

    if (!actionCommandStatus->berserkerEnabled) {
        hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    }
    id = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &x, &y);

    draw_mash_meter_multicolor_with_divisor(x, y, actionCommandStatus->barFillLevel / 100, 1);
    hud_element_draw_clipped(actionCommandStatus->hudElements[3]);
    id = actionCommandStatus->hudElements[2];
    if (!actionCommandStatus->targetWeakness) {
        if (D_802AA888_4254F8[battleStatus->actionResult] != hud_element_get_script(id)) {
            hud_element_set_script(id, D_802AA888_4254F8[battleStatus->actionResult]);
        }
    } else {
        if (D_802AA8A0_425510[battleStatus->actionResult] != hud_element_get_script(id)) {
            hud_element_set_script(id, D_802AA8A0_425510[battleStatus->actionResult]);
        }
    }
    hud_element_draw_clipped(id);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
