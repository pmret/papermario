#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_power_shock

extern HudScript HudScript_BlueMeter;
extern HudScript HudScript_AButton;
extern HudScript HudScript_MashAButton;
extern HudScript HudScript_RunAwayOK;
extern HudScript HudScript_100pct;
extern s32 D_802943A0[];
extern s16 D_802A9AA2_42D9B2[];
extern s32 D_802A9B00;

void func_80268834(s32, s32, s32, s32);

ApiStatus N(CreateHudElements)(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;
    s32 temp_v1;

    battleStatus->unk_82 = 0x64;
    battleStatus->unk_434 = D_802943A0;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_POWER_SHOCK;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_46 = rand_int(100);
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->unk_68 = 0;
    actionCommandStatus->unk_66 = 0;
    D_802A9B00 = 0;
    actionCommandStatus->hudElementY = 80;

    hudElement = hud_element_create(&HudScript_AButton);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);

    hudElement = hud_element_create(&HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(&HudScript_100pct);
    actionCommandStatus->hudElements[3] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(&HudScript_RunAwayOK);
    actionCommandStatus->hudElements[4] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    temp_v1 = (100 - actionCommandStatus->unk_46) * 60;
    temp_v1 /= 100;
    temp_v1 = 29 - temp_v1;
    hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX - temp_v1, actionCommandStatus->hudElementY + 17);
    return ApiStatus_DONE2;
}

