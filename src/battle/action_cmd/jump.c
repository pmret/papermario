#include "common.h"

#define NAMESPACE action_command_jump

extern s32 D_802941C0;

// icon id's for hud elements
extern s32 D_80108B28;
extern s32 D_80292A2C;
extern s32 D_80108B54;

ApiStatus N(CreateHudElements)(ScriptInstance* script, s32 isInitialCall) {
    HudElement* hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    gBattleStatus.unk_82 = 1;
    gBattleStatus.unk_434 = &D_802941C0;
    gBattleStatus.unk_86 = 0;

    if (gBattleStatus.unk_83 == 0) {
        gBattleStatus.actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    
    func_80268858();
    actionCommandStatus->actionCommandID = 1;
    actionCommandStatus->hudElementX = -0x30;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->hudElementY = 0x50;

    hudElement = create_hud_element(&D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_flags(hudElement, 0x82);
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_alpha(hudElement, 0xFF);

    hudElement = create_hud_element(&D_80292A2C);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_flags(hudElement, 0x82);
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_alpha(hudElement, 0xFF);

    return ApiStatus_DONE2;
}

ApiStatus func_802A9120_421B10(ScriptInstance* script, s32 isInitialCall) {
    HudElement* hudElement;

    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    } else {
        func_80268858();
        actionCommandStatus->unk_4E = get_variable(script, *args++);
        actionCommandStatus->unk_50 = get_variable(script, *args++);
        actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
        actionCommandStatus->unk_60 = 0;
        battleStatus->actionSuccess = 0;

        hudElement = actionCommandStatus->hudElements[0];
        actionCommandStatus->hudElementX = 0x32;
        battleStatus->flags1 &= ~0x8000;
        battleStatus->flags1 &= ~0x2000;
        set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
        if (actionCommandStatus->unk_61 != 0) {
            clear_hud_element_flags(hudElement, 2);
        }

        actionCommandStatus->state = 10;
        func_80269118();
        btl_set_popup_duration(0xA);
        return ApiStatus_DONE2;
    }
}

void N(Update)(void) {
    HudElement* hudElement;
    s32 temp_s0_3;

    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    switch (actionCommandStatus->state) {
    case 0:
        if (battleStatus->unk_83 == 2) {
            btl_set_popup_duration(0x63);
        }
        actionCommandStatus->state = 1;
        return;
    case 1:
        if (battleStatus->unk_83 == 2) {
            btl_set_popup_duration(0x63);
        }

        actionCommandStatus->hudElementX += 0x14;
        if (actionCommandStatus->hudElementX > 0x32) {
            actionCommandStatus->hudElementX = 0x32;
        }

        hudElement = actionCommandStatus->hudElements[0];
        set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
        if (actionCommandStatus->unk_61) {
            clear_hud_element_flags(hudElement, 2);
        }

        if (actionCommandStatus->autoSucceed) {
            hudElement = actionCommandStatus->hudElements[1];
            set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX + 0x32, actionCommandStatus->hudElementY);
            if (actionCommandStatus->unk_61) {
                clear_hud_element_flags(hudElement, 2);
                return;
            }
        }
    default:
        return;
    case 10:
        if (battleStatus->unk_83 == 2) {
            btl_set_popup_duration(0x63);
        }

        temp_s0_3 = *(s32*)((actionCommandStatus->unk_50 * 4) + battleStatus->unk_434);
        if (((actionCommandStatus->unk_4E - temp_s0_3) - 2) <= 0) {
            set_hud_element_script(actionCommandStatus->hudElements[0], &D_80108B54);
        }
        if (((battleStatus->currentButtonsPressed & 0x8000) != 0) && (actionCommandStatus->autoSucceed == 0)) {
            actionCommandStatus->unk_60 = 1;
            battleStatus->unk_86 = -1;
        }
        if ((actionCommandStatus->unk_4E - temp_s0_3) > 0) {
            actionCommandStatus->unk_4E -= 1;
            return;
        }
        
        actionCommandStatus->unk_54 = ((s32*)((actionCommandStatus->unk_50 * 4) + battleStatus->unk_434))[0];
        battleStatus->actionSuccess = -1;
        actionCommandStatus->state = 11;
    case 11:
        if (battleStatus->unk_83 == 2) {
            btl_set_popup_duration(0x63);
        }
        if (battleStatus->unk_83 >= 2) {
            if (actionCommandStatus->unk_54 == 0) {
                return;
            }
        } else {
            if (battleStatus->actionSuccess >= 0) {
                hudElement = actionCommandStatus->hudElements[0];
                if (actionCommandStatus->unk_61 != 0) {
                    set_hud_element_flags(hudElement, 2);
                }
            } 
        }

        if (battleStatus->actionSuccess < 0) {
            if ((((battleStatus->currentButtonsPressed & 0x8000) != 0) &&
                (actionCommandStatus->unk_60 == 0)) || 
                (actionCommandStatus->autoSucceed != 0)) {
                battleStatus->actionSuccess = 1;
                battleStatus->unk_86 = 1;
                gBattleStatus.flags1 |= 0x2000;
            }
        }

        if (actionCommandStatus->unk_54 == 0) {
            if (battleStatus->actionSuccess == 1) {
                func_80269160();
            }
            if (battleStatus->unk_83 == 2) {
                btl_set_popup_duration(0);
            }
            actionCommandStatus->unk_54 = 5;
            actionCommandStatus->state = 0xC;
            return;
        }
        actionCommandStatus->unk_54 -= 1;
        return;
    case 12:
        if (actionCommandStatus->unk_54 != 0) {
            actionCommandStatus->unk_54 -= 1;
            return;
        }
        func_80268C9C();
        return;
    }
}

void N(DrawHudElements)(void) {
	draw_hud_element_clipped(gActionCommandStatus.hudElements[0]);
	if (!(gGameStatusPtr->demoFlags & 1)) {
		draw_hud_element_clipped(gActionCommandStatus.hudElements[1]);
	}
}

void N(FreeHudElements)(void) {
	free_hud_element(gActionCommandStatus.hudElements[0]);
	free_hud_element(gActionCommandStatus.hudElements[1]);
}