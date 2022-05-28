#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_water_block

#include "battle/action_cmd/water_block_1.png.inc.c"
#include "battle/action_cmd/water_block_1.pal.inc.c"

#include "battle/action_cmd/water_block_2.png.inc.c"
#include "battle/action_cmd/water_block_2.pal.inc.c"

#include "battle/action_cmd/water_block_3.png.inc.c"
#include "battle/action_cmd/water_block_3.pal.inc.c"

#include "battle/action_cmd/water_block_0.png.inc.c"
#include "battle/action_cmd/water_block_0.pal.inc.c"

#include "battle/action_cmd/water_block_block.png.inc.c"
#include "battle/action_cmd/water_block_block.pal.inc.c"

#include "battle/action_cmd/water_block_circle.png.inc.c"
#include "battle/action_cmd/water_block_circle.pal.inc.c"

#include "battle/action_cmd/water_block_cloud.png.inc.c"
#include "battle/action_cmd/water_block_cloud.pal.inc.c"

#include "battle/action_cmd/water_block_4.png.inc.c"
#include "battle/action_cmd/water_block_4.pal.inc.c"

HudScript HudScript_WaterBlock1 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_1_png, (s32)battle_action_cmd_water_block_1_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlock2 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_2_png, (s32)battle_action_cmd_water_block_2_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlock3 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_3_png, (s32)battle_action_cmd_water_block_3_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlock0 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_0_png, (s32)battle_action_cmd_water_block_0_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlock4 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_4_png, (s32)battle_action_cmd_water_block_4_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlockBlock = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_32x32,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_block_png, (s32)battle_action_cmd_water_block_block_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlockCircle = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_40x40,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_circle_png, (s32)battle_action_cmd_water_block_circle_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlockCloud = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_40x40,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_cloud_png, (s32)battle_action_cmd_water_block_cloud_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript* D_802AB180_42C670[] = {
    &HudScript_WaterBlock0
};

HudScript* D_802AB184_42C674[] = {
    &HudScript_WaterBlock1, &HudScript_WaterBlock2, &HudScript_WaterBlock3, &HudScript_WaterBlock4, &HudScript_WaterBlock4, &HudScript_WaterBlock4, &HudScript_WaterBlock4, &HudScript_WaterBlock4, &HudScript_WaterBlock4, 0, 0
};

extern s32 D_80294460;

extern HudScript HudScript_AButton;
extern HudScript HudScript_AButtonDown;
extern HudScript HudScript_TimingBar3Chances;
extern HudScript HudScript_TimingCharge2;
extern HudScript HudScript_TimingCharge3;
extern HudScript HudScript_TimingCharge4b;
extern HudScript HudScript_TimingCharge4c;
extern HudScript HudScript_TimingOK;
extern HudScript HudScript_TimingMiss;
extern HudScript HudScript_TimingWait;
extern HudScript HudScript_TimingReady;

ApiStatus func_802A9000_42A4F0(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 id;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294460;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_WATER_BLOCK;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_64 = evt_get_variable(script, *args++);
    battleStatus->unk_84 = 1;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    id = hud_element_create(&HudScript_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HudScript_TimingBar3Chances);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_TimingWait);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_TimingWait);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_TimingWait);
    actionCommandStatus->hudElements[4] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_TimingOK);
    actionCommandStatus->hudElements[6] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_TimingOK);
    actionCommandStatus->hudElements[7] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(&HudScript_TimingOK);
    actionCommandStatus->hudElements[8] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    actionCommandStatus->hudElements[10] = hud_element_create(D_802AB184_42C674[0]);
    hud_element_set_render_pos(actionCommandStatus->hudElements[10],
                               actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);

    actionCommandStatus->hudElements[11] = hud_element_create(&HudScript_TimingCharge4c);
    hud_element_set_render_pos(actionCommandStatus->hudElements[11],
                               actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);

    id = hud_element_create(&HudScript_TimingCharge4b);
    actionCommandStatus->hudElements[12] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);

    switch (actionCommandStatus->unk_64) {
        case 0:
            actionCommandStatus->hudElements[13] = hud_element_create(&HudScript_WaterBlockBlock);
            id = actionCommandStatus->hudElements[13];
            break;
        case 1:
            actionCommandStatus->hudElements[13] = hud_element_create(&HudScript_WaterBlockCircle);
            id = actionCommandStatus->hudElements[13];
            break;
        case 2:
            actionCommandStatus->hudElements[13] = hud_element_create(&HudScript_WaterBlockCloud);
            id = actionCommandStatus->hudElements[13];
            break;
    }

    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    return ApiStatus_DONE2;
}

