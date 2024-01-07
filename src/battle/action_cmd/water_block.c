#include "common.h"
#include "battle/action_cmd.h"
#include "include_asset.h"

#define NAMESPACE action_command_water_block

INCLUDE_IMG("battle/action_cmd/water_block_1.png", battle_action_cmd_water_block_1_png);
INCLUDE_PAL("battle/action_cmd/water_block_1.pal", battle_action_cmd_water_block_1_pal);

INCLUDE_IMG("battle/action_cmd/water_block_2.png", battle_action_cmd_water_block_2_png);
INCLUDE_PAL("battle/action_cmd/water_block_2.pal", battle_action_cmd_water_block_2_pal);

INCLUDE_IMG("battle/action_cmd/water_block_3.png", battle_action_cmd_water_block_3_png);
INCLUDE_PAL("battle/action_cmd/water_block_3.pal", battle_action_cmd_water_block_3_pal);

INCLUDE_IMG("battle/action_cmd/water_block_0.png", battle_action_cmd_water_block_0_png);
INCLUDE_PAL("battle/action_cmd/water_block_0.pal", battle_action_cmd_water_block_0_pal);

INCLUDE_IMG("battle/action_cmd/water_block_block.png", battle_action_cmd_water_block_block_png);
INCLUDE_PAL("battle/action_cmd/water_block_block.pal", battle_action_cmd_water_block_block_pal);

INCLUDE_IMG("battle/action_cmd/water_block_circle.png", battle_action_cmd_water_block_circle_png);
INCLUDE_PAL("battle/action_cmd/water_block_circle.pal", battle_action_cmd_water_block_circle_pal);

INCLUDE_IMG("battle/action_cmd/water_block_cloud.png", battle_action_cmd_water_block_cloud_png);
INCLUDE_PAL("battle/action_cmd/water_block_cloud.pal", battle_action_cmd_water_block_cloud_pal);

INCLUDE_IMG("battle/action_cmd/water_block_4.png", battle_action_cmd_water_block_4_png);
INCLUDE_PAL("battle/action_cmd/water_block_4.pal", battle_action_cmd_water_block_4_pal);

HudScript HES_WaterBlock1 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_1_png, (s32)battle_action_cmd_water_block_1_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HES_WaterBlock2 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_2_png, (s32)battle_action_cmd_water_block_2_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HES_WaterBlock3 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_3_png, (s32)battle_action_cmd_water_block_3_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HES_WaterBlock0 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_0_png, (s32)battle_action_cmd_water_block_0_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HES_WaterBlock4 = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_4_png, (s32)battle_action_cmd_water_block_4_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HES_WaterBlockBlock = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_32x32,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_block_png, (s32)battle_action_cmd_water_block_block_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HES_WaterBlockCircle = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_40x40,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_circle_png, (s32)battle_action_cmd_water_block_circle_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HES_WaterBlockCloud = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_40x40,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_cloud_png, (s32)battle_action_cmd_water_block_cloud_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript* D_802AB180_42C670[] = {
    &HES_WaterBlock0
};

HudScript* D_802AB184_42C674[] = {
    &HES_WaterBlock1, &HES_WaterBlock2, &HES_WaterBlock3, &HES_WaterBlock4, &HES_WaterBlock4, &HES_WaterBlock4, &HES_WaterBlock4, &HES_WaterBlock4, &HES_WaterBlock4, 0, 0
};

extern s32 actionCmdTableWaterBlock[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 id;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableWaterBlock;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_WATER_BLOCK;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->targetWeakness = evt_get_variable(script, *args++);
    battleStatus->actionQuality = 1;
    actionCommandStatus->hudPrepareTime = 30;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_TimingBar3Chances);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_TimingWait);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_TimingWait);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_TimingWait);
    actionCommandStatus->hudElements[4] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_TimingOK);
    actionCommandStatus->hudElements[6] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_TimingOK);
    actionCommandStatus->hudElements[7] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_TimingOK);
    actionCommandStatus->hudElements[8] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    actionCommandStatus->hudElements[10] = hud_element_create(D_802AB184_42C674[0]);
    hud_element_set_render_pos(actionCommandStatus->hudElements[10],
                               actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);

    actionCommandStatus->hudElements[11] = hud_element_create(&HES_TimingCharge4c);
    hud_element_set_render_pos(actionCommandStatus->hudElements[11],
                               actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);

    id = hud_element_create(&HES_TimingCharge4b);
    actionCommandStatus->hudElements[12] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);

    switch (actionCommandStatus->targetWeakness) {
        case 0:
            actionCommandStatus->hudElements[13] = hud_element_create(&HES_WaterBlockBlock);
            id = actionCommandStatus->hudElements[13];
            break;
        case 1:
            actionCommandStatus->hudElements[13] = hud_element_create(&HES_WaterBlockCircle);
            id = actionCommandStatus->hudElements[13];
            break;
        case 2:
            actionCommandStatus->hudElements[13] = hud_element_create(&HES_WaterBlockCloud);
            id = actionCommandStatus->hudElements[13];
            break;
    }

    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    battleStatus->actionQuality = 1;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    func_80269118();
    return ApiStatus_DONE2;
}

