#include "common.h"
#include "ld_addrs.h"

u8 mashMeter_bgColors[15] = {
     33,  33, 117,
     29,  35, 163,
     70,  12, 180,
    107,   0, 120,
    115,  13,  19,
};

u8 mashMeter_fillColors[15] = {
      0, 228, 134,
     46, 180, 242,
    117, 112, 255,
    243,   4, 188,
    247,  13,   5,
};

u8 mashMeter_cutOffColors[15] = {
     45,  56, 210,
     84,  40, 209,
    125,  44, 181,
    161,  27,  85,
    255, 255, 255,
};

s32 actionCmdTableJump[] = { 7, 6, 5, 4, 3, 2, 1, 0 };
s32 actionCmdTableHammer[] = { 11, 10, 9, 8, 7, 6, 5, 4 };
s32 actionCmdTableFlee[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableBreakFree[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableWhirlwind[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableStopLeech[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTable07[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableDizzyShell[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableFireShell[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTable0A[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableBomb[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableBodySlam[] = { 9, 8, 7, 6, 5, 4, 3, 2 };
s32 actionCmdTableAirLift[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableAirRaid[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableSquirt[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTablePowerShock[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableMegaShock[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableSmack[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableSpinySurge[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableHurricane[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableSpook[] = { 130, 120, 110, 100, 90, 80, 70, 60 };
s32 actionCmdTableWaterBlock[] = { 6, 3, 5, 3, 4, 3, 2, 3, 1, 3, 0, 3, 0, 2, 0, 1 };
s32 actionCmdTableTidalWave[] = { 130, 120, 110, 100, 90, 80, 70, 60 };

#define AC_TBL_ENTRY(name) \
    action_cmd_ ## name ## _ROM_START, action_cmd_ ## name ## _ROM_END, action_cmd_ ## name ## _VRAM

void* actionCommandDmaTable[] = {
    NULL, NULL, NULL,
    AC_TBL_ENTRY(jump),
    AC_TBL_ENTRY(hammer),
    AC_TBL_ENTRY(flee),
    AC_TBL_ENTRY(break_free),
    AC_TBL_ENTRY(whirlwind),
    AC_TBL_ENTRY(stop_leech),
    AC_TBL_ENTRY(07),
    AC_TBL_ENTRY(dizzy_shell),
    AC_TBL_ENTRY(fire_shell),
    AC_TBL_ENTRY(0A),
    AC_TBL_ENTRY(bomb),
    AC_TBL_ENTRY(body_slam),
    AC_TBL_ENTRY(air_lift),
    AC_TBL_ENTRY(air_raid),
    AC_TBL_ENTRY(squirt),
    AC_TBL_ENTRY(power_shock),
    AC_TBL_ENTRY(mega_shock),
    AC_TBL_ENTRY(smack),
    AC_TBL_ENTRY(spiny_surge),
    AC_TBL_ENTRY(hurricane),
    AC_TBL_ENTRY(spook),
    AC_TBL_ENTRY(water_block),
    AC_TBL_ENTRY(tidal_wave),
};

BSS s32 sMashMeterSmoothDivisor;
BSS s32 D_8029FBC4_pad[3];
// TODO move to actor_api
BSS s32 IsGroupHeal;
BSS s8 ApplyingBuff;
BSS s32 D_8029FBD8_pad[2];

#include "action_cmd.h"

BSS ActionCommandStatus gActionCommandStatus;

API_CALLABLE(LoadActionCommand) {
    Bytecode* args = script->ptrReadPos;
    s32 cmd = evt_get_variable(script, *args++);

    dma_copy(actionCommandDmaTable[cmd * 3 + 0], actionCommandDmaTable[cmd * 3 + 1], actionCommandDmaTable[cmd * 3 + 2]);
    return ApiStatus_DONE2;
}

s32 adjust_action_command_difficulty(s32 arg0) {
    if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
        arg0 -= is_ability_active(ABILITY_DODGE_MASTER) * 3;
    }

    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 7) {
        arg0 = 7;
    }

    return arg0;
}

void draw_mash_meter(s32 posX, s32 posY, s32 fillValue, s32 colorMode) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 maxCutOff;
    s32 i;
    s32 cutOff;
    s32 width;
    s32 offsetX;
    s32 filledWidth;
    s32 r, g, b;

    if (!actionCommandStatus->showHud) {
        return;
    }

    posX -= 28;
    posY -= 4;

    maxCutOff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];

    if (fillValue < 0) {
        fillValue = 0;
    }

    width = 0;
    for (i = 0; i < actionCommandStatus->mashMeterIntervals; i++) {
        cutOff = actionCommandStatus->mashMeterCutoffs[i + 1];
        if (cutOff > fillValue) {
            cutOff = fillValue;
        }

        width = (cutOff * 60 / maxCutOff) * 100;
        if (fillValue == cutOff) {
            break;
        }
    }

    //difference between current and previous filled value
    offsetX = width - actionCommandStatus->barFillWidth;
    if (abs(offsetX) >= sMashMeterSmoothDivisor * 100) {
        actionCommandStatus->barFillWidth += offsetX / sMashMeterSmoothDivisor;
    } else {
        actionCommandStatus->barFillWidth = width;
    }

    offsetX = 0;
    for (i = 0; i < actionCommandStatus->mashMeterIntervals; i++) {
        cutOff = actionCommandStatus->mashMeterCutoffs[i + 1];
        width = (cutOff * 60 / maxCutOff) - offsetX;
        r = mashMeter_bgColors[3 * i + 0];
        g = mashMeter_bgColors[3 * i + 1];
        b = mashMeter_bgColors[3 * i + 2];
        startup_draw_prim_rect_COPY(posX + offsetX, posY, posX + offsetX + width, posY + 5, r, g, b, 255);
        if (i < actionCommandStatus->mashMeterIntervals - 1) {
            r = mashMeter_cutOffColors[3 * i + 0];
            g = mashMeter_cutOffColors[3 * i + 1];
            b = mashMeter_cutOffColors[3 * i + 2];
            startup_draw_prim_rect_COPY(posX + offsetX + width - 1, posY, posX + offsetX + width, posY + 5, r, g, b, 255);
            offsetX += width;
        } else {
            break;
        }
    }

    offsetX = 0;
    for (i = 0; i < actionCommandStatus->mashMeterIntervals; i++) {
        if (colorMode == 0) {
            r = mashMeter_fillColors[3 * i + 0];
            g = mashMeter_fillColors[3 * i + 1];
            b = mashMeter_fillColors[3 * i + 2];
        } else if (colorMode > 0) {
            r = 224;
            g = 63;
            b = 0;
        } else if (gGameStatusPtr->frameCounter % 2 != 0){
            r = mashMeter_fillColors[3 * i + 0];
            g = mashMeter_fillColors[3 * i + 1];
            b = mashMeter_fillColors[3 * i + 2];
        } else {
            r = 250;
            g = 175;
            b = 0;
        }

        cutOff = actionCommandStatus->mashMeterCutoffs[i + 1];
        if (cutOff > fillValue) {
            cutOff = fillValue;
        }

        filledWidth = cutOff * 60 / maxCutOff - offsetX;
        width = actionCommandStatus->barFillWidth / 100 - offsetX;

        if (width < 0) {
            break;
        }
        if (filledWidth == 0) {
            filledWidth = width;
        } else if (cutOff == fillValue) {
            filledWidth = width;
        } else if (width > filledWidth) {
            width = filledWidth;
        }

        startup_draw_prim_rect_COPY(posX + offsetX, posY, posX + offsetX + width, posY + 5, r, g, b, 255);
        offsetX += filledWidth;
        if (i >= actionCommandStatus->mashMeterIntervals - 1) {
            break;
        }
    }
}

void draw_mash_meter_multicolor(s32 posX, s32 posY, s32 fillValue) {
    sMashMeterSmoothDivisor = 2;
    draw_mash_meter(posX, posY, fillValue, MASH_METER_MODE_MULTI_COLOR);
}

void draw_mash_meter_multicolor_with_divisor(s32 posX, s32 posY, s32 fillValue, s32 divisor) {
    sMashMeterSmoothDivisor = divisor;
    draw_mash_meter(posX, posY, fillValue, MASH_METER_MODE_MULTI_COLOR);
}

void draw_mash_meter_mode(s32 posX, s32 posY, s32 fillValue, s32 colorMode) {
    sMashMeterSmoothDivisor = 2;
    draw_mash_meter(posX, posY, fillValue, colorMode);
}

void draw_mash_meter_mode_with_divisor(s32 posX, s32 posY, s32 fillValue, s32 divisor, s32 colorMode) {
    sMashMeterSmoothDivisor = divisor;
    draw_mash_meter(posX, posY, fillValue, colorMode);
}

void draw_mash_meter_blink(s32 posX, s32 posY, s32 fillValue) {
    sMashMeterSmoothDivisor = 2;
    draw_mash_meter(posX, posY, fillValue, MASH_METER_MODE_BLINK);
}

void draw_mash_meter_blink_with_divisor(s32 posX, s32 posY, s32 fillValue, s32 divisor) {
    sMashMeterSmoothDivisor = divisor;
    draw_mash_meter(posX, posY, fillValue, MASH_METER_MODE_BLINK);
}

void action_command_init_status(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    actionCommandStatus->autoSucceed = FALSE;
    actionCommandStatus->berserkerEnabled = FALSE;

    if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
        if (is_ability_active(ABILITY_RIGHT_ON)) {
            actionCommandStatus->autoSucceed = TRUE;
        }

        if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING) && is_ability_active(ABILITY_BERSERKER)) {
            actionCommandStatus->showHud = FALSE;
            actionCommandStatus->berserkerEnabled = TRUE;

            if (rand_int(100) < 25) {
                actionCommandStatus->autoSucceed = TRUE;
            }
        }
    }

    if (gGameStatusPtr->demoBattleFlags & DEMO_BTL_FLAG_ENABLED) {
        actionCommandStatus->autoSucceed = TRUE;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_AUTO_SUCCEED_ACTION) {
        actionCommandStatus->autoSucceed = TRUE;
        actionCommandStatus->showHud = FALSE;
    }
}

void action_command_update(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    if (gBattleStatus.flags1 & BS_FLAGS1_FREE_ACTION_COMMAND) {
        action_command_free();
    }

    switch (actionCommandStatus->actionCommandID) {
        case ACTION_COMMAND_NONE:
            break;
        case ACTION_COMMAND_JUMP:
            action_command_jump_update();
            break;
        case ACTION_COMMAND_SMASH:
            action_command_hammer_update();
            break;
        case ACTION_COMMAND_FLEE:
            action_command_flee_update();
            break;
        case ACTION_COMMAND_BREAK_FREE:
            action_command_break_free_update();
            break;
        case ACTION_COMMAND_WHIRLWIND:
            action_command_whirlwind_update();
            break;
        case ACTION_COMMAND_STOP_LEECH:
            action_command_stop_leech_update();
            break;
        case ACTION_COMMAND_07:
            action_command_07_update();
            break;
        case ACTION_COMMAND_DIZZY_SHELL:
            action_command_dizzy_shell_update();
            break;
        case ACTION_COMMAND_FIRE_SHELL:
            action_command_fire_shell_update();
            break;
        case ACTION_COMMAND_0A:
            action_command_0A_update();
            break;
        case ACTION_COMMAND_BOMB:
            action_command_bomb_update();
            break;
        case ACTION_COMMAND_BODY_SLAM:
            action_command_body_slam_update();
            break;
        case ACTION_COMMAND_AIR_LIFT:
            action_command_air_lift_update();
            break;
        case ACTION_COMMAND_AIR_RAID:
            action_command_air_raid_update();
            break;
        case ACTION_COMMAND_SQUIRT:
            action_command_squirt_update();
            break;
        case ACTION_COMMAND_POWER_SHOCK:
            action_command_power_shock_update();
            break;
        case ACTION_COMMAND_MEGA_SHOCK:
            action_command_mega_shock_update();
            break;
        case ACTION_COMMAND_SMACK:
            action_command_smack_update();
            break;
        case ACTION_COMMAND_SPINY_SURGE:
            action_command_spiny_surge_update();
            break;
        case ACTION_COMMAND_HURRICANE:
            action_command_hurricane_update();
            break;
        case ACTION_COMMAND_SPOOK:
            action_command_spook_update();
            break;
        case ACTION_COMMAND_WATER_BLOCK:
            action_command_water_block_update();
            break;
        case ACTION_COMMAND_TIDAL_WAVE:
            action_command_tidal_wave_update();
            break;
        default:
            break;
    }
}

void action_command_draw(void) {
    switch (gActionCommandStatus.actionCommandID) {
        case ACTION_COMMAND_NONE:
            break;
        case ACTION_COMMAND_JUMP:
            action_command_jump_draw();
            break;
        case ACTION_COMMAND_SMASH:
            action_command_hammer_draw();
            break;
        case ACTION_COMMAND_FLEE:
            action_command_flee_draw();
            break;
        case ACTION_COMMAND_BREAK_FREE:
            action_command_break_free_draw();
            break;
        case ACTION_COMMAND_WHIRLWIND:
            action_command_whirlwind_draw();
            break;
        case ACTION_COMMAND_STOP_LEECH:
            action_command_stop_leech_draw();
            break;
        case ACTION_COMMAND_07:
            action_command_07_draw();
            break;
        case ACTION_COMMAND_DIZZY_SHELL:
            action_command_dizzy_shell_draw();
            break;
        case ACTION_COMMAND_FIRE_SHELL:
            action_command_fire_shell_draw();
            break;
        case ACTION_COMMAND_0A:
            action_command_0A_draw();
            break;
        case ACTION_COMMAND_BOMB:
            action_command_bomb_draw();
            break;
        case ACTION_COMMAND_BODY_SLAM:
            action_command_body_slam_draw();
            break;
        case ACTION_COMMAND_AIR_LIFT:
            action_command_air_lift_draw();
            break;
        case ACTION_COMMAND_AIR_RAID:
            action_command_air_raid_draw();
            break;
        case ACTION_COMMAND_SQUIRT:
            action_command_squirt_draw();
            break;
        case ACTION_COMMAND_POWER_SHOCK:
            action_command_power_shock_draw();
            break;
        case ACTION_COMMAND_MEGA_SHOCK:
            action_command_mega_shock_draw();
            break;
        case ACTION_COMMAND_SMACK:
            action_command_smack_draw();
            break;
        case ACTION_COMMAND_SPINY_SURGE:
            action_command_spiny_surge_draw();
            break;
        case ACTION_COMMAND_HURRICANE:
            action_command_hurricane_draw();
            break;
        case ACTION_COMMAND_SPOOK:
            action_command_spook_draw();
            break;
        case ACTION_COMMAND_WATER_BLOCK:
            action_command_water_block_draw();
            break;
        case ACTION_COMMAND_TIDAL_WAVE:
            action_command_tidal_wave_draw();
    }
}

void action_command_free(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    switch (actionCommandStatus->actionCommandID) {
        case ACTION_COMMAND_NONE:
            break;
        case ACTION_COMMAND_JUMP:
            action_command_jump_free();
            break;
        case ACTION_COMMAND_SMASH:
            action_command_hammer_free();
            break;
        case ACTION_COMMAND_FLEE:
            action_command_flee_free();
            break;
        case ACTION_COMMAND_BREAK_FREE:
            action_command_break_free_free();
            break;
        case ACTION_COMMAND_WHIRLWIND:
            action_command_whirlwind_free();
            break;
        case ACTION_COMMAND_STOP_LEECH:
            action_command_jump_draw();
            break;
        case ACTION_COMMAND_07:
            action_command_07_free();
            break;
        case ACTION_COMMAND_DIZZY_SHELL:
            action_command_dizzy_shell_free();
            break;
        case ACTION_COMMAND_FIRE_SHELL:
            action_command_fire_shell_free();
            break;
        case ACTION_COMMAND_0A:
            action_command_0A_free();
            break;
        case ACTION_COMMAND_BOMB:
            action_command_bomb_free();
            break;
        case ACTION_COMMAND_BODY_SLAM:
            action_command_body_slam_free();
            break;
        case ACTION_COMMAND_AIR_LIFT:
            action_command_air_lift_free();
            break;
        case ACTION_COMMAND_AIR_RAID:
            action_command_air_raid_free();
            break;
        case ACTION_COMMAND_SQUIRT:
            action_command_squirt_free();
            break;
        case ACTION_COMMAND_POWER_SHOCK:
            action_command_power_shock_free();
            break;
        case ACTION_COMMAND_MEGA_SHOCK:
            action_command_mega_shock_free();
            break;
        case ACTION_COMMAND_SMACK:
            action_command_smack_free();
            break;
        case ACTION_COMMAND_SPINY_SURGE:
            action_command_spiny_surge_free();
            break;
        case ACTION_COMMAND_HURRICANE:
            action_command_hurricane_free();
            break;
        case ACTION_COMMAND_SPOOK:
            action_command_spook_free();
            break;
        case ACTION_COMMAND_WATER_BLOCK:
            action_command_water_block_free();
            break;
        case ACTION_COMMAND_TIDAL_WAVE:
            action_command_tidal_wave_free();
            break;
    }

    actionCommandStatus->actionCommandID = ACTION_COMMAND_NONE;
    gBattleStatus.flags1 &= ~BS_FLAGS1_2000;
    gBattleStatus.flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    gBattleStatus.flags1 &= ~BS_FLAGS1_4000;
    close_action_command_instruction_popup();
    btl_set_popup_duration(0);
}

void func_80268E88(void) {
    ActionCommandStatus* actionCmdStatus = &gActionCommandStatus;
    actionCmdStatus->workerID = create_worker_frontUI(action_command_update, action_command_draw);
    actionCmdStatus->actionCommandID = 0;
}

s32 check_block_input(s32 buttonMask) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 mashWindow;
    s32 blockWindow;
    s32 block;
    s32 mash = FALSE;
    s32 bufferPos;
    s32 i;
    s32 ignoreWindow;

    battleStatus->blockResult = BLOCK_RESULT_FAIL;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_TUTORIAL_BLOCK && (battleStatus->flags1 & BS_FLAGS1_TUTORIAL_BATTLE)) {
        battleStatus->blockResult = BLOCK_RESULT_SUCCESS;
        return TRUE;
    }

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED || (gGameStatusPtr->demoBattleFlags & DEMO_BTL_FLAG_ENABLED)) {
        return FALSE;
    }

    if (playerData->hitsTaken < 9999) {
        playerData->hitsTaken++;
        actionCommandStatus->hitsTakenIsMax = FALSE;
    } else {
        actionCommandStatus->hitsTakenIsMax = TRUE;
    }

    block = FALSE;
    blockWindow = 3;
    mashWindow = 10;

    if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING) && is_ability_active(ABILITY_DODGE_MASTER)) {
        blockWindow = 5;
    }

    // Pre-window mashing check
    bufferPos = battleStatus->inputBufferPos;
    bufferPos -= mashWindow + blockWindow;

    if (bufferPos < 0) {
        bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
    }
    for (i = 0; i < mashWindow; i++) {
        if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
            bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
        }

        if (battleStatus->pushInputBuffer[bufferPos] & buttonMask) {
            mash = TRUE;
            break;
        }
        bufferPos++;
    }

    // Block check
    bufferPos = battleStatus->inputBufferPos;
    bufferPos -= blockWindow;
    if (bufferPos < 0) {
        bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
    }
    for (i = 0; i < blockWindow; i++) {
        if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
            bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
        }

        if (battleStatus->pushInputBuffer[bufferPos] & buttonMask) {
            battleStatus->blockResult = BLOCK_RESULT_SUCCESS;
            block = TRUE;
            break;
        }
        bufferPos++;
    }

    if (mash) {
        battleStatus->blockResult = BLOCK_RESULT_EARLY;
        block = FALSE;
    }

    // Ignore inputs until another mash window has passed, so check_block_input() can be called in quick succession
    if (block == TRUE) {
        bufferPos = battleStatus->inputBufferPos;
        bufferPos -= mashWindow + blockWindow;
        if (bufferPos < 0) {
            bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
        }

        for (i = 0; i < mashWindow + blockWindow; i++) {
            if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
            }
            battleStatus->pushInputBuffer[bufferPos] = 0;
            bufferPos++;
        }
    }
    if (block && !actionCommandStatus->hitsTakenIsMax) {
        playerData->hitsBlocked++;
    }

    return block;
}

void func_80269118(void) {
    PlayerData* playerData = &gPlayerData;
    ActionCommandStatus *actionCommandStatus = &gActionCommandStatus;

    if (!actionCommandStatus->autoSucceed) {
        if (playerData->actionCommandAttempts < 9999) {
            playerData->actionCommandAttempts++;
            actionCommandStatus->hitsTakenIsMax = FALSE;
        } else {
            actionCommandStatus->hitsTakenIsMax = TRUE;
        }
    }
}

void func_80269160(void) {
    PlayerData* playerData = &gPlayerData;

    if (!gActionCommandStatus.autoSucceed && gActionCommandStatus.hitsTakenIsMax) {
        playerData->actionCommandSuccesses++;
    }
}

API_CALLABLE(SetActionDifficultyTable) {
    gBattleStatus.actionCmdDifficultyTable = (s32*) evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetupMashMeter) {
    Bytecode* args = script->ptrReadPos;
    gActionCommandStatus.mashMeterIntervals = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[1] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[2] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[3] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[4] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[5] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[0] = gActionCommandStatus.mashMeterCutoffs[1] / 2;
    return ApiStatus_DONE2;
}

API_CALLABLE(GetActionSuccess) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.actionSuccess);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetActionSuccess) {
    gBattleStatus.actionSuccess = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetActionCommandMode) {
    gBattleStatus.actionCommandMode = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetActionCommandMode) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.actionCommandMode);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetActionHudPrepareTime) {
    gActionCommandStatus.hudPrepareTime = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetCommandAutoSuccess) {
    evt_set_variable(script, *script->ptrReadPos, gActionCommandStatus.autoSucceed);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetCommandAutoSuccess) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    if (evt_get_variable(script, *script->ptrReadPos) != 0) {
        actionCommandStatus->autoSucceed = TRUE;
    } else {
        actionCommandStatus->autoSucceed = FALSE;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802693F0) {
    gBattleStatus.flags1 &= ~BS_FLAGS1_4000;
    return ApiStatus_DONE2;
}