ApiStatus func_802A9398_42A888(Evt* script, s32 isInitialCall) {
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
    battleStatus->unk_84 = 1;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_8000;
    func_80269118();
    return ApiStatus_DONE2;
}

void func_802A948C_42A97C(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 pos;
    s32 i;
    s32 limit;
    s32 id;

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
            id = actionCommandStatus->hudElements[4];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[10];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[11];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[12];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[13];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->unk_61 != 0) {
                hud_element_clear_flags(id, 2);
            }
            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_6C != 0) {
                actionCommandStatus->unk_6C--;
                return;
            }
            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX + 28, actionCommandStatus->hudElementY + 28);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudElementX + 21, actionCommandStatus->hudElementY + 24);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudElementX + 41, actionCommandStatus->hudElementY + 24);
            hud_element_set_render_pos(actionCommandStatus->hudElements[4], actionCommandStatus->hudElementX + 61, actionCommandStatus->hudElementY + 24);

            id = actionCommandStatus->hudElements[10];
            switch (actionCommandStatus->unk_64) {
                case 0:
                    hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 91, actionCommandStatus->hudElementY + 7);
                    break;
                case 1:
                    hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 91, actionCommandStatus->hudElementY + 13);
                    break;
                case 2:
                    hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 91, actionCommandStatus->hudElementY + 13);
                    break;
            }

            hud_element_set_render_pos(actionCommandStatus->hudElements[11], actionCommandStatus->hudElementX - 5, actionCommandStatus->hudElementY + 29);
            hud_element_set_render_pos(actionCommandStatus->hudElements[12], actionCommandStatus->hudElementX + 7, actionCommandStatus->hudElementY + 29);
            hud_element_set_render_pos(actionCommandStatus->hudElements[13], actionCommandStatus->hudElementX + 92, actionCommandStatus->hudElementY + 23);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E--;
                return;
            }

            actionCommandStatus->unk_54 = actionCommandStatus->unk_52 - 60;
            if (actionCommandStatus->unk_54 < 42) {
                actionCommandStatus->unk_54 = 42;
            }
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_54 == 42) {
                hud_element_set_script(actionCommandStatus->hudElements[11], &HudScript_TimingCharge3);
                sfx_play_sound(SOUND_233);
            }
            if (actionCommandStatus->unk_54 == 22) {
                hud_element_set_script(actionCommandStatus->hudElements[12], &HudScript_TimingCharge2);
                sfx_play_sound(SOUND_233);
            }
            if (actionCommandStatus->unk_54 == 2) {
                hud_element_set_script(actionCommandStatus->hudElements[2], &HudScript_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_AButtonDown);
                sfx_play_sound(SOUND_234);
            }
            actionCommandStatus->unk_54--;
            if (actionCommandStatus->unk_54 == 0) {
                actionCommandStatus->unk_54 = 20;
                actionCommandStatus->unk_5D = 0;
                actionCommandStatus->state = 12;
                actionCommandStatus->unk_5C = 0;
                actionCommandStatus->unk_60 = 0;
            }
            break;
        case 12:
            btl_set_popup_duration(99);
            if ((actionCommandStatus->unk_60 == 0) && (actionCommandStatus->unk_5C == 0) && (actionCommandStatus->unk_5D >= -5)) {
                limit = battleStatus->unk_434[actionCommandStatus->unk_50 * 2] +
                        battleStatus->unk_434[actionCommandStatus->unk_50 * 2 + 1] +
                        5;
                pos = battleStatus->inputBufferPos;
                pos -= limit;
                if (pos < 0) {
                    pos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }
                if (limit == 0) {
                    limit = 1;
                }

                for (i = 0; i < limit; pos++, i++) {
                    if (pos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        pos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    if (i < 5 && (battleStatus->pushInputBuffer[pos] & BUTTON_A)) {
                        actionCommandStatus->unk_60 = 1;
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !(actionCommandStatus->unk_60 != 0)) ||
                        (actionCommandStatus->autoSucceed != 0)) {
                        actionCommandStatus->unk_5C = 1;
                        battleStatus->unk_84++;
                        break;
                    }
                }
            }

            if ((actionCommandStatus->unk_5D >= -4) && ((actionCommandStatus->unk_60 != 0) || (actionCommandStatus->unk_5C != 0))) {
                id = actionCommandStatus->hudElements[6];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HudScript_TimingOK);
                } else {
                    hud_element_set_script(id, &HudScript_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 28, actionCommandStatus->hudElementY + 38);
                hud_element_clear_flags(id, 2);
            }

            if (actionCommandStatus->unk_5D == -5) {
                id = actionCommandStatus->hudElements[6];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HudScript_TimingOK);
                } else {
                    hud_element_set_script(id, &HudScript_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 28, actionCommandStatus->hudElementY + 38);
                hud_element_clear_flags(id, 2);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_AButton);
            }
            actionCommandStatus->unk_5D--;
            if (actionCommandStatus->unk_54 == 2) {
                hud_element_set_script(actionCommandStatus->hudElements[3], &HudScript_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_AButtonDown);
                sfx_play_sound(SOUND_234);
            }
            actionCommandStatus->unk_54--;
            if (actionCommandStatus->unk_54 == 0) {
                actionCommandStatus->unk_54 = 20;
                actionCommandStatus->unk_5D = 0;
                actionCommandStatus->state = 13;
                actionCommandStatus->unk_5C = 0;
                actionCommandStatus->unk_60 = 0;
            }
            break;
        case 13:
            btl_set_popup_duration(99);
            if ((actionCommandStatus->unk_60 == 0) && (actionCommandStatus->unk_5C == 0) && (actionCommandStatus->unk_5D >= -5)) {
                limit = battleStatus->unk_434[actionCommandStatus->unk_50 * 2] +
                        battleStatus->unk_434[actionCommandStatus->unk_50 * 2 + 1] +
                        4;
                if (limit < 6) {
                    limit = 6;
                }
                pos = battleStatus->inputBufferPos;
                pos -= limit;
                if (pos < 0) {
                    pos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }
                if (limit == 0) {
                    limit = 1;
                }

                for (i = 0; i < limit; pos++, i++) {
                    if (pos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        pos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    if (i < 5) {
                        if (battleStatus->pushInputBuffer[pos] & BUTTON_A) {
                            actionCommandStatus->unk_60 = 1;
                        }
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !(actionCommandStatus->unk_60 != 0)) ||
                        (actionCommandStatus->autoSucceed != 0)) {
                        actionCommandStatus->unk_5C = 1;
                        battleStatus->unk_84++;
                        break;
                    }
                }
            }

            if ((actionCommandStatus->unk_5D >= -4) && ((actionCommandStatus->unk_60 != 0) || (actionCommandStatus->unk_5C != 0))) {
                id = actionCommandStatus->hudElements[7];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HudScript_TimingOK);
                } else {
                    hud_element_set_script(id, &HudScript_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 48, actionCommandStatus->hudElementY + 38);
                hud_element_clear_flags(id, 2);
            }
            if (actionCommandStatus->unk_5D == -5) {
                id = actionCommandStatus->hudElements[7];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HudScript_TimingOK);
                } else {
                    hud_element_set_script(id, &HudScript_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 48, actionCommandStatus->hudElementY + 38);
                hud_element_clear_flags(id, 2);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_AButton);
            }
            actionCommandStatus->unk_5D--;
            if (actionCommandStatus->unk_54 == 2) {
                hud_element_set_script(actionCommandStatus->hudElements[4], &HudScript_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_AButtonDown);
                sfx_play_sound(SOUND_234);
            }
            actionCommandStatus->unk_54--;
            if (actionCommandStatus->unk_54 == 0) {
                actionCommandStatus->unk_54 = 20;
                actionCommandStatus->unk_5D = 0;
                actionCommandStatus->state = 14;
                actionCommandStatus->unk_5C = 0;
                actionCommandStatus->unk_60 = 0;
            }
            break;
        case 14:
            btl_set_popup_duration(99);
            if ((actionCommandStatus->unk_60 == 0) && (actionCommandStatus->unk_5C == 0) && (actionCommandStatus->unk_5D >= -5)) {
                limit = battleStatus->unk_434[actionCommandStatus->unk_50 * 2] +
                        battleStatus->unk_434[actionCommandStatus->unk_50 * 2 + 1] +
                        3;
                if (limit < 6) {
                    limit = 6;
                }
                pos = battleStatus->inputBufferPos;
                pos -= limit;
                if (pos < 0) {
                    pos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }
                if (limit == 0) {
                    limit = 1;
                }

                for (i = 0; i < limit; pos++, i++) {
                    if (pos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        pos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    if (i < 5) {
                        if (battleStatus->pushInputBuffer[pos] & BUTTON_A) {
                            actionCommandStatus->unk_60 = 1;
                        }
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !(actionCommandStatus->unk_60 != 0)) ||
                        (actionCommandStatus->autoSucceed != 0)) {
                        actionCommandStatus->unk_5C = 1;
                        battleStatus->unk_84++;
                        break;
                    }
                }
            }
            if (actionCommandStatus->unk_5D >= -4) {
                if ((actionCommandStatus->unk_60 != 0) || (actionCommandStatus->unk_5C != 0)) {
                    id = actionCommandStatus->hudElements[8];
                    if (actionCommandStatus->unk_5C != 0) {
                        hud_element_set_script(id, &HudScript_TimingOK);
                    } else {
                        hud_element_set_script(id, &HudScript_TimingMiss);
                    }
                    hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 68, actionCommandStatus->hudElementY + 38);
                    hud_element_clear_flags(id, 2);
                }
            }
            if (actionCommandStatus->unk_5D == -5) {
                id = actionCommandStatus->hudElements[8];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HudScript_TimingOK);
                } else {
                    hud_element_set_script(id, &HudScript_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudElementX + 68, actionCommandStatus->hudElementY + 38);
                hud_element_clear_flags(id, 2);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HudScript_AButton);
                actionCommandStatus->state = 16;
                return;
            }
            actionCommandStatus->unk_5D--;
            break;
        case 16:
            if (battleStatus->unk_84 == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = battleStatus->unk_84;
            }
            battleStatus->unk_86 = 1;
            if (battleStatus->actionSuccess == 3) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            actionCommandStatus->unk_54 = 5;
            actionCommandStatus->state = 17;
            break;
        case 17:
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54--;
                return;
            }
            func_80268C9C();
            break;
    }
}

void func_802AA014_42B504(void) {
    s32 hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[1]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[3]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[4]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[6]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[7]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[8]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[13]);

    hudElement = actionCommandStatus->hudElements[10];
    if (hud_element_get_script(hudElement) != D_802AB180_42C670[battleStatus->unk_84]) {
        hud_element_set_script(hudElement, D_802AB180_42C670[battleStatus->unk_84]);
    }

    hud_element_draw_clipped(hudElement);
    hud_element_draw_clipped(actionCommandStatus->hudElements[11]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[12]);
}

void func_802AA0D8_42B5C8(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
    hud_element_free(gActionCommandStatus.hudElements[6]);
    hud_element_free(gActionCommandStatus.hudElements[7]);
    hud_element_free(gActionCommandStatus.hudElements[8]);
    hud_element_free(gActionCommandStatus.hudElements[10]);
    hud_element_free(gActionCommandStatus.hudElements[11]);
    hud_element_free(gActionCommandStatus.hudElements[12]);
    hud_element_free(gActionCommandStatus.hudElements[13]);
}
