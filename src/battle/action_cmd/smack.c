#include "battle/battle.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_smack

typedef struct UnkVec2s {
    /* 0x00 */ s16 unk_0;
    /* 0x02 */ s16 unk_2;
} UnkVec2s;

UnkVec2s D_802A99D2_42ED72[] = {
    { 0x00, 0x00 },
    { 0x00, 0x19 },
    { 0x00, 0x32 },
    { 0x00, 0x4B },
    { 0x00, 0x4B },
};

s32 D_802A99E4_42ED84[] = {
    0x28, 0x46, 0x63, 0xC8,
};

s32 D_802A99F4_42ED94[] = {
    0x23, 0x3C, 0x50, 0x63, 0xC8,
};

s32 D_802A9A08_42EDA8[] = {
    0x23, 0x23, 0x3C, 0x50, 0x63, 0xC8,
};

s32 D_802A9A20_42EDC0[] = {
    0x23, 0x3C, 0x50, 0x63, 0xC8, 0x00,
};

extern s32 actionCmdTableSmack[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableSmack;
    battleStatus->unk_86 = 127;
    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SMACK;
    actionCommandStatus->showHud = TRUE;
    actionCommandStatus->hudPrepareTime = 30;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = 0;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->hudPosY = 80;

    hudElement = hud_element_create(&HES_StickNeutral);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;

    s32 mashMeterCutoff;
    s32 hudElement;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            hudElement = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(hudElement, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }
            hudElement = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(hudElement, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }
            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            if (actionCommandStatus->hudPrepareTime != 0) {
                actionCommandStatus->hudPrepareTime--;
                break;
            }

            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }

            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX,
                actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX,
                actionCommandStatus->hudPosY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                break;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_StickMashLeft);
            actionCommandStatus->barFillLevel = 0;
            battleStatus->unk_85 = 0;
            actionCommandStatus->unk_5C = 0;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            sfx_play_sound_with_params(SOUND_80000041, 0, 0, 0);
            actionCommandStatus->state = 11;

            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->isBarFilled) {
                s32 index;
                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                actionCommandStatus->barFillLevel -=
                    D_802A99D2_42ED72[actionCommandStatus->barFillLevel / mashMeterCutoff / 20].unk_2;

                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }

                if (!actionCommandStatus->isBarFilled) {
                    if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                        actionCommandStatus->unk_5C = TRUE;
                    }

                    if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && actionCommandStatus->unk_5C) {
                        if (actionCommandStatus->targetWeakness == 0) {
                            actionCommandStatus->barFillLevel += battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 13;
                        } else {
                            actionCommandStatus->barFillLevel += battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 850 / 100;
                        }

                        actionCommandStatus->unk_5C = 0;
                    }

                    if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                        actionCommandStatus->barFillLevel -= battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 11;
                    }
                }
            }

            if (actionCommandStatus->barFillLevel < 0) {
                actionCommandStatus->barFillLevel = 0;
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                hudElement = actionCommandStatus->hudElements[2];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->isBarFilled = TRUE;
                hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX + 50,
                    actionCommandStatus->hudPosY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionResult = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_80000041, 0, 0, battleStatus->actionResult * 12);

            switch (partnerActor->actorBlueprint->level) {
                case 0:
                    if (battleStatus->actionResult >= D_802A99E4_42ED84[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }

                    if (battleStatus->unk_85 > 0) {
                        s32 index = battleStatus->unk_85 - 1;
                        if (battleStatus->actionResult < D_802A99E4_42ED84[index]) {
                            battleStatus->unk_85--;
                        }
                    }
                    break;
                case 1:
                    if (battleStatus->actionResult >= D_802A99F4_42ED94[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }

                    if (battleStatus->unk_85 > 0) {
                        s32 index = battleStatus->unk_85 - 1;
                        if (battleStatus->actionResult < D_802A99F4_42ED94[index]) {
                            battleStatus->unk_85--;
                        }
                    }
                    break;
                case 2:
                    if (actionCommandStatus->targetWeakness == 0) {
                        if (battleStatus->actionResult >= D_802A9A08_42EDA8[battleStatus->unk_85]) {
                            battleStatus->unk_85++;
                        }

                        if (battleStatus->unk_85 > 0) {
                            s32 index = battleStatus->unk_85 - 1;
                            if (battleStatus->actionResult < D_802A9A08_42EDA8[index]) {
                                battleStatus->unk_85--;
                            }
                        }
                    } else {
                        if (battleStatus->actionResult >= D_802A9A20_42EDC0[battleStatus->unk_85]) {
                            battleStatus->unk_85++;
                        }

                        if (battleStatus->unk_85 > 0) {
                            s32 index = battleStatus->unk_85 - 1;
                            if (battleStatus->actionResult < D_802A9A20_42EDC0[index]) {
                                battleStatus->unk_85--;
                            }
                        }
                    }
                    break;
            }

            if (actionCommandStatus->frameCounter == 0) {
                s32 mashMeterCutoff;

                if (actionCommandStatus->barFillLevel == 0) {
                    battleStatus->actionSuccess = -1;
                } else {
                    mashMeterCutoff = actionCommandStatus->barFillLevel;
                    battleStatus->actionSuccess = mashMeterCutoff / 100;
                }

                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
                if (mashMeterCutoff < battleStatus->actionSuccess) {
                    battleStatus->unk_86 = 1;
                } else {
                    battleStatus->unk_86 = -2;
                }

                if (battleStatus->actionSuccess == 100) {
                    func_80269160();
                }

                btl_set_popup_duration(0);
                sfx_stop_sound(SOUND_80000041);
                actionCommandStatus->frameCounter = 5;
                actionCommandStatus->state = 12;
                break;
            }

            actionCommandStatus->frameCounter--;
            break;
        case 12:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                break;
            }
            action_command_free();
            break;
    }
}

#include "common/draw_hud_elements.inc.c"

#include "common/free_hud_elements.inc.c"
