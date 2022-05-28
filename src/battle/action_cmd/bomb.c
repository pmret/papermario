#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_bomb

extern HudScript HudScript_BlueMeter;
extern HudScript HudScript_AButton;
extern HudScript HudScript_100pct;
extern s32 D_80294300;

extern HudScript HudScript_MashAButton;

s32 D_802A9810_428280[] = { 0, 25, 50, 75, 75, 0, 0, 0 };

ApiStatus func_802A9000_427A70(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->unk_434 = &D_80294300;
    battleStatus->unk_86 = 127;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = 0xB;
    actionCommandStatus->unk_61 = TRUE;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = FALSE;
    battleStatus->actionSuccess = 0;

    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = hud_element_create(&HudScript_AButton);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(&HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(&HudScript_100pct);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

void func_802A928C_427CFC(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;
    s32 mashMeterCutoff;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            hudElement = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(hudElement, 255);
            if (actionCommandStatus->unk_61) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            hudElement = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(hudElement, 255);
            if (actionCommandStatus->unk_61) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
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

            hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_MashAButton);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0, 0, 0);
            actionCommandStatus->state = 11;

            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->unk_68) {
                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                actionCommandStatus->barFillLevel -=
                    D_802A9810_428280[actionCommandStatus->barFillLevel / mashMeterCutoff / 20];

                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
            }

            if (battleStatus->currentButtonsPressed & 0x8000) {
                switch(actionCommandStatus->unk_64) {
                    case 0: {
                        s32 fillOffset = battleStatus->unk_434[actionCommandStatus->unk_50] * 235 * 4;
                        actionCommandStatus->barFillLevel += fillOffset / 100;
                        break;
                    }
                    case 1:
                        actionCommandStatus->barFillLevel += battleStatus->unk_434[actionCommandStatus->unk_50] * 8;
                        break;
                    case 2: {
                        s32 fillOffset = battleStatus->unk_434[actionCommandStatus->unk_50] * 185 * 4;
                        actionCommandStatus->barFillLevel += fillOffset / 100;
                        break;
                    }
                }
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                hudElement = actionCommandStatus->hudElements[2];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->unk_68 = TRUE;
                hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX + 50,
                    actionCommandStatus->hudElementY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            battleStatus->unk_84 = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->unk_84 * 12);

            if (actionCommandStatus->unk_54 == 0) {
                if (actionCommandStatus->barFillLevel == 0) {
                    battleStatus->actionSuccess = -1;
                } else {
                    battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
                }

                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
                if (mashMeterCutoff >= battleStatus->actionSuccess) {
                    battleStatus->unk_86 = -2;
                } else {
                    battleStatus->unk_86 = 1;
                }

                if (battleStatus->actionSuccess == 100) {
                    func_80269160();
                }

                sfx_stop_sound(0x80000041);
                btl_set_popup_duration(0);
                actionCommandStatus->unk_54 = 5;
                actionCommandStatus->state = 12;
            } else {
                actionCommandStatus->unk_54--;
            }
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

#include "common/draw_hud_elements.inc.c"

#include "common/free_hud_elements.inc.c"
