#include "common.h"

#define NAMESPACE action_command_bomb

void btl_set_popup_duration(s32);
void func_80268C9C(void);
void func_80269160(void);
void sfx_adjust_env_sound_params(s32, s32, s32, s32);

extern HudElementAnim D_80108AFC;
extern HudElementAnim D_80108B28;
extern HudElementAnim D_80292974;
extern s32 D_80294300;

extern HudElementAnim D_80108B80;

typedef struct UnkVec2s {
    /* 0x00 */ s16 unk_0;
    /* 0x02 */ s16 unk_2;
} UnkVec2s;

UnkVec2s D_802A9812_428280[] = {
    { 0x0, 0x00 },
    { 0x0, 0x19 },
    { 0x0, 0x32 },
    { 0x0, 0x4B },
    { 0x0, 0x4B },
    { 0x0, 0x00 },
    { 0x0, 0x00 },
    { 0x0, 0x00 },
};

ApiStatus func_802A9000_427A70(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->unk_434 = &D_80294300;
    battleStatus->unk_86 = 127;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = 0xB;
    actionCommandStatus->unk_61 = TRUE;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = FALSE;
    battleStatus->actionSuccess = 0;

    actionCommandStatus->hudElementX = -48;
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

    hudElement = create_hud_element(&D_80292974);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

void func_802A928C_427CFC(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;
    s32 mashMeterCutoff;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            hudElement = actionCommandStatus->hudElements[0];
            set_hud_element_alpha(hudElement, 255);
            if (actionCommandStatus->unk_61) {
                clear_hud_element_flags(hudElement, 0x2);
            }

            hudElement = actionCommandStatus->hudElements[1];
            set_hud_element_alpha(hudElement, 255);
            if (actionCommandStatus->unk_61) {
                clear_hud_element_flags(hudElement, 0x2);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);

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

            set_hud_element_anim(actionCommandStatus->hudElements[0], &D_80108B80);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0, 0, 0);
            actionCommandStatus->state = 11;

            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->unk_68) {
                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                actionCommandStatus->barFillLevel -=
                    D_802A9812_428280[actionCommandStatus->barFillLevel / mashMeterCutoff / 20].unk_2;

                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
            }

            if (battleStatus->currentButtonsPressed & 0x8000) {
                switch(actionCommandStatus->unk_64) {
                    case 0: {
                        s32 fillOffset = battleStatus->unk_434[actionCommandStatus->unk_50] * 235 * 4;
                        actionCommandStatus->barFillLevel += fillOffset / 100;
                        break;
                    }
                    case 1:
                        actionCommandStatus->barFillLevel += battleStatus->unk_434[actionCommandStatus->unk_50] * 8;
                        break;
                    case 2: {
                        s32 fillOffset = battleStatus->unk_434[actionCommandStatus->unk_50] * 185 * 4;
                        actionCommandStatus->barFillLevel += fillOffset / 100;
                        break;
                    }
                }
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                hudElement = actionCommandStatus->hudElements[2];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->unk_68 = TRUE;
                set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX + 50,
                    actionCommandStatus->hudElementY + 28);
                clear_hud_element_flags(hudElement, 0x2);
            }

            battleStatus->unk_84 = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->unk_84 * 12);

            if (actionCommandStatus->unk_54 == 0) {
                if (actionCommandStatus->barFillLevel == 0) {
                    battleStatus->actionSuccess = -1;
                } else {
                    battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
                }

                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
                if (mashMeterCutoff >= battleStatus->actionSuccess) {
                    battleStatus->unk_86 = -2;
                } else {
                    battleStatus->unk_86 = 1;
                }

                if (battleStatus->actionSuccess == 100) {
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
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
            } else {
                func_80268C9C();
            }
            break;
    }
}

#include "common/UnkActionCommandFunc1.inc.c"

#include "common/free_hud_elements.inc.c"
