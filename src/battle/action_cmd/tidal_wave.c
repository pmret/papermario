#include "common.h"

#define NAMESPACE action_command_tidal_wave

extern s32 D_80108AFC;
extern s32 D_80108B28;
extern s32 D_802944A0;

extern s32* D_802A97C0_42CEB0[];
extern s32* D_802A97CC_42CEBC[];

ApiStatus N(CreateHudElements)(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;
    s32 i;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_802944A0;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    } else {
        func_80268858();
        actionCommandStatus->actionCommandID = ACTION_COMMAND_TIDAL_WAVE;
        actionCommandStatus->state = 0;
        actionCommandStatus->unk_60 = 0;
        actionCommandStatus->barFillLevel = 0;
        actionCommandStatus->unk_48 = 0;
        battleStatus->unk_84 = 0;
        actionCommandStatus->hudElementX = -48;
        actionCommandStatus->hudElementY = 80;

        hudElement = create_hud_element(&D_80108AFC);
        actionCommandStatus->hudElements[0] = hudElement;
        set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
        set_hud_element_render_depth(hudElement, 0);
        set_hud_element_flags(hudElement, 0x82);

        for (i = 1; i < ARRAY_COUNT(actionCommandStatus->hudElements); i++) {
            hudElement = create_hud_element(&D_80108B28);
            actionCommandStatus->hudElements[i] = hudElement;
            set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            set_hud_element_render_depth(hudElement, 0);
            set_hud_element_flags(hudElement, 0x82);
        }

        return ApiStatus_DONE2;
    }
}

