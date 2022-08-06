#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_body_slam

extern HudScript HES_BlueMeter;
extern HudScript HES_AButton;
extern HudScript HES_AButtonDown;
extern HudScript HES_TimingWait;
extern HudScript HES_TimingReady;
extern HudScript HES_FillGaugeResult;
extern s32 D_80294320;

ApiStatus N(CreateHudElements)(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 100;
    battleStatus->unk_434 = &D_80294320;
    battleStatus->unk_86 = 127;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_BODY_SLAM;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HES_FillGaugeResult);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HES_TimingWait);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 41, actionCommandStatus->hudElementY + 22);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

void func_802A92D4_4285B4(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 phi_v0;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[2];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[3];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX + 41, actionCommandStatus->hudElementY + 22);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX + 42, actionCommandStatus->hudElementY + 24);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                return;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButtonDown);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->unk_46 = 0;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
            sfx_play_sound_with_params(0x80000041, 0, 0, 0);
            actionCommandStatus->state = 11;
        case 11:
            btl_set_popup_duration(99);

            if (battleStatus->currentButtonsDown & BUTTON_A) {
                actionCommandStatus->barFillLevel += 154;
                actionCommandStatus->unk_46 += 154;
            } else {
                actionCommandStatus->unk_54 = 0;
            }

            if (actionCommandStatus->barFillLevel >= 10000) {
                actionCommandStatus->barFillLevel = 10000;
                hud_element_set_script(actionCommandStatus->hudElements[2], &HES_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButton);
                if (actionCommandStatus->unk_68 == 0) {
                    sfx_play_sound(SOUND_234);
                    actionCommandStatus->unk_68 = 1;
                }
            }

            battleStatus->unk_84 = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(0x80000041, 0, 0, battleStatus->unk_84 * 12);
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }

            do {
                if (actionCommandStatus->unk_46 < 10000) {
                    battleStatus->actionSuccess = -1;
                } else if (actionCommandStatus->unk_46 - (battleStatus->unk_434[actionCommandStatus->unk_50] * 154) >= 10309) {
                    battleStatus->actionSuccess = -1;
                } else {
                    battleStatus->actionSuccess = 1;
                }
            } while (0); // required to match

            battleStatus->unk_86 = 0;
            if (battleStatus->actionSuccess == 1) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(0x80000041);
            actionCommandStatus->unk_54 = 5;
            actionCommandStatus->state = 12;
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
    s32 x, y;
    s32 hudElement;

    hud_element_draw_clipped(gActionCommandStatus.hudElements[0]);
    hudElement = gActionCommandStatus.hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &x, &y);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[3]);
    func_80268770(x, y, gActionCommandStatus.barFillLevel / 100);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[2]);
}

void N(free_hud_elements)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
