#include "common.h"

#define NAMESPACE action_command_flee

extern s32 D_80108AFC;
extern s32 D_80108B28;
extern s32 D_80109244;
extern s32 D_802928F8;
extern s32 D_80292974;
extern s32 D_80294200;
extern s32 D_802A9920;
extern s32 D_80108B80;
extern s32 D_802A9920;
extern s32 D_802A9920;

ApiStatus func_802A9000_422AD0(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 xOffset;
    HudElement* hudElement;

    battleStatus->unk_82 = 0;
    battleStatus->unk_434 = &D_80294200;
    battleStatus->unk_86 = 127;
    func_80268858();
    actionCommandStatus->unk_5A = get_variable(script, *args++);
    actionCommandStatus->actionCommandID = ACTION_COMMAND_FLEE;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_44 = actionCommandStatus->unk_5A * 100;
    actionCommandStatus->unk_46 = rand_int(50);
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_5C = 1;
    actionCommandStatus->unk_5A = rand_int(1);
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudElementX = -48;
    D_802A9920 = 0;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(&D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80108AFC);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_802928F8);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80109244);
    actionCommandStatus->hudElements[3] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    xOffset = 29 - ((100 - actionCommandStatus->unk_46) * 60) / 100;
    set_hud_element_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX - xOffset, actionCommandStatus->hudElementY + 17);
    set_hud_element_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX - xOffset, actionCommandStatus->hudElementY - 1);

    hudElement = create_hud_element(&D_80292974);
    actionCommandStatus->hudElements[4] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    return ApiStatus_DONE2;
}

ApiStatus func_802A92A0_422D70(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    func_80268858();
    actionCommandStatus->unk_4E = get_variable(script, *args++);
    actionCommandStatus->unk_52 = get_variable(script, *args++);
    actionCommandStatus->unk_50 = get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_60 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 127;
    battleStatus->unk_82 = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
    battleStatus->flags1 &= ~0x8000;
    actionCommandStatus->state = 10;
    return ApiStatus_DONE2;
}

void func_802A9378_422E48(void) {
    s32 temp;
    HudElement* hudElement;
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    switch (actionCommandStatus->state) {
        case 0:
            hudElement = actionCommandStatus->hudElements[0];
            set_hud_element_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                clear_hud_element_flags(hudElement, 2);
            }

            hudElement = actionCommandStatus->hudElements[1];
            set_hud_element_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                clear_hud_element_flags(hudElement, 2);
            }

            hudElement = actionCommandStatus->hudElements[2];
            set_hud_element_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                clear_hud_element_flags(hudElement, 2);
            }

            hudElement = actionCommandStatus->hudElements[3];
            set_hud_element_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                clear_hud_element_flags(hudElement, 2);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }
            set_hud_element_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            set_hud_element_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
            break;
        case 10:
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                break;
            }

            set_hud_element_anim(actionCommandStatus->hudElements[0], &D_80108B80);
            D_802A9920 = 1;
            actionCommandStatus->state = 11;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
        case 11:
            if ((battleStatus->unk_83 != 0) && ((battleStatus->currentButtonsPressed & 0x8000) != 0)) {
                actionCommandStatus->unk_44 += (battleStatus->unk_434[actionCommandStatus->unk_50] * 180 / 100);
            }
            if (actionCommandStatus->unk_44 >= 10000) {
                hudElement = actionCommandStatus->hudElements[4];
                actionCommandStatus->unk_44 = 10000;
                actionCommandStatus->unk_68 = 1;
                set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX + 50, actionCommandStatus->hudElementY + 28);
                clear_hud_element_flags(hudElement, 2);
            }

            battleStatus->actionSuccess = actionCommandStatus->unk_44 / 100;
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

void func_802A96F4_4231C4(void) {
    s32 y;
    s32 x;
    s32 temp_a1;
    HudElement* hudElement;
    s32 temp_v1;

    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    temp_v1 = (100 - actionCommandStatus->unk_46) * 60;
    x = 60 - temp_v1 / 100;
    temp_a1 = x - 31;

    set_hud_element_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX - temp_a1, actionCommandStatus->hudElementY + 17);
    set_hud_element_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX + 31 - x, actionCommandStatus->hudElementY - 1);

    if (battleStatus->unk_83 != 0) {
        draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    }

    hudElement = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &x, &y);

    if (D_802A9920 == 0) {
        func_80268798(x, y, actionCommandStatus->unk_44 / 100, 1);
    } else {
        if (actionCommandStatus->unk_68 == 0) {
            func_80268798(x, y, actionCommandStatus->unk_44 / 100, 4);
        } else {
            func_8026880C(x, y, actionCommandStatus->unk_44 / 100, 4);
        }
    }

    draw_hud_element_clipped(actionCommandStatus->hudElements[2]);
    draw_hud_element_clipped(actionCommandStatus->hudElements[3]);
    draw_hud_element_clipped(actionCommandStatus->hudElements[4]);
}

void func_802A9894_423364(void) {
    free_hud_element(gActionCommandStatus.hudElements[0]);
    free_hud_element(gActionCommandStatus.hudElements[1]);
    free_hud_element(gActionCommandStatus.hudElements[2]);
    free_hud_element(gActionCommandStatus.hudElements[3]);
    free_hud_element(gActionCommandStatus.hudElements[4]);
}
