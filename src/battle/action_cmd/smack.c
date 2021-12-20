#include "common.h"
#include "battle/battle.h"
#include "hud_element.h"

#define NAMESPACE action_command_smack

void sfx_adjust_env_sound_params(s32 soundID, u8 volume, u8 pan, s16 pitchShift);

extern HudElementAnim D_80108AFC;
extern HudElementAnim D_80108E1C;
extern HudElementAnim D_80292974;
extern HudElementAnim D_80108F30;
extern s32 D_802943E0;

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

ApiStatus func_802A9000_42E3A0(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->unk_434 = &D_802943E0;
    battleStatus->unk_86 = 127;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SMACK;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_84 = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(&D_80108E1C);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80108AFC);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80292974);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

void func_802A9298_42E638(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;

    s32 mashMeterCutoff;
    s32 hudElement;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            hudElement = actionCommandStatus->hudElements[0];
            set_hud_element_alpha(hudElement, 255);
            if (actionCommandStatus->unk_61 != 0) {
                clear_hud_element_flags(hudElement, 2);
            }
            hudElement = actionCommandStatus->hudElements[1];
            set_hud_element_alpha(hudElement, 255);
            if (actionCommandStatus->unk_61 != 0) {
                clear_hud_element_flags(hudElement, 2);
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

            set_hud_element_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX,
                actionCommandStatus->hudElementY);
            set_hud_element_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX,
                actionCommandStatus->hudElementY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                break;
            }
            set_hud_element_anim(actionCommandStatus->hudElements[0], &D_80108F30);
            actionCommandStatus->barFillLevel = 0;
            battleStatus->unk_85 = 0;
            actionCommandStatus->unk_5C = 0;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0U, 0U, 0U);
            actionCommandStatus->state = 11;

            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_68 == 0) {
                s32 index;
                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                actionCommandStatus->barFillLevel -=
                    D_802A99D2_42ED72[actionCommandStatus->barFillLevel / mashMeterCutoff / 20].unk_2;

                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }

                if (actionCommandStatus->unk_68 == 0) {

                    if (battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) {
                        actionCommandStatus->unk_5C = TRUE;
                    }

                    if (!(battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) && actionCommandStatus->unk_5C) {
                        s16 phi_v1;
                        if (actionCommandStatus->unk_64 == 0) {
                            actionCommandStatus->barFillLevel += battleStatus->unk_434[actionCommandStatus->unk_50] * 13;
                        } else {
                            actionCommandStatus->barFillLevel += battleStatus->unk_434[actionCommandStatus->unk_50] * 850 / 100;
                        }

                        actionCommandStatus->unk_5C = 0;
                    }

                    if (battleStatus->currentButtonsPressed & BUTTON_STICK_RIGHT) {
                        actionCommandStatus->barFillLevel -= battleStatus->unk_434[actionCommandStatus->unk_50] * 11;
                    }
                }
            }

            if (actionCommandStatus->barFillLevel < 0) {
                actionCommandStatus->barFillLevel = 0;
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                hudElement = actionCommandStatus->hudElements[2];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->unk_68 = 1;
                set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX + 50,
                    actionCommandStatus->hudElementY + 28);
                clear_hud_element_flags(hudElement, 2);
            }

            battleStatus->unk_84 = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->unk_84 * 12);

            switch (partnerActor->staticActorData->level) {
                case 0:
                    if (battleStatus->unk_84 >= D_802A99E4_42ED84[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }

                    if (battleStatus->unk_85 > 0) {
                        s32 index = battleStatus->unk_85 - 1;
                        if (battleStatus->unk_84 < D_802A99E4_42ED84[index]) {
                            battleStatus->unk_85--;
                        }
                    }
                    break;
                case 1:
                    if (battleStatus->unk_84 >= D_802A99F4_42ED94[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }

                    if (battleStatus->unk_85 > 0) {
                        s32 index = battleStatus->unk_85 - 1;
                        if (battleStatus->unk_84 < D_802A99F4_42ED94[index]) {
                            battleStatus->unk_85--;
                        }
                    }
                    break;
                case 2:
                    if (actionCommandStatus->unk_64 == 0) {
                        if (battleStatus->unk_84 >= D_802A9A08_42EDA8[battleStatus->unk_85]) {
                            battleStatus->unk_85++;
                        }

                        if (battleStatus->unk_85 > 0) {
                            s32 index = battleStatus->unk_85 - 1;
                            if (battleStatus->unk_84 < D_802A9A08_42EDA8[index]) {
                                battleStatus->unk_85--;
                            }
                        }
                    } else {
                        if (battleStatus->unk_84 >= D_802A9A20_42EDC0[battleStatus->unk_85]) {
                            battleStatus->unk_85++;
                        }

                        if (battleStatus->unk_85 > 0) {
                            s32 index = battleStatus->unk_85 - 1;
                            if (battleStatus->unk_84 < D_802A9A20_42EDC0[index]) {
                                battleStatus->unk_85--;
                            }
                        }
                    }
                    break;
            }

            if (actionCommandStatus->unk_54 == 0) {
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
                sfx_stop_sound(0x80000041);
                actionCommandStatus->unk_54 = 5;
                actionCommandStatus->state = 12;
                break;
            }

            actionCommandStatus->unk_54--;
            break;
        case 12:
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                break;
            }
            func_80268C9C();
            break;
    }
}

#include "common/UnkActionCommandFunc1.inc.c"

#include "common/free_hud_elements.inc.c"
