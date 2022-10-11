#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_flee

extern HudScript HES_BlueMeter;
extern HudScript HES_AButton;
extern HudScript HES_RunAwayOK;
extern HudScript HES_RunningAway;
extern HudScript HES_100pct;
extern s32 D_80294200;
extern s32 D_802A9920;
extern HudScript HES_MashAButton;

ApiStatus func_802A9000_422AD0(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 xOffset;
    s32 hudElement;

    battleStatus->unk_82 = 0;
    battleStatus->unk_434 = &D_80294200;
    battleStatus->unk_86 = 127;
    func_80268858();
    actionCommandStatus->unk_5A = evt_get_variable(script, *args++);
    actionCommandStatus->actionCommandID = ACTION_COMMAND_FLEE;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = actionCommandStatus->unk_5A * 100;
    actionCommandStatus->unk_46 = rand_int(50);
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_5C = 1;
    actionCommandStatus->unk_5A = rand_int(1);
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudElementX = -48;
    D_802A9920 = 0;
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

    hudElement = hud_element_create(&HES_RunningAway);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(&HES_RunAwayOK);
    actionCommandStatus->hudElements[3] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    xOffset = 29 - ((100 - actionCommandStatus->unk_46) * 60) / 100;
    hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX - xOffset, actionCommandStatus->hudElementY + 17);
    hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX - xOffset, actionCommandStatus->hudElementY - 1);

    hudElement = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[4] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

ApiStatus func_802A92A0_422D70(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    func_80268858();
    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_60 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 127;
    battleStatus->unk_82 = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
    battleStatus->flags1 &= ~BS_FLAGS1_8000;
    actionCommandStatus->state = 10;
    return ApiStatus_DONE2;
}

void func_802A9378_422E48(void) {
    s32 temp;
    s32 hudElement;
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    switch (actionCommandStatus->state) {
        case 0:
            hudElement = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            hudElement = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            hudElement = actionCommandStatus->hudElements[2];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            hudElement = actionCommandStatus->hudElements[3];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
            break;
        case 10:
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                break;
            }

            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            D_802A9920 = 1;
            actionCommandStatus->state = 11;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
        case 11:
            if ((battleStatus->unk_83 != 0) && (battleStatus->currentButtonsPressed & BUTTON_A)) {
                actionCommandStatus->barFillLevel += (battleStatus->unk_434[actionCommandStatus->unk_50] * 180 / 100);
            }
            if (actionCommandStatus->barFillLevel >= 10000) {
                hudElement = actionCommandStatus->hudElements[4];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->unk_68 = 1;
                hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX + 50, actionCommandStatus->hudElementY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
            if (actionCommandStatus->unk_54 == 0) {
                if (battleStatus->actionSuccess >= (100 - actionCommandStatus->unk_46)) {
                    battleStatus->unk_86 = 1;
                    battleStatus->actionSuccess = 1;
                } else {
                    battleStatus->unk_86 = -2;
                    battleStatus->actionSuccess = -1;
                }
                actionCommandStatus->unk_54 = 20;
                actionCommandStatus->state = 12;
            } else {
                actionCommandStatus->unk_54--;
            }
            break;
        case 12:
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                break;
            }
            func_80268C9C();
            break;
    }

    switch (actionCommandStatus->state) {
        case 1:
        case 10:
        case 11:
            temp = actionCommandStatus->unk_5A == 0 ? 7 : 8;
            if (actionCommandStatus->unk_5C == 0) {
                actionCommandStatus->unk_46 += temp;
                if (actionCommandStatus->unk_46 >= 100) {
                    actionCommandStatus->unk_46 = 100;
                    actionCommandStatus->unk_5C = 1;
                }
                break;
            }
            actionCommandStatus->unk_46 -= temp;
            if (actionCommandStatus->unk_46 <= 0) {
                actionCommandStatus->unk_46 = 0;
                actionCommandStatus->unk_5C = 0;
            }
    }
}

void N(draw_hud_elements)(void) {
    s32 y;
    s32 x;
    s32 temp_a1;
    s32 hudElement;
    s32 temp_v1;

    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    temp_v1 = (100 - actionCommandStatus->unk_46) * 60;
    x = 60 - temp_v1 / 100;
    temp_a1 = x - 31;

    hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX - temp_a1, actionCommandStatus->hudElementY + 17);
    hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX + 31 - x, actionCommandStatus->hudElementY - 1);

    if (battleStatus->unk_83 != 0) {
        hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    }

    hudElement = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &x, &y);

    if (D_802A9920 == 0) {
        func_80268798(x, y, actionCommandStatus->barFillLevel / 100, 1);
    } else {
        if (actionCommandStatus->unk_68 == 0) {
            func_80268798(x, y, actionCommandStatus->barFillLevel / 100, 4);
        } else {
            func_8026880C(x, y, actionCommandStatus->barFillLevel / 100);
        }
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[3]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[4]);
}

void N(free_hud_elements)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