ApiStatus func_802A9138_42C828(Evt* script, s32 isInitialCall) {
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
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_84 = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;
    func_80269118();
    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElement* hudElement;
    s8 oldButton;
    s8 newButton;
    s32 numLookbackFrames;
    s32 bufferPos;
    s32 buttonsPressed;
    s32 success;
    s32 i;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            hudElement = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->unk_61 != 0) {
                clear_hud_element_flags(hudElement, 2);
            }
            set_hud_element_alpha(hudElement, 0xFF);
            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }
            set_hud_element_render_pos(
                actionCommandStatus->hudElements[0],
                actionCommandStatus->hudElementX + 21,
                actionCommandStatus->hudElementY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                break;
            }
            actionCommandStatus->unk_5D = 1;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            actionCommandStatus->unk_5C = rand_int(2);
            actionCommandStatus->state = 11;
            actionCommandStatus->unk_72 = 0U;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);

            // Pick a new button that doesn't match the old one.
            oldButton = actionCommandStatus->unk_5C;
            do {
                newButton = rand_int(2);
                actionCommandStatus->unk_5C = newButton;
            } while (oldButton == newButton);

            hudElement = actionCommandStatus->hudElements[actionCommandStatus->unk_5D];
            set_hud_element_anim(
                hudElement, D_802A97C0_42CEB0[newButton]);
            set_hud_element_render_pos(
                hudElement,
                actionCommandStatus->hudElementX + ((actionCommandStatus->unk_5D - 1) * 20) + 16,
                actionCommandStatus->hudElementY);
            clear_hud_element_flags(hudElement, 2);
            sfx_play_sound(0x233);
            actionCommandStatus->unk_70 = 1;
            actionCommandStatus->state = 12;
            // fallthrough
        case 12:
            btl_set_popup_duration(99);
            if (--actionCommandStatus->unk_54 == 0) {
                actionCommandStatus->state = 13;
                break;
            }

            // Stops checking for input if on the 15th button.
            if (actionCommandStatus->unk_5D == 15) {
                break;
            }

            // Number of frames until input possible (if negative, used to look backward;
            // allows correct presses to be buffered after an incorrect press).
            actionCommandStatus->unk_70--;
            // Wrong-input lockout frame counter
            actionCommandStatus->unk_72--;

            if (actionCommandStatus->unk_70 <= 0) {
                // Determine number of frames to look back in input buffer (up to 20).
                numLookbackFrames = abs(actionCommandStatus->unk_70);
                if (numLookbackFrames > 20) {
                    numLookbackFrames = 20;
                }

                // Determine starting point in input buffer.
                bufferPos = battleStatus->inputBufferPos - numLookbackFrames;
                if (bufferPos < 0) {
                    bufferPos += 0x40;
                }

                // If determined that 0 frames should be searched, search a minimum of 1.
                if (numLookbackFrames == 0) {
                    numLookbackFrames = 1;
                }

                // Check buffer for past N frames' worth of button presses.
                for (i = 0; i < numLookbackFrames; i++) {
                    if (bufferPos >= 0x40) {
                        bufferPos -= 0x40;
                    }

                    // If not locked out from previous wrong press...
                    if (actionCommandStatus->unk_72 > 0) {
                        break;
                    };

                    success = FALSE;
                    actionCommandStatus->unk_60 = FALSE;

                    // Check for presses of the current button.
                    switch (actionCommandStatus->unk_5C) {
                        case 0:
                            if (actionCommandStatus->autoSucceed) {
                                success = TRUE;
                            } else {
                                buttonsPressed = battleStatus->pushInputBuffer[bufferPos];
                                if (buttonsPressed != 0) {
                                    if (buttonsPressed & ~0x8000) {
                                        actionCommandStatus->unk_60 = TRUE;
                                    } else {
                                        success = TRUE;
                                    }
                                }
                            }
                            break;
                        case 1:
                            if (actionCommandStatus->autoSucceed) {
                                success = TRUE;
                            } else {
                                buttonsPressed = battleStatus->pushInputBuffer[bufferPos];
                                if (buttonsPressed != 0) {
                                    if (buttonsPressed & ~0x4000) {
                                        actionCommandStatus->unk_60 = TRUE;
                                    } else {
                                        success = TRUE;
                                    }
                                }
                            }
                            break;
                        case 2:
                            if (actionCommandStatus->autoSucceed) {
                                success = TRUE;
                            } else {
                                buttonsPressed = battleStatus->pushInputBuffer[bufferPos];
                                if (buttonsPressed != 0) {
                                    if (buttonsPressed & ~0x4) {
                                        actionCommandStatus->unk_60 = TRUE;
                                    } else {
                                        success = TRUE;
                                    }
                                }
                            }
                            break;
                    }

                    if (actionCommandStatus->unk_60) {
                        // Wrong; prevent successful inputs for 10 frames.
                        actionCommandStatus->unk_72 = 10;
                        sfx_play_sound(0x21D);
                        actionCommandStatus->unk_70 = 0;
                    }

                    if (success) {
                        // Correct; shrink button, set up next button press, etc.
                        hudElement = actionCommandStatus->hudElements[actionCommandStatus->unk_5D];
                        set_hud_element_anim(hudElement, D_802A97CC_42CEBC[actionCommandStatus->unk_5C]);
                        set_hud_element_scale(hudElement, 0.5f);
                        set_hud_element_render_pos(
                            hudElement,
                            actionCommandStatus->hudElementX + ((actionCommandStatus->unk_5D - 1) * 20),
                            actionCommandStatus->hudElementY + 7);
                        actionCommandStatus->unk_5D++;
                        actionCommandStatus->barFillLevel +=
                            battleStatus->unk_434[actionCommandStatus->unk_50] * 0x12;
                        if (actionCommandStatus->barFillLevel > 10000) {
                            actionCommandStatus->barFillLevel = 10000;
                        }
                        actionCommandStatus->state = 11;
                        battleStatus->unk_84++;
                        sfx_play_sound(0x21C);
                        return;
                    }

                    bufferPos++;
                }
            }
            break;
        case 13:
            if (battleStatus->unk_84 == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = battleStatus->unk_84;
            }
            battleStatus->unk_86 = 1;
            if (battleStatus->actionSuccess >= 10) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            actionCommandStatus->unk_54 = 5;
            actionCommandStatus->state = 14;
            break;
        case 14:
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
            } else {
                func_80268C9C();
            }
            break;
    }
}

void N(draw_hud_elements)(void) {
    s32 i;

    for (i = 1; i < 15; i++) {
        draw_hud_element_clipped(gActionCommandStatus.hudElements[i]);
    }
}

void N(free_hud_elements)(void) {
    s32 i;

    free_hud_element(gActionCommandStatus.hudElements[0]);

    for (i = 1; i < 15; i++) {
        free_hud_element(gActionCommandStatus.hudElements[i]);
    }
}
