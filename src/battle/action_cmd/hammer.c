#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_hammer

// icon indexes for hud elements
extern HudScript HudScript_TimingBar1Chance;
extern HudScript HudScript_TimingWait;
extern HudScript HudScript_TimingCharge1;
extern HudScript HudScript_TimingCharge2;
extern HudScript HudScript_TimingCharge3;
extern HudScript HudScript_TimingCharge4a;
extern HudScript HudScript_TimingCharge4b;
extern HudScript HudScript_TimingCharge4c;
extern HudScript HudScript_StickHoldLeft;
extern HudScript HudScript_StickTapNeutral;
extern HudScript HudScript_RightOn;
extern HudScript HudScript_TimingReady;

extern s32 D_802941E0;

ApiStatus N(CreateHudElements)(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 1;
    battleStatus->unk_434 = &D_802941E0;
    battleStatus->unk_86 = 0;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        battleStatus->unk_84 = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SMASH;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->hudElementY = 96;

    id = hud_element_create(&HudScript_TimingBar1Chance);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 10);

    id = hud_element_create(&HudScript_TimingWait);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HudScript_TimingCharge4a);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HudScript_TimingCharge4b);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HudScript_TimingCharge4c);
    actionCommandStatus->hudElements[4] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HudScript_StickHoldLeft);
    actionCommandStatus->hudElements[5] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HudScript_RightOn);
    actionCommandStatus->hudElements[6] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_alpha(id, 0xFF);

    return ApiStatus_DONE2;
}

ApiStatus func_802A9258_422258(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        battleStatus->unk_84 = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_62 = 1;
    if (actionCommandStatus->unk_4E < 0) {
        actionCommandStatus->unk_4E = 0;
        actionCommandStatus->unk_62 = 0;
    }

    actionCommandStatus->unk_5F = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_84 = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;
    func_80269118();
    return ApiStatus_DONE2;
}

