#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_spiny_surge

extern s32 D_80294400;
extern HudScript HudScript_BlueMeter;
extern HudScript HudScript_StickNeutral;
extern HudScript HudScript_StickMashLeft;
extern HudScript HudScript_100pct;

s32 D_802A9860_42F680[8] = { 0, 25, 50, 75, 75, 0, 0, 0 };
extern s32 D_802A98C0; // bss?

ApiStatus func_802A9000_42EE20(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 0x10;
    battleStatus->unk_434 = &D_80294400;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();

    actionCommandStatus->actionCommandID = 19;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    id = hud_element_create(&HudScript_StickNeutral);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_100pct);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

ApiStatus func_802A916C_42EF8C(Evt* script, s32 isInitialCall) {
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
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;

    func_80269118();

    return ApiStatus_DONE2;
}

void func_802A9254_42F074(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 cutoff;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            }

            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);

            if (actionCommandStatus->unk_6C != 0) {
                actionCommandStatus->unk_6C--;
                break;
            }

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

            hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_StickMashLeft);
            actionCommandStatus->unk_5C = 0;
            D_802A98C0 = 0;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0, 0, 0);
            actionCommandStatus->state = 11;

            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_68 == 0) {
                cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                actionCommandStatus->barFillLevel -=
                    D_802A9860_42F680[actionCommandStatus->barFillLevel / cutoff / 20];

                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }

                if (actionCommandStatus->unk_68 == 0) {
                    if (battleStatus->currentButtonsPressed & BUTTON_STICK_LEFT) {
                        actionCommandStatus->barFillLevel += (battleStatus->unk_434[actionCommandStatus->unk_50] * 1250) / 100;
                    }
                    if (battleStatus->currentButtonsPressed & BUTTON_STICK_RIGHT) {
                        actionCommandStatus->barFillLevel -= (battleStatus->unk_434[actionCommandStatus->unk_50] * 1250) / 100;
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

            if (D_802A98C0 & BUTTON_STICK_LEFT) {
                actionCommandStatus->unk_5C = 1;
            }
            if (D_802A98C0 & BUTTON_STICK_RIGHT) {
                actionCommandStatus->unk_5C = -1;
            }

            if (!(D_802A98C0 & BUTTON_STICK_LEFT) &&
                !(battleStatus->currentButtonsDown & BUTTON_STICK_RIGHT) &&
                actionCommandStatus->unk_5C == 1)
            {
                actionCommandStatus->unk_5C = 2;
            }
            battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
            D_802A98C0 = battleStatus->currentButtonsDown;
            battleStatus->unk_84 = actionCommandStatus->unk_5C;

            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->actionSuccess * 12);

            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }

            if (actionCommandStatus->barFillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
            }

            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
            if (cutoff >= battleStatus->actionSuccess) {
                battleStatus->unk_86 = -2;
            } else {
                battleStatus->unk_86 = 1;
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

#include "common/UnkActionCommandFunc1.inc.c"

#include "common/free_hud_elements.inc.c"
