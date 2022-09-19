#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "hud_element.h"

#define NAMESPACE action_command_air_lift

void func_80268834(s32, s32, s16, s32);

extern HudScript HES_BlueMeter;
extern HudScript HES_AButton;
extern HudScript HES_MashAButton;
extern HudScript HES_100pct;
extern s32 D_80294340;

s32 D_802A9852_4292C0[] = { 0, 25, 50, 75, 75, 0, 0, 0 };

BSS s32 air_lift_bss_0;

ApiStatus func_802A9000_428A70(Evt* script, s32 isInitialCall) {
    s32 *args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudElement;

    battleStatus->unk_434 = &D_80294340;
    battleStatus->unk_82 = 0;
    battleStatus->unk_86 = 127;
    func_80268858();
    actionCommandStatus->unk_5A = evt_get_variable(script, *args++);
    actionCommandStatus->actionCommandID = ACTION_COMMAND_AIR_LIFT;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_84 = 0;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->hudElementX = -48;
    air_lift_bss_0 = 0;
    actionCommandStatus->hudElementY = 80;

    hudElement = hud_element_create(&HES_AButton);
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

ApiStatus func_802A9184_428BF4(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    u8 mashMeterCutoff;

    func_80268858();

    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->easyVersion = evt_get_variable(script, *args++);

    actionCommandStatus->unk_60 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 127;

    mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
    actionCommandStatus->unk_5C = 0;

    battleStatus->flags1 &= ~BS_FLAGS1_8000;
    actionCommandStatus->state = 10;
    battleStatus->unk_82 = mashMeterCutoff;

    func_80269118();

    return ApiStatus_DONE2;
}

void func_802A9278_428CE8(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
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

            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            air_lift_bss_0 = 1;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0, 0, 0);
            actionCommandStatus->state = 0xB;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_68 == 0) {
                if (actionCommandStatus->unk_5A != 0) {
                    s32 a = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];

                    actionCommandStatus->barFillLevel -= D_802A9852_4292C0[actionCommandStatus->barFillLevel / a / 20];
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                } else {
                    actionCommandStatus->barFillLevel -= 10;
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                }
            }

            if (battleStatus->unk_83 != 0 && (battleStatus->currentButtonsPressed & BUTTON_A)) {
                if (actionCommandStatus->unk_5A != 0) {
                    s32 a = battleStatus->unk_434[actionCommandStatus->unk_50];
                    s32 b = actionCommandStatus->unk_5A * 820;

                    actionCommandStatus->barFillLevel += (a * b) / 10000;
                } else {
                    actionCommandStatus->barFillLevel += 100;
                    if (actionCommandStatus->barFillLevel >= 500) {
                        actionCommandStatus->barFillLevel = 500;
                    }
                }

            }

            if (actionCommandStatus->barFillLevel > 10000) {
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->unk_68 = 1;
                id = actionCommandStatus->hudElements[2];
                hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 50, actionCommandStatus->hudElementY + 28);
                hud_element_clear_flags(id, 2);
            }

            battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
            if (battleStatus->unk_84 < battleStatus->actionSuccess) {
                battleStatus->unk_84 = battleStatus->actionSuccess;
            }
            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->actionSuccess * 12);

            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }

            if (actionCommandStatus->unk_5A == 0) {
                battleStatus->unk_84 = 0;
            }

            battleStatus->actionSuccess = battleStatus->unk_84;
            if (rand_int(99) < battleStatus->actionSuccess) {
                battleStatus->unk_86 = 1;
                battleStatus->actionSuccess = 1;
            } else {
                battleStatus->unk_86 = -2;
                battleStatus->actionSuccess = -1;
            }

            if (battleStatus->actionSuccess == 1) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(0x80000041);
            actionCommandStatus->unk_54 = 20;
            actionCommandStatus->state = 0xC;
            break;
        case 12:
            if (actionCommandStatus->unk_5A == 0) {
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

void N(draw_hud_elements)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudX;
    s32 hudY;
    s32 hudElement1;

    if (gBattleStatus.unk_83 != 0) {
        hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    }

    hudElement1 = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement1);
    hud_element_get_render_pos(hudElement1, &hudX, &hudY);

    if (air_lift_bss_0 == 0) {
        func_80268798(hudX, hudY, actionCommandStatus->barFillLevel / 100, 1);
    } else if (actionCommandStatus->unk_68 == 0) {
        func_80268798(hudX, hudY, actionCommandStatus->barFillLevel / 100, 4);
    } else {
        func_80268834(hudX, hudY, actionCommandStatus->barFillLevel / 100, 4);
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
}

#include "common/free_hud_elements.inc.c"
