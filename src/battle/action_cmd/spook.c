#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_spook

extern HudScript HudScript_BlueMeter[];
extern HudScript HudScript_StickNeutral[];
extern HudScript HudScript_StickMashLeft[];
extern HudScript HudScript_100pct[];
extern s32 D_80294440;

s32 D_802A9920_430940[8] = { 0, 25, 50, 75, 75, 0, 0, 0 };

ApiStatus func_802A9000_430020(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->unk_434 = &D_80294440;
    battleStatus->unk_86 = 127;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SPOOK;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_84 = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = hud_element_create(HudScript_StickNeutral);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(HudScript_100pct);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

void func_802A9298_4302B8(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 cutoff;
    s32 fillLevel;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                return;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], HudScript_StickMashLeft);
            actionCommandStatus->barFillLevel = 0;
            battleStatus->unk_84 = 0;
            actionCommandStatus->unk_5C = 0;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0, 0, 0);
            actionCommandStatus->state = 11;
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_68 == 0) {
                if (actionCommandStatus->unk_64 != 0) {
                    cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];

                    actionCommandStatus->barFillLevel -= D_802A9920_430940[actionCommandStatus->barFillLevel / cutoff / 20];
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                } else {
                    actionCommandStatus->barFillLevel -= 10;
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                }

                 if (actionCommandStatus->unk_68 == 0) {
                    if (actionCommandStatus->unk_64 != 0) {

                        if (battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) {
                            actionCommandStatus->unk_5C = TRUE;
                        }

                        if (!(battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) && actionCommandStatus->unk_5C) {
                            s32 a = battleStatus->unk_434[actionCommandStatus->unk_50];
                            s32 b = actionCommandStatus->unk_64 * 850;

                            actionCommandStatus->barFillLevel += (a * b) / 10000;
                            actionCommandStatus->unk_5C = 0;
                        }

                        if (battleStatus->currentButtonsPressed & BUTTON_STICK_RIGHT) {
                            s32 a = battleStatus->unk_434[actionCommandStatus->unk_50];
                            s32 b = actionCommandStatus->unk_64 * 850;

                            actionCommandStatus->barFillLevel -= (a * b) / 10000;
                        }
                    } else {
                        if (battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) {
                            actionCommandStatus->unk_5C = TRUE;
                        }

                        if (!(battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) && actionCommandStatus->unk_5C) {
                            actionCommandStatus->barFillLevel += 100;
                            if (actionCommandStatus->barFillLevel >= 500) {
                                actionCommandStatus->barFillLevel = 500;
                            }
                            actionCommandStatus->unk_5C = 0;
                        }

                        if (battleStatus->currentButtonsPressed & BUTTON_STICK_RIGHT) {
                            actionCommandStatus->barFillLevel -= 100;
                        }
                    }
                }
            }

            if (actionCommandStatus->barFillLevel < 0) {
                actionCommandStatus->barFillLevel = 0;
            }
            if (actionCommandStatus->barFillLevel > 10000) {
                id = actionCommandStatus->hudElements[2];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->unk_68 = 1;
                hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 50, actionCommandStatus->hudElementY + 28);
                hud_element_clear_flags(id, 2);
            }

            battleStatus->unk_84 = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->unk_84 * 12);

            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }

            fillLevel = actionCommandStatus->barFillLevel;
            if (actionCommandStatus->unk_64 == 0) {
                fillLevel = 0;
            }

            if (fillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = fillLevel / 100;

            }

            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
            if (battleStatus->actionSuccess > cutoff) {
                battleStatus->unk_86 = 1;
            } else {
                battleStatus->unk_86 = -2;
            }

            if (battleStatus->actionSuccess == 100) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(0x80000041);
            actionCommandStatus->unk_54 = 5;
            actionCommandStatus->state = 12;
            break;
        case 12:
            if (actionCommandStatus->unk_64 == 0) {
                actionCommandStatus->barFillLevel -= 100;
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
            }

            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }
            func_80268C9C();
            break;
    }
}

#include "common/UnkActionCommandFunc1.inc.c"

#include "common/free_hud_elements.inc.c"