API_CALLABLE(CloseActionCommandInfo) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    if (isInitialCall) {
        switch (actionCommandStatus->actionCommandID) {
            case ACTION_COMMAND_WHIRLWIND:
            case ACTION_COMMAND_STOP_LEECH:
                return ApiStatus_DONE2;
            default:
                action_command_free();
                return ApiStatus_BLOCK;
        }
    }

    sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
    close_action_command_instruction_popup();

    return ApiStatus_DONE2;
}

API_CALLABLE(func_80269470) {
    if (isInitialCall) {
        action_command_free();
        return ApiStatus_BLOCK;
    }

    close_action_command_instruction_popup();
    return ApiStatus_DONE2;
}

API_CALLABLE(ShowActionHud) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    if (evt_get_variable(script, *script->ptrReadPos) == 0) {
        actionCommandStatus->showHud = FALSE;
    } else {
        actionCommandStatus->showHud = TRUE;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(GetActionSuccessCopy) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.actionSuccess);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetActionResult) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.actionResult);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetActionResult) {
    gBattleStatus.actionResult = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetBlockResult) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.blockResult);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetActionQuality) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.actionQuality);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetActionQuality) {
    gBattleStatus.actionQuality = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80269600) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.unk_85);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_8026962C) {
    gBattleStatus.unk_85 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
