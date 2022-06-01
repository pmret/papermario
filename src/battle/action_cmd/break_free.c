#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_break_free

extern s32 D_80294220;
extern HudScript HudScript_AButton;
extern HudScript HudScript_MashAButton;
extern HudScript HudScript_BlueMeter;
extern HudScript HudScript_RunningAway;
extern HudScript HudScript_RunAwayOK;

ApiStatus func_802A9000_4233F0(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 0;
    battleStatus->unk_434 = &D_80294220;
    battleStatus->unk_86 = 127;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_BREAK_FREE;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_46 = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    id = hud_element_create(&HudScript_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_RunningAway);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_RunAwayOK);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

ApiStatus func_802A91B0_4235A0(Evt* script, s32 isInitialCall) {
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
    actionCommandStatus->unk_5A = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);

    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_46 = 0;
    actionCommandStatus->unk_48 = 0;

    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0x7F;
    battleStatus->unk_82 = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];

    actionCommandStatus->unk_46 = rand_int(actionCommandStatus->unk_5A);
    actionCommandStatus->unk_5C = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;

    return ApiStatus_DONE2;
}

void func_802A92DC_4236CC(void) {
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

            id = actionCommandStatus->hudElements[2];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[3];
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
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX + 31, actionCommandStatus->hudElementY - 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX + 31, actionCommandStatus->hudElementY + 17);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                return;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_MashAButton);
            actionCommandStatus->state = 11;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_5C == 0) {
                actionCommandStatus->unk_46++;
                if (actionCommandStatus->unk_46 >= actionCommandStatus->unk_5A) {
                    actionCommandStatus->unk_46 = actionCommandStatus->unk_5A;
                    actionCommandStatus->unk_5C = 1;
                }
            } else {
                actionCommandStatus->unk_46--;
                if (actionCommandStatus->unk_46 <= 0) {
                    actionCommandStatus->unk_46 = 0;
                    actionCommandStatus->unk_5C = 0;
                }
            }

            if (actionCommandStatus->unk_6A == 0) {
                s32 inputBufPos = battleStatus->inputBufferPos;
                s32 temp_a2 = actionCommandStatus->unk_52 - actionCommandStatus->unk_54;
                s32 i;

                actionCommandStatus->barFillLevel = 0;

                inputBufPos -= temp_a2;
                if (inputBufPos < 0) {
                    inputBufPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                for (i = 0; i < temp_a2; i++, inputBufPos++) {
                    if (inputBufPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        inputBufPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }
                    if (battleStatus->pushInputBuffer[inputBufPos] & BUTTON_A) {
                        actionCommandStatus->barFillLevel += battleStatus->unk_434[actionCommandStatus->unk_50];
                    }
                }
            } else {
                actionCommandStatus->barFillLevel += (battleStatus->unk_434[actionCommandStatus->unk_50]) / 4;
                actionCommandStatus->barFillLevel += rand_int(battleStatus->unk_434[actionCommandStatus->unk_50] / 4);
            }

            battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }

            if (battleStatus->actionSuccess >= actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals] - actionCommandStatus->unk_46) {
                battleStatus->unk_86 = 1;
                battleStatus->actionSuccess = 1;
            } else {
                battleStatus->unk_86 = -2;
                battleStatus->actionSuccess = -1;
            }

            btl_set_popup_duration(0);
            actionCommandStatus->unk_54 = 20;
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

void N(draw_hud_elements)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32* hudElements = actionCommandStatus->hudElements;
    s32 hudX;
    s32 hudY;
    s32 id;
    s16 mashMeterCutoff;
    s32 thirtyOne;

    mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
    hudX = 60 - ((mashMeterCutoff - actionCommandStatus->unk_46) * 60 / mashMeterCutoff);

    // Putting 31 into a variable manually fixes regalloc, so perhaps this was a constant defined somewhere?
    thirtyOne = 31;
    hud_element_set_render_pos(hudElements[3], actionCommandStatus->hudElementX - (hudX - thirtyOne),
        actionCommandStatus->hudElementY + 17);
    hud_element_set_render_pos(hudElements[2], actionCommandStatus->hudElementX - (hudX - thirtyOne),
        actionCommandStatus->hudElementY - 1);

    if (actionCommandStatus->unk_6A == 0) {
        hud_element_draw_clipped(hudElements[0]);
    }

    id = hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &hudX, &hudY);

    func_80268770(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    hud_element_draw_clipped(hudElements[2]);
    hud_element_draw_clipped(hudElements[3]);
}

void N(free_hud_elements)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
