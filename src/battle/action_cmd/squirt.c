#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_squirt

extern HudScript HudScript_BlueMeter[];
extern HudScript HudScript_AButton[];
extern HudScript HudScript_AButtonDown[];
extern HudScript HudScript_PressAButton[];
extern s32 D_80294380;

s32 D_802A9760_42A480[] = { 300, 300, 265, 220, 175, 175, };
s32 D_802A9778_42A498[] = { 300, 300, 265, 220, 175, 175, };

ApiStatus func_802A9000_429D20(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294380;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SQUIRT;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->unk_84 = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->unk_5C = 0;
    actionCommandStatus->hudElementY = 80;

    hudElement = hud_element_create(HudScript_AButton);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);

    hudElement = hud_element_create(HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

ApiStatus func_802A911C_429E3C(Evt* script) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;
    func_80269118();
    return ApiStatus_DONE2;
}

void func_802A9208_429F28(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 mashMeterCutoff;
    s32 cutoff;
    s32 temp;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->unk_61) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);

            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }

            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX,
                actionCommandStatus->hudElementY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX,
                actionCommandStatus->hudElementY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);

            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                break;
            }

            hud_element_set_script(actionCommandStatus->hudElements[0], HudScript_AButtonDown);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->unk_5C = 0;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0, 0, 0);
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
            temp = actionCommandStatus->barFillLevel / cutoff;
            if (actionCommandStatus->unk_5C == 0) {
                if (!(battleStatus->currentButtonsDown & BUTTON_A)) {
                    actionCommandStatus->barFillLevel -= D_802A9760_42A480[temp / 20];
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                } else {
                    actionCommandStatus->barFillLevel += D_802A9778_42A498[temp / 20] * battleStatus->unk_434[actionCommandStatus->unk_50] / 100;
                    if (actionCommandStatus->barFillLevel > 10000) {
                        actionCommandStatus->barFillLevel = 10000;
                        actionCommandStatus->unk_5C = 1;
                    }
                }
            } else {
                actionCommandStatus->barFillLevel -= 250;
                if (actionCommandStatus->barFillLevel <= 0) {
                    actionCommandStatus->barFillLevel = 0;
                    actionCommandStatus->unk_5C = 0;
                }
            }

            battleStatus->unk_84 = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->unk_84 * 12);
            id = actionCommandStatus->hudElements[0];
            if (temp < 80) {
                if (hud_element_get_script(id) != HudScript_AButtonDown) {
                    hud_element_set_script(id, HudScript_AButtonDown);
                }
            } else {
                if (hud_element_get_script(id) != HudScript_PressAButton) {
                    hud_element_set_script(id, HudScript_PressAButton);
                }
            }

            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }

            if (actionCommandStatus->barFillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = battleStatus->unk_84;
            }

            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
            if (cutoff / 2 < battleStatus->unk_84) {
                battleStatus->unk_86 = 1;
            } else {
                battleStatus->unk_86 = -4;
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
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
            } else {
                func_80268C9C();
            }
            break;
    }
}

void func_802A9634_42A354(void) {
    s32 x, y;
    s32 hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    hudElement = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &x, &y);
    if (actionCommandStatus->unk_5C == 0) {
        func_80268798(x, y, actionCommandStatus->barFillLevel / 100, 1);
    } else {
        func_802687E4(x, y, actionCommandStatus->barFillLevel / 100, 1, 1);
    }
}

void func_802A9720_42A440(void) {
    sfx_stop_sound(0x80000041);
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
}