ApiStatus func_802A9210_42D120(Evt* script, s32 isInitialCall) {
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
    actionCommandStatus->unk_64 = evt_get_variable(script, *args++);
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

#ifdef NON_EQUIVALENT
void func_802A9310_42D220(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;
    s32 temp_lo;
    s32 temp_v0_2;
    s16 phi_v0;
    s32 phi_a1;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            hudElement = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }
            hud_element_set_alpha(hudElement, 0xFF);
            hudElement = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }
            hudElement = actionCommandStatus->hudElements[4];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }
            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_6C != 0) {
                actionCommandStatus->unk_6C--;
            } else {
                actionCommandStatus->hudElementX += 20;
                if (actionCommandStatus->hudElementX > 50) {
                    actionCommandStatus->hudElementX = 50;
                }
                hud_element_set_render_pos(
                    actionCommandStatus->hudElements[0],
                    actionCommandStatus->hudElementX,
                    actionCommandStatus->hudElementY);
                hud_element_set_render_pos(
                    actionCommandStatus->hudElements[1],
                    actionCommandStatus->hudElementX,
                    actionCommandStatus->hudElementY + 28);

                temp_v0_2 = (((100 - actionCommandStatus->unk_46) * 60) / 100);
                temp_v0_2 = 29 - temp_v0_2;
                hud_element_set_render_pos(
                    actionCommandStatus->hudElements[4],
                    actionCommandStatus->hudElementX - temp_v0_2,
                    actionCommandStatus->hudElementY + 17);
            }
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                break;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_MashAButton);
            actionCommandStatus->unk_44 = 0;
            actionCommandStatus->unk_5C = 0;
            D_802A9B00 = 1;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0U, 0U, 0U);
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);

            if (actionCommandStatus->unk_68 == 0) {
                if (actionCommandStatus->unk_64 != 0) {
                    temp_lo = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                    temp_lo = actionCommandStatus->unk_44 / temp_lo;
                    phi_v0 = actionCommandStatus->unk_44 - D_802A9AA2_42D9B2[temp_lo / 20 * 2];
                } else {
                    phi_v0 = actionCommandStatus->unk_44 - 10;
                }
                actionCommandStatus->unk_44 = phi_v0;
                if (actionCommandStatus->unk_44 < 0) {
                    actionCommandStatus->unk_44 = 0;
                }
            }

            if ((battleStatus->currentButtonsPressed & 0x8000) != 0) {
                if (actionCommandStatus->unk_64 != 0) {
                    // unk_434 = array of scaling values based on attack difficulty (unk_50).
                    actionCommandStatus->unk_44 +=
                        battleStatus->unk_434[actionCommandStatus->unk_50] * 850 / 100 * actionCommandStatus->unk_64 / 100;
                } else {
                    actionCommandStatus->unk_44 += 100;
                    if (actionCommandStatus->unk_44 >= 500) {
                        actionCommandStatus->unk_44 = 500;
                    }
                }
            }

            if (actionCommandStatus->unk_44 > 10000) {
                hudElement = actionCommandStatus->hudElements[3];
                actionCommandStatus->unk_44 = 10000;
                actionCommandStatus->unk_68 = 1;
                hud_element_set_render_pos(
                    hudElement,
                    actionCommandStatus->hudElementX + 50,
                    actionCommandStatus->hudElementY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            battleStatus->unk_84 = actionCommandStatus->unk_44 / 100;
            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->unk_84 * 12);

            if (actionCommandStatus->unk_54 == 0) {
                phi_a1 = actionCommandStatus->unk_44;
                if (actionCommandStatus->unk_64 == 0) {
                    phi_a1 = 0;
                }

                battleStatus->unk_84 = phi_a1 / 100;
                if (phi_a1 == 0) {
                    battleStatus->actionSuccess = -1;
                } else if (battleStatus->unk_84 >= actionCommandStatus->unk_46) {
                    battleStatus->actionSuccess = 1;
                } else {
                    battleStatus->actionSuccess = 0;
                }

                if ((actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1] / 2) < battleStatus->unk_84) {
                    battleStatus->unk_86 = 1;
                } else {
                    battleStatus->unk_86 = -4;
                }

                if (battleStatus->actionSuccess == 1) {
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
            if (actionCommandStatus->unk_64 == 0) {
                actionCommandStatus->unk_44 -= 100;
                if (actionCommandStatus->unk_44 < 0) {
                    actionCommandStatus->unk_44 = 0;
                }
            }
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                break;
            }
            func_80268C9C();
            break;
    }

    // Invisible "run away"-like meter that determines success threshold.
    // https://www.youtube.com/watch?v=FagUpV0c67s
    switch (actionCommandStatus->state) {
        case 1:
        case 10:
        case 11:
            if (actionCommandStatus->unk_66 == 0) {
                actionCommandStatus->unk_46 += 7;
                if (actionCommandStatus->unk_46 >= 100) {
                    actionCommandStatus->unk_46 = 100;
                    actionCommandStatus->unk_66 = 1;
                }
            } else {
                actionCommandStatus->unk_46 -= 7;
                if (actionCommandStatus->unk_46 <= 0) {
                    actionCommandStatus->unk_46 = 0;
                    actionCommandStatus->unk_66 = 0;
                }
            }
    }
}
#else
INCLUDE_ASM(s32, "battle/action_cmd/power_shock", func_802A9310_42D220, void);
#endif

void N(draw_hud_elements)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 y;
    s32 x;
    s32 hudElement;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = actionCommandStatus->unk_46 * 60;
    x = 60 - temp_v0 / 100;
    temp_a1 = x - 31;
    hud_element_set_render_pos(actionCommandStatus->hudElements[4], actionCommandStatus->hudElementX - temp_a1, actionCommandStatus->hudElementY + 17);
    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);

    hudElement = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &x, &y);
    // Redundant call, but needed to match.
    hud_element_get_render_pos(hudElement, &x, &y);

    if (D_802A9B00 == 0) {
        func_80268798(x, y, actionCommandStatus->barFillLevel / 100, 1);
    } else if (actionCommandStatus->unk_68 == 0) {
        func_80268798(x, y, actionCommandStatus->barFillLevel / 100, 4);
    } else {
        func_80268834(x, y, actionCommandStatus->barFillLevel / 100, 4);
    }
    hudElement = actionCommandStatus->hudElements[3];
    hud_element_draw_clipped(hudElement);
}

void N(free_hud_elements)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
