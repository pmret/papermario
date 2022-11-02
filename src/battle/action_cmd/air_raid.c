#include "common.h"
#include "battle/battle.h"
#include "hud_element.h"

#define NAMESPACE action_command_air_raid

extern HudScript HES_BlueMeter;
extern HudScript HES_StickNeutral;
extern HudScript HES_100pct;
extern HudScript HES_StickMashLeft;

extern s32 D_80294360;

s32 D_802A9970_429C90[] = { 0, 25, 50, 75, 75, };
s32 D_802A9984_429CA4[] = { 40, 70, 99, 200, };
s32 D_802A9994_429CB4[] = { 35, 60, 80, 99, 200, };
s32 D_802A99A8_429CC8[] = { 35, 35, 60, 80, 99, 200, };

ApiStatus func_802A9000_429320(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->unk_434 = &D_80294360;
    battleStatus->unk_86 = 127;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();

    actionCommandStatus->actionCommandID = 14;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = hud_element_create(&HES_StickNeutral);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

void func_802A9294_4295B4(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 cutoff;
    s32 id;

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

            if (actionCommandStatus->unk_6C != 0) {
                actionCommandStatus->unk_6C--;
                return;
            }

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

            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_StickMashLeft);
            actionCommandStatus->barFillLevel = 0;
            battleStatus->unk_85 = 0;
            actionCommandStatus->unk_5C = 0;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(SOUND_80000041, 0, 0, 0);
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_68 == 0) {
                cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];

                actionCommandStatus->barFillLevel -= D_802A9970_429C90[actionCommandStatus->barFillLevel / cutoff / 20];
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }

                if (actionCommandStatus->unk_68 == 0) {
                    if ( // todo remove assignment from conditional
                        (!(battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) || (actionCommandStatus->unk_5C = 1, !(battleStatus->currentButtonsDown & BUTTON_STICK_LEFT))) &&
                        (actionCommandStatus->unk_5C != 0))
                    {
                        actionCommandStatus->barFillLevel += (battleStatus->unk_434[actionCommandStatus->unk_50] * 850) / 100;
                        actionCommandStatus->unk_5C = 0;
                    }

                    if (battleStatus->currentButtonsPressed & BUTTON_STICK_RIGHT) {
                        actionCommandStatus->barFillLevel -= (battleStatus->unk_434[actionCommandStatus->unk_50] * 850) / 100;
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

            switch (partner->actorBlueprint->level) {
                case 0:
                    if (battleStatus->unk_84 >= D_802A9984_429CA4[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }

                    if (battleStatus->unk_85 > 0 && battleStatus->unk_84 < D_802A9984_429CA4[battleStatus->unk_85 - 1]) {
                        battleStatus->unk_85--;
                    }
                    break;
                case 1:
                    if (battleStatus->unk_84 >= D_802A9994_429CB4[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }
                    if (battleStatus->unk_85 > 0 && battleStatus->unk_84 < D_802A9994_429CB4[battleStatus->unk_85 - 1]) {
                        battleStatus->unk_85--;
                    }
                    break;
                case 2:
                    if (battleStatus->unk_84 >= D_802A99A8_429CC8[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }
                    if (battleStatus->unk_85 > 0 && battleStatus->unk_84 < D_802A99A8_429CC8[battleStatus->unk_85 - 1]) {
                        battleStatus->unk_85--;
                    }
                    break;
            }

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
            if (battleStatus->actionSuccess <= cutoff) {
                battleStatus->unk_86 = -2;
            } else {
                battleStatus->unk_86 = 1;
            }

            if (battleStatus->actionSuccess == 100) {
                func_80269160();
            }

            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_80000041);
            actionCommandStatus->unk_54 = 5;
            actionCommandStatus->state = 12;
            break;
        case 12:
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }
            func_80268C9C();
            break;
    }
}

#include "common/draw_hud_elements.inc.c"

#include "common/free_hud_elements.inc.c"