void func_802A936C_42236C(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 id;
    f32 temp_f20;
    s32 phi_s0;
    s32 new_var;
    s32 a;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[1];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[2];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[3];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[4];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[5];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX + 21, actionCommandStatus->hudElementY - 3);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX + 5, actionCommandStatus->hudElementY + 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX - 7, actionCommandStatus->hudElementY + 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[4], actionCommandStatus->hudElementX - 19, actionCommandStatus->hudElementY + 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[5], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY - 23);
            if (actionCommandStatus->autoSucceed != 0) {
                id = actionCommandStatus->hudElements[6];
                hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 50, actionCommandStatus->hudElementY);
                if (actionCommandStatus->unk_61 != 0) {
                    hud_element_clear_flags(id, 2);
                    break;
                }
            }
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E < 15) {
                hud_element_set_alpha(actionCommandStatus->hudElements[0], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[1], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[2], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[3], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[4], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[5], 255);
            }

            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                return;
            }

            actionCommandStatus->unk_54 = 0;
            if (!(battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) && battleStatus->unk_83 < 2) {
                actionCommandStatus->unk_5F = 1;
            }
            actionCommandStatus->state = 11;
        case 11:
            btl_set_popup_duration(99);

            if (battleStatus->unk_83 < 0) {
                return;
            }

            phi_s0 = battleStatus->unk_434[actionCommandStatus->unk_50];
            new_var = phi_s0 + 2;
            temp_f20 = (actionCommandStatus->unk_52 - new_var) / 3;

            if (actionCommandStatus->unk_54 < temp_f20) {
                hud_element_set_script(actionCommandStatus->hudElements[4], &HudScript_TimingCharge3);
                battleStatus->unk_84 = 0;
                if (actionCommandStatus->unk_54 == 0 && actionCommandStatus->unk_62 != 0) {
                    sfx_play_sound(SOUND_233);
                }
            } else if (actionCommandStatus->unk_54 < temp_f20 * 2) {
                hud_element_set_script(actionCommandStatus->hudElements[3], &HudScript_TimingCharge2);
                battleStatus->unk_84 = 1;
                if (actionCommandStatus->unk_54 == temp_f20) {
                    if (actionCommandStatus->unk_62 != 0) {
                        sfx_play_sound(SOUND_233);
                    }
                }
            } else if (actionCommandStatus->unk_54 < temp_f20 * 3.0f) {
                hud_element_set_script(actionCommandStatus->hudElements[2], &HudScript_TimingCharge1);
                battleStatus->unk_84 = 2;
                if (actionCommandStatus->unk_54 == temp_f20 * 2) {
                    if (actionCommandStatus->unk_62 != 0) {
                        sfx_play_sound(SOUND_233);
                    }
                }
            }

            if (actionCommandStatus->unk_54 == (~phi_s0 + actionCommandStatus->unk_52)) {
                battleStatus->unk_84 = 3;
                hud_element_set_script(actionCommandStatus->hudElements[1], &HudScript_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[5], &HudScript_StickTapNeutral);
                if (actionCommandStatus->unk_62 != 0) {
                    sfx_play_sound(SOUND_234);
                }
                if (actionCommandStatus->autoSucceed != 0 && actionCommandStatus->autoSucceed != 2) {
                    actionCommandStatus->autoSucceed = 2;
                    actionCommandStatus->unk_54 = actionCommandStatus->unk_52 - 4;
                }
            }

            a = actionCommandStatus->unk_52 - actionCommandStatus->unk_54;
            phi_s0 = battleStatus->unk_434[actionCommandStatus->unk_50] - a + 3;
            if (phi_s0 < 0) {
                phi_s0 = 0;
            }

            if (!(battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) &&
                phi_s0 == 0 &&
                actionCommandStatus->autoSucceed == 0 &&
                battleStatus->unk_83 < 2)
            {
                battleStatus->actionSuccess = -1;
                battleStatus->unk_86 = -1;
                func_80268C9C();
            } else {
                s32 i;
                s32 bufferPos;

                bufferPos = battleStatus->inputBufferPos;
                bufferPos -= phi_s0;
                if (bufferPos < 0) {
                    bufferPos += ARRAY_COUNT(battleStatus->holdInputBuffer);
                }

                if (battleStatus->actionSuccess == 0) {
                    for (i = 0; i < phi_s0; i++, bufferPos++) {
                        if (bufferPos >= ARRAY_COUNT(battleStatus->holdInputBuffer)) {
                            bufferPos -= ARRAY_COUNT(battleStatus->holdInputBuffer);
                        }

                        if (!(battleStatus->holdInputBuffer[bufferPos] & BUTTON_STICK_LEFT) ||
                            actionCommandStatus->autoSucceed != 0)
                        {
                            battleStatus->actionSuccess = 1;
                            battleStatus->unk_86 = 1;
                            gBattleStatus.flags1 |= BS_FLAGS1_2000;
                        }
                    }
                }

                if (battleStatus->unk_83 < 2 || actionCommandStatus->unk_54 != actionCommandStatus->unk_52) {
                    actionCommandStatus->unk_54++;
                    if (actionCommandStatus->unk_52 < actionCommandStatus->unk_54) {
                        if (battleStatus->actionSuccess == 0) {
                            battleStatus->actionSuccess = -1;
                        }

                        if (battleStatus->actionSuccess == 1) {
                            func_80269160();
                        }

                        btl_set_popup_duration(0);
                        actionCommandStatus->unk_54 = 5;
                        actionCommandStatus->state = 12;
                    }
                }
            }
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
    hud_element_draw_clipped(gActionCommandStatus.hudElements[0]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[1]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[2]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[3]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[4]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[5]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[6]);
}

void N(free_hud_elements)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
    hud_element_free(gActionCommandStatus.hudElements[5]);
    hud_element_free(gActionCommandStatus.hudElements[6]);
}
