#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_power_shock

extern HudScript HES_BlueMeter;
extern HudScript HES_AButton;
extern HudScript HES_MashAButton;
extern HudScript HES_RunAwayOK;
extern HudScript HES_100pct;
extern s32 D_802943A0[];
s32 D_802A9AA0_42D9B0[] = { 0, 25, 50, 75, 75, 0, 0, 0};
extern s32 D_802A9B00;

void func_80268834(s32, s32, s32, s32);

ApiStatus N(CreateHudElements)(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 temp_v1;

    battleStatus->unk_82 = 100;
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

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HES_RunAwayOK);
    actionCommandStatus->hudElements[4] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

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
    s32 id;
    s32 temp_v0_2;
    s32 phi_a1;
    s32 cutoff;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            }
            hud_element_set_alpha(id, 255);
            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            }
            id = actionCommandStatus->hudElements[4];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
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

                cutoff = 100 - actionCommandStatus->unk_46;
                cutoff = (cutoff * 60) / 100;
                temp_v0_2 = 29 - cutoff;
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
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            actionCommandStatus->unk_44 = 0;
            actionCommandStatus->unk_5C = 0;
            D_802A9B00 = 1;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0, 0, 0);
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);

            if (actionCommandStatus->unk_68 == 0) {
                if (actionCommandStatus->unk_64 != 0) {
                    cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                    actionCommandStatus->barFillLevel -= D_802A9AA0_42D9B0[actionCommandStatus->barFillLevel / cutoff / 20];
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

            if (battleStatus->currentButtonsPressed & BUTTON_A) {
                phi_a1 = actionCommandStatus->unk_64;
                    // unk_434 = array of scaling values based on attack difficulty (unk_50).
                if (phi_a1 != 0) {
                    s32 a;
                    a = battleStatus->unk_434[actionCommandStatus->unk_50];
                    actionCommandStatus->barFillLevel += a * 850 / 100 * phi_a1 / 100;
                } else {
                    actionCommandStatus->barFillLevel += 100;
                    if (actionCommandStatus->barFillLevel >= 500) {
                        actionCommandStatus->barFillLevel = 500;
                    }
                }
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                id = actionCommandStatus->hudElements[3];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->unk_68 = 1;
                hud_element_set_render_pos(
                    id,
                    actionCommandStatus->hudElementX + 50,
                    actionCommandStatus->hudElementY + 28);
                hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            }

            battleStatus->unk_84 = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->unk_84 * 12);

            if (actionCommandStatus->unk_54 == 0) {
                phi_a1 = actionCommandStatus->barFillLevel;
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

                cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
                if (cutoff / 2 < battleStatus->unk_84) {
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
                actionCommandStatus->barFillLevel -= 100;
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
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
    s32 id;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = actionCommandStatus->unk_46 * 60;
    x = 60 - temp_v0 / 100;
    temp_a1 = x - 31;
    hud_element_set_render_pos(actionCommandStatus->hudElements[4], actionCommandStatus->hudElementX - temp_a1, actionCommandStatus->hudElementY + 17);
    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);

    id = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &x, &y);
    // Redundant call, but needed to match.
    hud_element_get_render_pos(id, &x, &y);

    if (D_802A9B00 == 0) {
        func_80268798(x, y, actionCommandStatus->barFillLevel / 100, 1);
    } else if (actionCommandStatus->unk_68 == 0) {
        func_80268798(x, y, actionCommandStatus->barFillLevel / 100, 4);
    } else {
        func_80268834(x, y, actionCommandStatus->barFillLevel / 100, 4);
    }
    id = actionCommandStatus->hudElements[3];
    hud_element_draw_clipped(id);
}

void N(free_hud_elements)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