void N(update)(void) {
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
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);
            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[2];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[3];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[4];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[10];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[11];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[12];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            id = actionCommandStatus->hudElements[13];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            if (actionCommandStatus->hudPrepareTime != 0) {
                actionCommandStatus->hudPrepareTime--;
                return;
            }
            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX + 28, actionCommandStatus->hudPosY + 28);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudPosX + 21, actionCommandStatus->hudPosY + 24);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudPosX + 41, actionCommandStatus->hudPosY + 24);
            hud_element_set_render_pos(actionCommandStatus->hudElements[4], actionCommandStatus->hudPosX + 61, actionCommandStatus->hudPosY + 24);

            id = actionCommandStatus->hudElements[10];
            switch (actionCommandStatus->targetWeakness) {
                case 0:
                    hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 91, actionCommandStatus->hudPosY + 7);
                    break;
                case 1:
                    hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 91, actionCommandStatus->hudPosY + 13);
                    break;
                case 2:
                    hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 91, actionCommandStatus->hudPosY + 13);
                    break;
            }

            hud_element_set_render_pos(actionCommandStatus->hudElements[11], actionCommandStatus->hudPosX - 5, actionCommandStatus->hudPosY + 29);
            hud_element_set_render_pos(actionCommandStatus->hudElements[12], actionCommandStatus->hudPosX + 7, actionCommandStatus->hudPosY + 29);
            hud_element_set_render_pos(actionCommandStatus->hudElements[13], actionCommandStatus->hudPosX + 92, actionCommandStatus->hudPosY + 23);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                return;
            }

            actionCommandStatus->frameCounter = actionCommandStatus->duration - 60;
            if (actionCommandStatus->frameCounter < 42) {
                actionCommandStatus->frameCounter = 42;
            }
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->frameCounter == 42) {
                hud_element_set_script(actionCommandStatus->hudElements[11], &HES_TimingCharge3);
                sfx_play_sound(SOUND_TIMING_BAR_TICK);
            }
            if (actionCommandStatus->frameCounter == 22) {
                hud_element_set_script(actionCommandStatus->hudElements[12], &HES_TimingCharge2);
                sfx_play_sound(SOUND_TIMING_BAR_TICK);
            }
            if (actionCommandStatus->frameCounter == 2) {
                hud_element_set_script(actionCommandStatus->hudElements[2], &HES_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButtonDown);
                sfx_play_sound(SOUND_TIMING_BAR_GO);
            }
            actionCommandStatus->frameCounter--;
            if (actionCommandStatus->frameCounter == 0) {
                actionCommandStatus->frameCounter = 20;
                actionCommandStatus->unk_5D = 0;
                actionCommandStatus->state = 12;
                actionCommandStatus->unk_5C = 0;
                actionCommandStatus->wrongButtonPressed = FALSE;
            }
            break;
        case 12:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->wrongButtonPressed && (actionCommandStatus->unk_5C == 0) && (actionCommandStatus->unk_5D >= -5)) {
                limit = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty * 2] +
                        battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty * 2 + 1] +
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
                        actionCommandStatus->wrongButtonPressed = TRUE;
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !actionCommandStatus->wrongButtonPressed) ||
                        actionCommandStatus->autoSucceed) {
                        actionCommandStatus->unk_5C = 1;
                        battleStatus->actionQuality++;
                        break;
                    }
                }
            }

            if ((actionCommandStatus->unk_5D >= -4) && (actionCommandStatus->wrongButtonPressed || (actionCommandStatus->unk_5C != 0))) {
                id = actionCommandStatus->hudElements[6];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HES_TimingOK);
                } else {
                    hud_element_set_script(id, &HES_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 28, actionCommandStatus->hudPosY + 38);
                hud_element_clear_flags(id, 2);
            }

            if (actionCommandStatus->unk_5D == -5) {
                id = actionCommandStatus->hudElements[6];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HES_TimingOK);
                } else {
                    hud_element_set_script(id, &HES_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 28, actionCommandStatus->hudPosY + 38);
                hud_element_clear_flags(id, 2);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButton);
            }
            actionCommandStatus->unk_5D--;
            if (actionCommandStatus->frameCounter == 2) {
                hud_element_set_script(actionCommandStatus->hudElements[3], &HES_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButtonDown);
                sfx_play_sound(SOUND_TIMING_BAR_GO);
            }
            actionCommandStatus->frameCounter--;
            if (actionCommandStatus->frameCounter == 0) {
                actionCommandStatus->frameCounter = 20;
                actionCommandStatus->unk_5D = 0;
                actionCommandStatus->state = 13;
                actionCommandStatus->unk_5C = 0;
                actionCommandStatus->wrongButtonPressed = FALSE;
            }
            break;
        case 13:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->wrongButtonPressed && (actionCommandStatus->unk_5C == 0) && (actionCommandStatus->unk_5D >= -5)) {
                limit = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty * 2] +
                        battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty * 2 + 1] +
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
                            actionCommandStatus->wrongButtonPressed = TRUE;
                        }
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !actionCommandStatus->wrongButtonPressed) ||
                        actionCommandStatus->autoSucceed) {
                        actionCommandStatus->unk_5C = 1;
                        battleStatus->actionQuality++;
                        break;
                    }
                }
            }

            if ((actionCommandStatus->unk_5D >= -4) && (actionCommandStatus->wrongButtonPressed || (actionCommandStatus->unk_5C != 0))) {
                id = actionCommandStatus->hudElements[7];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HES_TimingOK);
                } else {
                    hud_element_set_script(id, &HES_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 48, actionCommandStatus->hudPosY + 38);
                hud_element_clear_flags(id, 2);
            }
            if (actionCommandStatus->unk_5D == -5) {
                id = actionCommandStatus->hudElements[7];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HES_TimingOK);
                } else {
                    hud_element_set_script(id, &HES_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 48, actionCommandStatus->hudPosY + 38);
                hud_element_clear_flags(id, 2);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButton);
            }
            actionCommandStatus->unk_5D--;
            if (actionCommandStatus->frameCounter == 2) {
                hud_element_set_script(actionCommandStatus->hudElements[4], &HES_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButtonDown);
                sfx_play_sound(SOUND_TIMING_BAR_GO);
            }
            actionCommandStatus->frameCounter--;
            if (actionCommandStatus->frameCounter == 0) {
                actionCommandStatus->frameCounter = 20;
                actionCommandStatus->unk_5D = 0;
                actionCommandStatus->state = 14;
                actionCommandStatus->unk_5C = 0;
                actionCommandStatus->wrongButtonPressed = FALSE;
            }
            break;
        case 14:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->wrongButtonPressed && (actionCommandStatus->unk_5C == 0) && (actionCommandStatus->unk_5D >= -5)) {
                limit = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty * 2] +
                        battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty * 2 + 1] +
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
                            actionCommandStatus->wrongButtonPressed = TRUE;
                        }
                    }

                    if (((battleStatus->pushInputBuffer[pos] & BUTTON_A) && !actionCommandStatus->wrongButtonPressed) ||
                        actionCommandStatus->autoSucceed) {
                        actionCommandStatus->unk_5C = 1;
                        battleStatus->actionQuality++;
                        break;
                    }
                }
            }
            if (actionCommandStatus->unk_5D >= -4) {
                if (actionCommandStatus->wrongButtonPressed || (actionCommandStatus->unk_5C != 0)) {
                    id = actionCommandStatus->hudElements[8];
                    if (actionCommandStatus->unk_5C != 0) {
                        hud_element_set_script(id, &HES_TimingOK);
                    } else {
                        hud_element_set_script(id, &HES_TimingMiss);
                    }
                    hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 68, actionCommandStatus->hudPosY + 38);
                    hud_element_clear_flags(id, 2);
                }
            }
            if (actionCommandStatus->unk_5D == -5) {
                id = actionCommandStatus->hudElements[8];
                if (actionCommandStatus->unk_5C != 0) {
                    hud_element_set_script(id, &HES_TimingOK);
                } else {
                    hud_element_set_script(id, &HES_TimingMiss);
                }
                hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 68, actionCommandStatus->hudPosY + 38);
                hud_element_clear_flags(id, 2);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButton);
                actionCommandStatus->state = 16;
                return;
            }
            actionCommandStatus->unk_5D--;
            break;
        case 16:
            if (battleStatus->actionQuality == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = battleStatus->actionQuality;
            }
            battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            if (battleStatus->actionSuccess == 3) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            actionCommandStatus->frameCounter = 5;
            actionCommandStatus->state = 17;
            break;
        case 17:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
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
    if (hud_element_get_script(hudElement) != D_802AB180_42C670[battleStatus->actionQuality]) {
        hud_element_set_script(hudElement, D_802AB180_42C670[battleStatus->actionQuality]);
    }

    hud_element_draw_clipped(hudElement);
    hud_element_draw_clipped(actionCommandStatus->hudElements[11]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[12]);
}

void N(free)(void) {
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
