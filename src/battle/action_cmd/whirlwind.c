#include "common.h"
#include "hud_element.h"
#include "battle/action_cmd/whirlwind_bubble.png.h"

#define NAMESPACE action_command_whirlwind

extern HudScript HudScript_BlueMeter;
extern HudScript HudScript_MashAButton;
extern HudScript HudScript_AButton;

extern s32 D_80294240;

#include "battle/action_cmd/whirlwind_1.png.inc.c"
#include "battle/action_cmd/whirlwind_1.pal.inc.c"

#include "battle/action_cmd/whirlwind_2.png.inc.c"
#include "battle/action_cmd/whirlwind_2.pal.inc.c"

#include "battle/action_cmd/whirlwind_3.png.inc.c"
#include "battle/action_cmd/whirlwind_3.pal.inc.c"

#include "battle/action_cmd/whirlwind_4.png.inc.c"
#include "battle/action_cmd/whirlwind_4.pal.inc.c"

#include "battle/action_cmd/whirlwind_5.png.inc.c"
#include "battle/action_cmd/whirlwind_5.pal.inc.c"

#include "battle/action_cmd/whirlwind_6.png.inc.c"
#include "battle/action_cmd/whirlwind_6.pal.inc.c"

#include "battle/action_cmd/whirlwind_7.png.inc.c"
#include "battle/action_cmd/whirlwind_7.pal.inc.c"

#include "battle/action_cmd/whirlwind_bubble.png.inc.c"
#include "battle/action_cmd/whirlwind_bubble.pal.inc.c"

HudScript HudScript_Whirlwind1 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_whirlwind_1_png, (s32)battle_action_cmd_whirlwind_1_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_Whirlwind2 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_whirlwind_2_png, (s32)battle_action_cmd_whirlwind_2_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_Whirlwind3 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI,
    60, (s32)battle_action_cmd_whirlwind_3_png, (s32)battle_action_cmd_whirlwind_3_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_Whirlwind4 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI,
    60, (s32)battle_action_cmd_whirlwind_4_png, (s32)battle_action_cmd_whirlwind_4_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_Whirlwind5 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI,
    60, (s32)battle_action_cmd_whirlwind_5_png, (s32)battle_action_cmd_whirlwind_5_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_Whirlwind6 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI,
    60, (s32)battle_action_cmd_whirlwind_6_png, (s32)battle_action_cmd_whirlwind_6_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_Whirlwind7 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI,
    60, (s32)battle_action_cmd_whirlwind_7_png, (s32)battle_action_cmd_whirlwind_7_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WhirlwindBubble = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetCustomSize, battle_action_cmd_whirlwind_bubble_png_width, battle_action_cmd_whirlwind_bubble_png_height,
    0x00000004,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_whirlwind_bubble_png, (s32)battle_action_cmd_whirlwind_bubble_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

s32 D_802AA844_4254B4[] = { 0, 25, 50, 75, 100, 100 };

s32 D_802AA85C_4254CC[] = { 50, 50, 50, 50, 75, 75, 75, 100, 100, 100, 100 };

HudScript* D_802AA888_4254F8[] = {
    &HudScript_Whirlwind7, &HudScript_Whirlwind6, &HudScript_Whirlwind5, &HudScript_Whirlwind4, &HudScript_Whirlwind3, &HudScript_Whirlwind2
};

HudScript* D_802AA8A0_425510[] = {
    &HudScript_Whirlwind1, &HudScript_Whirlwind1, &HudScript_Whirlwind2, &HudScript_Whirlwind3, &HudScript_Whirlwind3
};

s32 D_802AA8B4_425524[] = { 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

ApiStatus func_802A9000_423C70(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s16 temp_v0;
    s32 id;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294240;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    temp_v0 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_64 = temp_v0;
    actionCommandStatus->actionCommandID = ACTION_COMMAND_WHIRLWIND;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    if (temp_v0 == 0) {
        battleStatus->unk_84 = 0;
    } else {
        battleStatus->unk_84 = 3;
    }
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    id = hud_element_create(&HudScript_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_Whirlwind7);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 54, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_WhirlwindBubble);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 60, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

ApiStatus func_802A91E0_423E50(Evt* script, s32 isInitialCall) {
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
    battleStatus->unk_86 = 0;
    if (actionCommandStatus->unk_64 == 0) {
        battleStatus->unk_84 = 0;
    } else {
        battleStatus->unk_84 = 3;
    }
    actionCommandStatus->state = 10;
    gBattleStatus.flags1 &= ~BS_FLAGS1_8000;
    return ApiStatus_DONE2;
}

void func_802A92F0_423F60(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 cutoff;
    s32 temp;
    s32 amt;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

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
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX + 54, actionCommandStatus->hudElementY + 23);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX + 60, actionCommandStatus->hudElementY + 23);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                return;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_MashAButton);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->state = 11;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
        case 11:
            btl_set_popup_duration(99);
            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
            temp = actionCommandStatus->barFillLevel / cutoff;
            if (actionCommandStatus->unk_64 == 0) {
                amt = D_802AA844_4254B4[temp / 20];
            } else {
                amt = D_802AA85C_4254CC[temp / 10];
            }
            actionCommandStatus->barFillLevel -= amt;

            if (actionCommandStatus->barFillLevel < 0) {
                actionCommandStatus->barFillLevel = 0;
            }

            if (actionCommandStatus->unk_6A == 0) {
                if (battleStatus->currentButtonsPressed & BUTTON_A) {
                    s32 amt;

                    if (actionCommandStatus->unk_64 == 0) {
                        amt = battleStatus->unk_434[actionCommandStatus->unk_50] * 5;
                    } else {
                        amt = battleStatus->unk_434[actionCommandStatus->unk_50] * 6;
                    }
                    actionCommandStatus->barFillLevel += amt;
                }
            } else {
                actionCommandStatus->barFillLevel += battleStatus->unk_434[actionCommandStatus->unk_50] / 4;
                actionCommandStatus->barFillLevel += rand_int(battleStatus->unk_434[actionCommandStatus->unk_50] / 4);
            }

            if (actionCommandStatus->barFillLevel > cutoff * 100) {
                actionCommandStatus->barFillLevel = cutoff * 100;
            }
            if (actionCommandStatus->unk_64 == 0) {
                battleStatus->unk_84 = actionCommandStatus->barFillLevel / 2000;
            } else {
                battleStatus->unk_84 = D_802AA8B4_425524[actionCommandStatus->barFillLevel / 1000];
            }

            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }
            battleStatus->unk_86 = 127;
            battleStatus->actionSuccess = battleStatus->unk_84;
            btl_set_popup_duration(0);
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

void func_802A9744_4243B4(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 x, y;
    s32 id;

    if (actionCommandStatus->unk_6A == 0) {
        hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    }
    id = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &x, &y);

    func_80268798(x, y, actionCommandStatus->barFillLevel / 100, 1);
    hud_element_draw_clipped(actionCommandStatus->hudElements[3]);
    id = actionCommandStatus->hudElements[2];
    if (actionCommandStatus->unk_64 == 0) {
        if (D_802AA888_4254F8[battleStatus->unk_84] != hud_element_get_script(id)) {
            hud_element_set_script(id, D_802AA888_4254F8[battleStatus->unk_84]);
        }
    } else {
        if (D_802AA8A0_425510[battleStatus->unk_84] != hud_element_get_script(id)) {
            hud_element_set_script(id, D_802AA8A0_425510[battleStatus->unk_84]);
        }
    }
    hud_element_draw_clipped(id);
}

void func_802A9898_424508(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
