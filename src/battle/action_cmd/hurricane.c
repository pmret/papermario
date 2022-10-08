#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_hurricane

extern s32 D_80294420;
extern HudScript HES_BlueMeter;
extern HudScript HES_AButton;
extern HudScript HES_MashAButton;
extern HudScript HES_BButton;
extern HudScript HES_MashBButton1;
extern HudScript HES_100pct;

s32 D_802A98E0_42FFC0[8] = { 0, 25, 50, 75, 75, 0, 0, 0 };

ApiStatus func_802A9000_42F6E0(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294420;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();

    actionCommandStatus->actionCommandID = 20;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    actionCommandStatus->hudElementY = 80;

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BButton);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[4] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

ApiStatus func_802A91A0_42F880(Evt* script, s32 isInitialCall) {
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
    actionCommandStatus->easyVersion = evt_get_variable(script, *args++);

    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_8000;

    func_80269118();

    return ApiStatus_DONE2;
}

// Almost identical to func_802A92A0_42DCB0 (mega_shock)
void func_802A92A0_42F980(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    s32 buttonsPushed;
    s32 frameCount;
    s32 buttonsAB;
    s32 bufferPos;
    s32 hudElement;
    s32 mashMeterIndex;
    s32 mashMeterCutoff;
    s8 adjustedFillLevel;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            hudElement = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }
            hud_element_set_alpha(hudElement, 255);

            hudElement = actionCommandStatus->hudElements[2];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }
            hud_element_set_alpha(hudElement, 255);

            hudElement = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(hudElement, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_6C != 0) {
                actionCommandStatus->unk_6C--;
                break;
            }

            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }

            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX - 17,
                actionCommandStatus->hudElementY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX + 23,
                actionCommandStatus->hudElementY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX,
                actionCommandStatus->hudElementY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                break;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            hud_element_set_script(actionCommandStatus->hudElements[2], &HES_MashBButton1);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->unk_5C = 0;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_68 == 0) {
                s16 newFillLevel;

                if (actionCommandStatus->easyVersion != 0) {
                    s8 mashMeterIntervals = actionCommandStatus->mashMeterIntervals;
                    s16* mashMeterCutoffs = actionCommandStatus->mashMeterCutoffs;
                    s32 index;

                    mashMeterCutoff = mashMeterCutoffs[mashMeterIntervals];
                    index = actionCommandStatus->barFillLevel / mashMeterCutoff / 20;
                    newFillLevel = actionCommandStatus->barFillLevel - D_802A98E0_42FFC0[index];
                } else {
                    newFillLevel = actionCommandStatus->barFillLevel - 10;
                }

                actionCommandStatus->barFillLevel = newFillLevel;
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
            }

            bufferPos = battleStatus->inputBufferPos;
            bufferPos -= 2;
            if (bufferPos < 0) {
                bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
            }

            buttonsPushed = 0;
            frameCount = 1;

            while(frameCount >= 0) {
                if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                    bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                buttonsPushed |= battleStatus->pushInputBuffer[bufferPos++];
                frameCount--;
            }

            buttonsAB = BUTTON_A | BUTTON_B;
            if ((buttonsPushed & buttonsAB) == buttonsAB) {
                if (actionCommandStatus->easyVersion != 0) {
                    s32 fillLevel;

                    fillLevel = actionCommandStatus->easyVersion * 650;
                    fillLevel = fillLevel / 100 * battleStatus->unk_434[actionCommandStatus->unk_50];

                    // Perplexing reuse of buttonsPushed here, but it fixes register allocation. Likely another
                    // subexpression from above can be put into a variable and reused instead.
                    //
                    // TODO: Find a way to avoid reusing buttonsPushed.
                    buttonsPushed = fillLevel / 100;

                    actionCommandStatus->barFillLevel += buttonsPushed;
                } else {
                    actionCommandStatus->barFillLevel += 100;

                    if (actionCommandStatus->barFillLevel >= 500) {
                        actionCommandStatus->barFillLevel = 500;
                    }
                }

                bufferPos = battleStatus->inputBufferPos;
                bufferPos -= 2;
                if (bufferPos < 0) {
                    bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                frameCount = 1;
                while (frameCount >= 0) {
                    if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    battleStatus->pushInputBuffer[bufferPos++] = 0;
                    frameCount--;
                }
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                hudElement = actionCommandStatus->hudElements[4];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->unk_68 = 1;
                hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX + 50,
                    actionCommandStatus->hudElementY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            adjustedFillLevel = actionCommandStatus->barFillLevel / 100;

            battleStatus->unk_84 = adjustedFillLevel;

            if (actionCommandStatus->unk_54 == 0) {
                s16 threshold;

                // Again, reusing buttonsPushed specifically for reg-alloc. See above.
                //
                // TODO: Find a way to avoid reusing buttonsPushed.
                buttonsPushed = actionCommandStatus->barFillLevel;
                if (actionCommandStatus->easyVersion == 0) {
                    buttonsPushed = 0;
                }

                if (buttonsPushed == 0) {
                    battleStatus->actionSuccess = -1;
                } else {
                    battleStatus->actionSuccess = buttonsPushed / 100;
                }

                mashMeterIndex = actionCommandStatus->mashMeterIntervals - 1;
                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[mashMeterIndex];
                threshold = mashMeterCutoff / 2;

                if (battleStatus->unk_84 <= threshold) {
                    battleStatus->unk_86 = -4;
                } else {
                    battleStatus->unk_86 = 1;
                }

                if (battleStatus->actionSuccess == 100) {
                    func_80269160();
                }

                btl_set_popup_duration(0);
                actionCommandStatus->unk_54 = 5;
                actionCommandStatus->state = 12;
            } else {
                actionCommandStatus->unk_54 -= 1;
            }
            break;
        case 12:
            if (actionCommandStatus->easyVersion == 0) {
                actionCommandStatus->barFillLevel -= 100;
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
            }

            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54 -= 1;
            } else {
                func_80268C9C();
            }
            break;
    }
}

void N(draw_hud_elements)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudY;
    s32 hudX;
    s32 id;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);

    id = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &hudX, &hudY);

    if (actionCommandStatus->unk_68 == 0) {
        func_80268770(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    } else {
        func_8026880C(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[4]);
}

void N(free_hud_elements)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
